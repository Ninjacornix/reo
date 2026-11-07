#include "prepared_graph.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <stdexcept>
#include <thread>
namespace n=reo::native::movie_lifecycle;
namespace t=reo::native::movie_timing_context;
namespace a=reo::native::adxt_control_session;
namespace r=reo::native::resources;
unsigned checks{};
void check(bool v,const char* detail){++checks;if(!v)throw std::runtime_error(detail);}
template<class F>void until(F done,const char* detail){const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(10);while(!done()){if(std::chrono::steady_clock::now()>deadline)throw std::runtime_error(detail);std::this_thread::yield();}}
struct View final:r::ByteView {
    mutable std::mutex mutex;mutable std::condition_variable cv;mutable bool entered{},released{};bool blocked{};
    std::uint64_t size()const noexcept override{return 4096;}
    r::ReadResult read(std::uint64_t,std::span<std::byte> out)const override{std::unique_lock lock(mutex);entered=true;cv.notify_all();if(blocked)cv.wait(lock,[&]{return released;});std::fill(out.begin(),out.end(),std::byte{0x41});return{r::Status::ok,out.size()};}
    void release(){std::lock_guard lock(mutex);released=true;cv.notify_all();}
    bool active(){std::lock_guard lock(mutex);return entered;}
};
struct Release {std::shared_ptr<View> view;~Release(){view->release();}};
struct Model final:n::Graph {
    bool stopped{},ready{},fault{};unsigned drains{},visits{};std::function<void()> callback;
    n::Status service()noexcept override{++visits;if(callback)callback();return fault?n::Status::provider_failure:n::Status::completed;}
    void request_stop()noexcept override{stopped=true;}
    n::Status poll_retired()noexcept override{return fault?n::Status::provider_failure:ready?n::Status::completed:n::Status::pending;}
    void drain()noexcept override{++drains;stopped=ready=true;}
};
struct Factory final:n::Factory {
    std::vector<std::shared_ptr<Model>> graphs;bool fail{};std::function<void()> callback;
    n::Build construct(const n::Recipe&,std::uint64_t)noexcept override{if(callback)callback();auto graph=std::make_shared<Model>();graphs.push_back(graph);return{fail?n::Status::provider_failure:n::Status::completed,graph};}
};
struct Surface final:t::FrameSurface {
    bool finished{};unsigned drains{};
    t::FrameStatus ready()noexcept override{return t::FrameStatus::completed;}
    t::FrameStatus submit()noexcept override{return t::FrameStatus::completed;}
    t::FrameStatus retire()noexcept override{return finished?t::FrameStatus::completed:t::FrameStatus::pending;}
    void drain()noexcept override{finished=true;++drains;}
};
struct Video final:n::VideoBackend {
    std::shared_ptr<t::VideoFrames> frames;std::shared_ptr<Surface> surface=std::make_shared<Surface>();std::uint64_t fed{};bool ended{},closed{};
    explicit Video(std::shared_ptr<t::Context> clock):frames(t::VideoFrames::create(clock,1)) {const auto reserved=frames->reserve();if(frames->publish(reserved.key,{0,48000},surface)!=t::FrameStatus::completed)throw std::runtime_error("Prepared frame construction");}
    n::Status feed(std::uint64_t at,std::span<const std::byte> bytes)noexcept override{if(at!=fed)return n::Status::provider_failure;fed+=bytes.size();return n::Status::completed;}
    n::Status end()noexcept override{ended=true;return n::Status::completed;}
    n::Status service()noexcept override{return closed?n::Status::closed:n::Status::completed;}
    void request_stop()noexcept override{closed=true;(void)frames->close();}
    n::Status poll_retired()noexcept override{return frames->close()==t::FrameStatus::completed?n::Status::completed:n::Status::pending;}
    void drain()noexcept override{surface->drain();(void)frames->close();}
};
struct Videos final:n::VideoFactory {
    std::vector<std::shared_ptr<Video>> values;std::shared_ptr<t::Context> clock;bool fail{};
    std::shared_ptr<n::VideoBackend> create(std::shared_ptr<t::Context> value,std::uint64_t)override{clock=value;if(fail)throw std::runtime_error("Injected video construction refusal");auto video=std::make_shared<Video>(value);values.push_back(video);return video;}
};
struct Helper final:t::audio::HelperClock {
    t::audio::ProviderStatus counter(std::uint64_t& value)noexcept override{value=0;return t::audio::ProviderStatus::completed;}
    t::audio::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=576000;return t::audio::ProviderStatus::completed;}
};
struct Tick final:t::audio::ServiceTick {t::audio::ProviderStatus read(std::uint32_t& value)noexcept override{value=0;return t::audio::ProviderStatus::completed;}};
struct Ports final:t::Ports {t::Reply call(t::pause::Call,const t::View&)noexcept override{return{};}};
int main(){try{
    {
        auto factory=std::make_shared<Factory>();auto session=n::Session::create(factory);auto view=std::make_shared<View>();
        const auto first=session->open({view,0,view->size()});check(first.status==n::Status::completed,"Construct owned movie graph");
        auto other=n::Session::create(factory);check(other->service(first.key)==n::Status::invalid_key,"Foreign movie key refused");
        check(session->rebuild(first.key)==n::Status::pending && factory->graphs[0]->stopped,"Rebuild signals prior graph stop");
        check(session->service(first.key)==n::Status::closed && session->poll().status==n::Status::pending && factory->graphs.size()==1,"No progress or construction while old graph pending");
        factory->graphs[0]->ready=true;const auto next=session->poll();check(next.status==n::Status::completed && factory->graphs.size()==2,"Replacement follows actual retirement");
        check(session->service(first.key)==n::Status::invalid_key && session->service(next.key)==n::Status::completed,"Fresh generation invalidates old key");
        factory->graphs[1]->fault=true;check(session->service(next.key)==n::Status::provider_failure && session->snapshot().failed,"Service failure closes publication");
        check(session->poll().status==n::Status::provider_failure && session->snapshot().live,"Retirement failure retains graph");
        factory->graphs[1]->fault=false;factory->graphs[1]->ready=true;check(session->poll().status==n::Status::completed,"Retirement failure retry");
        check(session->rebuild(next.key)==n::Status::closed,"Retired key cannot schedule empty rebuild");
        const auto last=session->open({view,0,view->size()});check(last.status==n::Status::completed,"Explicit reopen after stop");
        factory->graphs.back()->callback=[&]{check(session->close()==n::Status::busy,"Callback-time close refused");};
        check(session->service(last.key)==n::Status::completed,"Reentry leaves live graph intact");factory->graphs.back()->ready=true;
        check(session->close()==n::Status::completed && session->open({view,0,view->size()}).status==n::Status::closed,"Final close rejects reopen");
    }
    {
        auto factory=std::make_shared<Factory>();factory->fail=true;auto owner=n::Session::create(factory);auto view=std::make_shared<View>();
        check(owner->open({view,0,view->size()}).status==n::Status::provider_failure && owner->snapshot().live,"Partial construction retains graph");
        check(owner->poll().status==n::Status::pending,"Partial construction waits for retirement");factory->graphs.back()->ready=true;
        check(owner->poll().status==n::Status::completed,"Partial graph retires before retry");factory->fail=false;
        factory->callback=[&]{check(owner->open({view,0,view->size()}).status==n::Status::busy,"Factory-time recursive open refused");};
        const auto run=owner->open({view,0,view->size()});factory->callback={};check(run.status==n::Status::completed,"Construct retry");
        auto raw=owner.get();factory->graphs.back()->callback=[&]{owner.reset();};check(raw->service(run.key)==n::Status::completed && factory->graphs.back()->drains==1,"Owner retained through callback and destructor drains");
    }
    {
        auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto audio=std::make_shared<a::Session>(a::Config{},slot,provider);check(audio->start()==a::Status::completed,"Native shared audio device model started");
        auto adx=reo::native::adxt_shared_player::testing::file(1,48000,120000);n::AudioRoute route;route.session=audio;route.input=adx;route.tick=std::make_shared<Tick>();route.player.decoder.source_config.byte_length=static_cast<std::int32_t>(adx->size());
        auto videos=std::make_shared<Videos>();n::GraphConfig config;config.video=videos;config.audio=route;config.clock.helper=std::make_shared<Helper>();config.clock.ports=std::make_shared<Ports>();config.clock.audio_commands=t::AudioCommands{};config.clock.buffering=t::Buffering{};config.clock.buffering->audio=1;
        auto factory=std::make_shared<n::PreparedFactory>(config);auto owner=n::Session::create(factory);auto view=std::make_shared<View>();view->blocked=true;
        auto first=owner->open({view,0,view->size()});check(first.status==n::Status::completed && audio->snapshot().records==1,"Actual audio/timing/source/video graph constructed");Release release{view};
        check(owner->service(first.key)==n::Status::pending,"Actual native positioned source read submitted");until([&]{return view->active();},"Source worker did not enter");
        check(owner->rebuild(first.key)==n::Status::pending && owner->poll().status==n::Status::pending,"Blocked source plus pending render fence retain old generation");
        check(videos->values.size()==1 && !videos->clock->snapshot().detached,"No early replacement or timing detach");view->release();
        for(unsigned i=0;i<100;++i){check(owner->poll().status==n::Status::pending,"Real source join cannot bypass renderer obligation");std::this_thread::yield();}
        videos->values[0]->surface->finished=true;n::Open second;until([&]{second=owner->poll();check(second.status==n::Status::pending || second.status==n::Status::completed,"Composed retirement status");return second.status==n::Status::completed;},"Prepared graph rebuild retirement");
        check(videos->values.size()==2 && audio->snapshot().records==1 && owner->service(first.key)==n::Status::invalid_key,"Fresh graph and audio incarnation after old work completes");
        until([&]{const auto value=owner->service(second.key);check(value==n::Status::completed || value==n::Status::pending,"Composed source/audio service");return videos->values.back()->ended;},"Positioned source feed/end");
        check(videos->values.back()->fed==view->size(),"Source bytes fed exactly once");videos->values.back()->surface->finished=true;
        until([&]{return owner->close()==n::Status::completed;},"Prepared final close");
        check(audio->snapshot().records==0 && slot->occupied() && !provider->unloaded,"Movie close retains shared device but retires its voice");
        videos->fail=true;auto failed=n::Session::create(factory);check(failed->open({view,0,view->size()}).status==n::Status::provider_failure,"Video construction failure unwinds actual native audio/source");
        check(failed->snapshot().live && failed->snapshot().closing,"Failed construction retains the actual partial graph for retry");
        until([&]{const auto status=failed->poll().status;check(status==n::Status::pending || status==n::Status::completed,"Partial native graph retirement retry");return status==n::Status::completed;},"Partial graph retirement");
        check(audio->snapshot().records==0,"Constructor rollback retired opened audio voice");
        until([&]{return audio->join()==a::Status::completed;},"Shared audio final join");check(provider->unloaded && !slot->occupied(),"Final audio provider retirement");
    }
    std::printf("%u native lifecycle ownership/source/audio/video checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
