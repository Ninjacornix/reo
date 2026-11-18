#include "game/native/gameplay_scenario/camera_math.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <vector>
namespace t=reo::native::transform_math;
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},camera_cases{},basis_cases{},inverse_cases{};
std::string phase;unsigned current_case{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Native camera math comparison failed");}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted camera math helper");}
}
void same(const t::Matrix& a,const t::Matrix& b){for(unsigned column=0;column<4;++column)for(unsigned lane=0;lane<4;++lane){const auto native=std::bit_cast<std::uint32_t>(a[column][lane]),original=std::bit_cast<std::uint32_t>(b[column][lane]);if(native!=original)throw std::runtime_error(phase+" case "+std::to_string(current_case)+" column "+std::to_string(column)+" lane "+std::to_string(lane)+" native "+std::to_string(native)+" original "+std::to_string(original));++checks;}}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
int main(){
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());transform_write(memory.data(),0x294e00,t::identity());PS2Runtime runtime;std::uint32_t random=0x375a50;
    const auto invoke=[&](std::uint32_t address,std::uint32_t a0=0,std::uint32_t a1=0,std::uint32_t a2=0){R5900Context context;context.pc=address;SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,5,a1);SET_GPR_U32(&context,6,a2);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);};
    const auto scalar=[&](){return float(std::int32_t(random_word(random)%200001)-100000)/64.f;};
    for(unsigned index=0;index<131072;++index){
        current_case=index;phase="camera";s::CameraPose pose{{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},random_word(random)};
        if(index<8){pose.eye={};pose.aim=index&1?t::Vector{}:t::Vector{0,0,1};pose.up=index&2?t::Vector{}:t::Vector{0,1,0};pose.roll=index&4?0xffffu:0u;}
        transform_write(memory.data(),0x324138,pose.eye);transform_write(memory.data(),0x324144,pose.aim);transform_write(memory.data(),0x32415c,pose.up);transform_write(memory.data(),0x32418c,pose.roll);
        invoke(0x375a50);same(s::camera_view(pose),transform_read<t::Matrix>(memory.data(),0x3240e0));++camera_cases;
        const t::Vector forward{pose.eye.x-pose.aim.x,pose.eye.y-pose.aim.y,pose.eye.z-pose.aim.z};transform_write(memory.data(),0x10000,forward);transform_write(memory.data(),0x11000,pose.up);
        phase="basis";auto previous=t::identity();previous[3]={scalar(),scalar(),scalar(),scalar()};transform_write(memory.data(),0x12000,previous);invoke(0x191820,0x12000,0x10000,0x11000);t::direction_basis(previous,forward,pose.up);same(previous,transform_read<t::Matrix>(memory.data(),0x12000));++basis_cases;
        auto matrix=t::direction_basis(forward,pose.up);matrix[3]={pose.eye.x,pose.eye.y,pose.eye.z,1};transform_write(memory.data(),0x12000,matrix);
        phase="inverse";invoke(0x191220,0x12000);same(t::inverse_orthonormal(matrix),transform_read<t::Matrix>(memory.data(),0x12000));++inverse_cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"camera_cases\":"<<camera_cases<<",\"basis_cases\":"<<basis_cases<<",\"inverse_cases\":"<<inverse_cases<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
