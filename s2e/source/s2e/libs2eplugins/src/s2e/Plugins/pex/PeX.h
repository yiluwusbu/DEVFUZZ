/*
 * PeX S2E Plugin
 * 2020 Tong Zhang <ztong0001@gmail.com>
 */
#ifndef S2E_PLUGINS_PEX_H
#define S2E_PLUGINS_PEX_H

#include <s2e/CorePlugin.h>
#include <s2e/Plugin.h>
#include <s2e/Plugins/OSMonitors/ModuleDescriptor.h>
#include <s2e/S2EExecutionState.h>
#include <semaphore.h>
#include <utility>
#include <vector>

#include "commondef.h"
#include "pcidef.h"
#include "shm.h"

struct XXX {
    sem_t semr;
    sem_t semw;
    char path[128]; // the input data path
    uint8_t type;
    uint8_t data[128];
} XXX;

// we want a fixed address in the PCI system
#define SYMDEV_BUS 0x00
#define SYMDEV_DEV 0x1b
// this is mask -- support up to 8 functions
#define SYMDEV_FUNC 0x01

namespace s2e {
namespace plugins {
class OSMonitor;

class PeX final : public Plugin, public IPluginInvoker {
    S2E_PLUGIN
public:
    PeX(S2E *s2e) : Plugin(s2e) {
        aflProxyShm = new SHM<struct XXX>("/afl-proxy");
    }
    ~PeX() {
        delete aflProxyShm;
        // release the bar memory
        for (auto ptr : barMMIO)
            free(ptr);
    }
    void initialize();
    void pluginInit2(S2EExecutionState *);

    void slotOnPortAccess(S2EExecutionState *, KleeExprRef port, KleeExprRef value, bool isWrite);
    void slotOnConcreteDataMemoryAccess(S2EExecutionState *, uint64_t vaddr, uint64_t value, uint8_t size,
                                        unsigned flags);
    void onBeforeSymbolicDataMemoryAccess(S2EExecutionState *state, klee::ref<klee::Expr> addr,
                                          klee::ref<klee::Expr> value, bool isWrite);

    bool isPortSymbolic(S2EExecutionState *, uint16_t port);
    bool isMmioSymbolic(S2EExecutionState *, uint64_t physAddr);
    // IO address space
    KleeExprRef createExpressionPort(S2EExecutionState *, uint64_t address, unsigned size, uint64_t concreteValue);
    // memory address space
    KleeExprRef createExpressionMMIO(S2EExecutionState *, uint64_t address, unsigned size, uint64_t concreteValue);

    void slotTranslateBlockStart(ExecutionSignal *, S2EExecutionState *state, TranslationBlock *tb, uint64_t pc);
#if 0
    void slotTranslateBlockEnd(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb, uint64_t pc,
                               bool staticTarget, uint64_t targetPc);
    void onExecuteDirectCall(S2EExecutionState *state, uint64_t pc);
    void onExecuteIndirectCall(S2EExecutionState *state, uint64_t pc);
#endif
    void slotExecuteBlockStart(S2EExecutionState *state, uint64_t pc);
    void onTranslateInstructionStart(ExecutionSignal *signal, S2EExecutionState *state, TranslationBlock *tb,
                                     uint64_t pc);
    void onInstruction(S2EExecutionState *state, uint64_t pc);

    void slotOnStateKill(S2EExecutionState *state);

    ///
    /// the guest tool will call this to let us know device has been probed successfully
    ///
    void handleOpcodeInvocation(S2EExecutionState *state, uint64_t guestDataPtr, uint64_t guestDataSize);

private:
    OSMonitor *os_monitor;
    int m_delay_enable_symbhw;
    bool m_printAllPortAccess;
    bool m_with_afl;
    // bool m_traceBlockTranslation;
    // bool m_traceBlockExecution;
    // bool m_killWhenNotInRange;

    uint32_t reg_vid;
    uint32_t reg_pid;
    uint32_t reg_sub_vid;
    uint32_t reg_sub_pid;
    uint32_t reg_class;
    // register at 0x3 (offset 0xc)
    uint32_t reg_bhlc;

