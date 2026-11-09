#include "game/native/animation/model.hpp"
#include "game/native/animation/constraints.hpp"
#include "game/native/gameplay_world/model_constraints.hpp"
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
const reo::native::gameplay_collision::response::Grid* current_floor{};
std::vector<reo::native::gameplay_collision::Vec3> floor_points;
std::uint64_t surface_one_queries{},sample_cases{},floor_hits{},floor_calls{},ground_cases{},raised_cases{},fallback_cases{},checks{},helper_calls{},model_cases{},joint_cases{},root_cases{},nonzero_root{},difference_cases{},frame_cases{},binding_refusals{},snapshot_cases{},math_cases{},correction_cases{},publication_cases{},ownership_cases{},body_cases{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++helper_calls;if(context->pc==0x617000){check(current_floor,"explicit qualified native617000 floor seam");const auto point=get<reo::native::gameplay_collision::Vec3>(memory,GPR_U32(context,4));floor_points.push_back(point);++floor_calls;check(GPR_U32(context,8)==255,"source floor required-type argument");const auto result=current_floor->floor(point,std::uint8_t(GPR_U32(context,8)));if(result.triangle)++floor_hits;context->f[0]=result.height;context->pc=GPR_U32(context,31);return;}
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
 put(ram,actor_address,std::uint8_t(actor.active));put(ram,actor_address+2,actor.category);put(ram,actor_address+0x34,work);put(ram,actor_address+0x38,actor.position);put(ram,actor_address+0x50,actor_matrix(actor));put(ram,actor_address+0xb4,actor.model_scale);put(ram,actor_address+0xb40,actor.model_correction_skip);put(ram,actor_address+0xaa8,actor.model_height_correction);put(ram,actor_address+0xbb4,actor.model_variant);put(ram,actor_address+0xb98,actor.character);put(ram,actor_address+0x54a,actor.contact_flags);put(ram,actor_address+0x54f,actor.motion_class);put(ram,actor_address+0x174,actor.surface_kind);put(ram,actor_address+0xb9b,actor.class_marker);
}
void contexts(const a::Constraints& owner,const std::vector<std::uint8_t>& ram){
 for(unsigned i=0;i<7;++i){const auto& c=owner.contexts()[i];const auto at=actor_address+0x560+0xc0*i;check(std::memcmp(&c.relative_first,ram.data()+at,64)==0&&std::memcmp(&c.relative_second,ram.data()+at+0x40,64)==0,"constraint relative frame matrices");check(c.mode==get<std::uint16_t>(ram.data(),at+0x80)&&c.enabled==get<std::uint16_t>(ram.data(),at+0x82),"actual raw mode and enabled halfwords");for(auto [value,offset]:{std::pair{c.twist,0x84u},{c.first_length,0x90u},{c.second_length,0x94u},{c.bend,0xbcu}})check(std::bit_cast<std::uint32_t>(value)==get<std::uint32_t>(ram.data(),at+offset),"constraint float metadata");check(std::memcmp(&c.reference,ram.data()+at+0xa0,12)==0&&std::memcmp(&c.target,ram.data()+at+0xac,12)==0,"reference and target are separate source fields");if(c.enabled)check(get<std::uint32_t>(ram.data(),at+0x88)==nodes+400*c.first_node&&get<std::uint32_t>(ram.data(),at+0x8c)==nodes+400*c.second_node,"typed output node identities");}
 for(unsigned i=0;i<owner.bindings().size();++i){const auto binding=owner.bindings()[i];const auto callback=binding.callback==a::ConstraintCallback::none?0u:binding.callback==a::ConstraintCallback::two_link?0x5d5be0u:binding.callback==a::ConstraintCallback::already_solved?0x5d5bd0u:0x5d59a0u;check(get<std::uint32_t>(ram.data(),nodes+400*i+0x178)==callback,"real installed typed node callback");check(get<std::uint32_t>(ram.data(),nodes+400*i+0x17c)==(callback?actor_address+0x560+0xc0*binding.context:0),"callback retains its exact native context");}
}
void direct_create(std::uint8_t* ram,unsigned index,unsigned mode,unsigned first,unsigned middle,unsigned last,a::Vector scale,float twist,a::Vector aux){
 R5900Context ctx;ctx.pc=0x5d5fa0;SET_GPR_U32(&ctx,4,actor_address+0x560+0xc0*index);SET_GPR_U32(&ctx,5,mode);SET_GPR_U32(&ctx,6,nodes+400*first);SET_GPR_U32(&ctx,7,nodes+400*middle);SET_GPR_U32(&ctx,8,nodes+400*last);put(ram,0x260000,scale);SET_GPR_U32(&ctx,9,0x260000);SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);ctx.f[12]=twist;ctx.f[13]=aux.x;ctx.f[14]=aux.y;ctx.f[15]=aux.z;PS2Runtime rt;original_transform_port(ram,&ctx,&rt);check(ctx.pc==0xabcdef,"complete original two-link constructor return");
}
int main(int argc,char** argv)try{
 check(argc==4,"owned model and floor packages required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);
 std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());put(ram.data(),0x294e00,t::identity());const auto clips=load(argv[1]);const auto skeletons=load(argv[2]);const auto floor_bytes=load(argv[3]);Scales scales;g::World world(profile(),std::make_shared<g::Session>());
 for(unsigned fi=0;fi<floor_bytes.size();++fi){const auto floor=reo::native::gameplay_collision::response::Grid::import(floor_bytes[fi]);current_floor=&floor;check(!floor.triangles().empty(),"actual imported room has triangles");
  const auto& header=floor.header();
  for(unsigned si=0;si<skeletons.size();++si){auto skeleton=a::Skeleton::import_raw(skeletons[si]);std::vector<unsigned> compatible;for(unsigned c=0;c<clips.size();++c){auto clip=a::Clip::import_raw(clips[c]);unsigned count{};for(const auto& n:skeleton->nodes())count+=n.track==0;if(count==clip->tracks().size())compatible.push_back(c);}check(!compatible.empty(),"real body motion group0 clips exist");
   for(unsigned case_id=0;case_id<80;++case_id){
    const auto& raw=skeletons[si];std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);call(ram.data(),0x193380,nodes,1);std::fill_n(ram.data()+actor_address,0x10e0,0);for(unsigned i=0;i<skeleton->nodes().size();++i)put(ram.data(),work+0x820+4*i,nodes+400*i);
    g::Actor actor;actor.active=true;actor.model=std::make_shared<a::Instance>(skeleton);actor.category=std::uint8_t(case_id%5);actor.character=std::uint8_t(case_id%8);actor.class_marker=case_id%3==0?3:0;actor.model_variant=case_id%7==0?1:0;actor.model_correction_skip=1;actor.model_height_correction=float(int(case_id%9)-4)*.25f;actor.motion_class=std::uint8_t(case_id*17);actor.surface_kind=std::uint8_t(case_id%2&&actor.category<=2?1:0);actor.model_scale={1.f+float(case_id%3)*.125f,.75f+float(case_id%5)*.125f,.9f};
    const auto& tri=floor.triangles()[case_id%floor.triangles().size()];float x=(tri.vertices[0].x+tri.vertices[1].x+tri.vertices[2].x)/3.f,z=(tri.vertices[0].z+tri.vertices[1].z+tri.vertices[2].z)/3.f;float y=(tri.vertices[0].y+tri.vertices[1].y+tri.vertices[2].y)/3.f;
    if(case_id%6==0){x=float(header.origin_x)-500;z=float(header.origin_z)-500;}
    actor.position={x,y+float(int(case_id%7)-3)*30.f,z};world.paused=0;export_actor(ram.data(),actor);put(ram.data(),0x4badf8,world.paused);put(ram.data(),actor_address+0x1c,0u);put(ram.data(),0x3b59f0,actor_address);
    if(case_id%4){const auto& bytes=clips[compatible[case_id%compatible.size()]];auto clip=a::Clip::import_raw(bytes);std::memcpy(ram.data()+0x500000,bytes.data(),bytes.size());call(ram.data(),0x1a1fd0,0x18000,clip_resource,0x500000);call(ram.data(),0x192bf0,nodes,2,0);actor.model->bind(0,clip);const float frame=clip->last_frame()*float(case_id%5)*.25f;call(ram.data(),0x193230,nodes,0,0,0,frame);actor.model->sample(0,frame);++sample_cases;}
    actor.constraints=std::make_shared<a::Constraints>(actor.model);const unsigned variant=case_id%5;
    if(variant==0){g::initialize_model_constraints(world,actor);call(ram.data(),0x5d6850,actor_address);}
    else if(variant<4){const unsigned index=variant==1?0:variant==2?1:2;const unsigned first=index==1?4:7;const a::Vector scale{actor.model_scale.x,actor.model_scale.y,actor.model_scale.z};const float twist=std::bit_cast<float>(index==1?0x3fc90fdcu:0xbfc90fdcu);const a::Vector aux{index==1?-1.f:1.f,0,0};actor.constraints->create(index,2,first,first+1,first+2,scale,twist,aux);direct_create(ram.data(),index,2,first,first+1,first+2,scale,twist,aux);}
    floor_points.clear();const auto old_position=actor.position;const auto report=g::rebuild_model_constraints(world,actor,g::ModelPoseKind::primary,scales,&floor);call(ram.data(),0x3769f0,0);compare_nodes(*actor.model,ram,true);contexts(*actor.constraints,ram);
    check(std::memcmp(&old_position,&actor.position,sizeof old_position)==0,"ground adjustment never moves canonical actor position");check(actor.model->retain()!=nullptr,"complete native grounded pose publication");check(report.contexts_consulted,"active primary consults explicit typed contexts");
    check(report.floor_queries==floor_points.size(),"actual two floor calls count and no query for other-slot-only/no-enabled");
    if(report.base_height)check(std::bit_cast<std::uint32_t>(*report.base_height)==get<std::uint32_t>(ram.data(),0x743490),"actual original base-height metadata and rounding");
    for(unsigned i=0;i<2;++i)check(std::bit_cast<std::uint32_t>(actor.constraints->floor_heights()[i])==get<std::uint32_t>(ram.data(),actor_address+0xaa0+4*i),"complete original floor target height cache");
    if(report.floor_queries){check(report.floor_queries==2,"both endpoints queried independently of individual enabled states");for(unsigned i=0;i<2;++i){const auto target=actor.constraints->contexts()[i].target;check(floor_points[i].x==target.x&&floor_points[i].z==target.z&&floor_points[i].y==actor.position.y,"floor inputs use endpointXZ and canonical actorY");}}
    if(actor.surface_kind==1)surface_one_queries+=report.floor_queries;
    if(report.raised_mask)++raised_cases;
    ++ground_cases;
   }
  }
 }
 // All signed pause patterns admit the source standard path without requiring
 // constraints or floors, including paused model creation preserving absence.
 current_floor=nullptr;auto skeleton=a::Skeleton::import_raw(skeletons[0]);
 for(unsigned raw_pause=1;raw_pause<256;++raw_pause){
  const auto& raw=skeletons[0];std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);call(ram.data(),0x193380,nodes,1);std::fill_n(ram.data()+actor_address,0x10e0,0);for(unsigned i=0;i<skeleton->nodes().size();++i)put(ram.data(),work+0x820+4*i,nodes+400*i);
  g::Actor actor;actor.active=true;actor.model=std::make_shared<a::Instance>(skeleton);actor.model_correction_skip=1;actor.position={1,2,3};world.paused=std::bit_cast<std::int8_t>(std::uint8_t(raw_pause));export_actor(ram.data(),actor);put(ram.data(),0x4badf8,world.paused);put(ram.data(),0x3b59f0,actor_address);g::initialize_model_constraints(world,actor);check(!actor.constraints,"paused creator preserves missing component");const auto report=g::rebuild_model_constraints(world,actor,g::ModelPoseKind::primary,scales,nullptr);call(ram.data(),0x3769f0,0);compare_nodes(*actor.model,ram,true);check(!report.contexts_consulted&&report.floor_queries==0,"paused complete publication avoids required-context/floor guesses");++fallback_cases;
 }
 {
  world.paused=0;g::Actor actor;actor.active=true;actor.model=std::make_shared<a::Instance>(skeleton);actor.model_correction_skip=1;g::initialize_model_constraints(world,actor);auto previous=actor.constraints;auto previous_model=actor.model;previous->target(0,{11,22,33});previous->floor_height(0,44);actor.model=std::make_shared<a::Instance>(skeleton);bool refused{};try{g::rebuild_model_constraints(world,actor,g::ModelPoseKind::primary,scales,nullptr);}catch(const std::runtime_error&){refused=true;}check(refused&&previous->model()==previous_model,"stale model constraint owner refused without retargeting retained model");g::initialize_model_constraints(world,actor);check(actor.constraints!=previous&&actor.constraints->model()==actor.model&&previous->model()==previous_model,"explicit original reinitialization creates replacement typed lease");check(actor.constraints->contexts()[0].target.y==22&&actor.constraints->floor_heights()[0]==44,"model recreation preserves source constructor-untouched target and cached floor");
  actor.constraints.reset();refused=false;try{g::rebuild_model_constraints(world,actor,g::ModelPoseKind::primary,scales,nullptr);}catch(const std::runtime_error&){refused=true;}check(refused,"missing contexts are unavailable, never assumed disabled");actor.constraints=std::make_shared<a::Constraints>(actor.model);check(g::rebuild_model_constraints(world,actor,g::ModelPoseKind::primary,scales,nullptr).floor_queries==0&&actor.model->retain(),"known zero contexts admit required standard publication");++ownership_cases;
 }
 check(surface_one_queries>0,"distinct source174==1 branch actually executes");
 check(raised_cases>0&&floor_hits>0,"real imported floor hits and actual raised endpoint solver exercised");
 std::cout<<"{\"checks\":"<<checks<<",\"surface_one_queries\":"<<surface_one_queries<<",\"ground_cases\":"<<ground_cases<<",\"raised_cases\":"<<raised_cases<<",\"sample_cases\":"<<sample_cases<<",\"floor_calls\":"<<floor_calls<<",\"floor_hits\":"<<floor_hits<<",\"pause_patterns\":"<<fallback_cases<<",\"joint_cases\":"<<joint_cases<<",\"ownership_cases\":"<<ownership_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
