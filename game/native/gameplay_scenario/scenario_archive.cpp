#include "scenario_archive.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdio>
#include <stdexcept>

namespace reo::native::gameplay_scenario::content {
namespace {
constexpr std::array<std::uint16_t,5> scenario_ids{1,2,28,35,41};
constexpr std::size_t maximum_member_bytes = 32 * 1024 * 1024;
std::uint32_t sector_extent(std::uint64_t offset,std::uint32_t bytes,std::uint64_t parent)noexcept{
    const auto rounded=(std::uint64_t(bytes)+2047u)&~std::uint64_t(2047u);
    return offset<=parent&&rounded<=parent-offset&&rounded<=UINT32_MAX?std::uint32_t(rounded):0;
}

std::string lower_name(std::string_view name) {
    std::string result(name);
    for (char& character : result) {
        if (character >= 'A' && character <= 'Z') character += 'a' - 'A';
    }
    return result;
}
}

ScenarioArchive::ScenarioArchive(std::shared_ptr<const reo::assets::Source> archive)
    : archive_(std::move(archive)) {
    if (!archive_) throw std::invalid_argument("Scenario archive source is unavailable");
    const auto root = reo::assets::table(*archive_,0,archive_->size);
    for (std::size_t index = 0; index < scenario_ids.size(); ++index) {
        std::array<char,16> name{};
        std::snprintf(name.data(),name.size(),"r%03u.afs",unsigned(scenario_ids[index]));
        const auto match = [&](const auto& entry) { return lower_name(entry.name) == name.data(); };
        const auto source = std::find_if(root.entries.begin(),root.entries.end(),match);
        if (source == root.entries.end() || std::find_if(source+1,root.entries.end(),match) != root.entries.end())
            throw std::invalid_argument("Missing or ambiguous File #1 scenario archive");
        const auto contents = reo::assets::table(*archive_,source->offset,source->size);
        auto& members = members_[index];
        members.reserve(contents.entries.size());
        for (const auto& entry : contents.entries) {
            if (!entry.name.empty())
                members.push_back({lower_name(entry.name),std::uint64_t(source->offset)+entry.offset,entry.size,sector_extent(entry.offset,entry.size,source->size)});
        }
        std::stable_sort(members.begin(),members.end(),[](const Member& a,const Member& b) { return a.name < b.name; });
        std::snprintf(name.data(),name.size(),"r%03u_h.bin",unsigned(scenario_ids[index]));
        const auto header_match=[&](const auto& entry){return lower_name(entry.name)==name.data();};
        const auto header=std::find_if(root.entries.begin(),root.entries.end(),header_match);
        if(header==root.entries.end())continue;
        if(std::find_if(header+1,root.entries.end(),header_match)!=root.entries.end()||header->size<8||header->size>maximum_member_bytes)
            throw std::invalid_argument("Scenario resource index unavailable or ambiguous");
        std::vector<std::uint8_t> raw(header->size);archive_->read(header->offset,raw.size(),raw.data());
        const auto first=reo::assets::u32(raw.data()),count=reo::assets::u32(raw.data()+4);
        if(first>contents.entries.size()||count>contents.entries.size()-first||count>(raw.size()-8)/16||raw.size()!=8ull+16ull*count)
            throw std::invalid_argument("Scenario resource index extent unavailable");
        auto& resources=resources_[index];resources.reserve(count);
        for(std::size_t ordinal=0;ordinal<count;++ordinal){
            const auto* start=reinterpret_cast<const char*>(raw.data()+8+16*ordinal);
            const auto end=std::find(start,start+16,'\0');const auto& entry=contents.entries[first+ordinal];
            resources.push_back({std::string(start,end),std::uint64_t(source->offset)+entry.offset,entry.size,sector_extent(entry.offset,entry.size,source->size)});
        }
        std::stable_sort(resources.begin(),resources.end(),[](const Member& a,const Member& b){return a.name<b.name;});
    }
}

Bytes ScenarioArchive::read_member(std::uint16_t scenario,std::string_view name) const {
    const auto id = std::find(scenario_ids.begin(),scenario_ids.end(),scenario);
    if (id == scenario_ids.end() || name.empty() || name.size() > 32) return {};
    const auto& members = members_[std::size_t(id - scenario_ids.begin())];
    const auto key = lower_name(name);
    const auto member = std::lower_bound(members.begin(),members.end(),key,
        [](const Member& member,const std::string& key) { return member.name < key; });
    if (member == members.end() || member->name != key || member->size == 0) return {};
    if (member+1 != members.end() && (member+1)->name == key)
        throw std::invalid_argument("Ambiguous scenario archive member");
    return read(*member);
}

Bytes ScenarioArchive::read(const Member& member)const{
    if(!member.size)return{};
    if(member.size>maximum_member_bytes)throw std::invalid_argument("Scenario archive member exceeds limit");
    auto bytes=std::make_shared<std::vector<std::byte>>(member.size);
    archive_->read(member.offset,bytes->size(),bytes->data());
    return bytes;
}

const ScenarioArchive::Member* ScenarioArchive::resource(std::uint16_t scenario,std::string_view name)const{
    const auto id=std::find(scenario_ids.begin(),scenario_ids.end(),scenario);
    if(id==scenario_ids.end()||name.empty()||name.size()>255||name.find('\0')!=name.npos)return{};
    //1A9D70 selects the suffix after the last forward slash; it looks for a
    // backslash only when no forward slash exists. Preserve mixed-path order.
    auto slash=name.rfind('/');if(slash==name.npos)slash=name.rfind('\\');
    if(slash!=name.npos)name.remove_prefix(slash+1);
    if(name.empty()||name.size()>16)return{};
    std::string key(name);
    for(char& c:key){
        if(c<' '||static_cast<unsigned char>(c)>126)return{};
        if(c>='a'&&c<='z')c+='A'-'a';
        if(c=='\\'||c=='/'||c=='.'||c==':')c='_';
    }
    const auto& resources=resources_[std::size_t(id-scenario_ids.begin())];
    const auto member=std::lower_bound(resources.begin(),resources.end(),key,[](const Member& value,const std::string& key){return value.name<key;});
    return member==resources.end()||member->name!=key?nullptr:&*member;
}
Bytes ScenarioArchive::read_resource(std::uint16_t scenario,std::string_view name)const{
    const auto member=resource(scenario,name);return member?read(*member):Bytes{};
}
Bytes ScenarioArchive::read_resource_sectors(std::uint16_t scenario,std::string_view name)const{
    const auto member=resource(scenario,name);if(!member||!member->size)return{};
    if(!member->storage_bytes)throw std::invalid_argument("Scenario resource sector extent unavailable");
    if(member->storage_bytes>maximum_member_bytes)throw std::invalid_argument("Scenario resource sectors exceed limit");
    auto bytes=std::make_shared<std::vector<std::byte>>(member->storage_bytes);archive_->read(member->offset,bytes->size(),bytes->data());return bytes;
}

std::optional<ScriptBank> ScenarioArchive::scenario_scripts(std::uint16_t scenario) const {
    std::array<char,16> name{};
    std::snprintf(name.data(),name.size(),"r%03u.evb",unsigned(scenario));
    auto bytes = read_member(scenario,name.data());
    if (!bytes) return {};
    return ScriptBank(std::move(bytes),BankFormat::scenario_evb);
}

std::optional<RdtDirectory> ScenarioArchive::room(RoomId id) const {
    if (id.room > 99 || id.variant > 99) return {};
    std::array<char,20> name{};
    std::snprintf(name.data(),name.size(),"r%03u%02u%02u.rdt",unsigned(id.scenario),unsigned(id.room),unsigned(id.variant));
    auto bytes = read_member(id.scenario,name.data());
    if (!bytes) return {};
    return RdtDirectory(std::move(bytes));
}
}
