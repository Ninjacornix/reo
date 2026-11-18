#include "game/native/gameplay_scenario/dialogue_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "dialogue_asset_profile.hpp"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},banks{},cue_cases{},text_cases{},source_calls{},lifetimes{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Dialogue assets "+std::to_string(at.line()));}
std::vector<std::uint8_t> memory(0x2000000);
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
R5900Context call(unsigned at,unsigned a0,unsigned a1=0,unsigned a2=0){R5900Context state;PS2Runtime runtime;state.pc=at;SET_GPR_U32(&state,4,a0);SET_GPR_U32(&state,5,a1);SET_GPR_U32(&state,6,a2);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef&&GPR_U32(&state,29)==0x1f00000);return state;}
template<class F>void refused(F operation){bool failed{};try{operation();}catch(const std::invalid_argument&){failed=true;}check(failed);++refusals;}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++source_calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared dialogue asset helper");}}
int main(int argc,char** argv)try{
    check(argc==2);std::optional<s::DialogueBank> retained;
    {
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);s::content::ScenarioArchive archive(source);
    for(const auto& row:dialogue_asset_profile){
        auto bank=s::prepare_dialogue_bank(archive,row.scenario,row.section,row.character);check(bank.cues&&bank.texts&&bank.cue_identity==row.cue&&bank.text_identity==row.text);++banks;
        const auto cue_bytes=bank.cues->backing();constexpr unsigned cue_base=0x600000;std::memcpy(memory.data()+cue_base,cue_bytes->data(),cue_bytes->size());put(0x324438,cue_base-0x50000);call(0x6b7350,cue_base,0,4);check(get<unsigned>(0x74f0dc)==cue_base+24);
        for(unsigned index=0;index<s::DialogueCues::selections;++index){const auto native=bank.cues->cue(index);const auto original_state=call(0x6b7520,8,index,1);const auto original=GPR_U32(&original_state,2);check(bool(native)==bool(original));if(native)check(native->text==get<std::uint16_t>(original+2)&&native->delay==get<std::int16_t>(original+4)&&native->voice==get<std::int16_t>(original+6));++cue_cases;}
        const auto text_bytes=bank.texts->backing();constexpr unsigned text_base=0x800000;std::memcpy(memory.data()+text_base,text_bytes->data(),text_bytes->size());
        for(unsigned index=0;index<bank.texts->size();++index){const auto native=bank.texts->text(index);check(bool(native));const auto reference=get<unsigned>(text_base+4+8*index),start=text_base+get<unsigned>(text_base+reference)+8;const auto end=std::find(memory.begin()+start,memory.end(),std::uint8_t{});check(native->body.size()==std::size_t(end-(memory.begin()+start))&&std::memcmp(native->body.data(),memory.data()+start,native->body.size())==0);
            const auto effects=text_base+get<unsigned>(text_base)+16*index;for(unsigned i=0;i<8;++i)check(native->effects[i]==get<std::uint16_t>(effects+2*i));
            const auto line=call(0x6b9750,start,0);check(GPR_U32(&line,2)==start);const auto length=call(0x6b9790,start);std::size_t first_line{};while(first_line<native->body.size()&&native->body[first_line]!=std::byte{10}&&native->body[first_line]!=std::byte{13})++first_line;check(GPR_U32(&length,2)==first_line);++text_cases;}
        check(!bank.cues->cue(6000)&&!bank.texts->text(bank.texts->size()));
        if(!retained)retained=bank;
    }
    const auto missing=s::prepare_dialogue_bank(archive,1,99,0);check(!missing.cues&&!missing.texts);
    }
    check(retained&&retained->cues->cue(0)&&retained->texts->text(0)&&!retained->texts->text(0)->body.empty());++lifetimes;
    const auto mutate=[](s::content::Bytes data,unsigned at,unsigned value){auto copy=std::make_shared<std::vector<std::byte>>(*data);for(unsigned i=0;i<4;++i)(*copy)[at+i]=std::byte((value>>(8*i))&255);return copy;};
    refused([&]{s::DialogueCues invalid(mutate(retained->cues->backing(),0,0));});
    refused([&]{s::DialogueCues invalid(mutate(retained->cues->backing(),16,28));});
    refused([&]{s::DialogueCues invalid(mutate(retained->cues->backing(),24,25));});
    refused([&]{s::DialogueTexts invalid(mutate(retained->texts->backing(),4,13));});
    refused([&]{s::DialogueTexts invalid(mutate(retained->texts->backing(),8,2));});
    refused([&]{s::DialogueTexts invalid(mutate(retained->texts->backing(),0,0xffffffffu));});
    std::cout<<"{\"checks\":"<<checks<<",\"owned_pairs\":"<<banks<<",\"original_cue_getters\":"<<cue_cases<<",\"owned_text_rows\":"<<text_cases<<",\"source_calls\":"<<source_calls<<",\"retained_asset_lifetimes\":"<<lifetimes<<",\"malformed_refusals\":"<<refusals<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
