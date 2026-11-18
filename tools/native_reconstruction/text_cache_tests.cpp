#include "game/native/gameplay_scenario/text_cache.hpp"
#include "reference.hpp"
#include "functions.h"
#include <bit>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},commands{},source_calls{},allocations{},misses{},interrupted{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Text cache "+std::to_string(at.line())+" command "+std::to_string(commands));}
std::vector<std::uint8_t> memory(0x2000000);bool interrupt_copy{},did_interrupt{};
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
R5900Context call(unsigned at,std::array<std::int32_t,7> arguments={}){R5900Context state;PS2Runtime runtime;state.pc=at;for(unsigned i=0;i<arguments.size();++i)SET_GPR_S32(&state,4+i,arguments[i]);SET_GPR_U32(&state,29,0x1f00000);SET_GPR_U32(&state,31,0xabcdef);did_interrupt=false;original_transform_port(memory.data(),&state,&runtime);check(state.pc==(did_interrupt?0xdead0001u:0xabcdefu));if(!did_interrupt)check(GPR_U32(&state,29)==0x1f00000);return state;}
void compare(const s::TextCache& cache){const auto snapshot=cache.snapshot();check(bool(snapshot));for(unsigned index=0;index<s::TextCache::capacity;++index){const auto& record=(*snapshot)[index];std::array<std::uint8_t,0x8c> expected{};const auto put=[&]<class T>(unsigned at,T value){std::memcpy(expected.data()+at,&value,sizeof value);};put(0,std::uint16_t(record.active));put(2,record.x);put(4,record.y);put(6,record.duration);put(8,record.height);put(9,record.fade);put(10,record.alpha);put(11,record.priority);std::memcpy(expected.data()+12,record.text.data(),128);const auto at=0x3151d0+0x8c*index;
    if(std::memcmp(expected.data(),memory.data()+at,expected.size()))for(unsigned byte=0;byte<expected.size();++byte)if(expected[byte]!=memory[at+byte]){std::cerr<<"Cache difference slot="<<index<<" byte="<<byte<<" native="<<unsigned(expected[byte])<<" original="<<unsigned(memory[at+byte])<<'\n';break;}
    check(std::memcmp(expected.data(),memory.data()+at,expected.size())==0);}}
unsigned input(std::span<const std::byte> text,unsigned alignment){const unsigned at=0x100000+alignment;std::fill_n(memory.data()+0x100000,256,0xa5);std::memcpy(memory.data()+at,text.data(),text.size());memory[at+text.size()]=0;return at;}
void inserted(const s::CachedTextResult& native,const R5900Context& original){check(native.status==s::TextCacheStatus::completed);const auto pointer=GPR_U32(&original,2);check(bool(native.index)==bool(pointer));if(native.index){check(pointer==0x3151d0+0x8c*(*native.index)+10);++allocations;}else ++misses;}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++source_calls;if(interrupt_copy&&context->pc==0x10afc0){did_interrupt=true;context->pc=0xdead0001;return;}switch(context->pc){
#include "original_dispatch.hpp"
default:throw std::runtime_error("Undeclared text cache helper "+std::to_string(context->pc));}}
int main()try{
    s::TextCache cache;check(!cache.snapshot()&&cache.request(1,0,0,1,20,{},0).status==s::TextCacheStatus::unbound&&cache.erase({})==s::TextCacheStatus::unbound);
    std::fill_n(memory.data()+0x3151c0-16,0x1190+32,0xa5);cache.reset();call(0x1b4a60);compare(cache);for(unsigned i=0;i<16;++i)check(memory[0x3151c0-16+i]==0xa5&&memory[0x3151c0+0x1190+i]==0xa5&&memory[0x3151c0+i]==0);
    std::array<std::vector<std::byte>,5> texts{{{}, {std::byte{'C'},std::byte{'a'},std::byte{'p'},std::byte{'t'},std::byte{'i'},std::byte{'o'},std::byte{'n'}},{std::byte{'c'},std::byte{'a'},std::byte{'p'},std::byte{'t'},std::byte{'i'},std::byte{'o'},std::byte{'n'}},{std::byte{0x82},std::byte{0xa0},std::byte{'A'},std::byte{0x81},std::byte{0x69}},std::vector<std::byte>(127,std::byte{'L'})}};
    const std::array<std::int32_t,12> ys{-32768,-1,0,1,320,321,346,32767,32768,65536,INT32_MAX,INT32_MIN};const std::array<std::int32_t,7> heights{0,1,20,255,256,INT32_MAX,-20};
    for(unsigned seed=0;seed<32768;++seed){const auto text=std::span<const std::byte>(texts[(seed/7)%texts.size()]);const auto pointer=input(text,seed%16);const int operation=int(seed%11);
        if(operation<6){const auto priority=seed%17==0?-1:std::int32_t((seed/11)%256);const auto x=std::bit_cast<std::int32_t>(seed*7477u+3u);const auto y=ys[(seed/13)%ys.size()],duration=std::bit_cast<std::int32_t>(seed*65537u),height=heights[(seed/19)%heights.size()],fade=std::int32_t(seed%5==0?0:seed*256u+(seed&255));const auto native=cache.request(priority,x,y,duration,height,text,fade);const auto original=call(0x1b46e0,{priority,x,y,duration,height,std::int32_t(pointer),fade});inserted(native,original);}
        else if(operation==6){check(cache.erase(text)==s::TextCacheStatus::completed);call(0x1b49b0,{std::int32_t(pointer)});}
        else if(operation==7){check(cache.expire()==s::TextCacheStatus::completed);call(0x1b4940);}
        else if(operation==8){check(cache.cull()==s::TextCacheStatus::completed);call(0x1b4450);}
        else if(operation==9){const auto x=std::bit_cast<std::int16_t>(std::uint16_t(seed*7));const auto y=std::uint16_t(seed*11);const auto alpha=std::uint8_t(seed);const auto native=cache.dialogue(x,y,text,alpha);const auto original=call(0x1b48e0,{x,y,1,20,std::int32_t(pointer),alpha});inserted(native,original);}
        else if(seed%127==0){cache.reset();call(0x1b4a60);}
        compare(cache);++commands;
    }
    const auto retained=cache.snapshot();cache.reset();call(0x1b4a60);check(retained.has_value());compare(cache);
    std::vector<std::byte> long_text(128,std::byte{'X'});const auto pointer=input(long_text,0);interrupt_copy=true;const auto native=cache.request(1,3,321,77,20,long_text,0);call(0x1b46e0,{1,3,321,77,20,std::int32_t(pointer),0});check(did_interrupt&&native.status==s::TextCacheStatus::unsupported_profile&&native.index==0);compare(cache);++interrupted;
    std::cout<<"{\"checks\":"<<checks<<",\"complete_commands\":"<<commands<<",\"source_calls\":"<<source_calls<<",\"insertions\":"<<allocations<<",\"admitted_no_insertions\":"<<misses<<",\"bounded_copy_interruptions\":"<<interrupted<<",\"retained_snapshots\":1,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
