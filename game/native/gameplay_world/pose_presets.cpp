#include "pose_presets.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
PresetPoseWork::PresetPoseWork(World& world,PoseWorkPool& pool,gameplay_collision::delivery::Packets& packets,const gameplay_collision::delivery::Catalog& catalog)
    :world_(world),pool_(pool),packets_(packets),catalog_(catalog){if(!bound_to(world))throw std::invalid_argument("Native preset pose owners unavailable");}
bool PresetPoseWork::bound_to(const World& world)const noexcept{return &world==&world_&&pool_.bound_to(world)&&!packets_.closed();}
bool PresetPoseWork::packet(const actors::EntityId& id,std::int32_t descriptor){
    const auto actor=pool_.resolve(id);if(!actor||descriptor<0||descriptor>255)return false;
    const auto made=packets_.attach(catalog_,1,std::uint8_t(descriptor),{id,*actor,actor->contact,actor->character,actor->position,actor->normalized_marker});last_packet_=made.id;
    return made.status==gameplay_collision::delivery::PacketStatus::completed||made.status==gameplay_collision::delivery::PacketStatus::full;
}
ResourcePoseCreated PresetPoseWork::create(const actors::EntityId& owner,const transform_math::Matrix& basis,transform_math::Vector point,
    const std::array<std::int16_t,4>& angles,std::uint32_t descriptor,std::uint32_t variant,bool attach_packet){
    ResourcePoseCreated result;if(!bound_to(world_))return result;const auto parent=world_.resolve(owner);if(!parent)return result;
    if(parent->room!=world_.room){result.status=PoseWorkStatus::completed;return result;}
    const auto made=pool_.allocate(true);result.status=made.status;result.work=made.id;if(made.status!=PoseWorkStatus::completed)return result;
    const auto actor=pool_.resolve(made.id);last_packet_={};
    if(!actor||!prepare_preset_pose(*actor,made.id,owner,basis,point,angles,descriptor,variant,pool_.remaining(),attach_packet,*this))result.status=PoseWorkStatus::unavailable;
    result.packet=last_packet_;return result;
}
}
