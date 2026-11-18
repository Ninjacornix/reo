#include "game/native/gameplay_world/dialogue_partner_characters.hpp"
#include "reference.hpp"
#include "functions.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},cases{},stops{},calls{};
constexpr unsigned base=0x4a5c30;struct PartnerOverflow {};
void check(bool value){++checks;if(!value)throw std::runtime_error("Partner character source comparison "+std::to_string(cases));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
}
void observed_partner_write(std::uint8_t* ram,const R5900Context* context,std::uint32_t at,std::uint8_t value){if(context->pc==0x6b81f8&&at>=base+0xdb0)throw PartnerOverflow{};transform_write(ram,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Unexpected response branch during inactive partner-list profile");}}
int main()try{
    w::World world(profile(),std::make_shared<w::Session>());world.selected_actor=7;
    for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->slot=std::uint8_t(i);check(world.spawn_primary(i,std::move(actor)).status==w::actors::EntityStatus::completed);}
    for(unsigned seed=0;seed<4096;++seed){
        auto actor=world.primary(0);actor->category=std::uint8_t(seed%7==0?1:seed%11==0?255:0);actor->speech.partner_characters=std::array<std::int8_t,4>{5,-1,8,127};world.session().primary_population=seed%9;
        for(unsigned i=0;i<8;++i){auto candidate=world.primary(i);candidate->character=std::uint8_t(seed%4==0?seed%256:seed%4==1?i%3:i+seed);put(base+0x10e0*i+0xb98,candidate->character);}
        put(base,std::uint8_t(0));put(base+2,actor->category);put(base+3,std::uint8_t(0));put(0x4baded,std::uint8_t(7));put(0x4baea0,*world.session().primary_population);put(0x4bae77,std::uint8_t(0xa5));
        std::memcpy(memory.data()+base+0xdac,actor->speech.partner_characters->data(),4);put(base+0xdb0,0xa5a5a5a5u);
        const auto native=w::rebuild_dialogue_partner_characters(world,world.identity(0));R5900Context state;PS2Runtime runtime;state.pc=0x6b8130;SET_GPR_U32(&state,4,base);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);bool stopped{};
        try{original_transform_port(memory.data(),&state,&runtime);}catch(const PartnerOverflow&){stopped=true;++stops;}
        if(stopped)check(native.status==w::DialogueStatus::unsupported_profile&&native.written==4);else{check(native.status==w::DialogueStatus::completed&&state.pc==0xabcdef&&GPR_U32(&state,29)==0x1f00000);++cases;}
        check(std::memcmp(actor->speech.partner_characters->data(),memory.data()+base+0xdac,4)==0&&transform_read<unsigned>(memory.data(),base+0xdb0)==0xa5a5a5a5u);
    }
    auto actor=world.primary(0);actor->category=0;actor->speech.partner_characters.reset();world.session().primary_population.reset();check(w::rebuild_dialogue_partner_characters(world,world.identity(0)).status==w::DialogueStatus::unavailable&&actor->speech.partner_characters==std::array<std::int8_t,4>{-1,-1,-1,-1});
    check(w::rebuild_dialogue_partner_characters(world,{}).status==w::DialogueStatus::unavailable);check(world.close()==w::Status::completed&&w::rebuild_dialogue_partner_characters(world,{}).status==w::DialogueStatus::closed);
    std::cout<<"{\"checks\":"<<checks<<",\"complete_original_inactive_profiles\":"<<cases<<",\"overflow_prefix_profiles\":"<<stops<<",\"source_calls\":"<<calls<<",\"native_capability_checks\":3,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
