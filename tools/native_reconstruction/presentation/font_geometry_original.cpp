#include "reference.hpp"
#include "functions.h"
#include <cmath>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

void original_transform_port(std::uint8_t*,R5900Context* context,PS2Runtime*){
    if(context->pc!=0x1b6fd0)throw std::runtime_error("Unexpected glyph geometry callee");
    SET_GPR_U32(context,2,GPR_U32(context,4));context->pc=GPR_U32(context,31);
}
static std::uint32_t low(std::uint64_t word){return std::uint32_t(word);}
static std::uint32_t high(std::uint64_t word){return std::uint32_t(word>>32);}
int main(){try{
    std::vector<std::uint8_t> memory(0x2000000);constexpr std::uint32_t object=0x10000,packet=0x20000,stack=0x1fff000;
    std::size_t checks=0;
    for(const auto width:{512,640,1280})for(const auto screen_height:{224,448})for(const auto interlace:{0,1})
    for(const auto glyph_size:{7,20,31})for(const auto x:{-13,44,320,639})for(const auto y:{0,72,447})for(const auto half:{0,1}){
        auto set=[&](std::uint32_t offset,std::uint32_t value){transform_write<std::uint32_t>(memory.data(),offset,value);};
        set(0x29f9bc,width);set(0x29f9c0,screen_height);set(0x29f9b4,interlace);
        set(object+12,20);set(object+0x54,17);set(object+0x58,19);set(object+0x6c,glyph_size);set(object+0x98,glyph_size);
        set(object+0x70,std::uint32_t(x));set(object+0x74,std::uint32_t(y));set(object+0x78,0xfffffffe);set(object+0x7c,0);set(object+0x80,0x60808080);
        R5900Context ctx{};PS2Runtime runtime;SET_GPR_U32(&ctx,4,object);SET_GPR_U32(&ctx,5,packet);SET_GPR_U32(&ctx,6,0x30000);SET_GPR_U32(&ctx,7,half);SET_GPR_U32(&ctx,29,stack);
        sub_001B71D0_0x1b71d0(memory.data(),&ctx,&runtime);
        const auto xy0=transform_read<std::uint64_t>(memory.data(),packet+0x78),xy1=transform_read<std::uint64_t>(memory.data(),packet+0x88);
        const auto uv0=transform_read<std::uint64_t>(memory.data(),packet+0x70),uv1=transform_read<std::uint64_t>(memory.data(),packet+0x80);
        const auto x0=((4096-width)/2)*16+int(16.f*(float(x)*(float(width)/640.f)));
        const auto x1=x0+int(16.f*(float(glyph_size>>half)*(float(width)/640.f)));
        const auto y0=((4096-screen_height)/2)*16+(interlace?y*16:y*8);
        const auto y1=y0+(interlace?glyph_size*16:glyph_size*8);
        if(std::uint16_t(low(xy0))!=std::uint16_t(x0)||std::uint16_t(low(xy0)>>16)!=std::uint16_t(y0)||
           std::uint16_t(low(xy1))!=std::uint16_t(x1)||std::uint16_t(low(xy1)>>16)!=std::uint16_t(y1)||
           high(xy0)!=0xfffffffe||high(xy1)!=0xfffffffe||low(uv0)!=0x00080008||
           low(uv1)!=std::uint32_t(((20*16+8)<<16)|((20*16>>half)+8)))
            throw std::runtime_error("original glyph geometry mismatch");
        checks+=9;
    }
    std::cout<<"{\"cases\":"<<checks/9<<",\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
