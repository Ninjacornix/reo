#pragma once
#include <emmintrin.h>
#include <cstdint>
// Native packet helpers; preserve separate rounding, truncation and saturation.
// A binary32 value scaled by a power of two has the same integer truncation as
// the old binary64 scale, including overflow. NaN declines without mutation.
namespace reo_native_fixed {
inline unsigned laneBits(unsigned m) {
    return ((m & 8) >> 3) | ((m & 4) >> 1) | ((m & 2) << 1) | ((m & 1) << 3);
}
inline bool bounded(__m128 value, float bound, unsigned mask = 15) {
    const auto absolute = _mm_and_ps(value, _mm_castsi128_ps(_mm_set1_epi32(0x7fffffff)));
    return (unsigned(_mm_movemask_ps(_mm_cmple_ps(absolute, _mm_set1_ps(bound)))) &
            laneBits(mask)) == laneBits(mask);
}
inline bool positive(__m128 value, unsigned mask = 15) {
    return (unsigned(_mm_movemask_ps(_mm_cmplt_ps(value, _mm_setzero_ps()))) & laneBits(mask)) == 0;
}
template <unsigned Mask, unsigned Shift> inline bool convert(__m128& value) {
    static_assert(Mask < 16 && Shift < 31);
    const auto mask =
        _mm_set_epi32(Mask & 1 ? -1 : 0, Mask & 2 ? -1 : 0, Mask & 4 ? -1 : 0, Mask & 8 ? -1 : 0);
    const auto bits = _mm_and_si128(_mm_castps_si128(value), mask);
    const auto nan = _mm_and_si128(
        _mm_cmpeq_epi32(_mm_and_si128(bits, _mm_set1_epi32(0x7f800000)),
                        _mm_set1_epi32(0x7f800000)),
        _mm_cmpgt_epi32(_mm_and_si128(bits, _mm_set1_epi32(0x007fffff)), _mm_setzero_si128()));
    if (_mm_movemask_ps(_mm_castsi128_ps(nan)))
        return false;
    const auto scaled =
        Shift ? _mm_mul_ps(_mm_castsi128_ps(bits), _mm_set1_ps(float(uint32_t(1) << Shift)))
              : _mm_castsi128_ps(bits);
    const auto truncated = _mm_cvttps_epi32(scaled);
    const auto high = _mm_castps_si128(_mm_cmpge_ps(scaled, _mm_set1_ps(2147483648.0f)));
    const auto saturated = _mm_or_si128(_mm_and_si128(high, _mm_set1_epi32(0x7fffffff)),
                                        _mm_andnot_si128(high, truncated));
    value = _mm_castsi128_ps(_mm_or_si128(_mm_and_si128(mask, saturated),
                                          _mm_andnot_si128(mask, _mm_castps_si128(value))));
    return true;
}
} // namespace reo_native_fixed
