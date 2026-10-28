#pragma once
#include <cstdint>

namespace reo::mods {
// Only addresses/structure offsets vary. Both games use the same selection,
// exclusion, progression protection and deterministic planning algorithms.
struct GameLayout {
    uint32_t itemPool, itemLookup, itemMetadata, itemCount;
    uint32_t itemScale, itemPriority, itemCombinations, scenario, room;
    uint32_t spawnTable, spawnCount, enemyBase, enemyEnd, enemyStride;
    uint32_t enemyModel, enemySpawn, enemyLifecycle, enemyBehavior, enemyPosture;
    uint32_t enemyHealth, enemyMaximum;
    uint32_t animationSlots, animationPool, animationStride;
    uint32_t modelTable, callbackIndex, callbackTable, sharedTypes;
};
inline constexpr GameLayout file1Layout{
    0x3c5630, 0x74b6e0, 0x74bb50, 0x74ccf0,
    0x74b940, 0x74b2d0, 0x74c970, 0x3243da, 0x3243dc,
    0x74f250, 0x4bae8e, 0x42eb00, 0x459120, 0xd90,
    0xbba, 0xb98, 0xb9a, 0xc2b, 0xb9c, 0x544, 0x546,
    0x4baeb0, 0x4bec30, 0xc84, 0x387e90, 0x70aa50, 0x70ab20, 0x709ac0
};
// File #2 values are verified against SLUS-20984 v1.05 opcode readers.
inline constexpr GameLayout file2Layout{
    0x3e1c20, 0x7ac590, 0x7aca00, 0x7ada20,
    0x7ac7f0, 0x7ac180, 0x7ad660, 0x30095a, 0x30095c,
    0x7aff80, 0x4db44e, 0x44de90, 0x478af0, 0xdb0,
    0xbd2, 0xbb0, 0xbb2, 0xc48, 0xbb4, 0x540, 0x542,
    0x4db470, 0x4df200, 0xc84, 0x3a2360, 0x766ee0, 0x766fb0, 0x765f40
};
#if defined(REO_GAME_FILE2)
inline constexpr auto gameLayout = file2Layout;
#else
inline constexpr auto gameLayout = file1Layout;
#endif
}
