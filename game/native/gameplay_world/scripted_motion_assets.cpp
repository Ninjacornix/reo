#include "scripted_motion_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_world {
namespace {
#include "scripted_motion_members.inc"
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+=char('a'-'A');return value;}
}
std::span<const ScriptedMotionMember> file1_scripted_motion_members()noexcept{return scripted_motion_members;}
ScriptedMotionAssets::ScriptedMotionAssets(std::shared_ptr<const reo::assets::Source> source):source_(std::move(source)){
    if(!source_)throw std::invalid_argument("Native scripted motion archive source unavailable");
    const auto root=reo::assets::table(*source_,0,source_->size);
    const auto match=[](const auto& entry){return lower(entry.name)=="romdata_usa.afs";};
    const auto common=std::find_if(root.entries.begin(),root.entries.end(),match);
    if(common==root.entries.end()||std::find_if(common+1,root.entries.end(),match)!=root.entries.end())
        throw std::invalid_argument("Native File1 scripted motion archive missing or ambiguous");
    const auto directory=reo::assets::table(*source_,common->offset,common->size);
    if(directory.entries.size()!=1342)throw std::invalid_argument("Native File1 ROM motion member profile differs");
    members_.reserve(directory.entries.size());
    for(const auto& entry:directory.entries)members_.push_back({std::uint64_t(common->offset)+entry.offset,entry.size});
}
ScriptedMotionLoad ScriptedMotionAssets::read(std::uint16_t scenario,std::uint16_t clip,const ScriptedMotionBanks& previous)const{
    ScriptedMotionLoad result;result.banks=previous;
    std::array<std::shared_ptr<const animation::MotionBank>*,3> destinations{&result.banks.mode_one,&result.banks.track_two,&result.banks.other_modes};
    for(unsigned kind=0;kind<destinations.size();++kind){
        const auto entry=std::find_if(scripted_motion_members.begin(),scripted_motion_members.end(),
            [&](const auto& row){return row.scenario==scenario&&row.clip==clip&&row.kind==kind;});
        if(entry==scripted_motion_members.end())continue;
        result.members[kind]=entry->member;const auto& member=members_[entry->member];
        if(!member.bytes)continue;
        if(member.bytes>32u*1024u*1024u){result.status[kind]=ScriptedMotionLoadStatus::invalid_asset;continue;}
        std::vector<std::byte> bytes;
        try{bytes.resize(member.bytes);source_->read(member.offset,bytes.size(),bytes.data());}
        catch(const std::bad_alloc&){result.status[kind]=ScriptedMotionLoadStatus::no_memory;continue;}
        catch(const std::exception&){result.status[kind]=ScriptedMotionLoadStatus::source_failure;continue;}
        try{
            auto bank=*destinations[kind]?std::make_shared<animation::MotionBank>(**destinations[kind]):std::make_shared<animation::MotionBank>();
            std::array<char,96> identity{};
            const auto prefix=kind==2?"hd":"d";
            std::snprintf(identity.data(),identity.size(),"File1 ROM member %u: motion/demo/r%03u/%s%02u%s.bin",
                unsigned(entry->member),unsigned(scenario),prefix,unsigned(clip),kind==1?"face":"");
            bank->load_strided(bytes,200,0,identity.data());
            *destinations[kind]=std::move(bank);result.status[kind]=ScriptedMotionLoadStatus::loaded;
        }catch(const std::bad_alloc&){result.status[kind]=ScriptedMotionLoadStatus::no_memory;}
        catch(const std::exception&){result.status[kind]=ScriptedMotionLoadStatus::invalid_asset;}
    }
    return result;
}
}
