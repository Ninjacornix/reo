#include "camera_projection.hpp"
#include <bit>
#include <cmath>
#include <limits>
namespace reo::native::gameplay_scenario {
namespace {
float quotient(float numerator,float denominator){
    if(denominator==0.0f)return std::copysign(std::numeric_limits<float>::max(),
        std::signbit(numerator)!=std::signbit(denominator)?-1.0f:1.0f);
    return numerator/denominator;
}
transform_math::Matrix projection_product(const transform_math::Matrix& left,const transform_math::Matrix& right){
    // A zero lens is replaced by the original0.001 degree epsilon. In the
    // admitted scalar/SIMD profile its rounded sine can be zero. The scalar
    // quotient saturates, and later products can overflow. These projection
    // buffers preserve those derived infinities/NaNs. The general
    // transform API deliberately admits only finite intermediate matrices.
    transform_math::Matrix result;
    for(unsigned column=0;column<4;++column)for(unsigned row=0;row<4;++row){
        float value=left[0][row]*right[column][0];
        value=value+left[1][row]*right[column][1];
        value=value+left[2][row]*right[column][2];
        result[column][row]=value+left[3][row]*right[column][3];
    }
    return result;
}
}
CameraProjectionMatrices camera_projection(const CameraProjectionContext& context,float far_plane,
                                           float near_plane,float radians,float aspect){
    const auto angle=transform_math::sin_cos(radians*0.5f);
    auto perspective=transform_math::identity();
    perspective[0][0]=quotient(quotient(angle.cosine,angle.sine),aspect);
    perspective[1][1]=quotient(angle.cosine,angle.sine);
    const auto distance=far_plane-near_plane;
    perspective[2][2]=quotient(-(far_plane+near_plane),distance);perspective[2][3]=-1.0f;
    perspective[3][2]=quotient(-((2.0f*far_plane)*near_plane),distance);perspective[3][3]=0.0f;
    CameraProjectionMatrices result;result.perspective=perspective;result.scaled=perspective;
    const auto vertical=quotient(context.vertical_extent,0.5f*context.height);
    const auto horizontal=quotient(context.horizontal_extent,0.5f*context.width);
    result.scaled[0][0]=quotient(2.0f*result.scaled[0][0],vertical);
    result.scaled[1][1]=quotient(2.0f*result.scaled[1][1],horizontal);
    result.first_composite=projection_product(context.first_transform,perspective);
    result.second_composite=projection_product(context.second_transform,perspective);
    return result;
}
void publish_camera_display(CameraParameters& parameters,std::int8_t mode,
                            const CameraProjectionContext& context,CameraDisplayState& state,CameraDisplaySink& sink){
    if(parameters.lens==0.0f)parameters.lens=std::bit_cast<float>(0x3a83126fu);
    state.viewport.width=mode?512:640;
    state.projection=camera_projection(context,parameters.far_plane,parameters.near_plane,
        std::bit_cast<float>(0x3c8efa35u)*parameters.lens,std::bit_cast<float>(0x3faaaaabu));
    sink.viewport(state.viewport,state.projection);
    state.view=camera_view(parameters.pose);sink.view(state.view);
}
void initialize_camera_display(CameraParameters& parameters,std::int8_t mode,
                               const CameraProjectionContext& context,CameraDisplayState& state,CameraDisplaySink& sink){
    parameters={};parameters.pose.eye={0,0,500};parameters.pose.up={0,1,0};
    parameters.secondary_up={0,1,0};parameters.distance=500;
    parameters.far_plane=50000;parameters.near_plane=1;parameters.lens=27;
    state.viewport={0,0,mode?512:640,448,0,1};
    state.projection=camera_projection(context,parameters.far_plane,parameters.near_plane,
        std::bit_cast<float>(0x3c8efa35u)*parameters.lens,std::bit_cast<float>(0x3faaaaabu));
    sink.viewport(state.viewport,state.projection);
    publish_camera_display(parameters,mode,context,state,sink);
}
} // namespace reo::native::gameplay_scenario
