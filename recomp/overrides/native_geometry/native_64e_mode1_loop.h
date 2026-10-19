#pragma once
#include "native_fixed_point.h"
// Private game-owned native mesh loop. No opcode dispatch, instruction-step loop,
// per-pair PC update, branch-delay scheduling, or per-pair budget checks.
#include "runtime/ps2_vu1.h"
#include <array>
#include <emmintrin.h>
#include <cmath>
#include <climits>
#include <cstdint>
#include <cstring>
#include <limits>
#include <type_traits>
#if defined(_MSC_VER)
#pragma float_control(precise, on, push)
#pragma fp_contract(off)
#endif
namespace reo_native_64e_rigid {
struct Admission {
    bool exactImageSelected = false, captureInactive = false;
};
struct Result {
    uint32_t vertices = 0, pairs = 0;
};
inline float mul(float a, float b) {
    return a * b;
}
inline float add(float a, float b) {
    return a + b;
}
inline float sub(float a, float b) {
    return a - b;
}
inline float divq(float numerator, float denominator) {
    return denominator != 0 ? numerator / denominator
                            : std::copysign(std::numeric_limits<float>::max(),
                                            numerator * std::copysign(1.0f, denominator));
}
inline uint32_t bits(float x) {
    uint32_t b;
    std::memcpy(&b, &x, 4);
    return b;
}
inline float literal(uint32_t b) {
    float x;
    std::memcpy(&x, &b, 4);
    return x;
}
inline bool convert(float x, unsigned shift, float& out) {
    const double scaled = double(x) * double(uint32_t(1) << shift);
    if (std::isnan(scaled))
        return false; // Original cast is undefined here; decline transactionally.
    const int32_t r = scaled >= 2147483648.0   ? INT32_MAX
                      : scaled < -2147483648.0 ? INT32_MIN
                                               : int32_t(scaled);
    std::memcpy(&out, &r, 4);
    return true;
}
template <unsigned C> inline __m128 spread(__m128 value) {
    return _mm_shuffle_ps(value, value, _MM_SHUFFLE(C, C, C, C));
}
template <unsigned C> inline float lane(__m128 value) {
    return _mm_cvtss_f32(spread<C>(value));
}
template <unsigned M> inline __m128 merge(__m128 oldValue, __m128 value) {
    if constexpr (M == 15)
        return value;
    else if constexpr (M == 0)
        return oldValue;
    else {
        const __m128 mask = _mm_castsi128_ps(
            _mm_set_epi32(M & 1 ? -1 : 0, M & 2 ? -1 : 0, M & 4 ? -1 : 0, M & 8 ? -1 : 0));
        return _mm_or_ps(_mm_and_ps(mask, value), _mm_andnot_ps(mask, oldValue));
    }
}
template <unsigned M, unsigned S> inline bool toInteger(__m128& value) {
    return reo_native_fixed::convert<M, S>(value);
}
// Certificate applies to consumed numeric lanes only; raw/copy lanes remain exact.
constexpr float NumericBound = 32768.0f;
constexpr float ProjectedBound = 67108864.0f;
constexpr float ProjectionTranslationBound = 33554432.0f;
template <unsigned M> inline bool bounded(__m128 value, float bound = NumericBound) {
    constexpr unsigned lanes =
        ((M & 8) ? 1 : 0) | ((M & 4) ? 2 : 0) | ((M & 2) ? 4 : 0) | ((M & 1) ? 8 : 0);
    const __m128 absolute = _mm_and_ps(value, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
    return (unsigned(_mm_movemask_ps(_mm_cmple_ps(absolute, _mm_set1_ps(bound)))) & lanes) == lanes;
}
inline bool boundedScalar(float value) {
    return std::isfinite(value) && std::fabs(value) <= NumericBound;
}
inline bool overlap(const void* a, size_t na, const void* b, size_t nb) {
    const uintptr_t aa = reinterpret_cast<uintptr_t>(a), bb = reinterpret_cast<uintptr_t>(b);
    return aa <= bb ? bb - aa < na : aa - bb < nb;
}
// Distinct64e mode1 semantic body; carried MAC behavior matches03A only.
// The selected full 16KiB image must be 64e4b38e...10d3. A signature bucket is
// insufficient; the different2ea program must not call this implementation.
inline bool executeLoop(VU1State& original, uint8_t* originalData, uint32_t dataBytes,
                        uint32_t remaining, bool& pending, uint32_t& target, Admission admission,
                        Result& output) {
    if (!admission.exactImageSelected || !admission.captureInactive || !originalData ||
        dataBytes != 16384 || original.pc != 0x298 || original.ebit || pending ||
        original.vi[6] != 1 || original.vi[0] != 0 ||
        overlap(&original, sizeof(original), originalData, dataBytes))
        return false;
    const uint32_t vertices = uint16_t(original.vi[7]);
    if (!vertices || vertices > 256 || remaining < vertices * 117u)
        return false;
    if (bits(original.vf[0][0]) || bits(original.vf[0][1]) || bits(original.vf[0][2]) ||
        bits(original.vf[0][3]) != 0x3f800000u)
        return false;
    // Initial proof version stages all state/data: any rejected arithmetic leaves
    // the real input unchanged. This 32KiB copy cost must be measured separately.
    VU1State s;
    std::memcpy(&s, &original, sizeof(s));
    std::array<uint8_t, 16384> memory;
    std::memcpy(memory.data(), originalData, memory.size());
    const __m128 column0 = _mm_loadu_ps(s.vf[0]);
    const __m128 column1 = _mm_loadu_ps(s.vf[1]);
    const __m128 column2 = _mm_loadu_ps(s.vf[2]);
    const __m128 column3 = _mm_loadu_ps(s.vf[3]);
    const __m128 column4 = _mm_loadu_ps(s.vf[4]);
    const __m128 column5 = _mm_loadu_ps(s.vf[5]);
    const __m128 column6 = _mm_loadu_ps(s.vf[6]);
    const __m128 column7 = _mm_loadu_ps(s.vf[7]);
    const __m128 column8 = _mm_loadu_ps(s.vf[8]);
    const __m128 column9 = _mm_loadu_ps(s.vf[9]);
    const __m128 column10 = _mm_loadu_ps(s.vf[10]);
    const __m128 column11 = _mm_loadu_ps(s.vf[11]);
    const __m128 column12 = _mm_loadu_ps(s.vf[12]);
    const __m128 column13 = _mm_loadu_ps(s.vf[13]);
    const __m128 column14 = _mm_loadu_ps(s.vf[14]);
    const __m128 column15 = _mm_loadu_ps(s.vf[15]);
    const __m128 column16 = _mm_loadu_ps(s.vf[16]);
    const __m128 column17 = _mm_loadu_ps(s.vf[17]);
    const __m128 column18 = _mm_loadu_ps(s.vf[18]);
    const __m128 column19 = _mm_loadu_ps(s.vf[19]);
    const __m128 column20 = _mm_loadu_ps(s.vf[20]);
    const __m128 column21 = _mm_loadu_ps(s.vf[21]);
    // Constants are immutable within this body. No Q/P/I/working/raw-state scan.
    for (unsigned r = 1; r <= 9; ++r)
        if (!bounded<15>(_mm_loadu_ps(s.vf[r]), r == 4 ? ProjectionTranslationBound : NumericBound))
            return false;
    if (!bounded<12>(column10))
        return false;
    if (!bounded<14>(column11) || !bounded<14>(column12) || !bounded<14>(column13))
        return false;
    // FLT_MAX is the original legitimate attenuation sentinel. Check its
    // consumed products before the later MINI instead of rejecting the input.
    if (!bounded<6>(column14, std::numeric_limits<float>::max()) || s.vf[14][1] < 0 ||
        s.vf[14][2] < 0)
        return false;
    for (unsigned r = 15; r <= 21; ++r)
        if (!bounded<14>(_mm_loadu_ps(s.vf[r])))
            return false;
    __m128 lightX = _mm_loadu_ps(s.vf[22]);
    __m128 lightY = _mm_loadu_ps(s.vf[23]);
    __m128 lightZ = _mm_loadu_ps(s.vf[24]);
    __m128 distance = _mm_loadu_ps(s.vf[25]);
    __m128 color = _mm_loadu_ps(s.vf[26]);
    __m128 stq = _mm_loadu_ps(s.vf[27]);
    __m128 screen = _mm_loadu_ps(s.vf[28]);
    __m128 position = _mm_loadu_ps(s.vf[29]);
    __m128 normal = _mm_loadu_ps(s.vf[30]);
    __m128 uv = _mm_loadu_ps(s.vf[31]);
    __m128 accumulator = _mm_loadu_ps(s.acc);
    auto& vi = s.vi;
    uint32_t pairs = 0;
    auto address = [](int32_t q) { return (uint32_t(q) * 16u) & 16383u; };
    auto load = [&](int32_t q) {
        return _mm_loadu_ps(reinterpret_cast<const float*>(memory.data() + address(q)));
    };
    auto store = [&](int32_t q, __m128 value, auto maskConstant) {
        constexpr unsigned M = decltype(maskConstant)::value;
        const auto off = address(q);
        _mm_storeu_ps(
            reinterpret_cast<float*>(memory.data() + off),
            merge<M>(_mm_loadu_ps(reinterpret_cast<const float*>(memory.data() + off)), value));
    };
    auto iload = [&](int32_t q, unsigned c) {
        uint32_t x;
        std::memcpy(&x, memory.data() + address(q) + c * 4, 4);
        return int32_t(int16_t(x));
    };
    auto istore = [&](int32_t q, unsigned c, int32_t x) {
        const uint32_t value = uint16_t(x);
        std::memcpy(memory.data() + address(q) + c * 4, &value, 4);
    };
    for (uint32_t vertex = 0; vertex < vertices; ++vertex) {
        bool markADC = false, rawControl = false, checkedMAC = false;
        // Owned64e arithmetic/memory sequence0x298.
        vi[9] = iload(vi[5] + (0), 3);
        // Owned64e arithmetic/memory sequence0x2a0.
        position = merge<15>(position, load(vi[5] + (0)));
        if (!bounded<14>(position, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2a8.
        normal = merge<15>(normal, load(vi[5] + (1)));
        if (!bounded<15>(normal, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2b0.
        vi[10] = iload(vi[5] + (3), 0);
        // Owned64e arithmetic/memory sequence0x2b8.
        vi[11] = iload(vi[5] + (3), 1);
        // Owned64e arithmetic/memory sequence0x2c0.
        uv = merge<15>(uv, load(vi[5] + (2)));
        if (!bounded<14>(uv, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2c8.
        vi[5] = int16_t(vi[5] + 5);
        // Owned64e arithmetic/memory sequence0x2d0.
        lightY = merge<15>(lightY, load(vi[0] + (11)));
        if (!bounded<12>(lightY, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2d8.
        lightZ = merge<15>(lightZ, load(vi[0] + (12)));
        if (!bounded<12>(lightZ, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2e0.
        distance = merge<15>(distance, load(vi[0] + (13)));
        if (!bounded<12>(distance, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2e8.
        lightX = merge<15>(lightX, load(vi[10] + (0)));
        if (!bounded<15>(lightX, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2f0.
        accumulator = merge<12>(accumulator, _mm_mul_ps(lightY, spread<0>(uv)));
        lightY = merge<15>(lightY, load(vi[10] + (1)));
        if (!bounded<15>(lightY, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x2f8.
        accumulator =
            merge<12>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<1>(uv))));
        lightZ = merge<15>(lightZ, load(vi[10] + (2)));
        if (!bounded<15>(lightZ, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x300.
        uv = merge<12>(uv, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<3>(column0))));
        distance = merge<15>(distance, load(vi[10] + (3)));
        if (!bounded<15>(distance, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x308.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightX, spread<0>(position)));
        // Owned64e arithmetic/memory sequence0x310.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(lightY, spread<1>(position))));
        lightY = merge<15>(lightY, load(vi[0] + (1016)));
        if (!bounded<14>(lightY, ProjectedBound))
            return false;
        // Owned64e arithmetic/memory sequence0x318.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<2>(position))));
        lightZ = merge<15>(lightZ, load(vi[0] + (1015)));
        if (!bounded<14>(lightZ, ProjectedBound))
            return false;
        // Owned64e arithmetic/memory sequence0x320.
        position =
            merge<15>(position, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<3>(column0))));
        // Owned64e arithmetic/memory sequence0x330.
        store(vi[0] + (1017), lightY, std::integral_constant<unsigned, 15>{});
        // Owned64e arithmetic/memory sequence0x338.
        store(vi[0] + (1016), lightZ, std::integral_constant<unsigned, 15>{});
        // Owned64e arithmetic/memory sequence0x340.
        accumulator = merge<15>(accumulator, _mm_mul_ps(column1, spread<0>(position)));
        lightX = merge<15>(lightX, load(vi[11] + (0)));
        if (!bounded<15>(lightX, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x348.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column2, spread<1>(position))));
        lightY = merge<15>(lightY, load(vi[11] + (1)));
        if (!bounded<15>(lightY, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x350.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column3, spread<2>(position))));
        lightZ = merge<15>(lightZ, load(vi[11] + (2)));
        if (!bounded<15>(lightZ, NumericBound))
            return false;
        // Owned64e arithmetic/memory sequence0x358.
        screen =
            merge<15>(screen, _mm_add_ps(accumulator, _mm_mul_ps(column4, spread<3>(column0))));
        // Owned64e arithmetic/memory sequence0x360.
        accumulator = merge<14>(accumulator, _mm_mul_ps(lightX, spread<0>(normal)));
        // Owned64e arithmetic/memory sequence0x368.
        accumulator =
            merge<14>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightY, spread<1>(normal))));
        // Owned64e arithmetic/memory sequence0x370.
        normal = merge<14>(normal, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<2>(normal))));
        // Owned64e arithmetic/memory sequence0x378.
        lightX = merge<6>(lightX, _mm_sub_ps(column11, spread<0>(position)));
        s.q = divq(lane<3>(column0), lane<3>(screen));
        if (!boundedScalar(s.q))
            return false;
        // Owned64e arithmetic/memory sequence0x380.
        lightY = merge<6>(lightY, _mm_sub_ps(column12, spread<1>(position)));
        // Owned64e arithmetic/memory sequence0x388.
        lightZ = merge<6>(lightZ, _mm_sub_ps(column13, spread<2>(position)));
        // Owned64e arithmetic/memory sequence0x390.
        lightX = merge<8>(lightX, _mm_add_ps(column11, spread<0>(column0)));
        // Owned64e arithmetic/memory sequence0x398.
        lightY = merge<8>(lightY, _mm_add_ps(column12, spread<0>(column0)));
        // Owned64e arithmetic/memory sequence0x3a0.
        lightZ = merge<8>(lightZ, _mm_add_ps(column13, spread<0>(column0)));
        // Owned64e arithmetic/memory sequence0x3b0.
        screen = merge<14>(screen, _mm_mul_ps(screen, _mm_set1_ps(s.q)));
        if (!bounded<14>(screen, ProjectedBound))
            return false;
        // Owned64e arithmetic/memory sequence0x3b8.
        accumulator = merge<6>(accumulator, _mm_mul_ps(lightX, lightX));
        // Owned64e arithmetic/memory sequence0x3c0.
        stq = merge<14>(stq, _mm_mul_ps(uv, _mm_set1_ps(s.q)));
        // Owned64e arithmetic/memory sequence0x3c8.
        accumulator = merge<6>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightY, lightY)));
        // Owned64e arithmetic/memory sequence0x3d0.
        distance = merge<6>(distance, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, lightZ)));
        store(vi[0] + (1015), screen, std::integral_constant<unsigned, 15>{});
        // Owned64e arithmetic/memory sequence0x3d8.
        if (!toInteger<14, 4>(screen))
            return false;
        // Owned64e arithmetic/memory sequence0x3e0.
        accumulator = merge<15>(accumulator, _mm_mul_ps(column5, spread<0>(position)));
        store(vi[4] + (0), stq, std::integral_constant<unsigned, 15>{});
        // Owned64e arithmetic/memory sequence0x3e8.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column6, spread<1>(position))));
        // Owned64e arithmetic/memory sequence0x3f0.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column7, spread<2>(position))));
        {
            float value = lane<1>(distance);
            if (value >= 0) {
                value = std::sqrt(value);
                if (value != 0)
                    value = 1.0f / value;
            }
            s.p = value;
        }
        if (!boundedScalar(s.p))
            return false;
        // Owned64e arithmetic/memory sequence0x3f8.
        position =
            merge<15>(position, _mm_add_ps(accumulator, _mm_mul_ps(column8, spread<3>(column0))));
        s.q = divq(lane<3>(column0), std::sqrt(std::fabs(lane<2>(distance))));
        if (!boundedScalar(s.q))
            return false;
        // Owned64e arithmetic/memory sequence0x400.
        store(vi[4] + (2), screen, std::integral_constant<unsigned, 14>{});
        // Owned64e arithmetic/memory sequence0x408.
        screen = merge<8>(screen, _mm_sub_ps(column10, spread<3>(screen)));
        // Owned64e arithmetic/memory sequence0x418.
        {
            const float w = std::fabs(lane<3>(position));
            uint32_t flags = 0;
            {
                const float v = lane<0>(position);
                if (v > w)
                    flags |= 1u;
                if (v < -w)
                    flags |= 2u;
            }
            {
                const float v = lane<1>(position);
                if (v > w)
                    flags |= 4u;
                if (v < -w)
                    flags |= 8u;
            }
            {
                const float v = lane<2>(position);
                if (v > w)
                    flags |= 16u;
                if (v < -w)
                    flags |= 32u;
            }
            s.clip = ((s.clip << 6) | flags) & 0xffffffu;
        }
        // Owned64e arithmetic/memory sequence0x428.
        screen = merge<8>(screen, _mm_mul_ps(screen, spread<1>(column10)));
        // Owned64e arithmetic/memory sequence0x438.
        vi[1] = ((s.clip & 0x03ffffu) != 0) ? 1 : 0;
        // Owned64e arithmetic/memory sequence0x440.
        s.i = literal(0x437f0000u);
        // Owned64e arithmetic/memory sequence0x448.
        screen = merge<8>(screen, _mm_mul_ps(screen, _mm_set1_ps(s.i)));
        // Owned64e arithmetic/memory sequence0x460.
        lightX = merge<2>(lightX, _mm_mul_ps(lightX, _mm_set1_ps(s.q)));
        // Owned64e arithmetic/memory sequence0x468.
        lightY = merge<2>(lightY, _mm_mul_ps(lightY, _mm_set1_ps(s.q)));
        // Owned64e arithmetic/memory sequence0x470.
        lightZ = merge<2>(lightZ, _mm_mul_ps(lightZ, _mm_set1_ps(s.q)));
        // Owned64e arithmetic/memory sequence0x478.
        color = merge<2>(color, _mm_mul_ps(column14, _mm_set1_ps(s.q)));
        if (!bounded<2>(color, std::numeric_limits<float>::max()))
            return false;
        // Owned64e arithmetic/memory sequence0x480.
        screen = merge<8>(screen, _mm_min_ps(screen, _mm_set1_ps(s.i)));
        distance = merge<4>(distance, _mm_set1_ps(s.p));
        // Owned64e arithmetic/memory sequence0x4a0.
        lightX = merge<4>(lightX, _mm_mul_ps(lightX, distance));
        // Owned64e arithmetic/memory sequence0x4a8.
        lightY = merge<4>(lightY, _mm_mul_ps(lightY, distance));
        // Owned64e arithmetic/memory sequence0x4b0.
        lightZ = merge<4>(lightZ, _mm_mul_ps(lightZ, distance));
        // Owned64e arithmetic/memory sequence0x4b8.
        color = merge<4>(color, _mm_mul_ps(column14, distance));
        if (!bounded<4>(color, std::numeric_limits<float>::max()))
            return false;
        // Owned64e arithmetic/memory sequence0x4c0.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightX, spread<0>(normal)));
        // Owned64e arithmetic/memory sequence0x4c8.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightY, spread<1>(normal))));
        // Owned64e arithmetic/memory sequence0x4d0.
        lightX = merge<15>(lightX, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<2>(normal))));
        // Owned64e arithmetic/memory sequence0x4d8.
        color = merge<6>(color, _mm_min_ps(color, spread<3>(column0)));
        // Owned64e arithmetic/memory sequence0x4e0.
        screen = merge<8>(screen, _mm_max_ps(screen, spread<0>(column0)));
        // Owned64e arithmetic/memory sequence0x4f0.
        lightX = merge<14>(lightX, _mm_max_ps(lightX, spread<0>(column0)));
        // Owned64e arithmetic/memory sequence0x500.
        if (!toInteger<8, 4>(screen))
            return false;
        // Owned64e arithmetic/memory sequence0x510.
        lightX = merge<6>(lightX, _mm_mul_ps(lightX, color));
        // Owned64e arithmetic/memory sequence0x520.
        vi[13] = int16_t(bits(lane<0>(screen)));
        // Owned64e arithmetic/memory sequence0x530.
        accumulator = merge<14>(accumulator, _mm_mul_ps(column15, spread<0>(lightX)));
        // Owned64e arithmetic/memory sequence0x538.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column16, spread<1>(lightX))));
        // Owned64e arithmetic/memory sequence0x540.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column17, spread<2>(lightX))));
        // Owned64e arithmetic/memory sequence0x548.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column18, spread<3>(column0))));
        // Owned64e arithmetic/memory sequence0x550.
        accumulator =
            merge<14>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(column19, spread<1>(color))));
        // Owned64e arithmetic/memory sequence0x558.
        accumulator =
            merge<14>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(column20, spread<2>(color))));
        color = merge<15>(color, load(vi[0] + (1017)));
        if (!bounded<14>(color, ProjectedBound))
            return false;
        // Owned64e arithmetic/memory sequence0x560.
        lightX =
            merge<14>(lightX, _mm_add_ps(accumulator, _mm_mul_ps(column21, spread<3>(column0))));
        distance = merge<15>(distance, load(vi[0] + (1016)));
        if (!bounded<14>(distance, ProjectedBound))
            return false;
        // Owned64e arithmetic/memory sequence0x568.
        lightZ = merge<15>(lightZ, load(vi[0] + (1015)));
        if (!bounded<14>(lightZ, ProjectedBound))
            return false;
        // Owned64e arithmetic/memory sequence0x570.
        s.i = literal(0x43000000u);
        // Owned64e arithmetic/memory sequence0x580.
        lightX = merge<15>(lightX, _mm_min_ps(lightX, _mm_set1_ps(s.i)));
        // Owned64e arithmetic/memory sequence0x588.
        distance = merge<14>(distance, _mm_sub_ps(distance, color));
        // Owned64e arithmetic/memory sequence0x590.
        color = merge<14>(color, _mm_sub_ps(lightZ, color));
        vi[4] = int16_t(vi[4] + 3);
        // Owned64e arithmetic/memory sequence0x598.
        vi[7] = int16_t(vi[7] + (-1));
        // Owned64e arithmetic/memory sequence0x5a0.
        lightX = merge<15>(lightX, _mm_mul_ps(lightX, column9));
        // Owned64e arithmetic/memory sequence0x5b0.
        accumulator = merge<14>(
            accumulator, _mm_mul_ps(_mm_shuffle_ps(color, color, _MM_SHUFFLE(3, 0, 2, 1)),
                                    _mm_shuffle_ps(distance, distance, _MM_SHUFFLE(3, 1, 0, 2))));
        // Owned64e arithmetic/memory sequence0x5b8.
        color = merge<14>(
            color,
            _mm_sub_ps(accumulator,
                       _mm_mul_ps(_mm_shuffle_ps(distance, distance, _MM_SHUFFLE(3, 0, 2, 1)),
                                  _mm_shuffle_ps(color, color, _MM_SHUFFLE(3, 1, 0, 2)))));
        // Owned64e arithmetic/memory sequence0x5c0.
        if (!toInteger<14, 0>(lightX))
            return false;
        // Owned64e arithmetic/memory sequence0x5d0.
        istore(vi[4] + (-2), 3, vi[15]);
        // Owned64e arithmetic/memory sequence0x5d8.
        color = merge<2>(color, _mm_mul_ps(color, spread<3>(normal)));
        const bool clipRejected = (vi[0] != vi[1]);
        markADC = clipRejected;
        // Owned64e arithmetic/memory sequence0x5e0.
        store(vi[4] + (-2), lightX, std::integral_constant<unsigned, 14>{});
        if (!clipRejected) {
            // Owned64e arithmetic/memory sequence0x5e8.
            rawControl = (vi[0] != vi[9]);
            if (!rawControl) {
                checkedMAC = true;
                // Owned64e arithmetic/memory sequence0x5f8.
                vi[1] = int16_t(vi[0] + 32);
                // Owned64e arithmetic/memory sequence0x600.
                vi[1] = int32_t(s.mac & uint16_t(vi[1]));
                // Owned64e arithmetic/memory sequence0x608.
                markADC = (vi[0] != vi[1]);
            }
        }
        if (markADC) {
            // Owned64e arithmetic/memory sequence0x618.
            vi[9] = int16_t(vi[0] + 32767);
            // Owned64e arithmetic/memory sequence0x620.
            vi[9] = int16_t(vi[9] + 1);
        }
        // Owned64e arithmetic/memory sequence0x628.
        vi[9] = int16_t(vi[9] + vi[13]);
        // Owned64e arithmetic/memory sequence0x638.
        istore(vi[4] + (-1), 3, vi[9]);
        pairs += 111u + (checkedMAC ? 4u : 0u) + (checkedMAC && markADC ? 2u : 0u);
    }
    if (vi[7] != 0)
        return false;
    // Materialize all carried working vectors exactly once, after the native mesh loop.
    _mm_storeu_ps(s.vf[22], lightX);
    _mm_storeu_ps(s.vf[23], lightY);
    _mm_storeu_ps(s.vf[24], lightZ);
    _mm_storeu_ps(s.vf[25], distance);
    _mm_storeu_ps(s.vf[26], color);
    _mm_storeu_ps(s.vf[27], stq);
    _mm_storeu_ps(s.vf[28], screen);
    _mm_storeu_ps(s.vf[29], position);
    _mm_storeu_ps(s.vf[30], normal);
    _mm_storeu_ps(s.vf[31], uv);
    _mm_storeu_ps(s.acc, accumulator);
    s.pc = 0x640;
    pending = false;
    target = 0x638;
    std::memcpy(&original, &s, sizeof(s));
    std::memcpy(originalData, memory.data(), memory.size());
    output = Result{vertices, pairs};
    return true;
}
} // namespace reo_native_64e_rigid
#if defined(_MSC_VER)
#pragma float_control(pop)
#endif
