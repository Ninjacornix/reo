#pragma once
#include "room_camera.hpp"
#include "../gameplay_tasks/tasks.hpp"
#include <memory>

namespace reo::native::gameplay_collision::response {class Grid;}
namespace reo::native::gameplay_scenario {
class SequenceControl;class SceneControls;class SceneModels;class SceneModelBindings;
class Lighting;class RoomSceneInput;class RoomSceneOwner;class Fog;
enum class CameraModeStatus {completed,unavailable,unsupported_numeric,busy,closed};
// 5BE9A0 and its linked 5D9960/5D9790/5D9DD0 tasks. The World, scheduler,
// room scene owner, controls/bindings, lighting and parameter owners are borrowed. Their
// actual room lifetime must outlive this owner and its scheduled tasks.
class RoomCameraModes final {
public:
    RoomCameraModes(gameplay_world::World&,gameplay_tasks::Scheduler&,SequenceControl&,
        CameraParameters&,Lighting&,RoomSceneOwner&,SceneControls&,SceneModels&,SceneModelBindings&,
        std::shared_ptr<const RoomSceneInput>,
        std::shared_ptr<const gameplay_collision::response::Grid>);
    ~RoomCameraModes();
    RoomCameraModes(const RoomCameraModes&)=delete;
    RoomCameraModes& operator=(const RoomCameraModes&)=delete;
    CameraModeStatus update(std::size_t loaded_models,Fog&,CameraDisplayBinding&)noexcept;
    CameraModeStatus status()const noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
    CameraModeStatus close()noexcept;
private:
    struct Shared;class Work;
    std::shared_ptr<Shared> shared_;
};
}
