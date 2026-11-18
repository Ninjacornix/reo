#include "reference.hpp"
#include "functions.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
static unsigned calls{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    default:char buf[64];std::snprintf(buf,sizeof buf,"unmapped callee %08x",context->pc);throw std::runtime_error(buf);
    }
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("ELF image required");
    std::vector<std::uint8_t> memory(0x2000000);std::ifstream image(argv[1],std::ios::binary);image.read(reinterpret_cast<char*>(memory.data()),memory.size());if(!image)throw std::runtime_error("ELF image read");R5900Context context;PS2Runtime runtime;
    SET_GPR_U32(&context,29,0x1fff000);context.pc=0x1b22c0;sub_001B22C0_0x1b22c0(memory.data(),&context,&runtime);
    auto before=memory;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0);context.pc=0x1b2340;sub_001B2340_0x1b2340(memory.data(),&context,&runtime);
    std::cout<<"{\"original_calls\":"<<calls<<",\"changed_ranges\":[";bool first=true;
    // The test stack is above 0x1f00000; report all other writes.
    for(std::size_t i=0;i<0x1f00000;){if(memory[i]==before[i]){++i;continue;}const auto start=i;while(i<0x1f00000&&memory[i]!=before[i])++i;
        if(!first)std::cout<<',';first=false;std::cout<<'['<<start<<','<<i<<']';}
    std::cout<<"],";
    for(unsigned n=0;n<2;++n){const unsigned slot=10+n,callback=n?0x1bb480:0x1bb8f0;
        SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0);SET_GPR_U32(&context,4,callback);SET_GPR_U32(&context,5,slot);context.pc=0x1b7ee0;
        sub_001B7EE0_0x1b7ee0(memory.data(),&context,&runtime);
        const auto address=0x316350+slot*32;std::array<std::uint8_t,32> expected{};expected[0]=12;std::memcpy(expected.data()+4,&callback,4);
        if(std::memcmp(memory.data()+address,expected.data(),expected.size()))throw std::runtime_error("frontend callback registration mismatch");
    }
    std::cout<<"\"registered_callbacks\":2,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<" after "<<calls<<" calls\n";return 1;}
