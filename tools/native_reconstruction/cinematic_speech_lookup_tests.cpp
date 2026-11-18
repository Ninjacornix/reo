#include "game/native/gameplay_bank_loading/aliases.hpp"
#include "reference.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
namespace b=reo::native::gameplay_bank_loading;
std::uint64_t checks{},calls{},queries{},misses{},prepared_sdk{};bool preparing{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Cinematic speech lookup line "+std::to_string(at.line()));}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "original_dispatch.inc"
 case 0x10a830:check(preparing&&std::string_view(reinterpret_cast<const char*>(memory+GPR_U32(context,5)))=="vo001%02d.afs");check(std::snprintf(reinterpret_cast<char*>(memory+GPR_U32(context,4)),64,"vo001%02d.afs",GPR_U32(context,6))>0);context->pc=GPR_U32(context,31);return;
 case 0x128738:check(preparing&&GPR_U32(context,4)>=5&&GPR_U32(context,4)<10&&GPR_U32(context,5)==3&&GPR_U32(context,6)>=401&&GPR_U32(context,6)<=408&&GPR_U32(context,7)>=0xd00000&&GPR_U32(context,7)<0xd10000);++prepared_sdk;SET_GPR_U32(context,2,0);context->pc=GPR_U32(context,31);return;
 case 0x128b18:check(preparing&&GPR_U32(context,4)>=5&&GPR_U32(context,4)<10);++prepared_sdk;SET_GPR_U32(context,2,3);context->pc=GPR_U32(context,31);return;
 case 0x1327b8:case 0x132df0:case 0x133490:case 0x132e50:check(preparing&&GPR_U32(context,4)==0x10008);if(context->pc==0x133490)check(GPR_U32(context,5)==3&&GPR_U32(context,6)<422);++prepared_sdk;SET_GPR_U32(context,2,0);context->pc=GPR_U32(context,31);return;
 default:throw std::runtime_error("Reached unexpected cinematic speech SDK child "+std::to_string(context->pc));
}}
unsigned invoke(std::uint8_t* memory,unsigned pc,unsigned a0,unsigned a1=0,unsigned a2=0,unsigned a3=0){R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,5,a1);SET_GPR_U32(&context,6,a2);SET_GPR_U32(&context,7,a3);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(memory,&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);}
int main(int argc,char** argv)try{
 check(argc==3);std::vector<std::uint8_t> memory(0x2000000);std::ifstream table(argv[1],std::ios::binary);unsigned count;table.read(reinterpret_cast<char*>(&count),4);check(count==426);std::vector<std::pair<unsigned,std::vector<std::uint8_t>>> immutable;
 for(unsigned index=0;index<count;++index){unsigned at,n;table.read(reinterpret_cast<char*>(&at),4);table.read(reinterpret_cast<char*>(&n),4);check(at<0x2000000&&n<=0x2000000-at);table.read(reinterpret_cast<char*>(memory.data()+at),n);check(bool(table));immutable.push_back({at,std::vector<std::uint8_t>(memory.begin()+at,memory.begin()+at+n)});}
 const auto lookup=[&](std::string_view name){check(name.size()<255);std::fill_n(memory.data()+0x500000,256,0);std::memcpy(memory.data()+0x500000,name.data(),name.size());const auto expected=b::sound_member(name);check(invoke(memory.data(),0x1ab2f0,0x500000)==(expected?*expected:0xffffffffu));++queries;return expected;};
 unsigned ordinal{};for(const auto name:b::sound_aliases()){check(lookup(name)==ordinal);++ordinal;}check(ordinal==422);
 preparing=true;transform_write(memory.data(),0x324468,0xd00000u);for(unsigned character=0;character<8;++character)check(invoke(memory.data(),0x1ab450,character%5,character)==1);transform_write(memory.data(),0x2b8dcc,0x10008u);transform_write(memory.data(),0x2b8d90,127u);
 for(const auto name:{"DEMO_S010300A.ADX","DEMO_S010301A.ADX"}){std::fill_n(memory.data()+0x500000,256,0);std::memcpy(memory.data()+0x500000,name,std::strlen(name));(void)invoke(memory.data(),0x1ae7d0,1,0,0x500000,0);}
 preparing=false;for(const auto& [at,bytes]:immutable)check(std::memcmp(bytes.data(),memory.data()+at,bytes.size())==0);check(prepared_sdk==24);
 std::ifstream cues(argv[2]);unsigned scenario,cue;int voice;
 while(cues>>scenario>>cue>>voice){for(int character=0;character<=8;++character){char name[128];const auto length=std::snprintf(name,sizeof name,"VO%03d%02d%02d_%01d.adx",scenario,cue,voice,character);check(length>0&&length<128);check(!lookup(name));check(invoke(memory.data(),0x1adb30,2,0x500000)==0);++misses;}}
 for(unsigned scenario_value:{0u,65535u})for(unsigned cue_value:{0u,255u})for(int voice_value:{-32768,-1,0,32767})for(int character:{-128,-1,0,127}){char name[128];check(std::snprintf(name,sizeof name,"VO%03d%02d%02d_%01d.adx",scenario_value,cue_value,voice_value,character)>0);check(!lookup(name));check(invoke(memory.data(),0x1adb30,2,0x500000)==0);++misses;}
 check(cues.eof()&&misses>64);std::cout<<"{\"checks\":"<<checks<<",\"positive_aliases\":"<<ordinal<<",\"queries\":"<<queries<<",\"voice_misses\":"<<misses<<",\"original_calls\":"<<calls<<",\"preparation_sdk_calls\":"<<prepared_sdk<<",\"voice_sdk_children_reached\":0,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
