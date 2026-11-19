// Unit test for frame_replay.hpp: build with any C++17 compiler, run, expect "PASS".
#include "frame_replay.hpp"
#include <cstdio>
#include <vector>
using reo::frame_replay::blend_gif;
using reo::frame_replay::BlendStats;

static int failures = 0;
static void check(bool ok, const char* what) {
    if (!ok) { std::printf("FAIL %s\n", what); ++failures; }
}
static uint64_t tag(uint32_t nloop, uint32_t flg, uint32_t nreg, bool eop = true) {
    return uint64_t(nloop) | (uint64_t(eop) << 15) | (uint64_t(flg) << 58) | (uint64_t(nreg & 15) << 60);
}

int main() {
    // PACKED: RGBAQ (1), XYZ2 (5) per loop, 2 loops.
    std::vector<uint64_t> prev = {tag(2, 0, 2), 0x51,
                                  0x11111111, 0, (uint64_t(100 * 16) << 32) | (200 * 16), 1000,
                                  0x22222222, 0, (uint64_t(10 * 16) << 32) | (20 * 16), 5000};
    std::vector<uint64_t> cur = prev;
    cur[4] = (uint64_t(110 * 16) << 32) | (220 * 16); cur[5] = 2000;  // vertex 1 moved
    cur[2] = 0x99999999;                                               // colour changed
    std::vector<uint64_t> out(cur.size());
    BlendStats s;
    check(blend_gif(cur.data(), prev.data(), out.data(), cur.size(), 0.5f, &s), "packed blends");
    check((out[4] & 0xFFFF) == 210 * 16 && ((out[4] >> 32) & 0xFFFF) == 105 * 16 && out[5] == 1500, "packed XYZ2 halfway");
    check(out[2] == 0x99999999, "colour keeps current value");
    check(out[8] == cur[8] && out[9] == cur[9], "unmoved vertex unchanged");
    check(s.vertices == 2 && s.kept == 0, "vertex count");
    check(blend_gif(cur.data(), prev.data(), out.data(), cur.size(), 1.0f) && out == cur, "k=1 equals current frame");
    check(blend_gif(cur.data(), prev.data(), out.data(), cur.size(), 0.0f) && (out[4] == prev[4]) && out[5] == prev[5], "k=0 equals previous positions");

    // Different tag: no blending.
    auto other = cur; other[0] = tag(3, 0, 2);
    check(!blend_gif(cur.data(), other.data(), out.data(), cur.size(), 0.5f) && out == cur, "tag mismatch keeps current");

    // Large jump: kept.
    auto far = prev; far[4] = (uint64_t(400 * 16) << 32) | (200 * 16);
    s = {};
    blend_gif(cur.data(), far.data(), out.data(), cur.size(), 0.5f, &s);
    check(out[4] == cur[4] && s.kept == 1, "teleport is not interpolated");

    // A+D write of XYZF2 (addr 0x04): X 0-15, Y 16-31, Z 32-55, F 56-63.
    std::vector<uint64_t> pa = {tag(1, 0, 1), 0xE, (0xAAull << 56) | (uint64_t(1000) << 32) | (uint64_t(50 * 16) << 16) | (60 * 16), 0x04};
    auto ca = pa; ca[2] = (0xBBull << 56) | (uint64_t(3000) << 32) | (uint64_t(70 * 16) << 16) | (80 * 16);
    out.assign(ca.size(), 0);
    blend_gif(ca.data(), pa.data(), out.data(), ca.size(), 0.5f);
    check((out[2] & 0xFFFF) == 70 * 16 && ((out[2] >> 16) & 0xFFFF) == 60 * 16 && ((out[2] >> 32) & 0xFFFFFF) == 2000 &&
          (out[2] >> 56) == 0xBB, "A+D XYZF2 blends XYZ, keeps fog");

    // REGLIST: XYZ2 64-bit words, 3 registers (pad to even).
    std::vector<uint64_t> pr = {tag(1, 1, 3), 0x555, 0, 0, 0, 0};
    pr[2] = (uint64_t(100) << 32) | (uint64_t(16 * 16) << 16) | (32 * 16);
    pr[3] = 0; pr[4] = 0;
    auto cr = pr; cr[2] = (uint64_t(300) << 32) | (uint64_t(48 * 16) << 16) | (64 * 16);
    out.assign(cr.size(), 0);
    blend_gif(cr.data(), pr.data(), out.data(), cr.size(), 0.5f);
    check((out[2] & 0xFFFF) == 48 * 16 && ((out[2] >> 16) & 0xFFFF) == 32 * 16 && (out[2] >> 32) == 200, "reglist XYZ2");

    // IMAGE data is never touched.
    std::vector<uint64_t> pi = {tag(1, 2, 0), 0, 0x1234, 0x5678};
    auto ci = pi; ci[2] = 0x9999;
    out.assign(ci.size(), 0);
    blend_gif(ci.data(), pi.data(), out.data(), ci.size(), 0.5f);
    check(out[2] == 0x9999, "image data kept");

    std::printf(failures ? "FAILED %d\n" : "PASS\n", failures);
    return failures != 0;
}
