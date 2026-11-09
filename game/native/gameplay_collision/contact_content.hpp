#pragma once
#include "delivery.hpp"
#include <memory>
#include <variant>
namespace reo::native::gameplay_collision::delivery {
struct SegmentShape {
    Vec3 origin, direction;
    std::uint16_t range{};
    std::optional<std::uint16_t> joint;
};
struct SweepShape {
    Vec3 center;
    std::uint16_t radius{};
    std::optional<std::uint16_t> joint;
};
struct MarginShape {
    Vec3 origin, direction;
    std::uint16_t margin{}, range{};
    std::optional<std::uint16_t> joint;
};
struct AngularShape {
    Vec3 origin, direction;
    std::uint16_t extent{}, range{};
    std::optional<std::uint16_t> joint;
};
using Geometry = std::variant<std::monostate, SegmentShape, SweepShape, MarginShape, AngularShape>;
struct Definition {
    std::uint8_t startup{}, lifetime{}, mask{}, attachment_flags{}, key{};
    Template response;
    Geometry geometry;
};
// Immutable converted content. The runtime format contains typed values and
// indices, never original addresses, instructions or guest relocation entries.
// Packet leases retain individual definitions; the session retains the catalog
// while borrowing its immutable response tables during synchronous delivery.
class Catalog {
  public:
    Catalog() = default;
    static Catalog import(std::span<const std::byte>);
    std::shared_ptr<const Definition> find(std::uint8_t bank, std::int32_t ordinal) const noexcept;
    std::size_t size(std::uint8_t bank) const noexcept;
    const Tables& tables() const;

  private:
    struct Data;
    std::shared_ptr<const Data> data_;
};
} // namespace reo::native::gameplay_collision::delivery
