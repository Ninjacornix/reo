// Exact factory/wrapper/aggregate bodies. Runtime, capture acquisition and native
// device methods below are explicit protocol fixtures, not real RAM authority.
#include <array>
#include <atomic>
#include <chrono>
#include <future>
#include <iostream>
#include <thread>
#include <unordered_map>
#include "ps2_runtime.h"
#include "recomp/overrides/native_banks/v3/test_capture.h"
#include "game/native/adxt_shared_player/test_sources.hpp"
#include "game/native/audio_banks/v2/test_inputs.hpp"
#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"
#include "snapshot/Kernel/Syscalls/Helpers/ReoSoundBanks.cpp"
#include "source/composite_backend.cpp"

namespace sr=reo::native::sound_ram;
namespace sdk=ps2_cri_audio;
namespace out=reo::audio_output;
namespace own=reo::native::adxt_control_owner;
namespace inst=reo::native::adxt_instances;
namespace file=reo::native::adxt_shared_player::testing;
namespace pkt=reo::native::bank_packets::v3;
thread_local unsigned guest_depth{},io_depth{};
unsigned prepared{},attached{},detached{},stopped{},unloaded{},polls{},masters{},bank_gains{},route_resets{},route_calls{};
std::uint32_t last_route{};float route_factor=0.37f;
bool layout_ok=true,prepare_ok=true,provider_ok=true,detach_ok=true;
std::weak_ptr<sr::RuntimeMemory> prepared_memory;
out::CallbackSlot* callback_slot{};
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept{return guest_depth;}
std::uint32_t ps2IoRegLockDepth()noexcept{return io_depth;}
namespace ps2_syscalls {PS2DtxCompatLayout dtxCompatLayoutSnapshot(){PS2DtxCompatLayout v{};if(layout_ok){v.rpcSid=0x90000200;v.urpcObjBase=0x1e0000;v.urpcObjLimit=0x1eff00;v.urpcObjStride=0x20;}return v;}}
float reoAudioMasterGain(){++masters;return 1;}
float reoAudioStreamGain(std::uint32_t key){++route_calls;last_route=key;return route_factor;}
float reoAudioBankGain(unsigned,unsigned,std::uint64_t){++bank_gains;return 1;}
void reoAudioPoll(){++polls;}void reoAudioResetStreams(){++route_resets;}
namespace reo::audio_output {
CallbackSlot& native_stream_callback_slot(){static CallbackSlot slot;return slot;}
std::shared_ptr<NativeStreamProvider> NativeStreamProvider::create(){if(!provider_ok)return {};return std::shared_ptr<NativeStreamProvider>(new NativeStreamProvider);}
std::string_view NativeStreamProvider::source_sha256()const noexcept{return provider_source_sha256;}
bool NativeStreamProvider::attach(CallbackSlot& slot)noexcept{++attached;callback_slot=&slot;return true;}
bool NativeStreamProvider::detach()noexcept{++detached;if(!detach_ok)return false;callback_slot=nullptr;return true;}
bool NativeStreamProvider::stop()noexcept{++stopped;return true;}
bool NativeStreamProvider::unload()noexcept{++unloaded;return true;}
}
namespace reo::native::sound_ram {
MemoryPrepareResult RuntimeMemory::prepare(PS2Runtime&,const reo_cd_async::ConfigurationReceipt&,packet::MemoryIdentity id)noexcept{
    ++prepared;if(!prepare_ok)return{MemoryPrepareStatus::invalid_profile,{}};
    auto value=std::make_shared<RuntimeMemory>();value->profile=id;prepared_memory=value;return{MemoryPrepareStatus::ready,std::move(value)};
}
}
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("media factory assertion "+std::to_string(checks));}
template<class F>struct Operation final:own::Operation {F fn;explicit Operation(F f):fn(std::move(f)){}void run(inst::Instances& p)noexcept override{fn(p);}};
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(15);while(!done()){check(std::chrono::steady_clock::now()<end);std::this_thread::yield();}}
struct Fixture {
    PS2Runtime runtime;reo_cd_async::ConfigurationReceipt cd;
    sr::MediaInstallResult result;
    void install(){result=sr::install_native_sources(runtime,cd,packet_test::identity());check(result.backend.status==sr::InstallStatus::installed && bool(result.sources) && bool(result.pcm_order));}
    void finish(){runtime.stop();check(runtime.join());check(result.sources->report().joined);}
};
inst::Source source(std::shared_ptr<const reo::native::resources::ByteView> view,unsigned channels){inst::Source s;s.input=std::move(view);s.player.decoder.channels=channels;s.player.decoder.source_config.byte_length=static_cast<std::int32_t>(s.input->size());return s;}
void live(){
    Fixture f;f.install();check(f.runtime.workers.size()==2 && attached==0);
    auto memory=prepared_memory.lock();check(bool(memory));
    sdk::reset();check(route_resets==1);
    const auto b=bank();check(ps2_reo_sound::submitBank(0,b.hd.data(),b.hd.size(),b.bd.data(),b.bd.size(),b.tq.data(),b.tq.size()));
    inst::Key key;
    Operation start([&](auto& p){check(p.start_output()==inst::Status::completed);auto opened=p.create({1,{0,0,0,0,0x1e0000}});check(opened.status==inst::Status::completed);key=opened.key;check(p.start(key,source(file::file(1,48000,20000),1))==inst::Status::completed);});
    check(f.result.sources->run(start)==own::Admission::accepted);
    bool ready{};Operation service([&](auto& p){check(p.service(17)==inst::Status::completed);const auto s=p.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{check(f.result.sources->run(service)==own::Admission::accepted);return ready;});
    sdk::ensureHostOutput();check(attached==1 && callback_slot);
    std::array<float,128> buffer{};check(callback_slot->dispatch(buffer.data(),64));
    Operation inspect([&](auto& p){const auto s=p.inspect(key).source;check(s && s->output.channel[0].consumed_bytes==128 && s->output.voice.gain==route_factor);});
    check(f.result.sources->run(inspect)==own::Admission::accepted);
    check(polls==1 && masters==1 && route_calls==1 && last_route==0x1e0000);
    check(!memory->stats.retired && memory->retires==0);
    f.finish();check(memory->stats.retired && memory->retires==1 && detached==1 && stopped==1 && unloaded==1);
    const auto final=f.result.sources->report();check(final.final && final.final->session.output.statistics.output_frames==64 && !final.final->session.output.provider_joined);
    auto noop=Operation([](auto&){});check(f.result.sources->run(noop)==own::Admission::closed);
    check(f.runtime.join() && memory->retires==1);
}
void blocked_source(){
    Fixture f;f.install();auto bytes=std::make_shared<file::Blocked>();bytes->bytes=file::file(1,48000,20000)->bytes;
    Operation start([&](auto& p){check(p.start_output()==inst::Status::completed);auto key=p.create({1,{0,0,0,0}});check(key.status==inst::Status::completed);check(p.start(key.key,source(bytes,1))==inst::Status::completed);check(p.service(17)==inst::Status::completed);});
    check(f.result.sources->run(start)==own::Admission::accepted);
    {std::unique_lock lock(bytes->mutex);check(bytes->cv.wait_for(lock,std::chrono::seconds(5),[&]{return bytes->entered;}));}
    auto memory=prepared_memory.lock();check(bool(memory));f.runtime.stop();
    auto joining=std::async(std::launch::async,[&]{return f.runtime.join();});
    check(joining.wait_for(std::chrono::milliseconds(30))==std::future_status::timeout);
    check(!memory->stats.retired && memory->retires==0 && !f.result.sources->report().joined);
    {std::lock_guard lock(bytes->mutex);bytes->released=true;bytes->cv.notify_all();}
    check(joining.get());check(memory->stats.retired && f.result.sources->report().joined);
}
void refusals(const std::string& mode){
    Fixture f;
    if(mode=="disabled")_putenv_s("REO_NATIVE_AUDIO","0");
    if(mode=="phase")f.runtime.sealed=true;
    if(mode=="layout")layout_ok=false;
    if(mode=="memory")prepare_ok=false;
    if(mode=="provider")provider_ok=false;
    if(mode=="registration")f.runtime.accept=false;
    if(mode=="publication")f.runtime.registered=[&]{if(f.runtime.workers.size()==1)f.runtime.accept=false;};
    auto result=sr::install_native_sources(f.runtime,f.cd,packet_test::identity());
    check(!result.sources && result.backend.status!=sr::InstallStatus::installed && attached==0);
    auto memory=prepared_memory.lock();if(memory)check(memory->stats.retired);
    check(f.runtime.join());
    if(mode=="publication")check(f.runtime.workers.size()==1);
}
void scoped_join(){
    Fixture f;f.install();auto memory=prepared_memory.lock();
    Operation scoped([&](auto&){check(!f.runtime.join());check(!f.result.sources->report().stopping && !memory->stats.retired && !memory->retires && !detached);});
    check(f.result.sources->run(scoped)==own::Admission::accepted);
    guest_depth=1;check(!f.runtime.join());guest_depth=0;io_depth=1;check(!f.runtime.join());io_depth=0;
    check(!f.result.sources->report().stopping && !memory->stats.retired);f.finish();
}
void device_fence(){
    Fixture f;f.install();auto memory=prepared_memory.lock();sdk::ensureHostOutput();check(attached==1);
    detach_ok=false;f.runtime.stop();check(!f.runtime.join());
    check(f.result.sources->report().joined && !memory->stats.retired && !memory->retires && !stopped && !unloaded);
    detach_ok=true;check(f.runtime.join() && memory->stats.retired && stopped==1 && unloaded==1);
}
void legacy(){
    Fixture f;const auto result=sr::install(f.runtime,f.cd,packet_test::identity());
    check(result.status==sr::InstallStatus::installed && f.runtime.workers.size()==1);
    std::array<std::int16_t,128> samples;samples.fill(1234);std::uint64_t end{};
    check(sdk::queue(0x1e0000,reinterpret_cast<const std::uint8_t*>(samples.data()),sizeof(samples),end));
    sdk::configure(0x1e0020,0x1e0000,0,1,48000,256,true);sdk::ensureHostOutput();check(attached==1 && callback_slot);
    std::array<float,128> buffer{};check(callback_slot->dispatch(buffer.data(),64));check(sdk::consumed(0x1e0000)==128);
    f.runtime.stop();check(f.runtime.join());auto memory=prepared_memory.lock();check(memory && memory->stats.retired);
}
void pcm_order(){
    Fixture f;f.install();std::array<std::uint32_t,32> actual{};
    auto copy=[&](const auto& expected){
        actual.fill(0xdeadbeef);const auto result=f.result.pcm_order->copy(actual);
        check(result.status==reo::native::pcm_bridge::Status::ok && result.value==expected.size());
        unsigned i{};for(const auto& row:expected)check(actual[i++]==row.first);
        check(actual[i]==0xdeadbeef);
    };
    std::unordered_map<std::uint32_t,unsigned> expected;copy(expected);
    // Enough real facade configurations to cross the host STL's default bucket
    // growth, plus replacement, release and cold reset. All shadow voices are
    // muted and carry no PCM. The capability must observe actual container
    // history, not caller insertion order or a sorted list.
    for(unsigned i=0;i<16;++i){const auto id=0x1e0100+i*0x20;sdk::configure(id,0x1e0000,0,1,48000,256,false);expected.emplace(id,i);copy(expected);}
    std::array<std::uint32_t,1> short_buffer{0x12345678};const auto short_copy=f.result.pcm_order->copy(short_buffer);
    check(short_copy.status==reo::native::pcm_bridge::Status::invalid_input && short_copy.value==16 && short_buffer[0]==0x12345678);
    sdk::configure(0x1e0160,0x1e0000,0,1,24000,128,false);copy(expected);
    sdk::release(0x1e0160);expected.erase(0x1e0160);copy(expected);
    sdk::configure(0x1e0160,0x1e0000,0,1,48000,256,false);expected.emplace(0x1e0160,3);copy(expected);
    sdk::reset();expected.clear();copy(expected);check(route_resets==1);
    sdk::configure(0x1e0040,0x1e0000,0,1,48000,256,false);expected.emplace(0x1e0040,0);copy(expected);
    // The capability retains only fenced aggregate state after ordinary join.
    auto retained=f.result.pcm_order;f.finish();expected.clear();copy(expected);
    f.result={};check(retained->copy(actual).status==reo::native::pcm_bridge::Status::ok && retained->copy(actual).value==0);
}
void source_reset(){
    Fixture f;f.install();sdk::reset();check(route_resets==1);
    auto bytes=std::make_shared<file::Blocked>();bytes->bytes=file::file(1,48000,20000)->bytes;inst::Key key;
    Operation create([&](auto& p){check(p.start_output()==inst::Status::completed);const auto made=p.create({1,{0,0,0,0}});check(made.status==inst::Status::completed);key=made.key;});
    check(f.result.sources->run(create)==own::Admission::accepted);
    sdk::configure(0x1e0040,0x1e0000,0,1,48000,256,false);std::array<std::uint32_t,8> order{};
    auto unchanged=[&]{const auto r=f.result.pcm_order->copy(order);check(r.status==reo::native::pcm_bridge::Status::ok && r.value==1 && order[0]==0x1e0040);};
    sdk::reset();check(route_resets==1);unchanged(); // Even idle constructed handles exclude reset.
    Operation start([&](auto& p){check(p.start(key,source(bytes,1))==inst::Status::completed && p.service(17)==inst::Status::completed);});
    check(f.result.sources->run(start)==own::Admission::accepted);
    {std::unique_lock lock(bytes->mutex);check(bytes->cv.wait_for(lock,std::chrono::seconds(5),[&]{return bytes->entered;}));}
    Operation destroy([&](auto& p){check(p.destroy(key)==inst::Status::pending && !p.snapshot().session.output.occupied && p.snapshot().instances==1);});
    check(f.result.sources->run(destroy)==own::Admission::accepted);
    sdk::reset();check(route_resets==1 && !f.result.sources->report().stopping);unchanged(); // Source has NOT joined.
    {std::lock_guard lock(bytes->mutex);bytes->released=true;bytes->cv.notify_all();}
    bool retired{};Operation service([&](auto& p){const auto r=p.service(17);check(r==inst::Status::completed || r==inst::Status::pending);retired=p.inspect(key).status==inst::Status::invalid_key;});
    until([&]{check(f.result.sources->run(service)==own::Admission::accepted);return retired;});
    sdk::reset();check(route_resets==2 && f.result.pcm_order->copy(order).value==0 && !f.result.sources->report().stopping);
    // The same source owner and actual output remain usable in the new epoch.
    check(f.result.sources->run(create)==own::Admission::accepted);
    Operation restart([&](auto& p){check(p.start(key,source(file::file(1,48000,20000),1))==inst::Status::completed);});
    check(f.result.sources->run(restart)==own::Admission::accepted);
    bool ready{};Operation playable([&](auto& p){check(p.service(17)==inst::Status::completed);const auto s=p.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{check(f.result.sources->run(playable)==own::Admission::accepted);return ready;});
    check(callback_slot);std::array<float,128> output{};check(callback_slot->dispatch(output.data(),64));
    f.finish();check(attached==1 && detached==1 && stopped==1 && unloaded==1);
}
void prepared_sources(const std::string& mode){
    Fixture f;auto prepared=std::make_shared<own::Owner>(inst::control::Config{{1},{}});
    if(mode=="prepared_phase")f.runtime.sealed=true;
    if(mode=="prepared_occupied"){
        Operation create([&](auto& p){check(p.create({1,{0,0,0,0}}).status==inst::Status::completed);});
        check(prepared->run(create)==own::Admission::accepted);
    }
    if(mode=="prepared_scoped"){
        Operation scope([&](auto&){f.result=sr::install_prepared_native_sources(f.runtime,f.cd,packet_test::identity(),prepared);});
        check(prepared->run(scope)==own::Admission::accepted);
    }else f.result=sr::install_prepared_native_sources(f.runtime,f.cd,packet_test::identity(),mode=="prepared_null"?std::shared_ptr<own::Owner>{}:prepared);
    if(mode!="prepared_live"){
        check(f.result.backend.status!=sr::InstallStatus::installed && !f.result.sources && !f.result.pcm_order);
        check(f.runtime.workers.empty() && !prepared->report().stopping && !attached && prepared_memory.expired());
        check(prepared->join()==own::Join::completed && f.runtime.join());return;
    }
    check(f.result.backend.status==sr::InstallStatus::installed && f.result.sources==prepared && f.result.pcm_order && f.runtime.workers.size()==2 && !attached);
    sdk::reset();check(route_resets==1);
    Operation create([&](auto& p){check(p.start_output()==inst::Status::completed);auto made=p.create({1,{0,0,0,0}});check(made.status==inst::Status::completed);check(p.start(made.key,source(file::file(1,48000,20000),1))==inst::Status::completed);});
    check(prepared->run(create)==own::Admission::accepted);f.finish();check(prepared->report().joined);
}
int main(int argc,char** argv)try{
    check(argc==2);_putenv_s("REO_NATIVE_AUDIO","1");std::string mode=argv[1];
    if(mode=="live")live();else if(mode=="blocked")blocked_source();else if(mode=="scoped")scoped_join();else if(mode=="device_fence")device_fence();else if(mode=="legacy")legacy();else if(mode=="pcm_order")pcm_order();else if(mode=="source_reset")source_reset();else if(mode.starts_with("prepared_"))prepared_sources(mode);else refusals(mode);
    std::cout<<"media factory checks="<<checks<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
