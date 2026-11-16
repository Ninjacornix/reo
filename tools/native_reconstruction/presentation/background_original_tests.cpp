#include "game/native/gameplay_presentation/background.hpp"
#include "reference.hpp"
#include "functions.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace reo::native::gameplay_presentation;
namespace {std::vector<std::uint8_t> memory(0x2000000);unsigned checks{},calls{};}
void original_transform_port(std::uint8_t* bytes,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x1af780:sub_001AF780_0x1af780(bytes,context,runtime);return;
    case 0x196010:
        // The source-audited dispatch takes ID 0x14 to 197470 with its argument.
        if(GPR_U32(context,4)!=20)throw std::runtime_error("Unexpected render parameter");
        SET_GPR_U32(context,4,GPR_U32(context,5));context->pc=0x197470;
        sub_00197470_0x197470(bytes,context,runtime);return;
    default:throw std::runtime_error("Unexpected background original dependency");
    }
}
int main(int argc,char** argv)try{
    if(argc!=2)return 2;std::FILE* f=std::fopen(argv[1],"rb");if(!f)throw std::runtime_error("Palette missing");
    if(std::fread(memory.data()+0x234350,1,48,f)!=48){std::fclose(f);throw std::runtime_error("Palette truncated");}std::fclose(f);
    BackgroundState native;if(native.rgb()||native.parameter14())throw std::runtime_error("Cold background not unknown");++checks;
    native.parameter14(0x12345678);if(native.rgb()||native.parameter14()!=0x12345678)throw std::runtime_error("Independent parameter lost");++checks;
    for(unsigned i=0;i<16;++i){
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,i);SET_GPR_U32(&context,31,0x1000);context.pc=0x1af6a0;
        sub_001AF6A0_0x1af6a0(memory.data(),&context,&runtime);if(context.pc!=0x1000||!native.select(i))throw std::runtime_error("Palette call failed");++checks;
        const auto rgb=*native.rgb();for(unsigned j=0;j<3;++j){if(rgb[j]!=memory[0x32407c+j])throw std::runtime_error("RGB mismatch");++checks;}
        if(native.parameter14()!=transform_read<std::uint32_t>(memory.data(),0x29fd50))throw std::runtime_error("Render parameter mismatch");++checks;
    }
    const auto rgb=native.rgb();const auto param=native.parameter14();if(native.select(16)||native.rgb()!=rgb||native.parameter14()!=param)throw std::runtime_error("Out-of-profile palette mutated state");++checks;
    native.parameter14(0xdecafbad);if(native.rgb()!=rgb||native.parameter14()!=0xdecafbad)throw std::runtime_error("Independent parameter changed RGB");++checks;
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"palette_rows\":16,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
