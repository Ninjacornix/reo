#include "game/native/gameplay_world/dialogue_response_uses.hpp"
#include "reference.hpp"
#include "functions.h"
#include <bit>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},calls{},lookups{},choices{},increments{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue response uses source comparison "+std::to_string(checks));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
R5900Context call(unsigned at,std::int32_t input){R5900Context c;PS2Runtime r;c.pc=at;SET_GPR_S32(&c,4,input);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory.data(),&c,&r);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);return c;}
void compare(const w::DialogueResponseUses& uses){static_assert(sizeof(w::DialogueResponseUse)==4);check(std::memcmp(uses.data(),memory.data()+0x74cd10,sizeof uses)==0);}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared response use helper");}}
int main()try{
    constexpr std::array<std::uint32_t,13> edges{0,1,2,999,1000,9999,32767,32768,65535,65536,0xffffffffu,0x7fffffffu,0x80000000u};
    w::DialogueResponseUses uses;
    for(unsigned seed=0;seed<16384;++seed){
        for(unsigned i=0;i<uses.size();++i){uses[i].selection=std::int16_t(seed%7==0?i:seed%7==1?999-i:seed%7==2?i%32:seed%7==3?32767:i%3==0?-1:int(i));uses[i].count=std::bit_cast<std::int16_t>(std::uint16_t(seed*113+i*379));}
        const auto input=std::bit_cast<std::int32_t>(edges[seed%edges.size()]);
        std::memcpy(memory.data()+0x74cd10,uses.data(),sizeof uses);
        const auto found=w::find_dialogue_response_use(uses,input);const auto c=call(0x6b9250,input);
        check(GPR_U32(&c,2)==(found?0x74cd10+4*unsigned(*found):0));compare(uses);++lookups;
        auto selected=std::bit_cast<std::int32_t>(edges[(seed/13)%edges.size()]);put(0x74e7a4,selected);
        w::choose_dialogue_response_use(uses,selected,input);call(0x6b91a0,input);check(selected==get<std::int32_t>(0x74e7a4));compare(uses);++choices;
        put(0x74e790,input);w::increment_dialogue_response_use(uses,input);call(0x6b92e0,0);compare(uses);++increments;
    }
    for(unsigned value=0;value<65536;++value){
        uses[0]={17,std::bit_cast<std::int16_t>(std::uint16_t(value))};std::memcpy(memory.data()+0x74cd10,uses.data(),sizeof uses);put(0x74e790,std::int32_t(17));
        w::increment_dialogue_response_use(uses,17);call(0x6b92e0,0);compare(uses);++increments;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_lookups\":"<<lookups<<",\"complete_choices\":"<<choices<<",\"complete_increments\":"<<increments<<",\"source_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
