#pragma once
#include "resource_factory.hpp"
#include "resource_use.hpp"
namespace reo::native::gameplay_world {
// Content mutation through the existing descriptor, template and model owners.
// Borrowed owners must outlive synchronous simulation-thread calls.
class ResourceContents final {
public:
    ResourceContents(World&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,ResourceFrames&,ResourceFactory&);
    //5B4C90: no activity/owner gate, quantity unchanged. Native logical record
    // identity replaces an arbitrary original record pointer.
    void replace_direct(std::uint32_t resource,std::uint32_t content);
    //5B4BF0: active, owned and unsigned old content != signed new content.
    // On admission replaces content then resets quantity through5B4E60.
    bool replace_owned(std::uint32_t resource,std::uint32_t content);
    //5B3C70: admitted active0/1/B remap to1C5/1C8/1C6, no quantity reset.
    bool remap(std::uint32_t resource);
private:
    friend class ResourceRecipes;
    friend class ResourceDeployment;
    friend class ResourceDepletion;
    World& world_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;
    ResourceFactory& factory_;ResourceUse use_;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
};
}
