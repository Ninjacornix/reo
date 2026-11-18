#include "frame.hpp"
#include <bit>

namespace reo::native::gameplay_actors {
namespace {
std::int32_t signed_grid(std::uint8_t value)noexcept {
    return std::bit_cast<std::int8_t>(value);
}
}
void update_primary_actors(World& world,Services& services) {
    if(world.mode==0)services.begin_offline_frame(world);
    for(auto& actor:world.actors) {
        if(!actor.active)continue;
        world.frame_shared_counter=0;
        actor.response_mask=0x1ffff;
        actor.response_value=0;
        actor.motion_override=0;
        actor.pending_notice=0;
        actor.interaction_marker=0;
        actor.contact_flags=0;
        actor.frame_value_a=actor.frame_value_b=0;
        actor.status&=0xddfdffff;
        actor.auxiliary_status&=~std::uint32_t(0x40);
        actor.movement_enabled=1;
        if(actor.normalized_marker==0xff)actor.normalized_marker=0;
        if(world.mode==0) {
            world.selected_actor=actor.slot;
            if(actor.ai_control)services.run(Stage::offline_ai,world,actor);
        }
        // The original pause branch still services actors, including off-room
        // actors. It must not become a blanket return/freeze here.
        if(!world.paused && actor.room!=world.room) {
            actor.visible=false;
            if(world.mode==0)services.run(Stage::leave_room,world,actor);
            actor.room_marker=0;
            actor.status&=0xff7fbfff;
            actor.auxiliary_status&=0xfa9cfeff;
            continue;
        }
        if(!world.paused && !(actor.status&0x100))actor.visible=true;
        services.run(Stage::prepare_contacts,world,actor);
        services.run(Stage::route_input,world,actor);
        actor.auxiliary_status&=0xfa9dffff;
        if(world.filter_nonselected_input && actor.slot!=world.selected_actor)actor.input_words.fill(0);
        services.run(Stage::prepare_authority,world,actor);
        services.run(Stage::update_behavior,world,actor);
        if(services.remote_motion(world,actor)) {
            services.run(Stage::update_pose,world,actor);
            actor.contact_flags|=4;
        } else {
            services.run(Stage::update_local_motion,world,actor);
            services.run(Stage::update_pose,world,actor);
        }
        services.run(Stage::update_auxiliary_motion,world,actor);
        services.run(Stage::finish_motion,world,actor);
        if(actor.auxiliary_status&0x08000000) {
            actor.auxiliary_status&=~std::uint32_t(0x08000000);
            services.run(Stage::refresh_grid_position,world,actor);
        }
        std::int8_t selected{};
        if(services.find_grid(world,actor,selected)) {
            actor.status|=0x4000;
            // The comparison is unsigned stored byte versus signed returned
            // byte; negative IDs must not silently become equal modulo 256.
            if(std::int32_t(actor.grid)!=std::int32_t(selected))
                services.switch_grid(world,selected,signed_grid(actor.grid));
            actor.grid=std::bit_cast<std::uint8_t>(selected);
            const auto response=services.grid_response(world,actor.grid);
            actor.grid_response=actor.grid_response+response;
            actor.contact_flags|=1;
        } else {
            if((actor.status&0x4000) && !(actor.contact_flags&2)) {
                services.switch_grid(world,-1,signed_grid(actor.grid));
                actor.grid=0;
            }
            actor.status&=~std::uint32_t(0x4000);
        }
        services.run(Stage::finish_actor,world,actor);
        if(actor.pending_notice) {
            services.run(Stage::publish_notice,world,actor);
            actor.pending_notice=0;
        }
        actor.room_marker=actor.transient_marker=0;
        actor.status&=~std::uint32_t(0x400000);
        if(actor.slot==world.selected_actor)world.selected_frame_marker=0;
    }
    if(world.mode==0)world.selected_actor=0;
}
} // namespace reo::native::gameplay_actors
