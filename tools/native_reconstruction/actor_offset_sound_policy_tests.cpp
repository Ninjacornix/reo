#include "game/native/gameplay_world/actor_offset_sound_policy.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace a=reo::native::gameplay_audio;
unsigned checks{},cases{},calls{},requests{},silent{};constexpr unsigned actor_at=0x20000;
std::optional<a::Request> observed;unsigned observed_gate{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Actor offset gate "+std::to_string(at.line())+" case "+std::to_string(cases));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;switch(context->pc){
 case 0x1b93d0:check(GPR_U32(context,4)==12&&GPR_U32(context,7)==actor_at+0x38&&GPR_U32(context,8)==1&&!GPR_U32(context,9));observed=a::Request{GPR_U32(context,4),GPR_U32(context,5),UINT32_MAX,UINT32_MAX,std::uint8_t(GPR_U32(context,10))};observed_gate=GPR_U32(context,6);break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted offset audio helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);
}
int main()try{
 std::vector<std::uint8_t> memory(0x2000000);
 for(std::uint32_t event:{0u,7u,128u,0xdeadffffu})for(unsigned n=0;n<65536;++n){
  const g::ActorSoundState state{std::uint8_t(n),std::uint8_t(n>>8)};memory[actor_at+0x554]=state.allocation_slot;memory[actor_at+0x33]=state.program_variant;observed.reset();
  R5900Context context;PS2Runtime runtime;context.pc=0x1b9310;SET_GPR_U32(&context,4,actor_at);SET_GPR_U32(&context,5,event);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
  const auto plan=g::plan_actor_offset_sound(state,event);check(plan.available&&bool(plan.request)==bool(observed));if(observed){check(plan.request->bank==observed->bank&&plan.request->event==observed->event&&plan.request->gain==observed->gain&&plan.request->pan==observed->pan&&plan.request->tag==observed->tag&&observed_gate==state.allocation_slot);++requests;}else ++silent;++cases;
 }
 check(!g::plan_actor_offset_sound({},7).available);std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"requests\":"<<requests<<",\"silent\":"<<silent<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
