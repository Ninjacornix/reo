#include "game/native/gameplay_session/session.hpp"
#include "original_fixture.hpp"
#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>
#include "original_declarations.inc"
namespace s=reo::native::gameplay_session;
namespace {
unsigned checks{};std::vector<std::uint32_t> events;bool mutate{};
void check(bool value){++checks;if(!value)throw std::runtime_error("session differential "+std::to_string(checks));}
void returned(R5900Context* c){c->pc=GPR_U32(c,31);}
template<class T>T get(const std::vector<std::uint8_t>& r,std::uint32_t at){return fixture_read<T>(r.data(),at);}
template<class T>void put(std::vector<std::uint8_t>& r,std::uint32_t at,T v){fixture_write(r.data(),at,v);}
s::Options options(const std::vector<std::uint8_t>& r){return {r[0x3243c5],r[0x3243c9],r[0x3243ca],r[0x3243ec],r[0x3243ef],r[0x3243f0],std::bit_cast<std::int8_t>(r[0x3243ed]),std::bit_cast<std::int8_t>(r[0x3243ee])};}
void options(std::vector<std::uint8_t>& r,const s::Options& o){r[0x3243c5]=o.audio_mode;r[0x3243c9]=o.music_volume;r[0x3243ca]=o.effects_volume;r[0x3243ec]=o.controller_profile;r[0x3243ef]=o.vibration;r[0x3243f0]=o.brightness;r[0x3243ed]=std::bit_cast<std::uint8_t>(o.screen_x);r[0x3243ee]=std::bit_cast<std::uint8_t>(o.screen_y);}
s::SavedOptions saved(const std::vector<std::uint8_t>& r){s::SavedOptions v;std::memcpy(v.data(),r.data()+0x3241a0,16);return v;}
void saved(std::vector<std::uint8_t>& r,const s::SavedOptions& v){std::memcpy(r.data()+0x3241a0,v.data(),16);}
void event(std::uint32_t id,std::uint32_t a=0,std::uint32_t b=0){events.insert(events.end(),{id,a,b});}
struct Services:s::OptionServices {
 void defaults_changed(s::SavedOptions& v)override{event(0x1b8290);if(mutate)v[14]=std::byte(99);}
 void screen_offset(s::Options& o,std::int8_t x,std::int8_t y)override{event(0x1af790,std::uint32_t(std::int32_t(x)),std::uint32_t(std::int32_t(y)));if(mutate)o.audio_mode=0x83;}
 void audio_mode(s::Options& o,std::uint8_t v)override{event(0x1b86c0,v);if(mutate)o.effects_volume=0x91;}
 void effects_volume(s::Options& o,std::uint8_t v)override{event(0x1b86f0,v);if(mutate)o.music_volume=0xf7;}
 void music_volume(s::Options&,std::uint8_t v)override{event(0x1b8780,v);}
};
std::uint32_t invoke(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram,std::uint32_t argument=0){R5900Context c;PS2Runtime rt;SET_GPR_U32(&c,4,argument);SET_GPR_U32(&c,29,0x3f0000);SET_GPR_U32(&c,31,0xdead0000);fn(ram.data(),&c,&rt);check(c.pc==0xdead0000);return GPR_U32(&c,2);}
}
void sub_00107C68_0x107c68(std::uint8_t* r,R5900Context* c,PS2Runtime*){std::memset(r+GPR_U32(c,4),int(GPR_U32(c,5)),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));returned(c);}
void sub_00107AB0_0x107ab0(std::uint8_t* r,R5900Context* c,PS2Runtime*){std::memmove(r+GPR_U32(c,4),r+GPR_U32(c,5),GPR_U32(c,6));SET_GPR_U32(c,2,GPR_U32(c,4));returned(c);}
void sub_001B8290_0x1b8290(std::uint8_t* r,R5900Context* c,PS2Runtime*){event(0x1b8290);if(mutate)r[0x3241ae]=99;returned(c);}
void sub_001AF790_0x1af790(std::uint8_t* r,R5900Context* c,PS2Runtime*){event(0x1af790,GPR_U32(c,4),GPR_U32(c,5));if(mutate)r[0x3243c5]=0x83;returned(c);}
void sub_001B86C0_0x1b86c0(std::uint8_t* r,R5900Context* c,PS2Runtime*){event(0x1b86c0,GPR_U32(c,4));if(mutate)r[0x3243ca]=0x91;returned(c);}
void sub_001B86F0_0x1b86f0(std::uint8_t* r,R5900Context* c,PS2Runtime*){event(0x1b86f0,GPR_U32(c,4));if(mutate)r[0x3243c9]=0xf7;returned(c);}
void sub_001B8780_0x1b8780(std::uint8_t*,R5900Context* c,PS2Runtime*){event(0x1b8780,GPR_U32(c,4));returned(c);}

