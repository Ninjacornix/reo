#pragma once
#include "tools/parallel_gs_backend/resident_geometry/resident_array_owner.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/catalogue_enrollment.hpp"

// Immutable asset transport only. This helper neither calculates graphics nor
// promotes any live proof, registry policy or runtime activation flag.
namespace reo_gpu_static_catalog {
using reo_gpu_catalog::Asset;
struct Assets {
    std::array<Asset, 27> producer{};
    std::array<Asset, 4> consumer{};
    std::array<Asset, 2> exporter{};
    Asset pooledTail{};
};
inline constexpr std::array<const char*, 4> ConsumerHashes{
    "e68b9c2d48ce1c908ffa72183fd98376e158ccd5d4593bfce8309088b03a1b52",
    "97d571bdad6ad73f7c86c9d09504d3edb30dda43f79e51f82905b5cab9ca0264",
    "0b7f9e0e9c940e4165760b4508d4fb8d76c0dbf474d3c8612ff04800bdefd81e",
    "e00ed6e44aabc640d375e55f4652e3a8b1f3899363728e8ba5e976beb4c0466a"};
inline constexpr std::array<const char*, 2> ExportHashes{
    "59d84ef0268e370520360e700b012fd8b080f952eca8de024b613934ba1b119b",
    "cef30ef928f7a1181c5738db4c580f97bcbac7c0555814a15eb9fd55f5796d65"};
inline constexpr const char* PooledTailHash =
    "d6573a4179e53b87959ddaf0aa280b7da0d5302e68051e40758725536135e344";
inline std::vector<uint32_t> module(const std::filesystem::path& directory, const Asset& asset,
                                    const char* expected) {
    if (asset.digest != expected)
        throw std::invalid_argument("Static group asset differs from the proved shader cohort");
    return reo_gpu_catalog::readSpirv(directory, asset);
}
inline void attachPinnedStaticGroupSource(reo_resident_live::ArrayShaderBundle& owner,
                                          const std::filesystem::path& directory,
                                          const Assets& assets,
                                          std::shared_ptr<const reo_resident_live::Program> program,
                                          uint32_t capacity = 128) {
    constexpr uint64_t binding = 0x5273fa3e9893df4bull;
    if (!program || program->bindingId != binding || !capacity || capacity > 128)
        throw std::invalid_argument(
            "Static group requires its bounded immutable registry identity");
    const std::vector<uint8_t> image(program->exactImage.begin(), program->exactImage.end());
    if (reo_gpu_catalog::sha256(image) !=
        "5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25")
        throw std::invalid_argument("Static group source uses a different exact image");
    bool present = false;
    for (const auto& p : owner.programs)
        present |= p.bindingId == binding;
    if (!present || owner.staticGroup.program || owner.staticGroup.activationRequested)
        throw std::invalid_argument(
            "Static group source requires its untouched owner configuration");
    for (const auto& words : owner.staticGroup.modules.producer)
        if (!words.empty())
            throw std::invalid_argument("Static producer source is already configured");
    for (const auto& words : owner.staticGroup.modules.consumer)
        if (!words.empty())
            throw std::invalid_argument("Static consumer source is already configured");
    for (const auto& words : owner.staticGroup.modules.exporter)
        if (!words.empty())
            throw std::invalid_argument("Static exporter source is already configured");
    if (owner.staticGroup.proofs.complete() || owner.staticGroup.exporterProofs.complete())
        throw std::invalid_argument("Asset attachment cannot replace promoted live proofs");
    reo_gpu_static_group::Configuration candidate{};
    candidate.program = std::move(program);
    candidate.capacity = capacity;
    candidate.scope = reo_gpu_static_group::Scope::ScopedLive;
    for (unsigned n = 0; n < 27; ++n)
        candidate.modules.producer[n] =
            module(directory, assets.producer[n], reo_gpu_static_group::StageHashes[n]);
    for (unsigned n = 0; n < 4; ++n)
        candidate.modules.consumer[n] = module(directory, assets.consumer[n], ConsumerHashes[n]);
    for (unsigned n = 0; n < 2; ++n)
        candidate.modules.exporter[n] = module(directory, assets.exporter[n], ExportHashes[n]);
    auto pooled = module(directory, assets.pooledTail, PooledTailHash);
    if (!owner.pooledTail.empty() && owner.pooledTail != pooled)
        throw std::invalid_argument("Static owner pool tail differs from the proved module");
    // Commit after all file/hash/shape validation. Every proof starts false;
    // real source/context/registry closure is required before activation.
    owner.pooledTail = std::move(pooled);
    owner.staticGroup = std::move(candidate);
}
} // namespace reo_gpu_static_catalog
