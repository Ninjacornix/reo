#pragma once
#include <cstdint>
namespace reo::native::gameplay_world {
// Ordinary actor sound metadata. Source554 gates1B9310, while source33
// selects the bank12 program variant. A generic Actor does not establish it.
struct ActorSoundState {
    std::uint8_t allocation_slot{},program_variant{};
    friend bool operator==(const ActorSoundState&,const ActorSoundState&)=default;
};
}
