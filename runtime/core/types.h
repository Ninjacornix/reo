#pragma once

#include <cstdint>
#include <cstring>

namespace reo {

// PS2 Emotion Engine types — the R5900 has 128-bit GPRs
// We represent them as a union for easy access at different widths

union GPR128 {
    uint8_t u8[16];
    int8_t s8[16];
    uint16_t u16[8];
    int16_t s16[8];
    uint32_t u32[4];
    int32_t s32[4];
    uint64_t u64[2];
    int64_t s64[2];
    float f32[4];

    // Standard MIPS access is the lower 64 bits
    // MMI instructions use all 128 bits

    void clear() {
        memset(this, 0, sizeof(*this));
    }

    // Convenience for standard 32/64-bit MIPS ops
    uint32_t lo32() const {
        return u32[0];
    }
    uint64_t lo64() const {
        return u64[0];
    }
    void set32(uint32_t val) {
        u64[0] = (int32_t)val;
        u64[1] = 0;
    }
    void set64(uint64_t val) {
        u64[0] = val;
        u64[1] = 0;
    }
};

static_assert(sizeof(GPR128) == 16, "GPR128 must be 128 bits");

// VU register types
union VF128 {
    float f[4]; // x, y, z, w
    uint32_t u[4];
    struct {
        float x, y, z, w;
    };

    void clear() {
        memset(this, 0, sizeof(*this));
    }
};

static_assert(sizeof(VF128) == 16, "VF128 must be 128 bits");

// PS2 memory addresses
constexpr uint32_t EE_MAIN_RAM_BASE = 0x00000000;
constexpr uint32_t EE_MAIN_RAM_SIZE = 0x02000000; // 32 MB
constexpr uint32_t EE_IO_BASE = 0x10000000;
constexpr uint32_t EE_VU0_CODE_BASE = 0x11000000;
constexpr uint32_t EE_VU0_DATA_BASE = 0x11004000;
constexpr uint32_t EE_VU1_CODE_BASE = 0x11008000;
constexpr uint32_t EE_VU1_DATA_BASE = 0x1100C000;
constexpr uint32_t EE_GS_BASE = 0x12000000;
constexpr uint32_t EE_IOP_RAM_BASE = 0x1C000000;
constexpr uint32_t EE_IOP_RAM_SIZE = 0x00200000; // 2 MB
constexpr uint32_t EE_BIOS_BASE = 0x1FC00000;
constexpr uint32_t EE_BIOS_SIZE = 0x00400000; // 4 MB
constexpr uint32_t EE_UNCACHED_BASE = 0x20000000;
constexpr uint32_t EE_UNCACHED_ACC = 0x30000000;
constexpr uint32_t EE_SCRATCHPAD_BASE = 0x70000000;
constexpr uint32_t EE_SCRATCHPAD_SIZE = 0x00004000; // 16 KB
constexpr uint32_t EE_KSEG0_BASE = 0x80000000;
constexpr uint32_t EE_KSEG1_BASE = 0xA0000000;

// Mask to convert virtual → physical address
constexpr uint32_t PHYS_ADDR_MASK = 0x1FFFFFFF;

} // namespace reo
