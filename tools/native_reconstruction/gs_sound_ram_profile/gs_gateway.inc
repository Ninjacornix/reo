namespace gs_backend_bridge {
SoundRamProfileResultV1 acquireSoundRamProfileBeforeRunV1(PS2Runtime& runtime) noexcept {
    try {
        auto setup=runtime.acquirePreRunSetup();
        if(!setup||ps2ActualGuestExecutionDepth(&runtime)!=0u||ps2IoRegLockDepth()!=0u)
            return {SoundRamProfileStatusV1::unavailable,{}};
        auto control=acquireGlobalGsControlV1();
        if(control.status!=SoundRamProfileStatusV1::ok)return {control.status,{}};
        const auto permit=control.control.profilePermitV1();
        if(!permit)return {SoundRamProfileStatusV1::busy,{}};
        const auto identity=SoundRamProfileIdentityV1{&runtime,runtime.memory().getRDRAM(),runtime.memory().getIOPRAM(),runtime.memory().getGSVRAM(),&runtime.gs()};
        if(!identity.ee||!identity.iop||!identity.vram||ps2RamBackingBytes!=PS2_RAM_SIZE||g_gsInstance!=identity.gs)
            return {SoundRamProfileStatusV1::foreign_runtime,{}};
        struct Reply {std::mutex mutex;bool cancelled{};SoundRamProfileResultV1 result;};
        auto result=std::make_shared<Reply>();
        // Owned result survives a cancelled waiter. No raw Runtime access on
        // the queued owner; a late cancelled reply releases its temporary pin
        // before actual GS worker join, never after caller storage destruction.
        bool complete=false;
        try{complete=gsBackendControl([result,identity,permit]{
            // Cancellation handshake is metadata-only. The probe is pure,
            // bounded, allocation-free, and Route uses try_lock, never GPU work.
            std::lock_guard lock(result->mutex);if(result->cancelled)return;
            if(g_gsInstance!=identity.gs||ps2GsWorkerStopRequested())return;
            result->result=g_backendRoute.acquireProfileV1(identity,permit);
        });}catch(...){complete=false;}
        if(!complete){
            SoundRamSelectionLeaseV1 abandoned;
            {std::lock_guard lock(result->mutex);result->cancelled=true;abandoned=std::move(result->result.lease);}
            return {SoundRamProfileStatusV1::unavailable,{}};
        }
        return std::move(result->result);
    }catch(const std::bad_alloc&){return {SoundRamProfileStatusV1::allocation_failed,{}};}
    catch(...){return {SoundRamProfileStatusV1::unavailable,{}};}
}
} // namespace gs_backend_bridge
