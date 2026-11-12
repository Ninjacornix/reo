#include "game/native/gameplay_world/pose_timed_projectile.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;
namespace m=reo::native::transform_math;
namespace c=reo::native::gameplay_collision;

unsigned checks{},cases{},calls{},retirements{},floor_queries{},packets{},trail_requests{};
constexpr unsigned work_at=0x20000,parent_at=0x22000;

void check(bool value,std::source_location p=std::source_location::current()){++checks;
if(!value)throw std::runtime_error("Timed pose projectile "+std::to_string(p.line())+" case "+std::to_string(cases));
}
template<class T>T get(const std::uint8_t* p,unsigned at){return transform_read<T>(p,at);
}template<class T>void put(std::uint8_t* p,unsigned at,T value){transform_write(p,at,value);
}
struct Effects final:g::TimedProjectileEffects {
    g::Actor* actor{};
std::uint8_t parent{},factor{};
unsigned reject{};
c::response::Floor water,ground;
std::vector<unsigned> events;
std::vector<m::Vector> points;

    std::optional<std::uint8_t> parent_variant(const g::actors::EntityId&)override{return reject==1?std::nullopt:std::optional(parent);
}
    std::optional<std::uint8_t> quantum()override{return reject==2?std::nullopt:std::optional(factor);
}
    std::optional<c::response::Floor> floor(m::Vector p,std::uint8_t type)override{check(type==0x81||type==255);
events.push_back(type==0x81?10:11);
points.push_back(p);
return reject==(type==0x81?6u:7u)?std::nullopt:std::optional(type==0x81?water:ground);
}
    bool packet(const g::actors::EntityId&,std::uint8_t descriptor,std::uint8_t bank)override{check(descriptor==0x50&&bank==1);
events.push_back(1);
return reject!=3;
}
    bool trail(const g::actors::EntityId&,const g::actors::EntityId&,std::uint8_t mode)override{check(mode<4);
events.push_back(unsigned(mode)+2);
return reject!=unsigned(mode)+4;
}
    bool retire(const g::actors::EntityId&)override{events.push_back(20);
if(reject==8)return false;
actor->active=actor->visible=false;
return true;
}
} effects;

std::vector<unsigned> original_events;
std::vector<m::Vector> original_points;

void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
switch(context->pc){
    case 0x5da2c0:check(GPR_U32(context,4)==work_at&&GPR_U32(context,5)==0x50&&GPR_U32(context,6)==1);
original_events.push_back(1);
break;

    case 0x578620:check(GPR_U32(context,4)==parent_at&&GPR_U32(context,5)==work_at&&GPR_U32(context,6)<4&&!GPR_U32(context,7)&&!GPR_U32(context,8));
original_events.push_back(GPR_U32(context,6)+2);
break;

    case 0x616f20:{const auto type=GPR_U32(context,6);
check(type==0x81||type==255);
const auto floor=type==0x81?effects.water:effects.ground;
original_events.push_back(type==0x81?10:11);
original_points.push_back(get<m::Vector>(memory,GPR_U32(context,4)));
context->f[0]=floor.height;
memory[GPR_U32(context,5)]=floor.type;
break;
}
    case 0x582de0:check(GPR_U32(context,4)==work_at);
original_events.push_back(20);
memory[work_at]=memory[work_at+1]=0;
break;

#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted timed pose helper "+std::to_string(context->pc));

    }context->pc=GPR_U32(context,31);

}
void vector_equal(const void* a,const void* b){check(std::memcmp(a,b,12)==0);
}
int main()try{
    std::vector<std::uint8_t> ram(0x2000000);
auto* memory=ram.data();
owned_constants(memory);
g::Actor actor;
actor.pose_work.emplace();
effects.actor=&actor;

    for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned n=0;
n<65536;
++n){
        actor.active=true;
actor.visible=n&1;
actor.primary=std::uint8_t(phase);
actor.subphase=std::uint8_t(n>>8);
actor.auxiliary_status=n*257;
actor.contact.serial=n%5==0?1:0;
actor.orientation={std::int16_t(n*19),std::int16_t(n*257),std::int16_t(n*251),-17};
actor.position={float(int(n%13)-6)*.125f,float(int(n%17)-8)*.5f,float(int(n%19)-9)*.25f};
actor.sampled_surface_height=-999;
auto& state=*actor.pose_work;
state.variant=std::uint8_t(n);
state.timer=std::bit_cast<std::int16_t>(std::uint16_t(n));
state.lifetime=std::bit_cast<std::int16_t>(std::uint16_t(n*17));
state.velocity={.25f,float(int(n%7)-3)*.125f,-.5f};
state.acceleration={-.125f,float(int(n%11)-5)*.0625f,.25f};
actor.collision.local_center={1,2,3};
actor.collision.radius=4;
actor.collision.previous_local_center={5,6,7};
actor.collision.previous_radius=8;

        effects.parent=std::uint8_t(n>>8);
effects.factor=std::uint8_t(n*31+(n>>8));
effects.water.height=float(int(n%29)-14)*.25f;
effects.water.type=n&16?0x81:255;
effects.ground.height=float(int(n%37)-18)*.25f;
effects.ground.type=n&64?0x81:0;
effects.events.clear();
effects.points.clear();
original_events.clear();
original_points.clear();

        memory[work_at]=actor.active;
memory[work_at+1]=actor.visible;
memory[work_at+8]=actor.primary;
memory[work_at+11]=actor.subphase;
memory[work_at+5]=state.variant;
memory[work_at+0x115]=std::uint8_t(actor.auxiliary_status);
memory[work_at+0x116]=actor.contact.serial;
put(memory,work_at+12,state.timer);
put(memory,work_at+18,state.lifetime);
put(memory,work_at+0x28,parent_at);
put(memory,work_at+0x38,actor.position);
put(memory,work_at+0x90,actor.orientation);
put(memory,work_at+0xc0,state.velocity);
put(memory,work_at+0xcc,state.acceleration);
put(memory,work_at+0x170,actor.sampled_surface_height);
put(memory,work_at+0x1ac,actor.collision.local_center);
put(memory,work_at+0x1b8,actor.collision.radius);
put(memory,work_at+0x1bc,actor.collision.previous_local_center);
put(memory,work_at+0x1c8,actor.collision.previous_radius);
memory[parent_at+0xcf2]=effects.parent;
memory[0x74f200]=effects.factor;

        R5900Context context;
PS2Runtime runtime;
context.pc=0x583730;
SET_GPR_U32(&context,4,work_at);
SET_GPR_U32(&context,29,0x1f00000);
SET_GPR_U32(&context,31,0x1234);
original_transform_port(memory,&context,&runtime);
check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);

        check(g::advance_timed_pose_projectile(actor,{},effects));
