#pragma once
#include "runtime/memory_card/card_rpc.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "source_instruction_access.hpp"

namespace reo::mc2 {
inline memory_card::Service& service() {
    static memory_card::Service cards({PS2Runtime::getIoPaths().mcRoot, {}});
    return cards;
}
class Request {
    uint8_t* ram_;
    static constexpr uint32_t Scratch = 0xfff00000;
    std::vector<uint8_t> scratch_ = std::vector<uint8_t>(128 * 1024);

  public:
    std::vector<uint8_t> packet = std::vector<uint8_t>(1044);
    explicit Request(uint8_t* ram) : ram_(ram) {}
    bool transfer(uint32_t address, void* data, size_t count, bool store) {
        if (address >= Scratch && count <= scratch_.size() &&
            address - Scratch <= scratch_.size() - count) {
            if (store)
                std::memcpy(scratch_.data() + address - Scratch, data, count);
            else
                std::memcpy(data, scratch_.data() + address - Scratch, count);
            return true;
        }
        const uint32_t bank = address & 0xfe000000u;
        if (bank != 0 && bank != 0x20000000u && bank != 0x80000000u && bank != 0xa0000000u)
            return false;
        uint32_t physical = address & 0x1fffffffu;
        if (physical >= 0x02000000u || count > 0x02000000u - physical)
            return false;
        if (store)
            reo_source_instrumentation::copyBytesForBank(ram_, ram_ + physical, data, count);
        else
            reo_source_instrumentation::copyBytesForBank(ram_, data, ram_ + physical, count);
        return true;
    }
    void put(int offset, uint32_t value) {
        std::memcpy(packet.data() + offset, &value, 4);
    }
    bool text(uint32_t address, std::string& result) {
        for (size_t i = 0; i < 128; ++i) {
            char c;
            if (!transfer(address + static_cast<uint32_t>(i), &c, 1, false))
                return false;
            if (!c)
                return true;
            result += c;
        }
        return false;
    }
    bool named(int device, uint32_t address, int flags = 0, int count = 0) {
        std::string path;
        if (!text(address, path))
            return false;
        put(0, device);
        put(4, 0);
        put(8, flags);
        put(12, count);
        put(16, Scratch);
        std::memcpy(packet.data() + 20, path.c_str(), path.size() + 1);
        return true;
    }
    int call(uint32_t cmd) {
        return service().call(
            cmd, packet, [&](uint32_t a, void* p, size_t n) { return transfer(a, p, n, false); },
            [&](uint32_t a, const void* p, size_t n) {
                return transfer(a, const_cast<void*>(p), n, true);
            });
    }
    uint8_t* scratch() {
        return scratch_.data();
    }
    static uint32_t scratchAddress() {
        return Scratch;
    }
    static int error(int code) {
        if (code >= 0)
            return code;
        switch (code) {
            case -1:
                return static_cast<int>(0x8101006fu);
            case -2:
                return static_cast<int>(0x8101002fu);
            case -3:
                return static_cast<int>(0x8101001cu);
            case -4:
                return static_cast<int>(0x81010002u);
            case -6:
                return static_cast<int>(0x8101005au);
            case -7:
                return static_cast<int>(0x81010018u);
            default:
                return static_cast<int>(0x8101000du);
        }
    }
    static void converted(const uint8_t* source, uint8_t* out) {
        std::memcpy(out, source, 16);
        std::memcpy(out + 16, source + 16, 4);
        std::memcpy(out + 20, source + 20, 2);
        std::memcpy(out + 24, source + 32, 32);
    }
    void finish(R5900Context* ctx, int result) {
        uint8_t* rdram = ram_;
        SET_GPR_S32(ctx, 2, result);
        ctx->pc = GPR_U32(ctx, 31);
    }
};
inline void info(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int device = GPR_U32(ctx, 4);
    r.put(4, device);
    r.put(28, r.scratchAddress());
    int result = r.call(1);
    std::array<uint32_t, 3> output{};
    std::memcpy(&output[0], r.scratch(), 4);
    std::memcpy(&output[1], r.scratch() + 144, 4);
    std::memcpy(&output[2], r.scratch() + 4, 4);
    uint32_t target = GPR_U32(ctx, 5);
    if (target && !r.transfer(target, output.data(), sizeof(output), true))
        result = -5;
    // libmc2 reports card insertion separately from ordinary I/O errors.
    int code =
        result == -1 && output[0] == 2 ? static_cast<int>(0x81019003u) : Request::error(result);
    static unsigned logged = 0;
    if (++logged <= 24)
        std::fprintf(stderr, "[MC2] info device=%d type=%u format=%u free=%u result=%08x\n", device,
                     output[0], output[1], output[2], unsigned(code));
    r.finish(ctx, code);
}
inline void create(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int attrs = GPR_U32(ctx, 6);
    int result = -5;
    if (r.named(GPR_U32(ctx, 4), GPR_U32(ctx, 5), (attrs & 0x20) ? 0x40 : 0x203)) {
        // Creation never truncates an existing save.
        auto packet = r.packet;
        r.put(8, 0);
        r.put(12, 1);
        int exists = r.call(13);
        r.packet = packet;
        if (exists > 0)
            result = static_cast<int>(0x81010011u);
        else {
            result = r.call(2);
            if (result >= 0 && !(attrs & 0x20)) {
                r.put(0, result);
                result = r.call(3);
            } else if (result == -4)
                result = static_cast<int>(0x81010011u);
            else
                result = Request::error(result);
        }
    }
    std::fprintf(stderr, "[MC2] create result=%08x\n", unsigned(result));
    r.finish(ctx, result);
}
template <bool Store> inline void data(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int result = -5;
    int device = GPR_U32(ctx, 4), offset = GPR_U32(ctx, 7), length = GPR_U32(ctx, 8);
    uint32_t buffer = GPR_U32(ctx, 6);
    if (offset >= 0 && length >= 0 && r.named(device, GPR_U32(ctx, 5), Store ? 3 : 1)) {
        if constexpr (!Store) {
            if (!length) {
                auto p = r.packet;
                r.put(8, 0);
                r.put(12, 1);
                int found = r.call(13);
                uint32_t size = 0;
                std::memcpy(&size, r.scratch() + 16, 4);
                r.packet = p;
                if (found > 0)
                    length = std::max(0, static_cast<int>(size) - offset);
            }
        }
        int fd = r.call(2);
        result = fd;
        if (fd >= 0) {
            r.packet.assign(48, 0);
            r.put(0, fd);
            r.put(16, offset);
            r.put(20, 0);
            result = r.call(4);
            if (result >= 0) {
                r.put(12, length);
                r.put(24, buffer);
                r.put(28, r.scratchAddress());
                result = r.call(Store ? 6 : 5);
            }
            int close = r.call(3);
            if (result >= 0 && close < 0)
                result = close;
        }
    }
    std::fprintf(stderr, "[MC2] %s bytes=%d result=%d\n", Store ? "write" : "read", length, result);
    r.finish(ctx, Request::error(result));
}
inline void remove(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int result = r.named(GPR_U32(ctx, 4), GPR_U32(ctx, 5)) ? r.call(15) : -5;
    r.finish(ctx, Request::error(result));
}
inline void stat(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int result = -5;
    if (r.named(GPR_U32(ctx, 4), GPR_U32(ctx, 5), 0, 1))
        result = r.call(13);
    if (result > 0) {
        // libmc2's internal 512-byte directory entry differs from libmc's table.
        std::array<uint8_t, 512> entry{};
        auto* src = r.scratch();
        std::memcpy(entry.data(), src + 20, 2);
        std::memcpy(entry.data() + 4, src + 16, 4);
        std::memcpy(entry.data() + 8, src, 8);
        std::memcpy(entry.data() + 24, src + 8, 8);
        std::memcpy(entry.data() + 64, src + 32, 32);
        if (!r.transfer(GPR_U32(ctx, 6), entry.data(), entry.size(), true))
            result = -5;
        else
            result = static_cast<int>(0x81010011u);
    } else
        result = Request::error(result == 0 ? -4 : result);
    r.finish(ctx, result);
}
inline void directory(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int skip = GPR_U32(ctx, 6), limit = static_cast<int>(GPR_U32(ctx, 7));
    uint32_t output = GPR_U32(ctx, 8), countOut = GPR_U32(ctx, 9);
    int count = 0, result = -5;
    if (skip >= 0 && limit >= -1 && limit <= 1024 &&
        r.named(GPR_U32(ctx, 4), GPR_U32(ctx, 5), 0, 1024)) {
        int entries = r.call(13);
        result = entries < 0 ? entries : 0;
        if (entries >= 0)
            for (int i = std::min(skip, entries); i < entries; ++i) {
                if (output && limit > 0 && count >= limit)
                    break;
                if (output && limit > 0) {
                    std::array<uint8_t, 56> entry{};
                    Request::converted(r.scratch() + 64 * i, entry.data());
                    if (!r.transfer(output + 56 * count, entry.data(), entry.size(), true)) {
                        result = -5;
                        break;
                    }
                }
                ++count;
            }
        if (result == 0 && countOut && !r.transfer(countOut, &count, 4, true))
            result = -5;
    }
    std::fprintf(stderr, "[MC2] directory entries=%d result=%d path=%.*s\n", count, result, 128,
                 reinterpret_cast<const char*>(r.packet.data() + 20));
    r.finish(ctx, Request::error(result));
}
template <int Command> inline void format(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    r.put(4, GPR_U32(ctx, 4));
    r.finish(ctx, Request::error(r.call(Command)));
}
inline void chdir(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int result = -5;
    if (r.named(GPR_U32(ctx, 4), GPR_U32(ctx, 5))) {
        result = r.call(12);
        if (result == 0 && GPR_U32(ctx, 6))
            result = r.transfer(GPR_U32(ctx, 6), r.scratch(), 128, true) ? 0 : -5;
    }
    r.finish(ctx, Request::error(result));
}
inline void chmod(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    int result = -5;
    if (r.named(GPR_U32(ctx, 4), GPR_U32(ctx, 5), 0, 1)) {
        result = r.call(13);
        if (result > 0) {
            uint16_t attrs;
            std::memcpy(&attrs, r.scratch() + 20, 2);
            attrs = (attrs & 0xe7f0) | (GPR_U32(ctx, 6) & 0x180f);
            std::memcpy(r.scratch() + 20, &attrs, 2);
            r.put(8, 4);
            result = r.call(14);
        } else if (!result)
            result = -4;
    }
    r.finish(ctx, Request::error(result));
}
inline void rename(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    std::string from, to;
    int result = -5;
    if (r.text(GPR_U32(ctx, 5), from) && r.text(GPR_U32(ctx, 6), to))
        result = service().rename(GPR_U32(ctx, 4), from, to);
    r.finish(ctx, Request::error(result));
}
inline void space(uint8_t* ram, R5900Context* ctx, PS2Runtime*) {
    Request r(ram);
    std::string name;
    int result = -5;
    if (r.text(GPR_U32(ctx, 5), name))
        result = service().entrySpace(GPR_U32(ctx, 4), name);
    r.finish(ctx, Request::error(result));
}
inline void install(PS2Runtime& runtime) {
    // SLUS-20765 libmc2 worker backends. Original request thread, semaphore,
    // completion status and public API remain guest code.
    runtime.registerFunction(0x183290, info);
    runtime.registerFunction(0x185280, create);
    runtime.registerFunction(0x184828, data<false>);
    runtime.registerFunction(0x1858c8, data<true>);
    runtime.registerFunction(0x185e40, remove);
    runtime.registerFunction(0x184360, stat);
    runtime.registerFunction(0x186230, directory);
    runtime.registerFunction(0x183670, format<16>);
    runtime.registerFunction(0x183fc8, format<17>);
    runtime.registerFunction(0x1860b0, chdir);
    runtime.registerFunction(0x186798, chmod);
    runtime.registerFunction(0x1868c8, rename);
    runtime.registerFunction(0x186a88, space);
}
} // namespace reo::mc2
