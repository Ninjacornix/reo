#include "motion.hpp"
#include <stdexcept>

namespace reo::native::gameplay_world {
void save_action_pose(Actor& actor)noexcept{
    actor.saved_action_position=actor.position;
    actor.saved_action_yaw=actor.orientation[1];
}
MotionStatus advance_collision_shape(Actor& actor)noexcept{
    auto& shape=actor.collision;
    shape.previous_local_center=shape.local_center;
    shape.previous_radius=shape.radius;
    if(!shape.interpolation_ticks)return MotionStatus::completed;
    --shape.interpolation_ticks;
    if(shape.interpolation_ticks){
        shape.local_center.x=shape.local_center.x+shape.interpolation_step.x;
        shape.local_center.y=shape.local_center.y+shape.interpolation_step.y;
        shape.local_center.z=shape.local_center.z+shape.interpolation_step.z;
    }else{
        if(!shape.interpolation_target)return MotionStatus::shape_target_unavailable;
        shape.local_center=shape.interpolation_target->center;
        shape.radius=shape.interpolation_target->radius;
    }
    return MotionStatus::completed;
}
void finish_motion(World& world,Actor& actor,MotionServices& services){
    if(world.paused==1 || (actor.contact_flags&4))return;
    // The original mode predicate means mode==0; its zero-result branch is
    // therefore the nonzero-mode policy, rather than the offline branch.
    const bool other_slot=world.mode!=0 && actor.category==0 && actor.slot!=world.selected_actor;
    services.enqueue(world,actor,1,(other_slot || actor.category==1)?0:3);
}
void MotionFrameServices::begin_offline_frame(World& world){frame_.begin_offline_frame(world);}
void MotionFrameServices::run(Stage stage,World& world,Actor& actor){
    if(stage==Stage::update_auxiliary_motion){
        if(advance_collision_shape(actor)!=MotionStatus::completed)
            throw std::runtime_error("Native actor collision shape target unavailable after snapshot/decrement");
    }else if(stage==Stage::finish_motion)finish_motion(world,actor,motion_);
    else frame_.run(stage,world,actor);
}
bool MotionFrameServices::remote_motion(World& world,Actor& actor){return frame_.remote_motion(world,actor);}
bool MotionFrameServices::find_grid(World& world,Actor& actor,std::int8_t& selected){return frame_.find_grid(world,actor,selected);}
void MotionFrameServices::switch_grid(World& world,std::int32_t next,std::int32_t previous){frame_.switch_grid(world,next,previous);}
float MotionFrameServices::grid_response(World& world,std::uint8_t grid){return frame_.grid_response(world,grid);}
} // namespace reo::native::gameplay_world
