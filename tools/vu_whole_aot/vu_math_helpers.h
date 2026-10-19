#pragma once
// Generic arithmetic/bit-copy helpers; no game code bytes or captured identities.
#include "runtime/ps2_vu1.h"
#include "runtime/ps2_memory.h"
#include "runtime/ps2_gs_gpu.h"
#include <cmath>
#include <cstring>
#include <cstdint>
#include <limits>
#include <stdexcept>
#if defined(_M_X64) || defined(_M_IX86) || defined(__SSE2__)
#include <emmintrin.h>
#define REO_VU_PACKED_SSE2 1
#endif
namespace {
#if defined(_MSC_VER)
#define VU_BLOCK_INLINE __forceinline
#define VU_BLOCK_NOINLINE __declspec(noinline)
#else
#define VU_BLOCK_INLINE inline __attribute__((always_inline))
#define VU_BLOCK_NOINLINE __attribute__((noinline))
#endif
VU_BLOCK_INLINE void vuBlockDest(float* dst, const float* result, uint8_t dest) {
    if (dest & 0x8)
        dst[0] = result[0]; // x
    if (dest & 0x4)
        dst[1] = result[1]; // y
    if (dest & 0x2)
        dst[2] = result[2]; // z
    if (dest & 0x1)
        dst[3] = result[3]; // w
}
VU_BLOCK_INLINE float vuBlockBroadcast(const float* vf, uint8_t bc) {
    return vf[bc & 3];
}
#if defined(REO_VU_PACKED_SSE2)

template <unsigned dest> VU_BLOCK_INLINE void vuBlockPackedStore(float* target, __m128 result) {
    if constexpr (dest == 15u)
        _mm_storeu_ps(target, result);
    else if constexpr (dest) {
        const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(dest & 1 ? -1 : 0, dest & 2 ? -1 : 0,
                                                           dest & 4 ? -1 : 0, dest & 8 ? -1 : 0));
        const __m128 previous = _mm_loadu_ps(target);
        _mm_storeu_ps(target, _mm_or_ps(_mm_and_ps(mask, result), _mm_andnot_ps(mask, previous)));
    }
}
template <unsigned dest, bool add>
VU_BLOCK_INLINE void vuBlockGuardedBroadcast(float* target, const float* source, float scalar,
                                             const float* acc) {
    const __m128 product = _mm_mul_ps(_mm_set1_ps(scalar), _mm_loadu_ps(source));
    if constexpr (add)
        vuBlockPackedStore<dest>(target, _mm_add_ps(product, _mm_loadu_ps(acc)));
    else
        vuBlockPackedStore<dest>(target, product);
}
#endif
template <uint32_t instr> VU_BLOCK_INLINE void vuBlockUpper(VU1State& m_state) {
#if defined(REO_VU_PACKED_SSE2)
    constexpr unsigned packedOp = instr & 63u, packedRow = (instr >> 6) & 31u,
                       packedColumn = instr & 3u;
    constexpr unsigned packedDest = (instr >> 21) & 15u, packedFs = (instr >> 11) & 31u,
                       packedFt = (instr >> 16) & 31u, packedFd = (instr >> 6) & 31u;
    if constexpr (packedOp <= 0x2Du ||
                  (packedOp >= 0x3Cu &&
                   (packedRow <= 3u || packedRow == 6u || (packedRow == 7u && packedColumn < 3u) ||
                    packedRow == 8u || packedRow == 9u || (packedRow == 10u && packedColumn < 3u) ||
                    (packedRow == 11u && packedColumn < 2u)))) {
        const __m128 source = _mm_loadu_ps(m_state.vf[packedFs]);
        const __m128 accumulator = _mm_loadu_ps(m_state.acc);
        __m128 other, result;
        float* target = m_state.vf[packedFd];
        if constexpr (packedOp < 0x1Cu) {
            other = _mm_set1_ps(m_state.vf[packedFt][packedOp & 3u]);
            if constexpr (packedOp < 4u)
                result = _mm_add_ps(source, other);
            else if constexpr (packedOp < 8u)
                result = _mm_sub_ps(source, other);
            else if constexpr (packedOp < 12u)
                result = _mm_add_ps(accumulator, _mm_mul_ps(source, other));
            else if constexpr (packedOp < 16u)
                result = _mm_sub_ps(accumulator, _mm_mul_ps(source, other));
            else if constexpr (packedOp < 20u)
                result = _mm_max_ps(source, other);
            else if constexpr (packedOp < 24u)
                result = _mm_min_ps(source, other);
            else
                result = _mm_mul_ps(source, other);
        } else if constexpr (packedOp <= 0x27u) {
            constexpr bool useQ = packedOp == 0x1Cu || packedOp == 0x20u || packedOp == 0x21u ||
                                  packedOp == 0x24u || packedOp == 0x25u;
            other = _mm_set1_ps(useQ ? m_state.q : m_state.i);
            if constexpr (packedOp == 0x1Cu || packedOp == 0x1Eu)
                result = _mm_mul_ps(source, other);
            else if constexpr (packedOp == 0x1Du)
                result = _mm_max_ps(source, other);
            else if constexpr (packedOp == 0x1Fu)
                result = _mm_min_ps(source, other);
            else if constexpr (packedOp == 0x20u || packedOp == 0x22u)
                result = _mm_add_ps(source, other);
            else if constexpr (packedOp == 0x21u || packedOp == 0x23u)
                result = _mm_add_ps(accumulator, _mm_mul_ps(source, other));
            else if constexpr (packedOp == 0x24u || packedOp == 0x26u)
                result = _mm_sub_ps(source, other);
            else
                result = _mm_sub_ps(accumulator, _mm_mul_ps(source, other));
        } else if constexpr (packedOp <= 0x2Du) {
            other = _mm_loadu_ps(m_state.vf[packedFt]);
            if constexpr (packedOp == 0x28u)
                result = _mm_add_ps(source, other);
            else if constexpr (packedOp == 0x29u)
                result = _mm_add_ps(accumulator, _mm_mul_ps(source, other));
            else if constexpr (packedOp == 0x2Au)
                result = _mm_mul_ps(source, other);
            else if constexpr (packedOp == 0x2Bu)
                result = _mm_max_ps(source, other);
            else if constexpr (packedOp == 0x2Cu)
                result = _mm_sub_ps(source, other);
            else
                result = _mm_sub_ps(accumulator, _mm_mul_ps(source, other));
        } else {
            target = m_state.acc;
            if constexpr (packedRow <= 3u || packedRow == 6u) {
                other = _mm_set1_ps(m_state.vf[packedFt][packedColumn]);
                if constexpr (packedRow == 0u)
                    result = _mm_add_ps(source, other);
                else if constexpr (packedRow == 1u)
                    result = _mm_sub_ps(source, other);
                else if constexpr (packedRow == 2u)
                    result = _mm_add_ps(accumulator, _mm_mul_ps(source, other));
                else if constexpr (packedRow == 3u)
                    result = _mm_sub_ps(accumulator, _mm_mul_ps(source, other));
                else
                    result = _mm_mul_ps(source, other);
            } else if constexpr (packedRow == 7u) {
                if constexpr (packedColumn == 1u) {
                    result = _mm_and_ps(source, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
                    target = m_state.vf[packedFt];
                } else
                    result =
                        _mm_mul_ps(source, _mm_set1_ps(packedColumn == 0u ? m_state.q : m_state.i));
            } else if constexpr (packedRow == 8u || packedRow == 9u) {
                other = _mm_set1_ps(packedColumn < 2u ? m_state.q : m_state.i);
                if constexpr (packedColumn & 1u) {
                    const __m128 signedSource =
                        _mm_mul_ps(_mm_set1_ps(packedRow == 8u ? 1.0f : -1.0f), source);
                    result = _mm_add_ps(accumulator, _mm_mul_ps(signedSource, other));
                } else
                    result = _mm_add_ps(
                        source, packedRow == 8u ? other
                                                : _mm_xor_ps(other, _mm_castsi128_ps(_mm_set1_epi32(
                                                                        int(0x80000000u)))));
            } else {
                other = _mm_loadu_ps(m_state.vf[packedFt]);
                if constexpr (packedRow == 10u) {
                    if constexpr (packedColumn == 0u)
                        result = _mm_add_ps(source, other);
                    else if constexpr (packedColumn == 1u)
                        result = _mm_add_ps(accumulator, _mm_mul_ps(source, other));
                    else
                        result = _mm_mul_ps(source, other);
                } else {
                    if constexpr (packedColumn == 0u)
                        result = _mm_sub_ps(source, other);
                    else
                        result = _mm_sub_ps(accumulator, _mm_mul_ps(source, other));
                }
            }
        }
        vuBlockPackedStore<packedDest>(target, result);
        return;
    }
#endif

    constexpr uint8_t dest = ((uint8_t)((instr >> 21) & 0xF));
    constexpr uint8_t ft = ((uint8_t)((instr >> 16) & 0x1F));
    constexpr uint8_t fs = ((uint8_t)((instr >> 11) & 0x1F));
    constexpr uint8_t fd = ((uint8_t)((instr >> 6) & 0x1F));
    constexpr uint8_t op = instr & 0x3F;

    float* vd = m_state.vf[fd];
    const float* vs = m_state.vf[fs];
    const float* vt = m_state.vf[ft];
    float result[4];

#if defined(REO_VU_PACKED_SSE2)
    if constexpr (op >= 0x08u && op <= 0x0Bu) {
        vuBlockGuardedBroadcast<dest, true>(vd, vs, vt[op & 3u], m_state.acc);
        return;
    } else if constexpr (op >= 0x3Cu) {
        constexpr unsigned row = (instr >> 6) & 31u;
        if constexpr (row == 2u || row == 6u) {
            vuBlockGuardedBroadcast<dest, row == 2u>(m_state.acc, vs, vt[op & 3u], m_state.acc);
            return;
        }
    }
#endif

    // Upper opcode decoding (bits 5:0 of upper word)
    switch (op) {
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x03: // ADDbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] + bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x04:
        case 0x05:
        case 0x06:
        case 0x07: // SUBbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] - bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x08:
        case 0x09:
        case 0x0A:
        case 0x0B: // MADDbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] + vs[c] * bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x0F: // MSUBbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] - vs[c] * bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13: // MAXbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = (vs[c] > bc) ? vs[c] : bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17: // MINIbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = (vs[c] < bc) ? vs[c] : bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B: // MULbc
        {
            float bc = vuBlockBroadcast(vt, op & 3);
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] * bc;
            vuBlockDest(vd, result, dest);
            return;
        }
        case 0x1C: // MULq
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] * m_state.q;
            vuBlockDest(vd, result, dest);
            return;
        case 0x1D: // MAXi
            for (int c = 0; c < 4; c++)
                result[c] = (vs[c] > m_state.i) ? vs[c] : m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x1E: // MULi
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] * m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x1F: // MINIi
            for (int c = 0; c < 4; c++)
                result[c] = (vs[c] < m_state.i) ? vs[c] : m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x20: // ADDq
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] + m_state.q;
            vuBlockDest(vd, result, dest);
            return;
        case 0x21: // MADDq
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] + vs[c] * m_state.q;
            vuBlockDest(vd, result, dest);
            return;
        case 0x22: // ADDi
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] + m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x23: // MADDi
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] + vs[c] * m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x24: // SUBq
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] - m_state.q;
            vuBlockDest(vd, result, dest);
            return;
        case 0x25: // MSUBq
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] - vs[c] * m_state.q;
            vuBlockDest(vd, result, dest);
            return;
        case 0x26: // SUBi
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] - m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x27: // MSUBi
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] - vs[c] * m_state.i;
            vuBlockDest(vd, result, dest);
            return;
        case 0x28: // ADD
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] + vt[c];
            vuBlockDest(vd, result, dest);
            return;
        case 0x29: // MADD
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] + vs[c] * vt[c];
            vuBlockDest(vd, result, dest);
            return;
        case 0x2A: // MUL
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] * vt[c];
            vuBlockDest(vd, result, dest);
            return;
        case 0x2B: // MAX
            for (int c = 0; c < 4; c++)
                result[c] = (vs[c] > vt[c]) ? vs[c] : vt[c];
            vuBlockDest(vd, result, dest);
            return;
        case 0x2C: // SUB
            for (int c = 0; c < 4; c++)
                result[c] = vs[c] - vt[c];
            vuBlockDest(vd, result, dest);
            return;
        case 0x2D: // MSUB
            for (int c = 0; c < 4; c++)
                result[c] = m_state.acc[c] - vs[c] * vt[c];
            vuBlockDest(vd, result, dest);
            return;
        case 0x2E: // OPMSUB
            result[0] = m_state.acc[0] - vs[1] * vt[2];
            result[1] = m_state.acc[1] - vs[2] * vt[0];
            result[2] = m_state.acc[2] - vs[0] * vt[1];
            result[3] = 0.0f;
            vuBlockDest(vd, result, dest);
            return;
        case 0x2F: // MINI
            for (int c = 0; c < 4; c++)
                result[c] = (vs[c] < vt[c]) ? vs[c] : vt[c];
            vuBlockDest(vd, result, dest);
            return;

        // Secondary table row is bits10:6, column is the low two opcode bits.
        case 0x3C:
        case 0x3D:
        case 0x3E:
        case 0x3F: {
            constexpr unsigned row = (instr >> 6) & 31, column = instr & 3;
            if (row <= 3 || row == 6) {
                const float scalar = vt[column];
                for (unsigned c = 0; c < 4; ++c)
                    result[c] = row == 0   ? vs[c] + scalar
                                : row == 1 ? vs[c] - scalar
                                : row == 2 ? m_state.acc[c] + vs[c] * scalar
                                : row == 3 ? m_state.acc[c] - vs[c] * scalar
                                           : vs[c] * scalar;
                vuBlockDest(m_state.acc, result, dest);
                return;
            }
            if (row == 4 || row == 5) {
                static constexpr unsigned shifts[4] = {0, 4, 12, 15};
                const float scale = float(uint32_t(1) << shifts[column]);
                for (unsigned c = 0; c < 4; ++c) {
                    if (row == 4) {
                        int32_t value;
                        std::memcpy(&value, &vs[c], 4);
                        result[c] = float(value) / scale;
                    } else {
                        const double scaled = double(vs[c]) * scale;
                        const int32_t value = scaled >= 2147483648.0   ? INT32_MAX
                                              : scaled < -2147483648.0 ? INT32_MIN
                                                                       : int32_t(scaled);
                        std::memcpy(&result[c], &value, 4);
                    }
                }
                vuBlockDest(m_state.vf[ft], result, dest);
                return;
            }
            if (row == 7) {
                if (column == 3) {
                    const float limit = std::fabs(vt[3]);
                    uint32_t flags = 0;
                    for (unsigned c = 0; c < 3; ++c) {
                        if (vs[c] > limit)
                            flags |= 1u << (c * 2);
                        if (vs[c] < -limit)
                            flags |= 2u << (c * 2);
                    }
                    m_state.clip = ((m_state.clip << 6) | flags) & 0xFFFFFFu;
                    return;
                }
                if (column == 1) {
                    for (unsigned c = 0; c < 4; ++c)
                        result[c] = std::fabs(vs[c]);
                    vuBlockDest(m_state.vf[ft], result, dest);
                    return;
                }
                const float scalar = column == 0 ? m_state.q : m_state.i;
                for (unsigned c = 0; c < 4; ++c)
                    result[c] = vs[c] * scalar;
                vuBlockDest(m_state.acc, result, dest);
                return;
            }
            if (row == 8 || row == 9) {
                const float scalar = column < 2 ? m_state.q : m_state.i;
                for (unsigned c = 0; c < 4; ++c)
                    result[c] = (column & 1)
                                    ? m_state.acc[c] + (row == 8 ? 1.0f : -1.0f) * vs[c] * scalar
                                    : vs[c] + (row == 8 ? scalar : -scalar);
                vuBlockDest(m_state.acc, result, dest);
                return;
            }
            if (row == 10 && column < 3) {
                for (unsigned c = 0; c < 4; ++c)
                    result[c] = column == 0   ? vs[c] + vt[c]
                                : column == 1 ? m_state.acc[c] + vs[c] * vt[c]
                                              : vs[c] * vt[c];
                vuBlockDest(m_state.acc, result, dest);
                return;
            }
            if (row == 11 && column < 3) {
                if (column == 2) {
                    result[0] = vs[1] * vt[2];
                    result[1] = vs[2] * vt[0];
                    result[2] = vs[0] * vt[1];
                    vuBlockDest(m_state.acc, result, dest & 14);
                    return;
                }
                for (unsigned c = 0; c < 4; ++c)
                    result[c] = column == 0 ? vs[c] - vt[c] : m_state.acc[c] - vs[c] * vt[c];
                vuBlockDest(m_state.acc, result, dest);
                return;
            }
            return; // row11/column3 is the actual upper NOP.
        }

        default:
            // NOP / unimplemented upper
            return;
    }
}
template <uint32_t instr>
VU_BLOCK_INLINE void vuBlockLower(VU1State& m_state, uint8_t* vuData, uint32_t dataSize, GS& gs,
                                  PS2Memory* memory) {
    static_assert(!(((instr >> 25) & 127u) == 0x40u && (instr & 2047u) == 0x6FCu),
                  "XGKICK cannot enter specialized block");

    if (!vuData || dataSize < 16u)
        return;

    constexpr uint8_t opHi = (instr >> 25) & 0x7F;

    // The lower instruction encoding uses bits 31:25 for the primary opcode
    switch (opHi) {
        case 0x00: // LQ (Load Quadword from VU data memory)
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0x1F));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr uint8_t dest = (instr >> 21) & 0xF;
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            uint32_t addr = ((uint32_t)(int32_t)(m_state.vi[is] + imm)) * 16u;
            addr &= (dataSize - 1);
            if (addr + 16 <= dataSize) {
                float tmp[4];
                std::memcpy(tmp, vuData + addr, 16);
                vuBlockDest(m_state.vf[it], tmp, dest);
            }
            return;
        }
        case 0x01: // SQ (Store Quadword to VU data memory)
        {
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0x1F));
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t dest = (instr >> 21) & 0xF;
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            uint32_t addr = ((uint32_t)(int32_t)(m_state.vi[it] + imm)) * 16u;
            addr &= (dataSize - 1);
            if (addr + 16 <= dataSize) {
                float tmp[4];
                std::memcpy(tmp, vuData + addr, 16);
                if (dest & 0x8)
                    tmp[0] = m_state.vf[is][0];
                if (dest & 0x4)
                    tmp[1] = m_state.vf[is][1];
                if (dest & 0x2)
                    tmp[2] = m_state.vf[is][2];
                if (dest & 0x1)
                    tmp[3] = m_state.vf[is][3];
                std::memcpy(vuData + addr, tmp, 16);
            }
            return;
        }
        case 0x04: // ILW (Integer Load Word from VU data memory)
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr uint8_t dest = (instr >> 21) & 0xF;
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            uint32_t addr = ((uint32_t)(int32_t)(m_state.vi[is] + imm)) * 16u;
            addr &= (dataSize - 1);
            if (addr + 16 <= dataSize) {
                int comp = 0;
                if (dest & 0x8)
                    comp = 0;
                else if (dest & 0x4)
                    comp = 1;
                else if (dest & 0x2)
                    comp = 2;
                else
                    comp = 3;
                uint32_t v;
                std::memcpy(&v, vuData + addr + comp * 4, 4);
                if (it != 0)
                    m_state.vi[it] = (int32_t)(int16_t)(v & 0xFFFF);
            }
            return;
        }
        case 0x05: // ISW (Integer Store Word to VU data memory)
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr uint8_t dest = (instr >> 21) & 0xF;
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            uint32_t addr = ((uint32_t)(int32_t)(m_state.vi[is] + imm)) * 16u;
            addr &= (dataSize - 1);
            if (addr + 16 <= dataSize) {
                uint32_t val = (uint32_t)(uint16_t)(m_state.vi[it] & 0xFFFF);
                if (dest & 0x8)
                    std::memcpy(vuData + addr + 0, &val, 4);
                if (dest & 0x4)
                    std::memcpy(vuData + addr + 4, &val, 4);
                if (dest & 0x2)
                    std::memcpy(vuData + addr + 8, &val, 4);
                if (dest & 0x1)
                    std::memcpy(vuData + addr + 12, &val, 4);
            }
            return;
        }
        case 0x08: // IADDIU
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = (int16_t)(instr & 0x7FF) | ((instr >> 10) & 0x7800);
            if (it != 0)
                m_state.vi[it] = (int16_t)(m_state.vi[is] + imm);
            return;
        }
        case 0x09: // ISUBIU
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = (int16_t)(instr & 0x7FF) | ((instr >> 10) & 0x7800);
            if (it != 0)
                m_state.vi[it] = (int16_t)(m_state.vi[is] - imm);
            return;
        }
        case 0x10: // FCEQ
        {
            uint32_t imm24 = instr & 0xFFFFFF;
            if (1 != 0)
                m_state.vi[1] = ((m_state.clip & 0xFFFFFF) == imm24) ? 1 : 0;
            return;
        }
        case 0x11: // FCSET
        {
            m_state.clip = instr & 0xFFFFFF;
            return;
        }
        case 0x12: // FCAND
        {
            uint32_t imm24 = instr & 0xFFFFFF;
            if (1 != 0)
                m_state.vi[1] = ((m_state.clip & imm24) != 0) ? 1 : 0;
            return;
        }
        case 0x13: // FCOR
        {
            uint32_t imm24 = instr & 0xFFFFFF;
            if (1 != 0)
                m_state.vi[1] = ((m_state.clip | imm24) == 0xFFFFFF) ? 1 : 0;
            return;
        }
        case 0x14: // FSEQ
        {
            constexpr uint16_t imm12 = instr & 0xFFF;
            if (1 != 0)
                m_state.vi[1] = ((m_state.status & 0xFFF) == imm12) ? 1 : 0;
            return;
        }
        case 0x15: // FSSET
        {
            m_state.status = (instr >> 6) & 0xFC0;
            return;
        }
        case 0x16: // FSAND
        {
            constexpr uint16_t imm12 = instr & 0xFFF;
            if (1 != 0)
                m_state.vi[1] = (int32_t)(m_state.status & imm12);
            return;
        }
        case 0x17: // FSOR
        {
            constexpr uint16_t imm12 = instr & 0xFFF;
            if (1 != 0)
                m_state.vi[1] = ((m_state.status | imm12) == 0xFFF) ? 1 : 0;
            return;
        }
        case 0x1A: // FMAND
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            if (it != 0)
                m_state.vi[it] = (int32_t)(m_state.mac & (uint32_t)(uint16_t)m_state.vi[is]);
            return;
        }
        case 0x18: // FMEQ
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            if (it != 0)
                m_state.vi[it] =
                    ((m_state.mac & 0xFFFF) == (uint32_t)(uint16_t)m_state.vi[is]) ? 1 : 0;
            return;
        }
        case 0x1B: // FMOR
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            if (it != 0)
                m_state.vi[it] = (int32_t)(m_state.mac | (uint32_t)(uint16_t)m_state.vi[is]);
            return;
        }
        case 0x1C: // FCGET
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            if (it)
                m_state.vi[it] = int32_t(m_state.clip & 0xFFFu);
            return;
        }
        case 0x20: // B (unconditional branch)
        {
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
            // run() executes the paired delay instruction before this target.
            m_state.pc = target | 0x80000000u;
            return;
        }
        case 0x21: // BAL (Branch and link)
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
            if (it != 0)
                m_state.vi[it] = (int32_t)((m_state.pc + 16) / 8);
            m_state.pc = target | 0x80000000u;
            return;
        }
        case 0x24: // JR
        {
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            uint32_t target = ((uint32_t)(uint16_t)m_state.vi[is] * 8u) & 0x3FFF;
            m_state.pc = target | 0x80000000u;
            return;
        }
        case 0x25: // JALR
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            uint32_t target = ((uint32_t)(uint16_t)m_state.vi[is] * 8u) & 0x3FFF;
            if (it != 0)
                m_state.vi[it] = (int32_t)((m_state.pc + 16) / 8);
            m_state.pc = target | 0x80000000u;
            return;
        }
        case 0x28: // IBEQ
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            if ((int16_t)m_state.vi[is] == (int16_t)m_state.vi[it]) {
                uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
                m_state.pc = target | 0x80000000u;
            }
            return;
        }
        case 0x29: // IBNE
        {
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            if ((int16_t)m_state.vi[is] != (int16_t)m_state.vi[it]) {
                uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
                m_state.pc = target | 0x80000000u;
            }
            return;
        }
        case 0x2C: // IBLTZ
        {
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            if ((int16_t)m_state.vi[is] < 0) {
                uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
                m_state.pc = target | 0x80000000u;
            }
            return;
        }
        case 0x2D: // IBGTZ
        {
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            if ((int16_t)m_state.vi[is] > 0) {
                uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
                m_state.pc = target | 0x80000000u;
            }
            return;
        }
        case 0x2E: // IBLEZ
        {
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            if ((int16_t)m_state.vi[is] <= 0) {
                uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
                m_state.pc = target | 0x80000000u;
            }
            return;
        }
        case 0x2F: // IBGEZ
        {
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr int16_t imm = ((int16_t)(int32_t)((int32_t)(instr << 21) >> 21));
            if ((int16_t)m_state.vi[is] >= 0) {
                uint32_t target = (m_state.pc + 8 + imm * 8) & 0x3FFF;
                m_state.pc = target | 0x80000000u;
            }
            return;
        }

        case 0x40: // Lower special (opcode in bits 5:0)
        {
            constexpr uint8_t funct = instr & 0x3F;
            constexpr uint8_t it = ((uint8_t)((instr >> 16) & 0xF));
            constexpr uint8_t is = ((uint8_t)((instr >> 11) & 0xF));
            constexpr uint8_t id = ((uint8_t)((instr >> 6) & 0xF));
            constexpr uint8_t dest = (instr >> 21) & 0xF;

            switch (funct) {
                case 0x30: // IADD
                    if (id != 0)
                        m_state.vi[id] = (int16_t)(m_state.vi[is] + m_state.vi[it]);
                    return;
                case 0x31: // ISUB
                    if (id != 0)
                        m_state.vi[id] = (int16_t)(m_state.vi[is] - m_state.vi[it]);
                    return;
                case 0x32: // IADDI
                {
                    constexpr int16_t imm5 = int16_t(int32_t(instr << 21) >> 27);
                    if (it != 0)
                        m_state.vi[it] = (int16_t)(m_state.vi[is] + imm5);
                    return;
                }
                case 0x34: // IAND
                    if (id != 0)
                        m_state.vi[id] = m_state.vi[is] & m_state.vi[it];
                    return;
                case 0x35: // IOR
                    if (id != 0)
                        m_state.vi[id] = m_state.vi[is] | m_state.vi[it];
                    return;

                case 0x3C:
                case 0x3D:
                case 0x3E:
                case 0x3F: {
                    constexpr uint8_t vft = ((uint8_t)((instr >> 16) & 0x1F)),
                                      vfs = ((uint8_t)((instr >> 11) & 0x1F));
                    constexpr uint16_t selector = instr & 0x7FF;
                    switch (selector) {
                        case 0x33C: // MOVE
                        case 0x33D: // MR32
                        {
                            float tmp[4];
                            for (unsigned c = 0; c < 4; ++c)
                                tmp[c] = m_state.vf[vfs][(c + (selector == 0x33D)) & 3];
                            vuBlockDest(m_state.vf[vft], tmp, dest);
                            return;
                        }
                        case 0x3FD: // MFIR
                        {
                            const int32_t value = int16_t(m_state.vi[is]);
                            float scalar;
                            std::memcpy(&scalar, &value, 4);
                            float tmp[4] = {scalar, scalar, scalar, scalar};
                            vuBlockDest(m_state.vf[vft], tmp, dest);
                            return;
                        }
                        case 0x3FC: // MTIR
                        {
                            uint32_t value;
                            std::memcpy(&value, &m_state.vf[vfs][(instr >> 21) & 3], 4);
                            if (it)
                                m_state.vi[it] = int16_t(value);
                            return;
                        }
                        case 0x37C:
                        case 0x37E: // LQI / LQD
                        {
                            if (selector == 0x37E && is)
                                m_state.vi[is] = int16_t(m_state.vi[is] - 1);
                            const uint32_t addr =
                                (uint32_t(uint16_t(m_state.vi[is])) * 16u) & (dataSize - 1);
                            float tmp[4];
                            std::memcpy(tmp, vuData + addr, 16);
                            vuBlockDest(m_state.vf[vft], tmp, dest);
                            if (selector == 0x37C && is)
                                m_state.vi[is] = int16_t(m_state.vi[is] + 1);
                            return;
                        }
                        case 0x37D:
                        case 0x37F: // SQI / SQD
                        {
                            if (selector == 0x37F && it)
                                m_state.vi[it] = int16_t(m_state.vi[it] - 1);
                            const uint32_t addr =
                                (uint32_t(uint16_t(m_state.vi[it])) * 16u) & (dataSize - 1);
                            for (unsigned c = 0; c < 4; ++c)
                                if (dest & (8u >> c))
                                    std::memcpy(vuData + addr + c * 4, &m_state.vf[vfs][c], 4);
                            if (selector == 0x37D && it)
                                m_state.vi[it] = int16_t(m_state.vi[it] + 1);
                            return;
                        }
                        case 0x3FE:
                        case 0x3FF: // ILWR / ISWR
                        {
                            const uint32_t addr =
                                (uint32_t(uint16_t(m_state.vi[is])) * 16u) & (dataSize - 1);
                            for (unsigned c = 0; c < 4; ++c)
                                if (dest & (8u >> c)) {
                                    if (selector == 0x3FE) {
                                        uint16_t value;
                                        std::memcpy(&value, vuData + addr + c * 4, 2);
                                        if (it)
                                            m_state.vi[it] = int16_t(value);
                                    } else {
                                        const uint32_t value = uint16_t(m_state.vi[it]);
                                        std::memcpy(vuData + addr + c * 4, &value, 4);
                                    }
                                }
                            return;
                        }
                        case 0x3BC:
                        case 0x3BD:
                        case 0x3BE: // DIV / SQRT / RSQRT
                        {
                            const float numerator = m_state.vf[vfs][(instr >> 21) & 3];
                            const float value = m_state.vf[vft][(instr >> 23) & 3];
                            if (selector == 0x3BD)
                                m_state.q = std::sqrt(std::fabs(value));
                            else {
                                const float denominator =
                                    selector == 0x3BE ? std::sqrt(std::fabs(value)) : value;
                                m_state.q = denominator != 0
                                                ? numerator / denominator
                                                : std::copysign(
                                                      std::numeric_limits<float>::max(),
                                                      numerator * std::copysign(1.0f, denominator));
                            }
                            return;
                        }
                        case 0x3BF:
                        case 0x7BF:
                            return; // WAITQ / WAITP; arithmetic is synchronous.
                        case 0x67C: // MFP
                        {
                            float tmp[4] = {m_state.p, m_state.p, m_state.p, m_state.p};
                            vuBlockDest(m_state.vf[vft], tmp, dest);
                            return;
                        }
                        case 0x6BC: // XTOP
                            if (it)
                                m_state.vi[it] = int16_t(memory ? memory->vif1_regs.top : 0);
                            return;
                        case 0x6BD: // XITOP
                            if (it)
                                m_state.vi[it] = int16_t(m_state.itop);
                            return;
                        case 0x73C:
                        case 0x73D:
                        case 0x73E:
                        case 0x73F: // ESADD/ERSADD/ELENG/ERLENG
                        {
                            const float* v = m_state.vf[vfs];
                            const float square = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
                            const float value = (selector & 2) ? std::sqrt(square) : square;
                            m_state.p = (selector & 1)
                                            ? (value != 0 ? 1.0f / value
                                                          : std::numeric_limits<float>::max())
                                            : value;
                            return;
                        }
                        case 0x77E: // ESUM
                        {
                            const float* v = m_state.vf[vfs];
                            m_state.p = v[0] + v[1] + v[2] + v[3];
                            return;
                        }
                        case 0x7BD: // ERSQRT
                        {
                            // VU EFU leaves negative inputs unchanged and preserves zero.
                            float value = m_state.vf[vfs][(instr >> 21) & 3];
                            if (value >= 0) {
                                value = std::sqrt(value);
                                if (value != 0)
                                    value = 1.0f / value;
                            }
                            m_state.p = value;
                            return;
                        }
                        case 0x7BC:
                        case 0x7BE: // ESQRT / ERCPR
                        {
                            const float value = m_state.vf[vfs][(instr >> 21) & 3];
                            m_state.p = selector == 0x7BC
                                            ? std::sqrt(std::fabs(value))
                                            : (value != 0 ? 1.0f / value
                                                          : std::numeric_limits<float>::max());
                            return;
                        }
                        case 0x6FC:
                            return; // Registration rejects every XGKICK pair.

                        default:
                            return; // Remaining random/transcendental instructions are not implemented.
                    }
                }
                default:
                    return;
            }
        }
        default:
            break;
    }
}
template <uint32_t lo, uint32_t hi, uint32_t pc>
VU_BLOCK_INLINE void vuBlockPair(VU1State& s, uint8_t* data, uint32_t size, GS& gs,
                                 PS2Memory* memory, bool& pending, uint32_t& target) {
    // Exactly the live interpreter pair order and invariant writes.
    if constexpr ((hi & 0x7FFu) != 0x2FFu)
        vuBlockUpper<hi>(s);
    if constexpr (hi & 0x80000000u) {
        constexpr uint32_t bits = lo;
        std::memcpy(&s.i, &bits, 4);
    } else if constexpr (lo != 0x8000033Cu)
        vuBlockLower<lo>(s, data, size, gs, memory);
    const bool newBranch = (s.pc & 0x80000000u) != 0;
    const uint32_t newTarget = s.pc & 0x3FFFu;
    s.vf[0][0] = 0;
    s.vf[0][1] = 0;
    s.vf[0][2] = 0;
    s.vf[0][3] = 1;
    s.vi[0] = 0;
    s.pc = pending ? target : pc + 8;
    if (s.pc >= 16384u)
        s.pc = 0;
    pending = newBranch;
    target = newTarget;
    // Generator proves no E pair and requires !ebit on entry.
}
bool vuBlockDisjoint(const uint8_t* a, size_t an, const uint8_t* b, size_t bn) {
    const uintptr_t x = reinterpret_cast<uintptr_t>(a), y = reinterpret_cast<uintptr_t>(b);
    if (!a || !b || x > UINTPTR_MAX - an || y > UINTPTR_MAX - bn)
        return false;
    return x + an <= y || y + bn <= x;
}
// Only arithmetic operands capable of affecting a written lane are admitted.
// The 2^59 magnitude bound makes every upper float product/sum finite; integer
// bit copies (ITOF/LQ/SQ/MFIR/MFP) are not numeric floating-point operations.
VU_BLOCK_INLINE bool vuBlockNumber(float value) {
    uint32_t bits;
    std::memcpy(&bits, &value, 4);
    return (bits & 0x7FFFFFFFu) <= 0x5D000000u;
}
VU_BLOCK_INLINE bool vuBlockLanes(const float* values, unsigned mask) {
    for (unsigned c = 0; c < 4; ++c)
        if ((mask & (8u >> c)) && !vuBlockNumber(values[c]))
            return false;
    return true;
}
template <uint32_t hi> VU_BLOCK_INLINE bool vuBlockUpperSafe(const VU1State& s) {
    constexpr unsigned op = hi & 63u, fs = (hi >> 11) & 31u, ft = (hi >> 16) & 31u,
                       dest = (hi >> 21) & 15u;
    const float* a = s.vf[fs];
    const float* b = s.vf[ft];
    if constexpr (op < 0x1Cu)
        return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(b[op & 3u]) &&
                         ((op >= 8u && op < 16u) ? vuBlockLanes(s.acc, dest) : true));
    else if constexpr (op >= 0x1Cu && op <= 0x27u) {
        constexpr bool useQ =
            op == 0x1Cu || op == 0x20u || op == 0x21u || op == 0x24u || op == 0x25u;
        constexpr bool acc = op == 0x21u || op == 0x23u || op == 0x25u || op == 0x27u;
        return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(useQ ? s.q : s.i) &&
                         (!acc || vuBlockLanes(s.acc, dest)));
    } else if constexpr (op == 0x2Eu) {
        for (unsigned c = 0; c < 3; ++c)
            if (dest & (8u >> c))
                if (!vuBlockNumber(s.acc[c]) || !vuBlockNumber(a[(c + 1) % 3]) ||
                    !vuBlockNumber(b[(c + 2) % 3]))
                    return false;
        return true;
    } else if constexpr (op >= 0x28u && op <= 0x2Fu)
        return !dest || (vuBlockLanes(a, dest) && vuBlockLanes(b, dest) &&
                         ((op == 0x29u || op == 0x2Du) ? vuBlockLanes(s.acc, dest) : true));
    else if constexpr (op >= 0x3Cu) {
        constexpr unsigned row = (hi >> 6) & 31u, column = hi & 3u;
        if constexpr (row <= 3u || row == 6u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(b[column]) &&
                             ((row == 2u || row == 3u) ? vuBlockLanes(s.acc, dest) : true));
        else if constexpr (row == 4u)
            return true; // ITOF interprets source bits as int32.
        else if constexpr (row == 5u)
            return vuBlockLanes(a, dest);
        else if constexpr (row == 7u && column == 3u)
            return vuBlockLanes(a, 14u) && vuBlockNumber(b[3]);
        else if constexpr (row == 7u && column == 1u)
            return vuBlockLanes(a, dest);
        else if constexpr (row == 7u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(column == 0u ? s.q : s.i));
        else if constexpr (row == 8u || row == 9u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockNumber(column < 2u ? s.q : s.i) &&
                             ((column & 1u) ? vuBlockLanes(s.acc, dest) : true));
        else if constexpr (row == 11u && column == 2u) {
            for (unsigned c = 0; c < 3; ++c)
                if (dest & (8u >> c))
                    if (!vuBlockNumber(a[(c + 1) % 3]) || !vuBlockNumber(b[(c + 2) % 3]))
                        return false;
            return true;
        } else if constexpr ((row == 10u || row == 11u) && column < 3u)
            return !dest || (vuBlockLanes(a, dest) && vuBlockLanes(b, dest) &&
                             (column == 1u ? vuBlockLanes(s.acc, dest) : true));
    }
    return true; // Original unimplemented/NOP upper performs no state writes.
}
template <uint32_t hi> constexpr bool vuBlockUpperWrites(unsigned reg, unsigned component) {
    constexpr unsigned op = hi & 63u, dest = (hi >> 21) & 15u;
    if (!(dest & (8u >> component)))
        return false;
    if constexpr (op <= 0x2Fu)
        return reg == ((hi >> 6) & 31u);
    else if constexpr (op >= 0x3Cu) {
        constexpr unsigned row = (hi >> 6) & 31u, column = hi & 3u;
        if constexpr (row == 4u || row == 5u || (row == 7u && column == 1u))
            return reg == ((hi >> 16) & 31u);
    }
    return false; // ACC/CLIP writes cannot change a lower VF operand.
}
template <uint32_t lo, uint32_t hi> VU_BLOCK_INLINE bool vuBlockLowerSafe(const VU1State& s) {
    if constexpr (hi & 0x80000000u)
        return true; // Lower literal, not arithmetic.
    if constexpr (((lo >> 25) & 127u) != 0x40u)
        return true;
    constexpr unsigned selector = lo & 2047u, fs = (lo >> 11) & 31u, ft = (lo >> 16) & 31u;
    const auto input = [&](unsigned r, unsigned c) {
        // Never execute upper first then retry the complete pair. Any same-pair
        // upper->lower VF dependency remains wholly in the original interpreter.
        return !vuBlockUpperWrites<hi>(r, c) && vuBlockNumber(s.vf[r][c]);
    };
    if constexpr (selector == 0x3BCu || selector == 0x3BDu || selector == 0x3BEu) {
        if (!input(ft, (lo >> 23) & 3u))
            return false;
        if constexpr (selector != 0x3BDu)
            return input(fs, (lo >> 21) & 3u);
    } else if constexpr (selector == 0x7BDu || selector == 0x7BCu || selector == 0x7BEu)
        return input(fs, (lo >> 21) & 3u);
    else if constexpr (selector >= 0x73Cu && selector <= 0x73Fu)
        return input(fs, 0) && input(fs, 1) && input(fs, 2);
    else if constexpr (selector == 0x77Eu)
        return input(fs, 0) && input(fs, 1) && input(fs, 2) && input(fs, 3);
    return true; // Memory transfers and register bit copies preserve all payloads.
}
template <uint32_t lo, uint32_t hi> VU_BLOCK_INLINE bool vuBlockPairSafe(const VU1State& s) {
    return vuBlockUpperSafe<hi>(s) && vuBlockLowerSafe<lo, hi>(s);
}

