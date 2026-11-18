#pragma once
#include <array>
#include <cstdint>

namespace reo::native::movie_audio_filter {
struct Pair {std::uint64_t numerator{},denominator{1};bool operator==(const Pair&)const=default;};
struct State {
    std::uint32_t enabled{1},pause{},active{},mode{1},window{10},sample_counter{};
    std::array<std::int32_t,60> history{};
    Pair previous_input,previous_helper,previous_output;
    Pair quantum{16683,1000000},threshold{200000,1000000},first_offset{0,1000000},later_offset{0,1000000};
    std::uint64_t helper_anchor{UINT64_MAX},master_anchor{},raw_maximum{};
    std::uint32_t reanchors{},positive_steps{},negative_steps{},resets{},excess_resets{};
    std::int32_t average_before{},average_after{},inactive_max{},inactive_min{},active_max{},active_min{};
    bool operator==(const State&)const=default;
};
enum class Status {completed,invalid_history,division_by_zero,invalid_alias};
struct Result {Status status{Status::completed};Pair output;bool observed{};};
struct Average {Status status{Status::completed};std::int32_t value{};};
enum class Ratio {quantum,threshold,first_offset,later_offset};
[[nodiscard]] State initialize() noexcept;
void clear_history(State&) noexcept;
void enabled(State&,std::uint32_t) noexcept;
void pause(State&,std::uint32_t) noexcept;
void mode(State&,std::uint32_t) noexcept;
[[nodiscard]] Status window(State&,std::uint32_t) noexcept;
void ratio(State&,Ratio,Pair) noexcept;
[[nodiscard]] Average average(const State&) noexcept;
[[nodiscard]] Average push(State&,std::int32_t) noexcept;
[[nodiscard]] Average shift(State&,std::int32_t) noexcept;
[[nodiscard]] Status baseline(State&,Pair) noexcept;
// Owned bounded profile. Failures leave State and input untouched. A normal
// successful call preserves the original input-numerator clamp and signals the
// caller's last-filter observation; no guest pointer/global/CSV buffer is owned.
[[nodiscard]] Result process(State&,Pair& input,Pair helper) noexcept;
}
