#pragma once
#include <cstdint>
#include <cstring>
#include <emmintrin.h>
// Private source-only diagnostic payload. No timers, allocation, logging, or
// guest-state writes. Passing nullptr preserves the normal caller contract.
namespace reo_native_refusal {
enum class Reason : uint32_t {
    None,
    Structural,
    CountOrBudget,
    ZeroRegisters,
    QuantizationNaN,
    LoopCounter
};
struct Event {
    Reason reason = Reason::None;
    uint32_t pc = 0, mask = 0, shift = 0, vertex = 0, count = 0, remaining = 0;
    uint32_t originalPC = 0, mode = 0, originalInput = 0, originalOutput = 0;
    uint32_t input[4]{}, q = 0, p = 0, nanMask = 0;
    // Semantic working vectors map to VF22..31 followed by ACC. Unwritten/raw
    // lanes remain raw words; the observer does not classify the whole state.
    uint32_t working[11][4]{};
};
inline void raw(uint32_t (&out)[4], __m128 value) {
    _mm_storeu_si128(reinterpret_cast<__m128i*>(out), _mm_castps_si128(value));
}
inline uint32_t raw(float value) {
    uint32_t result;
    std::memcpy(&result, &value, 4);
    return result;
}
inline void stage(Event* out, Reason reason, uint32_t pc, uint32_t vertex, uint32_t count,
                  uint32_t remaining) {
    if (!out)
        return;
    out->reason = reason;
    out->pc = pc;
    out->vertex = vertex;
    out->count = count;
    out->remaining = remaining;
}
inline void quantization(Event* out, uint32_t pc, uint32_t mask, uint32_t shift, __m128 before,
                         float q, float p, uint32_t vertex, uint32_t count, uint32_t remaining,
                         __m128 lightX, __m128 lightY, __m128 lightZ, __m128 distance, __m128 color,
                         __m128 stq, __m128 screen, __m128 position, __m128 normal, __m128 uv,
                         __m128 acc) {
    if (!out)
        return;
    stage(out, Reason::QuantizationNaN, pc, vertex, count, remaining);
    out->mask = mask;
    out->shift = shift;
    raw(out->input, before);
    out->q = raw(q);
    out->p = raw(p);
    for (unsigned lane = 0; lane < 4; ++lane)
        if ((mask & (8u >> lane)) && ((out->input[lane] & 0x7f800000u) == 0x7f800000u) &&
            (out->input[lane] & 0x007fffffu))
            out->nanMask |= 8u >> lane;
    const __m128 values[] = {lightX, lightY,   lightZ, distance, color, stq,
                             screen, position, normal, uv,       acc};
    for (unsigned n = 0; n < 11; ++n)
        raw(out->working[n], values[n]);
}
} // namespace reo_native_refusal
