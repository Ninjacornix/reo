#include "actor_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#ifdef REO_NPC_ASSETS_ORIGINAL
#include "reference.hpp"
#endif
namespace w=reo::native::gameplay_world;
namespace {
std::uint64_t checks{},name_cases{},assets_loaded{},skeletons{},parts{},hp_assets{},shared_assets{},auxiliary_assets{},auxiliary_names{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Native NPC asset check "+std::to_string(at.line()));
}
void contracts(){
    check(w::ActorAssets::npc_model_name(0,0)=="N00.NBD"&&w::ActorAssets::npc_model_name(90,1)=="HN90.NBD");
    check(w::ActorAssets::npc_model_name(65535,255)=="N255.NBD"&&w::ActorAssets::npc_model_name(0x1067,1)=="HN103.NBD");
    check(w::ActorAssets::substituted_model_name(1,0,255)=="N00.NBD"&&w::ActorAssets::substituted_model_name(11,2,255)=="N10.NBD");
    check(w::ActorAssets::substituted_model_name(65535,255,0)=="N65534.NBD"&&w::ActorAssets::substituted_model_name(1,1,255)=="HP255.NBD");
    bool refused=false;try{(void)w::ActorAssets::substituted_model_name(0,1,0);}catch(const std::invalid_argument&){refused=true;}check(refused);
}
void auxiliary_owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);w::ActorAssets assets(source);std::ifstream rows(manifest);check(bool(rows));
    unsigned identity{},model_class{},nodes{},part_count{};std::string name;std::uint64_t offset{};std::size_t length{};
    while(rows>>identity>>model_class>>name>>offset>>length>>nodes>>part_count){
        const auto asset=assets.read_npc(std::uint16_t(identity+0x100u),std::uint8_t(model_class));
        check(asset&&asset->name()==name&&asset->bytes().size()==length&&asset->part_count()==part_count);
        std::vector<std::byte> expected(length);source->read(offset,length,expected.data());check(std::memcmp(asset->bytes().data(),expected.data(),length)==0);
        check(assets.read_npc(std::uint16_t(identity),std::uint8_t(model_class))==asset);
        const auto model=asset->make_instance();check(model&&model->nodes().size()==nodes);model->rebuild(reo::native::transform_math::identity());check(model->retain()&&model->retain()->joints.size()==nodes);++auxiliary_assets;
    }
    check(rows.eof()&&auxiliary_assets==233);
    // Missing N88 must not silently select HN88 or the one-based N87 route.
    bool refused=false;try{(void)assets.read_npc(88,0);}catch(const std::invalid_argument&){refused=true;}check(refused);
    check(assets.read_npc(88,1)->name()=="HN88.NBD");
}
void owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);w::ActorAssets assets(source);std::ifstream rows(manifest);check(bool(rows));
    unsigned variant{},definition{},character{},nodes{},part_count{};std::string name;std::uint64_t offset{};std::size_t length{};
    while(rows>>variant>>definition>>character>>name>>offset>>length>>nodes>>part_count){
        const auto asset=assets.read_substituted_model(std::uint16_t(variant),std::uint8_t(definition),std::uint8_t(character));
        check(asset&&asset->name()==name&&asset->bytes().size()==length&&asset->part_count()==part_count);
        std::vector<std::byte> expected(length);source->read(offset,length,expected.data());check(std::memcmp(asset->bytes().data(),expected.data(),length)==0);
        check(assets.read_substituted_model(std::uint16_t(variant),std::uint8_t(definition),std::uint8_t(character))==asset);
        auto first=asset->make_instance(),second=asset->make_instance();check(bool(first)==bool(nodes)&&bool(second)==bool(nodes));
        if(first){check(first!=second&&first->nodes().size()==nodes);first->rebuild(reo::native::transform_math::identity());check(first->retain()&&first->retain()->joints.size()==nodes);++skeletons;}
        if(definition==1)++hp_assets;
        // Ordinary table entries selecting an NPC bundle use the same retained
        // archive member/cache, rather than a second mutable asset copy.
        bool shared=false;
        for(unsigned type=0;type<62&&!shared;++type)for(unsigned index=0;index<100&&!shared;++index){
            try{const auto& model=w::File1LinkedModelProfiles{}.definition(std::uint8_t(type),std::uint16_t(index));
                if(model.model!=255&&w::ActorAssets::model_name(model.model,w::ModelDefinitionBank::ordinary)==name){check(assets.read(std::uint8_t(type),std::uint16_t(index))==asset);shared=true;++shared_assets;}
            }catch(const std::out_of_range&){}
        }
        parts+=part_count;++assets_loaded;
    }
    check(rows.eof()&&assets_loaded==133&&hp_assets==8&&shared_assets>0);
    bool missing=false;try{(void)assets.read_substituted_model(65535,0,0);}catch(const std::invalid_argument&){missing=true;}check(missing);
}
}
#ifdef REO_NPC_ASSETS_ORIGINAL
#include "npc_actor_asset_reference_tests.inc"
#endif
int main(int argc,char** argv)try{
    contracts();
#ifdef REO_NPC_ASSETS_ORIGINAL
    original_names();original_auxiliary_names();
#endif
    if(argc==3||argc==4){owned(argv[1],argv[2]);if(argc==4)auxiliary_owned(argv[1],argv[3]);}else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"name_cases\":"<<name_cases<<",\"assets\":"<<assets_loaded<<",\"skeletons\":"<<skeletons<<",\"hp_assets\":"<<hp_assets<<",\"parts\":"<<parts<<",\"shared_assets\":"<<shared_assets<<",\"auxiliary_assets\":"<<auxiliary_assets<<",\"auxiliary_names\":"<<auxiliary_names<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
