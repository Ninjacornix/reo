#pragma once
#include "dialogue_pool.hpp"
#include "../gameplay_scenario/dialogue_response_program.hpp"
namespace reo::native::gameplay_scenario {class Flags;class SceneResources;class ResourceTemplates;}
namespace reo::native::gameplay_world {
struct DialogueConditionBindings {
    const gameplay_scenario::Flags* flags{};
    const gameplay_scenario::SceneResources* resources{};
    const gameplay_scenario::ResourceTemplates* templates{};
};
struct DialogueConditionResult {
    DialogueStatus status{DialogueStatus::completed};
    std::int16_t value{};
};
// Reached leaves borrow the same canonical actor/session, pool flag bank and
// random generator. Unported phase-dependent actor scratch roles stay explicit.
DialogueConditionResult evaluate_dialogue_condition(World&,const DialoguePool*,
    const gameplay_scenario::DialogueCondition&,const actors::EntityId&,const DialogueConditionBindings& = {})noexcept;
} // namespace reo::native::gameplay_world
