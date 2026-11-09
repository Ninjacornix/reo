#include "game/native/animation/model.hpp"
#include "game/native/animation/model_math.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace a=reo::native::animation;
namespace t=reo::native::transform_math;
#include "owned_constants.hpp"
#include "functions.h"
constexpr std::uint32_t nodes=0x100000,skeleton_resource=0x800000,clip_resource=0xa00000;
std::uint64_t checks{},helper_calls{},model_cases{},joint_cases{},root_cases{},nonzero_root{},difference_cases{},frame_cases{},binding_refusals{},snapshot_cases{},math_cases{};
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
int main(int argc,char** argv)try{
 check(argc==3,"owned clip and skeleton corpus required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());put(ram.data(),0x294e00,t::identity());auto clips=load(argv[1]),skeletons=load(argv[2]);
 for(unsigned skeleton_id=0;skeleton_id<skeletons.size();++skeleton_id){
  const auto& raw=skeletons[skeleton_id];auto skeleton=a::Skeleton::import_raw(raw);a::Instance instance(skeleton);std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000,0);check(get<std::uint16_t>(ram.data(),0x10002)==skeleton->nodes().size(),"actual raw skeleton forest node count");std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);call(ram.data(),0x193380,nodes,1);compare_nodes(instance,ram,false);
  for(unsigned i=0;i<skeleton->nodes().size();++i){const auto& d=skeleton->nodes()[i];const auto at=nodes+400*i;check(get<std::int16_t>(ram.data(),at+0xc4)==d.palette_index&&get<std::uint16_t>(ram.data(),at+0xc6)==d.track&&get<std::int32_t>(ram.data(),at+0x174)==d.static_index,"raw descriptor IDs and signed static index");check(get<std::uint32_t>(ram.data(),at+0xd0)==(d.child?nodes+400*(*d.child):0)&&get<std::uint32_t>(ram.data(),at+0xcc)==(d.sibling?nodes+400*(*d.sibling):0)&&get<std::uint32_t>(ram.data(),at+0xc8)==(d.parent?nodes+400*(*d.parent):0),"actual original resolved child/sibling/parent topology");}
  for(unsigned clip_id=0;clip_id<clips.size();++clip_id){
   const auto& raw_clip=clips[clip_id];auto clip=a::Clip::import_raw(raw_clip);std::optional<std::uint16_t> group;
   for(const auto& n:skeleton->nodes()){unsigned count=0;for(const auto& x:skeleton->nodes())count+=x.track==n.track;if(count==clip->tracks().size()){group=n.track;break;}}
   if(!group){bool refused{};try{instance.bind(0,clip);}catch(const std::invalid_argument&){refused=true;}check(refused,"incompatible real clip/model cardinality refuses admission");++binding_refusals;continue;}
   std::memcpy(ram.data()+0x500000,raw_clip.data(),raw_clip.size());call(ram.data(),0x1a1fd0,0x18000,clip_resource,0x500000);call(ram.data(),0x192bf0,nodes,2,*group);instance.bind(*group,clip);check(!instance.retain(),"binding invalidates published pose");
   std::vector<float> frames{0,.5f,1,clip->last_frame()*.25f,clip->last_frame()*.75f,clip->last_frame(),clip->last_frame()+1};std::shared_ptr<const a::JointSnapshot> prior_snapshot;a::Matrix retained_joint{};
   for(float frame:frames){
    call(ram.data(),0x193230,nodes,*group,0,0,frame);instance.sample(*group,frame);compare_nodes(instance,ram,false);check(!instance.retain(),"sample invalidates pose capability");
    call(ram.data(),0x18fe60,nodes+0x40,0,0,0,1.25f,.75f,.5f);instance.root_scale({1.25f,.75f,.5f});
    const auto parent=t::scale({1.25f,.75f,1.5f});put(ram.data(),0x20000,parent);call(ram.data(),0x193240,nodes,0x20000);instance.rebuild(parent);compare_nodes(instance,ram,true);auto snapshot=instance.retain();check(snapshot&&snapshot->joints.size()==instance.nodes().size(),"real owned joint snapshot retained");check(std::memcmp(&snapshot->joints[2],ram.data()+nodes+800,64)==0,"retained joint2 is the actual original world pose");if(prior_snapshot)check(std::memcmp(&prior_snapshot->joints[2],&retained_joint,64)==0,"old immutable joint snapshot survives later complete pose publication");prior_snapshot=snapshot;retained_joint=snapshot->joints[2];
    // The actual actor consumer selects node ordinal1 through modelword4.
    if(*group==skeleton->nodes()[1].track){put(ram.data(),0x210000,nodes);put(ram.data(),0x210004,nodes+400);call(ram.data(),0x58c6a0,0x200000,0x210000);const auto delta=instance.consume_root_translation();const auto expected=get<a::Vector>(ram.data(),0x200000+0x4e4);check(std::memcmp(&delta,&expected,sizeof delta)==0,"actual root read/subtract/save/clear consumer");check(!instance.retain(),"consuming root translation invalidates old snapshot");nonzero_root+=delta.x!=0||delta.y!=0||delta.z!=0;++root_cases;compare_nodes(instance,ram,false);}
    check(snapshot->joints.size()==instance.nodes().size(),"old immutable snapshot survives subsequent model mutation");++snapshot_cases;
   }
   if(*group==skeleton->nodes()[1].track){const auto ctx=call(ram.data(),0x1925c0,0x230000,nodes+400,0,0,1.f,clip->last_frame()*.75f);(void)ctx;const auto delta=instance.translation_difference(1,1.f,clip->last_frame()*.75f);const auto expected=get<a::Vector>(ram.data(),0x230000);check(std::memcmp(&delta,&expected,sizeof delta)==0,"actual complete two-matrix root translation difference");compare_nodes(instance,ram,false);++difference_cases;}
   call(ram.data(),0x192b30,nodes,*group);instance.clear(*group);call(ram.data(),0x193230,nodes,*group,0,0,0);instance.sample(*group,0);compare_nodes(instance,ram,false);++model_cases;
  }
 }
 // Independent scale/rotation/hierarchy inputs stress the exact matrix order,
 // beyond the scales that happen to be present in these two stock skeletons.
 for(unsigned i=0;i<4096;++i){
  a::Parameters p{.25f+float(i%7)*.25f,.5f+float(i%5)*.25f,.75f+float(i%3)*.25f,float(int(i%41)-20)*.25f,float(int((i/7)%41)-20)*.25f,float(int((i/11)%41)-20)*.25f,float(int(i%23)-11),float(int(i%29)-14),float(int(i%31)-15),0};
  put(ram.data(),0x260000,p);call(ram.data(),0x1939a0,0x260100,0x260000);const auto local=a::unscaled_pose(p);check(std::memcmp(&local,ram.data()+0x260100,64)==0,"full original direct-radian unscaled pose");
  call(ram.data(),0x192df0,0,0x260000,0x260200,0x260300);const auto scaled=a::scaled_pose(p);check(std::memcmp(&scaled,ram.data()+0x260300,64)==0,"full original defaults/scaled motion pose");
  auto parent=t::identity();t::reset_euler_axes(parent,{std::uint16_t(i*17),std::uint16_t(i*31),std::uint16_t(i*43)});parent[3]={float(i%19),float(i%17),float(i%13),1};put(ram.data(),0x260400,parent);put(ram.data(),0x261000+0x104,p);put(ram.data(),0x261000+0x40,local);put(ram.data(),0x261000+0xcc,0u);put(ram.data(),0x261000+0xd0,0u);call(ram.data(),0x193260,0x261000,0x260400,0,0,.75f,1.5f,2.25f);a::NodePose n;n.parameters=p;n.local=local;const auto world=a::hierarchical_pose(n,parent,{.75f,1.5f,2.25f});check(std::memcmp(&world,ram.data()+0x261000,64)==0,"full original reciprocal-parent-scale hierarchy order");++math_cases;
 }
 for(unsigned i=0;i<65536;++i){a::FrameRecord r;r.flags=std::uint8_t(i);r.loop=std::int8_t(i>>8);r.frame=float(int(i%41)-10)*.5f;r.end=i%7?10.f:0.f;r.restart=float(i%13)*.5f;const float step=float(int((i/7)%17)-8)*.5f;put(ram.data(),0x250000,r.frame);put(ram.data(),0x250004,r.end);put(ram.data(),0x250008,r.restart);put(ram.data(),0x25000c,r.loop);put(ram.data(),0x25000d,r.flags);const auto ctx=call(ram.data(),0x58bf50,0x250000,0,0,0,step);const auto result=a::advance(r,step);check(result==GPR_U32(&ctx,2)&&std::bit_cast<std::uint32_t>(r.frame)==get<std::uint32_t>(ram.data(),0x250000)&&r.flags==get<std::uint8_t>(ram.data(),0x25000d)&&r.loop==get<std::int8_t>(ram.data(),0x25000c),"all flag/loop byte patterns and source boundary timing");++frame_cases;}
 check(model_cases>0&&root_cases>0&&nonzero_root>0&&difference_cases>0,"real asset model/root consumers exercised");
 std::cout<<"{\"checks\":"<<checks<<",\"model_cases\":"<<model_cases<<",\"joint_cases\":"<<joint_cases<<",\"root_cases\":"<<root_cases<<",\"nonzero_root\":"<<nonzero_root<<",\"difference_cases\":"<<difference_cases<<",\"frame_cases\":"<<frame_cases<<",\"binding_refusals\":"<<binding_refusals<<",\"snapshot_cases\":"<<snapshot_cases<<",\"math_cases\":"<<math_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"owned_skeletons\":"<<skeletons.size()<<",\"owned_clips\":"<<clips.size()<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
