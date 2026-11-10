#pragma once
#include "execution.hpp"
#include "control_requests.hpp"
#include "../gameplay_navigation/actor_routes.hpp"
namespace reo::native::gameplay_ai {
struct InitializationResult {
    Status status{Status::unavailable};
    bool enabled{};
    std::optional<RegistrationStatus> registration;
    std::optional<RequestResult> publication;
};
// Complete8120C0 for existing canonical actor components. The header clear is
// unconditional; disabled AI then leaves everything else untouched. An enabled
// actor requires known prior execution/route state before its remaining effects.
InitializationResult initialize(gameplay_navigation::Bank&,ControlRequests&,
    std::uint8_t ai_control,std::uint8_t actor_slot,ExecutionState*,gameplay_navigation::ActorRouteState*)noexcept;
}
