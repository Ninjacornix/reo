#include "completion.hpp"
#include <bit>
#include <cfenv>
#include <immintrin.h>
#include <stdexcept>
#include <utility>

namespace reo::native::adxt_serviced_clock {
namespace {
float signed_float(std::uint32_t word) noexcept {
    return static_cast<float>(std::bit_cast<std::int32_t>(word));
}
std::uint32_t converted(float value) noexcept {
    const auto bits = std::bit_cast<std::uint32_t>(value);
    const auto exponent = (bits >> 23) & 255u;
    if (exponent > 157u) return bits >> 31 ? 0x80000000u : 0x7fffffffu;
    if (exponent < 127u) return 0;
    const auto shift = exponent - 127u;
    const auto significand = (bits & 0x7fffffu) | 0x800000u;
    const auto magnitude = shift >= 23u ? significand << (shift - 23u) : significand >> (23u - shift);
    return bits >> 31 ? 0u - magnitude : magnitude;
}
std::uint32_t baseline(clock::integer::Ratio raw, std::uint32_t rate) noexcept {
    float value = signed_float(raw.numerator) / signed_float(raw.denominator);
    value = value * signed_float(rate);
    if (2147483648.0f <= value) {
        value = value - 2147483648.0f;
        return converted(value) | 0x80000000u;
    }
    return converted(value);
}
class Call final {
public:
    explicit Call(clock::Shared& shared)noexcept:shared_(shared),csr_(_mm_getcsr()){
        valid_=std::fegetenv(&environment_)==0;if(valid_)shared_.in_call=true;
    }
    ~Call(){if(valid_){(void)std::fesetenv(&environment_);_mm_setcsr(csr_);shared_.in_call=false;}}
    bool valid()const noexcept{return valid_;}
private:
    clock::Shared& shared_;std::fenv_t environment_{};unsigned csr_{};bool valid_{};
};
Status admitted(clock::integer::Observation observation,bool needs_raw)noexcept{
    const auto raw=clock::integer::query(clock::integer::Query::decoded_minus_queued,observation);
    if(raw.status!=clock::integer::Status::completed)return Status::invalid_queue;
    return needs_raw && !raw.ratio.denominator?Status::zero_divisor:Status::completed;
}
}
Completion::Completion(std::shared_ptr<clock::Shared> shared,clock::Stream stream,std::shared_ptr<Service> service)
    :shared_(std::move(shared)),stream_(stream),service_(std::move(service)){
    if(!shared_ || !service_ || service_->clock_identity()!=shared_.get())throw std::invalid_argument("Matching owned service/clock binding required");
}
Status Completion::discard(std::uint32_t tick)noexcept{
    if(shared_->in_call)return Status::busy;
    if(!clock::supported_fp_environment())return Status::unsupported_fp;
    auto observation=service_->observation();const bool paused=stream_.paused!=0;
    const auto preflight=admitted(observation,paused);if(preflight!=Status::completed)return preflight;
    Call call(*shared_);if(!call.valid())return Status::unsupported_fp;
    if(!paused)return Status::completed;
    service_->discard_diagnostic();
    auto fresh=stream_;
    const auto serviced=service_->run_and_refresh(fresh,observation);
    if(serviced==ServiceStatus::failed)return Status::service_failure;
    if(!clock::supported_fp_environment())return Status::unsupported_fp;
    const auto postflight=admitted(observation,true);if(postflight!=Status::completed)return postflight;
    const auto raw=clock::integer::query(clock::integer::Query::decoded_minus_queued,observation);
    fresh.estimate_base=baseline(raw.ratio,shared_->mode.ratio);fresh.tick_base=tick;stream_=fresh;
    return Status::completed;
}
} // namespace reo::native::adxt_serviced_clock
