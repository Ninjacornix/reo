#include "game/native/animation/model.hpp"
#include "game/native/animation/playback.hpp"
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
constexpr std::uint32_t nodes=0x100000,skeleton_resource=0x800000;
std::string location;
std::array<float,2> last_weights{};
void(*prelude_hook)(std::uint8_t*,R5900Context*){};
std::vector<std::uint32_t> resources{0,0x800000};
std::uint64_t config_cases{},plain_cases{},tick_cases{},transition_cases{},four_cases{},whole_model_cases{},orchestration_cases{},prelude_calls{};
std::uint64_t whole_configuration_cases{},whole_tick_cases{},whole_missing_cases{},whole_boundary_refusals{};
std::uint64_t whole_reserved_configurations{},whole_reserved_ticks{},whole_reserved_nonzero_rows{};
std::uint64_t whole_reserved_owned_configurations{};
std::uint64_t routing_queries{},routing_owned_cases{},routing_controlled_prefixes{},routing_continuations{},routing_tail_cases{};
std::uint64_t routing_refusals{};
std::uint64_t topology_patches{},topology_samples{},topology_blends{},topology_refusals{},topology_copies{},topology_parent_cases{};
std::uint64_t topology_pair_refusals{};
std::uint64_t topology_mixed_blends{};
std::uint64_t model_replacement_cases{},replacement_continuations{},replacement_refusals{};
std::uint64_t independent_copies{},copy_continuations{},copy_isolations{};
std::uint64_t scalar_bindings{},scalar_ticks{},scalar_early_returns{},scalar_odd_endpoints{},scalar_refusals{};
std::uint64_t capture_cases{},blend_cases{},link_cases{},checks{},helper_calls{},model_cases{},joint_cases{},root_cases{},nonzero_root{},difference_cases{},frame_cases{},binding_refusals{},snapshot_cases{},math_cases{},constructor_cases{},callback_cases{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
#ifdef REO_WHOLE_PLAYBACK_TESTS
 if(context->pc==0x1a0d70){const auto token=GPR_U32(context,4);check(token>0&&token<resources.size(),"bounded packed clip metadata lookup");SET_GPR_U32(context,2,resources[token]);context->pc=GPR_U32(context,31);return;}
#endif
 ++helper_calls;if(context->pc==0x192690)last_weights={context->f[12],context->f[13]};if(context->pc==0x18dca0){const auto token=GPR_U32(context,4);check(token<resources.size(),"only admitted owned model/Clip token identities");SET_GPR_U32(context,2,resources[token]);context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x107c68){check(GPR_U32(context,6)==32&&GPR_U32(context,5)==0,"only original bounded zero-channel record seam");std::memset(memory+GPR_U32(context,4),0,32);context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x573430){++prelude_calls;if(prelude_hook)prelude_hook(memory,context);context->pc=GPR_U32(context,31);return;}
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
 R5900Context ctx;ctx.pc=address;SET_GPR_U32(&ctx,4,arg0);SET_GPR_U32(&ctx,5,arg1);SET_GPR_U32(&ctx,6,arg2);SET_GPR_U32(&ctx,7,arg3);SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);ctx.f[12]=frame;ctx.f[13]=frame2;ctx.f[14]=frame3;PS2Runtime rt;original_transform_port(ram,&ctx,&rt);check(ctx.pc==0xabcdef&&GPR_U32(&ctx,29)==0x1f00000,"complete original model helper return address="+std::to_string(address)+" pc="+std::to_string(ctx.pc)+" sp="+std::to_string(GPR_U32(&ctx,29)));return ctx;
}
std::vector<std::vector<std::byte>> load(const char* path){std::ifstream f(path,std::ios::binary);std::uint32_t count{};f.read(reinterpret_cast<char*>(&count),4);check(count&&count<1000,"owned corpus count");std::vector<std::vector<std::byte>> result;for(unsigned i=0;i<count;++i){std::uint32_t size{};f.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x400000,"owned corpus extent");result.emplace_back(size);f.read(reinterpret_cast<char*>(result.back().data()),size);check(bool(f),"complete owned corpus bytes");}return result;}
void compare_nodes(const a::Instance& instance,const std::vector<std::uint8_t>& ram,bool world){
 for(unsigned i=0;i<instance.nodes().size();++i){const auto at=nodes+400*i;const auto& native=instance.nodes()[i];check(std::memcmp(native.parameters.data(),ram.data()+at+0x104,sizeof native.parameters)==0,"sampled parameters joint "+std::to_string(i));if(std::memcmp(native.caches.data(),ram.data()+at+0x15c,sizeof native.caches)){for(unsigned c=0;c<10;++c)std::cerr<<c<<":"<<native.caches[c]<<"/"<<get<std::int16_t>(ram.data(),at+0x15c+2*c)<<" ";std::cerr<<"\n";}check(std::memcmp(native.caches.data(),ram.data()+at+0x15c,sizeof native.caches)==0,"sampled caches joint "+std::to_string(i)+" actual="+std::to_string(get<std::int16_t>(ram.data(),at+0x15c))+" native="+std::to_string(native.caches[0]));check(std::memcmp(&native.local,ram.data()+at+0x40,64)==0,"sampled local matrix joint "+std::to_string(i));if(world)check(std::memcmp(&native.world,ram.data()+at,64)==0,"recursive world matrix joint "+std::to_string(i));++joint_cases;}
}
#ifndef PLAYBACK_ACTOR_ADDRESS
#define PLAYBACK_ACTOR_ADDRESS 0x200000
#endif
constexpr std::uint32_t second=0x120000,actor=PLAYBACK_ACTOR_ADDRESS,work=0x210000,bank_at=0x300000;
std::uint32_t bits(float x){return std::bit_cast<std::uint32_t>(x);}
void records(const a::Playback& owner,const std::vector<std::uint8_t>& ram,a::Vector delta){
 for(unsigned bank=0;bank<2;++bank)for(unsigned i=0;i<5;++i){const auto& c=owner.channel(bank?a::ModelBank::secondary:a::ModelBank::primary,i);const auto at=actor+(bank?0x364:0x1e4)+32*i;check(bits(c.timing.frame)==get<std::uint32_t>(ram.data(),at)&&bits(c.timing.end)==get<std::uint32_t>(ram.data(),at+4)&&bits(c.timing.restart)==get<std::uint32_t>(ram.data(),at+8),"complete channel frame/end/restart");check(std::bit_cast<std::uint8_t>(c.timing.loop)==ram[at+12]&&c.timing.flags==ram[at+13]&&c.selector==get<std::uint16_t>(ram.data(),at+14),"channel activation/flags/selector bank="+std::to_string(bank)+" track="+std::to_string(i)+" native="+std::to_string(c.timing.loop)+","+std::to_string(c.timing.flags)+","+std::to_string(c.selector)+" actual="+std::to_string(ram[at+12])+","+std::to_string(ram[at+13])+","+std::to_string(get<std::uint16_t>(ram.data(),at+14)));check(bits(c.blend_increment)==get<std::uint32_t>(ram.data(),at+16)&&bits(c.blend_position)==get<std::uint32_t>(ram.data(),at+20)&&c.blend_remaining==get<std::uint16_t>(ram.data(),at+24),"complete transition state bank="+std::to_string(bank)+" track="+std::to_string(i)+" native="+std::to_string(c.blend_increment)+","+std::to_string(c.blend_position)+","+std::to_string(c.blend_remaining)+" actual="+std::to_string(get<float>(ram.data(),at+16))+","+std::to_string(get<float>(ram.data(),at+20))+","+std::to_string(get<std::uint16_t>(ram.data(),at+24)));check(c.skip_flags==ram[at+26]&&c.mode==ram[at+27]&&c.auxiliary==get<std::uint32_t>(ram.data(),at+28),"remaining channel metadata");}
 check(std::memcmp(&delta,ram.data()+actor+0x4e4,12)==0,"canonical output root delta");const auto saved=owner.saved_delta(),unblended=owner.unblended_delta(),reference=a::PoseBlend::root_reference(*owner.model());check(std::memcmp(&saved,ram.data()+actor+0x4fc,12)==0&&std::memcmp(&unblended,ram.data()+actor+0x4f0,12)==0&&std::memcmp(&reference,ram.data()+actor+0x508,12)==0,"distinct saved/unblended/root-reference ownership");check(owner.progress_flags==ram[actor+0xce2]&&owner.progress_threshold==ram[actor+0xce3],"motion progress flags");
 for(unsigned i=0;i<owner.model()->nodes().size();++i)for(unsigned b=0;b<2;++b){const auto model=b?owner.secondary_model():owner.model();if(!model)continue;const auto& n=model->nodes()[i];const auto at=(b?second:nodes)+400*i;if(std::memcmp(&n.local,ram.data()+at+0x40,64)){for(unsigned lane=0;lane<16;++lane){const auto native=std::bit_cast<std::array<std::uint32_t,16>>(n.local)[lane],actual=get<std::uint32_t>(ram.data(),at+0x40+4*lane);if(native!=actual)std::cerr<<"matrix lane="<<lane<<" nativebits="<<native<<" actualbits="<<actual<<"\n";}std::cerr<<"weightbits="<<bits(last_weights[0])<<","<<bits(last_weights[1])<<" expected="<<bits(a::transition_weight(owner.channel(a::ModelBank::primary,0).blend_position))<<","<<bits(float(1.0-double(a::transition_weight(owner.channel(a::ModelBank::primary,0).blend_position))))<<"\n";}if(std::memcmp(n.parameters.data(),ram.data()+at+0x104,40)){for(unsigned c=0;c<10;++c)if(bits(n.parameters[c])!=get<std::uint32_t>(ram.data(),at+0x104+4*c))std::cerr<<"parameter="<<c<<" nativebits="<<bits(n.parameters[c])<<" actualbits="<<get<std::uint32_t>(ram.data(),at+0x104+4*c)<<"\n";std::cerr<<"weightbits="<<bits(last_weights[0])<<","<<bits(last_weights[1])<<" expected="<<bits(a::transition_weight(owner.channel(a::ModelBank::primary,0).blend_position))<<","<<bits(float(1.0-double(a::transition_weight(owner.channel(a::ModelBank::primary,0).blend_position))))<<"\n";}check(model->track_ids()[i]==get<std::uint16_t>(ram.data(),at+0xc6),"per-instance node track routing");check(std::memcmp(&n.local,ram.data()+at+0x40,64)==0&&std::memcmp(n.parameters.data(),ram.data()+at+0x104,40)==0&&std::memcmp(n.caches.data(),ram.data()+at+0x15c,20)==0,"both real model bank local/sample/cache states bank="+std::to_string(b)+" joint="+std::to_string(i)+" weights="+std::to_string(last_weights[0])+","+std::to_string(last_weights[1])+" expectedPrimary="+std::to_string(a::transition_weight(owner.channel(a::ModelBank::primary,0).blend_position)));++joint_cases;}
}
void export_channel(std::uint8_t* ram,unsigned bank,unsigned track,const a::MotionChannel& c){const auto at=actor+(bank?0x364:0x1e4)+32*track;put(ram,at,c.timing.frame);put(ram,at+4,c.timing.end);put(ram,at+8,c.timing.restart);put(ram,at+12,c.timing.loop);put(ram,at+13,c.timing.flags);put(ram,at+14,c.selector);put(ram,at+16,c.blend_increment);put(ram,at+20,c.blend_position);put(ram,at+24,c.blend_remaining);put(ram,at+26,c.skip_flags);put(ram,at+27,c.mode);put(ram,at+28,c.auxiliary);}
#ifdef REO_WHOLE_PLAYBACK_TESTS
#include "game/native/animation/primary_motion_routing.hpp"
#include "whole_playback_tests.inc"
#include "primary_motion_routing_tests.inc"
#include "node_topology_tests.inc"
#include "scalar_playback_tests.inc"
#endif
int main(int argc,char** argv)try{
 check(argc==4,"owned real model/Clip/bank packages required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());put(ram.data(),0x294e00,t::identity());const auto skeletons=load(argv[2]),banks=load(argv[3]);std::shared_ptr<const a::Skeleton> skeleton;std::vector<std::byte> raw_skeleton;for(const auto& bytes:skeletons){auto candidate=a::Skeleton::import_raw(bytes);if(candidate->nodes().size()==36){skeleton=candidate;raw_skeleton=bytes;}}check(bool(skeleton),"actual36-node player forest");a::MotionBank resource;resource.load_sparse(banks[0],8,0,"pc000");resource.load_sparse(banks[1],8,1,"pc001");std::vector<unsigned> keys;
 for(unsigned key=0;key<2000&&keys.size()<8;++key){bool valid=true;for(unsigned track=0;track<5;++track){auto block=resource.find(key,std::uint16_t(track));if(!block){if(track<2)valid=false;continue;}try{unsigned count{};for(const auto& d:skeleton->nodes())count+=d.track==track;if(block->clip()->tracks().size()!=count)valid=false;}catch(const std::exception&){valid=false;}}if(valid)keys.push_back(key);}check(keys.size()==8,"eight actual compatible complete player motion rows");
 for(unsigned variant=0;variant<64;++variant){location="variant="+std::to_string(variant);std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);std::fill_n(ram.data()+second,skeleton->nodes().size()*400,0);std::fill_n(ram.data()+actor,0x10e0,0);std::fill_n(ram.data()+work,0x1468,0);std::fill_n(ram.data()+bank_at,0x1f44,0);std::memcpy(ram.data()+0x400000,raw_skeleton.data(),raw_skeleton.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);put(ram.data(),actor+0x34,work);put(ram.data(),actor+0x524,std::uint8_t(5));put(ram.data(),work,work+0x820);put(ram.data(),work+4,work+0xa20);put(ram.data(),work+0x816,std::uint16_t(skeleton->nodes().size()));for(unsigned i=0;i<skeleton->nodes().size();++i){put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);}
  resources.resize(2);std::vector<std::shared_ptr<const a::MotionBlock>> blocks;const unsigned key=keys[variant%keys.size()];for(unsigned track=0;track<5;++track){auto block=resource.find(key,std::uint16_t(track));if(block&&std::find(blocks.begin(),blocks.end(),block)==blocks.end())blocks.push_back(block);}ram[bank_at]=resource.first_track();ram[bank_at+1]=resource.track_count();ram[bank_at+2]=std::uint8_t(resource.kind());for(unsigned i=0;i<2000;++i)put(ram.data(),bank_at+0xfa4+2*i,resource.rows()[i]);
  for(const auto& block:blocks){const auto token=unsigned(resources.size());const auto packed=0x900000+0x80000*(token-2);resources.push_back(packed);check(block->bytes().size()<0x40000,"bounded actual Clip packing arena");std::memcpy(ram.data()+0x500000,block->bytes().data(),block->bytes().size());call(ram.data(),0x1a1fd0,0x18000,packed,0x500000);for(unsigned i=0;i<2000;++i)if(resource.slots()[i]==block)put(ram.data(),bank_at+4+2*i,std::uint16_t(token));}
  auto model=std::make_shared<a::Instance>(skeleton);a::Playback player(model);a::Vector root{3,4,5};a::RootMotionRef root_ref{root.x,root.y,root.z};put(ram.data(),actor+0x4e4,root);const a::MotionClock clock{std::uint8_t(variant%2),std::uint8_t(variant%4),.5f+float(variant%4)*.25f};put(ram.data(),0x3243cc,clock.mode);put(ram.data(),actor+2,clock.category);put(ram.data(),actor+0xba8,clock.rate);
  for(unsigned track=0;track<5;++track){auto& c=player.channel(a::ModelBank::primary,track);c.timing.flags=std::uint8_t(variant*17);export_channel(ram.data(),0,track,c);const float frame=float(variant%5)*.5f;const float duration=variant%4==0?0:variant%4==1?-6.f:variant%4==2?10.f:.5f;location="variant="+std::to_string(variant)+" configuring="+std::to_string(track);const int result=player.configure(resource,std::int32_t(key),std::uint16_t(track),frame,duration,clock,root_ref);const auto actual=call(ram.data(),0x58b9a0,actor,bank_at,key,track,frame,duration);check(result==std::int32_t(GPR_U32(&actual,2)),"complete original configuration return");records(player,ram,root);++config_cases;}
  for(unsigned track=0;track<2;++track){(void)player.bind_plain(a::ModelBank::secondary,resource,key,std::uint16_t(track),1.25f);R5900Context c;c.pc=0x58ce60;SET_GPR_U32(&c,4,actor);SET_GPR_U32(&c,5,bank_at);SET_GPR_U32(&c,6,key);SET_GPR_U32(&c,7,track);SET_GPR_U32(&c,8,1);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);c.f[12]=1.25f;PS2Runtime r;original_transform_port(ram.data(),&c,&r);check(c.pc==0xabcdef,"complete original plain secondary bind");records(player,ram,root);++plain_cases;}
  player.activate(5);call(ram.data(),0x58c7b0,actor);records(player,ram,root);player.or_primary_flags82();call(ram.data(),0x58c7f0,actor);player.or_packed_primary_flags(std::uint8_t(variant*3));call(ram.data(),0x5d5950,actor,variant*3);records(player,ram,root);
  auto independent=player.clone_independent();auto independent_root=root;
  a::RootMotionRef independent_ref{independent_root.x,independent_root.y,independent_root.z};
  check(independent.get()!=&player&&independent->model()!=player.model()&&independent->secondary_model()!=player.secondary_model(),"independent mutable playback/model banks");
  check(&independent->model()->skeleton()==&player.model()->skeleton()&&independent->resources==player.resources,"immutable authored identities remain shared");
  records(*independent,ram,independent_root);++independent_copies;
  for(unsigned tick=0;tick<16;++tick){const float step=tick%5==0?-1.f:1.f;const auto result=player.advance_primary(0,step,clock.mode,root_ref);const auto copy_result=independent->advance_primary(0,step,clock.mode,independent_ref);check(copy_result==result,"copied primary continuation return");const auto original=call(ram.data(),0x58c130,actor,0,0,0,step);check(result==std::int8_t(GPR_U32(&original,2)),"full root track advancement return");records(player,ram,root);records(*independent,ram,independent_root);++copy_continuations;++tick_cases;}
  for(unsigned tick=0;tick<4;++tick){const float weight=float(tick)*.25f;const auto result=player.advance_four_after_prelude(1,weight,clock.mode,clock.category,false,0);const auto copy_result=independent->advance_four_after_prelude(1,weight,clock.mode,clock.category,false,0);check(copy_result==result,"copied four-channel continuation return");const auto original=call(ram.data(),0x5d57d0,actor,0,0,0,1,weight);check(result==std::int8_t(GPR_U32(&original,2)),"full four-channel blend return");records(player,ram,root);records(*independent,ram,independent_root);++copy_continuations;++four_cases;}
  independent->channel(a::ModelBank::primary,0).auxiliary^=0x12345678;
  independent->channel(a::ModelBank::secondary,0).selector^=0xffff;
  independent->model()->local_translation(0,{111,222,333});
  independent->secondary_model()->local_translation(0,{-111,-222,-333});
  a::PoseBlend::root_reference(*independent->model(),{777,888,999});
  records(player,ram,root);++copy_isolations;
  for(unsigned tick=0;tick<8;++tick){const auto count=std::uint8_t((tick+variant)%6);player.progress_threshold=std::uint8_t(variant%7);put(ram.data(),actor+0xce3,player.progress_threshold);put(ram.data(),actor+0x524,count);put(ram.data(),actor+0xf80,std::uint32_t(tick%2?0xf3f:0));for(unsigned track=0;track<5;++track){player.channel(a::ModelBank::primary,track).skip_flags=std::uint8_t((tick+track)%3==0);export_channel(ram.data(),0,track,player.channel(a::ModelBank::primary,track));}const auto result=player.advance_channels_after_prelude(count,1,clock.mode,clock.category,true,tick%2?0xf3f:0,root_ref);const auto original=call(ram.data(),0x58c300,actor,0,0,0,1);check(result==std::int8_t(GPR_U32(&original,2)),"complete original ordered primary channel/skip/progress orchestration");records(player,ram,root);++orchestration_cases;}


  // Resident model reconstruction replaces node allocations, not actor-owned
  // channels/root fields. Recreate the original node banks with the complete
  // owned pack/constructor bodies. Resource/archive selection is outside this
  // focused case; the full5EC100 cache caller is qualified separately.
  location="model replacement variant="+std::to_string(variant);
  const auto held_primary=player.model(),held_secondary=player.secondary_model();
  held_primary->rebuild(t::identity());const auto held_pose=held_primary->retain();
  const auto held_joints=held_pose->joints;
  const a::Vector history{float(variant)+.25f,-2.5f,7.75f};
  a::PoseBlend::root_reference(*held_primary,history);put(ram.data(),actor+0x508,history);
  player.resources={std::make_shared<const a::MotionBank>(resource),nullptr,nullptr};
  player.resources_known=true;player.channel_count=std::uint8_t(variant%6);
  player.motion=std::int16_t(variant*17);player.source_kind=std::uint8_t(variant);
  player.source_slot=std::uint8_t(variant+3);const auto held_resources=player.resources;
  auto fresh=std::make_shared<a::Instance>(skeleton);
  player.replace_model(fresh);
  check(player.model()==fresh&&player.secondary_model()!=held_secondary&&
        &player.secondary_model()->skeleton()==&fresh->skeleton(),"new corresponding mutable model banks");
  check(player.resources==held_resources&&player.resources_known&&player.channel_count==variant%6&&
        player.motion==std::int16_t(variant*17)&&player.source_kind==variant&&player.source_slot==variant+3,
        "resident reconstruction retains actor resource/progress selectors");
  check(held_pose->joints==held_joints&&held_primary->retain()==nullptr,
        "retained published pose survives old model root invalidation");
  std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);
  std::fill_n(ram.data()+second,skeleton->nodes().size()*400,0);
  call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);
  records(player,ram,root);
  const auto same_secondary=player.secondary_model();player.replace_model(fresh);
  check(player.secondary_model()==same_secondary,"same canonical model retains secondary pose owner");
  bool rejected{};try{player.replace_model({});}catch(const std::invalid_argument&){rejected=true;}
  check(rejected&&player.model()==fresh&&player.secondary_model()==same_secondary,
        "absent model refuses before channel/model publication");++replacement_refusals;
  records(player,ram,root);
  // Old clips must not leak into either fresh node bank. The original sampler
  // runs on the independently reconstructed, initially unbound node records.
  (void)player.advance_primary(0,1,clock.mode,root_ref);
  call(ram.data(),0x58c130,actor,0,0,0,1);records(player,ram,root);
  for(unsigned track=0;track<2;++track){
   const float frame=float(variant%5)*.5f;
   const auto result=player.configure(resource,std::int32_t(key),std::uint16_t(track),frame,4,clock,root_ref);
   const auto original=call(ram.data(),0x58b9a0,actor,bank_at,key,track,frame,4);
   check(result==std::int32_t(GPR_U32(&original,2)),"replacement rebind full original return");records(player,ram,root);
  }
  for(unsigned tick=0;tick<4;++tick){
   const auto result=player.advance_primary(0,1,clock.mode,root_ref);
   const auto original=call(ram.data(),0x58c130,actor,0,0,0,1);
   check(result==std::int8_t(GPR_U32(&original,2)),"replacement continuation full original return");records(player,ram,root);
   ++replacement_continuations;
  }
  check(held_pose->joints==held_joints&&held_primary!=player.model(),"old published pose and model lease remain independent");
  ++model_replacement_cases;

 }

 // Cross-size, independently authored Skeletons and the no-secondary policy.
 for(const auto& initial_bytes:skeletons)for(const auto& replacement_bytes:skeletons)for(bool secondary_policy:{false,true}){
  location="cross-skeleton replacement";
  auto initial=std::make_shared<a::Instance>(a::Skeleton::import_raw(initial_bytes));
  auto replacement=std::make_shared<a::Instance>(a::Skeleton::import_raw(replacement_bytes));
  a::Playback owner(initial,secondary_policy);a::Vector delta{3,4,5};a::RootMotionRef root_ref{delta.x,delta.y,delta.z};
  const a::Vector history{2,4,8};a::PoseBlend::root_reference(*initial,history);
  std::fill_n(ram.data()+actor,0x10e0,0);std::fill_n(ram.data()+work,0x1468,0);
  std::fill_n(ram.data()+nodes,replacement->nodes().size()*400,0);std::fill_n(ram.data()+second,replacement->nodes().size()*400,0);
  std::memcpy(ram.data()+0x400000,replacement_bytes.data(),replacement_bytes.size());
  call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);
  put(ram.data(),actor+0x34,work);put(ram.data(),work,work+0x820);put(ram.data(),work+4,work+0xa20);
  put(ram.data(),work+0x816,std::uint16_t(replacement->nodes().size()));
  for(unsigned i=0;i<replacement->nodes().size();++i){put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);}
  put(ram.data(),actor+0x4e4,delta);put(ram.data(),actor+0x508,history);put(ram.data(),0x3243cc,std::uint8_t(0));
  for(unsigned bank=0;bank<2;++bank)for(unsigned track=0;track<5;++track){auto& channel=owner.channel(bank?a::ModelBank::secondary:a::ModelBank::primary,track);
   channel.timing.frame=float(track)+.5f;channel.timing.end=40;channel.timing.restart=2;channel.timing.loop=1;
   channel.selector=std::uint16_t(123+track);channel.mode=std::uint8_t(bank+7);channel.auxiliary=0x12345600+track;
   export_channel(ram.data(),bank,track,channel);
  }
  owner.replace_model(replacement);auto independent=owner.clone_independent();auto independent_delta=delta;a::RootMotionRef independent_ref{independent_delta.x,independent_delta.y,independent_delta.z};check(bool(independent->secondary_model())==secondary_policy&&independent->model()!=owner.model(),"copy retains secondary policy with independent model");++independent_copies;check(bool(owner.secondary_model())==secondary_policy,"cross-skeleton replacement preserves secondary policy");
  records(owner,ram,delta);
  const auto result=owner.advance_primary(0,1,0,root_ref);const auto copy_result=independent->advance_primary(0,1,0,independent_ref);check(copy_result==result,"cross-skeleton copy continuation return");const auto original=call(ram.data(),0x58c130,actor,0,0,0,1);
  check(result==std::int8_t(GPR_U32(&original,2)),"cross-skeleton unbound continuation return");records(owner,ram,delta);records(*independent,ram,independent_delta);++copy_continuations;
  ++model_replacement_cases;++replacement_continuations;
 }

 for(unsigned asset=2;asset<banks.size();++asset){a::MotionBank whole;whole.load_strided(banks[asset],200,0,"actual-whole");unsigned used{};for(unsigned key=0;key<100&&used<4;++key){const auto block=whole.find(key,0);if(!block)continue;location="whole import asset="+std::to_string(asset)+" key="+std::to_string(key);std::shared_ptr<const a::Clip> clip;try{clip=block->clip();}catch(const std::invalid_argument&){continue;}std::shared_ptr<const a::Skeleton> definition;std::vector<std::byte> raw;for(const auto& bytes:skeletons){auto candidate=a::Skeleton::import_raw(bytes);if(candidate->nodes().size()==clip->tracks().size()){definition=candidate;raw=bytes;break;}}if(!definition)continue;location="whole asset="+std::to_string(asset)+" key="+std::to_string(key);std::fill_n(ram.data()+nodes,definition->nodes().size()*400,0);std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);call(ram.data(),0x193380,nodes,1);resources={0,skeleton_resource,0x900000};std::memcpy(ram.data()+0x500000,block->bytes().data(),block->bytes().size());call(ram.data(),0x1a1fd0,0x18000,resources[2],0x500000);call(ram.data(),0x192a00,nodes,2);a::Instance model(definition);a::PoseBlend::bind_all(model,clip);for(float frame:{0.f,.5f,clip->last_frame()*.5f,clip->last_frame()}){location="whole asset="+std::to_string(asset)+" key="+std::to_string(key)+" frame="+std::to_string(frame);call(ram.data(),0x193220,nodes,0,0,0,frame);try{model.sample_all(frame);}catch(const std::exception&){unsigned nonfinite{};for(unsigned j=0;j<definition->nodes().size();++j)for(unsigned c=0;c<10;++c)if(!std::isfinite(get<float>(ram.data(),nodes+400*j+0x104+4*c)))++nonfinite;std::cerr<<"actual original nonfinite parameters="<<nonfinite<<"\n";throw;}compare_nodes(model,ram,false);model.rebuild(t::identity());put(ram.data(),0x270000,t::identity());call(ram.data(),0x193240,nodes,0x270000);compare_nodes(model,ram,true);++whole_model_cases;}++used;}check(used>0,"real whole-model cutscene motion is admitted for actual matching skeleton");}
 check(whole_model_cases>=8,"actual whole-model bind/sample/publication source path exercised");
