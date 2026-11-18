#pragma once
#include <array>
#include <cstdint>
namespace reo::native::movie_timestamp {
struct Stamp {std::uint32_t value{},begin{},bytes{};};
struct State {
    std::uint32_t baseline{0xffffffff},origin{},base{},maximum{};
    Stamp cached{0xffffffff,0,0xffffffff};
};
struct Input {std::uint32_t rate{},reference{},kind{},changed{};Stamp stamp;};
struct Result {std::uint32_t value{};bool admitted{};};
// File #1 temporal reconciliation in the original 22,500-unit timestamp
// domain. Payload offsets remain opaque provenance; only cached.value decides
// whether a new accounting record has arrived. No host clock or guessed cadence.
[[nodiscard]] Result reconcile(State&,const Input&)noexcept;
}
