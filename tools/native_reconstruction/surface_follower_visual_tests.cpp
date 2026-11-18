#include "game/native/gameplay_effects/surface_follower_visual.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <source_location>
#include <vector>
namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},retirements{};constexpr unsigned work_at=0x20000,parent_at=0x22000;bool original_retired{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Follower visual "+std::to_string(at.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
 case 0x651d00:check(GPR_U32(context,4)==work_at);original_retired=true;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted follower visual helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);}
int main()try{
 std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();
 for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned present=0;present<2;++present)for(unsigned lane=0;lane<4;++lane)for(unsigned n=0;n<65536;++n){
  const auto signed_n=std::bit_cast<std::int16_t>(std::uint16_t(n));e::SurfaceFollowerVisual state;state.phase=std::uint8_t(phase);state.visible=n&1;state.flags=n*317u;state.column=lane==3?1:signed_n;state.row=signed_n;state.interval=lane==1?signed_n:0;state.delay=lane==0?signed_n:0;
  state.position={float(int(n%13)-6),float(int(n%17)-8),float(int(n%23)-11)};state.scale={2,3,4};state.color={.2f,.3f,.4f,.5f};state.tile_step={.5f,.25f};state.tile_origin={2,3};state.tile_extent={4,5};state.tile_cursor={float(int(n%7)-3)*.25f,float(int(n%11)-5)*.125f};const m::Vector parent{100,200,300};
  memory[work_at+8]=state.phase;memory[work_at+1]=state.visible;put(memory,work_at+0x24,present?parent_at:0u);put(memory,parent_at+0x38,parent);
  const auto export_state=[&](const auto& value,unsigned offset){put(memory,work_at+offset,value);};
  export_state(state.column,12);export_state(state.row,14);export_state(state.interval,16);export_state(state.delay,18);export_state(state.flags,0x200);export_state(state.position,0x38);export_state(state.scale,0xb4);export_state(state.color,0x208);export_state(state.tile_step,0xcc);export_state(state.tile_origin,0x218);export_state(state.tile_extent,0x220);export_state(state.tile_cursor,0x228);original_retired=false;
  R5900Context context;PS2Runtime runtime;context.pc=0x58db50;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
  const auto retired=e::advance_surface_follower_visual(state,present?std::optional(parent):std::nullopt);check(retired==original_retired&&state.phase==memory[work_at+8]&&state.visible==bool(memory[work_at+1]));
  const auto equal=[&](const auto& value,unsigned offset){check(std::memcmp(&value,memory+work_at+offset,sizeof value)==0);};
  equal(state.column,12);equal(state.row,14);equal(state.interval,16);equal(state.delay,18);equal(state.flags,0x200);equal(state.position,0x38);equal(state.scale,0xb4);equal(state.color,0x208);equal(state.tile_step,0xcc);equal(state.tile_origin,0x218);equal(state.tile_extent,0x220);equal(state.tile_cursor,0x228);retirements+=retired;++cases;
 }
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
