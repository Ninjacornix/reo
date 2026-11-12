#include "game/native/animation/secondary_pose_math.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <limits>
#include <source_location>
namespace a=reo::native::animation;
std::uint64_t checks{},preparations{},queries{},collisions{},original_calls{},refusals{};
unsigned test_case{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Secondary pose math case "+std::to_string(test_case)+" line "+std::to_string(at.line()));
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Undeclared secondary pose math call "+std::to_string(context->pc));
    }
}
unsigned invoke(std::uint8_t* memory,unsigned pc,unsigned first,unsigned second,unsigned third=0,float f12=0){
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,first);SET_GPR_U32(&context,5,second);SET_GPR_U32(&context,6,third);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);context.f[12]=f12;
    original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);
}
void compare(std::uint8_t* memory,a::Vector first,a::Vector last,float radius,a::Vector point,float particle){
    const auto capsule=a::prepare_pose_capsule(first,last,radius);
    static_assert(sizeof(capsule)==56);constexpr unsigned input=0x100000,packed=0x110000,position=0x120000,result=0x130000;
    std::memcpy(memory+input,&first,12);std::memcpy(memory+input+12,&last,12);std::memcpy(memory+input+24,&radius,4);
    invoke(memory,0x61b250,input,packed);check(std::memcmp(&capsule,memory+packed,56)==0);++preparations;
    std::memcpy(memory+position,&point,12);a::Vector output{123,456,789};std::memcpy(memory+result,&output,12);
    const auto actual=a::constrain_pose_point(point,particle,capsule,output);const auto expected=invoke(memory,0x61b390,position,packed,result,particle);
    if(bool(expected)!=actual||std::memcmp(&output,memory+result,12)!=0){
        a::Vector source;std::memcpy(&source,memory+result,12);
        std::cerr<<"first "<<first.x<<','<<first.y<<','<<first.z<<" last "<<last.x<<','<<last.y<<','<<last.z<<" radius "<<radius<<" point "<<point.x<<','<<point.y<<','<<point.z<<" particle "<<particle<<" statuses "<<actual<<','<<expected<<" native "<<output.x<<','<<output.y<<','<<output.z<<" source "<<source.x<<','<<source.y<<','<<source.z<<'\n';
    }
    check(bool(expected)==actual);check(std::memcmp(&output,memory+result,12)==0);check(std::memcmp(&point,memory+position,12)==0);++queries;collisions+=actual;++test_case;
}
#include "secondary_pose_contacts_tests.inc"
int main(int argc,char** argv)try{
    check(argc==2);
    const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    std::uint32_t random=0x4f153821;const auto next=[&](){random=random*1664525u+1013904223u;return random;};
    const auto value=[&](){return float(std::int32_t(next()%4097)-2048)/32.f;};
    for(unsigned i=0;i<65536;++i){const a::Vector first{value(),value(),value()},last{value(),value(),value()},point{value(),value(),value()};const auto radius=float(next()%1025)/32.f,particle=float(next()%129)/32.f;compare(memory.data(),first,last,radius,point,particle);}
    for(unsigned axis=0;axis<3;++axis)for(float length:{0.f,1.f,10.f,-10.f})for(float radius:{0.f,1.f,10.5f})for(float particle:{0.f,1.f,4.f})for(float offset:{-11.f,-10.f,-1.f,0.f,.0001f,.001f,1.f,10.f,11.f})for(float axial:{-15.f,-10.f,-.001f,0.f,.001f,5.f,10.f,15.f}){
        std::array<float,3> last{},point{};last[axis]=length;point[axis]=axial;point[(axis+1)%3]=offset;compare(memory.data(),{},{last[0],last[1],last[2]},radius,{point[0],point[1],point[2]},particle);
    }
    for(float bad:{-1.f,std::numeric_limits<float>::infinity(),std::numeric_limits<float>::quiet_NaN()}){
        bool caught{};try{(void)a::prepare_pose_capsule({},{1,0,0},bad);}catch(const std::domain_error&){caught=true;}check(caught);++refusals;
    }
    contacts_tests(memory.data(),argv[1]);
    std::cout<<"{\"checks\":"<<checks<<",\"preparations\":"<<preparations<<",\"queries\":"<<queries<<",\"collisions\":"<<collisions<<",\"refusals\":"<<refusals<<",\"contact_gates\":"<<contact_gates<<",\"contact_models\":"<<contact_models<<",\"contact_refusals\":"<<contact_refusals<<",\"joint_patches\":"<<joint_patches<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
