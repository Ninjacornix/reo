#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstring>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
#include "snapshot/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"
namespace a=ps2_cri_audio;
struct Event {std::mutex mutex;std::condition_variable changed;bool set{};
    void signal(){std::lock_guard lock(mutex);set=true;changed.notify_all();}
    void wait(){std::unique_lock lock(mutex);if(!changed.wait_for(lock,std::chrono::seconds(8),[&]{return set;}))throw std::runtime_error("event timeout");}};
void check(bool value){if(!value)throw std::runtime_error("joint dispatch check failed");}
std::atomic<unsigned> route_resets{},gain_calls{};
std::atomic<bool> hold_reset{};Event reset_entered,reset_resume;
float reoAudioMasterGain(){return 1;}
float reoAudioStreamGain(std::uint32_t){return 1;}
float reoAudioBankGain(unsigned,unsigned,std::uint64_t){++gain_calls;return 1;}
void reoAudioPoll(){}
void reoAudioResetStreams(){++route_resets;if(hold_reset){reset_entered.signal();reset_resume.wait();}}
#include "rpc_setup.inc"
#include "rpc_sound.inc"
#include "sif_transfer.inc"
namespace outer_fixture {
using rpc_fixture::g_rpc_mutex;
struct Client {struct Header{int sema_id=7;}hdr;};
struct ClientState{bool busy=true;};std::unordered_map<unsigned,ClientState> g_rpc_clients;
std::atomic<unsigned> payload_effects{},completion_effects{},signals{};std::atomic<int> returned{99};
bool signalRpcCompletionSema(unsigned){++signals;return true;}
void setReturnS32(int*,int value){returned=value;}
void entry(PS2Runtime* runtime,Event* entered=nullptr,Event* resume=nullptr){
    unsigned sid=1,rpcNum=6,clientPtr=1,endParam=8;Client storage;Client* client=&storage;int result{};int* ctx=&result;auto* rdram=rpc_fixture::ram.data();
#include "rpc_outer_begin.inc"
    // The exact source's entry fragment owns the lease through this surrounding
    // completion. Real full-RPC object compilation qualifies its actual context.
    ++payload_effects;if(entered)entered->signal();if(resume)resume->wait();++completion_effects;
}
}
enum Operation {Ensure,Queue,Configure,Consumed,Render,Discard,Drain,Release,Queued,Reset,Shutdown,Stop,Join,
    BankSubmit,PacketSubmit,BankMix,BankReset,Pending,Port,Se,Report,Count};
