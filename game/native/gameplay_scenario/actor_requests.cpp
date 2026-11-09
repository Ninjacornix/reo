#include "actor_requests.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_world/motion.hpp"
namespace reo::native::gameplay_scenario {
namespace {
void cleanup(gameplay_world::Actor& actor,gameplay_world::Session& session)noexcept{
    session.control_notice=0;actor.status&=~std::uint32_t(0x200000);
    if(actor.control_pending){actor.control_pending=0;actor.input.history[0]=actor.input.held;actor.input.repeat=0;actor.input.released=0;actor.input.pressed=0;}
}
void action(gameplay_world::Actor& actor,std::uint8_t secondary)noexcept{
    actor.primary=1;actor.secondary=secondary;actor.phase=0;actor.subphase=0;gameplay_world::save_action_pose(actor);
}
}
bool actor_request_kind_supported(std::uint8_t kind)noexcept{return kind==0||kind==5||kind==8||kind==0x17||kind==0x28;}
ActorRequestStatus queue_actor_request(gameplay_world::World& world,std::uint32_t kind,std::uint32_t parameter)noexcept{
    const auto narrowed=std::uint8_t(kind);if(!actor_request_kind_supported(narrowed))return ActorRequestStatus::unsupported_kind;
    const auto actor=world.primary(world.selected_actor);if(!actor)return ActorRequestStatus::actor_unavailable;
    actor->control_request={1,narrowed,std::uint16_t(parameter)};return ActorRequestStatus::completed;
}
ActorRequestStatus consume_actor_request(gameplay_world::Actor& actor,gameplay_world::Session& session)noexcept{
    auto& request=actor.control_request;if(!request.pending)return ActorRequestStatus::idle;
    if(actor.status&0x80){request.pending=0;return ActorRequestStatus::completed;}
    if(!actor_request_kind_supported(request.kind))return ActorRequestStatus::unsupported_kind;
    request.pending=0;cleanup(actor,session);actor.status&=~std::uint32_t(0x80000);
    switch(request.kind){
    case 0:cleanup(actor,session);break;
    case 5:actor.control_pending=1;session.control_notice=1;break;
    case 8:action(actor,0x2e);actor.subphase=2;actor.control_pending=1;break;
    case 0x17:action(actor,0xd9);break;
    case 0x28:actor.status|=0x200000;actor.control_pending=1;break;
    default:break; // The explicit admission above excludes this path.
    }
    return ActorRequestStatus::completed;
}
}
