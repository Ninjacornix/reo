#pragma once
#include "model_attachments.hpp"
#include <span>
namespace reo::native::gameplay_world {
struct ResourceStaticRoot {
    std::int16_t content{};
    std::size_t part_count{};
    // Actual source-derived world poses. More than six parts cannot bind to
    // the current primary ResourceModel contract; those roots remain explicit.
    std::shared_ptr<const ResourcePartPoses> admitted_parts;
};
// Immutable asset ownership replacing the source1D3100/372490 cache for the
// reached primary matrix consumer. No mutable global cache or temporary heap.
class ResourceStaticAssets final {
public:
    static std::shared_ptr<const ResourceStaticAssets> import_nbd(std::span<const std::byte>);
    static std::shared_ptr<const ResourceStaticAssets> import_forest(std::span<const std::byte>);
    std::span<const ResourceStaticRoot> roots()const noexcept{return roots_;}
    std::int16_t find(std::int16_t content)const noexcept;
    std::shared_ptr<const ResourcePartPoses> parts(std::int16_t index)const;
private:
    std::vector<ResourceStaticRoot> roots_;
};
}