struct Owner {
    std::array<std::atomic<unsigned>,Count> calls{};
    std::atomic<bool> hold_producer{},hold_render{},hold_query{},hold_stop{};
    std::atomic<bool> joined{},allow_join{true},self_join{},self_refused{},reject_bank_reset{};
    PS2Runtime* runtime{};
    Event entered,resume;
    void pause(bool condition){if(condition){entered.signal();resume.wait();}}
};
Owner& owner(void* p){return *static_cast<Owner*>(p);}
a::BackendRegistrationV2 registration(const std::shared_ptr<Owner>& o){
    a::BackendApiV2 api;api.abi_version=a::backendAbiVersionV2;api.structure_bytes=sizeof(api);api.capabilities=a::backendRequiredCapabilitiesV2;
    auto& p=api.pcm;p.abi_version=a::backendAbiVersionV1;p.structure_bytes=sizeof(p);p.capabilities=a::backendRequiredCapabilitiesV1;
    p.ensure_host_output=[](void* x)noexcept{++owner(x).calls[Ensure];};
    p.queue=[](void* x,std::uint32_t,const std::uint8_t*,std::uint32_t,std::uint64_t& end)noexcept{++owner(x).calls[Queue];end=123;return true;};
    p.configure=[](void* x,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,std::uint32_t,bool)noexcept{++owner(x).calls[Configure];};
    p.consumed=[](void* x,std::uint32_t)noexcept{++owner(x).calls[Consumed];return std::uint64_t(9);};
    // V2 must never call the compatibility render function.
    p.render=[](void* x,float*,unsigned)noexcept{++owner(x).calls[Render];std::terminate();};
    p.discard=[](void* x,std::uint32_t)noexcept{++owner(x).calls[Discard];};
    p.drain=[](void* x,std::uint32_t)noexcept{++owner(x).calls[Drain];};
    p.release=[](void* x,std::uint32_t)noexcept{++owner(x).calls[Release];};
    p.queued_samples=[](void* x,std::uint32_t)noexcept{++owner(x).calls[Queued];return std::size_t(11);};
    p.reset=[](void* x)noexcept{++owner(x).calls[Reset];};
    p.shutdown=[](void* x)noexcept{++owner(x).calls[Shutdown];};
    p.request_stop=[](void* x)noexcept{auto& o=owner(x);++o.calls[Stop];o.pause(o.hold_stop);};
    p.join=[](void* x)noexcept{auto& o=owner(x);++o.calls[Join];o.joined=o.allow_join.load();return o.joined.load();};
    auto& b=api.banks;
    b.submit_bank=[](void* x,unsigned,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t)noexcept{auto& o=owner(x);++o.calls[BankSubmit];o.pause(o.hold_producer);return a::BankStatusV2::ok;};
    b.submit_packet=[](void* x,const std::uint8_t*,std::size_t,const std::uint8_t*,std::size_t)noexcept{auto& o=owner(x);++o.calls[PacketSubmit];if(o.self_join)o.self_refused=!o.runtime->join();o.pause(o.hold_producer);return a::BankStatusV2::unsupported;};
    b.mix=[](void* x,float* out,unsigned frames)noexcept{auto& o=owner(x);++o.calls[BankMix];if(out)for(unsigned n=0;n<frames*2;++n)out[n]+=0.5f;return a::BankStatusV2::ok;};
    b.reset=[](void* x)noexcept{auto& o=owner(x);++o.calls[BankReset];return o.reject_bank_reset?a::BankStatusV2::unsupported:a::BankStatusV2::ok;};
    b.pending_loads=[](void* x)noexcept{auto& o=owner(x);++o.calls[Pending];o.pause(o.hold_query);return a::BankQueryV2{a::BankStatusV2::ok,0};};
    b.port_state=[](void* x,unsigned,std::uint32_t& count)noexcept{++owner(x).calls[Port];count=7;return a::BankQueryV2{a::BankStatusV2::ok,1};};
    b.se_state=[](void* x,unsigned,unsigned,unsigned)noexcept{++owner(x).calls[Se];return a::BankQueryV2{a::BankStatusV2::ok,1};};
    b.report_audio_paths=[](void* x)noexcept{++owner(x).calls[Report];return a::BankStatusV2::ok;};
    api.render_admitted=[](void* x,a::SoundCall& call,float* out,unsigned frames)noexcept{auto& o=owner(x);++o.calls[Render];if(out)std::fill_n(out,std::size_t(frames)*2,0.25f);o.pause(o.hold_render);if(call.mix(out,frames)!=a::BankStatusV2::ok)std::terminate();};
    return {api,o};
}
struct Setup {PS2Runtime runtime;std::shared_ptr<Owner> value=std::make_shared<Owner>();
    Setup(){value->runtime=&runtime;runtime.memory().rdram=rpc_fixture::ram.data();}
    void install(){check(a::installBackendBeforeRunV2(runtime,registration(value))==a::BackendInstallStatusV1::installed);}
};
void no_legacy(){check(a::channels.empty()&&a::voices.empty()&&ps2_reo_sound::voices.empty());for(const auto& p:ps2_reo_sound::ports)check(!p.loaded);check(gain_calls==0&&route_resets==0);}
void complete(){Setup s;s.install();{
    auto call=a::acquireSoundCall(&s.runtime);check(call&&call.native());check(call.ensure_output()==a::BankStatusV2::ok);
    check(call.submit_bank(0,nullptr,0,nullptr,0,nullptr,0)==a::BankStatusV2::ok);
    check(call.submit_packet(nullptr,0,nullptr,0)==a::BankStatusV2::unsupported);
    check(call.pending_loads().value==0);std::uint32_t n=99;check(call.port_state(1,n).value==1&&n==7);
    check(call.se_state(1,2,3).value==1);check(call.reset_banks()==a::BankStatusV2::ok);check(call.report_audio_paths()==a::BankStatusV2::ok);
    }std::array<float,4> out{};a::render(out.data(),2);check(out==std::array<float,4>{.75f,.75f,.75f,.75f});
    check(s.value->calls[Render]==1&&s.value->calls[BankMix]==1);check(s.runtime.join());no_legacy();
}
void wrappers(){Setup s;s.install();check(ps2_reo_sound::submitBank(0,nullptr,0,nullptr,0,nullptr,0));check(!ps2_reo_sound::submitPacket(nullptr,0,nullptr,0));
    std::uint32_t n=99;check(ps2_reo_sound::portState(0,n)==1&&n==7);check(ps2_reo_sound::pendingLoads()==0&&ps2_reo_sound::seState(0,0,0)==1);
    ps2_reo_sound::reportAudioPaths();ps2_reo_sound::reset();std::array<float,2> out{};ps2_reo_sound::mix(out.data(),1);check(out[0]==.5f);
    check(s.runtime.join());for(auto op:{BankSubmit,PacketSubmit,BankMix,BankReset,Pending,Port,Se,Report})check(s.value->calls[op]==1);no_legacy();
}
void invalid(){Setup s;for(unsigned missing=0;missing<9;++missing){auto r=registration(s.value);switch(missing){case 0:r.api.banks.submit_bank=nullptr;break;case 1:r.api.banks.submit_packet=nullptr;break;case 2:r.api.banks.mix=nullptr;break;case 3:r.api.banks.reset=nullptr;break;case 4:r.api.banks.pending_loads=nullptr;break;case 5:r.api.banks.port_state=nullptr;break;case 6:r.api.banks.se_state=nullptr;break;case 7:r.api.banks.report_audio_paths=nullptr;break;case 8:r.api.render_admitted=nullptr;break;}check(a::installBackendBeforeRunV2(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);}
    auto r=registration(s.value);r.api.pcm.queue=nullptr;check(a::installBackendBeforeRunV2(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);
    r=registration(s.value);r.api.abi_version=1;check(a::installBackendBeforeRunV2(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);
    r=registration(s.value);--r.api.structure_bytes;check(a::installBackendBeforeRunV2(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);
    r=registration(s.value);r.api.capabilities=0;check(a::installBackendBeforeRunV2(s.runtime,r)==a::BackendInstallStatusV1::invalid_api);
    r=registration(s.value);r.owner={};check(a::installBackendBeforeRunV2(s.runtime,r)==a::BackendInstallStatusV1::invalid_owner);
    check(s.runtime.workers.empty()&&a::backendStatusV1().selection==a::BackendSelectionV1::unselected);s.install();check(s.runtime.join());
}
void first(){Setup s;ps2_reo_sound::reset();check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::legacy_in_use);}
void publication(){Setup s;s.runtime.registering=[]{(void)ps2_reo_sound::pendingLoads();};check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::publication_lost);check(s.runtime.join());for(const auto& c:s.value->calls)check(c==0);}
void late(){Setup s;s.runtime.sealed=true;check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::runtime_rejected);check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);}
void registration_stop(){Setup s;s.runtime.registered=[&]{s.runtime.stop();};check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::runtime_rejected);check(s.runtime.join());for(const auto& c:s.value->calls)check(c==0);}
void foreign(){Setup s;s.install();PS2Runtime other;auto call=a::acquireSoundCall(&other);check(!call&&call.status()==a::BankStatusV2::foreign_runtime);check(call.reset_banks()==a::BankStatusV2::foreign_runtime);check(s.value->calls[BankReset]==0);check(s.runtime.join());no_legacy();}
void stop_render(){Setup s;s.install();s.value->hold_render=true;std::array<float,4> out{};std::atomic<bool> done{};
    std::thread render([&]{a::render(out.data(),2);});s.value->entered.wait();s.runtime.stop();std::thread join([&]{check(s.runtime.join());done=true;});
    check(!done&&a::backendStatusV1().active_calls==1);s.value->resume.signal();render.join();join.join();check(done&&s.value->calls[BankMix]==1&&out[0]==.75f);no_legacy();
}
void stop_producer(){Setup s;s.install();s.value->hold_producer=true;std::atomic<bool> done{};
    std::thread producer([]{check(ps2_reo_sound::submitBank(0,nullptr,0,nullptr,0,nullptr,0));});s.value->entered.wait();s.runtime.stop();
    std::thread join([&]{check(s.runtime.join());done=true;});check(!done&&a::backendStatusV1().active_calls==1);s.value->resume.signal();producer.join();join.join();check(done);no_legacy();
}
void self(){Setup s;s.install();s.value->self_join=true;check(!ps2_reo_sound::submitPacket(nullptr,0,nullptr,0));check(s.value->self_refused&&s.value->calls[Join]==0);check(s.runtime.join());no_legacy();}
void closed(){Setup s;s.install();s.runtime.stop();std::uint32_t n=99;check(!ps2_reo_sound::submitBank(0,nullptr,0,nullptr,0,nullptr,0));check(ps2_reo_sound::portState(0,n)==0&&n==99);ps2_reo_sound::reset();
    std::array<float,2> out{1,1};ps2_reo_sound::mix(out.data(),1);check(out[0]==1);a::render(out.data(),1);check(out[0]==0);check(s.runtime.join());check(s.value->calls[BankSubmit]==0&&s.value->calls[BankReset]==0);no_legacy();}
