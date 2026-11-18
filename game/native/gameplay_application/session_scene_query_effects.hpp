#pragma once
#include "session_actor_queries.hpp"

namespace reo::native::gameplay_application {

// Concrete 5C1710 callback owner for the current NativeSession and its
// canonical room/object/descriptor records.
class SessionSceneQueryEffects final : public SessionActorQueryEffects {
public:
    SessionSceneQueryEffects(NativeSession&,SessionRooms&) noexcept;
    std::optional<std::uint16_t> selected_content(
        gameplay_world::World&,gameplay_world::Actor&,
        const gameplay_collision::Proxy&) override;
    std::optional<bool> dispatch(gameplay_world::World&,gameplay_world::Actor&,
        const gameplay_collision::ownership::Selected&,
        const gameplay_scene::Record&) override;
private:
    std::optional<bool> room_grid_contact(gameplay_world::World&,
        gameplay_world::Actor&,const gameplay_scene::Record&,
        const gameplay_collision::ownership::Selected&) noexcept;
    std::optional<bool> object_interaction(gameplay_world::Actor&,
        const gameplay_scene::Record&,std::uint8_t) noexcept;
    std::optional<bool> scene_trigger(gameplay_world::World&,
        gameplay_world::Actor&,const gameplay_scene::Record&) noexcept;
    std::optional<bool> flag_policy(gameplay_world::World&,
        gameplay_world::Actor&,const gameplay_scene::Record&) noexcept;
    std::optional<bool> inventory_policy(gameplay_world::World&,
        gameplay_world::Actor&,const gameplay_scene::Record&);
    std::optional<bool> conditional_event_policy(gameplay_world::World&,
        gameplay_world::Actor&,const gameplay_scene::Record&);
    std::optional<bool> scene_anchor(gameplay_world::World&,
        gameplay_world::Actor&,const gameplay_scene::Record&) noexcept;
    NativeSession& session_;
    SessionRooms& rooms_;
};

} // namespace reo::native::gameplay_application
