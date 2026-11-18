#include "pose_surface_follower.hpp"
#include <bit>
namespace reo::native::gameplay_world {
namespace {
constexpr transform_math::Vector delta{std::bit_cast<float>(0x3e2aaaabu),std::bit_cast<float>(0x0u),std::bit_cast<float>(0x3f355555u)},offset{std::bit_cast<float>(0x43e10000u),std::bit_cast<float>(0x42c80000u),std::bit_cast<float>(0x42c80000u)};
std::int16_t decrement(std::int16_t v){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(v)-1u));}
}
bool advance_pose_surface_follower(Actor& actor,const actors::EntityId& id,SurfaceFollowerEffects& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        ++actor.primary;actor.visible=false;
        const auto visual=effects.visual(id);if(!visual)return false;
        if(!*visual)return effects.retire(id);
        state.follower_visual=*visual;state.timer=1200;return true;
    }
    if(actor.primary!=1)return true;
    actor.position={actor.position.x+delta.x,actor.position.y+delta.y,actor.position.z+delta.z};
    const auto floor=effects.floor({actor.position.x,actor.position.y,actor.position.z});if(!floor)return false;
    actor.sampled_surface_height=floor->height;actor.position.y=floor->height;
    if(!effects.position(state.follower_visual,{actor.position.x+offset.x,actor.position.y+offset.y,actor.position.z+offset.z}))return false;
    state.timer=decrement(state.timer);if(state.timer<0)++actor.primary;
    return true;
}
}
