#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <memory>
#include <mutex>
#include <new>
#include <stdexcept>
#include <string>
#include <thread>
#include <vector>

std::atomic<bool> reject_new{};
[[gnu::noinline]] void* operator new(std::size_t size){if(reject_new.exchange(false))throw std::bad_alloc();if(auto* p=std::malloc(size?size:1))return p;throw std::bad_alloc();}
[[gnu::noinline]] void operator delete(void* p) noexcept {std::free(p);}
[[gnu::noinline]] void operator delete(void* p,std::size_t) noexcept {std::free(p);}
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
float reoAudioMasterGain(){return 1;}
float reoAudioStreamGain(std::uint32_t){return 1;}
void reoAudioPoll(){}
void reoAudioResetStreams(){}
std::atomic<unsigned> bank_calls{},bank_resets{};
namespace ps2_reo_sound {void mix(float*,unsigned){++bank_calls;}void reset(){++bank_resets;}void reportAudioPaths(){}}
namespace a=ps2_cri_audio;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("dispatch check failed");}
template<class Predicate>void await(Predicate predicate){const auto until=std::chrono::steady_clock::now()+std::chrono::seconds(5);while(!predicate()){if(std::chrono::steady_clock::now()>until)throw std::runtime_error("bounded await failed");std::this_thread::yield();}}
struct State {std::mutex mutex;std::condition_variable changed;bool hold_queue{},hold_render{},hold_stop{},release{};std::atomic<unsigned> entered{},destroyed{};};
enum Count {Ensure,Queue,Configure,Consumed,Render,Discard,Drain,Release,Queued,Reset,Shutdown,Stop,Join,CountSize};
struct Fake {
    std::shared_ptr<State> state;
    std::array<std::atomic<unsigned>,CountSize> calls{};
    PS2Runtime* runtime{};
    bool reject_queue{},reentry{},self_join{};std::atomic<bool> allow_join{true},self_refused{};
    explicit Fake(std::shared_ptr<State> value):state(std::move(value)){}
    ~Fake(){(void)a::backendStatusV1();++state->destroyed;}
    void block(bool enabled) noexcept {if(!enabled)return;std::unique_lock<std::mutex> lock(state->mutex);++state->entered;state->changed.notify_all();state->changed.wait(lock,[&]{return state->release;});}
};
Fake& fake(void* owner){return *static_cast<Fake*>(owner);}
a::BackendRegistrationV1 registration(const std::shared_ptr<Fake>& owner){
    a::BackendApiV1 api;api.abi_version=a::backendAbiVersionV1;api.structure_bytes=sizeof(api);api.capabilities=a::backendRequiredCapabilitiesV1;
    api.ensure_host_output=[](void* p)noexcept{++fake(p).calls[Ensure];};
    api.queue=[](void* p,std::uint32_t,const std::uint8_t*,std::uint32_t,std::uint64_t& end)noexcept{
        auto& f=fake(p);++f.calls[Queue];
        if(f.self_join){f.self_refused=!f.runtime->join();a::shutdown();}
        f.block(f.state->hold_queue);end=1234;return !f.reject_queue;};
    api.configure=[](void* p,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,bool)noexcept{auto& f=fake(p);++f.calls[Configure];if(f.reentry){if(a::queuedSamples(3)!=17)std::terminate();if(a::backendStatusV1().active_calls<1)std::terminate();}};
    api.consumed=[](void* p,std::uint32_t)noexcept{++fake(p).calls[Consumed];return std::uint64_t(19);};
    api.render=[](void* p,float* output,unsigned frames)noexcept{auto& f=fake(p);++f.calls[Render];f.block(f.state->hold_render);if(output)std::fill_n(output,std::size_t(frames)*2,0.25f);};
    api.discard=[](void* p,std::uint32_t)noexcept{++fake(p).calls[Discard];};
    api.drain=[](void* p,std::uint32_t)noexcept{++fake(p).calls[Drain];};
    api.release=[](void* p,std::uint32_t)noexcept{++fake(p).calls[Release];};
    api.queued_samples=[](void* p,std::uint32_t)noexcept{++fake(p).calls[Queued];return std::size_t(17);};
    api.reset=[](void* p)noexcept{++fake(p).calls[Reset];};
    api.shutdown=[](void* p)noexcept{++fake(p).calls[Shutdown];(void)a::backendStatusV1();a::reset();};
    api.request_stop=[](void* p)noexcept{auto& f=fake(p);++f.calls[Stop];(void)a::backendStatusV1();f.block(f.state->hold_stop);};
    api.join=[](void* p)noexcept{auto& f=fake(p);++f.calls[Join];(void)a::backendStatusV1();return f.allow_join.load();};
    return {api,owner};
}
struct Setup {PS2Runtime runtime;std::shared_ptr<State> state=std::make_shared<State>();std::shared_ptr<Fake> owner=std::make_shared<Fake>(state);
    void install(){owner->runtime=&runtime;check(a::installBackendBeforeRunV1(runtime,registration(owner))==a::BackendInstallStatusV1::installed);check(runtime.workers.size()==1);}
};
void no_legacy(){check(a::channels.empty()&&a::voices.empty()&&bank_calls==0&&bank_resets==0);}
void complete(){Setup s;s.install();std::uint8_t pcm[2]{};std::uint64_t end=99;std::array<float,4> out{};
    a::ensureHostOutput();check(a::queue(1,pcm,2,end)&&end==1234);a::configure(2,1,0,1,48000,256,true);check(a::consumed(1)==19);a::render(out.data(),2);check(out[0]==0.25f);a::discard(1);a::drain(2);a::release(2);check(a::queuedSamples(1)==17);a::reset();a::shutdown();
    for(unsigned n=0;n<Shutdown+1;++n){check(s.owner->calls[n]==1);}check(s.owner->calls[Stop]==1);check(s.runtime.join());check(s.owner->calls[Join]==1);check(a::backendStatusV1().selection==a::BackendSelectionV1::native_joined);no_legacy();
}
void legacy(){Setup s;std::uint8_t pcm[2]{};std::uint64_t end=77;check(a::queue(1,pcm,2,end)&&end==2);check(a::queuedSamples(1)==1);check(a::installBackendBeforeRunV1(s.runtime,registration(s.owner))==a::BackendInstallStatusV1::legacy_in_use);check(s.runtime.workers.empty());check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);check(a::queue(2,pcm,2,end)&&a::channels.size()==2);}
void invalid(){Setup s;auto r=registration(s.owner);for(unsigned missing=0;missing<13;++missing){r=registration(s.owner);switch(missing){case 0:r.api.ensure_host_output=nullptr;break;case 1:r.api.queue=nullptr;break;case 2:r.api.configure=nullptr;break;case 3:r.api.consumed=nullptr;break;case 4:r.api.render=nullptr;break;case 5:r.api.discard=nullptr;break;case 6:r.api.drain=nullptr;break;case 7:r.api.release=nullptr;break;case 8:r.api.queued_samples=nullptr;break;case 9:r.api.reset=nullptr;break;case 10:r.api.shutdown=nullptr;break;case 11:r.api.request_stop=nullptr;break;case 12:r.api.join=nullptr;break;}check(a::installBackendBeforeRunV1(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);}r=registration(s.owner);r.api.abi_version=2;check(a::installBackendBeforeRunV1(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);r=registration(s.owner);--r.api.structure_bytes;check(a::installBackendBeforeRunV1(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);r=registration(s.owner);r.api.capabilities=0;check(a::installBackendBeforeRunV1(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);r=registration(s.owner);r.owner.reset();check(a::installBackendBeforeRunV1(s.runtime,r)==a::BackendInstallStatusV1::invalid_owner);check(s.runtime.workers.empty());check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);s.install();check(a::installBackendBeforeRunV1(s.runtime,registration(s.owner))==a::BackendInstallStatusV1::native_in_use);check(s.runtime.workers.size()==1);no_legacy();}
void legacy_invalid(){Setup s;std::uint64_t end=123;check(!a::queue(0,nullptr,1,end)&&end==123);check(a::channels.empty()&&a::voices.empty());check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);check(a::installBackendBeforeRunV1(s.runtime,registration(s.owner))==a::BackendInstallStatusV1::legacy_in_use);}
void late(){Setup s;s.runtime.sealed=true;check(a::installBackendBeforeRunV1(s.runtime,registration(s.owner))==a::BackendInstallStatusV1::runtime_rejected);check(s.runtime.workers.empty());check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);a::discard(1);check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);}
void publication(){Setup s;s.runtime.registering=[] {check(a::queuedSamples(1)==0);};check(a::installBackendBeforeRunV1(s.runtime,registration(s.owner))==a::BackendInstallStatusV1::publication_lost);check(s.runtime.workers.size()==1);check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);check(s.runtime.join());check(s.owner->calls[Shutdown]==0&&s.owner->calls[Join]==0&&s.owner->calls[Stop]==0);}
void registration_stop(){Setup s;s.runtime.registered=[&]{s.runtime.stop();};check(a::installBackendBeforeRunV1(s.runtime,registration(s.owner))==a::BackendInstallStatusV1::runtime_rejected);check(s.runtime.workers.size()==1);check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);check(s.runtime.join());check(s.owner->calls[Shutdown]==0&&s.owner->calls[Join]==0&&s.owner->calls[Stop]==0);a::discard(1);check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);}
void busy(){Setup s;auto other=std::make_shared<Fake>(s.state);PS2Runtime second;s.runtime.registering=[&]{check(a::installBackendBeforeRunV1(second,registration(other))==a::BackendInstallStatusV1::installation_busy);};s.install();check(second.workers.empty());no_legacy();}
void allocation(){Setup s;reject_new=true;const auto result=a::installBackendBeforeRunV1(s.runtime,registration(s.owner));check(result==a::BackendInstallStatusV1::allocation_failed);check(s.runtime.workers.empty());check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);s.install();}
void reentry(){Setup s;s.install();s.owner->reentry=true;a::configure(3,4,0,1,48000,256,true);check(s.owner->calls[Configure]==1&&s.owner->calls[Queued]==1);a::shutdown();check(s.runtime.join());check(s.owner->calls[Reset]==0);no_legacy();}
void rejection(){Setup s;s.install();s.owner->reject_queue=true;std::uint8_t bytes[2]{};std::uint64_t end=0xABCD;check(!a::queue(1,bytes,2,end)&&end==0xABCD);check(s.owner->calls[Queue]==1);for(auto key:{0u,1u})for(auto length:{0u,1u,0x4002u})check(!a::queue(key,bytes,length,end));check(!a::queue(1,nullptr,2,end));check(s.owner->calls[Queue]==1&&end==0xABCD);no_legacy();}
void stopped(){Setup s;s.install();a::reset();check(s.owner->calls[Reset]==1);s.runtime.stop();a::reset();a::ensureHostOutput();a::configure(1,2,0,1,48000,256,true);std::uint8_t bytes[2]{};std::uint64_t end=7;check(!a::queue(1,bytes,2,end)&&end==7);std::array<float,4> out{1,1,1,1};a::render(out.data(),2);check(out==std::array<float,4>{});check(a::consumed(1)==0&&a::queuedSamples(1)==0);check(s.runtime.join());a::shutdown();check(s.owner->calls[Shutdown]==1&&s.owner->calls[Stop]==1&&s.owner->calls[Join]==1);check(s.owner->calls[Ensure]==0&&s.owner->calls[Configure]==0&&s.owner->calls[Queue]==0&&s.owner->calls[Render]==0&&s.owner->calls[Reset]==1);no_legacy();}
void strong_call(){Setup s;s.install();s.state->hold_queue=true;std::weak_ptr<Fake> weak=s.owner;s.owner.reset();std::thread producer([&]{std::uint8_t bytes[2]{};std::uint64_t end=1;(void)a::queue(1,bytes,2,end);});await([&]{return s.state->entered.load()==1;});s.runtime.workers.clear();check(!weak.expired());{std::lock_guard<std::mutex> lock(s.state->mutex);s.state->release=true;}s.state->changed.notify_all();producer.join();check(weak.expired()&&s.state->destroyed==1);check(a::backendStatusV1().selection==a::BackendSelectionV1::native_expired);std::uint8_t bytes[2]{};std::uint64_t end=99;check(!a::queue(1,bytes,2,end)&&end==99);no_legacy();}
void concurrent(){Setup s;s.install();s.state->hold_queue=s.state->hold_render=true;std::atomic<bool> done{};std::thread producer([&]{std::uint8_t bytes[2]{};std::uint64_t end=1;(void)a::queue(1,bytes,2,end);});std::thread callback([]{std::array<float,4> out{};a::render(out.data(),2);});await([&]{return s.state->entered.load()==2;});std::thread shutdown([&]{a::shutdown();done=true;});await([&]{return s.owner->calls[Stop].load()==1;});check(!done&&a::backendStatusV1().active_calls==2);{std::lock_guard<std::mutex> lock(s.state->mutex);s.state->release=true;}s.state->changed.notify_all();producer.join();callback.join();shutdown.join();check(done&&s.owner->calls[Shutdown]==1);check(s.runtime.join());no_legacy();}
void self_join(){Setup s;s.install();s.owner->self_join=true;std::uint8_t bytes[2]{};std::uint64_t end=1;check(a::queue(1,bytes,2,end));check(s.owner->self_refused&&s.owner->calls[Shutdown]==0);check(a::backendStatusV1().selection==a::BackendSelectionV1::native_stopping);check(s.runtime.join());check(s.owner->calls[Shutdown]==1&&s.owner->calls[Join]==1);no_legacy();}
void failed_join(){Setup s;s.install();s.owner->allow_join=false;check(!s.runtime.join());check(a::backendStatusV1().selection==a::BackendSelectionV1::native_stopping);check(s.owner->calls[Shutdown]==1&&s.owner->calls[Join]==1);s.owner->allow_join=true;check(s.runtime.join());check(s.owner->calls[Shutdown]==1&&s.owner->calls[Join]==2);}
void stop_callback_fence(){Setup s;s.install();s.state->hold_stop=true;std::weak_ptr<Fake> weak=s.owner;s.owner.reset();std::atomic<bool> join_started{},joined{},join_result{},second_stop{};
    std::thread signal([&]{s.runtime.workers[0]->requestStop();});await([&]{return s.state->entered.load()==1;});
    std::thread joining([&]{join_started=true;s.state->changed.notify_all();join_result=s.runtime.workers[0]->join();joined=true;s.state->changed.notify_all();});
    std::thread repeated([&]{s.runtime.workers[0]->requestStop();second_stop=true;});
    await([&]{return join_started.load()&&second_stop.load();});repeated.join();
    bool premature;
    {std::unique_lock<std::mutex> lock(s.state->mutex);premature=s.state->changed.wait_for(lock,std::chrono::milliseconds(25),[&]{return joined.load();});}
    auto owner=weak.lock();const bool retained=bool(owner);
    const bool no_overlap=retained&&owner->calls[Stop]==1&&owner->calls[Shutdown]==0&&owner->calls[Join]==0;
    const bool stopping=a::backendStatusV1().selection==a::BackendSelectionV1::native_stopping;
    {std::lock_guard<std::mutex> lock(s.state->mutex);s.state->release=true;}s.state->changed.notify_all();signal.join();joining.join();
    check(!premature&&retained&&no_overlap&&stopping);check(joined&&join_result&&owner->calls[Shutdown]==1&&owner->calls[Join]==1);owner.reset();s.runtime.workers.clear();check(weak.expired()&&s.state->destroyed==1);no_legacy();
}
void plain(){std::int16_t pcm=16384;std::uint64_t end=0;check(a::queue(1,reinterpret_cast<std::uint8_t*>(&pcm),2,end)&&end==2);a::configure(2,1,0,1,48000,256,true);std::array<float,2> out{};a::render(out.data(),1);check(out==std::array<float,2>{0.5f,0.5f});check(a::consumed(1)==2);a::release(2);a::discard(1);check(a::queuedSamples(1)==0);a::reset();check(a::channels.empty()&&a::voices.empty());a::shutdown();check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);}
int main(int argc,char** argv){try{if(argc!=2)throw std::runtime_error("scenario required");const std::string name=argv[1];if(name=="complete")complete();else if(name=="legacy")legacy();else if(name=="legacy_invalid")legacy_invalid();else if(name=="invalid")invalid();else if(name=="late")late();else if(name=="publication")publication();else if(name=="registration_stop")registration_stop();else if(name=="busy")busy();else if(name=="allocation")allocation();else if(name=="reentry")reentry();else if(name=="rejection")rejection();else if(name=="stopped")stopped();else if(name=="strong")strong_call();else if(name=="concurrent")concurrent();else if(name=="self")self_join();else if(name=="failed_join")failed_join();else if(name=="stop_fence")stop_callback_fence();else if(name=="plain")plain();else throw std::runtime_error("unknown scenario");std::cout<<name<<" checks="<<checks<<'\n';return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
