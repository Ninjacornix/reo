#include "surfaces.hpp"
namespace reo::native::gameplay_world {
void sample_surface(Actor& a,const gameplay_collision::response::Grid& floors)noexcept{
    const auto floor=floors.floor({a.position.x,a.position.y+1000.0f,a.position.z},0x81);
    a.sampled_surface_valid=floor.type==0x81;
    a.sampled_surface_height=a.sampled_surface_valid?floor.height:0.0f;
}
void resolve_surface(Actor& a,const gameplay_collision::response::Grid& floors)noexcept{
    const auto query_y=a.position.y+50.0f;
    const auto floor=floors.floor({a.position.x,query_y,a.position.z});
    a.grid_response=floor.height;a.surface_kind=floor.type;
    a.surface_material=floor.material;a.surface_attributes=floor.attributes;
    a.surface_normal={floor.normal.x,floor.normal.y,floor.normal.z};
    if(a.surface_kind==3){
        a.movement_enabled=0;
        a.grid_response=a.sampled_surface_valid?a.sampled_surface_height:a.position.y+160.0f;
    }else if(a.grid_response==query_y)a.grid_response=a.position.y;
    if((a.status&0x88) && a.surface_kind==3){a.position=a.previous_position;a.orientation=a.previous_orientation;}
}
}
