#include "game/native/animation/motion_descriptors.hpp"
#include "reference.hpp"
#include <iostream>
#include <vector>
namespace a=reo::native::animation;
#include "constants.hpp"
#include "functions.h"
std::uint64_t checks{},calls{},resolve_cases{},unpack_cases{},refused_cases{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){++calls;switch(context->pc){
#include "dispatch.hpp"
 default:throw std::runtime_error("undeclared descriptor helper");}}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* memory,std::uint32_t at,std::uint32_t x,std::uint32_t y,std::uint32_t z=0){R5900Context c;c.pc=at;SET_GPR_U32(&c,4,x);SET_GPR_U32(&c,5,y);SET_GPR_U32(&c,6,z);SET_GPR_U32(&c,31,0xabcdef);PS2Runtime r;original_transform_port(memory,&c,&r);check(c.pc==0xabcdef,"complete original descriptor body return");return c;}
constexpr std::uint32_t actor=0x200000,output=0x220000,input=0x230000;
void export_identity(std::uint8_t* memory,const a::MotionIdentity& x){put(memory,actor+0xba0,x.status);put(memory,actor+0xca8,x.resource_action);put(memory,actor+2,x.category);put(memory,actor+4,x.subtype);put(memory,actor+0xb98,x.character);put(memory,actor+0xb9b,x.class_marker);}
int main()try{
 std::vector<std::uint8_t> ram(0x2000000);constants(ram.data());a::File1MotionDescriptors catalog;
 for(unsigned family=0;family<16;++family)for(unsigned key=0;key<568;++key)for(unsigned state=0;state<8;++state){a::MotionIdentity identity;identity.class_marker=std::uint8_t(state%5);identity.resource_action=std::uint16_t((key+state)%64);identity.status=state>=4?0x38u:state==3?0x18u:0;export_identity(ram.data(),identity);const std::uint32_t code=(family<<12)|key|0xabcd0000u;const a::PackedMotion* selected{};try{selected=&catalog.resolve(identity,code);}catch(const std::out_of_range&){++refused_cases;continue;}const auto result=call(ram.data(),0x5d46c0,actor,code);const auto at=GPR_U32(&result,2);check(at>=0x726aa0&&at<0x726aa0+568*8&&((at-0x726aa0)%8)==0,"original lookup lands in exact admitted descriptor profile");check(std::memcmp(selected->bytes.data(),ram.data()+at,8)==0,"complete original family/state/resource lookup");++resolve_cases;}
 for(unsigned id=0;id<1112;++id)for(unsigned category=0;category<5;++category)for(unsigned variant=0;variant<8;++variant){a::MotionIdentity identity;identity.category=std::uint8_t(category);identity.character=std::uint8_t(variant);identity.subtype=std::uint8_t(7-variant);export_identity(ram.data(),identity);const a::PackedMotion* admitted{};try{admitted=&catalog.at(id);}catch(const std::out_of_range&){++refused_cases;continue;}const auto& packed=*admitted;std::memcpy(ram.data()+input,packed.bytes.data(),8);std::fill_n(ram.data()+output,12,0xcc);a::DecodedMotion decoded;try{decoded=catalog.unpack(identity,packed);}catch(const std::out_of_range&){++refused_cases;continue;}call(ram.data(),0x5d4570,actor,output,input);check(decoded.family==ram[output]&&decoded.flags==ram[output+2]&&decoded.offset_selector==ram[output+3]&&decoded.shape_selector==ram[output+4]&&decoded.threshold==ram[output+5]&&decoded.alternate_threshold==ram[output+6]&&decoded.channel_one==get<std::uint16_t>(ram.data(),output+8)&&decoded.channel_zero==get<std::uint16_t>(ram.data(),output+10),"complete original packed descriptor expansion including category-one coercion and single indirection");check(ram[output+1]==0xcc&&ram[output+7]==0xcc,"original scratch padding is not a semantic native field");++unpack_cases;}
 // Preserve literal linear class-index arithmetic, including source states
 // larger than3 while the resulting whole-table index remains admitted.
 for(unsigned state=0;state<256;++state){a::MotionIdentity identity;identity.class_marker=std::uint8_t(state);for(unsigned family:{2u,3u}){export_identity(ram.data(),identity);const auto& selected=catalog.resolve(identity,family<<12);const auto result=call(ram.data(),0x5d46c0,actor,family<<12);check(std::memcmp(selected.bytes.data(),ram.data()+GPR_U32(&result,2),8)==0,"all raw class bytes preserve linear source table indexing");++resolve_cases;}}
 unsigned admitted_count{};for(unsigned id=0;id<1112;++id){try{(void)catalog.at(id);++admitted_count;}catch(const std::out_of_range&){}}check(admitted_count==768,"exact568 lookup roots plus200 proven one-level targets; gaps refused");for(unsigned id=0;id<64;++id)check(catalog.resource_class(std::uint16_t(id))==ram[0x719a64+68*id],"owned resource selector used by full native motion selection");
 std::cout<<"{\"checks\":"<<checks<<",\"resolve_cases\":"<<resolve_cases<<",\"unpack_cases\":"<<unpack_cases<<",\"unsupported_profile_refusals\":"<<refused_cases<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
