#pragma once
#include "linked_resource_flight.hpp"
#include "packed_actor_audio.hpp"
#include "../gameplay_contact_world/contacts.hpp"
#include "../gameplay_lighting/timed_lights.hpp"
namespace reo::native::gameplay_world {
class ResourceLinkedFlightEffects final:public LinkedFlightEffects {
public:
    ResourceLinkedFlightEffects(World&,gameplay_contact_world::RoomResources&,ResourcePoseWork&,
        gameplay_lighting::TimedLights&,PackedActorAudio&,gameplay_collision::delivery::Packets&,
        const gameplay_collision::delivery::Catalog&);
    bool bound_to(const World&)const noexcept override;
    std::optional<gameplay_collision::response::Floor> floor(transform_math::Vector)override;
    bool burst(const actors::EntityId&,transform_math::Vector)override;
    bool light(const actors::EntityId&,transform_math::Vector)override;
    bool sound(const actors::EntityId&,std::uint8_t)override;
    bool packet(const actors::EntityId&,std::uint8_t)override;
private:
    World& world_;gameplay_contact_world::RoomResources& rooms_;ResourcePoseWork& poses_;
    gameplay_lighting::TimedLights& lights_;PackedActorAudio& audio_;
    gameplay_collision::delivery::Packets& packets_;const gameplay_collision::delivery::Catalog& catalog_;
};
}
