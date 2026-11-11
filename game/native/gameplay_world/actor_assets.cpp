#include "actor_assets.hpp"
#include "model_parts.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>

namespace reo::native::gameplay_world {
namespace {
#include "actor_asset_names.inc"

std::string lower_name(std::string_view input) {
    std::string result(input);
    for (auto& character : result)
        if (character >= 'A' && character <= 'Z') character += 'a'-'A';
    return result;
}
std::uint32_t word(std::span<const std::byte> bytes,std::size_t offset) {
    if (offset > bytes.size() || sizeof(std::uint32_t) > bytes.size()-offset)
        throw std::invalid_argument("Truncated native actor model bundle");
    std::uint32_t value;
    std::memcpy(&value,bytes.data()+offset,sizeof(value));
    return value;
}
}

ActorAssets::ActorAssets(std::shared_ptr<const reo::assets::Source> source) : source_(std::move(source)) {
    if (!source_) throw std::invalid_argument("Native actor archive source unavailable");
    const auto root = reo::assets::table(*source_,0,source_->size);
    const auto match = [](const auto& entry) { return lower_name(entry.name) == "romdata_usa.afs"; };
    const auto common = std::find_if(root.entries.begin(),root.entries.end(),match);
    if (common == root.entries.end() || std::find_if(common+1,root.entries.end(),match) != root.entries.end())
        throw std::invalid_argument("Native File #1 actor archive missing or ambiguous");
    const auto directory = reo::assets::table(*source_,common->offset,common->size);
    members_.reserve(directory.entries.size());
    for (const auto& entry : directory.entries)
        if (!entry.name.empty()) members_.push_back({lower_name(entry.name),std::uint64_t(common->offset)+entry.offset,entry.size});
    std::stable_sort(members_.begin(),members_.end(),[](const Member& first,const Member& second) { return first.name < second.name; });
}

std::string_view ActorAssets::model_name(std::uint8_t identity,ModelDefinitionBank bank) {
    const auto names = bank == ModelDefinitionBank::alternate ? std::span<const std::string_view>(alternate_actor_names) : std::span<const std::string_view>(ordinary_actor_names);
    if (identity >= names.size() || names[identity].empty())
        throw std::out_of_range("Native actor model name unavailable");
    return names[identity];
}

std::shared_ptr<const ActorModelAsset> ActorAssets::read(std::uint8_t type,std::uint16_t variant,
    ModelDefinitionBank bank) const {
    const auto& definition = File1LinkedModelProfiles{}.definition(type,variant,bank);
    if (definition.model == 255) return {};
    const auto name = model_name(definition.model,bank);
    const auto key = lower_name(name);
    const auto member = std::lower_bound(members_.begin(),members_.end(),key,
        [](const Member& entry,const std::string& key) { return entry.name < key; });
    if (member == members_.end() || member->name != key || member->bytes == 0)
        throw std::invalid_argument("Native actor model asset missing");
    if (member+1 != members_.end() && (member+1)->name == key)
        throw std::invalid_argument("Native actor model asset ambiguous");
    if (member->bytes > 32u*1024u*1024u)
        throw std::invalid_argument("Native actor model asset exceeds limit");
    const auto cache_key = std::size_t(member-members_.begin());
    {
        std::lock_guard guard(cache_mutex_);
        const auto retained = cache_.find(cache_key);
        if (retained != cache_.end()) return retained->second;
    }
    auto bytes = std::make_shared<std::vector<std::byte>>(member->bytes);
    source_->read(member->offset,bytes->size(),bytes->data());
    const auto offset = word(*bytes,0x24),length = word(*bytes,0x28);
    if (offset && (!length || offset > bytes->size() || length > bytes->size()-offset))
        throw std::invalid_argument("Native actor skeleton section unavailable");
    auto result = std::shared_ptr<ActorModelAsset>(new ActorModelAsset);
    result->name_ = name;
    const auto model_offset = word(*bytes,0x14),model_length = word(*bytes,0x18);
    if (model_offset) {
        if (!model_length || model_offset > bytes->size() || model_length > bytes->size()-model_offset)
            throw std::invalid_argument("Native actor model section unavailable");
        result->part_count_ = std::uint16_t(model_part_count(std::span<const std::byte>(*bytes).subspan(model_offset,model_length)));
    }
    if (offset)
        result->skeleton_ = animation::Skeleton::import_raw(std::span<const std::byte>(*bytes).subspan(offset,length));
    result->bytes_ = std::move(bytes);
    std::lock_guard guard(cache_mutex_);
    return cache_.try_emplace(cache_key,std::move(result)).first->second;
}

std::shared_ptr<animation::Instance> ActorModelAsset::make_instance() const {
    return skeleton_ ? std::make_shared<animation::Instance>(skeleton_) : nullptr;
}
}
