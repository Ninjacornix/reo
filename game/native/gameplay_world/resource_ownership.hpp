#pragma once
#include "inventory.hpp"
#include "resource_factory.hpp"
namespace reo::native::gameplay_world {
// Complete5B16D0 descriptor-only primitive, shared by actual resource owners.
bool clear_resource_claims(gameplay_scenario::SceneResources&)noexcept;
// Ownership and claims operate on the same descriptor/inventory/model owners.
// These primitives do not insert inventory, journal actions or send messages.
// Missing required actors/profiles throw after preserving the known prefix.
class ResourceOwnership final {
public:
    ResourceOwnership(WorldInventory&,ResourceFactory&);
    bool admits(std::uint32_t actor_index,std::uint32_t resource)const; //593060
    std::int8_t assign(std::uint32_t resource,std::uint32_t actor_index); //5B1760
    std::int8_t exchange_world(std::uint32_t world_resource,std::uint32_t owned_resource); //5B1BF0
    std::int8_t swap_owned(std::uint32_t first,std::uint32_t second); //5B1DE0
    void set_claim(std::uint32_t resource,std::uint32_t actor); //5B15D0
    void clear_claim(std::uint32_t resource,std::uint32_t actor); //5B1610
    bool claimed_by_other(std::uint32_t resource,std::uint32_t actor)const; //5B1670
    void clear_claims(); //5B16D0
    void clear_actor_claims(std::uint32_t actor); //5B1710
private:
    WorldInventory& inventory_;ResourceFactory& factory_;
    World& world_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;ResourceFrames& frames_;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
    void publish(std::uint8_t,const gameplay_scenario::SceneDescriptor&);
    const gameplay_scenario::ResourceTemplate& metadata(std::uint8_t)const;
};
}