void failed_join(){Setup s;s.install();s.value->allow_join=false;check(!s.runtime.join());check(a::backendStatusV1().selection==a::BackendSelectionV1::native_stopping);s.value->allow_join=true;check(s.runtime.join());check(s.value->calls[Shutdown]==1&&s.value->calls[Join]==2);}
void boot(){Setup s;PS2DtxCompatLayout layout;layout.rpcSid=0x90000200;
    ps2_syscalls::clearDtxCompatLayout(&s.runtime);ps2_syscalls::setDtxCompatLayout(layout,&s.runtime);check(a::resetBanksBeforeRuntimeRun(s.runtime));
    check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected);s.install();s.runtime.beginExternalWorkerRun();check(!a::resetBanksBeforeRuntimeRun(s.runtime));rpc_fixture::resetSoundDriverRpcState(&s.runtime);check(s.value->calls[BankReset]==1);check(s.runtime.join());}
void boot_first(){Setup s;hold_reset=true;std::atomic<bool> done{};std::thread setup([&]{check(a::resetBeforeRuntimeRun(s.runtime));});reset_entered.wait();
    std::thread first([&]{(void)ps2_reo_sound::pendingLoads();done=true;});check(!done);check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::installation_busy);reset_resume.signal();setup.join();first.join();check(done&&a::backendStatusV1().selection==a::BackendSelectionV1::legacy);}
