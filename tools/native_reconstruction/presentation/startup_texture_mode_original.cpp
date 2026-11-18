#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <stdexcept>
#include <vector>
static unsigned reads{},decompressions{},registrations{};
static bool read_success{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
    case 0x1ccb30:return sub_001CCB30_0x1ccb30(memory,context,runtime);
    case 0x1cc8f0:++reads;SET_GPR_U32(context,2,read_success?2048:0);break;
    case 0x1af5d0:++decompressions;break;
    case 0x1ccb90:++registrations;SET_GPR_U32(context,2,0x20000);break;
    default:throw std::runtime_error("unexpected original texture callee");
    }
    context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);unsigned checks{};
    const auto check=[&](bool value){++checks;if(!value)throw std::runtime_error("original texture mode check "+std::to_string(checks));};
    for(const auto mode:{1u,0x10001u})for(const auto existing:{false,true})for(const auto success:{false,true}){
        std::fill(memory.begin(),memory.end(),0);reads=decompressions=registrations=0;read_success=success;
        transform_write(memory.data(),0x340ad8,std::uint32_t(0x300000));
        if(existing){transform_write(memory.data(),0x341640,std::uint32_t(0x20000));transform_write(memory.data(),0x341644,std::uint32_t(0x2604));transform_write(memory.data(),0x34164e,std::uint16_t(1));}
        R5900Context context;PS2Runtime runtime;context.pc=0x1ccd90;SET_GPR_U32(&context,29,0x1fff000);SET_GPR_U32(&context,31,0x1000);
        SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,5,0x2604);SET_GPR_U32(&context,6,mode);
        sub_001CCD90_0x1ccd90(memory.data(),&context,&runtime);check(context.pc==0x1000);
        if(mode==1&&existing){check(reads==0&&registrations==0&&decompressions==0);check(transform_read<std::uint16_t>(memory.data(),0x34164e)==2);}
        else{check(reads==1&&registrations==unsigned(success));check(decompressions==unsigned(success&&mode==0x10001));
            if(existing)check(transform_read<std::uint16_t>(memory.data(),0x34164e)==1);}
    }
    std::cout<<"{\"checks\":"<<checks<<",\"calls\":8,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
