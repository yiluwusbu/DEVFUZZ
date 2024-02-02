/*
 * PeX S2E Plugin
 * Hookup device memory region (pio/mmio) and do symbolic execution
 * 2020 Tong Zhang <ztong0001@gmail.com>
 */
#include <s2e/ConfigFile.h>
#include <s2e/S2E.h>
#include <s2e/Utils.h>
#include <s2e/cpu.h>

#include <s2e/Plugins/OSMonitors/OSMonitor.h>
#include <s2e/Plugins/OSMonitors/Support/ModuleMap.h>
#include <s2e/Plugins/OSMonitors/Support/ProcessExecutionDetector.h>

#include <s2e/SymbolicHardwareHook.h>

#include <cstdio>
#include <llvm/ADT/DenseSet.h>
#include "PeX.h"

/* for KVM_SET_USER_MEMORY_REGION */
struct kvm_userspace_memory_region {
    __u32 slot;
    __u32 flags;
    __u64 guest_phys_addr;
    __u64 memory_size;    /* bytes */
    __u64 userspace_addr; /* start of the userspace allocated memory */
};

namespace s2e {
namespace plugins {

// type, size
static uint64_t bar_configuration[6][2] = {{BAR_TYPE_PIO, 0xfffff800},  {BAR_TYPE_MMIO, 0xfff80000},
                                           {BAR_TYPE_MMIO, 0xfff80000}, {BAR_TYPE_MMIO, 0xfff80000},
                                           {BAR_TYPE_MMIO, 0xfff80000}, {BAR_TYPE_MMIO, 0xfff80000}};

S2E_DEFINE_PLUGIN(PeX, "PeX S2E plugin", "", );

#include "pexcb.h"

void PeX::initBarMMIO() {
    for (int i = 0; i < 6; i++) {
        auto BAR_HMASK = bar_configuration[i][1];
        int size = ~BAR_HMASK + 1;
        // must be 4k aligned
        auto *mchunk = (uint8_t *) memalign(4096, size);
        barMMIO.push_back(mchunk);
    }
}

void PeX::initialize() {
    processBarConfiguration();

    initBarMMIO();
    os_monitor = static_cast<OSMonitor *>(s2e()->getPlugin("OSMonitor"));
    getDebugStream(g_s2e_state) << " dmesg addr = " << hexval(os_monitor->getDmesgAddress())
                                << " len= " << hexval(os_monitor->getDmesgLen()) << "\n";
    // configs specified by user
    auto *config = s2e()->getConfig();

    m_with_afl = config->getBool(getConfigKey() + ".withAFL");
    m_inject_irq_per_xxx_ins = config->getInt(getConfigKey() + ".irq_inject_per_x_ins");

    // m_traceBlockTranslation = config->getBool(getConfigKey() + ".traceBlockTranslation");
    // m_traceBlockExecution = config->getBool(getConfigKey() + ".traceBlockExecution");
    // m_killWhenNotInRange = config->getBool(getConfigKey() + ".killWhenNotInRange");
    m_delay_enable_symbhw = config->getInt(getConfigKey() + ".delayEnableSymbHW");
    m_printAllPortAccess = config->getBool(getConfigKey() + ".printAllPortAccess");
    reg_vid = config->getInt(getConfigKey() + ".VID");
    reg_pid = config->getInt(getConfigKey() + ".PID");
    reg_class = config->getInt(getConfigKey() + ".CLASS");
    reg_bhlc = config->getInt(getConfigKey() + ".BHLC");

    reg_sub_vid = config->getInt(getConfigKey() + ".SUBVID");
    reg_sub_pid = config->getInt(getConfigKey() + ".SUBPID");
    use_capability = config->getBool(getConfigKey() + ".USECAPABILITY");

    // set the device location on the bus
    n_bus = (uint8_t) config->getInt(getConfigKey() + ".SYMDEV_BUS") & 0xff;
    if (n_bus == 0)
        n_bus = SYMDEV_BUS;
    n_device = (uint8_t) config->getInt(getConfigKey() + ".SYMDEV_DEV") & 0xff;
    if (n_device == 0)
        n_device = SYMDEV_DEV;
    n_function = (uint8_t) config->getInt(getConfigKey() + ".SYMDEV_FUNC") & 0xff;
    if (n_function == 0)
        n_function = SYMDEV_FUNC;
    // this is actually the vector(int) not IRQ -- since PIC will map IRQ to vector
    // and figure out ISR using IDT + vector
    irq = config->getInt(getConfigKey() + ".interrupt");

#if 0
    // processPCRange();
    // processTargetStackInfo();
#endif
    auto *plugin = s2e()->getCorePlugin();
    // PORT access hook
    plugin->onPortAccess.connect(sigc::mem_fun(*this, &PeX::slotOnPortAccess));
    // MMIO hook
    g_symbolicPortHook = SymbolicPortHook(_isPortSymbolic, symbolicPortRead, symolicPortWrite, this);
    g_symbolicMemoryHook = SymbolicMemoryHook(_isMmioSymbolic, symbolicMMIORead, symbolicMMIOWrite, this);

    if (m_with_afl) {
        openAFLProxySHMBlock();
        plugin->onStateKill.connect(sigc::mem_fun(*this, &PeX::slotOnStateKill));
        // hook bb start
        plugin->onTranslateBlockStart.connect(sigc::mem_fun(*this, &PeX::slotTranslateBlockStart));
    }
#if 0
    // hook bb end to capture call/jump
     plugin->onTranslateBlockEnd.connect(
            sigc::mem_fun(*this, &PeX::slotTranslateBlockEnd));
#endif
    // monitor all instruction execution
    if (irq != -1)
        plugin->onTranslateInstructionStart.connect(sigc::mem_fun(*this, &PeX::onTranslateInstructionStart));
    // monitor all memory access
    // plugin->onConcreteDataMemoryAccess.connect(sigc::mem_fun(*this, &PeX::slotOnConcreteDataMemoryAccess));
    // plugin->onBeforeSymbolicDataMemoryAccess.connect(sigc::mem_fun(*this, &PeX::onBeforeSymbolicDataMemoryAccess));
}

// called after g_s2e_state is available
void PeX::pluginInit2(S2EExecutionState *state) {
    auto *mem = state->mem();
    // set initial PCI config data
    auto &pci_header = mem->sfpPCIDeviceHeader;
    // bar registers
    pci_header.reg[PCI_CONFIG_DATA_REG_BAR0] = bar_configuration[0][0];
    pci_header.reg[PCI_CONFIG_DATA_REG_BAR1] = bar_configuration[1][0];
    pci_header.reg[PCI_CONFIG_DATA_REG_BAR2] = bar_configuration[2][0];
    pci_header.reg[PCI_CONFIG_DATA_REG_BAR3] = bar_configuration[3][0];
    pci_header.reg[PCI_CONFIG_DATA_REG_BAR4] = bar_configuration[4][0];
    pci_header.reg[PCI_CONFIG_DATA_REG_BAR5] = bar_configuration[5][0];

    // VID and PIC
    pci_header.reg[PCI_CONFIG_DATA_REG_0] = (reg_pid << 16) | reg_vid;
    // Status and Command
    uint16_t reg_status = 0;
    if (use_capability)
        reg_status |= (1 << 4);
    uint16_t reg_cmd = 0;
    pci_header.reg[PCI_CONFIG_DATA_REG_1] = (reg_status << 16) | reg_cmd;
    // Class code/Subclass
    pci_header.reg[PCI_CONFIG_DATA_REG_2] = reg_class;
    // BIST | Header type | Latency Timer | Cache Line Size
    pci_header.reg[PCI_CONFIG_DATA_REG_3] = reg_bhlc;
    // card bus ptr
    pci_header.reg[PCI_CONFIG_DATA_REG_A] = 0xffffffff;
    // Subsystem ID, Subsystem Vendor ID
    pci_header.reg[PCI_CONFIG_DATA_REG_B] = (reg_sub_pid << 16) | reg_sub_vid;
    // expansion rom -- currently not supported
    pci_header.reg[PCI_CONFIG_DATA_REG_C] = 0xffffffff;
    // Reserved	Capabilities Pointers
    if (use_capability) {
        // capability pointer are last 8 bits
        // we want the capability list offset to be put at 0x50 of pci_header.reg
        // linux/drivers/pci/pci.c PCI_CAPABILITY_LIST, __pci_bus_find_cap_start
        // setup Express
        int cap_offset = 0x50; // this is byte address
        int cap_offset_next = 0x70;
        pci_header.reg[PCI_CONFIG_DATA_REG_D] = 0xffffff00 | cap_offset;
        pci_header.reg[cap_offset >> 2] = 0x00000010 | (cap_offset_next << 8);
        // setup Power cap
        cap_offset = cap_offset_next;
        cap_offset_next = 0x90; // the next offset is at 0x90
        pci_header.reg[cap_offset >> 2] = 0x00000001 | (cap_offset_next << 8);
        // setup MSI
        cap_offset = cap_offset_next;
        cap_offset_next = 0xc0; // the next offset is at 0xc0
        pci_header.reg[cap_offset >> 2] = 0x00000005 | (cap_offset_next << 8);
        // setup MSI-X
        cap_offset = cap_offset_next;
        cap_offset_next = 0x00;
        // pci_header.reg[cap_offset >> 2] = 0x00010011 | (cap_offset_next << 8);
        pci_header.reg[cap_offset >> 2] = 0x00000011 | (cap_offset_next << 8);
        // use offset 0x100 at MMIO bar 4 as MSI-X table
        // the table is at 256 offset so bar 4 should be at least 4k
        pci_header.reg[(cap_offset >> 2) + 1] = (0x100 << 3) | 4;
        // FIXME: for MSI-X we need to set the table concrete, making the bar
        // symbolic will not work
    } else {
        pci_header.reg[PCI_CONFIG_DATA_REG_D] = 0xffffffff;
    }
    // Reserved -- always concrete
    pci_header.reg[PCI_CONFIG_DATA_REG_E] = 0xffffffff;
    // PCI devices are always connected to INT PIN 2 in QEMU
    // this register will always be concrete
    // get IRQ number from /proc/interrupt in guestos
    pci_header.reg[PCI_CONFIG_DATA_REG_F] = 0x000002ff;
}

//////////////////////////////////////////////////////////////////////////
bool PeX::isPortSymbolic(S2EExecutionState *state, uint16_t port) {
    static int count = m_delay_enable_symbhw;
    if (count != 0) {
        count--;
        if (count == 0)
            getDebugStream(state) << " PeX ... start Symbolic HW on port PCI_CONFIG*\n";
        return false;
    }
    switch (port) {
        case PCI_CONFIG_ADDRESS_PORT ... PCI_CONFIG_DATA_PORT_END:
            return true;
        default:
            break;
    }
    // port falls into bar mapped to IO address space
    if (fallsIntoPIOBar(state, port) != -1) {
        getDebugStream(state) << " PeX ... port access to mapped bar, port " << hexval(port) << "\n";
        return true;
    }
    return false;
}

bool PeX::isMmioSymbolic(S2EExecutionState *state, uint64_t physAddr) {
    int bar = fallsIntoMMIOBar(state, physAddr);
    if (bar != -1) {
        getDebugStream(state) << " - BAR " << bar << " MMIO @ ADDR " << hexval(physAddr) << "\n";
        return true;
    }
    return false;
}

void PeX::onBeforeSymbolicDataMemoryAccess(S2EExecutionState *state, klee::ref<klee::Expr> addr,
                                           klee::ref<klee::Expr> value, bool isWrite) {
#if 0
    uint64_t address = 0;
    klee::ref<klee::ConstantExpr> conc = state->toConstant(addr, "addr");
    address = conc->getZExtValue();

    // this is virtual address -- need physical address
    uint64_t paddr = state->mem()->getPhysicalAddress(address);
    int bar = fallsIntoMMIOBar(state, paddr);
    // if (bar == -1)
    //    return;
    getDebugStream(state) << "-PeX: SLOT Accessing Bar " << bar << " address=" << hexval(address)
                          << " paddr=" << hexval(paddr) << " value=" << value
                          << " pc=" << hexval(state->regs()->getPc()) << "\n";
    // flag & MEM_TRACE_FLAG_WRITE
#else
    getDebugStream(state) << "-PeX::onBeforeSymbolicDataMemoryAccess "
                          << " pc=" << hexval(state->regs()->getPc()) << " addr=" << addr << "\n";

#endif
}

void PeX::slotOnConcreteDataMemoryAccess(S2EExecutionState *state, uint64_t address, uint64_t value, uint8_t size,
                                         unsigned flags) {
#if 0
    // this is virtual address -- need physical address
    uint64_t paddr = state->mem()->getPhysicalAddress(address);
    int bar = fallsIntoMMIOBar(state, paddr);
    if (bar == -1)
        return;
    getDebugStream(state) << "+PeX: SLOT Accessing Bar " << bar << " address=" << hexval(address)
                          << " paddr=" << hexval(paddr) << " value=" << hexval(value)
                          << " pc=" << hexval(state->regs()->getPc()) << "\n";
    // flag & MEM_TRACE_FLAG_WRITE
#else
    getDebugStream(state) << "+PeX::slotOnConcreteDataMemoryAccess pc=" << hexval(state->regs()->getPc())
                          << " address=" << hexval(address) << "\n";
#endif
}

bool PeX::isOurDevice(S2EExecutionState *state) {
    // FIXME: is g_s2e_state the current state?
    uint32_t reg_pci_cfg_addr = getPortIORegister(state, PCI_CONFIG_ADDRESS_PORT);
    uint8_t bus = BUS_ADDR(reg_pci_cfg_addr);
    uint8_t device = DEV_ADDR(reg_pci_cfg_addr);
    uint8_t function = FUN_ADDR(reg_pci_cfg_addr);
    if ((bus == n_bus) && (device == n_device) && (((1u << function) & n_function) != 0)) {
        getDebugStream(state) << " isOurDevice:  bus:" << hexval(bus) << "  device:" << hexval(device)
                              << "  function:" << hexval(function) << "\n";
        return true;
    }
    return false;
}

int PeX::fallsIntoMMIOBar(S2EExecutionState *state, uint64_t physAddr) {
    auto &pci_header = getPCIHeader(state);
    uint32_t *bar = &(pci_header.reg[PCI_CONFIG_DATA_REG_BAR0]);
    // getDebugStream(g_s2e_state) << " MMIO @ " << hexval(physAddr) << "\n";
    for (int i = 0; i < 6; i++) {
        if (bar_configuration[i][0] != 0) {
            // this is not MMIO bar
            continue;
        }
        if ((bar[i] == 0xffffffff) || (bar[i] == 0) || (bar[i] == bar_configuration[i][0]))
            continue;
        auto BAR_HMASK = bar_configuration[i][1];
        auto barlo = (uint64_t)(bar[i]) & 0xFFFFFFF0;
        auto barhi = (uint64_t)(barlo + ~BAR_HMASK) & 0xFFFFFFF0;
        if ((physAddr >= barlo) && (physAddr <= barhi)) {
            return i;
        }
    }
    return -1;
}

uint64_t PeX::getBarLowAddr(S2EExecutionState *state, int barid) {
    assert((barid >= 0) && (barid < 7));
    auto &pci_header = getPCIHeader(state);
    uint32_t *bar = &(pci_header.reg[PCI_CONFIG_DATA_REG_BAR0]);
    auto barlo = (uint64_t)(bar[barid]) & 0xFFFFFFF0;
    return barlo;
}

int PeX::fallsIntoPIOBar(S2EExecutionState *state, uint64_t physAddr) {
    auto &pci_header = getPCIHeader(state);
    uint32_t *bar = &(pci_header.reg[PCI_CONFIG_DATA_REG_BAR0]);
    // getDebugStream(g_s2e_state) << " MMIO @ " << hexval(physAddr) << "\n";
    for (int i = 0; i < 6; i++) {
        if (bar_configuration[i][0] != 1) {
            // this is not PIO bar
            continue;
        }
        if ((bar[i] == 0xffffffff) || (bar[i] == 0) || (bar[i] == bar_configuration[i][0]))
            continue;
        auto BAR_HMASK = bar_configuration[i][1];
        auto barlo = (uint64_t)(bar[i]) & 0xFFFFFFF0;
        auto barhi = (uint64_t)(barlo + ~BAR_HMASK) & 0xFFFFFFF0;
        if ((physAddr >= barlo) && (physAddr <= barhi)) {
            return i;
        }
    }
    return -1;
}

void PeX::dumpbar(S2EExecutionState *state) {
    auto &pci_header = getPCIHeader(state);
    uint32_t *bar = &(pci_header.reg[PCI_CONFIG_DATA_REG_BAR0]);
    for (int i = 0; i < 6; i++) {
        if ((bar[i] == 0xffffffff) || (bar[i] == 0) || (bar[i] == bar_configuration[i][0]))
            continue;
        auto BAR_HMASK = bar_configuration[i][1];
        auto barlo = bar[i] & 0xFFFFFFF0;
        auto barhi = (barlo + ~BAR_HMASK) + 0xFFFFFFF0;
        getDebugStream(state) << " PeX ... BAR " << i << " [" << hexval(barlo) << " - " << hexval(barhi) << "]\n";
    }
}

void PeX::configBAR(S2EExecutionState *state, uint32_t reg, uint32_t value) {
    // dumpDmesg(state);
    if (!isOurDevice(state))
        return;
    auto baridx = reg - PCI_CONFIG_DATA_REG_BAR0;
    getDebugStream(state) << " PeX .. config BAR[" << baridx << "] = " << hexval(value) << "\n";
    auto &pci_header = getPCIHeader(state);
    assert((reg >= 0) && (reg < PCI_HEADER_REG_SIZE));

    if (value == 0xffffffff) {
        // pio bar
        // pci_header.reg[reg] = BAR_HMASK | 0x01;
        // mmio bar
        auto BAR_HMASK = bar_configuration[baridx][1];
        pci_header.reg[reg] = BAR_HMASK & (~1UL);
        return;
    } else {
        // pio bar
        // pci_header.reg[reg] = value | 0x01;
        // mmio bar
        pci_header.reg[reg] = value & (~1UL);
        dumpbar(state);
        if (value != 0) {
            // uint64_t size = ~BAR_HMASK + 1;
            // kvm_userspace_memory_region barRegion = {0, 0, value, size, (uintptr_t) barMMIO[0]};
            // s2e_kvm_register_mmio_region(&barRegion);
            // getDebugStream(state) << "PeX:: done\n";
#if 0
            int size = ~BAR_HMASK + 1;
            getDebugStream(state) << " PeX .. config BAR[" << baridx << "] IO Memory\n";
            // auto *mchunk = barMMIO[baridx];
            auto *mchunk = (uint8_t *) memalign(4096, size);
            for (int i = 0; i < size; i++)
                mchunk[i] = 1;
            uint64_t hostaddr = (uint64_t) mchunk;
            g_s2e->getExecutor()->registerRam(state, nullptr, value, size, hostaddr, false, false, "PeXBar");
            // - mark this region symbolic
            // create symbolic array
            std::string name = "PeXBar";
            name += std::to_string(baridx);
            std::vector<unsigned char> array;
            auto symb = state->createSymbolicArray(name, size, nullptr);
            auto* mem = state->mem();
            // this is not working....
            for (int i = 0; i < size; i++) {
                if (!mem->write((uint64_t) &mchunk[i], symb[i], HostAddress)) {
                    getWarningsStream(state)
                        << "PeX:Can not insert symbolic value at " << hexval(value + i) << ": cannot write to memory\n";
                }
            }
#endif
        }
    }
}

void PeX::slotOnPortAccess(S2EExecutionState *state, KleeExprRef port, KleeExprRef value, bool isWrite) {
    auto &pci_header = getPCIHeader(state);
    uint64_t cport = 0, cvalue = 0;
    if (auto *_cport = dyn_cast<klee::ConstantExpr>(port.get())) {
        cport = _cport->getZExtValue();
    }
    if (auto *_cvalue = dyn_cast<klee::ConstantExpr>(value.get())) {
        cvalue = _cvalue->getZExtValue();
    } else {
        if (isWrite) {
            getDebugStream(state) << "write sym value to port\n";
        }
    }
    if (m_printAllPortAccess) {
        std::string rw = isWrite ? "write" : "read";
        getDebugStream(state) << rw << "  port " << port << " value=" << value << "\n";
    }

    if (isWrite) {
        switch (cport) {
            case PCI_CONFIG_ADDRESS_PORT: {
                uint32_t reg_pci_cfg_addr = (uint32_t) cvalue;
                setPortIORegister(PCI_CONFIG_ADDRESS_PORT, reg_pci_cfg_addr);
                uint8_t bus = BUS_ADDR(reg_pci_cfg_addr);
                uint8_t device = DEV_ADDR(reg_pci_cfg_addr);
                uint8_t function = FUN_ADDR(reg_pci_cfg_addr);
                uint8_t reg = REG_ADDR(reg_pci_cfg_addr);
                getDebugStream(state) << " PeX ... pio set PCI_CONFIG_ADDRESS : " << value << " Bus " << hexval(bus)
                                      << ", Dev " << hexval(device) << ", Func " << hexval(function) << ", Reg "
                                      << hexval(reg) << "\n";
                break;
            }
            case PCI_CONFIG_DATA_PORT ... PCI_CONFIG_DATA_PORT_END: {
                uint32_t reg_pci_cfg_addr = getPortIORegister(state, PCI_CONFIG_ADDRESS_PORT);
                auto regaddr = REG_ADDR(reg_pci_cfg_addr);
                if ((regaddr >= PCI_CONFIG_DATA_REG_BAR0) && (regaddr <= PCI_CONFIG_DATA_REG_BAR5)) {
                    configBAR(state, regaddr, cvalue);
                } else {
                    // other registers ----
                    assert((regaddr >= 0) && (regaddr < PCI_HEADER_REG_SIZE));
                    switch (value->getWidth()) {
                        case (8): {
                            pci_header.reg[regaddr] &= 0xffffff00;
                            pci_header.reg[regaddr] |= cvalue;
                            break;
                        }
                        case (16): {
                            pci_header.reg[regaddr] &= 0xffff0000;
                            pci_header.reg[regaddr] |= cvalue;
                            break;
                        }
                        case (32): {
                            pci_header.reg[regaddr] = cvalue;
                            break;
                        }
                        default:
                            assert(0);
                    }
                }
                break;
            }
            default:
                break;
        }
    } else {
        // port read
        if ((cport >= PCI_CONFIG_DATA_PORT) && (cport <= PCI_CONFIG_DATA_PORT_END)) {
            uint32_t reg_pci_cfg_addr = getPortIORegister(state, PCI_CONFIG_ADDRESS_PORT);
            uint8_t bus = BUS_ADDR(reg_pci_cfg_addr);
            uint8_t device = DEV_ADDR(reg_pci_cfg_addr);
            uint8_t function = FUN_ADDR(reg_pci_cfg_addr);
            uint8_t reg = REG_ADDR(reg_pci_cfg_addr);
            getDebugStream(state) << " PeX ... pio get PCI_CONFIG_DATA_PORT from : " << hexval(reg_pci_cfg_addr)
                                  << " BDFR = " << hexval(bus) << "," << hexval(device) << "," << hexval(function)
                                  << "," << hexval(reg) << "   value = " << hexval(cvalue) << "\n";
            switch (reg) {
                case 0: {
                    getDebugStream(state) << " PeX ... pio probing device "
                                          << "@BDFR:" << hexval(bus) << "," << hexval(device) << "," << hexval(function)
                                          << "," << hexval(reg) << " feeding VID:PID = " << hexval(cvalue) << "\n";
                    break;
                }
                case PCI_CONFIG_DATA_REG_BAR0 ... PCI_CONFIG_DATA_REG_BAR5: {
                    getDebugStream(state) << " PeX ... pio read BAR " << (reg - PCI_CONFIG_DATA_REG_BAR0) << " = "
                                          << hexval(cvalue) << "\n";
                    break;
                }
                default:
                    break;
            }
        }
    }
}

template <typename T> static void SymbHwGetConcolicVector(T in, unsigned size, ConcreteArray &out) {
    union {
        // XXX: assumes little endianness!
        T value;
        uint8_t array[8];
    };
    value = in;
    out.resize(size);
    for (unsigned i = 0; i < size; ++i) {
        out[i] = array[i];
    }
}

KleeExprRef PeX::createExpressionPort(S2EExecutionState *state, uint64_t address, unsigned size,
                                      uint64_t concreteValue) {
    auto &pci_header = getPCIHeader(state);
    // the PCI configuration register is 32 bit, so the offset here can be used to address inside this 32bit
    int cfc_offset = address - 0xcfc;

    uint32_t reg_pci_cfg_addr = getPortIORegister(state, PCI_CONFIG_ADDRESS_PORT);
    // auto function = FUN_ADDR(reg_pci_cfg_addr);
    std::stringstream ss;
    // ss << "PCI device @ " << hexval(reg_pci_cfg_addr) << " pio read ";
    uint8_t reg = REG_ADDR(reg_pci_cfg_addr);

    // PIO bar access does not need to actually set PCI_CFG_ADDR and PCI_CFG_DATA
    int bar = fallsIntoPIOBar(state, address);
    if (bar != -1) {
        auto barLowAddr = getBarLowAddr(state, bar);
        auto baraddr = address - barLowAddr;
        ss << "pex symdev bar " << bar << " pio @ " << hexval(baraddr) << " size " << size
           << " pc=" << hexval(state->regs()->getPc());
        getDebugStream(g_s2e_state) << ss.str();
        goto symend;
    }

    ss << "pex symdev pio read @ " << hexval(address) << " size " << size << " pc=" << hexval(state->regs()->getPc())
       << " Reg: " << hexval(reg) << " cfc_offset=" << hexval(cfc_offset);

    if (!isOurDevice(state))
        goto end;
    if ((address < PCI_CONFIG_DATA_PORT) || (address > PCI_CONFIG_DATA_PORT_END))
        goto end;

    switch (reg) {
        case PCI_CONFIG_DATA_REG_0:
        case PCI_CONFIG_DATA_REG_1:
        case PCI_CONFIG_DATA_REG_2: // class
        case PCI_CONFIG_DATA_REG_3:
        case PCI_CONFIG_DATA_REG_A:
        case PCI_CONFIG_DATA_REG_B:
        case PCI_CONFIG_DATA_REG_C:
        case PCI_CONFIG_DATA_REG_D:
        case PCI_CONFIG_DATA_REG_E:
        case PCI_CONFIG_DATA_REG_F: {
            ss << " sym=no\n";
            getDebugStream(g_s2e_state) << ss.str();
            goto concend;
        }
        case PCI_CONFIG_DATA_REG_BAR0 ... PCI_CONFIG_DATA_REG_BAR5: {
            auto idx = reg - PCI_CONFIG_DATA_REG_BAR0;
            ss << " access bar @ " << idx << " sym=no \n";
            getDebugStream(g_s2e_state) << ss.str();
#if 0
            // the last bit of bar indicates whether this is IO or MEM, thus we need to mark it symbolic
            // https://en.wikipedia.org/wiki/PCI_configuration_space#cite_note-8
            ConcreteArray concolicValue;
            SymbHwGetConcolicVector(pci_header.reg[reg], size, concolicValue);
            getDebugStream(g_s2e_state) << ss.str();
            return state->createSymbolicValue(ss.str(), size * 8, concolicValue);
#else
            // create LEGACY IO region
            return klee::ExtractExpr::create(klee::ConstantExpr::create(pci_header.reg[reg], 64), 0, size * 8);
#endif
        }

        default: {
            // ss << " sym=yes\n";
            // goto symend;
            ss << " default sym=no\n";
            getDebugStream(g_s2e_state) << ss.str();
            goto concend;
        }
    }

symend : {
#if 0
    ConcreteArray concolicValue;
    if (size == 1) {
        SymbHwGetConcolicVector(getPCIReg8(reg, cfc_offset), size, concolicValue);
    } else if (size == 2) {
        SymbHwGetConcolicVector(getPCIReg16(reg, cfc_offset), size, concolicValue);
    } else {
        SymbHwGetConcolicVector(getPCIReg32(reg), size, concolicValue);
    }
    return state->createSymbolicValue(ss.str(), size * 8, concolicValue);
#else
    return state->createSymbolicValue(ss.str(), size * 8);
#endif
}

concend : {
    if (size == 1) {
        return klee::ExtractExpr::create(klee::ConstantExpr::create(getPCIReg8(state, reg, cfc_offset), 8), 0,
                                         size * 8);
    } else if (size == 2) {
        return klee::ExtractExpr::create(klee::ConstantExpr::create(getPCIReg16(state, reg, cfc_offset), 16), 0,
                                         size * 8);
    } else {
        return klee::ExtractExpr::create(klee::ConstantExpr::create(getPCIReg32(state, reg), 32), 0, size * 8);
    }
}
end : { return klee::ExtractExpr::create(klee::ConstantExpr::create(concreteValue, 64), 0, size * 8); }
}

KleeExprRef PeX::createExpressionMMIO(S2EExecutionState *state, uint64_t address, unsigned size,
                                      uint64_t concreteValue) {
    std::stringstream ss;
    int bar = fallsIntoMMIOBar(state, address);
    assert(bar != -1);
    auto barLowAddr = getBarLowAddr(state, bar);
    auto baraddr = address - barLowAddr;
    ss << "pex symdev bar " << bar << " mmio @ " << hexval(baraddr) << " size " << size
       << " pc=" << hexval(state->regs()->getPc());
    getDebugStream(state) << ss.str() << "\n";
    if (state->metadata["device_probed"]) {
        uint64_t ret;
        if (m_with_afl) {
            // ask data from AFL
            // should already open
            openAFLProxySHMBlock();
            auto *sm = aflProxyShm->getMem();
            ret = getByteFromFile(sm->path, address);
        } else {
            // feed random data
            // srand(time(NULL));
            ret = random();
        }
        getDebugStream(state) << "feed concrete value " << hexval(ret) << "\n";
        return klee::ExtractExpr::create(klee::ConstantExpr::create(ret, 64), 0, size * 8);
    }
    // not probed yet --
    return state->createSymbolicValue(ss.str(), size * 8);
}

// dmesg from m_logBuf and m_logBufLen
void PeX::dumpDmesg(S2EExecutionState *state) {
    std::string dmesg;
    uint64_t dmesg_addr = os_monitor->getDmesgAddress();
    uint64_t dmesg_len = os_monitor->getDmesgLen();
    getDebugStream(state) << " dmesg is at " << hexval(dmesg_addr) << " length = " << hexval(dmesg_len) << "\n";
    static uint8_t *buffer;
    if (!buffer)
        buffer = (uint8_t *) malloc(dmesg_len);
    auto *mem = state->mem();
    // cannot use readString here since kernel log buffer is not
    //  plain text buffer
    // state->mem()->readString(dmesg_addr, str, dmesg_len);
    memset(buffer, 0, sizeof(uint8_t) * dmesg_len);
    mem->read(dmesg_addr, buffer, dmesg_len);
    // TODO: decode buffer into plain text

    getDebugStream(state) << dmesg << "\n";
}

void PeX::processBarConfiguration() {
    auto *config = s2e()->getConfig();
    bar_configuration[0][0] = config->getInt(getConfigKey() + ".bar0type");
    bar_configuration[0][1] = config->getInt(getConfigKey() + ".bar0range");
    bar_configuration[1][0] = config->getInt(getConfigKey() + ".bar1type");
    bar_configuration[1][1] = config->getInt(getConfigKey() + ".bar1range");
    bar_configuration[2][0] = config->getInt(getConfigKey() + ".bar2type");
    bar_configuration[2][1] = config->getInt(getConfigKey() + ".bar2range");
    bar_configuration[3][0] = config->getInt(getConfigKey() + ".bar3type");
    bar_configuration[3][1] = config->getInt(getConfigKey() + ".bar3range");
    bar_configuration[4][0] = config->getInt(getConfigKey() + ".bar4type");
    bar_configuration[4][1] = config->getInt(getConfigKey() + ".bar4range");
    bar_configuration[5][0] = config->getInt(getConfigKey() + ".bar5type");
    bar_configuration[5][1] = config->getInt(getConfigKey() + ".bar5range");
}

/////////////////////////////////////////////////////////////////////////
// dust
#if 0
void PeX::processTargetStackInfo() {
    auto *config = s2e()->getConfig();
    auto pcrangeFilePath = config->getString(getConfigKey() + ".pcrange");
    std::ifstream file(pcrangeFilePath);
    if (!file.is_open())
        return;
    std::string line;
    while (std::getline(file, line)) {
        if (line == "---stack binary range---")
            break;
    }
    while (std::getline(file, line)) {
        if (line == "EOR") {
            // end of range
            break;
        }
        uint64_t pc1, pc2;
        int found = line.find("[");
        std::string str = line.substr(found + 1);
        std::sscanf(str.c_str(), "0x%lx,0x%lx", &pc1, &pc2);
        pcrange_pair p;
        if (pc1 > pc2)
            p = std::make_pair(pc1, pc2);
        else
            p = std::make_pair(pc2, pc2);
        targetStack.push_back(p);
    }
    file.close();
}

void PeX::processPCRange() {
    auto *config = s2e()->getConfig();
    auto pcrangeFilePath = config->getString(getConfigKey() + ".pcrange");
    std::ifstream file(pcrangeFilePath);
    if (!file.is_open())
        return;
    std::string line;
    while (std::getline(file, line)) {
        if (line == "---possible pc range---")
            break;
    }
    while (std::getline(file, line)) {
        if (line == "EOR") {
            // end of range
            break;
        }
        uint64_t pc1, pc2;
        int found = line.find("[");
        std::string str = line.substr(found + 1);
        std::sscanf(str.c_str(), "0x%lx,0x%lx", &pc1, &pc2);
        pcrange_pair p;
        if (pc1 > pc2)
            p = std::make_pair(pc1, pc2);
        else
            p = std::make_pair(pc2, pc2);
        pcrange.push_back(p);
    }
    file.close();
}
void PeX::slotTranslateBlockStart(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb,
                                  uint64_t pc) {
    if (!os_monitor->isKernelAddress(pc))
        return;
    if (m_traceBlockTranslation) {
        // getDebugStream(state) <<"kernel Start
        // @"<<hexval(os_monitor->getKernelStart())<<"\n";
        getDebugStream(state) << "Translating kernel block at " << hexval(pc) << "\n";
        // getDebugStream(state) << "Translating kernel block @ " <<
        // hexval(pc-os_monitor->getKernelStart()) << "\n";
    }

    if (m_traceBlockExecution) {
        signal->connect(sigc::mem_fun(*this, &PeX::slotExecuteBlockStart));
    }
}
bool PeX::isInRange(uint64_t pc) {
    for (const auto &p : pcrange) {
        // high
        if (p.first < pc)
            continue;
        // low
        if (p.second > pc)
            continue;
        return true;
    }
    return false;
}

bool PeX::isDestRange(uint64_t pc) {
    if (pcrange.size() == 0)
        return false;
    auto &p = pcrange.front();
    // high
    if (p.first < pc)
        return false;
    // low
    if (p.second > pc)
        return false;
    return true;
}

bool PeX::isTargetStack(std::vector<uint64_t> &stack) {
    int depth = targetStack.size();
    if (stack.size() < depth)
        return false;
    for (int i = 0; i < depth; i++) {
        auto pair = targetStack[i];
        auto highpc = pair.first;
        auto lowpc = pair.second;
        auto pc = stack[i];
        if (pc < lowpc)
            return false;
        if (pc > highpc)
            return false;
    }
    return true;
}

#define PAGE_SIZE 0x1000
#define PAGE_MASK ~(0x0fff)
#define STACK_MAX_SIZE (PAGE_SIZE * 2)

std::vector<uint64_t> PeX::unwindStack(S2EExecutionState *state) {
    std::vector<uint64_t> stack;
    // read out stack
    auto pc = state->regs()->getPc();
    stack.push_back(pc);
    auto sp = state->regs()->getSp();
    auto bp = state->regs()->getBp();
    auto stacklow = sp & PAGE_MASK;
    auto stackhigh = sp + STACK_MAX_SIZE;
    getDebugStream(state) << " stack pointer sp=" << hexval(sp) << " stack low = " << hexval(stacklow)
                          << " stack high = " << hexval(stackhigh) << "\n"
                          << " base pointer[stack frame] bp=" << hexval(bp) << "\n";
    uint8_t stackSnapshot[STACK_MAX_SIZE];
    state->mem()->read(stacklow, stackSnapshot, STACK_MAX_SIZE);
    uint64_t *stackPtr = (uint64_t *) stackSnapshot;
    auto ptrSize = sizeof(uint64_t);
    auto ptrCnt = STACK_MAX_SIZE / ptrSize;
#if 0
  getDebugStream(state)<<" ===== STACK ==== \n";
  for (int i=0;i<ptrCnt;i++) {
    getDebugStream(state)<<"   ["
     <<i<<"] => " << hexval(stacklow + i*ptrSize) <<" = "
     <<hexval(stackPtr[i])<<"\n";
  }
#endif
    // this is where we start
    int bpOffset = (bp - stacklow) / ptrSize;
    if (bpOffset < 0 || bpOffset >= ptrCnt) { // there's an error
        getDebugStream(state) << " error unwinding stack\n";
        goto end;
    }
    while (bpOffset < ptrCnt) {
        auto retOffset = bpOffset + 1;
        if (retOffset < 0 || retOffset >= ptrCnt) {
            // getDebugStream(state)<<" doesn't look like a valid stack here\n";
            break;
        }
        stack.push_back(stackPtr[retOffset]);
        auto nextBp = stackPtr[bpOffset];
        auto nextBpOffset = (nextBp - stacklow) / ptrSize;
        if (nextBpOffset <= bpOffset) {
            // getDebugStream(state)<<" doesn't look like a valid stack here\n";
            break;
        }
        bpOffset = nextBpOffset;
    }
end:
    return stack;
}

void PeX::slotExecuteBlockStart(S2EExecutionState *state, uint64_t pc) {
    if (!os_monitor->isKernelAddress(pc)) {
        return;
    }
    if (m_traceBlockExecution) {
        auto *e = s2e()->getExecutor();
        auto count = e->getStatesCount();
        if (count <= 1)
            return;
        if (isDestRange(pc)) {
            auto stack = unwindStack(state);
            ////////////////
            getDebugStream(state) << " === to match stack ===\n";
            for (auto pc : stack)
                getDebugStream(state) << "  " << hexval(pc) << "\n";
            ///////////////

            if (isTargetStack(stack)) {
                getDebugStream(state) << "Target Stack Identified\n";
            }
        }
        if ((m_killWhenNotInRange) && (!isInRange(pc))) {
            getDebugStream(state) << "terminating state " << count << " pc @ " << hexval(pc) << "\n";
            e->terminateState(*state);
        }
        // jump to itself
        // jumpToPc(state, exeTrace[cnt]);
    }
}

void PeX::jumpToPc(S2EExecutionState *state, uint64_t pc) {
    state->regs()->setPc(pc);
    throw CpuExitException();
}

void PeX::slotTranslateBlockEnd(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb, uint64_t pc,
                                bool staticTarget, uint64_t targetPc) {
    if (!os_monitor->initialized()) {
        return;
    }
    if (!os_monitor->isKernelAddress(pc)) {
        return;
    }

    if (tb->se_tb_type == TB_CALL) {
        signal->connect(sigc::mem_fun(*this, &PeX::onExecuteDirectCall));
    }
    if (tb->se_tb_type == TB_CALL_IND) {
        signal->connect(sigc::mem_fun(*this, &PeX::onExecuteIndirectCall));
    }
}

void PeX::onExecuteIndirectCall(S2EExecutionState *state, uint64_t pc) {
    auto calleepc = state->regs()->getPc();
    getDebugStream(state) << " execute indirect call @ " << hexval(pc) << " callee pc:" << hexval(calleepc) << "\n";
    // guide indirect execution here
    if (pc2pc.find(pc) != pc2pc.end())
        jumpToPc(state, pc2pc[pc]);
}

void PeX::onExecuteDirectCall(S2EExecutionState *state, uint64_t pc) {
    auto calleepc = state->regs()->getPc();
    getDebugStream(state) << " execute direct call @ " << hexval(pc) << " callee pc:" << hexval(calleepc) << "\n";
}
#endif

void PeX::onTranslateInstructionStart(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb,
                                      uint64_t pc) {
    if (!os_monitor->isKernelAddress(pc))
        return;
    signal->connect(sigc::mem_fun(*this, &PeX::onInstruction));
}

void PeX::onInstruction(S2EExecutionState *state, uint64_t pc) {
    // do not inject if not probed
    if (!state->metadata["device_probed"])
        return;
    // getDebugStream(state) << "PeX:: pc @ " << hexval(pc) << "\n";
    // IRQ generation strategy: generate IRQ every x instructions, this may be very slow---
    static uint64_t icount = 0;
    icount++;
    if (icount % m_inject_irq_per_xxx_ins == 0)
        assertIRQ(state);
}

void PeX::handleOpcodeInvocation(S2EExecutionState *state, uint64_t guestDataPtr, uint64_t guestDataSize) {
    // we are not really using guestDataPtr as a pointer -- instead we store data in the pointer itself
    // if the guest failed to probe the device we kill the state
    getDebugStream(state) << "PeX::handleOpcodeInvocation " << guestDataPtr << "\n";
    switch (guestDataPtr) {
        case (1):
            getDebugStream(state) << "PeX:: device probed for state " << state->getID() << "\n";
            state->metadata["device_probed"] = 1;
            // generate output here
            generateTestCase(state);
            // FIXME: still buggy here, several things need to be done here
            // 1. kill all others, but our parent state ---
            killAllOthers(state);
            // 2. save current state
            // 3. switch to concrete
            // state->switchToConcrete();
            // 4. disable forking as well?
            // state->disableForking();
            // assertIRQ(state);
            break;
        case (2):
            state->setStateSwitchForbidden(true);
            g_s2e->getExecutor()->terminateState(*state, "probe failed");
            assert(state->isZombie());
            break;
        default:
            break;
    }
}

void PeX::assertIRQ(S2EExecutionState *state) {
    auto &m = state->metadata;
    if (m.find("device_probed") == m.end())
        return;
    // if irq==-1, then we dont inject irq
    if (irq == -1)
        return;
    // irq 10 is mapped to interrupt vector 239?
    int _irq = 10;
    int vector = irq;
    getDebugStream(state) << "injecting IRQ " << _irq << "\n";
    // start to inject irq
    // PCI interrupt is routed through IO-APIC on x86_64 --
    // get irq number from /proc/interrupts from guest os
    // NOTE: use vector number not IRQ line number
    state->regs()->write(CPU_OFFSET(kvm_irq), vector);
    // will cause Forcing IRQ in libs2e/src/s2e-kvm-vcpu.cpp
    // int interrupt_request = state->regs()->read<int>(CPU_OFFSET(interrupt_request));
    // interrupt_request |= CPU_INTERRUPT_HARD;
    // state->regs()->write(CPU_OFFSET(interrupt_request), interrupt_request);
}

///
/// create test case for this state
///
void PeX::generateTestCase(S2EExecutionState *state) {
    getDebugStream(state) << "Generate Test Case:\n";
    klee::ArrayVec symbObjects = state->symbolics;
    klee::ConstraintManager constraints = state->constraints();
    klee::Solver *solver = state->solver()->solver;
    klee::Query query(constraints, klee::ConstantExpr::alloc(0, klee::Expr::Bool));
    std::vector<std::vector<unsigned char>> concreteObjects;
    if (!solver->getInitialValues(query, symbObjects, concreteObjects)) {
        getDebugStream(state) << "Could not get symbolic solution\n";
        return;
    }
    getDebugStream(state) << "Solved!\n";
    for (unsigned i = 0; i < symbObjects.size(); ++i) {
        getDebugStream(state) << symbObjects[i]->getName() << "\n";
        for (auto c : concreteObjects[i])
            getDebugStream(state) << hexval(c) << "\n";
    }
    getDebugStream(state) << "End of solution\n";

    // or use concolics???
    // Assignment assignment = *state->concolics;
}

void PeX::killAllOthers(S2EExecutionState *state) {
    auto *executor = g_s2e->getExecutor();
    decltype(executor->getStates()) states;
    for (auto *s : executor->getStates())
        if (s != state)
            states.insert(s);
    for (auto *s : states) {
        std::stringstream ss;
        ss << " terminating state " << static_cast<S2EExecutionState *>(s)->getID();
        executor->terminateState(*s, ss.str());
    }
}

void PeX::openAFLProxySHMBlock() {
    while (!aflProxyShm->isOpen()) {
        if (aflProxyShm->open(SHMOpenType::CONNECT))
            break;
        // sleep for 1s before retry
        sleep(1);
    }
}
void PeX::slotTranslateBlockStart(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb,
                                  uint64_t pc) {
    if (!os_monitor->isKernelAddress(pc))
        return;
    signal->connect(sigc::mem_fun(*this, &PeX::slotExecuteBlockStart));
}

void PeX::slotExecuteBlockStart(S2EExecutionState *state, uint64_t pc) {
    if (!os_monitor->isKernelAddress(pc))
        return;
    if (!m_with_afl)
        return;
    // do not feed afl before probed
    if (!state->metadata["device_probed"])
        return;
    openAFLProxySHMBlock();
    // send pc to AFL
    auto *sm = aflProxyShm->getMem();
    if (sem_wait(&sm->semr) == -1) {
        // error wait semr
    }
    sm->type = 0x01;
    memcpy(sm->data, &pc, sizeof(uint64_t));
    if (sem_post(&sm->semw) == -1) {
        // errror post semr
    }
}

void PeX::slotOnStateKill(S2EExecutionState *state) {
    if (!state->metadata["device_probed"])
        return;
    if (!m_with_afl)
        return;
    openAFLProxySHMBlock();
    // send terminate to AFL
    auto *sm = aflProxyShm->getMem();
    if (sem_wait(&sm->semr) == -1) {
        // error wait semr
    }
    sm->type = 0xff;
    if (sem_post(&sm->semw) == -1) {
        // errror post semr
    }
    aflProxyShm->close();
}
uint64_t PeX::getByteFromFile(const char *path, uint64_t offset) {
    uint64_t ret;
    std::ifstream in(path, std::ifstream::ate | std::ifstream::binary);
    uint64_t fsize = in.tellg();
    in.open(path);
    in.seekg(offset % fsize);
    in.read((char *) &ret, sizeof(uint64_t));
    in.close();
    return ret;
}

} // namespace plugins
} // namespace s2e
