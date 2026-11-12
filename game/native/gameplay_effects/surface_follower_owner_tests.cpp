#include "periodic_visuals.hpp"
#include "../gameplay_world/forward_pose_visuals.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <source_location>
namespace e=reo::native::gameplay_effects;namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;
unsigned checks{},banks{},constructors{},frames{},identity_cases{},budget_cases{};
void check(bool ok,std::source_location at=std::source_location::current()){++checks;if(!ok)throw std::runtime_error("Surface follower owner "+std::to_string(at.line()));}
g::Profile profile(){g::Profile p;p.layouts.push_back({});p.entities.capacity=256;return p;}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);input.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(input));}return out;}
g::actors::EntityId parent(g::PoseWorkPool& pool,m::Vector point){const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto actor=pool.resolve(made.id);check(actor&&actor->pose_work);actor->active=true;actor->pose_work->kind=100;actor->position={point.x,point.y,point.z};return made.id;}
#ifdef REO_SURFACE_FOLLOWER_ORIGINAL
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
constexpr unsigned source_work=0x20000,source_parent=0x22000;bool source_allocate{},source_retired{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
 case 0x651a30:check(!GPR_U32(context,4)&&GPR_U32(context,5)==1&&!GPR_U32(context,6));if(source_allocate){std::memset(memory+source_work,0,0x250);memory[source_work+2]=7;}SET_GPR_U32(context,2,source_allocate?source_work:0);break;
 case 0x651d00:check(GPR_U32(context,4)==source_work);source_retired=true;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted follower owner helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);}
void invoke(std::uint8_t* memory,unsigned pc,unsigned argument){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,argument);SET_GPR_U32(&context,5,0);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);}
void compare(const e::SurfaceFollowerVisual& state,const std::uint8_t* memory){
 check(state.phase==memory[source_work+8]&&state.visible==bool(memory[source_work+1]));
 const auto equal=[&](const auto& value,unsigned offset){check(std::memcmp(&value,memory+source_work+offset,sizeof value)==0);};
 equal(state.column,12);equal(state.row,14);equal(state.interval,16);equal(state.delay,18);equal(state.flags,0x200);equal(state.position,0x38);equal(state.scale,0xb4);equal(state.color,0x208);equal(state.tile_step,0xcc);equal(state.tile_origin,0x218);equal(state.tile_extent,0x220);equal(state.tile_cursor,0x228);
}
#endif
int main(int argc,char** argv)try{
 check(argc==1||argc==2);
 if(argc==2){const auto assets=corpus(argv[1]);for(unsigned asset=0;asset<assets.size();asset+=2){
  auto session=std::make_shared<g::Session>();g::World world(profile(),session);g::PoseWorkPool pool(world);const auto id=parent(pool,{1,2,3});const auto actor=pool.resolve(id);const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);e::PeriodicVisuals visuals(bank,session->random);g::ForwardPoseVisuals actions(world,visuals,0);
#ifdef REO_SURFACE_FOLLOWER_ORIGINAL
  std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);source_allocate=true;std::memcpy(memory+source_parent+0x38,&actor->position,12);invoke(memory,0x58da20,source_parent);check(memory[source_work]&&memory[source_work+2]==7&&!memory[source_work+4]&&!memory[source_work+0x30]&&memory[source_work+0x1fe]==1&&transform_read<unsigned>(memory,source_work+0x24)==source_parent&&transform_read<unsigned>(memory,source_work+0x14)==0x58dab0&&transform_read<unsigned>(memory,source_work+0x18)==0x371ef0);
#endif
  const auto made=actions.follower_visual(id);check(made&&bool(*made)&&visuals.size()==1&&visuals.piece_count()==0);++constructors;auto state=visuals.surface_follower_state(*made);check(state&&!state->visible&&state->phase==0);
  std::shared_ptr<const e::EffectFrame> retained;
  for(unsigned frame=0;frame<80;++frame){
   const m::Vector point{float(frame+10),float(frame+20),float(frame+30)};if(frame){check(actions.follower_position(*made,point));}
#ifdef REO_SURFACE_FOLLOWER_ORIGINAL
   if(frame){std::memcpy(memory+source_work+0x38,&point,12);}
   source_retired=false;invoke(memory,0x58dab0,source_work);check(!source_retired);
#endif
   check(visuals.update({}).status==e::VisualStatus::completed);state=visuals.surface_follower_state(*made);check(state&&state->phase==1&&state->visible);if(frame)check(std::memcmp(&state->position,&point,12)==0);else check(state->position.x==1&&state->position.y==2&&state->position.z==3&&state->delay==21);
#ifdef REO_SURFACE_FOLLOWER_ORIGINAL
   compare(*state,memory);
#endif
   if(frame==0){retained=visuals.retain();}
   ++frames;
  }
  check(retained&&retained->visuals.size()==1&&retained->visuals[0].surface_follower&&retained->visuals[0].category==7&&retained->visuals[0].pieces.empty()&&retained->visuals[0].surface_follower->position.x==1);
  const auto old_physical=pool.physical_slot(id);check(pool.retire(id,true)==g::PoseWorkStatus::completed);const auto replacement=parent(pool,{100,200,300});check(replacement!=id&&pool.physical_slot(replacement)==old_physical);check(visuals.update({}).status==e::VisualStatus::completed&&visuals.surface_follower_state(*made)->position.x==89);++identity_cases;
  check(visuals.retire(*made)&&!visuals.surface_follower_state(*made)&&!actions.follower_position(*made,{}));
  const auto null_parent=visuals.create_surface_follower_visual(world,{});check(null_parent.status==e::WorkStatus::completed);
#ifdef REO_SURFACE_FOLLOWER_ORIGINAL
  invoke(memory,0x58da20,0);source_retired=false;invoke(memory,0x58dab0,source_work);check(source_retired);
#endif
  check(visuals.update({}).status==e::VisualStatus::completed&&visuals.size()==0);++constructors;
  // Retire/reuse before the first callback still reads the retained old parent.
  const auto early=visuals.create_surface_follower_visual(world,replacement);check(early.status==e::WorkStatus::completed);check(pool.retire(replacement,true)==g::PoseWorkStatus::completed);const auto last=parent(pool,{400,500,600});check(visuals.update({}).status==e::VisualStatus::completed&&visuals.surface_follower_state(early.id)->position.x==100);check(visuals.retire(early.id));++identity_cases;
  for(unsigned i=0;i<168;++i){check(visuals.create_surface_follower_visual(world,last).status==e::WorkStatus::completed);++constructors;}check(visuals.size()==168&&visuals.piece_count()==0&&visuals.create_surface_follower_visual(world,last).status==e::WorkStatus::pool_full);const auto full=actions.follower_visual(last);check(full&&!*full);check(visuals.update({}).status==e::VisualStatus::completed&&visuals.size()==168&&visuals.piece_count()==0);++budget_cases;
#ifdef REO_SURFACE_FOLLOWER_ORIGINAL
  source_allocate=false;invoke(memory,0x58da20,source_parent);
#endif
  visuals.close();check(!actions.bound_to(world)&&retained->visuals[0].surface_follower->position.x==1);++banks;
 }}std::cout<<"{\"checks\":"<<checks<<",\"owned_banks\":"<<banks<<",\"constructors\":"<<constructors<<",\"frames\":"<<frames<<",\"budget_cases\":"<<budget_cases<<",\"identity_cases\":"<<identity_cases<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
