#pragma once
#include "resource_frames.hpp"
#include "resource_static_assets.hpp"
#include "../gameplay_scenario/resource_collisions.hpp"
#include "../gameplay_collision/response.hpp"
namespace reo::native::gameplay_world {
//591230 primary construction for the concrete common/weapon work families.
// The six special5DF450 companion routes and delayed class2 are unavailable
// until their actual consumers are supplied; no successful provider substitutes.
class ResourceFactory final {
public:
    ResourceFactory(ResourceModels&,ResourceFrames&,
        const gameplay_scenario::ResourceTemplates&,
        std::shared_ptr<const ResourceStaticAssets>);
    ResourceModelCreated create(std::uint16_t content,std::int8_t companion_argument=0);
    // Retains the actual immutable floor grid for this room and validates the
    // canonical shared scene owner. A later room change invalidates admission.
    bool bind_scene(gameplay_scenario::ResourceCollisions&,
        std::shared_ptr<const gameplay_collision::response::Grid>,std::uint16_t room)noexcept;
    ResourceModelCreated place(const gameplay_scenario::SceneResourceId&);
private:
    ResourceModels& models_;
    ResourceFrames& frames_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::shared_ptr<const ResourceStaticAssets> assets_;
    gameplay_scenario::ResourceCollisions* collisions_{};
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    std::uint16_t scene_room_{};
};
}
