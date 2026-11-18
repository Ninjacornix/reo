#include "game/native/gameplay_presentation/graphics_state.hpp"
#include "reference.hpp"
#include "functions.h"
#include <array>
#include <bit>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace p=reo::native::gameplay_presentation;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x196010){sub_00196010_0x196010(memory,context,runtime);return;}
    throw std::runtime_error("unexpected original graphics selector callee");
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);p::GraphicsState state;unsigned checks{};
    auto check=[&](bool ok){++checks;if(!ok)throw std::runtime_error("graphics color differential check "+std::to_string(checks));};
    check(!state.color()&&!state.color_mode());
    for(const std::uint32_t prior:std::array<std::uint32_t,4>{0,0xffffffffu,0x12345678u,0xa5a55a5au}){
        transform_write(memory.data(),0x29fe70,prior);R5900Context context;PS2Runtime runtime;
        SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,4,1);SET_GPR_U32(&context,5,0x200);SET_GPR_U32(&context,31,0x1000);context.pc=0x1af780;
        sub_001AF780_0x1af780(memory.data(),&context,&runtime);state.select_normalized_color();
        check(context.pc==0x1000&&transform_read<std::uint32_t>(memory.data(),0x29fe70)==((prior&~0xf00u)|0x200u));
        check(state.color_mode()==p::GraphicsColorMode::normalized);
    }
    for(unsigned channel=0;channel<256;++channel){R5900Context context;PS2Runtime runtime;
        SET_GPR_U32(&context,4,channel);SET_GPR_U32(&context,5,1);SET_GPR_U32(&context,31,0x1000);context.pc=0x18b2c0;
        sub_0018B2C0_0x18b2c0(memory.data(),&context,&runtime);
        check(context.pc==0x1000&&std::bit_cast<std::uint32_t>(context.f[0])==std::bit_cast<std::uint32_t>(float(channel)/255.f));
    }
    for(unsigned alpha=0;alpha<256;++alpha)for(unsigned seed=0;seed<4;++seed){
        const std::uint32_t packed=(alpha<<24)|(((seed*71+alpha*13)&255)<<16)|(((seed*17+alpha*29)&255)<<8)|((seed*53+alpha*47)&255);
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,4,14);SET_GPR_U32(&context,5,packed);SET_GPR_U32(&context,31,0x1000);context.pc=0x1af780;
        sub_001AF780_0x1af780(memory.data(),&context,&runtime);state.set_color(packed);const auto& actual=*state.color();
        check(context.pc==0x1000&&actual.packed==transform_read<std::uint32_t>(memory.data(),0x29fe30));
        for(unsigned i=0;i<3;++i)check(std::bit_cast<std::uint32_t>(actual.rgb[i])==transform_read<std::uint32_t>(memory.data(),0x294e50+4*i));
        check(std::bit_cast<std::uint32_t>(actual.alpha)==transform_read<std::uint32_t>(memory.data(),0x294e5c));
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_calls\":1284,\"alpha_values\":256,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
