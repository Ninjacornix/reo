#include "game/native/animation/motion_bank.hpp"
#include "reference.hpp"
#include <fstream>
#include <iostream>
#include <vector>
namespace a=reo::native::animation;
#include "constants.hpp"
#include "functions.h"
std::uint64_t checks{},calls{},constructed{},releases{},bank_cases{},live_slots{},lookup_cases{},lifetime_cases{},refusal_cases{};
std::uint64_t clear_cases{},cleared_queries{};
std::uint64_t family_clear_cases{};
std::uint64_t scene_family_cases{},reserved_queries{},reserved_live_cases{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
constexpr std::uint32_t raw_base=0x800000;
struct Token{unsigned asset{};std::size_t offset{};};std::vector<Token> tokens(1);Token pending;unsigned current_asset{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++calls;
 if(context->pc==0x1b2ce0){context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x107c68){const auto destination=GPR_U32(context,4),length=GPR_U32(context,6);check(GPR_U32(context,5)==0&&destination<=0x2000000&&length<=0x2000000-destination,"bounded original bank clear");std::memset(memory+destination,0,length);SET_GPR_U32(context,2,destination);context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x1d3550){const auto raw=GPR_U32(context,6);check(raw>=raw_base,"original pack seam identifies owned raw block");pending={current_asset,raw-raw_base};context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x192500){check(tokens.size()<65536,"bounded fixture token identity");tokens.push_back(pending);SET_GPR_U32(context,2,std::uint32_t(tokens.size()-1));++constructed;context->pc=GPR_U32(context,31);return;}
 if(context->pc==0x1925a0){check(GPR_U32(context,4)>0&&GPR_U32(context,4)<tokens.size(),"release preserves valid old token identity");++releases;context->pc=GPR_U32(context,31);return;}
 switch(context->pc){
#include "original_dispatch.hpp"
 default:throw std::runtime_error("unadmitted original bank helper "+std::to_string(context->pc));
 }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_banks.cpp"
#pragma GCC diagnostic pop
void call(std::uint8_t* ram,std::uint32_t at,std::uint32_t arg0,std::uint32_t arg1=0,std::uint32_t arg2=0,std::uint32_t arg3=0,std::uint32_t arg4=0){R5900Context c;c.pc=at;SET_GPR_U32(&c,4,arg0);SET_GPR_U32(&c,5,arg1);SET_GPR_U32(&c,6,arg2);SET_GPR_U32(&c,7,arg3);SET_GPR_U32(&c,8,arg4);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);PS2Runtime r;original_transform_port(ram,&c,&r);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000,"complete original constructor returned");}
std::vector<std::vector<std::byte>> load(const char* path){std::ifstream f(path,std::ios::binary);std::uint32_t n{};f.read(reinterpret_cast<char*>(&n),4);check(n==5,"five owned whole bank assets");std::vector<std::vector<std::byte>> result;for(unsigned i=0;i<n;++i){std::uint32_t size{};f.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x400000,"owned bank size");result.emplace_back(size);f.read(reinterpret_cast<char*>(result.back().data()),size);check(bool(f),"complete original bank bytes");}return result;}
void compare(const a::MotionBank& bank,const std::vector<std::uint8_t>& ram,std::uint32_t at){
 check(bank.first_track()==ram[at]&&bank.track_count()==ram[at+1]&&unsigned(bank.kind())==ram[at+2],"source bank header");
 for(unsigned i=0;i<2000;++i){const auto token=get<std::uint16_t>(ram.data(),at+4+2*i);const auto block=bank.slots()[i];check(bool(block)==bool(token),"actual sparse/strided live slot "+std::to_string(i));if(token){check(token<tokens.size(),"slot token provenance");const auto expected=tokens[token];check(block->source_offset()==expected.offset&&block->source_identity()==std::to_string(expected.asset),"owned raw block identity through original memoization and overwrite");++live_slots;}if(bank.kind()==a::MotionBankKind::sparse)check(bank.rows()[i]==get<std::uint16_t>(ram.data(),at+0xfa4+2*i),"complete original logical-row map");}
 for(unsigned key=0;key<2000;++key)for(unsigned track=0;track<bank.track_count();++track){const auto slot=bank.kind()==a::MotionBankKind::sparse?std::size_t(get<std::uint16_t>(ram.data(),at+0xfa4+2*key))+track:200ull*(key/100)+(key%100)*bank.track_count()+track;if(slot>=2000)continue;const auto expected=get<std::uint16_t>(ram.data(),at+4+2*slot);check(bank.find(key,std::uint16_t(track))==bank.slots()[slot]&&bool(bank.find(key,std::uint16_t(track)))==bool(expected),"actual original query-index formula");++lookup_cases;}
 ++bank_cases;
}
void scene_family_tests(const std::vector<std::vector<std::byte>>& assets,std::vector<std::uint8_t>& ram){
 constexpr unsigned destination=0x4e8970;
 for(unsigned kind=0;kind<3;++kind){
  std::fill_n(ram.data()+destination,0x1f44,0);std::fill_n(ram.data()+0x4e6a20,0x1f44,0);std::fill_n(ram.data()+0x4d7000,8*0x1f44,0);a::MotionBank bank;
  for(unsigned asset=0;asset<2;++asset){current_asset=asset;const auto& bytes=assets[asset];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());bank.load_sparse(bytes,8,std::uint8_t(asset),std::to_string(asset));call(ram.data(),0x1d1940,raw_base,destination,unsigned(bytes.size()),asset);}
  if(kind){current_asset=2;const auto& bytes=assets[2];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());bank.load_strided(bytes,kind==2?500:200,0,"2");call(ram.data(),kind==2?0x1d1990:0x1d1960,raw_base,destination,unsigned(bytes.size()),200);}
  const auto previous=bank;const auto count_before=releases;unsigned expected_releases{};for(unsigned i=5;i<2000;++i)expected_releases+=get<std::uint16_t>(ram.data(),destination+4+2*i)!=0;
  bank.clear_scene_families();call(ram.data(),0x1b1e50,0);compare(bank,ram,destination);
  check(bank.zero_header_known()&&bank.first_track()==0&&bank.track_count()==0&&bank.kind()==previous.kind(),"scene release preserves type with a known zero range");check(releases-count_before==expected_releases,"scene release retires every nonreserved token");
  bool reserved_live{};for(unsigned i=0;i<2000;++i){check(bank.rows()[i]==0&&bank.slots()[i]==(i<5?previous.slots()[i]:nullptr),"all logical rows clear while reserved five tokens survive");if(i<5)reserved_live|=bool(bank.slots()[i]);}
  check(bank.cleared()==!reserved_live,"known zero header is distinct from complete token retirement");
  if(reserved_live)++reserved_live_cases;
  for(unsigned key=0;key<(kind?1000u:2000u);++key)for(unsigned track=0;track<5;++track){const auto slot=kind?200u*(key/100)+track:track;const auto token=get<std::uint16_t>(ram.data(),destination+4+2*slot);check(bank.find(key,std::uint16_t(track))==bank.slots()[slot]&&bool(bank.find(key,std::uint16_t(track)))==bool(token),"zero range still resolves the source reserved token formula");++reserved_queries;}
  const auto prior_releases=releases;bank.clear_scene_families();call(ram.data(),0x1b1e50,0);check(releases==prior_releases,"repeated scene release preserves reserved tokens without another release");++scene_family_cases;
 }
 a::MotionBank unknown;bool refused{};try{unknown.clear_scene_families();}catch(const std::out_of_range&){refused=true;}check(refused&&!unknown.zero_header_known(),"scene cleanup refuses unknown source header/type instead of inventing an empty bank");++refusal_cases;
 check(reserved_live_cases>0,"actual owned scene data retains live reserved tokens under a zero header");
}
void family_clear_tests(const std::vector<std::vector<std::byte>>& assets,std::vector<std::uint8_t>& ram){
 constexpr unsigned destination=0x200000;
 for(unsigned kind=0;kind<3;++kind)for(unsigned family=0;family<3;++family){
  std::fill_n(ram.data()+destination,0x1f44,0);a::MotionBank bank;
  for(unsigned asset=0;asset<2;++asset){current_asset=asset;const auto& bytes=assets[asset];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());bank.load_sparse(bytes,8,std::uint8_t(asset),std::to_string(asset));call(ram.data(),0x1d1940,raw_base,destination,unsigned(bytes.size()),asset);}
  if(kind){current_asset=2;const auto& bytes=assets[2];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());bank.load_strided(bytes,kind==2?500:200,0,"2");call(ram.data(),kind==2?0x1d1990:0x1d1960,raw_base,destination,unsigned(bytes.size()),200);}
  compare(bank,ram,destination);const auto before=bank;const auto old_releases=releases;
  const unsigned row_begin=get<std::uint16_t>(ram.data(),0x234410+8*family),row_end=row_begin+get<std::uint16_t>(ram.data(),0x234412+8*family);
  const unsigned token_begin=get<std::uint16_t>(ram.data(),0x234414+8*family),token_end=token_begin+get<std::uint16_t>(ram.data(),0x234416+8*family);
  unsigned expected{};for(unsigned i=token_begin;i<token_end;++i)expected+=get<std::uint16_t>(ram.data(),destination+4+2*i)!=0;
  bank.clear_family(std::uint8_t(family));call(ram.data(),0x1b1c20,destination,family);compare(bank,ram,destination);
  check(bank.first_track()==before.first_track()&&bank.track_count()==before.track_count()&&bank.kind()==before.kind()&&bank.cleared()==before.cleared(),"partial family release preserves exact header/admission");
  check(releases-old_releases==expected,"original family releases exactly its live token range");
  for(unsigned i=0;i<2000;++i){check(bank.slots()[i]==(i>=token_begin&&i<token_end?nullptr:before.slots()[i]),"partial family preserves outside slot leases");check(bank.rows()[i]==(i>=row_begin&&i<row_end?0:before.rows()[i]),"partial family preserves outside logical rows");}
  bank.clear_family(std::uint8_t(family));call(ram.data(),0x1b1c20,destination,family);check(releases-old_releases==expected,"repeated family release has no live tokens");
  for(auto invalid:{std::uint8_t(3),std::uint8_t(255)}){const auto retained=bank;bool refused{};try{bank.clear_family(invalid);}catch(const std::out_of_range&){refused=true;}check(refused&&std::equal(retained.rows().begin(),retained.rows().end(),bank.rows().begin())&&std::equal(retained.slots().begin(),retained.slots().end(),bank.slots().begin()),"unknown family refuses before mutation");++refusal_cases;}
  ++family_clear_cases;
 }
 a::MotionBank unknown;unknown.clear_family(0);bool refused{};try{(void)unknown.find(0,0);}catch(const std::out_of_range&){refused=true;}check(refused&&!unknown.cleared(),"partial release cannot invent a default header profile");
}
void clear_tests(const std::vector<std::vector<std::byte>>& assets,std::vector<std::uint8_t>& ram){
 constexpr unsigned destination=0x200000;
 for(unsigned kind=0;kind<3;++kind){
  a::MotionBank bank;current_asset=kind?2u:0u;const auto& bytes=assets[current_asset];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());std::fill_n(ram.data()+destination,0x1f44,0);
  if(kind==0){bank.load_sparse(bytes,8,0,"0");call(ram.data(),0x1d1940,raw_base,destination,unsigned(bytes.size()),0);}
  else{bank.load_strided(bytes,kind==2?500:200,0,"2");call(ram.data(),kind==2?0x1d1990:0x1d1960,raw_base,destination,unsigned(bytes.size()),200);}
  compare(bank,ram,destination);check(!bank.cleared(),"loaded bank is not cleared");const auto retained=bank;const auto old_kind=bank.kind();auto held=std::find_if(bank.slots().begin(),bank.slots().end(),[](const auto& slot){return bool(slot);});check(held!=bank.slots().end(),"owned release input has live block");const auto block=*held;const auto data=std::vector<std::byte>(block->bytes().begin(),block->bytes().end());
  const auto old_releases=releases;unsigned expected{};for(unsigned i=0;i<2000;++i)expected+=get<std::uint16_t>(ram.data(),destination+4+2*i)!=0;
  bank.clear();call(ram.data(),0x1b1bc0,destination);compare(bank,ram,destination);check(bank.cleared()&&bank.kind()==old_kind&&releases-old_releases==expected,"complete release clears every token and preserves type");
  check(std::equal(data.begin(),data.end(),block->bytes().begin(),block->bytes().end())&&std::any_of(retained.slots().begin(),retained.slots().end(),[](const auto& slot){return bool(slot);}),"retained snapshot and block survive release");++lifetime_cases;
  for(unsigned key=0;key<(kind?1000u:2000u);++key)for(unsigned track=0;track<5;++track){const auto slot=kind?200u*(key/100)+track:track;check(!bank.find(key,std::uint16_t(track))&&get<std::uint16_t>(ram.data(),destination+4+2*slot)==0,"cleared lookup has an actual zero token");++cleared_queries;}
  bank.clear();call(ram.data(),0x1b1bc0,destination);check(releases-old_releases==expected,"repeated release has no live tokens");++clear_cases;
 }
 auto bank=a::MotionBank::cleared_bank();std::fill_n(ram.data()+destination,0x1f44,0xa5);call(ram.data(),0x1b2130,destination);compare(bank,ram,destination);check(bank.cleared()&&bank.kind()==a::MotionBankKind::strided&&!bank.find(0,0),"fresh clear has type zero rather than default sparse type");++clear_cases;
 bool refused{};try{(void)a::MotionBank{}.find(0,0);}catch(const std::out_of_range&){refused=true;}check(refused,"unknown default header stays unavailable");++refusal_cases;
 refused=false;try{(void)bank.find(1000,0);}catch(const std::out_of_range&){refused=true;}check(refused,"out-of-capacity strided lookup refuses adjacent row-map alias");++refusal_cases;
 refused=false;try{(void)a::MotionBank::cleared_bank(static_cast<a::MotionBankKind>(255));}catch(const std::invalid_argument&){refused=true;}check(refused,"unknown cleared type refused");++refusal_cases;
 auto bad=assets[0];std::uint32_t width{};std::memcpy(bad.data()+4,&width,4);refused=false;try{bank.load_sparse(bad,8,0,"bad");}catch(const std::invalid_argument&){refused=true;}check(refused&&bank.cleared()&&!bank.find(0,0),"failed reload preserves known cleared bank");++refusal_cases;
 current_asset=0;const auto& bytes=assets[0];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());bank.load_sparse(bytes,8,0,"0");call(ram.data(),0x1d1940,raw_base,destination,unsigned(bytes.size()),0);compare(bank,ram,destination);check(!bank.cleared(),"real reload replaces cleared admission");
}
int main(int argc,char** argv)try{
 check(argc==2,"whole owned bank package required");std::vector<std::uint8_t> ram(0x2000000);constants(ram.data());put(ram.data(),0x32440c,raw_base);const auto assets=load(argv[1]);std::array<a::MotionBank,2> native;std::shared_ptr<const a::MotionBlock> retained;
 for(unsigned cycle=0;cycle<5;++cycle){current_asset=cycle%2;const auto& bytes=assets[current_asset];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());const auto mode=cycle?1u:0u;native[0].load_sparse(bytes,8,std::uint8_t(mode),std::to_string(current_asset));native[1].load_sparse(bytes,168,std::uint8_t(mode),std::to_string(current_asset));call(ram.data(),0x1d19d0,raw_base,std::uint32_t(bytes.size()),mode);compare(native[0],ram,0x4e8970);compare(native[1],ram,0x4e6a20);if(!retained)for(const auto& block:native[0].slots())if(block){retained=block;break;}check(retained&&!retained->bytes().empty(),"native raw-block lease survives bank overwrite");++lifetime_cases;}
 // Real cutscene-format assets use the actual strided construction path; no
 // room identity is inferred from a duplicate basename in the archive.
 for(current_asset=2;current_asset<assets.size();++current_asset){for(unsigned kind=0;kind<2;++kind){const auto& bytes=assets[current_asset];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());constexpr std::uint32_t destination=0x200000;std::fill_n(ram.data()+destination,0x1f44,0);a::MotionBank bank;bank.load_strided(bytes,kind?500:200,0,std::to_string(current_asset));if(kind)call(ram.data(),0x1d1990,raw_base,destination,std::uint32_t(bytes.size()));else call(ram.data(),0x1d1960,raw_base,destination,std::uint32_t(bytes.size()),200);compare(bank,ram,destination);}}
 {current_asset=0;const auto& bytes=assets[0];std::memcpy(ram.data()+raw_base,bytes.data(),bytes.size());constexpr std::uint32_t destination=0x200000;std::fill_n(ram.data()+destination,0x1f44,0);a::MotionBank bank;bank.load_sparse(bytes,8,2,"0");call(ram.data(),0x1d1940,raw_base,destination,std::uint32_t(bytes.size()),2);compare(bank,ram,destination);auto held=bank.slots()[5];const auto before=std::vector<std::shared_ptr<const a::MotionBlock>>(bank.slots().begin(),bank.slots().end());auto malformed=bytes;std::uint32_t zero=0;std::memcpy(malformed.data()+4,&zero,4);bool refused{};try{bank.load_sparse(malformed,8,0,"bad-width");}catch(const std::invalid_argument&){refused=true;}check(refused&&std::equal(before.begin(),before.end(),bank.slots().begin()),"malformed asset refuses without replacing existing owned slots");++refusal_cases;refused=false;try{bank.load_sparse(bytes,8,3,"unknown-mode");}catch(const std::invalid_argument&){refused=true;}check(refused&&bank.slots()[5]==held,"unsupported mode retains admitted bank owner");++refusal_cases;}
 {a::MotionBank temporary;temporary.load_sparse(assets[0],8,0,"retained");auto held=temporary.slots()[5];check(held!=nullptr,"real initial sparse row");const auto data=std::vector<std::byte>(held->bytes().begin(),held->bytes().end());temporary=a::MotionBank{};check(std::equal(data.begin(),data.end(),held->bytes().begin(),held->bytes().end()),"immutable raw lease survives native bank destruction");++lifetime_cases;}
 clear_tests(assets,ram);
 family_clear_tests(assets,ram);
 scene_family_tests(assets,ram);
 check(constructed>0&&releases>0&&live_slots>0,"real original allocation/memoization/release and native ownership exercised");std::cout<<"{\"reserved_live_cases\":"<<reserved_live_cases<<",\"scene_family_cases\":"<<scene_family_cases<<",\"reserved_queries\":"<<reserved_queries<<",\"family_clear_cases\":"<<family_clear_cases<<",\"checks\":"<<checks<<",\"bank_cases\":"<<bank_cases<<",\"live_slots\":"<<live_slots<<",\"query_cases\":"<<lookup_cases<<",\"cleared_query_cases\":"<<cleared_queries<<",\"clear_cases\":"<<clear_cases<<",\"packed_block_seam_calls\":"<<constructed<<",\"release_seam_calls\":"<<releases<<",\"refusal_cases\":"<<refusal_cases<<",\"lifetime_cases\":"<<lifetime_cases<<",\"original_calls\":"<<calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
