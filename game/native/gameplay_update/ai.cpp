#include "update.hpp"
#include "../gameplay_ai/off_room_actions.hpp"
#include "../gameplay_ai/steering.hpp"
#include "../gameplay_ai/goal_route.hpp"
namespace reo::native::gameplay_update {
gameplay_ai::ObservationAdmitted Owner::admit_ai_reference_reaction(const world::actors::EntityId& id,std::uint32_t mode){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    const auto reference=world_.primary(0);
    return gameplay_ai::admit_reference_reaction(*actor,reference.get(),mode,world_.session().random);
}
gameplay_ai::ReactionScheduled Owner::schedule_ai_reaction(const world::actors::EntityId& id,std::uint32_t event){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor||!actor->ai_execution)return {};
    return gameplay_ai::schedule_reaction(*actor->ai_execution,actor->character,event,world_.session().random);
}
gameplay_ai::GoalReevaluated Owner::reevaluate_ai_goal(const world::actors::EntityId& id,const scenario::SceneResources& resources){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    const auto reference=world_.primary(0),companion=world_.primary(actor->slot==1?2:1);
    return gameplay_ai::reevaluate_goal(*actor,reference.get(),companion.get(),world_.navigation(),resources);
}
gameplay_ai::GoalDispatched Owner::dispatch_ai_goal(const world::actors::EntityId& id,
                                                  const scenario::SceneResources& resources) {
    if (!open())
        return {};
    const auto actor = world_.resolve(id);
    if (!actor || world_.identity(actor->slot) != id)
        return {};
    const auto reference = world_.primary(0);
    const auto companion = world_.primary(actor->slot == 1 ? 2 : 1);
    gameplay_navigation::RoomFlags flags;
    for (std::uint32_t room = 0; room < flags.size(); ++room)
        flags[room] = flags_.strided_half(room, 0);
    const gameplay_ai::GoalRouteContext context{world_.room, flags};
    return gameplay_ai::dispatch_goal(*actor, reference.get(), companion.get(), world_.navigation(),
                                     resources, world_.session().random, &context);
}
gameplay_ai::Status Owner::dispatch_active_ai_action(
    const world::actors::EntityId& id, bool updates_blocked,
    const gameplay_navigation::VisibilityRoom* room, std::optional<std::uint16_t> camera_heading) {
    if (!open())
        return gameplay_ai::Status::unavailable;
    const auto actor = world_.resolve(id);
    if (!actor || world_.identity(actor->slot) != id)
        return gameplay_ai::Status::unavailable;
    if (!updates_blocked && actor->ai_execution && actor->ai_execution->action == 2)
        return advance_active_ai_waypoint(*actor, room, camera_heading);
    const auto reference = world_.primary(0);
    return gameplay_ai::dispatch_active_room_action(*actor, reference.get(), updates_blocked);
}
AiFrameResult Owner::run_ai_frame(const world::actors::EntityId& id, bool updates_blocked,
                                  const gameplay_navigation::VisibilityRoom& room,
                                  const gameplay_scene::Records& records,
                                  const scenario::SceneResources& resources,
                                  std::optional<std::uint16_t> camera_heading) {
    AiFrameResult result;
    if (!open())
        return result;
    const auto actor = world_.resolve(id);
    if (!actor || world_.identity(actor->slot) != id || !actor->ai_execution)
        return result;

    auto& input = actor->input;
    auto& state = *actor->ai_execution;
    input.held = 0;
    input.pressed = 0;
    input.history[0] = 0;
    input.analog.fill(0);
    state.steering_button_10 = 1;
    state.steering_button_20 = 0;
    actor->speech.remote_request = 0;
    if (updates_blocked || state.inhibited || actor->response_lock ||
        world_.session().suppress_hits || (actor->status & 0x20u)) {
        result.status = AiFrameStatus::gated;
        return result;
    }

    result.observation = update_ai_observations(id, room, records, resources);
    if (result.observation.status != gameplay_ai::Status::completed) {
        result.status = AiFrameStatus::observation_unavailable;
        return result;
    }
    result.goal = dispatch_ai_goal(id, resources);
    if (result.goal.status != gameplay_ai::Status::completed) {
        result.status = AiFrameStatus::goal_unavailable;
        return result;
    }
    if (!actor->navigation_route) {
        result.status = AiFrameStatus::action_unavailable;
        return result;
    }
    const auto action_status =
        actor->navigation_route->selection_mode
            ? gameplay_ai::dispatch_off_room_action(*actor, world_.navigation(),
                                                    world_.session().clock_mode)
            : dispatch_active_ai_action(id, false, &room, camera_heading);
    if (action_status != gameplay_ai::Status::completed) {
        result.status = AiFrameStatus::action_unavailable;
        return result;
    }
    result.status = AiFrameStatus::completed;
    return result;
}
gameplay_ai::InitializationResult Owner::initialize_ai(const world::actors::EntityId& id){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return gameplay_ai::initialize(world_.navigation(),world_.session().ai_control_requests,actor->ai_control,actor->slot,
        actor->ai_execution?&*actor->ai_execution:nullptr,actor->navigation_route?&*actor->navigation_route:nullptr,&actor->speech.remote_request);
}
std::optional<std::int32_t> Owner::ai_activity_mode()const noexcept{
    if(!open())return {};
    return gameplay_session::activity_mode(world_.mode,world_.session().activity);
}
gameplay_ai::ControlApplied Owner::receive_ai_controls(std::span<const std::uint8_t> packet){
    if(!open())return {};
    return world_.session().ai_control_requests.receive(packet,ai_activity_mode());
}
gameplay_ai::ControlPayloadFlushed Owner::flush_ai_control_payloads(gameplay_ai::ControlPayloadSink& sink) {
    if (!open())
        return {};
    return world_.session().ai_control_requests.flush_payloads(world_.selected_actor, sink);
}
std::optional<gameplay_ai::RegistrationStatus> Owner::register_ai_control(const world::actors::EntityId& id){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return world_.session().ai_control_requests.register_control(0,actor->slot);
}
std::optional<gameplay_ai::RequestResult> Owner::publish_ai_control(const world::actors::EntityId& id,std::uint32_t value){
    if(!open())return {};
    const auto actor=world_.resolve(id);if(!actor)return {};
    return gameplay_ai::publish_actor_control(world_.session().ai_control_requests,actor->slot,value);
}
gameplay_ai::Status Owner::set_ai_goal(const world::actors::EntityId& id,std::uint32_t goal){
    if(!open())return gameplay_ai::Status::unavailable;
    const auto actor=world_.resolve(id);if(!actor||!actor->ai_execution)return gameplay_ai::Status::unavailable;
    gameplay_ai::set_goal(*actor->ai_execution,goal);return gameplay_ai::Status::completed;
}
gameplay_ai::Status Owner::set_ai_action(const world::actors::EntityId& id,std::uint32_t action){
    if(!open())return gameplay_ai::Status::unavailable;
    const auto actor=world_.resolve(id);if(!actor||!actor->ai_execution)return gameplay_ai::Status::unavailable;
    gameplay_ai::set_action(*actor->ai_execution,action);return gameplay_ai::Status::completed;
}
gameplay_ai::Status Owner::select_ai_weight_profile(const world::actors::EntityId& id,std::int32_t profile){
    if(!open())return gameplay_ai::Status::unavailable;
    const auto actor=world_.resolve(id);if(!actor||!actor->ai_execution)return gameplay_ai::Status::unavailable;
    return gameplay_ai::select_weight_profile(*actor->ai_execution,profile);
}
}
