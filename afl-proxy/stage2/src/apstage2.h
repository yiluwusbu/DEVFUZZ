/*
 * 2022 Tong Zhang<ztong0001@gmail.com>
 * 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
 */
#ifndef _AP_STAGE2_ANALYZER_H_
#define _AP_STAGE2_ANALYZER_H_

#include <fstream>
#include <unordered_map>
#include <sstream>
#include <stack>
#include "hw_input_model.h"
#include "color.h"
#include "llvm-c/Core.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Analysis/AliasSetTracker.h"
#include "llvm/Analysis/GlobalsModRef.h"
#include "llvm/Analysis/MemoryBuiltins.h"
#include "llvm/Analysis/ScalarEvolution.h"
#include "llvm/Analysis/ScalarEvolutionAliasAnalysis.h"
#include "llvm/Analysis/TargetLibraryInfo.h"
#include "llvm/Analysis/ValueTracking.h"
#include "llvm/IR/CFG.h"
#if (LLVM_VERSION_MAJOR <= 10)
#include "llvm/IR/CallSite.h"
#endif
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/GetElementPtrTypeIterator.h"
#include "llvm/IR/GlobalValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Operator.h"
#include "llvm/IR/Use.h"
#include "llvm/IR/ValueMap.h"
#include "llvm/Pass.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/Instrumentation.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"
#include "llvm/IR/InlineAsm.h"

#define DEBUG_TYPE "apstage2"
#define DEBUG_ON 1

#define WARN(X)                                                                \
  errs() << ANSI_COLOR_YELLOW << "WARN:" << X << ANSI_COLOR_RESET << "\n"

#define ERROR(X)                                                               \
  errs() << ANSI_COLOR_RED << "ERROR:" << X << ANSI_COLOR_RESET << "\n"

#define INFO(X) outs() << ANSI_COLOR_CYAN << "INFO:" << X << ANSI_COLOR_RESET << "\n"

#define DEBUG(X) if (DEBUG_ON) { errs() << ANSI_COLOR_GREEN << X << ANSI_COLOR_RESET << "\n"; }

#define unreachable(XXX)                                                       \
  {                                                                            \
    errs() << ANSI_COLOR_RED << __FILE__ << ":" << __LINE__ << " " << XXX      \
           << ANSI_COLOR_RESET << "\n";                                        \
    throw;                                                                     \
  }

using namespace llvm;

/* helper function */
void collectValueAlias(Value * v, std::set<Value*> & alias, std::set<Value*> & visited);

std::string getTypeOffsetStr(Type * tp, int offset) {
  return tp->getStructName().str() + "##" + std::to_string(offset);
}

Type * getPointerBaseType(Type * t) {
  while (t->isPointerTy()) {
    t = t->getPointerElementType();
  }
  return t;
}

std::string getStructBaseName(const std::string & s) {
  size_t i;
  int dot_cnt = 0;
  for (i=0; i<s.length(); i++) {
    if (s[i] == '.') {
      dot_cnt++;
    }
    if (dot_cnt == 2) {
      break;
    }
  }
  if (dot_cnt == 2) {
    return s.substr(0, i);
  }
  return s;
}

Function * getCalledFunction(CallInst * call) {
  Function * f;
  f = call->getCalledFunction();
  if (!f) {
    auto * callee = call->getCalledOperand()->stripPointerCasts();
    if (isa<Function>(callee)) {
      return (Function*)callee;
    }
  } else {
    return f;
  }
  return nullptr;
}

StructType *findGlobalValueStructType(GlobalVariable * gv, Module & m) {
  for (auto * u : gv->users()) {
    //errs() << "user: " << *u << "\n";

    Type * casted_type = u->getType();
    if (casted_type->isPointerTy()) {
      casted_type = getPointerBaseType(casted_type);
    }
    if (isa<StructType>(casted_type)) {
      StructType * st = (StructType*) casted_type;
      auto name = st->getStructName();
      // INFO("NAME:" << name);
      if (!name.empty()) {
        return st;
      }
    } else {
      errs() << "Type not struct?\n";
    }
    
  }

  return nullptr;
}

// Just to handle some opt bug in LLVM code
uint64_t getConstantLoaded(Value * addr) {
  for (auto * u : addr->users()) {
    if (StoreInst * st = dyn_cast<StoreInst>(u)) {
      Value * v = st->getValueOperand();
      if (auto * c = dyn_cast<ConstantInt>(v)) {
        return c->getZExtValue();
      }
    } else if (isa<CastInst>(u)) {
      getConstantLoaded(u);
    }
  }
  return -1;
}

