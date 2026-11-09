#pragma once
#include "resource_frames.hpp"
#include "resource_static_assets.hpp"
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
private:
    ResourceModels& models_;
    ResourceFrames& frames_;
    const gameplay_scenario::ResourceTemplates& templates_;
    std::shared_ptr<const ResourceStaticAssets> assets_;
};
}
