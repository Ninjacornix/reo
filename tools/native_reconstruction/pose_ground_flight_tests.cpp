#include "game/native/gameplay_world/pose_ground_flight.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;namespace c=reo::native::gameplay_collision;
unsigned checks{},cases{},calls{},retirements{},queries{},packets{},flares{},trail_requests{},sounds{};constexpr unsigned work_at=0x20000,parent_at=0x22000;
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Ground pose flight "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
struct Effects final:g::GroundPoseEffects {
    g::Actor* actor{};c::response::Floor sampled;unsigned reject{};std::vector<unsigned> events;std::vector<m::Vector> points;
    std::optional<c::response::Floor> floor(m::Vector p)override{events.push_back(0);points.push_back(p);return reject==1?std::nullopt:std::optional(sampled);}
    bool packet(const g::actors::EntityId&,std::uint8_t descriptor,std::uint8_t bank)override{check(descriptor==3&&bank==1);events.push_back(1);return reject!=2;}
    bool flare(const g::actors::EntityId&)override{events.push_back(2);return reject!=3;}
    bool trail(const g::actors::EntityId&)override{events.push_back(3);return reject!=4;}
    bool retire(const g::actors::EntityId&)override{events.push_back(4);if(reject==5)return false;actor->active=actor->visible=false;return true;}
    bool sound(const g::actors::EntityId&,std::uint8_t event)override{check(event==7);events.push_back(5);return reject!=6;}
} effects;
std::vector<unsigned> original_events;std::vector<m::Vector> original_points;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x616f20:check(GPR_U32(context,6)==255);original_events.push_back(0);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));context->f[0]=effects.sampled.height;memory[GPR_U32(context,5)]=effects.sampled.type;break;
    case 0x5da2c0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,5)==3&&GPR_U32(context,6)==1);original_events.push_back(1);break;
    case 0x57f990:case 0x57faa0:check(GPR_U32(context,4)==work_at);original_events.push_back(context->pc==0x57f990?2:3);break;
    case 0x582de0:check(GPR_U32(context,4)==work_at);original_events.push_back(4);memory[work_at]=memory[work_at+1]=0;break;
    case 0x1b9310:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==7&&!GPR_U32(context,6));original_events.push_back(5);break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted ground pose helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();effects.actor=&actor;
    for(unsigned phase:{0u,1u,2u,255u})for(unsigned n=0;n<65536;++n){
        actor.primary=std::uint8_t(phase);actor.visible=n&1;actor.active=true;actor.auxiliary_status=n*257;actor.position={float(int(n%17)-8)*.125f,float(int(n%31)-15)*.25f,float(int(n%37)-18)*.5f};actor.sampled_surface_height=float(int(n%43)-21)*.25f;actor.orientation={std::int16_t(n*19),std::int16_t(n*257),std::int16_t(n*251),-17};auto& state=*actor.pose_work;state.velocity={1,float(int(n%13)-6)*.125f,2};state.acceleration={3,float(int(n%19)-9)*.0625f,4};state.lifetime=std::bit_cast<std::int16_t>(std::uint16_t(n*17));effects.sampled.height=float(int(n%41)-20)*.25f;effects.sampled.type=std::uint8_t(n);effects.events.clear();effects.points.clear();original_events.clear();original_points.clear();
        memory[work_at]=actor.active;memory[work_at+8]=actor.primary;memory[work_at+1]=actor.visible;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);put(memory,work_at+0x38,actor.position);put(memory,work_at+0xc0,state.velocity);put(memory,work_at+0xcc,state.acceleration);put(memory,work_at+18,state.lifetime);put(memory,work_at+0x90,actor.orientation);put(memory,work_at+0x170,actor.sampled_surface_height);put(memory,work_at+0x28,parent_at);
        R5900Context context;PS2Runtime runtime;context.pc=0x583030;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        check(g::advance_ground_pose_flight(actor,{},effects));check(actor.primary==memory[work_at+8]&&actor.visible==bool(memory[work_at+1])&&actor.active==bool(memory[work_at])&&std::uint8_t(actor.auxiliary_status)==memory[work_at+0x115]);check(state.lifetime==get<std::int16_t>(memory,work_at+18)&&actor.sampled_surface_height==get<float>(memory,work_at+0x170));check(std::memcmp(&actor.position,memory+work_at+0x38,12)==0&&std::memcmp(&state.velocity,memory+work_at+0xc0,12)==0&&std::memcmp(&state.acceleration,memory+work_at+0xcc,12)==0&&std::memcmp(actor.orientation.data(),memory+work_at+0x90,8)==0);check(effects.events==original_events&&effects.points.size()==original_points.size());if(!effects.points.empty())check(std::memcmp(effects.points.data(),original_points.data(),12)==0);for(const auto event:effects.events){queries+=event==0;packets+=event==1;flares+=event==2;trail_requests+=event==3;retirements+=event==4;sounds+=event==5;}++cases;
    }
    for(unsigned reject=1;reject<=6;++reject){effects.reject=reject;actor.primary=reject<5?0:1;actor.position={};actor.sampled_surface_height=1000;actor.pose_work->velocity={};check(!g::advance_ground_pose_flight(actor,{},effects));}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"floor_queries\":"<<queries<<",\"packets\":"<<packets<<",\"flares\":"<<flares<<",\"trails\":"<<trail_requests<<",\"sounds\":"<<sounds<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
