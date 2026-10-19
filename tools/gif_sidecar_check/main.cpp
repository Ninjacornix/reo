#include "runtime/ps2_gif_arbiter.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/resident_gif_sidecar.h"
#include "../../third_party/PS2Recomp/ps2xRuntime/src/lib/gs_backend_route.h"
#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>
int main() {
    int checks = 0, failed = 0;
    auto check = [&](bool ok, const char* label) {
        ++checks;
        if (!ok)
            ++failed;
        std::cout << (ok ? "ok: " : "FAIL: ") << label << '\n';
    };
    std::vector<int> seen;
    bool fail = false;
    GifArbiter a([&](const uint8_t* p, uint32_t n) {
        if (fail)
            throw std::runtime_error("callback");
        if (n != 16)
            throw std::runtime_error("packet boundary changed");
        seen.push_back(100 * gs_backend_bridge::currentPath() + p[0]);
    });
    auto submit = [&](GifPathId path, int value, bool hl = false, bool image = false) {
        std::array<uint8_t, 16> b{};
        b[0] = uint8_t(value);
        if (image)
            b[7] = 8;
        a.submit(path, b.data(), 16, hl);
    };
    using namespace reo_resident_live;
    armArbiter(a);
    for (int i = 0; i < 1000; ++i) {
        submit(GifPathId::Path1, 1);
        a.drain();
    }
    check(seen.size() == 1000 && seen.front() == 101 && seen.back() == 101,
          "single ordinary provenance survives repeated drains");
    seen.clear();
    submit(GifPathId::Path3, 1);
    submit(GifPathId::Path1, 2);
    submit(GifPathId::Path1, 3);
    submit(GifPathId::Path2, 4);
    a.drain();
    check(seen == std::vector<int>({102, 103, 204, 301}),
          "inline and overflow ordinary packets retain path priority and stable order");
    seen.clear();
    submit(GifPathId::Path1, 1);
    submitResidentPath1(a, [&] { seen.push_back(150); });
    submit(GifPathId::Path1, 2);
    submitMoviePath3(a, false, [&](const auto&) { seen.push_back(350); });
    a.drain();
    check(seen == std::vector<int>({101, 150, 102, 350}),
          "typed effects interleave with ordinary packets by original ordinals");
    seen.clear();
    submit(GifPathId::Path2, 1, true);
    submit(GifPathId::Path3, 2, false, true);
    a.drain();
    check(seen == std::vector<int>({302, 201}), "PATH3 IMAGE keeps DIRECTHL priority exception");
    seen.clear();
    a.drain();
    submit(GifPathId::Path1, 7);
    a.drain();
    check(seen == std::vector<int>({107}), "empty drain does not lose subsequent provenance");
    seen.clear();
    armArbiter(a);
    disarmArbiter(a);
    submit(GifPathId::Path1, 8);
    a.drain();
    check(seen == std::vector<int>({108}), "nested arm ownership retains sidecar");
    seen.clear();
    fail = true;
    submit(GifPathId::Path1, 9);
    bool threw = false;
    try {
        a.drain();
    } catch (const std::runtime_error&) {
        threw = true;
    }
    check(threw, "single-packet callback refusal propagates");
    fail = false;
    submit(GifPathId::Path1, 10);
    a.drain();
    check(seen == std::vector<int>({110}),
          "failed prefix is discarded without stale callback replay");
    seen.clear();
    submit(GifPathId::Path1, 11);
    armArbiter(a);
    threw = false;
    try {
        a.drain();
    } catch (const std::logic_error&) {
        threw = true;
    }
    check(threw && seen.empty(), "arming after a queued packet still rejects missing provenance");
    std::cout << checks - failed << '/' << checks << " checks passed\n";
    return failed ? 1 : 0;
}
