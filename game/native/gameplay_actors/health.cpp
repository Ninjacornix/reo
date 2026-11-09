#include "health.hpp"
#include <bit>

namespace reo::native::gameplay_actors {
namespace {
std::int16_t narrow(std::int32_t value) noexcept {
    return std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(value));
}
}
std::int8_t adjust_health(HealthState& actor, std::uint32_t amount,
                          std::uint32_t mode) noexcept {
    const auto operation = std::bit_cast<std::int8_t>(std::uint8_t(mode));
    const auto delta = std::bit_cast<std::int16_t>(std::uint16_t(amount));
    if (operation == 0) {
        if (actor.status & 0x400000) return 0;
        actor.current = narrow(std::int32_t(actor.current) - delta);
        if (actor.current <= 0) { actor.current = 0; return 1; }
        if (actor.current > actor.maximum) actor.current = actor.maximum;
    } else if (operation == 1) {
        actor.current = narrow(std::int32_t(actor.current) + delta);
        if (actor.current > actor.maximum) actor.current = actor.maximum;
    }
    return 0;
}
std::int8_t apply_health(HealthState& actor, HealthSession& session,
                         HealthServices& services, std::uint32_t amount,
                         std::uint32_t mode) {
    if (actor.category == 0) {
        if (actor.slot != session.selected_actor) return 0;
    } else if (actor.category == 1 && services.authority_filter(session)) {
        if (!services.selected_authority(session, session.selected_actor)) return 0;
    }
    const auto result = adjust_health(actor, amount, mode);
    if (actor.room != session.room) {
        if (result == 1) actor.status |= 0x18;
        services.refresh_class(actor, session);
    }
    return result;
}
} // namespace reo::native::gameplay_actors
