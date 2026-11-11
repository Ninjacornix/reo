#include "launch.hpp"

namespace reo::native::gameplay_session {
std::optional<LaunchRoster> parse_launch_roster(std::span<const std::byte> bytes) noexcept {
    if(bytes.size()<32)return {};
    const auto byte=[&](std::size_t offset) { return std::to_integer<std::uint8_t>(bytes[offset]); };
    const auto half=[&](std::size_t offset) {
        return std::uint16_t(std::uint16_t(byte(offset)) | std::uint16_t(byte(offset+1))<<8);
    };
    const auto players=byte(4),ai=byte(5);
    if(players>4||ai>2||byte(2)>=4)return {};
    LaunchRoster roster;
    roster.gameplay_flags=byte(1);
    roster.choice_row=byte(2);
    roster.scenario=byte(3);
    for(std::size_t index=0;index<players;++index)
        roster.actors[roster.count++]={byte(8+index),byte(12+index),0,half(16+2*index)};
    for(std::size_t index=0;index<ai;++index)
        roster.actors[roster.count++]={byte(24+index),byte(26+index),1,half(28+2*index)};
    return roster;
}
}