int main()try{
 std::vector<std::uint8_t> ram(0x400000,0xac);Services services;
 constexpr std::array<std::uint8_t,16> defaults{0,7,7,0,1,128,0,0,1,0,0,0,0,0,0,0};std::memcpy(ram.data()+0x24fe30,defaults.data(),16);
 std::uint64_t requests{};
 for(std::uint32_t seed=0;seed<=0xffff;++seed){
  s::Random native({std::uint16_t(seed),std::uint16_t(seed^0xf731),std::uint8_t(seed)});
  put(ram,0x3244b0,std::uint16_t(seed));put(ram,0x3244b8,std::uint16_t(seed^0xf731));ram[0x2b8de8]=std::uint8_t(seed);
  for(const auto mode:{0u,1u,2u,3u,1u,3u,0u,2u,4u,0xffffffffu}){
   const auto value=invoke(sub_001AEC80_0x1aec80,ram,mode);check(native.request(mode)==value);check(native.state()==s::RandomState{get<std::uint16_t>(ram,0x3244b0),get<std::uint16_t>(ram,0x3244b8),ram[0x2b8de8]});++requests;
  }
 }
 for(unsigned seed=0;seed<256;++seed){
  s::Random native({0xffff,0xfefe,0xaa});ram[0x324199]=std::uint8_t(seed);ram[0x2b8de8]=0xff;invoke(sub_001AEC50_0x1aec50,ram);native.seed(std::uint8_t(seed));check(native.state()==s::RandomState{get<std::uint16_t>(ram,0x3244b0),get<std::uint16_t>(ram,0x3244b8),ram[0x2b8de8]});
 }
 for(unsigned i=0;i<4096;++i){
  s::Options o{std::uint8_t(i),std::uint8_t(i*3),std::uint8_t(i*7),std::uint8_t(i*11),std::uint8_t(i*13),std::uint8_t(i*17),std::bit_cast<std::int8_t>(std::uint8_t(i*19)),std::bit_cast<std::int8_t>(std::uint8_t(i*23))};options(ram,o);
  invoke(sub_001AEE40_0x1aee40,ram);s::sanitize_options(o);check(o==options(ram));
  s::SavedOptions native;native.fill(std::byte(0xa9));saved(ram,native);invoke(sub_001AEDB0_0x1aedb0,ram);s::capture_options(o,native);check(native==saved(ram));
  for(unsigned j=0;j<16;++j){native[j]=std::byte(std::uint8_t(i*3+j*7));}
  saved(ram,native);mutate=(i%2)!=0;
  events.clear();invoke(sub_001BADF0_0x1badf0,ram);const auto expected_events=events;events.clear();s::restore_options(native,o,services);check(o==options(ram));check(events==expected_events);
  events.clear();invoke(sub_001AED60_0x1aed60,ram);const auto expected_defaults=events;events.clear();s::initialize_saved_options(native,services);check(native==saved(ram));check(events==expected_defaults);
 }
 std::cout<<"{\"checks\":"<<checks<<",\"rng_requests\":"<<requests<<",\"option_cases\":4096,\"seed_cases\":256,\"original_bodies_executed\":true,\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
