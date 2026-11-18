#include "reference.hpp"
#include "functions.h"
#include "../../../game/native/gameplay_presentation/graphics_state.hpp"
#include <array>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>

void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x196010){sub_00196010_0x196010(memory,context,runtime);return;}
    throw std::runtime_error("unexpected original graphics selector callee");
}

int main()try {
    std::vector<std::uint8_t> memory(0x2000000);unsigned checks{};
    reo::native::gameplay_presentation::GraphicsState startup;
    startup.initialize_frontend_prefix();
    if(!startup.color()||startup.color()->packed!=0||startup.color()->alpha!=0||
       startup.color_mode()!=reo::native::gameplay_presentation::GraphicsColorMode::normalized||
       !startup.format_flags()||*startup.format_flags()!=2||!startup.option_12()||*startup.option_12())
        throw std::runtime_error("native frontend graphics prefix mismatch");
    const std::array<std::uint32_t,8> values{0,1,2,3,255,256,0x10002,0xffffffffu};
    for(const auto prior:std::array<std::uint32_t,8>{0,1,2,3,0xffffffffu,0x12345678,0xa5a55a5a,0x202})
        for(const auto value:values){
            transform_write(memory.data(),0x29fe70,prior);R5900Context context;PS2Runtime runtime;
            SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,4,0x15);
            SET_GPR_U32(&context,5,value);SET_GPR_U32(&context,31,0x1000);context.pc=0x1af780;
            sub_001AF780_0x1af780(memory.data(),&context,&runtime);
            if(context.pc!=0x1000||transform_read<std::uint32_t>(memory.data(),0x29fe70)!=((prior&~3u)|(value==2?2u:0u)))
                throw std::runtime_error("original graphics selector 0x15 mismatch");
            reo::native::gameplay_presentation::GraphicsState state;
            state.select_format(value);
            if(!state.format_flags()||*state.format_flags()!=(transform_read<std::uint32_t>(memory.data(),0x29fe70)&3u))
                throw std::runtime_error("native graphics format mismatch");
            ++checks;
        }
    for(const auto prior:std::array<std::uint32_t,8>{0,1,0x8000,0x10000,0x18000,0xffffffffu,0x12345678,0xa5a55a5a})
        for(const auto value:std::array<std::uint32_t,8>{0,1,2,0x8000,0x10000,0x18000,0x10002,0xffffffffu}){
            transform_write(memory.data(),0x29fe70,prior);R5900Context context;PS2Runtime runtime;
            SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,4,0x12);
            SET_GPR_U32(&context,5,value);SET_GPR_U32(&context,31,0x1000);context.pc=0x1af780;
            sub_001AF780_0x1af780(memory.data(),&context,&runtime);
            const auto actual=transform_read<std::uint32_t>(memory.data(),0x29fe70);
            if(context.pc!=0x1000||actual!=((prior&~0x18000u)|(value==0x8000u?0x8000u:0u)))
                throw std::runtime_error("original graphics selector 0x12 mismatch");
            reo::native::gameplay_presentation::GraphicsState state;state.select_option_12(value);
            if(!state.option_12()||*state.option_12()!=((actual&0x18000u)==0x8000u))
                throw std::runtime_error("native graphics option mismatch");
            ++checks;
        }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_calls\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