struct TypeOffset {
  Type * type;
  int offset;
};

struct MMIORegionPtr {
  Type * host_type;
  int  host_offset;
  int base_offset;
};

struct FieldConstraint {
  Type * type;
  int offset;
  int size;
  Expression * expr;
};



class APStage2 : public ModulePass {
public:
  
private:
  virtual bool runOnModule(Module &) override;
  void processCall(CallInst *);
  void processStore(StoreInst *);
  Value *processPCIM_IOMAP(Value *ci);
  bool isLLVMPrefix(Value *);
  AliasAnalysis *AA;
  std::vector<CallInst *> callInsts;
  std::vector<CallInst *> callDmaAlloc;
  std::vector<CallInst *> callDmaAllocPage;
  std::vector<CallInst *> callIoWrite;
  std::vector<CallInst *> callIoReads;
  std::vector<CallInst *> indirectCalls;
  // map device PIO/MMIO region
  std::vector<CallInst *> callIoMap;
  // for storeInst(ioaddr, PointerOperand), we collect PointerOperand
  std::set<Value *> deviceMemAddr;
  // for storeInst(dmaBuffer, PointerOperand), we collect PointerOperand
  std::set<Value *> dmaBufferAddr;
  std::set<Type *> dmaBufferTypes;
  std::set<std::string> dmaAddrStoreDst;
  std::unordered_map<std::string, int> typeOffset2DMABufferLengths;
  std::unordered_map<Type*, int> dmaType2DMABufferLengths;
  std::unordered_map<Type*, std::unordered_map<int, int>> secondDMABufferOffSz;
  // store instructions that store something to device
  std::vector<StoreInst *> mmioSt;
  std::unordered_map<std::string, struct MMIORegionPtr> mmioRegions;
  std::unordered_map<Value*, int> mmioReads;
  std::unordered_map<Value*, TypeOffset> dmaReads;  /* Value : Type::Offset */
  std::vector<FieldConstraint> fieldConstraints;
  std::unordered_map<int, HWInput> mmioModel;
  std::unordered_map<Type*, std::unordered_map<int, HWInput>> dmaModel;
  std::unordered_map<Function*, std::vector<int>> mmioReadWrappers; // func -> base, offset param id, size
  std::unordered_map<Value*, std::vector<CallInst*>> funcCallSites;
  std::unordered_map<Function*, std::vector<TypeOffset>> func2KMI;
  std::unordered_map<std::string, std::set<Function*>> kmi2Funcs;
  std::unordered_map<std::string, StructType*> structTypes;
  std::unordered_map<BasicBlock*, int> bbIOReadCnt;
  std::unordered_map<Function*, int> funcIOReadCnt;
  std::unordered_map<Type*, std::set<Function*>> type2Funcs;
  std::unordered_map<Value*, int> dmaPhyAddrToDMASz;
  bool enable_type_based_func_res;
  void identifyKMI(Module &module);
  void identifyKMIByStore(StoreInst *st);
  int getStructSize(StructType * t);
  bool findTypeOffsetAlias(Type * t, int offset, TypeOffset & result);
  void findMemRegionTypeByCast(std::set<std::string> & srcs, 
                                  std::set<Type *> & results); 
  Type * findStructTypeByStore(Value * src);
  Type * findStructTypeCasted(Value * v);
  Type * findStructTypeInUseChain(Value * v); 
  void tryFindDMATypeByCast(Value * dma_alloc, std::set<Type *> & results);
  void findPointerStoredToType(Value *v, std::set<std::string> & srcs, 
                                        std::set<Type *> & results);
  int findMMIO_Offset(CallInst * mmio);
  Type *findStructMemberTypeInSubclass(StructType * super_clas_type, int offset, Value * super_class_ptr);
  void doFindMMIORegionPtrs(Value * mmio_ptr, int base_off);
  void findMMIORegionPtrs();
  void collectMMIOReadInterface();
  void collectMMIOReadWrappers(Module & m);
  void collectIndirectMMIOReadWrappers(Module & m, std::set<Function*> & res);
  bool valueIsReturned(Value * v);
  void MMIOReadCallGraphBackwardSlicing(Function *v, std::set<Function*> & visited, int base, int offset_param_id, int size);
  int findMMIOBaseOff(Value * v, Value ** base_ptr, Value ** offset_ptr);
  int getParamIndex(Value * v, Function * f);
  void genSecondaryDMAInitCode();
  bool buildExpr(Value * inst, Expression * prev_expr, Expression * prev_bb_expr, 
                        std::vector<Expression*> & res, std::unordered_map<Value*, Expression*> & val2expr);
  void extractDMAFieldConstraint(Value * v, TypeOffset type_offset);
  void genStage2ModelInitCode(const std::string & model_name);
  void collectDMAReads();
  void drawCallGraph(CallInst * ci);
  void extractMMIOFieldConstraint();
  void collectLoadStoreStruct(Value *, std::set<Value *> &);
  void collectLoadFromAddress(Value *, std::vector<Value *> &);
  void collectStoreOfValue(Value *, std::vector<Value *> &);
  bool isGEPFromSameStructField(Value *, std::set<Value *> &);
  bool isLoadedFromAddress(Value *, std::set<Value *> &);
  bool isLoadedFromSameStructField(Value *, std::set<Value *> &);
  void __findDMAPageAddrOffset(Value * page_addr, std::set<Value*>visited, int sz);
  void findDMAPageAddrOffset(Value * page_addr, int sz);
  void collectMMIOReadSources(std::unordered_map<Value*, std::vector<std::vector<int>>>& );
  void __collectAliasPassedAsParam(Value *, std::set<Value*> & , std::set<Function*> & ); 
  void collectAliasPassedAsParam(Value * v, std::set<Value*> &);
  void cntFunctionIOReads();
  int getGEPOffset(GetElementPtrInst * gep) {
    APInt apint(64, 0);
    bool is_constant;
    is_constant = gep->accumulateConstantOffset(m_->getDataLayout(), apint);
#if 1
    if (is_constant) {
      return (int)(apint.getZExtValue());
    } else {
      // deal with a bug in clang/LLVM
      auto * off = gep->getOperand(1)->stripPointerCasts();
      if (auto * cast = dyn_cast<CastInst>(off)) {
        off = cast->getOperand(0);
      }
      if (auto * ld = dyn_cast<LoadInst>(off)) {
        INFO("YES!!!!!!!!!!");
        uint64_t c = getConstantLoaded(ld->getPointerOperand()->stripPointerCasts());
        return (int)c;
      }
      return -1;
    }
#else
    return is_constant ? (int)(apint.getZExtValue()) : -1;
#endif
  }