void query(){Setup s;s.install();rpc_fixture::read_count=rpc_fixture::write_count=0;std::uint32_t result=999;bool signal=false;
    check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,6,16,4,32,8,result,signal));check(signal&&result==32&&rpc_fixture::word(32)==1&&rpc_fixture::word(36)==7);
    const auto reads=rpc_fixture::read_count.load(),writes=rpc_fixture::write_count.load();s.runtime.stop();result=999;signal=false;
    check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,6,16,4,32,8,result,signal));check(signal&&result==0&&rpc_fixture::read_count==reads&&rpc_fixture::write_count==writes);check(s.runtime.join());no_legacy();}
void rpc_foreign(){Setup s;s.install();PS2Runtime other;std::uint32_t result=999;bool signal=false;auto before=rpc_fixture::g_soundDriverRpcState.ownerRuntime;
    check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&other,1,0x12,0,0,32,4,result,signal));check(signal&&result==0&&rpc_fixture::g_soundDriverRpcState.ownerRuntime==before&&s.value->calls[BankReset]==0&&rpc_fixture::read_count==0&&rpc_fixture::write_count==0);check(s.runtime.join());}
void unknown(){check(!a::coversSoundRpcV2(7,0));std::uint32_t result=999;bool signal=true;check(!rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),nullptr,7,0,0,0,0,0,result,signal));check(a::backendStatusV1().selection==a::BackendSelectionV1::unselected&&result==0&&!signal);}
void v1_banks(){Setup s;auto v2=registration(s.value);check(a::installBackendBeforeRunV1(s.runtime,{v2.api.pcm,v2.owner})==a::BackendInstallStatusV1::installed);
    std::uint32_t n=99;check(ps2_reo_sound::portState(0,n)==0&&n==0);std::array<float,2> out{};ps2_reo_sound::mix(out.data(),1);check(gain_calls==224&&s.value->calls[BankMix]==0);
    s.runtime.stop();ps2_reo_sound::reset();check(s.value->calls[BankReset]==0);check(s.runtime.join());
    s.runtime.workers.clear();auto call=a::acquireSoundCall();check(call&&call.pending_loads().status==a::BankStatusV2::ok);
}
void rpc_statusfail(){Setup s;s.install();s.value->reject_bank_reset=true;std::uint32_t result=999;bool signal=false;
    check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,0x12,0,0,32,4,result,signal));
    check(signal&&result==0&&rpc_fixture::g_soundDriverRpcState.ownerRuntime==0&&s.value->calls[BankReset]==1&&rpc_fixture::write_count==0);check(s.runtime.join());}
