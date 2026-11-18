#include "actor_surface_transition.hpp"
#include "motion.hpp"
#include <algorithm>
namespace reo::native::gameplay_world {
namespace {
constexpr std::array<std::uint16_t,16> ordinary_actions{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,0};
constexpr std::array<std::uint16_t,16> alternate_actions{74,75,76,77,78,79,80,81,82,83,84,85,80,81,82,74};
std::size_t find(const std::array<std::uint16_t,16>& values,std::uint8_t action){return std::size_t(std::find(values.begin(),values.end(),action)-values.begin());}
}
SurfaceTransitionStatus apply_surface_transition(Actor& actor,std::uint8_t next,std::optional<std::uint8_t>& flags)noexcept{
    if((actor.contact_flags&2)||actor.primary!=1)return SurfaceTransitionStatus::unchanged;
    std::optional<std::uint16_t> action;
    if(actor.surface_kind<=2){
        if(next<=2){
            const auto index=find(alternate_actions,actor.secondary);if(index==16)return SurfaceTransitionStatus::unchanged;
            action=ordinary_actions[index];
        }else if(next==3){
            if(actor.status&0x88){actor.position=actor.previous_position;actor.orientation=actor.previous_orientation;return SurfaceTransitionStatus::applied;}
            auto index=find(ordinary_actions,actor.secondary);if(index==16)index=0;action=alternate_actions[index];
        }else return SurfaceTransitionStatus::unchanged;
    }else if(actor.surface_kind==3){
        if(next<=2){
            auto index=find(alternate_actions,actor.secondary);if(index==16)index=0;action=ordinary_actions[index];
        }else if(next==3){
            const auto index=find(ordinary_actions,actor.secondary);if(index==16)return SurfaceTransitionStatus::unchanged;action=alternate_actions[index];
        }else return SurfaceTransitionStatus::unchanged;
    }else return SurfaceTransitionStatus::unchanged;
    if(!flags)return SurfaceTransitionStatus::unavailable;
    actor.primary=1;actor.secondary=std::uint8_t(*action);actor.phase=actor.subphase=0;save_action_pose(actor);*flags|=0x20;
    return SurfaceTransitionStatus::applied;
}
SurfaceTransitionStatus update_surface_transition(Actor& actor,const gameplay_collision::response::Grid& floors,std::optional<std::uint8_t>& flags)noexcept{
    if((actor.contact_flags&2)||actor.primary!=1)return SurfaceTransitionStatus::unchanged;
    const auto floor=floors.floor({actor.position.x,actor.position.y+50.f,actor.position.z});
    return apply_surface_transition(actor,floor.type,flags);
}
}
