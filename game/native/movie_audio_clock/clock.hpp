#pragma once
#include "../movie_audio_filter/filter.hpp"
#include "../movie_selected_clock/clock.hpp"
#include <memory>

namespace reo::native::movie_audio_clock {
namespace filter=movie_audio_filter;
namespace selected=movie_selected_clock;
using Words=selected::Words;
enum class ProviderStatus {completed,busy,closed,invalid_key,fault};
class AudioSource {
public:
    virtual ~AudioSource()=default;
    virtual ProviderStatus status(std::uint8_t&) noexcept=0;
    virtual ProviderStatus estimate(Words&) noexcept=0;
};
class HelperClock {
public:
    virtual ~HelperClock()=default;
    virtual ProviderStatus counter(std::uint64_t&) noexcept=0;
    virtual ProviderStatus frequency(std::uint64_t&) noexcept=0;
};
enum class Operation {slot,envelope};
enum class Status {completed,busy,provider_failure,filter_failure,invalid_input};
enum class Stage {none,audio_status,audio_estimate,helper_counter,helper_frequency,filter};
struct State {
    filter::State filter;
    Words cache{0,1};
    std::uint32_t diagnostic{};
    bool filter_observed{};
};
struct Health {
    Status status{Status::completed};
    Stage stage{Stage::none};
    ProviderStatus provider{ProviderStatus::completed};
    filter::Status filter{filter::Status::completed};
};
struct Snapshot {State state;Health health;};
struct Result {
    Status status{Status::invalid_input};
    Words words;
    bool written{},return_defined{};
    std::uint32_t callback_status{};
};
// One serialized control owner. Providers must not destroy this Clock or change
// its state during a query; nested execute is refused before effects. Provider
// samples may advance their own state even when a later stage fails.
class Clock final:public selected::Query {
public:
    Clock(State,std::shared_ptr<AudioSource>,std::shared_ptr<HelperClock>);
    Clock(const Clock&)=delete;Clock& operator=(const Clock&)=delete;
    [[nodiscard]] Result execute(Operation,std::uint32_t actual,Words prior) noexcept;
    selected::Reply query(selected::State snapshot,Words prior) noexcept override;
    [[nodiscard]] Snapshot snapshot()const noexcept{return{state_,health_};}
private:
    State state_;Health health_;
    std::shared_ptr<AudioSource> audio_;
    std::shared_ptr<HelperClock> helper_;
    bool busy_{};
};
}
