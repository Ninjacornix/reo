#include "game/native/gameplay_scenario/facial_assets.hpp"
#include "game/native/animation/facial_curves.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},bytes_checked{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Facial asset line "+std::to_string(at.line()));
}
int main(int argc,char** argv)try{
    check(argc==3);auto source=std::make_shared<reo::assets::Source>(argv[1]);s::File1FacialAssets assets(source);
    std::ifstream manifest(argv[2]);std::ifstream original(argv[1],std::ios::binary);
    unsigned kind,character,scenario,cue,voice,speaker,logical,storage;std::uint64_t offset;unsigned count{};
    std::vector<std::shared_ptr<const std::vector<std::byte>>> leases;
    while(manifest>>kind>>character>>scenario>>cue>>voice>>speaker>>offset>>logical>>storage){
        const auto selected=kind==2?assets.lip(std::uint16_t(scenario),std::uint16_t(cue),std::uint16_t(voice),speaker):assets.matrix(kind?s::FacialMatrixKind::npc:s::FacialMatrixKind::player,std::uint16_t(character));
        check(bool(selected.storage)&&selected.logical_bytes==logical&&selected.storage->size()==storage);
        std::vector<std::byte> expected(storage);original.seekg(std::streamoff(offset));original.read(reinterpret_cast<char*>(expected.data()),storage);check(bool(original));
        for(unsigned index=0;index<storage;++index){check(expected[index]==(*selected.storage)[index]);++bytes_checked;}
        if(kind==2){const auto curves=reo::native::animation::FacialCurves::import(*selected.storage);for(unsigned channel=0;channel<5;++channel)check(curves->channel(channel).size()>=2);}
        else check(storage==4096&&logical==3072);
        leases.push_back(selected.storage);++count;
    }
    check(manifest.eof()&&count==51);for(unsigned id=0;id<512;++id){
        const auto player=assets.matrix(s::FacialMatrixKind::player,std::uint16_t(id));check(bool(player.storage)==(id<8));
        const auto npc=assets.matrix(s::FacialMatrixKind::npc,std::uint16_t(id));
        check(bool(npc.storage)==(id==29||id==34||id==39||id==46||id==54||id==57||id==62||id==100||id==103||id==106));
        check(!assets.lip(65535,std::uint16_t(id),65535,65535).storage);
    }
    source.reset();for(const auto& lease:leases)check(lease&&!lease->empty());
    bool refused=false;try{s::File1FacialAssets missing(nullptr);}catch(const std::invalid_argument&){refused=true;}check(refused);
    std::cout<<"{\"checks\":"<<checks<<",\"assets\":"<<count<<",\"sector_bytes_compared\":"<<bytes_checked<<",\"retained_leases\":"<<leases.size()<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
