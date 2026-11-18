#include "game/native/gameplay_effects/actor_contact_channels.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},clones{},samples{},retirements{},rebinds{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Actor channel policy "+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* memory,unsigned address){return transform_read<T>(memory,address);}
template<class T>void put(std::uint8_t* memory,unsigned address,T value){transform_write(memory,address,value);}
struct Operations final:e::ActorContactOperations {
    unsigned rebinds{},clones{},samples{},variant{};std::int16_t sample_age{};
    bool rebind(e::ActorContactState& state)override{++rebinds;state.base_position={-9,8,7};state.basis=m::Matrix{{{{.5f,0,0,0}},{{0,2,0,0}},{{0,0,3,0}},{{1,2,3,1}}}};return true;}
    e::WorkStatus clone(const e::ActorContactState&,std::uint32_t value)override{++clones;variant=value;return e::WorkStatus::pool_full;}
    bool sample(const e::ActorContactState& state)override{++samples;sample_age=state.age;return true;}
};
Operations original;bool original_retire{},original_release{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    switch(context->pc){
    case 0x572030:o2_00572030_0x572030(memory,context,runtime);return;
    case 0x572290:{e::ActorContactState state;check(GPR_U32(context,4)==0x10000);original.rebind(state);put(memory,0x10044,state.base_position);put(memory,0x10050,*state.basis);put(memory,0x101f0,0x10050u);break;}
    case 0x571ec0:
        check(GPR_U32(context,4)==0x20000&&GPR_U32(context,5)==get<unsigned>(memory,0x101f0)&&GPR_U32(context,6)==0x10044&&GPR_U32(context,7)==memory[0x10004]);
        original.clone({},GPR_U32(context,8));break;
    case 0x6526f0:
        check(GPR_U32(context,4)==0x10000&&GPR_U32(context,5)==0x30000&&GPR_U32(context,6)==2);original.sample_age=get<std::int16_t>(memory,0x10010);++original.samples;SET_GPR_U32(context,2,1);break;
    case 0x652d60:check(GPR_U32(context,4)==0x10000);original_release=true;break;
    case 0x651d00:check(GPR_U32(context,4)==0x10000);original_retire=true;break;
    default:throw std::runtime_error("Unadmitted actor channel helper "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void export_state(std::uint8_t* memory,const e::ActorContactState& state){
    memory[0x10001]=state.visible;memory[0x10004]=state.mode;memory[0x10005]=state.clone;memory[0x10008]=state.phase;memory[0x10009]=state.pose_phase;memory[0x101e0]=state.parent_left;
    put(memory,0x1000c,state.cycle);put(memory,0x1000e,state.remaining);put(memory,0x10010,state.age);put(memory,0x10012,state.clone_timer);
    put(memory,0x10038,state.position);put(memory,0x10044,state.base_position);put(memory,0x101f0,state.basis?0x10050u:0u);if(state.basis)put(memory,0x10050,*state.basis);
    put(memory,0x10024,0x20000u);put(memory,0x101f4,0x392670u);put(memory,0x392688,0xdeadbeefu);
    memory[0x10031]=1;put(memory,0x10114,std::int16_t(2));put(memory,0x10134,0x30000u);memory[0x100f4]=0;
}
void compare(const std::uint8_t* memory,const e::ActorContactState& state){
    check(state.visible==bool(memory[0x10001])&&state.phase==memory[0x10008]&&state.pose_phase==memory[0x10009]&&state.parent_left==bool(memory[0x101e0]));
    check(state.cycle==get<std::int16_t>(memory,0x1000c)&&state.remaining==get<std::int16_t>(memory,0x1000e)&&state.age==get<std::int16_t>(memory,0x10010)&&state.clone_timer==get<std::int16_t>(memory,0x10012));
    check(std::memcmp(&state.position,memory+0x10038,12)==0&&std::memcmp(&state.base_position,memory+0x10044,12)==0);
    check(bool(state.basis)==bool(get<unsigned>(memory,0x101f0)));if(state.basis)check(std::memcmp(&*state.basis,memory+0x10050,64)==0);
}
int main()try{
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    for(unsigned mode=0;mode<16;++mode)for(unsigned variant:{0u,1u,2u,3u,4u,7u,8u,0x80000000u,0x80000003u,0xffffffffu}){
        const auto value=e::actor_contact_profile(mode,variant);const auto index=std::uint64_t(mode)+(variant&0x7fffffffu);check(bool(value)==(index<8));
        if(value){check(value->resource==memory[0x708580+index*2]&&value->variant==memory[0x708581+index*2]&&value->child_mask==memory[0x7123a0+value->resource]);}
    }
    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned pattern=0;pattern<16;++pattern)for(unsigned n=0;n<65536;++n){
        e::ActorContactState state;state.phase=std::uint8_t(phase);state.pose_phase=std::uint8_t((pattern>>2)%4);state.clone=pattern&1;state.visible=n%3!=0;state.parent_left=n%7==0;state.mode=std::uint8_t(n%8);
        state.cycle=std::bit_cast<std::int16_t>(std::uint16_t(n));state.remaining=std::bit_cast<std::int16_t>(std::uint16_t(n));state.age=std::bit_cast<std::int16_t>(std::uint16_t(n*257));state.clone_timer=std::bit_cast<std::int16_t>(std::uint16_t(n));
        state.position={1,2,3};state.base_position={4,5,6};if(n%2)state.basis=m::Matrix{};
        export_state(memory.data(),state);const std::uint8_t primary=pattern&2?3:2,secondary=n%5?2:3;memory[0x20008]=primary;memory[0x20009]=secondary;
        original={};original_retire=original_release=false;R5900Context context;PS2Runtime runtime;context.pc=0x572030;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        Operations native;const auto result=e::advance_actor_contact(state,primary,secondary,native);check(result.available&&result.retire==original_retire&&original_retire==original_release);compare(memory.data(),state);
        check(native.rebinds==original.rebinds&&native.clones==original.clones&&native.samples==original.samples&&native.variant==original.variant&&native.sample_age==original.sample_age);
        rebinds+=native.rebinds;clones+=native.clones;samples+=native.samples;retirements+=result.retire;++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"rebinds\":"<<rebinds<<",\"clones\":"<<clones<<",\"samples\":"<<samples<<",\"retirements\":"<<retirements<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
