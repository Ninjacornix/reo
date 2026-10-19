#include "clut_shadow.h"
#include <cstdio>
#include <vector>
using namespace clut_shadow;
struct Call {
    unsigned psm, cbp, width, x, y;
};
int main() {
    unsigned failures = 0, checks = 0;
    std::vector<Call> calls;
    uint32_t revision = 0;
    auto check = [&](const char* n, bool ok) {
        ++checks;
        failures += !ok;
        if (!ok)
            std::printf("FAIL %s\n", n);
    };
    // Independent coordinate oracle: no PSM swizzle/address helper reused.
    auto reader = [&](unsigned psm, unsigned cbp, unsigned width, unsigned x, unsigned y) {
        calls.push_back({psm, cbp, width, x, y});
        return Raw{0x80000000u | (revision << 24) | (cbp << 16) | (y << 8) | x,
                   uint32_t(calls.size() * 4), true};
    };
    Shadow s;
    Tex a{3, 0x14, 0, 0, 0, 2};
    Origin weird{4, 7, 9};
    check("initial unknown", !s.select(a, weird, 8).raw.valid);
    a.cld = 0;
    s.load(a, weird, reader);
    check("CLD0 no read", calls.empty());
    check("CLD0 does not invent CBP", !s.cbpKnown()[0] && !s.cbpKnown()[1]);
    a.cld = 2;
    auto e = s.load(a, weird, reader);
    check("CLD2 loads16", e.loaded && calls.size() == 16);
    check("CLD2 remembers0", s.cbpKnown()[0] && s.cbps()[0] == 3 && !s.cbpKnown()[1]);
    for (unsigned i = 0; i < 16; ++i) {
        const auto& c = calls[i];
        check("T4 source coordinates independent CSA/TEXCLUT",
              c.psm == 0 && c.cbp == 3 && c.width == 1 && c.x == i % 8 && c.y == i / 8);
    }
    check("T4 entry8 raw", s.select(a, weird, 8).raw.value == 0x80030100u);
    revision = 1;
    a.cld = 0;
    s.load(a, weird, reader);
    check("source mutation no reload", s.select(a, weird, 8).raw.value == 0x80030100u);
    a.cld = 4;
    unsigned oldCalls = unsigned(calls.size());
    e = s.load(a, weird, reader);
    check("CLD4 same pointer retains",
          !e.loaded && calls.size() == oldCalls && s.select(a, weird, 8).raw.value == 0x80030100u);
    a.cbp = 4;
    e = s.load(a, weird, reader);
    check("CLD4 changed loads",
          e.loaded && s.cbps()[0] == 4 && s.select(a, weird, 8).raw.value == 0x81040100u);
    a.cld = 3;
    a.cbp = 5;
    s.load(a, weird, reader);
    check("CLD3 remembers1 independently", s.cbps()[0] == 4 && s.cbps()[1] == 5);
    a.cld = 5;
    e = s.load(a, weird, reader);
    check("CLD5 same skips", !e.loaded);
    a.cbp = 6;
    e = s.load(a, weird, reader);
    check("CLD5 changed", e.loaded && s.cbps()[1] == 6 && s.cbps()[0] == 4);
    Tex nonindexed{88, 0, 0, 0, 0, 2};
    oldCalls = unsigned(calls.size());
    s.load(nonindexed, weird, reader);
    check("nonindexed cannot update CBP", s.cbps()[0] == 4 && calls.size() == oldCalls);
    a.cld = 1;
    a.csa = 1;
    a.cbp = 7;
    s.load(a, weird, reader);
    check("partial bank source stays CBP upperleft",
          calls[calls.size() - 16].x == 0 && calls[calls.size() - 16].y == 0);
    check("CSA selects new bank", s.select(a, weird, 8).raw.value == 0x81070100u);
    a.csa = 0;
    check("other bank preserved", s.select(a, weird, 8).raw.value == 0x81060100u);
    // TEX2 adapter uses identical load model; it must not need geometry to reload.
    a.cbp = 9;
    revision = 2;
    s.load(a, weird, reader);
    check("TEX2 style reload", s.select(a, weird, 8).raw.value == 0x82090100u);
    Tex t8{2, 0x13, 0, 0, 0, 1};
    calls.clear();
    s.load(t8, weird, reader);
    check("T8 count256", calls.size() == 256);
    // Diagram-based independently written coordinate examples.
    check("T8 index8 is x0 y1", calls[8].x == 0 && calls[8].y == 1);
    check("T8 index16 is x8 y0", calls[16].x == 8 && calls[16].y == 0);
    check("T8 index255 is x15 y15", calls[255].x == 15 && calls[255].y == 15);
    check("T8 entry8 raw", s.select(t8, weird, 8).raw.value == 0x82020100u);
    t8.csa = 1;
    e = s.load(t8, weird, reader);
    check("T8 offset explicitly unknown",
          e.reason == Reason::T8Offset && !s.select(a, weird, 0).raw.valid);
    for (unsigned cpsm : {2u, 10u}) {
        Tex t16{1, 0x14, uint8_t(cpsm), 0, 31, 1};
        calls.clear();
        s.load(t16, weird, reader);
        check("T16 last bank", s.select(t16, weird, 8).raw.value == 0x0100 && calls.size() == 16);
    }
    Tex csm2{1, 0x14, 2, 1, 0, 1};
    Origin origin{4, 2, 5};
    calls.clear();
    s.load(csm2, origin, reader);
    check("CSM2 documented horizontal", calls.size() == 16 && calls[0].x == 32 &&
                                            calls[15].x == 47 && calls[15].y == 5 &&
                                            calls[15].width == 4);
    check("CSM2 entry15", s.select(csm2, origin, 15).raw.value == 0x052f);
    auto live = Shadow::live(csm2, origin, 15, reader);
    check("current-live mapping differs", live.value != s.select(csm2, origin, 15).raw.value);
    csm2.csm = 0;
    csm2.cld = 0;
    s.load(csm2, origin, reader);
    check("CSM reinterpretation uncertain",
          s.select(csm2, origin, 0).reason == Reason::CsmReinterpretation);
    csm2.csm = 1;
    csm2.cpsm = 0;
    csm2.cld = 1;
    e = s.load(csm2, origin, reader);
    check("undocumented CSM2 CT32 unknown", e.reason == Reason::UnsupportedCsm2);
    a.csa = 16;
    e = s.load(a, origin, reader);
    check("CT32 CSA16 unknown", e.reason == Reason::InvalidCsa);
    a.csa = 0;
    a.cld = 6;
    e = s.load(a, origin, reader);
    check("reserved CLD loses certainty", e.reason == Reason::ReservedCld && !s.cbpKnown()[0]);
    s.reset();
    a.cld = 4;
    e = s.load(a, origin, reader);
    check("conditional before known CBP not guessed", e.reason == Reason::UnknownCbp && !e.loaded);
    a.cld = 1;
    s.load(a, origin, [](auto...) { return Raw{}; });
    check("unavailable source unknown",
          !s.select(a, origin, 0).raw.valid && s.lastReason() == Reason::SourceUnavailable);
    s.reset();
    check("reset cannot retain prior session palette",
          !s.select(a, origin, 0).raw.valid && !s.cbpKnown()[0]);
    std::printf("CORE checks=%u failures=%u\n", checks, failures);
    return failures ? 1 : 0;
}