void rpc_query_stop(){Setup s;s.install();s.value->hold_query=true;std::uint32_t result=999;bool signal=false;std::atomic<bool> joined{};
    std::thread query([&]{check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,0x0C,0,0,32,4,result,signal));});s.value->entered.wait();s.runtime.stop();
    std::thread join([&]{check(s.runtime.join());joined=true;});check(!joined&&rpc_fixture::write_count==0);s.value->resume.signal();query.join();join.join();check(joined&&signal&&result==32&&rpc_fixture::write_count==1);}
void outer_tail(){Setup s;s.install();Event entered,resume;std::atomic<bool> joined{};
    std::thread rpc([&]{outer_fixture::entry(&s.runtime,&entered,&resume);});entered.wait();s.runtime.stop();std::thread join([&]{check(s.runtime.join());joined=true;});
    check(!joined&&outer_fixture::payload_effects==1&&outer_fixture::completion_effects==0&&a::backendStatusV1().active_calls==1);resume.signal();rpc.join();join.join();check(joined&&outer_fixture::completion_effects==1);}
void outer_cancel(){Setup s;s.install();s.runtime.stop();outer_fixture::entry(&s.runtime);check(outer_fixture::payload_effects==0&&outer_fixture::completion_effects==0&&outer_fixture::signals==1&&outer_fixture::returned==-1);check(s.runtime.join());}
void accepted_after_stop(){Setup s;s.install();auto call=a::acquireSoundCall(&s.runtime);check(bool(call));s.runtime.stop();check(!a::acquireSoundCall(&s.runtime));
    check(call.submit_bank(0,nullptr,0,nullptr,0,nullptr,0)==a::BankStatusV2::ok);check(call.submit_packet(nullptr,0,nullptr,0)==a::BankStatusV2::unsupported);
    std::array<float,2> out{};check(call.mix(out.data(),1)==a::BankStatusV2::ok&&out[0]==.5f);check(call.pending_loads().status==a::BankStatusV2::ok);
    call={};check(s.runtime.join());no_legacy();}
void strong_bank(){Setup s;s.install();s.value->hold_producer=true;std::weak_ptr<Owner> weak=s.value;
    std::thread producer([]{check(ps2_reo_sound::submitBank(0,nullptr,0,nullptr,0,nullptr,0));});s.value->entered.wait();s.runtime.workers.clear();s.value.reset();
    check(!weak.expired());{auto value=weak.lock();value->resume.signal();}producer.join();check(weak.expired());
    check(a::backendStatusV1().selection==a::BackendSelectionV1::native_expired);check(!ps2_reo_sound::submitBank(0,nullptr,0,nullptr,0,nullptr,0));no_legacy();}
void reset_foreign(){Setup s;s.install();PS2Runtime other;rpc_fixture::g_soundDriverRpcState.ownerRuntime=123;
    rpc_fixture::resetSoundDriverRpcState();check(s.value->calls[BankReset]==0&&rpc_fixture::g_soundDriverRpcState.ownerRuntime==123);
    rpc_fixture::resetSoundDriverRpcState(&other);check(s.value->calls[BankReset]==0&&rpc_fixture::g_soundDriverRpcState.ownerRuntime==123);
    rpc_fixture::resetSoundDriverRpcState(&s.runtime);check(s.value->calls[BankReset]==1&&rpc_fixture::g_soundDriverRpcState.ownerRuntime==0);check(s.runtime.join());}
