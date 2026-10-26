#include "reo_vu_specialized.h"
#include "vu_specialized_route.h"
#include "vu_native_geometry_route.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#if defined(REO_HAVE_NATIVE_GEOMETRY) && (defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2))
#include "reo_vu_native_geometry.h"
#endif

// Root/generator supplies this file in the ignored game-generated candidate.
// Runtime sources and distributed generic patches contain no game code image.
#if defined(REO_HAVE_GENERATED_VU_PROGRAMS) && (defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2))
#include "reo_vu_specialized_generated.h"
#endif
#if defined(REO_HAVE_WHOLE_VU_PROGRAMS) && (defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2))
#include "vu_whole_program.h"
#include "reo_vu_whole_registered_generated.h"
#endif

// Whole-program AOT (tools/vu_whole_aot) covers images that have no specialized/native table.
// Opt-in (REO_VU_WHOLE=1): 2026-10-18 A/B gave no measurable room speed gain (20.13 on vs 20.18 off
// updates/s), and only 2 of its programs have byte-parity oracle proof. REO_VU_SPECIALIZED=0 also disables it.
static void reoRegisterVuWholePrograms(bool enabled) noexcept {
#if defined(REO_HAVE_WHOLE_VU_PROGRAMS) && (defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2))
    const char* flag = std::getenv("REO_VU_WHOLE");
    if (!(flag && std::strcmp(flag, "1") == 0))
        enabled = false;
    vu_whole_program::registerProgramTable(
        enabled ? reo_vu_whole_registered_generated::programTable() : nullptr);
#else
    (void)enabled;
#endif
}

bool reoRegisterVuSpecializedPrograms() noexcept {
    const char* master = std::getenv("REO_VU_SPECIALIZED");
    reoRegisterVuWholePrograms(!(master && std::strcmp(master, "0") == 0));
    if (master && std::strcmp(master, "0") == 0) {
        vu_native_geometry::registerProgramTable(nullptr);
        return vu_specialized::registerProgramTable(nullptr);
    }
#if defined(REO_HAVE_GENERATED_VU_PROGRAMS) && (defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2))
    const auto* legacy = reo_vu_specialized_generated::programTable();
    // The VU bank can retain room/effect uploads after the canonical geometry
    // image. Only blocks and native loops fully covered by this checked prefix
    // may run compiled; every other instruction still reads the live bank.
    // A longer canonical image simply extends the required comparison.
    uint32_t extent = 8u;
    if (!legacy || !legacy->programs || !legacy->count || legacy->count>64u) return false;
    for (uint32_t n=0;n<legacy->count;++n) {
        const auto& program=legacy->programs[n];
        if (!program.exactCodeImage || program.codeBytes<8u || program.codeBytes>16384u) return false;
        uint32_t end=program.codeBytes;
        while (end && !program.exactCodeImage[end-1u]) --end;
        const uint32_t aligned=(end+7u)&~7u;
        if (aligned>extent) extent=aligned;
    }
    const bool exactBank = std::getenv("REO_VU_EXACT_BANK") != nullptr;
    const bool registered = exactBank
        ? vu_specialized::registerProgramTable(legacy)
        : vu_specialized::registerProgramTableCodeExtent(legacy,extent);
    if (!registered) {
        vu_native_geometry::registerProgramTable(nullptr);
        return false;
    }
    std::fprintf(stderr,"[VU-CODE-COVERAGE] compared_bytes=%u full_bank=%u\n",
                 exactBank && legacy && legacy->count ? legacy->programs[0].codeBytes : extent,
                 unsigned(exactBank));
#if defined(REO_HAVE_NATIVE_GEOMETRY)
    return reoRegisterNativeGeometryPrograms(legacy);
#else
    vu_native_geometry::registerProgramTable(nullptr);
    return true;
#endif
#else
    vu_native_geometry::registerProgramTable(nullptr);
    return false; // Skeleton has no specialization: retain the original interpreter.
#endif
}
