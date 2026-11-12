#include "game/native/gameplay_world/pose_parent_flight.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;
unsigned checks{},cases{},calls{},retirements{},queries{},trails{},sounds{};constexpr unsigned work_at=0x20000,parent_at=0x22000;
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Parent pose flight "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
struct Effects final:g::ParentFlightEffects {
    g::ParentFlightLaunch parent;g::Actor* actor{};bool alias{};unsigned reject{};
    c::response::Floor sampled;std::vector<unsigned> events;std::vector<m::Vector> points;
    std::optional<g::ParentFlightLaunch> launch(const g::actors::EntityId&)override{if(reject==1)return{};auto value=parent;if(alias){value.primary=actor->primary;value.secondary=actor->secondary;}return value;}
    std::optional<c::response::Floor> floor(m::Vector p)override{events.push_back(3);points.push_back(p);return reject==4?std::nullopt:std::optional(sampled);}
    bool trail(const g::actors::EntityId&,const g::actors::EntityId&,std::uint8_t mode)override{events.push_back(unsigned(mode)+1);return reject!=unsigned(mode)+2;}
    bool sound(const g::actors::EntityId&,std::uint8_t event)override{check(event==9);events.push_back(4);return reject!=5;}
} effects;
bool retired{};std::vector<unsigned> original_events;std::vector<m::Vector> original_points;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x578620:check(GPR_U32(context,5)==work_at&&GPR_U32(context,6)<2&&!GPR_U32(context,7)&&!GPR_U32(context,8));original_events.push_back(GPR_U32(context,6)+1);break;
    case 0x616f20:check(GPR_U32(context,6)==255);original_events.push_back(3);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));context->f[0]=effects.sampled.height;memory[GPR_U32(context,5)]=effects.sampled.type;break;
    case 0x1b9310:check(GPR_U32(context,5)==9&&!GPR_U32(context,6));original_events.push_back(4);break;
    case 0x582de0:check(GPR_U32(context,4)==work_at);retired=true;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted parent flight helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();effects.actor=&actor;
    for(unsigned profile=0;profile<8;++profile)for(unsigned n=0;n<65536;++n){
        actor.primary=std::uint8_t(profile<4?profile:0);actor.secondary=std::uint8_t(n>>8);actor.visible=n&1;actor.auxiliary_status=n*257;actor.position={float(int(n%17)-8)*.125f,float(int(n%31)-15)*.25f,float(int(n%37)-18)*.5f};actor.sampled_surface_height=-999;auto& state=*actor.pose_work;state.velocity={float(int(n%11)-5)*.25f,float(int(n%13)-6)*.125f,float(int(n%19)-9)*.5f};state.acceleration={.5f,-.75f,.125f};state.lifetime=std::bit_cast<std::int16_t>(std::uint16_t(n*17));effects.parent.primary=std::uint8_t(profile==4||profile==5?2:n);effects.parent.secondary=std::uint8_t(profile==4?0:profile==5?2:n>>8);effects.parent.basis={{{.5f,0,0,0},{.125f,2,0,0},{float(int(n%5)-2)*.25f,0,-1,0},{3,4,5,1}}};effects.sampled.height=float(int(n%41)-20)*.25f;effects.sampled.type=std::uint8_t(n);effects.alias=profile>=6;effects.events.clear();effects.points.clear();original_events.clear();original_points.clear();retired=false;
        memory[work_at+8]=actor.primary;memory[work_at+9]=actor.secondary;memory[work_at+1]=actor.visible;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);put(memory,work_at+0x38,actor.position);put(memory,work_at+0xc0,state.velocity);put(memory,work_at+0xcc,state.acceleration);put(memory,work_at+18,state.lifetime);put(memory,work_at+0x170,actor.sampled_surface_height);put(memory,work_at+0x28,effects.alias?work_at:parent_at);const auto owner=effects.alias?work_at:parent_at;memory[owner+8]=effects.alias?actor.primary:effects.parent.primary;memory[owner+9]=effects.alias?actor.secondary:effects.parent.secondary;put(memory,owner+0x50,effects.parent.basis);memory[0x3243cc]=std::uint8_t(n);
        R5900Context context;PS2Runtime runtime;context.pc=0x584500;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        const auto step=g::advance_parent_pose_flight(actor,{},std::uint8_t(n),effects);check(step==(retired?g::ParentFlightStep::retire:g::ParentFlightStep::completed));check(actor.primary==memory[work_at+8]&&actor.visible==bool(memory[work_at+1])&&std::uint8_t(actor.auxiliary_status)==memory[work_at+0x115]);check(state.lifetime==get<std::int16_t>(memory,work_at+18)&&actor.sampled_surface_height==get<float>(memory,work_at+0x170));check(std::memcmp(&actor.position,memory+work_at+0x38,12)==0&&std::memcmp(&state.velocity,memory+work_at+0xc0,12)==0&&std::memcmp(&state.acceleration,memory+work_at+0xcc,12)==0);check(effects.events==original_events&&effects.points.size()==original_points.size());if(!effects.points.empty())check(std::memcmp(effects.points.data(),original_points.data(),12)==0);retirements+=retired;queries+=unsigned(effects.points.size());for(const auto event:effects.events){trails+=event<3;sounds+=event==4;}++cases;
    }
    effects.alias=false;effects.parent.primary=2;effects.parent.secondary=0;effects.parent.basis=m::identity();effects.sampled.height=1000;
    for(unsigned rejection=1;rejection<=5;++rejection){actor.primary=0;actor.position={};effects.reject=rejection;check(g::advance_parent_pose_flight(actor,{},0,effects)==g::ParentFlightStep::unavailable&&actor.primary==1);}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"floor_queries\":"<<queries<<",\"trails\":"<<trails<<",\"sounds\":"<<sounds<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
