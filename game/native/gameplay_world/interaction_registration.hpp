#pragma once
#include "world.hpp"

namespace reo::native::gameplay_world {

struct InteractionRegistrationMessage {
    std::uint8_t selector{3};
    std::uint8_t control_selector{};
    std::uint8_t room{};
    std::uint8_t sequence{};
    std::uint8_t yaw_high{};
};
enum class InteractionRegistrationStatus { completed, unavailable };
class InteractionRegistrationPublication {
public:
    virtual ~InteractionRegistrationPublication()=default;
    virtual bool publish(World&,Actor&,const InteractionRegistrationMessage&)=0;
};

// 67FF80 selectors1..6, including selector3 used by64F110. The typed
// message omits uninitialized stack padding; admission/state effects retain
// their original order if the actual route publisher refuses.
InteractionRegistrationStatus register_interaction(World&,Actor&,
    std::uint8_t control_selector,InteractionRegistrationPublication&);
InteractionRegistrationStatus register_interaction(World&,Actor&,
    std::uint8_t selector,std::uint8_t control_selector,InteractionRegistrationPublication&);

} // namespace reo::native::gameplay_world
