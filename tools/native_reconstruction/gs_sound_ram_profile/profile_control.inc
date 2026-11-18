struct FactoryEntryV1 {Factory factory;SoundRamProfileProbeV1 probe{};};
namespace {
struct ProfiledFactoryV1 {
    Factory factory;SoundRamProfileProbeV1 probe;
    std::unique_ptr<Backend> operator()()const{return factory();}
};
std::uint64_t factoryGenerationV1=1,factoryPinsV1{},controlsV1{};
std::thread::id globalControlThreadV1;
std::uint32_t globalControlDepthV1{};
std::uint64_t globalControlGenerationV1{};
std::shared_ptr<const FactoryEntryV1> factoryEntryV1;
struct RuntimeProfileSealV1 {const PS2Runtime* runtime{};std::uint64_t count{};};
std::array<RuntimeProfileSealV1,16> runtimeSealsV1{};
}
Factory withSoundRamProfileProbeV1(Factory value,SoundRamProfileProbeV1 probe){
    if(!value||!probe)throw std::invalid_argument("Complete concrete GS factory/probe required");
    return ProfiledFactoryV1{std::move(value),probe};
}
SoundRamProfileStatusV1 tryRegisterFactoryV1(Factory value){
    {std::lock_guard lock(factoryMutex());if(factoryPinsV1)return SoundRamProfileStatusV1::leased;}
    auto next=std::make_shared<FactoryEntryV1>();
    if(auto* body=value.target<ProfiledFactoryV1>())next->probe=body->probe;
    next->factory=std::move(value);std::shared_ptr<const FactoryEntryV1> previous;
    {std::lock_guard lock(factoryMutex());
        if(factoryPinsV1)return SoundRamProfileStatusV1::leased;
        if(factoryGenerationV1==UINT64_MAX)return SoundRamProfileStatusV1::capacity;
        previous=std::move(factoryEntryV1);factoryEntryV1=std::move(next);++factoryGenerationV1;}
    return SoundRamProfileStatusV1::ok; // Previous captures die outside metadata lock.
}
FactorySnapshotV1 registeredFactoryV1(){
    std::lock_guard lock(factoryMutex());FactorySnapshotV1 result;
    result.entry_=factoryEntryV1;result.generation_=factoryGenerationV1;return result;
}
bool soundRamProfileHeldForRuntimeV1(const PS2Runtime* runtime) noexcept {
    std::lock_guard lock(factoryMutex());
    for(const auto& seal:runtimeSealsV1)if(runtime&&seal.runtime==runtime&&seal.count)return true;
    return false;
}
bool soundRamSelectionHeldV1() noexcept {std::lock_guard lock(factoryMutex());return factoryPinsV1!=0;}
GlobalGsControlV1::GlobalGsControlV1(GlobalGsControlV1&& other) noexcept {*this=std::move(other);}
GlobalGsControlV1& GlobalGsControlV1::operator=(GlobalGsControlV1&& other) noexcept {
    if(this!=&other){release();active_=std::exchange(other.active_,false);thread_=other.thread_;outer_=other.outer_;generation_=other.generation_;}return *this;
}
GlobalGsControlV1::~GlobalGsControlV1(){release();}
void GlobalGsControlV1::release() noexcept {
    if(!std::exchange(active_,false))return;
    std::lock_guard lock(factoryMutex());
    if(thread_!=std::this_thread::get_id()||globalControlThreadV1!=thread_||!globalControlDepthV1||!controlsV1)std::terminate();
    if(!--globalControlDepthV1){globalControlThreadV1={};--controlsV1;}
}
std::uint64_t GlobalGsControlV1::profilePermitV1()const noexcept {
    std::lock_guard lock(factoryMutex());
    return active_&&outer_&&thread_==std::this_thread::get_id()&&globalControlThreadV1==thread_&&
        globalControlDepthV1==1&&controlsV1==1&&globalControlGenerationV1==generation_?generation_:0;
}
GlobalGsControlResultV1 acquireGlobalGsControlV1() noexcept {
    std::lock_guard lock(factoryMutex());const auto thread=std::this_thread::get_id();
    if(factoryPinsV1)return {SoundRamProfileStatusV1::leased,{}};
    if(globalControlDepthV1){
        if(globalControlThreadV1!=thread)return {SoundRamProfileStatusV1::busy,{}};
        if(globalControlDepthV1==UINT32_MAX)return {SoundRamProfileStatusV1::capacity,{}};
        ++globalControlDepthV1;
    }else{
        if(controlsV1)return {SoundRamProfileStatusV1::busy,{}};
        if(globalControlGenerationV1==UINT64_MAX)return {SoundRamProfileStatusV1::capacity,{}};
        globalControlThreadV1=thread;globalControlDepthV1=1;++controlsV1;
        ++globalControlGenerationV1;
    }
    GlobalGsControlV1 result;result.active_=true;result.thread_=thread;result.outer_=globalControlDepthV1==1;result.generation_=globalControlGenerationV1;
    return {SoundRamProfileStatusV1::ok,std::move(result)};
}
SoundRamSelectionLeaseV1::SoundRamSelectionLeaseV1(SoundRamSelectionLeaseV1&& other) noexcept {*this=std::move(other);}
SoundRamSelectionLeaseV1& SoundRamSelectionLeaseV1::operator=(SoundRamSelectionLeaseV1&& other) noexcept {
    if(this!=&other){release();route_=std::exchange(other.route_,nullptr);identity_=other.identity_;
        incarnation_=other.incarnation_;factory_generation_=other.factory_generation_;runtime_slot_=other.runtime_slot_;}return *this;
}
SoundRamSelectionLeaseV1::~SoundRamSelectionLeaseV1(){release();}
bool SoundRamSelectionLeaseV1::matches(const PS2Runtime& runtime,const void* ee,const void* iop)const noexcept {
    return route_&&identity_.runtime==&runtime&&identity_.ee==ee&&identity_.iop==iop;
}
void SoundRamSelectionLeaseV1::release() noexcept {
    auto* route=std::exchange(route_,nullptr);if(!route)return;
    std::lock_guard lock(factoryMutex());auto& seal=runtimeSealsV1[runtime_slot_];
    if(!route->profilePinsV1_||!factoryPinsV1||!seal.count||seal.runtime!=identity_.runtime||route->profileIncarnationV1_!=incarnation_)std::terminate();
    --route->profilePinsV1_;--factoryPinsV1;if(!--seal.count)seal.runtime=nullptr;
}
SoundRamProfileStatusV1 Route::reserveProfileControlV1(bool starting,std::uint64_t generation){
    std::lock_guard lock(factoryMutex());
    if(profilePinsV1_||(starting&&factoryPinsV1))return SoundRamProfileStatusV1::leased;
    if(globalControlDepthV1&&globalControlThreadV1!=std::this_thread::get_id())return SoundRamProfileStatusV1::busy;
    if(profileTransitionV1_)return SoundRamProfileStatusV1::busy;
    if(generation&&generation!=factoryGenerationV1)return SoundRamProfileStatusV1::unavailable;
    if(controlsV1==UINT64_MAX||profileIncarnationV1_==UINT64_MAX)return SoundRamProfileStatusV1::capacity;
    profileTransitionV1_=true;++controlsV1;return SoundRamProfileStatusV1::ok;
}
void Route::finishProfileControlV1(std::uint64_t factoryGeneration,SoundRamProfileProbeV1 probe) noexcept {
    std::lock_guard lock(factoryMutex());if(!profileTransitionV1_||!controlsV1)std::terminate();
    ++profileIncarnationV1_;profileFactoryGenerationV1_=factoryGeneration;profileProbeV1_=probe;
    profileTransitionV1_=false;--controlsV1;
}
SoundRamProfileResultV1 Route::acquireProfileV1(SoundRamProfileIdentityV1 identity,std::uint64_t permit) noexcept {
    SoundRamSelectionLeaseV1 lease;
    {
        std::lock_guard lock(factoryMutex());
        const bool ownMint=permit&&permit==globalControlGenerationV1&&globalControlDepthV1==1&&controlsV1==1;
        if(profileTransitionV1_||(controlsV1&&!ownMint))return {SoundRamProfileStatusV1::busy,{}};
        if(!identity.runtime||!identity.ee||!identity.iop||!identity.vram||!identity.gs)return {SoundRamProfileStatusV1::foreign_runtime,{}};
        if(!profileProbeV1_||!profileFactoryGenerationV1_||profileFactoryGenerationV1_!=factoryGenerationV1||state_!=State::Accelerated)return {SoundRamProfileStatusV1::unsupported,{}};
        if(profilePinsV1_==UINT64_MAX||factoryPinsV1==UINT64_MAX)return {SoundRamProfileStatusV1::capacity,{}};
        std::size_t slot=runtimeSealsV1.size();
        for(std::size_t n=0;n<runtimeSealsV1.size();++n)if(runtimeSealsV1[n].runtime==identity.runtime){slot=n;break;}
        if(slot==runtimeSealsV1.size())for(std::size_t n=0;n<runtimeSealsV1.size();++n)if(!runtimeSealsV1[n].count){slot=n;break;}
        if(slot==runtimeSealsV1.size()||runtimeSealsV1[slot].count==UINT64_MAX)return {SoundRamProfileStatusV1::capacity,{}};
        ++profilePinsV1_;++factoryPinsV1;runtimeSealsV1[slot].runtime=identity.runtime;++runtimeSealsV1[slot].count;
        lease.route_=this;lease.identity_=identity;lease.incarnation_=profileIncarnationV1_;lease.factory_generation_=profileFactoryGenerationV1_;lease.runtime_slot_=slot;
    }
    // Pin prevents rebind/close. Never wait behind a GPU execution from another
    // thread, and never hold factory/selection metadata across the app probe.
    std::unique_lock lock(mutex_,std::try_to_lock);
    if(!lock.owns_lock())return {SoundRamProfileStatusV1::busy,{}};
    if(state_!=State::Accelerated||!backend_||!profileProbeV1_(*backend_))return {SoundRamProfileStatusV1::unsupported,{}};
    return {SoundRamProfileStatusV1::ok,std::move(lease)};
}
SoundRamProfileStatusV1 Route::tryStopV1() noexcept {
    const auto status=reserveProfileControlV1(false,0);if(status!=SoundRamProfileStatusV1::ok)return status;
    std::unique_ptr<Backend> old;
    {std::lock_guard lock(mutex_);old=std::move(backend_);state_=State::Stopped;}
    if(old)old->close();old.reset(); // No selection/execution lock across close.
    finishProfileControlV1(0,nullptr);return SoundRamProfileStatusV1::ok;
}
bool Route::startRegisteredV1(Choice choice,const Init& init,FactorySnapshotV1 snapshot,std::string& reason){
    return startProfileV1(choice,init,snapshot.entry_?snapshot.entry_->factory:Factory{},snapshot.generation_,snapshot.entry_?snapshot.entry_->probe:nullptr,reason);
}
bool Route::start(Choice choice,const Init& init,Factory make,std::string& reason){
    return startProfileV1(choice,init,std::move(make),0,nullptr,reason);
}
bool Route::startProfileV1(Choice choice,const Init& init,Factory make,std::uint64_t generation,SoundRamProfileProbeV1 probe,std::string& reason){
    const auto reserved=reserveProfileControlV1(true,generation);
    if(reserved!=SoundRamProfileStatusV1::ok){reason=reserved==SoundRamProfileStatusV1::leased?"GS selection leased by native sound":"GS selection transition unavailable";return false;}
    struct Finish final {Route& route;std::uint64_t generation{};SoundRamProfileProbeV1 probe{};
        ~Finish(){route.finishProfileControlV1(generation,probe);}} finish{*this};
    // Reservation blocks new pins. Old working backend is untouched until the
    // pre-effect lease check above. Factory/init/close run outside all locks.
    std::unique_ptr<Backend> old,candidate;
    {std::lock_guard lock(mutex_);old=std::move(backend_);error_.clear();vramSize_=init.vramSize;state_=State::Software;}
    if(old)old->close();old.reset();reason.clear();bool selected=false;
    if(choice!=Choice::Software){try{
        if(!init.vram||init.vramSize!=4u*1024u*1024u)throw std::runtime_error("GS backend requires 4 MiB initial VRAM");
        if(!make)throw std::runtime_error("paraLLEl backend factory is not registered");
        candidate=make();if(!candidate)throw std::runtime_error("GS backend factory returned null");
        if(candidate->init(init,reason))selected=true;
        else if(reason.empty())reason="GS backend initialization returned false";
    }catch(const std::exception& e){reason=e.what();}catch(...){reason="GS backend initialization failed";}}
    if(!selected&&candidate){candidate->close();candidate.reset();}
    {std::lock_guard lock(mutex_);if(selected){backend_=std::move(candidate);state_=State::Accelerated;reason.clear();}}
    finish.generation=selected?generation:0;finish.probe=selected?probe:nullptr;return selected;
}
