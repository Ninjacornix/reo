#pragma once
#include "resource_recipes.hpp"
namespace reo::native::gameplay_world {
// Locality-gated actor callers over actual resource and inventory consumers.
// The action notice lives once on Actor; network dispatch is a later consumer.
class ActorResourceOperations final {
public:
    explicit ActorResourceOperations(ResourceRecipes&);
    bool bound_to(const World& world)const noexcept{return &world_==&world;}
    std::int8_t transfer_quantity(const actors::EntityId&,std::uint32_t mode,
        std::uint32_t first,std::uint32_t second,std::uint32_t amount); //5F4FE0
    std::int8_t release_instances(const actors::EntityId&,std::uint32_t mode,
        std::uint32_t resource); //5F5C50
    std::int8_t remap_content(const actors::EntityId&,std::uint32_t mode,
        std::uint32_t resource); //5F6A80
    std::int8_t transfer_inventory(const actors::EntityId&,std::uint32_t mode); //5F6800
private:
    ResourceRecipes& resources_;World& world_;
    std::shared_ptr<Actor> actor(const actors::EntityId&)const;
    bool eligible(const Actor&,std::uint8_t mode)const noexcept;
    static void notice(Actor&,std::uint16_t mask,std::uint8_t resource)noexcept;
};
}
