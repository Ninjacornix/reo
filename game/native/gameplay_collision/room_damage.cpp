#include "room_damage.hpp"
#include <bit>
namespace reo::native::gameplay_collision::delivery {
namespace {
// Four 16-halfword policy rows at 717690 in the File #1 gameplay overlay.
constexpr std::array<std::array<std::int16_t, RoomCounterPolicy::columns>, RoomCounterPolicy::rows> built_in{{
    {700, 900, 1100, 1300, 1500, 1700, 1900, 2100, 2300, 2500, 2700, 3000, 3300, 3600, 4000, 4400},
    {700, 900, 1100, 1300, 1500, 1700, 1900, 2100, 2300, 2500, 2700, 3000, 3300, 3600, 4000, 4400},
    {1100, 1300, 1500, 1700, 1900, 2100, 2300, 2500, 2700, 2900, 3100, 3400, 3700, 4000, 4400, 4800},
    {1500, 1700, 1900, 2100, 2300, 2500, 2700, 2900, 3100, 3300, 3500, 3800, 4100, 4400, 4800, 5200}
}};
}
std::optional<RoomCounterPolicy> RoomCounterPolicy::select(
    std::uint8_t row, const std::optional<ScenarioRows>& scenario) noexcept {
    if (row >= rows) return {};
    RoomCounterPolicy policy(row);
    if (scenario) policy.scenario_ = (*scenario)[row];
    return policy;
}
std::int16_t RoomCounterPolicy::initial_value() const noexcept {
    return built_in[row_][4];
}
std::optional<std::int16_t> RoomCounterPolicy::value(std::int32_t selector) const noexcept {
    if (selector < 100) return built_in[row_][std::uint32_t(selector) & 15];
    if (!scenario_) return {};
    return std::bit_cast<std::int16_t>(std::uint16_t((*scenario_)[(selector - 100) & 15]));
}
bool RoomContacts::initialize_counters(std::uint8_t row,
    const std::optional<RoomCounterPolicy::ScenarioRows>& scenario) noexcept {
    const auto policy = RoomCounterPolicy::select(row, scenario);
    if (!policy) return false;
    counters.reset(policy->initial_value());
    policy_ = policy;
    return true;
}
bool RoomContacts::set_from_policy(std::uint32_t room, std::uint32_t edge, std::int32_t selector) noexcept {
    const auto value = policy_ ? policy_->value(selector) : std::nullopt;
    return value && counters.set(room, edge, *value);
}
void RoomCounters::reset(std::int16_t policy) noexcept {
    for (auto& row : values_)
        row.fill(policy);
}
std::optional<std::int16_t> RoomCounters::get(std::uint32_t room,
                                              std::uint32_t edge) const noexcept {
    if (room >= rooms || edge >= edges)
        return {};
    return values_[room][edge];
}
bool RoomCounters::set(std::uint32_t room, std::uint32_t edge, std::int16_t value) noexcept {
    if (room >= rooms || edge >= edges)
        return false;
    values_[room][edge] = value;
    return true;
}
namespace {
std::int16_t subtract(std::int16_t value, std::int32_t amount) {
    return std::bit_cast<std::int16_t>(
        std::uint16_t(std::uint32_t(std::int32_t(value)) - std::uint32_t(amount)));
}
bool test(std::uint16_t value, std::uint8_t edge) {
    return (value & std::uint16_t(1u << (edge & 31))) != 0;
}
} // namespace
DamageReport apply_route_damage(RoomCounters& counters, RouteFlags& flags, RouteChannels& channels,
                                RouteDamageEffects& effects, const std::uint16_t& current_room,
                                std::uint8_t room, std::uint8_t edge, std::int32_t amount) {
    DamageReport report;
    if (edge >= RoomCounters::edges) {
        report.status = DamageStatus::unadmitted_counter;
        return report;
    }
    if (edge >= 16) {
        const auto before = counters.get(room, edge);
        if (!before) {
            report.status = DamageStatus::unadmitted_counter;
            return report;
        }
        auto value = subtract(*before, amount);
        if (value < 0)
            value = 0;
        counters.set(room, edge, value);
        return report;
    }
    // Original captures the canonical current room before any effect call.
    const auto selected_room = current_room;
    std::optional<ChannelView> channel;
    const auto require_channel = [&]() {
        if (!channel) {
            const auto found = channels.channel(edge);
            if (found)
                channel.emplace(*found);
        }
        return bool(channel);
    };
    if (room == selected_room) {
        if (!require_channel()) {
            report.status = DamageStatus::unavailable_channel;
            return report;
        }
        channel->active = 1;
    }
    const auto protected_mask = flags.half(room, 5);
    if (!protected_mask) {
        report.status = DamageStatus::unadmitted_flags;
        return report;
    }
    if (test(*protected_mask, edge))
        return report;
    const auto closed_mask = flags.half(room, 2);
    if (!closed_mask) {
        report.status = DamageStatus::unadmitted_flags;
        return report;
    }
    if (test(*closed_mask, edge)) {
        if (!counters.set(room, edge, 0)) {
            report.status = DamageStatus::unadmitted_counter;
            return report;
        }
        if (!require_channel()) {
            report.status = DamageStatus::unavailable_channel;
            return report;
        }
        channel->active = 0;
        return report;
    }
    const auto before = counters.get(room, edge);
    if (!before) {
        report.status = DamageStatus::unadmitted_counter;
        return report;
    }
    const auto value = subtract(*before, amount);
    counters.set(room, edge, value);
    if (value > 0)
        return report;
    counters.set(room, edge, 500);
    if (room == selected_room) {
        if (!require_channel()) {
            report.status = DamageStatus::unavailable_channel;
            return report;
        }
        channel->active = 0;
        if (!effects.refresh_channel(edge)) {
            report.status = DamageStatus::provider_failed;
            return report;
        }
        report.refreshed = true;
    }
    if (!flags.bit(room, edge, 0, false) || !flags.bit(room, edge, 3, false))
        report.status = DamageStatus::unadmitted_flags;
    return report;
}
DamageStatus finish_route(RouteFlags& flags, RouteDamageEffects& effects, std::uint32_t room,
                          std::uint32_t edge, std::uint8_t kind) {
    if (!flags.bit(room, edge, kind, true))
        return DamageStatus::unadmitted_flags;
    return effects.notify(room, edge, 1, kind) ? DamageStatus::completed
                                               : DamageStatus::provider_failed;
}
} // namespace reo::native::gameplay_collision::delivery
