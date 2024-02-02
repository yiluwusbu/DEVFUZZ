/*
 * AP Stage2
 * 2022 Tong Zhang<ztong0001@gmail.com>
 * 2022 Yilun Wu <yiluwu@cs.stonybrook.edu>
 * Note: Compile kernel module with -O0 to preserve all information needed (-O2 is also supported)
 * by APStage2 Analysis
 */

#include "apstage2.h"

// my aux headers
#include "color.h"
#include "stopwatch.h"

using namespace llvm;

char APStage2::ID;

bool APStage2::runOnModule(Module &module) {
  // AA = &getAnalysis<AAResultsWrapperPass>().getAAResults();
  return APStage2Pass(module);
}

bool APStage2::isLLVMPrefix(Value *v) {
  Value *nv = v->stripPointerCasts();
  if (auto *cnv = dyn_cast<ConstantExpr>(nv)) {
    nv = cnv->getAsInstruction();
  }
  if (auto *gep = dyn_cast<GetElementPtrInst>(nv)) {
    nv = gep->getPointerOperand();
  }
  if (nv->getName().startswith("__llvm"))
    return true;
  if (nv->getName().startswith(".sink"))
    return true;
  // errs()<<" ===>"<<*nv<<"\n";
  return false;
}


void APStage2::processStore(StoreInst *st) {
  // skip gcov
  auto *p = st->getPointerOperand();
  if (isLLVMPrefix(p))
    return;
  auto *v = st->getValueOperand();
  // store constant is not what we are interested in
  if (isa<Constant>(v))
    return;
  // MMIO use store instruction instead of out
  mmioSt.push_back(st);
  // errs() << *st<<"\n";
  // if (auto *gep = dyn_cast<GetElementPtrInst>(p)) {
  //   errs() << " source + " << *st << "\n";
  // }
}

void APStage2::drawCallGraph(CallInst *ci) {
  Value * cv = ci->getCalledOperand()->stripPointerCasts();
  if (auto * f = dyn_cast<Function>(cv)) {
    auto name = f->getName();
    if (name.startswith("__asan_") || (name.startswith("llvm."))) {
      return;
    }
  }
  funcCallSites[cv].push_back(ci);
}

void APStage2::processCall(CallInst *ci) {

  if (ci->isInlineAsm()) {
    Value *cv = ci->getCalledOperand();
    auto * iasm = dyn_cast<InlineAsm>(cv->stripPointerCasts());
    const std::string & asm_str = iasm->getAsmString();
    if (asm_str == "movl $1,$0" || asm_str == "movb $1,$0" ||
       asm_str == "movw $1,$0" || asm_str == "movq $1,$0" || asm_str == "inl ${1:w}, $0"
       || asm_str == "inb ${1:w}, ${0:b}" || asm_str == "inw ${1:w}, ${0:w}") {
      callIoReads.push_back(ci);
    } else if (iasm->getAsmString() == "movl $0,$1") {
      // who cares about writes ???
      callIoWrite.push_back(ci);
    }
    return;
  }

  if (ci->isIndirectCall()) {
    indirectCalls.push_back(ci);
  }

#if (LLVM_VERSION_MAJOR <= 10)
  Value *cv = ci->getCalledValue();
#else
  Value *cv = ci->getCalledOperand();
#endif
  Function *bcf = dyn_cast<Function>(cv->stripPointerCasts());

  // indirect call?
  if (!bcf)
    return;
  auto name = bcf->getName();
  
  if (name.startswith("__asan_") || (name.startswith("llvm."))) {
    return;
  }
  // all CallInst
  callInsts.push_back(ci);
  if (name.startswith("dma_alloc_attrs")) {
    callDmaAlloc.push_back(ci);
    Value * ptr = ci->getArgOperand(2);
    Value * sz_v = ci->getOperand(1);
    int sz = 0;
    if (auto * c = dyn_cast<ConstantInt>(sz_v)) {
      sz = c->getZExtValue();
    }
    std::vector<Value*> lds;
    collectLoadFromAddress(ptr, lds);
    for (auto * v : lds) {
      dmaPhyAddrToDMASz[v] = sz;
    }
  }
  if (name.startswith("dma_alloc_coherent")) {
    callDmaAlloc.push_back(ci);
  }

  if (name.startswith("dma_map_single")
     || name.startswith("dma_map_page")) {
    callDmaAllocPage.push_back(ci);
  }
  if (name.startswith("dma_sync_single")) {
    // errs() << *ci << "\n";
  }
  // could write DMA address to device register ?
  if (name.startswith("iowrite32") || name.startswith("writel")) {
    callIoWrite.push_back(ci);
  }
  if (name.startswith("ioread8") || name.startswith("ioread16")
      || name.startswith("ioread32") || name.startswith("ioread64")) {
    callIoReads.push_back(ci);
  }
  // map device pio/mmio region
  if (name.startswith("pci_iomap") || name.startswith("ioremap") || name.startswith("pcim_iomap_table") || name.startswith("pcim_iomap")
      || name.startswith("pci_ioremap")) 
  {
    callIoMap.push_back(ci);
  }
  // errs()<<*ci<<"\n";
}

void APStage2::collectLoadFromAddress(Value *v, std::vector<Value *> &lds) {
  for (auto *u : v->users()) {
    // got load
    if (isa<LoadInst>(u))
      lds.push_back(u);
    // cast is OK
    if (isa<CastInst>(u))
      collectLoadFromAddress(u, lds);
  }
}

void APStage2::collectStoreOfValue(Value *v, std::vector<Value *> &sts) {
  for (auto *u : v->users()) {
    // got store
    if (StoreInst *st = dyn_cast<StoreInst>(u)) {
      if (st->getValueOperand() == v) {
        sts.push_back(st);
      } else {
        // what else?
      }
    }
    // cast is OK
    if (isa<CastInst>(u))
      collectStoreOfValue(u, sts);
  }
}

/* Need to handle Bitcasts ? */
Value * APStage2::processPCIM_IOMAP(Value *ci) {
  for (auto * user : ci->users()) {
    if (auto * gep = dyn_cast<GetElementPtrInst>(user)) {
      return processPCIM_IOMAP(gep);
    } else if (auto * ld = dyn_cast<LoadInst>(user)) {
      return ld;
    }
  }
  return nullptr;
}

int APStage2::getStructSize(StructType * t) {
  auto & dl = m_->getDataLayout();
  const StructLayout * struct_dl = dl.getStructLayout(t);
  return struct_dl->getSizeInBytes();
}


