#include "instances.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include <chrono>
#include <iostream>
#include <thread>

namespace n=reo::native::adxt_instances;
namespace f=reo::native::adxt_shared_player::testing;
namespace integer=reo::native::adxt_integer_clock;
using S=n::Status;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Game control check "+std::to_string(checks));}
template<class F>void until(F&& done){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(15);while(!done()){check(std::chrono::steady_clock::now()<end);std::this_thread::yield();}}
n::Source source(std::shared_ptr<const reo::native::resources::ByteView> bytes,std::uint32_t base=0){n::Source result;result.input=std::move(bytes);result.player.decoder.source_config.byte_length=static_cast<std::int32_t>(result.input->size());result.player.time_base=base;return result;}
void service(n::Instances& players){const auto value=players.service(17);check(value==S::completed || value==S::pending);}
void join(n::Instances& players){until([&]{const auto value=players.join();check(value==S::completed || value==S::pending);return value==S::completed;});}
struct Release {std::shared_ptr<f::Blocked> file;void run(){std::lock_guard lock(file->mutex);file->released=true;file->cv.notify_all();}~Release(){run();}};
void clocks_and_replacement(){
    n::Instances p(n::control::Config{{1},{}});check(p.start_output()==S::completed);auto opened=p.create({1,{0,0,0,0}});check(opened.status==S::completed);const auto key=opened.key;
    check(p.centiseconds(key,1).status==n::control::Status::pending && p.ratio(key,integer::Query::rna_ratio).status==n::control::Status::pending && p.discard_rebase(key,1).status==n::control::Status::pending);
    check(p.configure_clock({{0,5994,UINT32_MAX},7,0x7fc12345})==S::completed);
    const auto imported=p.snapshot().session.clock_state;check(imported.mode.selection==0 && imported.mode.ratio==5994 && imported.mode.resynchronizations==UINT32_MAX && imported.rebase_selector==7 && imported.drift_bits==0x7fc12345 && !imported.service_busy && !imported.in_call);
    check(p.start(key,source(f::file(1,48000,20000),7))==S::completed);
    auto ratio=p.ratio(key,integer::Query::decoded_minus_queued);check(ratio.status==n::control::Status::completed && ratio.value.ratio==integer::Ratio{7,1});
    const auto time=p.centiseconds(key,17);check(time.status==n::control::Status::completed && time.value.result.value==700);
    check(p.set_time_base(key,11)==S::completed && p.ratio(key,integer::Query::rna_ratio).value.ratio==integer::Ratio{11,1});
    check(p.ratio(key,static_cast<integer::Query>(9)).status==n::control::Status::unsupported_profile);
    until([&]{service(p);return p.inspect(key).source->configured;});
    check(p.pause(key,1,20)==S::completed && p.discard_rebase(key,21).status==n::control::Status::completed);
    check(p.snapshot().session.discard_diagnostics==1 && !p.snapshot().session.clock_state.service_busy && !p.snapshot().session.clock_state.in_call);
    auto blocked=std::make_shared<f::Blocked>();blocked->bytes=f::file(1,48000,20000)->bytes;Release release{blocked};
    const auto started=p.start(key,source(blocked,99));check(started==S::completed || started==S::pending);
    until([&]{service(p);std::lock_guard lock(blocked->mutex);return blocked->entered;});
    auto next=f::file(1,48000,20000);check(p.start(key,source(next,101))==S::pending && !next->reads);
    check(p.set_time_base(key,19)==S::completed && p.set_loop_enabled(key,false)==S::completed);
    check(p.centiseconds(key,22).status==n::control::Status::pending && p.ratio(key,integer::Query::rna_ratio).status==n::control::Status::pending && p.discard_rebase(key,22).status==n::control::Status::pending);
    release.run();until([&]{service(p);const auto s=p.inspect(key);return s.starts==3 && s.source->configured;});
    check(p.inspect(key).source->clock_observation.base==19 && p.inspect(key).source->clock.paused==1);
    const auto destroyed=p.destroy(key);check(destroyed==S::completed || destroyed==S::pending);until([&]{service(p);return p.inspect(key).status==S::invalid_key;});
    check(p.set_time_base(key,1)==S::invalid_key && p.set_loop_enabled(key,true)==S::invalid_key && p.ratio(key,integer::Query::rna_ratio).status==n::control::Status::invalid_key && p.centiseconds(key,1).status==n::control::Status::invalid_key && p.discard_rebase(key,1).status==n::control::Status::invalid_key);
    auto fresh=p.create({1,{0,0,0,0}});check(fresh.status==S::completed && p.start(fresh.key,source(f::file(1,48000,20000),23))==S::completed);
    check(p.ratio(fresh.key,integer::Query::rna_ratio).value.ratio==integer::Ratio{23,1});join(p);
    check(p.configure_clock({})==S::closed && p.set_time_base(fresh.key,0)==S::closed && p.set_loop_enabled(fresh.key,false)==S::closed && p.centiseconds(fresh.key,1).status==n::control::Status::closed && p.ratio(fresh.key,integer::Query::rna_ratio).status==n::control::Status::closed && p.discard_rebase(fresh.key,1).status==n::control::Status::closed);
}
std::shared_ptr<f::File> looping(){
    auto bytes=std::make_shared<f::File>();constexpr unsigned total=20000,header=2048,end=header+(total+31)/32*18;
    auto& d=bytes->bytes;d.resize((end+4+2047)/2048*2048);f::be16(d,0,0x8000);f::be16(d,2,header-4);d[4]=3;d[5]=18;d[6]=4;d[7]=1;f::be32(d,8,48000);f::be32(d,12,total);f::be16(d,16,500);d[18]=3;
    f::be16(d,22,1);f::be16(d,26,1);f::be32(d,32,header);f::be32(d,36,total);f::be32(d,40,end);
    for(unsigned at=header;at<end;at+=18){d[at+1]=3;std::fill_n(d.begin()+at+2,16,0x11);}f::be16(d,end,0x8001);return bytes;
}
void loop_control(){
    n::Instances p(n::control::Config{{1},{}});check(p.start_output()==S::completed);auto key=p.create({1,{0,0,0,0}}).key;
    check(p.set_service_divisor(key,30)==S::completed && p.set_loop_enabled(key,true)==S::completed && p.set_time_base(key,7)==S::completed && p.start(key,source(looping(),99))==S::completed);
    std::array<float,1024> buffer{};
    until([&]{service(p);const auto s=p.inspect(key).source;check(s && !s->fault);if(s->output.channel[0].samples>=512)check(p.submix()->render_add(buffer.data(),512)==n::control::output::Status::completed);return s->decoder.loop.iterations>=2;});
    const auto running=p.inspect(key).source;check(running->decoder.source.loop.enabled && running->clock_observation.base==7 && running->playback.request_samples==4864);
    const auto ratio=p.ratio(key,integer::Query::decoded_minus_queued);check(ratio.status==n::control::Status::completed && ratio.value.ratio.numerator==running->output.channel[0].consumed_bytes/2+7 && ratio.value.ratio.denominator==48000);
    check(p.set_loop_enabled(key,false)==S::completed && !p.inspect(key).source->decoder.source.loop.enabled);
    until([&]{service(p);const auto s=p.inspect(key).source;if(s->output.channel[0].samples>=512)check(p.submix()->render_add(buffer.data(),512)==n::control::output::Status::completed);return s->playback.phase==reo::native::adxt_playback::Phase::ended;});join(p);
}
void seamless_admission(){
    std::array<std::shared_ptr<const reo::native::resources::ByteView>,2> views;
    for(auto& view:views){auto bytes=f::file(1,48000,4097);const auto end=96+(4097+31)/32*18;bytes->bytes.resize((end+18+2047)/2048*2048);f::be16(bytes->bytes,end,0x8001);f::be16(bytes->bytes,end+2,14);view=bytes;}
    auto prepared=reo::native::adx_sequence::Sequence::prepare(views);check(prepared.status==reo::native::adx_sequence::Status::completed);
    n::Instances p(n::control::Config{{1},{}});check(p.start_output()==S::completed);auto key=p.create({1,{0,0,0,0}}).key;
    check(p.set_loop_enabled(key,true)==S::completed && p.start(key,source(f::file(1,48000,20000)))==S::completed);
    auto queued=source(prepared.sequence);queued.player.sequence=prepared.sequence;queued.player.decoder.seamless_enabled=true;
    auto invalid=queued;invalid.player.decoder.loop_enabled=true;
    check(p.start(key,std::move(invalid))==S::unsupported_profile && p.inspect(key).starts==1 && p.inspect(key).phase==n::Phase::active);
    const auto start=p.start(key,std::move(queued));check(start==S::completed || start==S::pending);
    until([&]{service(p);return p.inspect(key).starts==2 && p.inspect(key).source->configured;});
    check(p.set_loop_enabled(key,true)==S::completed && !p.inspect(key).source->fault && !p.inspect(key).source->decoder.source.loop.enabled);
    join(p);
}
void start_gate(){
    n::Instances p(n::control::Config{{2},{}});check(p.start_output()==S::completed);
    auto a=p.create({1,{0,0,0,0}}),b=p.create({1,{1,1,1,1}});check(a.status==S::completed && b.status==S::completed);
    check(p.set_start_inhibit(a.key,true)==S::completed);
    check(p.start(a.key,source(f::file(1,48000,20000)))==S::completed && p.start(b.key,source(f::file(1,48000,20000)))==S::completed);
    check(p.inspect(a.key).source->playback.inhibit && !p.inspect(a.key).source->configured);
    until([&]{service(p);const auto own=p.inspect(a.key).source,peer=p.inspect(b.key).source;return own->configured && own->playback.started && peer->output.voice.playing && peer->output.channel[0].samples>=512;});
    auto own=p.inspect(a.key).source;check(own->playback.inhibit && own->playback.phase==reo::native::adxt_playback::Phase::buffering && !own->output.voice.playing && !own->clock.rna_play);
    std::array<float,128> buffer{};check(p.submix()->render_add(buffer.data(),64)==n::control::output::Status::completed);
    check(!p.inspect(a.key).source->output.channel[0].consumed_bytes && p.inspect(b.key).source->output.channel[0].consumed_bytes==128);
    check(p.set_start_inhibit(a.key,false)==S::completed && p.service(77)==S::completed);
    own=p.inspect(a.key).source;check(!own->playback.inhibit && own->playback.phase==reo::native::adxt_playback::Phase::playing && own->output.voice.playing && own->clock.tick_base==77);
    check(p.set_start_inhibit(a.key,true)==S::completed && p.service(88)==S::completed && p.inspect(a.key).source->output.voice.playing && !p.inspect(a.key).source->clock.paused);
    check(p.submix()->render_add(buffer.data(),64)==n::control::output::Status::completed && p.inspect(a.key).source->output.channel[0].consumed_bytes==128);
    const auto stopped=p.stop(a.key);check(stopped==S::completed || stopped==S::pending);
    check(p.set_start_inhibit(a.key,true)==S::completed);const auto replaced=p.start(a.key,source(f::file(1,48000,20000)));check(replaced==S::completed || replaced==S::pending);
    until([&]{service(p);const auto s=p.inspect(a.key);return s.starts==2 && s.source->configured && s.source->playback.started;});
    own=p.inspect(a.key).source;check(own->playback.inhibit && own->playback.phase==reo::native::adxt_playback::Phase::buffering && !own->output.voice.playing);
    check(p.pause(a.key,1,90)==S::completed && p.set_start_inhibit(a.key,false)==S::completed && p.service(99)==S::completed);
    own=p.inspect(a.key).source;check(own->playback.phase==reo::native::adxt_playback::Phase::playing && own->clock.paused==1 && !own->output.voice.playing);
    check(p.pause(a.key,0,123)==S::completed && p.inspect(a.key).source->output.voice.playing && p.inspect(a.key).source->clock.tick_base==123);
    const auto destroyed=p.destroy(a.key);check(destroyed==S::completed || destroyed==S::pending);until([&]{service(p);return p.inspect(a.key).status==S::invalid_key;});
    check(p.set_start_inhibit(a.key,true)==S::invalid_key);auto fresh=p.create({1,{0,0,0,0}});check(fresh.status==S::completed && p.start(fresh.key,source(f::file(1,48000,20000)))==S::completed && !p.inspect(fresh.key).source->playback.inhibit);
    join(p);check(p.set_start_inhibit(fresh.key,false)==S::closed);
}
void service_divisor(){
    n::Instances p(n::control::Config{{1},{}});check(p.start_output()==S::completed);
    auto key=p.create({2,{0,0,0,0}}).key;
    auto first=source(f::file(2,48000,20000));first.player.decoder.channels=2;
    check(p.start(key,first)==S::completed && p.set_service_divisor(key,30)==S::completed);
    check(p.set_service_divisor(key,0)==S::unsupported_profile && p.set_service_divisor(key,INT32_MIN)==S::unsupported_profile);
    until([&]{service(p);return p.inspect(key).source->configured;});
    const auto before=p.inspect(key).source;check(before->decoder.service_divisor==30 && before->playback.request_samples==2432);
    check(p.set_service_divisor(key,24)==S::completed && p.inspect(key).source->playback.request_samples==2432);
    auto second=source(f::file(2,48000,20000));second.player.decoder.channels=2;
    const auto started=p.start(key,std::move(second));check(started==S::completed || started==S::pending);
    check(p.set_service_divisor(key,30)==S::completed);
    until([&]{service(p);return p.inspect(key).starts==2 && p.inspect(key).source->configured;});
    check(p.inspect(key).source->playback.request_samples==2432 && p.inspect(key).source->decoder.service_divisor==30);
    auto bad=source(f::file(2,48000,20000));bad.player.decoder.channels=2;bad.player.decoder.service_divisor=0;
    // A stable explicit setting overrides source defaults, including replacement.
    const auto replaced=p.start(key,std::move(bad));check(replaced==S::completed || replaced==S::pending);
    until([&]{service(p);return p.inspect(key).starts==3 && p.inspect(key).source->configured;});
    check(p.inspect(key).source->playback.request_samples==2432);
    const auto destroyed=p.destroy(key);check(destroyed==S::completed || destroyed==S::pending);
    until([&]{service(p);return p.inspect(key).status==S::invalid_key;});
    check(p.set_service_divisor(key,30)==S::invalid_key);
    key=p.create({1,{0,0,0,0}}).key;
    auto invalid=source(f::file(1,48000,20000));invalid.player.decoder.service_divisor=0;
    check(p.start(key,std::move(invalid))==S::unsupported_profile && p.inspect(key).phase==n::Phase::idle);
    check(p.start(key,source(f::file(1,48000,20000)))==S::completed);
    until([&]{service(p);return p.inspect(key).source->configured;});
    check(p.inspect(key).source->decoder.service_divisor==60 && p.inspect(key).source->playback.request_samples==1216);
    join(p);check(p.set_service_divisor(key,30)==S::closed);
}
int main()try{clocks_and_replacement();loop_control();seamless_admission();start_gate();service_divisor();std::cout<<"native game control checks="<<checks<<'\n';return 0;}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
