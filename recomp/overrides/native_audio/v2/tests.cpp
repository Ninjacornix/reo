// Mechanically derived from frozen Aggregate1 by derive.py; grouped packet3 contract.
#include "aggregate.h"
#include "recomp/overrides/native_banks/v3/test_capture.h"
#include "game/native/audio_banks/v2/test_inputs.hpp"
#include <atomic>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <new>
#include <malloc.h>
#include <thread>
#include <string>
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
#include "snapshot/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"
namespace n=reo::native::audio_aggregate::v2;
namespace a=ps2_cri_audio;
namespace p=n::packet;
namespace o=n::output;
namespace t=packet_test;
thread_local bool track_callback{};
std::atomic<unsigned> callback_alloc{},callback_free{},assertions{};
void* operator new(std::size_t bytes){if(track_callback)++callback_alloc;if(void* v=std::malloc(bytes?bytes:1))return v;throw std::bad_alloc();}
void operator delete(void* p)noexcept {if(track_callback&&p)++callback_free;std::free(p);}
void operator delete(void* p,std::size_t)noexcept {::operator delete(p);}
void* operator new(std::size_t bytes,std::align_val_t alignment){if(track_callback)++callback_alloc;if(void* v=_aligned_malloc(bytes?bytes:1,std::size_t(alignment)))return v;throw std::bad_alloc();}
void operator delete(void* p,std::align_val_t)noexcept{if(track_callback&&p)++callback_free;_aligned_free(p);}
void operator delete(void* p,std::size_t,std::align_val_t alignment)noexcept{::operator delete(p,alignment);}
void check(bool v){++assertions;if(!v)throw std::runtime_error("aggregate assertion "+std::to_string(assertions.load()));}
float reoAudioMasterGain(){return 1;}float reoAudioStreamGain(std::uint32_t){return 1;}float reoAudioBankGain(unsigned,unsigned,std::uint64_t){return 1;}void reoAudioPoll(){}void reoAudioResetStreams(){}
struct Hooks final:n::HostHooks {
    std::atomic<std::int64_t> now{};std::atomic<unsigned> route_resets{},path_reports{},joined_reports{},bank_gains{},stream_gains{},polls{},masters{};
    std::atomic<bool> self_join{},self_refused{},direct_self_join{};PS2Runtime* runtime{};std::weak_ptr<n::Aggregate> owner;
    n::Report last;
    std::int64_t now_ns()noexcept override{return now.load();}
    void poll_settings()noexcept override{++polls;}
    float stream_gain(std::uint32_t)noexcept override{++stream_gains;return 1;}
    float bank_gain(unsigned,unsigned,std::uint64_t)noexcept override{++bank_gains;if(self_join.exchange(false))self_refused=!runtime->join();if(direct_self_join.exchange(false)){if(auto held=owner.lock()){auto r=held->registration();self_refused=!r.api.pcm.join(r.owner.get());}}return 1;}
    float master_gain()noexcept override{++masters;return 1;}
    void reset_stream_routes()noexcept override{++route_resets;}
    void report_bank_paths(const n::bank::Snapshot&,bool)noexcept override{++path_reports;}
    void report_joined(const n::Report& r)noexcept override{last=r;++joined_reports;}
};
struct Provider final:o::Provider {
    std::mutex audio;o::CallbackSlot* slot{};
    std::atomic<unsigned> attach_calls{},detach_calls{},stop_calls{},unload_calls{};
    std::atomic<bool> fail_attach{},fail_detach{},fail_stop{},fail_unload{},synchronous{};
    std::string_view source_sha256()const noexcept override{return o::provider_source_sha256;}
    bool attach(o::CallbackSlot& s)noexcept override{++attach_calls;std::lock_guard lock(audio);if(fail_attach)return false;slot=&s;if(synchronous){std::array<float,2> out{};s.dispatch(out.data(),1);}return true;}
    bool detach()noexcept override{++detach_calls;std::lock_guard lock(audio);if(fail_detach)return false;slot=nullptr;return true;}
    bool stop()noexcept override{++stop_calls;return !fail_stop;}
    bool unload()noexcept override{++unload_calls;return !fail_unload;}
    bool emit(float* out,unsigned frames){std::lock_guard lock(audio);if(!slot)return false;track_callback=true;const auto result=slot->dispatch(out,frames);track_callback=false;return result;}
};
struct Capture final:n::QualifiedCaptureProvider {
    p::MemoryIdentity id=t::identity();std::atomic<unsigned> packets{},banks{};std::atomic<bool> pause{},lie{},repeat{},unavailable{};t::Event entered,resume;
    p::MemoryIdentity identity()const noexcept override{return id;}
    p::PacketResult with_packet(const n::PacketBorrow& raw,n::PacketOperation& operation)noexcept override {
        ++packets;if(pause.exchange(false)){entered.signal();resume.wait();}
        if(unavailable)return {p::Status::unsupported};if(lie)return {p::Status::ok,true};
        if((!raw.ram&&raw.ram_bytes)||(!raw.packet&&raw.packet_bytes))return {p::Status::invalid_input};
        t::Capture source;source.profile=id;source.has_ram=raw.ram!=nullptr;source.ram_extent=raw.ram_bytes;source.present=raw.packet!=nullptr;
        if(raw.ram)source.ram={raw.ram,raw.ram_bytes};if(raw.packet)source.packet={raw.packet,raw.packet_bytes};
        const auto result=operation.run(source);if(repeat)(void)operation.run(source);return result;
    }
    p::Status with_bank(const n::BankBorrow& raw,n::BankOperation& operation)noexcept override {
        ++banks;if(pause.exchange(false)){entered.signal();resume.wait();}if(unavailable)return p::Status::unsupported;if(lie)return p::Status::ok;
        if((!raw.hd&&raw.hd_bytes)||(!raw.bd&&raw.bd_bytes)||(!raw.tq&&raw.tq_bytes))return p::Status::invalid_input;
        t::Capture source;source.profile=id;source.bank={std::span<const uint8_t>(raw.hd,raw.hd_bytes),std::span<const uint8_t>(raw.bd,raw.bd_bytes),std::span<const uint8_t>(raw.tq,raw.tq_bytes)};
        const auto result=operation.run(source);if(repeat)(void)operation.run(source);return result;
    }
};
struct Probe final:n::TestRenderProbe {
    std::atomic<bool> pause{};t::Event entered,resume;
    void after_pcm_before_banks()noexcept override{if(pause.exchange(false)){entered.signal();resume.wait();}}
};
struct Setup {
    PS2Runtime runtime;std::shared_ptr<Hooks> hooks=std::make_shared<Hooks>();std::shared_ptr<Capture> capture=std::make_shared<Capture>();
    std::shared_ptr<Provider> provider=std::make_shared<Provider>();std::shared_ptr<o::CallbackSlot> slot=std::make_shared<o::CallbackSlot>();
    std::shared_ptr<Probe> probe=std::make_shared<Probe>();std::shared_ptr<n::Aggregate> owner;
    Setup(){hooks->runtime=&runtime;n::Inputs inputs;inputs.host=hooks;inputs.capture=capture;inputs.provider=provider;inputs.slot=slot;inputs.banks.path_counters=true;inputs.packets.max_calls=4;inputs.packets.max_packet_bytes=8192;inputs.packets.control_byte_budget=65536;
        n::TestDomain domain;domain.render_probe=probe;auto made=n::create_for_tests(inputs,domain);check(made.status==n::BuildStatus::ready_composition);owner=std::move(made.owner);hooks->owner=owner;check(provider->attach_calls==0);}
    void install(){check(a::installBackendBeforeRunV2(runtime,owner->registration())==a::BackendInstallStatusV1::installed);}
    void load(){auto data=bank();check(ps2_reo_sound::submitBank(0,data.hd.data(),data.hd.size(),data.bd.data(),data.bd.size(),data.tq.data(),data.tq.size()));}
    void finish(){check(runtime.join());check(hooks->joined_reports==1&&owner->report().owner_joined);}
};
void no_legacy(){check(ps2_cri_audio::channels.empty()&&ps2_cri_audio::voices.empty()&&ps2_reo_sound::voices.empty());for(const auto& x:ps2_reo_sound::ports)check(!x.loaded);}
void prepare_pcm(){const std::array<std::int16_t,8> pcm{1000,2000,3000,4000,5000,6000,7000,8000};std::uint64_t end=99;check(a::queue(1,reinterpret_cast<const std::uint8_t*>(pcm.data()),sizeof(pcm),end)&&end==sizeof(pcm));a::configure(2,1,0,1,48000,256,true);}
void complete(){Setup s;s.install();s.load();const std::array<uint8_t,5> note{0,0,0,0,0};check(ps2_reo_sound::submitPacket(nullptr,0,note.data(),note.size()));
    a::ensureHostOutput();prepare_pcm();std::array<float,8> out{};check(s.provider->emit(out.data(),4));check(callback_alloc==0&&callback_free==0);check(s.owner->inspect_channel(1).info.consumed_bytes==8&&s.owner->inspect_banks().frame_clock==4);
    check(a::consumed(1)==8&&a::queuedSamples(1)==4);a::drain(2);a::discard(1);a::release(2);
    std::uint32_t count=99;check(ps2_reo_sound::portState(0,count)==1&&count==1);check(ps2_reo_sound::pendingLoads()==0);(void)ps2_reo_sound::seState(0,0,0);ps2_reo_sound::reportAudioPaths();check(s.hooks->path_reports==1);
    a::reset();check(ps2_reo_sound::portState(0,count)==1);ps2_reo_sound::reset();check(ps2_reo_sound::portState(0,count)==0);
    a::shutdown();s.finish();const auto r=s.owner->report();for(std::size_t i=0;i<n::operation_count;++i)check(r.completed[i]>=1);
    check(r.captured_after_fence&&r.host_output_started&&r.stream_fenced&&r.pcm_statistics.output_frames==4&&r.hard_failures==0&&r.device_renderer_calls==1&&r.device_renders_completed==1);no_legacy();}
