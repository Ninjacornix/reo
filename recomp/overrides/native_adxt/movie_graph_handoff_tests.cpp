#include "game_handles_fixture.hpp"
#include "game/native/movie_lifecycle/prepared_graph.hpp"

namespace graph_handoff {
namespace life=reo::native::movie_lifecycle;
namespace timing=reo::native::movie_timing_context;
namespace audio=reo::native::movie_audio_clock;
using P=audio::ProviderStatus;
struct Tick final:audio::ServiceTick {unsigned calls{};P read(std::uint32_t& out)noexcept override{++calls;out=17;return P::completed;}};
struct Helper final:audio::HelperClock {
    P counter(std::uint64_t& out)noexcept override{out=19200;return P::completed;}
    P frequency(std::uint64_t& out)noexcept override{out=576000;return P::completed;}
};
struct Ports final:timing::Ports {timing::Reply call(timing::pause::Call,const timing::View&)noexcept override{return{};}};
// Declared video lifecycle only: no parser, GPU decode, frame presentation or
// A/V timing measurement is claimed by this audio ownership composition test.
struct Video final:life::VideoBackend {
    std::uint64_t bytes{};bool ended{},closing{};
    life::Status feed(std::uint64_t at,std::span<const std::byte> payload)noexcept override{
        if(closing)return life::Status::closed;
        if(at!=bytes)return life::Status::provider_failure;
        bytes+=payload.size();return life::Status::completed;
    }
    life::Status end()noexcept override{ended=true;return life::Status::completed;}
    life::Status service()noexcept override{return closing?life::Status::closed:life::Status::completed;}
    void request_stop()noexcept override{closing=true;}
    life::Status poll_retired()noexcept override{return closing?life::Status::completed:life::Status::invalid_input;}
    void drain()noexcept override{closing=true;}
};
struct Videos final:life::VideoFactory {
    bool fail{};std::vector<std::shared_ptr<Video>> values;std::vector<std::shared_ptr<timing::Context>> clocks;
    std::shared_ptr<life::VideoBackend> create(std::shared_ptr<timing::Context> clock,std::uint64_t)override{
        if(fail)throw std::runtime_error("Declared video construction refusal");
        auto video=std::make_shared<Video>();values.push_back(video);clocks.push_back(std::move(clock));return video;
    }
};
void workflow(){
    auto sources=std::make_shared<owner::Owner>(inst::control::Config{{2},{}});n::GameHandles handles(sources);start_output(sources);Fixture guest(5,2);
    auto adopted=handles.adopt(guest.inspect(),table());check(adopted.status==S::completed);
    Control start([&](auto& p,const auto& key,const auto&){check(p.start(key,source(files_test::file(2,48000,120000),2))==S::completed);});check(handles.with(adopted.key,start)==S::completed);
    bool ready{};Control inspect([&](auto& p,const auto& key,const auto&){auto s=p.inspect(key).source;ready=s && s->output.voice.playing && s->output.channel[0].samples>=512;});
    until([&]{service(handles);check(handles.with(adopted.key,inspect)==S::completed);return ready;});
    auto tick=std::make_shared<Tick>();auto captured=handles.capture_audio(handles.find(guest.inspect()),tick);check(captured.status==P::completed && captured.source);
    auto videos=std::make_shared<Videos>();life::GraphConfig config;config.video=videos;config.clock.audio=captured.source;config.clock.helper=std::make_shared<Helper>();config.clock.ports=std::make_shared<Ports>();
    config.clock.audio_commands=timing::AudioCommands{};config.clock.buffering=timing::Buffering{};config.clock.buffering->audio=1;config.clock.audio_filter_mode=0;
    check(!config.audio); // Borrowed source: graph must neither open nor retire it.
    auto factory=std::make_shared<life::PreparedFactory>(config);auto movie=life::Session::create(factory);auto bytes=files_test::file(1,48000,64);auto opened=movie->open({bytes,0,bytes->size()});check(opened.status==life::Status::completed);
    std::uint64_t visits{};Control before([&](auto& p,const auto&,const auto&){visits=p.snapshot().session.group_visits;check(p.snapshot().session.records==1);});check(handles.with(adopted.key,before)==S::completed);
    until([&]{auto work=movie->service(opened.key);check(work==life::Status::completed || work==life::Status::pending);return videos->values.back()->ended;});
    check(videos->values.back()->bytes==bytes->size() && !tick->calls);
    Control no_second_service([&](auto& p,const auto&,const auto&){check(p.snapshot().session.records==1 && p.snapshot().session.group_visits==visits);});check(handles.with(adopted.key,no_second_service)==S::completed);
    auto clock=videos->clocks.back();timing::Updates active;active.actual=4;active.requested=4;check(clock->observe(active)==timing::Status::completed);
    check(clock->execute(timing::Operation::refresh).status==timing::Status::completed && tick->calls==1 && clock->snapshot().audio.diagnostic==3 && clock->snapshot().audio_health.status==audio::Status::completed);
    timing::Input command;command.value=1;check(clock->execute(timing::Operation::audio_requested,command).status==timing::Status::completed);
    Control paused([&](auto& p,const auto& key,const auto&){const auto s=p.inspect(key).source;check(s->clock.paused==1 && !s->output.voice.playing);});check(handles.with(adopted.key,paused)==S::completed);
    command.value=2;check(clock->execute(timing::Operation::audio_command,command).status==timing::Status::completed && clock->snapshot().audio_commands->residual==1601);
    Control discarded([&](auto& p,const auto&,const auto&){check(p.snapshot().session.group_visits==visits+1 && p.snapshot().session.discard_diagnostics==1);});check(handles.with(adopted.key,discarded)==S::completed);
    command.value=0;check(clock->execute(timing::Operation::audio_requested,command).status==timing::Status::completed);
    check(movie->rebuild(opened.key)==life::Status::pending);life::Open next;until([&]{next=movie->poll();check(next.status==life::Status::pending || next.status==life::Status::completed);return next.status==life::Status::completed;});
    std::uint8_t phase=99;check(videos->values.size()==2 && clock->snapshot().detached && captured.source->status(phase)==P::completed && phase==3 && movie->service(opened.key)==life::Status::invalid_key);
    until([&]{const auto work=movie->service(next.key);check(work==life::Status::completed || work==life::Status::pending);return videos->values.back()->ended;});check(videos->values.back()->bytes==bytes->size());
    until([&]{const auto work=movie->close();check(work==life::Status::completed || work==life::Status::pending);return work==life::Status::completed;});
    check(videos->clocks.back()->snapshot().detached && captured.source->status(phase)==P::completed);
    Control still_playing([&](auto& p,const auto& key,const auto&){auto s=p.inspect(key).source;check(p.snapshot().session.records==1 && !s->stop_requested && !s->retired && s->output.voice.playing && !s->clock.paused);});check(handles.with(adopted.key,still_playing)==S::completed);
    std::array<float,128> rendered{};check(sources->submix()->render_add(rendered.data(),64)==inst::control::output::Status::completed && std::any_of(rendered.begin(),rendered.end(),[](float v){return v!=0;}));
    videos->fail=true;auto failed=life::Session::create(factory);check(failed->open({bytes,0,bytes->size()}).status==life::Status::provider_failure);
    until([&]{auto work=failed->poll().status;check(work==life::Status::pending || work==life::Status::completed);return work==life::Status::completed;});check(handles.with(adopted.key,still_playing)==S::completed && captured.source->status(phase)==P::completed);
    shutdown(handles,sources);phase=99;check(captured.source->status(phase)==P::closed && phase==99);
}
}
int main()try{graph_handoff::workflow();std::cout<<"canonical audio through prepared movie graph checks="<<checks<<"; real audio/read workers, declared video, no device/game/GPU\n";return 0;}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
