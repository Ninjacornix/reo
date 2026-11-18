#include "game/native/gameplay_actors/input.hpp"
#include "runtime.hpp"
#include <bit>
#include <iostream>
#include <vector>
#define SRL32(a,b) (static_cast<std::uint32_t>(a)>>static_cast<unsigned>(b))
namespace g=reo::native::gameplay_actors::input;
constexpr std::uint32_t actor=0x4a5c30,frame_at=actor+0xf78;
template<class T>T get(const std::uint8_t* r,std::uint32_t at){return oracle_read<T>(r,at);}
template<class T>void put(std::uint8_t* r,std::uint32_t at,T v){oracle_write(r,at,v);}
void write(std::uint8_t* r,std::uint32_t at,const g::Frame& f){
    put(r,at,f.pressed);put(r,at+4,f.released);put(r,at+8,f.held);
    for(std::uint32_t i=0;i<3;++i)put(r,at+12+4*i,f.history[i]);
    put(r,at+24,f.repeat);put(r,at+28,f.repeat_timer);
    for(std::uint32_t i=0;i<8;++i)put(r,at+32+2*i,f.analog[i]);
}
g::Frame read(const std::uint8_t* r,std::uint32_t at){
    g::Frame f;f.pressed=get<std::uint32_t>(r,at);f.released=get<std::uint32_t>(r,at+4);f.held=get<std::uint32_t>(r,at+8);
    for(std::uint32_t i=0;i<3;++i)f.history[i]=get<std::uint32_t>(r,at+12+4*i);
    f.repeat=get<std::uint32_t>(r,at+24);f.repeat_timer=get<std::int32_t>(r,at+28);
    for(std::uint32_t i=0;i<8;++i)f.analog[i]=get<std::int16_t>(r,at+32+2*i);
    return f;
}
void sub_001B0980_0x1b0980(std::uint8_t*,R5900Context*,PS2Runtime*);
void original_port(std::uint8_t* r,R5900Context* c,PS2Runtime* runtime){
    if(c->pc==0x1b0300)SET_GPR_U32(c,2,r[0x3243f2]);
    else if(c->pc==0x1b02d0)SET_GPR_U32(c,2,r[0x3243f2]==0);
    else if(c->pc==0x1b0980){sub_001B0980_0x1b0980(r,c,runtime);return;}
    else throw std::runtime_error("undeclared input service");
    c->pc=GPR_U32(c,31);
}
#include "owned_remaps.hpp"
#include "original_input.cpp"
std::uint32_t next(std::uint32_t& s){s^=s<<13;s^=s>>17;s^=s<<5;return s;}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000,0xa5);PS2Runtime runtime;runtime.port=&original_port;
    std::uint32_t random=0x6a527d91;std::uint64_t cases{},updated{},skipped{},invalid{};
    for(std::size_t i=0;i<owned_remaps.size();++i){const auto& m=owned_remaps[i];const auto at=0x2343c0+std::uint32_t(12*i);put(ram.data(),at,m.button_100);put(ram.data(),at+4,m.button_10);put(ram.data(),at+8,m.button_20);}
    for(std::uint32_t seed=0;seed<65536;++seed)for(unsigned operation=0;operation<3;++operation){
        g::Frame f;f.pressed=next(random);f.released=next(random);f.held=next(random);for(auto& v:f.history)v=next(random);
        f.repeat=next(random);constexpr std::int32_t timers[]{INT32_MIN,-1,0,1,2,12,INT32_MAX};f.repeat_timer=timers[seed%7];
        for(auto& v:f.analog)v=std::bit_cast<std::int16_t>(std::uint16_t(next(random)));
        std::array<g::ControllerFrame,4> sources;for(auto& source:sources){source.held=next(random);for(auto& v:source.analog)v=std::bit_cast<std::int16_t>(std::uint16_t(next(random)));}
        if(seed%5==0)sources[0].held=f.held;
        if(seed%5==1)f.pressed&=~std::uint32_t(0xf000f);
        if(seed%5==2)f.held&=~std::uint32_t(0xf000f);
        g::Routing routing;routing.mode=std::uint8_t(seed%4);routing.selected_actor=std::uint8_t((seed/4)%8);routing.layout=std::uint8_t((seed/16)%6);
        for(unsigned i=0;i<8;++i){routing.actor_ports[i]=std::int8_t(int((seed+i)%5)-1);ram[0x2b8e90+i]=std::bit_cast<std::uint8_t>(routing.actor_ports[i]);}
        g::ActorRoute a{std::uint8_t((seed/8)%8),std::uint8_t((seed/32)%2)};
        ram[actor+3]=a.slot;ram[actor+0xff0]=a.ai_control;ram[0x3243f2]=routing.mode;ram[0x4baded]=routing.selected_actor;ram[0x3243ec]=routing.layout;
        for(std::uint32_t i=0;i<sources.size();++i){const auto at=0x324240+48*i;put(ram.data(),at+8,sources[i].held);for(std::uint32_t k=0;k<8;++k)put(ram.data(),at+32+2*k,sources[i].analog[k]);}
        put(ram.data(),0x324308,sources[0].held);for(std::uint32_t k=0;k<8;++k)put(ram.data(),0x324320+2*k,sources[0].analog[k]);
        const auto at=operation==2?0x324210u:frame_at;write(ram.data(),at,f);std::uint32_t actions{};
        if(operation==0)g::repeat(f);
        else if(operation==1){const auto result=g::route(f,a,routing,sources,owned_remaps);if(result==g::Routed::updated)++updated;else if(result==g::Routed::skipped)++skipped;else throw std::runtime_error("valid input fixture refused");}
        else actions=g::menu(f,sources[0],owned_remaps[routing.layout]);
        R5900Context ctx;ctx.r[4][0]=operation==1?actor:at;ctx.r[29][0]=0x1f00000;ctx.r[31][0]=0xdead0000;
        if(operation==0)sub_001B0980_0x1b0980(ram.data(),&ctx,&runtime);
        else if(operation==1)sub_001B0B80_0x1b0b80(ram.data(),&ctx,&runtime);
        else sub_001B0DB0_0x1b0db0(ram.data(),&ctx,&runtime);
        if(f!=read(ram.data(),at) || ctx.pc!=0xdead0000 || ctx.r[29][0]!=0x1f00000 || (operation==2&&actions!=get<std::uint32_t>(ram.data(),0x4bae90)))throw std::runtime_error("input original mismatch seed="+std::to_string(seed)+" operation="+std::to_string(operation));
        ++cases;
    }
    g::Frame frame;const auto unchanged=frame;std::array<g::ControllerFrame,1> source{};g::Routing routing;routing.mode=2;routing.actor_ports[0]=-2;
    if(g::route(frame,{0,0},routing,source,owned_remaps)!=g::Routed::invalid_port || frame!=unchanged)throw std::runtime_error("negative input port");
    ++invalid;
    routing.actor_ports[0]=1;if(g::route(frame,{0,0},routing,source,owned_remaps)!=g::Routed::invalid_port || frame!=unchanged)throw std::runtime_error("input port bound");++invalid;
    if(g::route(frame,{8,0},routing,source,owned_remaps)!=g::Routed::invalid_slot || frame!=unchanged)throw std::runtime_error("input actor slot");
    ++invalid;
    routing.mode=0;routing.layout=6;if(g::route(frame,{0,0},routing,source,owned_remaps)!=g::Routed::invalid_layout || frame!=unchanged)throw std::runtime_error("input layout bound");++invalid;
    std::cout<<"{\"cases\":"<<cases<<",\"updated\":"<<updated<<",\"skipped\":"<<skipped<<",\"invalid_cases\":"<<invalid<<",\"original_bodies_executed\":3,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
