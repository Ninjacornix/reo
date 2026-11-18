#pragma once
#include "../adxt_integer_clock/integer_clock.hpp"
#include <cstdint>

namespace reo::native::adxt_estimated_clock {
namespace integer = adxt_integer_clock;
enum class Status { completed, busy, unsupported_fp, invalid_queue, zero_divisor, unsupported_service };
struct Shared {
    integer::Mode mode;
    std::uint32_t rebase_selector{}, service_busy{}, drift_bits{};
    bool in_call{}; // Reentry detection only; external serialization required.
};
struct Stream {
    std::uint32_t estimate_base{}, tick_base{};
    std::uint8_t paused{}, rna_play{};
    friend bool operator==(const Stream&, const Stream&) = default;
};
enum class Event { critical_enter, critical_leave, discard_diagnostic };
struct Hooks {
    void* context{};
    void (*observe)(void*, Event, Stream, const Shared&) noexcept {};
};
struct Result {
    Status status{Status::completed};
    integer::Ratio ratio;
    std::uint32_t value{};
};

// Independent prepared-observation clock. Shared must outlive this owner. No
// mutable stream reference, real queue/device access, host time or worker exists.
class Clock final {
public:
    Clock(Shared& shared, Stream state, Hooks hooks = {}) noexcept;
    Clock(const Clock&) = delete;
    Clock& operator=(const Clock&) = delete;
    [[nodiscard]] Stream snapshot() const noexcept { return state_; }
    [[nodiscard]] Result estimate(integer::Observation, std::uint32_t tick) noexcept;
    [[nodiscard]] Result centiseconds(integer::Observation, std::uint32_t tick) noexcept;
    [[nodiscard]] Status pause(integer::Observation, std::int32_t argument, std::uint32_t tick) noexcept;
    [[nodiscard]] Status discard_rebase(integer::Observation, std::uint32_t tick) noexcept;
private:
    Shared& shared_; Stream state_; Hooks hooks_;
    void event(Event) noexcept;
    [[nodiscard]] Status preflight(integer::Observation, bool needs_raw, bool needs_ratio) const noexcept;
    [[nodiscard]] integer::Ratio estimate_impl(integer::Observation, std::uint32_t tick) noexcept;
    [[nodiscard]] std::uint32_t raw_baseline(integer::Observation) const noexcept;
};
[[nodiscard]] bool supported_fp_environment() noexcept;
} // namespace reo::native::adxt_estimated_clock
