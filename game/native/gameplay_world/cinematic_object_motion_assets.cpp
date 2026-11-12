#include "cinematic_object_motion_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "cinematic_object_motion_members.inc"
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+=char('a'-'A');return value;}
}
std::span<const CinematicObjectMotionMember> file1_cinematic_object_motion_members()noexcept{return cinematic_object_motion_members;}
CinematicObjectMotionAssets::CinematicObjectMotionAssets(std::shared_ptr<const reo::assets::Source> source):source_(std::move(source)){
    if(!source_)throw std::invalid_argument("Native cinematic object motion archive unavailable");
    const auto root=reo::assets::table(*source_,0,source_->size);
    const auto match=[](const auto& member){return lower(member.name)=="romdata_usa.afs";};
    const auto common=std::find_if(root.entries.begin(),root.entries.end(),match);
    if(common==root.entries.end()||std::find_if(common+1,root.entries.end(),match)!=root.entries.end())throw std::invalid_argument("Native cinematic object motion ROM missing or ambiguous");
    const auto directory=reo::assets::table(*source_,common->offset,common->size);
    if(directory.entries.size()!=1342)throw std::invalid_argument("Native cinematic object motion ROM profile unavailable");
    members_.reserve(directory.entries.size());
    for(const auto& member:directory.entries)members_.push_back({std::uint64_t(common->offset)+member.offset,member.size});
}
CinematicObjectMotionLoad CinematicObjectMotionAssets::read(std::uint16_t scenario,std::uint16_t area,std::shared_ptr<const animation::MotionBank> previous)const{
    CinematicObjectMotionLoad result;result.bank=std::move(previous);
    const auto member=std::find_if(cinematic_object_motion_members.begin(),cinematic_object_motion_members.end(),[&](const auto& value){return value.scenario==scenario&&value.area==area;});
    if(member==cinematic_object_motion_members.end())return result;
    result.member=member->member;const auto input=members_[member->member];
    if(!input.bytes)return result;
    if(input.bytes>32u*1024u*1024u){result.status=CinematicObjectMotionStatus::invalid_asset;return result;}
    std::vector<std::byte> bytes;
    try{bytes.resize(input.bytes);source_->read(input.offset,bytes.size(),bytes.data());}
    catch(const std::bad_alloc&){result.status=CinematicObjectMotionStatus::no_memory;return result;}
    catch(const std::exception&){result.status=CinematicObjectMotionStatus::source_failure;return result;}
    try{
        auto bank=result.bank?std::make_shared<animation::MotionBank>(*result.bank):std::make_shared<animation::MotionBank>();
        std::array<char,96> identity{};std::snprintf(identity.data(),identity.size(),"File1 ROM member %u: motion/demo/r%03u/b%02u.bin",unsigned(member->member),unsigned(scenario),unsigned(area));
        bank->load_strided(bytes,200,0,identity.data());result.bank=std::move(bank);result.status=CinematicObjectMotionStatus::loaded;
    }catch(const std::bad_alloc&){result.status=CinematicObjectMotionStatus::no_memory;}
    catch(const std::exception&){result.status=CinematicObjectMotionStatus::invalid_asset;}
    return result;
}
}
