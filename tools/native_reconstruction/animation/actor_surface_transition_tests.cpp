#include "game/native/gameplay_world/actor_surface_transition.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
namespace g=reo::native::gameplay_world;
std::uint64_t checks{},cases{},floor_queries{},changed{},calls{};unsigned next_surface{},current_case{};g::Position queried{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Surface transition "+std::to_string(current_case)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;if(context->pc==0x616f20){queried=transform_read<g::Position>(memory,GPR_U32(context,4));transform_write(memory,GPR_U32(context,5),std::uint8_t(next_surface));check(GPR_U32(context,6)==255);++floor_queries;context->f[0]=170;context->pc=GPR_U32(context,31);return;}switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared surface transition source call");}}
void invoke(std::uint8_t* memory){R5900Context c;PS2Runtime runtime;c.pc=0x6660b0;SET_GPR_U32(&c,4,0x200000);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);}
template<class T>void put(std::uint8_t* memory,unsigned offset,T value){transform_write(memory,0x200000+offset,value);}
void project(std::uint8_t* memory,const g::Actor& actor,std::uint8_t flags){put(memory,0x38,actor.position);put(memory,0x44,actor.previous_position);put(memory,0x90,actor.orientation);put(memory,0xa0,actor.previous_orientation);put(memory,8,actor.primary);put(memory,9,actor.secondary);put(memory,10,actor.phase);put(memory,11,actor.subphase);put(memory,0x174,actor.surface_kind);put(memory,0x54a,actor.contact_flags);put(memory,0xba0,actor.status);put(memory,0xd94,actor.saved_action_position);put(memory,0xda0,actor.saved_action_yaw);put(memory,0xce2,flags);}
void compare(std::uint8_t* memory,const g::Actor& actor,std::uint8_t flags){check(memory[0x200008]==actor.primary&&memory[0x200009]==actor.secondary&&memory[0x20000a]==actor.phase&&memory[0x20000b]==actor.subphase);check(std::memcmp(memory+0x200038,&actor.position,12)==0&&std::memcmp(memory+0x200090,actor.orientation.data(),8)==0);check(std::memcmp(memory+0x200d94,&actor.saved_action_position,12)==0&&transform_read<std::int16_t>(memory,0x200da0)==actor.saved_action_yaw);check(memory[0x200ce2]==flags&&memory[0x200174]==actor.surface_kind);}
int main()try{_mm_setcsr(0x1f80);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());
    for(unsigned old:{0u,1u,2u,3u,4u,255u})for(unsigned next:{0u,1u,2u,3u,4u,255u})for(unsigned action=0;action<256;++action)for(unsigned status:{0u,8u,0x80u,0x88u})for(unsigned contacts:{0u,2u})for(unsigned primary:{0u,1u,4u}){
        g::Actor actor;actor.position={float(action)*.25f,-float(action)*.5f,17};actor.previous_position={-12,4,101};actor.orientation={1,1234,3,4};actor.previous_orientation={5,6789,7,8};actor.primary=std::uint8_t(primary);actor.secondary=std::uint8_t(action);actor.phase=51;actor.subphase=71;actor.surface_kind=std::uint8_t(old);actor.contact_flags=std::uint16_t(contacts);actor.status=status;actor.saved_action_position={9,99,999};actor.saved_action_yaw=-999;std::optional<std::uint8_t> flags=std::uint8_t(action);project(memory.data(),actor,*flags);next_surface=next;const auto before=floor_queries;invoke(memory.data());const bool gate=primary==1&&!contacts;check(floor_queries-before==unsigned(gate));if(gate)check(queried.x==actor.position.x&&queried.y==actor.position.y+50&&queried.z==actor.position.z);
        const auto result=g::apply_surface_transition(actor,std::uint8_t(next),flags);check(result!=g::SurfaceTransitionStatus::unavailable);changed+=result==g::SurfaceTransitionStatus::applied;compare(memory.data(),actor,*flags);++cases;++current_case;
    }
    g::Actor actor;actor.primary=1;actor.secondary=74;actor.surface_kind=0;std::optional<std::uint8_t> absent;const auto before=actor;check(g::apply_surface_transition(actor,3,absent)==g::SurfaceTransitionStatus::unavailable&&actor.primary==before.primary&&actor.secondary==before.secondary&&!absent);reo::native::gameplay_collision::response::Grid empty;std::optional<std::uint8_t> flags=0;check(g::update_surface_transition(actor,empty,flags)==g::SurfaceTransitionStatus::unchanged);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_cases\":"<<cases<<",\"floor_queries\":"<<floor_queries<<",\"changed\":"<<changed<<",\"source_calls\":"<<calls<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
