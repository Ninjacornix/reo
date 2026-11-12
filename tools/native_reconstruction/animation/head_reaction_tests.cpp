#include "game/native/gameplay_world/head_reaction.hpp"
#include "game/native/animation/model.hpp"
#include "game/native/animation/playback.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace t=reo::native::transform_math;
std::uint64_t checks{},original_calls{},directions{},transitions{},resets{},updates{},wrappers{},gates{},refusals{};
unsigned case_index{};std::string phase;
bool ordinary_projection{};w::OrdinaryHeadAction ordinary_observed{};unsigned ordinary_head_calls{};std::uint64_t ordinary_choices{};
void check(bool value,std::source_location at=std::source_location::current()) {++checks;if(!value)throw std::runtime_error("Head reaction "+phase+" case "+std::to_string(case_index)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++original_calls;
 if(ordinary_projection){switch(context->pc){
 case 0x1b02d0:case 0x1b0340:SET_GPR_U32(context,2,0);context->pc=GPR_U32(context,31);return;
 case 0x581870:case 0x6660b0:case 0x61a820:context->pc=GPR_U32(context,31);return;
 case 0x661310:ordinary_observed=w::OrdinaryHeadAction::reset;++ordinary_head_calls;context->pc=GPR_U32(context,31);return;
 case 0x6613a0:check(GPR_U32(context,5)==1);ordinary_observed=w::OrdinaryHeadAction::track;++ordinary_head_calls;context->pc=GPR_U32(context,31);return;
 default:break;}}
 switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared original head helper "+std::to_string(context->pc));}}
constexpr unsigned actor_at=0x200000,work_at=0x210000,nodes_at=0x300000,vector_at=0x220000;
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
unsigned invoke(std::uint8_t* memory,unsigned pc,unsigned first=actor_at,unsigned second=0,unsigned third=0,float distance=0,unsigned fourth=0){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,first);SET_GPR_U32(&context,5,second);SET_GPR_U32(&context,6,third);SET_GPR_U32(&context,7,fourth);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);context.f[12]=distance;original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);}
void export_actor(std::uint8_t* memory,const w::Actor& actor,const w::World& world){
 std::fill_n(memory+actor_at,0x10e0,0);put(memory,actor_at+0x34,work_at);put(memory,actor_at+0xba0,actor.status);put(memory,actor_at+0x92,actor.orientation[1]);put(memory,actor_at+0x38,actor.position);
 const auto& h=*actor.head_reaction;put(memory,actor_at+0xbd1,h.mode);put(memory,actor_at+0xbd2,h.ticks);put(memory,actor_at+0xbd4,h.step);put(memory,actor_at+0xbd8,h.current);put(memory,actor_at+0xbdc,h.applied);put(memory,actor_at+0xbf0,h.local);put(memory,actor_at+0xc30,h.retarget_ticks);put(memory,actor_at+0xfa4,h.input);
 const auto& script=*actor.scripted;put(memory,actor_at+0xb3c,script.request_flags);put(memory,actor_at+0xb48,script.relation_mode);put(memory,actor_at+0xb50,script.relation_options);put(memory,actor_at+0xb54,script.relation_offset);put(memory,actor_at+0xb60,script.relation_parameter);
 put(memory,actor_at+0x211,actor.animation->channel(a::ModelBank::primary,1).timing.flags);put(memory,0x3243cc,world.session().clock_mode);put(memory,0x324200,world.session().session_state);put(memory,0x4badf8,world.paused);
 const auto& instance=*actor.model;for(unsigned n=0;n<instance.nodes().size();++n){const auto at=nodes_at+400*n;put(memory,work_at+0x820+4*n,at);const auto& node=instance.nodes()[n];put(memory,at,node.world);put(memory,at+0x40,node.local);put(memory,at+0x104,node.parameters);put(memory,at+0xdc,instance.skeleton().nodes()[n].defaults);const auto& links=instance.links()[n];put(memory,at+0xc8,links.parent?nodes_at+400*unsigned(*links.parent):0u);put(memory,at+0xcc,links.sibling?nodes_at+400*unsigned(*links.sibling):0u);put(memory,at+0xd0,links.child?nodes_at+400*unsigned(*links.child):0u);}
}
void compare(std::uint8_t* memory,const w::Actor& actor){
 const auto& state=*actor.head_reaction;if(state.mode!=transform_read<std::uint8_t>(memory,actor_at+0xbd1)||state.ticks!=transform_read<std::int16_t>(memory,actor_at+0xbd2)||std::memcmp(state.current.data(),memory+actor_at+0xbd8,4))std::cerr<<"state native mode="<<unsigned(state.mode)<<" ticks="<<state.ticks<<" current="<<state.current[0]<<','<<state.current[1]<<" source mode="<<unsigned(transform_read<std::uint8_t>(memory,actor_at+0xbd1))<<" ticks="<<transform_read<std::int16_t>(memory,actor_at+0xbd2)<<" current="<<transform_read<std::int16_t>(memory,actor_at+0xbd8)<<','<<transform_read<std::int16_t>(memory,actor_at+0xbda)<<'\n';
 const auto& h=*actor.head_reaction;check(h.mode==transform_read<std::uint8_t>(memory,actor_at+0xbd1));check(h.ticks==transform_read<std::int16_t>(memory,actor_at+0xbd2));check(std::memcmp(h.step.data(),memory+actor_at+0xbd4,4)==0);check(std::memcmp(h.current.data(),memory+actor_at+0xbd8,4)==0);check(std::memcmp(h.applied.data(),memory+actor_at+0xbdc,4)==0);check(h.retarget_ticks==transform_read<std::int16_t>(memory,actor_at+0xc30));check(std::memcmp(&h.local,memory+actor_at+0xbf0,64)==0);check(actor.scripted->request_flags==transform_read<std::uint32_t>(memory,actor_at+0xb3c));check(actor.scripted->relation_parameter==transform_read<std::uint32_t>(memory,actor_at+0xb60));
 for(unsigned n=0;n<actor.model->nodes().size();++n){const auto& node=actor.model->nodes()[n];const auto at=nodes_at+400*n;
  if(std::memcmp(&node.local,memory+at+0x40,64)||std::memcmp(&node.world,memory+at,64))std::cerr<<"matrix mismatch node="<<n<<" phase="<<phase<<" case="<<case_index<<'\n';
  check(std::memcmp(&node.local,memory+at+0x40,64)==0);check(std::memcmp(&node.world,memory+at,64)==0);check(std::memcmp(node.parameters.data(),memory+at+0x104,40)==0);
 }
}
#include "head_reaction_targets_tests.inc"
#include "head_reaction_pass_tests.inc"
void ordinary_tests(std::uint8_t* memory,const std::shared_ptr<const a::Skeleton>& skeleton){
 phase="ordinary selection";w::Actor actor;actor.model=std::make_shared<a::Instance>(skeleton);actor.animation=std::make_shared<a::Playback>(actor.model);constexpr unsigned base=0x4a5c30;std::fill_n(memory+base,8*0x10e0,0);put(memory,base,std::uint8_t(1));put(memory,base+0x1e2,std::uint16_t(7));put(memory,0x3243dc,std::uint16_t(7));ordinary_projection=true;
 for(unsigned category:{0u,1u,2u})for(unsigned primary=0;primary<4;++primary)for(unsigned secondary:{0u,1u,255u})for(unsigned motion=0;motion<256;++motion)for(unsigned selected:{0u,0x2011u,0x2014u,65535u})for(unsigned flags:{0u,0x80u}){
  actor.category=std::uint8_t(category);actor.primary=std::uint8_t(primary);actor.secondary=std::uint8_t(secondary);actor.motion_class=std::uint8_t(motion);actor.animation->motion=std::bit_cast<std::int16_t>(std::uint16_t(selected));actor.status=flags;put(memory,base+2,actor.category);put(memory,base+8,actor.primary);put(memory,base+9,actor.secondary);put(memory,base+0x54f,actor.motion_class);put(memory,base+0x520,actor.animation->motion);put(memory,base+0xba0,actor.status);ordinary_observed=w::OrdinaryHeadAction::unchanged;ordinary_head_calls=0;invoke(memory,0x66a3a0);
  if(w::ordinary_head_action(actor)!=ordinary_observed||ordinary_head_calls!=(category?0u:1u))std::cerr<<"ordinary category="<<category<<" primary="<<primary<<" secondary="<<secondary<<" class="<<motion<<" motion="<<selected<<" status="<<flags<<" native="<<unsigned(w::ordinary_head_action(actor))<<" source="<<unsigned(ordinary_observed)<<" calls="<<ordinary_head_calls<<'\n';
  check(w::ordinary_head_action(actor)==ordinary_observed&&ordinary_head_calls==(category?0u:1u));++ordinary_choices;
 }
 ordinary_projection=false;
}
int main(int argc,char** argv)try{
 check(argc==2);const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);
 std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());put(memory.data(),0x294e00,t::identity());
 std::uint32_t random=0x735192ec;const auto next=[&](){random=random*1664525u+1013904223u;return random;};const auto value=[&](){return float(std::int32_t(next()%65537)-32768)/64.f;};
 phase="directions";for(unsigned i=0;i<65536;++i){case_index=i;t::Vector from{value(),value(),value()},to{value(),value(),value()};if(i%31==0)to.x=from.x;if(i%37==0)to=from;put(memory.data(),vector_at,from);put(memory.data(),vector_at+16,to);invoke(memory.data(),0x376ef0,vector_at+32,vector_at,vector_at+16);const auto angles=w::head_direction_turns(from,to);check(std::memcmp(angles.data(),memory.data()+vector_at+32,6)==0);++directions;}
 std::ifstream input(argv[1],std::ios::binary);check(bool(input));unsigned count{};input.read(reinterpret_cast<char*>(&count),4);check(count==3);
 w::Profile profile;profile.layouts.push_back({});auto session=std::make_shared<w::Session>();w::World world(profile,session);
 for(unsigned asset=0;asset<count;++asset){unsigned size{};input.read(reinterpret_cast<char*>(&size),4);std::vector<std::byte> raw(size);input.read(reinterpret_cast<char*>(raw.data()),size);check(bool(input));const auto skeleton=a::Skeleton::import_raw(raw);check(skeleton->nodes().size()>21);
  if(!asset){ordinary_tests(memory.data(),skeleton);target_tests(memory.data(),skeleton);pass_tests(memory.data(),skeleton);}
  for(unsigned i=0;i<1024;++i){case_index=asset*1024+i;w::Actor actor;actor.head_reaction.emplace();actor.scripted.emplace();actor.model=std::make_shared<a::Instance>(skeleton);actor.animation=std::make_shared<a::Playback>(actor.model);auto basis=t::identity();t::compose_euler_axes(basis,{std::uint16_t(i*1237),std::uint16_t(i*719),std::uint16_t(i*2797)});basis[3]={float(int(i)-450),float(i%21)-11.f,float(i%19)*-3.f,1};actor.model->root_scale({1.f+float(i%3)*.125f,1.f+float(i%5)*.125f,1.f+float(i%7)*.125f});actor.model->rebuild(basis);
   auto& h=*actor.head_reaction;h.mode=std::uint8_t(i%7);h.ticks=std::int16_t((i%29)-5);h.current={std::bit_cast<std::int16_t>(std::uint16_t(next())),std::bit_cast<std::int16_t>(std::uint16_t(next()))};h.step={std::int16_t(i%17),std::int16_t(-int(i%23))};h.applied={123,456};h.retarget_ticks=std::int16_t(i%9);h.input={std::int16_t(int(i%255)-127),std::int16_t(int(i*7%255)-127)};h.local=basis;actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(i*1111));actor.scripted->relation_parameter=std::array<std::uint32_t,5>{0,1,60,65535,UINT32_MAX}[i%5];actor.scripted->relation_offset={value(),value(),value()};session->clock_mode=std::uint8_t(i%3);world.paused=std::int8_t(i%2);session->session_state=std::int16_t(i%3);actor.animation->channel(a::ModelBank::primary,1).timing.flags=std::uint8_t(i%11==0?0x18:0);actor.status=i%13==0?0x8000u:i%17==0?0x38u:0u;
   if(i<256){phase="transition";const std::array<std::int16_t,3> angles{std::bit_cast<std::int16_t>(std::uint16_t(next())),std::bit_cast<std::int16_t>(std::uint16_t(next())),std::int16_t(i)};export_actor(memory.data(),actor,world);put(memory.data(),vector_at,angles);const auto retained=actor.model->retain();const auto old_joints=retained->joints;invoke(memory.data(),0x661160,actor_at,vector_at);w::advance_head_reaction(actor,angles);compare(memory.data(),actor);check(retained->joints==old_joints);++transitions;}
   else if(i<320){phase="reset";export_actor(memory.data(),actor,world);invoke(memory.data(),0x661310);w::reset_head_reaction(actor);compare(memory.data(),actor);++resets;}
   else if(i<800){phase="update";const unsigned mode=std::array<unsigned,7>{0,2,3,4,5,6,255}[i%7];const w::HeadReactionContext context{w::Position{33,7,-88}};put(memory.data(),0x4a6d48,*context.camera);export_actor(memory.data(),actor,world);invoke(memory.data(),0x6613a0,actor_at,mode);const auto result=w::update_head_reaction(world,actor,std::uint8_t(mode),context);check(result==w::HeadReactionStatus::applied||result==w::HeadReactionStatus::unchanged);compare(memory.data(),actor);++updates;}
   else{phase="wrapper";actor.scripted->request_flags=(i%2?4u:0u)|0x8100u;actor.scripted->relation_mode=i%11==0?2:0;export_actor(memory.data(),actor,world);invoke(memory.data(),0x67c100);const auto result=w::update_scripted_head_reaction(world,actor);check(result==w::HeadReactionStatus::applied||result==w::HeadReactionStatus::unchanged);compare(memory.data(),actor);++wrappers;}
  }
 }
 std::cout<<"{\"checks\":"<<checks<<",\"directions\":"<<directions<<",\"transitions\":"<<transitions<<",\"resets\":"<<resets<<",\"updates\":"<<updates<<",\"wrappers\":"<<wrappers<<",\"ordinary_choices\":"<<ordinary_choices<<",\"target_queries\":"<<target_queries<<",\"target_updates\":"<<target_updates<<",\"relation_updates\":"<<relation_updates<<",\"cinematic_passes\":"<<cinematic_passes<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
