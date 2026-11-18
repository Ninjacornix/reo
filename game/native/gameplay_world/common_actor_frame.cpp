#include "common_actor_frame.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
void CommonActorFrame::tick(const actors::EntityId& id){
    if(world_.closed())throw std::runtime_error("Native common actor frame World closed");
    if(running_)throw std::runtime_error("Native common actor frame reentry unavailable");
    const auto actor=world_.resolve(id);
    if(!actor)throw std::runtime_error("Native common actor frame identity unavailable");
    const bool previous=world_.updating_;running_=true;world_.updating_=true;
    struct Reset{bool& running;bool& updating;bool previous;~Reset(){running=false;updating=previous;}}reset{running_,world_.updating_,previous};
    world_.frame_shared_counter=0;actor->response_mask=0x1ffff;actor->response_value=0;
    actor->motion_override=0;actor->pending_notice=0;actor->interaction_marker=0;
    actor->contact_flags=0;actor->frame_value_a=actor->frame_value_b=0;
    if(world_.paused==0)actor->movement_enabled=1;
    if(world_.filter_nonselected_input&&actor->category==0&&actor->slot!=world_.selected_actor)actor->input={};
    actor->normalized_marker=0;
    behavior_.run(Stage::update_behavior,world_,*actor);
    if(world_.resolve(id)!=actor)throw std::runtime_error("Native common actor frame actor retired during behavior");
    integrate_local_motion(*actor);rebuild_actor_pose(world_,*actor,pose_);
    if(world_.resolve(id)!=actor)throw std::runtime_error("Native common actor frame actor retired during pose");
}
}
