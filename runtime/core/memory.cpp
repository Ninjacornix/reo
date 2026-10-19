#include "memory.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace reo {

Memory::~Memory() {
    if (m_main_ram)
        free(m_main_ram);
    if (m_iop_ram)
        free(m_iop_ram);
    if (m_scratchpad)
        free(m_scratchpad);
    if (m_bios_rom)
        free(m_bios_rom);
    if (m_vu0_code)
        free(m_vu0_code);
    if (m_vu0_data)
        free(m_vu0_data);
    if (m_vu1_code)
        free(m_vu1_code);
    if (m_vu1_data)
        free(m_vu1_data);
}

bool Memory::init() {
    // Allocate aligned memory regions
    m_main_ram = (uint8_t*)calloc(1, EE_MAIN_RAM_SIZE);
    m_iop_ram = (uint8_t*)calloc(1, EE_IOP_RAM_SIZE);
    m_scratchpad = (uint8_t*)calloc(1, EE_SCRATCHPAD_SIZE);
    m_bios_rom = (uint8_t*)calloc(1, EE_BIOS_SIZE);
    m_vu0_code = (uint8_t*)calloc(1, 4096);
    m_vu0_data = (uint8_t*)calloc(1, 4096);
    m_vu1_code = (uint8_t*)calloc(1, 16384);
    m_vu1_data = (uint8_t*)calloc(1, 16384);

    if (!m_main_ram || !m_iop_ram || !m_scratchpad || !m_bios_rom || !m_vu0_code || !m_vu0_data ||
        !m_vu1_code || !m_vu1_data) {
        fprintf(stderr, "[MEM] Failed to allocate PS2 memory regions\n");
        return false;
    }

    printf("[MEM] Allocated: Main RAM 32MB, IOP RAM 2MB, SPR 16KB, BIOS 4MB\n");
    printf("[MEM] Allocated: VU0 8KB, VU1 32KB\n");
    return true;
}

void Memory::reset() {
    memset(m_main_ram, 0, EE_MAIN_RAM_SIZE);
    memset(m_iop_ram, 0, EE_IOP_RAM_SIZE);
    memset(m_scratchpad, 0, EE_SCRATCHPAD_SIZE);
    memset(m_vu0_code, 0, 4096);
    memset(m_vu0_data, 0, 4096);
    memset(m_vu1_code, 0, 16384);
    memset(m_vu1_data, 0, 16384);
    // BIOS ROM is not cleared on reset
}

uint32_t Memory::translate_address(uint32_t vaddr) const {
    // KSEG0 (0x80000000) and KSEG1 (0xA0000000) → physical
    if (vaddr >= EE_KSEG1_BASE) {
        return vaddr & PHYS_ADDR_MASK;
    }
    if (vaddr >= EE_KSEG0_BASE) {
        return vaddr & PHYS_ADDR_MASK;
    }

    // Scratchpad at 0x70000000
    if (vaddr >= EE_SCRATCHPAD_BASE && vaddr < EE_SCRATCHPAD_BASE + EE_SCRATCHPAD_SIZE) {
        return vaddr; // Keep as-is, handled specially
    }

    // Uncached accelerated mirror at 0x30000000
    if (vaddr >= EE_UNCACHED_ACC && vaddr < EE_UNCACHED_ACC + EE_MAIN_RAM_SIZE) {
        return vaddr - EE_UNCACHED_ACC;
    }

    // Uncached mirror at 0x20000000
    if (vaddr >= EE_UNCACHED_BASE && vaddr < EE_UNCACHED_BASE + EE_MAIN_RAM_SIZE) {
        return vaddr - EE_UNCACHED_BASE;
    }

    // KUSEG — direct mapping
    return vaddr;
}

uint8_t* Memory::get_pointer(uint32_t vaddr) {
    uint32_t paddr = translate_address(vaddr);

    // Scratchpad
    if (vaddr >= EE_SCRATCHPAD_BASE && vaddr < EE_SCRATCHPAD_BASE + EE_SCRATCHPAD_SIZE) {
        return m_scratchpad + (vaddr - EE_SCRATCHPAD_BASE);
    }

    // Main RAM
    if (paddr < EE_MAIN_RAM_SIZE) {
        return m_main_ram + paddr;
    }

    // IOP RAM
    if (paddr >= EE_IOP_RAM_BASE && paddr < EE_IOP_RAM_BASE + EE_IOP_RAM_SIZE) {
        return m_iop_ram + (paddr - EE_IOP_RAM_BASE);
    }

    // BIOS ROM
    if (paddr >= EE_BIOS_BASE && paddr < EE_BIOS_BASE + EE_BIOS_SIZE) {
        return m_bios_rom + (paddr - EE_BIOS_BASE);
    }

    // VU memories
    if (paddr >= EE_VU0_CODE_BASE && paddr < EE_VU0_CODE_BASE + 4096) {
        return m_vu0_code + (paddr - EE_VU0_CODE_BASE);
    }
    if (paddr >= EE_VU0_DATA_BASE && paddr < EE_VU0_DATA_BASE + 4096) {
        return m_vu0_data + (paddr - EE_VU0_DATA_BASE);
    }
    if (paddr >= EE_VU1_CODE_BASE && paddr < EE_VU1_CODE_BASE + 16384) {
        return m_vu1_code + (paddr - EE_VU1_CODE_BASE);
    }
    if (paddr >= EE_VU1_DATA_BASE && paddr < EE_VU1_DATA_BASE + 16384) {
        return m_vu1_data + (paddr - EE_VU1_DATA_BASE);
    }

    // MMIO regions return nullptr (must use read/write functions)
    return nullptr;
}

