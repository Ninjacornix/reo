#pragma once
#include <cstdint>

namespace reo::native::gameplay_actors {
struct HealthState {
    std::int16_t current{}, maximum{};
    std::uint32_t status{};
    std::uint16_t room{};
    std::uint8_t category{}, slot{}, class_marker{};
};
struct HealthSession {
    std::uint8_t selected_actor{};
    std::uint16_t room{};
    bool authority_filter{};
};
class HealthServices {
public:
    virtual ~HealthServices() = default;
    virtual bool authority_filter(HealthSession&) = 0;
    virtual std::int32_t selected_authority(HealthSession&, std::uint8_t) = 0;
    virtual void refresh_class(HealthState&, HealthSession&) = 0;
};
// Numeric mode is the signed low byte; amount is the signed low halfword.
// A zero return is not a general success indication (additions return zero).
std::int8_t adjust_health(HealthState&, std::uint32_t amount, std::uint32_t mode) noexcept;
std::int8_t apply_health(HealthState&, HealthSession&, HealthServices&,
                         std::uint32_t amount, std::uint32_t mode);
} // namespace reo::native::gameplay_actors
