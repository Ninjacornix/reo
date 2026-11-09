#include "game/native/animation/model.hpp"
#include "game/native/animation/model_blend.hpp"
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
std::string location;
std::uint64_t capture_cases{},blend_cases{},link_cases{},checks{},helper_calls{},model_cases{},joint_cases{},root_cases{},nonzero_root{},difference_cases{},frame_cases{},binding_refusals{},snapshot_cases{},math_cases{},constructor_cases{},callback_cases{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++helper_calls;if(context->pc==0x18dca0){const auto token=GPR_U32(context,4);check(token<=3,"only owned native fixture resource identities");SET_GPR_U32(context,2,token==1?skeleton_resource:token==2?clip_resource:token==3?0xc00000:0);context->pc=GPR_U32(context,31);return;}
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
 for(unsigned i=0;i<instance.nodes().size();++i){const auto at=nodes+400*i;const auto& native=instance.nodes()[i];check(std::memcmp(native.parameters.data(),ram.data()+at+0x104,sizeof native.parameters)==0,"sampled parameters joint "+std::to_string(i));if(std::memcmp(native.caches.data(),ram.data()+at+0x15c,sizeof native.caches)){for(unsigned c=0;c<10;++c)std::cerr<<c<<":"<<native.caches[c]<<"/"<<get<std::int16_t>(ram.data(),at+0x15c+2*c)<<" ";std::cerr<<"\n";}check(std::memcmp(native.caches.data(),ram.data()+at+0x15c,sizeof native.caches)==0,"sampled caches joint "+std::to_string(i)+" actual="+std::to_string(get<std::int16_t>(ram.data(),at+0x15c))+" native="+std::to_string(native.caches[0]));check(std::memcmp(&native.local,ram.data()+at+0x40,64)==0,"sampled local matrix joint "+std::to_string(i));if(world)check(std::memcmp(&native.world,ram.data()+at,64)==0,"recursive world matrix joint "+std::to_string(i));++joint_cases;}
}
int main(int argc,char** argv)try{
 check(argc==3,"owned model and clip inputs required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());put(ram.data(),0x294e00,t::identity());const auto skeletons=load(argv[2]),clips=load(argv[1]);constexpr std::uint32_t second=0x120000,actor=0x200000,work=0x210000;
 for(const auto& raw:skeletons){auto skeleton=a::Skeleton::import_raw(raw);auto primary=std::make_shared<a::Instance>(skeleton);auto secondary=a::PoseBlend::create_sibling(*primary);std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);std::fill_n(ram.data()+second,skeleton->nodes().size()*400,0);call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);put(ram.data(),actor+0x34,work);put(ram.data(),work,work+0x820);put(ram.data(),work+4,work+0xa20);put(ram.data(),work+0x816,std::uint16_t(skeleton->nodes().size()));for(unsigned i=0;i<skeleton->nodes().size();++i){put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);}
  for(unsigned track=0;track<5;++track){std::vector<unsigned> compatible;unsigned count{};for(const auto& d:skeleton->nodes())count+=d.track==track;for(unsigned ci=0;ci<clips.size();++ci)if(a::Clip::import_raw(clips[ci])->tracks().size()==count)compatible.push_back(ci);if(compatible.empty())continue;
   for(unsigned pair=0;pair<compatible.size();++pair){const auto& raw_primary=clips[compatible[pair]],raw_secondary=clips[compatible[(pair+1)%compatible.size()]];auto cp=a::Clip::import_raw(raw_primary),cs=a::Clip::import_raw(raw_secondary);std::memcpy(ram.data()+0x500000,raw_primary.data(),raw_primary.size());std::memcpy(ram.data()+0x600000,raw_secondary.data(),raw_secondary.size());call(ram.data(),0x1a1fd0,0x18000,clip_resource,0x500000);call(ram.data(),0x1a1fd0,0x19000,0xc00000,0x600000);call(ram.data(),0x192bf0,nodes,2,track);call(ram.data(),0x192bf0,second,3,track);primary->bind(std::uint16_t(track),cp);secondary->bind(std::uint16_t(track),cs);
    for(unsigned k=0;k<12;++k){location="track="+std::to_string(track)+" pair="+std::to_string(pair)+" k="+std::to_string(k);const float fp=cp->last_frame()*float(k%5)*.25f,fs=cs->last_frame()*float((k+2)%5)*.25f;call(ram.data(),0x193230,nodes,track,0,0,fp);primary->sample(std::uint16_t(track),fp);compare_nodes(*primary,ram,false);call(ram.data(),0x193230,second,track,0,0,fs);secondary->sample(std::uint16_t(track),fs);const float p=float(int(k)-3)*.125f,s=k%3?1.f-p:.25f;compare_nodes(*primary,ram,false);primary->rebuild(t::identity());auto retained=primary->retain();const auto old_joint=retained->joints[2];a::PoseBlend::blend(*primary,*secondary,std::uint16_t(track),p,s);call(ram.data(),0x58ce00,actor,track,0,0,p,s);compare_nodes(*primary,ram,false);check(!primary->retain()&&std::memcmp(&old_joint,&retained->joints[2],64)==0,"blending invalidates current ready pose and preserves retained publication");++blend_cases;}
    a::PoseBlend::capture_pose(*secondary,*primary,std::uint16_t(track));call(ram.data(),0x5d42d0,actor,track);for(unsigned i=0;i<skeleton->nodes().size();++i){check(std::memcmp(&secondary->nodes()[i].local,ram.data()+second+400*i+0x40,64)==0,"complete original selective pose-bank capture");check(std::memcmp(secondary->nodes()[i].parameters.data(),ram.data()+second+400*i+0x104,40)==0,"capture copies only original three scale parameters");}++capture_cases;
    a::PoseBlend::capture_links(*secondary,*primary,std::uint16_t(track));call(ram.data(),0x5d43c0,actor,track);const float seek=cp->last_frame()*.625f;secondary->sample(std::uint16_t(track),seek);call(ram.data(),0x193230,second,track,0,0,seek);for(unsigned i=0;i<skeleton->nodes().size();++i){check(std::memcmp(&secondary->nodes()[i].local,ram.data()+second+400*i+0x40,64)==0,"copied immutable Clip binding actually samples same original frame");check(std::memcmp(secondary->nodes()[i].caches.data(),ram.data()+second+400*i+0x15c,20)==0,"complete actual binding-cache copy and later mutation");}++link_cases;
   }
  }
 }
 for(unsigned k=0;k<4096;++k){auto x=t::identity(),y=t::identity();t::reset_euler_axes(x,{std::uint16_t(k*31),std::uint16_t(k*53),std::uint16_t(k*103)});t::reset_euler_axes(y,{std::uint16_t(k*17),std::uint16_t(k*59),std::uint16_t(k*131)});x[3]={float(k%11),float(k%7),float(k%13),99};y[3]={float(k%5),float(k%17),float(k%19),-7};if(k%31==0)x[0]={0,0,0,99};if(k%37==0)y[1]=y[0];const float p=float(int(k%17)-8)*.125f,s=float(int(k%13)-6)*.125f;put(ram.data(),0x260000,x);put(ram.data(),0x260100,y);call(ram.data(),0x191900,0x260200,0x260000,0x260100,0,p,s);const auto result=a::PoseBlend::matrix(x,y,p,s);check(std::memcmp(&result,ram.data()+0x260200,64)==0,"full original weighted/reorthonormalized matrix including degenerate vectors and W reset");++math_cases;}
 std::cout<<"{\"checks\":"<<checks<<",\"blend_cases\":"<<blend_cases<<",\"pose_capture_cases\":"<<capture_cases<<",\"binding_capture_cases\":"<<link_cases<<",\"matrix_cases\":"<<math_cases<<",\"joint_cases\":"<<joint_cases<<",\"original_calls\":"<<helper_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<location<<" "<<e.what()<<'\n';return 1;}
