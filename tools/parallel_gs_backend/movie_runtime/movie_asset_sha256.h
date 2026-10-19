#pragma once
#include <array>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>
namespace reo_gpu_movie_asset {
// Hash raw program/shader assets only. No graphics computation is performed.
inline std::string sha256(const std::vector<uint8_t>& bytes) {
    static constexpr uint32_t k[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4,
        0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
        0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
        0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
        0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
        0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116,
        0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
        0xc67178f2};
    auto rotate = [](uint32_t x, unsigned n) { return (x >> n) | (x << (32 - n)); };
    std::array<uint32_t, 8> h{{0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f,
                               0x9b05688c, 0x1f83d9ab, 0x5be0cd19}};
    std::vector<uint8_t> padded = bytes;
    padded.push_back(0x80);
    while ((padded.size() & 63) != 56)
        padded.push_back(0);
    uint64_t bits = uint64_t(bytes.size()) * 8;
    for (int shift = 56; shift >= 0; shift -= 8)
        padded.push_back(uint8_t(bits >> shift));
    for (size_t offset = 0; offset < padded.size(); offset += 64) {
        uint32_t w[64]{};
        for (unsigned i = 0; i < 16; ++i)
            for (unsigned j = 0; j < 4; ++j)
                w[i] = (w[i] << 8) | padded[offset + i * 4 + j];
        for (unsigned i = 16; i < 64; ++i) {
            uint32_t s0 = rotate(w[i - 15], 7) ^ rotate(w[i - 15], 18) ^ (w[i - 15] >> 3);
            uint32_t s1 = rotate(w[i - 2], 17) ^ rotate(w[i - 2], 19) ^ (w[i - 2] >> 10);
            w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        }
        uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], v = h[7];
        for (unsigned i = 0; i < 64; ++i) {
            uint32_t s1 = rotate(e, 6) ^ rotate(e, 11) ^ rotate(e, 25), ch = (e & f) ^ (~e & g);
            uint32_t t1 = v + s1 + ch + k[i] + w[i];
            uint32_t s0 = rotate(a, 2) ^ rotate(a, 13) ^ rotate(a, 22),
                     maj = (a & b) ^ (a & c) ^ (b & c), t2 = s0 + maj;
            v = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }
        const uint32_t out[8]{a, b, c, d, e, f, g, v};
        for (unsigned i = 0; i < 8; ++i)
            h[i] += out[i];
    }
    constexpr char hex[] = "0123456789abcdef";
    std::string result;
    result.reserve(64);
    for (uint32_t word : h)
        for (int shift = 28; shift >= 0; shift -= 4)
            result.push_back(hex[(word >> shift) & 15]);
    return result;
}
} // namespace reo_gpu_movie_asset
