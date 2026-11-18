#pragma once
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_world {
// Actual6DEE20 inputs, shared by inventory behavior and dialogue presentation.
struct DialogueVisibilityInputs {
    std::optional<std::uint8_t> enabled; //4BAE33
    std::optional<std::uint8_t> mode;    //755EC4
};
inline std::optional<bool> dialogue_suppressed(const DialogueVisibilityInputs& value,
                                             std::uint8_t inventory_owner)noexcept{
    if(!value.enabled)return{};
    if(!*value.enabled)return false;
    if(!value.mode)return{};
    if(!*value.mode)return false;
    return *value.mode!=2||inventory_owner!=0;
}
}
