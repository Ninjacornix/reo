#include "session_behavior_services.hpp"
#include "native_session.hpp"
#include "session_resources.hpp"
#include "session_control_preparation.hpp"
#include "session_primary_actions.hpp"
#include "../gameplay_world/actor_terminal_timer.hpp"
#include "../gameplay_world/actor_gauge_progression.hpp"
#include "../gameplay_world/action_notices.hpp"
#include "../gameplay_world/actor_recovery.hpp"
#include "../gameplay_world/animation_primitives.hpp"
#include "../gameplay_world/analog_control.hpp"
#include "../gameplay_world/primary_turn.hpp"
#include "../gameplay_world/ordinary_action_entry.hpp"
#include "../gameplay_world/assistance.hpp"
#include "../gameplay_world/behavior_attachments.hpp"
#include "../gameplay_world/hit_contact_response.hpp"
#include "../gameplay_world/motion.hpp"
#include "../gameplay_actors/health_class.hpp"
#include <stdexcept>
#include <string>

namespace reo::native::gameplay_application {
namespace w=gameplay_world;
namespace {
[[noreturn]] void unavailable(const char* name){
    throw std::runtime_error(std::string("Native behavior consumer unavailable: ")+name);
}
}
SessionBehaviorServices::SessionBehaviorServices(NativeSession& session):session_(session){
    if(!session_.open())throw std::invalid_argument("Open native behavior session required");
}
SessionBehaviorServices::SessionBehaviorServices(NativeSession& session,SessionPrimaryActions& actions):SessionBehaviorServices(session){
    if(!actions.bound_to(session))throw std::invalid_argument("Canonical primary action service required");
    primary_actions_=&actions;
}
w::actors::EntityId SessionBehaviorServices::admit(w::World& world,w::Actor& actor)const{
    if(!session_.open()||&world!=&session_.world())throw std::runtime_error("Native behavior session retired or foreign");
    const auto id=world.identity_of(actor);
    if(!id||world.resolve(id).get()!=&actor)throw std::runtime_error("Native behavior actor retired or foreign");
    return id;
}
std::shared_ptr<w::Actor> SessionBehaviorServices::admit_health(
    w::actors::HealthState& actor,w::actors::HealthSession& session)const{
    if(!session_.open()||&session!=static_cast<w::actors::HealthSession*>(&session_.world().session()))
        unavailable("foreign health session");
    // This application service supplies the canonical primary-frame behavior.
    // Compare base pointers before accessing a concrete Actor; a foreign base
    // object or retained retired actor must never be downcast speculatively.
    for(std::size_t i=0;i<w::World::primary_capacity;++i){
        const auto value=session_.world().primary(i);
        if(value&&static_cast<w::actors::HealthState*>(value.get())==&actor)return value;
    }
    unavailable("foreign primary health actor");
}
void SessionBehaviorServices::run(w::BehaviorStage stage,w::World& world,w::Actor& actor){
    const auto id=admit(world,actor);
    switch(stage){
    case w::BehaviorStage::update_attachment:
        w::update_behavior_attachment(world,actor);return;
    case w::BehaviorStage::update_terminal_attachment:
        w::update_terminal_attachment(actor);return;
    case w::BehaviorStage::cooperation:{
        auto* resources=session_.resources();
        auto* animation=resources&&resources->bound_to(session_)&&resources->initialized()?&resources->action_animation():nullptr;
        w::update_cooperation_action(session_.update(),actor,session_.inventory_ui(),animation);return;
    }
    case w::BehaviorStage::consume_control_request:
        if(!primary_actions_||!primary_actions_->bound_to(session_))unavailable("ordinary modal action owner");
        primary_actions_->consume_modal(actor);return;
    case w::BehaviorStage::prepare_inventory:
        if(session_.inventory_ui().prepare_actor(actor)!=w::InventoryUiStatus::completed)
            unavailable("inventory preparation 5F4F00");
        return;
    case w::BehaviorStage::prepare_control:{
        SessionControlPreparation controls(world);
        if(!controls.prepare_control(world,actor))unavailable("control preparation 64AE50");
        return;
    }
    case w::BehaviorStage::analog_control:{
        const auto& pose=session_.camera_parameters().pose;
        if(w::update_analog_control(world,actor,pose.eye,pose.aim,
            session_.sequences().camera_change_latch(),session_.inventory_ui().request_blocked(),
            session_.inventory_ui().dialogue_suppressed())!=w::AnalogControlStatus::completed)
            unavailable("analog control 6621F0");
        return;
    }
    case w::BehaviorStage::interaction:{
        // Complete668740: the modal query is reached only for the local actor.
        if(world.locally_controlled(actor)){
            const auto suppressed=session_.inventory_ui().dialogue_suppressed();
            if(!suppressed)unavailable("inventory suppression 6DEE20");
            if(*suppressed)return;
        }
        if(actor.motion_class==0x15)return;
        if(!world.scenario)unavailable("resource expiration scenario");
        if(*world.scenario!=41)return;
        auto* resources=session_.resources();
        if(!resources||!resources->bound_to(session_)||!resources->initialized())
            unavailable("resource expiration 5B6450");
        (void)resources->consumption().age_carried_expirations(id);
        return;
    }
    case w::BehaviorStage::terminal_timer:{
        if(!(actor.auxiliary_status&0x1000u)||actor.primary==4)return;
        auto* resources=session_.resources();
        if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("terminal resource owner");
        w::ActorTerminalTimer timing(world,resources->actor_operations());timing.tick(id);return;
    }
    case w::BehaviorStage::progression:{
        if(world.paused||actor.category!=0||actor.slot!=world.selected_actor||(actor.status&0x400000u))return;
        auto* resources=session_.resources();
        if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("progression resource owner");
        w::ActorGaugeProgression progression(session_.update(),resources->actor_operations());
        (void)progression.tick(id);return;
    }
    case w::BehaviorStage::activity_notice:
        if(!session_.update().publish_activity(world,actor))unavailable("activity publication 664F60");
        return;
    default:throw std::runtime_error("Native behavior stage unavailable: "+std::to_string(static_cast<unsigned>(stage)));
    }
}
void SessionBehaviorServices::dispatch(w::ActionPass pass,std::uint8_t state,w::World& world,w::Actor& actor){
    const auto id=admit(world,actor);
    const auto retained=world.resolve(id);
    if(state!=actor.primary)unavailable("stale ordinary action selector");
    // Original primary0/66B950 has no instructions with observable effects.
    if(pass==w::ActionPass::primary&&state==0)return;
    if(pass==w::ActionPass::primary&&state==1&&(actor.auxiliary_status&4u))return;
    if(pass==w::ActionPass::primary&&state==1){
        if(!primary_actions_||!primary_actions_->bound_to(session_))unavailable("ordinary primary action owner");
        primary_actions_->select(actor);return;
    }
    if(pass==w::ActionPass::secondary&&state==0){
        if(w::enter_ordinary_action(world,actor,session_.update().message_sink())!=gameplay_update::PublicationStatus::completed)
            unavailable("ordinary actor room claim 1AFF90");
        if(admit(world,actor)!=id||world.resolve(id)!=retained)unavailable("ordinary actor entry retired");
        state=actor.primary;
    }
    if(pass==w::ActionPass::secondary&&state==1){
        actor.status&=~0x200u; //66B960 commits before secondary table dispatch.
        //712C50 entries12..14 point to the complete empty66CB40 body.
        if(actor.secondary>=12&&actor.secondary<=14)return;
        if(actor.secondary<=11){
            auto* resources=session_.resources();
            if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("ordinary action animation owner");
            if(actor.secondary==0)w::update_idle_action(actor,resources->action_animation());
            else if(actor.secondary<=2)w::update_turn_action(world,actor,resources->action_animation());
            else resources->locomotion_action(actor);
            return;
        }
    }
    unavailable("ordinary action dispatch");
}
bool SessionBehaviorServices::suppress_action_notice(w::World& world,w::Actor& actor,std::uint8_t previous_primary,std::uint8_t previous_secondary){
    (void)admit(world,actor);
    std::optional<std::int16_t> quantity;
    if(actor.primary==2&&actor.secondary==2){
        auto* resources=session_.resources();
        if(resources&&resources->bound_to(session_)&&resources->initialized()){
            const auto id=resources->descriptors().slot(actor.selected_resource);
            const auto descriptor=id?resources->descriptors().get(*id):std::nullopt;
            if(descriptor)quantity=descriptor->parameter;
        }
    }
    const auto result=w::suppress_action_notice(actor,previous_primary,previous_secondary,quantity);
    if(!result)unavailable("action notice resource quantity");
    return *result;
}
bool SessionBehaviorServices::locally_controlled(w::actors::HitActor& actor,w::actors::HitSession& session){
    return session_.world().locally_controlled(*admit_health(actor,session));
}
bool SessionBehaviorServices::authority_filter(w::actors::HealthSession& session){
    if(!session_.open()||&session!=static_cast<w::actors::HealthSession*>(&session_.world().session()))
        unavailable("foreign health authority session");
    const auto phase=session_.world().session().message_phase; //actual1B0310 reads3243FB
    return phase==1||phase==2;
}
std::int32_t SessionBehaviorServices::selected_authority(w::actors::HealthSession& session,std::uint8_t actor){
    if(!session_.open()||&session!=static_cast<w::actors::HealthSession*>(&session_.world().session()))
        unavailable("foreign health authority session");
    const auto& world=session_.world();
    if(world.mode!=0&&world.mode!=1)return 1; //Complete1B0110 mode fallback.
    if(actor>=4||world.room>=128)return 0;
    const auto& membership=session_.room_membership();
    if(!membership.ready(world.mode))unavailable("selected health room membership");
    const auto result=membership.first(world.room,actor);
    if(!result)unavailable("selected health authority");
    return *result;
}
void SessionBehaviorServices::refresh_class(w::actors::HealthState& actor,w::actors::HealthSession& session){
    const auto value=admit_health(actor,session);
    constexpr std::array<float,2> thresholds{50.f,25.f}; //owned71B030; actual65FAB0
    if(w::actors::derive_health_class(*value,thresholds)==w::actors::ClassResult::invalid_maximum)
        unavailable("health class denominator");
}
void SessionBehaviorServices::feedback(w::actors::StatusActor&,w::actors::StatusSession&,std::uint8_t){unavailable("status feedback");}
void SessionBehaviorServices::publish(w::actors::StatusActor& actor,w::actors::StatusSession& session,std::uint8_t selector){
    const auto value=admit_health(actor,session);
    if(session_.update().record_actor_message(session_.world().identity_of(*value),
        static_cast<gameplay_update::ActorMessageSelector>(selector))!=gameplay_update::PublicationStatus::completed)
        unavailable("status publication");
}
void SessionBehaviorServices::cleanup(w::actors::StatusActor& actor,w::actors::StatusSession& session){
    const auto value=admit_health(actor,session);
    if(value->category!=0||value->slot!=session.selected_actor)return; //5F6800 mode0
    auto* resources=session_.resources();
    if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("status cleanup resources");
    (void)resources->actor_operations().transfer_inventory(session_.world().identity_of(*value),0);
}
void SessionBehaviorServices::recover(w::actors::StatusActor& actor,w::actors::StatusSession& session){
    const auto value=admit_health(actor,session);
    auto* resources=session_.resources();
    if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("status recovery resources");
    w::ActorRecovery recovery(session_.update(),resources->actor_operations());
    recovery.enter_zero_health(session_.world().identity_of(*value),0);
}
void SessionBehaviorServices::snapshot(w::actors::StatusActor& actor,w::actors::StatusSession& session){
    w::save_action_pose(*admit_health(actor,session));
}
std::uint32_t SessionBehaviorServices::partner_flags(std::uint8_t slot){
    const auto actor=session_.open()?session_.world().primary(slot):nullptr;
    if(!actor)unavailable("hit partner flags");
    return actor->status;
}
std::uint8_t SessionBehaviorServices::partner_character(std::uint8_t slot){
    const auto actor=session_.open()?session_.world().primary(slot):nullptr;
    if(!actor)unavailable("hit partner character");
    return actor->character;
}
std::uint16_t SessionBehaviorServices::scene_owner(std::uint8_t slot){
    auto* resources=session_.open()?session_.resources():nullptr;
    if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("hit scene resources");
    const auto id=resources->descriptors().slot(slot);
    const auto value=id?resources->descriptors().get(*id):std::nullopt;
    if(!value)unavailable("hit scene descriptor");
    return value->ownership_tag;
}
void SessionBehaviorServices::event(w::actors::HitActor& actor,w::actors::HitSession& session,std::uint32_t kind,std::uint32_t parameter){
    (void)admit_health(actor,session);
    const auto result=session_.update().record_event(kind,parameter,0);
    if(result.status!=gameplay_events::Status::completed&&result.status!=gameplay_events::Status::priority_rejected&&result.status!=gameplay_events::Status::full)
        unavailable("hit event");
}
void SessionBehaviorServices::add_status(w::actors::HitActor&,w::actors::HitSession&,std::uint8_t){unavailable("hit status");}
void SessionBehaviorServices::close_inventory(w::actors::HitActor& actor,w::actors::HitSession& session){
    (void)admit_health(actor,session);
    if(session_.inventory_ui().force_close()!=w::InventoryUiStatus::completed)unavailable("hit inventory close");
}
void SessionBehaviorServices::detach_scene(w::actors::HitActor& actor,w::actors::HitSession& session,std::uint8_t kind,std::uint8_t slot){
    const auto value=admit_health(actor,session);
    class Publication final:public w::InteractionRegistrationPublication {
    public:
        explicit Publication(gameplay_update::Owner& owner):owner_(owner){}
        bool publish(w::World& world,w::Actor& source,const w::InteractionRegistrationMessage& message)override{
            return &world==&owner_.world()&&owner_.record_interaction_registration(world.identity_of(source),message)==gameplay_update::PublicationStatus::completed;
        }
    private:gameplay_update::Owner& owner_;
    } publication(session_.update());
    if(w::register_interaction(session_.world(),*value,kind,slot,publication)!=w::InteractionRegistrationStatus::completed)
        unavailable("hit scene registration");
}
void SessionBehaviorServices::release_equipment(w::actors::HitActor& actor,w::actors::HitSession& session,std::uint8_t slot){
    const auto value=admit_health(actor,session);
    if(value->category!=1&&value->slot!=session.selected_actor)return; //5F5C50 mode0
    auto* resources=session_.resources();
    if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("hit equipment resources");
    (void)resources->actor_operations().release_instances(session_.world().identity_of(*value),0,slot);
}
void SessionBehaviorServices::cancel_action(w::actors::HitActor& actor,w::actors::HitSession& session){
    const auto value=admit_health(actor,session);
    w::animation_events::notify_equipment_selection(*value,session.selected_actor);
}
void SessionBehaviorServices::apply_progression(w::actors::HitActor& actor,w::actors::HitSession& session,std::uint16_t amount){
    const auto value=admit_health(actor,session);
    if(!session_.update().apply_hit_gauge(session_.world(),*value,amount))unavailable("hit progression");
}
void SessionBehaviorServices::refresh_statistics(w::actors::HitActor&,w::actors::HitSession&){unavailable("hit statistics");}
void SessionBehaviorServices::finish_contact_state(w::actors::HitActor& actor,w::actors::HitSession& session){
    w::finish_hit_contact(session_.world(),*admit_health(actor,session));
}
void SessionBehaviorServices::clear_hit_relations(w::actors::HitActor&,w::actors::HitSession&){unavailable("hit relation cleanup");}
}