// Fused admission and store. Refusal leaves all guest state untouched.
// Only MULq changes admission; every other arithmetic guard remains unchanged.
template <uint32_t hi> VU_BLOCK_INLINE bool vuWholeFiniteMulQ(VU1State& s) {
    static_assert((hi & 63u) == 0x1cu);
    constexpr unsigned dest = (hi >> 21) & 15u, fs = (hi >> 11) & 31u, fd = (hi >> 6) & 31u;
    if constexpr (!dest)
        return true;
    uint32_t qb;
    std::memcpy(&qb, &s.q, 4);
    if ((qb & 0x7fffffffu) > 0x7f7fffffu)
        return false;
    uint32_t source[4];
    std::memcpy(source, s.vf[fs], sizeof(source));
    for (unsigned c = 0; c < 4; ++c)
        if ((dest & (8u >> c)) && (source[c] & 0x7fffffffu) > 0x7f7fffffu)
            return false;
#if defined(REO_VU_PACKED_SSE2)
    // Unselected lanes cannot change guest results, nor need an FP operation.
    const __m128 mask = _mm_castsi128_ps(
        _mm_set_epi32(dest & 1 ? -1 : 0, dest & 2 ? -1 : 0, dest & 4 ? -1 : 0, dest & 8 ? -1 : 0));
    const __m128 input = _mm_and_ps(mask, _mm_loadu_ps(s.vf[fs]));
    const __m128 result = _mm_mul_ps(input, _mm_set1_ps(s.q));
    uint32_t bits[4];
    _mm_storeu_si128(reinterpret_cast<__m128i*>(bits), _mm_castps_si128(result));
    for (unsigned c = 0; c < 4; ++c)
        if ((dest & (8u >> c)) && (bits[c] & 0x7fffffffu) > 0x7f7fffffu)
            return false;
    vuBlockPackedStore<dest>(s.vf[fd], result);
    return true;
#else
    float result[4] = {};
    for (unsigned c = 0; c < 4; ++c)
        if (dest & (8u >> c)) {
            result[c] = s.vf[fs][c] * s.q;
            uint32_t bits;
            std::memcpy(&bits, &result[c], 4);
            if ((bits & 0x7fffffffu) > 0x7f7fffffu)
                return false;
        }
    vuBlockDest(s.vf[fd], result, dest);
    return true;
#endif
}

} // namespace
