#include "motion_transforms.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
namespace math=transform_math;
template<class V>math::Vector vector(const V& v){return{v.x,v.y,v.z};}
template<class V>void finite_vector(const V& v){
    if(!std::isfinite(v.x)||!std::isfinite(v.y)||!std::isfinite(v.z))
        throw std::domain_error("Native actor transform finite position/delta required");
}
float finite(float value){if(!std::isfinite(value))throw std::domain_error("Native actor transform finite arithmetic required");return value;}
math::Angles angles(const Actor& actor){return{std::bit_cast<std::uint16_t>(actor.orientation[0]),std::bit_cast<std::uint16_t>(actor.orientation[1]),std::bit_cast<std::uint16_t>(actor.orientation[2])};}
math::Matrix matrix(const gameplay_collision::actors::Basis& b){
    return{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};
}
gameplay_collision::actors::Basis basis(const math::Matrix& m){return{{m[0][0],m[0][1],m[0][2]},{m[1][0],m[1][1],m[1][2]},{m[2][0],m[2][1],m[2][2]},{m[3][0],m[3][1],m[3][2]}};}
}
void integrate_local_motion(Actor& actor){
    math::require_profile();finite_vector(actor.position);finite_vector(actor.root_motion_delta);finite(actor.motion_multiplier);
    auto rotation=math::identity();math::reset_euler_axes(rotation,angles(actor));
    if(!(actor.contact_flags&8))math::concatenate_left(rotation,math::scale({actor.model_scale.x,1,actor.model_scale.z}));
    actor.contact_flags&=std::uint16_t(~std::uint16_t(8));
    auto delta=math::direction(rotation,vector(actor.root_motion_delta));
    delta.x=finite(delta.x*actor.motion_multiplier);delta.y=finite(delta.y*actor.motion_multiplier);delta.z=finite(delta.z*actor.motion_multiplier);
    actor.collision.pose_ready=false;
    actor.position.x=finite(actor.position.x+delta.x);
    actor.position.y=finite(actor.position.y+delta.y);
    actor.position.z=finite(actor.position.z+delta.z);
}
void rebuild_actor_pose(World& world,Actor& actor,MotionTransformServices& services){
    math::require_profile();finite_vector(actor.position);finite_vector(actor.local_impulse);finite_vector(actor.world_impulse);
    actor.collision.pose_ready=false;
    actor.collision.basis=basis(math::identity());
    auto heading=math::identity();math::reset_euler_axes(heading,{0,std::bit_cast<std::uint16_t>(actor.orientation[1]),0});
    const auto forward=math::direction(heading,{0,0,1});actor.candidate_direction={forward.x,forward.y,forward.z};
    auto pose=matrix(actor.collision.basis);math::compose_euler_axes(pose,angles(actor));actor.collision.basis=basis(pose);
    const auto local=math::direction(pose,vector(actor.local_impulse));
    actor.position.x=finite(actor.position.x+finite(local.x+actor.world_impulse.x));
    actor.position.y=finite(actor.position.y+finite(local.y+actor.world_impulse.y));
    actor.position.z=finite(actor.position.z+finite(local.z+actor.world_impulse.z));
    actor.local_impulse={};actor.world_impulse={};
    services.orient_surface(world,actor);
    finite_vector(actor.position);
    finite_vector(actor.collision.basis.x);finite_vector(actor.collision.basis.y);finite_vector(actor.collision.basis.z);
    actor.collision.basis.translation={actor.position.x,actor.position.y,actor.position.z};
    actor.collision.pose_ready=true;
}
void MotionTransformFrameServices::begin_offline_frame(World& world){frame_.begin_offline_frame(world);}
void MotionTransformFrameServices::run(Stage stage,World& world,Actor& actor){
    if(stage==Stage::update_local_motion)integrate_local_motion(actor);
    else if(stage==Stage::update_pose)rebuild_actor_pose(world,actor,pose_);
    else frame_.run(stage,world,actor);
}
bool MotionTransformFrameServices::remote_motion(World& world,Actor& actor){return frame_.remote_motion(world,actor);}
bool MotionTransformFrameServices::find_grid(World& world,Actor& actor,std::int8_t& selected){return frame_.find_grid(world,actor,selected);}
void MotionTransformFrameServices::switch_grid(World& world,std::int32_t next,std::int32_t previous){frame_.switch_grid(world,next,previous);}
float MotionTransformFrameServices::grid_response(World& world,std::uint8_t grid){return frame_.grid_response(world,grid);}
} // namespace reo::native::gameplay_world
