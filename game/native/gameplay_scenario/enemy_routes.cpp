#include "enemy_routes.hpp"
#include <algorithm>
#include <bit>
#include <span>

namespace reo::native::gameplay_scenario {
namespace {
using Path=std::span<const std::int8_t>;
using Paths=std::span<const Path>;
struct ScenarioPaths { std::uint16_t scenario; std::span<const Paths> groups; };
#include "enemy_route_profiles.inc"
}

EnemyRoutePosition EnemyRoutes::position(std::optional<std::uint16_t> scenario,
    std::uint8_t family,std::uint8_t room,std::uint8_t selector) const noexcept {
    const auto requested=std::int32_t(std::bit_cast<std::int8_t>(family));
    const auto match=std::find(classes.begin(),classes.end(),requested);
    if (match==classes.end()) return {true,-1};
    if (room>=128) return {};
    const auto bank=room_banks[std::size_t(match-classes.begin())][room];
    if (bank==65535) return {true,-1};
    if (!scenario) return {};
    const auto source=std::find_if(route_scenarios.begin(),route_scenarios.end(),
        [&](const auto& entry) { return entry.scenario==*scenario; });
    if (source==route_scenarios.end() || bank>=source->groups.size()) return {};
    const auto group=source->groups[bank];
    if (group.empty()) return {true,-1};
    if (selector>=group.size()) return {};
    const auto path=group[selector];
    if (path.empty() || path.front()<0) return {true,-1};
    const auto wanted=std::bit_cast<std::int8_t>(room);
    for (std::size_t index=0;index<path.size() && path[index]>=0;++index)
        if (path[index]==wanted) return {true,std::int8_t(index)};
    return {true,-1};
}
}
