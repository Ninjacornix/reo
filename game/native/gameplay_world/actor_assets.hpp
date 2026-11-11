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
    std::shared_ptr<animation::Instance> make_instance() const;
private:
    friend class ActorAssets;
    ActorModelAsset() = default;
    std::string name_;
    std::shared_ptr<const std::vector<std::byte>> bytes_;
    std::shared_ptr<const animation::Skeleton> skeleton_;
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
private:
    struct Member {std::string name;std::uint64_t offset{};std::uint32_t bytes{};};
    std::shared_ptr<const reo::assets::Source> source_;
    std::vector<Member> members_;
    mutable std::mutex cache_mutex_;
    mutable std::map<std::size_t,std::shared_ptr<const ActorModelAsset>> cache_;
};
}
