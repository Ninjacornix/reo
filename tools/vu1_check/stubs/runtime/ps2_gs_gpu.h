#pragma once
#include <cstdint>
#include <vector>
// Only the packet sink is replaced. Instruction execution is production code.
class GS {
  public:
    std::vector<std::vector<uint8_t>> packets;
    void processGIFPacket(const uint8_t* data, uint32_t size) {
        packets.emplace_back(data, data + size);
    }
};
