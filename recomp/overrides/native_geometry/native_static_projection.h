#pragma once
#include "native_fixed_point.h"
// Event-free expanded polygon geometry, source proposal. Exact image selection
// belongs to the game-owned adapter. Original XGKICK900/AE0 remain outside.
#include "runtime/ps2_vu1.h"
#include <emmintrin.h>
#include <cmath>
#include <climits>
#include <cstdint>
#include <cstring>
#if defined(_MSC_VER)
#pragma float_control(precise, on, push)
#pragma fp_contract(off)
#endif
namespace reo_native_static_projection {
struct Admission {
    bool exactImageSelected, captureInactive;
};
struct Result {
    uint32_t vertices, pairs;
};
namespace detail {
inline bool disjoint(const void* a, size_t an, const void* b, size_t bn) {
    const uintptr_t x = reinterpret_cast<uintptr_t>(a), y = reinterpret_cast<uintptr_t>(b);
    return a && b && x <= UINTPTR_MAX - an && y <= UINTPTR_MAX - bn && (x + an <= y || y + bn <= x);
}
inline bool bounded(__m128 value, float bound, unsigned mask = 15) {
    return reo_native_fixed::bounded(value, bound, mask);
}
template <unsigned C> inline float lane(__m128 value) {
    return _mm_cvtss_f32(_mm_shuffle_ps(value, value, _MM_SHUFFLE(C, C, C, C)));
}
inline __m128 xyz(__m128 retained, __m128 value) {
    const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0, -1, -1, -1));
    return _mm_or_ps(_mm_and_ps(mask, value), _mm_andnot_ps(mask, retained));
}
inline __m128 mul(__m128 a, float b) {
    return _mm_mul_ps(a, _mm_set1_ps(b));
}
inline __m128 madd(__m128 accumulated, __m128 column, float scalar) {
    const __m128 product = mul(column, scalar);
    return _mm_add_ps(accumulated, product);
}
inline int32_t fixed(float value, unsigned shift) {
    const double scaled = double(value) * double(uint32_t(1) << shift);
    return scaled >= 2147483648.0   ? INT32_MAX
           : scaled < -2147483648.0 ? INT32_MIN
                                    : int32_t(scaled);
}
template <unsigned Mask, unsigned Shift> inline __m128 quantize(__m128 value) {
    __m128 converted = value;
    if (reo_native_fixed::convert<Mask, Shift>(converted))
        return converted;
    alignas(16) float v[4];
    _mm_store_ps(v, value);
    for (unsigned c = 0; c < 4; ++c)
        if (Mask & (8u >> c)) {
            const int32_t bits = fixed(v[c], Shift);
            std::memcpy(v + c, &bits, 4);
        }
    return _mm_load_ps(v);
}
struct PacketVertex {
    __m128 stq, rgba, xyzf;
};
} // namespace detail
// Each completed vertex consumes exactly51 pairs, including final branch delay.
// A later unsafe perspective divide or short budget commits only the already
// completed prefix. Refusal before the first completion leaves everything intact.
inline bool executeLoop(VU1State& state, uint8_t* data, uint32_t bytes, uint32_t remaining,
                        bool& pending, uint32_t& target, Admission admission, Result& output) {
    using namespace detail;
    constexpr uint32_t zero[4] = {0, 0, 0, 0x3f800000};
    if (!admission.exactImageSelected || !admission.captureInactive || bytes != 16384 ||
        state.pc != 0x930 || state.ebit || pending || remaining < 51 || state.vi[0] ||
        std::memcmp(state.vf[0], zero, 16) || !disjoint(&state, sizeof(state), data, bytes))
        return false;
    const int count = state.vi[4];
    if (count < 1 || count > 12)
        return false;
    const unsigned input = uint16_t(state.vi[9]), destination = uint16_t(state.vi[6]);
    if (input < 935 || input > 971 || (input - 935) % 3 || input + 3 * count > 975 ||
        destination < 24 || destination + 3 * count > 920)
        return false;
    const auto load = [&](unsigned qw) {
        return _mm_loadu_ps(reinterpret_cast<const float*>(data + 16 * qw));
    };
    constexpr float sourceBound = 1099511627776.0f, matrixBound = 33554432.0f;
    const __m128 column0 = _mm_loadu_ps(state.vf[27]), column1 = _mm_loadu_ps(state.vf[28]);
    const __m128 column2 = _mm_loadu_ps(state.vf[29]), column3 = _mm_loadu_ps(state.vf[30]);
    if (!bounded(column0, matrixBound) || !bounded(column1, matrixBound) ||
        !bounded(column2, matrixBound) || !bounded(column3, matrixBound) ||
        !bounded(_mm_loadu_ps(state.vf[26]), matrixBound, 12))
        return false;
    for (int i = 0; i < count; ++i)
        if (!bounded(load(input + 3 * i), sourceBound) ||
            !bounded(load(input + 3 * i + 1), sourceBound) ||
            !bounded(load(input + 3 * i + 2), sourceBound, 14))
            return false;
    const float fogFar = state.vf[26][0], fogScale = state.vf[26][1];
    PacketVertex packets[12];
    __m128 finalPosition{}, finalColor{}, finalTexture{}, finalACC{};
    float finalQ = 0;
    int32_t finalFog = 0;
    unsigned completed = 0;
    const unsigned allowance = remaining / 51;
    for (unsigned i = 0; i < unsigned(count) && i < allowance; ++i) {
        const __m128 position = load(input + 3 * i), color = load(input + 3 * i + 1),
                     texture = load(input + 3 * i + 2);
        __m128 linear = mul(column0, lane<0>(position));
        linear = madd(linear, column1, lane<1>(position));
        linear = madd(linear, column2, lane<2>(position));
        const __m128 screen = madd(linear, column3, lane<3>(position));
        const float w = lane<3>(screen);
        if (w == 0.0f)
            break; // Original signed saturated zero-DIV remains generic.
        const float q = _mm_cvtss_f32(_mm_div_ss(_mm_set_ss(1.0f), _mm_set_ss(w)));
        if (!std::isfinite(q) || std::fabs(q) > matrixBound)
            break;
        const __m128 limitedColor = xyz(color, _mm_min_ps(color, _mm_set1_ps(128.0f)));
        const __m128 rgba = quantize<15, 0>(limitedColor);
        const __m128 perspectivePosition = xyz(screen, mul(screen, q));
        const __m128 stq = xyz(texture, mul(texture, q));
        const __m128 fixedPosition = quantize<14, 4>(perspectivePosition);
        // Preserve original SUB/MUL/MULI/MINI/MAX f32 order and quantization.
        __m128 fog = _mm_sub_ss(_mm_set_ss(fogFar), _mm_set_ss(w));
        fog = _mm_mul_ss(fog, _mm_set_ss(fogScale));
        fog = _mm_mul_ss(fog, _mm_set_ss(255.0f));
        fog = _mm_min_ss(fog, _mm_set_ss(255.0f));
        fog = _mm_max_ss(fog, _mm_setzero_ps());
        const int32_t fogBits = fixed(_mm_cvtss_f32(fog), 4);
        float packedFog;
        std::memcpy(&packedFog, &fogBits, 4);
        alignas(16) float xyzf[4];
        _mm_store_ps(xyzf, fixedPosition);
        std::memcpy(xyzf + 3, &fogBits, 4);
        packets[i] = {stq, rgba, _mm_load_ps(xyzf)};
        // Residual VF23.x is fog, while emitted XYZ.x is the screen coordinate.
        finalPosition = _mm_move_ss(fixedPosition, _mm_set_ss(packedFog));
        finalColor = rgba;
        finalTexture = stq;
        finalACC = linear;
        finalQ = q;
        finalFog = int16_t(fogBits);
        ++completed;
    }
    if (!completed)
        return false;
    for (unsigned i = 0; i < completed; ++i) {
        _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * (destination + 3 * i)), packets[i].stq);
        _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * (destination + 3 * i + 1)),
                      packets[i].rgba);
        _mm_storeu_ps(reinterpret_cast<float*>(data + 16 * (destination + 3 * i + 2)),
                      packets[i].xyzf);
    }
    _mm_storeu_ps(state.vf[23], finalPosition);
    _mm_storeu_ps(state.vf[24], finalColor);
    _mm_storeu_ps(state.vf[25], finalTexture);
    _mm_storeu_ps(state.acc, finalACC);
    state.q = finalQ;
    state.i = 255.0f;
    state.vi[4] = int16_t(count - completed);
    state.vi[6] = int16_t(destination + 3 * completed);
    state.vi[9] = int16_t(input + 3 * completed);
    state.vi[13] = finalFog;
    state.pc = state.vi[4] ? 0x930 : 0xac8;
    pending = false;
    target = 0xac0;
    output = {completed, 51 * completed};
    return true;
}
} // namespace reo_native_static_projection
#if defined(_MSC_VER)
#pragma float_control(pop)
#endif
