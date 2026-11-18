#include "session_control_preparation.hpp"
#include "../gameplay_scenario/actor_requests.hpp"

namespace reo::native::gameplay_application {
bool SessionControlPreparation::prepare_control(gameplay_world::World& world,
                                               gameplay_world::Actor& actor)noexcept {
    if(&world!=&world_||world.closed())return false;
    const auto identity=world.identity_of(actor);
    if(!identity||world.resolve(identity).get()!=&actor)return false;
    const auto result=gameplay_scenario::consume_actor_request(actor,world.session());
    return result==gameplay_scenario::ActorRequestStatus::idle||
           result==gameplay_scenario::ActorRequestStatus::completed;
}
}
