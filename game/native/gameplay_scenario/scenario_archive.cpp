#include "scenario_archive.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdio>
#include <stdexcept>

namespace reo::native::gameplay_scenario::content {
namespace {
constexpr std::array<std::uint16_t,5> scenario_ids{1,2,28,35,41};
constexpr std::size_t maximum_member_bytes = 32 * 1024 * 1024;

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
                members.push_back({lower_name(entry.name),std::uint64_t(source->offset)+entry.offset,entry.size});
        }
        std::stable_sort(members.begin(),members.end(),[](const Member& a,const Member& b) { return a.name < b.name; });
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
    if (member->size > maximum_member_bytes) throw std::invalid_argument("Scenario archive member exceeds limit");
    auto bytes = std::make_shared<std::vector<std::byte>>(member->size);
    archive_->read(member->offset,bytes->size(),bytes->data());
    return bytes;
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
