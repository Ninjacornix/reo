#include "session_source.hpp"
#include <bit>
#include <stdexcept>
#include <utility>
namespace reo::native::movie_audio_clock {
namespace {
ProviderStatus map(adxt_control_session::Status value)noexcept{
    using S=adxt_control_session::Status;
    if(value==S::completed)return ProviderStatus::completed;
    if(value==S::busy)return ProviderStatus::busy;
    if(value==S::closed)return ProviderStatus::closed;
    if(value==S::invalid_key)return ProviderStatus::invalid_key;
    return ProviderStatus::fault;
}
}
SessionSource::SessionSource(std::shared_ptr<adxt_control_session::Session> session,adxt_control_session::Key key,std::shared_ptr<ServiceTick> tick)
    :session_(std::move(session)),key_(key),tick_(std::move(tick)){
    if(!session_ || !tick_)throw std::invalid_argument("Owned ADXT session and service-tick provider required");
}
ProviderStatus SessionSource::status(std::uint8_t& output)noexcept {
    if(session_->snapshot().closing)return ProviderStatus::closed;
    const auto value=session_->inspect(key_);
    if(value.status!=adxt_control_session::Status::completed)return map(value.status);
    if(value.evidence.stop_requested || value.evidence.retired)return ProviderStatus::closed;
    if(value.evidence.fault)return ProviderStatus::fault;
    output=value.evidence.clock_observation.state;return ProviderStatus::completed;
}
ProviderStatus SessionSource::estimate(Words& output)noexcept {
    std::uint8_t phase{};const auto admitted=status(phase);
    if(admitted!=ProviderStatus::completed)return admitted;
    std::uint32_t tick{};const auto sampled=tick_->read(tick);
    if(sampled!=ProviderStatus::completed)return sampled;
    const auto value=session_->estimate(key_,tick);
    if(value.status!=adxt_control_session::Status::completed)return map(value.status);
    if(value.value.result.status!=adxt_estimated_clock::Status::completed)return ProviderStatus::fault;
    output={value.value.result.ratio.numerator,value.value.result.ratio.denominator};return ProviderStatus::completed;
}
ProviderStatus SessionSource::sample_frequency(std::uint32_t& output)noexcept {
    std::uint8_t phase{};const auto admitted=status(phase);if(admitted!=ProviderStatus::completed)return admitted;
    const auto value=session_->inspect(key_);if(value.status!=adxt_control_session::Status::completed)return map(value.status);
    output=std::bit_cast<std::int8_t>(phase)<2?0:value.evidence.clock_observation.frequency;return ProviderStatus::completed;
}
ProviderStatus SessionSource::pause(std::uint32_t argument)noexcept {
    std::uint8_t phase{};const auto admitted=status(phase);if(admitted!=ProviderStatus::completed)return admitted;
    std::uint32_t tick{};const auto sampled=tick_->read(tick);if(sampled!=ProviderStatus::completed)return sampled;
    const auto value=session_->pause(key_,std::bit_cast<std::int32_t>(argument),tick);
    if(value.status!=adxt_control_session::Status::completed)return map(value.status);
    return value.value.result==adxt_estimated_clock::Status::completed?ProviderStatus::completed:ProviderStatus::fault;
}
ProviderStatus SessionSource::discard(std::uint32_t,std::uint32_t& output)noexcept {
    std::uint8_t phase{};const auto admitted=status(phase);if(admitted!=ProviderStatus::completed)return admitted;
    std::uint32_t tick{};const auto sampled=tick_->read(tick);if(sampled!=ProviderStatus::completed)return sampled;
    const auto value=session_->discard_rebase(key_,tick);
    if(value.status!=adxt_control_session::Status::completed)return map(value.status);
    if(value.value.result!=adxt_estimated_clock::Status::completed)return ProviderStatus::fault;
    output=0;return ProviderStatus::completed;
}
}
