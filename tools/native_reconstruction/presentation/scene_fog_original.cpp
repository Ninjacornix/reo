#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_presentation/raster.hpp"
#include "game/native/gameplay_scenario/fog.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
struct Selector {std::uint32_t id{},value{};};
static std::vector<Selector> calls;
void original_transform_port(std::uint8_t*,R5900Context* context,PS2Runtime*){
    if(context->pc!=0x1af780)throw std::runtime_error("Unexpected scene fog callee");
    calls.push_back({GPR_U32(context,4),GPR_U32(context,5)});context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);std::size_t checks{};
    const std::array<std::array<std::uint8_t,3>,4> colors{{{0,0,0},{10,20,30},{255,254,1},{128,64,32}}};
    const std::array<std::array<std::uint8_t,3>,4> flashes{{{0,0,0},{246,20,128},{127,128,255},{128,127,0}}};
    const std::array<std::array<float,2>,5> ranges{{{0,0},{10,10},{500,2000},{-1000,-500},{100,-100}}};
    for(const auto& color:colors)for(const auto& flash:flashes)for(const auto& range:ranges){
        std::fill(memory.begin(),memory.end(),0);reo::native::gameplay_scenario::FogState state;
        state.color=color;for(unsigned i=0;i<3;++i)state.flash[i]=flash[i];state.near_distance=range[0];state.far_distance=range[1];
        transform_write(memory.data(),0x324010,state.near_distance);transform_write(memory.data(),0x324014,state.far_distance);
        for(unsigned i=0;i<3;++i){memory[0x324018+i]=color[i];memory[0x3240d0+i]=flash[i];}
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0x1000);
        context.pc=0x6b1660;calls.clear();o2_006B1660_0x6b1660(memory.data(),&context,&runtime);
        if(context.pc!=0x1000)throw std::runtime_error("original scene fog caller did not return");
        const auto get=[](std::uint32_t id){for(const auto& call:calls)if(call.id==id)return call.value;throw std::runtime_error("selector absent");};
        const auto actual=reo::native::gameplay_presentation::prepare_scene_fog(state);if(!actual)throw std::runtime_error("native fog refused");
        const auto rgb=std::uint32_t(actual->color[0])<<16|std::uint32_t(actual->color[1])<<8|actual->color[2];
        if(rgb!=(get(0x0f)&0xffffffu)||std::bit_cast<std::uint32_t>(actual->near_distance)!=get(0x10)||
           std::bit_cast<std::uint32_t>(actual->far_distance)!=get(0x11))throw std::runtime_error("scene fog publication differs");
        checks+=3;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<checks/3<<",\"selector_callee\":\"capture only\",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
