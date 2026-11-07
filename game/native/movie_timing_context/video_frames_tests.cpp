#include "video_frames.hpp"
#include "../movie_audio_clock/session_source.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <cstdio>
#include <source_location>
#include <stdexcept>
#include <string>
#include <thread>
namespace n=reo::native::movie_timing_context;
unsigned checks{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Video owner check at line "+std::to_string(at.line()));}
struct Audio final:n::audio::ControlledSource {
    std::uint32_t position{1600},paused{};bool fail{};
    n::audio::ProviderStatus status(std::uint8_t& value)noexcept override{value=3;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{value={position,48000};return fail?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus sample_frequency(std::uint32_t& value)noexcept override{value=48000;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus pause(std::uint32_t value)noexcept override{paused=value;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus discard(std::uint32_t,std::uint32_t& value)noexcept override{value=0;return n::audio::ProviderStatus::completed;}
};
struct Helper final:n::audio::HelperClock {
    n::audio::ProviderStatus counter(std::uint64_t& value)noexcept override{value=19200;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=576000;return n::audio::ProviderStatus::completed;}
};
struct Ports final:n::Ports {n::Reply call(n::pause::Call,const n::View&)noexcept override{return{};}};
struct Surface final:n::FrameSurface {
    bool produced{true},read_complete{true},fault{},retired{},busy{},drop{},retention_missing{};
    unsigned renders{},retirements{},drains{};std::weak_ptr<n::VideoFrames> owner;std::shared_ptr<n::VideoFrames>* external{};
    n::FrameStatus ready()noexcept override{
        if(drop && owner.use_count()<2){retention_missing=true;return n::FrameStatus::provider_failure;}
        if(auto value=owner.lock()){busy=value->reserve().status==n::FrameStatus::busy && value->close()==n::FrameStatus::busy;if(drop)external->reset();}
        return fault?n::FrameStatus::provider_failure:produced?n::FrameStatus::completed:n::FrameStatus::pending;
    }
    n::FrameStatus submit()noexcept override{if(fault)return n::FrameStatus::provider_failure;++renders;read_complete=false;return n::FrameStatus::completed;}
    n::FrameStatus retire()noexcept override{if(fault)return n::FrameStatus::provider_failure;if(!produced || !read_complete)return n::FrameStatus::pending;retired=true;++retirements;return n::FrameStatus::completed;}
    void drain()noexcept override{++drains;produced=read_complete=retired=true;}
};
n::Config config(std::shared_ptr<n::audio::AudioSource> audio){n::Config value;value.audio=std::move(audio);value.helper=std::make_shared<Helper>();value.ports=std::make_shared<Ports>();value.facts.selector=1;value.buffering=n::Buffering{};value.buffering->audio=1;value.audio_commands=n::AudioCommands{};return value;}
n::Result control(const std::shared_ptr<n::Context>& owner,n::Operation op,std::uint32_t value){n::Input input;input.value=value;return owner->execute(op,input);}
n::FrameKey publish(const std::shared_ptr<n::VideoFrames>& frames,n::Words time,std::shared_ptr<Surface> image,bool reference=false){
    const auto reserved=frames->reserve();check(reserved.status==n::FrameStatus::completed);const auto result=frames->publish(reserved.key,time,std::move(image),reference);check(result==n::FrameStatus::completed || result==n::FrameStatus::pending);return reserved.key;
}
int main(){try{
    {
        auto clock=n::Context::create(config(std::make_shared<Audio>()));auto frames=n::VideoFrames::create(clock,1);auto surface=std::make_shared<Surface>();surface->owner=frames;surface->produced=false;
        const auto key=publish(frames,{0,48000},surface);check(surface->busy && frames->peek().status==n::FrameStatus::empty && frames->poll()==n::FrameStatus::pending);
        check(frames->reserve().status==n::FrameStatus::pending && !surface->drains);
        surface->produced=true;check(frames->poll()==n::FrameStatus::completed && frames->acquire().key==key);
        check(frames->present(key)==n::FrameStatus::completed && surface->renders==1);check(frames->release(key)==n::FrameStatus::completed);
        check(frames->poll()==n::FrameStatus::pending && !surface->retired && !surface->drains && frames->reserve().status==n::FrameStatus::pending);
        surface->read_complete=true;check(frames->poll()==n::FrameStatus::completed && surface->retired);
        const auto replacement=frames->reserve();check(replacement.status==n::FrameStatus::completed && !(replacement.key==key));
        check(frames->release(key)==n::FrameStatus::invalid_key && frames->present(key)==n::FrameStatus::invalid_key);
        check(frames->close()==n::FrameStatus::completed);
    }
    {
        auto clock=n::Context::create(config(std::make_shared<Audio>()));auto frames=n::VideoFrames::create(clock,1);auto surface=std::make_shared<Surface>();const auto key=publish(frames,{0,1},surface,true);
        check(frames->retain_reference(key)==n::FrameStatus::completed && frames->acquire().key==key && frames->release(key)==n::FrameStatus::completed);
        check(frames->snapshot().pictures[0].state==3 && frames->poll()==n::FrameStatus::completed && !surface->retired && frames->reserve().status==n::FrameStatus::pending);
        check(frames->demote(key)==n::FrameStatus::completed && frames->poll()==n::FrameStatus::completed && !surface->retired);
        check(frames->release_reference(key)==n::FrameStatus::completed && frames->poll()==n::FrameStatus::completed && surface->retired);
        auto other=n::Context::create(config(std::make_shared<Audio>()));auto foreign=n::VideoFrames::create(other,1);check(foreign->release(key)==n::FrameStatus::invalid_key);
        check(frames->close()==n::FrameStatus::completed && foreign->close()==n::FrameStatus::completed);
    }
    {
        auto audio=std::make_shared<Audio>();auto clock=n::Context::create(config(audio));auto frames=n::VideoFrames::create(clock,3);
        auto first=std::make_shared<Surface>(),second=std::make_shared<Surface>(),third=std::make_shared<Surface>();
        const auto a=publish(frames,{0,48000},first);const auto b=publish(frames,{1600,48000},second,true);const auto c=publish(frames,{3200,48000},third);
        check(frames->acquire().key==a && frames->release(a)==n::FrameStatus::completed);
        check(control(clock,n::Operation::pause,1).status==n::Status::completed && audio->paused==1);
        check(clock->execute(n::Operation::tick).status==n::Status::completed && clock->snapshot().clock.active_counter==0);
        check(frames->acquire().status==n::FrameStatus::held && clock->snapshot().clock.previous.numerator==1600);
        check(!frames->can_advance().decision && control(clock,n::Operation::pause,2).status==n::Status::completed);
        check(clock->snapshot().clock.active_counter==1601 && clock->snapshot().audio_commands->residual==1601 && audio->paused==1);
        check(clock->execute(n::Operation::tick).status==n::Status::completed && clock->snapshot().clock.active_counter==1601);
        check(frames->acquire().key==b && frames->present(b)==n::FrameStatus::completed && frames->release(b)==n::FrameStatus::completed);
        check(frames->snapshot().pictures[1].state==3 && frames->acquire().status==n::FrameStatus::held);
        check(control(clock,n::Operation::pause,2).status==n::Status::completed && clock->execute(n::Operation::tick).status==n::Status::completed && frames->acquire().key==c);
        check(frames->release(c)==n::FrameStatus::completed && control(clock,n::Operation::pause,0).status==n::Status::completed && audio->paused==0);
        second->read_complete=true;check(frames->demote(b)==n::FrameStatus::completed && frames->close()==n::FrameStatus::completed);
    }
    {
        auto clock=n::Context::create(config(std::make_shared<Audio>()));auto frames=n::VideoFrames::create(clock,3);auto a=std::make_shared<Surface>(),b=std::make_shared<Surface>(),c=std::make_shared<Surface>();
        publish(frames,{-2u,1},a);publish(frames,{0,48000},b);publish(frames,{1600,48000},c);
        const auto skipped=frames->skip_if_due();check(skipped.status==n::FrameStatus::completed && skipped.decision && a->renders==0 && b->renders==0);
        check(frames->snapshot().pictures[0].state==0 && frames->snapshot().pictures[1].state==2 && !frames->can_advance().decision);
        check(frames->close()==n::FrameStatus::completed);
    }
    {
        auto audio=std::make_shared<Audio>();auto input=config(audio);input.facts.selector=2;auto clock=n::Context::create(input);auto frames=n::VideoFrames::create(clock,1);auto surface=std::make_shared<Surface>();
        auto key=publish(frames,{0,48000},surface);audio->fail=true;check(frames->acquire().status==n::FrameStatus::clock_failure && frames->snapshot().borrowed[0]);
        audio->fail=false;check(frames->acquire().key==key);surface->fault=true;check(frames->present(key)==n::FrameStatus::provider_failure && frames->release(key)==n::FrameStatus::completed);
        check(frames->poll()==n::FrameStatus::provider_failure && frames->snapshot().resources==1 && !surface->retired);
        surface->fault=false;surface->read_complete=false;check(frames->close()==n::FrameStatus::pending && frames->reserve().status==n::FrameStatus::closed);
        check(clock->detach_queries()==n::Status::completed);surface->read_complete=true;check(frames->poll()==n::FrameStatus::completed && frames->snapshot().closed);
    }
    {
        auto clock=n::Context::create(config(std::make_shared<Audio>()));auto frames=n::VideoFrames::create(clock,2);auto surface=std::make_shared<Surface>();surface->produced=false;
        const auto a=frames->reserve(),b=frames->reserve();check(frames->publish(a.key,{0,1},surface)==n::FrameStatus::pending);
        check(frames->publish(b.key,{1,1},surface)==n::FrameStatus::invalid_input && frames->abandon(a.key)==n::FrameStatus::completed && frames->poll()==n::FrameStatus::pending);
        surface->produced=true;check(frames->poll()==n::FrameStatus::completed && surface->retired && frames->close()==n::FrameStatus::completed);
    }
    {
        auto clock=n::Context::create(config(std::make_shared<Audio>()));auto frames=n::VideoFrames::create(clock,1);auto surface=std::make_shared<Surface>();surface->drop=true;surface->produced=false;surface->owner=frames;surface->external=&frames;
        const auto key=frames->reserve().key;auto raw=frames.get();check(raw->publish(key,{0,1},surface)==n::FrameStatus::pending && !surface->retention_missing && !frames && surface->drains==1 && surface->owner.expired());
    }
    // Actual native audio source/PCM session remains paused while video is held
    // or advanced by the original counter-clock frame-step profile.
    {
        namespace s=reo::native::adxt_control_session;
        struct Tick final:n::audio::ServiceTick {n::audio::ProviderStatus read(std::uint32_t& value)noexcept override{value=0;return n::audio::ProviderStatus::completed;}};
        auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto device=std::make_shared<reo::native::adxt_player::testing::Provider>();auto session=std::make_shared<s::Session>(s::Config{},slot,device);check(session->start()==s::Status::completed);
        auto file=reo::native::adxt_shared_player::testing::file(1,48000,120000);s::player::Config player;player.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());auto stream=session->open(player,file,{0,0,0,0});check(stream.status==s::Status::completed);bool ready=false;
        for(unsigned i=0;i<100000;++i){check(session->service(0)==s::Status::completed);if(session->inspect(stream.key).evidence.output.channel[0].samples>=512){ready=true;break;}std::this_thread::yield();}check(ready);
        auto source=std::make_shared<n::audio::SessionSource>(session,stream.key,std::make_shared<Tick>());auto clock=n::Context::create(config(source));auto frames=n::VideoFrames::create(clock,2);auto a=std::make_shared<Surface>(),b=std::make_shared<Surface>();
        const auto first=publish(frames,{0,48000},a);const auto second=publish(frames,{1600,48000},b);check(frames->acquire().key==first && frames->release(first)==n::FrameStatus::completed);
        check(control(clock,n::Operation::pause,1).status==n::Status::completed && frames->acquire().status==n::FrameStatus::held);
        const auto consumed=session->inspect(stream.key).evidence.output.channel[0].consumed_bytes;check(device->step(64));check(session->inspect(stream.key).evidence.output.channel[0].consumed_bytes==consumed);
        const auto visits=session->snapshot().group_visits;check(control(clock,n::Operation::pause,2).status==n::Status::completed && session->snapshot().group_visits==visits+1 && frames->acquire().key==second);
        check(frames->present(second)==n::FrameStatus::completed && frames->release(second)==n::FrameStatus::completed && frames->close()==n::FrameStatus::pending);
        b->read_complete=true;check(frames->poll()==n::FrameStatus::completed && control(clock,n::Operation::pause,0).status==n::Status::completed);
        check(session->inspect(stream.key).evidence.clock.paused==0);check(session->join()==s::Status::completed && device->unloaded && !slot->occupied());check(clock->detach_queries()==n::Status::completed);
    }
    std::printf("%u native video ownership/clock/audio/fence checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
