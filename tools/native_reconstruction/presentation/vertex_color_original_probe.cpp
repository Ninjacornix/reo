#include "reference.hpp"
#include "functions.h"
#include <algorithm>
#include <bit>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <vector>
void original_transform_port(std::uint8_t*,R5900Context*,PS2Runtime*){
    throw std::runtime_error("Unexpected color conversion callee");
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);std::size_t checks{};
    for(std::uint32_t mode=0;mode!=2;++mode)for(std::uint32_t value=0;value!=256;++value){
        R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,4,value);SET_GPR_U32(&context,5,mode);
        SET_GPR_U32(&context,31,0x1000);context.pc=0x18b2c0;
        sub_0018B2C0_0x18b2c0(memory.data(),&context,&runtime);
        const auto alpha=value==255?128u:value?std::max(1u,value>>1):0u;
        const float expected=mode?float(value)/255.f:float(alpha);
        if(context.pc!=0x1000||std::bit_cast<std::uint32_t>(context.f[0])!=std::bit_cast<std::uint32_t>(expected))
            throw std::runtime_error("original color conversion mismatch");
        ++checks;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_calls\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
