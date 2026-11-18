#pragma once
#include <array>
#include <cstdint>
namespace reo::native::gameplay_world {
struct PrimarySavedActorState {
    std::int16_t health{};
    std::uint8_t class_marker{},selected_resource{};
    friend bool operator==(const PrimarySavedActorState&,const PrimarySavedActorState&)=default;
};
using PrimarySavedActors=std::array<PrimarySavedActorState,8>;
}