void init_foreign(){Setup s;s.install();PS2Runtime other;std::uint32_t result{};bool signal{};
    check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,0x12,0,0,0,0,result,signal));
    check(s.value->calls[BankReset]==1&&rpc_fixture::g_soundDriverRpcState.initialized);
    const auto cookie=rpc_fixture::g_soundDriverRpcState.ownerRuntime;const auto writes=rpc_fixture::write_count.load();auto* const iop=rpc_fixture::g_soundDriverIopRam;
    ps2_syscalls::g_dtx_remote_by_id[3]=4;rpc_fixture::R5900Context context;
    rpc_fixture::SifInitRpc(rpc_fixture::ram.data(),&context,&other);check(context.result==-1&&!rpc_fixture::g_rpc_initialized&&other.iop().initializations==0);
    check(rpc_fixture::g_soundDriverRpcState.ownerRuntime==cookie&&rpc_fixture::g_soundDriverRpcState.initialized&&rpc_fixture::g_soundDriverIopRam==iop&&ps2_syscalls::g_dtx_remote_by_id.size()==1&&s.value->calls[Reset]==0);
    rpc_fixture::SifInitRpc(rpc_fixture::ram.data(),&context,nullptr);check(context.result==-1);
    check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,0x12,0,0,0,0,result,signal));
    rpc_fixture::ram[16]=255;check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,0,0,16,1,0,0,result,signal));
    check(s.value->calls[BankReset]==1&&s.value->calls[Reset]==0&&rpc_fixture::write_count==writes&&rpc_fixture::g_soundDriverRpcState.ownerRuntime==cookie);check(s.runtime.join());}
void init_owned(){Setup s;s.install();rpc_fixture::R5900Context context;ps2_syscalls::g_dtx_remote_by_id[3]=4;
    rpc_fixture::SifInitRpc(rpc_fixture::ram.data(),&context,&s.runtime);check(context.result==0&&rpc_fixture::g_rpc_initialized&&s.runtime.iop().initializations==1&&s.value->calls[Reset]==1&&ps2_syscalls::g_dtx_remote_by_id.empty());
    rpc_fixture::SifInitRpc(rpc_fixture::ram.data(),&context,&s.runtime);check(s.value->calls[Reset]==1&&s.runtime.iop().initializations==2);
    s.runtime.stop();context.result=99;rpc_fixture::SifInitRpc(rpc_fixture::ram.data(),&context,&s.runtime);check(context.result==-1&&s.runtime.iop().initializations==2);check(s.runtime.join());}
void control_foreign(){Setup s;s.install();PS2Runtime other;PS2DtxCompatLayout value;value.rpcSid=77;
    ps2_syscalls::g_dtxCompatLayout.rpcSid=23;ps2_syscalls::g_dtx_remote_by_id[3]=4;
    ps2_syscalls::setDtxCompatLayout(value,&other);ps2_syscalls::clearDtxCompatLayout(&other);ps2_syscalls::setDtxCompatLayout(value);ps2_syscalls::clearDtxCompatLayout();
    check(ps2_syscalls::g_dtxCompatLayout.rpcSid==23&&ps2_syscalls::g_dtx_remote_by_id.size()==1&&s.value->calls[Reset]==0);
    PS2SoundDriverCompatLayout sound;sound.primarySeCheckAddr=45;rpc_fixture::g_soundDriverCompatLayout.primarySeCheckAddr=123;rpc_fixture::setSoundDriverCompatLayout(sound);rpc_fixture::clearSoundDriverCompatLayout();check(rpc_fixture::g_soundDriverCompatLayout.primarySeCheckAddr==123);
    ps2_syscalls::setDtxCompatLayout(value,&s.runtime);check(ps2_syscalls::g_dtxCompatLayout.rpcSid==77&&ps2_syscalls::g_dtx_remote_by_id.empty()&&s.value->calls[Reset]==1);check(s.runtime.join());}
void metadata_reservation(){Setup s;auto control=a::acquireSoundControlCall(nullptr);check(control&&a::backendStatusV1().selection==a::BackendSelectionV1::unselected);
    check(control.reset_pcm()==a::BankStatusV2::unsupported&&control.reset_banks()==a::BankStatusV2::unsupported);
    check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::installation_busy&&s.runtime.workers.empty());check(!a::resetBeforeRuntimeRun(s.runtime));
    auto moved=std::move(control);check(!control);moved={};s.install();check(s.runtime.join());}
void ram_foreign(){Setup s;s.install();std::array<uint8_t,128> foreign{};std::uint32_t result=99;bool signal=false;rpc_fixture::R5900Context context;
    check(rpc_fixture::handleSoundDriverRpcService(foreign.data(),&s.runtime,1,6,16,4,32,8,result,signal));check(signal&&result==0&&rpc_fixture::read_count==0&&rpc_fixture::write_count==0&&s.value->calls[Port]==0);
    rpc_fixture::SifInitRpc(foreign.data(),&context,&s.runtime);check(context.result==-1&&s.runtime.iop().initializations==0&&!rpc_fixture::g_rpc_initialized);check(s.runtime.join());}
