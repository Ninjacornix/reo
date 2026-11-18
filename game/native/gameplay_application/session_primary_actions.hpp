#pragma once
#include "session_actor_queries.hpp"
#include "session_forward_contact.hpp"
#include "../gameplay_world/primary_movement_selection.hpp"
#include "../gameplay_world/interaction_action.hpp"
#include "../gameplay_world/control_request_flow.hpp"
#include "../gameplay_world/control_request_gate.hpp"
#include "../gameplay_world/modal_action.hpp"

namespace reo::native::gameplay_application {
// Actual application consumers reached by64B060 and the ordinary movement
// selection wrappers. All calls use the same session, room and actor owners.
class SessionPrimaryActions final:private gameplay_world::PrimaryActionSelectionServices,
    private gameplay_world::InteractionActionServices,
    private gameplay_world::ControlRequestDispatcher,
    private gameplay_world::ControlRequestFlowServices,
    private gameplay_world::ModalActionServices,
    private gameplay_world::ModalActionPublication {
public:
    SessionPrimaryActions(NativeSession&,SessionRooms&,SessionActorQueries&);
    bool bound_to(const NativeSession&)const noexcept;
    void select(gameplay_world::Actor&);
    void consume_modal(gameplay_world::Actor&);
private:
    using World=gameplay_world::World;
    using Actor=gameplay_world::Actor;
    gameplay_world::actors::EntityId admit(World&,Actor&)const;
    bool dialogue_suppressed()override;
    bool interaction(World&,Actor&)override;
    bool request(World&,Actor&)override;
    bool modal(World&,Actor&)override;
    void prepare_weapon_target(World&,Actor&,bool)override;
    bool reload_available(World&,Actor&,std::uint8_t)override;
    gameplay_world::ForwardContactResult forward_contact(World&,Actor&,
        std::uint32_t,std::uint32_t,float)override;
    std::optional<bool> actor_query(World&,Actor&,std::uint8_t,std::uint8_t)override;
    std::optional<std::int8_t> admit_actor(World&,Actor&)override;
    bool prepare_alignment(World&,Actor&,std::uint32_t,float)override;
    bool activate(World&,Actor&)override;
    bool notify(World&,Actor&,std::uint8_t)override;
    std::optional<bool> consume_request(World&,Actor&)override;
    std::optional<bool> dispatch(World&,Actor&)override;
    std::optional<bool> query_actor(World&,Actor&,std::uint8_t)override;
    std::optional<std::uint32_t> prepare_equipment(World&,Actor&)override;
    bool consume_equipment(World&,Actor&,std::uint32_t)override;
    bool activate_action(World&,Actor&)override;
    std::optional<std::int8_t> admit_control(World&,Actor&,std::uint8_t)override;
    bool publish_control(World&,Actor&,std::uint8_t,std::uint8_t)override;
    bool request_resource(World&,Actor&,std::uint8_t)override;
    bool query_actor(World&,Actor&,std::uint8_t,std::uint8_t)override;
    bool close_inventory(World&,Actor&)override;
    bool publish(World&,Actor&,const gameplay_world::InteractionRegistrationMessage&)override;
    bool publish_interaction_request(World&,Actor&)override;
    NativeSession& session_;
    SessionRooms& rooms_;
    SessionActorQueries& queries_;
    SessionForwardContact forward_;
    gameplay_world::animation_events::File1Metadata metadata_;
    //6507F0 returns a peer, despite the legacy flow-interface equipment name.
    //The following call consumes this retained native identity, never an address.
    gameplay_world::actors::EntityId assistance_;
    bool running_{};
};
}
