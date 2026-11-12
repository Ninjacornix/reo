#pragma once
#include "work.hpp"
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_effects {
struct ActorContactState {
    std::uint8_t phase{},pose_phase{},mode{};
    bool visible{},clone{},parent_left{};
    std::int16_t cycle{},remaining{},age{},clone_timer{};
    std::optional<transform_math::Matrix> basis;
    transform_math::Vector position,base_position;
};
class ActorContactOperations {
public:
    virtual ~ActorContactOperations()=default;
    // Required actual572290 pose update and571EC0 clone construction.
    virtual bool rebind(ActorContactState&)=0;
    virtual WorkStatus clone(const ActorContactState&,std::uint32_t variant)=0;
    // Samples actual bound children at the current age, before age advances.
    virtual bool sample(const ActorContactState&)=0;
};
struct ActorContactStep {bool available{true},retire{};};
ActorContactStep advance_actor_contact(ActorContactState&,std::uint8_t parent_primary,
    std::uint8_t parent_secondary,ActorContactOperations&);
struct ActorContactProfile {std::uint16_t resource{};std::int16_t variant{};std::uint32_t child_mask{};};
class ActorContactPoses {
public:
    virtual ~ActorContactPoses()=default;
    virtual bool bound_to(const gameplay_world::World&)const noexcept=0;
    virtual bool rebind(const gameplay_actors::EntityId&,ActorContactState&)=0;
};
class ActorContactBackend {
public:
    virtual ~ActorContactBackend()=default;
    virtual bool channels_bound_to(const gameplay_world::World&)const noexcept=0;
    virtual WorkStatus actor_channel(const gameplay_actors::EntityId&,
        const std::optional<transform_math::Matrix>&,transform_math::Vector,std::uint32_t,std::uint32_t)=0;
};
// Admitted full mode+low31 variant index into the exact eight owned pairs.
// The clone bit is orthogonal; out-of-table indices remain unavailable.
std::optional<ActorContactProfile> actor_contact_profile(std::uint32_t mode,std::uint32_t variant)noexcept;
}
