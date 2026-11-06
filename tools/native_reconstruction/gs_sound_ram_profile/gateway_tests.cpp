#define main route_metadata_test_main
#include "tests.cpp"
#undef main
class GS {};
std::atomic<bool> memoryFreed{},gsJoined{},stopped{};
std::atomic<unsigned> guestDepth{},ioDepth{};
constexpr unsigned PS2_RAM_SIZE=32u*1024u*1024u;
unsigned ps2RamBackingBytes=PS2_RAM_SIZE;
class PS2Runtime {
public:
    struct Memory {std::array<uint8_t,1> ee{},iop{},vram{};unsigned reads{};
        uint8_t* getRDRAM(){++reads;return ee.data();}uint8_t* getIOPRAM(){++reads;return iop.data();}uint8_t* getGSVRAM(){++reads;return vram.data();}
        ~Memory(){memoryFreed=true;}}m_memory;
    Memory& memory(){return m_memory;}GS gs_;GS& gs(){return gs_;}
    unsigned setupCount{};bool running{},stopping{};
    class Setup {PS2Runtime* r_{};public:Setup()=default;explicit Setup(PS2Runtime*r):r_(r){++r_->setupCount;}Setup(Setup&&o)noexcept:r_(std::exchange(o.r_,nullptr)){}~Setup(){if(r_)--r_->setupCount;}explicit operator bool()const{return r_;}};
    Setup acquirePreRunSetup(){return running||stopping?Setup{}:Setup(this);}
    struct ExternalWorker {virtual ~ExternalWorker()=default;virtual void requestStop()noexcept=0;virtual bool join()noexcept=0;};
    std::vector<std::shared_ptr<ExternalWorker>> workers;
    bool externalWorkerResetAllowed(){return workers.empty()&&setupCount==0;}
    void requestStop(){if(stopping)return;stopping=true;for(auto&w:workers)w->requestStop();}
    void joinExternalWorkersOrTerminate(){for(auto&w:workers){w->requestStop();if(!w->join())std::terminate();}}
    ~PS2Runtime();
};
namespace {g::Route g_backendRoute;GS* g_gsInstance{};std::function<void()> pending;
enum class Control {complete,cancel_before,cancel_after,throw_pending};Control behavior=Control::complete;
bool gsBackendControl(std::function<void()> fn){if(behavior==Control::cancel_before||behavior==Control::throw_pending){pending=std::move(fn);if(behavior==Control::throw_pending)throw std::runtime_error("injected enqueue failure");return false;}fn();return behavior!=Control::cancel_after;}}
uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept{return guestDepth;}
uint32_t ps2IoRegLockDepth()noexcept{return ioDepth;}
bool ps2GsWorkerStopRequested(){return stopped;}
namespace gs_backend_bridge {
#include "actual_gateway.inc"
}
void ps2GsJoinWorker(){
#include "actual_join_guard.inc"
    gsJoined=true;if(g_backendRoute.tryStopV1()!=S::ok)std::terminate();g_gsInstance=nullptr;
}
void ps2GsJoinRasterWorkers(){}
namespace reo_parent_natural {void beginActualRuntimeContextStop(PS2Runtime&){}void stopActualPreEntryControlRuntime(PS2Runtime&){}void finishActualRuntimeContextStopAfterGsJoin(PS2Runtime&){} }
namespace ps2_syscalls {void joinInterruptWorker(){}void joinAllGuestHostThreads(){}void finishRuntimeStop(){} }
namespace reo_async_vif {void shutdown(PS2Runtime::Memory&){} }
namespace reo_native_movie {void releaseImageProviderAfterGsJoin(PS2Runtime&){} }
namespace reo_resident_live {void releaseAfterGsStop(PS2Runtime::Memory&){} }
namespace ps2_cri_audio {void shutdown(){} }
#include "actual_destructor_prefix.inc"
struct Worker final:PS2Runtime::ExternalWorker {
    g::SoundRamSelectionLeaseV1 lease;Event stopSeen,allowDrain;std::atomic<bool> joined{};
    void requestStop()noexcept override{stopSeen.signal();}
    bool join()noexcept override{allowDrain.wait();lease.release();joined=true;return true;}
};
void initialize(PS2Runtime& r){setup(g_backendRoute);g_gsInstance=&r.gs();}
void gateway_basic(){
    PS2Runtime r;initialize(r);auto result=g::acquireSoundRamProfileBeforeRunV1(r);check(result.status==S::ok&&result.lease);check(r.setupCount==0);
    check(result.lease.matches(r,r.memory().ee.data(),r.memory().iop.data()));check(g::acquireGlobalGsControlV1().status==S::leased);
    result.lease.release();check(!g::soundRamSelectionHeldV1());
}
void gateway_refusals(){
    PS2Runtime r;initialize(r);r.running=true;check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::unavailable);r.running=false;
    guestDepth=1;check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::unavailable);guestDepth=0;
    ioDepth=1;check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::unavailable);ioDepth=0;
    ps2RamBackingBytes=2*PS2_RAM_SIZE;check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::foreign_runtime);ps2RamBackingBytes=PS2_RAM_SIZE;
    GS foreign;g_gsInstance=&foreign;check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::foreign_runtime);g_gsInstance=&r.gs();
    {auto global=g::acquireGlobalGsControlV1();check(global.status==S::ok);check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::busy);}
    check(r.setupCount==0&&!g::soundRamSelectionHeldV1());
}
void cancellation(){
    PS2Runtime r;initialize(r);
    for(auto mode:{Control::cancel_before,Control::cancel_after,Control::throw_pending}){
        behavior=mode;check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::unavailable);check(!g::soundRamSelectionHeldV1()&&r.setupCount==0);
        if(pending){auto after=std::exchange(pending,{});auto global=g::acquireGlobalGsControlV1();check(global.status==S::ok);after();check(!g::soundRamSelectionHeldV1());}
    }behavior=Control::complete;
    check(g::acquireSoundRamProfileBeforeRunV1(r).status==S::ok);
}
void actual_teardown_order(){
    auto r=std::make_unique<PS2Runtime>();initialize(*r);auto result=g::acquireSoundRamProfileBeforeRunV1(*r);check(result.status==S::ok);
    auto worker=std::make_shared<Worker>();worker->lease=std::move(result.lease);r->workers.push_back(worker);
    auto deleting=std::async(std::launch::async,[value=r.release()]{delete value;});worker->stopSeen.wait();
    check(!gsJoined&&!memoryFreed&&g::soundRamSelectionHeldV1());worker->allowDrain.signal();deleting.get();
    check(worker->joined&&gsJoined&&memoryFreed&&!g::soundRamSelectionHeldV1());
}
int main(int argc,char**argv)try{
    std::set_terminate([]{std::fputs("GS profile illegal teardown order\n",stderr);std::_Exit(87);});check(argc==2);std::string mode=argv[1];
    if(mode=="gateway")gateway_basic();else if(mode=="refusals")gateway_refusals();else if(mode=="cancel")cancellation();else if(mode=="teardown")actual_teardown_order();else throw std::runtime_error("gateway mode");
    std::cout<<"gateway checks="<<checks.load()<<'\n';return 0;
}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
