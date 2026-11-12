#pragma once
#include "lighting.hpp"
#include "../transform_math/transform_math.hpp"
namespace reo::native::gameplay_scenario {
// Consumed fields of one48-byte light record. Half6 chooses start/end binding;
// flags half4 bit0 selects the source's mode2/3 primary light.
struct CutsceneLightKey {
    std::int8_t enabled{};std::uint16_t frame{},flags{};std::int16_t binding{};
    transform_math::Vector point{},control{};float radius{},extra{};
    std::array<std::uint8_t,3> first{},second{};
};
struct CutsceneLightSegment {CutsceneLightKey current,next;};
void initialize_cutscene_light(NativeLight&,const CutsceneLightKey&,std::uint8_t material)noexcept;
// Position uses the authored quadratic each visit. Colors/radius/extra accumulate
// per simulation visit using the source duration; they are not resampled from t.
// Return the auxiliary mirror before the end marker clears local extra.
std::optional<LightDescriptor> sample_cutscene_light(NativeLight&,const CutsceneLightSegment&,
    std::int8_t end_enabled,std::uint32_t frame,std::uint8_t clock_mode,std::uint8_t material)noexcept;
transform_math::Vector cutscene_light_point(const CutsceneLightSegment&,std::uint32_t frame)noexcept;
} // namespace reo::native::gameplay_scenario
