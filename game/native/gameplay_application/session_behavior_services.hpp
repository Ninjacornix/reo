#pragma once
#include "../gameplay_world/behavior.hpp"

namespace reo::native::gameplay_application {
class NativeSession;
class SessionPrimaryActions;
// Terminal behavior owner for the canonical application. Implemented stages
// call the actual inventory, control, resource and update owners. Remaining
// action/hit consumers refuse at their call site until their owners migrate.
// The borrowed session must outlive this synchronous service.
class SessionBehaviorServices final:public gameplay_world::BehaviorServices {
public:
    explicit SessionBehaviorServices(NativeSession&);
    SessionBehaviorServices(NativeSession&,SessionPrimaryActions&);
    void run(gameplay_world::BehaviorStage,gameplay_world::World&,gameplay_world::Actor&)override;
    void dispatch(gameplay_world::ActionPass,std::uint8_t,gameplay_world::World&,gameplay_world::Actor&)override;
    bool suppress_action_notice(gameplay_world::World&,gameplay_world::Actor&,std::uint8_t,std::uint8_t)override;
    bool locally_controlled(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&)override;
    bool authority_filter(gameplay_world::actors::HealthSession&)override;
    std::int32_t selected_authority(gameplay_world::actors::HealthSession&,std::uint8_t)override;
    void refresh_class(gameplay_world::actors::HealthState&,gameplay_world::actors::HealthSession&)override;
    void feedback(gameplay_world::actors::StatusActor&,gameplay_world::actors::StatusSession&,std::uint8_t)override;
    void publish(gameplay_world::actors::StatusActor&,gameplay_world::actors::StatusSession&,std::uint8_t)override;
    void cleanup(gameplay_world::actors::StatusActor&,gameplay_world::actors::StatusSession&)override;
    void recover(gameplay_world::actors::StatusActor&,gameplay_world::actors::StatusSession&)override;
    void snapshot(gameplay_world::actors::StatusActor&,gameplay_world::actors::StatusSession&)override;
    std::uint32_t partner_flags(std::uint8_t)override;
    std::uint8_t partner_character(std::uint8_t)override;
    std::uint16_t scene_owner(std::uint8_t)override;
    void event(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&,std::uint32_t,std::uint32_t)override;
    void add_status(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&,std::uint8_t)override;
    void close_inventory(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&)override;
    void detach_scene(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&,std::uint8_t,std::uint8_t)override;
    void release_equipment(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&,std::uint8_t)override;
    void cancel_action(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&)override;
    void apply_progression(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&,std::uint16_t)override;
    void refresh_statistics(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&)override;
    void finish_contact_state(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&)override;
    void clear_hit_relations(gameplay_world::actors::HitActor&,gameplay_world::actors::HitSession&)override;
private:
    NativeSession& session_;
    SessionPrimaryActions* primary_actions_{};
    gameplay_world::actors::EntityId admit(gameplay_world::World&,gameplay_world::Actor&)const;
    std::shared_ptr<gameplay_world::Actor> admit_health(
        gameplay_world::actors::HealthState&,gameplay_world::actors::HealthSession&)const;
};
}