  int getStructMemberOffset(GetElementPtrInst * gep);


public:
  static char ID;
  APStage2() : ModulePass(ID){ enable_type_based_func_res =true; };

  virtual StringRef getPassName() const override { return "apstage2"; }
  bool APStage2Pass(Module &module);

  virtual void print(raw_ostream &OS, const Module *M) const override {
    OS << "Analysis Result\n";
  }

  void getAnalysisUsage(AnalysisUsage &au) const override {
    ModulePass::getAnalysisUsage(au);
    // au.addRequired<AAResultsWrapperPass>();
    // au.addRequired<TargetLibraryInfoWrapperPass>();
    // au.addRequired<ScalarEvolutionWrapperPass>();
    au.setPreservesAll();
  }

private:
  Module * m_;
};

class FieldConstraintBuilder {
public:
  FieldConstraintBuilder(const std::string & name, int off, Value * hw_input) {
    offset = off;
    struct_name = name;
    hw_input_src = hw_input;
    Type * field_type = hw_input->getType();
    size_in_bytes = field_type->getScalarSizeInBits() / 8;
    hw_value_expr = new ValueExpr(name, off, size_in_bytes);
  }

  Expression * buildPredExprTopDown(int level);
  void buildPreds(Value * hw_input_op, std::set<Value*> & visited);
  void buildConstraints();
  std::vector<Expression*> & getResults() { return results; }
 
private:
  std::string struct_name;
  int offset;
  int size_in_bytes;
  Value * hw_input_src;
  ValueExpr * hw_value_expr;
  std::vector<Value*>  path;
  std::unordered_map<Instruction*, Expression*> preds;
  std::vector<Expression*> results;
  std::unordered_map<BasicBlock*, BranchInst*> bb2branch;
};


#endif //_AP_STAGE2_ANALYZER_H_
