#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "game/native/gameplay_scenario/lighting.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace {
std::size_t checks{},invocations{},asset_cases{};
void check(bool ok){++checks;if(!ok)throw std::runtime_error("Lighting assertion "+std::to_string(checks));}
void done(R5900Context* c){c->pc=GPR_U32(c,31);}
void copy(std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto d=GPR_U32(c,4),s=GPR_U32(c,5),n=GPR_U32(c,6);check(d<=0x800000&&n<=0x800000-d&&s<=0x800000&&n<=0x800000-s);std::memmove(r+d,r+s,n);done(c);}
void fill(std::uint8_t* r,R5900Context* c,PS2Runtime*){const auto d=GPR_U32(c,4),n=GPR_U32(c,6);check(d<=0x800000&&n<=0x800000-d);std::memset(r+d,int(GPR_U32(c,5)&255),n);done(c);}
std::uint32_t call(PS2Runtime::Function f,std::vector<std::uint8_t>& r,std::uint32_t a=0,std::uint32_t b=0,std::uint32_t d=0){R5900Context c;PS2Runtime rt;SET_GPR_U32(&c,4,a);SET_GPR_U32(&c,5,b);SET_GPR_U32(&c,6,d);SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);f(r.data(),&c,&rt);check(c.pc==0xdeadbeef);++invocations;return GPR_U32(&c,2);}
void put(std::vector<std::byte>& b,std::size_t p,std::uint32_t v){for(unsigned i=0;i<4;++i)b.at(p+i)=std::byte((v>>(8*i))&255);}
std::array<float,13> values(const vm::LightDescriptor& d){std::array<float,13> a{};std::copy(d.vector0.begin(),d.vector0.end(),a.begin());std::copy(d.vector1.begin(),d.vector1.end(),a.begin()+4);std::copy(d.position.begin(),d.position.end(),a.begin()+8);a[11]=d.attenuation;a[12]=d.parameter;return a;}
void compare_descriptor(const vm::LightDescriptor& d,const std::vector<std::uint8_t>& r,std::uint32_t at){const auto a=values(d);for(std::size_t i=0;i<a.size();++i)check(std::bit_cast<std::uint32_t>(a[i])==fixture_read<std::uint32_t>(r.data(),at+std::uint32_t(4*i)));}
void compare(const vm::Lighting& state,const std::vector<std::uint8_t>& r){
 check(std::uint8_t(state.selected())==r[0x3240be]);check(state.primary_count()==r[0x747538]);
 for(std::size_t i=0;i<4;++i){const auto& bank=state.banks()[i];const auto at=0x3dc1e0+std::uint32_t(i*0x6f4);
  check(bank.kind==fixture_read<std::uint16_t>(r.data(),at));check(bank.count==fixture_read<std::uint16_t>(r.data(),at+2));compare_descriptor(bank.base,r,at+4);
  for(std::size_t j=0;j<14;++j)check(bank.environment_words[j]==fixture_read<std::uint32_t>(r.data(),at+56+std::uint32_t(4*j)));
  for(std::size_t j=0;j<32;++j)compare_descriptor(bank.entries[j],r,at+112+std::uint32_t(52*j));
  check(bank.enabled_mask==fixture_read<std::uint32_t>(r.data(),at+0x6f0));
 }
 for(std::size_t i=0;i<64;++i){const auto& p=state.primary()[i];const auto at=0x747540+std::uint32_t(i*56);check(p.active==r[at]);check(p.tag==r[at+1]);check(p.mode==r[at+2]);check(p.reserved==r[at+3]);compare_descriptor(p.descriptor,r,at+4);}
 for(std::size_t i=0;i<32;++i){const auto address=fixture_read<std::uint32_t>(r.data(),0x7474b0+std::uint32_t(i*4));check(address==(state.bindings()[i]==255?0u:0x747540u+56u*state.bindings()[i]));}
}
void import(vm::Lighting& state,std::vector<std::uint8_t>& r,const std::vector<std::byte>& b){check(b.size()<0x100000);std::memcpy(r.data()+0x10000,b.data(),b.size());const auto v=state.import_lig(b);call(o2_006B1EC0_0x6b1ec0,r,0x10000);check(v==vm::LightingImport::completed);compare(state,r);}
std::vector<std::byte> synthetic(){std::vector<std::byte> b(24+4*(116+32*52));put(b,0,4);put(b,4,4);std::uint32_t seed=0x7215a8f1;
 for(unsigned i=0;i<4;++i){const auto at=24+i*(116+32*52);put(b,8+4*i,at);put(b,at,0xabcdef01u+i);put(b,at+4,32);
  for(unsigned j=8;j<116+32*52;j+=4){seed=seed*1664525u+1013904223u;put(b,at+j,seed);}
  for(unsigned j=0;j<32;++j){constexpr std::array<std::uint32_t,8> edges{0,0x80000000u,0xbf800000u,0x3f800000u,0x7fc12345u,0x7f800000u,0xff800000u,0x00000001u};put(b,at+116+52*j+44,edges[j%edges.size()]);}
 }return b;
}
}
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at)const{if(at==0x107ab0)return copy;if(at==0x107c68)return fill;throw std::runtime_error("Unexpected lighting dependency "+std::to_string(at));}
int main(int argc,char** argv)try{
 check(argc==2);std::vector<std::uint8_t> r(0x800000);vm::Lighting state;state.reset_work();call(o2_006B1DC0_0x6b1dc0,r);compare(state,r);
 std::ifstream list(argv[1]);check(bool(list));std::string line;
 while(std::getline(list,line)){if(line.empty())continue;const auto a=line.find('\t'),z=line.find('\t',a+1);check(a!=std::string::npos&&z!=std::string::npos);std::ifstream f(line.substr(0,a),std::ios::binary);check(bool(f));const auto at=std::stoull(line.substr(a+1,z-a-1)),n=std::stoull(line.substr(z+1));std::vector<std::byte> b(n);f.seekg(std::streamoff(at));f.read(reinterpret_cast<char*>(b.data()),std::streamsize(n));check(std::size_t(f.gcount())==n);import(state,r,b);++asset_cases;
  for(unsigned k=0;k<6;++k){state.select(std::uint8_t(k));call(o2_006B1FE0_0x6b1fe0,r,k);compare(state,r);}
 }
 const auto b=synthetic();import(state,r,b);
 // All original byte bank selectors, including upper bits ignored by ABI.
 for(unsigned i=0;i<256;++i){state.select(std::uint8_t(i));call(o2_006B1FE0_0x6b1fe0,r,0xaabb0000u|i);compare(state,r);}
 for(unsigned bank=0;bank<4;++bank){state.select(std::uint8_t(bank));call(o2_006B1FE0_0x6b1fe0,r,bank);
  for(unsigned i=0;i<32;++i){check(state.create(std::uint8_t(i)));call(o2_006B2020_0x6b2020,r,0x12340000u|i);compare(state,r);}
  for(unsigned i=0;i<32;++i){check(state.remove(std::uint8_t(i)));call(o2_006B2170_0x6b2170,r,i);compare(state,r);}
 }
 // Exhaustion still marks enabled; null payload allocation retains old payload.
 import(state,r,b);state.select(0);call(o2_006B1FE0_0x6b1fe0,r,0);
 for(unsigned i=0;i<65;++i){const auto slot=state.allocate(nullptr,std::uint8_t(i),std::uint8_t(i+7));const auto address=call(o2_006B3090_0x6b3090,r,0,i,i+7);check(address==(slot?0x747540u+56u*(*slot):0));compare(state,r);}
 check(state.create(3));call(o2_006B2020_0x6b2020,r,3);compare(state,r);check(state.banks()[0].enabled_mask&(1u<<3));check(state.bindings()[3]==255);
 // Retained bank binding deliberately targets a reused native pool slot.
 import(state,r,b);state.select(0);call(o2_006B1FE0_0x6b1fe0,r,0);check(state.create(3));call(o2_006B2020_0x6b2020,r,3);check(state.remove(3));call(o2_006B2170_0x6b2170,r,3);const auto reused=state.allocate(nullptr,9,2);call(o2_006B3090_0x6b3090,r,0,9,2);check(reused&&*reused==0);check(state.remove(3));call(o2_006B2170_0x6b2170,r,3);compare(state,r);check(state.primary_count()==0);
 // Invalid version clears imported banks while keeping existing work intact.
 auto bad=b;put(bad,0,3);check(state.import_lig(bad)==vm::LightingImport::unsupported_version);std::memcpy(r.data()+0x10000,bad.data(),bad.size());call(o2_006B1EC0_0x6b1ec0,r,0x10000);compare(state,r);
 for(const auto count:{0u,0xffffffffu,0x80000000u}){auto empty=b;put(empty,4,count);import(state,r,empty);}
 import(state,r,b);state.select(0);call(o2_006B1FE0_0x6b1fe0,r,0);check(state.create_all());for(unsigned i=0;i<32;++i)call(o2_006B2020_0x6b2020,r,i);compare(state,r);
 const auto epoch=state.reset_epoch();for(unsigned mode=0;mode<4;++mode){auto broken=b;if(mode==0)broken.resize(7);if(mode==1)put(broken,4,5);if(mode==2)put(broken,8,0xfffffff0u);if(mode==3)put(broken,28,33);bool refused=false;try{state.import_lig(broken);}catch(const std::invalid_argument&){refused=true;}check(refused);check(state.reset_epoch()==epoch);compare(state,r);}
 check(!state.create(32));check(!state.remove(255));check(!state.release(64));state.reset_work();call(o2_006B1DC0_0x6b1dc0,r);compare(state,r);check(!state.remove(0));
 std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<invocations<<",\"owned_lig_cases\":"<<asset_cases<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
