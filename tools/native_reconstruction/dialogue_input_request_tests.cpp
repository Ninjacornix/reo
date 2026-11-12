#include "game/native/gameplay_world/dialogue_input_request.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <bit>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace input=reo::native::gameplay_actors::input;
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},cases{},loop_cases{},calls{},stops{};bool undefined_direction{};struct RegisterHistory {};
constexpr unsigned actor=0x4a5c30;
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue input request comparison "+std::to_string(cases)+" check "+std::to_string(checks));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
}
std::uint8_t observed_request_byte(const std::uint8_t* ram,const R5900Context* c,std::uint32_t at){if(undefined_direction&&(c->pc==0x6b7de0||c->pc==0x6b7df4))throw RegisterHistory{};return ram[at];}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared input request helper");}}
int main()try{
    owned_constants(memory.data());constexpr std::array<std::uint32_t,8> pressed{0,0x2000,0x100000,0xf00000,0xffffffffu,0x80,0x200000,0x800000};
    for(unsigned seed=0;seed<65536;++seed){
        input::Frame frame;frame.pressed=pressed[seed%pressed.size()];frame.held=seed&8?0x80:0;frame.analog[5]=std::bit_cast<std::int16_t>(std::uint16_t(seed));
        w::SpeechState speech;speech.request=std::bit_cast<std::int8_t>(std::uint8_t(seed/32));speech.variant=std::bit_cast<std::int8_t>(std::uint8_t(seed/256));const bool suppressed=seed%7==0;
        put(0x4bae33,std::uint8_t(1));put(0x755ec4,std::uint8_t(suppressed?1:0));put(0x4badee,std::uint8_t(0));put(0x3243f2,std::uint8_t(seed/256));put(0x324210,frame.pressed);put(0x324218,frame.held);put(0x32423a,frame.analog[5]);put(actor+0xda8,*speech.request);put(actor+0xda9,*speech.variant);
        undefined_direction=!suppressed&&*speech.request&&!(frame.pressed&(0x2000u|0xf00000u));const auto native=w::prepare_dialogue_input_request(speech,&frame,suppressed);
        R5900Context state;PS2Runtime runtime;state.pc=0x6b7d40;SET_GPR_U32(&state,4,actor);SET_GPR_U32(&state,16,0x12345678);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);bool stopped{};
        try{original_transform_port(memory.data(),&state,&runtime);}catch(const RegisterHistory&){stopped=true;++stops;}
        if(stopped)check(native.status==w::DialogueStatus::unsupported_profile);
        else{check(native.status==w::DialogueStatus::completed&&native.requested==bool(GPR_U32(&state,2))&&state.pc==0xabcdef&&GPR_U32(&state,16)==0x12345678&&GPR_U32(&state,29)==0x1f00000);++cases;}
        check(speech.request==get<std::int8_t>(actor+0xda8)&&speech.variant==get<std::int8_t>(actor+0xda9));
    }
    for(unsigned physical=0;physical<8;++physical)for(unsigned seed=0;seed<65536;++seed){
        input::Frame frame;frame.held=seed&1?0x80:0;
        w::SpeechState speech;speech.request=std::bit_cast<std::int8_t>(std::uint8_t(seed/256));speech.variant=std::bit_cast<std::int8_t>(std::uint8_t(seed));const bool suppressed=seed%7==0;
        put(0x4bae33,std::uint8_t(1));put(0x755ec4,std::uint8_t(suppressed?1:0));put(0x4badee,std::uint8_t(0));put(0x3243f2,std::uint8_t(0));put(0x324210,frame.pressed);put(0x324218,frame.held);put(0x32423a,frame.analog[5]);put(actor+0xda8,*speech.request);put(actor+0xda9,*speech.variant);
        undefined_direction=false;const auto native=w::prepare_loop_dialogue_input_request(speech,&frame,suppressed,physical);
        R5900Context state;PS2Runtime runtime;state.pc=0x6b7d40;SET_GPR_U32(&state,4,actor);SET_GPR_U32(&state,16,physical);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);
        check(native.status==w::DialogueStatus::completed&&!native.requested&&GPR_U32(&state,2)==0&&state.pc==0xabcdef&&GPR_U32(&state,16)==physical&&GPR_U32(&state,29)==0x1f00000);
        check(speech.request==get<std::int8_t>(actor+0xda8)&&speech.variant==get<std::int8_t>(actor+0xda9));++loop_cases;
    }
    w::SpeechState invalid_index;invalid_index.request=1;invalid_index.variant=5;input::Frame no_direction;
    check(w::prepare_loop_dialogue_input_request(invalid_index,&no_direction,false,8).status==w::DialogueStatus::unsupported_profile&&invalid_index.request==1&&invalid_index.variant==5);
    no_direction.pressed=0x2000;check(w::prepare_loop_dialogue_input_request(invalid_index,&no_direction,false,999).status==w::DialogueStatus::completed&&invalid_index.variant==7);
    w::SpeechState unknown;check(w::prepare_dialogue_input_request(unknown,nullptr,true).status==w::DialogueStatus::completed);check(w::prepare_dialogue_input_request(unknown,nullptr,{}).status==w::DialogueStatus::unavailable);check(w::prepare_dialogue_input_request(unknown,nullptr,false).status==w::DialogueStatus::unavailable);input::Frame empty;check(w::prepare_dialogue_input_request(unknown,&empty,false).status==w::DialogueStatus::unavailable);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_cases\":"<<cases<<",\"mode_zero_loop_input_cases\":"<<loop_cases<<",\"undefined_direction_entry_interruptions\":"<<stops<<",\"source_calls\":"<<calls<<",\"native_capability_checks\":4,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
