// Real GS pixels/depth, synthetic resources, independent fixed-address checks.
#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmct16.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

static unsigned failures = 0, checks = 0;
int main(int argc, char** argv) {
    const bool expectBug = argc == 2 && !std::strcmp(argv[1], "--expect-current-bug");
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE, 0);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), uint32_t(vram.size()), &regs);
    constexpr unsigned x = 12, y = 20;
    constexpr uint32_t oldColor = 0x80445566, newColor = 0x20112233;
    const uint32_t fb = GSPSMCT32::addrPSMCT32(0, 1, x, y);
    auto read = [&](unsigned off, unsigned size = 4) {
        uint32_t value = 0;
        std::memcpy(&value, vram.data() + off, size);
        return value;
    };
    auto store = [&](unsigned off, uint32_t value, unsigned size = 4) {
        std::memcpy(vram.data() + off, &value, size);
    };
    auto check = [&](bool value, const char* name) {
        ++checks;
        failures += !value;
        std::printf("%s %s\n", value ? "PASS" : "FAIL", name);
    };
    auto setup = [&](uint64_t test, unsigned psm = 0, bool zmask = false, unsigned framePsm = 0) {
        std::memset(vram.data(), 0, vram.size());
        gs.writeRegister(GS_REG_FRAME_1, (1ull << 16) | (uint64_t(framePsm) << 24));
        gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (63ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_TEST_1, test);
        gs.writeRegister(GS_REG_ZBUF_1, 4ull | (uint64_t(psm) << 24) | (uint64_t(zmask) << 32));
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_POINT);
        store(fb, oldColor);
    };
    auto plot = [&](uint32_t z, uint32_t color = 0x20112233u) {
        gs.writeRegister(GS_REG_RGBAQ, color | (0x3f800000ull << 32));
        gs.writeRegister(GS_REG_XYZ2,
                         uint64_t(x * 16) | (uint64_t(y * 16) << 16) | (uint64_t(z) << 32));
        gs.getLastDisplayBaseBytes();
    };
    // Independently calculated address at ZBP4, FBW1, x12/y20. Z32/24 use
    // CT32 block17 (CT block9 xor24), column40; Z16/Z16S blocks28/16.
    const unsigned formats[] = {0, 1, 2, 10}, offsets[] = {0x91a0, 0x91a0, 0x9ca2, 0x90a2};
    for (unsigned i = 0; i < 4; ++i) {
        const unsigned size = i < 2 ? 4 : 2;
        for (unsigned func = 0; func < 4; ++func)
            for (unsigned src = 99; src <= 101; ++src) {
                setup((1u << 16) | (func << 17), formats[i]);
                store(offsets[i], i == 1 ? 0xab000064u : 100u, size);
                plot(src);
                const bool passes =
                    func == 1 || (func == 2 && src >= 100) || (func == 3 && src > 100);
                const uint32_t expectedZ = passes ? src : 100;
                const uint32_t actualZ =
                    read(offsets[i], size) & (i == 1 ? 0xffffffu : 0xffffffffu);
                char name[120];
                std::snprintf(name, sizeof(name), "Z format=%u func=%u source=%u color+depth",
                              formats[i], func, src);
                check(read(fb) == (passes ? newColor : oldColor) && actualZ == expectedZ, name);
                if (i == 1)
                    check((read(offsets[i]) >> 24) == 0xab, "Z24 preserves high byte");
            }
    }
    setup((1u << 16) | (3u << 17), 0, true);
    store(0x91a0, 100);
    plot(101);
    check(read(fb) == newColor && read(0x91a0) == 100,
          "ZMSK suppresses write but retains greater test");
    setup((1u << 16) | (3u << 17), 0, true);
    store(0x91a0, 100);
    plot(99);
    check(read(fb) == oldColor && read(0x91a0) == 100, "ZMSK does not bypass rejecting depth test");
    setup(0);
    store(0x91a0, 100);
    plot(99);
    check(read(fb) == newColor && read(0x91a0) == 100,
          "ZTE0 keeps 2D color and never writes depth");
    setup((1u << 16) | (3u << 17));
    store(0x91a0, 0xf0000011u);
    plot(0xf0000012u);
    check(read(fb) == newColor && read(0x91a0) == 0xf0000012u,
          "Z32 exact adjacent high unsigned integers");
    for (unsigned afail = 0; afail < 4; ++afail) {
        setup(1u | (afail << 12) | (1u << 16) | (1u << 17)); // ATE NEVER, Z ALWAYS.
        store(0x91a0, 100);
        plot(101);
        const uint32_t color = afail == 1   ? newColor
                               : afail == 3 ? (newColor & 0xffffff) | (oldColor & 0xff000000)
                                            : oldColor;
        char name[96];
        std::snprintf(name, sizeof(name), "ATE fail mode=%u independently masks framebuffer/depth",
                      afail);
        check(read(fb) == color && read(0x91a0) == (afail == 2 ? 101u : 100u), name);
    }
    setup(1u | (2u << 12) | (1u << 16) | (3u << 17));
    store(0x91a0, 100);
    plot(99);
    check(read(fb) == oldColor && read(0x91a0) == 100,
          "Z failure rejects AFAIL ZB_ONLY depth write");
    for (unsigned datm = 0; datm < 2; ++datm)
        for (unsigned destMsb = 0; destMsb < 2; ++destMsb) {
            setup((1u << 14) | (datm << 15) | (1u << 16) | (1u << 17));
            const uint32_t destination = (oldColor & 0x7fffffff) | (destMsb << 31);
            store(fb, destination);
            store(0x91a0, 100);
            plot(101);
            const bool passes = datm == destMsb;
            check(read(fb) == (passes ? newColor : destination) &&
                      read(0x91a0) == (passes ? 101u : 100u),
                  "DATE/DATM reject or accept both color and depth");
        }
    setup((1u << 14) | (1u << 16) | (1u << 17), 0, false, GS_PSM_CT24);
    store(0x91a0, 100);
    plot(101);
    check(read(fb) == oldColor && read(0x91a0) == 100,
          "CT24 with DATE rejects entire draw (hardware reference)");
    const uint32_t fb16 = GSPSMCT16::addrPSMCT16(0, 1, x, y);
    for (unsigned datm = 0; datm < 2; ++datm)
        for (unsigned destMsb = 0; destMsb < 2; ++destMsb) {
            setup((1u << 14) | (datm << 15) | (1u << 16) | (1u << 17), 0, false, GS_PSM_CT16);
            const uint16_t destination = uint16_t(0x1234 | (destMsb << 15));
            store(fb16, destination, 2);
            store(0x91a0, 100);
            plot(101);
            const bool passes = datm == destMsb;
            check((passes ? read(fb16, 2) != destination : read(fb16, 2) == destination) &&
                      read(0x91a0) == (passes ? 101u : 100u),
                  "CT16 DATE reads bit15 and rejects depth together");
        }
    // Sprite depth is the second vertex, not a gradient or first vertex.
    setup((1u << 16) | (3u << 17));
    store(0x91a0, 100);
    gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE);
    gs.writeRegister(GS_REG_RGBAQ, newColor | (0x3f800000ull << 32));
    gs.writeRegister(GS_REG_XYZ2,
                     uint64_t((x - 1) * 16) | (uint64_t((y - 1) * 16) << 16) | (90ull << 32));
    gs.writeRegister(GS_REG_XYZ2,
                     uint64_t((x + 2) * 16) | (uint64_t((y + 2) * 16) << 16) | (110ull << 32));
    gs.getLastDisplayBaseBytes();
    check(read(fb) == newColor && read(0x91a0) == 110, "sprite uses constant second vertex depth");
    setup((1u << 16) | (3u << 17));
    store(0x91a0, 182);
    gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE);
    gs.writeRegister(GS_REG_RGBAQ, newColor | (0x3f800000ull << 32));
    gs.writeRegister(GS_REG_XYZ2, 64ull | (64ull << 16) | (100ull << 32));
    gs.writeRegister(GS_REG_XYZ2, 576ull | (64ull << 16) | (164ull << 32));
    gs.writeRegister(GS_REG_XYZ2, 64ull | (576ull << 16) | (228ull << 32));
    gs.getLastDisplayBaseBytes();
    check(read(fb) == newColor && read(0x91a0) == 183,
          "triangle interpolates affine Z at pixel center");
    setup((1u << 16) | (2u << 17));
    store(0x91a0, 131);
    gs.writeRegister(GS_REG_PRIM, GS_PRIM_LINE);
    gs.writeRegister(GS_REG_RGBAQ, newColor | (0x3f800000ull << 32));
    gs.writeRegister(GS_REG_XYZ2, 64ull | (uint64_t(y * 16) << 16) | (100ull << 32));
    gs.writeRegister(GS_REG_XYZ2, 576ull | (uint64_t(y * 16) << 16) | (228ull << 32));
    gs.getLastDisplayBaseBytes();
    check(read(fb) == newColor && read(0x91a0) == 132,
          "line interpolates affine Z along raster steps");
    setup((1u << 16) | (1u << 17));
    store(0x91a0, 100);
    gs.writeRegister(GS_REG_FRAME_1, (1ull << 16) | (0xffffffffull << 32));
    plot(101);
    check(read(fb) == oldColor && read(0x91a0) == 101,
          "full framebuffer mask does not mask depth write");
    setup(1u | (3u << 12) | (1u << 16) | (1u << 17), 0, false, GS_PSM_CT16);
    store(fb16, 0x9234u, 2);
    store(0x91a0, 100);
    plot(101);
    check((read(fb16, 2) & 0x8000u) != 0 && read(0x91a0) == 100,
          "CT16 AFAIL RGB_ONLY preserves destination alpha and depth");

    for (unsigned format : {1u, 2u}) {
        const unsigned off = format == 1 ? 0x91a0 : 0x9ca2;
        const unsigned bytes = format == 1 ? 4u : 2u;
        const uint32_t mask = format == 1 ? 0xffffffu : 0xffffu;
        setup((1u << 16) | (2u << 17), format);
        store(off, mask, bytes);
        plot(mask + 2);
        check(read(fb) == newColor && (read(off, bytes) & mask) == mask,
              "point depth clamps overflow to format maximum");
        setup((1u << 16) | (3u << 17), format);
        store(off, mask, bytes);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_SPRITE);
        gs.writeRegister(GS_REG_RGBAQ, newColor | (0x3f800000ull << 32));
        gs.writeRegister(GS_REG_XYZ2, uint64_t((x - 1) * 16) | (uint64_t((y - 1) * 16) << 16));
        gs.writeRegister(GS_REG_XYZ2, uint64_t((x + 2) * 16) | (uint64_t((y + 2) * 16) << 16) |
                                          (uint64_t(mask + 2) << 32));
        gs.getLastDisplayBaseBytes();
        check(read(fb) == newColor && (read(off, bytes) & mask) == 1,
              "sprite raw overflow compares before format write mask");
    }
    // At x32/y0, CT32 framebuffer and Z16 both address byte0x1000 with base0.
    // Blending/masks must read the framebuffer before the overlapping Z write.
    for (unsigned masked = 0; masked < 3; ++masked) {
        setup((1u << 16) | (1u << 17), 2);
        gs.writeRegister(GS_REG_ZBUF_1, 2ull << 24);
        gs.writeRegister(GS_REG_FRAME_1, (1ull << 16) | ((masked == 2 ? 0xffffffffull
                                                          : masked    ? 0x00ffff00ull
                                                                      : 0)
                                                         << 32));
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_POINT | (masked ? 0 : 1u << 6));
        gs.writeRegister(GS_REG_ALPHA_1,
                         (2ull << 2) | (2ull << 4) | (1ull << 6)); // FIX0 + destination.
        store(0x1000, oldColor);
        gs.writeRegister(GS_REG_RGBAQ, newColor | (0x3f800000ull << 32));
        gs.writeRegister(GS_REG_XYZ2, 512ull | (0x1234ull << 32));
        gs.getLastDisplayBaseBytes();
        check(read(0x1000) == (masked == 2 ? 0x80441234u
                               : masked    ? 0x20445533u
                                           : 0x20445566u),
              "aliased framebuffer/depth original destination or fully masked write");
    }
    std::printf("depth_checks=%u failures=%u mode=%s\n", checks, failures,
                expectBug ? "baseline-defect" : "correct");
    return expectBug ? (failures > 40 ? 0 : 1) : (failures ? 1 : 0);
}
