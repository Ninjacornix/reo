#pragma once
#include <array>
#include <cstdint>

namespace reo::native::movie_counter_clock {
// Raw words preserve original signed loads/comparisons and modulo arithmetic.
// The future movie owner supplies state and actual admitted tick events.
struct State {
    std::uint32_t actual{},requested{},pause{},buffering_pause{},property_47{};
    std::uint32_t active_counter{},increment{},elapsed_counter{},elapsed_origin{},external_accumulator{};
};
struct Words {std::uint32_t numerator{},denominator{};};
enum class Operation {tick,active_gate,elapsed_gate,rebase,unavailable,counter,contextual,admit};
enum class Field {active_counter,elapsed_counter,elapsed_origin,numerator,denominator};
struct Effects {
    std::array<Field,2> writes{};
    std::uint32_t count{},status{};
    bool status_defined{},valid_operation{true};
};
// No allocation, clock sampling, callbacks, guest state or playback policy.
[[nodiscard]] Effects execute(State&,Operation,Words&,std::uint32_t shared_frequency) noexcept;
}
