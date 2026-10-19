#pragma once
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>
namespace reo_parallel_backend {
inline uint64_t word(const uint8_t* data) {
    uint64_t out;
    std::memcpy(&out, data, 8);
    return out;
}
// Does not execute or reissue a GS command. Observes exact PACKED A+D command
// boundaries so an ordered GPU prefix can complete BEFORE subsequent commands.
class GifBoundaryObserver {
    struct Path {
        uint32_t loops = 0, reg = 0, loop = 0, count = 0, format = 0;
        uint64_t regs = 0;
    };
    std::array<Path, 3> paths_{};

  public:
    struct Boundary {
        size_t end;
        uint8_t addr;
        uint64_t value;
    };
    void reset() {
        paths_ = {};
    }
    void consumeImage(uint8_t path, uint32_t bytes) {
        if (path < 1 || path > 3 || !bytes || (bytes & 15u))
            throw std::invalid_argument("Invalid resident IMAGE observer fragment");
        auto& p = paths_[path - 1];
        if (p.format != 2u || p.reg || p.loop > p.loops || bytes / 16u > p.loops - p.loop)
            throw std::runtime_error(
                "Resident IMAGE differs from actual GIF observer continuation");
        p.loop += bytes / 16u;
    }
    std::vector<Boundary> observe(uint8_t path, const uint8_t* data, size_t bytes) {
        if (path < 1 || path > 3 || !data || (bytes & 15))
            throw std::invalid_argument("Invalid GIF observer input");
        auto& p = paths_[path - 1];
        std::vector<Boundary> out;
        for (size_t offset = 0; offset < bytes; offset += 16) {
            const uint64_t lo = word(data + offset), hi = word(data + offset + 8);
            if (p.loop == p.loops) {
                p = {};
                p.loops = uint32_t(lo & 0x7FFF);
                p.count = uint32_t(lo >> 60) & 15;
                if (!p.count)
                    p.count = 16;
                p.format = uint32_t(lo >> 58) & 3;
                p.regs = hi;
                continue;
            }
            if (p.format == 0) {
                const uint32_t descriptor = uint32_t(p.regs >> (4 * p.reg)) & 15;
                if (descriptor == 14) {
                    const uint8_t addr = uint8_t(hi & 0x7F);
                    if (addr == 0x53 || addr == 0x60 || addr == 0x61 || addr == 0x62)
                        out.push_back({offset + 16, addr, lo});
                }
                if (++p.reg == p.count) {
                    p.reg = 0;
                    ++p.loop;
                }
            } else if (p.format == 1) {
                // REGLIST descriptors cannot address TRXDIR or event registers.
                for (unsigned half = 0; half < 2 && p.loop < p.loops; ++half)
                    if (++p.reg == p.count) {
                        p.reg = 0;
                        ++p.loop;
                    }
            } else
                ++p.loop; // IMAGE / IMAGE2, one quadword per loop.
        }
        return out;
    }
};
class ByteFifo {
    std::vector<uint8_t> bytes_;
    size_t cursor_ = 0;

  public:
    void replace(std::vector<uint8_t> bytes) {
        bytes_ = std::move(bytes);
        cursor_ = 0;
    }
    void clear() {
        bytes_.clear();
        cursor_ = 0;
    }
    size_t remaining() const {
        return bytes_.size() - cursor_;
    }
    uint32_t read(uint8_t* dst, uint32_t maximum) {
        if (!dst && maximum)
            throw std::invalid_argument("Null FIFO destination");
        const size_t count = std::min<size_t>(maximum, remaining());
        if (count)
            std::memcpy(dst, bytes_.data() + cursor_, count);
        cursor_ += count;
        return uint32_t(count);
    }
};
inline uint64_t mergeLane(uint64_t old, uint32_t lane, uint8_t width, uint64_t input) {
    if ((width != 1 && width != 2 && width != 4 && width != 8) || (lane & (width - 1)) ||
        lane + width > 8)
        throw std::invalid_argument("Invalid privileged byte lane");
    const uint64_t mask =
        width == 8 ? ~uint64_t(0) : ((uint64_t(1) << (8 * width)) - 1) << (8 * lane);
    return (old & ~mask) | ((input << (8 * lane)) & mask);
}
inline constexpr std::array<uint32_t, 19> privilegedOffsets = {
    0x00, 0x10, 0x20, 0x30, 0x40, 0x50,   0x60,   0x70,   0x80,  0x90,
    0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0x1000, 0x1010, 0x1040, 0x1080};
} // namespace reo_parallel_backend
