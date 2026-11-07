#pragma once
#include "../movie_counter_clock/clock.hpp"
#include <cstdint>
namespace reo::native::movie_admission {
using Words=movie_counter_clock::Words;
struct State {
    std::uint32_t selector{},tolerance{},rate{},increment{};
    std::uint32_t count{};
    float tracked{-1};
    std::uint32_t cached{};
    float previous{-1};
    std::uint32_t auxiliary{0xFFFFFFFFu};
};
enum class Operation {core,fallback,hysteresis};
struct Input {
    Words query,sample;
    std::uint32_t slack{},frequency{};
    float query_time{},current_time{};
};
enum class Status {completed,invalid_input,zero_frequency,unsupported_fp};
struct Result {Status status{Status::invalid_input};std::uint32_t decision{};};
[[nodiscard]] bool supported_fp_environment()noexcept;
// Arithmetic after the explicit cached-clock sample boundary. Caller supplies
// actual post-query facts and raw in/out pair; no provider or frame is owned.
// Refusal leaves State unchanged. Host floating-point state is restored.
[[nodiscard]] Result evaluate(State&,Operation,const Input&)noexcept;
}
