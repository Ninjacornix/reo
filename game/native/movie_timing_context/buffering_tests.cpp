#include "context.hpp"
#include "buffer_queues.hpp"
#include <cstdio>
#include <stdexcept>
#include <string>
#include <vector>
namespace n=reo::native::movie_timing_context;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Buffering ownership check "+std::to_string(checks));}
struct Audio final:n::audio::AudioSource {
    bool fail{};
    n::audio::ProviderStatus status(std::uint8_t& value)noexcept override{value=3;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{value={1600,48000};return fail?n::audio::ProviderStatus::fault:n::audio::ProviderStatus::completed;}
};
struct Helper final:n::audio::HelperClock {
    n::audio::ProviderStatus counter(std::uint64_t& value)noexcept override{value=19200;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=576000;return n::audio::ProviderStatus::completed;}
};
struct Ports final:n::Ports {
    unsigned commands{},predicates{};std::uint32_t mode{};
    n::Reply call(n::pause::Call call,const n::View&)noexcept override{
        if(call.kind==n::pause::Kind::command){++commands;mode=call.argument;}else ++predicates;return{};
    }
};
struct Hooks final:n::selected::GuardHooks {
    std::weak_ptr<n::Context> owner;std::vector<std::uint32_t> depths;
    void enter(std::uint32_t)noexcept override{depths.push_back(owner.lock()->snapshot().guard.depth);}
    void leave(std::uint32_t)noexcept override{depths.push_back(owner.lock()->snapshot().guard.depth);}
};
struct Refused final:n::BufferQueue {
    std::weak_ptr<n::Context> owner;bool busy{},peek{};
    bool available(std::uint32_t&)noexcept override{return false;}
    bool two_spans(std::array<std::uint32_t,2>&)noexcept override{
        peek=true;const auto context=owner.lock();busy=context->observe_buffering({})==n::Status::busy && context->detach_queries()==n::Status::busy && context->execute(n::Operation::cached).status==n::Status::busy;return false;
    }
};
n::Config config(const std::shared_ptr<Audio>& audio,const std::shared_ptr<Ports>& ports){n::Config value;value.audio=audio;value.helper=std::make_shared<Helper>();value.ports=ports;return value;}
int main(){try{
    auto regions=std::make_shared<std::array<std::vector<std::uint8_t>,3>>();
    for(unsigned i=0;i<3;++i)(*regions)[i].resize(i+3);
    auto pool=std::make_shared<reo::native::sjuni::Pool>(16);
    for(unsigned i=0;i<3;++i)check(pool->put(1,{i+1,0,static_cast<std::int32_t>(i+3)})==reo::native::sjuni::Result::completed);
    std::weak_ptr<reo::native::sjuni::Pool> weak_pool=pool;std::weak_ptr<const void> weak_regions=regions;
    auto queue=std::make_shared<n::UniBufferQueue>(pool,regions);std::uint32_t count{};std::array<std::uint32_t,2> lengths{};
    check(queue->available(count) && count==12);check(queue->two_spans(lengths) && lengths==std::array<std::uint32_t,2>{3,4});
    // Count would report 12; only the first two spans report 7. Borrow/return
    // must preserve order for the next movie consumer, including a third span.
    for(unsigned i=0;i<3;++i){reo::native::sjuni::Span span;check(pool->get(1,0x7FFFFFFF,span)==reo::native::sjuni::Result::completed && span.region==i+1 && span.bytes==static_cast<std::int32_t>(i+3));}
    pool.reset();regions.reset();check(!weak_pool.expired() && !weak_regions.expired());queue.reset();check(weak_pool.expired() && weak_regions.expired());
    auto ring=std::make_shared<reo::native::sjrb::Ring>(10,0);reo::native::sjrb::Chunk span;
    check(ring->get(0,8,span)==reo::native::sjrb::Status::completed && ring->put(1,span)==reo::native::sjrb::Status::completed);
    check(ring->get(1,6,span)==reo::native::sjrb::Status::completed && ring->put(0,span)==reo::native::sjrb::Status::completed);
    check(ring->get(0,5,span)==reo::native::sjrb::Status::completed && ring->put(1,span)==reo::native::sjrb::Status::completed);
    check(ring->get(0,3,span)==reo::native::sjrb::Status::completed && ring->put(1,span)==reo::native::sjrb::Status::completed);
    const auto ring_before=ring->snapshot();n::RingBufferQueue ring_queue(ring);
    check(ring_queue.two_spans(lengths) && lengths==std::array<std::uint32_t,2>{4,3});
    const auto ring_after=ring->snapshot();check(ring_before.data==ring_after.data && ring_before.free==ring_after.free && ring_before.read==ring_after.read && ring_before.write==ring_after.write);
    auto audio=std::make_shared<Audio>();auto ports=std::make_shared<Ports>();auto hooks=std::make_shared<Hooks>();hooks->depths.reserve(64);
    auto input=config(audio,ports);input.hooks=hooks;n::Buffering buffer;buffer.enabled=1;buffer.latest={1000,48000};input.buffering=buffer;
    auto owner=n::Context::create(std::move(input));hooks->owner=owner;
    check(owner->execute(n::Operation::refresh).status==n::Status::completed);
    check(owner->execute(n::Operation::buffer).status==n::Status::completed && owner->snapshot().facts.buffering==1 && ports->commands==1 && ports->mode==1 && ports->predicates==0);
    buffer.latest={2000,48000};check(owner->observe_buffering(buffer)==n::Status::completed);
    check(owner->execute(n::Operation::buffer).status==n::Status::completed && owner->snapshot().facts.buffering==0 && ports->commands==2 && ports->mode==0);
    auto refused=std::make_shared<Refused>();refused->owner=owner;buffer.audio=1;buffer.streams[2].queue=refused;
    check(owner->observe_buffering(buffer)==n::Status::completed);const auto before=owner->snapshot();
    check(owner->execute(n::Operation::buffer).status==n::Status::provider_failure && refused->peek && refused->busy);
    auto after=owner->snapshot();check(after.guard.depth==0 && after.guard.tag==0 && after.facts.buffering==before.facts.buffering && after.facts.episodes==before.facts.episodes && ports->commands==2);
    buffer.audio=0;buffer.video=1;buffer.stalled=1;buffer.video_slot=8;check(owner->observe_buffering(buffer)==n::Status::completed);
    check(owner->execute(n::Operation::buffer).status==n::Status::provider_failure && owner->snapshot().guard.depth==0);
    // Disabled fixed-slot peek performs no queue call. Use a fresh cache so
    // the complete predicate must make its own original cached-clock query.
    buffer.video=0;buffer.audio=1;buffer.streams[2].enabled=0;buffer.latest={1000,48000};check(owner->observe_buffering(buffer)==n::Status::completed);
    auto fresh=config(audio,ports);fresh.buffering=buffer;fresh.hooks=hooks;owner=n::Context::create(std::move(fresh));hooks->owner=owner;audio->fail=true;
    check(owner->execute(n::Operation::buffer).status==n::Status::provider_failure && owner->snapshot().facts.buffering==0 && owner->snapshot().guard.depth==0);
    audio->fail=false;check(owner->execute(n::Operation::buffer).status==n::Status::completed && owner->snapshot().facts.buffering==1);
    check(owner->detach_queries()==n::Status::completed && owner->observe_buffering({})==n::Status::detached);
    std::printf("%u complete buffering/queue ownership checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
