#define main independent_handle_shape_checks
#include "handle_profile_tests.cpp"
#undef main
#include "game_handles.h"
#include "game/native/adxt_shared_player/test_sources.hpp"
#include <chrono>
#include <thread>
namespace owner=n::control_owner;
namespace inst=n::instances;
namespace files_test=reo::native::adxt_shared_player::testing;
using S=inst::Status;
template<class F>struct Control final:n::HandleOperation {
    F fn;explicit Control(F value):fn(std::move(value)){}void run(inst::Instances& p,const inst::Key& key,const n::Handle& h)noexcept override{fn(p,key,h);}
};
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(15);while(!done()){check(std::chrono::steady_clock::now()<end);std::this_thread::yield();}}
inst::Source source(std::shared_ptr<const reo::native::resources::ByteView> bytes,unsigned channels){inst::Source s;s.input=std::move(bytes);s.player.decoder.channels=channels;s.player.decoder.source_config.byte_length=static_cast<std::int32_t>(s.input->size());return s;}
auto table(){std::array<std::uint32_t,1000> words{};for(unsigned i=0;i<words.size();++i)words[i]=(999-i)*256/999;auto result=reo::native::adxt_attenuation::Table::from_words(words);check(bool(result.table));return result.table;}
void start_output(const std::shared_ptr<owner::Owner>& sources){struct Start final:owner::Operation{void run(inst::Instances& p)noexcept override{check(p.start_output()==S::completed);}}start;check(sources->run(start)==owner::Admission::accepted);}
void service(n::GameHandles& handles){const auto status=handles.service(17);check(status==S::completed || status==S::pending);}
void shutdown(n::GameHandles& handles,const std::shared_ptr<owner::Owner>& sources){check(handles.clear_after_join()==S::pending);sources->request_stop();check(sources->join()==owner::Join::completed);check(handles.clear_after_join()==S::completed && handles.clear_after_join()==S::completed && handles.counts().cleared_after_join && !handles.counts().mapped);}
void domains_and_lifetime(){
    auto sources=std::make_shared<owner::Owner>(inst::control::Config{{2},{}});n::GameHandles handles(sources);start_output(sources);Fixture guest(5,2);
    const auto file39=at(n::files,39);guest.ram[file39]=1;store(guest.ram,file39+4,guest.input);store(guest.ram,guest.handle+8,file39);
    const auto admitted=handles.adopt(guest.inspect(),table());check(admitted.status==S::completed && handles.counts().mapped==1);
    auto current=handles.find(guest.inspect());unsigned calls{};
    Control start([&](auto& p,const auto& key,const auto& h){++calls;check(h.slot==5 && h.file_slot==39);check(p.attenuation(key,0xffffff9c)==S::completed && p.start(key,source(files_test::file(2,48000,20000),2))==S::completed);});
    check(handles.with(current,start)==S::completed && calls==1);
    bool ready{};Control inspect([&](auto& p,const auto& key,const auto&){const auto s=p.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{service(handles);check(handles.with(current,inspect)==S::completed);return ready;});
    std::array<float,128> buffer{};check(sources->submix()->render_add(buffer.data(),64)==inst::control::output::Status::completed);
    Control consumed([&](auto& p,const auto& key,const auto&){const auto s=p.inspect(key).source;check(s && s->output.channel[0].consumed_bytes==128 && s->output.channel[1].consumed_bytes==128);});check(handles.with(current,consumed)==S::completed);
    auto changed=guest.inspect();changed.value.route+=0x20;auto stale=handles.find(changed);check(handles.with(stale,start)==S::invalid_key && calls==1);
    check(handles.adopt(guest.inspect(),table()).status==S::occupied);
    const auto destroyed=handles.destroy(current);check(destroyed==S::completed || destroyed==S::pending);until([&]{const auto value=handles.destroy(current);check(value==S::completed || value==S::pending || value==S::invalid_key);return !handles.counts().mapped;});
    check(handles.with(current,start)==S::invalid_key && calls==1);auto fresh=handles.adopt(guest.inspect(),table());check(fresh.status==S::completed && handles.with(current,start)==S::invalid_key);
    shutdown(handles,sources);check(handles.with(fresh.key,start)==S::closed && calls==1);
}
void reserve_both_transfers(){
    auto sources=std::make_shared<owner::Owner>(inst::control::Config{{2},{}});n::GameHandles handles(sources);Fixture stereo(5,2),mono(6,1);
    check(handles.adopt(stereo.inspect(),table()).status==S::completed);
    const auto shared=stereo.dtr[1];mono.ram[shared]=1;store(mono.ram,shared+4,mono.output[0]);store(mono.ram,shared+8,mono.destination[0]);store(mono.ram,mono.rna+0x10,shared);
    const auto prepared=mono.inspect();check(prepared.status==n::HandleStatus::ready && prepared.value.transfer_slot[0]==11);
    check(handles.adopt(prepared,table()).status==S::occupied && handles.counts().mapped==1);
    shutdown(handles,sources);
}
void blocked_destroy_and_order(){
    auto sources=std::make_shared<owner::Owner>(inst::control::Config{{3},{}});n::GameHandles handles(sources);start_output(sources);Fixture first(0,1),second(1,1),third(2,1);
    const auto a=handles.adopt(first.inspect(),table()),b=handles.adopt(second.inspect(),table()),c=handles.adopt(third.inspect(),table());check(a.status==S::completed && b.status==S::completed && c.status==S::completed);
    auto blocked=std::make_shared<files_test::Blocked>();blocked->bytes=files_test::file(1,48000,20000)->bytes;
    struct Release{std::shared_ptr<files_test::Blocked> bytes;void run(){std::lock_guard lock(bytes->mutex);bytes->released=true;bytes->cv.notify_all();}~Release(){run();}}release{blocked};
    auto peer=files_test::file(1,48000,20000);Control start_blocked([&](auto& p,const auto& key,const auto&){check(p.start(key,source(blocked,1))==S::completed);});Control start_peer([&](auto& p,const auto& key,const auto&){check(p.start(key,source(peer,1))==S::completed);});
    check(handles.with(a.key,start_blocked)==S::completed && handles.with(b.key,start_peer)==S::completed && handles.with(c.key,start_peer)==S::completed);
    check(handles.service(17)==S::order_required && !blocked->reads && !peer->reads);
    const std::array duplicate{a.key,a.key,c.key};check(handles.set_order(duplicate)==S::invalid_key);
    const std::array order{c.key,b.key,a.key};check(handles.set_order(order)==S::completed);
    bool ready{};Control inspect_peer([&](auto& p,const auto& key,const auto&){const auto s=p.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{service(handles);check(handles.with(b.key,inspect_peer)==S::completed);std::lock_guard lock(blocked->mutex);return blocked->entered && ready;});
    check(handles.destroy(a.key)==S::pending && handles.counts().destroying==1);
    check(handles.adopt(first.inspect(),table()).status==S::occupied && handles.with(a.key,start_peer)==S::invalid_key);
    std::array<float,128> buffer{};check(sources->submix()->render_add(buffer.data(),64)==inst::control::output::Status::completed);
    release.run();until([&]{service(handles);const auto result=handles.destroy(a.key);check(result==S::pending || result==S::completed);return result==S::completed;});
    check(handles.counts().mapped==2 && !handles.counts().destroying && handles.with(a.key,start_peer)==S::invalid_key);
    check(handles.adopt(first.inspect(),table()).status==S::completed);shutdown(handles,sources);
}
void movie_source_handoff(){
    namespace audio=reo::native::movie_audio_clock;using P=audio::ProviderStatus;
    struct Tick final:audio::ServiceTick {unsigned calls{};P read(std::uint32_t& out)noexcept override{++calls;out=17;return P::completed;}};
    auto sources=std::make_shared<owner::Owner>(inst::control::Config{{2},{}});n::GameHandles handles(sources);start_output(sources);Fixture guest(5,2);
    auto tick=std::make_shared<Tick>();auto adopted=handles.adopt(guest.inspect(),table());check(adopted.status==S::completed);
    check(handles.capture_audio({},tick).status==P::invalid_key && handles.capture_audio(adopted.key,tick).status==P::closed && !tick->calls);
    Control start([&](auto& p,const auto& key,const auto&){check(p.start(key,source(files_test::file(2,48000,120000),2))==S::completed);});
    check(handles.with(adopted.key,start)==S::completed && handles.capture_audio(adopted.key,{}).status==P::invalid_key);
    auto captured=handles.capture_audio(handles.find(guest.inspect()),tick);check(captured.status==P::completed && captured.source);
    Control nested([&](auto&,const auto&,const auto&){check(handles.capture_audio(adopted.key,tick).status==P::busy);});check(handles.with(adopted.key,nested)==S::completed);
    bool ready{};Control inspect([&](auto& p,const auto& key,const auto&){auto s=p.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{service(handles);check(handles.with(adopted.key,inspect)==S::completed);return ready;});
    std::uint8_t phase=99;std::uint32_t frequency=99;check(captured.source->status(phase)==P::completed && phase==3 && captured.source->sample_frequency(frequency)==P::completed && frequency==48000 && !tick->calls);
    inst::control::ClockResult expected;Control estimate([&](auto& p,const auto& key,const auto&){expected=p.estimate(key,17);});check(handles.with(adopted.key,estimate)==S::completed);
    audio::Words words{77,88};check(captured.source->estimate(words)==P::completed && expected.status==inst::control::Status::completed && words.numerator==expected.value.result.ratio.numerator && words.denominator==expected.value.result.ratio.denominator && tick->calls==1);
    check(captured.source->pause(1)==P::completed);std::uint32_t discarded=99;check(captured.source->discard(UINT32_MAX,discarded)==P::completed && discarded==0);
    auto changed=guest.inspect();changed.value.input+=0x20;check(handles.capture_audio(handles.find(changed),tick).status==P::invalid_key);
    const auto stale=adopted.key;auto replacement=source(files_test::file(2,48000,120000),2);
    Control replace([&](auto& p,const auto& key,const auto&){auto result=p.start(key,std::move(replacement));check(result==S::completed || result==S::pending);});check(handles.with(adopted.key,replace)==S::completed);
    until([&]{service(handles);bool replaced{};Control inspect_replacement([&](auto& p,const auto& key,const auto&){auto state=p.inspect(key);replaced=state.starts==2 && state.source->configured;});check(handles.with(adopted.key,inspect_replacement)==S::completed);return replaced;});
    const auto ticks=tick->calls;phase=99;check(captured.source->status(phase)!=P::completed && phase==99 && tick->calls==ticks);
    auto fresh=handles.capture_audio(adopted.key,tick);check(fresh.status==P::completed && fresh.source && fresh.source->pause(0)==P::completed);
    until([&]{const auto result=handles.destroy(adopted.key);check(result==S::completed || result==S::pending);return result==S::completed;});
    check(handles.capture_audio(stale,tick).status==P::invalid_key && fresh.source->status(phase)!=P::completed);
    auto reused=handles.adopt(guest.inspect(),table());check(reused.status==S::completed && handles.with(reused.key,start)==S::completed);
    check(handles.capture_audio(stale,tick).status==P::invalid_key && handles.capture_audio(reused.key,tick).status==P::completed);
    shutdown(handles,sources);check(handles.capture_audio(reused.key,tick).status==P::closed);
}
int main()try{domains_and_lifetime();reserve_both_transfers();blocked_destroy_and_order();movie_source_handoff();std::cout<<"native game handle mapping checks="<<checks<<"; 4 workflows, actual native workers, declared guest RAM\n";return 0;}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
