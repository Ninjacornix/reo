#pragma once

#include "session_rooms.hpp"
#include "../gameplay_collision/ownership.hpp"

namespace reo::native::gameplay_application {

// The original 5DC570/5DCA90 selector has source-owned actor predicates and
// callback families. Those are required capabilities; absence is not an empty
// scene. Per-record channel/grid gates are resolved by this application owner.
class SessionActorQueryEffects {
public:
    virtual ~SessionActorQueryEffects() = default;
    // Populate only source-owned non-geometric predicates/content. The adapter
    // sets actor identity/class, query class, world position and selector point.
    virtual std::optional<std::uint16_t> selected_content(
        gameplay_world::World&, gameplay_world::Actor&,
        const gameplay_collision::Proxy&) = 0;
    // Called after the original +34 owner and +3E query-class prefix has been
    // published into the canonical shared scene record.
    virtual std::optional<bool> dispatch(gameplay_world::World&,
        gameplay_world::Actor&, const gameplay_collision::ownership::Selected&,
        const gameplay_scene::Record&) = 0;
};

// Application adapter for 663190. It retains the current room and actor across
// selection and callback dispatch, publishes the selected record's canonical
// owner/query-class prefix, and revalidates both identities after callbacks.
// Selector geometry follows the complete 663190 source body and the canonical
// local-center, heading, and interaction-control fields on Actor.
class SessionActorQueries final {
public:
    SessionActorQueries(NativeSession&, SessionRooms&, SessionActorQueryEffects&) noexcept;
    std::optional<bool> query(gameplay_world::World&, gameplay_world::Actor&,
        std::uint8_t selector, std::uint8_t mode);
private:
    std::optional<bool> room_grid_span(gameplay_world::Actor&,std::uint8_t) noexcept;
    NativeSession& session_;
    SessionRooms& rooms_;
    SessionActorQueryEffects& effects_;
};

} // namespace reo::native::gameplay_application
