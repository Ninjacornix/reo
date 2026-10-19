#include "reo_vu_specialized.h"
#include "vu_specialized_route.h"
#include "vu_native_geometry_route.h"
#include <cstdlib>
#include <cstring>
#if defined(REO_HAVE_NATIVE_GEOMETRY) && defined(REO_GAME_FILE1)
#include "reo_vu_native_geometry.h"
#endif

// Root/generator supplies this file in the ignored game-generated candidate.
// Runtime sources and distributed generic patches contain no game code image.
#if defined(REO_HAVE_GENERATED_VU_PROGRAMS) && defined(REO_GAME_FILE1)
#include "reo_vu_specialized_generated.h"
#endif
#if defined(REO_HAVE_WHOLE_VU_PROGRAMS) && defined(REO_GAME_FILE1)
#include "vu_whole_program.h"
#include "reo_vu_whole_registered_generated.h"
#endif

// Whole-program AOT (tools/vu_whole_aot) covers images that have no specialized/native table.
// Opt-in (REO_VU_WHOLE=1): 2026-10-18 A/B gave no measurable room speed gain (20.13 on vs 20.18 off
// updates/s), and only 2 of its programs have byte-parity oracle proof. REO_VU_SPECIALIZED=0 also disables it.
static void reoRegisterVuWholePrograms(bool enabled) noexcept {
#if defined(REO_HAVE_WHOLE_VU_PROGRAMS) && defined(REO_GAME_FILE1)
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
#if defined(REO_HAVE_GENERATED_VU_PROGRAMS) && defined(REO_GAME_FILE1)
    const auto* legacy = reo_vu_specialized_generated::programTable();
    if (!vu_specialized::registerProgramTable(legacy)) {
        vu_native_geometry::registerProgramTable(nullptr);
        return false;
    }
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
