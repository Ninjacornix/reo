#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmct16.h"
#include "runtime/ps2_gs_psmt4.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
uint64_t ps2GsClutShadowStat(unsigned);
void ps2GsRequestWorkerStop();
void ps2GsJoinWorker();
void ps2GsJoinRasterWorkers();
namespace {
struct Packet {
    std::vector<uint8_t> b;
    void q(uint64_t l, uint64_t h) {
        auto n = b.size();
        b.resize(n + 16);
        std::memcpy(b.data() + n, &l, 8);
        std::memcpy(b.data() + n + 8, &h, 8);
    }
    void ad(uint8_t reg, uint64_t val) {
        q(1 | 0x8000ull | (1ull << 60), 14);
        q(val, reg);
    }
    void image(const std::vector<uint8_t>& bytes) {
        q(bytes.size() / 16 | 0x8000ull | (2ull << 58), 0);
        b.insert(b.end(), bytes.begin(), bytes.end());
    }
};
uint64_t tex(unsigned cbp, unsigned cld, unsigned csa = 0, unsigned csm = 0, unsigned cpsm = 0) {
    return 8000ull | (1ull << 14) | (0x14ull << 20) | (6ull << 26) | (6ull << 30) | (1ull << 34) |
           (1ull << 35) | (uint64_t(cbp) << 37) | (uint64_t(cpsm) << 51) | (uint64_t(csm) << 55) |
           (uint64_t(csa) << 56) | (uint64_t(cld) << 61);
}
uint64_t hash(const std::vector<uint8_t>& v) {
    uint64_t h = 14695981039346656037ull;
    for (auto b : v)
        h = (h ^ b) * 1099511628211ull;
    return h;
}
} // namespace
int main(int argc, char** argv) {
    if (argc != 2)
        return 2;
    _putenv_s("REO_GS_THREAD", "0");
    _putenv_s("REO_GS_NO_PARALLEL", "1");
    std::ofstream dump(argv[1], std::ios::binary);
    if (!dump)
        return 2;
    const bool enabled =
        std::getenv("REO_GS_CLUT_SHADOW") && std::atoi(std::getenv("REO_GS_CLUT_SHADOW"));
    unsigned failures = 0, checks = 0, records = 0;
    auto check = [&](const char* n, bool ok) {
        ++checks;
        failures += !ok;
        if (!ok)
            std::printf("FAIL %s\n", n);
    };
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters regs{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &regs);
    auto submit = [&](const Packet& p) { gs.processGIFPacket(p.b.data(), unsigned(p.b.size())); };
    auto reg = [&](uint8_t r, uint64_t v) {
        Packet p;
        p.ad(r, v);
        submit(p);
    };
    auto source = [&](unsigned cbp, uint32_t color) {
        Packet p;
        p.ad(GS_REG_BITBLTBUF, uint64_t(cbp) << 32 | 1ull << 48);
        p.ad(GS_REG_TRXPOS, 0);
        p.ad(GS_REG_TRXREG, 8ull | (2ull << 32));
        p.ad(GS_REG_TRXDIR, 0);
        std::vector<uint8_t> bytes(64);
        for (unsigned i = 0; i < 16; ++i)
            std::memcpy(bytes.data() + i * 4, &color, 4);
        p.image(bytes);
        submit(p);
    };
    auto setup = [&] {
        gs.reset();
        std::fill(vram.begin(), vram.end(), 0);
        reg(GS_REG_FRAME_1, 8ull << 16);
        reg(GS_REG_FRAME_2, 8ull << 16);
        reg(GS_REG_ZBUF_1, 224ull | 1ull << 32);
        reg(GS_REG_ZBUF_2, 224ull | 1ull << 32);
        reg(GS_REG_TEST_1, 0);
        reg(GS_REG_TEST_2, 0);
        reg(GS_REG_SCISSOR_1, 511ull << 16 | 447ull << 48);
        reg(GS_REG_SCISSOR_2, 511ull << 16 | 447ull << 48);
        reg(GS_REG_XYOFFSET_1, 0);
        reg(GS_REG_XYOFFSET_2, 0);
        reg(GS_REG_PRMODECONT, 1);
        reg(GS_REG_TEXCLUT, 0);
        reg(GS_REG_CLAMP_1, 5);
        reg(GS_REG_CLAMP_2, 5);
        for (unsigned y = 0; y < 64; ++y)
            for (unsigned x = 0; x < 64; ++x) {
                auto n = GSPSMT4::addrPSMT4(8000, 1, x, y);
                vram[n / 2] =
                    uint8_t((vram[n / 2] & ~(15u << ((n & 1) * 4))) | (8u << ((n & 1) * 4)));
            }
        source(10000, 0x80604020u);
        source(11000, 0x80705030u);
    };
    auto draw = [&](unsigned context = 0) {
        Packet p;
        p.ad(GS_REG_PRIM, 3ull | 1ull << 4 | 1ull << 8 | uint64_t(context) << 9);
        p.ad(GS_REG_RGBAQ, 0x3f80000080808080ull);
        p.ad(GS_REG_UV, 0);
        p.ad(GS_REG_XYZ2, 144ull * 16 | (64ull * 16 << 16) | 1ull << 32);
        p.ad(GS_REG_XYZ2, 160ull * 16 | (64ull * 16 << 16) | 1ull << 32);
        p.ad(GS_REG_XYZ2, 144ull * 16 | (80ull * 16 << 16) | 1ull << 32);
        submit(p);
    };
    auto emit = [&](const char* name, bool divergence, bool unknown) {
        check("diagnostic primitive reached", ps2GsClutShadowStat(3) == (enabled ? 1 : 0));
        check("diagnostic expected divergence",
              ps2GsClutShadowStat(1) == (enabled && divergence ? 1 : 0));
        check("diagnostic expected unknown",
              ps2GsClutShadowStat(2) == (enabled && unknown ? 1 : 0));
        std::printf("CASE %u %s hash=%016llx\n", records++, name,
                    static_cast<unsigned long long>(hash(vram)));
        dump.write(reinterpret_cast<const char*>(vram.data()), vram.size());
    };
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 0));
    draw();
    emit("initial_unknown", false, true);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2));
    source(10000, 0x80503010);
    reg(GS_REG_TEX0_1, tex(10000, 0));
    draw();
    auto output = GSPSMCT32::addrPSMCT32(0, 8, 145, 65);
    uint32_t pixel = 0;
    std::memcpy(&pixel, vram.data() + output, 4);
    check("renderer still uses live color", pixel == 0x80503010u);
    emit("retained_after_image_mutation", true, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2));
    source(10000, 0x80503010);
    reg(GS_REG_TEX0_1, tex(10000, 4));
    draw();
    emit("conditional_same_pointer", true, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2));
    reg(GS_REG_TEX0_1, tex(11000, 4));
    draw();
    emit("conditional_new_pointer", false, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2));
    source(10000, 0x80503010);
    reg(GS_REG_TEX2_1, tex(10000, 1));
    draw();
    emit("tex2_reload", false, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2));
    reg(GS_REG_TEX0_2, tex(11000, 2));
    draw();
    emit("shared_context_palette", true, false);
    setup();
    reg(GS_REG_TEXCLUT, 4 | (7ull << 6) | (9ull << 12));
    reg(GS_REG_TEX0_1, tex(10000, 2));
    draw();
    emit("csm1_ignores_texclut", true, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2, 1));
    draw();
    emit("csa_bank_source_separation", true, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2));
    reg(GS_REG_TEX0_1, tex(10000, 6));
    draw();
    emit("reserved_control_unknown", false, true);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2, 0, 1, 0));
    draw();
    emit("undocumented_csm2_unknown", false, true);
    auto seed16Diagram = [&](bool horizontal) {
        // Independent GS diagram byte offsets, not the model/address helpers.
        // Current CT16 IMAGE writes linear rows, so it cannot initialize this
        // swizzled-source test. Actual CT32 IMAGE mutation is covered above.
        const unsigned row5x32[16] = {0x888, 0x88c, 0x898, 0x89c, 0x8a8, 0x8ac, 0x8b8, 0x8bc,
                                      0x88a, 0x88e, 0x89a, 0x89e, 0x8aa, 0x8ae, 0x8ba, 0x8be};
        const unsigned top8x2[16] = {0, 4, 16, 20, 32, 36, 48, 52, 8, 12, 24, 28, 40, 44, 56, 60};
        const auto* offsets = horizontal ? row5x32 : top8x2;
        const uint16_t c = 0x8421;
        bool knownSource = true;
        for (unsigned i = 0; i < 16; ++i) {
            const unsigned off = 12000 * 256 + offsets[i];
            std::memcpy(vram.data() + off, &c, 2);
            uint16_t actual = 0;
            std::memcpy(&actual, vram.data() + off, 2);
            knownSource &= actual == c;
        }
        check("independent diagram palette source initialized", knownSource);
    };
    setup();
    seed16Diagram(true);
    reg(GS_REG_TEXCLUT, 4 | (2ull << 6) | (5ull << 12));
    // Live entry8 wrongly uses COU2+x8=(10,5), offset0x9A, not (40,5).
    uint16_t liveEntry8 = 0;
    std::memcpy(&liveEntry8, vram.data() + 12000 * 256 + 0x9a, 2);
    check("documented CSM2 source differs from live entry8", liveEntry8 == 0);
    reg(GS_REG_TEX0_1, tex(12000, 2, 0, 1, 2));
    draw();
    emit("documented_csm2_horizontal", true, false);
    setup();
    seed16Diagram(false);
    reg(GS_REG_TEX0_1, tex(12000, 2, 31, 0, 10));
    draw();
    emit("ct16s_last_bank", true, false);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 2, 0, 0, 1));
    draw();
    emit("undocumented_ct24_unknown", false, true);
    setup();
    reg(GS_REG_TEX0_1, (tex(10000, 2, 1) & ~(0x3full << 20)) | (0x13ull << 20));
    draw();
    emit("t8_offset_unknown", false, true);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 4));
    draw();
    emit("initial_cbp_unknown", false, true);
    ps2GsRequestWorkerStop();
    ps2GsJoinWorker();
    ps2GsJoinRasterWorkers();
    gs.init(vram.data(), unsigned(vram.size()), &regs);
    setup();
    reg(GS_REG_TEX0_1, tex(10000, 0));
    draw();
    emit("restart_no_palette_invention", false, true);
    ps2GsRequestWorkerStop();
    ps2GsJoinWorker();
    ps2GsJoinRasterWorkers();
    std::printf("INTEGRATION checks=%u failures=%u records=%u\n", checks, failures, records);
    return failures || !dump ? 1 : 0;
}
