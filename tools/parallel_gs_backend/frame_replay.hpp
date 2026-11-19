#pragma once
// Frame replay (REO_FRAME_REPLAY): blend the vertex positions of a recorded GIF packet toward
// the matching packet of the previous frame, for interpolated in-between frames.
// docs/native-gameplay/FRAME_DECOUPLING.md ("Toward full interpolation").
//
// Packets pair by position in the frame's GS input stream. Only packets with identical GIF
// tags are blended; anything else keeps the current frame's bytes. Within a packet only
// vertex coordinates change (XYZ2/XYZ3/XYZF2/XYZF3 in PACKED and REGLIST data, and the same
// registers written through A+D); fog, colours, texture coordinates and IMAGE data keep the
// current frame's values.
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace reo::frame_replay {

struct BlendStats { uint32_t vertices = 0, kept = 0; };

namespace detail {
// 12.4 fixed-point screen coordinates; a jump larger than this is not the same vertex moving.
constexpr int32_t max_step = 128 * 16;
inline uint64_t lerp_field(uint64_t cur, uint64_t prev, float k) {
    const double v = double(prev) + (double(cur) - double(prev)) * double(k);
    return uint64_t(std::llround(v < 0 ? 0 : v));
}
inline bool close(uint64_t a, uint64_t b) {
    const int64_t d = int64_t(a) - int64_t(b);
    return d <= max_step && d >= -max_step;
}
// 64-bit register form: X 0-15, Y 16-31, Z 32-63 (XYZ2/XYZ3) or Z 32-55, F 56-63 (XYZF).
inline void blend_reg64(uint64_t& out, uint64_t cur, uint64_t prev, bool fog, float k, BlendStats& s) {
    const uint64_t xc = cur & 0xFFFF, yc = (cur >> 16) & 0xFFFF, xp = prev & 0xFFFF, yp = (prev >> 16) & 0xFFFF;
    if (!close(xc, xp) || !close(yc, yp)) { ++s.kept; return; }
    const uint64_t zmask = fog ? 0xFFFFFFull : 0xFFFFFFFFull;
    const uint64_t zc = (cur >> 32) & zmask, zp = (prev >> 32) & zmask;
    uint64_t v = lerp_field(xc, xp, k) | (lerp_field(yc, yp, k) << 16) | ((lerp_field(zc, zp, k) & zmask) << 32);
    if (fog) v |= cur & 0xFF00000000000000ull;
    out = v;
    ++s.vertices;
}
inline bool is_xyz(uint32_t reg) { return reg == 0x04 || reg == 0x05 || reg == 0x0C || reg == 0x0D; }
inline bool is_fog(uint32_t reg) { return reg == 0x04 || reg == 0x0C; }
}  // namespace detail

// out receives cur's words with blended vertices. Returns false (out == cur) if the packets'
// GIF tags differ anywhere.
inline bool blend_gif(const uint64_t* cur, const uint64_t* prev, uint64_t* out, size_t words, float k,
                      BlendStats* stats = nullptr) {
    using namespace detail;
    BlendStats local;
    BlendStats& s = stats ? *stats : local;
    std::memcpy(out, cur, words * 8);
    size_t i = 0;
    while (i + 2 <= words) {
        const uint64_t lo = cur[i], hi = cur[i + 1];
        if (prev[i] != lo || prev[i + 1] != hi) {
            std::memcpy(out, cur, words * 8);
            return false;
        }
        i += 2;
        const uint32_t nloop = uint32_t(lo & 0x7FFF), flg = uint32_t((lo >> 58) & 3);
        const uint32_t nreg = uint32_t((lo >> 60) & 15) ? uint32_t((lo >> 60) & 15) : 16u;
        if (flg == 0) {  // PACKED: one qword per register
            for (uint32_t loop = 0; loop < nloop; ++loop)
                for (uint32_t r = 0; r < nreg; ++r, i += 2) {
                    if (i + 2 > words) return true;
                    const uint32_t reg = uint32_t((hi >> (4 * r)) & 15);
                    const uint64_t cl = cur[i], ch = cur[i + 1], pl = prev[i], ph = prev[i + 1];
                    if (reg == 0x0E) {  // A+D: 64-bit register data, address in the high qword
                        const uint32_t addr = uint32_t(ch & 0xFF);
                        if (is_xyz(addr) && (ph & 0xFF) == addr)
                            blend_reg64(out[i], cl, pl, is_fog(addr), k, s);
                    } else if (is_xyz(reg)) {
                        // PACKED XYZ: X lo 0-15, Y lo 32-47; Z hi 0-31 (XYZ) or hi 4-27 (XYZF).
                        const uint64_t xc = cl & 0xFFFF, yc = (cl >> 32) & 0xFFFF;
                        const uint64_t xp = pl & 0xFFFF, yp = (pl >> 32) & 0xFFFF;
                        if (!close(xc, xp) || !close(yc, yp)) { ++s.kept; continue; }
                        out[i] = (cl & ~0x0000FFFF0000FFFFull) | lerp_field(xc, xp, k) | (lerp_field(yc, yp, k) << 32);
                        if (is_fog(reg)) {
                            const uint64_t zc = (ch >> 4) & 0xFFFFFF, zp = (ph >> 4) & 0xFFFFFF;
                            out[i + 1] = (ch & ~(0xFFFFFFull << 4)) | ((lerp_field(zc, zp, k) & 0xFFFFFF) << 4);
                        } else {
                            const uint64_t zc = ch & 0xFFFFFFFF, zp = ph & 0xFFFFFFFF;
                            out[i + 1] = (ch & ~0xFFFFFFFFull) | (lerp_field(zc, zp, k) & 0xFFFFFFFF);
                        }
                        ++s.vertices;
                    }
                }
        } else if (flg == 1) {  // REGLIST: one 64-bit word per register, padded to 128 bits
            const size_t count = size_t(nloop) * nreg;
            for (size_t n = 0; n < count; ++n) {
                if (i + n >= words) return true;
                const uint32_t reg = uint32_t((hi >> (4 * (n % nreg))) & 15);
                if (is_xyz(reg))
                    blend_reg64(out[i + n], cur[i + n], prev[i + n], is_fog(reg), k, s);
            }
            i += count + (count & 1);
        } else {  // IMAGE: raw transfer data
            i += size_t(nloop) * 2;
        }
    }
    return true;
}

}  // namespace reo::frame_replay
