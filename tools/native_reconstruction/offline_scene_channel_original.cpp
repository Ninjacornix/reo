#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <vector>
static unsigned checks{},calls{},submitted{};
static void check(bool value){++checks;if(!value)throw std::runtime_error("Offline channel check "+std::to_string(checks));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
#include "original_dispatch.inc"
    case 0x1b82a0:SET_GPR_U32(context,2,0);break; //debug output disabled
    case 0x810960:
        check(GPR_U32(context,4)==5&&GPR_U32(context,6)==0&&GPR_U32(context,7)==4);
        ++submitted;break; //ordered framing/queue observation; not a scheduler proof
    default:throw std::runtime_error("Unexpected offline channel port "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
static void load(std::vector<std::uint8_t>& memory,const char* path,unsigned at){
    std::ifstream in(path,std::ios::binary);check(bool(in));std::vector<char> bytes{std::istreambuf_iterator<char>(in),{}};
    check(std::size_t(at)+bytes.size()<=memory.size());std::memcpy(memory.data()+at,bytes.data(),bytes.size());
}
int main(int argc,char** argv)try{
    check(argc==3);std::vector<std::uint8_t> memory(0x2000000);load(memory,argv[1],0x570000);load(memory,argv[2],0x810000);PS2Runtime runtime;
    constexpr unsigned message=0x10000;
    const auto invoke=[&](unsigned pc){R5900Context c;c.pc=pc;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0x1ffff00);
        SET_GPR_U32(&c,4,5);SET_GPR_U32(&c,5,message);SET_GPR_U32(&c,6,0);SET_GPR_U32(&c,7,4);
        original_transform_port(memory.data(),&c,&runtime);check(c.pc==0x1ffff00);++calls;};
    for(unsigned type:{0u,6u})for(unsigned active:{0u,1u})for(unsigned frame:{0u,1u,0xffffffffu})for(unsigned prior:{0u,511u,512u,1024u}){
        memory[0x83e2d4]=std::uint8_t(active);memory[0x83e2d3]=5;memory[0x4baded]=2;
        transform_write(memory.data(),0x83e2d8,frame);transform_write(memory.data(),0x83e2f8,prior);
        transform_write(memory.data(),0x83bbc0+12*2+2,std::uint16_t(0));memory[message]=std::uint8_t(type);memory[message+1]=std::uint8_t(type?6:8);memory[message+2]=99;
        submitted=0;invoke(0x811190);check(submitted==unsigned(active&&frame&&prior<512));
        check(memory[message+2]==(active&&frame?2:99));
    }
    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned suppress:{0u,1u,255u})for(unsigned sender:{0u,1u})
    for(unsigned selected:{0u,1u})for(unsigned value:{0u,1u,255u})for(unsigned flag:{0u,123u,511u}){
        memory[0x3243fb]=std::uint8_t(phase);memory[0x4bae76]=std::uint8_t(suppress);memory[0x4baded]=std::uint8_t(selected);
        memory[message]=0;memory[message+2]=std::uint8_t(sender);memory[message+6]=std::uint8_t(value);
        transform_write(memory.data(),message+4,std::uint16_t(flag));memory[0x4baa50+flag]=77;
        const auto at=0x4b9c00+4*(flag/32);transform_write(memory.data(),at,0xaaaaaaaaU);
        invoke(0x810ae0);const bool applies=!suppress&&sender!=selected&&(phase==1||phase==2);const auto mask=1u<<(flag&31);
        check(transform_read<std::uint32_t>(memory.data(),at)==(applies?(value?0xaaaaaaaaU|mask:0xaaaaaaaaU&~mask):0xaaaaaaaaU));
        check(memory[0x4baa50+flag]==(applies&&value?sender+1:77));
    }
    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned suppress:{0u,1u,255u})for(unsigned sender:{0u,1u})
    for(unsigned selected:{0u,1u})for(unsigned value:{0u,1u,255u})for(unsigned ordinal:{0u,123u,255u}){
        memory[0x3243fb]=std::uint8_t(phase);memory[0x4bae76]=std::uint8_t(suppress);memory[0x4baded]=std::uint8_t(selected);
        memory[message]=6;memory[message+1]=6;memory[message+2]=std::uint8_t(sender);memory[message+4]=std::uint8_t(ordinal);memory[message+5]=std::uint8_t(value);
        const auto at=0x74f250+96*ordinal+0x2e;memory[at]=77;
        invoke(0x810ae0);const bool applies=!suppress&&sender!=selected&&(phase==1||phase==2);
        check(memory[at]==(applies?value:77));
    }
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
