#pragma once
#include "work.hpp"
#include "../gameplay_session/session.hpp"
namespace reo::native::gameplay_effects {
// The specialty state of the five staggered5789C0 work records. Position,
// velocity and animation counters belong to their actual168-record owner.
struct InheritedTrailState {
    std::uint8_t phase{},ordinal{},parent_type{},latched{},motion_variant{};
    bool visible{};
    std::int16_t delay{},remaining{},age{},rotation_offset{};
    std::uint16_t attributes{};
    transform_math::Vector position,previous_position,velocity,acceleration,target;
    transform_math::Vector scale{1,1,1};
    std::array<std::int16_t,4> angles{};
    float feedback_scale{};
};
struct InheritedTrailMotion {
    std::uint8_t kind{},primary{},variant{};
    transform_math::Vector position;
};
class InheritedTrailOperations {
public:
    virtual ~InheritedTrailOperations()=default;
    virtual std::optional<float> floor(transform_math::Vector)=0;
    virtual bool contact_cue(transform_math::Vector)=0; // actual654D40(kind14)
    virtual WorkCreated impact(const WorkRequest&)=0;
    virtual bool configure_impact(const WorkCreated&,transform_math::Vector color,transform_math::Vector scale)=0;
    virtual bool contact_burst(transform_math::Vector)=0; // actual5783A0 particle burst
    // Complete652880 sampling followed by signed16 addition to child rotation
    // Z (34), repeated for the actual mesh channel count, in child order.
    virtual bool sample(const InheritedTrailState&)=0;
};
struct InheritedTrailStep {bool available{true},retire{};};
InheritedTrailStep advance_inherited_trail(InheritedTrailState&,
    const InheritedTrailMotion&,InheritedTrailOperations&,gameplay_session::Random&);
}
