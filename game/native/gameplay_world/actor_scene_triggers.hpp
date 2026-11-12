#pragma once
#include "world.hpp"
#include "../gameplay_scene/records.hpp"
#include "../gameplay_scenario/scene_matrix_programs.hpp"
namespace reo::native::gameplay_world {
enum class ActorSceneTriggerStatus {completed,unavailable};
struct ActorSceneTriggerReport {ActorSceneTriggerStatus status{ActorSceneTriggerStatus::completed};std::size_t visited{},triggered{};};
// Complete581870 with reached5C1710->5C2F00, on the same canonical proxy,
// channel, room-flag and actor owners. There is no invented visibility gate.
ActorSceneTriggerReport update_actor_scene_triggers(World&,Actor&,gameplay_scene::Records&,gameplay_scenario::SceneMatrixPrograms&,gameplay_scenario::FlagState&)noexcept;
}
