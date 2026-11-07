#define main original_aggregate_scenarios
#include "tests.cpp"
#undef main
#include "game/native/adxt_instances/instances.hpp"
#include "game/native/adxt_shared_player/test_sources.hpp"
#include <chrono>
namespace streams=reo::native::adxt_instances;
namespace files=reo::native::adxt_shared_player::testing;
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(15);while(!done()){if(std::chrono::steady_clock::now()>=end)throw std::runtime_error("Native aggregate/source deadline");std::this_thread::yield();}}
streams::Source source(unsigned channels){streams::Source s;s.input=files::file(channels,48000,20000);s.player.decoder.channels=channels;s.player.decoder.source_config.byte_length=static_cast<std::int32_t>(s.input->size());return s;}
struct StreamGains final:streams::control::output::StreamGains {
    std::array<float,2> values{0.37f,1.41f};std::array<unsigned,2> calls{};bool unknown{};
    float factor(std::uint32_t key)noexcept override{
        if(key==0x1e0000){++calls[0];return values[0];}if(key==0x1e0020){++calls[1];return values[1];}
        unknown=true;return 0;
    }
};
void native_streams(){
    auto gains=std::make_shared<StreamGains>();streams::control::Config config{{2},{}};config.output.stream_gains=gains;
    streams::Instances players(config);Setup s(players.submix());s.install();s.load();
    a::reset();check(!s.owner->report().hard_failures && s.hooks->route_resets==1 && s.owner->inspect_banks().ports[0].loaded);
    check(players.start_output()==streams::Status::completed);const auto x=players.create({1,{0,0,0,0,0x1e0000}}),y=players.create({2,{1,1,1,1,0x1e0020}});
    check(x.status==streams::Status::completed && y.status==streams::Status::completed);
    check(players.volume(x.key,193)==streams::Status::completed && players.volume(y.key,67)==streams::Status::completed);
    check(players.start(x.key,source(1))==streams::Status::completed && players.start(y.key,source(2))==streams::Status::completed);
    const auto service=[&]{const auto r=players.service(17);check(r==streams::Status::completed || r==streams::Status::pending);};
    until([&]{service();const auto a=players.inspect(x.key).source,b=players.inspect(y.key).source;return a && b && a->output.voice.playing && b->output.voice.playing && a->output.channel[0].samples>=512 && b->output.channel[0].samples>=512;});
    a::ensureHostOutput();std::array<float,128> output{};check(s.provider->emit(output.data(),64));
    check(players.inspect(x.key).source->output.channel[0].consumed_bytes==128 && players.inspect(y.key).source->output.channel[0].consumed_bytes==128);
    check(players.inspect(x.key).source->output.voice.gain==0.37f && players.inspect(y.key).source->output.voice.gain==1.41f &&
        players.inspect(x.key).source->output.voice.volume==193 && players.inspect(y.key).source->output.voice.volume==67);
    check(gains->calls[0]==1 && gains->calls[1]==1 && !gains->unknown);
    check(callback_alloc==0 && callback_free==0 && s.provider->attach_calls==1);
    auto report=s.owner->report();check(report.native_streams_bound && report.native_submix_calls==1 && report.native_submix_frames==64 && !report.native_submix_failures);
    check(s.owner->inspect_banks().frame_clock==64 && report.hard_failures==0);
    const auto stopped=players.stop(x.key);check(stopped==streams::Status::completed || stopped==streams::Status::pending);
    until([&]{service();return players.inspect(x.key).phase==streams::Phase::idle;});check(players.inspect(x.key).source->decoder.source.joined);
    gains->values[1]=2.72f;
    check(s.provider->emit(output.data(),64) && players.inspect(y.key).source->output.channel[0].consumed_bytes==256 && s.provider->detach_calls==0);
    check(players.inspect(y.key).source->output.voice.gain==2.72f && gains->calls[0]==1 && gains->calls[1]==2 && !gains->unknown);
    until([&]{const auto r=players.join();check(r==streams::Status::completed || r==streams::Status::pending);return r==streams::Status::completed;});
    check(players.snapshot().session.output.submix_fenced && !players.snapshot().session.output.provider_joined);
    check(s.provider->emit(output.data(),64));report=s.owner->report();
    check(report.native_submix_calls==3 && report.native_submix_frames==128 && s.owner->inspect_banks().frame_clock==192 && !report.hard_failures);
    s.finish();report=s.owner->report();check(report.pcm_statistics.signal_frames==0 && report.banks.frame_clock==192);
    check(s.provider->attach_calls==1 && s.provider->detach_calls==1 && s.provider->stop_calls==1 && s.provider->unload_calls==1);no_legacy();
}
void native_refusals(){
    streams::Instances players(streams::control::Config{{1},{}});Setup s(players.submix());s.install();
    a::reset();check(!s.owner->report().hard_failures && !players.submix()->source_epoch_started());
    const std::array<std::int16_t,32> pcm{};std::uint64_t end=77;
    check(!a::queue(1,reinterpret_cast<const uint8_t*>(pcm.data()),sizeof(pcm),end) && end==77);
    check(!s.owner->inspect_channel(1).source_visible);
    a::configure(2,1,0,1,48000,256,true);check(!s.owner->inspect_voice(2).info.playing);
    a::configure(2,1,0,1,48000,256,false);check(!s.owner->inspect_voice(2).info.playing);
    const auto key=players.create({1,{0,0,0,0}});check(key.status==streams::Status::completed);
    check(players.start(key.key,source(1))==streams::Status::completed && players.submix()->source_epoch_started());
    a::reset();const auto report=s.owner->report();check(report.hard_failures==3 && report.native_submix_calls==0);
    until([&]{const auto r=players.join();check(r==streams::Status::completed || r==streams::Status::pending);return r==streams::Status::completed;});s.finish();no_legacy();
}
int main(int argc,char** argv)try{
    if(argc!=2)return 2;const std::string name=argv[1];
    if(name=="native_streams")native_streams();else if(name=="native_refusals")native_refusals();else return original_aggregate_scenarios(argc,argv);
    std::cout<<"aggregate3 "<<name<<" assertions="<<assertions.load()<<'\n';return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
