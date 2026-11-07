#pragma once
#include "../movie_selected_clock/clock.hpp"
#include <array>
#include <cstdint>
#include <memory>
namespace reo::native::movie_clock_initialize {
using Words=movie_selected_clock::Words;
struct Record {std::uint32_t count{};std::array<std::uint32_t,7> history{};Words value;};
struct TrackerPrefix {
    // Remaining tracker roles are unresolved. These are bounded payloads, not
    // timestamps, memory addresses or permission to discard the real writers.
    std::array<std::uint32_t,4> opaque{};
    std::uint32_t side_baseline{},bias{},opaque_flag{};
};
struct State {
    std::array<movie_selected_clock::Kind,7> callbacks;
    std::array<Record,6> records;
    TrackerPrefix prefix;
    std::array<std::uint32_t,32> first_window{};
    std::array<std::uint32_t,4> window_parameters{};
    std::array<std::uint32_t,32> second_window{};
    Words previous,latest,cached;
    std::array<std::uint32_t,5> admission_payload{};
    std::uint32_t active_counter{},increment{},picture_sequence{};
    Words requested_picture;
    std::uint32_t hysteresis_count{},tracked_query_bits{},cached_decision{},previous_query_bits{};
    std::uint32_t elapsed_counter{},elapsed_origin{};
    std::shared_ptr<movie_selected_clock::Query> external;
    std::uint32_t previous_external{},external_accumulator{},external_denominator{};
};
// Fresh owned clock construction only. Replacing a live context still requires
// its actual callback/source/frame fences; no reset or stop shortcut is exposed.
[[nodiscard]] State initialize()noexcept;
}
