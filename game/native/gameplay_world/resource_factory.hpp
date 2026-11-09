#pragma once
#include "resource_frames.hpp"
#include "resource_static_assets.hpp"
#include "../gameplay_scenario/resource_collisions.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
class ResourceFactory;
struct ResourceFactoryToken final {ResourceFactory* owner;};
class DelayedResourceWork final:public ResourceModelWork {
public:
    explicit DelayedResourceWork(ResourceFactory&);
    void update(ResourceModels&,const ResourceModelId&,ResourceModel&)override;
private:
    std::weak_ptr<ResourceFactoryToken> owner_;
};
//591230 primary construction for the concrete common/weapon work families.
// The six special5DF450 companion routes are unavailable
// until their actual consumers are supplied; no successful provider substitutes.
class ResourceFactory final:public gameplay_scenario::SceneEffects {
public:
    ResourceFactory(ResourceModels&,ResourceFrames&,
        const gameplay_scenario::ResourceTemplates&,
        std::shared_ptr<const ResourceStaticAssets>);
    ~ResourceFactory();
    ResourceFactory(const ResourceFactory&)=delete;
    ResourceFactory& operator=(const ResourceFactory&)=delete;
    ResourceModelCreated create(std::uint16_t content,std::int8_t companion_argument=0);
    ResourceModelCreated create_delayed(std::uint16_t content,std::int16_t ticks);
    // Retains the actual immutable floor grid for this room and validates the
    // canonical shared scene owner. A later room change invalidates admission.
    bool bind_scene(gameplay_scenario::ResourceCollisions&,
        std::shared_ptr<const gameplay_collision::response::Grid>,std::uint16_t room)noexcept;
    ResourceModelCreated place(const gameplay_scenario::SceneResourceId&);
    gameplay_scenario::SceneStatus apply(gameplay_scenario::SceneResources&,
        const gameplay_scenario::SceneResourceId&,gameplay_scenario::SceneEffect,std::uint8_t)noexcept override;
private:
    friend class DelayedResourceWork;
    friend class gameplay_weapon_resources::Equipment;
    ResourceModels& models_;
    ResourceFrames& frames_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::shared_ptr<const ResourceStaticAssets> assets_;
    gameplay_scenario::ResourceCollisions* collisions_{};
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    std::uint16_t scene_room_{};
    std::shared_ptr<ResourceFactoryToken> token_;
    void delayed_frame(ResourceModels&,const ResourceModelId&,ResourceModel&);
};
}