void between_stop(){Setup s;s.install();s.load();prepare_pcm();s.probe->pause=true;std::array<float,8> out{};std::thread callback([&]{check(s.provider->emit(out.data(),4));});s.probe->entered.wait();
    check(s.owner->inspect_channel(1).info.consumed_bytes==8&&s.owner->inspect_banks().frame_clock==0);s.runtime.stop();std::atomic<bool> joined{};
    std::thread join([&]{check(s.runtime.join());joined=true;});check(!joined&&s.provider->detach_calls==0);s.probe->resume.signal();callback.join();join.join();
    const auto r=s.owner->report();check(joined&&r.banks.frame_clock==4&&r.completed[unsigned(n::Operation::mix_banks)]==1&&r.hard_failures==0);no_legacy();}
void pretable(){Setup s;s.install();auto call=a::acquireSoundCall(&s.runtime);check(bool(call));s.runtime.stop();const std::array<uint8_t,3> packet{0x29,2,0};check(call.submit_packet(nullptr,0,packet.data(),packet.size())==a::BankStatusV2::ok);check(s.owner->inspect_banks().ports[0].volume==512);call={};s.finish();check(s.owner->report().banks.ports[0].volume==512);no_legacy();}
void producer_stop(){Setup s;s.install();s.capture->pause=true;const std::array<uint8_t,3> packet{0x29,2,0};std::thread producer([&]{check(ps2_reo_sound::submitPacket(nullptr,0,packet.data(),packet.size()));});s.capture->entered.wait();s.runtime.stop();std::atomic<bool> joined{};
    std::thread join([&]{check(s.runtime.join());joined=true;});check(!joined&&s.provider->detach_calls==0);s.capture->resume.signal();producer.join();join.join();check(joined&&s.owner->report().banks.ports[0].volume==512);no_legacy();}
