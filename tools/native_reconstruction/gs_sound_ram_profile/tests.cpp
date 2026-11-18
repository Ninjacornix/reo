#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <thread>
#include <utility>
#include <vector>
#define private public
#include <gs_sound_ram_profile.h>
#undef private
#include "parallel_backend.h"
#include "gs_backend_route.cpp"
using namespace std::chrono_literals;
namespace g=gs_backend_bridge;
using S=g::SoundRamProfileStatusV1;
struct Event {std::mutex mutex;std::condition_variable cv;bool set{};void signal(){std::lock_guard lock(mutex);set=true;cv.notify_all();}void wait(){std::unique_lock lock(mutex);cv.wait(lock,[&]{return set;});}};
alignas(16) std::array<uint8_t,16> packet{};
std::atomic<unsigned> checks{};
void check(bool v){auto n=++checks;if(!v)throw std::runtime_error("GS profile assertion "+std::to_string(n));}
struct Counters {unsigned inits{},closes{},draws{},resets{},destroys{};bool fail{},throw_init{},pause_init{},pause_close{},pause_draw{};Event entered,resume;};
std::shared_ptr<Counters> counters;
// Declared source surroundings only; production functions are the actual SDK
// atomic enrollment/binding observations, compiled in the full app object.
namespace reo_parent_natural {
bool testEnrollment{},testOwner{};
bool actualFirstEntryEnrollmentRequested()noexcept{return testEnrollment;}
bool anyActualOwnerBound()noexcept{return testOwner;}
}
namespace reo_parallel_backend {
namespace {
class ParallelBackend final:public g::Backend {
    Config config_;bool live_{};std::shared_ptr<Counters> count_=counters;
public:
#include "actual_member.inc"
    explicit ParallelBackend(Config config):config_(std::move(config)){}
    ~ParallelBackend()override{++count_->destroys;}
    bool init(const g::Init&,std::string&)override{++count_->inits;if(count_->pause_init){count_->entered.signal();count_->resume.wait();}if(count_->throw_init)throw std::runtime_error("injected init failure");live_=!count_->fail;return live_;}
    void close()noexcept override{++count_->closes;live_=false;if(count_->pause_close){count_->entered.signal();count_->resume.wait();}}
    void reset()override{++count_->resets;}
    void rawGif(uint8_t,const uint8_t*,size_t)override{++count_->draws;if(count_->pause_draw){count_->entered.signal();count_->resume.wait();}}
    void directRegister(uint8_t,uint64_t)override{}
    void privilegedWrite(uint32_t,uint8_t,uint64_t)override{}
    g::Frame capture(const g::Capture&)override{return {};}
    void exportVram(size_t,uint8_t*,size_t)override{}
    uint32_t readTransfer(uint8_t*,uint32_t)override{return 0;}
    bool clearContext(uint32_t,uint32_t,bool)override{return true;}
    void flush()override{}
};
}
#include "actual_probe.inc"
#include "actual_factory.inc"
}
g::Init init(){g::Init i;i.vram=reinterpret_cast<const uint8_t*>(0x300000);i.vramSize=4u*1024u*1024u;return i;}
g::SoundRamProfileIdentityV1 identity(unsigned n=1){return {reinterpret_cast<PS2Runtime*>(uintptr_t(0x1000*n)),reinterpret_cast<void*>(0x100000),reinterpret_cast<void*>(0x200000),init().vram,reinterpret_cast<GS*>(uintptr_t(0x2000*n))};}
std::shared_ptr<Counters> setup(g::Route& route,bool resident=false){
    counters=std::make_shared<Counters>();reo_parallel_backend::Config cfg;cfg.residentGeometry.enabled=resident;
    cfg.validatedDrawing=true;cfg.residentPresentation=true;cfg.persistentPipelineCache=true;cfg.forceProgressive=true;cfg.antiBlur=true;
    check(g::tryRegisterFactoryV1(reo_parallel_backend::makeFactory(std::move(cfg)))==S::ok);
    std::string reason;check(route.startRegisteredV1(g::Choice::Parallel,init(),g::registeredFactoryV1(),reason));return counters;
}
void basic(){
    g::Route route;auto count=setup(route);auto acquired=route.acquireProfileV1(identity());check(acquired.status==S::ok&&acquired.lease);
    check(acquired.lease.matches(*identity().runtime,identity().ee,identity().iop));check(g::soundRamProfileHeldForRuntimeV1(identity().runtime));
    check(!acquired.lease.matches(*identity(2).runtime,identity().ee,identity().iop));check(acquired.lease.incarnation()!=0&&acquired.lease.factory_generation()!=0);
    auto oldInc=acquired.lease.incarnation();g::SoundRamSelectionLeaseV1 moved=std::move(acquired.lease);check(moved&&!acquired.lease);
    auto second=route.acquireProfileV1(identity());check(second.status==S::ok);moved=std::move(second.lease);check(moved&&!second.lease);
    check(route.tryStopV1()==S::leased&&count->closes==0);std::string why;
    check(!route.startRegisteredV1(g::Choice::Software,init(),g::registeredFactoryV1(),why)&&route.state()==g::State::Accelerated&&count->closes==0);
    check(!route.start(g::Choice::Parallel,init(),g::registeredFactory(),why)&&count->inits==1);
    check(g::tryRegisterFactoryV1({})==S::leased);bool refused=false;try{g::registerFactory({});}catch(const std::logic_error&){refused=true;}check(refused);
    check(route.gif(3,packet.data(),packet.size())&&route.reset());check(count->draws==1&&count->resets==1);
    moved.release();check(!g::soundRamSelectionHeldV1());check(route.tryStopV1()==S::ok&&count->closes==1&&count->destroys==1);
    setup(route);auto next=route.acquireProfileV1(identity());check(next.status==S::ok&&next.lease.incarnation()>oldInc);
}
void unsupported(){
    {g::Route route;setup(route,true);check(route.acquireProfileV1(identity()).status==S::unsupported);check(!g::soundRamSelectionHeldV1());}
    {g::Route route;counters=std::make_shared<Counters>();std::string why;check(route.start(g::Choice::Parallel,init(),reo_parallel_backend::makeFactory({}),why));check(route.acquireProfileV1(identity()).status==S::unsupported);}
    {g::Route route;setup(route);auto bad=identity();bad.iop=nullptr;check(route.acquireProfileV1(bad).status==S::foreign_runtime);}
    {g::Route route;setup(route);reo_parent_natural::testEnrollment=true;check(route.acquireProfileV1(identity()).status==S::unsupported);reo_parent_natural::testEnrollment=false;
        reo_parent_natural::testOwner=true;check(route.acquireProfileV1(identity()).status==S::unsupported);reo_parent_natural::testOwner=false;check(route.acquireProfileV1(identity()).status==S::ok);}
    {g::Route route;counters=std::make_shared<Counters>();counters->fail=true;g::registerFactory(reo_parallel_backend::makeFactory({}));std::string why;
        check(!route.startRegisteredV1(g::Choice::Parallel,init(),g::registeredFactoryV1(),why));check(route.acquireProfileV1(identity()).status==S::unsupported);}
    {g::Route route;setup(route);g::registerFactory(reo_parallel_backend::makeFactory({}));check(route.acquireProfileV1(identity()).status==S::unsupported);}
}
void transitions(){
    g::Route route;counters=std::make_shared<Counters>();auto count=counters;count->pause_init=true;g::registerFactory(reo_parallel_backend::makeFactory({}));std::string why;
    auto starting=std::async(std::launch::async,[&]{return route.startRegisteredV1(g::Choice::Parallel,init(),g::registeredFactoryV1(),why);});count->entered.wait();
    check(route.acquireProfileV1(identity()).status==S::busy);check(route.tryStopV1()==S::busy);
    // Proves factory registration is not locked across external init.
    check(g::tryRegisterFactoryV1(reo_parallel_backend::makeFactory({}))==S::ok);count->resume.signal();check(starting.get());
    check(route.acquireProfileV1(identity()).status==S::unsupported); // Old factory generation.
    check(route.tryStopV1()==S::ok);count=setup(route);count->pause_close=true;
    auto closing=std::async(std::launch::async,[&]{return route.tryStopV1();});count->entered.wait();check(route.acquireProfileV1(identity()).status==S::busy);
    check(g::tryRegisterFactoryV1(reo_parallel_backend::makeFactory({}))==S::ok);count->resume.signal();check(closing.get()==S::ok);
}
void busy_probe(){
    g::Route route;auto count=setup(route);count->pause_draw=true;auto drawing=std::async(std::launch::async,[&]{return route.gif(3,packet.data(),packet.size());});count->entered.wait();
    check(route.acquireProfileV1(identity()).status==S::busy);check(!g::soundRamSelectionHeldV1());count->resume.signal();check(drawing.get());
    auto acquired=route.acquireProfileV1(identity());check(acquired.status==S::ok);
}
void races(){
    for(unsigned n=0;n<32;++n){g::Route route;auto count=setup(route);std::promise<void> start;auto ready=start.get_future().share();
        auto pin=std::async(std::launch::async,[&]{ready.wait();return route.acquireProfileV1(identity());});
        auto stop=std::async(std::launch::async,[&]{ready.wait();return route.tryStopV1();});start.set_value();auto p=pin.get();auto s=stop.get();
        check((p.status==S::ok&&s==S::leased&&count->closes==0)||((p.status==S::busy||p.status==S::unsupported)&&s==S::ok&&count->closes==1));}
}
void factory_races(){
    for(unsigned n=0;n<32;++n){g::Route route;setup(route);std::promise<void> start;auto ready=start.get_future().share();
        auto pin=std::async(std::launch::async,[&]{ready.wait();return route.acquireProfileV1(identity());});
        auto replace=std::async(std::launch::async,[&]{ready.wait();return g::tryRegisterFactoryV1(reo_parallel_backend::makeFactory({}));});start.set_value();auto p=pin.get();auto r=replace.get();
        check((p.status==S::ok&&r==S::leased)||(p.status==S::unsupported&&r==S::ok));}
}
void global_controls(){
    g::Route route;setup(route);
    {
        auto outer=g::acquireGlobalGsControlV1();check(outer.status==S::ok&&outer.control);
        check(!g::soundRamSelectionHeldV1()); // A boolean-only guard misses this.
        check(route.acquireProfileV1(identity()).status==S::busy);
        auto nested=g::acquireGlobalGsControlV1();check(nested.status==S::ok&&nested.control);
        check(!nested.control.profilePermitV1());
        auto foreign=std::async(std::launch::async,[]{return g::acquireGlobalGsControlV1().status;});check(foreign.get()==S::busy);
        std::string reason;check(route.startRegisteredV1(g::Choice::Parallel,init(),g::registeredFactoryV1(),reason));
        check(route.acquireProfileV1(identity()).status==S::busy);
    }
    auto pin=route.acquireProfileV1(identity());check(pin.status==S::ok);check(g::acquireGlobalGsControlV1().status==S::leased);
}
void global_races(){
    for(unsigned n=0;n<32;++n){g::Route route;setup(route);std::promise<void> start;auto ready=start.get_future().share();Event pinned,controlled,release;S ps{},cs{};
        auto pin=std::async(std::launch::async,[&]{ready.wait();auto p=route.acquireProfileV1(identity());ps=p.status;pinned.signal();release.wait();});
        auto control=std::async(std::launch::async,[&]{ready.wait();auto c=g::acquireGlobalGsControlV1();cs=c.status;controlled.signal();release.wait();});
        start.set_value();pinned.wait();controlled.wait();const bool valid=(ps==S::ok&&cs==S::leased)||(ps==S::busy&&cs==S::ok);release.signal();pin.get();control.get();check(valid);}
}
int main(int argc,char**argv)try{check(argc==2);std::string mode=argv[1];
    if(mode=="basic")basic();else if(mode=="unsupported")unsupported();else if(mode=="transitions")transitions();else if(mode=="busy")busy_probe();else if(mode=="races")races();else if(mode=="factory_races")factory_races();else if(mode=="global")global_controls();else if(mode=="global_races")global_races();
    else if(mode=="illegal_stop"){g::Route route;setup(route);auto pin=route.acquireProfileV1(identity());check(pin.status==S::ok);std::set_terminate([]{std::_Exit(86);});route.stop();throw std::runtime_error("illegal stop returned");}
    else if(mode=="illegal_destructor"){auto route=std::make_unique<g::Route>();setup(*route);auto pin=route->acquireProfileV1(identity());check(pin.status==S::ok);std::set_terminate([]{std::_Exit(86);});route.reset();throw std::runtime_error("illegal destructor returned");}
    else throw std::runtime_error("unknown GS profile mode");std::cout<<"gs_profile checks="<<checks.load()<<'\n';return 0;
}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
