// Included only by the isolated GPU source, after GS address headers.
#include "clut_shadow.h"
#include <cmath>
#include <cstring>
#include <limits>
namespace {
bool clutShadowEnabled() {
    static const bool on = [] {
        const char* e = std::getenv("REO_GS_CLUT_SHADOW");
        return e && std::atoi(e) != 0;
    }();
    return on;
}
clut_shadow::Tex clutShadowTex(const GSTex0Reg& t) {
    return {t.cbp, t.psm, t.cpsm, t.csm, t.csa, t.cld};
}
clut_shadow::Origin clutShadowOrigin(const GSTexClutReg& o) {
    return {o.cbw, o.cou, o.cov};
}
struct ClutShadowReader {
    const uint8_t* bytes;
    uint32_t size;
    bool hardwareWrap;
    clut_shadow::Raw operator()(uint8_t psm, uint32_t cbp, unsigned width, unsigned x,
                                unsigned y) const {
        uint32_t off;
        if (psm == 0 || psm == 1)
            off = GSPSMCT32::addrPSMCT32(cbp, width, x, y);
        else if (psm == 2)
            off = GSPSMCT16::addrPSMCT16(cbp, width, x, y);
        else if (psm == 10)
            off = GSPSMCT16::addrPSMCT16S(cbp, width, x, y);
        else
            return {};
        const unsigned n = psm == 0 || psm == 1 ? 4 : 2;
        if (hardwareWrap) {
            if (size != 4u * 1024u * 1024u)
                return {};
            off &= size - 1;
        }
        if (!bytes || uint64_t(off) + n > size)
            return {0, off, false};
        uint32_t raw = 0;
        std::memcpy(&raw, bytes + off, n);
        return {raw, off, true};
    }
};
struct ClutShadowRuntime {
    using Clock = std::chrono::steady_clock;
    const void* owner = nullptr;
    clut_shadow::Shadow shadow;
    Clock::time_point epoch;
    double at = 70, seconds = 60;
    unsigned limit = 512, logLimit = 64, checks = 0, logs = 0, zbp = 224;
    uint64_t loads = 0, unknownLoads = 0, skippedLoads = 0, divergent = 0, unknown = 0, events = 0;
    bool finished = false;
    struct LoadRecord {
        uint64_t serial = 0;
        clut_shadow::Tex tex;
        clut_shadow::Origin origin;
    };
    std::array<LoadRecord, 128> records{};
    ClutShadowRuntime() {
        if (const char* e = std::getenv("REO_GS_CLUT_SHADOW_AT"))
            at = std::max(0., std::strtod(e, nullptr));
        if (const char* e = std::getenv("REO_GS_CLUT_SHADOW_SECONDS"))
            seconds = std::clamp(std::strtod(e, nullptr), .001, 60.);
        if (const char* e = std::getenv("REO_GS_CLUT_SHADOW_COUNT"))
            limit = unsigned(std::clamp(std::atoi(e), 1, 4096));
        if (const char* e = std::getenv("REO_GS_CLUT_SHADOW_LOG_LIMIT"))
            logLimit = unsigned(std::clamp(std::atoi(e), 1, 128));
        if (const char* e = std::getenv("REO_GS_CLUT_SHADOW_ZBP"))
            zbp = std::strtoul(e, nullptr, 0) & 511;
    }
    void reset(const void* gs) {
        owner = gs;
        shadow.reset();
        epoch = Clock::now();
        checks = logs = 0;
        loads = unknownLoads = skippedLoads = divergent = unknown = events = 0;
        finished = false;
        records = {};
        auto ns =
            std::chrono::duration_cast<std::chrono::nanoseconds>(epoch.time_since_epoch()).count();
        std::fprintf(stderr,
                     "[GS-CLUT-SHADOW-CONFIG] epoch_ns=%lld origin=GS_reset at=%.6f seconds=%.6f "
                     "count=%u log_limit=%u zbp=%u fbps=0,112 roi_bbox=143,0,359,130 raw_words=512 "
                     "max_load_events=262144 load_time_poll=256 never_substitutes=1 "
                     "initial_cbp_known=0 initial_palette_known=0\n",
                     static_cast<long long>(ns), at, seconds, limit, logLimit, zbp);
    }
    void end(double elapsed, const char* reason) {
        finished = true;
        std::fprintf(
            stderr,
            "[GS-CLUT-SHADOW-END] reason=%s elapsed=%.6f events=%llu checks=%u divergent=%llu "
            "unknown=%llu loads=%llu skipped=%llu unknown_loads=%llu logs=%u\n",
            reason, elapsed, static_cast<unsigned long long>(events), checks,
            static_cast<unsigned long long>(divergent), static_cast<unsigned long long>(unknown),
            static_cast<unsigned long long>(loads), static_cast<unsigned long long>(skippedLoads),
            static_cast<unsigned long long>(unknownLoads), logs);
    }
    static ClutShadowRuntime& get() {
        static ClutShadowRuntime r;
        return r;
    }
};
void clutShadowReset(const void* gs) {
    if (clutShadowEnabled())
        ClutShadowRuntime::get().reset(gs);
}
void clutShadowLoad(const void* gs, const GSTex0Reg& t, const GSTexClutReg& o, const uint8_t* vram,
                    uint32_t size) {
    if (!clutShadowEnabled())
        return;
    auto& r = ClutShadowRuntime::get();
    if (r.owner != gs || r.finished)
        return;
    ++r.events;
    if ((r.events & 255) == 0) {
        const double elapsed =
            std::chrono::duration<double>(ClutShadowRuntime::Clock::now() - r.epoch).count();
        if (elapsed >= r.at + r.seconds || r.events >= 262144) {
            r.end(elapsed, r.events >= 262144 ? "load_cap" : "window");
            return;
        }
    }
    auto tex = clutShadowTex(t);
    auto origin = clutShadowOrigin(o);
    auto e = r.shadow.load(tex, origin, ClutShadowReader{vram, size, true});
    r.records[e.serial % r.records.size()] = {e.serial, tex, origin};
    r.loads += e.loaded;
    r.skippedLoads += !e.permitted;
    r.unknownLoads += e.reason != clut_shadow::Reason::None &&
                      e.reason != clut_shadow::Reason::NoLoad &&
                      e.reason != clut_shadow::Reason::UnsupportedIndex;
}
} // namespace
bool ps2GsClutShadowEnabled() {
    return clutShadowEnabled();
}
void ps2GsClutShadowInspect(const void* gs, const clut_shadow::Primitive& p, const uint8_t* vram,
                            uint32_t size) {
    if (!clutShadowEnabled())
        return;
    auto& r = ClutShadowRuntime::get();
    if (r.owner != gs || r.finished || (p.tex.psm != 0x13 && p.tex.psm != 0x14) ||
        (p.zbuf & 511) != r.zbp || (p.fbp != 0 && p.fbp != 112) || !p.vertices)
        return;
    float x0 = std::numeric_limits<float>::infinity(), y0 = x0, x1 = -x0, y1 = x1;
    for (unsigned i = 0; i < p.vertices; ++i) {
        const float x = p.x[i] - float(p.ofx) / 16, y = p.y[i] - float(p.ofy) / 16;
        if (!std::isfinite(x) || !std::isfinite(y))
            return;
        x0 = std::min(x0, x);
        x1 = std::max(x1, x);
        y0 = std::min(y0, y);
        y1 = std::max(y1, y);
    }
    if (x1 < 143 || x0 >= 359 || y1 < 0 || y0 >= 130)
        return;
    const double elapsed =
        std::chrono::duration<double>(ClutShadowRuntime::Clock::now() - r.epoch).count();
    if (elapsed < r.at)
        return;
    if (elapsed >= r.at + r.seconds || r.checks >= r.limit) {
        r.end(elapsed, r.checks >= r.limit ? "primitive_cap" : "window");
        return;
    }
    ++r.checks;
    unsigned differences = 0, unknownEntries = 0, invalidLive = 0, first = 0, unknownReason = 0;
    clut_shadow::Selection firstRetained;
    clut_shadow::Raw firstLive;
    uint64_t retainedHash = 14695981039346656037ull, liveHash = retainedHash;
    auto hash = [&](uint64_t& h, uint32_t raw) {
        for (unsigned j = 0; j < 4; ++j)
            h = (h ^ uint8_t(raw >> (j * 8))) * 1099511628211ull;
    };
    const unsigned n = clut_shadow::entries(p.tex);
    for (unsigned i = 0; i < n; ++i) {
        auto cached = r.shadow.select(p.tex, p.origin, i);
        auto live =
            clut_shadow::Shadow::live(p.tex, p.origin, i, ClutShadowReader{vram, size, false});
        if (!cached.raw.valid && !unknownEntries)
            unknownReason = unsigned(cached.reason);
        unknownEntries += !cached.raw.valid;
        invalidLive += !live.valid;
        hash(retainedHash, cached.raw.value);
        hash(liveHash, live.value);
        if (cached.raw.valid && live.valid && cached.raw.value != live.value) {
            if (!differences) {
                first = i;
                firstRetained = cached;
                firstLive = live;
            }
            ++differences;
        }
    }
    r.divergent += differences != 0;
    r.unknown += unknownEntries != 0 || invalidLive != 0;
    // Every selected primitive counts, but only the first and bounded evidence
    // lines print. These are possible palette differences, not sampled-pixel proof.
    if (r.logs < r.logLimit && (r.checks == 1 || differences || unknownEntries || invalidLive)) {
        ++r.logs;
        const auto& load = r.records[firstRetained.loadSerial % r.records.size()];
        const bool loadKnown = load.serial == firstRetained.loadSerial && load.serial != 0;
        std::fprintf(
            stderr,
            "[GS-CLUT-SHADOW] elapsed=%.6f check=%u event_serial=%llu generation=%llu ctx=%u "
            "prim=%u frame=%u/%u/%u/%x zbuf=%llx test=%llx alpha=%llx clamp=%llx cbp=%x cpsm=%u "
            "csm=%u csa=%u cld=%u psm=%u texclut=%u/%u/%u texa=%u/%u/%u bbox=%.3f,%.3f,%.3f,%.3f "
            "entries=%u differing=%u unknown=%u unknown_reason=%u invalid_live=%u "
            "retained_hash=%016llx live_hash=%016llx first=%u retained=%08x live=%08x "
            "load_serial=%llu load_record_known=%u load_cbp=%x load_csm=%u load_csa=%u "
            "retained_source=%x live_source=%x verdict=potential_full_palette_not_used_indices\n",
            elapsed, r.checks, static_cast<unsigned long long>(r.shadow.serial()),
            static_cast<unsigned long long>(r.shadow.generation()), p.context, p.type, p.fbp, p.fbw,
            p.framePsm, p.fbmsk, static_cast<unsigned long long>(p.zbuf),
            static_cast<unsigned long long>(p.test), static_cast<unsigned long long>(p.alpha),
            static_cast<unsigned long long>(p.clamp), p.tex.cbp, p.tex.cpsm, p.tex.csm, p.tex.csa,
            p.tex.cld, p.tex.psm, p.origin.cbw, p.origin.cou, p.origin.cov, p.ta0, p.ta1, p.aem, x0,
            y0, x1, y1, n, differences, unknownEntries, unknownReason, invalidLive,
            static_cast<unsigned long long>(retainedHash),
            static_cast<unsigned long long>(liveHash), first, firstRetained.raw.value,
            firstLive.value, static_cast<unsigned long long>(firstRetained.loadSerial),
            unsigned(loadKnown), loadKnown ? load.tex.cbp : 0, loadKnown ? load.tex.csm : 0,
            loadKnown ? load.tex.csa : 0, firstRetained.sourceOffset, firstLive.offset);
    }
}
uint64_t ps2GsClutShadowStat(unsigned n) {
    if (!clutShadowEnabled())
        return 0;
    const auto& r = ClutShadowRuntime::get();
    return n == 0   ? r.loads
           : n == 1 ? r.divergent
           : n == 2 ? r.unknown
           : n == 3 ? r.checks
                    : r.unknownLoads;
}
// Optional matched-marker hook. Caller must hold the GS worker/state lock.
// Not wired into 0060 capture automatically; it allocates only when requested.
std::string ps2GsClutShadowStateJson(const void* gs) {
    if (!clutShadowEnabled())
        return "{\"enabled\":false}";
    const auto& r = ClutShadowRuntime::get();
    if (r.owner != gs)
        return "{\"owner_known\":false}";
    std::ostringstream o;
    o << "{\"schema\":1,\"finished\":" << r.finished << ",\"serial\":" << r.shadow.serial()
      << ",\"generation\":" << r.shadow.generation();
    auto array = [&](const char* n, const auto& a) {
        o << ",\"" << n << "\":[";
        bool first = true;
        for (const auto v : a) {
            if (!first)
                o << ',';
            first = false;
            o << +v;
        }
        o << ']';
    };
    array("cbp", r.shadow.cbps());
    array("cbp_known", r.shadow.cbpKnown());
    array("raw_words", r.shadow.words());
    array("known", r.shadow.known());
    array("load_serial", r.shadow.loadSerials());
    array("source_offset", r.shadow.sourceOffsets());
    array("load_csm", r.shadow.loadCsms());
    o << ",\"last_reason\":" << unsigned(r.shadow.lastReason())
      << ",\"model_complete_for_all_combinations\":false}";
    return o.str();
}
