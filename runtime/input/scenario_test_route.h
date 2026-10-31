#pragma once
#include <cstdint>

namespace reo::scenario_test_route {
// Diagnostic-only chapter routing. The caller observes the original menu and
// sends ordinary pad input; no progression, guest state or timing is changed.
inline int requested(const char* value) noexcept {
    if (!value || !*value) return 0;
    return value[0] >= '0' && value[0] <= '4' && !value[1] ? value[0] - '0' : -1;
}
enum class Choice { Confirm, Left, Right, Unavailable };
inline Choice choose(int target, uint32_t cursor, uint32_t count) noexcept {
    // Require all five chapters so a filtered list cannot select a different
    // chapter with the same list index. The probe supplies the unlock builtin.
    if (target < 0 || target > 4 || count != 5 || cursor >= count) return Choice::Unavailable;
    return cursor == uint32_t(target) ? Choice::Confirm : cursor < uint32_t(target) ? Choice::Right : Choice::Left;
}
}
