#include "game/native/gameplay_scenario/scene_voice_assets.hpp"
#include "reference.hpp"
#include "functions.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <source_location>
#include <string_view>
#include <vector>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},calls{},cases{},matches{};
void check(bool ok,std::source_location where=std::source_location::current()){++checks;if(!ok)throw std::runtime_error("scene voice resolver line "+std::to_string(where.line()));}
std::string_view literal(const std::uint8_t* memory,unsigned at){check(at<0x2000000);unsigned length{};while(length<128&&at+length<0x2000000&&memory[at+length])++length;check(length<128&&at+length<0x2000000);return{reinterpret_cast<const char*>(memory+at),length};}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.hpp"
case 0x10ae78:{const auto a=literal(memory,GPR_U32(context,4)),b=literal(memory,GPR_U32(context,5));const auto compared=a.compare(b);SET_GPR_S32(context,2,compared<0?-1:compared>0?1:0);context->pc=GPR_U32(context,31);return;}
default:throw std::runtime_error("undeclared scene voice resolver dependency "+std::to_string(context->pc));
}}
void query(std::uint8_t* memory,std::uint16_t scenario,std::string_view key,const s::SceneVoiceAsset* typed=nullptr){check(key.size()<128);std::memcpy(memory+0x10000,key.data(),key.size());memory[0x10000+key.size()]=0;transform_write(memory,0x3243da,scenario);R5900Context context;PS2Runtime runtime;context.pc=0x6d7520;SET_GPR_U32(&context,4,0x10000);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);const auto native=s::scene_voice_asset(scenario,key);const auto original=GPR_U32(&context,2);if(bool(native)!=bool(original))std::cerr<<"scenario "<<scenario<<" key "<<key<<" native "<<bool(native)<<" original "<<std::hex<<original<<std::dec<<"\n";check(bool(native)==bool(original));if(native){if(native->basename!=literal(memory,original))std::cerr<<native->basename<<" != "<<literal(memory,original)<<"\n";check(native->basename==literal(memory,original));check(native->source.archive==0&&native->source.member>=0&&native->source.member<422);++matches;}if(typed)check(native==typed);++cases;}
int main(int argc,char** argv)try{check(argc==2);std::ifstream file(argv[1],std::ios::binary);check(bool(file));file.seekg(0,std::ios::end);const auto bytes=file.tellg();check(bytes>0&&bytes<0x2000000-0x570000);file.seekg(0);std::vector<std::uint8_t> memory(0x2000000);file.read(reinterpret_cast<char*>(memory.data()+0x570000),std::streamsize(bytes));check(file.gcount()==std::streamsize(bytes));const auto assets=s::scene_voice_assets();check(assets.size()==323);
 for(const auto& asset:assets){const auto* first=s::scene_voice_asset(asset.scenario,asset.key);query(memory.data(),asset.scenario,asset.key,first);check(first&&first->basename==asset.basename&&first->source.member==asset.source.member);check(s::scene_voice_asset(asset.scenario,asset.cue)==first);query(memory.data(),0,asset.key);query(memory.data(),65535,asset.key);}
 for(unsigned scenario=0;scenario<65536;++scenario){const auto& asset=assets[scenario%assets.size()];query(memory.data(),std::uint16_t(scenario),asset.key);}
 for(unsigned seed=0;seed<65536;++seed){const std::uint16_t scenario=std::array<std::uint16_t,7>{0,1,2,28,35,41,65535}[seed%7];const s::CutsceneCue cue{std::uint8_t(seed),std::uint8_t(seed>>8),std::uint8_t(seed*73)};char key[32];const auto size=std::snprintf(key,sizeof key,"%02u_%02u_%u",unsigned(cue.area),unsigned(cue.scene),unsigned(cue.variant));check(size>0&&unsigned(size)<sizeof key);query(memory.data(),scenario,{key,std::size_t(size)});check(s::scene_voice_asset(scenario,std::string_view(key))==s::scene_voice_asset(scenario,cue));}
 for(auto scenario:std::array<std::uint16_t,7>{0,1,2,28,35,41,65535})for(auto key:std::array<std::string_view,9>{"","03_00_00","03_0_0","3_00_0","03_00_0x","00_00_0","255_255_255","a","03_00_0 "})query(memory.data(),scenario,key);
 std::cout<<"{\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"matches\":"<<matches<<",\"original_calls\":"<<calls<<",\"profile_rows\":"<<assets.size()<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
