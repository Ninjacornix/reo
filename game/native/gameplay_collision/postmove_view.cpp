#include "postmove_view.hpp"
namespace reo::native::gameplay_collision::postmove {
namespace {
Vec3 add(Vec3 a,Vec3 b){return{a.x+b.x,a.y+b.y,a.z+b.z};}
sweep::Result walls(WallView state,bool disabled,const actors::Basis& basis,const response::Grid& grid,response::Filter filter,std::span<const response::Triangle> dynamic){
    state.contact=false;const auto offset=basis.direction(state.local_center);const auto current=add(Vec3(state.position),offset),previous=add(Vec3(state.previous),state.previous_center_offset);state.previous_center_offset=offset;
    if(disabled)return{};
    filter.include=state.include;filter.exclude=state.exclude;filter.dynamic_kind_gate=state.dynamic_kind_gate;
    auto result=sweep::query(grid,sweep::input(current,previous,state.radius),filter,dynamic);
    if(result.resolution.contact_count){state.contact=true;state.position.x=(current.x+result.resolution.correction.x)-offset.x;state.position.z=(current.z+result.resolution.correction.z)-offset.z;state.point=result.reported_point;state.normal=result.reported_normal;}
    return result;
}
}
View references(State& s)noexcept{
    auto& w=s.wall;
    return{{w.position,w.previous,w.local_center,w.previous_center_offset,w.radius,w.include,w.exclude,w.dynamic_kind_gate,w.contact,w.point,w.normal},s.wall_displacement,s.joint_two_position,s.height,s.surface_target,s.movement_flags,s.height_flags,s.controls,s.room,s.route_ticks,s.region,s.kind,s.surface,s.material,s.active,s.pose_dirty};
}
Result update(View state,Context context,const actors::Basis& basis,const response::Grid& wall_grid,const response::Grid& floor_grid,const regions::World& regions,const room_objects::Owner& objects,response::Filter filter,std::span<const response::Triangle> dynamic){
    Result result;if(!state.active||(!context.ignore_room&&state.room!=context.room))return result;result.eligible=true;
    if(!(state.controls&2)&&state.kind==0x14&&!state.joint_two_position){result.missing_joint=true;return result;}
    const auto before=Vec3(state.wall.position);
    if(!(state.controls&1)&&(state.movement_flags&0x80))state.wall.include=0x41ffff;
    const auto wall=walls(state.wall,(state.controls&1)!=0,basis,wall_grid,filter,dynamic);result.wall_status=wall.resolution.status;
    if(!(state.controls&1))state.wall_displacement={state.wall.position.x-before.x,state.wall.position.y-before.y,state.wall.position.z-before.z};
    if(!(state.controls&2)){
        if(state.kind==0x14){const auto point=*state.joint_two_position;state.material=floor_grid.floor(point).material;state.region=regions.select(point);}
        else{
            const auto y=state.wall.position.y;
            if(state.surface==3){const auto difference=(state.surface_target-160.0f)-y;state.height=y+((state.height_flags&0x80)?difference:difference/2.0f);}
            else if(state.surface==2){const auto difference=state.height-y;state.height=y+((state.height_flags&0x80)?difference:difference/2.0f);}
            if(!state.route_ticks||(state.controls&0x4000))state.wall.position.y=state.height;
            state.region=regions.select(Vec3(state.wall.position));
        }
    }
    if(state.surface==2||state.surface==3)state.pose_dirty=false;
    if(!(state.controls&2)&&(!(state.controls&1)||(state.movement_flags&0x4000))){const auto constrained=footprint::constrain(objects,Vec3(state.wall.position),Vec3(state.wall.previous),context.room_objects_enabled,context.height_layers,&floor_grid);state.wall.position=constrained.position;result.footprint_status=constrained.status;}
    return result;
}
}
