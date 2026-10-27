#pragma once
#include <cstdint>

namespace reo_network::game {
struct MenuAddresses {
    uint32_t step, substep, cursor, delay, choice;
    uint32_t profileStage, profileWork, keyboardWork, keyboardDelay, password;
};
// Original SLUS-20765/SLUS-20984 network-overlay load/store references.
// File #2 uses a one-update keyboard initialization delay; the flow observes it.
#if defined(REO_GAME_FILE2)
inline constexpr uint32_t frontMenu = 0x5B7D00;
inline constexpr MenuAddresses menu{0x6E9490, 0x6E9491, 0x6E9498, 0x6E9494, 0x6E94B9,
    0x6ABF88, 0x6ABF70, 0x64C160, 0x64C148, 0x8A58F0};
#else
inline constexpr uint32_t frontMenu = 0x5D4898;
inline constexpr MenuAddresses menu{0x6DF150, 0x6DF151, 0x6DF158, 0x6DF154, 0x6DF179,
    0x69BCD8, 0x69BCC0, 0x6436D0, 0x6436C8, 0x8A64E0};
#endif
} // namespace reo_network::game
