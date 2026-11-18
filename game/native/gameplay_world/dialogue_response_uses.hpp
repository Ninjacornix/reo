#pragma once
#include <array>
#include <cstdint>
#include <optional>
#include <span>
namespace reo::native::gameplay_world {
struct DialogueResponseUse {
    std::int16_t selection{-1},count{};
    friend bool operator==(const DialogueResponseUse&,const DialogueResponseUse&)=default;
};
using DialogueResponseUses=std::array<DialogueResponseUse,1000>;
// The array and selected value belong to the canonical response owner. These
// functions operate directly on that storage; they hold no second copy.
std::optional<std::size_t> find_dialogue_response_use(std::span<DialogueResponseUse,1000>,std::int32_t)noexcept; //6B9250
void choose_dialogue_response_use(std::span<DialogueResponseUse,1000>,std::int32_t& selected,std::int32_t candidate)noexcept; //6B91A0
void increment_dialogue_response_use(std::span<DialogueResponseUse,1000>,std::int32_t choice)noexcept; //6B92E0
}
