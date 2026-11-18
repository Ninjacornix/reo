#pragma once
#include "resource_pose_work.hpp"
namespace reo::native::gameplay_world {
class PresetPosePacket {
public:
    virtual ~PresetPosePacket()=default;
    // Descriptor is the full signed LB argument, not a wrapped byte.
    virtual bool packet(const actors::EntityId&,std::int32_t)=0;
};
// Constructor body after the actual room check and successful581FE0 clear.
// The qualified literal profile is indices0..13, not a claimed table extent.
bool prepare_preset_pose(Actor&,const actors::EntityId& work,const actors::EntityId& owner,
    const transform_math::Matrix&,transform_math::Vector,const std::array<std::int16_t,4>&,
    std::uint32_t descriptor,std::uint32_t variant,std::size_t remaining,bool attach_packet,PresetPosePacket&);
class PresetPoseWork final:private PresetPosePacket {
public:
    PresetPoseWork(World&,PoseWorkPool&,gameplay_collision::delivery::Packets&,const gameplay_collision::delivery::Catalog&);
    bool bound_to(const World&)const noexcept;
    ResourcePoseCreated create(const actors::EntityId&,const transform_math::Matrix&,transform_math::Vector,
        const std::array<std::int16_t,4>&,std::uint32_t descriptor,std::uint32_t variant,bool attach_packet=true);
private:
    World& world_;PoseWorkPool& pool_;gameplay_collision::delivery::Packets& packets_;const gameplay_collision::delivery::Catalog& catalog_;
    gameplay_collision::delivery::PacketId last_packet_;
    bool packet(const actors::EntityId&,std::int32_t)override;
};
}
