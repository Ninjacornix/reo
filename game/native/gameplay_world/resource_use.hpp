#pragma once
#include "resource_frames.hpp"
namespace reo::native::gameplay_world {
struct ResourceUsePayload {
    std::optional<animation::Vector> vector;
    std::optional<std::array<std::int16_t,4>> parameters;
};
// Complete5B3AA0/5B3B80 and5B4E60 through canonical descriptor/model state.
// Payloads are native values; arbitrary guest-pointer alias profiles are not
// part of this interface. Borrowed owners outlive synchronous simulation calls.
class ResourceUse final {
public:
    ResourceUse(World&,gameplay_scenario::SceneResources&,const gameplay_scenario::ResourceTemplates&,ResourceFrames&);
    // Source return0 inactive,1 depleted,2 retained/override. Does not destroy
    // records, detach inventory, play sound or allocate a new instance.
    std::uint8_t use(std::uint32_t resource,const ResourceUsePayload& = {});
    void configure(std::uint32_t resource,const ResourceUsePayload& = {});
    std::int16_t initial_quantity(std::uint32_t resource)const;
    // Complete5B5850: signed low-byte switch0 sets instance flag80000000;
    // nonzero clears it. Visibility changes during the actual common frame.
    void visibility(std::uint32_t resource,std::uint32_t switch_value);
private:
    World& world_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;ResourceModels& models_;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
};
}
