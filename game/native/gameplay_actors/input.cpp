#include "input.hpp"
#include <bit>

namespace reo::native::gameplay_actors::input {
std::uint32_t remap(std::uint32_t held,Remap r)noexcept{
    auto result=held&~std::uint32_t(0x130);
    if(held&0x100)result|=r.button_100;
    if(held&0x10)result|=r.button_10;
    if(held&0x20)result|=r.button_20;
    return result;
}
namespace {
void snapshot(Frame& f,const ControllerFrame& source,std::uint32_t held)noexcept{
    f.history[2]=f.history[1];f.history[1]=f.history[0];f.history[0]=f.held;
    f.held=held;f.pressed=held&~f.history[0];f.released=f.history[0]&~held;f.analog=source.analog;
}
}
void repeat(Frame& f)noexcept{
    f.repeat=0;
    if(f.pressed&0x000f000f){f.repeat_timer=12;f.repeat=f.pressed;return;}
    if(f.held&0x000f000f){
        f.repeat_timer=std::bit_cast<std::int32_t>(std::uint32_t(f.repeat_timer)-1);
        if(f.repeat_timer<0){f.repeat_timer=2;f.repeat=f.held;}
    }else f.repeat_timer=12;
    f.repeat|=f.pressed&0x8ff0;
}
Routed route(Frame& f,ActorRoute actor,const Routing& routing,std::span<const ControllerFrame> controllers,std::span<const Remap> layouts)noexcept{
    std::int32_t port=0;
    if(routing.mode==1){if(actor.slot!=routing.selected_actor)return Routed::skipped;}
    else if(routing.mode==0){if(actor.ai_control)return Routed::skipped;}
    else{
        if(actor.slot>=routing.actor_ports.size())return Routed::invalid_slot;
        port=routing.actor_ports[actor.slot];
    }
    if(port==-1)return Routed::skipped;
    if(port<0 || std::size_t(port)>=controllers.size())return Routed::invalid_port;
    if(routing.layout>=layouts.size())return Routed::invalid_layout;
    const auto& source=controllers[std::size_t(port)];snapshot(f,source,remap(source.held,layouts[routing.layout]));
    return Routed::updated;
}
std::uint32_t menu(Frame& f,const ControllerFrame& source,Remap layout)noexcept{
    snapshot(f,source,source.held);repeat(f);
    f.pressed|=(f.pressed&0x000f0000)>>16;
    f.held|=(f.held&0x000f0000)>>16;
    f.repeat|=(f.repeat&0x000f0000)>>16;
    return remap(f.pressed,layout);
}
} // namespace reo::native::gameplay_actors::input
