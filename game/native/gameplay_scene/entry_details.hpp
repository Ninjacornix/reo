#pragma once
#include "../gameplay_scenario/model_reference.hpp"
#include <array>
#include <cstdint>
namespace reo::native::gameplay_scene {
// Additional meaningful room-entry inputs, produced by5C1390. Existing
// control bodies, collision admission and model identities retain their fields.
struct DoorEntryDetails {
    std::uint32_t side{},yaw{};
};
struct ObjectEntryDetails {
    std::array<float,3> anchor{};
    std::uint32_t yaw{},travel{},endpoint{};
    std::uint16_t scenario_flag{65535};
};
struct LadderEntryDetails {
    std::uint32_t mode{};
    gameplay_scenario::ModelReference model;
};
}
