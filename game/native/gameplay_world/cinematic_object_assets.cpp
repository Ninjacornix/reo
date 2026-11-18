#include "cinematic_object_assets.hpp"
#include "model_parts.hpp"
#include "../animation/constraint_math.hpp"
#include <bit>
#include <cstdio>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
std::uint32_t word(std::span<const std::byte> bytes,unsigned at){
    if(at>bytes.size()||4>bytes.size()-at)throw std::invalid_argument("Native cinematic object bundle header unavailable");
    std::uint32_t result;std::memcpy(&result,bytes.data()+at,4);return result;
}
std::span<const std::byte> section(std::span<const std::byte> bytes,unsigned at){
    const auto offset=word(bytes,at),size=word(bytes,at+4);
    if(!offset)return{};
    if(!size||offset>bytes.size()||size>bytes.size()-offset)throw std::invalid_argument("Native cinematic object bundle section unavailable");
    return bytes.subspan(offset,size);
}
}
std::shared_ptr<const CinematicObjectAsset> CinematicObjectAsset::import(std::string name,gameplay_scenario::content::Bytes bytes){
    if(!bytes||bytes->size()<48||bytes->size()>32u*1024u*1024u)throw std::invalid_argument("Native cinematic object bundle extent unavailable");
    auto result=std::shared_ptr<CinematicObjectAsset>(new CinematicObjectAsset);result->name_=std::move(name);result->bytes_=std::move(bytes);
    const auto model=section(*result->bytes_,0x14);
    if(!model.empty()){
        const auto parts=model_part_count(model),materials=model_material_count(model);
        if(parts>65535||materials>65535)throw std::out_of_range("Native cinematic object part/material count unavailable");
        result->parts_=std::uint16_t(parts);result->materials_=std::uint16_t(materials);
    }
    const auto skeleton=section(*result->bytes_,0x24);
    if(!skeleton.empty()){
        result->skeleton_=animation::Skeleton::import_raw(skeleton);
        if(result->skeleton_->nodes().size()>32)throw std::out_of_range("Native cinematic object first-root node profile unavailable");
        animation::Instance rest(result->skeleton_);rest.rebuild(transform_math::identity());
        result->inverse_bind_pose_.reserve(rest.nodes().size());
        for(const auto& node:rest.nodes())result->inverse_bind_pose_.push_back(animation::constraint_math::inverse_scaled(node.world));
    }
    return result;
}
std::shared_ptr<animation::Instance> CinematicObjectAsset::make_instance()const{
    return skeleton_?std::make_shared<animation::Instance>(skeleton_):nullptr;
}
CinematicObjectAssets::CinematicObjectAssets(std::shared_ptr<const gameplay_scenario::content::ScenarioArchive> archive):archive_(std::move(archive)){
    if(!archive_)throw std::invalid_argument("Native cinematic object archive unavailable");
}
std::string CinematicObjectAssets::model_name(gameplay_scenario::CutsceneCue cue,std::uint32_t model){
    if(cue.variant>25)throw std::out_of_range("Native cinematic object request suffix unavailable");
    std::array<char,64> name{};const auto count=std::snprintf(name.data(),name.size(),"obj%02u_%02u_%c_%02d.nbd",unsigned(cue.area),unsigned(cue.scene),int('a'+cue.variant),std::bit_cast<std::int32_t>(model));
    if(count<=0||std::size_t(count)>=name.size())throw std::out_of_range("Native cinematic object name extent unavailable");
    return name.data();
}
std::shared_ptr<const CinematicObjectAsset> CinematicObjectAssets::read(std::uint16_t destination,gameplay_scenario::CutsceneCue cue,std::uint32_t model)const{
    const auto name=model_name(cue,model);const auto key=std::pair{destination,name};
    {std::lock_guard guard(mutex_);const auto found=cache_.find(key);if(found!=cache_.end())return found->second;}
    //1AAAD0 explicitly terminates its basename at16 bytes before1A9D70
    // resolves the scenario header's ordinal key. Display names are separate.
    const auto bytes=archive_->read_resource(destination,std::string_view(name).substr(0,16));if(!bytes)return{};
    const auto asset=CinematicObjectAsset::import(name,bytes);
    std::lock_guard guard(mutex_);return cache_.try_emplace(key,asset).first->second;
}
}
