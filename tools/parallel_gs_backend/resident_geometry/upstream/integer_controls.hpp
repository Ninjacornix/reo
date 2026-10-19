#pragma once
#include <cstdint>
namespace reo_gpu_upstream {
enum IntegerControl : uint32_t { ReturnPC = 1u, A0 = 2u, A1 = 4u, A2 = 8u };
inline constexpr uint32_t perspectiveIntegerControls(uint32_t entry) {
    if (entry == 0x18f754u || entry == 0x18f75cu)
        return 0u;
    if (entry == 0x1921c8u)
        return A2;
    if (entry == 0x1921b0u)
        return ReturnPC | A0 | A1;
    return ReturnPC | A0;
}
} // namespace reo_gpu_upstream
