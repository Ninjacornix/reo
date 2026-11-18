#include "scene_reset.hpp"
namespace reo::native::gameplay_application {
SceneResetStatus reset_scene_models(SceneResetContext context)noexcept{
    auto& world=context.world;
    if(world.closed())return SceneResetStatus::closed;
    if(world.busy())return SceneResetStatus::busy;
    if(!context.inventory.bound_to(world)||!context.bindings.bound_to(context.models)||
       !context.programs.bound_to(context.models,context.bindings))
        return SceneResetStatus::unavailable_owner;
    context.globals.reset();
    if(context.bindings.reset()!=gameplay_scenario::ModelBindingError::none)
        return SceneResetStatus::unavailable_owner;
    context.saved.restore_poses_and_styles(context.models);
    if(context.programs.reset()!=gameplay_scenario::SceneMatrixStatus::completed)
        return SceneResetStatus::unavailable_owner;
    context.modulation.reset();
    context.text.reset_active();
    if(context.inventory.reset_request_gate()!=gameplay_world::InventoryUiStatus::completed)
        return SceneResetStatus::unavailable_owner;
    context.camera.reset_camera_override();
    return SceneResetStatus::completed;
}
} // namespace reo::native::gameplay_application
