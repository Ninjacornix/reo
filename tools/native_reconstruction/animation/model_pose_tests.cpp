#include "game/native/animation/model.hpp"
#include "game/native/gameplay_world/model_poses.hpp"
#include "game/native/animation/model_math.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace a=reo::native::animation;
namespace g=reo::native::gameplay_world;
namespace t=reo::native::transform_math;
#include "owned_constants.hpp"
#include "functions.h"
constexpr std::uint32_t nodes=0x100000,skeleton_resource=0x800000,clip_resource=0xa00000;
std::uint64_t checks{},helper_calls{},model_cases{},joint_cases{},root_cases{},nonzero_root{},difference_cases{},frame_cases{},binding_refusals{},snapshot_cases{},math_cases{},correction_cases{},publication_cases{},ownership_cases{},body_cases{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++helper_calls;if(context->pc==0x18dca0){const auto token=GPR_U32(context,4);check(token<=2,"only owned native fixture resource identities");SET_GPR_U32(context,2,token==1?skeleton_resource:token==2?clip_resource:0);context->pc=GPR_U32(context,31);return;}
 switch(context->pc){
#include "original_dispatch.hpp"
 default:throw std::runtime_error("undeclared original model helper "+std::to_string(context->pc));
 }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_models.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* ram,std::uint32_t address,std::uint32_t arg0,std::uint32_t arg1=0,std::uint32_t arg2=0,std::uint32_t arg3=0,float frame=0,float frame2=0,float frame3=0){
 R5900Context ctx;ctx.pc=address;SET_GPR_U32(&ctx,4,arg0);SET_GPR_U32(&ctx,5,arg1);SET_GPR_U32(&ctx,6,arg2);SET_GPR_U32(&ctx,7,arg3);SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);ctx.f[12]=frame;ctx.f[13]=frame2;ctx.f[14]=frame3;PS2Runtime rt;original_transform_port(ram,&ctx,&rt);check(ctx.pc==0xabcdef&&GPR_U32(&ctx,29)==0x1f00000,"complete original model helper return");return ctx;
}
std::vector<std::vector<std::byte>> load(const char* path){std::ifstream f(path,std::ios::binary);std::uint32_t count{};f.read(reinterpret_cast<char*>(&count),4);check(count&&count<1000,"owned corpus count");std::vector<std::vector<std::byte>> result;for(unsigned i=0;i<count;++i){std::uint32_t size{};f.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x400000,"owned corpus extent");result.emplace_back(size);f.read(reinterpret_cast<char*>(result.back().data()),size);check(bool(f),"complete owned corpus bytes");}return result;}
void compare_nodes(const a::Instance& instance,const std::vector<std::uint8_t>& ram,bool world){
 for(unsigned i=0;i<instance.nodes().size();++i){const auto at=nodes+400*i;const auto& native=instance.nodes()[i];check(std::memcmp(native.parameters.data(),ram.data()+at+0x104,sizeof native.parameters)==0,"sampled parameters joint "+std::to_string(i));check(std::memcmp(native.caches.data(),ram.data()+at+0x15c,sizeof native.caches)==0,"sampled caches joint "+std::to_string(i));check(std::memcmp(&native.local,ram.data()+at+0x40,64)==0,"sampled local matrix joint "+std::to_string(i));if(world)check(std::memcmp(&native.world,ram.data()+at,64)==0,"recursive world matrix joint "+std::to_string(i));++joint_cases;}
}
g::Profile profile(){return{{g::input::Remap{0x100,0x20,0x10}},4,{16,UINT64_MAX}};}
struct Scales final:g::ModelCorrectionScales {
 g::File1ModelCorrectionScales owned;mutable unsigned calls{};
 float character(std::uint8_t id)const override{++calls;return owned.character(id);}
 float variant(std::uint16_t id)const override{++calls;return owned.variant(id);}
};
a::Matrix actor_matrix(const g::Actor& actor){const auto& b=actor.collision.basis;return{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
constexpr std::uint32_t actor_address=0x4a5c30,work=0x210000;
void export_actor(std::uint8_t* ram,const g::Actor& actor){
 put(ram,actor_address,std::uint8_t(actor.active));put(ram,actor_address+2,actor.category);put(ram,actor_address+0x34,work);put(ram,actor_address+0x38,actor.position);put(ram,actor_address+0x50,actor_matrix(actor));put(ram,actor_address+0xb4,actor.model_scale);put(ram,actor_address+0xb40,actor.model_correction_skip);put(ram,actor_address+0xaa8,actor.model_height_correction);put(ram,actor_address+0xbb4,actor.model_variant);put(ram,actor_address+0xb98,actor.character);put(ram,actor_address+0x54a,actor.contact_flags);
}
int main(int argc,char** argv)try{
 check(argc==3,"owned model content required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());put(ram.data(),0x294e00,t::identity());const auto skeletons=load(argv[2]);auto skeleton=a::Skeleton::import_raw(skeletons[0]);g::World world(profile(),std::make_shared<g::Session>());Scales scales;std::vector<std::uint16_t> variants;
 for(unsigned id=1;id<=208;++id){try{const float value=scales.owned.variant(std::uint16_t(id));check(std::bit_cast<std::uint32_t>(value)==get<std::uint32_t>(ram.data(),0x716444+20*id),"actual owned NPC scale metadata");variants.push_back(std::uint16_t(id));}catch(const std::out_of_range&){}}
 check(variants.size()==150,"all ordinary and high-detail named NPC correction variants admitted");
 for(unsigned id=0;id<8;++id)check(std::bit_cast<std::uint32_t>(scales.owned.character(std::uint8_t(id)))==get<std::uint32_t>(ram.data(),0x71ae00+12*id),"actual owned player scale metadata");
 auto instance=std::make_shared<a::Instance>(skeleton);std::memcpy(ram.data()+0x400000,skeletons[0].data(),skeletons[0].size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);call(ram.data(),0x193380,nodes,1);
 for(unsigned i=0;i<skeleton->nodes().size();++i)put(ram.data(),work+0x820+4*i,nodes+400*i);
 auto prior_parent=t::identity();prior_parent[3][1]=1000;put(ram.data(),0x20000,prior_parent);call(ram.data(),0x193240,nodes,0x20000);instance->rebuild(prior_parent);
 const auto height=instance->world_translation(21).y;
 for(unsigned i=0;i<65536;++i){
  g::Actor actor;actor.active=true;actor.model=instance;actor.category=std::uint8_t(i%5);actor.character=std::uint8_t(i%8);actor.model_variant=i%3?0:variants[i%variants.size()];actor.model_correction_skip=std::int8_t(i);actor.model_height_correction=float(int(i%17)-8)*.25f;actor.model_scale={1.1f,.75f+float(i%5)*.25f,.9f};actor.position={10,height-47.05f+float(int(i%9)-4)*10,20};world.paused=std::int8_t(i>>8);export_actor(ram.data(),actor);put(ram.data(),0x4badf8,world.paused);
  g::correct_model_height(world,actor,scales);call(ram.data(),0x5d6fc0,actor_address);compare_nodes(*instance,ram,false);const auto local=instance->local_translation(1);check(std::memcmp(&local,ram.data()+nodes+400+0x70,sizeof local)==0,"actual5D6FC0 local-root correction and ordered max clamp");++correction_cases;
 }
 check(scales.calls>0,"required owned scale metadata actually queried");
 for(unsigned i=0;i<64;++i){
  g::Actor actor;actor.active=true;actor.model=instance;actor.category=std::uint8_t(i%5);actor.character=std::uint8_t(i%8);actor.model_variant=i%7?0:1;actor.model_correction_skip=std::int8_t(i%3);actor.model_height_correction=float(i%5)*.5f;actor.model_scale={1.f+float(i%3)*.125f,.75f+float(i%5)*.125f,.9f};actor.position={float(i),1000.f+float(i%23),float(i%17)};actor.contact_flags=0x12;actor.collision.basis.x={1,0,0};actor.collision.basis.y={0,1,0};actor.collision.basis.z={0,0,1};actor.collision.basis.translation={99,98,97};world.paused=std::int8_t(i%3);export_actor(ram.data(),actor);put(ram.data(),0x4badf8,world.paused);put(ram.data(),actor_address+0x1c,0u);put(ram.data(),0x3b59f0,actor_address);
  if((i&1)&&world.paused!=0){actor.contact_flags=0;put(ram.data(),actor_address+0x54a,actor.contact_flags);}
  g::rebuild_standard_model(world,actor,i&1?g::ModelPoseKind::primary:g::ModelPoseKind::linked_actor,scales);call(ram.data(),i&1?0x3769f0:0x376ae0,0);compare_nodes(*instance,ram,true);const auto basis=actor_matrix(actor);check(std::memcmp(&basis,ram.data()+actor_address+0x50,64)==0,"actual complete frameModel standard route actor translation");const auto joint=instance->world_translation(2);check(actor.collision.joint_two_position&&actor.collision.joint_two_position->x==joint.x&&actor.collision.joint_two_position->y==joint.y&&actor.collision.joint_two_position->z==joint.z,"canonical joint2 comes from published real native model");++publication_cases;
 }
 {
  g::Actor actor;actor.active=true;actor.model=instance;actor.position={7,1000,9};actor.model_scale={.75f,1.25f,.5f};world.paused=0;actor.model_correction_skip=1;bool failed{};
  try{g::rebuild_standard_model(world,actor,g::ModelPoseKind::primary,scales);}catch(const std::runtime_error&){failed=true;}
  check(failed&&!instance->retain()&&actor.collision.basis.translation.x==7,"unported IK is explicit after original common prelude; no fake ready pose");
  actor.active=false;g::rebuild_standard_model(world,actor,g::ModelPoseKind::primary,scales);actor.model.reset();world.paused=1;g::correct_model_height(world,actor,scales);++ownership_cases;
 }
 {
  g::World owned(profile(),std::make_shared<g::Session>());owned.room=1;g::WorldBodies bodies(owned);g::WorldModelPoses poses(owned);
  for(unsigned slot=0;slot<2;++slot){auto actor=std::make_unique<g::Actor>();actor->active=true;actor->slot=std::uint8_t(slot);actor->room=1;actor->position={float(slot)*.5f,0,0};actor->previous_position=actor->position;actor->candidate_direction={slot?-1.f:1.f,0,0};actor->model=std::make_shared<a::Instance>(skeleton);actor->contact_flags=0x12;actor->collision.body_definition=reo::native::gameplay_collision::actors::ShapeDefinition{reo::native::gameplay_collision::actors::ShapeKind::sphere,2,{{2},{},{0,0,0},{}},{}};check(owned.spawn_primary(slot,std::move(actor)).status==g::actors::EntityStatus::completed,"real canonical model actor admission");}
  auto left=owned.primary(0),right=owned.primary(1);const auto first=owned.identity(0);check(!poses.retain(first,*left),"unpublished model is unavailable to body solver");
  for(auto* actor:{left.get(),right.get()}){g::rebuild_standard_model(owned,*actor,g::ModelPoseKind::primary,scales);bodies.enqueue(owned,*actor,1,3);}
  auto pose=poses.retain(first,*left);check(pose&&pose->joints.size()==skeleton->nodes().size(),"body consumer retains actual native joint poses");const auto report=bodies.solve(poses,first,false,false);check(report.status==g::BodyStatus::completed&&report.solve.contacts>0,"real WorldBodies consumes model-generated joint sphere and resolves contact");++body_cases;
  g::World other(profile(),std::make_shared<g::Session>());g::WorldModelPoses foreign(other);check(!foreign.retain(first,*left),"wrong World/owner model lease refused");const auto old_joint=pose->joints[2];check(owned.retire_primary(0)==g::actors::EntityStatus::completed&&!poses.retain(first,*left),"retired generation cannot reacquire model pose");left.reset();check(std::memcmp(&pose->joints[2],&old_joint,sizeof old_joint)==0,"immutable body joint lease survives native actor/model retirement");++ownership_cases;
 }
 std::cout<<"{\"checks\":"<<checks<<",\"correction_cases\":"<<correction_cases<<",\"publication_cases\":"<<publication_cases<<",\"joint_cases\":"<<joint_cases<<",\"ownership_cases\":"<<ownership_cases<<",\"body_cases\":"<<body_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
