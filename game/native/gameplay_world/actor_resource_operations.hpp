#pragma once
#include "resource_recipes.hpp"
namespace reo::native::gameplay_world {
//7030F0's signed-half gates precede every resource owner read. Unknown
//population or a reached unsupported physical slot is an explicit refusal.
std::optional<bool> offline_actor_resource_required(const World&,std::int16_t index,std::int16_t content)noexcept;
// Locality-gated actor callers over actual resource and inventory consumers.
// The action notice lives once on Actor; network dispatch is a later consumer.
class ActorResourceOperations final {
public:
    explicit ActorResourceOperations(ResourceRecipes&);
    bool bound_to(const World& world)const noexcept{return &world_==&world;}
    bool bound_to(const World&,const gameplay_scenario::SceneResources&,const gameplay_scenario::ResourceTemplates&)const noexcept;
    // Complete7030F0/826CB0 acquisition. A real source allocation/capacity
    //failure is a completed command; unavailable native consumers returnfalse.
    //Allocation and any successful reclaim prefix remain committed on refusal.
    bool grant_offline_resource(std::int16_t index,std::int16_t content,
        std::int16_t quantity,std::int16_t cleanup)noexcept;
    std::int8_t transfer_quantity(const actors::EntityId&,std::uint32_t mode,
        std::uint32_t first,std::uint32_t second,std::uint32_t amount); //5F4FE0
    std::int8_t release_instances(const actors::EntityId&,std::uint32_t mode,
        std::uint32_t resource); //5F5C50
    std::int8_t remap_content(const actors::EntityId&,std::uint32_t mode,
        std::uint32_t resource); //5F6A80
    bool transfer_inventory_ready(const actors::EntityId&,std::uint32_t mode)const noexcept;
    std::int8_t transfer_inventory(const actors::EntityId&,std::uint32_t mode); //5F6800
    bool clear_claims()noexcept; //5B16D0, actual66AD30 scene-entry caller
private:
    ResourceRecipes& resources_;World& world_;
    std::shared_ptr<Actor> actor(const actors::EntityId&)const;
    bool eligible(const Actor&,std::uint8_t mode)const noexcept;
    static void notice(Actor&,std::uint16_t mask,std::uint8_t resource)noexcept;
};
}
