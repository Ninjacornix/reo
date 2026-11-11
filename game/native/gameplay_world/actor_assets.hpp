#pragma once
#include "linked_models.hpp"
#include "../animation/model.hpp"
#include <string>
#include <string_view>
#include <map>
#include <mutex>

namespace reo::assets { struct Source; }
namespace reo::native::gameplay_world {

class ActorModelAsset final {
public:
    std::string_view name() const noexcept { return name_; }
    std::span<const std::byte> bytes() const noexcept { return *bytes_; }
    const std::shared_ptr<const animation::Skeleton>& skeleton() const noexcept { return skeleton_; }
    std::uint16_t part_count() const noexcept { return part_count_; }
    std::shared_ptr<animation::Instance> make_instance() const;
private:
    friend class ActorAssets;
    ActorModelAsset() = default;
    std::string name_;
    std::shared_ptr<const std::vector<std::byte>> bytes_;
    std::shared_ptr<const animation::Skeleton> skeleton_;
    std::uint16_t part_count_{};
};

// Immutable definitions are shared. Every mutable model instance has its own
// lifetime. This owner reads the actual retained File #1 common archive.
class ActorAssets final {
public:
    explicit ActorAssets(std::shared_ptr<const reo::assets::Source>);
    static std::string_view model_name(std::uint8_t identity,ModelDefinitionBank);
    // A definition's FF model selector is an admitted absent model. Missing
    // named content and malformed bundles throw. A missing skeleton section
    // is represented explicitly and make_instance() then returns null.
    std::shared_ptr<const ActorModelAsset> read(std::uint8_t type,std::uint16_t variant,
        ModelDefinitionBank bank = ModelDefinitionBank::ordinary) const;
    // Actual1AA740 nonzeroBB4 routes: NPC indexBB4-1, or HP character for
    // definition1. Primary BB4==0 has different appearance paths.
    static std::string substituted_model_name(std::uint16_t variant,std::uint8_t definition,std::uint8_t character);
    std::shared_ptr<const ActorModelAsset> read_substituted_model(std::uint16_t variant,std::uint8_t definition,std::uint8_t character)const;
    // Auxiliary NPC loader1D0800 uses the low-byte identity directly. Class1
    // selects HN; other classes select N. This is independent of primary BB4.
    static std::string npc_model_name(std::uint16_t identity,std::uint8_t model_class);
    std::shared_ptr<const ActorModelAsset> read_npc(std::uint16_t identity,std::uint8_t model_class)const;
private:
    struct Member {std::string name;std::uint64_t offset{};std::uint32_t bytes{},ordinal{};};
    std::shared_ptr<const reo::assets::Source> source_;
    std::vector<Member> members_;
    std::size_t common_count_{};
    mutable std::mutex cache_mutex_;
    mutable std::map<std::size_t,std::shared_ptr<const ActorModelAsset>> cache_;
    std::shared_ptr<const ActorModelAsset> read_named(std::string_view)const;
    std::shared_ptr<const ActorModelAsset> read_entry(const Member&,std::string_view,bool bounded_records=false)const;
};
// Attach a prepared immutable asset to a live canonical actor. Allocations
// finish before publication. Missing or retired IDs preserve the old model.
// Asset I/O belongs to ActorAssets::read, outside this simulation-owner call.
bool bind_actor_model_asset(World&,const actors::EntityId&,
                            std::shared_ptr<const ActorModelAsset>);
}
