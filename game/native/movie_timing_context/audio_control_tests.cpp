#include "context.hpp"
#include "../movie_audio_clock/session_source.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <cstdio>
#include <source_location>
#include <stdexcept>
#include <string>
#include <thread>
namespace n=reo::native::movie_timing_context;
namespace session=reo::native::adxt_control_session;
unsigned checks{};
void check(bool value,std::source_location location=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Audio control check at line "+std::to_string(location.line()));
}
struct Helper final:n::audio::HelperClock {
    n::audio::ProviderStatus counter(std::uint64_t& value)noexcept override{value=19200;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=576000;return n::audio::ProviderStatus::completed;}
};
struct Tick final:n::audio::ServiceTick {
    unsigned calls{};bool fail{};
    n::audio::ProviderStatus read(std::uint32_t& value)noexcept override{++calls;value=0;return fail?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
};
struct Ports final:n::Ports {unsigned calls{};n::Reply call(n::pause::Call,const n::View&)noexcept override{++calls;return{};}};
struct Device final:n::audio::ControlledSource {
    std::weak_ptr<n::Context> owner;std::shared_ptr<n::Context>* external{};n::audio::Clock* direct{};
    n::AudioStage failure{n::AudioStage::none};std::uint32_t frequency{48000},paused{};unsigned pauses{},discards{};
    bool busy{},drop{},retention_missing{},clock_busy{};
    n::audio::ProviderStatus status(std::uint8_t& value)noexcept override{value=3;return failure==n::AudioStage::status?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{
        if(direct)clock_busy=direct->set_pause(99)==n::audio::Status::busy && direct->add_baseline({1,1})==n::audio::Status::busy;
        value={1600,48000};return n::audio::ProviderStatus::completed;
    }
    n::audio::ProviderStatus sample_frequency(std::uint32_t& value)noexcept override{value=frequency;return failure==n::AudioStage::frequency?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus pause(std::uint32_t value)noexcept override{
        ++pauses;
        if(drop && owner.use_count()<2){retention_missing=true;return n::audio::ProviderStatus::fault;}
        auto context=owner.lock();if(drop)external->reset();
        if(context)busy=context->execute(n::Operation::audio_command).status==n::Status::busy && context->detach_queries()==n::Status::busy && context->observe({})==n::Status::busy;
        if(failure==n::AudioStage::pause)return n::audio::ProviderStatus::fault;
        paused=value&255;return n::audio::ProviderStatus::completed;
    }
    n::audio::ProviderStatus discard(std::uint32_t,std::uint32_t& value)noexcept override{++discards;value=0;return failure==n::AudioStage::discard?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
};
n::Config config(std::shared_ptr<n::audio::AudioSource> source){
    n::Config input;input.audio=std::move(source);input.helper=std::make_shared<Helper>();input.ports=std::make_shared<Ports>();
    n::Buffering buffering;buffering.audio=1;buffering.enabled=1;buffering.latest={1000,48000};input.buffering=buffering;input.audio_commands=n::AudioCommands{};return input;
}
n::Result call(const std::shared_ptr<n::Context>& owner,n::Operation op,std::uint32_t value){n::Input input;input.value=value;return owner->execute(op,input);}
void retire(const std::shared_ptr<session::Session>& owner,const session::Key& key){
    for(unsigned i=0;i<100000;++i){const auto value=owner->retire(key);if(value.status==session::Status::completed){check(value.source_joined);return;}check(value.status==session::Status::pending);std::this_thread::yield();}
    check(false);
}
int main(){try{
    {
        auto device=std::make_shared<Device>();n::audio::Clock clock({},device,std::make_shared<Helper>());device->direct=&clock;
        check(clock.execute(n::audio::Operation::slot,4,{}).status==n::audio::Status::completed && device->clock_busy && clock.snapshot().state.filter.pause==0);
    }
    for(auto failure:{n::AudioStage::status,n::AudioStage::frequency,n::AudioStage::discard}){
        auto device=std::make_shared<Device>();auto owner=n::Context::create(config(device));device->owner=owner;
        check(call(owner,n::Operation::pause,1).status==n::Status::completed && device->busy);
        const auto before=owner->snapshot();device->failure=failure;const auto result=call(owner,n::Operation::pause,2);const auto after=owner->snapshot();
        check(result.status==n::Status::provider_failure && !result.return_defined && after.audio_commands->stage==failure && after.audio_commands->provider==n::audio::ProviderStatus::fault);
        check(after.clock.active_counter==before.clock.active_counter+1601 && after.audio_commands->residual==before.audio_commands->residual && after.audio.filter==before.audio.filter && after.guard.depth==0);
        device->failure=n::AudioStage::none;check(call(owner,n::Operation::audio_command,2).status==n::Status::completed && owner->snapshot().audio_commands->residual==1601);
    }
    {
        auto device=std::make_shared<Device>();device->failure=n::AudioStage::pause;auto owner=n::Context::create(config(device));device->owner=owner;
        const auto result=call(owner,n::Operation::pause,1);check(result.status==n::Status::provider_failure && owner->snapshot().facts.pause==1 && owner->snapshot().facts.depth==1 && owner->snapshot().audio.filter.pause==0);
        device->failure=n::AudioStage::none;check(call(owner,n::Operation::audio_requested,1).status==n::Status::completed && owner->snapshot().audio.filter.pause==1);
        const auto count=device->pauses;check(call(owner,n::Operation::audio_requested,0).status==n::Status::completed && device->pauses==count);
        check(call(owner,n::Operation::audio_temporary,0).status==n::Status::completed && device->paused==0);
    }
    {
        auto device=std::make_shared<Device>();device->frequency=0;auto input=config(device);input.audio_filter_mode=0;
        auto owner=n::Context::create(input);const auto before=owner->snapshot().audio.filter;check(call(owner,n::Operation::audio_command,2).status==n::Status::numeric_failure);
        check(device->discards==1 && owner->snapshot().audio_commands->stage==n::AudioStage::filter && owner->snapshot().audio.filter==before);
    }
    {
        auto device=std::make_shared<Device>();device->drop=true;auto owner=n::Context::create(config(device));device->owner=owner;device->external=&owner;
        auto raw=owner.get();n::Input input;input.value=1;const auto result=raw->execute(n::Operation::audio_requested,input);
        check(result.status==n::Status::completed && !device->retention_missing && !owner && device->owner.expired());
    }
    // Real native source worker, decoder, PCM queues, mixer and control session.
    // The output provider is an explicit device model; no audio device opens.
    for(unsigned channels:{1u,2u})for(unsigned rate:{24000u,44100u,48000u}){
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
        auto audio_session=std::make_shared<session::Session>(session::Config{},slot,provider);check(audio_session->start()==session::Status::completed);
        const auto file=reo::native::adxt_shared_player::testing::file(channels,rate,120000);session::player::Config pc;pc.decoder.channels=channels;pc.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
        const auto opened=audio_session->open(pc,file,{0,0,0,0});check(opened.status==session::Status::completed);bool ready=false;
        for(unsigned i=0;i<100000;++i){check(audio_session->service(0)==session::Status::completed);const auto value=audio_session->inspect(opened.key).evidence;
            if(value.output.voice.playing && value.output.channel[0].samples>=512){ready=true;break;}std::this_thread::yield();}check(ready);
        auto tick=std::make_shared<Tick>();auto bound=std::make_shared<n::audio::SessionSource>(audio_session,opened.key,tick);auto owner=n::Context::create(config(bound));
        check(provider->step(512));check(owner->execute(n::Operation::refresh).status==n::Status::completed);
        for(unsigned cycle=0;cycle<8;++cycle){
            n::Buffering buffer;buffer.audio=1;buffer.enabled=1;buffer.latest={1,rate};buffer.audio_slot=3;
            for(auto& stream:buffer.streams)stream.capacity=100;
            // Missing fixed peek stream is a legitimate empty observation;
            // resume uses a stream-end observation, avoiding a fabricated count.
            check(owner->observe_buffering(buffer)==n::Status::completed);
            check(owner->execute(n::Operation::buffer).status==n::Status::completed && owner->snapshot().facts.buffering==1 && owner->snapshot().audio.filter.pause==1);
            check(audio_session->inspect(opened.key).evidence.clock.paused==1 && !audio_session->inspect(opened.key).evidence.output.voice.playing);
            const auto consumed=audio_session->inspect(opened.key).evidence.output.channel[0].consumed_bytes;check(provider->step(64));check(audio_session->inspect(opened.key).evidence.output.channel[0].consumed_bytes==consumed);
            check(call(owner,n::Operation::pause,1).status==n::Status::completed && owner->snapshot().facts.depth==2);
            const auto before=owner->snapshot().clock.active_counter;const auto visits=audio_session->snapshot().group_visits;
            check(call(owner,n::Operation::pause,2).status==n::Status::completed && owner->snapshot().clock.active_counter==before+1601);
            check(audio_session->snapshot().group_visits==visits+1 && owner->snapshot().audio_commands->residual==static_cast<std::uint32_t>(rate*1000/29970));
            buffer.streams[7].ended=1;check(owner->observe_buffering(buffer)==n::Status::completed);check(owner->execute(n::Operation::buffer).status==n::Status::completed && owner->snapshot().facts.depth==1 && owner->snapshot().audio.filter.pause==1);
            check(call(owner,n::Operation::pause,0).status==n::Status::completed && owner->snapshot().facts.depth==0 && owner->snapshot().audio.filter.pause==0);
            check(audio_session->inspect(opened.key).evidence.clock.paused==0 && audio_session->inspect(opened.key).evidence.output.voice.playing);
            // Mode 0 clears residual, so the next cycle starts from zero.
            check(owner->snapshot().audio_commands->residual==0);
        }
        tick->fail=true;const auto before=owner->snapshot().audio.filter;check(call(owner,n::Operation::audio_requested,1).status==n::Status::provider_failure && owner->snapshot().audio.filter==before);tick->fail=false;
        auto other=std::make_shared<session::Session>(session::Config{},std::make_shared<reo::audio_output::CallbackSlot>(),std::make_shared<reo::native::adxt_player::testing::Provider>());
        n::audio::SessionSource foreign(other,opened.key,tick);const auto ticks=tick->calls;std::uint32_t untouched=123;
        check(foreign.pause(1)==n::audio::ProviderStatus::invalid_key && foreign.discard(99,untouched)==n::audio::ProviderStatus::invalid_key && foreign.sample_frequency(untouched)==n::audio::ProviderStatus::invalid_key && untouched==123 && tick->calls==ticks);
        retire(audio_session,opened.key);const auto stale_ticks=tick->calls;check(call(owner,n::Operation::audio_requested,1).status==n::Status::provider_failure && owner->snapshot().audio_commands->provider==n::audio::ProviderStatus::invalid_key && tick->calls==stale_ticks);
        check(owner->detach_queries()==n::Status::completed && call(owner,n::Operation::audio_command,0).status==n::Status::detached);
        provider->fail_detach=1;check(audio_session->join()==session::Status::pending && !provider->unloaded && slot->occupied());check(audio_session->join()==session::Status::completed && provider->unloaded && !slot->occupied());
        std::weak_ptr<session::Session> retained=audio_session;audio_session.reset();bound.reset();check(!retained.expired());owner.reset();check(retained.expired());check(other->join()==session::Status::completed);
    }
    std::printf("%u joined audio control/real source/PCM/failure/retirement checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
