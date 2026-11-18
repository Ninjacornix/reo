#include "game/native/animation/curves.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
namespace a=reo::native::animation;
#include "owned_constants.hpp"
#include "functions.h"
std::uint64_t checks{},helper_calls{},clip_cases{},curve_cases{},sample_cases{},parameter_cases{},admission_cases{},unused_tangent_cases{},used_tangent_refusals{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++helper_calls;switch(context->pc){
#include "original_dispatch.hpp"
 default:throw std::runtime_error("undeclared raw curve original helper "+std::to_string(context->pc));
 }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_curves.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* ram,std::uint32_t address,std::uint32_t arg0,std::uint32_t arg1=0,std::uint32_t arg2=0,std::uint32_t arg3=0,float frame=0){
 R5900Context ctx;ctx.pc=address;SET_GPR_U32(&ctx,4,arg0);SET_GPR_U32(&ctx,5,arg1);SET_GPR_U32(&ctx,6,arg2);SET_GPR_U32(&ctx,7,arg3);SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0xabcdef);ctx.f[12]=frame;PS2Runtime rt;original_transform_port(ram,&ctx,&rt);check(ctx.pc==0xabcdef&&GPR_U32(&ctx,29)==0x1f00000,"complete original curve chain returned");return ctx;
}
void compare_clip(std::vector<std::uint8_t>& ram,std::span<const std::byte> raw){
 auto clip=a::Clip::import_raw(raw);std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a1fd0,0x10000,0x800000,0x400000);
 const auto base=0x800000u;check(get<std::uint16_t>(ram.data(),0x10002)==clip->tracks().size(),"real raw packer/native track count");check(std::bit_cast<std::uint32_t>(clip->last_frame())==get<std::uint32_t>(ram.data(),0x10008),"real raw packer/native duration");check(bool(get<std::uint16_t>(ram.data(),0x10000)&0x8000)==clip->looping(),"real raw packer/native loop flag");if(clip->looping())check(std::bit_cast<std::uint32_t>(clip->loop_start())==get<std::uint32_t>(ram.data(),0x1000c),"real raw packer/native loop value");
 const auto offsets=base+get<std::uint32_t>(ram.data(),0x10010);put(ram.data(),0x294160,base);put(ram.data(),0x294168,base);
 for(unsigned index=0;index<clip->tracks().size();++index){
  const auto& track=clip->tracks()[index];const auto packed=base+get<std::uint32_t>(ram.data(),offsets+4*index);check(get<std::uint16_t>(ram.data(),packed+2)==track.curves.size(),"real raw packer/native channel count");check((get<std::uint16_t>(ram.data(),packed)&0xf000)==(track.quantized?0x2000:0x1000),"real raw packer/native channel mode");const auto descriptors=base+get<std::uint32_t>(ram.data(),packed+4);
  std::vector<float> times{-1.f,0.f,1.f,clip->last_frame(),clip->last_frame()+1};
  for(unsigned channel=0;channel<track.curves.size();++channel){
   const auto& curve=track.curves[channel];const auto descriptor=descriptors+8*channel;check(get<std::uint8_t>(ram.data(),descriptor)==curve.format()&&get<std::uint8_t>(ram.data(),descriptor+1)==curve.channel()&&get<std::uint16_t>(ram.data(),descriptor+2)==curve.keys().size(),"native channel import agrees with actual original raw converter");
   for(unsigned k=0;k<curve.keys().size();++k){times.push_back(curve.keys()[k].time);if(k)times.push_back((curve.keys()[k-1].time+curve.keys()[k].time)*.5f);}
   std::int16_t cache=32767;std::vector<float> samples{curve.keys().front().time-1,curve.keys().back().time+1};for(const auto& key:curve.keys())samples.push_back(key.time);for(unsigned k=1;k<curve.keys().size();++k)samples.push_back((curve.keys()[k-1].time+curve.keys()[k].time)*.5f);
   for(bool backwards:{false,true}){
    if(backwards)std::reverse(samples.begin(),samples.end());
    for(float frame:samples){put(ram.data(),0x20000,cache);const auto ctx=call(ram.data(),0x18e3c0,descriptor,0x20000,0,0,frame);const auto value=curve.sample(frame,cache);check(std::bit_cast<std::uint32_t>(value)==std::bit_cast<std::uint32_t>(ctx.f[0]),"curve value differs format "+std::to_string(curve.format())+" frame "+std::to_string(frame));check(cache==get<std::int16_t>(ram.data(),0x20000),"original per-channel cache effect");++sample_cases;}
   }
   ++curve_cases;
  }
  a::Caches cache{};a::Parameters values{};for(unsigned i=0;i<10;++i)values[i]=float(i)*.125f;
  for(float frame:times){put(ram.data(),0x21000,values);put(ram.data(),0x22000,cache);call(ram.data(),0x193c80,packed,0,0x21000,0x22000,frame);a::sample_parameters(track,frame,values,cache);check(std::memcmp(values.data(),ram.data()+0x21000,sizeof values)==0&&std::memcmp(cache.data(),ram.data()+0x22000,sizeof cache)==0,"complete original channel decode/quantization/cache state");++parameter_cases;}
 }
 ++clip_cases;
}
std::vector<std::byte> synthetic(unsigned format){
 const unsigned stride=format==0x21?8:format==0x22?16:format==0x23?20:format==0x11?4:format==0x12?8:12;constexpr unsigned count=4;const unsigned total=20+12+12+count*stride;std::vector<std::byte> b(total);const auto write=[&]<class T>(unsigned at,T value){std::memcpy(b.data()+at,&value,sizeof value);};write(0,std::uint32_t(format>=0x20?1:2));write(4,1u);write(8,total);write(12,1u);write(16,2.f);write(20,0x80000000u);write(24,1u);write(28,12+12+count*stride);write(32,0x80000008u|(format<<16));write(36,count);write(40,12+count*stride);
 const bool compact=format<0x20,mixed=(format&15)==3,cubic=(format&15)==2;
 for(unsigned i=0;i<count;++i){unsigned at=44+i*stride;if(mixed){write(at,i==2?0x30000u:i&1?0x20000u:0x10000u);at+=4;}const auto number=[&](unsigned field,float v){if(compact)write(at+field*2,std::int16_t(v));else write(at+field*4,v);};number(0,float(int(i)*7-11));number(1,float(i)*3);if(cubic||mixed){number(2,float(int(i)-2));number(3,float(int(i)+1));}}
 return b;
}
int main(int argc,char** argv)try{
 check(argc==3,"owned ordinary and cinematic clip inputs required");const auto old=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old};_mm_setcsr(0x1f80);std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());
 for(unsigned format:{0x11u,0x12u,0x13u,0x21u,0x22u,0x23u}){auto raw=synthetic(format);compare_clip(ram,raw);}
 // Complete original sole-key branch never reads cubic/mixed tangent payloads.
 for(unsigned format:{0x22u,0x23u})for(std::uint32_t payload:{0xffc00000u,0x7f800000u,0xff800000u}){
  const unsigned stride=format==0x22?16:20;auto raw=synthetic(format);raw.resize(44+stride);
  const auto write=[&](unsigned at,std::uint32_t v){std::memcpy(raw.data()+at,&v,4);};
  write(8,unsigned(raw.size()));write(28,24+stride);write(36,1);write(40,12+stride);
  const unsigned tangent=44+(format==0x23?4:0)+8;write(tangent,payload);write(tangent+4,payload);
  compare_clip(ram,raw);++unused_tangent_cases;
  auto endpoints=synthetic(format);std::memcpy(endpoints.data()+tangent,&payload,4);std::memcpy(endpoints.data()+tangent+3*stride+4,&payload,4);
  compare_clip(ram,endpoints);++unused_tangent_cases;
  // Segment1 is cubic for both formats: its outgoing and key2 incoming
  // tangents are actually consumed, unlike either outer endpoint tangent.
  for(const auto used_at:{tangent+stride+4,tangent+2*stride}){
   auto used=synthetic(format);std::memcpy(used.data()+used_at,&payload,4);bool refused{};
   try{(void)a::Clip::import_raw(used);}catch(const std::domain_error&){refused=true;}
   check(refused,"actually used multi-key nonfinite tangent remains refused");++used_tangent_refusals;
  }
 }
 std::ifstream extra(argv[2],std::ios::binary);check(bool(extra),"owned object clip input opens");std::vector<char> extra_bytes((std::istreambuf_iterator<char>(extra)),{});check(!extra.bad()&&!extra_bytes.empty(),"complete owned object clip input");compare_clip(ram,std::as_bytes(std::span(extra_bytes)));
 std::ifstream f(argv[1],std::ios::binary);std::uint32_t count{};f.read(reinterpret_cast<char*>(&count),4);check(count==59,"bounded owned corpus identity");for(unsigned i=0;i<count;++i){std::uint32_t size{};f.read(reinterpret_cast<char*>(&size),4);check(size>0&&size<0x400000,"bounded owned clip extent");std::vector<std::byte> raw(size);f.read(reinterpret_cast<char*>(raw.data()),size);check(bool(f),"complete owned clip bytes");try{compare_clip(ram,raw);}catch(const std::exception& e){throw std::runtime_error("Owned clip "+std::to_string(i)+": "+e.what());}}
 for(unsigned mode=0;mode<5;++mode){auto raw=synthetic(0x12);if(mode==0)raw.resize(19);if(mode==1){std::uint32_t zero=0;std::memcpy(raw.data()+36,&zero,4);}if(mode==2){std::uint32_t inactive=0x00120008;std::memcpy(raw.data()+32,&inactive,4);}if(mode==3){std::int16_t t=-1;std::memcpy(raw.data()+44+8+2,&t,2);}if(mode==4){std::uint32_t unsupported=0x80140008;std::memcpy(raw.data()+32,&unsupported,4);}bool refused{};try{(void)a::Clip::import_raw(raw);}catch(const std::invalid_argument&){refused=true;}check(refused,"malformed/undefined clip admission is explicit");++admission_cases;}
 std::cout<<"{\"checks\":"<<checks<<",\"clips\":"<<clip_cases<<",\"curves\":"<<curve_cases<<",\"samples\":"<<sample_cases<<",\"parameter_cases\":"<<parameter_cases<<",\"admission_cases\":"<<admission_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"unused_tangent_cases\":"<<unused_tangent_cases<<",\"used_tangent_refusals\":"<<used_tangent_refusals<<",\"owned_clips\":"<<count<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
