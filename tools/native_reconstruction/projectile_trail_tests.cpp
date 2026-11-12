#include "game/native/gameplay_effects/projectile_trail.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},requests{},retirements{},known_misses{};constexpr unsigned work_at=0x20000,parent_at=0x22000;
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Projectile visual "+std::to_string(at.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
struct Emissions final:e::ProjectileTrailEmission{e::WorkStatus status{};std::optional<e::WorkRequest> observed;e::WorkStatus emit(const e::WorkRequest& q)override{observed=q;return status;}}emissions;
std::optional<e::WorkRequest> observed;bool original_retired{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;switch(context->pc){
 case 0x6525c0:{check(!GPR_U32(context,4)&&GPR_U32(context,5)==parent_at+0x38&&GPR_U32(context,7)==0x10&&GPR_U32(context,8)==UINT32_MAX&&GPR_U32(context,9)==0x1a193);e::WorkRequest q;q.position=get<m::Vector>(memory,GPR_U32(context,5));q.variant=std::int16_t(GPR_U32(context,6));q.effect=std::uint16_t(GPR_U32(context,7));q.child_mask=GPR_U32(context,8);q.flags=GPR_U32(context,9);observed=q;SET_GPR_U32(context,2,emissions.status==e::WorkStatus::completed?0x24000:0);break;}
 case 0x651d00:check(GPR_U32(context,4)==work_at);original_retired=true;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted projectile visual helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);
}
int main()try{
 std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();
 for(unsigned phase:{0u,1u,2u,255u})for(unsigned n=0;n<65536;++n){
  e::ProjectileTrailState state;state.phase=std::uint8_t(phase);state.visible=n&1;e::ProjectileTrailMotion motion;const auto active=std::uint8_t(n>>8);motion.active=active!=0;motion.kind=std::uint8_t(n);const auto variant=std::uint8_t(n*37+(n>>8)*3);motion.position={std::bit_cast<float>(n*317u),float(int(n%19)-9)*.125f,float(int(n%23)-11)*.5f};
  for(unsigned c=0;c<4;++c)for(unsigned r=0;r<4;++r){motion.basis[c][r]=std::bit_cast<float>(n*314159u+c*37+r*307);state.basis[c][r]=float(c*4+r);}
  memory[work_at+8]=state.phase;memory[work_at+1]=state.visible;put(memory,work_at+0x24,parent_at);put(memory,work_at+0x50,state.basis);memory[parent_at]=active;memory[parent_at+4]=motion.kind;put(memory,parent_at+0x50,motion.basis);put(memory,parent_at+0x38,motion.position);memory[0x7123b0]=variant;emissions.status=e::WorkStatus((n>>8)%3);emissions.observed.reset();observed.reset();original_retired=false;
  R5900Context context;PS2Runtime runtime;context.pc=0x653cc0;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
  const auto result=e::advance_projectile_trail(state,motion,variant,emissions);check(result.available&&result.retire==original_retired);check(state.phase==memory[work_at+8]&&state.visible==bool(memory[work_at+1])&&std::memcmp(&state.basis,memory+work_at+0x50,64)==0);check(bool(observed)==bool(emissions.observed));
  if(observed){const auto& q=*emissions.observed;check(!q.basis&&q.position&&q.effect==observed->effect&&q.variant==observed->variant&&q.child_mask==observed->child_mask&&q.flags==observed->flags&&q.update==e::WorkUpdate::ordinary&&std::memcmp(&*q.position,&*observed->position,12)==0);++requests;known_misses+=emissions.status!=e::WorkStatus::completed;}
  retirements+=result.retire;++cases;
 }
 e::ProjectileTrailState state;e::ProjectileTrailMotion motion;motion.active=true;motion.kind=15;emissions.status=e::WorkStatus::unavailable;const auto rejected=e::advance_projectile_trail(state,motion,0,emissions);check(!rejected.available&&!rejected.retire&&state.phase==1&&state.visible);
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"requests\":"<<requests<<",\"retirements\":"<<retirements<<",\"known_misses\":"<<known_misses<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
