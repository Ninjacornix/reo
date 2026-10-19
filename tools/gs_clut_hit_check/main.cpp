// Include the frozen rasterizer to exercise its actual primitive-scoped cache,
// without production test wrappers, public headers or GS friend declarations.
#include "selected_source.cpp"
#include <fstream>
#define main clutHitTriangleFixtureMain
#include "triangle_fixture.inc"
#undef main

namespace clut_hit_oracle {
int direct() {
    _putenv("REO_GS_THREAD=0");
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters registers{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &registers);
    GSRasterizer rasterizer;
    unsigned checks = 0, failures = 0;
    auto check = [&](const char* name, bool ok) {
        ++checks;
        if (!ok) {
            ++failures;
            std::printf("FAIL CLUT_DIRECT %s\n", name);
        }
    };
    auto store = [&](unsigned address, uint32_t value) {
        std::memcpy(vram.data() + address, &value, 4);
    };
    const bool spriteValid = t_clutCache.valid;
    t_clutCache.valid = false;
    for (unsigned source : {unsigned(GS_PSM_T4), unsigned(GS_PSM_T8)})
        for (unsigned linear = 0; linear < 2; ++linear)
            for (unsigned csm = 0; csm < 2; ++csm)
                for (unsigned cpsm : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_CT24)}) {
                    std::fill(vram.begin(), vram.end(), uint8_t(0));
                    for (unsigned y = 0; y < 16; ++y)
                        for (unsigned x = 0; x < 16; ++x) {
                            if (source == GS_PSM_T8)
                                vram[GSPSMT8::addrPSMT8(4096, 1, x, y)] = 8;
                            else {
                                const unsigned n = GSPSMT4::addrPSMT4(4096, 1, x, y),
                                               shift = (n & 1) * 4;
                                vram[n / 2] =
                                    uint8_t((vram[n / 2] & ~(15 << shift)) | (8 << shift));
                            }
                        }
                    gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE | (1ull << 4));
                    gs.writeRegister(GS_REG_FRAME_1, 4ull << 16);
                    gs.writeRegister(GS_REG_XYOFFSET_1, 0);
                    gs.writeRegister(GS_REG_SCISSOR_1, (63ull << 16) | (31ull << 48));
                    gs.writeRegister(GS_REG_TEST_1, 0);
                    gs.writeRegister(GS_REG_ZBUF_1, 0);
                    gs.writeRegister(GS_REG_FBA_1, 0);
                    gs.writeRegister(GS_REG_PABE, 0);
                    gs.writeRegister(GS_REG_TEXCLUT, 4);
                    gs.writeRegister(GS_REG_TEXA, 0x8000000020ull);
                    gs.writeRegister(GS_REG_TEX1_1, linear ? 0x60 : 0);
                    gs.writeRegister(GS_REG_CLAMP_1, 5);
                    auto palette = [&](unsigned cbp) {
                        gs.writeRegister(GS_REG_TEX0_1,
                                         4096 | (1ull << 14) | (uint64_t(source) << 20) |
                                             (4ull << 26) | (4ull << 30) | (1ull << 34) |
                                             (1ull << 35) | (uint64_t(cbp) << 37) |
                                             (uint64_t(cpsm) << 51) | (uint64_t(csm) << 55));
                    };
                    const unsigned ci = csm ? 8 : 16, px = ci & 15, py = ci >> 4;
                    const uint32_t alpha = cpsm == GS_PSM_CT24 ? 0x20000000u : 0x80000000u;
                    GSContext ctx{};
                    ctx.frame.fbp = 0;
                    ctx.frame.fbw = 4;
                    ctx.frame.psm = GS_PSM_CT32;
                    auto sample = [&] {
                        return rasterizer.sampleTexture(&gs, 2.25f / 16, 4.75f / 16, 1, 0, 0);
                    };
                    TrianglePaletteCache* const previous = t_trianglePalette;
                    palette(8192);
                    const unsigned safeAddress = GSPSMCT32::addrPSMCT32(8192, 4, px, py);
                    store(safeAddress, 0x80543210u);
                    {
                        TrianglePaletteScope scope(ctx, unsigned(vram.size()), true, 0, 0, 63, 31);
                        check("safe miss actual color", sample() == (alpha | 0x543210));
                        check("safe index becomes state2", scope.cache.states[8] == 2);
                        check("safe cached repeat", sample() == (alpha | 0x543210));
                    }
                    check("scope restores previous pointer", t_trianglePalette == previous);
                    // A later primitive must reload changed palette data; no cache state
                    // or color may persist across the primitive boundary.
                    store(safeAddress, 0x80604820u);
                    {
                        TrianglePaletteScope scope(ctx, unsigned(vram.size()), true, 0, 0, 63, 31);
                        check("next primitive starts unknown", scope.cache.states[8] == 0);
                        check("next primitive refreshes color", sample() == (alpha | 0x604820));
                    }
                    // Aliased entries stay state1. A real fragment overwrites that palette
                    // location; the next fetch must read the new VRAM bytes in the same scope.
                    palette(0);
                    const unsigned liveAddress = GSPSMCT32::addrPSMCT32(0, 4, px, py);
                    store(liveAddress, 0x80543210u);
                    {
                        TrianglePaletteScope scope(ctx, unsigned(vram.size()), true, 0, 0, 63, 31);
                        check("aliased miss actual color", sample() == (alpha | 0x543210));
                        check("aliased entry remains live", scope.cache.states[8] == 1);
                        rasterizer.writePixel(&gs, int(px), int(py), 0x20, 0x48, 0x60, 0x80);
                        check("live fetch sees intervening fragment",
                              sample() == (alpha | 0x604820));
                        check("live entry still state1", scope.cache.states[8] == 1);
                    }
                    check("live scope restores pointer", t_trianglePalette == previous);
                    // With no triangle cache, the complete original lookup remains active.
                    store(liveAddress, 0x80543210u);
                    check("no-cache initial read", sample() == (alpha | 0x543210));
                    rasterizer.writePixel(&gs, int(px), int(py), 0x20, 0x48, 0x60, 0x80);
                    check("no-cache live read", sample() == (alpha | 0x604820));
                }
    t_clutCache.valid = spriteValid;
    std::printf("CLUT_DIRECT checks=%u failures=%u\n", checks, failures);
    return failures ? 1 : 0;
}
} // namespace clut_hit_oracle

int main(int argc, char** argv) {
    if (const int status = clut_hit_oracle::direct())
        return status;
    return clutHitTriangleFixtureMain(argc, argv);
}
