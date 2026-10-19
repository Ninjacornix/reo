// Compare every supported window size and FIFO boundary to the original reader.
#include "ipu/ps2_ipu.cpp"
#include <chrono>
#include <iostream>
#include <random>

static uint32_t reference(int n) {
    uint32_t v = 0;
    for (int i = 0; i < n; ++i) {
        const int64_t p = ps2_ipu::g_bitPos + i;
        uint32_t bit = 0;
        if (p >= 0 && p < static_cast<int64_t>(ps2_ipu::g_in.size()) * 8)
            bit = (ps2_ipu::g_in[static_cast<size_t>(p >> 3)] >> (7 - (p & 7))) & 1u;
        v = (v << 1) | bit;
    }
    return v;
}
int main() {
    std::mt19937 rng(0x424954);
    uint64_t cases = 0;
    for (unsigned size = 0; size <= 80; ++size) {
        ps2_ipu::g_in.resize(size);
        for (auto& b : ps2_ipu::g_in)
            b = static_cast<uint8_t>(rng());
        for (int64_t p = -9; p <= static_cast<int64_t>(size) * 8 + 16; ++p)
            for (int n = 0; n <= 32; ++n) {
                ps2_ipu::g_bitPos = p;
                ++cases;
                if (ps2_ipu::peekPadded(n) != reference(n)) {
                    std::cerr << "FAIL size=" << size << " pos=" << p << " count=" << n << "\n";
                    return 1;
                }
            }
    }
    std::cout << "PASS " << cases << " exact bit-window comparisons\n";
    volatile uint32_t checksum = 0;
    auto bench = [&](auto fn) {
        auto start = std::chrono::steady_clock::now();
        for (unsigned i = 0; i < 1000000; ++i) {
            ps2_ipu::g_bitPos = i % 600;
            checksum = checksum + fn(16);
        }
        return std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start)
            .count();
    };
    const double old = bench(reference), fast = bench(ps2_ipu::peekPadded);
    std::cout << "scalar_ms=" << old << " production_ms=" << fast << " speedup=" << old / fast
              << " checksum=" << checksum << "\n";
}
