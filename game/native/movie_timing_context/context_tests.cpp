#include "context.hpp"
#include <array>
#include <cstdio>
#include <stdexcept>
#include <string>
namespace n=reo::native::movie_timing_context;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Timing context boundary check "+std::to_string(checks));}
struct Data {
    std::weak_ptr<n::Context> context;std::shared_ptr<n::Context>* external{};
    std::array<unsigned,32> depths{};unsigned count{},failure{};
    bool nested{},drop{},retention_missing{},busy_observe{},busy_detach{},busy_tick{};n::Result nested_result;
    void depth()noexcept{if(count<depths.size())depths[count++]=context.lock()->snapshot().guard.depth;}
};
struct Audio final:n::audio::AudioSource {
    Data& data;explicit Audio(Data& value):data(value){}
    n::audio::ProviderStatus status(std::uint8_t& value)noexcept override{value=3;return data.failure==1?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{data.depth();value={1600,48000};return data.failure==2?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
};
struct Helper final:n::audio::HelperClock {
    Data& data;explicit Helper(Data& value):data(value){}
    n::audio::ProviderStatus counter(std::uint64_t& value)noexcept override{data.depth();value=19200;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=576000;return n::audio::ProviderStatus::completed;}
};
struct Hooks final:n::selected::GuardHooks {
    Data& data;explicit Hooks(Data& value):data(value){}
    void enter(std::uint32_t)noexcept override{data.depth();}
    void leave(std::uint32_t)noexcept override{data.depth();}
};
struct Ports final:n::Ports {
    Data& data;explicit Ports(Data& value):data(value){}
    n::Reply call(n::pause::Call call,const n::View&)noexcept override{
        n::Reply reply;reply.status=1;
        if(call.kind!=n::pause::Kind::command)return reply;
        if(data.drop && data.context.use_count()<2){data.retention_missing=true;reply.provider=n::pause::ProviderStatus::failed;return reply;}
        const auto owner=data.context.lock();
        if(data.drop)data.external->reset();
        n::Updates patch;patch.actual=0;data.busy_observe=owner->observe(patch)==n::Status::busy;
        data.busy_detach=owner->detach_queries()==n::Status::busy;
        data.busy_tick=owner->execute(n::Operation::tick).status==n::Status::busy;
        if(data.nested)data.nested_result=owner->execute(n::Operation::selected);
        return reply;
    }
};
n::Config config(Data& data){
    n::Config result;result.audio=std::make_shared<Audio>(data);result.helper=std::make_shared<Helper>(data);result.ports=std::make_shared<Ports>(data);result.hooks=std::make_shared<Hooks>(data);return result;
}
struct RawQuery final:n::selected::Query {
    n::selected::Reply reply;n::selected::Clock* owner{};bool busy_patch{};
    n::selected::Reply query(n::selected::State,n::Words)noexcept override{n::selected::ControlUpdate update;update.actual=0;busy_patch=owner->update(update)==n::selected::Status::busy;return reply;}
};
int main(){try{
    {
        Data data;data.nested=true;auto owner=n::Context::create(config(data));data.context=owner;
        const auto result=owner->execute(n::Operation::buffer);const auto after=owner->snapshot();
        check(result.status==n::Status::completed && data.nested_result.status==n::Status::completed);
        check(data.busy_observe && data.busy_detach && data.busy_tick);
        const std::array<unsigned,6> depths{0,1,2,2,1,0};check(data.count==depths.size());
        for(unsigned i=0;i<depths.size();++i)check(data.depths[i]==depths[i]);
        check(after.guard.depth==0 && after.guard.tag==0 && after.facts.buffering==1 && after.facts.depth==1 && after.facts.actual==4);
        n::Updates bad;bad.actual=6;bad.selector=3;check(owner->observe(bad)==n::Status::invalid_input && owner->snapshot().facts.actual==4);
        bad.selector.reset();bad.rate=9;check(owner->observe(bad)==n::Status::invalid_input && owner->snapshot().facts.actual==4);
    }
    {
        Data data;data.nested=true;auto input=config(data);input.facts.selector=1;input.facts.pause=1;input.facts.depth=1;
        auto owner=n::Context::create(std::move(input));data.context=owner;n::Input request;request.value=2;
        check(owner->execute(n::Operation::pause,request).status==n::Status::completed);
        // Independent original frame-step workflow: 48000*1000/29970.
        check(data.nested_result.words.numerator==1601 && data.nested_result.words.denominator==48000);
        check(owner->snapshot().clock.active_counter==1601 && owner->snapshot().clock.elapsed_counter==1600);
    }
    {
        Data data;data.failure=2;auto owner=n::Context::create(config(data));data.context=owner;
        check(owner->execute(n::Operation::refresh).status==n::Status::provider_failure);
        const auto before=owner->snapshot();check(before.clock.cached.numerator==0xFFFFFFFBu && before.facts.pending==0 && !before.audio.filter_observed);
        const auto failed=owner->execute(n::Operation::tick);const auto after=owner->snapshot();
        check(failed.status==n::Status::provider_failure && !failed.return_defined && after.clock.active_counter==1000);
        check(after.clock.cached.numerator==0xFFFFFFFBu && after.facts.pending==0 && after.guard.depth==0 && after.audio_health.stage==n::audio::Stage::audio_estimate);
        data.failure=0;check(owner->execute(n::Operation::refresh).status==n::Status::completed);
        const auto cached=owner->snapshot().clock.cached;data.failure=1;
        check(owner->execute(n::Operation::selected).status==n::Status::provider_failure);
        const auto old_cache=owner->execute(n::Operation::cached);
        check(old_cache.status==n::Status::completed && old_cache.words.numerator==cached.numerator && owner->snapshot().audio_health.status==n::audio::Status::provider_failure);
        check(owner->detach_queries()==n::Status::completed);const auto counter=owner->snapshot().clock.active_counter;
        check(owner->execute(n::Operation::tick).status==n::Status::detached && owner->observe({})==n::Status::detached && owner->snapshot().clock.active_counter==counter);
    }
    {
        Data data;data.drop=true;data.nested=true;auto owner=n::Context::create(config(data));data.context=owner;data.external=&owner;
        const auto raw=owner.get();n::Input input;input.value=1;const auto result=raw->execute(n::Operation::pause,input);
        check(result.status==n::Status::completed && !data.retention_missing && !owner && data.context.expired());
        check(data.nested_result.status==n::Status::completed && data.busy_observe && data.busy_detach);
    }
    {
        n::selected::Config config;config.state.selector=2;config.state.counter.actual=config.state.counter.requested=4;config.state.counter.property_47=1;config.state.counter.increment=1000;config.state.counter.elapsed_counter=0xFFFFFFFFu;
        n::selected::Clock clock(config);auto query=std::make_shared<RawQuery>();query->owner=&clock;query->reply.words={77,88};query->reply.status=17;
        check(clock.set_callback(2,query)==n::selected::Status::completed);
        check(clock.execute(n::selected::Operation::refresh,{},{}).status==n::selected::Status::completed && clock.snapshot().state.cached.numerator==77 && query->busy_patch);
        n::selected::ControlUpdate update;update.pending=0;check(clock.update(update)==n::selected::Status::completed);
        query->reply.admitted=false;query->reply.words={999,1000};query->reply.facts.actual=6;
        const auto refused=clock.execute(n::selected::Operation::tick,{},{});const auto after=clock.snapshot();
        check(refused.status==n::selected::Status::provider_failure && !refused.query_status_defined && after.state.cached.numerator==77 && after.state.pending==0);
        check(after.state.counter.active_counter==1000 && after.state.counter.actual==6);
        update={};update.actual=0;update.selector=7;check(clock.update(update)==n::selected::Status::invalid_input && clock.snapshot().state.counter.actual==6);
    }
    std::printf("%u joined timing guard/control/refusal/lifetime checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
