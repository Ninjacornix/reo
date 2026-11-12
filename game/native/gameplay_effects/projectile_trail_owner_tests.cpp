#include "periodic_visuals.hpp"
#include "../gameplay_world/forward_pose_visuals.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
#include <cstring>
namespace e=reo::native::gameplay_effects;namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;
unsigned checks{},banks{},constructors{},frames{},budget_cases{},identity_cases{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Projectile visual owner "+std::to_string(at.line()));}
g::Profile profile(){g::Profile p;p.layouts.push_back({});p.entities.capacity=256;return p;}
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream input(path,std::ios::binary);unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);input.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(input));}return out;}
g::actors::EntityId parent(g::PoseWorkPool& pool){const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);const auto actor=pool.resolve(made.id);check(actor&&actor->pose_work);actor->active=true;actor->pose_work->kind=15;actor->pose_work->basis=m::identity();actor->pose_work->basis[3]={7,8,9,37};actor->position={1,2,3};return made.id;}
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
#include "reference.hpp"
#include "functions.h"
constexpr unsigned source_work=0x20000,source_parent=0x22000;bool source_allocate{},source_retired{};unsigned source_requests{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
 case 0x652390:check(GPR_U32(context,4)==0x12);SET_GPR_U32(context,2,source_allocate?source_work:0);break;
 case 0x6525c0:check(!GPR_U32(context,4)&&GPR_U32(context,5)==source_parent+0x38&&GPR_U32(context,6)==memory[0x7123b0]&&GPR_U32(context,7)==0x10&&GPR_U32(context,8)==UINT32_MAX&&GPR_U32(context,9)==0x1a193);++source_requests;SET_GPR_U32(context,2,0);break;
 case 0x651d00:check(GPR_U32(context,4)==source_work);source_retired=true;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted projectile owner helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);}
void invoke(std::uint8_t* memory,unsigned pc,unsigned argument){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,argument);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);}
#endif
int main(int argc,char** argv)try{
 check(argc==1||argc==2);
 if(argc==2){const auto assets=corpus(argv[1]);for(unsigned asset=0;asset<assets.size();asset+=2){
  auto session=std::make_shared<g::Session>();g::World world(profile(),session);g::PoseWorkPool pool(world);const auto id=parent(pool);const auto actor=pool.resolve(id);const auto bank=e::EffectBank::import(assets[asset],assets[asset+1]);e::PeriodicVisuals visuals(bank,session->random);g::ForwardPoseVisuals actions(world,visuals,0);check(actions.bound_to(world));const auto root=bank->geometry().resolve(0x12);
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
  std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();std::memcpy(memory+source_parent+0x50,&actor->pose_work->basis,64);std::memcpy(memory+source_parent+0x38,&actor->position,12);memory[source_parent]=1;memory[source_parent+4]=15;source_allocate=bool(root);invoke(memory,0x5def90,source_parent);
#endif
  const auto made=visuals.create_projectile_trail(world,id,0);++constructors;
  if(!root){check(made.status==e::WorkStatus::resource_missing&&!made.id&&visuals.size()==0);++banks;continue;}
  check(made.status==e::WorkStatus::completed&&bool(made.id)&&visuals.size()==1&&visuals.piece_count()==0);auto state=visuals.projectile_trail_state(made.id);check(state&&!state->state.visible&&state->state.phase==0&&state->geometry_root==*root&&state->resource==0x12&&state->draw_kind==26&&state->flags==0x8193&&std::memcmp(&state->state.basis,&actor->pose_work->basis,64)==0);
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
  check(memory[source_work]&&memory[source_work+1]==state->state.visible&&memory[source_work+2]==6&&memory[source_work+3]==state->draw_kind&&transform_read<std::uint32_t>(memory,source_work+0x200)==state->flags&&transform_read<std::int16_t>(memory,source_work+0x204)==state->resource&&transform_read<std::uint32_t>(memory,source_work+0x24)==source_parent&&std::memcmp(memory+source_work+0x50,&state->state.basis,64)==0);
#endif
  for(unsigned frame=0;frame<4;++frame){actor->position={float(frame+1),float(frame+2),float(frame+3)};
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
   std::memcpy(memory+source_parent+0x38,&actor->position,12);source_requests=0;source_retired=false;invoke(memory,0x653cc0,source_work);check(source_requests==1&&!source_retired);
#endif
   check(visuals.update({0,1,0}).status==e::VisualStatus::completed);state=visuals.projectile_trail_state(made.id);check(state&&state->state.phase==1&&state->state.visible&&state->state.basis[3][0]==actor->position.x&&state->state.basis[3][1]==actor->position.y&&state->state.basis[3][2]==actor->position.z&&state->state.basis[3][3]==37);
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
   check(state->state.phase==memory[source_work+8]&&state->state.visible==bool(memory[source_work+1])&&std::memcmp(&state->state.basis,memory+source_work+0x50,64)==0);
#endif
   ++frames;
  }
  const auto retained=visuals.retain();check(bool(retained));bool published=false;for(const auto& output:retained->visuals)if(output.id==made.id){check(output.projectile_trail&&output.visible&&output.category==6&&output.pieces.empty()&&output.projectile_trail->geometry_root==*root);published=true;}check(published);
  // Preserve the actual inactive-parent phase before retirement, even when
  // its physical pose slot is immediately reused for a new live generation.
  const auto physical=pool.physical_slot(id);check(pool.retire(id,true)==g::PoseWorkStatus::completed);const auto replacement=parent(pool);check(replacement!=id&&pool.physical_slot(replacement)==physical);
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
  memory[source_parent]=0;source_retired=false;invoke(memory,0x653cc0,source_work);check(!source_retired&&memory[source_work+8]==2&&!memory[source_work+1]);
#endif
  check(visuals.update({0,1,0}).status==e::VisualStatus::completed);state=visuals.projectile_trail_state(made.id);check(state&&state->state.phase==2&&!state->state.visible);
#ifdef REO_PROJECTILE_TRAIL_ORIGINAL
  source_retired=false;invoke(memory,0x653cc0,source_work);check(source_retired);
#endif
  check(visuals.update({0,1,0}).status==e::VisualStatus::completed&&!visuals.projectile_trail_state(made.id));for(const auto& output:retained->visuals)if(output.id==made.id)check(output.visible&&output.projectile_trail->state.phase==1);++identity_cases;visuals.close();check(!actions.bound_to(world));
  // Controllers consume the actual168 work budget and no256 child slots.
  e::PeriodicVisuals pressure(bank,session->random);for(unsigned i=0;i<168;++i){const auto item=pressure.create_projectile_trail(world,replacement,0);check(item.status==e::WorkStatus::completed);++constructors;}check(pressure.size()==168&&pressure.piece_count()==0&&pressure.create_projectile_trail(world,replacement,0).status==e::WorkStatus::pool_full);check(pressure.update({0,1,0}).status==e::VisualStatus::completed&&pressure.size()==168&&pressure.piece_count()==0);pool.resolve(replacement)->pose_work->kind=14;check(pressure.update({0,1,0}).status==e::VisualStatus::completed&&pressure.size()==168);check(pressure.update({0,1,0}).status==e::VisualStatus::completed&&pressure.size()==0&&pressure.piece_count()==0);++budget_cases;pressure.close();++banks;
 }}std::cout<<"{\"checks\":"<<checks<<",\"owned_banks\":"<<banks<<",\"constructors\":"<<constructors<<",\"frames\":"<<frames<<",\"budget_cases\":"<<budget_cases<<",\"identity_cases\":"<<identity_cases<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
