#include "surface_follower_visual.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
std::int16_t add(std::int16_t value,int delta){return std::bit_cast<std::int16_t>(std::uint16_t(unsigned(std::uint16_t(value))+unsigned(delta)));}
float plus(float a,float b){const auto result=a+b;if(!std::isfinite(result))throw std::domain_error("Native follower visual finite arithmetic required");return result;}
}
bool advance_surface_follower_visual(SurfaceFollowerVisual& state,std::optional<transform_math::Vector> parent){
    if(!parent)state.phase=3;
    if(state.phase==3)return true;
    if(state.phase==2){++state.phase;state.visible=false;return false;}
    if(state.phase!=0&&state.phase!=1)return true;
    if(state.phase==0){
        state.flags=0x2c2c3;state.position=*parent;state.scale={1,1,1};state.color={1,1,1,.75f};state.visible=true;++state.phase;
        state.tile_step={.5f,.25f};state.column=0;state.row=0;state.interval=2;state.delay=22;state.tile_origin={0,0};state.tile_extent={1,1};
    }
    if(state.delay){state.delay=add(state.delay,-1);return false;}
    if(state.interval<=0){
        state.interval=2;state.column=add(state.column,1);
        if(state.column>=2){
            state.tile_cursor[0]=0;state.column=0;state.row=add(state.row,1);
            if(state.row>=4){state.tile_cursor[1]=0;state.row=0;}
            else state.tile_cursor[1]=plus(state.tile_cursor[1],state.tile_step[1]);
        }else state.tile_cursor[0]=plus(state.tile_cursor[0],state.tile_step[0]);
    }
    state.interval=add(state.interval,-1);return false;
}
}
