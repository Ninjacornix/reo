#include "game/native/animation/facial_pose_math.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <source_location>
#include <vector>
namespace a=reo::native::animation;namespace m=reo::native::transform_math;
std::uint64_t checks{},calls{},blends{},bases{},zero_cases{},alias_cases{},owned_samples{};unsigned serial{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Facial math case "+std::to_string(serial)+" line "+std::to_string(at.line()));
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted facial math source call "+std::to_string(context->pc));
    }
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
float random_float(std::uint32_t& state){return float(int(random_word(state)%65537)-32768)/256.f;}
void invoke(std::uint8_t* memory,unsigned entry,unsigned destination,unsigned first,unsigned second,unsigned fourth=0){
    R5900Context context;PS2Runtime runtime;context.pc=entry;SET_GPR_U32(&context,4,destination);SET_GPR_U32(&context,5,first);SET_GPR_U32(&context,6,second);SET_GPR_U32(&context,7,fourth);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
}
int main(int argc,char** argv)try{
    std::vector<std::uint8_t> memory(0x2000000);const auto identity=m::identity();std::memcpy(memory.data()+0x294e00,identity.data(),64);std::uint32_t random=0x67c990;
    for(serial=0;serial<262144;++serial){
        a::FacialMatrices matrices;a::FacialWeights weights;
        for(auto& matrix:matrices)for(unsigned row=0;row<4;++row)for(unsigned lane=0;lane<4;++lane){matrix[row][lane]=lane==3||row==2?std::bit_cast<float>(random_word(random)):random_float(random);}
        for(auto& weight:weights)weight=float(int(random_word(random)%513)-256)/256.f;
        if(serial%17==0){weights={};++zero_cases;}
        if(serial%29==0)weights={1,0,0,0,0,0};
        if(serial%37==0)for(auto& matrix:matrices){matrix[0]={0,0,0,0};matrix[1]={0,0,0,0};}
        if(serial%53==0)for(auto& matrix:matrices){matrix[0]={1,2,3,0};matrix[1]={2,4,6,0};}
        const auto ordinal=serial%8;for(unsigned bank=0;bank<6;++bank)std::memcpy(memory.data()+0x100000+bank*512+ordinal*64,matrices[bank].data(),64);std::memcpy(memory.data()+0x110000,weights.data(),24);
        const auto destination=serial%7<6?0x100000+unsigned(serial%7)*512+ordinal*64:0x120000;
        invoke(memory.data(),0x67c990,destination,0x110000,0x100000,ordinal);const auto blended=a::blend_facial_pose(matrices,weights);
        if(std::memcmp(blended.data(),memory.data()+destination,64))for(unsigned row=0;row<4;++row)for(unsigned lane=0;lane<4;++lane)if(std::bit_cast<unsigned>(blended[row][lane])!=transform_read<unsigned>(memory.data(),destination+16*row+4*lane))std::cerr<<"blend["<<row<<"]["<<lane<<"] native="<<std::hex<<std::bit_cast<unsigned>(blended[row][lane])<<" original="<<transform_read<unsigned>(memory.data(),destination+16*row+4*lane)<<std::dec<<'\n';
        check(std::memcmp(blended.data(),memory.data()+destination,64)==0);++blends;if(serial%7<6)++alias_cases;
        m::Vector first{random_float(random),random_float(random),random_float(random)},second{random_float(random),random_float(random),random_float(random)};
        if(serial%19==0)first={};
        if(serial%31==0)second=first;
        const m::Vector translation{std::bit_cast<float>(random_word(random)),std::bit_cast<float>(random_word(random)),std::bit_cast<float>(random_word(random))};auto prior=identity;prior[3]={translation.x,translation.y,translation.z,random_float(random)};
        std::memcpy(memory.data()+0x120000,prior.data(),64);transform_write(memory.data(),0x130000,first);transform_write(memory.data(),0x130010,second);
        invoke(memory.data(),0x1a5050,0x120000,0x130000,0x130010);const auto basis=a::facial_basis(first,second,translation);check(std::memcmp(basis.data(),memory.data()+0x120000,64)==0);++bases;
    }
    check(argc==2);std::ifstream owned(argv[1],std::ios::binary);unsigned count{};owned.read(reinterpret_cast<char*>(&count),4);check(owned&&count==18);
    for(unsigned asset=0;asset<count;++asset){
        unsigned facial_count{};owned.read(reinterpret_cast<char*>(&facial_count),4);check(owned&&facial_count>0&&facial_count<=8);
        std::array<m::Matrix,48> bank;owned.read(reinterpret_cast<char*>(bank.data()),3072);check(bool(owned));
        for(unsigned node=0;node<facial_count;++node)for(unsigned sample=0;sample<32;++sample){
            a::FacialMatrices matrices;for(unsigned pose=0;pose<6;++pose)matrices[pose]=bank[8*pose+node];a::FacialWeights weights;
            for(auto& weight:weights)weight=float(random_word(random)%151)/100.f;
            if(sample<6){weights={};weights[sample]=1;}
            if(sample==6)weights={};
            for(unsigned pose=0;pose<6;++pose)std::memcpy(memory.data()+0x100000+pose*512+node*64,matrices[pose].data(),64);
            std::memcpy(memory.data()+0x110000,weights.data(),24);
            invoke(memory.data(),0x67c990,0x120000,0x110000,0x100000,node);const auto result=a::blend_facial_pose(matrices,weights);check(std::memcmp(result.data(),memory.data()+0x120000,64)==0);++blends;++owned_samples;
        }
    }
    a::FacialMatrices invalid{};a::FacialWeights weights{1,0,0,0,0,0};invalid[0][0][0]=std::numeric_limits<float>::infinity();bool refused=false;try{(void)a::blend_facial_pose(invalid,weights);}catch(const std::domain_error&){refused=true;}check(refused);
    std::cout<<"{\"checks\":"<<checks<<",\"blends\":"<<blends<<",\"bases\":"<<bases<<",\"owned_matrix_assets\":"<<count<<",\"owned_matrix_samples\":"<<owned_samples<<",\"zero_cases\":"<<zero_cases<<",\"input_output_aliases\":"<<alias_cases<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<"case="<<serial<<" blends="<<blends<<" bases="<<bases<<" "<<error.what()<<'\n';return 1;}
