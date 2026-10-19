#pragma once
#include "catalogue_enrollment.hpp"
#include "resident_array_owner.hpp"

namespace reo_gpu_catalog {
// Explicit incremental selection. The other seven images remain unadmitted.
// Numerical reference: retained ordinal672, operation4, full632/16384 bytes
// and all nine raw packets, plus the original134-case staged-static proof.
// GS consumer/tail reference: owner-fixture5's actual-device render controls.
inline void configureStaticIncremental(Bootstrap& bootstrap,
                                       const std::filesystem::path& directory) {
    constexpr uint64_t binding = 0x5273fa3e9893df4bull;
    if (!bootstrap.readyToInstall || !bootstrap.registry || bootstrap.registry->complete() ||
        !bootstrap.registry->perProgramAdmission || !bootstrap.registry->allowIncrementalFallback)
        throw std::invalid_argument(
            "Static multi-effect selection requires the explicit incremental registry");
    auto registry = std::make_shared<reo_resident_live::Registry>(*bootstrap.registry);
    auto found = std::find_if(registry->programs.begin(), registry->programs.end(),
                              [](const auto& p) { return p->bindingId == binding; });
    if (found == registry->programs.end() || !(*found)->complete() || !(*found)->gpuAdmitted)
        throw std::invalid_argument("Static multi-effect selection lacks its admitted exact image");
    auto selected = std::make_shared<reo_resident_live::Program>(**found);
    if (sha256(std::vector<uint8_t>(selected->exactImage.begin(), selected->exactImage.end())) !=
        "5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25")
        throw std::invalid_argument("Static multi-effect image differs");
    // This owner uses the pinned literal-source-guarded legacy module and
    // the multi-event producer's pre-publication raw command verification.
    // Neither capability widens entry coverage or admits another image.
    selected->literalSourcePreserved = true;
    *found = selected;
    reo_resident_live::ArrayShaderBundle owner{};
    owner.whole2ea = bootstrap.shaders.whole2ea;
    owner.whole2eaBinding = bootstrap.shaders.whole2eaBinding;
    owner.programs = bootstrap.shaders.programs;
    auto module = std::find_if(owner.programs.begin(), owner.programs.end(),
                               [](const auto& p) { return p.bindingId == binding; });
    if (module == owner.programs.end())
        throw std::invalid_argument("Static module not registered");
    std::vector<uint8_t> moduleBytes(module->spirv.size() * 4);
    std::memcpy(moduleBytes.data(), module->spirv.data(), moduleBytes.size());
    if (sha256(moduleBytes) != "96a5c431ebb432e8cc48e529a3a83250ea183b2e75abb55322df874b64f0828b")
        throw std::invalid_argument("Static literal-source module differs from the proven binary");
    module->freshLiteralSourcePreserved = true;
    module->resumeLiteralSourcePreserved = true;
    owner.strip = bootstrap.shaders.strip;
    owner.unpack = bootstrap.shaders.unpack;
    owner.effectValidate = bootstrap.shaders.effectValidate;
    owner.bytePatch = bootstrap.shaders.bytePatch;
    const auto load = [&](const char* name, const char* digest) {
        return readSpirv(directory, {std::string("multi-effect/") + name, digest});
    };
    owner.pooledTail =
        load("pooled_tail.spv", "d6573a4179e53b87959ddaf0aa280b7da0d5302e68051e40758725536135e344");
    auto& multi = owner.multiEffect;
    multi.activationRequested = true;
    multi.binding = binding;
    multi.family = 0x5273fa3e;
    multi.exactImage = selected->exactImage;
    multi.pooledTail = owner.pooledTail;
    multi.producer = load("static_fallback.spv",
                          "4c9cfae68392d1887b72f338ed3216d19976c85522a2c81b312d097407095fe8");
    multi.admission = load("live_authority_admission.spv",
                           "9aa8aeabe44b61e9db1a90be68c6e538c657d4bc084a3ebd3913f21a97e5862d");
    multi.commit = load("live_authority_commit.spv",
                        "2f06b7c7bb503a3f2e6742c80f2b58034de410da2b51834e6635a1b37f909933");
    multi.fastProducer = {
        load("static_prefix.spv",
             "ea3c2dbf6dcafee443aa7660825b7957e76021675aa776108d2c74be8e422a13"),
        load("static_geometry.spv",
             "91009cf10f1ccea48ff8ca6632cf6b1575dbac08c6a413ccbbfd95eb13822b53"),
        load("static_clip.spv", "48f670f133c20c69ecd0d5d625029c6970cb9bddf61bbe3d9a474d6ae40dd693"),
        load("static_compose.spv",
             "8e8d45042f4572e2e0ba18f7b0a942605d1c7afc7ea08d1e7aa16873487502e1"),
        load("static_fallback_selected.spv",
             "939532dd9ef1b995cfd52d7775727e0746823f171f0bc5668d7e078f3f1a489b")};
    if (const char* fused = std::getenv("REO_GPU_FUSED_STATIC"); fused && fused[0] == '1')
        multi.fusedProducer = load(
            "static_fused.spv", "da3aa2609d1a96a2e560f46e9eb653cf0b0f683490da15fb7c8b7404ea5c79aa");
    if (const char* pipeline = std::getenv("REO_GPU_STATIC_PIPELINE");
        pipeline && pipeline[0] == '1')
        multi.fusedPipeline =
            load("static_pipeline.spv",
                 "553797bf7831b8f6061b981152f247356c9998733c9a2e45f6a3cf0453b4761e");
    multi.consumer = {
        load("validate_tape.spv",
             "4ab8d8a72fb2bb3956354c7285efcbf837e7c3006be00f4b4668c0c67cd58865"),
        load("expand_tape.spv", "9f0c8768764b2499d371cfd9cd2180e2ad093af6e56b5410797b3045c62ec500"),
        load("seal_consumer.spv",
             "bde17cadea8ad94bc24eca25e500937b73a644c9073a064ecc34d70057a979d5"),
        load("publication_gate.spv",
             "c14d243425a4d796e0a89524f9820f4ff03995ed65d70b4abc9f5936a3bfbd10")};
    auto configuration = reo_resident_live::makeArrayResidentOwnerConfig(std::move(owner));
    configuration.enabled = bootstrap.owner.enabled;
    configuration.fullProtocolCoverage = bootstrap.owner.fullProtocolCoverage;
    bootstrap.registry = std::move(registry);
    bootstrap.owner = std::move(configuration);
}
} // namespace reo_gpu_catalog
