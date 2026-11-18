#pragma once
#include "scene_controls.hpp"
#include "scene_models.hpp"
#include "flags.hpp"
#include "../gameplay_world/world.hpp"
namespace reo::native::gameplay_scenario {
enum class SceneEntryRequestStatus {completed,unavailable};
// Complete bounded6F8DD0/6F90B0/6F9440 geometry/request producers. The
// enclosing6F9600 caller owns room publication and812170 reentry afterward.
// Inputs retain their canonical scene/actor/model/flag owners; disabled pools
// and no matching authored record are actual source early returns.
SceneEntryRequestStatus queue_scene_entry_request(gameplay_world::World&,gameplay_world::Actor&,
    SceneControls&,SceneModels&,FlagState&,std::uint32_t entry,std::uint32_t kind)noexcept;
}
