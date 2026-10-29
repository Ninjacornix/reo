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

// Exact room variants with replay and live-route validation run compiled by default.
// REO_VU_WHOLE=1 also admits the experimental catalogue; 0 disables both tables.
// Old generated factories without a default table retain their opt-in behavior.
static void reoRegisterVuWholePrograms(bool enabled) noexcept {
#if defined(REO_HAVE_WHOLE_VU_PROGRAMS) && (defined(REO_GAME_FILE1) || defined(REO_GAME_FILE2))
    const char* flag = std::getenv("REO_VU_WHOLE");
    const vu_whole_program::Table* table = nullptr;
    if (enabled) {
        if (flag && std::strcmp(flag, "1") == 0)
            table = reo_vu_whole_registered_generated::programTable();
#if defined(REO_VU_HAS_DEFAULT_PROGRAM_TABLE)
        else if (!flag)
            table = reo_vu_whole_registered_generated::defaultProgramTable();
#endif
    }
    const bool registered = vu_whole_program::registerProgramTable(table);
    std::fprintf(stderr, "[VU-WHOLE] mode=%s programs=%u registered=%u\n",
                 flag ? (std::strcmp(flag, "1") == 0 ? "all" : "disabled") : "default",
                 table ? table->count : 0u, unsigned(registered));
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
