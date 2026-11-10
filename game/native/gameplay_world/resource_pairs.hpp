#pragma once
#include "resource_frames.hpp"
namespace reo::native::gameplay_world {
struct ResourcePairMatch {
    std::int16_t kind{};
    // Source writes the extra halfword on a table match, including kind0.
    // An absent value preserves the caller's prior output.
    std::optional<std::int16_t> extra;
};
// Compatibility and quantity operations over the canonical resource table.
// Borrowed owners outlive synchronous simulation calls. No inventory mirroring.
class ResourcePairs final {
public:
    ResourcePairs(World&,gameplay_scenario::SceneResources&,
        const gameplay_scenario::ResourceTemplates&,ResourceFrames&);
    //5B3E40 plus5B4020. Native optional slots replace nullable record pointers.
    ResourcePairMatch classify(std::optional<std::uint8_t> first,
        std::optional<std::uint8_t> second)const;
    //5B3DD0: low-byte IDs must both be active, but ownership is not gated.
    std::int16_t query_active(std::uint32_t first,std::uint32_t second)const;
    // Complete5B3690 dispatch (compatibility D/B/C/1), preserving return0/1/3.
    std::int8_t transfer_owned(std::uint32_t first,std::uint32_t second,std::uint32_t amount);
    // Complete5B3820 and separately audited5B39A0, plus5B3920. Primitive
    // record operations retain the source's lack of activity/ownership gates.
    std::int8_t move_quantity(std::uint8_t destination,std::optional<std::uint8_t> source,std::uint32_t amount);
    std::int8_t swap_quantity(std::uint8_t first,std::uint8_t second);
private:
    friend class ResourceRecipes;
    friend class OwnedResourceRecipes;
    friend class ResourceConsumption;
    World& world_;gameplay_scenario::SceneResources& resources_;
    const gameplay_scenario::ResourceTemplates& templates_;ResourceFrames& frames_;
    gameplay_scenario::SceneDescriptor descriptor(std::uint8_t)const;
    const gameplay_scenario::ResourceTemplate& metadata(std::uint8_t)const;
    ResourcePairMatch special(const gameplay_scenario::SceneDescriptor&,const gameplay_scenario::SceneDescriptor&)const;
    void quantity(std::uint8_t,std::int32_t);
    void destroy_owned(std::uint8_t);
};
}