void metadata_first(){Setup s;auto control=a::acquireSoundControlCall(nullptr);check(bool(control));check(ps2_reo_sound::pendingLoads()==0);check(a::backendStatusV1().selection==a::BackendSelectionV1::legacy);control={};check(a::installBackendBeforeRunV2(s.runtime,registration(s.value))==a::BackendInstallStatusV1::legacy_in_use);}
rpc_fixture::R5900Context transfer_context(){rpc_fixture::R5900Context context;context.regs[4]=16;context.regs[5]=rpc_fixture::g_soundDriverRpcState.statusAddr;context.regs[6]=64;context.regs[7]=0x42;return context;}
void initialize_status(Setup& s){std::uint32_t result{};bool signal{};check(rpc_fixture::handleSoundDriverRpcService(rpc_fixture::ram.data(),&s.runtime,1,0x12,0,0,0,0,result,signal));check(s.value->calls[BankReset]==1);s.runtime.memory().iop[rpc_fixture::g_soundDriverRpcState.statusAddr+1]=77;}
void transfer_foreign(){Setup s;s.install();initialize_status(s);PS2Runtime other;auto context=transfer_context();
    sif_fixture::sceSifGetOtherData(rpc_fixture::ram.data(),&context,&other);check(context.result==-1&&rpc_fixture::backfill_count==0&&rpc_fixture::ram[65]==0);
    std::array<uint8_t,128> foreign{};sif_fixture::sceSifGetOtherData(foreign.data(),&context,&s.runtime);check(context.result==-1&&rpc_fixture::backfill_count==0);
    rpc_fixture::prepareSoundDriverStatusTransfer(rpc_fixture::ram.data(),context.regs[5],0x42);check(rpc_fixture::backfill_count==0);
    context=transfer_context();sif_fixture::sceSifGetOtherData(rpc_fixture::ram.data(),&context,&s.runtime);check(context.result==0&&rpc_fixture::backfill_count==1&&rpc_fixture::ram[65]==77);check(s.runtime.join());}
void transfer_stop(){Setup s;s.install();initialize_status(s);sif_fixture::pause_copy=true;auto context=transfer_context();std::atomic<bool> joined{};
    std::thread transfer([&]{sif_fixture::sceSifGetOtherData(rpc_fixture::ram.data(),&context,&s.runtime);});sif_fixture::copy_entered.wait();s.runtime.stop();std::thread join([&]{check(s.runtime.join());joined=true;});
    check(!joined&&a::backendStatusV1().active_calls==1&&rpc_fixture::ram[65]==0);sif_fixture::copy_resume.signal();transfer.join();join.join();check(joined&&context.result==0&&rpc_fixture::ram[65]==77);}
int main(int argc,char** argv)try{if(argc!=2)return 2;const std::string name=argv[1];
    if(name=="complete")complete();else if(name=="wrappers")wrappers();else if(name=="invalid")invalid();else if(name=="first")first();else if(name=="publication")publication();else if(name=="late")late();else if(name=="registration_stop")registration_stop();else if(name=="foreign")foreign();else if(name=="stop_render")stop_render();else if(name=="stop_producer")stop_producer();else if(name=="self")self();else if(name=="closed")closed();else if(name=="failed_join")failed_join();else if(name=="boot")boot();else if(name=="boot_first")boot_first();else if(name=="query")query();else if(name=="rpc_foreign")rpc_foreign();else if(name=="unknown")unknown();else if(name=="v1_banks")v1_banks();else if(name=="rpc_statusfail")rpc_statusfail();else if(name=="rpc_query_stop")rpc_query_stop();else if(name=="outer_tail")outer_tail();else if(name=="outer_cancel")outer_cancel();else if(name=="accepted_after_stop")accepted_after_stop();else if(name=="strong_bank")strong_bank();else if(name=="reset_foreign")reset_foreign();else if(name=="init_foreign")init_foreign();else if(name=="init_owned")init_owned();else if(name=="control_foreign")control_foreign();else if(name=="metadata_reservation")metadata_reservation();else if(name=="ram_foreign")ram_foreign();else if(name=="metadata_first")metadata_first();else if(name=="transfer_foreign")transfer_foreign();else if(name=="transfer_stop")transfer_stop();else return 2;
    std::cout<<"joint "<<name<<" PASS\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
