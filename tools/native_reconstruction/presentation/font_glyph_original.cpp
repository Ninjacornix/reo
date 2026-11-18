#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_presentation/font_face.hpp"
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
        case 0x1b6460: sub_001B6460_0x1b6460(memory,context,runtime);return;
        case 0x1b6380: sub_001B6380_0x1b6380(memory,context,runtime);return;
        case 0x1b6670: sub_001B6670_0x1b6670(memory,context,runtime);return;
        case 0x1b65b0: sub_001B65B0_0x1b65b0(memory,context,runtime);return;
        default:throw std::runtime_error("Unexpected font callee");
    }
}

static std::uint32_t single(std::uint32_t c){
    if(c<0x60)return 0x851f+c;
    if(c<0x80)return 0x8520+c;
    if(c==0xa5)return 0x85a3;
    return 0x84fe + c;
}
static std::uint32_t glyph_index(std::uint32_t pair){
    auto hi=(pair>>8)&255u,lo=pair&255u;
    auto row=((std::uint16_t(hi-(hi<0xa0?0x71:0xb1))*2u)+1u)&65535u;
    if(lo>=0x80)--lo;
    if(lo>=0x9e){lo=(lo-0x7d)&65535u;row=(row+1u)&65535u;}
    else lo=(lo-0x1f)&65535u;
    const auto translated=(row<<8)|lo;
    const auto high=(translated>>8)&255u,low=translated&255u;
    return (high-0x21u)*94u+(low-0x21u);
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("owned font required");
    std::ifstream file(argv[1],std::ios::binary);std::vector<char> font{std::istreambuf_iterator<char>(file),{}};
    if(font.size()!=780800)throw std::runtime_error("unexpected font extent");
    std::vector<std::uint8_t> memory(0x2000000);std::memcpy(memory.data()+0x10000,font.data(),font.size());
    constexpr std::uint32_t context_address=0x1000,output=0x100000,stack=0x1fff000;
    transform_write<std::uint32_t>(memory.data(),context_address+8,1);
    transform_write<std::uint32_t>(memory.data(),context_address+12,20);
    transform_write<std::uint32_t>(memory.data(),context_address+16,1);
    transform_write<std::uint32_t>(memory.data(),context_address+24,256);
    transform_write<std::uint32_t>(memory.data(),context_address+32,100);
    transform_write<std::uint32_t>(memory.data(),context_address+40,0x10000);
    transform_write<std::uint32_t>(memory.data(),context_address+44,output);
    std::uint64_t checks=0;
    for(std::uint32_t c=0;c<256;++c){
        R5900Context ctx{};PS2Runtime runtime;SET_GPR_U32(&ctx,4,c);SET_GPR_U32(&ctx,5,1);SET_GPR_U32(&ctx,29,stack);
        sub_001B6580_0x1b6580(memory.data(),&ctx,&runtime);
        if(GPR_U32(&ctx,2)!=single(c)||GPR_U32(&ctx,2)!=reo::native::gameplay_presentation::FontFace::single_code(std::uint8_t(c)))throw std::runtime_error("single-byte mapping mismatch");++checks;
    }
    for(std::uint32_t c=0;c<65536;++c){
        R5900Context ctx{};PS2Runtime runtime;SET_GPR_U32(&ctx,4,c);SET_GPR_U32(&ctx,5,1);SET_GPR_U32(&ctx,29,stack);
        sub_001B64F0_0x1b64f0(memory.data(),&ctx,&runtime);
        if(GPR_U32(&ctx,2)!=glyph_index(c)||GPR_U32(&ctx,2)!=reo::native::gameplay_presentation::FontFace::index(std::uint16_t(c)))throw std::runtime_error("glyph mapping mismatch");++checks;
    }
    for(std::uint32_t glyph=0;glyph<7808;++glyph){
        R5900Context ctx{};PS2Runtime runtime;SET_GPR_U32(&ctx,4,context_address);SET_GPR_U32(&ctx,5,glyph);SET_GPR_U32(&ctx,29,stack);
        sub_001B5CA0_0x1b5ca0(memory.data(),&ctx,&runtime);
        if(GPR_U32(&ctx,2)!=output)throw std::runtime_error("glyph workspace mismatch");
        for(unsigned i=0;i<100;++i){const auto in=std::uint8_t(font[glyph*100u+i]);
            const auto expected=std::uint16_t(((in>>6)&3u)|(((in>>4)&3u)<<4)|(((in>>2)&3u)<<8)|((in&3u)<<12));
            if(transform_read<std::uint16_t>(memory.data(),output+i*2)!=expected)throw std::runtime_error("glyph pixels mismatch");++checks;
        }
    }
    std::cout<<"{\"single_codes\":256,\"pair_codes\":65536,\"owned_glyphs\":7808,\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