void failed_fence(){Setup s;s.install();prepare_pcm();s.load();s.provider->fail_detach=true;check(!s.runtime.join());check(!s.owner->report().owner_joined&&s.slot->occupied()&&s.owner->inspect_banks().ports[0].loaded&&s.owner->inspect_channel(1).source_visible&&s.hooks->joined_reports==0&&s.hooks->route_resets==0);
    s.provider->fail_detach=false;s.finish();const auto r=s.owner->report();check(r.fence_failures>=1&&r.banks.ports[0].loaded&&r.asset_budget.assets==1&&r.pcm_statistics.output_frames==0);check(!s.slot->occupied()&&s.hooks->route_resets==1);no_legacy();}
void headless(){Setup s;s.provider->fail_attach=true;s.install();prepare_pcm();s.hooks->now=100000;check(a::consumed(1)>0);s.finish();auto r=s.owner->report();check(!r.host_output_started&&!r.stream_fenced&&r.device_renderer_calls==0&&r.pcm_statistics.output_frames>0);no_legacy();}
void contract(){Setup s;s.install();s.capture->lie=true;const std::array<uint8_t,1> end{255};check(!ps2_reo_sound::submitPacket(nullptr,0,end.data(),end.size()));check(s.owner->report().hard_failures>0);s.capture->lie=false;s.capture->repeat=true;check(!ps2_reo_sound::submitPacket(nullptr,0,end.data(),end.size()));s.finish();no_legacy();}
void self_join(){Setup s;s.install();prepare_pcm();s.hooks->self_join=true;std::array<float,2> out{};check(s.provider->emit(out.data(),1));check(s.hooks->self_refused&&!s.owner->report().owner_joined);s.finish();no_legacy();}
void weak_lifetime(){Setup s;s.install();prepare_pcm();std::weak_ptr<n::Aggregate> weak=s.owner;s.owner.reset();std::array<float,2> out{};check(s.provider->emit(out.data(),1)&&!weak.expired());check(s.runtime.join());s.runtime.workers.clear();check(weak.expired()&&!s.slot->occupied());}
void boundaries(){Setup s;s.install();std::array<float,2> out{5,6};a::render(out.data(),16385);check(out[0]==5&&out[1]==6);s.finish();check(s.owner->report().hard_failures==1);const auto d=n::production_domain();check(d.max_channels==2040&&d.max_voices==2041&&std::uint64_t(d.max_channels)*96000*2==n::production_pcm_bytes);no_legacy();}
void synchronous(){Setup s;s.provider->synchronous=true;s.install();a::ensureHostOutput();check(s.owner->report().device_renderer_calls==1);s.finish();check(s.owner->report().pcm_statistics.output_frames==1);no_legacy();}
void self_owner(){Setup s;s.install();prepare_pcm();s.hooks->direct_self_join=true;std::array<float,2> out{};check(s.provider->emit(out.data(),1));check(s.hooks->self_refused&&s.owner->report().self_join_refusals==1&&!s.owner->report().owner_joined);s.finish();no_legacy();}
int main(int argc,char** argv)try{if(argc!=2)return 2;std::string name=argv[1];if(name=="complete")complete();else if(name=="between_stop")between_stop();else if(name=="pretable")pretable();else if(name=="producer_stop")producer_stop();else if(name=="failed_fence")failed_fence();else if(name=="headless")headless();else if(name=="contract")contract();else if(name=="self")self_join();else if(name=="weak")weak_lifetime();else if(name=="boundaries")boundaries();else if(name=="synchronous")synchronous();else if(name=="self_owner")self_owner();else return 2;std::cout<<"aggregate "<<name<<" assertions="<<assertions.load()<<"\n";return 0;}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
