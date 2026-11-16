#pragma once
// Host pad tap for native camera mods (see docs/native-gameplay/HYBRID_INTEGRATION_PLAN.md).
//
// reo_hw_bridge publishes every libpad2 frame it builds: host sticks (PS2 0..255,
// 0x80 centre) and the pressed-button mask (bit order of pad2ButtonBit). A camera
// mod reads the latest sample from the game thread. While consume_right_stick is
// set, the bridge reports a centred right stick to the game, so the stick drives
// the camera instead of the game's own right-stick actions.
#include <atomic>
#include <cstdint>

namespace reo_pad_tap {
struct Sample {
    std::uint8_t right_x{0x80}, right_y{0x80}, left_x{0x80}, left_y{0x80};
    std::uint16_t pressed{};
    std::uint32_t frame{};
};
inline std::atomic<std::uint64_t> packed{0x80808080ull};  // rx | ry<<8 | lx<<16 | ly<<24 | pressed<<32
inline std::atomic<std::uint32_t> frames{0};
inline std::atomic<bool> consume_right_stick{false};

// Button bits, as pad2ButtonBit in reo_hw_bridge.cpp.
constexpr std::uint16_t L3 = 1u << 1, R3 = 1u << 2, L2 = 1u << 8, R2 = 1u << 9, L1 = 1u << 10, R1 = 1u << 11,
                        CROSS = 1u << 14;

// Mouse buttons for mouse look (bit 0 left, bit 1 right, bit 2 middle). Set only by a
// camera mod built against SDK patch 0132; the bridge never links the SDK symbol
// itself, so builds without that patch are unaffected. Right = R1 (aim), left = cross.
inline std::atomic<unsigned (*)()> mouse_buttons_source{nullptr};

inline void publish(std::uint8_t rx, std::uint8_t ry, std::uint8_t lx, std::uint8_t ly, std::uint16_t pressed) {
    packed.store(std::uint64_t(rx) | std::uint64_t(ry) << 8 | std::uint64_t(lx) << 16 | std::uint64_t(ly) << 24 |
                     std::uint64_t(pressed) << 32,
                 std::memory_order_relaxed);
    frames.fetch_add(1, std::memory_order_relaxed);
}
inline Sample latest() {
    const auto v = packed.load(std::memory_order_relaxed);
    Sample s;
    s.right_x = std::uint8_t(v); s.right_y = std::uint8_t(v >> 8);
    s.left_x = std::uint8_t(v >> 16); s.left_y = std::uint8_t(v >> 24);
    s.pressed = std::uint16_t(v >> 32);
    s.frame = frames.load(std::memory_order_relaxed);
    return s;
}
}  // namespace reo_pad_tap
