#include "game/native/gameplay_world/cinematic_object_attachment.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace t=reo::native::transform_math;
std::uint64_t checks{},original_calls{},attachments{},object_parents{},actor_parents{},zero_axes{},preserved_translation{},refusals{};
std::string location;
void check(bool value,const char* why){++checks;if(!value)throw std::runtime_error(why);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;
    switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("undeclared cinematic attachment original call "+std::to_string(context->pc));
    }
}
void call(std::uint8_t* memory,std::uint32_t node){
    R5900Context context;context.pc=0x5717c0;SET_GPR_U32(&context,4,0x210000);SET_GPR_U32(&context,5,0x200000);SET_GPR_U32(&context,6,0x230000);SET_GPR_U32(&context,7,node);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);PS2Runtime runtime;
    original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000,"complete original attachment return and stack");
}
int main(int argc,char** argv)try{
    check(argc==2,"owned attachment skeleton package required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());transform_write(memory.data(),0x294e00,t::identity());
    std::ifstream input(argv[1],std::ios::binary);std::uint32_t count{};input.read(reinterpret_cast<char*>(&count),4);check(count==4,"actual P07 HP07 HN54 HN88 skeletons");
    for(unsigned asset=0;asset<count;++asset){std::uint32_t size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x40000,"bounded owned skeleton extent");std::vector<std::byte> raw(size);input.read(reinterpret_cast<char*>(raw.data()),size);check(bool(input),"complete owned attachment skeleton");
        a::Instance parent(a::Skeleton::import_raw(raw));unsigned previous=UINT32_MAX;
        transform_write(memory.data(),0x200034,0x220000u);transform_write(memory.data(),0x220000+0x820,0x100000u);transform_write(memory.data(),0x200070,0x220820u);
        for(unsigned node=0;node<parent.nodes().size();++node)transform_write(memory.data(),0x220820+4*node,0x100000+400*node);
        for(unsigned value=0;value<65536;++value){location="attachment asset="+std::to_string(asset)+" turn="+std::to_string(value);const auto preset=value>>12;
            if(preset!=previous){auto basis=t::identity();t::compose_euler_axes(basis,{std::uint16_t(preset*1131),std::uint16_t(preset*2333),std::uint16_t(preset*3713)});
                for(unsigned lane=0;lane<3;++lane){basis[0][lane]*=1.25f;basis[1][lane]*=.75f;basis[2][lane]*=2.f;}
                if(preset==3){basis[0]={0,0,0,0};}if(preset==5){basis[1]={-0.f,0,-0.f,0};}
                basis[3]={10.f+float(preset),-20.f+float(preset),30,1};
                if(preset&8){basis[0][3]=.125f;basis[1][3]=-.25f;basis[2][3]=.5f;basis[3][3]=2;}
                parent.rebuild(basis);previous=preset;
            }
            const auto node=std::uint32_t(value%parent.nodes().size());const auto& matrix=parent.nodes()[node].world;transform_write(memory.data(),0x100000+400*node,matrix);
            const bool object=value&1;memory[0x200002]=object?10:3;
            const a::Vector scale{value%7==0?0.f:value%7==1?-1.5f:1.25f,value%11==0?0.f:.75f,value%3==0?-2.f:2.5f};transform_write(memory.data(),0x2000b4,scale);
            std::array<std::byte,36> command{};const a::Vector offset{float(int(value%5)-2)*.25f,float(int(value%7)-3)*.5f,float(int(value%3)-1)};
            const t::Angles rotation{std::uint16_t(value),std::uint16_t(value*113),std::uint16_t(value^0xffff)};std::memcpy(command.data()+12,&offset,12);std::memcpy(command.data()+24,rotation.data(),6);std::memcpy(memory.data()+0x230000,command.data(),command.size());
            const auto request=g::CinematicObjectAttachment::read(command);g::CinematicObject output;output.angles={123,456,789};output.flags=0x89abcdef;output.position={-97,-98,-99};output.basis=t::identity();
            transform_write(memory.data(),0x210018,output.angles);transform_write(memory.data(),0x210020,output.position);transform_write(memory.data(),0x210030,output.basis);transform_write(memory.data(),0x21118c,output.flags);
            g::attach_cinematic_object(output,parent,node,scale,request);call(memory.data(),node);
            if(std::memcmp(&output.position,memory.data()+0x210020,12)||std::memcmp(&output.basis,memory.data()+0x210030,64)){
                std::cerr<<"node="<<node<<" position="<<std::memcmp(&output.position,memory.data()+0x210020,12)<<" basis="<<std::memcmp(&output.basis,memory.data()+0x210030,64)<<'\n';
                for(unsigned col=0;col<4;++col)for(unsigned lane=0;lane<4;++lane){const auto expected=transform_read<std::uint32_t>(memory.data(),0x210030+16*col+4*lane);if(std::bit_cast<std::uint32_t>(output.basis[col][lane])!=expected)std::cerr<<"matrix "<<col<<","<<lane<<" native="<<std::bit_cast<std::uint32_t>(output.basis[col][lane])<<" source="<<expected<<'\n';}
            }
            check(std::memcmp(&output.position,memory.data()+0x210020,12)==0&&std::memcmp(&output.basis,memory.data()+0x210030,64)==0,"complete original attachment position and basis");
            check(output.angles==t::Angles{123,456,789}&&output.flags==0x89abcdef&&std::memcmp(output.angles.data(),memory.data()+0x210018,6)==0&&transform_read<std::uint32_t>(memory.data(),0x21118c)==output.flags,"attachment preserves existing angle and flag controls");
            for(unsigned axis=0;axis<4;++axis)check(std::bit_cast<std::uint32_t>(output.basis[axis][3])==std::bit_cast<std::uint32_t>(matrix[axis][3]),"attachment preserves copied W lanes");
            check(std::memcmp(output.basis[3].data(),matrix[3].data(),16)==0,"attachment basis retains copied translation rather than replacing it from offset position");
            if(std::memcmp(&output.position,matrix[3].data(),12))++preserved_translation;
            if(std::any_of(matrix.begin(),matrix.begin()+3,[](const auto& axis){return axis[0]==0&&axis[1]==0&&axis[2]==0;})){++zero_axes;}
            if(object){++object_parents;}else{++actor_parents;}++attachments;
        }
        g::CinematicObject output;output.position={7,8,9};output.basis=t::identity();const auto before=output.basis;
        for(const auto node:{std::uint32_t(parent.nodes().size()),256u,UINT32_MAX}){bool refused{};try{g::attach_cinematic_object(output,parent,node,{1,1,1},{});}catch(const std::out_of_range&){refused=true;}check(refused&&output.basis==before&&output.position.x==7,"full node ordinal bounds refuse before mutation without low-byte wrapping");++refusals;}
    }
    std::array<std::byte,35> short_command{};bool refused{};try{(void)g::CinematicObjectAttachment::read(short_command);}catch(const std::invalid_argument&){refused=true;}check(refused,"short attachment record refuses");++refusals;
    check(preserved_translation&&zero_axes&&actor_parents==object_parents,"actual offset zero-axis and both parent lookup cases exercised");
    std::cout<<"{\"checks\":"<<checks<<",\"attachments\":"<<attachments<<",\"actor_parents\":"<<actor_parents<<",\"object_parents\":"<<object_parents<<",\"zero_axis_cases\":"<<zero_axes<<",\"distinct_position_translation\":"<<preserved_translation<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<location<<" "<<error.what()<<'\n';return 1;}
