#pragma once
#include "runtime/ps2_gif_arbiter.h"
#include <cstdint>
#include <vector>
constexpr uint32_t PS2_RAM_SIZE = 32u * 1024u * 1024u;
class PS2Memory {
  public:
    struct {
        uint32_t top = 0, tops = 0, itop = 0;
    } vif1_regs;
    std::vector<std::vector<uint8_t>> packets;
    uint8_t* diagnosticRAM = nullptr;
    uint8_t* getRDRAM() {
        return diagnosticRAM;
    }
    void setDiagnosticRAM(uint8_t* ram) {
        diagnosticRAM = ram;
    }
    void submitGifPacket(GifPathId, const uint8_t* data, uint32_t size, bool = true, bool = false) {
        packets.emplace_back(data, data + size);
    }
};
