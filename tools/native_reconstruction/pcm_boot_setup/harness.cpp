#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
namespace a=ps2_cri_audio;
struct Event {std::mutex mutex;std::condition_variable cv;bool set{};void signal(){std::lock_guard lock(mutex);set=true;cv.notify_all();}void wait(){std::unique_lock lock(mutex);if(!cv.wait_for(lock,std::chrono::seconds(5),[&]{return set;}))throw std::runtime_error("event timeout");}};
std::atomic<unsigned> route_resets{},native_resets{};
std::atomic<bool> pause_reset{};
Event entered,finish;
PS2Runtime* observe_runtime{};
float reoAudioMasterGain(){return 1;}
float reoAudioStreamGain(std::uint32_t){return 1;}
void reoAudioPoll(){}
void reoAudioResetStreams(){
    ++route_resets;
    (void)a::backendStatusV1(); // Must not hold the registry lock across hook.
    if(observe_runtime){auto nested=observe_runtime->acquirePreRunSetup();if(!nested)throw std::runtime_error("runtime lock held or phase changed in setup hook");}
    if(pause_reset){entered.signal();finish.wait();}
}
namespace ps2_reo_sound {void mix(float*,unsigned){}void reset(){}void reportAudioPaths(){}}
namespace ps2_syscalls {
std::mutex g_rpc_mutex,g_dtx_rpc_mutex;
PS2DtxCompatLayout g_dtxCompatLayout;
std::deque<int> g_pcmPending,g_sjxReplies;
std::unordered_set<int> g_pcmRings;
std::unordered_map<int,int> g_dtx_remote_by_id,g_dtx_transfer_by_id,g_dtx_sjx_by_handle,g_dtx_ps2rna_by_handle,g_dtx_sjrmt_by_handle;
std::uint32_t g_dtx_next_urpc_obj{};
#include "exact_rpc_methods.inc"
}
std::atomic<unsigned> assertions{};
void check(bool value){++assertions;if(!value)throw std::runtime_error("boot setup check failed");}
a::BackendRegistrationV1 registration(){
    a::BackendApiV1 api;api.abi_version=a::backendAbiVersionV1;api.structure_bytes=sizeof(api);api.capabilities=a::backendRequiredCapabilitiesV1;
    api.ensure_host_output=[](void*)noexcept{};
    api.queue=[](void*,std::uint32_t,const std::uint8_t*,std::uint32_t,std::uint64_t&)noexcept{return false;};
    api.configure=[](void*,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,bool)noexcept{};
    api.consumed=[](void*,std::uint32_t)noexcept{return std::uint64_t(0);};
    api.render=[](void*,float*,unsigned)noexcept{};
    api.discard=api.drain=api.release=[](void*,std::uint32_t)noexcept{};
    api.queued_samples=[](void*,std::uint32_t)noexcept{return size_t(0);};
    api.reset=[](void*)noexcept{++native_resets;};api.shutdown=api.request_stop=[](void*)noexcept{};
    api.join=[](void*)noexcept{return true;};return {api,std::make_shared<int>(1)};
}
PS2DtxCompatLayout layout(){PS2DtxCompatLayout value;value.rpcSid=0x90000200;value.urpcObjBase=0x1e0000;value.urpcObjLimit=0x1eff00;return value;}
void flow(){
    PS2Runtime runtime;observe_runtime=&runtime;
    // Actual applyMatching begins with clear, then File1 override sets layout.
    ps2_syscalls::clearDtxCompatLayout(&runtime);ps2_syscalls::setDtxCompatLayout(layout(),&runtime);
    observe_runtime=nullptr;
    check(route_resets==2&&a::backendStatusV1().selection==a::BackendSelectionV1::unselected);
    check(ps2_syscalls::dtxCompatLayoutSnapshot().rpcSid==0x90000200);
    check(a::installBackendBeforeRunV1(runtime,registration())==a::BackendInstallStatusV1::installed);
    // Registered worker alone must not prohibit pre-run setup; native selection
    // causes the ordinary reset callback rather than legacy-state mutation.
    ps2_syscalls::setDtxCompatLayout(layout(),&runtime);check(native_resets==1&&route_resets==2);
    runtime.beginExternalWorkerRun();check(!runtime.acquirePreRunSetup());
    ps2_syscalls::clearDtxCompatLayout(&runtime);check(native_resets==2);
    runtime.stop();check(runtime.join());
}
void plain(bool explicit_public){PS2Runtime runtime;if(explicit_public)a::reset();else ps2_syscalls::setDtxCompatLayout(layout());check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);check(a::installBackendBeforeRunV1(runtime,registration())==a::BackendInstallStatusV1::legacy_in_use);}
void lease(){
    PS2Runtime runtime;check(runtime.externalWorkerResetAllowed());
    {auto first=runtime.acquirePreRunSetup();check(bool(first)&&!runtime.externalWorkerResetAllowed());auto second=std::move(first);check(!first&&bool(second)&&runtime.m_preRunSetupCount==1);runtime.stop();check(!runtime.acquirePreRunSetup());}
    check(runtime.m_preRunSetupCount==0);
}
void paused(const std::string& mode){
    PS2Runtime runtime;pause_reset=true;
    std::atomic<bool> boot_done{},other_done{};
    std::thread boot([&]{check(a::resetBeforeRuntimeRun(runtime));boot_done=true;});entered.wait();
    check(!boot_done&&runtime.m_preRunSetupCount==1&&!runtime.externalWorkerResetAllowed());
    if(mode=="install")check(a::installBackendBeforeRunV1(runtime,registration())==a::BackendInstallStatusV1::installation_busy&&runtime.workers.empty());
    std::thread other;Event other_started;
    if(mode=="first")other=std::thread([&]{other_started.signal();(void)a::queuedSamples(1);other_done=true;});
    else if(mode=="run")other=std::thread([&]{other_started.signal();runtime.beginExternalWorkerRun();other_done=true;});
    else if(mode=="stop"){runtime.stop();check(!runtime.acquirePreRunSetup());check(!other_done);}
    // Hold the actual reset hook; candidate setup must not be published/sealed
    // during it. No callback runs while registry/runtime locks remain held.
    if(other.joinable()){other_started.wait();std::this_thread::sleep_for(std::chrono::milliseconds(25));check(!other_done);}
    check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);
    pause_reset=false;finish.signal();boot.join();if(other.joinable())other.join();
    check(boot_done&&runtime.m_preRunSetupCount==0);
    if(mode=="first")check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);
    if(mode=="run")check(other_done&&!runtime.acquirePreRunSetup());
    if(mode=="install")check(a::installBackendBeforeRunV1(runtime,registration())==a::BackendInstallStatusV1::installed);
    if(mode=="stop")check(a::installBackendBeforeRunV1(runtime,registration())==a::BackendInstallStatusV1::runtime_rejected);
}
void install_wins(){
    PS2Runtime runtime;runtime.registering=[&]{ps2_syscalls::setDtxCompatLayout(layout(),&runtime);};
    check(a::installBackendBeforeRunV1(runtime,registration())==a::BackendInstallStatusV1::publication_lost);
    check(route_resets==1&&a::backendStatusV1().selection==a::BackendSelectionV1::legacy);
    check(runtime.workers.size()==1&&runtime.join()&&native_resets==0);
}
int main(int argc,char**argv){try{
    check(argc==2);const std::string mode=argv[1];
    if(mode=="flow")flow();else if(mode=="plain")plain(false);else if(mode=="public")plain(true);else if(mode=="lease")lease();else if(mode=="install_wins")install_wins();else paused(mode);
    std::cout<<mode<<": "<<assertions<<" boot setup checks passed\n";return 0;
}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}}
