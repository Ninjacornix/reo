#include "game/native/gameplay_scenario/timer_hud.hpp"
#include "reference.hpp"
#include <iostream>
#include <fstream>
#include <vector>
namespace s=reo::native::gameplay_scenario;
#include "functions.h"
std::uint64_t checks{},cases{},calls{};
std::vector<s::TimerHudGlyph> sprites;
unsigned setup_calls{},restores{};
void check(bool value,const char* message){++checks;if(!value)throw std::runtime_error(message);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    switch(context->pc){
    case 0x1cd250:check(GPR_U32(context,4)==0x2500,"actual HUD texture resource");SET_GPR_U32(context,2,0x12340000);++setup_calls;break;
    case 0x1af780:
        if(GPR_U32(context,4)==0x6c){if(GPR_U32(context,5))++setup_calls;else ++restores;}
        else{check(GPR_U32(context,4)==4&&GPR_U32(context,5)==0x12340000,"actual translated texture binding");++setup_calls;}
        break;
    case 0x1af1e0:check(GPR_U32(context,4)==4&&GPR_U32(context,5)==5,"actual HUD blend selection");++setup_calls;break;
    case 0x19d720:check(GPR_U32(context,4)==1&&transform_read<std::uint32_t>(memory,GPR_U32(context,5))==0x12340000,"actual opaque texture conversion boundary");++setup_calls;break;
    case 0x1af230:check(GPR_U32(context,4)==0,"actual HUD primitive mode");++setup_calls;break;
    case 0x1ab860:sprites.push_back(transform_read<s::TimerHudGlyph>(memory,GPR_U32(context,4)));break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Undeclared timer HUD support call "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
void run(std::vector<std::uint8_t>& memory,s::TimerHudPulse input,std::int16_t counter,std::uint32_t primary,std::uint32_t alternate,bool use_alternate,bool pulse){
    constexpr std::uint32_t record=0x100000;
    sprites.clear();setup_calls=restores=0;
    transform_write(memory.data(),0x3b64c0,record);transform_write(memory.data(),0x3b64bc,1u);
    transform_write(memory.data(),0x4b9a80,std::uint32_t(use_alternate)|(std::uint32_t(pulse)<<1));
    transform_write(memory.data(),record+0x60,primary);transform_write(memory.data(),record+0x64,alternate);
    transform_write(memory.data(),record+0x6c,0u);transform_write(memory.data(),record+0x70,1u);
    transform_write(memory.data(),record+5,input.falling);transform_write(memory.data(),record+0xc,input.value);transform_write(memory.data(),record+0xe,input.delta);
    std::array<std::int16_t,8> values;values.fill(counter);for(unsigned i=0;i<8;++i)transform_write(memory.data(),0x4bad88+2*i,counter);
    auto native=input;const auto frame=s::timer_hud(native,values,primary,alternate,use_alternate,pulse);
    R5900Context context{};SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x123456);context.pc=0x5ba530;PS2Runtime runtime;
    original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x123456,"whole original presentation callback returns");
    check(frame.status==s::TimerHudStatus::complete&&setup_calls==6,"complete original setup contract");
    check(frame.count==sprites.size(),"whole original sprite count");
    for(unsigned i=0;i<frame.count;++i)check(frame.glyphs[i]==sprites[i],"whole original typed sprite packet");
    check(frame.restore==(restores==1)&&frame.acknowledge==!transform_read<std::uint32_t>(memory.data(),0x3b64bc),"original early return versus restore/ack");
    check(native.falling==transform_read<std::int8_t>(memory.data(),record+5)&&native.value==transform_read<std::int16_t>(memory.data(),record+0xc)&&native.delta==transform_read<std::int16_t>(memory.data(),record+0xe),"whole original pulse field updates");
    ++cases;
}
int main(int argc,char** argv)try{
    check(argc==2,"owned HUD constants required");std::ifstream input(argv[1],std::ios::binary);std::array<std::uint8_t,80> constants{};input.read(reinterpret_cast<char*>(constants.data()),constants.size());check(bool(input),"complete owned HUD tables");
    std::vector<std::uint8_t> memory(0x2000000);std::memcpy(memory.data()+0x70a1e0,constants.data(),constants.size());sprites.reserve(8);
    for(unsigned bits=0;bits<65536;++bits){const auto value=std::bit_cast<std::int16_t>(std::uint16_t(bits));
        run(memory,{},value,bits%8,255,false,false);
        run(memory,{},value,0,bits%8,true,false);
        for(auto direction:{std::int8_t(0),std::int8_t(1),std::int8_t(-128)})for(auto delta:{std::int16_t(0),std::int16_t(257),std::int16_t(-32768)})
            run(memory,{direction,value,delta},0,0xffffffffu,0xffffffffu,false,true);
    }
    for(auto selector:{8u,255u,0x7fffffffu})run(memory,{1,123,7},0,selector,selector,false,false);
    s::TimerHudPulse state;std::array<std::int16_t,8> counters{};check(s::timer_hud(state,counters,0xffffffffu,0,false,false).status==s::TimerHudStatus::unavailable_counter,"unowned negative counter explicitly refuses");
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"original_calls\":"<<calls<<",\"game_launched\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
