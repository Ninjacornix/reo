#pragma once
#include "timestamp.hpp"
#include <optional>
namespace reo::native::movie_timestamp {
struct Picture {
    std::uint32_t rate{},reference{},kind{},drop{},hours{},minutes{},seconds{},frames{},gop{};
};
struct Record {
    std::uint32_t valid{},rate{},drop{},hours{},minutes{},seconds{},frames{},reference{},value{},scale{1};
};
struct FlowState {
    State temporal;
    std::uint32_t mode{},jump_tolerance{};
    Record first{0,0,0,0,0,0,0,0,0x7fffffff,1};
    Record latest{0,0,0,0,0,0,0,0,0xffffffff,1};
    Record current;
};
struct FlowInput {Picture picture;std::optional<Stamp> accounting;std::uint32_t changed{};};
struct Publication {Picture picture;std::uint32_t stamp{0xffffffff},value{},scale{1};bool admitted{};};
// Joined original reconciliation/baseline/latest policy. MPEG/SJ provenance and
// discontinuity observations belong to the source owner; no host-time synthesis.
[[nodiscard]] Publication publish(FlowState&,const FlowInput&)noexcept;
}
