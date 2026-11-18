#include "game/native/gameplay_effects/inherited_trail.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <algorithm>
#include <iostream>
#include <source_location>
#include <vector>
namespace e=reo::native::gameplay_effects;namespace m=reo::native::transform_math;namespace s=reo::native::gameplay_session;
unsigned checks{},cases{},calls{},samples{},impacts{},retirements{},floors{};constexpr unsigned work_at=0x20000,motion_at=0x22000,parent_at=0x24000,impact_at=0x26000,bank_at=0x28000,metadata_at=0x30000,draw_at=0x34000,children_at=0x40000;
void check(bool v,std::source_location p=std::source_location::current()){++checks;if(!v)throw std::runtime_error("Inherited trail "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T v){transform_write(p,at,v);}
struct Edit final:e::WorkEdit {reo::native::gameplay_actors::EntityId identity()const noexcept override{return{};}bool uniform_scale(float)noexcept override{return false;}bool third_angle(std::int16_t)noexcept override{return false;}bool add_attributes(std::uint16_t)noexcept override{return false;}bool set_attributes(std::uint16_t)noexcept override{return false;}bool feedback(m::Vector,float)noexcept override{return false;}};
std::vector<unsigned> original_events;std::vector<m::Vector> original_points;std::vector<e::WorkRequest> original_requests;s::Random original_random;bool retired{},allocated{};unsigned source_samples{};e::InheritedTrailState sampled;std::array<std::int16_t,2> rotation{};
e::InheritedTrailState read_state(std::uint8_t* p){e::InheritedTrailState x;x.phase=p[work_at+8];x.ordinal=p[work_at+5];x.parent_type=p[work_at+0x32];x.latched=p[work_at+9];x.motion_variant=p[work_at+10];x.visible=p[work_at+1];x.delay=get<std::int16_t>(p,work_at+12);x.remaining=get<std::int16_t>(p,work_at+14);x.age=get<std::int16_t>(p,work_at+16);x.rotation_offset=get<std::int16_t>(p,work_at+0x234);x.attributes=get<std::uint16_t>(p,work_at+0x23e);x.position=get<m::Vector>(p,work_at+0x38);x.previous_position=get<m::Vector>(p,work_at+0x44);x.velocity=get<m::Vector>(p,work_at+0xc0);x.acceleration=get<m::Vector>(p,work_at+0xcc);x.target=get<m::Vector>(p,work_at+0xe4);x.scale=get<m::Vector>(p,work_at+0xb4);x.angles=get<std::array<std::int16_t,4>>(p,work_at+0x90);x.feedback_scale=get<float>(p,work_at+0xa8);return x;}
void vector_equal(const char* label,m::Vector a,m::Vector b){++checks;if(std::memcmp(&a,&b,12))throw std::runtime_error(std::string(label)+" case "+std::to_string(cases)+" actual "+std::to_string(a.x)+","+std::to_string(a.y)+","+std::to_string(a.z)+" source "+std::to_string(b.x)+","+std::to_string(b.y)+","+std::to_string(b.z));}
void equal(const e::InheritedTrailState& a,const e::InheritedTrailState& b){
 check(a.phase==b.phase&&a.ordinal==b.ordinal&&a.parent_type==b.parent_type&&a.latched==b.latched&&a.motion_variant==b.motion_variant&&a.visible==b.visible);
 check(a.delay==b.delay&&a.remaining==b.remaining&&a.age==b.age&&a.rotation_offset==b.rotation_offset&&a.attributes==b.attributes);
 vector_equal("position",a.position,b.position);vector_equal("previous",a.previous_position,b.previous_position);vector_equal("velocity",a.velocity,b.velocity);vector_equal("acceleration",a.acceleration,b.acceleration);vector_equal("target",a.target,b.target);vector_equal("scale",a.scale,b.scale);
 check(a.angles==b.angles);check(std::bit_cast<unsigned>(a.feedback_scale)==std::bit_cast<unsigned>(b.feedback_scale));
}

struct Operations final:e::InheritedTrailOperations {
 float height{};bool available{true},reject{};std::vector<unsigned> events;std::vector<m::Vector> points;std::vector<e::WorkRequest> requests;std::shared_ptr<Edit> edit=std::make_shared<Edit>();
 std::optional<float> floor(m::Vector p)override{events.push_back(1);points.push_back(p);return available?std::optional(height):std::nullopt;}
 bool contact_cue(m::Vector p)override{events.push_back(2);points.push_back(p);return!reject;}
 e::WorkCreated impact(const e::WorkRequest& q)override{events.push_back(3);requests.push_back(q);return{allocated?e::WorkStatus::completed:e::WorkStatus::pool_full,allocated?edit:nullptr};}
 bool configure_impact(const e::WorkCreated& made,m::Vector tint,m::Vector scale)override{check(made.edit==edit);events.push_back(4);check(std::memcmp(&tint,&impact_color,12)==0&&std::memcmp(&scale,&impact_scale,12)==0);return!reject;}
 bool contact_burst(m::Vector p)override{events.push_back(5);points.push_back(p);return!reject;}
 bool sample(const e::InheritedTrailState& state)override{events.push_back(6);equal(state,sampled);return!reject;}
 m::Vector impact_color,impact_scale;
} operations;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;switch(context->pc){
 case 0x1aec80:check(GPR_U32(context,4)==1);SET_GPR_U32(context,2,original_random.request(1));break;
 case 0x616f20:check(GPR_U32(context,6)==255);original_events.push_back(1);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));memory[GPR_U32(context,5)]=0;context->f[0]=operations.height;++floors;break;
 case 0x654d40:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==14);original_events.push_back(2);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,6)));break;
 case 0x6525c0:case 0x6525d0:{check(!GPR_U32(context,4)&&!GPR_U32(context,6)&&GPR_U32(context,9)==0x1a193);e::WorkRequest q;q.position=get<m::Vector>(memory,GPR_U32(context,5));q.effect=std::uint16_t(GPR_U32(context,7));q.variant=std::int16_t(GPR_U32(context,8));q.update=context->pc==0x6525d0?e::WorkUpdate::scaled:e::WorkUpdate::ordinary;if(q.update==e::WorkUpdate::scaled)check(GPR_U32(context,10)==0x653e80);original_events.push_back(3);original_requests.push_back(q);SET_GPR_U32(context,2,allocated?impact_at:0);++impacts;break;}
 case 0x5783a0:check(GPR_U32(context,4)==parent_at&&!GPR_U32(context,6)&&!GPR_U32(context,7));original_events.push_back(5);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,5)));break;
 case 0x652880:check(GPR_U32(context,4)==work_at&&std::uint16_t(GPR_U32(context,7))==get<std::uint16_t>(memory,work_at+0x23e));if(source_samples++==0){original_events.push_back(6);sampled=read_state(memory);}SET_GPR_U32(context,2,1);++samples;break;
 case 0x652d60:check(GPR_U32(context,4)==work_at);original_events.push_back(7);break;
 case 0x651d00:check(GPR_U32(context,4)==work_at);retired=true;break;