static Type* getTypeByOffset(Module & m, Type * base, uint64_t offset) {
  auto & dl = m.getDataLayout();
  StructType * st = dyn_cast<StructType>(base);
  if (!st) 
    return nullptr;
  const StructLayout * struct_dl = dl.getStructLayout(st);
  if (offset >= struct_dl->getSizeInBytes()) {
    return nullptr;
  }
  int n_fields = st->getNumElements();
  int idx = -1;
  for (int i=0; i<n_fields; i++) {
    if (struct_dl->getElementOffset(i) == offset) {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    return nullptr;
  }
  return st->getElementType(idx);
}

void APStage2::tryFindDMATypeByCast(Value * v, std::set<Type *> & results) {
  for (auto * u : v->users()) {
    if (StoreInst * st = dyn_cast<StoreInst>(u)) {
      if (st->getValueOperand() == v) {
        Value * dst = st->getPointerOperand()->stripPointerCasts();
        if (auto * gep = dyn_cast<GetElementPtrInst>(dst)) {
          Type * t = findStructTypeCasted(gep);
          if (t) {
            results.insert(t);
          }
        }
      }
    } else if (isa<CastInst>(u)) {
      tryFindDMATypeByCast(u, results);
    }
  }
}

void APStage2::findPointerStoredToType(Value *v, std::set<std::string> & srcs, 
                                        std::set<Type *> & results)
{
  const auto &dl = m_->getDataLayout();
  for (auto *u : v->users()) {
    // got store
    if (StoreInst *st = dyn_cast<StoreInst>(u)) {
      if (st->getValueOperand() == v) {
        Value * dst = st->getPointerOperand()->stripPointerCasts();
        GetElementPtrInst * gep = dyn_cast<GetElementPtrInst>(dst);
        if (gep) {
          int offset = getGEPOffset(gep);
          errs() << "gep: " << *gep << "\n";
          if (offset == -1) {
            errs() << "Can't extract offset from GEP\n";
          } else {
            // errs() << "GEP offset = " << offset << "\n";
            Type * base = gep->getSourceElementType();
            if (!isa<StructType>(base)) {
              continue;
            }
            Type * t = gep->getType();
            if (t->isPointerTy())
              t = getPointerBaseType(t);
            if (!isa<StructType>(t)) {
              t = getTypeByOffset(*m_, base, offset);
              if (t && t->isPointerTy()) {
                t = getPointerBaseType(t);
              }
            }
            if (t && isa<StructType>(t)) {
              errs() << "Loc: ";
              gep->getDebugLoc().print(errs());
              errs() << "Type: " << *(t) << "\n";
              results.insert(t);
            } else {
              std::string type_off = getTypeOffsetStr(base, offset);
              srcs.insert(type_off);
              // Let's try to find the type in subclass, if the source is a super class
               int struct_sz = dl.getStructLayout((StructType*)base)->getSizeInBytes();
               if (offset >= struct_sz) {
                Type * t = findStructMemberTypeInSubclass((StructType*)base, offset, gep->getPointerOperand());
                if (t && t->isPointerTy()) {
                  t = getPointerBaseType(t);
                }
                if (t && isa<StructType>(t)) {
                  INFO("DMA Type detected in subclass: " << t->getStructName());
                  results.insert(t);
                }
              }
            }
            
          }
        } else {
          // std::vector<Value *> lds;
          // collectLoadFromAddress(st->getPointerOperand(), lds);
          // for (auto * ld : lds) {
          //   collectStoreDstStruct(m, ld);
          // }
        }
      } 
    } else if (isa<CastInst>(u) || isa<PHINode>(u)) {
      findPointerStoredToType(u, srcs, results);
    } else if (isa<BinaryOperator>(u)) {
      findPointerStoredToType(u, srcs, results);
    } else if (isa<GetElementPtrInst>(u)) {
      findPointerStoredToType(u, srcs, results);
    }
  }
}

void APStage2::collectLoadStoreStruct(Value *v, std::set<Value *> &r) {
  std::vector<Value *> users;
  // contains dma buffer address
  std::vector<Value *> lds, sts;
  collectLoadFromAddress(v, lds);
  for (auto *ld : lds)
    collectStoreOfValue(ld, sts);
  //
  for (auto *ist : sts) {
    StoreInst *st = dyn_cast<StoreInst>(ist);
    // errs()<<" -- "<<*st<<"\n";
    r.insert(st->getPointerOperand());
  }
}


bool APStage2::findTypeOffsetAlias(Type * t, int offset, TypeOffset & result) {
  std::set<std::string>  type_offsets;
  std::set<Type *> res;

  const DataLayout & dl = m_->getDataLayout();
  if (!isa<StructType>(t)) {
    return false;
  }
  const StructLayout * struct_dl = dl.getStructLayout((StructType*)t);
  type_offsets.insert(getTypeOffsetStr(t, offset));
  findMemRegionTypeByCast(type_offsets, res);
  if (res.empty()) {
    return false;
  }
  
  int offset_into_alias = (int)struct_dl->getSizeInBytes() - offset;
  for (auto * aat: res) {
    const StructLayout * struct_dl = dl.getStructLayout((StructType*)aat);
    if ((uint64_t)offset_into_alias < struct_dl->getSizeInBytes()) {
      result.type = aat;
      result.offset = offset_into_alias;
      return true;
    }
  }
  return false;
}

Type * APStage2::findStructMemberTypeInSubclass(StructType * super_class_type, int offset, Value * super_class_ptr) {
   const DataLayout & dl = m_->getDataLayout();
   const StructLayout * struct_dl = dl.getStructLayout(super_class_type);
   StructType *subclass_type = nullptr;
   int super_struct_sz = struct_dl->getSizeInBytes();
   // Locate src
   for (auto * v : super_class_ptr->users()) {
     if (auto * gep = dyn_cast<GetElementPtrInst>(v)) {
       if (gep->getPointerOperand() != super_class_ptr) {
         continue;
       }
       int offset = getGEPOffset(gep);
       if (offset != super_struct_sz) {
         continue;
       }
       subclass_type = (StructType*)findStructTypeCasted(gep);
       if (!subclass_type) {
         continue;
       }
       INFO("Subclass found: " << subclass_type->getName());
       break;
     }
   }
   
   if (!subclass_type) {
     return nullptr;
   }
   
   int offset_into_sub = offset - super_struct_sz;
   INFO("offset :" << offset_into_sub);
   if (offset_into_sub < 0) {
     WARN("Strange, the offset into the subclass < 0");
     return nullptr;
   }

   Type * res = getTypeByOffset(*m_, subclass_type, offset_into_sub);
   if (res && !isa<StructType>(res)) {
     DEBUG("Member Type: " << *res);
   }
   return res;
}


/*
 * LLVM IR will cast the type back to
 * a struct type, we can know the type
 * of the DMA struct by scanning the casting
 * of the DMA pointers, this is a whole module analysis
 */
void APStage2::findMemRegionTypeByCast(std::set<std::string> & type_offsets, 
                                  std::set<Type *> & results) 
{
  Module & module = *m_;
  
  for (Module::iterator fi = module.begin(), f_end = module.end(); fi != f_end; ++fi) {
    Function *func = dyn_cast<Function>(fi);
    if (func->isDeclaration() || func->isIntrinsic())
      continue;
    for (Function::iterator fi = func->begin(), fe = func->end(); fi != fe;
         ++fi) 
    {
      BasicBlock *bb = dyn_cast<BasicBlock>(fi);
      for (BasicBlock::iterator ii = bb->begin(), ie = bb->end(); ii != ie;
           ++ii) 
      {
        if (auto *bc = dyn_cast<CastInst>(ii)) {
          Type * dst_type= getPointerBaseType(bc->getType());
          
          if (!isa<StructType>(dst_type)) {
            continue;
          }

          if (auto *gep = dyn_cast<GetElementPtrInst>(bc->getOperand(0))) {
            Type * base_type = gep->getSourceElementType();
            if (!isa<StructType>(base_type)) {
              continue;
            }
            
            int offset = getGEPOffset(gep);
            if (offset == -1) {
              continue;
            }
            std::string tp_off =  getTypeOffsetStr(base_type, offset);
            if (type_offsets.count(tp_off)) {
              errs() << "Mem Region Type Found: " << dst_type->getStructName() << "\n";
              errs() << "bc: " << *bc << "\n";
              dmaType2DMABufferLengths[dst_type] =typeOffset2DMABufferLengths[tp_off];
              results.insert(dst_type);
            }
          }
        }
      }
    }
  }
}

int APStage2::getStructMemberOffset(GetElementPtrInst * gep) {
  int offset = -1;
  if (gep->hasAllConstantIndices()) {
    return getGEPOffset(gep);
  }
  Value * idx0 = gep->getOperand(1);
  // errs() << "gep " << *gep << "\n";
  if (!isa<ConstantInt>(idx0)) {
    bool rest_all_constants=true;
    for (auto i = gep->idx_begin()+1; i != gep->idx_end(); ++i) {
      if (!isa<ConstantInt>(i)) {
        rest_all_constants = false;
        break;
      }
    }
    if (rest_all_constants) {
      ConstantInt * idx0_const = ConstantInt::get(Type::getInt64Ty(gep->getContext()), 0, true);
      gep->replaceUsesOfWith(idx0, idx0_const);
      offset = getGEPOffset(gep);
      gep->replaceUsesOfWith(idx0_const, idx0);
      // delete idx0_const;
      return offset;
    }
  }
  return offset;
}

/*
 * find the offset of the secondary DMA
 * in the level-1 DMA struct
 * struct Level1_DMA {  
 *    dma_addr_t dma_buf;
 * }
 */

void APStage2::findDMAPageAddrOffset(Value * page_addr, int sz) {
  std::set<Value*> visited;
  __findDMAPageAddrOffset(page_addr, visited, sz);
  return;
}

void APStage2::__findDMAPageAddrOffset(Value * page_addr, std::set<Value*>visited, int sz) {
  if (visited.count(page_addr)) {
    return;
  }
  visited.insert(page_addr);
  for (auto * user : page_addr->users()) {
    if (isa<StoreInst>(user)) {
      StoreInst * st = dyn_cast<StoreInst>(user);
      Value * ptr_op = st->getPointerOperand();
      if (GetElementPtrInst * gep = dyn_cast<GetElementPtrInst>(ptr_op)) {
        Type * struct_type = gep->getSourceElementType();
        
        if (dmaBufferTypes.count(struct_type)) {
          errs() << "hit\n";
          int offset = getStructMemberOffset(gep);
          if (offset != -1) {
            Type * type = getTypeByOffset(*m_, struct_type, offset);
            if (type) {
              secondDMABufferOffSz[struct_type][offset] = sz;
              errs() << struct_type->getStructName() << ": @" << (*type) << " offset " << offset << " type: " << *(gep->getResultElementType()) <<  " secondary DMA buffer " << "\n" ; 
            }
          }
        }
      }
    } else if (isa<PHINode>(user)) {
      __findDMAPageAddrOffset(user, visited, sz);
    } else if (isa<CastInst>(user)) {
      __findDMAPageAddrOffset(user, visited, sz);
    }
  }
}

void APStage2::genSecondaryDMAInitCode() {
  // std::set<int> dma_size_seen;
  std::string code;
  for (auto & p : secondDMABufferOffSz) {
    StructType * struct_type = (StructType *)(p.first);
    auto & sec_off_sz_pairs = p.second;
    int struct_sz = getStructSize(struct_type);
    int l1_dma_buffer_sz = dmaType2DMABufferLengths[struct_type];
    if (l1_dma_buffer_sz % struct_sz != 0) {
      continue;
    }
    for (auto & off_sz_p : sec_off_sz_pairs) {
      int offset = off_sz_p.first;
      int l2_dma_buffer_sz = off_sz_p.second;
      code += "model->setSecondaryDMAInfo(" + std::to_string(struct_sz) + ", " + 
              std::to_string(l1_dma_buffer_sz) + ", " + std::to_string(offset);
      if (l2_dma_buffer_sz != 0) {
        code += ", " + std::to_string(l2_dma_buffer_sz);
      }
      code += + ");\n";
      
    }
  }
  errs() << code << "\n";
}

static void doCollectMMIOBaseInterProc(Value * src, std::set<Value*> & mmio_base_set) {
  for (auto * u : src->users()) {
    if (isa<CastInst>(u)) {
      doCollectMMIOBaseInterProc(u, mmio_base_set);
    } else if (auto * call = dyn_cast<CallInst>(u)) {
      // find out which arg
      Function * func = getCalledFunction(call);
      if (!func) {
        WARN("No function?");
        continue;
      }
      if (func->isVarArg()) 
        continue;
      for (unsigned int i=0; i<call->getNumArgOperands(); i++) {
        if (call->getArgOperand(i) == src) {
          INFO("found: " << func->getName() << " " << " arg: " << i);
          Argument * arg = func->getArg(i);
          mmio_base_set.insert(arg);
        }
      }

    }
  }
  return;
}

static void collectMMIOBaseInterProc(std::set<Value*> & mmio_base_set) {
  std::set<Value*> workset;
  std::set<Value*> newset;
  for (auto * base : mmio_base_set) {
    workset.insert(base);
  }
  do {
    for (auto * mmio_base : workset) {
      doCollectMMIOBaseInterProc(mmio_base, newset);
    }
    workset = newset;
    for (auto * v : newset) {
      mmio_base_set.insert(v);
    }
    newset.clear();
  } while (!workset.empty());
} 

void APStage2::findMMIORegionPtrs() {
  std::set<Value*> mmio_bases;
  Module & module = *m_;
  collectMMIOBaseInterProc(deviceMemAddr);
  for (auto * mmio_base : deviceMemAddr) {
    errs() << *mmio_base << "\n";
    for (auto * u : mmio_base->users()) {
      doFindMMIORegionPtrs(u, 0);
    }
  }
  Type * base_struct_type = nullptr;
  int base_field_offset;
  for (auto & pair : mmioRegions) {
    MMIORegionPtr mr = pair.second;
    if (mr.base_offset == 0) {
      if (base_struct_type) {
        DEBUG("Already have a base\n");
        continue;
      }
      base_struct_type = mr.host_type;
      base_field_offset = mr.host_offset;
    }
  }
  // find all the ld of mmio_base in the module
  for (Module::iterator fi = module.begin(), f_end = module.end(); fi != f_end;
       ++fi) {
    Function *func = dyn_cast<Function>(fi);
    if (func->isDeclaration() || func->isIntrinsic())
      continue;
    for (Function::iterator fi = func->begin(), fe = func->end(); fi != fe;
         ++fi) {
      BasicBlock *bb = dyn_cast<BasicBlock>(fi);
      for (BasicBlock::iterator ii = bb->begin(), ie = bb->end(); ii != ie;
           ++ii) {
        if (auto * ld = dyn_cast<LoadInst>(ii)) {
          Value * src = ld->getPointerOperand();
          if (!isa<GetElementPtrInst>(src)) {
            src = src->stripPointerCasts();
          }
          if (auto * gep = dyn_cast<GetElementPtrInst>(src)) {
            Type * src_type = gep->getSourceElementType(); 
            int offset = getGEPOffset(gep);
            if (src_type == base_struct_type && 
                offset == base_field_offset)
            {
              mmio_bases.insert(ld);
            }
          }
        }
          
      }
    }
  }
  collectMMIOBaseInterProc(mmio_bases);
  for (auto * mb : mmio_bases) {
    for (auto * u : mb->users()) {
      doFindMMIORegionPtrs(u, 0);
    }
  }
}

/*
 *  struct XXX * x = ...
 *  devs[n] = x;
 *  Find the x's type by using the array's type
 */
Type * APStage2::findStructTypeByStore(Value * src)
{
  Type * res = nullptr;
  for (auto * u : src->users()) {
    if (isa<CastInst>(u)) {
      res = findStructTypeByStore(u);
      if (res) {
        return res;
      }
    } else if (isa<StoreInst>(u)) {
      // sink
      StoreInst * st = (StoreInst*)u;
      Value * dst = st->getPointerOperand()->stripPointerCasts();
      Type * dst_type = dst->getType();
      if (dst_type->isPointerTy()) {
        Type * base_type = getPointerBaseType(dst_type);
        if (isa<StructType>(base_type)) {
          return base_type;
        }
      }
    }
  }
  return res;
}

Type * APStage2::findStructTypeCasted(Value * v) {
  for (auto * u : v->users()) {
    if (isa<CastInst>(u)) {
      Type * t = u->getType();
      if (t->isPointerTy())
        t = getPointerBaseType(t);
      if (isa<StructType>(t)) {
        return t;
      }
    }
  }
  return nullptr;
}

Type * APStage2::findStructTypeInUseChain(Value * v) {
  Type *res = nullptr;
  res = findStructTypeCasted(v);
  if (res) 
    return res;
  res = findStructTypeByStore(v);
  return res;
}

/*
 * Find the structs containing the pointers 
 * that points to MMIO regions as well as the pointers's
 * offset relative the sturct base. We also track the MMIO subregion that
 * the pointer points to by finding out the subregion's offset relative to the MMIO base
 * Approach:
 * 1. find the StoreInst that stores the mmio ptr to a struct
 * 2. The StoreInst's dest is a GEP
 * 3. find the struct type of the GEP's pointer operand, and GEP's offset(constant)
 */
void APStage2::doFindMMIORegionPtrs(Value *mmio_ptr, int base_off) {
  if (isa<StoreInst>(mmio_ptr)) {
    // sink 
    StoreInst * store = (StoreInst*)mmio_ptr;
    Value * dst = store->getPointerOperand()->stripPointerCasts();
    if (auto * gep = dyn_cast<GetElementPtrInst>(dst)) {
      errs() << "mmio gep\n";
      errs() << *gep << "\n";
      Type * src_type = gep->getSourceElementType();
      Value * struct_ptr = gep->getPointerOperand();
      if (!isa<StructType>(src_type)) {
        src_type = findStructTypeInUseChain(struct_ptr);
        if (!src_type) {
          return;
        }
      }
      int offset = getGEPOffset(gep);
      if (offset != -1) {
        std::string key = getTypeOffsetStr(src_type, offset);
        if (mmioRegions.find(key) == mmioRegions.end()) {
          errs() << "MMIO Host: " << src_type->getStructName() << " offset: " << offset << " base off:" << base_off << "\n";
          mmioRegions[key] = {src_type, offset, base_off};
          Type * t = getTypeByOffset(*m_, src_type, offset);
          if (!t) {
            TypeOffset alias;
            if (findTypeOffsetAlias(src_type, offset, alias)) {
              key = getTypeOffsetStr(alias.type, alias.offset);
              mmioRegions[key] = {alias.type, alias.offset, base_off};
              errs() << "MMIO Host Alias: " << alias.type->getStructName() << " offset: " << alias.offset << " base off:" << base_off << "\n";
            }
          }
        }
      } else {
        errs() << "findMMIORegionPtrs: GEP offsets are not all constants\n"; 
      }
    } else if (auto * kmalloc = dyn_cast<CallInst>(dst)) {
      //struct kmalloc-ed, NO GEP, offset is 0
      Type * host_type = findStructTypeInUseChain(kmalloc);
      if (!host_type) 
        return;
      std::string key = getTypeOffsetStr(host_type, 0);
      if (mmioRegions.find(key) == mmioRegions.end()) {
        errs() << "MMIO Host: " << host_type->getStructName() << " offset: " << 0<< " base off:" << base_off << "\n";
        mmioRegions[key] = {host_type, 0, base_off};
      }
    }
  } else if (isa<BinaryOperator>(mmio_ptr)) {
    // pointer arithmetics
    ConstantInt * cint;
    int64_t cint_val;
    int new_base_off;
    auto * bin_op = (BinaryOperator*)mmio_ptr;
    Value * op1 = bin_op->getOperand(0);
    Value * op2 = bin_op->getOperand(1);
    if (!isa<ConstantInt>(op1) && !isa<ConstantInt>(op2)) {
      return;
    }
    cint = isa<ConstantInt>(op1) ? (ConstantInt*)op1 : (ConstantInt*)op2;
    cint_val = cint->getSExtValue();
    auto opcode = bin_op->getOpcode();
    if (opcode == Instruction::BinaryOps::Add) {
      new_base_off = base_off + cint_val;
    } else if (opcode == Instruction::BinaryOps::Sub) {
      new_base_off = base_off - cint_val;
    }
    for (auto * u : mmio_ptr->users()) {
      doFindMMIORegionPtrs(u, new_base_off);
    }
  } else if (isa<CastInst>(mmio_ptr)) {
    for (auto * u : mmio_ptr->users()) {
      doFindMMIORegionPtrs(u, base_off);
    }
  } else if (isa<GetElementPtrInst>(mmio_ptr)) {
    auto * gep = (GetElementPtrInst*)mmio_ptr;
    int off = getGEPOffset(gep);
    if (off != -1) {
      int new_base_off = base_off + off;
      for (auto * u : mmio_ptr->users()) {
        doFindMMIORegionPtrs(u, new_base_off);
      }
    } 
  }
  
}

void APStage2::__collectAliasPassedAsParam(Value * v, std::set<Value*> & res, std::set<Function*> & visited) {
  std::set<Value*> reads_alias;
  std::set<Value*> value_visited;
  collectValueAlias(v, reads_alias, value_visited);
  for (auto * vi : reads_alias) {
    for (auto * u : vi->users()) {
      if (auto * ci = dyn_cast<CallInst>(u)) {
        Function * f = ci->getCalledFunction();
        if (!f || f->isVarArg()) {
          continue;
        }
        INFO("DMA Alias Called Func: " << f->getName());
        int arg_id = -1;
        for (size_t i=0; i<ci->getNumArgOperands(); i++ ) {
          if (ci->getArgOperand(i) == vi) {
            arg_id = (int)i;
          }
        }
        if (arg_id == -1) {
          continue;
        }
        Value * arg = f->getArg(arg_id);
        if (!visited.count(f)) {
          visited.insert(f);
          res.insert(arg);
          __collectAliasPassedAsParam(arg, res, visited);
        }
      }
    }
  }
}

void APStage2::collectAliasPassedAsParam(Value * v, std::set<Value*> & res) {
  std::set<Function*>  visited;
  __collectAliasPassedAsParam(v, res, visited);
}

/* collect DMA inputs source */
void APStage2::collectDMAReads() {
  Module & module = *m_;
  for (Module::iterator fi = module.begin(), f_end = module.end(); fi != f_end; ++fi) {
    Function *func = dyn_cast<Function>(fi);
    if (func->isDeclaration() || func->isIntrinsic())
      continue;
    for (Function::iterator fi = func->begin(), fe = func->end(); fi != fe;
         ++fi) 
    {
      BasicBlock *bb = dyn_cast<BasicBlock>(fi);
      for (BasicBlock::iterator ii = bb->begin(), ie = bb->end(); ii != ie;
           ++ii) 
      {
        if (auto * gep = dyn_cast<GetElementPtrInst>(ii)) {
          Type * type = gep->getSourceElementType();
          if (!dmaBufferTypes.count(type)) {
            continue;
          }
          int offset = getStructMemberOffset(gep);
          if (offset == -1) {
            continue;
          }
          std::vector<Value*> loads;
          std::set<Value*> dma_read_alias;
          collectLoadFromAddress(gep, loads);
          for (auto * ld : loads) {
            collectAliasPassedAsParam(ld, dma_read_alias);
            errs() << "DMA Read: offset = " << offset << "\n";
            ((LoadInst*)ld)->getDebugLoc().print(errs());
            errs() << "\n";
            dmaReads[ld] = {type, offset};
            bbIOReadCnt[((LoadInst*)ld)->getParent()] += 1;
          }
          for (auto * a : dma_read_alias) {
            errs() << "DMA Read Alias: offset = " << offset << "\n";
            dmaReads[a] = {type, offset};
          }
        }
      }
    }
  }
}

static std::unordered_map<Instruction::BinaryOps, Expression::ExpType> op_map {
  {Instruction::BinaryOps::Add, Expression::ExpType::ADD},
  {Instruction::BinaryOps::Sub, Expression::ExpType::SUB},
  {Instruction::BinaryOps::Mul, Expression::ExpType::MUL},
  {Instruction::BinaryOps::SDiv, Expression::ExpType::DIV},
  {Instruction::BinaryOps::UDiv, Expression::ExpType::DIV},
  {Instruction::BinaryOps::And, Expression::ExpType::BITAND},
  {Instruction::BinaryOps::Or, Expression::ExpType::BITOR},
  {Instruction::BinaryOps::Xor, Expression::ExpType::BITXOR},
  {Instruction::BinaryOps::Shl, Expression::ExpType::LSHIFT},
  {Instruction::BinaryOps::LShr, Expression::ExpType::RSHIFT},
};

static std::unordered_map<CmpInst::Predicate, Expression::ExpType> pred_map {
  {CmpInst::Predicate::ICMP_EQ, Expression::ExpType::EQ},
  {CmpInst::Predicate::ICMP_NE, Expression::ExpType::NE},
  {CmpInst::Predicate::ICMP_SLT, Expression::ExpType::LT},
  {CmpInst::Predicate::ICMP_ULT, Expression::ExpType::LT},
  {CmpInst::Predicate::ICMP_SLE, Expression::ExpType::LE},
  {CmpInst::Predicate::ICMP_ULE, Expression::ExpType::LE},
  {CmpInst::Predicate::ICMP_SGT, Expression::ExpType::GT},
  {CmpInst::Predicate::ICMP_UGT, Expression::ExpType::GT},
  {CmpInst::Predicate::ICMP_SGE, Expression::ExpType::GE},
  {CmpInst::Predicate::ICMP_UGE, Expression::ExpType::GE},
};

/* helper function, find the first user of the HW Input */
Value * getFirstHWInputInBB(BasicBlock * bb, 
                           std::unordered_map<Value*, Expression*> & val2expr) 
{
  for (BasicBlock::iterator ii = bb->begin(), ie = bb->end(); ii != ie;
      ++ii)
  {
    Value * v = &*ii;
    if (val2expr.find(v) != val2expr.end()) {
      return v;
    }
  } 
  return nullptr;                                              
}

void collectValueAlias(Value * v, std::set<Value*> & alias, std::set<Value*> & visited) {
  if (visited.count(v)) {
    return;
  }
  visited.insert(v);
  alias.insert(v);
  for (auto * u : v->users()) {
    if (isa<CastInst>(u) || isa<PHINode>(u)) {
      collectValueAlias(u, alias, visited);
    }
  }
}

Expression * FieldConstraintBuilder::buildPredExprTopDown(int level) {
  if (level == 0) {
    return hw_value_expr;
  }
  int idx = level -1;
  Instruction * cur_op = static_cast<Instruction*>(path[idx]);

  if (isa<SwitchInst>(cur_op)) {
    SwitchInst * sw = (SwitchInst*)cur_op;
    Expression * lhs = buildPredExprTopDown(level-1);
    if (!lhs) {
      errs() << "can't build expr\n";
      return nullptr;
    }
    for (auto case_it = sw->case_begin(); case_it != sw->case_end(); ++case_it) {
      ConstantInt * cst = case_it->getCaseValue();
      ValueExpr * cst_expr = new ValueExpr(cst->getZExtValue());
      ArithExpr * eq_expr = new ArithExpr(Expression::ExpType::EQ, lhs, cst_expr);
      results.push_back(eq_expr);
    }
    return nullptr;
  }


  Value * const_v = isa<ConstantInt>(cur_op->getOperand(0)) ? cur_op->getOperand(0) : cur_op->getOperand(1);
  ConstantInt * const_int = static_cast<ConstantInt*>(const_v);
  Expression::ExpType exp_type;

  if (isa<BinaryOperator>(cur_op)) {
    auto * bin_op = (BinaryOperator*)cur_op;
    auto opcode = bin_op->getOpcode();
    if (op_map.find(opcode) == op_map.end()) {
      errs() << "Unhandled Operation type!!\n";
      return nullptr;
    }
    exp_type = op_map[opcode];
  } else if (isa<CmpInst>(cur_op)) {
    auto * cmp = (CmpInst*)cur_op;
    auto pred = cmp->getPredicate();
    if (pred_map.find(pred) == pred_map.end()) {
      errs() << "Pred type Undefined!\n";
      return nullptr;
    }
    exp_type = pred_map[pred];
  }  
  Expression * left_expr = buildPredExprTopDown(level-1);
  if (!left_expr) {
    return nullptr;
  }
  ValueExpr * const_expr = new ValueExpr(const_int->getZExtValue());
  ArithExpr * expr = new ArithExpr(exp_type, left_expr, const_expr);
  return expr;
}

void FieldConstraintBuilder::buildPreds(Value * hw_input_op, std::set<Value*> & visited) 
{
  if (isa<BinaryOperator>(hw_input_op) || isa<CmpInst>(hw_input_op)) {
    Instruction * inst = (Instruction*)hw_input_op;
    Value * op1 = inst->getOperand(0);
    Value * op2 = inst->getOperand(1);
  
    
    if (!isa<ConstantInt>(op1) && !isa<ConstantInt>(op2)) {
      if (auto * bop = dyn_cast<BinaryOperator>(hw_input_op)) {
        auto opcode = bop->getOpcode();
        if (opcode == Instruction::BinaryOps::And
           || opcode == Instruction::BinaryOps::Or) {
          for (auto * u : hw_input_op->users()) {
            buildPreds(u, visited);
          }
        }
      }
      return;
    }
    path.push_back(hw_input_op);
    for (auto * u : hw_input_op->users()) {
      buildPreds(u, visited);
    }
    path.pop_back();
  } else if (isa<BranchInst>(hw_input_op)) {
    /* sink */
    BranchInst * branch = (BranchInst*)hw_input_op;
    Expression * expr = buildPredExprTopDown(path.size());
    if (!expr) {
      errs() << "Fatal Error: can't build expression\n";
    } else {
      preds[branch] = expr;
      bb2branch[branch->getParent()] = branch;
    }
  } else if (isa<SwitchInst>(hw_input_op)) {
    /* sink */
    path.push_back(hw_input_op);
    buildPredExprTopDown(path.size());
    path.pop_back();
  } else if (isa<PHINode>(hw_input_op)) {
    if (visited.count(hw_input_op)) {
      return;
    }
    visited.insert(hw_input_op);
    for (auto * u : hw_input_op->users()) {
      buildPreds(u, visited);
    }
  } else if (isa<CastInst>(hw_input_op)) {
    for (auto * u : hw_input_op->users()) {
      buildPreds(u, visited);
    }
  }
  return;
}

void FieldConstraintBuilder::buildConstraints() {
  std::set<Value*> alias;
  std::set<Value*> visited;
  assert(path.empty());

  collectValueAlias(hw_input_src, alias, visited);
  alias.insert(hw_input_src);
  for (auto * v : alias) {
    for (auto * u : v->users()) {
      std::set<Value*> visited;
      buildPreds(u, visited);
    }
  }
  
  // for (auto & pair : preds) {
  //   BranchInst * b = dyn_cast<BranchInst>(pair.first);
  //   if (!b) {
  //     continue;
  //   }
  //   auto * true_bb = b->getSuccessor(0);
  //   Expression * expr = preds[pair.first];
  //   if (bb2branch.find(true_bb) != bb2branch.end()) {
  //     // AND
  //     BranchInst * btb = bb2branch[true_bb];
  //     Expression * expr_tbt = preds[btb];
  //     if (!expr) {
  //       errs() << "Unhandled condition\n";
  //       continue;
  //     }
  //     errs() << "And Expression\n";
  //     ArithExpr * and_expr = new ArithExpr(Expression::ExpType::AND, expr, expr_tbt);
  //     preds[btb] = nullptr;
  //     preds[b] = and_expr;
  //   } 
  // }

  for (auto & pair : preds) {
    if (pair.second) {
      results.push_back(pair.second);
    }
  }
  
}

static bool BBhasReturn(BasicBlock * bb) {
  for (auto ii=bb->begin(); ii != bb->end(); ++ii) {
    if (isa<ReturnInst>(ii)) {
      return true;
    }
  }
  return false;
}

static int __maxNumOfBBToReturn(BasicBlock * bb, std::set<BasicBlock*> &visited) {
  if (visited.count(bb)) {
    return 0;
  }
  visited.insert(bb);
  if (BBhasReturn(bb)) {
    return 1;
  }
  int max_num = 1;
  for (auto * succ : successors(bb)) {
    int nbtr = __maxNumOfBBToReturn(succ, visited) + 1;
    max_num =  max_num > nbtr ? max_num : nbtr;
  }
  return max_num;
}

static int maxNumOfBBToReturn(BasicBlock * bb) {
  std::set<BasicBlock*> visited;
  return __maxNumOfBBToReturn(bb, visited);
}


void APStage2::cntFunctionIOReads() {
  for (auto fi=m_->begin(); fi != m_->end(); ++fi) {
    Function *f = &(*fi);
    int io_cnt = 0;
    for (auto bi=fi->begin(); bi != fi->end(); ++bi) {
      BasicBlock * bb = &(*bi);
      io_cnt += bbIOReadCnt[bb];
    }
    funcIOReadCnt[f] = io_cnt;
  }
}

bool doValueIsReturned(Value * v, std::set<Value*> &visited) {
  if (visited.count(v)) {
    return false;
  }
  visited.insert(v);
  for (auto * u : v->users()) {
    if (isa<ReturnInst>(u)) {
      return true;
    } else if (isa<CastInst>(u) || isa<PHINode>(u)) {
      bool returned =  doValueIsReturned(u, visited);
      if (returned) {
        return true;
      }
    }
  }
  return false;
}

bool APStage2::valueIsReturned(Value *v) {
  std::set<Value*> visited;
  return doValueIsReturned(v, visited);
}

void APStage2::identifyKMIByStore(StoreInst * st) {
  auto * stored = st->getValueOperand();
  Type * tp = stored->getType();
  Type * func_ptr_tp = nullptr;
  const DataLayout & dl = m_->getDataLayout();
  if (tp->isPointerTy()) {
    func_ptr_tp = tp;
    tp = getPointerBaseType(tp);
  }
  if (!tp->isFunctionTy()) {
    return;
  }
  int offset = -1;
  Type * dst_tp;
  Type * alias_tp = nullptr;
  int alias_offset;
  Function * func = (Function*)stored;
  GetElementPtrInst * gep = nullptr;
  auto * dst = st->getPointerOperand()->stripPointerCasts();
  if ((gep = dyn_cast<GetElementPtrInst>(dst))) {
    offset = getGEPOffset(gep);
    dst_tp = gep->getSourceElementType();
  } else {
    offset = 0;
    dst_tp = dst->getType();
  }

  if (!isa<StructType>(dst_tp)) {
      return;
  }
  if (offset == -1) {
    WARN("GEP offset is not constant, it is uncommon\n");
    return;
  }
  const StructLayout * sl = dl.getStructLayout((StructType*)dst_tp);
  if (gep && sl->getSizeInBytes() >= (uint64_t)offset) {
    alias_tp = findStructMemberTypeInSubclass((StructType*)dst_tp, offset, gep->getPointerOperand());
  }
  DEBUG("Function: " << func->getName() << " struct: " << dst_tp->getStructName() << " offset: " << offset);
  TypeOffset tp_off = {dst_tp, offset};
  func2KMI[func].push_back(tp_off);
  type2Funcs[func_ptr_tp].insert(func);
  DEBUG("Function Ptr Type: " << *func_ptr_tp << "\n Func Name: " << func->getName());
  if (alias_tp && alias_tp->isStructTy()) {
    alias_offset = offset - dl.getStructLayout((StructType*)alias_tp)->getSizeInBytes();
    DEBUG("Function: " << func->getName() << " struct: " << alias_tp->getStructName() << " offset: " << alias_offset);
    func2KMI[func].push_back({alias_tp, alias_offset});
  }
}

void APStage2::identifyKMI(Module &module) {
  auto & dl = module.getDataLayout();
  for (auto *st : module.getIdentifiedStructTypes()) {
    structTypes[st->getStructName().str()] = st;
  }
  for (GlobalVariable &gvi : module.globals()) {
    GlobalVariable *gi = &gvi;
 
    if (gi->isDeclaration())
      continue;
    StringRef gvn = gi->getName();
    if (gvn.startswith(".str") || gvn.startswith("llvm.") 
        || gvn.startswith("__setup_str")) { // || !gvn.startswith("trans_ops_pcie")) {
      continue;
    }
    Type * gi_type = gi->getType();
    
    if (gi_type->isPointerTy()) {
      gi_type = gi_type->getPointerElementType();
    }
    if (!gi_type->isStructTy()) {
      continue;
    }
    StructType * st_type = (StructType*)gi_type;
    const StructLayout * struct_dl = dl.getStructLayout(st_type);
    // errs() << "Global Type: " << *st_type << "\n";
    // errs() << "Global st type: " << st_type->getStructName() << " noname\n";
    
    for (unsigned int i=0; i<st_type->getNumElements(); i++) {
      auto * init = gi->getInitializer();
      Constant * ci = init->getAggregateElement(i);
      
      if (!ci) {
        DEBUG("i = " << i);
        continue;
      }
      ci = ci->stripPointerCasts();
      Type * ti = ci->getType();
      if (ti->isPointerTy()) {
        ti = getPointerBaseType(ti);
      } 
      if (!ti->isFunctionTy()) {
        continue;
      }
      if (!isa<Function>(ci)) {
        // it is a null func pointer, just let go.
        continue;
      }
      if (st_type->getStructName().empty()) {
        StructType * alias = findGlobalValueStructType(gi, module);
        if (alias) {
          st_type = alias;
          //errs() << "Global st resolved type: " << st_type->getStructName();
          std::string name = getStructBaseName(st_type->getStructName().str());
         // errs() << "  Equivalent name: " << name << "\n";
          StructType * t = structTypes[name];
          if (t) {
            //errs() << "Type is : " << t->getStructName() << "\n";
            st_type = t;
          }
        }
      }
      Function * f = (Function *)ci;
      // DEBUG("Function name: " << f->getName() << " Function Type: " << *ti);
      int elm_offset = struct_dl->getElementOffset(i);
      func2KMI[f].push_back({st_type, elm_offset});
    }
  }
}

static int doGetParamIndex(Value * v, std::unordered_map<Value *, int> & arg_ind) {
  if (arg_ind.find(v) != arg_ind.end()) {
    return arg_ind[v];
  }
  if (isa<CastInst>(v)) {
    CastInst * cast = (CastInst*)v;
    return doGetParamIndex(cast->getOperand(0), arg_ind);
  } else if (isa<BinaryOperator>(v)) {
    WARN("doGetParamIndex: Unhandled instruction type: BinaryOP");
    return -1;
  } else if (isa<PHINode>(v)) {
    WARN("doGetParamIndex: Unhandled instruction type: PHINode");
    return -1;
  }
  WARN("doGetParamIndex: Unhandled instruction type " << *v);
  return -1;
}

// do backward slicing until it reaches the function param 
int APStage2::getParamIndex(Value * v, Function * f) {
  std::unordered_map<Value *, int> arg_ind;
  for (auto it = f->arg_begin(); it != f->arg_end(); ++it) {
    arg_ind[it] = it->getArgNo();
  }
  return doGetParamIndex(v, arg_ind);
}

void APStage2::MMIOReadCallGraphBackwardSlicing(Function *func, std::set<Function*> & visited, int base, int offset_param_id, int size) {
  if (visited.count(func)) {
    return;
  }
  visited.insert(func);
  mmioReadWrappers[func] = {base, offset_param_id, size};
  if (func2KMI.find(func) != func2KMI.end()) {
    for (auto & kmi : func2KMI[func]) {
      std::string key = getTypeOffsetStr(kmi.type, kmi.offset);
      kmi2Funcs[key].insert(func);
    }
  }
  for (auto * call : funcCallSites[func]) {
    if (valueIsReturned(call)) {
      Function * caller = call->getFunction();
      int caller_func_offset_arg_id;
      if (offset_param_id < 0) {
        // negative means it is a constant value 
        caller_func_offset_arg_id = offset_param_id;
      } else {
        Value * offset_op = call->getOperand(offset_param_id);
        caller_func_offset_arg_id = getParamIndex(offset_op, caller);
      }
      if (caller_func_offset_arg_id == -1) {
        DEBUG("offset not in caller's args? Function: " << caller->getName() << "  call: " << *call);
        continue;
      }
      MMIOReadCallGraphBackwardSlicing(caller, visited, base, 
                            caller_func_offset_arg_id, size);
    }
  }
}

void APStage2::collectMMIOReadInterface() {
  std::set<Function*>  visited;
  for (auto * ci : callIoReads) {
    auto * func = ci->getFunction();
    // DEBUG("Analyzing " << func->getName() << "...");
    Value * mmio_ptr = ci->getArgOperand(0);
    if (!valueIsReturned(ci)) {
      continue;
    }
    int sz = ci->getType()->getScalarSizeInBits() / 8;
    Value * base = nullptr;
    Value * offset = nullptr;
    int base_off = findMMIOBaseOff(mmio_ptr, &base, &offset);
    if (base_off == -1) {
      DEBUG("collectMMIOReadInterface: Can't identify the base offset, setting it to be 0");
      base_off = 0;
    }
    if (offset) {
      int offset_param_idx = getParamIndex(offset, func);
      if (offset_param_idx != -1) {
        MMIOReadCallGraphBackwardSlicing(func, visited, base_off, offset_param_idx, sz);
      } else {
        DEBUG("param not identified?");
      }
    } else if (auto * gep = dyn_cast<GetElementPtrInst>(mmio_ptr->stripPointerCasts())) {
      // offset is a constant
      int constant_off = getGEPOffset(gep);
      assert(constant_off != -1);
      MMIOReadCallGraphBackwardSlicing(func, visited, base_off, -constant_off, sz);
    } else if (auto * binary_op = dyn_cast<BinaryOperator>(mmio_ptr->stripPointerCasts())){
      if (binary_op->getOpcode() == Instruction::BinaryOps::Add) {
        auto * cop = binary_op->getOperand(1);
        if (auto * ci = dyn_cast<ConstantInt>(cop)) {
          int constant_off = ci->getZExtValue();
          MMIOReadCallGraphBackwardSlicing(func, visited, base_off, -constant_off, sz);
        }
      }
      
    } else {
      DEBUG("no offset?");
    }
  }
}

// collect all wrappers of indirect mmio read func call
void APStage2::collectIndirectMMIOReadWrappers(Module & m, std::set<Function*> & res) {
  // if this is a indirect call ...
  // callee is loaded from a struct variable
  for (auto * ci : indirectCalls) {
    Function * func = ci->getFunction();
    // INFO("Analyzing " << func->getName() << "...");
    Value * callee = ci->getCalledOperand()->stripPointerCasts();
    if (!isa<LoadInst>(callee)) {
      // DEBUG("collectIndirectMMIOReadWrappers: Callee is not loaded");
      continue;
    }
    LoadInst * load = (LoadInst*)callee;
    Value * src = load->getPointerOperand()->stripPointerCasts();
    int offset = -1;
    Type * t;
    if (auto * gep = dyn_cast<GetElementPtrInst>(src)) {
      t = gep->getSourceElementType();
      offset = getGEPOffset(gep);
    } else {
      t = src->getType();
      offset = 0;
    }
    if (!t->isStructTy()) {
      //DEBUG("collectIndirectMMIOReadWrappers: function ptr is not from a struct");
      // errs() << "GEP: " << *src << "\n";
      // auto * inst = (Instruction*)src;
      // inst->getDebugLoc().print(errs());
      // errs() << "\n";
      continue;
    }
    if (offset == -1) {
      //DEBUG("collectIndirectMMIOReadWrappers: GEP offset is not a constant");
      continue;
    }
    if (!valueIsReturned(ci)) {
      // DEBUG("Val not returned\n");
      continue;
    }
    // if this is a function that is a mmio wrapper
    // we need to resolve struct type alias here
    std::string st_name = getStructBaseName(t->getStructName().str());
    StructType * st = structTypes[st_name];
    assert(st && "struct type does not exist?");
    auto key = getTypeOffsetStr(st, offset);
    if (kmi2Funcs.find(key) != kmi2Funcs.end()) {
      for (auto * called_func : kmi2Funcs[key]) {
        auto & vec = mmioReadWrappers[called_func];
        int base = vec[0];
        int param_id = vec[1];
        int size = vec[2];
        int caller_param_id = param_id;

        // negative value means it is a constant offset
        if (param_id >= 0) {
          Value *arg_op = ci->getArgOperand(param_id);
          caller_param_id = getParamIndex(arg_op, func);
        }
        if (caller_param_id == -1) {
          DEBUG("No param id?");
          continue;
        }
        errs() << "Wrapper found: " << func->getName() << "\n";
        mmioReadWrappers[func] = {base, caller_param_id, size};
        res.insert(func);
      }
    }
  }
}



void APStage2::collectMMIOReadWrappers(Module & m) {
  identifyKMI(m);
  collectMMIOReadInterface();
  for (auto & p : kmi2Funcs) {
    errs() << "Read Interface: " << p.first << "  "; 
    for (auto * f : p.second) {
      errs() << f->getName() << " ";
    }
    errs() << "\n";
  }
  int oldsz1;
  int oldsz2;
  int newsz1;
  int newsz2;
  do {
    oldsz1 = mmioReadWrappers.size();
    oldsz2 = kmi2Funcs.size();
    std::set<Function*> res;
    std::set<Function*> visited;
    collectIndirectMMIOReadWrappers(m, res);
    for (auto * func : res) {
      auto & b_idx_sz = mmioReadWrappers[func];
      MMIOReadCallGraphBackwardSlicing(func, visited, b_idx_sz[0], b_idx_sz[1], b_idx_sz[2]);
    }
    newsz1 = mmioReadWrappers.size();
    newsz2 = kmi2Funcs.size();
  } while (oldsz1 != newsz1 || oldsz2 != newsz2);

}


int APStage2::findMMIOBaseOff(Value * mmio_ptr, Value ** base_ptr, Value ** offset_ptr) {
  Value * base;
  mmio_ptr = mmio_ptr->stripPointerCasts();
  if (auto * gep = dyn_cast<GetElementPtrInst>(mmio_ptr)) {
    base= gep->getPointerOperand()->stripPointerCasts();
    // if offset is a non-constant
    if (offset_ptr) {
      *offset_ptr = nullptr;
      auto op_start = gep->op_begin()+1;
      for (auto op_it = op_start; op_it != gep->op_end(); ++op_it) {
        Value * op = *op_it;
        if (!isa<Constant>(op)) {
          *offset_ptr = op;
        }
      }
    }
  } else if (auto * ld = dyn_cast<LoadInst>(mmio_ptr)) {
    base = ld;
  } else {
    DEBUG("findMMIOBaseOff: Unhandled Inst type");
    errs() << "Inst: " << *mmio_ptr << "\n";
    return -1;
  }
  if (!isa<LoadInst>(base)) {
    DEBUG("findMMIOBaseOff: Not a load inst");
    return -1;
  }
  LoadInst * base_load = (LoadInst*)base;
  /// X->y  pointer operand of load is a GEP instruction that locates field y
  Value * load_src = base_load->getPointerOperand()->stripPointerCasts();
  if (!isa<GetElementPtrInst>(load_src)) {
    DEBUG("findMMIOBaseOff: Load src is not a GEP");
    return -1;
  }
  GetElementPtrInst * struct_field_gep = (GetElementPtrInst*)load_src;
  int field_offset = getGEPOffset(struct_field_gep);
  if (field_offset == -1) {
    DEBUG("findMMIOBaseOff: field offset is not a constant, can't verify whether it is a MMIO base ptr");
    return -1;
  }
  Type * mmio_host_type = struct_field_gep->getSourceElementType();
  Value * mmio_host = struct_field_gep->getPointerOperand()->stripPointerCasts();
  if (base_ptr) {
    *base_ptr = mmio_host;
  }
  if (!isa<StructType>(mmio_host_type)) {
    if (isa<StructType>(mmio_host->getType())) {
      mmio_host_type = mmio_host->getType();
    } else {
      DEBUG("findMMIOBaseOff: MMIO ptr host is not a struct, weird");
      return -1;
    }
  }
  std::string key = getTypeOffsetStr(mmio_host_type, field_offset);
  if (mmioRegions.find(key) != mmioRegions.end()) {
    MMIORegionPtr & mrp = mmioRegions[key];
    return mrp.base_offset;
  } else {
    DEBUG("findMMIOBaseOff: MMIO host type not found");
  }
  return -1;
   
}

/// TODO: clean up the this code
int APStage2::findMMIO_Offset(CallInst * mmio) {
  Value * src = mmio->getNumArgOperands() == 1 ? 
                mmio->getArgOperand(0) : mmio->getArgOperand(1);
  src = src->stripPointerCasts();
  if (isa<CastInst>(src)) {
    src = static_cast<CastInst*>(src)->getOperand(0);
  }
  int offset;
  int res = -1;
  GetElementPtrInst * gep=nullptr;
  BinaryOperator * bin_op=nullptr;
  if ((gep = dyn_cast<GetElementPtrInst>(src))
      || (bin_op = dyn_cast<BinaryOperator>(src))) {
    // errs() << "gep: " << *gep << "\n";
    Value * ptr = nullptr;
    if (gep) {
      offset = getGEPOffset(gep);
      if (offset == -1) {
        errs() << "MMIO Offset is not constant\n";
        return -1;
      }
    /* find load instruction */
      ptr = gep->getPointerOperand()->stripPointerCasts();
    } else if (bin_op->getOpcode() == Instruction::Add) {
      Value * op1 = bin_op->getOperand(1);
      if (!isa<ConstantInt>(op1)) {
        errs() << "Add: MMIO Offset is not constant\n";
        return -1;
      }
      ConstantInt * ci = (ConstantInt*)op1;
      offset = ci->getZExtValue();
      ptr =  bin_op->getOperand(0)->stripPointerCasts();
    } else {
      errs() << "Unhandled Op\n";
      return -1;
    }
    if (auto *load = dyn_cast<LoadInst>(ptr)) {
      //  errs() << "load: " << *load << "\n";
      Value * load_src = load->getPointerOperand();
      if (!isa<GetElementPtrInst>(load_src)) {
        load_src = load_src->stripPointerCasts();

      }

      if (auto * gep_load = dyn_cast<GetElementPtrInst>(load_src)) {
        int field_offset = getGEPOffset(gep_load);
        if (field_offset != -1) {
          Type * gep_src_type = gep_load->getSourceElementType();
          if (!isa<StructType>(gep_src_type)) {
            gep_src_type = findStructTypeInUseChain(gep_load->getPointerOperand());
            if (!gep_src_type) {
              errs() << "GEP src not struct, conservatively set base_off to be 0\n";
              return offset;
            }
          }
          assert(isa<StructType>(gep_src_type));
          std::string key = getTypeOffsetStr(gep_src_type, field_offset);
          if (mmioRegions.find(key) != mmioRegions.end()) {
            MMIORegionPtr & mrp = mmioRegions[key];
            res = mrp.base_offset + offset;
            return res;
          } else {
            errs() << "MMIORegion Type can't be found\n";
            errs() << "field_off: " << field_offset << "\n";
            errs() << "inst: " << *gep_load << "\n";
          }
        } else {
          errs() << "MMIO Ptr GEP is not constant\n";
        }
      } else {
        errs() << "Load Src Not GEP: " << *((Instruction*)load_src) << "\n";
      }
    } else {
      errs() << "gep pointer is not loaded\n";
    }
   
    errs() << "conservatively set base_off to be 0\n";
    return offset;
   
  } else if (auto * ld = dyn_cast<LoadInst>(src)) {
    // 0 offset
    offset = 0;
    auto * ld_src = ld->getPointerOperand()->stripPointerCasts();
    if (auto * gep_load = dyn_cast<GetElementPtrInst>(ld_src)) {
        int field_offset = getGEPOffset(gep_load);
        if (field_offset != -1) {
          Type * gep_src_type = gep_load->getSourceElementType();
          if (!isa<StructType>(gep_src_type)) {
            errs() << "GEP src not struct, conservatively set base_off to be 0\n";
            return offset;
          }
          std::string key = getTypeOffsetStr(gep_src_type, field_offset);
          if (mmioRegions.find(key) != mmioRegions.end()) {
            MMIORegionPtr & mrp = mmioRegions[key];
            res = mrp.base_offset + offset;
            return res;
          } else {
            errs() << "MMIORegion Type can't be found\n";
          }
        } else {
          errs() << "MMIO Ptr GEP is not constant\n";
        }
      } else {
        errs() << "Load Src Not GEP: " << *((Instruction*)ld_src) << "\n";
      }
    errs() << "Case 2: conservatively set base_off to be 0\n";
    return offset;
  } else if (isa<Instruction>(src)) {
    errs() << "Not GEP: " << *src << "\n Loc: ";
    mmio->getDebugLoc().print(errs());
    errs() << "\n";
  } else {
    errs() << "Case 3: conservatively set base_off to be 0\n";
    return 0;
  }
  return res;
}

static bool getOffsetSizeInMMIOReadCall(CallInst * ci, std::vector<int> &vec, std::vector<int> & off_sz) {
  int param_id = vec[1];
  int sz = vec[2];
  int base = vec[0];
  off_sz[1] = sz;
  if (param_id < 0) {
    int constant_offset = -param_id;
    off_sz[0] = base + constant_offset;
  } else {
    // need to retrive the offset value
    // if it is not a constant, give up
    auto * offset_val = ci->getArgOperand(param_id);
    if (auto * off_const = dyn_cast<ConstantInt>(offset_val)) {
      uint64_t off = off_const->getZExtValue();
      off_sz[0] = base + off;
    } else {
      return false;
    }
  }
  return true;
}


void APStage2::collectMMIOReadSources(std::unordered_map<Value*, std::vector<std::vector<int>>> & res) {
  // resolve indirect calls
  for (auto * ci : indirectCalls) {
    Value * callee = ci->getCalledOperand()->stripPointerCasts();

    if (!isa<LoadInst>(callee)) {
      // INFO("Not load");
      // INFO(*ci);
      continue;
    }
    LoadInst * load = (LoadInst*)callee;
    Value * src = load->getPointerOperand()->stripPointerCasts();
    int offset = -1;
    Type * t;
    GetElementPtrInst *gep = nullptr; 
    if ((gep = dyn_cast<GetElementPtrInst>(src))) {
      t =  gep->getSourceElementType();
      offset = getGEPOffset(gep);
    } else {
      t = src->getType();
      offset = 0;
    }
    if (t->isPointerTy()) {
      t = getPointerBaseType(t);
    }
    
    std::set<Function*> funcs;
    std::string key = "None";
    if (t->isStructTy() && offset != -1) {
      std::string st_name = getStructBaseName(t->getStructName().str());
      StructType * st = structTypes[st_name];
      assert(st && "struct type does not exist?");
      key = getTypeOffsetStr(st, offset);
    }

    if (kmi2Funcs.find(key) != kmi2Funcs.end()) {
      // resolve the indirect call here
        funcs = kmi2Funcs[key];
    } else if (enable_type_based_func_res
              && type2Funcs.find(load->getType()) != type2Funcs.end()) {
      DEBUG("Resolving using type based analysis...");
      funcs = type2Funcs[load->getType()];
    }

    for (auto * resolved_callee: funcs) {
      // if this is a mmio read wrapper
      if (mmioReadWrappers.find(resolved_callee) != mmioReadWrappers.end()) {
        ci->getDebugLoc().print(errs());
        errs() << "\n";
        DEBUG("Resolved callee: " << resolved_callee->getName());
        std::vector<int> & vec = mmioReadWrappers[resolved_callee];
        std::vector<int> offset_sz = {-1, 0};
        bool ok = getOffsetSizeInMMIOReadCall(ci, vec, offset_sz);
        if (!ok) {
          DEBUG("In function: " << ci->getFunction()->getName() << " calling " << resolved_callee->getName() <<
            "offset is not a constant... ");
        } else {
          // we are good
          res[ci].push_back(offset_sz);
          bbIOReadCnt[ci->getParent()] += 1;
        }
      }
    }
  }
  // regular calls
  for (auto * ci : callInsts) {
    Function * f = ci->getCalledFunction();
    if (!f) {
      auto * callee = ci->getCalledOperand()->stripPointerCasts();
      if (isa<Function>(callee)) {
        f = (Function*)callee;
      } else {
        continue;
      }
    }
    
    if (mmioReadWrappers.find(f) != mmioReadWrappers.end()) {
      std::vector<int> & vec = mmioReadWrappers[f];
      std::vector<int> offset_sz = {-1, 0};
      bool ok = getOffsetSizeInMMIOReadCall(ci, vec, offset_sz);
      if (!ok) {
        DEBUG("In function: " << ci->getFunction()->getName() << " calling " << f->getName() <<
            "offset is not a constant... ");
      } else {
        // we are good
        res[ci].push_back(offset_sz);
        bbIOReadCnt[ci->getParent()] += 1;
      }
    }
  }

  for (auto * ci : callIoReads) {
    int offset = findMMIO_Offset(ci);
    int size = ci->getType()->getScalarSizeInBits() / 8;
    if (offset != -1) {
      res[ci].push_back({offset, size});
      bbIOReadCnt[ci->getParent()] += 1;
    }
  }
}

void APStage2::extractMMIOFieldConstraint() {
  std::unordered_map<Value*, std::vector<std::vector<int>>> mmio_reads;
  collectMMIOReadSources(mmio_reads);
  cntFunctionIOReads();
  for (auto & p : mmio_reads) {
    CallInst * ci = (CallInst*)p.first;

    for (auto & off_sz : p.second) {
      int offset = off_sz[0];
      int size = off_sz[1];
      assert(offset != -1);
      if (Function * callee = ci->getCalledFunction()) {
        errs() << "\nCalled Function : " << callee->getName() << "\n";
      } else {
        errs() << "\n";
      }
      errs() << "MMIO Read: ";
      ci->getDebugLoc().print(errs());
      errs() << *ci << "\n";
      errs() << "\nOFFSET: " << offset <<  " SIZE: " << size << "\n";
      errs() << "Results:\n";
      
      auto * builder = new FieldConstraintBuilder("mmio", offset, ci);
      builder->buildConstraints();
      auto & cstrs = builder->getResults();
      
      if (!cstrs.size()) {
        delete builder;
        continue;
      }

      if (cstrs.empty()) {
        continue;
      }

      HWInput * hw_input;
      if (mmioModel.find(offset) == mmioModel.end()) {
        hw_input = &mmioModel[offset];
        hw_input->setOffset(offset);
        hw_input->setSize(size);
      } else {
        hw_input = &mmioModel[offset];
      }

      for (auto * expr : cstrs) {
        errs() << expr->str() << "\n";
        genHWInputConstraint(expr, *hw_input);
      }

      delete builder;
    }
  }
}

void APStage2::genStage2ModelInitCode(const std::string & model_name) {
  std::string code;
  code += "unordered_map<int, HWInput> mmio_mdl =\n{\n";
  for (auto & pair : mmioModel) {
    int offset = pair.first;
    HWInput & hwi = pair.second;
    if (hwi.empty()) {
      WARN("Empty MMIO Model\n");
      continue;
    }
    hwi.process();
    auto head = "{" + std::to_string(offset) + " , ";
    code += head + hwi.genModelInitCode(head.length());
    code += "},\n";
  }
  code += "};\n\n";

  code += "vector<DMAInputModel> dma_mdl = {\n";
  for (auto & p : dmaModel) {
    StructType * t = (StructType*)(p.first);
    int buflen = dmaType2DMABufferLengths[t];
    int struct_len = getStructSize(t);
    auto & mdl = p.second;
    code += "DMAInputModel(" + std::to_string(buflen) + "," + std::to_string(struct_len) + ", {\n";
    for (auto & pair : mdl) {
      int offset = pair.first;
      auto & hwi = pair.second;
      if (hwi.empty()) {
        WARN("Empty DMA Model\n");
        continue;
      }
      hwi.process();
      code += "{" + std::to_string(offset) + " , " + hwi.genModelInitCode(0) + "},\n";
    }
    code += "}),\n";
  }
  code += "};\n";
  code += "auto * model = new Stage2HWModel(\"" + model_name + "\", mmio_mdl, dma_mdl);\n";
  errs() << code;
}

void APStage2::extractDMAFieldConstraint(Value * v, TypeOffset type_offset) {
  std::vector<Expression*> res;
  std::unordered_map<Value*, Expression*> val2expr;
  auto sname = (type_offset.type)->getStructName().str();
  int offset = type_offset.offset;
  int size = v->getType()->getScalarSizeInBits() / 8;

  /* print some debug info */
  if (isa<Instruction>(v)) {
    Instruction * inst = (Instruction*)v;
    inst->getDebugLoc().print(errs());
    errs() << "\n IR: " << *inst << "\n";
  } 

  auto * builder = new FieldConstraintBuilder(sname, offset, v);
  builder->buildConstraints();
  auto & cstrs = builder->getResults();

  if (cstrs.empty()) {
    return;
  }
  auto & dma_mdls = dmaModel[type_offset.type];
  
  HWInput * hw_input;
  if (dma_mdls.find(offset) == dma_mdls.end()) {
    hw_input = &dma_mdls[offset];
    hw_input->setOffset(offset);
    hw_input->setSize(size);
  } else {
    hw_input = &dma_mdls[offset];
  }

  errs() << "Results:\n";
  for (auto * expr : cstrs) {
    genHWInputConstraint(expr, *hw_input);
    errs() << expr->str() << "\n";
  }
  errs() << "\n";
}

bool APStage2::APStage2Pass(Module &module) {
  m_ = &module;
  // identifyKMI(module);
  errs() << ANSI_COLOR_CYAN << "--- PROCESS FUNCTIONS ---" << ANSI_COLOR_RESET
         << "\n";
  // Step 1, process CallInst
  errs() << ANSI_COLOR_GREEN << "Collect CallInst" << ANSI_COLOR_RESET << "\n";
  for (Module::iterator fi = module.begin(), f_end = module.end(); fi != f_end;
       ++fi) {
    Function *func = dyn_cast<Function>(fi);
    if (func->isDeclaration() || func->isIntrinsic())
      continue;
    for (Function::iterator fi = func->begin(), fe = func->end(); fi != fe;
         ++fi) {
      BasicBlock *bb = dyn_cast<BasicBlock>(fi);
      for (BasicBlock::iterator ii = bb->begin(), ie = bb->end(); ii != ie;
           ++ii) {
        if (auto *ci = dyn_cast<CallInst>(ii)) {
          drawCallGraph(ci);
          processCall(ci);
        }
        if (auto *st = dyn_cast<StoreInst>(ii)) {
          processStore(st);
          identifyKMIByStore(st);
        }
      }
    }
  }
  // Step 2, DMA buffer value either store to global value or to some struct
  // field
  errs() << "==================\n";
  for (auto *ci : callDmaAlloc) {
    /* 
     * TODO(Yilun)
     * Deal with store -> load -> store pattern ?
     */
    findPointerStoredToType(ci, dmaAddrStoreDst, dmaBufferTypes);
    tryFindDMATypeByCast(ci, dmaBufferTypes);
    // Map Loc to DMA Length
    Value * sz_v = ci->getArgOperand(1);
    ConstantInt * sz_c = dyn_cast<ConstantInt>(sz_v);
    int len = 0;
    if (!sz_c) {
      WARN("dma_alloc_coherent() size is not constant");
    } else {
      len = (int)(sz_c->getZExtValue());
    }
    for (auto & type_offset : dmaAddrStoreDst) {
      typeOffset2DMABufferLengths[type_offset] = len;
    }
    for (auto * t : dmaBufferTypes) {
      dmaType2DMABufferLengths[t] = len;
    }

  }
  // if (!dmaBufferTypes.size()) {
  errs() << "======= Type Discovery Phase 2 ===========\n";
  for (auto & s : dmaAddrStoreDst) {
    errs() << s << "\n";
  }
  findMemRegionTypeByCast(dmaAddrStoreDst, dmaBufferTypes);
  // }
  errs() << "Total number of DMA Buffer Types: " << dmaBufferTypes.size() << "\n";
  for (auto * t : dmaBufferTypes) {
      INFO("DMA Buffer Type: " << t->getStructName());
  }

  errs() << "==================\n";
  // Step 3, MMIO PIO Address either store to global value or to some struct
  // field
  for (auto *ci : callIoMap) {
#if (LLVM_VERSION_MAJOR <= 10)
    Value *cv = ci->getCalledValue();
#else
    Value *cv = ci->getCalledOperand();
#endif
    Function *bcf = dyn_cast<Function>(cv->stripPointerCasts());
    auto name = bcf->getName();
    // ci->getDebugLoc().print(errs());
    if (name.startswith("pcim_iomap_table")) { 
      Value * v = processPCIM_IOMAP(ci);
      if (v) {
        deviceMemAddr.insert(v);
      }
    } else {
      deviceMemAddr.insert(ci);
    }
  }

  errs() << "=========Secondary DMA Search============\n";
  for (auto * ci : callDmaAllocPage) {
    findDMAPageAddrOffset(ci, 4096);
  }
  for (auto & p : dmaPhyAddrToDMASz) {
    findDMAPageAddrOffset(p.first, p.second);
  }

  collectDMAReads();

  errs() << "========Finding MMIO Ptrs=============\n";
  findMMIORegionPtrs();
  errs() << "========Extracting MMIO Read Wrappers=============\n";
  collectMMIOReadWrappers(*m_);
  for (auto & p : mmioReadWrappers) {
    Function * f = p.first;
    std::vector<int> & base_id_sz = p.second;
    errs() << "MMIO wrapper: " << f->getName().str() << "\n";
    errs() << "base: " << base_id_sz[0] << " ";
    errs() << "offset: ";
    if (base_id_sz[1] < 0) {
      errs() << " constant " << -base_id_sz[1] << " ";
    } else {
      errs() << " arg " << base_id_sz[1] << " ";
    }
    errs() << "size " << base_id_sz[2] << "\n";
  }
  errs() << "=========Construct Field Constraint============\n";
  extractMMIOFieldConstraint();
  for (auto & pair : dmaReads) {
    Value * dma_val = pair.first;
    TypeOffset & type_offset = pair.second;
    extractDMAFieldConstraint(dma_val, type_offset);
  }
  errs() << "=========Stage2 Model Init Code============\n";
  genStage2ModelInitCode("XXX");
  genSecondaryDMAInitCode();
  errs() << ANSI_COLOR_CYAN << "--- DONE! ---" << ANSI_COLOR_RESET << "\n";

  // just quit
  exit(0);
  // never reach here
  return false;
}

static RegisterPass<APStage2>
    XXX("apstage2", "APStage2 Pass (with getAnalysisUsage implemented)", false,
        false);
