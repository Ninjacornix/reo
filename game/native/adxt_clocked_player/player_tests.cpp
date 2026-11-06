#include "player.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <cfenv>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>
#include <thread>
namespace p=reo::native::adxt_clocked_player;
namespace t=reo::native::adxt_shared_player::testing;
namespace c=reo::native::adxt_estimated_clock;
namespace o=reo::native::adxt_output_session;
unsigned checks{};
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"FAILED: %s\n",why);std::exit(1);}}
struct Fixture {
    std::shared_ptr<reo::audio_output::CallbackSlot> slot=std::make_shared<reo::audio_output::CallbackSlot>();
    std::shared_ptr<reo::native::adxt_player::testing::Provider> host=std::make_shared<reo::native::adxt_player::testing::Provider>();
    o::Session output{{2},slot,host};
    std::shared_ptr<c::Shared> shared=std::make_shared<c::Shared>();
    Fixture(){shared->mode={1,6000,0};check(output.start()==o::Status::completed,"clock fixture output starts");}
    std::unique_ptr<p::Player> make(unsigned total=40017,unsigned initial_tick=0){
        auto file=t::file(1,48000,total);p::Config config;config.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());config.initial_tick=initial_tick;
        auto opened=output.open(1);check(opened.status==o::Status::completed,"clock producer opened");
        return std::make_unique<p::Player>(config,std::move(opened.producer),file,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),shared);
    }
    void advance(p::Player& a,p::Player* b=nullptr,unsigned count=1){
        for(unsigned n=0;n<count;++n){check(a.service(17)!=p::Status::fault,"clock player service");
            if(b)check(b->service(17)!=p::Status::fault,"clock peer service");
            host->step(64);std::this_thread::yield();}
    }
    void playing(p::Player& a,p::Player* b=nullptr){
        for(unsigned n=0;n<10000;++n){advance(a,b);if(a.snapshot().output.voice.playing && (!b || b->snapshot().output.voice.playing))return;}
        check(false,"clock players reached playing");
    }
    void retire(p::Player& player){
        for(unsigned n=0;n<10000;++n){const auto result=player.retire_on_control_thread();if(result==p::Status::completed)return;
            check(result==p::Status::pending,"clock source join pending");std::this_thread::yield();}check(false,"bounded clock source join");
    }
};
void live_pause(){
    Fixture f;auto a=f.make(),b=f.make(80001);f.playing(*a,b.get());
    check(a->snapshot().clock.tick_base==17 && a->snapshot().clock.rna_play==1,"startup origins and actual play bound");
    check(a->pause(1,30).status==p::Status::completed,"live pause accepted");
    const auto paused=a->snapshot();const auto peer=b->snapshot();
    check(paused.clock.paused==1 && paused.clock.rna_play==0 && !paused.output.voice.playing && paused.playback.paused,"pause bytes and actual voice agree");
    const auto first=a->centiseconds(31);check(first.status==p::Status::completed,"paused centiseconds available");
    f.advance(*a,b.get(),10);const auto after=a->snapshot();
    check(after.output.channel[0].consumed_bytes==paused.output.channel[0].consumed_bytes,"actual paused output consumption frozen");
    check(b->snapshot().output.channel[0].consumed_bytes>peer.output.channel[0].consumed_bytes,"peer continues during pause");
    check(a->centiseconds(500).result.value==first.result.value,"paused estimate independent of later supplied tick");
    const auto beforeDiscard=a->snapshot().clock;
    const auto refused=a->discard_rebase(700);
    check(refused.status==p::Status::unsupported_profile && refused.result==c::Status::unsupported_service && a->snapshot().clock==beforeDiscard,"unowned original service path refuses before effects");
    f.shared->service_busy=1;
    check(a->discard_rebase(701).status==p::Status::completed && a->snapshot().clock.tick_base==701,"already-busy discard branch bound to live queue");
    f.shared->service_busy=0;
    check(a->pause(2,800).status==p::Status::completed,"original argument2 resume accepted");
    const auto resumed=a->snapshot();
    check(resumed.clock.paused==2 && resumed.clock.rna_play==1 && resumed.output.voice.playing && resumed.clock.tick_base==800,"argument2 retains byte2 while actually playing");
    f.advance(*a,b.get());check(a->snapshot().output.channel[0].consumed_bytes>resumed.output.channel[0].consumed_bytes,"argument2 resumes actual PCM consumption");
    check(a->pause(0,801).status==p::Status::completed && a->snapshot().clock.paused==0,"argument0 clears original pause byte");
    check(a->snapshot().playback.estimate_base==a->snapshot().clock.estimate_base && a->snapshot().playback.tick_base==a->snapshot().clock.tick_base,"canonical origins synchronized with control state");
    f.retire(*a);check(!a->snapshot().clock_observation_valid && a->estimate(900).status==p::Status::closed,"retired historical queue is not a live clock observation");
    f.retire(*b);check(f.output.join()==o::Status::completed,"clock peer session joins last");
}
void before_header(){
    Fixture f;auto a=f.make(40017,50);
    check(a->pause(1,60).status==p::Status::completed && a->snapshot().clock.paused==1,"pre-header pause stored");
    for(unsigned n=0;n<10000 && a->snapshot().playback.phase!=reo::native::adxt_playback::Phase::playing;++n){
        check(a->service(70)!=p::Status::fault,"pre-paused buffering progresses");std::this_thread::yield();}
    const auto started=a->snapshot();
    check(started.configured && started.playback.started && !started.output.voice.playing && started.clock.tick_base==50,"paused start keeps original origin and actual output stopped");
    check(a->pause(0,80).status==p::Status::completed && a->snapshot().clock.tick_base==80 && a->snapshot().output.voice.playing,"pre-paused player resumes output with supplied tick");
    f.retire(*a);check(f.output.join()==o::Status::completed,"pre-paused session closes");
}
void refusals(){
    Fixture f;auto a=f.make();f.playing(*a);
    const auto before=a->snapshot();const auto csr=_mm_getcsr();std::fenv_t env;check(std::fegetenv(&env)==0,"save test FP state");
    check(std::fesetround(FE_DOWNWARD)==0,"select unsupported rounding");const auto refused=a->pause(1,90);
    check(refused.status==p::Status::unsupported_profile && refused.result==c::Status::unsupported_fp,"pause rejects FP environment before actual output effects");
    check(a->snapshot().clock==before.clock && a->snapshot().output.voice.playing,"FP refusal leaves origins and actual play unchanged");
    (void)std::fesetenv(&env);_mm_setcsr(csr);
    f.shared->mode.ratio=0;const auto zero=a->estimate(91);
    check(zero.status==p::Status::unsupported_profile && zero.result.status==c::Status::zero_divisor && a->snapshot().output.voice.playing,"zero ratio refusal does not mute game output");
    f.shared->mode.ratio=6000;f.shared->in_call=true;
    check(a->estimate(91).status==p::Status::busy && a->pause(1,91).status==p::Status::busy,"shared clock reentry refuses before effects");f.shared->in_call=false;
    f.shared->mode.selection=0;
    check(a->set_time_base(0xFFFFFFF0u)==p::Status::completed,"original raw base setter");
    const auto raw=a->estimate(92);check(raw.status==p::Status::completed && raw.result.ratio.denominator==48000,"live raw query uses actual header frequency");
    f.retire(*a);check(f.output.join()==o::Status::completed,"refusal session closes");
}
int main(){live_pause();before_header();refusals();std::printf("%u live clock/player ownership checks passed; no audio device\n",checks);}
