#pragma once
#include "scenario_publication.hpp"
#include "../gameplay_weapon_resources/equipment.hpp"
namespace reo::native::gameplay_update {
enum class ReceptionStatus {completed,unavailable};
struct ReceptionResult {
    ReceptionStatus status{ReceptionStatus::completed};
    std::optional<gameplay_weapon_resources::Selected> equipment;
};
// Simulation-thread consumer of typed messages after transport admission.
// Borrowed owners outlive this facade; no packet buffer or guest pointer enters
// the native state. The channel names a checked primary slot plus one.
class ActorReception final {
public:
    ActorReception(gameplay_world::World&,gameplay_collision::room_objects::Owner* = nullptr,gameplay_weapon_resources::Equipment* = nullptr);
    ReceptionResult receive(const ActorStatusMessage&,bool local_echo=false)noexcept;
    ReceptionResult receive(const ActorAlignmentMessage&,bool local_echo=false)noexcept;
    ReceptionResult receive(const ActorInteractionMessage&,bool local_echo=false)noexcept;
    ReceptionResult receive(const ActorInventoryMessage&,bool local_echo=false)noexcept;
    ReceptionResult receive(const ActorResourcePairMessage&,bool local_echo=false)noexcept;
    ReceptionResult receive(const ActorRoomObjectMessage&,bool local_echo=false)noexcept;
private:
    struct Admission {ReceptionStatus status{ReceptionStatus::completed};std::shared_ptr<gameplay_world::Actor> actor;};
    gameplay_world::World& world_;
    gameplay_collision::room_objects::Owner* objects_;
    gameplay_weapon_resources::Equipment* equipment_;
    Admission begin(std::uint32_t channel,bool local_echo)noexcept;
    ReceptionResult finish(gameplay_world::Actor&)noexcept;
};
}
