#pragma once
#include "resource_frames.hpp"
#include "resource_static_assets.hpp"
#include "../gameplay_scenario/resource_collisions.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_effects {class PeriodicVisuals;}
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
// The six special5DF450 companion routes require bound actual visual consumers.
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
    // Complete591510. Reuses this instance, retaining untouched state and
    // trailing part masks/poses. Rebinding does not construct companions.
    void rebind(const ResourceModelId&,std::uint16_t content);
    bool bind_companions(gameplay_effects::PeriodicVisuals&)noexcept;
    bool bound_to(const World& world,const ResourceModels& models)const noexcept{return frames_.open()&&&frames_.world_==&world&&&models_==&models;}
    std::shared_ptr<const gameplay_collision::response::Grid> room_floor(std::uint16_t room)const noexcept{return frames_.open()&&frames_.world_.room==room&&scene_room_==room?floors_:nullptr;}
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
    friend class ResourceContents;
    friend class ResourceRecipes;
    friend class ResourceDeployment;
    friend class ResourceDepletion;
    friend class gameplay_effects::PeriodicVisuals;
    ResourceModels& models_;
    ResourceFrames& frames_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::shared_ptr<const ResourceStaticAssets> assets_;
    gameplay_scenario::ResourceCollisions* collisions_{};
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    std::uint16_t scene_room_{};
    std::shared_ptr<ResourceFactoryToken> token_;
    gameplay_effects::PeriodicVisuals* companions_{};
    void delayed_frame(ResourceModels&,const ResourceModelId&,ResourceModel&);
};
}
