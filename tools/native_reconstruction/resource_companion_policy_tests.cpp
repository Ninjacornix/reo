#include "game/native/gameplay_effects/resource_companion.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <string>
#include <vector>
namespace e=reo::native::gameplay_effects;
namespace m=reo::native::transform_math;
unsigned checks{},calls{};
void check(bool value,std::source_location where=std::source_location::current()){++checks;if(!value)throw std::runtime_error(std::string(where.file_name())+":"+std::to_string(where.line()));}
template<class T>T get(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
bool companion_policy_capture{};
struct CompanionPolicyCapture {unsigned children{},released{},retired{},spawned{},cues{};std::int16_t sample_time{};std::uint16_t child_attributes{},cue{};float fade_delta{};bool faded{};} companion_policy_observed;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};constexpr unsigned work=0x120000;
    if(companion_policy_capture)switch(context->pc){
    case 0x652880:check(GPR_U32(context,4)==work&&GPR_U32(context,5)==0xa00000&&GPR_U32(context,6)==1);++companion_policy_observed.children;companion_policy_observed.sample_time=get<std::int16_t>(memory,work+0x10);companion_policy_observed.child_attributes=std::uint16_t(GPR_U32(context,7));SET_GPR_U32(context,2,1);done();return;
    case 0x652d60:check(GPR_U32(context,4)==work);++companion_policy_observed.released;done();return;
    case 0x651d00:check(GPR_U32(context,4)==work);++companion_policy_observed.retired;done();return;
    case 0x654180:check(GPR_U32(context,4)==work);companion_policy_observed.faded=true;companion_policy_observed.fade_delta=context->f[12];done();return;
    case 0x6b2680:check(GPR_U32(context,5)==work+0x44);++companion_policy_observed.spawned;done();return;
    case 0x1b8c70:++companion_policy_observed.cues;companion_policy_observed.cue=std::uint16_t(GPR_U32(context,5));done();return;
    default:break;
    }
    switch(context->pc){
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted companion policy call "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_visuals.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* memory,unsigned function,std::array<std::uint32_t,7> args={}){R5900Context context;context.pc=function;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);PS2Runtime runtime;original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return context;}
#include "tools/native_reconstruction/resource_companion_policy_tests.inc"
int main()try{std::vector<std::uint8_t> memory(0x2000000);compare_resource_companion_policy(memory);std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<companion_policy_cases<<",\"renders\":"<<companion_policy_renders<<",\"fades\":"<<companion_policy_fades<<",\"retirements\":"<<companion_policy_retirements<<",\"spawn_intents\":"<<companion_policy_spawn_intents<<",\"audio_intents\":"<<companion_policy_audio_intents<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";}catch(const std::exception& error){std::cerr<<error.what()<<" cases="<<companion_policy_cases<<" seed="<<companion_policy_seed<<" phase="<<companion_policy_phase<<'\n';return 1;}
