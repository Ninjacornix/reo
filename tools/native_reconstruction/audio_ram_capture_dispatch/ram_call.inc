bool nativeSoundRamSelectedV1() noexcept {
    return backend_detail::registry.ram_capture.load(std::memory_order_acquire);
}
NativeSoundRamCallV1::NativeSoundRamCallV1(const SoundCall& call,PS2Runtime* runtime,std::uint8_t* ram,NativeSoundRamUseV1 use)noexcept
    :call_(&call),binding_(call.binding_),selected_(binding_&&binding_->ram_capture.abi_version!=0) {
    if(!selected_){status_=call.status()==BankStatusV2::ok?BankStatusV2::unsupported:call.status();return;}
    if(!call.admitted_||call.status()!=BankStatusV2::ok||!runtime||binding_->runtime!=runtime||ram!=runtime->memory().getRDRAM()){
        status_=BankStatusV2::foreign_runtime;return;
    }
    begun_=true;SoundCallScope scope(call);
    auto& api=binding_->ram_capture;
    finish(NativeSoundRamStageV1::begin,api.begin(binding_->registration.owner.get(),call,runtime,ram,use,token_));
}
NativeSoundRamCallV1::~NativeSoundRamCallV1(){
    if(begun_){SoundCallScope scope(*call_);binding_->ram_capture.end(binding_->registration.owner.get(),*call_,token_);}
}
BankStatusV2 NativeSoundRamCallV1::finish(NativeSoundRamStageV1 stage,BankStatusV2 result)noexcept {
    status_=result;
    if(result!=BankStatusV2::ok&&begun_){SoundCallScope scope(*call_);binding_->ram_capture.report(binding_->registration.owner.get(),*call_,token_,{stage,result});}
    return result;
}
BankStatusV2 NativeSoundRamCallV1::read(std::span<const NativeSoundRamReadV1> reads)noexcept {
    if(status_!=BankStatusV2::ok)return status_;SoundCallScope scope(*call_);
    return finish(NativeSoundRamStageV1::read,binding_->ram_capture.read_batch(binding_->registration.owner.get(),*call_,token_,reads));
}
BankStatusV2 NativeSoundRamCallV1::control(std::span<const NativeSoundRamControlOpV1> ops,NativeSoundRamControlV1 kind)noexcept {
    if(status_!=BankStatusV2::ok)return status_;SoundCallScope scope(*call_);
    return finish(NativeSoundRamStageV1::control,binding_->ram_capture.control_batch(binding_->registration.owner.get(),*call_,token_,kind,ops));
}
BankStatusV2 NativeSoundRamCallV1::write(std::span<const NativeSoundRamWriteV1> writes,NativeSoundRamControlV1 kind)noexcept {
    if(writes.size()>16)return finish(NativeSoundRamStageV1::control,BankStatusV2::capacity);
    NativeSoundRamControlOpV1 ops[16]{};std::size_t n=0;
    for(const auto& w:writes)ops[n++]={NativeSoundRamControlKindV1::write,w.space,w.address,w.source,w.source.size()};
    return control({ops,n},kind);
}
BankStatusV2 NativeSoundRamCallV1::zero(NativeSoundRamSpaceV1 space,std::uint32_t at,std::size_t n,NativeSoundRamControlV1 kind)noexcept {
    NativeSoundRamControlOpV1 op{NativeSoundRamControlKindV1::zero,space,at,{},n};return control({&op,1},kind);
}
BankStatusV2 NativeSoundRamCallV1::forward(NativeSoundRamSpaceV1 srcSpace,std::uint32_t src,NativeSoundRamSpaceV1 dstSpace,std::uint32_t dst,std::size_t n)noexcept {
    if(status_!=BankStatusV2::ok)return status_;SoundCallScope scope(*call_);
    // Call sites preserve their own source limits: RPC clamps to1MiB, while
    // qualified IOP status transfers retain their original full transfer size.
    return finish(NativeSoundRamStageV1::transport,binding_->ram_capture.copy_forward(binding_->registration.owner.get(),*call_,token_,srcSpace,src,dstSpace,dst,n));
}
BankStatusV2 NativeSoundRamCallV1::snapshot(std::uint32_t at,std::size_t n,NativeSoundRamPacketV1& out)noexcept {
    if(status_!=BankStatusV2::ok)return status_;
    if(n>binding_->ram_capture.max_packet_bytes)return finish(NativeSoundRamStageV1::snapshot,BankStatusV2::capacity);
    SoundCallScope scope(*call_);NativeSoundRamPacketV1 staged;
    auto status=binding_->ram_capture.snapshot_packet(binding_->registration.owner.get(),*call_,token_,at,n,staged);
    if(status==BankStatusV2::ok&&(staged.bytes!=n||(n&&!staged.data)))status=BankStatusV2::invalid_input;
    if(status==BankStatusV2::ok)out=staged;return finish(NativeSoundRamStageV1::snapshot,status);
}
BankStatusV2 NativeSoundRamCallV1::log(NativeSoundRamPacketV1 packet)noexcept {
    if(status_!=BankStatusV2::ok)return status_;SoundCallScope scope(*call_);
    auto result=binding_->ram_capture.log_owned_packet(binding_->registration.owner.get(),*call_,token_,packet);
    // Diagnostic failure never turns a captured valid packet into gameplay
    // failure. Report it explicitly, without claiming an export was saved.
    if(result!=BankStatusV2::ok)binding_->ram_capture.report(binding_->registration.owner.get(),*call_,token_,{NativeSoundRamStageV1::log,result});
    return result;
}
