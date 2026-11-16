#include "reference.hpp"
#include "functions.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
static std::vector<std::pair<std::uint32_t,std::uint32_t>> selectors;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x1af780)selectors.emplace_back(GPR_U32(context,4),GPR_U32(context,5));
    switch(context->pc){
#include "original_dispatch.hpp"
    default:char buf[64];std::snprintf(buf,sizeof buf,"unmapped graphics callee %08x",context->pc);throw std::runtime_error(buf);
    }
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("ELF image required");std::vector<std::uint8_t> memory(0x2000000);
    std::ifstream image(argv[1],std::ios::binary);image.read(reinterpret_cast<char*>(memory.data()),memory.size());if(!image)throw std::runtime_error("ELF image read");
    // Controlled fixture: explicitly allocated, unused arena. This lets the
    // actual 18DDD0 bump allocator take its no-wrap branch without replacing
    // the 18D650 hardware synchronization call with a successful stub.
    transform_write(memory.data(),0x29fdb8,std::uint32_t(0x1800000));
    transform_write(memory.data(),0x29fdbc,std::uint32_t(0x1e00000));
    transform_write(memory.data(),0x29fdc0,std::uint32_t(0x1800000));
    // Controlled queue handles point to two distinct allocated packet lists;
    // using the ELF's pre-initialization zero handles would write near null.
    transform_write(memory.data(),0x29f6f4,std::uint32_t(128));
    transform_write(memory.data(),0x29f6fc,std::uint32_t(1));
    transform_write(memory.data(),0x29f700,std::uint32_t(2));
    transform_write(memory.data(),0x2afef0,std::uint32_t(2));
    transform_write(memory.data(),0x2afef8,std::uint32_t(0x17f0000));
    transform_write(memory.data(),0x17f0000,std::uint32_t(0x17f0100));
    transform_write(memory.data(),0x17f0010,std::uint32_t(0x17f1100));
    auto before=memory;
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0x1000);SET_GPR_U32(&context,4,0);context.pc=0x1af0c0;
    sub_001AF0C0_0x1af0c0(memory.data(),&context,&runtime);
    if(context.pc!=0x1000)throw std::runtime_error("original frontend did not return");
    std::cout<<"{\"selectors\":[";bool first=true;for(const auto [selector,value]:selectors){if(!first)std::cout<<',';first=false;std::cout<<'['<<selector<<','<<value<<']';}
    std::cout<<"],\"changed_ranges\":[";first=true;for(std::size_t i=0;i<0x1f00000;){if(memory[i]==before[i]){++i;continue;}const auto start=i;while(i<0x1f00000&&memory[i]!=before[i])++i;if(!first)std::cout<<',';first=false;std::cout<<'['<<start<<','<<i<<']';}
    std::cout<<"],\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<" after "<<selectors.size()<<" selectors:";for(const auto& [selector,value]:selectors)std::cerr<<' '<<selector<<'='<<value;std::cerr<<'\n';return 1;}
