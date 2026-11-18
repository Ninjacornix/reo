#pragma once
#include "dialogue_conditions.hpp"
namespace reo::native::gameplay_world {
struct DialogueResponseMutable {
    std::int16_t cue{};
    std::array<std::int8_t,4> condition_results;
    std::uint32_t replied_to{};
};
struct DialogueResponseCueMetadata {
    std::int16_t blocked{},priority{};
    std::array<std::uint16_t,4> replies;
};
std::optional<DialogueResponseCueMetadata> dialogue_response_cue_metadata(const gameplay_scenario::DialogueCues&,std::size_t)noexcept;
struct DialogueResponsePriority {DialogueStatus status{DialogueStatus::completed};std::int16_t value{99};};
// Complete6B94E0. Selected sequence is the canonical pool's channel-one output,
// and the cue bank is the actual selected primary's retained bank.
DialogueResponsePriority dialogue_response_priority(const Actor&,std::uint8_t selected_slot,std::optional<std::uint16_t> selected_sequence,const gameplay_scenario::DialogueCues* selected_cues)noexcept;
struct DialogueResponseEvaluated {DialogueStatus status{DialogueStatus::completed};std::size_t evaluated{};bool chosen{};};
// Complete6B9330 on the response owner's borrowed live row and choice slots.
// Definitions/metadata stay immutable; only authored mutable roles are written.
DialogueResponseEvaluated evaluate_dialogue_response_choice(World&,const DialoguePool*,const actors::EntityId&,
    const gameplay_scenario::DialogueResponseDefinition&,DialogueResponseMutable&,
    const gameplay_scenario::DialogueCues* actor_cues,std::optional<std::uint16_t> selected_sequence,
    const gameplay_scenario::DialogueCues* selected_cues,std::span<std::int32_t,8> choices,
    const DialogueConditionBindings& = {})noexcept;
}
