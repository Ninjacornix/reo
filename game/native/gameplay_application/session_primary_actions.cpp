#include "session_primary_actions.hpp"
#include "session_resources.hpp"
#include "../gameplay_world/assistance.hpp"
#include "../gameplay_world/weapon_target.hpp"
#include "../gameplay_world/reload_selection.hpp"
#include "../gameplay_world/motion.hpp"
#include "../gameplay_collision/object_queries.hpp"
#include <stdexcept>

namespace reo::native::gameplay_application {
namespace w=gameplay_world;
namespace c=gameplay_collision;
namespace u=gameplay_update;
namespace {
[[noreturn]] void unavailable(const char* message){throw std::runtime_error(message);}
}
SessionPrimaryActions::SessionPrimaryActions(NativeSession& session,SessionRooms& rooms,SessionActorQueries& queries):
    session_(session),rooms_(rooms),queries_(queries),forward_(session,rooms){
    if(!bound_to(session))throw std::invalid_argument("Canonical primary action owners required");
}
bool SessionPrimaryActions::bound_to(const NativeSession& session)const noexcept{
    return &session==&session_&&session_.open()&&rooms_.world().get()==&session_.world();
}
w::actors::EntityId SessionPrimaryActions::admit(World& world,Actor& actor)const{
    if(!bound_to(session_)||&world!=&session_.world())unavailable("Primary action session retired or foreign");
    const auto id=world.identity_of(actor);
    if(!id||world.resolve(id).get()!=&actor)unavailable("Primary action actor retired or foreign");
    return id;
}
void SessionPrimaryActions::select(Actor& actor){
    auto& world=session_.world();const auto id=admit(world,actor);const auto lease=world.resolve(id);
    if(running_)unavailable("Primary action selection reentered");
    if(actor.auxiliary_status&4u)return; //complete64AF50 prefix
    running_=true;struct Reset{SessionPrimaryActions& self;~Reset(){self.running_=false;self.assistance_={};}} reset{*this};
    if(actor.secondary==0)(void)w::select_idle_action(world,actor,metadata_,*this);
    else if(actor.secondary<=14)(void)w::select_movement_action(world,actor,metadata_,*this);
    else unavailable("Primary action secondary consumer unavailable");
    if(admit(world,actor)!=id||world.resolve(id)!=lease)unavailable("Primary action actor retired by consumer");
}
bool SessionPrimaryActions::dialogue_suppressed(){
    const auto value=session_.inventory_ui().dialogue_suppressed();
    if(!value)unavailable("Primary action inventory suppression unavailable");return *value;
}
void SessionPrimaryActions::consume_modal(Actor& actor){
    auto& world=session_.world();(void)admit(world,actor);
    if(running_)unavailable("Primary modal action reentered");
    running_=true;struct Reset{bool& value;~Reset(){value=false;}} reset{running_};
    (void)modal(world,actor);
}
bool SessionPrimaryActions::interaction(World& world,Actor& actor){
    (void)admit(world,actor);const auto result=w::process_interaction_action(world,actor,*this);
    if(result.status!=w::InteractionActionStatus::completed)unavailable("Primary interaction consumer unavailable");
    return result.original_result;
}
bool SessionPrimaryActions::request(World& world,Actor& actor){
    (void)admit(world,actor);const auto result=w::dispatch_control_request(world,actor,*this);
    if(result.status!=w::ControlRequestStatus::completed)unavailable("Primary control request unavailable");
    return result.original_result;
}
bool SessionPrimaryActions::modal(World& world,Actor& actor){
    (void)admit(world,actor);const auto result=w::consume_modal_action(world,actor,*this,*this);
    if(result.status!=w::ModalActionStatus::completed)unavailable("Primary modal action unavailable");
    return result.original_result;
}
void SessionPrimaryActions::prepare_weapon_target(World& world,Actor& actor,bool automatic){
    (void)admit(world,actor);w::prepare_weapon_target(world,actor,automatic);
}
bool SessionPrimaryActions::reload_available(World& world,Actor& actor,std::uint8_t resource){
    (void)admit(world,actor);auto* resources=session_.resources();
    if(!resources||!resources->bound_to(session_)||!resources->initialized())unavailable("Primary reload resources unavailable");
    return w::reload_available(actor,resources->descriptors(),resources->templates(),metadata_,resource);
}
w::ForwardContactResult SessionPrimaryActions::forward_contact(World& world,Actor& actor,std::uint32_t include,std::uint32_t exclude,float offset){
    (void)admit(world,actor);return forward_.probe(world,actor,include,exclude,offset);
}
std::optional<bool> SessionPrimaryActions::actor_query(World& world,Actor& actor,std::uint8_t selector,std::uint8_t mode){
    (void)admit(world,actor);return queries_.query(world,actor,selector,mode);
}
std::optional<std::int8_t> SessionPrimaryActions::admit_actor(World& world,Actor& actor){
    (void)admit(world,actor);const auto objects=rooms_.objects();if(!objects)return{};
    c::room_objects::InteractionOwner interactions(*objects);
    const auto phase=world.session().message_phase;
    const auto result=c::object_queries::exit(*objects,interactions,{actor.position.x,actor.position.y,actor.position.z},phase==1||phase==2);
    if(result.status!=c::object_queries::Status::complete)return{};return result.value;
}
bool SessionPrimaryActions::prepare_alignment(World& world,Actor& actor,std::uint32_t limit,float offset){
    const auto result=session_.update().prepare_actor_contact_alignment(admit(world,actor),limit,offset);
    if(!result)unavailable("Primary contact alignment unavailable");return *result;
}
bool SessionPrimaryActions::activate(World& world,Actor& actor){(void)admit(world,actor);w::save_action_pose(actor);return true;}
bool SessionPrimaryActions::notify(World& world,Actor& actor,std::uint8_t selector){
    return session_.update().record_actor_message(admit(world,actor),static_cast<u::ActorMessageSelector>(selector))==u::PublicationStatus::completed;
}
std::optional<bool> SessionPrimaryActions::consume_request(World& world,Actor& actor){
    const auto result=w::consume_interaction_request(world,admit(world,actor),0,session_.update().message_sink());
    if(result.status==w::InteractionTransitionStatus::unavailable)return{};return result.original_result;
}
std::optional<bool> SessionPrimaryActions::dispatch(World& world,Actor& actor){
    (void)admit(world,actor);const auto result=w::process_control_request(world,actor,*this,session_.update().message_sink());
    if(result.status!=w::ControlRequestFlowStatus::completed)return{};return result.original_result;
}
std::optional<bool> SessionPrimaryActions::query_actor(World& world,Actor& actor,std::uint8_t selector){return actor_query(world,actor,selector,0);}
std::optional<std::uint32_t> SessionPrimaryActions::prepare_equipment(World& world,Actor& actor){
    (void)admit(world,actor);assistance_=w::select_assistance_actor(session_.update(),actor);
    return assistance_?1u:0u; //opaque presence token; actual identity stays retained here
}
bool SessionPrimaryActions::consume_equipment(World& world,Actor& actor,std::uint32_t token){
    (void)admit(world,actor);if(token!=1||!assistance_)return false;
    const auto target=world.resolve(assistance_);if(!target)return false;
    w::begin_assistance(session_.update(),actor,*target);assistance_={};return true;
}
bool SessionPrimaryActions::activate_action(World& world,Actor& actor){return activate(world,actor);}
std::optional<std::int8_t> SessionPrimaryActions::admit_control(World& world,Actor& actor,std::uint8_t selector){
    (void)admit(world,actor);const auto objects=rooms_.objects();if(!objects)return{};
    c::room_objects::InteractionOwner interactions(*objects);const auto phase=world.session().message_phase;
    const auto result=c::object_queries::enter(*objects,interactions,selector,{actor.position.x,actor.position.y,actor.position.z},phase==1||phase==2);
    if(result.status!=c::object_queries::Status::complete)return{};return result.value;
}
bool SessionPrimaryActions::publish_control(World& world,Actor& actor,std::uint8_t selector,std::uint8_t control){
    (void)admit(world,actor);return w::register_interaction(world,actor,selector,control,*this)==w::InteractionRegistrationStatus::completed;
}
bool SessionPrimaryActions::request_resource(World& world,Actor& actor,std::uint8_t request){
    (void)admit(world,actor);
    gameplay_scenario::TimedTextRequest text;text.id=request;text.text_kind=2;
    return session_.timed_scene_text().request(text)==gameplay_scenario::TimedTextStatus::completed;
}
bool SessionPrimaryActions::query_actor(World& world,Actor& actor,std::uint8_t selector,std::uint8_t mode){
    return actor_query(world,actor,selector,mode).has_value(); //64F110 ignores the original Boolean
}
bool SessionPrimaryActions::close_inventory(World& world,Actor& actor){
    (void)admit(world,actor);return session_.inventory_ui().force_close()==w::InventoryUiStatus::completed;
}
bool SessionPrimaryActions::publish(World& world,Actor& actor,const w::InteractionRegistrationMessage& message){
    return session_.update().record_interaction_registration(admit(world,actor),message)==u::PublicationStatus::completed;
}
bool SessionPrimaryActions::publish_interaction_request(World& world,Actor& actor){return notify(world,actor,3);}
}
