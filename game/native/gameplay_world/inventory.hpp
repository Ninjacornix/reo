#pragma once
#include "resource_frames.hpp"
namespace reo::native::gameplay_world {
// The canonical actor owns the slots once. This facade supplies actual find,
// removal, equipped cleanup, insertion and refresh consumers through that state.
// Borrowed simulation owners outlive calls; stale/foreign entities refuse.
class WorldInventory final:public gameplay_scenario::SceneOwners {
public:
    WorldInventory(World&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,ResourceFrames&);
    std::uint8_t find(const actors::EntityId&,std::uint8_t resource)const;
    std::uint8_t find_by_content(const actors::EntityId&,std::uint32_t content)const;
    bool remove(const actors::EntityId&,std::uint8_t resource);
    bool detach_item(const actors::EntityId&,std::uint8_t resource);
    void compact(const actors::EntityId&);
    void insert(const actors::EntityId&,std::uint8_t resource);
    std::optional<actors::EntityId> resolve(gameplay_scenario::SceneOwnerReference)noexcept override;
    gameplay_scenario::SceneStatus detach(gameplay_scenario::SceneResources&,const actors::EntityId&,std::uint8_t)noexcept override;
    gameplay_scenario::SceneStatus refresh(gameplay_scenario::SceneResources&,const actors::EntityId&)noexcept override;
private:
    friend class ResourceRecipes;
    friend class ResourceOwnership;
    friend class ResourceAuxiliaryLists;
    World& world_;
    gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    ResourceFrames& frames_;
    std::shared_ptr<Actor> actor(const actors::EntityId&)const;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
};
}
