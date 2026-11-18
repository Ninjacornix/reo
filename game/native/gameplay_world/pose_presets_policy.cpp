#include "pose_presets.hpp"
namespace reo::native::gameplay_world {
namespace {
constexpr std::int8_t profile[14][3]{{0,-1,3},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{4,-1,13},{5,-1,26},{6,-1,27},{7,-1,28},{8,-1,38},{10,-1,39},{10,-1,39},{11,-1,80},{12,-1,82},{13,-1,95}};
}
bool prepare_preset_pose(Actor& actor,const actors::EntityId& id,const actors::EntityId& owner,
    const transform_math::Matrix& basis,transform_math::Vector point,const std::array<std::int16_t,4>& angles,
    std::uint32_t descriptor,std::uint32_t variant,std::size_t remaining,bool attach_packet,PresetPosePacket& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;actor.active=true;actor.category=9;actor.slot=std::uint8_t(descriptor);
    if(actor.slot>=14)return false;
    const auto& row=profile[actor.slot];state.kind=std::uint8_t(int(row[0])+6);state.variant=std::uint8_t(variant);state.selector=std::uint8_t(row[1]);state.update_bound=true;
    actor.contact.related=owner;state.emitter_owner=owner;state.ordinal=std::uint8_t(64-remaining);state.lifetime=180;
    actor.position={point.x,point.y,point.z};actor.orientation=angles;state.basis=basis;state.velocity={};
    return !attach_packet||effects.packet(id,row[2]);
}
}
