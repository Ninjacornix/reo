#pragma once
#include <array>
#include <cstdint>
#include <span>

namespace reo::native::gameplay_actors::input {
struct Frame {
    std::uint32_t pressed{},released{},held{};
    std::array<std::uint32_t,3> history{};
    std::uint32_t repeat{};
    std::int32_t repeat_timer{};
    std::array<std::int16_t,8> analog{};
    friend bool operator==(const Frame&,const Frame&)=default;
};
struct Remap {std::uint32_t button_100{},button_10{},button_20{};};
struct ControllerFrame {std::uint32_t held{};std::array<std::int16_t,8> analog{};};
struct ActorRoute {std::uint8_t slot{},ai_control{};};
struct Routing {
    std::uint8_t mode{},selected_actor{},layout{};
    std::array<std::int8_t,8> actor_ports{-1,-1,-1,-1,-1,-1,-1,-1};
};
enum class Routed {updated,skipped,invalid_slot,invalid_port,invalid_layout};
// Already normalized host/controller values; platform packet protocols remain
// outside the game-facing native input core.
std::uint32_t remap(std::uint32_t,Remap) noexcept;
void repeat(Frame&) noexcept;
Routed route(Frame&,ActorRoute,const Routing&,std::span<const ControllerFrame>,std::span<const Remap>) noexcept;
std::uint32_t menu(Frame&,const ControllerFrame&,Remap) noexcept;
} // namespace reo::native::gameplay_actors::input
