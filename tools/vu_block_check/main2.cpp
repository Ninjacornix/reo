// Reuse the independent full-output replay oracle, including its eight controls.
#include <cmath>
#define main vuReplayOracleMain
#include "../vu_nop_check/main.cpp"
#undef main

// Private whole-kick diagnostics are disabled in this isolated executable.
#if !defined(REO_VU_ISOLATED_RUNTIME_STUBS)
bool ps2VifKickVuProfileActive() noexcept {
    return false;
}
void ps2VifKickVuProfileRecord(uint64_t, uint32_t, bool) noexcept {}
#endif
void ps2VuBlockTestTracking(bool);
uint64_t ps2VuBlockTestHits();
uint64_t ps2VuBlockTestFallbacks();
bool ps2VuBlockTestCandidate();

static void restoreBlock(Fixture& f, const Snapshot& s) {
    std::memcpy(f.code.data(), s.code.data(), s.code.size());
    std::memcpy(f.data.data(), s.data.data(), s.data.size());
    std::memcpy(&f.vu.state(), s.state.data(), s.state.size());
    f.memory.packets.clear();
    f.gs.packets.clear();
    f.memory.vif1_regs.top = s.meta[5];
    f.memory.vif1_regs.tops = s.meta[6];
    f.memory.vif1_regs.itop = s.meta[7];
}
static void blockControls(const fs::path& out, const char* weighted, const char* room) {
    unsigned before = failures;
    for (unsigned group = 0; group < 2; ++group) {
        const auto s =
            load(fs::path(group ? room : weighted) / "vu1-run-0000", group ? "static" : "weighted");
        const unsigned start = group ? 0x260 : 0x348, pairs = group ? 50 : 75;
        const unsigned fallthrough = group ? 0x3F0 : 0x5A0, target = group ? 0x488 : 0x5B0;
        for (unsigned mode = 0; mode < 19; ++mode) {
            Fixture f;
            restoreBlock(f, s);
            unsigned cycles = pairs, pc = start;
            bool expectHit = true;
            uint64_t unusedMemoryHits = 0, unusedMemoryFallbacks = 0;
            if (mode == 1) {
                cycles = pairs - 1;
                expectHit = false;
            } // budget cannot overrun.
            if (mode == 2) {
                cycles = 1;
                expectHit = false;
            }
            if (mode == 3) {
                pc = start + 8;
                cycles = pairs - 1;
                expectHit = false;
            } // interior entry generic.
            if (mode == 4) {
                f.code[16000] ^= 1;
                expectHit = false;
            } // full identity, even outside block.
            if (mode == 5) { // Same pointer, changed upper to NOP; generic must see replacement.
                const uint32_t nop = 0x2FF;
                std::memcpy(f.code.data() + start + 4, &nop, 4);
                expectHit = false;
            }
            if (mode == 6) { // E in the first pair forces delay termination via generic path.
                uint32_t hi;
                std::memcpy(&hi, f.code.data() + start + 4, 4);
                hi |= 0x40000000;
                std::memcpy(f.code.data() + start + 4, &hi, 4);
                expectHit = false;
            }
            if (mode == 7) {
                expectHit =
                    false; // Nonfinite bit patterns keep scalar fallbacks and payload handling.
                for (unsigned r = 1; r < 32; ++r)
                    for (unsigned c = 0; c < 4; ++c) {
                        const uint32_t bits = (r + c) % 3 == 0
                                                  ? 0x7FC01234u
                                                  : ((r + c) % 3 == 1 ? 0xFF800000u : 0x80000000u);
                        std::memcpy(&f.vu.state().vf[r][c], &bits, 4);
                    }
            }
            if (mode ==
                8) { // Signed zero and tiny finite lanes exercise exact multiplication order.
                for (unsigned r = 1; r < 32; ++r)
                    for (unsigned c = 0; c < 4; ++c) {
                        const uint32_t bits = (r + c) % 2 ? 0x80000000u : 0x00800001u;
                        std::memcpy(&f.vu.state().vf[r][c], &bits, 4);
                    }
            }
            if (mode == 9) { // Incoming branch whose delay pair is the hot-block entry.
                pc = start - 8;
                cycles = pairs + 1;
                f.pair(pc, 0x40000003u);
                expectHit = false;
            }
            if (mode == 10) { // Zero-register pollution is normalized at the same pair boundary.
                f.vu.state().vi[0] = 12345;
                f.vu.state().vf[0][0] = 987;
            }
            if (mode == 11) {
                cycles = 0;
                expectHit = false;
            }
            if (mode >= 12 && mode <= 17) {
                // Controlled finite entry isolates memory-origin fallback from
                // tag-like nonfinite VF lanes in the original snapshots.
                for (unsigned r = 0; r < 32; ++r)
                    for (unsigned c = 0; c < 4; ++c)
                        f.vu.state().vf[r][c] = r == 0 ? (c == 3 ? 1.0f : 0.0f) : 1.0f;
                for (auto& v : f.vu.state().vi)
                    v = 0;
                f.vu.state().vi[5] = 32;
                for (auto& v : f.vu.state().acc)
                    v = 0;
                f.vu.state().q = f.vu.state().p = f.vu.state().i = 1;
                std::fill(f.data.begin(), f.data.end(), 0);
                if (mode == 12 || mode == 14 || mode == 15) {
                    const uint32_t word = mode == 12   ? 0x7FC05678u
                                          : mode == 14 ? 0x7F800000u
                                                       : 0x7F805678u;
                    for (unsigned off = 0; off < f.data.size(); off += 4)
                        std::memcpy(f.data.data() + off, &word, 4);
                }
                if (mode == 13) {
                    const uint32_t bits = 0x7F7FFFFFu;
                    for (unsigned r = 1; r < 32; ++r)
                        for (unsigned c = 0; c < 4; ++c)
                            std::memcpy(&f.vu.state().vf[r][c], &bits, 4);
                    expectHit = false;
                }
                if (mode == 16) {
                    Fixture reference;
                    restoreBlock(reference, s);
                    std::memcpy(&reference.vu.state(), &f.vu.state(), sizeof(VU1State));
                    reference.data = f.data;
                    ps2VuBlockTestTracking(true);
                    reference.vu.execute(reference.code.data(), reference.code.size(),
                                         reference.data.data(), reference.data.size(), reference.gs,
                                         &reference.memory, pc, s.meta[7], cycles);
                    unusedMemoryHits = ps2VuBlockTestHits();
                    unusedMemoryFallbacks = ps2VuBlockTestFallbacks();
                    ps2VuBlockTestTracking(false);
                    const uint32_t bits = 0x7FC05678u;
                    std::memcpy(f.data.data() + 900 * 16, &bits, 4);
                }
                if (mode == 17) {
                    const uint32_t bits = 0x7F805678u;
                    std::memcpy(&f.vu.state().vf[group ? 28 : 29][group ? 0 : 2], &bits, 4);
                    expectHit = false;
                }
            }
            if (mode == 18) {
                // Unknown replacement pair has a real upper->lower dependency:
                // finite upper multiplication overflows, then lower Inf/Inf
                // produces NaN. Identity/whole-pair fallback preserves it.
                const uint32_t max = 0x7F7FFFFFu;
                std::memcpy(&f.vu.state().vf[24][0], &max, 4);
                f.vu.state().i = 2;
                const uint32_t hi = (8u << 21) | (24u << 11) | (24u << 6) | 0x1Eu;
                const uint32_t lo = 0x800003BCu | (24u << 11) | (24u << 16);
                f.pair(start, lo, hi);
                cycles = 1;
                expectHit = false;
            }
            ps2VuBlockTestTracking(true);
            f.vu.execute(f.code.data(), f.code.size(), f.data.data(), f.data.size(), f.gs,
                         &f.memory, pc, s.meta[7], cycles);
            const auto hits = ps2VuBlockTestHits(), fallbacks = ps2VuBlockTestFallbacks();
            ps2VuBlockTestTracking(false);
            if (mode == 12 || mode == 14 || mode == 15) {
                check(hits <= 1, "memory-origin partial kernel has at most one hit");
                check(fallbacks == (ps2VuBlockTestCandidate() ? 1u : 0u),
                      "memory-origin arithmetic fallback reached");
            } else if (mode == 16) {
                check(hits == unusedMemoryHits && fallbacks == unusedMemoryFallbacks,
                      "unread memory NaN preserves finite-reference admission and fallback");
            } else {
                check(hits == (ps2VuBlockTestCandidate() && expectHit ? 1u : 0u),
                      "compiled-block gate / generic fallback hit count");
                if (mode == 7 || mode == 13 || mode == 17)
                    check(fallbacks == (ps2VuBlockTestCandidate() ? 1u : 0u),
                          "nonfinite/overflow input rejected before side effects");
            }
            if (mode == 18)
                check(std::isinf(f.vu.state().vf[24][0]) && std::isnan(f.vu.state().q),
                      "dependent replacement upper overflow / lower Inf division remains wholly "
                      "generic");
            if (mode == 0 || mode == 7 || mode == 8 || mode == 10) {
                check(f.vu.state().pc == (uint16_t(f.vu.state().vi[1]) == 0 ? target : fallthrough),
                      "terminal IBEQ and original delay pair preserve actual next PC");
                check(f.vu.state().vi[0] == 0 && f.vu.state().vf[0][0] == 0 &&
                          f.vu.state().vf[0][3] == 1,
                      "each compiled pair preserves zero-register invariants");
                check(f.memory.packets.empty() && f.gs.packets.empty(),
                      "non-XGKICK hot block emits no packet");
            }
            save(out / (std::string("block-") + (group ? "static-" : "weighted-") +
                        std::to_string(mode) + ".bin"),
                 f);
        }
        // Code and data may alias through the public interpreter API. This must
        // remain generic, since stores could modify instructions during a block.
        Fixture f;
        restoreBlock(f, s);
        ps2VuBlockTestTracking(true);
        f.vu.execute(f.code.data(), f.code.size(), f.code.data(), f.code.size(), f.gs, &f.memory,
                     start, s.meta[7], pairs);
        check(ps2VuBlockTestHits() == 0, "code/data alias suppresses compiled executor");
        ps2VuBlockTestTracking(false);
        std::memcpy(f.data.data(), f.code.data(), f.data.size());
        save(out / (std::string("block-") + (group ? "static" : "weighted") + "-alias.bin"), f);
    }
    std::printf("BLOCK_CONTROLS failed=%u candidate=%u\n", failures - before,
                unsigned(ps2VuBlockTestCandidate()));
}
int main(int argc, char** argv) {
    ps2VuBlockTestTracking(false);
    const int replayResult = vuReplayOracleMain(argc, argv);
    if (replayResult)
        return replayResult;
    try {
        blockControls(argv[1], argv[3], argv[4]);
    } catch (const std::exception& e) {
        std::fprintf(stderr, "ERROR %s\n", e.what());
        return 2;
    }
    std::printf("ALL_CHECKS %u passed %u failed\n", checks - failures, failures);
    return failures ? 1 : 0;
}
