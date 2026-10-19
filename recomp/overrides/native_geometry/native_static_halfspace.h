#pragma once
#include "native_fixed_point.h"
// Source proposal only. Exact owned code admission belongs to the caller.
// One semantic polygon/halfspace pass, not instruction or VF-number dispatch.
#include "runtime/ps2_vu1.h"
#include <emmintrin.h>
#include <cmath>
#include <cstdint>
#include <cstring>
#if defined(_MSC_VER)
#pragma float_control(precise, on, push)
#pragma fp_contract(off)
#endif
namespace reo_native_static_halfspace {
struct Admission {
    bool exactImageSelected, captureInactive;
};
struct Result {
    uint32_t vertices, pairs;
};
namespace detail {
struct Vertex {
    __m128 position, color, texture;
};
inline bool disjoint(const void* a, size_t an, const void* b, size_t bn) {
    const uintptr_t x = reinterpret_cast<uintptr_t>(a), y = reinterpret_cast<uintptr_t>(b);
    return a && b && x <= UINTPTR_MAX - an && y <= UINTPTR_MAX - bn && (x + an <= y || y + bn <= x);
}
inline bool bounded(__m128 value) {
    return reo_native_fixed::bounded(value, 1099511627776.0f);
}
inline uint32_t clipBits(__m128 position) {
    const __m128 absolute = _mm_and_ps(_mm_shuffle_ps(position, position, _MM_SHUFFLE(3, 3, 3, 3)),
                                       _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
    const __m128 negative =
        _mm_xor_ps(absolute, _mm_castsi128_ps(_mm_set1_epi32(int32_t(0x80000000u))));
    const unsigned positive = _mm_movemask_ps(_mm_cmpgt_ps(position, absolute)) & 7;
    const unsigned below = _mm_movemask_ps(_mm_cmplt_ps(position, negative)) & 7;
    return (positive & 1) | ((below & 1) << 1) | ((positive & 2) << 1) | ((below & 2) << 2) |
           ((positive & 4) << 2) | ((below & 4) << 3);
}
inline float axisLane(__m128 value, unsigned axis) {
    alignas(16) float v[4];
    _mm_store_ps(v, value);
    return v[axis];
}
inline bool safe(Vertex value) {
    return bounded(value.position) && bounded(value.color) && bounded(value.texture);
}
inline Vertex load(const uint8_t* data, unsigned qw) {
    return {_mm_loadu_ps(reinterpret_cast<const float*>(data + 16 * qw)),
            _mm_loadu_ps(reinterpret_cast<const float*>(data + 16 * (qw + 1))),
            _mm_loadu_ps(reinterpret_cast<const float*>(data + 16 * (qw + 2)))};
}
inline void store(uint8_t* data, unsigned qw, Vertex value) {
    _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * qw), value.position);
    _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * (qw + 1)), value.color);
    _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * (qw + 2)), value.texture);
}
inline bool validReturn(unsigned pc) {
    return pc == 0x720 || pc == 0x770 || pc == 0x7b0 || pc == 0x7f0 || pc == 0x830 || pc == 0x870;
}
// Mirrors the helper's ordered f32 operations. The signed DIV value is retained
// in Q, while VF27.x receives ABS(ADDq(+0,Q)); final deltas have separate mul/add.
inline bool intersection(Vertex previous, Vertex current, unsigned axis, float sign, Vertex& out,
                         float& rawQ, float& absoluteParameter) {
    const __m128 prevW =
        _mm_mul_ps(_mm_shuffle_ps(previous.position, previous.position, _MM_SHUFFLE(3, 3, 3, 3)),
                   _mm_set1_ps(sign));
    const __m128 currW =
        _mm_mul_ps(_mm_shuffle_ps(current.position, current.position, _MM_SHUFFLE(3, 3, 3, 3)),
                   _mm_set1_ps(sign));
    const __m128 previousDistance = _mm_sub_ps(previous.position, prevW);
    const __m128 currentDistance = _mm_sub_ps(current.position, currW);
    const __m128 delta = _mm_sub_ps(currentDistance, previousDistance);
    const float divisor = axisLane(delta, axis);
    if (divisor == 0.0f)
        return false; // Generic DIV's saturated-zero path remains generic.
    rawQ = _mm_cvtss_f32(
        _mm_div_ss(_mm_set_ss(axisLane(previousDistance, axis)), _mm_set_ss(divisor)));
    if (!std::isfinite(rawQ) || std::fabs(rawQ) > 33554432.0f)
        return false;
    const __m128 added = _mm_add_ss(_mm_setzero_ps(), _mm_set_ss(rawQ));
    absoluteParameter =
        _mm_cvtss_f32(_mm_and_ps(added, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff))));
    const __m128 ratio = _mm_set1_ps(absoluteParameter);
    const __m128 dp = _mm_sub_ps(current.position, previous.position);
    const __m128 dc = _mm_sub_ps(current.color, previous.color);
    const __m128 dt = _mm_sub_ps(current.texture, previous.texture);
    const __m128 mp = _mm_mul_ps(dp, ratio), mc = _mm_mul_ps(dc, ratio), mt = _mm_mul_ps(dt, ratio);
    out = {_mm_add_ps(mp, previous.position), _mm_add_ps(mc, previous.color),
           _mm_add_ps(mt, previous.texture)};
    return true;
}
} // namespace detail
// Complete polygon pass or untouched refusal. Packet headers, closure copy and
// original XGKICK900/AE0 are outside this body and remain in the original handler.
inline bool executeLoop(VU1State& state, uint8_t* data, uint32_t bytes, uint32_t remaining,
                        bool& pending, uint32_t& target, Admission admission, Result& output) {
    using namespace detail;
    constexpr uint32_t canonicalZero[4] = {0, 0, 0, 0x3f800000};
    if (!admission.exactImageSelected || !admission.captureInactive || bytes != 16384 ||
        state.pc != 0xc70 || state.ebit || pending || state.vi[0] ||
        std::memcmp(state.vf[0], canonicalZero, 16) ||
        !disjoint(&state, sizeof(state), data, bytes))
        return false;
    const int n = state.vi[4], axis = state.vi[7];
    if (n < 1 || n > 12 || axis < 0 || axis > 2)
        return false;
    const unsigned returnPC = (uint32_t(uint16_t(state.vi[13])) * 8u) & 0x3fffu;
    if (!validReturn(returnPC))
        return false;
    const float sign = state.vf[31][0];
    if (sign != 1.0f && sign != -1.0f)
        return false;
    const unsigned plane = 1u << (2 * axis + (sign < 0.0f ? 1 : 0));
    if (state.vi[6] != int(plane) || state.vi[5] != int(plane << 6) || state.vi[11] != 0)
        return false;
    const unsigned input = uint16_t(state.vi[9]), destination = uint16_t(state.vi[10]);
    if (!((input == 938 && destination == 975) || (input == 978 && destination == 935)))
        return false;
    if (remaining < uint32_t(23 * n + 2))
        return false;
    Vertex current{_mm_loadu_ps(state.vf[21]), _mm_loadu_ps(state.vf[22]),
                   _mm_loadu_ps(state.vf[23])};
    if (!safe(current))
        return false;
    for (int i = 0; i < n; ++i)
        if (!safe(load(data, input + 3 * i)))
            return false;
    Vertex previous{}, lastIntersection{_mm_loadu_ps(state.vf[28]), _mm_loadu_ps(state.vf[29]),
                                        _mm_loadu_ps(state.vf[30])};
    Vertex staged[12];
    unsigned emitted = 0, pairs = 2;
    uint32_t clip = state.clip;
    int32_t vi1 = state.vi[1], vi12 = state.vi[12];
    float q = state.q, parameter = 0;
    bool crossed = false;
    for (int i = 0; i < n; ++i) {
        // Original MUL.xyzw copies via VF0.w before loading the next ordered triple.
        const __m128 one = _mm_set1_ps(1.0f);
        previous = {_mm_mul_ps(current.position, one), _mm_mul_ps(current.color, one),
                    _mm_mul_ps(current.texture, one)};
        current = load(data, input + 3 * i);
        clip = ((clip << 6) | clipBits(previous.position)) & 0xffffffu;
        clip = ((clip << 6) | clipBits(current.position)) & 0xffffffu;
        vi1 = int32_t(clip & 0xfffu); // Original FCGET publishes twelve bits to VI1.
        const bool previousOutside = (vi1 & int32_t(plane << 6)) != 0;
        vi12 = vi1 & int32_t(plane);
        const bool currentOutside = vi12 != 0;
        unsigned cost = previousOutside ? 23 : 27;
        if (previousOutside != currentOutside) {
            if (!intersection(previous, current, unsigned(axis), sign, lastIntersection, q,
                              parameter))
                return false;
            crossed = true;
            vi12 = 0;
            vi1 = (previousOutside ? 0xd18 : 0xd70) / 8;
            cost = (previousOutside ? 62 : 65) + 8 * unsigned(axis);
            if (!previousOutside) {
                if (emitted >= 12)
                    return false;
                staged[emitted++] = previous;
            }
            if (emitted >= 12)
                return false;
            staged[emitted++] = lastIntersection;
        } else if (!previousOutside) {
            if (emitted >= 12)
                return false;
            staged[emitted++] = previous;
        }
        pairs += cost;
        if (pairs > remaining)
            return false;
    }
    // Commit once. No full state copy, VU-memory overlay, or callbacks occur in the
    // edge loop. Refusal at any point above leaves state/data/branch/result untouched.
    for (unsigned i = 0; i < emitted; ++i)
        store(data, destination + 3 * i, staged[i]);
    _mm_storeu_ps(state.vf[21], current.position);
    _mm_storeu_ps(state.vf[22], current.color);
    _mm_storeu_ps(state.vf[23], current.texture);
    _mm_storeu_ps(state.vf[24], previous.position);
    _mm_storeu_ps(state.vf[25], previous.color);
    _mm_storeu_ps(state.vf[26], previous.texture);
    if (crossed) {
        _mm_storeu_ps(state.vf[28], lastIntersection.position);
        _mm_storeu_ps(state.vf[29], lastIntersection.color);
        _mm_storeu_ps(state.vf[30], lastIntersection.texture);
        state.vf[27][0] = parameter;
        state.q = q;
    }
    state.vi[1] = vi1;
    state.vi[4] = 0;
    state.vi[9] = int16_t(input + 3 * n);
    state.vi[10] = int16_t(destination + 3 * emitted);
    state.vi[11] = int16_t(emitted);
    state.vi[12] = vi12;
    state.clip = clip;
    state.pc = returnPC;
    pending = false;
    target = 0xdf8;
    output = {unsigned(n), pairs};
    return true;
}
} // namespace reo_native_static_halfspace
#if defined(_MSC_VER)
#pragma float_control(pop)
#endif
