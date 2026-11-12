#include "game/native/gameplay_world/dialogue_flag_durations.hpp"
#include "reference.hpp"
#include "functions.h"
#include <array>
#include <bit>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},calls{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue flag duration source comparison");}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared flag duration helper");}}
int main()try{
    std::array<std::uint32_t,16> flags;std::array<std::int32_t,512> ticks;
    constexpr std::array<std::uint32_t,9> edges{0,1,29,30,59,60,0x7fffffffu,0x80000000u,0xffffffffu};
    for(unsigned seed=0;seed<4096;++seed){
        for(unsigned i=0;i<flags.size();++i){flags[i]=seed%9==0?0:seed%9==1?0xffffffffu:seed%9==2?1u<<(seed%32):(seed*747796405u+i*2891336453u);put(0x74e828+4*i,flags[i]);}
        for(unsigned i=0;i<ticks.size();++i){ticks[i]=std::bit_cast<std::int32_t>(edges[(i+seed)%edges.size()]);put(0x74e868+4*i,ticks[i]);}
        const auto retained=flags;reo::native::gameplay_world::advance_dialogue_flag_durations(flags,ticks);
        R5900Context state;PS2Runtime runtime;state.pc=0x6b80a0;SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef&&flags==retained);
        for(unsigned i=0;i<ticks.size();++i)check(ticks[i]==get<std::int32_t>(0x74e868+4*i));
    }
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_steps\":4096,\"source_calls\":"<<calls<<",\"counter_comparisons\":2097152,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
