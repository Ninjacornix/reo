#include "game/native/gameplay_scenario/dialogue_response_program.hpp"
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
std::uint64_t checks{},banks{},cases{},rows{},source_calls{},lifetimes{},refusals{};
std::array<std::uint64_t,256> condition_kinds{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Dialogue response program "+std::to_string(at.line()));}
std::vector<std::uint8_t> memory(0x2000000);
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
R5900Context call(unsigned at,unsigned a0,unsigned a1=0,unsigned a2=0){R5900Context state;PS2Runtime runtime;state.pc=at;SET_GPR_U32(&state,4,a0);SET_GPR_U32(&state,5,a1);SET_GPR_U32(&state,6,a2);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef&&GPR_U32(&state,29)==0x1f00000);return state;}
template<class F>void refused(F operation){bool failed{};try{operation();}catch(const std::invalid_argument&){failed=true;}check(failed);++refusals;}
auto mutate(s::content::Bytes data,unsigned at,unsigned value){auto copy=std::make_shared<std::vector<std::byte>>(*data);for(unsigned i=0;i<4;++i)(*copy)[at+i]=std::byte((value>>(8*i))&255);return copy;}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++source_calls;switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared dialogue response program helper");}}
int main(int argc,char** argv)try{
    check(argc==2);std::shared_ptr<s::DialogueResponseProgram> retained;unsigned retained_index{};
    {
    auto source=std::make_shared<const reo::assets::Source>(argv[1]);s::content::ScenarioArchive archive(source);
    for(const auto& row:dialogue_asset_profile){
        auto bank=s::prepare_dialogue_bank(archive,row.scenario,row.section,row.character);check(bank.cues&&bank.texts);s::DialogueResponseProgram program(bank.cues);++banks;
        const auto bytes=bank.cues->backing();constexpr unsigned base=0x600000;std::memcpy(memory.data()+base,bytes->data(),bytes->size());put(0x324438,base-0x50000);call(0x6b7350,base,0,4);const auto begin=base+get<unsigned>(base+20)+24000;
        for(unsigned index=0;index<s::DialogueCues::selections;++index){const auto native=program.response(index);const auto state=call(0x6b7520,8,index,0);const auto original=GPR_U32(&state,2);check(bool(native)==bool(original));++cases;if(!native)continue;++rows;
            check(native->physical_row==(original-begin)/48);check(native->definition.cue==get<std::int16_t>(original)&&native->definition.group==get<std::int8_t>(original+2)&&native->definition.mode==get<std::int8_t>(original+3));
            for(unsigned c=0;c<4;++c){const auto& condition=native->definition.conditions[c];const auto at=original+4+8*c;check(condition.kind==get<std::uint8_t>(at)&&condition.comparison==get<std::uint8_t>(at+1)&&condition.parameter==get<std::uint16_t>(at+2)&&condition.value==get<std::int32_t>(at+4));check(native->initial.condition_results[c]==get<std::int8_t>(original+40+c));++condition_kinds[condition.kind];}
            for(unsigned c=0;c<3;++c){check(native->definition.combiners[c]==get<std::int8_t>(original+36+c));}
            check(native->initial.replied_to==get<std::uint32_t>(original+44));
        }
        check(!program.response(6000));if(!retained){retained=std::make_shared<s::DialogueResponseProgram>(bank.cues);while(retained_index<6000&&!retained->response(retained_index))++retained_index;}
    }
    }
    check(retained&&retained->response(retained_index)&&retained->cues());++lifetimes;
    const auto bytes=retained->cues()->backing();const auto table=[&]{std::uint32_t value{};std::memcpy(&value,bytes->data()+20,4);return value;}();
    refused([&]{s::DialogueResponseProgram invalid({});});
    refused([&]{s::DialogueResponseProgram invalid(std::make_shared<const s::DialogueCues>(mutate(bytes,table,table)));});
    refused([&]{s::DialogueResponseProgram invalid(std::make_shared<const s::DialogueCues>(mutate(bytes,table,table+24001)));});
    refused([&]{s::DialogueResponseProgram invalid(std::make_shared<const s::DialogueCues>(mutate(bytes,table,0xfffffff0u)));});
    auto short_bytes=std::make_shared<std::vector<std::byte>>(*bytes);short_bytes->pop_back();refused([&]{s::DialogueResponseProgram invalid(std::make_shared<const s::DialogueCues>(short_bytes));});
    const auto first=[&]{std::uint32_t value{};std::memcpy(&value,bytes->data()+table+4*retained_index,4);return value;}();auto aliased=mutate(bytes,table+4*5999,first);s::DialogueResponseProgram alias(std::make_shared<const s::DialogueCues>(aliased));check(alias.response(retained_index)->physical_row==alias.response(5999)->physical_row&&alias.response(retained_index)->definition==alias.response(5999)->definition);
    std::cout<<"{\"checks\":"<<checks<<",\"owned_banks\":"<<banks<<",\"complete_original_getters\":"<<cases<<",\"authored_response_rows\":"<<rows<<",\"source_calls\":"<<source_calls<<",\"retained_program_lifetimes\":"<<lifetimes<<",\"malformed_refusals\":"<<refusals<<",\"alias_profiles\":1,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
