#pragma once
#include "camera_curves.hpp"

namespace reo::native::gameplay_scenario {
// The actual18F7E0 configuration and18F6A0 companion matrices are borrowed
// from their display owner. No guessed resolution or identity substitutes.
struct CameraProjectionContext {
    float horizontal_extent{},vertical_extent{},width{},height{};
    transform_math::Matrix first_transform,second_transform;
};
struct CameraProjectionMatrices {
    transform_math::Matrix perspective,scaled,first_composite,second_composite;
};
CameraProjectionMatrices camera_projection(const CameraProjectionContext&,float far_plane,
                                           float near_plane,float vertical_radians,float aspect);
struct CameraViewport {
    std::int32_t x{},y{},width{},height{},parameter{};
    float scale{};
};
class CameraDisplaySink {
public:
    virtual ~CameraDisplaySink()=default;
    virtual void viewport(const CameraViewport&,const CameraProjectionMatrices&)=0;
    virtual void view(const transform_math::Matrix&)=0;
};
struct CameraDisplayState {
    CameraViewport viewport;
    CameraProjectionMatrices projection;
    transform_math::Matrix view;
};
// Complete375920 CPU state and ordered renderer boundary: viewport publication
// precedes view construction/publication. The required sink is an explicit
// Stage5 consumer, never a successful default renderer implementation.
void publish_camera_display(CameraParameters&,std::int8_t display_mode,
                            const CameraProjectionContext&,CameraDisplayState&,CameraDisplaySink&);
} // namespace reo::native::gameplay_scenario
