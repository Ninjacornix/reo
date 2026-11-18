#pragma once
#include "room_models.hpp"
#include "../gameplay_scenario/scene_reset_state.hpp"
#include "../gameplay_scenario/sequence_control.hpp"
#include "../gameplay_scenario/scene_matrix_programs.hpp"
#include "../gameplay_world/inventory_ui.hpp"
#include "../gameplay_effects/surface_work.hpp"

namespace reo::native::gameplay_application {
enum class SceneResetStatus {completed,busy,closed,unavailable_owner};
// Complete5D7D60 reset of the represented native scene domains. The host passes
// its current canonical owners; this operation creates no pose, binding,
// channel, UI or effect bank. The simulation owner serializes this operation.
struct SceneResetContext {
    gameplay_world::World& world;
    const RoomModels& saved;
    gameplay_scenario::SceneModels& models;
    gameplay_scenario::SceneModelBindings& bindings;
    gameplay_scenario::SceneMatrixPrograms& programs;
    gameplay_effects::Modulation& modulation;
    gameplay_world::InventoryUi& inventory;
    gameplay_scenario::SceneModelGlobals& globals;
    gameplay_scenario::PriorityTextState& text;
    gameplay_scenario::SequenceControl& camera;
};
SceneResetStatus reset_scene_models(SceneResetContext)noexcept;
} // namespace reo::native::gameplay_application
