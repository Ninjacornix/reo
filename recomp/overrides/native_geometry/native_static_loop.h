#pragma once
#include "native_fixed_point.h"
// Game-owned direct STATIC mesh loop. Owned code identity belongs to the caller.
// No instruction dispatch, per-pair scheduling, state clone, scratch-QW search,
// or intermediate state/history materialization inside the vertex loop.
#include "runtime/ps2_vu1.h"
#include <emmintrin.h>
#include <array>
#include <initializer_list>
#include <cmath>
#include <climits>
#include <cstdint>
#include <cstring>
#include <limits>
#if defined(_MSC_VER)
#pragma float_control(precise, on, push)
#pragma fp_contract(off)
#endif
namespace reo_native_static {
struct Admission {
    bool exactImageSelected, captureInactive;
};
struct Result {
    uint32_t vertices, pairs;
};
namespace detail {
constexpr float Bound = 33554432.0f;
inline bool bounded(float f) {
    return std::isfinite(f) && std::fabs(f) <= Bound;
}
inline bool boundedVec(const float* p, unsigned mask = 15) {
    return reo_native_fixed::bounded(_mm_loadu_ps(p), Bound, mask);
}
inline bool positive(const float* p, unsigned mask = 15) {
    return reo_native_fixed::positive(_mm_loadu_ps(p), mask);
}
inline bool dataVecSafe(const uint8_t* data, unsigned qw, unsigned mask, bool nonnegative = false) {
    alignas(16) float p[4];
    std::memcpy(p, data + 16 * qw, 16);
    return boundedVec(p, mask) && (!nonnegative || positive(p, mask));
}
template <unsigned C> inline float lane(__m128 v) {
    return _mm_cvtss_f32(_mm_shuffle_ps(v, v, _MM_SHUFFLE(C, C, C, C)));
}
template <unsigned M> inline __m128 merge(__m128 old, __m128 value) {
    if constexpr (M == 15)
        return value;
    const __m128 mask = _mm_castsi128_ps(
        _mm_set_epi32(M & 1 ? -1 : 0, M & 2 ? -1 : 0, M & 4 ? -1 : 0, M & 8 ? -1 : 0));
    return _mm_or_ps(_mm_and_ps(mask, value), _mm_andnot_ps(mask, old));
}
inline __m128 x(__m128 old, float value) {
    return _mm_move_ss(old, _mm_set_ss(value));
}
inline __m128 mul(__m128 value, float scalar) {
    return _mm_mul_ps(value, _mm_set1_ps(scalar));
}
inline __m128 madd(__m128 acc, __m128 column, float scalar) {
    const __m128 product = mul(column, scalar);
    return _mm_add_ps(acc, product);
}
inline __m128 affineLinear(__m128 a, __m128 b, __m128 c, __m128 position) {
    __m128 result = mul(a, lane<0>(position));
    result = madd(result, b, lane<1>(position));
    return madd(result, c, lane<2>(position));
}
inline uint32_t clipBits(__m128 point) {
    const __m128 absolute = _mm_and_ps(_mm_shuffle_ps(point, point, _MM_SHUFFLE(3, 3, 3, 3)),
                                       _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
    const __m128 negative =
        _mm_xor_ps(absolute, _mm_castsi128_ps(_mm_set1_epi32(int32_t(0x80000000u))));
    const unsigned pos = _mm_movemask_ps(_mm_cmpgt_ps(point, absolute)) & 7,
                   neg = _mm_movemask_ps(_mm_cmplt_ps(point, negative)) & 7;
    return (pos & 1) | ((pos & 2) << 1) | ((pos & 4) << 2) | ((neg & 1) << 1) | ((neg & 2) << 2) |
           ((neg & 4) << 3);
}
inline uint32_t clip(uint32_t history, __m128 point) {
    return ((history << 6) | clipBits(point)) & 0xffffffu;
}
inline int32_t fixed(float value, unsigned shift) {
    const double scaled = double(value) * double(uint32_t(1) << shift);
    return scaled >= 2147483648.0   ? INT32_MAX
           : scaled < -2147483648.0 ? INT32_MIN
                                    : int32_t(scaled);
}
template <unsigned M, unsigned Shift> inline __m128 quantize(__m128 value) {
    __m128 converted = value;
    if (reo_native_fixed::convert<M, Shift>(converted))
        return converted;
    alignas(16) float values[4];
    _mm_store_ps(values, value);
    for (unsigned c = 0; c < 4; ++c)
        if (M & (8u >> c)) {
            const int32_t result = fixed(values[c], Shift);
            std::memcpy(values + c, &result, 4);
        }
    return _mm_load_ps(values);
}
inline bool disjoint(const void* a, size_t an, const void* b, size_t bn) {
    const uintptr_t aa = reinterpret_cast<uintptr_t>(a), bb = reinterpret_cast<uintptr_t>(b);
    return a && b && aa <= UINTPTR_MAX - an && bb <= UINTPTR_MAX - bn &&
           (aa + an <= bb || bb + bn <= aa);
}
inline bool initialSafe(const VU1State& s) {
    constexpr uint32_t zero[4] = {0, 0, 0, 0x3f800000};
    if (s.vi[0] || std::memcmp(s.vf[0], zero, 16))
        return false;
    for (unsigned r : {1u, 2u, 7u, 8u, 9u, 10u})
        if (!boundedVec(s.vf[r]))
            return false;
    for (unsigned r : {11u, 15u, 16u, 17u, 21u, 22u, 23u, 26u})
        if (!boundedVec(s.vf[r], r == 11 ? 12 : 8))
            return false;
    return std::isfinite(s.vf[24][0]) && boundedVec(s.vf[27]) && boundedVec(s.vf[28], 14) &&
           boundedVec(s.vf[29], 14) && boundedVec(s.vf[31], 12) && boundedVec(s.vf[20], 14) &&
           boundedVec(s.vf[13], 14) && positive(s.vf[13], 14) && boundedVec(s.vf[14], 14) &&
           positive(s.vf[14], 14) && std::isfinite(s.vf[12][0]) && s.vf[12][0] >= 0;
}
} // namespace detail
// A successful call consumes an admitted complete-iteration prefix. If a later
// vertex needs the original clipper/unsafe-Q/short budget, materialize that
// prefix once and return at its next PC0x260. Zero return changes nothing.
inline bool executeLoop(VU1State& state, uint8_t* data, uint32_t bytes, uint32_t remaining,
                        bool& pending, uint32_t& target, Admission admission, Result& output,
                        uint64_t* routes = nullptr) {
    using namespace detail;
    if (!admission.exactImageSelected || !admission.captureInactive || !data || bytes != 16384 ||
        state.pc != 0x260 || state.ebit || pending || remaining < 54 || state.vi[7] <= 0 ||
        !disjoint(&state, sizeof(state), data, bytes) || !initialSafe(state))
        return false;
    const unsigned count = uint32_t(state.vi[7]), initialInput = uint16_t(state.vi[5]),
                   initialOutput = uint16_t(state.vi[4]);
    // Whole-stream admission folds every per-point bounds/alias check. It also
    // ensures all data constants and scratch history stay immutable to output.
    if (count > 247 || initialInput < 24 || initialOutput < 24 ||
        initialInput + 4 * count + 3 >= 1015 || initialOutput + 3 * count > 1015 ||
        !(initialOutput + 3 * count <= initialInput ||
          initialInput + 4 * count + 4 <= initialOutput))
        return false;
    if (!dataVecSafe(data, 0, 14, true) || !dataVecSafe(data, 1, 15, true))
        return false;
    for (unsigned q = 3; q <= 10; ++q)
        if (!dataVecSafe(data, q, 15))
            return false;
    for (unsigned q = 15; q <= 17; ++q)
        if (!dataVecSafe(data, q, 12))
            return false;
    for (unsigned n = 0; n < count; ++n) {
        const unsigned i = initialInput + 4 * n;
        if (!dataVecSafe(data, i + 2, 15, true) || !dataVecSafe(data, i + 4, 14) ||
            !dataVecSafe(data, i + 5, 14) || !dataVecSafe(data, i + 7, 14))
            return false;
    }
    const auto load = [&](unsigned qw) {
        return _mm_loadu_ps(reinterpret_cast<const float*>(data + 16 * qw));
    };
    const auto store = [&](unsigned qw, __m128 value) {
        _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * qw), value);
    };
    // Immutable mesh constants are loaded once; no VF-number table in the loop.
    const __m128 screen0 = load(3), screen1 = load(4), screen2 = load(5), screen3 = load(6);
    const __m128 clip0 = load(7), clip1 = load(8), clip2 = load(9), clip3 = load(10);
    const __m128 texture0 = load(15), texture1 = load(16), texture2 = load(17);
    const __m128 ambient = load(0), modulation = load(1),
                 materialLight = _mm_loadu_ps(state.vf[13]),
                 materialColor = _mm_loadu_ps(state.vf[14]);
    const __m128 entryClip0 = _mm_loadu_ps(state.vf[7]), entryClip1 = _mm_loadu_ps(state.vf[8]),
                 entryClip2 = _mm_loadu_ps(state.vf[9]), entryClip3 = _mm_loadu_ps(state.vf[10]);
    const float lightX = state.vf[15][0], lightY = state.vf[16][0], lightZ = state.vf[17][0],
                attenuationScale = state.vf[12][0], fogFar = state.vf[11][0],
                fogScale = state.vf[11][1];
    __m128 priorClip1 = _mm_loadu_ps(state.vf[1]), priorClip2 = _mm_loadu_ps(state.vf[2]);
    __m128 priorColor = _mm_loadu_ps(state.vf[3]), oldColor = _mm_loadu_ps(state.vf[4]);
    __m128 priorTexture = _mm_loadu_ps(state.vf[5]), currentTexture = _mm_loadu_ps(state.vf[6]);
    __m128 stq = _mm_loadu_ps(state.vf[20]), distanceX = _mm_loadu_ps(state.vf[21]);
    __m128 distanceY = _mm_loadu_ps(state.vf[22]), distanceZ = _mm_loadu_ps(state.vf[23]);
    __m128 squaredDistance = _mm_loadu_ps(state.vf[24]), attenuation = _mm_loadu_ps(state.vf[25]);
    __m128 fog = _mm_loadu_ps(state.vf[26]), projected = _mm_loadu_ps(state.vf[27]);
    __m128 position = _mm_loadu_ps(state.vf[28]), normal = _mm_loadu_ps(state.vf[29]);
    __m128 color = _mm_loadu_ps(state.vf[30]), texture = _mm_loadu_ps(state.vf[31]);
    __m128 colorHistory = load(1016), lastOldClip = priorClip1, lastOldColor = priorColor,
           lastOldTexture = priorTexture;
    __m128 currentClip = _mm_loadu_ps(state.vf[19]), accumulator = _mm_loadu_ps(state.acc);
    uint32_t clipHistory = state.clip, pairs = 0, done = 0;
    int32_t vi1 = state.vi[1], vi9 = state.vi[9], vi13 = state.vi[13];
    float q = state.q;
    for (; done < count && remaining - pairs >= 54; ++done) {
        const unsigned input = initialInput + 4 * done, outputQW = initialOutput + 3 * done;
        // The only late refusal quantities are calculated before any packet or
        // work-vector mutation. Once admitted, finite bounds prove all other
        // arithmetic/FTOI operands finite (products at most approximately2^106).
        const float distance = std::sqrt(std::fabs(lane<0>(squaredDistance)));
        const float lightQ = distance != 0 ? 1.0f / distance : std::numeric_limits<float>::max();
        if (!bounded(lightQ))
            break;
        const float lightAttenuation = attenuationScale * lightQ;
        if (!std::isfinite(lightAttenuation))
            break;
        const __m128 nextPosition = load(input + 4), nextNormal = load(input + 5),
                     nextTexture = load(input + 7), inputColor = load(input + 2);
        const __m128 screenLinear = affineLinear(screen0, screen1, screen2, nextPosition);
        const __m128 nextScreen = madd(screenLinear, screen3, 1.0f);
        const float screenW = lane<3>(nextScreen);
        const float perspectiveQ = screenW != 0 ? 1.0f / screenW
                                                : std::copysign(std::numeric_limits<float>::max(),
                                                                std::copysign(1.0f, screenW));
        if (!bounded(perspectiveQ))
            break;
        const __m128 clipLinear = done ? affineLinear(clip0, clip1, clip2, position)
                                       : affineLinear(entryClip0, entryClip1, entryClip2, position);
        const __m128 clipPoint = madd(clipLinear, done ? clip3 : entryClip3, 1.0f);
        uint32_t nextClip = clip(clip(clip(clipHistory, priorClip1), priorClip2), clipPoint);
        uint32_t flags;
        std::memcpy(&flags, data + 16 * input + 12, 4);
        int32_t nextVI9 = int16_t(flags);
        int32_t nextVI1 = (nextClip & 0x03ffffu) != 0;
        uint32_t pointPairs = nextVI1 ? 56 : 54;
        if (nextVI1 && !nextVI9) {
            constexpr uint32_t masks[6] = {0xfdf7dfu, 0xfefbefu, 0xff7df7u,
                                           0xffbefbu, 0xffdf7du, 0xffefbeu};
            unsigned plane = 0;
            for (; plane < 6; ++plane)
                if (((nextClip | masks[plane]) & 0xffffffu) == 0xffffffu)
                    break;
            if (plane == 6)
                break; // Original BAL0x538 polygon clipping remains outside this kernel.
            nextVI1 = plane < 5 ? (((nextClip | masks[plane + 1]) & 0xffffffu) == 0xffffffu) : 1;
            nextVI9 = int16_t(0x8000u);
            pointPairs = 61 + 2 * plane;
        }
        if (pointPairs > remaining - pairs)
            break;
        // Direct native transform/light/fog pipeline, four vector lanes. History
        // rotation is carried as named vectors, never searched/stored per point.
        const float nx = lane<0>(distanceX) * lightQ, ny = lane<0>(distanceY) * lightQ,
                    nz = lane<0>(distanceZ) * lightQ;
        const float normalX = nx * lane<0>(normal), normalY = ny * lane<1>(normal),
                    normalZ = nz * lane<2>(normal);
        const float normalXY = normalX + normalY;
        const float dot = normalXY + normalZ;
        const float diffuse = dot > 0 ? dot : 0.0f;
        const __m128 lit =
            _mm_add_ps(mul(materialLight, diffuse), _mm_mul_ps(materialColor, inputColor));
        const float limitedAttenuation = lightAttenuation < 1.0f ? lightAttenuation : 1.0f;
        const __m128 lightColor = merge<14>(distanceX, lit);
        const __m128 lightAccum = mul(lightColor, limitedAttenuation);
        const __m128 rgb = _mm_add_ps(lightAccum, _mm_mul_ps(ambient, inputColor));
        const __m128 unclamped = merge<14>(inputColor, rgb);
        const __m128 capped = _mm_min_ps(unclamped, _mm_set1_ps(128.0f));
        const __m128 outputColor = quantize<15, 0>(_mm_mul_ps(capped, modulation));
        const float initialFog = lane<0>(fog) * 255.0f,
                    limitedFog = initialFog < 255.0f ? initialFog : 255.0f;
        const float positiveFog = limitedFog > 0 ? limitedFog : 0.0f;
        const int32_t nextVI13 = int16_t(fixed(positiveFog, 4));
        nextVI9 = int16_t(nextVI9 + nextVI13);
        const float dx = lightX - lane<0>(nextPosition), dy = lightY - lane<1>(nextPosition),
                    dz = lightZ - lane<2>(nextPosition);
        const float squareX = dx * dx, squareY = dy * dy, squareZ = dz * dz;
        const float squareXY = squareX + squareY;
        const float squareXYZ = squareXY + squareZ;
        __m128 nextAffine = mul(texture0, lane<0>(nextTexture));
        nextAffine = madd(nextAffine, texture1, lane<1>(nextTexture));
        nextAffine = madd(nextAffine, texture2, 1.0f);
        const __m128 nextUV = merge<12>(nextTexture, nextAffine);
        const __m128 xyz = quantize<14, 4>(projected);
        const uint32_t adc = uint16_t(nextVI9);
        const __m128 xyzADC = merge<1>(xyz, _mm_castsi128_ps(_mm_set_epi32(int32_t(adc), 0, 0, 0)));
        // Commit only the admitted packet record. Uniforms/input streams and
        // scratch histories were proved disjoint once, before the loop.
        store(outputQW, stq);
        store(outputQW + 1, outputColor);
        store(outputQW + 2, xyzADC);
        lastOldClip = priorClip1;
        lastOldColor = priorColor;
        lastOldTexture = priorTexture;
        priorClip1 = priorClip2;
        priorClip2 = clipPoint;
        priorColor = colorHistory;
        oldColor = colorHistory;
        priorTexture = currentTexture;
        currentTexture = texture;
        colorHistory = outputColor;
        currentClip = clipPoint;
        accumulator = x(merge<14>(screenLinear, lightAccum), squareXY);
        stq = merge<14>(stq, mul(nextUV, perspectiveQ));
        distanceX = x(lightColor, dx);
        distanceY = x(distanceY, dy);
        distanceZ = x(distanceZ, dz);
        squaredDistance = x(squaredDistance, squareXYZ);
        attenuation = x(attenuation, limitedAttenuation);
        fog = x(fog, (fogFar - screenW) * fogScale);
        projected = merge<14>(nextScreen, mul(nextScreen, perspectiveQ));
        position = nextPosition;
        normal = nextNormal;
        color = outputColor;
        texture = nextUV;
        clipHistory = nextClip;
        vi1 = nextVI1;
        vi9 = nextVI9;
        vi13 = nextVI13;
        q = perspectiveQ;
        pairs += pointPairs;
        if (routes) {
            const unsigned route = pointPairs == 54   ? 0
                                   : pointPairs == 56 ? 1
                                                      : 2 + (pointPairs - 61) / 2;
            ++routes[route];
        }
    }
    if (!done)
        return false;
    // One complete-state residue commit at mesh exit or before a declined
    // suffix. Untouched VF/VI/flags/itop/padding bytes remain exactly original.
    _mm_storeu_ps(state.vf[1], priorClip1);
    _mm_storeu_ps(state.vf[2], priorClip2);
    _mm_storeu_ps(state.vf[3], priorColor);
    _mm_storeu_ps(state.vf[4], oldColor);
    _mm_storeu_ps(state.vf[5], priorTexture);
    _mm_storeu_ps(state.vf[6], currentTexture);
    _mm_storeu_ps(state.vf[7], clip0);
    _mm_storeu_ps(state.vf[8], clip1);
    _mm_storeu_ps(state.vf[9], clip2);
    _mm_storeu_ps(state.vf[10], clip3);
    _mm_storeu_ps(state.vf[18], modulation);
    _mm_storeu_ps(state.vf[19], currentClip);
    _mm_storeu_ps(state.vf[20], stq);
    _mm_storeu_ps(state.vf[21], distanceX);
    _mm_storeu_ps(state.vf[22], distanceY);
    _mm_storeu_ps(state.vf[23], distanceZ);
    _mm_storeu_ps(state.vf[24], squaredDistance);
    _mm_storeu_ps(state.vf[25], attenuation);
    _mm_storeu_ps(state.vf[26], fog);
    _mm_storeu_ps(state.vf[27], projected);
    _mm_storeu_ps(state.vf[28], position);
    _mm_storeu_ps(state.vf[29], normal);
    _mm_storeu_ps(state.vf[30], color);
    _mm_storeu_ps(state.vf[31], texture);
    _mm_storeu_ps(state.acc, accumulator);
    store(1015, currentTexture);
    store(1016, color);
    store(1017, priorClip2);
    store(1018, priorTexture);
    store(1019, oldColor);
    store(1020, priorClip1);
    store(1021, lastOldTexture);
    store(1022, lastOldColor);
    store(1023, lastOldClip);
    state.vi[1] = vi1;
    state.vi[4] = int16_t(initialOutput + 3 * done);
    state.vi[5] = int16_t(initialInput + 4 * done);
    state.vi[7] = int16_t(count - done);
    state.vi[9] = vi9;
    state.vi[13] = vi13;
    state.q = q;
    state.i = 128.0f;
    state.clip = clipHistory;
    state.pc = done == count ? 0x4a8 : 0x260;
    pending = false;
    target = 0x4a0;
    output = {done, pairs};
    return true;
}
} // namespace reo_native_static
#if defined(_MSC_VER)
#pragma float_control(pop)
#endif
