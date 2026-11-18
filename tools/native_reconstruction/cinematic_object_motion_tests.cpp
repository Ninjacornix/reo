#include "game/native/gameplay_world/cinematic_object_motion_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
std::uint64_t checks{},loads{},blocks{},loader_cases{},original_calls{},releases{},retained_slots{},fault_cases{};
std::string location;
constexpr unsigned raw_base=0x800000,bank_at=0x4baef0;
unsigned selected_scenario{},selected_area{},selected_member{},pending_offset{};
int read_result{};
std::vector<std::byte> selected_raw;
struct Token {unsigned member{},offset{};};
std::vector<Token> tokens(1);
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error(std::string(at.file_name())+":"+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* memory,unsigned at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,unsigned at,T value){transform_write(memory,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;const auto a0=GPR_U32(context,4),a1=GPR_U32(context,5),a2=GPR_U32(context,6),a3=GPR_U32(context,7);
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x10a830:check(a2==selected_scenario&&a3==selected_area);SET_GPR_U32(context,2,std::snprintf(reinterpret_cast<char*>(memory+a0),128,reinterpret_cast<char*>(memory+a1),int(a2),int(a3)));break;
    case 0x1cc8f0:{
        std::array<char,128> name{};std::snprintf(name.data(),name.size(),"data\\rom\\motion\\demo\\r%03u\\b%02u.bin",selected_scenario,selected_area);
        check(name.data()==std::string(reinterpret_cast<char*>(memory+a0))&&a1==raw_base&&a2==1&&a3==0);
        if(read_result>0){check(std::size_t(read_result)==selected_raw.size());std::memcpy(memory+a1,selected_raw.data(),selected_raw.size());}SET_GPR_U32(context,2,std::uint32_t(read_result));break;}
    case 0x1d3550:check(a2>=raw_base&&a2-raw_base<selected_raw.size());pending_offset=a2-raw_base;break;
    case 0x192500:check(tokens.size()<65536);tokens.push_back({selected_member,pending_offset});SET_GPR_U32(context,2,tokens.size()-1);break;
    case 0x1925a0:check(a0>0&&a0<tokens.size());++releases;break;
    default:throw std::runtime_error("undeclared object-motion original call "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void original_load(std::uint8_t* memory){R5900Context c;PS2Runtime runtime;c.pc=0x1d1e00;SET_GPR_U32(&c,4,selected_scenario);SET_GPR_U32(&c,5,selected_area);SET_GPR_U32(&c,6,0xabcdef01);SET_GPR_U32(&c,7,255);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);original_transform_port(memory,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);++loader_cases;}
struct Owned {unsigned scenario{},area{},member{};std::uint64_t offset{};std::vector<std::byte> raw;};
void compare(const a::MotionBank& bank,const std::uint8_t* memory,const std::vector<Owned>& owned){
    check(bank.first_track()==memory[bank_at]&&bank.track_count()==memory[bank_at+1]&&unsigned(bank.kind())==memory[bank_at+2]);
    for(unsigned slot=0;slot<a::MotionBank::capacity;++slot){const auto token=get<std::uint16_t>(memory,bank_at+4+2*slot);const auto block=bank.slots()[slot];check(bool(token)==bool(block));
        if(block){check(token<tokens.size());const auto provenance=tokens[token];const auto found=std::find_if(owned.begin(),owned.end(),[&](const auto& item){return item.member==provenance.member;});check(found!=owned.end());check(block->source_offset()==provenance.offset&&block->bytes().size()<=found->raw.size()-block->source_offset());check(std::memcmp(block->bytes().data(),found->raw.data()+block->source_offset(),block->bytes().size())==0&&block->source_identity().find("ROM member "+std::to_string(found->member)+":")!=std::string::npos);if(found->member!=selected_member)++retained_slots;++blocks;}
    }
}
using File=std::pair<std::string,std::vector<std::uint8_t>>;
template<class T>void write(std::vector<std::uint8_t>& bytes,std::size_t at,T value){check(at<=bytes.size()&&sizeof value<=bytes.size()-at);std::memcpy(bytes.data()+at,&value,sizeof value);}
std::vector<std::uint8_t> afs(std::vector<File> files){
    const auto align=[](std::size_t n){return(n+2047)&~std::size_t(2047);};const auto names=16+8*files.size();std::vector<std::uint8_t> bytes(align(names+48*files.size()));std::memcpy(bytes.data(),"AFS\0",4);write(bytes,4,unsigned(files.size()));write(bytes,8+8*files.size(),unsigned(names));write(bytes,12+8*files.size(),unsigned(48*files.size()));
    for(unsigned i=0;i<files.size();++i){const auto& [name,raw]=files[i];check(name.size()<32);std::memcpy(bytes.data()+names+48*i,name.data(),name.size());const auto offset=bytes.size();bytes.resize(align(offset+raw.size()));write(bytes,8+8*i,unsigned(offset));write(bytes,12+8*i,unsigned(raw.size()));if(!raw.empty())std::memcpy(bytes.data()+offset,raw.data(),raw.size());}return bytes;
}
struct Memory final:reo::assets::PositionedSource {
    const std::vector<std::uint8_t> bytes;mutable std::optional<std::uint64_t> failure;mutable unsigned reads{};
    explicit Memory(std::vector<std::uint8_t> data):bytes(std::move(data)){}
    std::uint64_t size()const noexcept override{return bytes.size();}
    std::size_t read(std::uint64_t at,std::size_t size,void* target)const override{++reads;if(failure==at)throw std::runtime_error("Injected motion read failure");if(at>bytes.size()||size>bytes.size()-at)throw std::runtime_error("Fixture read bounds");std::memcpy(target,bytes.data()+at,size);return size;}
};
std::vector<std::uint8_t> raw_bank(bool present){std::vector<std::uint8_t> bytes(48);write(bytes,4,1u);write(bytes,8,1u);write(bytes,12,16u);write(bytes,16,present?28u:UINT32_MAX);write(bytes,36,20u);return bytes;}
void fault_tests(){
    std::vector<File> files(1342,{"duplicate.bin",{}});files[735]={"b00.bin",raw_bank(true)};
    const auto memory=std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(files)}}));const auto source=std::make_shared<reo::assets::Source>("object motion fixture",memory);w::CinematicObjectMotionAssets assets(source);const auto first=assets.read(1,0);check(first.status==w::CinematicObjectMotionStatus::loaded&&first.member==735&&first.bank);const auto block=first.bank->find(0,0);check(bool(block));
    const auto reads=memory->reads;const auto missing=assets.read(65535,65535,first.bank);check(missing.status==w::CinematicObjectMotionStatus::not_found&&missing.bank==first.bank&&!missing.member&&reads==memory->reads);++fault_cases;
    const auto root=reo::assets::table(*source,0,source->size),rom=reo::assets::table(*source,root.entries[0].offset,root.entries[0].size);memory->failure=std::uint64_t(root.entries[0].offset)+rom.entries[735].offset;const auto failed=assets.read(1,0,first.bank);check(failed.status==w::CinematicObjectMotionStatus::source_failure&&failed.bank==first.bank&&failed.member==735&&first.bank->find(0,0)==block);++fault_cases;
    for(unsigned mode=0;mode<3;++mode){files[735].second=mode==0?raw_bank(false):mode==1?std::vector<std::uint8_t>(3):std::vector<std::uint8_t>{};const auto replacement=std::make_shared<reo::assets::Source>("replacement object motion",std::make_shared<Memory>(afs({{"romdata_usa.afs",afs(files)}})));const auto changed=w::CinematicObjectMotionAssets(replacement).read(1,0,first.bank);
        check(changed.member==735);if(mode==0)check(changed.status==w::CinematicObjectMotionStatus::loaded&&changed.bank!=first.bank&&changed.bank->find(0,0)==block);else check(changed.bank==first.bank&&changed.status==(mode==1?w::CinematicObjectMotionStatus::invalid_asset:w::CinematicObjectMotionStatus::not_found));check(first.bank->find(0,0)==block);++fault_cases;
    }
    bool refused{};try{w::CinematicObjectMotionAssets invalid({});}catch(const std::invalid_argument&){refused=true;}check(refused);++fault_cases;
}
int main(int argc,char** argv)try{
    check(argc==3);std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());put(memory.data(),0x32440c,raw_base);
    const auto source=std::make_shared<reo::assets::Source>(argv[1]);w::CinematicObjectMotionAssets assets(source);std::ifstream manifest(argv[2]);check(bool(manifest));std::vector<Owned> owned;unsigned scenario{},area{},member{},length{};std::uint64_t offset{};
    while(manifest>>scenario>>area>>member>>offset>>length){Owned item{scenario,area,member,offset,std::vector<std::byte>(length)};source->read(offset,length,item.raw.data());owned.push_back(std::move(item));}check(manifest.eof()&&owned.size()==52&&w::file1_cinematic_object_motion_members().size()==52);
    for(unsigned sequence=0;sequence<2;++sequence){std::shared_ptr<const a::MotionBank> previous;std::fill_n(memory.data()+bank_at,0x1f44,0);tokens.resize(1);
        for(const auto& item:owned){location="object motion "+std::to_string(item.scenario)+"/"+std::to_string(item.area);selected_scenario=item.scenario;selected_area=item.area;selected_member=item.member;selected_raw=item.raw;read_result=int(item.raw.size());if(!sequence){previous.reset();std::fill_n(memory.data()+bank_at,0x1f44,0);tokens.resize(1);}const auto old=previous;const auto loaded=assets.read(std::uint16_t(item.scenario),std::uint16_t(item.area),previous);check(loaded.status==w::CinematicObjectMotionStatus::loaded&&loaded.bank&&loaded.member==item.member&&loaded.bank!=old);original_load(memory.data());compare(*loaded.bank,memory.data(),owned);previous=loaded.bank;++loads;
            for(int result:{0,-1}){read_result=result;std::array<std::byte,0x1f44> snapshot;std::memcpy(snapshot.data(),memory.data()+bank_at,snapshot.size());original_load(memory.data());check(std::memcmp(snapshot.data(),memory.data()+bank_at,snapshot.size())==0);}
        }
    }
    check(retained_slots>0);fault_tests();std::cout<<"{\"checks\":"<<checks<<",\"loads\":"<<loads<<",\"live_blocks\":"<<blocks<<",\"loader_cases\":"<<loader_cases<<",\"retained_slots\":"<<retained_slots<<",\"fault_cases\":"<<fault_cases<<",\"source_releases\":"<<releases<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<location<<" "<<e.what()<<'\n';return 1;}
