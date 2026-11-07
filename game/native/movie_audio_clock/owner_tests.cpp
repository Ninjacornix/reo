#include "session_source.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <cstdio>
#include <stdexcept>
#include <string>
#include <thread>
namespace n=reo::native::movie_audio_clock;
namespace c=reo::native::adxt_control_session;
namespace source=reo::native::adxt_shared_player::testing;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Bound movie/audio owner check "+std::to_string(checks));}
struct Tick final:n::ServiceTick {
    unsigned calls{};std::uint32_t value{};
    n::ProviderStatus read(std::uint32_t& result)noexcept override{++calls;result=value;return n::ProviderStatus::completed;}
};
struct Helper final:n::HelperClock {
    unsigned calls{};
    n::ProviderStatus counter(std::uint64_t& result)noexcept override{++calls;result=123456789;return n::ProviderStatus::completed;}
    n::ProviderStatus frequency(std::uint64_t& result)noexcept override{++calls;result=576000;return n::ProviderStatus::completed;}
};
int main(){try{
    auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    auto session=std::make_shared<c::Session>(c::Config{},slot,provider);check(session->start()==c::Status::completed);
    auto file=source::file(1,48000,120000);c::player::Config pc;pc.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
    const auto opened=session->open(pc,file,{0,0,0,0});check(opened.status==c::Status::completed);
    bool ready=false;
    for(unsigned count=0;count<100000;++count){
        check(session->service(0)==c::Status::completed);
        const auto value=session->inspect(opened.key);
        if(value.evidence.output.voice.playing && value.evidence.output.channel[0].samples>=512){ready=true;break;}
        std::this_thread::yield();
    }
    check(ready);
    auto tick=std::make_shared<Tick>();auto helper=std::make_shared<Helper>();
    auto bound=std::make_shared<n::SessionSource>(session,opened.key,tick);
    std::uint8_t status{};check(bound->status(status)==n::ProviderStatus::completed && status==session->inspect(opened.key).evidence.clock_observation.state);
    const auto expected=session->estimate(opened.key,0);check(expected.status==c::Status::completed);
    n::State state;state.filter.enabled=0;state.cache={0x80000000u,123};
    n::Clock owner(state,bound,helper);
    const auto result=owner.execute(n::Operation::slot,4,{77,88});
    check(result.status==n::Status::completed && result.written && result.words.numerator==expected.value.result.ratio.numerator && result.words.denominator==expected.value.result.ratio.denominator);
    check(tick->calls==1 && helper->calls==2 && !owner.snapshot().state.filter_observed);
    const auto cached=owner.snapshot().state.cache;const auto retained=owner.execute(n::Operation::slot,static_cast<std::uint32_t>(-4),{77,88});
    check(retained.words.numerator==cached.numerator && retained.words.denominator==cached.denominator && tick->calls==1 && helper->calls==2);
    auto other_slot=std::make_shared<reo::audio_output::CallbackSlot>();auto other_provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    auto other=std::make_shared<c::Session>(c::Config{},other_slot,other_provider);
    n::SessionSource foreign(other,opened.key,tick);n::Words untouched{77,88};status=123;
    check(foreign.status(status)==n::ProviderStatus::invalid_key && status==123);
    check(foreign.estimate(untouched)==n::ProviderStatus::invalid_key && untouched.numerator==77 && untouched.denominator==88);
    bool retired=false;
    for(unsigned count=0;count<100000;++count){const auto value=session->retire(opened.key);
        if(value.status==c::Status::completed){check(value.source_joined);retired=true;break;}
        check(value.status==c::Status::pending);std::this_thread::yield();
    }
    check(retired);
    const auto ticks=tick->calls;const auto before=owner.snapshot().state;
    const auto stale=owner.execute(n::Operation::slot,4,{77,88});
    check(stale.status==n::Status::provider_failure && !stale.written && stale.words.numerator==77 && owner.snapshot().health.provider==n::ProviderStatus::invalid_key);
    check(tick->calls==ticks && owner.snapshot().state.filter==before.filter && owner.snapshot().state.cache.numerator==before.cache.numerator);
    std::weak_ptr<c::Session> held=session;session.reset();check(!held.expired());
    check(held.lock()->join()==c::Status::completed && provider->unloaded && !slot->occupied());
    check(other->join()==c::Status::completed);
    std::printf("%u actual source/decoder/estimator/movie-cache ownership checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
