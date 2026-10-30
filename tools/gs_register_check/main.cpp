#include "../../runtime/gs/gs_renderer.h"
#include <algorithm>
#include <cstdio>
#include <memory>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() {
    auto renderer = std::make_unique<reo::GSRenderer>();
    if (!renderer->init(16, 16, false, true)) return 1;
    unsigned checks = 0;
    auto check = [&](bool value) { ++checks; return value; };
    if (!check(renderer->read_register(reo::GS_CSR) == 0x55)) return 2;
    if (!check(std::all_of(renderer->vram(), renderer->vram() + reo::GSRenderer::VRAM_SIZE,
                           [](uint8_t value) { return value == 0; }))) return 3;
    // Check both 4 KiB privileged-register blocks and the highest decoded slot.
    for (uint32_t offset : {reo::GS_PMODE, reo::GS_BGCOLOR, reo::GS_CSR,
                            reo::GS_IMR, reo::GS_BUSDIR, reo::GS_SIGLBLID, 0x1FF0u}) {
        const uint64_t value = 0x1234567800000000ull + offset;
        renderer->write_register(offset, value);
        if (!check(renderer->read_register(offset) == value)) return 4;
    }
    if (!check(std::all_of(renderer->vram(), renderer->vram() + reo::GSRenderer::VRAM_SIZE,
                           [](uint8_t value) { return value == 0; }))) return 5;
    renderer->shutdown();
    std::printf("PASS %u GS register checks: CSR, both address blocks and intact VRAM\n", checks);
}
