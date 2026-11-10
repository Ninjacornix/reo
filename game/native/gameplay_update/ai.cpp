#include "update.hpp"
namespace reo::native::gameplay_update {
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
