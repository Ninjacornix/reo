#pragma once
#include "execution.hpp"
namespace reo::native::gameplay_world {struct Actor;}
namespace reo::native::gameplay_scenario {class SceneResources;}
namespace reo::native::gameplay_navigation {class Bank;}
namespace reo::native::gameplay_session {class Random;}
namespace reo::native::gameplay_ai {
struct GoalResourceSelection {Status status{Status::unavailable};std::optional<std::uint8_t> selected;};
// Complete825CC0: character7 selects a descriptor ID from exact canonical
// inventory positions. This is a read-only selection, not transfer/consumption.
GoalResourceSelection select_character_seven_resource(const gameplay_world::Actor&,const gameplay_world::Actor&,const gameplay_scenario::SceneResources&)noexcept;
bool actor_target_busy(const gameplay_world::Actor&)noexcept; // complete823190
struct GoalReevaluated {Status status{Status::unavailable};bool goal_written{};};
// Complete8133D0 within known canonical actor/graph/resource state. Reference
// and companion are checked only when their original fields are actually read.
GoalReevaluated reevaluate_goal(gameplay_world::Actor&,const gameplay_world::Actor* reference,
    const gameplay_world::Actor* companion,const gameplay_navigation::Bank&,
    const gameplay_scenario::SceneResources&)noexcept;

struct GoalDispatched {
    Status status{Status::unavailable};
    std::optional<std::uint16_t> selected;
};
// 813330 for the admitted direct goals 0, 6 and 14. These handlers return zero
// to the outer dispatcher. Other goal families still require native handlers.
GoalDispatched dispatch_goal(gameplay_world::Actor&, const gameplay_world::Actor* reference,
    const gameplay_world::Actor* companion, const gameplay_navigation::Bank&,
    const gameplay_scenario::SceneResources&, gameplay_session::Random&) noexcept;
}
