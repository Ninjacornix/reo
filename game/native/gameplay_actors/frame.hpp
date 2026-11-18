#pragma once
#include <array>
#include <cstdint>

namespace reo::native::gameplay_actors {

struct Position { float x{}, y{}, z{}; };

// Game flags and action words are content/state, not a CPU register file.
// Unknown business meanings remain explicit in the boundary documentation.
struct Actor {
    bool active{};
    bool visible{};
    std::uint8_t slot{}, ai_control{}, normalized_marker{};
    std::uint16_t room{}, contact_flags{}, pending_notice{};
    std::uint32_t status{}, auxiliary_status{}, response_mask{}, response_value{};
    std::uint8_t motion_override{}, interaction_marker{}, room_marker{}, movement_enabled{};
    std::uint16_t frame_value_a{}, frame_value_b{};
    std::uint8_t transient_marker{}, grid{};
    float grid_response{};
    Position position{};
    std::array<std::uint32_t,12> input_words{};
};

struct World {
    std::array<Actor,8> actors{};
    std::uint8_t mode{}, selected_actor{}, selected_frame_marker{};
    bool paused{}, filter_nonselected_input{};
    std::uint16_t room{}, frame_shared_counter{};
};

enum class Stage {
    offline_ai, leave_room, prepare_contacts, route_input, prepare_authority,
    update_behavior, update_local_motion, update_pose, update_auxiliary_motion,
    finish_motion, refresh_grid_position, finish_actor, publish_notice
};

// Synchronous owner-thread domain calls. The core owns iteration/control flow;
// callees retain their own state and can change subsequent actors/session gates.
// These ports are migration seams, not proof that their implementations migrated.
class Services {
public:
    virtual ~Services()=default;
    virtual void begin_offline_frame(World&)=0;
    virtual void run(Stage,World&,Actor&)=0;
    virtual bool remote_motion(World&,Actor&)=0;
    virtual bool find_grid(World&,Actor&,std::int8_t& selected)=0;
    virtual void switch_grid(World&,std::int32_t next,std::int32_t previous)=0;
    virtual float grid_response(World&,std::uint8_t selected)=0;
};

// One admitted gameplay invocation. No wall-clock stepping, threading, guest
// addresses, rendering calls or CPU context is hidden inside this function.
void update_primary_actors(World&,Services&);

} // namespace reo::native::gameplay_actors
