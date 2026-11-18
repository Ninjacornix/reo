#pragma once
#include "conditions.hpp"
namespace reo::native::gameplay_navigation {
// Complete819010 within bounded source-node/condition state. Destination -1
// selects the node-level condition; all four authored edge slots are searched.
AdmissionResult admit_edge(const Bank&,std::uint32_t room,std::int32_t source,std::int32_t destination,
    ActorFacts,std::uint32_t actor_status,std::optional<std::uint16_t> room_flags)noexcept;
}
