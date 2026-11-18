#include "pose_timed_projectile.hpp"
#include <bit>
namespace reo::native::gameplay_world {
namespace {
#include "pose_timed_projectile_tables.inc"
std::int16_t decrement(std::int16_t v){return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(v)-1u));}
std::optional<std::int16_t> duration(unsigned numerator,TimedProjectileEffects& effects){const auto quantum=effects.quantum();if(!quantum)return{};return *quantum?std::int16_t(numerator/ *quantum):std::int16_t(-1);}
}
bool advance_timed_pose_projectile(Actor& actor,const actors::EntityId& id,TimedProjectileEffects& effects){
    if(!actor.pose_work)return false;
    auto& state=*actor.pose_work;
    if(actor.primary==0){
        actor.primary=1;actor.subphase=0;
        if(state.variant!=255){
            const unsigned n=state.variant;
            state.velocity={normal_x[n%4],normal_y[n%4],normal_z[n%6]};state.acceleration={0,normal_ay[n%5],normal_az[n%6]};
            if(!effects.packet(id,0x50,1))return false;
        }else{
            const auto n=effects.parent_variant(actor.contact.related);if(!n)return false;
            state.velocity={parent_x[*n%4],parent_y[*n%4],parent_z[*n%6]};state.acceleration={0,parent_ay[*n%5],parent_az[*n%6]};
            const auto ticks=duration(30,effects);if(!ticks)return false;state.timer=*ticks;
        }
        actor.orientation[0]=actor.orientation[1]=actor.orientation[2]=0;
        if((state.variant==0||state.variant==255)&&!effects.trail(actor.contact.related,id,0))return false;
        //58397C skips only mode0; every variant reaches the mode1 call.
        if(!effects.trail(actor.contact.related,id,1))return false;
        actor.collision.radius=50;actor.collision.local_center={};actor.collision.previous_local_center=actor.collision.local_center;actor.collision.previous_radius=actor.collision.radius;
        return true;
    }
    if(actor.primary==1){
        if(actor.contact.serial){actor.primary=3;actor.subphase=2;actor.auxiliary_status|=1;return true;}
        if(state.variant==255){state.timer=decrement(state.timer);if(state.timer<=0){if(!effects.packet(id,0x50,1))return false;state.variant=0;}}
        integrate_rotated_pose_velocity(actor);
        state.velocity={state.velocity.x+state.acceleration.x,state.velocity.y+state.acceleration.y,state.velocity.z+state.acceleration.z};
        if(state.velocity.y>0)return true;
        const transform_math::Vector point{actor.position.x,actor.position.y+200.f,actor.position.z};
        auto floor=effects.floor(point,0x81);if(!floor)return false;actor.sampled_surface_height=floor->height;
        if(floor->type!=0x81){floor=effects.floor(point,255);if(!floor)return false;actor.sampled_surface_height=floor->height;}
        if(actor.position.y<floor->height){
            ++actor.primary;actor.position.y=floor->height;const auto ticks=duration(180,effects);if(!ticks)return false;state.timer=*ticks;
            if(!effects.trail(actor.contact.related,id,2))return false;
            if(floor->type==0x81){actor.subphase=1;if(!effects.trail(actor.contact.related,id,3))return false;}
        }
        return true;
    }
    if(actor.primary==2){state.timer=decrement(state.timer);if(state.timer<0){actor.auxiliary_status|=1;return effects.retire(id);}return true;}
    return actor.primary!=3||effects.retire(id);
}
}
