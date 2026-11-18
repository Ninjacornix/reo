#pragma once
#include "session_rooms.hpp"
#include "../gameplay_world/forward_contact.hpp"

namespace reo::native::gameplay_application {
class NativeSession;

// Per-call bridge from an admitted actor to the current SessionRooms wall
// grid. The room invocation is retained only for the synchronous query; a
// stale or replaced room cannot be queried through an old grid pointer.
class SessionForwardContact final {
public:
    SessionForwardContact(NativeSession&,SessionRooms&) noexcept;
    gameplay_world::ForwardContactResult probe(gameplay_world::World&,
        gameplay_world::Actor&,std::uint32_t include,std::uint32_t exclude,
        float signed_offset) noexcept;
private:
    NativeSession& session_;
    SessionRooms& rooms_;
};
}