#ifdef REO_WHOLE_PLAYBACK_TESTS
 scalar_playback_tests(banks,skeletons,ram);
 whole_playback_tests(banks,skeletons,ram);
 node_topology_tests(banks,skeletons,ram);
 primary_routing_tests(banks,skeletons,ram);
#endif
 std::uint32_t random=0x19d42u;for(unsigned i=0;i<4096;++i){random=random*1664525u+1013904223u;auto raw=random;if((raw&0x7f800000u)==0x7f800000u)raw^=0x00800000u;const float weight=std::bit_cast<float>(raw);const auto cast=call(ram.data(),0x1118b8,0,0,0,0,weight);R5900Context c;c.pc=0x111d48;SET_GPR_U64(&c,4,0x3ff0000000000000ull);SET_GPR_U64(&c,5,GPR_U64(&cast,2));SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);PS2Runtime rt;original_transform_port(ram.data(),&c,&rt);check(c.pc==0xabcdef,"full software-double complement body");R5900Context narrow;narrow.pc=0x112470;SET_GPR_U64(&narrow,4,GPR_U64(&c,2));SET_GPR_U32(&narrow,29,0x1f00000);SET_GPR_U32(&narrow,31,0xabcdef);original_transform_port(ram.data(),&narrow,&rt);check(narrow.pc==0xabcdef&&bits(a::motion_complement(weight))==bits(narrow.f[0]),"full original complement conversion weight="+std::to_string(raw)+" native="+std::to_string(bits(a::motion_complement(weight)))+" actual="+std::to_string(bits(narrow.f[0])));++transition_cases;}
 std::cout<<"{\"scalar_bindings\":"<<scalar_bindings<<",\"scalar_ticks\":"<<scalar_ticks<<",\"scalar_early_returns\":"<<scalar_early_returns<<",\"scalar_odd_endpoints\":"<<scalar_odd_endpoints<<",\"scalar_refusals\":"<<scalar_refusals<<",\"topology_patches\":"<<topology_patches<<",\"topology_mixed_blends\":"<<topology_mixed_blends<<",\"topology_pair_refusals\":"<<topology_pair_refusals<<",\"topology_samples\":"<<topology_samples<<",\"topology_blends\":"<<topology_blends<<",\"topology_parent_cases\":"<<topology_parent_cases<<",\"topology_refusals\":"<<topology_refusals<<",\"topology_copies\":"<<topology_copies<<",\"routing_refusals\":"<<routing_refusals<<",\"routing_queries\":"<<routing_queries<<",\"routing_owned_cases\":"<<routing_owned_cases<<",\"routing_controlled_prefixes\":"<<routing_controlled_prefixes<<",\"routing_continuations\":"<<routing_continuations<<",\"routing_tail_cases\":"<<routing_tail_cases<<",\"whole_reserved_owned_configurations\":"<<whole_reserved_owned_configurations<<",\"whole_reserved_configurations\":"<<whole_reserved_configurations<<",\"whole_reserved_ticks\":"<<whole_reserved_ticks<<",\"whole_reserved_nonzero_rows\":"<<whole_reserved_nonzero_rows<<",\"independent_copies\":"<<independent_copies<<",\"copy_continuations\":"<<copy_continuations<<",\"copy_isolations\":"<<copy_isolations<<",\"model_replacement_cases\":"<<model_replacement_cases<<",\"replacement_continuations\":"<<replacement_continuations<<",\"replacement_refusals\":"<<replacement_refusals<<",\"checks\":"<<checks<<",\"configuration_cases\":"<<config_cases<<",\"plain_bind_cases\":"<<plain_cases<<",\"primary_tick_cases\":"<<tick_cases<<",\"four_channel_cases\":"<<four_cases<<",\"joint_cases\":"<<joint_cases<<",\"whole_model_cases\":"<<whole_model_cases<<",\"whole_configuration_cases\":"<<whole_configuration_cases<<",\"whole_tick_cases\":"<<whole_tick_cases<<",\"whole_missing_cases\":"<<whole_missing_cases<<",\"whole_boundary_refusals\":"<<whole_boundary_refusals<<",\"orchestration_cases\":"<<orchestration_cases<<",\"complement_cases\":"<<transition_cases<<",\"original_prelude_calls\":"<<prelude_calls<<",\"original_calls\":"<<helper_calls<<",\"game_run\":false}\n";return 0;
}catch(const std::exception& e){std::cerr<<location<<" "<<e.what()<<'\n';return 1;}
