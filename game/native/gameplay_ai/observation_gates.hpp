#pragma once
#include "execution.hpp"
namespace reo::native::gameplay_world {struct Actor;}
namespace reo::native::gameplay_session {class Random;}
namespace reo::native::gameplay_ai {
bool observation_blocked(const gameplay_world::Actor&)noexcept; // complete813BD0
struct ObservationAdmitted {Status status{Status::unavailable};bool admitted{};std::uint8_t random_draws{};};
// Complete812EF0 for authored character profiles. Mode0 checks scaled reference
// probability; every other mode checks room/memo and may update the same memo.
ObservationAdmitted admit_reference_reaction(gameplay_world::Actor&,const gameplay_world::Actor* reference,
    std::uint32_t mode,gameplay_session::Random&)noexcept;
}
