#include "color_fade.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
FadeStatus start_color_fade(World& world,const actors::EntityId& id,FadeDirection direction,std::uint32_t full_alpha,std::uint32_t updates)noexcept{
    if(world.closed())return FadeStatus::unavailable;
    const auto actor=world.resolve(id);if(!actor)return FadeStatus::unavailable;
    if(direction!=FadeDirection::increase&&direction!=FadeDirection::decrease)return FadeStatus::unavailable;
    const auto alpha=std::uint8_t(full_alpha);
    if(!updates)return FadeStatus::unavailable; // Native preflight: zero-divisor source profiles are unadmitted.
    actor->auxiliary_status|=direction==FadeDirection::increase?0x4000u:0x8000u;
    const auto distance=direction==FadeDirection::increase?255u-alpha:std::uint32_t(alpha);
    actor->color_fade=ColorFade{(std::uint32_t(alpha)<<24)|0xffffffu,(distance/updates)<<24,updates};
    return FadeStatus::completed;
}
FadeStatus advance_color_fade(World& world,const actors::EntityId& id,FadeDirection direction)noexcept{
    if(world.closed())return FadeStatus::unavailable;
    const auto actor=world.resolve(id);if(!actor||!actor->color_fade)return FadeStatus::unavailable;
    if(direction!=FadeDirection::increase&&direction!=FadeDirection::decrease)return FadeStatus::unavailable;
    auto& fade=*actor->color_fade;--fade.updates_left;
    if(fade.updates_left){
        if(direction==FadeDirection::increase)fade.rgba+=fade.step;else fade.rgba-=fade.step;
    }else{
        actor->auxiliary_status&=~(direction==FadeDirection::increase?0x4000u:0x8000u);
        fade.rgba=direction==FadeDirection::increase?0xffffffffu:0xffffffu;fade.step=0;
    }
    return FadeStatus::completed;
}
FadeStatus finish_color_fade(World& world,const actors::EntityId& id)noexcept{
    if(world.closed())return FadeStatus::unavailable;
    const auto actor=world.resolve(id);if(!actor)return FadeStatus::unavailable;
    if(actor->auxiliary_status&0x4000u)return advance_color_fade(world,id,FadeDirection::increase);
    if(actor->auxiliary_status&0x8000u)return advance_color_fade(world,id,FadeDirection::decrease);
    return FadeStatus::completed;
}
void ColorFadeFrameServices::begin_offline_frame(World& world){frame_.begin_offline_frame(world);}
void ColorFadeFrameServices::run(Stage stage,World& world,Actor& actor){
    if(stage==Stage::finish_actor){
        if(finish_color_fade(world,world.identity_of(actor))!=FadeStatus::completed)throw std::runtime_error("Native actor color fade unavailable at frame completion");
    }else frame_.run(stage,world,actor);
}
bool ColorFadeFrameServices::remote_motion(World& world,Actor& actor){return frame_.remote_motion(world,actor);}
bool ColorFadeFrameServices::find_grid(World& world,Actor& actor,std::int8_t& selected){return frame_.find_grid(world,actor,selected);}
void ColorFadeFrameServices::switch_grid(World& world,std::int32_t next,std::int32_t previous){frame_.switch_grid(world,next,previous);}
float ColorFadeFrameServices::grid_response(World& world,std::uint8_t grid){return frame_.grid_response(world,grid);}
}
