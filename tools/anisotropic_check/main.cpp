// SPDX-License-Identifier: GPL-3.0-only
#include "context.hpp"
#include "device.hpp"
#include "gs_interface.hpp"
#include "gs_util.hpp"
#include "thread_id.hpp"
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace ParallelGS;
static uint32_t bits(float v) {
    uint32_t result;
    std::memcpy(&result, &v, 4);
    return result;
}
int main(int argc, char** argv) try {
    if (argc < 2 || argc > 3)
        throw std::runtime_error("Usage: anisotropic_check OUTPUT.rgba [CLAMP_MODE_0_TO_3]");
    unsigned clampMode = argc == 3 ? unsigned(std::strtoul(argv[2], nullptr, 10)) : 0;
    if (clampMode > 3)
        throw std::runtime_error("Invalid clamp mode");
    Util::register_thread_index(0);
    if (!Vulkan::Context::init_loader(nullptr))
        throw std::runtime_error("Vulkan loader");
    Vulkan::Context context;
    context.set_num_thread_indices(1);
    if (!context.init_instance_and_device(nullptr, 0, nullptr, 0,
                                          Vulkan::CONTEXT_CREATION_ENABLE_PUSH_DESCRIPTOR_BIT |
                                              Vulkan::CONTEXT_CREATION_ENABLE_DESCRIPTOR_HEAP_BIT))
        throw std::runtime_error("Vulkan device");
    Vulkan::Device device;
    device.set_context(context);
    device.init_frame_contexts(4);
    GSInterface gs;
    if (!gs.init(&device, {}))
        throw std::runtime_error("GS init");
    constexpr unsigned bytes = 4 * 1024 * 1024, textureBase = 4096;
    auto* vram = static_cast<uint32_t*>(gs.map_vram_write(0, bytes));
    std::memset(vram, 0, bytes);
    for (unsigned y = 0; y < 64; ++y)
        for (unsigned x = 0; x < 64; ++x)
            vram[swizzle_PS2(x, y, textureBase, 1, PSMCT32, bytes - 1)] =
                (x & 1) ? 0x80ffffff : 0x80000000;
    gs.end_vram_write(0, bytes);
    auto reg = [&](unsigned addr, uint64_t value) { gs.write_register(RegisterAddr(addr), value); };
    reg(0x1a, 1);
    reg(0x4c, 4ull << 16);
    reg(0x4e, 224ull | (1ull << 32));
    reg(0x40, (255ull << 16) | (255ull << 48));
    reg(0x47, 0x30000);
    reg(0x18, 0);
    reg(0x46, 1);
    // 64x64 RGBA32 texture, DECAL, original bilinear filter, repeat addressing.
    reg(0x06,
        textureBase | (1ull << 14) | (6ull << 26) | (6ull << 30) | (1ull << 34) | (1ull << 35));
    reg(0x14, (1ull << 5) | (1ull << 6));
    reg(0x08, ((clampMode & 1) ? 1 : 0) | ((clampMode & 2) ? 4 : 0));
    auto vertex = [&](unsigned x, unsigned y, float s, float t, bool fixed) {
        reg(1, 0x3f80000080808080ull);
        if (fixed)
            reg(3, uint64_t(unsigned(s * 64 * 16)) | (uint64_t(unsigned(t * 64 * 16)) << 16));
        else
            reg(2, uint64_t(bits(s)) | (uint64_t(bits(t)) << 32));
        reg(5, uint64_t(x * 16) | (uint64_t(y * 16) << 16));
    };
    auto tile = [&](unsigned ox, unsigned oy, bool fixed, bool sprite, float sx, float sy) {
        reg(0, (sprite ? 6 : 3) | (1ull << 4) | (uint64_t(fixed) << 8));
        auto v = [&](unsigned x, unsigned y) {
            vertex(ox + x, oy + y, 0.123f + float(x) * sx / 64.0f, 0.31f + float(y) * sy / 64.0f,
                   fixed);
        };
        if (sprite) {
            v(0, 0);
            v(120, 120);
        } else {
            v(0, 0);
            v(120, 0);
            v(0, 120);
            v(120, 0);
            v(120, 120);
            v(0, 120);
        }
    };
    tile(0, 0, false, false, 8.3f, 0.5f);
    tile(128, 0, true, false, 8.3f, 0.5f);
    tile(0, 128, false, true, 8.3f, 0.5f);
    tile(128, 128, false, false, 0.25f, 0.25f);
    gs.flush();
    const void* result = gs.map_vram_read(0, bytes);
    std::vector<uint32_t> rgba(256 * 256);
    vram_readback<PSMCT32>(rgba.data(), result, 0, 4, 0, 0, 256, 256, bytes - 1);
    std::ofstream file(argv[1], std::ios::binary);
    file.write(reinterpret_cast<const char*>(rgba.data()), rgba.size() * 4);
    if (!file)
        throw std::runtime_error("Output write");
    std::cout << "PASS GPU texture fixture: 256x256 RGBA\n";
    return 0;
} catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return 1;
}
