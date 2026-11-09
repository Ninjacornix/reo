#pragma once
#include "world.hpp"
namespace reo::native::gameplay_world {
struct MotionShapeProfile {
    CollisionShapeTarget target;
    std::uint8_t ticks{};
};
class MotionProfiles {
  public:
    virtual ~MotionProfiles() = default;
    virtual gameplay_collision::actors::ShapeDefinition body(std::uint8_t model,
                                                             std::uint8_t word_offset) const = 0;
    virtual MotionShapeProfile shape(std::uint8_t model, std::uint8_t selector) const = 0;
};
class File1MotionProfiles final : public MotionProfiles {
  public:
    gameplay_collision::actors::ShapeDefinition body(std::uint8_t, std::uint8_t) const override;
    MotionShapeProfile shape(std::uint8_t, std::uint8_t) const override;
};
} // namespace reo::native::gameplay_world
