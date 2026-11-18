namespace {void resetLegacyState();}
SoundCall::SoundCall(SoundCall&& other) noexcept
    :binding_(std::move(other.binding_)),status_(other.status_),legacy_(other.legacy_),admitted_(std::exchange(other.admitted_,false)),setup_(std::exchange(other.setup_,false)),control_(std::exchange(other.control_,false)) {
    other.status_=BankStatusV2::closed;other.legacy_=false;
}
SoundCall& SoundCall::operator=(SoundCall&& other) noexcept {
    if(this!=&other){release();binding_=std::move(other.binding_);status_=other.status_;legacy_=other.legacy_;admitted_=std::exchange(other.admitted_,false);setup_=std::exchange(other.setup_,false);control_=std::exchange(other.control_,false);other.status_=BankStatusV2::closed;other.legacy_=false;}return *this;
}
void SoundCall::release() noexcept {
    if(admitted_)binding_->release();
    if(control_){std::lock_guard<std::mutex> lock(backend_detail::registry.mutex);--backend_detail::registry.controls;}
    admitted_=control_=false;binding_.reset();status_=BankStatusV2::closed;legacy_=setup_=false;
}
SoundCall::~SoundCall(){release();}
SoundCallScope::SoundCallScope(const SoundCall& call) noexcept:previous_(backend_detail::active_call) {
    if(call.admitted_)backend_detail::active_call=call.binding_.get();
}
SoundCallScope::~SoundCallScope(){backend_detail::active_call=previous_;}
SoundCall acquireSoundCall(PS2Runtime* runtime) noexcept {
    using namespace backend_detail;SoundCall call;std::shared_ptr<Binding> binding;Mode mode;bool joint=false;
    {std::unique_lock<std::mutex> lock(registry.mutex);
        while(registry.boot_resetting)registry.changed.wait(lock);
        if(registry.mode==Mode::unselected)registry.mode=Mode::legacy;
        mode=registry.mode;joint=registry.joint_banks;if(mode==Mode::native)binding=registry.binding.lock();
    }
    if(mode==Mode::legacy || (mode==Mode::native&&!joint)) {call.legacy_=true;call.status_=BankStatusV2::ok;return call;}
    call.binding_=std::move(binding);
    if(!call.binding_)return call;
    if(runtime&&call.binding_->runtime!=runtime){call.status_=BankStatusV2::foreign_runtime;return call;}
    call.admitted_=call.binding_->acquire();if(call.admitted_)call.status_=BankStatusV2::ok;
    return call;
}
SoundCall acquireSoundControlCall(PS2Runtime* runtime) noexcept {
    using namespace backend_detail;SoundCall call;std::shared_ptr<Binding> binding;Mode mode;bool joint=false;
    {std::unique_lock<std::mutex> lock(registry.mutex);
        while(registry.boot_resetting)registry.changed.wait(lock);
        mode=registry.mode;joint=registry.joint_banks;if(mode==Mode::native)binding=registry.binding.lock();
        if(mode==Mode::unselected){
            if(registry.installing||registry.controls==UINT64_MAX)return call;
            ++registry.controls;call.control_=true;call.legacy_=true;call.status_=BankStatusV2::ok;return call;
        }
    }
    if(mode!=Mode::native||!joint){call.legacy_=true;call.status_=BankStatusV2::ok;return call;}
    call.binding_=std::move(binding);if(!call.binding_)return call;
    if(!runtime||call.binding_->runtime!=runtime){call.status_=BankStatusV2::foreign_runtime;return call;}
    call.admitted_=call.binding_->acquire();if(call.admitted_)call.status_=BankStatusV2::ok;return call;
}
bool withAudioSetupBeforeRun(PS2Runtime& runtime,AudioSetupOperationV2 operation,void* context) noexcept {
    if(!operation)return false;
    auto setup=runtime.acquirePreRunSetup();if(!setup)return false;
    {std::unique_lock<std::mutex> lock(backend_detail::registry.mutex);
        while(backend_detail::registry.boot_resetting)backend_detail::registry.changed.wait(lock);
        if(backend_detail::registry.mode!=backend_detail::Mode::unselected||backend_detail::registry.installing||backend_detail::registry.controls)return false;
        backend_detail::registry.boot_resetting=true;
    }
    backend_detail::BootResetReservation reservation;
    SoundCall call;call.legacy_=call.setup_=true;call.status_=BankStatusV2::ok;
    operation(context,call);return true;
}
bool coversSoundRpcV2(std::uint32_t sid,std::uint32_t rpc) noexcept {
    const auto query=rpc&0xFFu;
    return (sid==0&&rpc==0)||(sid==1&&(query==4||query==6||query==0x0C||rpc==0x12||rpc==0x13));
}
BankStatusV2 SoundCall::ensure_output() const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;
    SoundCallScope scope(*this);
    if(legacy_)ensureHostOutput();else {auto& r=binding_->registration;r.api.ensure_host_output(r.owner.get());}
    return BankStatusV2::ok;
}
BankStatusV2 SoundCall::reset_pcm() const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;SoundCallScope scope(*this);
    if(legacy_){if(setup_)resetLegacyState();else reset();}
    else {auto& r=binding_->registration;r.api.reset(r.owner.get());}
    return BankStatusV2::ok;
}
BankStatusV2 SoundCall::submit_bank(unsigned port,const std::uint8_t* hd,std::size_t hn,const std::uint8_t* bd,std::size_t bn,const std::uint8_t* tq,std::size_t tn) const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;SoundCallScope scope(*this);
    if(legacy_)return ps2_reo_sound::legacy_detail::submitBank(port,hd,hn,bd,bn,tq,tn)?BankStatusV2::ok:BankStatusV2::rejected;
    return binding_->banks.submit_bank(binding_->registration.owner.get(),port,hd,hn,bd,bn,tq,tn);
}
BankStatusV2 SoundCall::submit_packet(const std::uint8_t* ram,std::size_t rn,const std::uint8_t* packet,std::size_t pn) const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;SoundCallScope scope(*this);
    if(legacy_)return ps2_reo_sound::legacy_detail::submitPacket(ram,rn,packet,pn)?BankStatusV2::ok:BankStatusV2::rejected;
    return binding_->banks.submit_packet(binding_->registration.owner.get(),ram,rn,packet,pn);
}
BankStatusV2 SoundCall::mix(float* out,unsigned frames) const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;SoundCallScope scope(*this);
    if(legacy_){ps2_reo_sound::legacy_detail::mix(out,frames);return BankStatusV2::ok;}
    return binding_->banks.mix(binding_->registration.owner.get(),out,frames);
}
BankStatusV2 SoundCall::reset_banks() const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;SoundCallScope scope(*this);
    if(legacy_){ps2_reo_sound::legacy_detail::reset();return BankStatusV2::ok;}
    return binding_->banks.reset(binding_->registration.owner.get());
}
BankQueryV2 SoundCall::pending_loads() const {
    if(status_!=BankStatusV2::ok)return {status_,0};if(control_)return {BankStatusV2::unsupported,0};SoundCallScope scope(*this);
    if(legacy_)return {BankStatusV2::ok,ps2_reo_sound::legacy_detail::pendingLoads()};
    return binding_->banks.pending_loads(binding_->registration.owner.get());
}
BankQueryV2 SoundCall::port_state(unsigned port,std::uint32_t& count) const {
    if(status_!=BankStatusV2::ok)return {status_,0};if(control_)return {BankStatusV2::unsupported,0};SoundCallScope scope(*this);
    if(legacy_)return {BankStatusV2::ok,ps2_reo_sound::legacy_detail::portState(port,count)};
    std::uint32_t staged{};auto result=binding_->banks.port_state(binding_->registration.owner.get(),port,staged);
    if(result.status==BankStatusV2::ok)count=staged;return result;
}
BankQueryV2 SoundCall::se_state(unsigned port,unsigned index,unsigned group) const {
    if(status_!=BankStatusV2::ok)return {status_,0};if(control_)return {BankStatusV2::unsupported,0};SoundCallScope scope(*this);
    if(legacy_)return {BankStatusV2::ok,ps2_reo_sound::legacy_detail::seState(port,index,group)};
    return binding_->banks.se_state(binding_->registration.owner.get(),port,index,group);
}
BankStatusV2 SoundCall::report_audio_paths() const {
    if(status_!=BankStatusV2::ok)return status_;if(control_)return BankStatusV2::unsupported;SoundCallScope scope(*this);
    if(legacy_){ps2_reo_sound::legacy_detail::reportAudioPaths();return BankStatusV2::ok;}
    return binding_->banks.report_audio_paths(binding_->registration.owner.get());
}
bool resetBanksBeforeRuntimeRun(PS2Runtime& runtime) noexcept {
    auto setup=runtime.acquirePreRunSetup();if(!setup)return false;
    {std::unique_lock<std::mutex> lock(backend_detail::registry.mutex);
        while(backend_detail::registry.boot_resetting)backend_detail::registry.changed.wait(lock);
        if(backend_detail::registry.mode!=backend_detail::Mode::unselected||backend_detail::registry.installing||backend_detail::registry.controls)return false;
        backend_detail::registry.boot_resetting=true;
    }
    backend_detail::BootResetReservation reservation;
    try{ps2_reo_sound::legacy_detail::reset();return true;}catch(...){return false;}
}
