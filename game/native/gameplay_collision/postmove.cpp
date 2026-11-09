#include "postmove.hpp"
namespace reo::native::gameplay_collision::postmove {
Result update(State& state,Context context,const actors::Basis& basis,const response::Grid& walls,const response::Grid& floors,const regions::World& regions,const room_objects::Owner& objects,response::Filter filter,std::span<const response::Triangle> dynamic){
    Result result;if(!state.active||(!context.ignore_room&&state.room!=context.room))return result;result.eligible=true;
    if(!(state.controls&2)&&state.kind==0x14&&!state.joint_two_position){result.missing_joint=true;return result;}
    state.wall.disabled=state.controls&1;const auto before=state.wall.position;
    if(!(state.controls&1)&&(state.movement_flags&0x80))state.wall.include=0x41ffff;
    const auto wall=ownership::move_against_walls(state.wall,basis,walls,filter,dynamic);result.wall_status=wall.resolution.status;
    if(!(state.controls&1))state.wall_displacement={state.wall.position.x-before.x,state.wall.position.y-before.y,state.wall.position.z-before.z};
    if(!(state.controls&2)){
        if(state.kind==0x14){const auto point=*state.joint_two_position;state.material=floors.floor(point).material;state.region=regions.select(point);}
        else{
            const auto y=state.wall.position.y;
            if(state.surface==3){const auto difference=(state.surface_target-160.0f)-y;state.height=y+((state.height_flags&0x80)?difference:difference/2.0f);}
            else if(state.surface==2){const auto difference=state.height-y;state.height=y+((state.height_flags&0x80)?difference:difference/2.0f);}
            if(!state.route_ticks||(state.controls&0x4000))state.wall.position.y=state.height;
            state.region=regions.select(state.wall.position);
        }
    }
    if(state.surface==2||state.surface==3)state.pose_dirty=false;
    if(!(state.controls&2)&&(!(state.controls&1)||(state.movement_flags&0x4000))){const auto constrained=footprint::constrain(objects,state.wall.position,state.wall.previous,context.room_objects_enabled,context.height_layers,&floors);state.wall.position=constrained.position;result.footprint_status=constrained.status;}
    return result;
}
}
