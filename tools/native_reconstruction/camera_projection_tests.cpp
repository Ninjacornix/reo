#include "game/native/gameplay_scenario/camera_projection.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace t=reo::native::transform_math;namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},publications{};unsigned current_case{};std::vector<unsigned> order;
void check(bool value){++checks;if(!value)throw std::runtime_error("Camera projection comparison case"+std::to_string(current_case));}
void same(const t::Matrix& native,const t::Matrix& original,std::source_location where=std::source_location::current()){for(unsigned column=0;column<4;++column)for(unsigned row=0;row<4;++row){const auto a=std::bit_cast<std::uint32_t>(native[column][row]),b=std::bit_cast<std::uint32_t>(original[column][row]);if(a!=b)throw std::runtime_error("Camera projection case"+std::to_string(current_case)+" line"+std::to_string(where.line())+" column"+std::to_string(column)+" row"+std::to_string(row)+" native"+std::to_string(a)+" original"+std::to_string(b));++checks;}}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x1af780:{const auto operation=GPR_U32(context,4);check(operation==24||operation==22);check(GPR_U32(context,5)==(operation==24?0x324120u:0x3240e0u));order.push_back(operation);context->pc=GPR_U32(context,31);return;}
    default:throw std::runtime_error("Unadmitted camera projection helper");}
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
struct Sink final:s::CameraDisplaySink {
    std::uint8_t* memory;s::CameraDisplayState& state;t::Matrix previous_view;unsigned step{};
    Sink(std::uint8_t* m,s::CameraDisplayState& s):memory(m),state(s),previous_view(s.view){}
    void viewport(const s::CameraViewport& viewport,const s::CameraProjectionMatrices& projection)override{
        check(step++==0&&order[0]==24);same(previous_view,state.view);
        const auto original=transform_read<s::CameraViewport>(memory,0x324120);check(std::memcmp(&viewport,&original,sizeof viewport)==0);
        same(projection.perspective,transform_read<t::Matrix>(memory,0x70003f00));same(projection.scaled,transform_read<t::Matrix>(memory,0x294d00));
        same(projection.first_composite,transform_read<t::Matrix>(memory,0x294d40));same(projection.second_composite,transform_read<t::Matrix>(memory,0x294d80));++publications;
    }
    void view(const t::Matrix& matrix)override{check(step++==1&&order[1]==22);same(matrix,transform_read<t::Matrix>(memory,0x3240e0));++publications;}
};
int main(){
    static_assert(sizeof(s::CameraViewport)==24);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());transform_write(memory.data(),0x294e00,t::identity());PS2Runtime runtime;std::uint32_t random=0x375920;
    const auto scalar=[&](){return float(std::int32_t(random_word(random)%200001)-100000)/64.f;};
    const auto matrix=[&](){t::Matrix value;for(auto& column:value)for(auto& lane:column)lane=scalar();return value;};
    for(unsigned index=0;index<65536;++index){
        current_case=index;s::CameraProjectionContext context{320+float(random_word(random)%1000),240+float(random_word(random)%1000),320+float(random_word(random)%1600),240+float(random_word(random)%1000),matrix(),matrix()};
        s::CameraParameters parameters{{{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},{scalar(),scalar(),scalar()},random_word(random)},10000+float(random_word(random)%50000),1+float(random_word(random)%100),index%17?1+float(random_word(random)%179):0.0f};
        s::CameraDisplayState state;state.viewport={std::int32_t(random_word(random)),std::int32_t(random_word(random)),33,448,std::int32_t(random_word(random)),scalar()};state.view=matrix();
        transform_write(memory.data(),0x324120,state.viewport);transform_write(memory.data(),0x324138,parameters.pose.eye);transform_write(memory.data(),0x324144,parameters.pose.aim);transform_write(memory.data(),0x32415c,parameters.pose.up);
        transform_write(memory.data(),0x324178,parameters.far_plane);transform_write(memory.data(),0x32417c,parameters.near_plane);transform_write(memory.data(),0x324180,parameters.lens);transform_write(memory.data(),0x32418c,parameters.pose.roll);
        transform_write(memory.data(),0x2941a8,context.horizontal_extent);transform_write(memory.data(),0x2941b0,context.vertical_extent);transform_write(memory.data(),0x2941c8,context.width);transform_write(memory.data(),0x2941d0,context.height);
        transform_write(memory.data(),0x70003f80,context.first_transform);transform_write(memory.data(),0x294dc0,context.second_transform);
        const auto mode=std::bit_cast<std::int8_t>(std::uint8_t(index));transform_write(memory.data(),0x3243cf,mode);order.clear();
        R5900Context original;original.pc=0x375920;SET_GPR_U32(&original,29,0x700000);SET_GPR_U32(&original,31,0xabcdef);original_transform_port(memory.data(),&original,&runtime);check(original.pc==0xabcdef&&GPR_U32(&original,29)==0x700000&&order==std::vector<unsigned>{24,22});
        Sink sink(memory.data(),state);s::publish_camera_display(parameters,mode,context,state,sink);check(sink.step==2);check(parameters.lens==transform_read<float>(memory.data(),0x324180));++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"publications\":"<<publications<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
