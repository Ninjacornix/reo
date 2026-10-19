// Exercise the private production IDCT against its original scalar definition.
// No guest code, assets or shared runtime interfaces are needed.
#include "ipu/ps2_ipu.cpp"
#include <chrono>
#include <random>
#include <iostream>

static void reference(const int32_t* in, int16_t* out) {
    static double c[8][8];
    static bool initialized = false;
    if (!initialized) {
        for (int x = 0; x < 8; ++x)
            for (int u = 0; u < 8; ++u)
                c[x][u] = (u == 0 ? std::sqrt(0.125) : 0.5) *
                          std::cos((2 * x + 1) * u * 3.14159265358979323846 / 16.0);
        initialized = true;
    }
    double tmp[64];
    for (int y = 0; y < 8; ++y)
        for (int x = 0; x < 8; ++x) {
            double sum = 0;
            for (int u = 0; u < 8; ++u)
                sum += c[x][u] * in[y * 8 + u];
            tmp[y * 8 + x] = sum;
        }
    for (int x = 0; x < 8; ++x)
        for (int y = 0; y < 8; ++y) {
            double sum = 0;
            for (int v = 0; v < 8; ++v)
                sum += c[y][v] * tmp[v * 8 + x];
            out[y * 8 + x] = static_cast<int16_t>(std::clamp<long>(std::lround(sum), -256, 255));
        }
}

int main() {
    std::mt19937 rng(0x495055);
    int32_t block[64];
    int16_t actual[64], expected[64];
    unsigned cases = 0;
#if defined(_M_X64) || defined(__SSE2__)
    for (double tie : {-256.5, -255.5, -1.5, -0.5, 0.5, 1.5, 254.5, 255.5})
        for (double value : {std::nextafter(tie, -INFINITY), tie, std::nextafter(tie, INFINITY)}) {
            int16_t result[2];
            ps2_ipu::roundIdctPair(_mm_set1_pd(value), result);
            const int16_t want =
                static_cast<int16_t>(std::clamp<long>(std::lround(value), -256, 255));
            if (result[0] != want || result[1] != want) {
                std::cerr << "FAIL rounding tie " << value << "\n";
                return 1;
            }
        }
#endif
    auto check = [&] {
        ps2_ipu::idct(block, actual);
        reference(block, expected);
        ++cases;
        for (int i = 0; i < 64; ++i)
            if (actual[i] != expected[i]) {
                std::cerr << "FAIL block=" << cases << " sample=" << i << " actual=" << actual[i]
                          << " expected=" << expected[i] << "\n";
                return false;
            }
        return true;
    };
    // Exhaust the dequantized DC range, with and without MPEG-2 mismatch bit.
    for (int dc = -2048; dc <= 2047; ++dc)
        for (int mismatch = 0; mismatch < 2; ++mismatch) {
            std::fill(block, block + 64, 0);
            block[0] = dc;
            block[63] = mismatch;
            if (!check())
                return 1;
        }
    for (int n = 0; n < 20000; ++n) {
        for (int& x : block)
            x = (rng() % 4 == 0 || n % 2) ? static_cast<int>(rng() % 4096) - 2048 : 0;
        if (!check())
            return 1;
    }
    std::cout << "PASS " << cases << " blocks, " << cases * 64ull << " exact sample comparisons\n";
    volatile int checksum = 0;
    auto bench = [&](auto fn) {
        const auto start = std::chrono::steady_clock::now();
        for (int n = 0; n < 50000; ++n) {
            fn(block, actual);
            checksum = checksum + actual[n % 64];
        }
        return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start)
            .count();
    };
    const double scalar = bench(reference), simd = bench(ps2_ipu::idct);
    std::cout << "scalar_ms=" << scalar << " production_ms=" << simd << " speedup=" << scalar / simd
              << " checksum=" << checksum << "\n";
}
