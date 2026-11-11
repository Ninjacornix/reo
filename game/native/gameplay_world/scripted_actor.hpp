#pragma once
#include <array>
#include <cstdint>
#include <vector>

namespace reo::native::gameplay_world {
enum class ModelDefinitionBank;
// Native rendering boundary for6BA5C0. Shadow conversion/submission belongs
// to Stage5; neither a scratch-cache address nor an original callback survives.
struct ActorRenderRequest {
    ModelDefinitionBank bank{};
    std::uint8_t model{},texture{},construction_mode{};
    std::int8_t shadow_enabled{};
    std::int16_t shadow_asset{};
};
struct ScriptedActorState {
    std::int8_t motion_rate_mode{},motion_selector{}; // B40/B43
    float motion_blend_duration{}; // B44, duration rather than initial frame
    std::int16_t track_two_motion{}; // B7C
    std::uint8_t model_group{}; // source31, logical resource group identity
    std::array<std::uint8_t,4> color{}; // CCC..CCF, distinct from primary fades
    std::int8_t alpha_mode{}; // CA0
    std::uint8_t alpha{}; // CA1
    std::vector<std::uint8_t> part_visibility;
    ActorRenderRequest render;
};
}
