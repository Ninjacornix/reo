#pragma once
#include <array>
#include <cstdint>
#include <optional>
namespace reo::native::gameplay_scenario {
struct TimerHudPulse {std::int8_t falling{};std::int16_t value{},delta{};};
struct TimerHudGlyph {
    std::int16_t x{},y{},width{},height{};
    std::uint32_t rgba{};
    std::int16_t u{},v{},end_u{},end_v{};
    friend bool operator==(const TimerHudGlyph&,const TimerHudGlyph&)=default;
};
enum class TimerHudStatus {complete,unavailable_counter};
struct TimerHudFrame {
    TimerHudStatus status{TimerHudStatus::complete};
    std::array<TimerHudGlyph,8> glyphs{};
    std::uint8_t count{};
    bool setup{true},restore{},acknowledge{};
};
// Complete5BA8D0 CPU sprite geometry. Texture acquisition and GPU submission
// consume these typed coordinates through the Stage5 presentation boundary.
std::optional<TimerHudGlyph> timer_hud_glyph(std::uint8_t slot,std::uint8_t glyph,std::uint32_t rgba)noexcept;
// Actual5BA530 timer/flag choice and pulse policy. The supplied countdowns are
// a view of canonical FlagTimers.remaining, never another counter bank.
TimerHudFrame timer_hud(TimerHudPulse&,const std::array<std::int16_t,8>& countdowns,
    std::uint32_t primary,std::uint32_t alternate,bool use_alternate,bool pulse)noexcept;
}
