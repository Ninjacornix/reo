// Captures live native queue observations and literal clock results only.
// No original expected result or baseline is read by this executable.
#include "player.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <iostream>
#include <cstdlib>
#include <string_view>
#include <thread>
namespace p=reo::native::adxt_clocked_player;
namespace c=reo::native::adxt_estimated_clock;
namespace t=reo::native::adxt_shared_player::testing;
namespace o=reo::native::adxt_output_session;
std::shared_ptr<reo::native::adxt_player::testing::Provider> scheduled_provider;
// Called only by a separately generated scheduling fixture, never production.
void test_after_play_before_clock()noexcept{if(scheduled_provider)scheduled_provider->step(64);}
void require(bool value){if(!value)std::abort();}
void stream(c::Stream s){std::cout<<'['<<s.estimate_base<<','<<s.tick_base<<','<<unsigned(s.paused)<<','<<unsigned(s.rna_play)<<']';}
void shared(const c::Shared& s){std::cout<<'['<<s.mode.selection<<','<<s.mode.ratio<<','<<s.mode.resynchronizations<<','<<s.rebase_selector<<','<<s.service_busy<<','<<s.drift_bits<<']';}
int main(){
    for(unsigned rate:{24000u,44100u,48000u}){
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();
        auto host=std::make_shared<reo::native::adxt_player::testing::Provider>();
        o::Session output({1},slot,host);require(output.start()==o::Status::completed);scheduled_provider=host;
        auto clock=std::make_shared<c::Shared>();clock->mode={1,5994,17};clock->service_busy=1;
        auto file=t::file(1,rate,40017);p::Config config;config.initial_tick=9;config.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
        auto producer=output.open(1);require(producer.status==o::Status::completed);
        p::Player player(config,std::move(producer.producer),file,reo::native::adxt_refill::make_async_backend(8192),std::make_shared<reo::native::adx_header::KeyContext>(),clock);
        unsigned index{};
        auto measure=[&](const char* op,unsigned tick,int argument=0){
            const auto before=player.snapshot();const auto global=*clock;
            p::ClockResult result;p::ClockControl control;
            const std::string_view name(op);
            if(name=="estimate")result=player.estimate(tick);
            else if(name=="centiseconds")result=player.centiseconds(tick);
            else if(name=="pause")control=player.pause(argument,tick);
            else if(name=="discard_rebase")control=player.discard_rebase(tick);
            else std::abort();
            const auto after=player.snapshot();const auto observation=after.clock_observation;
            const bool query=name=="estimate" || name=="centiseconds";
            require((query?result.status:control.status)==p::Status::completed && after.clock_observation_valid);
            // In this model no render occurs after the query-point scheduling
            // edge until the entire row is captured. Thus after-queue values
            // independently identify the actual raw-query observation.
            std::cout<<"{\"name\":\"live-"<<rate<<'-'<<index++<<"\",\"op\":\""<<op<<"\",\"tick\":"<<tick<<",\"argument\":"<<argument<<",\"before\":";
            stream(before.clock);std::cout<<",\"shared_before\":";shared(global);
            std::cout<<",\"observation\":["<<unsigned(observation.state)<<','<<observation.decoded<<','<<observation.total<<','<<observation.frequency
                <<','<<observation.base<<','<<observation.offset<<','<<observation.depth_mode<<','<<observation.depth_code<<','<<observation.output_present
                <<','<<observation.output_bytes<<','<<observation.rna_free_bytes<<"],\"after\":";stream(after.clock);
            std::cout<<",\"shared_after\":";shared(*clock);
            std::cout<<",\"status\":"<<unsigned(query?result.result.status:control.result)
                <<",\"numerator\":"<<result.result.ratio.numerator<<",\"denominator\":"<<result.result.ratio.denominator<<",\"value\":"<<result.result.value
                <<",\"actual_play\":"<<after.output.voice.playing<<",\"consumed_before\":"<<before.output.channel[0].consumed_bytes
                <<",\"consumed_after\":"<<after.output.channel[0].consumed_bytes<<"}\n";
        };
        measure("estimate",9);measure("pause",10,1);measure("pause",11,0);
        for(unsigned n=0;n<10000 && !player.snapshot().output.voice.playing;++n){require(player.service(20)!=p::Status::fault);std::this_thread::yield();}
        require(player.snapshot().output.voice.playing);host->step(64);
        measure("estimate",21);measure("centiseconds",22);measure("pause",23,1);
        measure("estimate",100);measure("pause",101,1);measure("discard_rebase",102);
        measure("pause",103,0);measure("pause",104,2);measure("pause",105,2);
        measure("pause",106,258);measure("pause",107,-1);measure("pause",108,-1);measure("pause",109,0);
        clock->mode.selection=0;measure("estimate",110);measure("centiseconds",111);
        require(player.set_time_base(0xFFFFFFF0u)==p::Status::completed);measure("estimate",112);
        require(player.set_time_base(0)==p::Status::completed);
        clock->mode={1,6000,0};clock->rebase_selector=1;measure("estimate",1000);
        bool ended=false;
        for(unsigned n=0;n<100000;++n){const auto result=player.service(2000);require(result!=p::Status::fault);
            if(result==p::Status::ended){ended=true;break;}
            if(player.snapshot().output.channel[0].samples>=512)host->step(512);
            std::this_thread::yield();}
        require(ended);measure("estimate",2001);measure("centiseconds",2002);measure("pause",2003,1);
        bool retired=false;for(unsigned n=0;n<10000;++n){const auto result=player.retire_on_control_thread();if(result==p::Status::completed){retired=true;break;}require(result==p::Status::pending);std::this_thread::yield();}
        require(retired && output.join()==o::Status::completed);scheduled_provider.reset();
    }
}
