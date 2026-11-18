#include "game/native/gameplay_scenario/camera_curves.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace t=reo::native::transform_math;
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},publications{},cases{};unsigned current_case{};
void check(bool value){++checks;
        if(!value)throw std::runtime_error("Camera curve comparison failed at case"+std::to_string(current_case));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x1b82a0:check(GPR_U32(context,4)==43);SET_GPR_U32(context,2,0);break;
    case 0x375920:++publications;break;
    default:throw std::runtime_error("Unadmitted camera curve helper");}
    context->pc=GPR_U32(context,31);
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
void key(std::uint8_t* memory,std::uint32_t at,const s::CameraKey& value){
    transform_write(memory,at+1,value.type);transform_write(memory,at+2,value.frame);
    transform_write(memory,at+4,value.point);transform_write(memory,at+20,value.lens);
    transform_write(memory,at+24,value.roll);transform_write(memory,at+28,value.control);
    transform_write(memory,at+48,value.roll_control);transform_write(memory,at+52,value.lens_control);
}
void parameters(std::uint8_t* memory,std::uint32_t at,const s::CameraParameters& value){
    transform_write(memory,at+88,value.pose.eye);transform_write(memory,at+100,value.pose.aim);
    transform_write(memory,at+124,value.pose.up);transform_write(memory,at+152,value.far_plane);
    transform_write(memory,at+156,value.near_plane);transform_write(memory,at+160,value.lens);
    transform_write(memory,at+172,value.pose.roll);
}
int main(){
    std::vector<std::uint8_t> memory(0x2000000);PS2Runtime runtime;std::uint32_t random=0x5c09a0;
    const auto scalar=[&](){return float(std::int32_t(random_word(random)%200001)-100000)/64.f;};
    const auto make=[&](){return s::CameraKey{std::uint8_t(random_word(random)),std::uint16_t(random_word(random)),{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},scalar(),scalar(),scalar(),random_word(random)};};
    for(unsigned index=0;index<131072;++index){
        current_case=index;const auto frame=index&1?random_word(random):random_word(random)&65535u;
        std::optional<s::CameraSegment> eye=s::CameraSegment{make(),make()},aim=s::CameraSegment{make(),make()};
        if(index%17==0)eye->next.frame=65535;
        if(index%19==0)aim->next.frame=65535;
        if(index%23==0)eye->next.frame=eye->current.frame;
        if(index%29==0)aim->next.frame=aim->current.frame;
        if(index%5==0)eye->current.roll_control=0;
        if(index%7==0)eye->current.lens_control=0;
        if(index%11==0)eye->next.roll=eye->current.roll;
        if(index%13==0)eye->next.lens=eye->current.lens;
        s::CameraParameters native{{{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},random_word(random)},scalar(),scalar(),scalar()};
        for(unsigned byte=0;byte<176;++byte)memory[0x3240e0+byte]=std::uint8_t(random_word(random));
        parameters(memory.data(),0x3240e0,native);
        key(memory.data(),0x10000,eye->current);key(memory.data(),0x10038,eye->next);
        key(memory.data(),0x11000,aim->current);key(memory.data(),0x11038,aim->next);
        if(index%31==0)eye.reset();
        if(index%37==0)aim.reset();
        transform_write(memory.data(),0x38ec90,eye?0x10000u:0u);transform_write(memory.data(),0x38ec94,aim?0x11000u:0u);
        transform_write(memory.data(),0x38eca8,frame);const auto before=publications;
        std::memcpy(memory.data()+0x18000,memory.data()+0x3240e0,176);
        R5900Context context;context.pc=0x5c09a0;SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);
        const auto sampled=s::sample_camera_parameters(native,eye,aim,frame);check(sampled==bool(eye&&aim));check(publications-before==std::uint64_t(sampled));
        parameters(memory.data(),0x18000,native);
        for(unsigned byte=0;byte<176;++byte)check(memory[0x18000+byte]==memory[0x3240e0+byte]);
        ++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"publications\":"<<publications<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
