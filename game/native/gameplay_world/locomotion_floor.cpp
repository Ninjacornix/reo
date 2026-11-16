#include "locomotion_floor.hpp"
#include "../transform_math/transform_math.hpp"
#include <bit>
namespace reo::native::gameplay_world {
LocomotionFloor probe_locomotion_floor(const Actor& actor,const gameplay_collision::response::Grid& floors){
    auto yaw=std::uint16_t(actor.orientation[1]);
    if(actor.root_motion_delta.z<0)yaw=std::uint16_t(yaw+0x8000u);
    const float scaled=std::bit_cast<float>(0x40c90fdbu)*float(yaw);
    const auto trig=transform_math::sin_cos(scaled/65536.f);
    //191BC0 preserves the zero products and the original separate multiply/add.
    const float xx=trig.cosine*0.f,xz=trig.sine*30.f;
    const float zx=(-trig.sine)*0.f,zz=trig.cosine*30.f;
    LocomotionFloor result{{(xx+xz)+actor.position.x,50.f+actor.position.y,(zx+zz)+actor.position.z},255};
    const gameplay_collision::Vec3 point{result.probe.x,result.probe.y,result.probe.z};
    if(floors.floor(point,1).type==1)result.type=1;
    (void)floors.floor(point,255);
    return result;
}
}
