#pragma once
#include "native_fixed_point.h"
// Private game-owned native mesh loop. No opcode dispatch, instruction-step loop,
// per-pair PC update, branch-delay scheduling, or per-pair budget checks.
#include "runtime/ps2_vu1.h"
#include "native_geometry_refusal.h"
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
namespace reo_native_multibone {
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
inline bool overlap(const void* a, size_t na, const void* b, size_t nb) {
    const uintptr_t aa = reinterpret_cast<uintptr_t>(a), bb = reinterpret_cast<uintptr_t>(b);
    return aa <= bb ? bb - aa < na : aa - bb < nb;
}
// Native 4-slot unit-weight blend; variable names retain their physical VF roles.
// The selected full 16KiB image must be 2ea02b...32ce. A signature bucket is
// insufficient; the different 64e4b38e program must not call this implementation.
inline bool executeLoop(VU1State& original, uint8_t* originalData, uint32_t dataBytes,
                        uint32_t remaining, bool& pending, uint32_t& target, Admission admission,
                        Result& output, reo_native_refusal::Event* refusal = nullptr) {
    if (refusal) {
        *refusal = {};
        refusal->originalPC = original.pc;
        refusal->mode = uint16_t(original.vi[6]);
        refusal->originalInput = uint16_t(original.vi[5]);
        refusal->originalOutput = uint16_t(original.vi[4]);
    }
    if (!admission.exactImageSelected || !admission.captureInactive || !originalData ||
        dataBytes != 16384 || original.pc != 0x760 || original.ebit || pending ||
        original.vi[6] != 2 || original.vi[0] != 0 ||
        overlap(&original, sizeof(original), originalData, dataBytes)) {
        reo_native_refusal::stage(refusal, reo_native_refusal::Reason::Structural, original.pc, 0,
                                  uint16_t(original.vi[7]), remaining);
        return false;
    }
    if (refusal) {
        refusal->originalPC = original.pc;
        refusal->mode = uint16_t(original.vi[6]);
        refusal->originalInput = uint16_t(original.vi[5]);
        refusal->originalOutput = uint16_t(original.vi[4]);
    }
    const uint32_t vertices = uint16_t(original.vi[7]);
    if (!vertices || vertices > 256 || remaining < vertices * 117u) {
        reo_native_refusal::stage(refusal, reo_native_refusal::Reason::CountOrBudget, original.pc,
                                  0, vertices, remaining);
        return false;
    }
    if (bits(original.vf[0][0]) || bits(original.vf[0][1]) || bits(original.vf[0][2]) ||
        bits(original.vf[0][3]) != 0x3f800000u) {
        reo_native_refusal::stage(refusal, reo_native_refusal::Reason::ZeroRegisters, original.pc,
                                  0, vertices, remaining);
        return false;
    }
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
        // Original arithmetic/memory sequence0x760.
        lightY = merge<15>(lightY, _mm_add_ps(accumulator, _mm_mul_ps(stq, spread<3>(uv))));
        stq = merge<15>(stq, load(vi[13] + (2)));
        // Original arithmetic/memory sequence0x768.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightZ, spread<0>(uv)));
        position = merge<15>(position, load(vi[10] + (3)));
        // Original arithmetic/memory sequence0x770.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<1>(uv))));
        distance = merge<15>(distance, load(vi[11] + (3)));
        // Original arithmetic/memory sequence0x778.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(color, spread<2>(uv))));
        color = merge<15>(color, load(vi[12] + (3)));
        // Original arithmetic/memory sequence0x780.
        lightZ = merge<15>(lightZ, _mm_add_ps(accumulator, _mm_mul_ps(stq, spread<3>(uv))));
        stq = merge<15>(stq, load(vi[13] + (3)));
        // Original arithmetic/memory sequence0x788.
        accumulator = merge<15>(accumulator, _mm_mul_ps(position, spread<0>(uv)));
        screen = merge<15>(screen, load(vi[5] + (0)));
        // Original arithmetic/memory sequence0x790.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<1>(uv))));
        vi[9] = iload(vi[5] + (0), 3);
        // Original arithmetic/memory sequence0x798.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(color, spread<2>(uv))));
        // Original arithmetic/memory sequence0x7a0.
        distance = merge<15>(distance, _mm_add_ps(accumulator, _mm_mul_ps(stq, spread<3>(uv))));
        // Original arithmetic/memory sequence0x7a8.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightX, spread<0>(screen)));
        position = merge<15>(position, load(vi[5] + (1)));
        // Original arithmetic/memory sequence0x7b0.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightY, spread<1>(screen))));
        vi[5] = int16_t(vi[5] + 5);
        // Original arithmetic/memory sequence0x7b8.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<2>(screen))));
        // Original arithmetic/memory sequence0x7c0.
        screen =
            merge<15>(screen, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<3>(column0))));
        // Original arithmetic/memory sequence0x7c8.
        accumulator = merge<14>(accumulator, _mm_mul_ps(lightX, spread<0>(position)));
        // Original arithmetic/memory sequence0x7d0.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(lightY, spread<1>(position))));
        vi[10] = iload(vi[5] + (3), 0);
        // Original arithmetic/memory sequence0x7d8.
        position =
            merge<14>(position, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<2>(position))));
        vi[11] = iload(vi[5] + (3), 1);
        // Original arithmetic/memory sequence0x7e0.
        accumulator = merge<15>(accumulator, _mm_mul_ps(column1, spread<0>(screen)));
        // Original arithmetic/memory sequence0x7e8.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(column2, spread<1>(screen))));
        vi[12] = iload(vi[5] + (3), 2);
        // Original arithmetic/memory sequence0x7f0.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(column3, spread<2>(screen))));
        vi[13] = iload(vi[5] + (3), 3);
        // Original arithmetic/memory sequence0x7f8.
        stq = merge<15>(stq, _mm_add_ps(accumulator, _mm_mul_ps(column4, spread<3>(column0))));
        // Original arithmetic/memory sequence0x800.
        uv = merge<14>(uv, _mm_mul_ps(position, position));
        // Original arithmetic/memory sequence0x808.
        lightX = merge<6>(lightX, _mm_sub_ps(column11, spread<0>(screen)));
        // Original arithmetic/memory sequence0x810.
        lightY = merge<6>(lightY, _mm_sub_ps(column12, spread<1>(screen)));
        // Original arithmetic/memory sequence0x818.
        lightZ = merge<6>(lightZ, _mm_sub_ps(column13, spread<2>(screen)));
        s.q = divq(lane<3>(column0), lane<3>(stq));
        // Original arithmetic/memory sequence0x820.
        uv = merge<8>(uv, _mm_add_ps(uv, spread<1>(uv)));
        // Original arithmetic/memory sequence0x828.
        lightX = merge<8>(lightX, _mm_add_ps(column11, spread<0>(column0)));
        // Original arithmetic/memory sequence0x830.
        lightY = merge<8>(lightY, _mm_add_ps(column12, spread<0>(column0)));
        // Original arithmetic/memory sequence0x838.
        lightZ = merge<8>(lightZ, _mm_add_ps(column13, spread<0>(column0)));
        // Original arithmetic/memory sequence0x840.
        uv = merge<8>(uv, _mm_add_ps(uv, spread<2>(uv)));
        // Original arithmetic/memory sequence0x848.
        accumulator = merge<6>(accumulator, _mm_mul_ps(lightX, lightX));
        // Original arithmetic/memory sequence0x850.
        stq = merge<14>(stq, _mm_mul_ps(stq, _mm_set1_ps(s.q)));
        // Original arithmetic/memory sequence0x858.
        normal = merge<14>(normal, _mm_mul_ps(normal, _mm_set1_ps(s.q)));
        // Original arithmetic/memory sequence0x860.
        accumulator = merge<6>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(lightY, lightY)));
        s.q = divq(lane<3>(column0), std::sqrt(std::fabs(lane<0>(uv))));
        // Original arithmetic/memory sequence0x868.
        distance = merge<6>(distance, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, lightZ)));
        // Original arithmetic/memory sequence0x870.
        {
            const __m128 before = stq;
            if (!toInteger<14, 4>(stq)) {
                reo_native_refusal::quantization(refusal, 0x870, 14, 4, before, s.q, s.p, vertex,
                                                 vertices, remaining, lightX, lightY, lightZ,
                                                 distance, color, stq, screen, position, normal, uv,
                                                 accumulator);
                return false;
            }
        }
        // Original arithmetic/memory sequence0x878.
        accumulator = merge<15>(accumulator, _mm_mul_ps(column5, spread<0>(screen)));
        store(vi[4] + (0), normal, std::integral_constant<unsigned, 15>{});
        // Original arithmetic/memory sequence0x880.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(column6, spread<1>(screen))));
        // Original arithmetic/memory sequence0x888.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(column7, spread<2>(screen))));
        {
            float value = lane<1>(distance);
            if (value >= 0) {
                value = std::sqrt(value);
                if (value != 0)
                    value = 1.0f / value;
            }
            s.p = value;
        }
        // Original arithmetic/memory sequence0x890.
        screen =
            merge<15>(screen, _mm_add_ps(accumulator, _mm_mul_ps(column8, spread<3>(column0))));
        store(vi[4] + (2), stq, std::integral_constant<unsigned, 14>{});
        // Original arithmetic/memory sequence0x898.
        normal = merge<15>(normal, load(vi[5] + (2)));
        // Original arithmetic/memory sequence0x8b0.
        {
            const float w = std::fabs(lane<3>(screen));
            uint32_t flags = 0;
            {
                const float v = lane<0>(screen);
                if (v > w)
                    flags |= 1u;
                if (v < -w)
                    flags |= 2u;
            }
            {
                const float v = lane<1>(screen);
                if (v > w)
                    flags |= 4u;
                if (v < -w)
                    flags |= 8u;
            }
            {
                const float v = lane<2>(screen);
                if (v > w)
                    flags |= 16u;
                if (v < -w)
                    flags |= 32u;
            }
            s.clip = ((s.clip << 6) | flags) & 0xffffffu;
        }
        // Original arithmetic/memory sequence0x8b8.
        stq = merge<8>(stq, _mm_sub_ps(column10, spread<3>(stq)));
        // Original arithmetic/memory sequence0x8c8.
        position = merge<14>(position, _mm_mul_ps(position, _mm_set1_ps(s.q)));
        s.q = divq(lane<3>(column0), std::sqrt(std::fabs(lane<2>(distance))));
        // Original arithmetic/memory sequence0x8d0.
        vi[1] = ((s.clip & 0x03ffffu) != 0) ? 1 : 0;
        // Original arithmetic/memory sequence0x8d8.
        stq = merge<8>(stq, _mm_mul_ps(stq, spread<1>(column10)));
        // Original arithmetic/memory sequence0x8e0.
        uv = merge<15>(uv, load(vi[5] + (4)));
        // Original arithmetic/memory sequence0x8f0.
        s.i = literal(0x437f0000u);
        // Original arithmetic/memory sequence0x8f8.
        stq = merge<8>(stq, _mm_mul_ps(stq, _mm_set1_ps(s.i)));
        // Original arithmetic/memory sequence0x918.
        stq = merge<8>(stq, _mm_min_ps(stq, _mm_set1_ps(s.i)));
        distance = merge<4>(distance, _mm_set1_ps(s.p));
        // Original arithmetic/memory sequence0x930.
        lightX = merge<2>(lightX, _mm_mul_ps(lightX, _mm_set1_ps(s.q)));
        // Original arithmetic/memory sequence0x938.
        lightX = merge<4>(lightX, _mm_mul_ps(lightX, distance));
        // Original arithmetic/memory sequence0x940.
        lightY = merge<4>(lightY, _mm_mul_ps(lightY, distance));
        // Original arithmetic/memory sequence0x948.
        lightZ = merge<4>(lightZ, _mm_mul_ps(lightZ, distance));
        // Original arithmetic/memory sequence0x950.
        distance = merge<4>(distance, _mm_mul_ps(column14, distance));
        // Original arithmetic/memory sequence0x958.
        lightY = merge<2>(lightY, _mm_mul_ps(lightY, _mm_set1_ps(s.q)));
        // Original arithmetic/memory sequence0x960.
        lightZ = merge<2>(lightZ, _mm_mul_ps(lightZ, _mm_set1_ps(s.q)));
        // Original arithmetic/memory sequence0x968.
        distance = merge<2>(distance, _mm_mul_ps(column14, _mm_set1_ps(s.q)));
        // Original arithmetic/memory sequence0x970.
        stq = merge<8>(stq, _mm_max_ps(stq, spread<0>(column0)));
        // Original arithmetic/memory sequence0x988.
        distance = merge<6>(distance, _mm_min_ps(distance, spread<3>(column0)));
        // Original arithmetic/memory sequence0x990.
        {
            const __m128 before = stq;
            if (!toInteger<8, 4>(stq)) {
                reo_native_refusal::quantization(refusal, 0x990, 8, 4, before, s.q, s.p, vertex,
                                                 vertices, remaining, lightX, lightY, lightZ,
                                                 distance, color, stq, screen, position, normal, uv,
                                                 accumulator);
                return false;
            }
        }
        // Original arithmetic/memory sequence0x9a8.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightX, spread<0>(position)));
        // Original arithmetic/memory sequence0x9b0.
        accumulator = merge<15>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(lightY, spread<1>(position))));
        vi[14] = int16_t(bits(lane<0>(stq)));
        // Original arithmetic/memory sequence0x9b8.
        lightX =
            merge<15>(lightX, _mm_add_ps(accumulator, _mm_mul_ps(lightZ, spread<2>(position))));
        // Original arithmetic/memory sequence0x9d8.
        lightX = merge<14>(lightX, _mm_max_ps(lightX, spread<0>(column0)));
        // Original arithmetic/memory sequence0x9f8.
        lightX = merge<6>(lightX, _mm_mul_ps(lightX, distance));
        // Original arithmetic/memory sequence0xa18.
        accumulator = merge<14>(accumulator, _mm_mul_ps(column15, spread<0>(lightX)));
        // Original arithmetic/memory sequence0xa20.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column16, spread<1>(lightX))));
        // Original arithmetic/memory sequence0xa28.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column17, spread<2>(lightX))));
        lightZ = merge<15>(lightZ, load(vi[10] + (0)));
        // Original arithmetic/memory sequence0xa30.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column18, spread<3>(column0))));
        stq = merge<15>(stq, load(vi[0] + (13)));
        // Original arithmetic/memory sequence0xa38.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column19, spread<1>(distance))));
        color = merge<15>(color, load(vi[0] + (12)));
        // Original arithmetic/memory sequence0xa40.
        accumulator = merge<14>(accumulator,
                                _mm_add_ps(accumulator, _mm_mul_ps(column20, spread<2>(distance))));
        distance = merge<15>(distance, load(vi[0] + (11)));
        // Original arithmetic/memory sequence0xa48.
        position =
            merge<14>(position, _mm_add_ps(accumulator, _mm_mul_ps(column21, spread<3>(column0))));
        s.i = literal(0x43000000u);
        // Original arithmetic/memory sequence0xa50.
        vi[4] = int16_t(vi[4] + 3);
        // Original arithmetic/memory sequence0xa58.
        vi[7] = int16_t(vi[7] + (-1));
        // Original arithmetic/memory sequence0xa60.
        accumulator = merge<12>(accumulator, _mm_mul_ps(distance, spread<0>(normal)));
        distance = merge<15>(distance, load(vi[11] + (0)));
        // Original arithmetic/memory sequence0xa68.
        position = merge<15>(position, _mm_min_ps(position, _mm_set1_ps(s.i)));
        // Original arithmetic/memory sequence0xa70.
        accumulator =
            merge<12>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(color, spread<1>(normal))));
        color = merge<15>(color, load(vi[12] + (0)));
        // Original arithmetic/memory sequence0xa78.
        normal = merge<12>(normal, _mm_add_ps(accumulator, _mm_mul_ps(stq, spread<3>(column0))));
        stq = merge<15>(stq, load(vi[13] + (0)));
        // Original arithmetic/memory sequence0xa80.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightZ, spread<0>(uv)));
        lightZ = merge<15>(lightZ, load(vi[10] + (1)));
        // Original arithmetic/memory sequence0xa88.
        position = merge<15>(position, _mm_mul_ps(position, column9));
        // Original arithmetic/memory sequence0xa90.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<1>(uv))));
        distance = merge<15>(distance, load(vi[11] + (1)));
        // Original arithmetic/memory sequence0xa98.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(color, spread<2>(uv))));
        color = merge<15>(color, load(vi[12] + (1)));
        // Original arithmetic/memory sequence0xaa0.
        lightX = merge<15>(lightX, _mm_add_ps(accumulator, _mm_mul_ps(stq, spread<3>(uv))));
        stq = merge<15>(stq, load(vi[13] + (1)));
        // Original arithmetic/memory sequence0xaa8.
        {
            const __m128 before = position;
            if (!toInteger<14, 0>(position)) {
                reo_native_refusal::quantization(refusal, 0xaa8, 14, 0, before, s.q, s.p, vertex,
                                                 vertices, remaining, lightX, lightY, lightZ,
                                                 distance, color, stq, screen, position, normal, uv,
                                                 accumulator);
                return false;
            }
        }
        // Original arithmetic/memory sequence0xab0.
        accumulator = merge<15>(accumulator, _mm_mul_ps(lightZ, spread<0>(uv)));
        lightZ = merge<15>(lightZ, load(vi[10] + (2)));
        // Original arithmetic/memory sequence0xab8.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(distance, spread<1>(uv))));
        distance = merge<15>(distance, load(vi[11] + (2)));
        // Original arithmetic/memory sequence0xac0.
        accumulator =
            merge<15>(accumulator, _mm_add_ps(accumulator, _mm_mul_ps(color, spread<2>(uv))));
        color = merge<15>(color, load(vi[12] + (2)));
        // Original arithmetic/memory sequence0xac8.
        istore(vi[4] + (-2), 3, vi[15]);
        // Original arithmetic/memory sequence0xad0.
        const bool clipBranch = (int16_t(vi[0]) == int16_t(vi[1]));
        // Original arithmetic/memory sequence0xad8.
        store(vi[4] + (-2), position, std::integral_constant<unsigned, 14>{});
        if (!clipBranch) {
            // Original arithmetic/memory sequence0xae0.
            vi[9] = int16_t(vi[0] + 32767);
            // Original arithmetic/memory sequence0xae8.
            vi[9] = int16_t(vi[9] + 1);
        }
        // Original arithmetic/memory sequence0xaf0.
        vi[9] = int16_t(vi[9] + vi[14]);
        // Original arithmetic/memory sequence0xb00.
        istore(vi[4] + (-1), 3, vi[9]);
        pairs += clipBranch ? 115u : 117u;
    }
    if (vi[7] != 0) {
        reo_native_refusal::stage(refusal, reo_native_refusal::Reason::LoopCounter, original.pc,
                                  vertices, vertices, remaining);
        return false;
    }
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
    s.pc = 0xb08;
    pending = false;
    target = 0xb00;
    std::memcpy(&original, &s, sizeof(s));
    std::memcpy(originalData, memory.data(), memory.size());
    output = Result{vertices, pairs};
    return true;
}
} // namespace reo_native_multibone
#if defined(_MSC_VER)
#pragma float_control(pop)
#endif
