#include "../control_session.hpp"
#include "../../adxt_shared_player/test_sources.hpp"
#include "../../adxt_player/test_provider.hpp"
#include <iostream>
#include <stdexcept>
#include <thread>

namespace c=reo::native::adxt_control_session;
namespace f=reo::native::adxt_shared_player::testing;
namespace p=reo::native::adxt_player::testing;
static std::shared_ptr<p::Provider> scheduled_provider;static bool armed{};static unsigned scheduled_callbacks{};
// Only generated verification sources call this declared external model event.
// The production session has no such scheduling hook or device progress call.
void test_after_group_before_clock_snapshot()noexcept{
    if(armed){armed=false;++scheduled_callbacks;(void)scheduled_provider->step(512);}
}
void require(bool b){if(!b)throw std::runtime_error("Serviced binding fixture failed");}
void observation(const c::player::clock::integer::Observation& o){
    std::cout<<'['<<unsigned(o.state)<<','<<o.decoded<<','<<o.total<<','<<o.frequency<<','<<o.base<<','<<o.offset<<','<<o.depth_mode<<','<<o.depth_code<<','<<o.output_present<<','<<o.output_bytes<<','<<o.rna_free_bytes<<']';
}
void stream(c::player::clock::Stream s){std::cout<<'['<<s.estimate_base<<','<<s.tick_base<<','<<unsigned(s.paused)<<','<<unsigned(s.rna_play)<<']';}
void shared(const c::player::clock::Shared& s){std::cout<<'['<<s.mode.selection<<','<<s.mode.ratio<<','<<s.mode.resynchronizations<<','<<s.rebase_selector<<','<<s.service_busy<<','<<s.drift_bits<<']';}
int main(){try{
    for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,44100u,48000u}){
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto provider=std::make_shared<p::Provider>();
        c::Config config;config.output.streams=2;config.clock.mode={1,6000,17};config.clock.drift_bits=0x12345678;
        c::Session session(config,slot,provider);require(session.start()==c::Status::completed);
        auto file=f::file(channels,rate,240000);c::player::Config pc;pc.decoder.channels=channels;pc.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
        const auto opened=session.open(pc,file,{0,0,0,0});require(opened.status==c::Status::completed);auto key=opened.key;
        bool ready=false;for(unsigned i=0;i<100000;++i){require(session.service(0)==c::Status::completed);const auto state=session.inspect(key).evidence;
            if(state.output.voice.playing && state.output.channel[0].samples>=4096){ready=true;break;}std::this_thread::yield();}require(ready);
        scheduled_provider=provider;
        auto capture=[&](const char* name,unsigned tick){
            const auto before=session.inspect(key).evidence;const auto before_session=session.snapshot();const auto callbacks=scheduled_callbacks;
            armed=before.clock.paused!=0;const auto result=session.discard_rebase(key,tick);armed=false;
            const auto after=session.inspect(key).evidence;const auto after_session=session.snapshot();require(result.status==c::Status::completed && result.value.result==c::player::clock::Status::completed);
            require(before.clock_observation.state==3 && after.clock_observation.state==3 && before.clock.paused==after.clock.paused && before.clock.rna_play==after.clock.rna_play);
            require(before.service_visits[0]==after.service_visits[0]);
            require(after_session.group_visits-before_session.group_visits==unsigned(before.clock.paused!=0));
            std::cout<<"{\"name\":\""<<channels<<'-'<<rate<<'-'<<name<<"\",\"tick\":"<<tick<<",\"before\":";stream(before.clock);
            std::cout<<",\"after\":";stream(after.clock);std::cout<<",\"shared_before\":";shared(before_session.clock_state);std::cout<<",\"shared_after\":";shared(after_session.clock_state);
            std::cout<<",\"observation_before\":";observation(before.clock_observation);std::cout<<",\"observation_after\":";observation(after.clock_observation);
            std::cout<<",\"group_visits\":"<<after_session.group_visits-before_session.group_visits<<",\"diagnostics\":"<<after_session.discard_diagnostics-before_session.discard_diagnostics
                     <<",\"scheduled_callbacks\":"<<scheduled_callbacks-callbacks<<",\"consumed_before\":"<<before.output.channel[0].consumed_bytes<<",\"consumed_after\":"<<after.output.channel[0].consumed_bytes<<"}\n";
        };
        capture("unpaused",101);require(session.pause(key,1,102).status==c::Status::completed);capture("paused",103);
        require(session.pause(key,2,104).status==c::Status::completed);capture("nonboolean-two",105);
        require(session.pause(key,255,106).status==c::Status::completed);capture("nonboolean-255",107);
        require(session.pause(key,0,108).status==c::Status::completed);capture("resumed",109);
        bool retired=false;for(unsigned i=0;i<100000;++i){const auto status=session.retire(key).status;if(status==c::Status::completed){retired=true;break;}require(status==c::Status::pending);std::this_thread::yield();}require(retired);
        require(session.join()==c::Status::completed && session.snapshot().records==0 && provider->unloads==1);scheduled_provider.reset();
    }
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