const uint8_t* Memory::get_pointer(uint32_t vaddr) const {
    return const_cast<Memory*>(this)->get_pointer(vaddr);
}

uint32_t Memory::read32(uint32_t vaddr) {
    uint32_t paddr = translate_address(vaddr);

    // Check MMIO regions first
    if (paddr >= EE_IO_BASE && paddr < 0x20000000) {
        for (int i = 0; i < m_mmio_count; i++) {
            auto& r = m_mmio_regions[i];
            if (paddr >= r.base && paddr < r.base + r.size && r.read) {
                return r.read(paddr);
            }
        }
        // Unhandled MMIO read
        return 0;
    }

    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        uint32_t val;
        memcpy(&val, ptr, sizeof(val));
        return val;
    }

    fprintf(stderr, "[MEM] Unhandled read32 at 0x%08X (phys 0x%08X)\n", vaddr, paddr);
    return 0;
}

void Memory::write32(uint32_t vaddr, uint32_t value) {
    uint32_t paddr = translate_address(vaddr);

    // Check MMIO regions
    if (paddr >= EE_IO_BASE && paddr < 0x20000000) {
        for (int i = 0; i < m_mmio_count; i++) {
            auto& r = m_mmio_regions[i];
            if (paddr >= r.base && paddr < r.base + r.size && r.write) {
                r.write(paddr, value);
                return;
            }
        }
        // Unhandled MMIO write — silently ignore for now
        return;
    }

    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        memcpy(ptr, &value, sizeof(value));
        return;
    }

    fprintf(stderr, "[MEM] Unhandled write32 at 0x%08X = 0x%08X\n", vaddr, value);
}

uint8_t Memory::read8(uint32_t vaddr) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr)
        return *ptr;
    return (uint8_t)read32(vaddr & ~3) >> ((vaddr & 3) * 8);
}

uint16_t Memory::read16(uint32_t vaddr) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        uint16_t val;
        memcpy(&val, ptr, sizeof(val));
        return val;
    }
    return (uint16_t)(read32(vaddr & ~3) >> ((vaddr & 2) * 8));
}

uint64_t Memory::read64(uint32_t vaddr) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        uint64_t val;
        memcpy(&val, ptr, sizeof(val));
        return val;
    }
    uint64_t lo = read32(vaddr);
    uint64_t hi = read32(vaddr + 4);
    return lo | (hi << 32);
}

void Memory::read128(uint32_t vaddr, void* out) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        memcpy(out, ptr, 16);
        return;
    }
    uint32_t* o = (uint32_t*)out;
    o[0] = read32(vaddr);
    o[1] = read32(vaddr + 4);
    o[2] = read32(vaddr + 8);
    o[3] = read32(vaddr + 12);
}

void Memory::write8(uint32_t vaddr, uint8_t value) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        *ptr = value;
        return;
    }
    fprintf(stderr, "[MEM] Unhandled write8 at 0x%08X = 0x%02X\n", vaddr, value);
}

void Memory::write16(uint32_t vaddr, uint16_t value) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        memcpy(ptr, &value, sizeof(value));
        return;
    }
    fprintf(stderr, "[MEM] Unhandled write16 at 0x%08X = 0x%04X\n", vaddr, value);
}

void Memory::write64(uint32_t vaddr, uint64_t value) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        memcpy(ptr, &value, sizeof(value));
        return;
    }
    write32(vaddr, (uint32_t)value);
    write32(vaddr + 4, (uint32_t)(value >> 32));
}

void Memory::write128(uint32_t vaddr, const void* data) {
    uint8_t* ptr = get_pointer(vaddr);
    if (ptr) {
        memcpy(ptr, data, 16);
        return;
    }
    const uint32_t* d = (const uint32_t*)data;
    write32(vaddr, d[0]);
    write32(vaddr + 4, d[1]);
    write32(vaddr + 8, d[2]);
    write32(vaddr + 12, d[3]);
}

void Memory::register_mmio_read(uint32_t base, uint32_t size, MmioReadHandler handler) {
    if (m_mmio_count >= MAX_MMIO_REGIONS) {
        fprintf(stderr, "[MEM] Too many MMIO regions!\n");
        return;
    }
    m_mmio_regions[m_mmio_count].base = base;
    m_mmio_regions[m_mmio_count].size = size;
    m_mmio_regions[m_mmio_count].read = handler;
    if (!m_mmio_regions[m_mmio_count].write) {
        m_mmio_count++;
    }
}

void Memory::register_mmio_write(uint32_t base, uint32_t size, MmioWriteHandler handler) {
    // Check if a read handler already exists for this region
    for (int i = 0; i < m_mmio_count; i++) {
        if (m_mmio_regions[i].base == base && m_mmio_regions[i].size == size) {
            m_mmio_regions[i].write = handler;
            return;
        }
    }

    if (m_mmio_count >= MAX_MMIO_REGIONS) {
        fprintf(stderr, "[MEM] Too many MMIO regions!\n");
        return;
    }
    m_mmio_regions[m_mmio_count].base = base;
    m_mmio_regions[m_mmio_count].size = size;
    m_mmio_regions[m_mmio_count].write = handler;
    m_mmio_count++;
}

} // namespace reo
