#pragma once
#include <atomic>
#include <cstdint>
#include <functional>
class ReoHwBridge {
public:
    ReoHwBridge() { current = this; }
    ~ReoHwBridge() { current = nullptr; }
    static ReoHwBridge* instance() { return current; }
    bool readCdSectors(std::uint32_t lsn, std::uint32_t count, std::uint32_t destination, std::uint8_t* memory) {
        ++reads;
        return on_read ? on_read(lsn, count, destination, memory) : true;
    }
    inline static ReoHwBridge* current{};
    std::atomic<unsigned> reads{0};
    std::function<bool(std::uint32_t, std::uint32_t, std::uint32_t, std::uint8_t*)> on_read;
};
