// Offline original-body schedule extraction only. No production unit includes
// this original instruction/register test harness.
#include "reference.hpp"
#include <iostream>
#include <fstream>
#include <vector>
struct Item {
    std::uint32_t kind{}, frame{}, a{}, b{}, c{};
    friend bool operator==(const Item&, const Item&) = default;
};
std::vector<Item> trace;
constexpr std::uint32_t actor = 0x100000;
bool lower_phase{};
struct ReachedUpper {};
template <class T> T observed_read(std::uint8_t* p, std::uint32_t at) {
    const auto value = transform_read<T>(p, at);
    if constexpr (sizeof(T) == 2) {
        if (at == actor + 0x212 && lower_phase)
            throw ReachedUpper{};
    }
    if constexpr (sizeof(T) == 1) {
        if (at == actor + 2)
            trace.push_back({0x100, 0, std::uint32_t(value == 0)});
        if (at == actor + 0x54f)
            trace.push_back({0x101, 0, std::uint32_t(value == 0x39)});
    }
    if constexpr (sizeof(T) == 4) {
        if (at == 0x719a60)
            trace.push_back({0x102, 0, std::uint32_t((value & 0x20) != 0)});
    }
    return value;
}
#undef READ8
#undef READ16
#undef READ32
#define READ8(at) observed_read<std::uint8_t>(rdram, at)
#define READ16(at) observed_read<std::uint16_t>(rdram, at)
#define READ32(at) observed_read<std::uint32_t>(rdram, at)
#include "functions.h"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original.cpp"
#pragma GCC diagnostic pop
void original_transform_port(std::uint8_t*, R5900Context* c, PS2Runtime*) {
    const auto destination = c->pc;
    const auto frame = GPR_U32(c, 4), a = GPR_U32(c, 6), b = GPR_U32(c, 7), d = GPR_U32(c, 8);
    Item item{destination, frame};
    switch (destination) {
        case 0x595b70:
        case 0x595c00:
        case 0x595fa0:
        case 0x596000:
        case 0x596470:
            item.a = a;
            break;
        case 0x595c90:
        case 0x595d30:
        case 0x596060:
            item.a = a;
            item.b = b;
            break;
        case 0x595dd0:
            item.b = b;
            break;
        case 0x595e30:
            break;
        case 0x596180:
            item.a = a;
            item.b = b;
            item.c = d;
            break;
        case 0x59ebb0:
            item.frame = 0;
            break;
        default:
            throw std::runtime_error("unreviewed event schedule callee");
    }
    if (destination != 0x59ebb0 &&
        std::bit_cast<std::uint32_t>(c->f[12]) != std::bit_cast<std::uint32_t>(1.25f))
        throw std::runtime_error("schedule fails to preserve caller step");
    trace.push_back(item);
    c->pc = GPR_U32(c, 31);
}
void print(unsigned family, unsigned selector, unsigned variant) {
    std::cout << family << ' ' << selector << ' ' << variant;
    for (const auto& i : trace)
        std::cout << ' ' << i.kind << ',' << i.frame << ',' << i.a << ',' << i.b << ',' << i.c;
    std::cout << '\n';
}
int main(int argc, char** argv) try {
    if (argc != 2)
        throw std::runtime_error("owned o2 required");
    std::vector<std::uint8_t> ram(0x2000000);
    {
        std::ifstream f(argv[1], std::ios::binary);
        f.read(reinterpret_cast<char*>(ram.data() + 0x570000), 0x1d3100);
        if (!f)
            throw std::runtime_error("owned o2 read");
    }
    R5900Context ctx;
    PS2Runtime runtime;
    for (unsigned family = 0; family < 3; ++family) {
        for (unsigned selector = 0; selector < 65536; ++selector) {
            const unsigned variants = family < 2 ? 8 : 1;
            for (unsigned v = 0; v < variants; ++v) {
                lower_phase = family < 2 && v == 0;
                // A separate lower-selector trace is generated once per family.
                if (lower_phase) {
                    transform_write(ram.data(), actor + 0x1f2, std::uint16_t(selector));
                    transform_write(ram.data(), actor + 0x212, std::uint16_t(65535));
                    trace.clear();
                    ctx = {};
                    SET_GPR_U32(&ctx, 4, actor);
                    SET_GPR_U32(&ctx, 29, 0x1f00000);
                    SET_GPR_U32(&ctx, 31, 0xabcdef);
                    ctx.f[12] = 1.25f;
                    ctx.pc = family ? 0x59a820 : 0x5965a0;
                    try {
                        if (family)
                            o2_0059A820_0x59a820(ram.data(), &ctx, &runtime);
                        else
                            o2_005965A0_0x5965a0(ram.data(), &ctx, &runtime);
                    } catch (const ReachedUpper&) {
                    }
                    print(family + 3, selector, 0);
                    lower_phase = false;
                }
                transform_write(ram.data(), actor + 0x1f2, std::uint16_t(65535));
                transform_write(ram.data(), actor + 0x212, std::uint16_t(selector));
                ram[actor + 2] = (v & 1) ? 0 : 1;
                ram[actor + 0x54f] = (v & 2) ? 0x39 : 0;
                transform_write(ram.data(), actor + 0xca8, std::uint16_t(0));
                transform_write(ram.data(), 0x719a60, std::uint32_t((v & 4) ? 0x20 : 0));
                trace.clear();
                ctx = {};
                SET_GPR_U32(&ctx, 4, actor);
                SET_GPR_U32(&ctx, 29, 0x1f00000);
                SET_GPR_U32(&ctx, 31, 0xabcdef);
                ctx.f[12] = 1.25f;
                if (family == 0) {
                    ctx.pc = 0x5965a0;
                    o2_005965A0_0x5965a0(ram.data(), &ctx, &runtime);
                }
                if (family == 1) {
                    ctx.pc = 0x59a820;
                    o2_0059A820_0x59a820(ram.data(), &ctx, &runtime);
                }
                if (family == 2) {
                    ctx.pc = 0x59ebb0;
                    o2_0059EBB0_0x59ebb0(ram.data(), &ctx, &runtime);
                }
                if (ctx.pc != 0xabcdef)
                    throw std::runtime_error("original schedule didnot return");
                print(family, selector, v);
            }
        }
    }
} catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    return 1;
}
