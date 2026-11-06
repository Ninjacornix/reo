#include "estimated_clock.hpp"
#include <bit>
#include <cfenv>
#include <immintrin.h>
#include <limits>

namespace reo::native::adxt_estimated_clock {
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
std::uint32_t baseline(integer::Ratio raw, std::uint32_t rate) noexcept {
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
    explicit Call(Shared& state) noexcept : shared_(state), csr_(_mm_getcsr()) {
        valid_ = std::fegetenv(&environment_) == 0;
        if (valid_) shared_.in_call = true;
    }
    ~Call() {
        if (valid_) {
            (void)std::fesetenv(&environment_); _mm_setcsr(csr_); shared_.in_call = false;
        }
    }
    [[nodiscard]] bool valid() const noexcept { return valid_; }
private:
    Shared& shared_; std::fenv_t environment_{}; std::uint32_t csr_{}; bool valid_{};
};
bool active(integer::Observation o) noexcept { return o.state == 3 || o.state == 4; }
}
bool supported_fp_environment() noexcept {
    static_assert(sizeof(float) == 4 && std::numeric_limits<float>::is_iec559);
    return std::fegetround() == FE_TONEAREST && (_mm_getcsr() & ~0x3fu) == 0x1f80u;
}
Clock::Clock(Shared& shared, Stream state, Hooks hooks) noexcept : shared_(shared), state_(state), hooks_(hooks) {}
void Clock::event(Event kind) noexcept {
    if (hooks_.observe) hooks_.observe(hooks_.context, kind, state_, shared_);
}
Status Clock::preflight(integer::Observation observation, bool needs_raw, bool needs_ratio) const noexcept {
    if (shared_.in_call) return Status::busy;
    if (!supported_fp_environment()) return Status::unsupported_fp;
    const auto raw = integer::query(integer::Query::decoded_minus_queued, observation);
    if (raw.status != integer::Status::completed) return Status::invalid_queue;
    if ((needs_raw && !raw.ratio.denominator) || (needs_ratio && !shared_.mode.ratio)) return Status::zero_divisor;
    return Status::completed;
}
std::uint32_t Clock::raw_baseline(integer::Observation observation) const noexcept {
    return baseline(integer::query(integer::Query::decoded_minus_queued, observation).ratio, shared_.mode.ratio);
}
integer::Ratio Clock::estimate_impl(integer::Observation observation, std::uint32_t tick) noexcept {
    if (!shared_.mode.selection) return integer::query(integer::Query::decoded_minus_queued, observation).ratio;
    shared_.drift_bits = 0;
    std::uint32_t value = 0;
    if (active(observation)) {
        value = state_.paused ? state_.estimate_base : state_.estimate_base + 100u * (tick - state_.tick_base);
        const auto raw = integer::query(integer::Query::decoded_minus_queued, observation).ratio;
        const float raw_time = signed_float(raw.numerator) / signed_float(raw.denominator);
        const float estimate_time = signed_float(value) / signed_float(shared_.mode.ratio);
        const float delta = raw_time - estimate_time;
        const float drift = delta * 1000.0f;
        shared_.drift_bits = std::bit_cast<std::uint32_t>(drift);
        if (60.0f < drift || drift < -60.0f) {
            if (shared_.rebase_selector == 1) {
                const auto mode = shared_.mode.selection; shared_.mode.selection = 0;
                const auto recursive_raw = estimate_impl(observation, tick);
                shared_.mode.selection = mode; integer::count_resynchronization(shared_.mode);
                state_.estimate_base = baseline(recursive_raw, shared_.mode.ratio);
            } else state_.estimate_base = baseline(raw, shared_.mode.ratio);
            state_.tick_base = tick;
        }
    } else if (observation.state == 5) {
        auto raw = observation; raw.base = raw.offset = 0;
        const auto terminal = integer::query(integer::Query::decoded_minus_queued, raw).ratio;
        float estimate = signed_float(terminal.numerator) / signed_float(terminal.denominator);
        estimate = estimate * signed_float(shared_.mode.ratio);
        value = converted(estimate) + state_.estimate_base + 1u;
    }
    return {value + observation.base, shared_.mode.ratio};
}
Result Clock::estimate(integer::Observation observation, std::uint32_t tick) noexcept {
    const bool uses_fp = shared_.mode.selection && (active(observation) || observation.state == 5);
    const auto status = preflight(observation, uses_fp, shared_.mode.selection && active(observation));
    if (status != Status::completed) return {status, {}, 0};
    Call call(shared_); if (!call.valid()) return {Status::unsupported_fp, {}, 0};
    return {Status::completed, estimate_impl(observation, tick), 0};
}
Result Clock::centiseconds(integer::Observation observation, std::uint32_t tick) noexcept {
    const bool raw = !shared_.mode.selection || active(observation) || observation.state == 5;
    const auto status = preflight(observation, raw, shared_.mode.selection != 0);
    if (status != Status::completed) return {status, {}, 0};
    Call call(shared_); if (!call.valid()) return {Status::unsupported_fp, {}, 0};
    const auto ratio = estimate_impl(observation, tick);
    float seconds = signed_float(ratio.numerator) / signed_float(ratio.denominator);
    seconds = seconds * 100.0f;
    return {Status::completed, ratio, converted(seconds)};
}
Status Clock::pause(integer::Observation observation, std::int32_t argument, std::uint32_t tick) noexcept {
    const auto status = preflight(observation, active(observation), false);
    if (status != Status::completed) return status;
    Call call(shared_); if (!call.valid()) return Status::unsupported_fp;
    if (argument == static_cast<std::int32_t>(std::bit_cast<std::int8_t>(state_.paused))) return Status::completed;
    event(Event::critical_enter); state_.paused = static_cast<std::uint8_t>(argument);
    if (active(observation)) {
        state_.rna_play = argument == 1 ? 0 : 1;
        if (argument != 1) state_.tick_base = tick;
        const auto selection = shared_.mode.selection; shared_.mode.selection = 0;
        const auto raw = estimate_impl(observation, tick); shared_.mode.selection = selection;
        state_.estimate_base = baseline(raw, shared_.mode.ratio);
    }
    event(Event::critical_leave); return Status::completed;
}
Status Clock::discard_rebase(integer::Observation observation, std::uint32_t tick) noexcept {
    if (shared_.in_call) return Status::busy;
    if (state_.paused && !shared_.service_busy) return Status::unsupported_service;
    const auto status = preflight(observation, state_.paused != 0, false);
    if (status != Status::completed) return status;
    Call call(shared_); if (!call.valid()) return Status::unsupported_fp;
    if (!state_.paused) return Status::completed;
    event(Event::discard_diagnostic); event(Event::critical_enter); event(Event::critical_leave);
    const auto selection = shared_.mode.selection; shared_.mode.selection = 0;
    const auto raw = estimate_impl(observation, tick); shared_.mode.selection = selection;
    state_.estimate_base = baseline(raw, shared_.mode.ratio); state_.tick_base = tick;
    return Status::completed;
}
} // namespace reo::native::adxt_estimated_clock
