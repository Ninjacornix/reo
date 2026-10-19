#pragma once

#include "types.h"
#include <cstdint>
#include <functional>

namespace reo {

/*
 * PS2 Memory Map Emulation
 *
 * The PS2 EE sees a 4GB virtual address space. We allocate the key regions
 * and translate addresses. The recompiled game code uses helper functions
 * to read/write memory, which we intercept for MMIO regions.
 *
 * Address mapping:
 *   0x00000000 - 0x01FFFFFF  Main RAM (32MB, cached)
 *   0x10000000 - 0x1000FFFF  EE I/O registers
 *   0x11000000 - 0x1100FFFF  VU memory
 *   0x12000000 - 0x12001FFF  GS privileged registers
 *   0x1C000000 - 0x1C1FFFFF  IOP RAM (2MB)
 *   0x1FC00000 - 0x1FFFFFFF  BIOS ROM (4MB)
 *   0x20000000 - 0x21FFFFFF  Main RAM (uncached mirror)
 *   0x30000000 - 0x31FFFFFF  Main RAM (uncached accelerated)
 *   0x70000000 - 0x70003FFF  Scratchpad (16KB)
 *   0x80000000+              KSEG0/KSEG1 mirrors
 */

// Callback for MMIO register access
using MmioReadHandler = std::function<uint32_t(uint32_t addr)>;
using MmioWriteHandler = std::function<void(uint32_t addr, uint32_t value)>;

class Memory {
  public:
    Memory() = default;
    ~Memory();

    bool init();
    void reset();

    // Physical memory access (for recompiled code)
    uint8_t read8(uint32_t vaddr);
    uint16_t read16(uint32_t vaddr);
    uint32_t read32(uint32_t vaddr);
    uint64_t read64(uint32_t vaddr);
    void read128(uint32_t vaddr, void* out);

    void write8(uint32_t vaddr, uint8_t value);
    void write16(uint32_t vaddr, uint16_t value);
    void write32(uint32_t vaddr, uint32_t value);
    void write64(uint32_t vaddr, uint64_t value);
    void write128(uint32_t vaddr, const void* data);

    // Direct pointer access (for DMA, bulk operations)
    // Returns nullptr for MMIO regions
    uint8_t* get_pointer(uint32_t vaddr);
    const uint8_t* get_pointer(uint32_t vaddr) const;

    // MMIO handler registration
    void register_mmio_read(uint32_t base, uint32_t size, MmioReadHandler handler);
    void register_mmio_write(uint32_t base, uint32_t size, MmioWriteHandler handler);

    // Raw region access
    uint8_t* main_ram() {
        return m_main_ram;
    }
    uint8_t* iop_ram() {
        return m_iop_ram;
    }
    uint8_t* scratchpad() {
        return m_scratchpad;
    }
    uint8_t* bios_rom() {
        return m_bios_rom;
    }
    uint8_t* vu0_code() {
        return m_vu0_code;
    }
    uint8_t* vu0_data() {
        return m_vu0_data;
    }
    uint8_t* vu1_code() {
        return m_vu1_code;
    }
    uint8_t* vu1_data() {
        return m_vu1_data;
    }

  private:
    uint32_t translate_address(uint32_t vaddr) const;

    uint8_t* m_main_ram = nullptr;   // 32 MB
    uint8_t* m_iop_ram = nullptr;    // 2 MB
    uint8_t* m_scratchpad = nullptr; // 16 KB
    uint8_t* m_bios_rom = nullptr;   // 4 MB
    uint8_t* m_vu0_code = nullptr;   // 4 KB
    uint8_t* m_vu0_data = nullptr;   // 4 KB
    uint8_t* m_vu1_code = nullptr;   // 16 KB
    uint8_t* m_vu1_data = nullptr;   // 16 KB

    struct MmioRegion {
        uint32_t base;
        uint32_t size;
        MmioReadHandler read;
        MmioWriteHandler write;
    };

    static constexpr int MAX_MMIO_REGIONS = 32;
    MmioRegion m_mmio_regions[MAX_MMIO_REGIONS] = {};
    int m_mmio_count = 0;
};

} // namespace reo
