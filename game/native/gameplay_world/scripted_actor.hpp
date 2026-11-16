#pragma once
#include "../gameplay_actors/entity.hpp"
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
    std::int8_t cue_phase{},scale_lock{}; // B38/B41
    std::uint8_t request_phase{}; // B42
    std::uint32_t request_flags{}; // B3C
    std::int8_t motion_selector{}; // B43; shared B40 lives on Actor
    float motion_blend_duration{}; // B44, duration rather than initial frame
    std::int16_t track_two_motion{}; // B7C
    std::uint8_t scale_profile{}; // B8B
    std::int32_t relation_mode{}; // B48
    gameplay_actors::EntityId related_actor; // B4C, canonical identity
    std::uint32_t relation_options{},relation_parameter{}; // B50/B60
    std::array<float,3> relation_offset{}; // B54/B58/B5C
    std::array<std::int16_t,3> command_angles{}; // B64/B66/B68
    std::array<std::int16_t,2> movement_angles{}; // B6C/B6E
    float forward_step{}; // B70
    std::uint32_t yaw_step{},movement_remaining{}; // B74/B78
    std::uint8_t model_group{}; // source31, logical resource group identity
    std::uint8_t scene_marker{}; // BA6, set by5F0610's kind2 construction
    std::array<std::uint8_t,4> color{}; // CCC..CCF, distinct from primary fades
    std::int8_t alpha_mode{}; // CA0
    std::uint8_t alpha{}; // CA1
    std::vector<std::uint8_t> part_visibility;
    ActorRenderRequest render;
};
}
