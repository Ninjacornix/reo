#pragma once
#include "motion_profiles.hpp"
#include "motion_resources.hpp"
#include "../animation/motion_descriptors.hpp"
namespace reo::native::gameplay_world {
class MotionPrelude {
  public:
    virtual ~MotionPrelude() = default;
    // Original573430 category-specific animation events/behavior effects. The
    // concrete owner must implement it; there is no successful default path.
    // step is the exact caller argument preserved by58C300/5D57D0.
    virtual void run(World&, Actor&, float step) = 0;
};
class WorldAnimation final {
  public:
    WorldAnimation(World& world, WorldMotionResources& resources, const MotionProfiles& profiles,
                   MotionPrelude& prelude)
        : world_(world), resources_(resources), profiles_(profiles), prelude_(prelude) {}
    bool bound_to(const World& world)const noexcept{return &world==&world_&&!world_.closed();}
    void select(const actors::EntityId&, std::uint32_t encoded, float initial, float blend);
    float first_frame(const actors::EntityId&,std::uint32_t encoded,std::uint16_t track); //5D4A10
    float last_frame(const actors::EntityId&,std::uint32_t encoded,std::uint16_t track); //5D4930
    float matched_frame(const actors::EntityId&,std::uint32_t encoded,std::uint16_t track); //5D4B10
    void select_blended(const actors::EntityId&, std::uint32_t primary, std::uint32_t secondary,
                        float weight);
    void apply_named(const actors::EntityId&, const animation::PackedMotion&, float initial,
                     float blend);
    void apply(const actors::EntityId&, const animation::PackedMotion&, float initial, float blend);
    void apply_blended(const actors::EntityId&, const animation::PackedMotion& primary,
                       const animation::PackedMotion& secondary, float weight);
    std::int8_t tick(const actors::EntityId&, float step);
    std::int8_t tick_blended(const actors::EntityId&, float step, float weight);

  private:
    std::shared_ptr<const animation::MotionBlock> frame_block(const actors::EntityId&,std::uint32_t,std::uint16_t);
    bool override_motion(const actors::EntityId&, std::uint32_t, float initial, float blend);
    World& world_;
    WorldMotionResources& resources_;
    const MotionProfiles& profiles_;
    MotionPrelude& prelude_;
    animation::File1MotionDescriptors descriptors_;
};
} // namespace reo::native::gameplay_world
