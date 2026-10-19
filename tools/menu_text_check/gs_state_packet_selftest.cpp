// The runner extracts the exact private production classifier into this include.
// No runtime library, worker, game, or copied classifier implementation is used.
#include <algorithm>
#include <cstdint>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <vector>
namespace {
#include "gs_state_packet_classifier.inc"
unsigned checks = 0, failures = 0;
void check(bool actual, bool expected, const char* name, unsigned detail = 0) {
    ++checks;
    if (actual != expected) {
        ++failures;
        std::printf("FAIL %s detail=%u actual=%u expected=%u\n", name, detail, actual, expected);
    }
}
void put64(std::vector<uint8_t>& p, size_t off, uint64_t value) {
    std::memcpy(p.data() + off, &value, 8u);
}
std::vector<uint8_t> statePacket(unsigned loops = 8) {
    static const uint64_t regs[] = {0x4c, 0x4d, 0x4e, 0x4f, 0x18, 0x19, 0x45, 0x46};
    std::vector<uint8_t> p(16u + size_t(loops) * 16u);
    put64(p, 0, 0x1000000000008000ull | loops);
    put64(p, 8, 0xe);
    for (unsigned i = 0; i < loops; ++i) {
        put64(p, 16u + i * 16u, 0xff00112233445566ull + i);
        put64(p, 24u + i * 16u, regs[i % 8u]);
    }
    return p;
}
bool classify(const std::vector<uint8_t>& p) {
    return gsIsStateOnlyPacket(p.data(), p.size());
}
void observe(GsStatePacketStream& s, const std::vector<uint8_t>& p) {
    s.observe(p.data(), p.size());
}
} // namespace
int main() {
    const auto actualIrq = statePacket();
    check(classify(actualIrq), true, "reached-IRQ-END-QWC9-tag-8008-descriptor-E");
    check(gsIsStateOnlyPacket(nullptr, actualIrq.size()), false, "null");
    for (size_t n = 0; n < actualIrq.size(); ++n)
        check(gsIsStateOnlyPacket(actualIrq.data(), n), false, "truncated", unsigned(n));
    for (unsigned n = 1; n <= 32; ++n) {
        auto p = actualIrq;
        p.resize(p.size() + n);
        check(classify(p), false, "trailing", n);
    }
    for (unsigned n = 1; n <= 16; ++n)
        check(classify(statePacket(n)), true, "bounded-valid-loops", n);
    check(classify(statePacket(17)), false, "oversized-state");
    for (uint64_t reg : {0x18ull, 0x19ull, 0x45ull, 0x46ull, 0x4cull, 0x4dull, 0x4eull, 0x4full}) {
        auto p = statePacket(1);
        put64(p, 24, reg);
        check(classify(p), true, "each-whitelisted-state", unsigned(reg));
    }
    // Includes vertex/PRIM, attributes, other state, HW transfers and IRQ writes.
    for (uint64_t reg : {0ull,    1ull,    2ull,    3ull,    4ull,    5ull,    6ull,    0x0cull,
                         0x0dull, 0x14ull, 0x3full, 0x42ull, 0x47ull, 0x49ull, 0x50ull, 0x51ull,
                         0x52ull, 0x53ull, 0x54ull, 0x60ull, 0x61ull, 0x62ull, 0xffull}) {
        auto p = actualIrq;
        put64(p, 24, reg);
        check(classify(p), false, "forbidden-state-or-side-effect", unsigned(reg));
    }
    for (uint64_t reg : {0x14cull, 0x800000000000004cull}) {
        auto p = actualIrq;
        put64(p, 24, reg);
        check(classify(p), false, "reserved-address-bits");
    }
    for (uint64_t high : {0ull, 5ull, 0xfull, 0xeeull, 0x100000000000000eull}) {
        auto p = actualIrq;
        put64(p, 8, high);
        check(classify(p), false, "descriptor-not-exact-AD", unsigned(high));
    }
    for (uint64_t tag : {0x1000000000000008ull, 0x1000000000008000ull, 0x0000000000008008ull,
                         0x2000000000008008ull, 0x1000000000018008ull, 0x1000200000008008ull,
                         0x1000400000008008ull, 0x1000800000008008ull, 0x1400000000008008ull,
                         0x1800000000008008ull, 0x1c00000000008008ull}) {
        auto p = actualIrq;
        put64(p, 0, tag);
        check(classify(p), false, "tag-reserved-PRE-format-or-length");
    }
    auto twoTags = actualIrq;
    twoTags.insert(twoTags.end(), actualIrq.begin(), actualIrq.end());
    check(classify(twoTags), false, "multiple-tags");

    GsStatePacketStream s;
    check(s.canBypass(), true, "initial-stream-known");
    observe(s, actualIrq);
    check(s.canBypass(), true, "state-stream-known");
    auto image = std::vector<uint8_t>(32u);
    put64(image, 0, 0x0800000000008004ull);
    observe(s, image);
    check(s.canBypass(), false, "fragmented-IMAGE-inhibits");
    check(s.pendingImageBytes == 48u, true, "fragment-count");
    observe(s, std::vector<uint8_t>(16u));
    check(s.pendingImageBytes == 32u, true, "IMAGE-partial-continuation");
    observe(s, std::vector<uint8_t>(32u));
    check(s.canBypass(), true, "IMAGE-completion-restores-proof");
    s = {};
    observe(s, image);
    check(s.canBypass() && classify(actualIrq), false, "state-looking-IMAGE-bytes-never-bypass");
    observe(s, actualIrq);
    check(s.canBypass(), false, "ambiguous-continuation-not-recovered-by-state-looking-bytes");
    s = {};
    auto completeImage = std::vector<uint8_t>(80u);
    put64(completeImage, 0, 0x0800000000008004ull);
    observe(s, completeImage);
    check(s.canBypass(), true, "complete-IMAGE-tracked");
    check(classify(completeImage), false, "IMAGE-cannot-exempt");
    s = {};
    auto reglist = std::vector<uint8_t>(32u);
    put64(reglist, 0, 0x1400000000008001ull);
    observe(s, reglist);
    check(s.canBypass(), true, "REGLIST-odd-padding-tracked");
    check(classify(reglist), false, "REGLIST-cannot-exempt");
    s = {};
    auto drawing = statePacket(1);
    put64(drawing, 8, 5);
    observe(s, drawing);
    check(s.canBypass(), true, "draw-stream-position-known");
    check(classify(drawing), false, "draw-cannot-exempt");
    s = {};
    auto broken = statePacket(1);
    put64(broken, 0, 0x1000000000008002ull);
    observe(s, broken);
    check(s.canBypass(), false, "malformed-stream-disables");
    observe(s, actualIrq);
    check(s.canBypass(), false, "unknown-proof-sticky");
    s = {};
    auto trailing = actualIrq;
    trailing.push_back(0);
    observe(s, trailing);
    check(s.canBypass(), false, "trailing-stream-disables");
    s = {};
    auto disabled = std::vector<uint8_t>(16u);
    put64(disabled, 0, 0x0c00000000008000ull);
    observe(s, disabled);
    check(s.canBypass(), false, "disabled-format-unproven");
    s = {};
    s.observe(actualIrq.data(), 16u * 1024u * 1024u + 16u);
    check(s.canBypass(), false, "bounded-parser-size");
    s = {};
    s.observe(nullptr, 16u);
    check(s.canBypass(), false, "null-stream-unproven");
    s = {};
    auto tooManyTags = std::vector<uint8_t>(4097u * 16u);
    observe(s, tooManyTags);
    check(s.canBypass(), false, "bounded-parser-tags");
    s = {};
    check(s.canBypass(), true, "new-session-reset");
    std::printf("GS state packet classification: checks=%u failures=%u\n", checks, failures);
    return failures ? 1 : 0;
}
