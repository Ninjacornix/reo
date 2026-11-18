#pragma once
#include "speech_state.hpp"
#include "dialogue_records.hpp"
#include "../gameplay_actors/input.hpp"
namespace reo::native::gameplay_world {
struct DialogueInputRequested {DialogueStatus status{DialogueStatus::completed};bool requested{};};
// Complete6B7D40 over the actual shared speech state and menu-frame input.
// Suppression is the separately qualified6DEE20 result, required at this exact
// call point. An absent frame is read only after suppression admits the work.
DialogueInputRequested prepare_dialogue_input_request(SpeechState&,const gameplay_actors::input::Frame*,std::optional<bool> suppression)noexcept;
// In6B7E40's mode-zero path the physical primary-loop index is the actual
// already-live caller variable used when no fresh direction was assigned.
DialogueInputRequested prepare_loop_dialogue_input_request(SpeechState&,const gameplay_actors::input::Frame*,std::optional<bool> suppression,std::size_t physical_index)noexcept;

}
