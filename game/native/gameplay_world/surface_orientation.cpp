#include "surface_orientation.hpp"
#include "surface_orientation_math.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
namespace math=surface_math;
float finite(float v){if(!std::isfinite(v))throw std::domain_error("Native actor surface finite arithmetic required");return v;}
template<class V>math::Vector vector(const V& v){return{v.x,v.y,v.z};}
transform_math::Matrix matrix(const gameplay_collision::actors::Basis& b){return{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
auto basis(const transform_math::Matrix& m){return gameplay_collision::actors::Basis{{m[0][0],m[0][1],m[0][2]},{m[1][0],m[1][1],m[1][2]},{m[2][0],m[2][1],m[2][2]},{m[3][0],m[3][1],m[3][2]}};}
float absolute(float v){return v<0?-v:v;}
}
SurfaceOrientationResult update_surface_orientation(World& world,Actor& actor,SurfaceOrientationFloors& floors){
    if((actor.category==0||actor.category==1)&&(actor.status&8)&&!(actor.action_flags&1)){
        actor.action_flags|=1;actor.surface_blend_rate=std::bit_cast<float>(0x3dcccccdu);
    }
    if(!(actor.action_flags&1))return SurfaceOrientationResult::not_requested;
    transform_math::require_profile();
    actor.surface_blend_weight=finite(actor.surface_blend_weight+actor.surface_blend_rate);
    if(actor.surface_blend_rate<=0){if(actor.surface_blend_weight<0)actor.surface_blend_weight=0;}
    else if(!(actor.surface_blend_weight<=1))actor.surface_blend_weight=1;
    const auto yaw=std::bit_cast<std::uint16_t>(actor.orientation[1]);
    std::array<math::Vector,3> points{math::rotate_probe({0,0,-40},yaw),math::rotate_probe({0,0,40},std::uint16_t(yaw-0x71c)),math::rotate_probe({0,0,40},std::uint16_t(yaw+0x71c))};
    // All translated coordinates precede the first observable floor call.
    for(auto& p:points){p.x=finite(p.x+actor.position.x);p.y=finite(p.y+actor.position.y);p.z=finite(p.z+actor.position.z);}
    for(auto& p:points)p.y=finite(floors.sample(world,actor,{p.x,p.y,p.z}).height);
    const auto difference=[&](unsigned i){return math::Vector{finite(points[i].x-points[0].x),finite(points[i].y-points[0].y),finite(points[i].z-points[0].z)};};
    const auto normal=math::cross(difference(1),difference(2));
    const auto reject=[&]{actor.action_flags&=std::uint16_t(~std::uint16_t(1));actor.surface_blend_weight=0;return SurfaceOrientationResult::processed;};
    if(!(absolute(finite(points[0].y-points[2].y))<=80))return reject();
    if(!(absolute(finite(points[0].y-points[1].y))<=80))return reject();
    if(!(math::dot(vector(actor.surface_normal),{0,1,0})<=math::turn_cosine(0x100)))return reject();
    auto next=math::normal_basis(normal,vector(actor.candidate_direction));
    auto old=matrix(actor.collision.basis);
    for(unsigned i=0;i<3;++i){next[3][i]=0;old[3][i]=0;}
    const float weight=finite(actor.surface_blend_weight);
    actor.collision.basis=basis(math::blend_basis(old,next,finite(1-weight),weight));
    return SurfaceOrientationResult::processed;
}
gameplay_collision::response::Floor GridSurfaceOrientation::sample(World&,Actor&,gameplay_collision::Vec3 p){return grid_.floor(p,255);}
void GridSurfaceOrientation::orient_surface(World& world,Actor& actor){(void)update_surface_orientation(world,actor,*this);}
} // namespace reo::native::gameplay_world
