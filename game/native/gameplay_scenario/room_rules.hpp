#pragma once
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_scenario {
class FlagState;
class SceneControls;
enum class RoomRuleStatus {completed,unavailable,budget_exhausted};
// Complete1B3C40 rules. Canonical session/flag/node owners are shared with the
// rest of gameplay; no duplicate scenario/room or actor flag snapshot is held.
RoomRuleStatus apply_scenario_room_rules(gameplay_world::World&,FlagState&,SceneControls&)noexcept;
}
