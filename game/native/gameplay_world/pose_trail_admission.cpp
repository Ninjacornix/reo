#include "pose_trail_admission.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
std::optional<PoseTrailSelection> select_pose_trail(std::uint8_t type,std::uint8_t mode)noexcept{
    if(mode>=4||type>=31)return{};
    // Complete owned708D40 type map and708CB0 four-mode resource rows.
    const int policy=type==7?3:type==0xa||type==0x1e?0:type==0x13?1:type==0x1d?2:-1;
    if(policy<0)return{};
    constexpr std::array<std::array<std::uint16_t,4>,4> resources{{{{0x85,0x86,0x87,0xffff}},{{0x85,0x86,0x87,0x88}},{{0x7a,0x7c,0xffff,0xffff}},{{0x85,0x86,0x87,0xffff}}}};
    const auto resource=resources[unsigned(policy)][mode];if(resource==0xffff)return{};
    return PoseTrailSelection{std::uint8_t(policy),resource};
}
PoseTrailAdmission::PoseTrailAdmission(World& world,PoseTrails* reached):world_(world),reached_(reached){if(!bound_to(world))throw std::invalid_argument("Native pose trail admission owners unavailable");}
bool PoseTrailAdmission::bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed()&&(!reached_||reached_->bound_to(world));}
bool PoseTrailAdmission::emit(const actors::EntityId& owner,const actors::EntityId& motion,std::uint8_t mode){
    if(!bound_to(world_))return false;
    if(mode>=4)return true;
    const auto actor=world_.resolve(owner);if(!actor)return false;
    if(!select_pose_trail(actor->slot,mode))return true;
    return reached_&&reached_->emit(owner,motion,mode);
}
}
