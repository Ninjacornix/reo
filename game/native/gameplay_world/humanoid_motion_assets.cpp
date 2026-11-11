#include "humanoid_motion_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_world {
struct HumanoidMotionRevision {};
namespace {
#include "humanoid_motion_members.inc"
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+=char('a'-'A');return value;}
}
std::span<const HumanoidMotionMember> file1_humanoid_motion_members()noexcept{return humanoid_motion_members;}
NpcMotionBindings HumanoidMotionBanks::npc_bindings()const{
    if(!scripted_.mode_one||!scripted_.other_modes||!alternate_style_||!characters_[3]||!characters_[5])throw std::runtime_error("Native NPC motion content owners unavailable");
    return{scripted_.mode_one,{scripted_.other_modes,alternate_style_},characters_};
}
std::shared_ptr<const animation::MotionBank> HumanoidMotionBanks::bank(HumanoidMotionAlias alias)const noexcept{
    if(alias.family==HumanoidMotionFamily::character)return alias.character<characters_.size()?characters_[alias.character]:nullptr;
    if(alias.character)return{};
    switch(alias.family){
    case HumanoidMotionFamily::scene_body:return scripted_.mode_one;
    case HumanoidMotionFamily::scene_face:return scripted_.track_two;
    case HumanoidMotionFamily::general:return scripted_.other_modes;
    case HumanoidMotionFamily::alternate:return alternate_style_;
    case HumanoidMotionFamily::primary:return primary_;
    default:return{};
    }
}
HumanoidMotionAssets::HumanoidMotionAssets(std::shared_ptr<const reo::assets::Source> source):source_(std::move(source)),scripted_(source_){
    const auto root=reo::assets::table(*source_,0,source_->size);
    const auto match=[](const auto& entry){return lower(entry.name)=="romdata_usa.afs";};
    const auto common=std::find_if(root.entries.begin(),root.entries.end(),match);
    if(common==root.entries.end()||std::find_if(common+1,root.entries.end(),match)!=root.entries.end())throw std::invalid_argument("Native humanoid motion archive missing or ambiguous");
    const auto directory=reo::assets::table(*source_,common->offset,common->size);
    if(directory.entries.size()!=1342)throw std::invalid_argument("Native File1 humanoid motion ROM profile differs");
    members_.reserve(directory.entries.size());
    for(const auto& entry:directory.entries)members_.push_back({std::uint64_t(common->offset)+entry.offset,entry.size,lower(entry.name)});
}
std::pair<std::vector<std::byte>,std::string> HumanoidMotionAssets::read(std::uint16_t index,std::uint8_t character)const{
    const auto row=std::find_if(humanoid_motion_members.begin(),humanoid_motion_members.end(),[&](const auto& entry){return entry.index==index&&entry.character==character;});
    if(row==humanoid_motion_members.end())throw std::out_of_range("Native humanoid motion member unavailable");
    const auto& member=members_.at(row->member);
    if(member.name!=lower(std::string(row->name))||!member.bytes||member.bytes>32u*1024u*1024u)throw std::invalid_argument("Native humanoid motion member identity/extent unavailable");
    std::vector<std::byte> bytes(member.bytes);source_->read(member.offset,bytes.size(),bytes.data());
    return{std::move(bytes),"File1 ROM member "+std::to_string(row->member)+": motion/player/"+std::string(row->name)};
}
std::shared_ptr<const HumanoidMotionBanks> HumanoidMotionAssets::base()const{
    auto result=std::shared_ptr<HumanoidMotionBanks>(new HumanoidMotionBanks);
    result->revision_=std::make_shared<const HumanoidMotionRevision>();
    //1B2150/1B2130 initially clear this distinct bank. Common/default and
    // scene loads do not populate it; it is not an alias for scene_body.
    result->primary_=std::make_shared<const animation::MotionBank>(animation::MotionBank::cleared_bank());
    load_defaults(*result);return result;
}
void HumanoidMotionAssets::load_defaults(HumanoidMotionBanks& result)const{
    const auto [bytes,identity]=read(0,255);
    //1D1A80 first executes1B1DF0. This is a real partial bank release,
    // including the character stores, not a temporary I/O-buffer operation.
    clear_base_family(result);
    auto ordinary=result.scripted_.other_modes?std::make_shared<animation::MotionBank>(*result.scripted_.other_modes):std::make_shared<animation::MotionBank>();
    auto alternate=result.alternate_style_?std::make_shared<animation::MotionBank>(*result.alternate_style_):std::make_shared<animation::MotionBank>();
    ordinary->load_sparse(bytes,8,0,identity);alternate->load_sparse(bytes,168,0,identity);
    result.scripted_.other_modes=std::move(ordinary);result.alternate_style_=std::move(alternate);result.base_loaded_=true;
}
void HumanoidMotionAssets::clear_base_family(HumanoidMotionBanks& banks){
    const auto clear=[](std::shared_ptr<const animation::MotionBank>& bank){
        if(!bank)return;
        auto next=std::make_shared<animation::MotionBank>(*bank);next->clear_family(0);bank=std::move(next);
    };
    clear(banks.scripted_.other_modes);clear(banks.alternate_style_);
    for(auto& bank:banks.characters_)clear(bank);
}
std::shared_ptr<const HumanoidMotionBanks> HumanoidMotionAssets::release_base(const HumanoidMotionBanks& previous)const{
    auto result=std::shared_ptr<HumanoidMotionBanks>(new HumanoidMotionBanks(previous));result->parent_=previous.revision_;result->revision_=std::make_shared<const HumanoidMotionRevision>();
    clear_base_family(*result);result->base_loaded_=false;return result;
}
std::shared_ptr<const HumanoidMotionBanks> HumanoidMotionAssets::ensure_base(std::shared_ptr<const HumanoidMotionBanks> previous)const{
    if(!previous)throw std::invalid_argument("Native humanoid motion publication unavailable");
    if(previous->base_loaded_)return previous;
    auto result=std::shared_ptr<HumanoidMotionBanks>(new HumanoidMotionBanks(*previous));result->parent_=previous->revision_;result->revision_=std::make_shared<const HumanoidMotionRevision>();load_defaults(*result);return result;
}
std::shared_ptr<const HumanoidMotionBanks> HumanoidMotionAssets::overlay(std::uint16_t common_index,
    std::span<const std::uint8_t> characters,const HumanoidMotionBanks& previous)const{
    if(!previous.scripted_.other_modes||!previous.alternate_style_)throw std::invalid_argument("Native humanoid base motion owners unavailable");
    for(auto character:characters)if(character>=8)throw std::out_of_range("Native humanoid character motion profile unavailable");
    auto result=std::shared_ptr<HumanoidMotionBanks>(new HumanoidMotionBanks(previous));
    result->parent_=previous.revision_;result->revision_=std::make_shared<const HumanoidMotionRevision>();
    const auto [bytes,identity]=read(common_index,255);
    auto ordinary=std::make_shared<animation::MotionBank>(*previous.scripted_.other_modes),alternate=std::make_shared<animation::MotionBank>(*previous.alternate_style_);
    ordinary->load_sparse(bytes,8,1,identity);alternate->load_sparse(bytes,168,1,identity);
    result->scripted_.other_modes=std::move(ordinary);result->alternate_style_=std::move(alternate);
    for(auto character:characters){
        const auto [character_bytes,character_identity]=read(0,character);
        auto bank=result->characters_[character]?std::make_shared<animation::MotionBank>(*result->characters_[character]):std::make_shared<animation::MotionBank>();
        bank->load_sparse(character_bytes,8,1,character_identity);result->characters_[character]=std::move(bank);
    }
    return result;
}
HumanoidSceneMotionLoad HumanoidMotionAssets::scene(std::uint16_t scenario,std::uint16_t clip,const HumanoidMotionBanks& previous)const{
    const auto loaded=scripted_.read(scenario,clip,previous.scripted_);
    auto result=std::shared_ptr<HumanoidMotionBanks>(new HumanoidMotionBanks(previous));result->parent_=previous.revision_;result->revision_=std::make_shared<const HumanoidMotionRevision>();result->scripted_=loaded.banks;result->base_loaded_=false;
    return{std::move(result),loaded.status,loaded.members};
}
std::shared_ptr<const HumanoidMotionBanks> HumanoidMotionAssets::release_character(std::uint8_t character,const HumanoidMotionBanks& previous)const{
    if(character>=8)throw std::out_of_range("Native humanoid character release profile unavailable");
    auto result=std::shared_ptr<HumanoidMotionBanks>(new HumanoidMotionBanks(previous));result->parent_=previous.revision_;result->revision_=std::make_shared<const HumanoidMotionRevision>();
    auto bank=std::make_shared<animation::MotionBank>(previous.characters_[character]?*previous.characters_[character]:animation::MotionBank::cleared_bank());bank->clear();result->characters_[character]=std::move(bank);return result;
}
}
