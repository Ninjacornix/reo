#include "game/native/gameplay_world/cached_dialogue_presentation.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;
std::uint64_t checks{},cases{};std::vector<std::uint8_t> memory(0x2000000);
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue visibility");}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected visibility helper");}}
int main()try{
    check(!w::dialogue_suppressed({},0));check(w::dialogue_suppressed({std::uint8_t(0),{}},0)==false);check(!w::dialogue_suppressed({std::uint8_t(1),{}},0));
    for(const auto enabled:std::array<std::uint8_t,4>{0,1,128,255})for(unsigned mode=0;mode<256;++mode)for(unsigned inventory=0;inventory<256;++inventory){memory[0x4bae33]=enabled;memory[0x755ec4]=std::uint8_t(mode);memory[0x4badee]=std::uint8_t(inventory);R5900Context state;PS2Runtime runtime;state.pc=0x6dee20;SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);const auto native=w::dialogue_suppressed({enabled,std::uint8_t(mode)},std::uint8_t(inventory));check(native.has_value()&&state.pc==0xabcdef&&unsigned(*native)==GPR_U32(&state,2));++cases;}
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_cases\":"<<cases<<",\"unavailable_input_checks\":3,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
