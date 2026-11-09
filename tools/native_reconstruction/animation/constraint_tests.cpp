#include "game/native/animation/model.hpp"
#include "game/native/animation/constraints.hpp"
#include "game/native/animation/constraint_math.hpp"
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
std::uint64_t checks{},helper_calls{},model_cases{},joint_cases{},root_cases{},nonzero_root{},difference_cases{},frame_cases{},binding_refusals{},snapshot_cases{},math_cases{},constructor_cases{},callback_cases{};
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
namespace m=a::constraint_math;
constexpr std::uint32_t actor=0x200000,work=0x210000;
void contexts(const a::Constraints& owner,const std::vector<std::uint8_t>& ram){
 for(unsigned i=0;i<7;++i){const auto& c=owner.contexts()[i];const auto at=actor+0x560+0xc0*i;check(std::memcmp(&c.relative_first,ram.data()+at,64)==0&&std::memcmp(&c.relative_second,ram.data()+at+0x40,64)==0,"constraint relative frame matrices");check(c.mode==get<std::uint16_t>(ram.data(),at+0x80)&&c.enabled==get<std::uint16_t>(ram.data(),at+0x82),"actual raw mode and enabled halfwords");for(auto [value,offset]:{std::pair{c.twist,0x84u},{c.first_length,0x90u},{c.second_length,0x94u},{c.bend,0xbcu}})check(std::bit_cast<std::uint32_t>(value)==get<std::uint32_t>(ram.data(),at+offset),"constraint float metadata");check(std::memcmp(&c.reference,ram.data()+at+0xa0,12)==0&&std::memcmp(&c.target,ram.data()+at+0xac,12)==0,"reference and target are separate source fields");if(c.enabled)check(get<std::uint32_t>(ram.data(),at+0x88)==nodes+400*c.first_node&&get<std::uint32_t>(ram.data(),at+0x8c)==nodes+400*c.second_node,"typed output node identities");}
 for(unsigned i=0;i<owner.bindings().size();++i){const auto binding=owner.bindings()[i];const auto callback=binding.callback==a::ConstraintCallback::none?0u:binding.callback==a::ConstraintCallback::two_link?0x5d5be0u:binding.callback==a::ConstraintCallback::already_solved?0x5d5bd0u:0x5d59a0u;check(get<std::uint32_t>(ram.data(),nodes+400*i+0x178)==callback,"real installed typed node callback");check(get<std::uint32_t>(ram.data(),nodes+400*i+0x17c)==(callback?actor+0x560+0xc0*binding.context:0),"callback retains its exact native context");}
}
void direct_create(std::uint8_t* ram,unsigned index,unsigned mode,unsigned first,unsigned middle,unsigned last,a::Vector scale,float twist,a::Vector aux){
 R5900Context ctx;ctx.pc=0x5d5fa0;SET_GPR_U32(&ctx,4,actor+0x560+0xc0*index);SET_GPR_U32(&ctx,5,mode);SET_GPR_U32(&ctx,6,nodes+400*first);SET_GPR_U32(&ctx,7,nodes+400*middle);SET_GPR_U32(&ctx,8,nodes+400*last);put(ram,0x260000,scale);SET_GPR_U32(&ctx,9,0x260000);SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);ctx.f[12]=twist;ctx.f[13]=aux.x;ctx.f[14]=aux.y;ctx.f[15]=aux.z;PS2Runtime rt;original_transform_port(ram,&ctx,&rt);check(ctx.pc==0xabcdef,"complete original two-link constructor return");
}
int main(int argc,char** argv)try{
 check(argc==3,"owned clip/model inputs required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());put(ram.data(),0x294e00,t::identity());const auto skeletons=load(argv[2]);
 for(const auto& raw:skeletons){
  auto skeleton=a::Skeleton::import_raw(raw);auto model=std::make_shared<a::Instance>(skeleton);a::Constraints owner(model);std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);call(ram.data(),0x193380,nodes,1);std::fill_n(ram.data()+actor,0x10e0,0);put(ram.data(),actor+0x34,work);for(unsigned i=0;i<skeleton->nodes().size();++i)put(ram.data(),work+0x820+4*i,nodes+400*i);
  const a::Vector input_scale{1.125f,.875f,1.25f};put(ram.data(),actor+0xb4,input_scale);
  for(std::int8_t paused:{std::int8_t(1),std::int8_t(-1),std::int8_t(0),std::int8_t(2)}){put(ram.data(),0x4badf8,paused);call(ram.data(),0x5d6850,actor);owner.initialize_mirrored(paused,input_scale);contexts(owner,ram);compare_nodes(*model,ram,false);++constructor_cases;}
  for(unsigned variant=0;variant<32;++variant){
   const float twist=float(int(variant%13)-6)*.25f;const a::Vector aux{1,.25f,.125f};owner.create(0,variant&1?1:2,7,8,9,input_scale,twist,aux);direct_create(ram.data(),0,variant&1?1:2,7,8,9,input_scale,twist,aux);contexts(owner,ram);++constructor_cases;
   auto parent=t::identity();t::reset_euler_axes(parent,{std::uint16_t(variant*101),std::uint16_t(variant*509),std::uint16_t(variant*37)});parent[3]={float(variant%5),float(int(variant%7)-3),float(variant%3),1};put(ram.data(),0x270000,parent);
   for(unsigned distance=0;distance<8;++distance){
    call(ram.data(),0x193240,nodes,0x270000);model->rebuild(parent);auto retained=model->retain();const auto old_joint=retained->joints[2];
    for(unsigned index=0;index<2;++index){const auto& c=owner.contexts()[index];const auto root=model->world_translation(c.first_node);const float length=c.first_length+c.second_length;const a::Vector target{root.x+length*(.125f+float(distance)*.2f),root.y+1.25f,root.z+.75f};const a::Vector reference{root.x+.25f,root.y+50,root.z+5};owner.reference(index,reference);owner.target(index,target);put(ram.data(),actor+0x560+0xc0*index+0xa0,reference);put(ram.data(),actor+0x560+0xc0*index+0xac,target);}
    owner.rebuild(parent);call(ram.data(),0x5d5ab0,nodes,0x270000);compare_nodes(*model,ram,true);contexts(owner,ram);check(model->retain()&&std::memcmp(&old_joint,&retained->joints[2],64)==0,"constrained publication preserves retained immutable snapshot");++callback_cases;
   }
  }
 }
 for(unsigned i=0;i<4096;++i){
  auto input=t::identity();const a::Vector first{float(int(i%13)-6),float(int(i%17)-8),float(int(i%19)-9)},aux{float(int(i%23)-11),float(int(i%29)-14),float(int(i%31)-15)};input[3]={float(i%5),float(i%7),float(i%11),1};put(ram.data(),0x280000,input);put(ram.data(),0x280100,first);put(ram.data(),0x280110,aux);call(ram.data(),0x191580,0x280000,0x280100,0x280110);const auto xy=m::basis_xy(input,first,aux);check(std::memcmp(&xy,ram.data()+0x280000,64)==0,"actual XY basis helper");put(ram.data(),0x280000,input);call(ram.data(),0x191660,0x280000,0x280100,0x280110);const auto xz=m::basis_xz(input,first,aux);check(std::memcmp(&xz,ram.data()+0x280000,64)==0,"actual XZ basis helper");put(ram.data(),0x280000,xy);call(ram.data(),0x191430,0x280200,0x280000);const auto inverse=m::inverse_scaled(xy);check(std::memcmp(&inverse,ram.data()+0x280200,64)==0,"actual reciprocal-square-root ordered scaled inverse");const float angle=float(int(i%49)-24)*.25f;put(ram.data(),0x280000,t::identity());call(ram.data(),0x190100,0x280000,0,0,0,angle);const auto rotation=m::rotation_x(angle);check(std::memcmp(&rotation,ram.data()+0x280000,64)==0,"actual direct X rotation helper");++math_cases;
 }
 std::cout<<"{\"checks\":"<<checks<<",\"constructor_cases\":"<<constructor_cases<<",\"callback_cases\":"<<callback_cases<<",\"math_cases\":"<<math_cases<<",\"joint_cases\":"<<joint_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