check(actor.active==bool(memory[work_at])&&actor.visible==bool(memory[work_at+1])&&actor.primary==memory[work_at+8]&&actor.subphase==memory[work_at+11]&&state.variant==memory[work_at+5]&&std::uint8_t(actor.auxiliary_status)==memory[work_at+0x115]&&actor.contact.serial==memory[work_at+0x116]);
check(state.timer==get<std::int16_t>(memory,work_at+12)&&state.lifetime==get<std::int16_t>(memory,work_at+18)&&actor.sampled_surface_height==get<float>(memory,work_at+0x170));
vector_equal(&actor.position,memory+work_at+0x38);
vector_equal(&state.velocity,memory+work_at+0xc0);
vector_equal(&state.acceleration,memory+work_at+0xcc);
vector_equal(&actor.collision.local_center,memory+work_at+0x1ac);
vector_equal(&actor.collision.previous_local_center,memory+work_at+0x1bc);
check(actor.collision.radius==get<float>(memory,work_at+0x1b8)&&actor.collision.previous_radius==get<float>(memory,work_at+0x1c8)&&std::memcmp(actor.orientation.data(),memory+work_at+0x90,8)==0);
check(effects.events==original_events&&effects.points.size()==original_points.size());
for(unsigned i=0;
i<effects.points.size();
++i)vector_equal(&effects.points[i],&original_points[i]);
for(const auto event:effects.events){packets+=event==1;
trail_requests+=event>=2&&event<=5;
floor_queries+=event==10||event==11;
retirements+=event==20;
}++cases;

    }
    for(unsigned reject=1;
reject<=8;
++reject){actor.primary=reject<=5?0:reject<8?1:2;
actor.contact.serial=0;
actor.position={};
actor.pose_work->variant=reject<=2?255:0;
actor.pose_work->timer=0;
actor.pose_work->velocity={0,-1,0};
actor.pose_work->acceleration={};
effects.water.type=255;
effects.water.height=effects.ground.height=1000;
effects.reject=reject;
check(!g::advance_timed_pose_projectile(actor,{},effects));
}
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"retirements\":"<<retirements<<",\"floor_queries\":"<<floor_queries<<",\"packets\":"<<packets<<",\"trails\":"<<trail_requests<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";

}catch(const std::exception& error){std::cerr<<error.what()<<'\n';
return 1;
}
