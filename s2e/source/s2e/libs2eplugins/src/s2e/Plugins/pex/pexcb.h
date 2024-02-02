/////////////////////////////////////////////////////////////////////////
/// for port access
static bool _isPortSymbolic(S2EExecutionState *state, uint16_t port, void *opaque) {
    PeX *pex = static_cast<PeX *>(opaque);
    return pex->isPortSymbolic(state, port);
}

static klee::ref<klee::Expr> symbolicPortRead(S2EExecutionState *state, uint16_t port, unsigned size,
                                              uint64_t concreteValue, void *opaque) {
    PeX *pex = static_cast<PeX *>(opaque);
    return pex->createExpressionPort(state, port, size, concreteValue);
}

static bool symolicPortWrite(S2EExecutionState *state, uint16_t port, const klee::ref<klee::Expr> &value,
                             void *opaque) {
    // FIXME: is there something special we need to handle?
    PeX *pex = static_cast<PeX *>(opaque);
    return !pex->isPortSymbolic(state, port);
}

//////////////////////////////////////////////////////////////////////////
// for mmio access
static bool _isMmioSymbolic(S2EExecutionState *state, struct MemoryDesc *mr, uint64_t physaddr, uint64_t size,
                            void *opaque) {
    PeX *pex = static_cast<PeX *>(opaque);
    return pex->isMmioSymbolic(state, physaddr);
}

// XXX: remove MemoryDesc -- it is nullptr and not used
static klee::ref<klee::Expr> symbolicMMIORead(S2EExecutionState *state, struct MemoryDesc *mr, uint64_t physaddress,
                                              const klee::ref<klee::Expr> &value, SymbolicHardwareAccessType type,
                                              void *opaque) {
    PeX *pex = static_cast<PeX *>(opaque);
    unsigned size = value->getWidth() / 8;
    uint64_t concreteValue = state->toConstantSilent(value)->getZExtValue();
    return pex->createExpressionMMIO(state, physaddress, size, concreteValue);
}

static bool symbolicMMIOWrite(S2EExecutionState *state, struct MemoryDesc *mr, uint64_t physaddress,
                              const klee::ref<klee::Expr> &value, SymbolicHardwareAccessType type, void *opaque) {
    // TODO: return bool to not call original handler, like for I/O
    PeX *pex = static_cast<PeX *>(opaque);
    return !pex->isMmioSymbolic(state, physaddress);
}
