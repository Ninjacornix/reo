#include "context.hpp"
#include "../movie_audio_clock/session_source.hpp"
#include "../adxt_shared_player/test_sources.hpp"
#include "../adxt_player/test_provider.hpp"
#include <bit>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <thread>
namespace n=reo::native::movie_timing_context;
namespace session=reo::native::adxt_control_session;
namespace source=reo::native::adxt_shared_player::testing;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Joined timing/source owner check "+std::to_string(checks));}
struct Tick final:n::audio::ServiceTick {n::audio::ProviderStatus read(std::uint32_t& value)noexcept override{value=0;return n::audio::ProviderStatus::completed;}};
struct Helper final:n::audio::HelperClock {
    std::uint64_t value{};
    n::audio::ProviderStatus counter(std::uint64_t& result)noexcept override{result=value;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus frequency(std::uint64_t& result)noexcept override{result=576000;return n::audio::ProviderStatus::completed;}
};
struct Ports final:n::Ports {n::Reply call(n::pause::Call,const n::View&)noexcept override{return{};}};
int main(){try{
    auto slot=std::make_shared<reo::audio_output::CallbackSlot>();auto provider=std::make_shared<reo::native::adxt_player::testing::Provider>();
    auto audio_session=std::make_shared<session::Session>(session::Config{},slot,provider);check(audio_session->start()==session::Status::completed);
    const auto file=source::file(1,48000,120000);session::player::Config player;player.decoder.source_config.byte_length=static_cast<std::int32_t>(file->size());
    const auto opened=audio_session->open(player,file,{0,0,0,0});check(opened.status==session::Status::completed);
    bool ready=false;
    for(unsigned count=0;count<100000;++count){check(audio_session->service(0)==session::Status::completed);const auto value=audio_session->inspect(opened.key);
        if(value.evidence.output.voice.playing && value.evidence.output.channel[0].samples>=512){ready=true;break;}std::this_thread::yield();}
    check(ready);
    auto helper=std::make_shared<Helper>();auto bound=std::make_shared<n::audio::SessionSource>(audio_session,opened.key,std::make_shared<Tick>());
    n::Config config;config.audio=bound;config.helper=helper;config.ports=std::make_shared<Ports>();
    auto context=n::Context::create(std::move(config));bound.reset();check(provider->step(512));
    const auto expected=audio_session->estimate(opened.key,0);check(expected.status==session::Status::completed);helper->value=19200;
    const auto sampled=context->execute(n::Operation::refresh);const auto view=context->snapshot();
    check(sampled.status==n::Status::completed && view.audio.filter_observed);
    const auto expected_numerator=static_cast<std::uint64_t>(static_cast<std::int64_t>(std::bit_cast<std::int32_t>(expected.value.result.ratio.numerator)));
    check(view.audio.filter.previous_input.numerator==expected_numerator && view.audio.filter.previous_input.denominator==expected.value.result.ratio.denominator);
    check(view.clock.cached.numerator==view.audio.cache.numerator && view.clock.cached.denominator==view.audio.cache.denominator);
    check(context->execute(n::Operation::tick).status==n::Status::completed && context->snapshot().clock.active_counter==1000);
    bool retired=false;
    for(unsigned count=0;count<100000;++count){const auto value=audio_session->retire(opened.key);if(value.status==session::Status::completed){check(value.source_joined);retired=true;break;}check(value.status==session::Status::pending);std::this_thread::yield();}
    check(retired);const auto before=context->snapshot();const auto refused=context->execute(n::Operation::tick);const auto after=context->snapshot();
    check(refused.status==n::Status::provider_failure && after.audio_health.provider==n::audio::ProviderStatus::invalid_key);
    check(after.clock.active_counter==before.clock.active_counter+1000 && after.clock.cached.numerator==before.clock.cached.numerator && after.clock.cached.denominator==before.clock.cached.denominator);
    check(context->detach_queries()==n::Status::completed && audio_session->join()==session::Status::completed && provider->unloaded && !slot->occupied());
    std::weak_ptr<session::Session> retained=audio_session;audio_session.reset();check(!retained.expired());context.reset();check(retained.expired());
    std::printf("%u joined actual source/estimator/filter/controller retirement checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