    // device address provided by user or pre-defined
    uint8_t n_bus;
    uint8_t n_device;
    uint8_t n_function;

    bool use_capability = false;

    // inject irq per xxx instructions
    uint32_t m_inject_irq_per_xxx_ins = 1000000;

    // the irq our virtual device will using
    int irq;

    // shared memory
    SHM<struct XXX> *aflProxyShm;
    void openAFLProxySHMBlock();
    uint64_t getByteFromFile(const char *path, uint64_t offset);

    std::vector<uint8_t *> barMMIO;
    void initBarMMIO();

    // PCI specific
    void configBAR(S2EExecutionState *, uint32_t reg, uint32_t value);
    int fallsIntoMMIOBar(S2EExecutionState *, uint64_t phy_addr);
    int fallsIntoPIOBar(S2EExecutionState *, uint64_t phy_addr);
    void dumpbar(S2EExecutionState *);
    uint32_t getPortIORegister(S2EExecutionState *state, uint32_t addr) {
        uint32_t ret;
        assert((addr < PORT_IO_ADDRESS_SPACE_SIZE) && (addr >= 0));
        memcpy(&ret, &(state->mem()->portIOMem[addr]), sizeof(uint32_t));
        return ret;
    }
    void setPortIORegister(uint32_t addr, uint32_t val) {
        assert((addr < PORT_IO_ADDRESS_SPACE_SIZE) && (addr >= 0));
        memcpy(&(g_s2e_state->mem()->portIOMem[addr]), &val, sizeof(uint32_t));
    }
    bool isOurDevice(S2EExecutionState *);

    // offset 0~3 - the byte offset
    uint8_t getPCIReg8(S2EExecutionState *s, int regidx, int offset) {
        auto &pci_header = s->mem()->sfpPCIDeviceHeader;
        uint8_t reg[4];
        assert((regidx >= 0) && (regidx < PCI_HEADER_REG_SIZE));
        memcpy(reg, &pci_header.reg[regidx], sizeof(uint32_t));
        return reg[offset];
    }
    // offset 0~3 - the byte offset -- yes it is byte offset
    uint16_t getPCIReg16(S2EExecutionState *s, int regidx, int offset) {
        auto &pci_header = s->mem()->sfpPCIDeviceHeader;
        uint16_t reg[2];
        assert((regidx >= 0) && (regidx < PCI_HEADER_REG_SIZE));
        memcpy(reg, &pci_header.reg[regidx], sizeof(uint32_t));
        return reg[offset >> 1];
    }
    uint32_t getPCIReg32(S2EExecutionState *s, int regidx) {
        auto &pci_header = s->mem()->sfpPCIDeviceHeader;
        assert((regidx >= 0) && (regidx < PCI_HEADER_REG_SIZE));
        return pci_header.reg[regidx];
    }

    PCI_HEADER &getPCIHeader(S2EExecutionState *state) {
        if (state)
            return state->mem()->sfpPCIDeviceHeader;
        return g_s2e_state->mem()->sfpPCIDeviceHeader;
    }

    void dumpDmesg(S2EExecutionState *state);
    void processBarConfiguration();

#if 0
    void processPCRange();
    void processTargetStackInfo();
    bool isInRange(uint64_t);
    bool isDestRange(uint64_t);
    bool isTargetStack(std::vector<uint64_t> &);
    typedef std::pair<uint64_t, uint64_t> pcrange_pair;
    typedef std::vector<pcrange_pair> PCRange;
    PCRange pcrange, targetStack;
    std::map<uint64_t, uint64_t> pc2pc;
    void jumpToPc(S2EExecutionState *state, uint64_t pc);
    std::vector<uint64_t> unwindStack(S2EExecutionState *state);
#endif
    void assertIRQ(S2EExecutionState *);
    void killAllOthers(S2EExecutionState *);
    void generateTestCase(S2EExecutionState *);
    uint64_t getBarLowAddr(S2EExecutionState *, int barid);
};

} // namespace plugins
} // namespace s2e

#endif // S2E_PLUGINS_PEX_H