#include "original_dispatch.hpp"
 default:throw std::runtime_error("Unadmitted inherited trail helper "+std::to_string(context->pc));
 }context->pc=GPR_U32(context,31);
}
int main()try{
 std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);
 for(unsigned profile=0;profile<6;++profile)for(unsigned n=0;n<65536;++n){
  e::InheritedTrailState state;state.phase=std::uint8_t(profile<4?profile:2);state.ordinal=std::uint8_t(n%5);constexpr unsigned types[]{7,10,19,29,30,0};state.parent_type=std::uint8_t(types[(n/5)%6]);state.latched=std::uint8_t((n>>6)&1);state.motion_variant=std::uint8_t((n>>7)&3);state.visible=n&1;state.delay=std::bit_cast<std::int16_t>(std::uint16_t(n));state.remaining=std::bit_cast<std::int16_t>(std::uint16_t(n*23));state.age=std::bit_cast<std::int16_t>(std::uint16_t(n*31));state.rotation_offset=std::bit_cast<std::int16_t>(std::uint16_t(n*17));state.attributes=std::uint16_t(n*257);state.position={float(n%17),float(int(n%23)-11),float(n%19)};state.previous_position={-1,-2,-3};state.velocity={float(int(n%11)-5)*.125f,float(int(n%13)-6)*.25f,float(int(n%7)-3)*.125f};state.acceleration={1,-.125f,2};state.target={7,float(int(n%31)-15),8};state.scale={.5f,.75f,1.25f};state.angles={std::int16_t(n*19),std::int16_t(n*257),std::int16_t(n*251),-7};state.feedback_scale=float(n%29)*.0625f;
  e::InheritedTrailMotion motion{std::uint8_t(profile==4?0x12:0),std::uint8_t((n>>5)&3),std::uint8_t((n>>8)&3),{1,float(int(n%27)-13),3}};operations.height=profile==5?100.f:float(int(n%41)-20);allocated=(n>>2)&1;const unsigned seed=n*1021+profile;const s::RandomState initial{std::uint16_t(seed),std::uint16_t(seed>>16),std::uint8_t(seed)};s::Random random(initial);original_random=s::Random(initial);operations.events.clear();operations.points.clear();operations.requests.clear();original_events.clear();original_points.clear();original_requests.clear();source_samples=0;retired=false;
  std::memset(memory+work_at,0,0x240);std::memset(memory+impact_at,0,0x240);memory[work_at+8]=state.phase;memory[work_at+5]=state.ordinal;memory[work_at+0x32]=state.parent_type;memory[work_at+9]=state.latched;memory[work_at+10]=state.motion_variant;memory[work_at+1]=state.visible;put(memory,work_at+12,state.delay);put(memory,work_at+14,state.remaining);put(memory,work_at+16,state.age);put(memory,work_at+0x234,std::int32_t(state.rotation_offset));put(memory,work_at+0x23e,state.attributes);put(memory,work_at+0x38,state.position);put(memory,work_at+0x44,state.previous_position);put(memory,work_at+0xc0,state.velocity);put(memory,work_at+0xcc,state.acceleration);put(memory,work_at+0xe4,state.target);put(memory,work_at+0xb4,state.scale);put(memory,work_at+0x90,state.angles);put(memory,work_at+0xa8,state.feedback_scale);put(memory,work_at+0x24,motion_at);put(memory,work_at+0x28,parent_at);memory[motion_at+4]=motion.kind;memory[motion_at+8]=motion.primary;memory[motion_at+11]=motion.variant;put(memory,motion_at+0x38,motion.position);
  memory[work_at+0x31]=2;put(memory,work_at+0x1f4,bank_at);put(memory,bank_at+0x18,metadata_at);put(memory,metadata_at+0x808,draw_at);
  for(unsigned i=0;i<2;++i){const auto child=children_at+i*0x100;put(memory,work_at+0x134+4*i,child);put(memory,work_at+0x114+2*i,std::int16_t(i+1));memory[child+1]=0;put(memory,child+2,std::uint16_t(i));put(memory,metadata_at+0x1024+32*i,std::int16_t(i));put(memory,draw_at+152*i+4,unsigned(i+1));rotation[i]=std::int16_t(n+101*i);put(memory,child+0x34,rotation[i]);}
  R5900Context context;PS2Runtime runtime;context.pc=0x5789c0;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);for(unsigned dispatch=0;context.pc!=0x1234&&dispatch<8;++dispatch)original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
  if(allocated&&!original_requests.empty()&&original_requests.back().update==e::WorkUpdate::scaled){const auto where=std::find(original_events.begin(),original_events.end(),3);original_events.insert(where+1,4);operations.impact_color=get<m::Vector>(memory,impact_at+0x208);operations.impact_scale=get<m::Vector>(memory,impact_at+0xb4);}
  const auto result=e::advance_inherited_trail(state,motion,operations,random);check(result.available&&result.retire==retired);if(retired)operations.events.push_back(7);equal(state,read_state(memory));check(operations.events==original_events&&operations.points.size()==original_points.size()&&operations.requests.size()==original_requests.size());for(unsigned i=0;i<operations.points.size();++i)check(std::memcmp(&operations.points[i],&original_points[i],12)==0);for(unsigned i=0;i<operations.requests.size();++i){const auto& a=operations.requests[i];const auto& b=original_requests[i];check(a.effect==b.effect&&a.variant==b.variant&&a.child_mask==b.child_mask&&a.flags==b.flags&&a.update==b.update&&std::memcmp(&*a.position,&*b.position,12)==0);}
  if(source_samples)for(unsigned i=0;i<2;++i)check(get<std::int16_t>(memory,children_at+i*0x100+0x34)==std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(rotation[i])+std::uint16_t(state.rotation_offset)*(i+1))));
  check(random.state()==original_random.state());retirements+=retired;++cases;
 }
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"samples\":"<<samples<<",\"impacts\":"<<impacts<<",\"retirements\":"<<retirements<<",\"floor_queries\":"<<floors<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
