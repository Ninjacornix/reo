    // Pure host-side classification; never exports an IOP pointer. An overlap
    // that is not wholly inside the owned arena remains a sound transfer and
    // is refused, rather than falling back to EE memory.
    bool describeSoundDriverIopTransfer(PS2Runtime* runtime,uint32_t addr,uint32_t bytes,bool& valid)
    {
        valid=false;std::lock_guard<std::mutex> lock(g_rpc_mutex);
        if(!runtime||!g_soundDriverRpcState.statusAddr||g_soundDriverRpcState.ownerRuntime!=reinterpret_cast<uintptr_t>(runtime))return false;
        const uint64_t begin=g_soundDriverRpcState.statusAddr,end=uint64_t(g_soundDriverRpcState.storageBaseAddr)+g_soundDriverRpcState.storageSize;
        const uint64_t transferEnd=uint64_t(addr)+bytes;
        if(addr>=end||transferEnd<=begin)return false;
        valid=addr>=begin&&transferEnd<=end&&g_soundDriverIopRam;return true;
    }
    bool prepareSoundDriverStatusTransferCaptured(uint32_t src,uint32_t bytes,PS2Runtime* runtime,ps2_cri_audio::NativeSoundRamCallV1& cap)
    {
        std::lock_guard<std::mutex> lock(g_rpc_mutex);
        if(!runtime||g_soundDriverRpcState.ownerRuntime!=reinterpret_cast<uintptr_t>(runtime))return false;
        return src!=g_soundDriverRpcState.statusAddr||bytes!=kSoundDriverStatusSize||backfillSoundDriverStatusCaptured(cap);
    }
