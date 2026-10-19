#pragma once
#include "hybrid_catalogue.hpp"
// Root's immutable packager replaces this private header only after review.
// Merely copying the source installer/helper never enables geometry.
namespace reo_gpu_mixed_selected {
inline constexpr bool ready = false;
inline constexpr const char* packageDigest = "";
inline constexpr const char* evidenceDigest = "";
inline constexpr const char* reviewDigest = "";
inline reo_gpu_mixed_catalog::Assets assets() {
    return {};
}
inline reo_gpu_mixed_catalog::Proofs proofs() {
    return {};
}
} // namespace reo_gpu_mixed_selected
