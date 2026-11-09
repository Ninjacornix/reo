#pragma once
#include <cstdint>
namespace reo::native::gameplay_world {class World;struct Actor;struct Session;}
namespace reo::native::gameplay_scenario {
enum class ActorRequestStatus {idle,completed,actor_unavailable,unsupported_kind};
// Explicit initial native consumer profile. These actual callbacks are closed
// over canonical actor/session/input state and the qualified action snapshot;
// other callback kinds remain unadmitted, never successful fallback effects.
bool actor_request_kind_supported(std::uint8_t)noexcept;
ActorRequestStatus queue_actor_request(gameplay_world::World&,std::uint32_t authored_kind,std::uint32_t authored_parameter)noexcept;
ActorRequestStatus consume_actor_request(gameplay_world::Actor&,gameplay_world::Session&)noexcept;
}
