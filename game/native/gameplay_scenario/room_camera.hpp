#pragma once
#include "camera_projection.hpp"
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_scenario {
class SequenceControl;class SceneModels;class Fog;
enum class RoomCameraStatus {completed,unavailable,unsupported_numeric};
//5BED30 ordinary selection and all authored pose types. Script selection,
// smoothing, mutable anchors, visibility and camera parameters have one owner.
// The caller supplies the actual display boundary; there is no empty sink.
class RoomCamera final {
public:
    RoomCamera(SequenceControl& sequences,CameraParameters& parameters)noexcept:
        sequences_(sequences),parameters_(parameters){}
    RoomCameraStatus update(gameplay_world::World&,SceneModels&,std::size_t loaded_models,
                            Fog&,CameraDisplayBinding&);
private:
    RoomCameraStatus evaluate(std::uint8_t,transform_math::Vector,CameraDisplayBinding&);
    SequenceControl& sequences_;CameraParameters& parameters_;
};
}
