#include "game/native/gameplay_events/statistics.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <limits>
#include <source_location>
namespace e=reo::native::gameplay_events;
std::uint64_t checks{},cases{},calls{},admitted{};unsigned current_case{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Actor counters "+std::to_string(current_case)+" line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
case 0x65ec40:case 0x581870:case 0x6660b0:case 0x661310:case 0x6613a0:case 0x61a820:context->pc=GPR_U32(context,31);return;
default:throw std::runtime_error("Undeclared actor counter source call "+std::to_string(context->pc));}}
void invoke(std::uint8_t* memory){R5900Context c;PS2Runtime runtime;c.pc=0x66a3a0;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);}
constexpr unsigned actor=0x4a5c30;
void project(std::uint8_t* memory,const e::ActorCounters& c){transform_write(memory,0x3b84b0,c.forward_distance);transform_write(memory,0x3b84bc,c.resource_uses);transform_write(memory,0x3b84c8,c.health_high);transform_write(memory,0x3b84cc,c.health_middle);transform_write(memory,0x3b84d0,c.health_low);transform_write(memory,0x3b84d4,c.status_one);transform_write(memory,0x3b84d8,c.status_two);transform_write(memory,0x3b84f5,c.used_resource);}
void compare(const std::uint8_t* memory,const e::ActorCounters& c){check(transform_read<unsigned>(memory,0x3b84b0)==c.forward_distance);check(transform_read<unsigned>(memory,0x3b84bc)==c.resource_uses);check(transform_read<unsigned>(memory,0x3b84c8)==c.health_high);check(transform_read<unsigned>(memory,0x3b84cc)==c.health_middle);check(transform_read<unsigned>(memory,0x3b84d0)==c.health_low);check(transform_read<unsigned>(memory,0x3b84d4)==c.status_one);check(transform_read<unsigned>(memory,0x3b84d8)==c.status_two);check(memory[0x3b84f5]==c.used_resource);}
int main()try{_mm_setcsr(0x1f80);std::vector<std::uint8_t> memory(0x2000000);std::uint32_t random=0x34169acb;const auto next=[&](){random=random*1664525+1013904223;return random;};
    for(unsigned i=0;i<65536;++i){current_case=i;e::ActorCounters c{next(),next(),next(),next(),next(),next(),next(),std::uint8_t(next())};project(memory.data(),c);const unsigned mode=i%4,category=(i/7)%3,slot=(i/3)%8,selected=(i/13)%8;const std::int16_t health=std::bit_cast<std::int16_t>(std::uint16_t(i)),maximum=std::bit_cast<std::int16_t>(std::uint16_t(next()));const unsigned status=i%16;const float distance=float(std::int32_t(next()%8193)-4096)*.125f;
        memory[actor]=1;memory[actor+2]=std::uint8_t(category);memory[actor+3]=std::uint8_t(slot);memory[actor+8]=0;transform_write(memory.data(),actor+0x1e2,std::uint16_t(1));transform_write(memory.data(),0x3243dc,std::uint16_t(1));memory[0x3243f2]=std::uint8_t(mode);memory[0x4baded]=std::uint8_t(selected);transform_write(memory.data(),actor+0xba0,status);transform_write(memory.data(),actor+0x4ec,distance);transform_write(memory.data(),actor+0x544,health);transform_write(memory.data(),actor+0x546,maximum);invoke(memory.data());
        const bool local=category==0&&slot==(mode==0?0:selected);if(local&&!(status&4)){check(e::record_actor_counters(c,distance,health,maximum,status));++admitted;}compare(memory.data(),c);++cases;
    }
    e::ActorCounters c;for(float distance:{0.f,-0.f,.5f,1.5f,16777216.f,2147483648.f,std::numeric_limits<float>::max()}){memory[actor]=1;memory[actor+2]=0;memory[actor+3]=0;memory[actor+8]=0;memory[0x3243f2]=0;transform_write(memory.data(),actor+0xba0,0u);transform_write(memory.data(),actor+0x544,std::int16_t(0));transform_write(memory.data(),actor+0x546,std::int16_t(0));transform_write(memory.data(),actor+0x4ec,distance);project(memory.data(),c);invoke(memory.data());check(e::record_actor_counters(c,distance,0,0,0));compare(memory.data(),c);++cases;}
    e::Statistics stats(e::RuleBook::create({e::RuleGroup{}},{0}));check(!stats.actor_frame(1,1,1,0)&&!stats.resource_use(0x10));e::Events events;check(stats.initialize(0,events)==e::StatisticsStatus::completed);check(stats.actor_frame(1.5f,1,1,0)&&stats.state().actors.forward_distance==1);check(stats.resource_use(0x10)&&stats.state().actors.used_resource==1&&stats.state().actors.resource_uses==1);check(stats.initialize(0,events)==e::StatisticsStatus::completed&&stats.state().actors.forward_distance==0&&stats.state().actors.resource_uses==0&&stats.state().actors.used_resource==0);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_outer_counter_cases\":"<<cases<<",\"admitted_actor_tails\":"<<admitted<<",\"source_calls\":"<<calls<<"}\n";
}catch(const std::exception& x){std::cerr<<x.what()<<'\n';return 1;}
