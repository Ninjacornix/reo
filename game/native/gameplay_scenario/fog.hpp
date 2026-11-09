#pragma once
#include "../transform_math/transform_math.hpp"
#include <array>
#include <cstddef>
#include <cstdint>
#include <span>
namespace reo::native::gameplay_scenario {
struct FogRecord {
    std::uint32_t active{};
    float near_distance{},far_distance{};
    std::array<std::uint32_t,3> colors{};
    std::uint32_t parameters{};
    std::uint16_t pitch{},yaw{};
    std::array<std::array<float,4>,3> vectors{};
    std::array<std::uint32_t,3> words{};
};
struct FogState {
    float near_distance{},far_distance{};
    std::array<std::uint8_t,3> color{},tail_color{};
    std::array<std::array<std::uint8_t,4>,2> secondary_colors{};
    std::array<std::uint16_t,2> parameters{};
    transform_math::Vector direction;
    std::array<std::array<float,4>,3> vectors{};
    std::array<std::uint32_t,2> words{};
    std::uint8_t option{};
    std::int8_t selected{-1};
    std::array<std::uint8_t,4> flash{};
};
enum class FogStatus {completed,unsupported_version,invalid_asset,unavailable,unsupported_numeric};
struct FogPulse {
    std::uint8_t phase{};
    std::int16_t counter{},duration{},delay{};
    transform_math::Vector velocity,accumulator;
    float saved_near{},saved_far{},last_near{},last_far{},near_step{},far_step{};
};
struct FogPulseResult {FogStatus status{FogStatus::completed};bool retire{};};
// Canonical game-side fog values and loaded catalog, borrowed by the one shared
// effect-work owner. Rendering consumes this state later; no guest data persists.
class Fog final {
public:
    explicit Fog(FogState initial):state_(initial){}
    FogStatus import_fog(std::span<const std::byte>)noexcept;
    FogStatus select(std::uint8_t)noexcept;
    FogPulseResult advance(FogPulse&)noexcept;
    FogState& state()noexcept{return state_;}
    const FogState& state()const noexcept{return state_;}
    const auto& records()const noexcept{return records_;}
    bool ready()const noexcept{return ready_;}
    void reset_selection()noexcept{state_.selected=-1;}
private:
    FogState state_;
    std::array<FogRecord,16> records_{};
    bool ready_{};
};
}
