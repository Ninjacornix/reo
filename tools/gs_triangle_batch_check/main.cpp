#include "runtime/ps2_gs_gpu.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_psmct32.h"
#include "runtime/ps2_gs_psmct16.h"
#include "runtime/ps2_gs_psmt8.h"
#include "runtime/ps2_gs_psmt4.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

uint64_t ps2GsTriangleBatchStat(unsigned);
void ps2GsTriangleBatchTestCancelAfterRows(uint64_t);
void ps2GsJoinRasterWorkers();
void ps2GsRequestWorkerStop();
void ps2GsJoinWorker();
namespace {
constexpr uint32_t Old = 0x80604820u;
uint32_t bits(float v) {
    uint32_t b;
    std::memcpy(&b, &v, 4);
    return b;
}
uint32_t load(const std::vector<uint8_t>& v, unsigned p, unsigned n = 4) {
    uint32_t x = 0;
    if (uint64_t(p) + n <= v.size())
        std::memcpy(&x, v.data() + p, n);
    return x;
}
void store(std::vector<uint8_t>& v, unsigned p, uint32_t x, unsigned n = 4) {
    if (uint64_t(p) + n <= v.size())
        std::memcpy(v.data() + p, &x, n);
}
uint64_t hash(const std::vector<uint8_t>& v) {
    uint64_t h = 14695981039346656037ull;
    for (auto b : v)
        h = (h ^ b) * 1099511628211ull;
    return h;
}
unsigned fb(unsigned base, unsigned width, unsigned fmt, unsigned x, unsigned y) {
    if (fmt == GS_PSM_CT16)
        return GSPSMCT16::addrPSMCT16(base * 32, width, x, y);
    if (fmt == GS_PSM_CT16S)
        return GSPSMCT16::addrPSMCT16S(base * 32, width, x, y);
    return GSPSMCT32::addrPSMCT32(base * 32, width, x, y);
}
unsigned za(unsigned base, unsigned width, unsigned fmt, unsigned x, unsigned y) {
    if (fmt == 2)
        return GSPSMCT16::addrPSMZ16(base * 32, width, x, y) % PS2_GS_VRAM_SIZE;
    if (fmt == 10)
        return GSPSMCT16::addrPSMZ16S(base * 32, width, x, y) % PS2_GS_VRAM_SIZE;
    unsigned block = GSPSMCT32::blockTable32[(y / 8) & 3][(x / 8) & 7] ^ 24;
    return ((base + (y / 32) * width + x / 64) * 8192 + block * 256 +
            GSPSMCT32::columnTable32[y & 7][x & 7] * 4) %
           PS2_GS_VRAM_SIZE;
}
struct Packet {
    std::vector<uint8_t> b;
    void q(uint64_t lo, uint64_t hi) {
        size_t p = b.size();
        b.resize(p + 16);
        std::memcpy(b.data() + p, &lo, 8);
        std::memcpy(b.data() + p + 8, &hi, 8);
    }
    void tag(unsigned loops, unsigned nreg, uint64_t regs, unsigned fmt = 0) {
        q(loops | 0x8000ull | (uint64_t(fmt) << 58) | (uint64_t(nreg) << 60), regs);
    }
    void ad(uint8_t reg, uint64_t value) {
        tag(1, 1, 14);
        q(value, reg);
    }
    void vertex(unsigned x, unsigned y, unsigned z, uint32_t color, bool adc = false) {
        q((color & 255ull) | ((uint64_t((color >> 8) & 255)) << 32),
          ((color >> 16) & 255ull) | (uint64_t(color >> 24) << 32));
        q(52, 84ull << 32);
        q(x * 16ull | (uint64_t(y * 16) << 32), z | (uint64_t(adc) << 47));
    }
    void append(const Packet& p) {
        b.insert(b.end(), p.b.begin(), p.b.end());
    }
};
struct Case {
    std::string name = "grid";
    unsigned fbp = 0, fbw = 8, frame = GS_PSM_CT32, zbp = 128, zfmt = 0;
    unsigned source = GS_PSM_CT32, tbp = 10000, cbp = 12000, csa = 0, csm = 0;
    bool textured = false, linear = false, overlap = false, blend = false, expectedParallel = true;
    unsigned width = 20, height = 28, count = 64, alpha = 128;
    uint32_t mask = 0, initial = Old;
    uint64_t test = (1ull << 16) | (2ull << 17), clamp = 5;
    bool zmask = false;
};
} // namespace
int main(int argc, char** argv) {
    const char* path = nullptr;
    unsigned bench = 16;
    for (int i = 1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "--dump") && i + 1 < argc)
            path = argv[++i];
        else if (!std::strcmp(argv[i], "--bench") && i + 1 < argc)
            bench = std::strtoul(argv[++i], nullptr, 10);
        else
            return 2;
    }
    _putenv_s("REO_GS_THREAD", "0");
    _putenv_s("REO_GS_TRI_PARALLEL", "0");
    std::ofstream dump;
    if (path) {
        dump.open(path, std::ios::binary);
        if (!dump)
            return 2;
    }
    std::vector<uint8_t> vram(PS2_GS_VRAM_SIZE);
    GSRegisters registers{};
    GS gs;
    gs.init(vram.data(), unsigned(vram.size()), &registers);
    unsigned failures = 0, checks = 0, records = 0;
    const bool batch =
        std::getenv("REO_GS_TRI_BATCH") && std::atoi(std::getenv("REO_GS_TRI_BATCH")) != 0;
    auto check = [&](const std::string& label, bool pass) {
        ++checks;
        failures += !pass;
        if (!pass)
            std::printf("FAIL %s\n", label.c_str());
    };
    auto emit = [&](const std::string& name) {
        std::printf("CASE %u %s hash=%016llx\n", records++, name.c_str(),
                    static_cast<unsigned long long>(hash(vram)));
        if (dump)
            dump.write(reinterpret_cast<const char*>(vram.data()), vram.size());
    };
    auto submit = [&](const Packet& p) { gs.processGIFPacket(p.b.data(), unsigned(p.b.size())); };
    auto setup = [&](const Case& c) {
        for (unsigned i = 0; i < vram.size(); ++i)
            vram[i] = uint8_t((i * 13 + (i >> 10) * 7 + 5) & 255);
        for (unsigned y = 0; y < 384; ++y)
            for (unsigned x = 0; x < 512; ++x) {
                store(vram, fb(c.fbp, c.fbw ? c.fbw : 1, c.frame, x, y), c.initial,
                      c.frame == GS_PSM_CT16 || c.frame == GS_PSM_CT16S ? 2 : 4);
                store(vram, za(c.zbp, c.fbw ? c.fbw : 1, c.zfmt, x, y),
                      c.zfmt == 1 ? 0x7e000064 : 100, c.zfmt == 2 || c.zfmt == 10 ? 2 : 4);
            }
        if (c.textured)
            for (unsigned y = 0; y < 64; ++y)
                for (unsigned x = 0; x < 64; ++x) {
                    if (c.source == GS_PSM_T8) {
                        auto p = GSPSMT8::addrPSMT8(c.tbp, 2, x, y);
                        if (p < vram.size())
                            vram[p] = 8;
                    } else if (c.source == GS_PSM_T4) {
                        auto n = GSPSMT4::addrPSMT4(c.tbp, 2, x, y);
                        if (n / 2 < vram.size())
                            vram[n / 2] = uint8_t((vram[n / 2] & ~(15 << ((n & 1) * 4))) |
                                                  (8 << ((n & 1) * 4)));
                    } else
                        store(vram, GSPSMCT32::addrPSMCT32(c.tbp, 2, x, y), 0x80543210);
                }
        if (c.source == GS_PSM_T8 || c.source == GS_PSM_T4)
            for (unsigned i = 0; i < (c.source == GS_PSM_T4 ? 16 : 256); ++i) {
                unsigned ci = c.source == GS_PSM_T4 ? c.csa * 16 + i : i;
                if (!c.csm)
                    ci = (ci & 0xe7) | ((ci & 8) << 1) | ((ci & 16) >> 1);
                store(vram, GSPSMCT32::addrPSMCT32(c.cbp, 1, ci & 15, ci / 16), 0x80543210);
            }
        gs.writeRegister(GS_REG_FRAME_1, c.fbp | (uint64_t(c.fbw) << 16) |
                                             (uint64_t(c.frame) << 24) | (uint64_t(c.mask) << 32));
        gs.writeRegister(GS_REG_FRAME_2, 64 | (8ull << 16));
        gs.writeRegister(GS_REG_SCISSOR_1, (511ull << 16) | (383ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_1, 0);
        gs.writeRegister(GS_REG_SCISSOR_2, (511ull << 16) | (383ull << 48));
        gs.writeRegister(GS_REG_XYOFFSET_2, 0);
        gs.writeRegister(GS_REG_TEST_1, c.test);
        gs.writeRegister(GS_REG_ZBUF_1,
                         c.zbp | (uint64_t(c.zfmt) << 24) | (uint64_t(c.zmask) << 32));
        gs.writeRegister(GS_REG_ALPHA_1, 0x44);
        gs.writeRegister(GS_REG_FBA_1, 0);
        gs.writeRegister(GS_REG_PABE, 0);
        gs.writeRegister(GS_REG_TEXCLUT, 1);
        gs.writeRegister(GS_REG_TEXA, 0x8000000080ull);
        gs.writeRegister(GS_REG_TEX0_1, c.tbp | (2ull << 14) | (uint64_t(c.source) << 20) |
                                            (6ull << 26) | (6ull << 30) | (1ull << 34) |
                                            (1ull << 35) | (uint64_t(c.cbp) << 37) |
                                            (uint64_t(c.csm) << 55) | (uint64_t(c.csa) << 56));
        gs.writeRegister(GS_REG_CLAMP_1, c.clamp);
        gs.writeRegister(GS_REG_TEX1_1, c.linear ? 0x60 : 0);
        gs.writeRegister(GS_REG_PRIM, GS_PRIM_TRIANGLE | (uint64_t(c.textured) << 4) |
                                          (uint64_t(c.blend) << 6) | (1ull << 8));
    };
    auto triangles = [&](const Case& c, unsigned begin = 0, unsigned count = 0) {
        if (!count)
            count = c.count;
        Packet p;
        p.tag(count * 3, 3, 0x531);
        for (unsigned i = begin; i < begin + count; ++i) {
            unsigned x = c.overlap ? 4 : 4 + (i % 8) * 32, y = c.overlap ? 4 : 4 + (i / 8) * 40;
            uint32_t color = (c.alpha << 24) | 0x00504000u | (32 + (i & 63));
            p.vertex(x, y, 200 + i, color);
            p.vertex(x + c.width, y, 200 + i, color);
            p.vertex(x, y + c.height, 200 + i, color);
        }
        return p;
    };
    auto run = [&](const Case& c, bool oracle = true) {
        setup(c);
        const auto parallel = ps2GsTriangleBatchStat(0);
        submit(triangles(c));
        check(c.name + " admission",
              (ps2GsTriangleBatchStat(0) > parallel) == (batch && c.expectedParallel));
        if (oracle && !c.textured && c.frame == GS_PSM_CT32 && c.fbw == 8 && c.zfmt == 0) {
            unsigned i = c.overlap ? 63 : 0;
            uint32_t expected = (c.alpha << 24) | 0x00504000u | (32 + i), z = 200 + i;
            if (c.test == (1ull << 16)) {
                expected = c.initial;
                z = 100;
            }
            if (c.mask == ~0u)
                expected = c.initial;
            if (c.zmask)
                z = 100;
            if (c.test & (1ull << 14)) {
                if (c.test & (1ull << 15)) {
                } else if (c.initial >> 31) {
                    expected = c.initial;
                    z = 100;
                } else {
                    expected = (c.alpha << 24) | 0x00504020u;
                    z = 200;
                }
            }
            check(c.name + " key color", load(vram, fb(c.fbp, c.fbw, c.frame, 5, 5)) == expected);
            check(c.name + " key depth", load(vram, za(c.zbp, c.fbw, c.zfmt, 5, 5)) == z);
        }
        gs.refreshDisplaySnapshot();
        uint32_t bytes = 0;
        const auto* snapshot = gs.lockDisplaySnapshot(bytes);
        check(c.name + " packet flush before full-VRAM snapshot",
              snapshot && bytes == vram.size() && !std::memcmp(snapshot, vram.data(), vram.size()));
        gs.unlockDisplaySnapshot();
        emit(c.name);
    };
    for (auto dims : {std::pair{8u, 9u}, std::pair{12u, 12u}, std::pair{20u, 28u}}) {
        Case c;
        c.name = "grid-" + std::to_string(dims.first) + "x" + std::to_string(dims.second);
        c.width = dims.first;
        c.height = dims.second;
        run(c);
    }
    {
        Case c;
        c.name = "overlap-original-order";
        c.overlap = true;
        run(c);
    }
    {
        Case c;
        c.name = "date-first-write-disables-followers";
        c.overlap = true;
        c.initial = Old & 0xffffff;
        c.test |= 1ull << 14;
        run(c);
    }
    {
        Case c;
        c.name = "date-datm1-overlap";
        c.overlap = true;
        c.test |= (1ull << 14) | (1ull << 15);
        run(c);
    }
    {
        Case c;
        c.name = "fully-masked-frame-z-still-ordered";
        c.mask = ~0u;
        run(c);
    }
    {
        Case c;
        c.name = "zmask";
        c.zmask = true;
        run(c);
    }
    {
        Case c;
        c.name = "ct24-date-draw-rejected";
        c.frame = GS_PSM_CT24;
        c.test |= 1ull << 14;
        run(c, false);
        check("CT24 DATE ignores the complete draw",
              load(vram, fb(0, 8, GS_PSM_CT24, 5, 5)) == Old);
        check("CT24 DATE also rejects depth", load(vram, za(128, 8, 0, 5, 5)) == 100);
    }
    {
        Case c;
        c.name = "ct24-preserve-destination-high-byte";
        c.frame = GS_PSM_CT24;
        run(c, false);
        check("CT24 color writes preserve destination high byte",
              load(vram, fb(0, 8, GS_PSM_CT24, 5, 5)) == 0x80504020);
    }
    {
        Case c;
        c.name = "z24-high-byte";
        c.zfmt = 1;
        run(c, false);
        check("Z24 preserves destination high byte", load(vram, za(128, 8, 1, 5, 5)) == 0x7e0000c8);
    }
    for (unsigned fail = 0; fail < 4; ++fail) {
        Case c;
        c.name = "afail-" + std::to_string(fail);
        c.overlap = true;
        c.test |= 1 | (uint64_t(fail) << 12);
        run(c, false);
    }
    for (unsigned source : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_T4), unsigned(GS_PSM_T8)})
        for (unsigned linear = 0; linear < 2; ++linear) {
            Case c;
            c.name = "texture-" + std::to_string(source) + "-linear" + std::to_string(linear);
            c.textured = true;
            c.source = source;
            c.linear = linear;
            run(c, false);
        }
    for (unsigned mode = 0; mode < 4; ++mode) {
        Case c;
        c.name = "clamp-" + std::to_string(mode);
        c.textured = true;
        c.linear = true;
        c.clamp = mode | (uint64_t(mode) << 2) | (31ull << 4) | (64ull << 14) | (31ull << 24) |
                  (64ull << 34);
        run(c, false);
    }
    for (unsigned mode = 0; mode < 2; ++mode) {
        Case c;
        c.name = "clut-csm" + std::to_string(mode);
        c.textured = true;
        c.source = GS_PSM_T4;
        c.csa = 17;
        c.csm = mode;
        run(c, false);
    }
    {
        Case c;
        c.name = "blend-order";
        c.blend = true;
        c.alpha = 64;
        c.overlap = true;
        setup(c);
        submit(triangles(c));
        uint32_t expected = Old;
        for (unsigned i = 0; i < 64; ++i) {
            const unsigned src[] = {32 + i, 64, 80};
            uint32_t out = 64u << 24;
            for (unsigned ch = 0; ch < 3; ++ch) {
                int dst = (expected >> (ch * 8)) & 255;
                out |= uint32_t((((int(src[ch]) - dst) * 64) >> 7) + dst) << (ch * 8);
            }
            expected = out;
        }
        check(c.name, load(vram, fb(0, 8, 0, 5, 5)) == expected);
        emit(c.name);
    }
    for (unsigned variant = 0; variant < 9; ++variant) {
        Case c;
        c.name = "unsafe-feedback-" + std::to_string(variant);
        c.expectedParallel = false;
        if (variant == 0)
            c.zbp = 0;
        if (variant == 1)
            c.fbw = 1;
        if (variant == 2)
            c.fbp = 500;
        if (variant == 3) {
            c.textured = true;
            c.tbp = 0;
        }
        if (variant == 4) {
            c.textured = true;
            c.source = GS_PSM_T8;
            c.cbp = 0;
        }
        if (variant == 5) {
            c.textured = true;
            c.source = GS_PSM_T4;
            c.cbp = 128 * 32;
        }
        if (variant == 6)
            c.frame = GS_PSM_CT16S;
        if (variant == 7)
            c.zfmt = 2;
        if (variant == 8)
            c.test = 1ull << 16;
        run(c, variant == 8);
    }
    // Ordered state writes, nontriangle draws and IMAGE writes inside ONE packet.
    for (unsigned variant = 0; variant < 5; ++variant) {
        Case c;
        c.name = "packet-barrier-" + std::to_string(variant);
        setup(c);
        Packet p = triangles(c, 0, 32);
        if (variant == 0)
            p.ad(GS_REG_FRAME_1, 32 | (8ull << 16));
        if (variant == 1)
            p.ad(GS_REG_TEST_1, 1ull << 16);
        if (variant == 2) {
            p.ad(GS_REG_PRIM, GS_PRIM_SPRITE | (1ull << 8));
            p.tag(2, 3, 0x531);
            p.vertex(4, 4, 500, 0x80808080);
            p.vertex(20, 20, 500, 0x80808080);
            p.ad(GS_REG_PRIM, GS_PRIM_TRIANGLE | (1ull << 8));
        }
        if (variant == 3) {
            p.ad(GS_REG_BITBLTBUF, (8ull << 48));
            p.ad(GS_REG_TRXPOS, 5ull << 32 | 5ull << 48);
            p.ad(GS_REG_TRXREG, 2ull | (2ull << 32));
            p.ad(GS_REG_TRXDIR, 0);
            p.tag(1, 0, 0, 2);
            p.q(0x80aabbcc80aabbccull, 0x80aabbcc80aabbccull);
        }
        if (variant == 4) {
            p.ad(GS_REG_PRIM, GS_PRIM_TRIANGLE | (1ull << 8) | (1ull << 9));
        }
        p.append(triangles(c, 32, 32));
        submit(p);
        if (variant == 2)
            check("nontriangle barrier key pixel", load(vram, fb(0, 8, 0, 5, 5)) == 0x80808080);
        if (variant == 3)
            check("IMAGE barrier key pixel", load(vram, fb(0, 8, 0, 5, 5)) == 0x80aabbcc);
        emit(c.name);
    }
    // Truncated payload retains original assembly state; pending draws flush on return.
    {
        Case c;
        setup(c);
        auto p = triangles(c);
        p.b.resize(p.b.size() - 16);
        submit(p);
        emit("truncated-before-last-vertex");
        Packet tail;
        tail.tag(1, 3, 0x531);
        tail.vertex(228, 312, 263, 0x8050405f);
        submit(tail);
        emit("truncated-then-completed");
    }
    {
        Case c;
        setup(c);
        Packet p = triangles(c);
        p.ad(GS_REG_BITBLTBUF, 8ull << 48);
        p.ad(GS_REG_TRXPOS, 5ull << 32 | 5ull << 48);
        p.ad(GS_REG_TRXREG, 2ull | (4ull << 32));
        p.ad(GS_REG_TRXDIR, 0);
        p.tag(2, 0, 0, 2);
        p.q(0x80aabbcc80aabbccull, 0x80aabbcc80aabbccull);
        submit(p);
        emit("fragmented-image-first-half");
        Packet tail;
        tail.q(0x8011223380112233ull, 0x8011223380112233ull);
        submit(tail);
        check("fragmented IMAGE finishes on raw payload return",
              load(vram, fb(0, 8, 0, 5, 8)) == 0x80112233);
        emit("fragmented-image-complete");
    }
    for (unsigned primitive : {unsigned(GS_PRIM_TRISTRIP), unsigned(GS_PRIM_TRIFAN)}) {
        Case c;
        setup(c);
        gs.writeRegister(GS_REG_PRIM, primitive | (1ull << 8));
        Packet p;
        p.tag(128, 3, 0x531);
        for (unsigned i = 0; i < 128; ++i) {
            unsigned x = primitive == GS_PRIM_TRISTRIP
                             ? 4 + (i / 2 % 12) * 20
                             : 128 + unsigned(24 + 24 * std::cos(i * .45));
            unsigned y = primitive == GS_PRIM_TRISTRIP
                             ? 4 + (i % 2) * 28
                             : 128 + unsigned(24 + 24 * std::sin(i * .45));
            p.vertex(x, y, 200 + i, 0x80504020 + (i & 63), (i % 5) == 3);
        }
        submit(p);
        emit("assembly-adc-" + std::to_string(primitive));
    }
    // Stop at row boundaries. Every row must equal a valid original primitive
    // prefix; independently rebuild every changed byte including Z and padding.
    for (unsigned iteration = 0; iteration < 3; ++iteration) {
        Case c;
        c.overlap = true;
        c.width = 32;
        c.height = 32;
        c.count = 32;
        setup(c);
        auto initial = vram, expected = initial;
        ps2GsTriangleBatchTestCancelAfterRows(48 + iteration * 16);
        submit(triangles(c));
        ps2GsTriangleBatchTestCancelAfterRows(0);
        bool prefix = true;
        unsigned changed = 0;
        for (unsigned y = 4; y < 36; ++y) {
            const unsigned z = load(vram, za(128, 8, 0, 4, y));
            unsigned n = z >= 200 && z < 232 ? z - 199 : 0;
            if (n)
                ++changed;
            for (unsigned x = 4; x < 36; ++x) {
                bool covered = (x - 4) + (y - 4) <= 31;
                unsigned p = fb(0, 8, 0, x, y), q = za(128, 8, 0, x, y);
                if (n && covered) {
                    store(expected, p, 0x80504000u | (31 + n));
                    store(expected, q, 199 + n);
                }
            }
        }
        prefix = vram == expected;
        check("cancellation full VRAM primitive-prefix oracle", prefix);
        check("cancellation made partial progress", changed > 0);
        std::printf("STOP iteration=%u rows=%u prefix=%u\n", iteration, changed, unsigned(prefix));
        ps2GsJoinRasterWorkers();
        run(Case{"after-stop-reused-workers-" + std::to_string(iteration)});
    }
    for (unsigned source : {unsigned(GS_PSM_CT32), unsigned(GS_PSM_T8)})
        for (auto dims : {std::pair{8u, 9u}, std::pair{20u, 28u}}) {
            Case c;
            c.textured = true;
            c.source = source;
            c.linear = true;
            c.width = dims.first;
            c.height = dims.second;
            c.test = (1ull << 16) | (1ull << 17);
            c.zmask = true;
            setup(c);
            const auto p = triangles(c);
            submit(p);
            for (unsigned round = 0; round < 5; ++round) {
                const auto start = std::chrono::steady_clock::now();
                for (unsigned n = 0; n < bench; ++n)
                    submit(p);
                const auto us = std::chrono::duration_cast<std::chrono::microseconds>(
                                    std::chrono::steady_clock::now() - start)
                                    .count();
                std::printf("BENCH source=%u bbox=%u packets=%u round=%u us=%lld hash=%016llx\n",
                            source, (c.width + 1) * (c.height + 1), bench, round,
                            static_cast<long long>(us),
                            static_cast<unsigned long long>(hash(vram)));
            }
        }
    ps2GsRequestWorkerStop();
    ps2GsJoinWorker();
    ps2GsJoinRasterWorkers();
    gs.init(vram.data(), unsigned(vram.size()), &registers);
    run(Case{"after-real-stop-reinit"});
    ps2GsRequestWorkerStop();
    ps2GsJoinWorker();
    ps2GsJoinRasterWorkers();
    std::printf("SUMMARY records=%u checks=%u failures=%u batch=%u parallel_batches=%llu\n",
                records, checks, failures, unsigned(batch),
                static_cast<unsigned long long>(ps2GsTriangleBatchStat(0)));
    return failures || !dump ? 1 : 0;
}
