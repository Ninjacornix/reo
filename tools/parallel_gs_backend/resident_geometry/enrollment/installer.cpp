#include "installer.hpp"
#include "parallel_backend.h"
#include "enrollment_selected.hpp"
#include "mixed_selected.hpp"
#include "first_entry_selected.hpp"
#include "static_incremental.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace reo_gpu_enrollment {
void configureBeforeBoot(reo_parallel_backend::Config& config,
                         const std::filesystem::path& applicationDirectory, const char* serial,
                         PS2Runtime* actualRuntime) {
    const char* request = std::getenv("REO_VIF1_GPU_RESIDENT");
    const char* firstEntry = std::getenv("REO_GPU_FIRST_ENTRY_AUDIT");
    // TEMPORARY diagnostic for the incremental plumbing trial: prove which environment
    // the live game process observes. Remove after the env/code-path question is settled.
    std::fprintf(stderr, "[GPU-ENROLL-DIAG] request=%s firstEntry=%s\n",
                 request ? request : "(null)", firstEntry ? firstEntry : "(null)");
    if (firstEntry && firstEntry[0] && (!request || request[0] != '1'))
        throw std::runtime_error(
            "Bounded native first-entry audit also requires the explicit resident backend request");
    if (!request || request[0] != '1')
        return;
    if (!serial || std::strcmp(serial, "SLUS-20765"))
        throw std::runtime_error("Selected GPU geometry registry belongs to Outbreak File1");
    const char* mixedRequest = std::getenv("REO_VIF1_GPU_MIXED_OWNER");
    const bool mixed = mixedRequest && std::strcmp(mixedRequest, "1") == 0;
    const char* backend = std::getenv("REO_GS_BACKEND");
    const char* thread = std::getenv("REO_GS_THREAD");
    const char* legacy = std::getenv("REO_GFX");
    if (!backend || std::strcmp(backend, "parallel") || (thread && thread[0] == '0') ||
        (legacy && !std::strcmp(legacy, "bridge")) || !config.validatedDrawing)
        throw std::runtime_error(
            "Resident geometry requires the validated parallel GS owner and GS worker");
    if (firstEntry && firstEntry[0]) {
        if (!actualRuntime || mixed || !reo_gpu_first_entry_selected::BoundedAssetPackagePinned)
            throw std::runtime_error("Bounded native first-entry audit requires its actual Runtime "
                                     "and separate pinned package");
        reo_gpu_upstream::FirstEntryPackage selected;
        if (!std::strcmp(firstEntry, "setter5a"))
            selected = reo_gpu_upstream::FirstEntryPackage::Setter5A;
        else if (!std::strcmp(firstEntry, "state197900"))
            selected = reo_gpu_upstream::FirstEntryPackage::StatePacket197900;
        else
            throw std::invalid_argument("Unknown bounded native graphics entry package");
        const char* overrideFirst = std::getenv("REO_GPU_FIRST_ENTRY_ASSET_DIR");
        const auto firstDirectory = overrideFirst ? std::filesystem::u8path(overrideFirst)
                                                  : applicationDirectory / "reo-gpu-first-entry";
        reo_gpu_catalog::readPinned(firstDirectory, {"first-entry-package.json",
                                                     reo_gpu_first_entry_selected::packageDigest});
        // Only immutable assets are loaded here; no Runtime RAM/code-image
        // snapshot or numerical cold seed is read before the real EntryScope.
        auto catalogue = reo_gpu_catalog::build(
            firstDirectory, reo_gpu_first_entry_selected::catalogueAssets(), {});
        auto first = reo_gpu_upstream::FirstEntryFactory::build(
            *actualRuntime, catalogue, {firstDirectory / "parent", firstDirectory / "upstream"},
            selected);
        first.installBeforeBoot(config.residentGeometry);
        std::fprintf(stderr,
                     "[GPU-FIRST-ENTRY] bounded native audit armed package=%s images=8 "
                     "full_selection=0 module_prewarm=before_guest manifest=%s\n",
                     firstEntry, reo_gpu_first_entry_selected::packageDigest);
        return;
    }
    if (mixed && !reo_gpu_mixed_selected::ready)
        throw std::runtime_error(
            "Mixed owner requested without pinned reviewed sparse-prefix-checkpoint/B enrollment");
    if (!reo_gpu_enrollment_selected::ready)
        throw std::runtime_error("GPU geometry requested without a complete pinned "
                                 "image/entry/operation enrollment package");
#ifndef REO_GPU_CATALOG_LITERAL_REUSE
    if (reo_gpu_enrollment_selected::usesLiteralReuse)
        throw std::runtime_error(
            "Selected guarded kernels require the matching private literal reuse ABI");
#endif
    const char* overrideDirectory = std::getenv("REO_VIF1_GPU_ASSET_DIR");
    const auto directory = overrideDirectory ? std::filesystem::u8path(overrideDirectory)
                                             : applicationDirectory / "reo-gpu-geometry";
    // Metadata itself is pinned into this TU; swapping another package while
    // preserving the assets cannot silently change the evidence or root review.
    reo_gpu_catalog::readPinned(directory,
                                {"package.json", reo_gpu_enrollment_selected::packageDigest});
    reo_gpu_catalog::readPinned(directory,
                                {"evidence.json", reo_gpu_enrollment_selected::evidenceDigest});
    reo_gpu_catalog::readPinned(directory,
                                {"root-review.json", reo_gpu_enrollment_selected::reviewDigest});
    if (mixed) {
        reo_gpu_catalog::readPinned(directory,
                                    {"mixed-package.json", reo_gpu_mixed_selected::packageDigest});
        reo_gpu_catalog::readPinned(
            directory, {"mixed-evidence.json", reo_gpu_mixed_selected::evidenceDigest});
        reo_gpu_catalog::readPinned(
            directory, {"mixed-root-review.json", reo_gpu_mixed_selected::reviewDigest});
    }
    auto bootstrap =
        mixed ? reo_gpu_mixed_catalog::build(directory, reo_gpu_enrollment_selected::assets(),
                                             reo_gpu_enrollment_selected::proofs(),
                                             reo_gpu_mixed_selected::assets(),
                                             reo_gpu_mixed_selected::proofs())
              : reo_gpu_catalog::build(directory, reo_gpu_enrollment_selected::assets(),
                                       reo_gpu_enrollment_selected::proofs());
    if (!bootstrap.readyToInstall)
        throw std::runtime_error(
            "GPU geometry enrollment fails the complete owner/registry contract");
    const char* staticMulti = std::getenv("REO_GPU_STATIC_MULTI");
    if (staticMulti && std::strcmp(staticMulti, "1") == 0) {
        if (mixed)
            throw std::invalid_argument(
                "Static incremental and full mixed-owner selections are separate");
        reo_gpu_catalog::configureStaticIncremental(bootstrap, directory);
        std::fprintf(stderr, "[GPU-GEOMETRY] static multi-packet owner selected; other images "
                             "remain CPU fallback\n");
    }
    // prewarm runs inside this factory, using the SAME Device owned by the
    // backend. Registration only publishes immutable raw identities/metadata.
    config.residentGeometry = bootstrap.owner;
    reo_gpu_catalog::installBeforeBoot(bootstrap);
    std::fprintf(stderr, "[GPU-GEOMETRY] pinned full registry installed: images=8 manifest=%s\n",
                 reo_gpu_enrollment_selected::packageDigest);
    if (mixed)
        std::fprintf(stderr,
                     "[GPU-GEOMETRY] mixed sparse-prefix-checkpoint/B owner selected: "
                     "stages=14+export boundaries=8+prepare+commit manifest=%s\n",
                     reo_gpu_mixed_selected::packageDigest);
}
} // namespace reo_gpu_enrollment
