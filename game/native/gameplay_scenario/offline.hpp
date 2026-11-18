#pragma once
#include "flags.hpp"

namespace reo::native::gameplay_scenario {
// Ordered authored party references0..2, resolved by the native actor owner.
// These values are not addresses or a layout of the runtime actor registry.
struct OfflinePartyActor {bool active{};std::uint8_t script_class{};std::uint16_t room{};};
struct OfflineFlagDelta {SharedFlags added,removed;};
struct OfflineState {std::array<OfflineFlagDelta,3> actors;};
struct OfflineResult {Status status{Status::completed};std::size_t invocations{},operations{};std::array<TickResult,3> actors;};
class OfflineCoordinator {
public:
    const OfflineState& snapshot()const noexcept{return state_;}
    Status restore(const OfflineState&)noexcept;
    // Channel1 evaluates each active party reference from one shared flag base,
    // then merges retained deltas in original actor order. Inactive deltas are
    // deliberately retained. Other channels use zeroed dispatch context once.
    OfflineResult tick(Interpreter&,std::size_t requested_channel,bool enabled,
        std::span<const OfflinePartyActor,3>,std::uint16_t current_room,std::uint8_t& selected_actor,
        FlagState&,Providers={},std::size_t maximum_operations=4096,
        std::optional<std::uint32_t> stream_tick={})noexcept;
private:
    OfflineState state_{};
    bool running_{};
};
} // namespace reo::native::gameplay_scenario
