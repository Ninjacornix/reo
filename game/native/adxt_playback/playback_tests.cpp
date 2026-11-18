#include "playback.hpp"
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
namespace p=reo::native::adxt_playback;
namespace pcm=reo::native::adx_pcm::v2;
unsigned checks{};
void check(bool value,const char* name) {
    ++checks;if(!value){std::fprintf(stderr,"FAILED: %s\n",name);std::exit(1);}
}
struct Output final:p::Output {
    std::uint32_t queued{},free{8192};unsigned calls{},stops{},plays{},throughs{},pending{};
    bool playing{},closed{},fail_query{},fail_play{},fail_stop{},fail_through{};
    p::Playback* reenter{};p::Status reentry{p::Status::completed};
    p::Status queued_samples(std::uint32_t& n) noexcept override {
        ++calls;n=queued;return fail_query?p::Status::fault:p::Status::completed;
    }
    p::Status free_samples(std::uint32_t& n) noexcept override { ++calls;n=free;return p::Status::completed; }
    p::Status play(bool v) noexcept override {
        ++plays;playing=v;
        if(reenter)reentry=reenter->set_paused_flag(true);
        return fail_play?p::Status::fault:p::Status::completed;
    }
    p::Status stop_transfer() noexcept override {
        ++stops;if(pending){--pending;return p::Status::pending;}
        if(fail_stop)return p::Status::fault;
        closed=true;return p::Status::completed;
    }
    p::Status through() noexcept override { ++throughs;return fail_through?p::Status::fault:p::Status::completed; }
};
void start() {
    pcm::Store store({});p::StorePcm port(store,1);p::Playback player;Output out;
    check(player.service({false,1,32,55},port,out)==p::Status::completed,"buffer wait");
    check(player.state().phase==p::Phase::buffering && !out.plays,"no early play");
    out.queued=256;out.reenter=&player;
    check(player.service({false,1,32,55},port,out)==p::Status::completed,"buffer admits exact threshold");
    check(player.state().started && player.state().phase==p::Phase::playing,"start flags");
    check(out.playing && out.reentry==p::Status::busy,"reentry refused while output side effect runs");
    check(player.state().tick_base==55 && player.state().estimate_base==0,"original estimate origins");
    p::State s;s.paused=true;s.estimate_base=13;s.tick_base=14;p::Playback paused(s);Output paused_out;
    paused_out.queued=256;
    check(paused.service({false,1,32,55},port,paused_out)==p::Status::completed,"paused start");
    check(paused.state().started && paused.state().phase==p::Phase::playing && !paused_out.plays,"paused state advances without play");
    check(paused.state().estimate_base==13 && paused.state().tick_base==14,"paused origins retained");
}
void padding() {
    pcm::Store store({2,16320,62},{},0xA5);p::StorePcm port(store,2);
    p::State s;s.inhibit=true;p::Playback player(s);Output out;
    check(player.service({true,2,32,0},port,out)==p::Status::completed,"ended buffering pads while inhibited");
    check(player.state().phase==p::Phase::buffering && !out.plays,"inhibit retains phase");
    check(player.state().started,"original inhibited admission still sets started byte");
    const auto state=store.snapshot();
    check(state.rings[0].data==256 && state.rings[1].data==256,"stereo request multiplier and bounded wrap grant");
    check(player.state().padding_samples==0,"buffer padding is not drain padding");
    auto read=store.read(256);check(read.status==pcm::Status::completed,"borrow padded bytes");
    std::array<std::uint8_t,256> bytes{};
    for(unsigned c=0;c<2;++c){
        check(read.lease.read_into(c,bytes)==pcm::Status::completed,"read wrapped silence");
        bool zero=true;for(std::size_t i=62;i<bytes.size();++i)zero=zero && bytes[i]==0;
        check(zero,"published tail is silence");
    }
    check(store.finish(read.lease)==pcm::Status::completed,"actual padding lease returned");
}
void drain() {
    pcm::Store store({2,0,62},{},0xA5);p::StorePcm port(store,2);
    p::State s;s.phase=p::Phase::playing;s.padding_samples=999;p::Playback player(s);Output out;
    check(player.service({true,2,32,0},port,out)==p::Status::completed,"short tail enters drain");
    check(player.state().phase==p::Phase::draining && !player.state().padding_samples,"drain resets padding");
    check(player.service({true,2,32,0},port,out)==p::Status::completed,"tail still outstanding");
    check(player.state().phase==p::Phase::draining && player.state().padding_samples==128 && !out.stops,"padding not consumed audio");
    auto lease=store.read(318);check(lease.status==pcm::Status::completed,"actual tail drain borrow");
    check(store.finish(lease.lease)==pcm::Status::completed,"actual tail drain credit");
    out.pending=2;
    check(player.service({true,2,32,0},port,out)==p::Status::pending,"real transfer join can remain pending");
    const auto queued=store.snapshot().rings[0].data;const auto padded=player.state().padding_samples;
    check(player.state().phase==p::Phase::draining && player.state().stopping_transfer && !out.throughs,"no false completion before join");
    check(player.service({true,2,32,0},port,out)==p::Status::pending,"pending fence retried");
    check(store.snapshot().rings[0].data==queued && player.state().padding_samples==padded,"pending fence never republishes silence");
    check(player.service({true,2,32,0},port,out)==p::Status::completed,"actual completed fence admitted");
    check(out.closed && out.stops==3 && out.plays==1 && out.throughs==1,"stop play through order cardinality");
    check(player.state().phase==p::Phase::ended && !player.state().stopping_transfer,"ended only after output accepts controls");
    const auto calls=out.calls;
    check(player.service({true,2,32,0},port,out)==p::Status::completed && out.calls==calls,"ended service inert");
}
void refusals() {
    pcm::Store store({});p::StorePcm port(store,1);p::Playback player;Output out;
    check(player.service({false,3,32,0},port,out)==p::Status::invalid_input && !out.calls,"invalid decoder before effects");
    auto lease=store.read(0);check(lease.status==pcm::Status::completed,"held zero lease");
    out.queued=256;
    check(player.service({true,1,32,0},port,out)==p::Status::fault,"busy padding after playback effects retains a fault");
    check(player.state().phase==p::Phase::playing && player.state().fault,"post-effect state preserved");
    check(store.finish(lease.lease)==pcm::Status::completed,"caller still owns lease after refusal");
    const auto plays=out.plays;
    check(player.service({true,1,32,0},port,out)==p::Status::fault && out.plays==plays,"no replay after partial effect");
    check(player.set_paused_flag(true)==p::Status::fault,"fault blocks flags");
    for(unsigned failure=0;failure<4;++failure){
        pcm::Store empty({});p::StorePcm empty_port(empty,1);p::State s;s.phase=p::Phase::draining;p::Playback test(s);Output output;
        output.fail_query=failure==0;output.fail_stop=failure==1;output.fail_play=failure==2;output.fail_through=failure==3;
        check(test.service({true,1,32,0},empty_port,output)==p::Status::fault,"failed output never claims ended");
        check(test.state().phase==p::Phase::draining && test.state().fault,"failed control state retained");
    }
    bool invalid=false;try{p::State s;s.request_samples=0;p::Playback test(s);}catch(const std::invalid_argument&){invalid=true;}
    check(invalid,"zero request constructor refused");
    invalid=false;try{p::StorePcm wrong(store,2);}catch(const std::invalid_argument&){invalid=true;}
    check(invalid,"wrong channel owner refused");
}
int main(){start();padding();drain();refusals();std::printf("%u playback ownership checks passed\n",checks);}
