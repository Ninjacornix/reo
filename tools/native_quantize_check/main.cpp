#include "../../recomp/overrides/native_geometry/native_fixed_point.h"
#include <array>
#include <chrono>
#include <cmath>
#include <climits>
#include <cstring>
#include <iostream>
#include <random>
template <unsigned M, unsigned S> bool check(const std::array<uint32_t, 4>& bits) {
    std::array<float, 4> v;
    std::memcpy(v.data(), bits.data(), 16);
    auto expected = bits;
    bool accepted = true;
    for (unsigned c = 0; c < 4; ++c)
        if (M & (8 >> c)) {
            const double scaled = double(v[c]) * double(1u << S);
            if (std::isnan(scaled)) {
                accepted = false;
                break;
            }
            const int32_t q = scaled >= 2147483648.0   ? INT32_MAX
                              : scaled < -2147483648.0 ? INT32_MIN
                                                       : int32_t(scaled);
            std::memcpy(&expected[c], &q, 4);
        }
    if (!accepted)
        expected = bits;
    auto a = _mm_castsi128_ps(_mm_loadu_si128(reinterpret_cast<const __m128i*>(bits.data())));
    const bool got = reo_native_fixed::convert<M, S>(a);
    std::array<uint32_t, 4> actual;
    _mm_storeu_si128(reinterpret_cast<__m128i*>(actual.data()), _mm_castps_si128(a));
    return got == accepted && expected == actual;
}
int main() {
    uint64_t checks = 0, failed = 0;
    std::mt19937 rng(0x189b08);
    const std::array<uint32_t, 20> edges = {
        0,          0x80000000, 1,          0x80000001, 0x007fffff, 0x00800000, 0x3f800000,
        0xbf800000, 0x4f000000, 0xcf000000, 0x4effffff, 0xceffffff, 0x7f800000, 0xff800000,
        0x7fc01234, 0x7fa01234, 0xffc01234, 0x4d000000, 0xcd000000, 0x7f7fffff};
    for (unsigned i = 0; i < 300000; ++i) {
        std::array<uint32_t, 4> b;
        for (unsigned c = 0; c < 4; ++c)
            b[c] = i < 400 ? edges[(i + c * 3) % edges.size()] : rng();
        for (bool ok :
             {check<15, 0>(b), check<14, 0>(b), check<14, 4>(b), check<8, 4>(b), check<0, 4>(b)}) {
            ++checks;
            failed += !ok;
        }
        std::array<float, 4> v;
        std::memcpy(v.data(), b.data(), 16);
        const auto s = _mm_loadu_ps(v.data());
        for (unsigned mask = 0; mask < 16; ++mask) {
            bool bounded = true, positive = true;
            for (unsigned c = 0; c < 4; ++c)
                if (mask & (8 >> c)) {
                    bounded &= std::isfinite(v[c]) && std::fabs(v[c]) <= 33554432.f;
                    positive &= !(v[c] < 0);
                }
            ++checks;
            failed += bounded != reo_native_fixed::bounded(s, 33554432.f, mask);
            ++checks;
            failed += positive != reo_native_fixed::positive(s, mask);
        }
    }
    std::cout << checks << " differential checks, failures=" << failed << '\n';
    return failed ? 1 : 0;
}
