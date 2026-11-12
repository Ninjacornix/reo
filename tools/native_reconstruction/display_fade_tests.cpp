#include "game/native/gameplay_scenario/display_fade.hpp"
#include "reference.hpp"
#include "functions.h"
#include <iostream>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},steps{},initializations{};unsigned current_case{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Display fade comparison case"+std::to_string(current_case));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x107c68:{const auto at=GPR_U32(context,4),size=GPR_U32(context,6);check(at==0x316650&&size==32&&GPR_U32(context,5)==0);std::fill_n(memory+at,size,0);context->pc=GPR_U32(context,31);return;}
    default:throw std::runtime_error("Unadmitted display fade helper");}
}
std::uint32_t random_word(std::uint32_t& state){state^=state<<13;state^=state>>17;state^=state<<5;return state;}
void project(std::uint8_t* memory,unsigned at,const s::DisplayFadeState& state){
    transform_write(memory,at,state.phase);transform_write(memory,at+4,state.status);transform_write(memory,at+8,state.color);
    transform_write(memory,at+12,state.alpha);transform_write(memory,at+16,state.step);transform_write(memory,at+20,state.rectangle);
}
int main(){
    std::vector<std::uint8_t> memory(0x2000000);PS2Runtime runtime;std::uint32_t random=0x1bb480;
    const auto invoke=[&](unsigned address,std::uint32_t a0=0,std::uint32_t a1=0){R5900Context context;context.pc=address;SET_GPR_U32(&context,29,0x700000);SET_GPR_U32(&context,31,0xabcdef);SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,5,a1);original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x700000);return GPR_U32(&context,2);};
    const auto compare=[&](const s::DisplayFadeState& value){project(memory.data(),0x18000,value);for(unsigned byte=0;byte<32;++byte)check(memory[0x18000+byte]==memory[0x316650+byte]);check(s::display_fade_finished(value)==bool(invoke(0x1bb8d0)));};
    for(unsigned index=0;index<131072;++index){
        current_case=index;s::DisplayFadeState value;value.phase=std::uint8_t(index);value.status=random_word(random);value.color=random_word(random);
        value.alpha=float(std::int32_t(random_word(random)%8193)-4096)/2048.f;value.step=float(std::int32_t(random_word(random)%4097)-2048)/2048.f;
        value.rectangle={std::int16_t(random_word(random)),std::int16_t(random_word(random)),std::int16_t(random_word(random)),std::int16_t(random_word(random)),random_word(random)};
        if(index%3==0)value.phase=std::array<std::uint8_t,5>{0,1,2,99,255}[(index/3)%5];
        if(index%7==0)value.status=0;
        for(unsigned byte=0;byte<32;++byte)memory[0x18000+byte]=memory[0x316650+byte]=std::uint8_t(random_word(random));
        project(memory.data(),0x316650,value);const auto duration=std::bit_cast<std::int16_t>(std::uint16_t(index));const auto mode=std::uint8_t(index>>3);const bool rising=index&1;
        if(index%5){transform_write(memory.data(),0x3243cc,mode);invoke(rising?0x1bb5c0:0x1bb650,0xabc00000u|std::uint16_t(duration),value.color);s::start_display_fade(value,rising,duration,mode,value.color);compare(value);}
        auto initialized=std::uint8_t(index%17==0?0:index%3==0?255:1);transform_write(memory.data(),0x10008,initialized);
        for(unsigned tick=0;tick<4;++tick){
            if(!initialized){std::fill_n(memory.data()+0x18000,32,0);++initializations;}
            invoke(0x1bb480,0x10000);s::advance_display_fade(value,initialized);check(initialized==memory[0x10008]);compare(value);++steps;
        }
        ++cases;
    }
    std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"steps\":"<<steps<<",\"initializations\":"<<initializations<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}
