#include "game/native/gameplay_world/pose_forward_projectile.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;namespace m=reo::native::transform_math;
unsigned checks{},cases{},calls{},retirements{},visuals{},sounds{},packets{},lights{};constexpr unsigned work_at=0x20000;
void check(bool value,std::source_location p=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Forward pose projectile "+std::to_string(p.line())+" case "+std::to_string(cases));}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);}
struct Effects final:g::ForwardProjectileEffects {
    g::Actor* actor{};unsigned reject{};std::vector<unsigned> events;std::vector<m::Vector> points;
    bool visual(const g::actors::EntityId&)override{events.push_back(1);return reject!=1;}
    bool sound(const g::actors::EntityId&,std::uint8_t packed)override{events.push_back(0x100+packed);return reject!=2;}
    bool packet(const g::actors::EntityId&,std::uint8_t descriptor,std::uint8_t bank)override{check(bank==0);events.push_back(0x200+descriptor);return reject!=3;}
    bool light(m::Vector p)override{events.push_back(4);points.push_back(p);return reject!=4;}
    bool retire(const g::actors::EntityId&)override{events.push_back(5);if(reject==5)return false;actor->active=actor->visible=false;return true;}
}effects;
std::vector<unsigned> original_events;std::vector<m::Vector> original_points;
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
    case 0x5def90:check(GPR_U32(context,4)==work_at);original_events.push_back(1);break;
    case 0x1ba5e0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,5)<=255);original_events.push_back(0x100+GPR_U32(context,5));break;
    case 0x5da2c0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,6)==0);original_events.push_back(0x200+GPR_U32(context,5));break;
    case 0x6b25b0:check(GPR_U32(context,4)==work_at+0x38);original_events.push_back(4);original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));break;
    case 0x582de0:check(GPR_U32(context,4)==work_at);original_events.push_back(5);memory[work_at]=memory[work_at+1]=0;break;
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted forward helper "+std::to_string(context->pc));
    }context->pc=GPR_U32(context,31);
}
void vector_equal(const void* a,const void* b){check(std::memcmp(a,b,12)==0);}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();owned_constants(memory);g::Actor actor;actor.pose_work.emplace();effects.actor=&actor;
    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned n=0;n<65536;++n){
        actor.active=true;actor.visible=n&1;actor.primary=std::uint8_t(phase);actor.auxiliary_status=n*257;actor.contact.serial=std::uint8_t(n%5);actor.sampled_surface_valid=n&0x400;actor.contact.recipient={std::uint8_t(n&0x800?0:255),255};actor.contact.related_recipient={255,std::uint8_t(n&0x1000?7:255)};
        actor.position={float(int(n%13)-6)*.125f,float(int(n%17)-8)*.5f,float(int(n%19)-9)*.25f};actor.previous_position={77,88,99};auto& state=*actor.pose_work;state.variant=std::uint8_t(n);state.timer=std::bit_cast<std::int16_t>(std::uint16_t(n));state.travel_speed=float(int(n%127)-63)*.5f;
        for(unsigned c=0;c<4;++c)for(unsigned r=0;r<4;++r)state.basis[c][r]=float(int((n*(c+1)+r*7)%29)-14)*.25f;
        effects.events.clear();effects.points.clear();original_events.clear();original_points.clear();
        memory[work_at]=actor.active;memory[work_at+1]=actor.visible;memory[work_at+8]=actor.primary;memory[work_at+5]=state.variant;memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);memory[work_at+0x116]=actor.contact.serial;memory[work_at+0x188]=actor.sampled_surface_valid;memory[work_at+0x117]=actor.contact.recipient.category;memory[work_at+0x118]=actor.contact.recipient.token;memory[work_at+0x119]=actor.contact.related_recipient.category;memory[work_at+0x11a]=actor.contact.related_recipient.token;put(memory,work_at+12,state.timer);put(memory,work_at+0x38,actor.position);put(memory,work_at+0x44,actor.previous_position);put(memory,work_at+0x50,state.basis);put(memory,work_at+0xf0,state.travel_speed);
        R5900Context context;PS2Runtime runtime;context.pc=0x584250;SET_GPR_U32(&context,4,work_at);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);original_transform_port(memory,&context,&runtime);check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
        check(g::advance_forward_pose_projectile(actor,{},effects));
        check(actor.active==bool(memory[work_at])&&actor.visible==bool(memory[work_at+1])&&actor.primary==memory[work_at+8]&&state.variant==memory[work_at+5]&&std::uint8_t(actor.auxiliary_status)==memory[work_at+0x115]);
        check(state.timer==get<std::int16_t>(memory,work_at+12)&&state.travel_speed==get<float>(memory,work_at+0xf0));
        vector_equal(&actor.position,memory+work_at+0x38);vector_equal(&actor.previous_position,memory+work_at+0x44);check(std::memcmp(&state.basis,memory+work_at+0x50,64)==0);
        check(effects.events==original_events&&effects.points.size()==original_points.size());for(unsigned i=0;i<effects.points.size();++i)vector_equal(&effects.points[i],&original_points[i]);for(const auto event:effects.events){visuals+=event==1;sounds+=event>=0x100&&event<0x200;packets+=event>=0x200;lights+=event==4;retirements+=event==5;}++cases;
    }
    check(sounds&&packets&&lights&&visuals&&retirements);
    for(unsigned reject=1;reject<=5;++reject){actor.active=actor.visible=true;actor.primary=reject==1?0:reject==5?3:1;actor.contact.serial=1;actor.contact.recipient=actor.contact.related_recipient={255,255};actor.sampled_surface_valid=false;actor.pose_work->variant=20;actor.pose_work->timer=60;effects.reject=reject;check(!g::advance_forward_pose_projectile(actor,{},effects));}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"visuals\":"<<visuals<<",\"sounds\":"<<sounds<<",\"packets\":"<<packets<<",\"lights\":"<<lights<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
