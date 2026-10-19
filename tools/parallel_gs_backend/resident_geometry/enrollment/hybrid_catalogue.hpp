#pragma once
// Private composition only. All proof values come from a reviewed exact
// catalogue package; this file neither manufactures nor promotes them.
#include "catalogue_enrollment.hpp"
#include "boundary_config.hpp"

namespace reo_gpu_mixed_catalog {
using reo_gpu_catalog::Asset;
struct Assets {
    // Exact order below; all eight-SSBO/push16 modules are immutable.
    std::array<Asset, 14> ordered;
    Asset guardedExport;
    std::array<Asset, 8> boundary;
    Asset boundaryPrepare, boundaryCommit;
};
struct Proofs {
    reo_gpu_array_bridge::Proofs ordered{};
    reo_gpu_boundary::Proofs boundary{};
};
inline constexpr std::array<const char*, 14> OrderedNames{
    "tape_validate",   "provenance_clear", "provenance_scatter", "row_versions",
    "prefix_prepare",  "geometry_mode1",   "geometry_mode2",     "packet_compose",
    "rigid_stq_carry", "history_resolve",  "terminal_mode1",     "terminal_mode2",
    "carry_fixup",     "event_certify"};
// Exact sparse/terminal module cohort is populated only after peer freeze.
inline constexpr std::array<const char*, 14> OrderedSHA256{
    "64ee33aa971d285377143b24347d7967cbb9940c04ffe8c543d7d829fac401c4",
    "6aa262b04c3bbebe7132cde2004bb0e11f9103646b174bf9f0a86e4f120ca121",
    "96a751c174cd96b31b0306e46175741f5ec4278bac3fd8717daa2c8107496c01",
    "a8eba0ac27a77f2fbba18955a48589eff33f623225adb3088a0c27e0968dcb38",
    "ceb16be23f8afaaace7866817c5d3a7127f78930029f30b8685464c341961992",
    "e33c448cefae9f28a4fddf0812ca3078d40f91284db5400f725ef06b16a5ae81",
    "c01dd066a6193c4b706333676cb7fe775a6559cb364f70ba86c17153e6348ee3",
    "2028f539a0943beccc856d9dccc2801d85e6bda97c1b9526cb2e14f3350edea4",
    "c21cdb45f86d03a5f86f360aa875af6aa121cfc4deb86cbba58946916b0e3ab6",
    "984de27194ae69546a3898bcdfc21fa2efb306318db996f857a9d75f305ba291",
    "e1020a895a9194c2760926e7a1abe74d6a5c2ef5895164dfbce9f3183806300a",
    "cbe5f71fa3b9ae2c863c981f9662bc449ac281c33badec52e7c22e147f2ebfbe",
    "1023d9e6ad50ee5776389b87950d6d2865c43e0f8b972803ac60a903c35a6fb7",
    "289c0d8987bcedfe584d2004d132249cdbf23f3826ac7661e02ee991eaed7de7"};
inline constexpr const char* ExportSHA256 =
    "a1ea13571ff1d7f0702523103f33f0cdb89bde3ad702f91e1530be131c604312";
inline constexpr const char* PrepareSHA256 =
    "20cca747a0f64979adf1aa059986cf5c22650d8379eccf8d319536c2035bd4f4";
inline constexpr const char* CommitSHA256 =
    "6c2529a95dfa43fe8708d9b52a34119ae17d1ffe3f54d6788fbc0255cc0c4b8b";
inline std::vector<uint32_t> readModule(const std::filesystem::path& directory, const Asset& asset,
                                        const char* expected) {
    if (asset.digest != expected)
        throw std::invalid_argument(
            "Mixed owner module differs from selected sparse-prefix-checkpoint/B source cohort");
    return reo_gpu_catalog::readSpirv(directory, asset);
}
struct Modules {
    reo_gpu_array_bridge::Bundle ordered;
    reo_gpu_boundary::Bundle boundary;
};
inline Modules load(const std::filesystem::path& directory, const Assets& assets,
                    const std::array<uint8_t, 16384>& exactImage, const Proofs& proof) {
    Modules out{};
    out.ordered.exactImageBinding = out.boundary.exactImageBinding = 0x2ea02b3628231f11ull;
    out.ordered.exactImage = out.boundary.exactImage = exactImage;
    for (size_t i = 0; i < OrderedNames.size(); ++i) {
        const auto role = i < 5    ? reo_gpu_array_bridge::StageRole::InputSnapshot
                          : i == 8 ? reo_gpu_array_bridge::StageRole::RigidStqCarry
                          : (i == 7 || i == 9 || i == 12 || i == 13)
                              ? reo_gpu_array_bridge::StageRole::OrderedCompose
                              : reo_gpu_array_bridge::StageRole::Geometry;
        const auto grid = i == 0   ? reo_gpu_array_bridge::Dispatch::One
                          : i == 1 ? reo_gpu_array_bridge::Dispatch::SparseTreeClear
                          : i == 2 ? reo_gpu_array_bridge::Dispatch::SparseEventScatter
                          : i == 3 ? reo_gpu_array_bridge::Dispatch::SparseRowSnapshots
                                   : reo_gpu_array_bridge::Dispatch::PerJob;
        out.ordered.orderedStages.push_back(
            {OrderedNames[i], readModule(directory, assets.ordered[i], OrderedSHA256[i]), role,
             grid});
    }
    out.ordered.guardedExport = readModule(directory, assets.guardedExport, ExportSHA256);
    for (size_t i = 0; i < out.boundary.stages.size(); ++i)
        out.boundary.stages[i] =
            readModule(directory, assets.boundary[i], reo_gpu_boundary::StageSHA256[i]);
    out.boundary.prepare = readModule(directory, assets.boundaryPrepare, PrepareSHA256);
    out.boundary.commit = readModule(directory, assets.boundaryCommit, CommitSHA256);
    out.ordered.proofs = proof.ordered;
    out.boundary.proofs = proof.boundary;
    // Constructor flags reflect only their existing exact scoped proof sets.
    out.ordered.activationRequested = proof.ordered.complete();
    out.boundary.activationRequested = proof.boundary.complete();
    return out;
}
// Compile extra stages on the actual GS-owned Device, alongside the existing
// complete scalar catalogue/auxiliary prewarm. No descriptors or bank mutation.
inline void prewarm(Vulkan::Device& device, const Modules& modules) {
    auto cmd = device.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
    if (!cmd)
        throw std::runtime_error("Mixed owner prewarm command allocation failed");
    auto compile = [&](const std::vector<uint32_t>& code) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Invalid mixed prewarm shader");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0xffu;
        for (unsigned b = 0; b < 8; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = 16;
        auto* program = device.request_program(code.data(), code.size() * 4, &layout);
        if (!program || !program->get_pipeline_layout())
            throw std::runtime_error("Mixed prewarm program creation failed");
        cmd->set_program(program);
        Vulkan::DeferredPipelineCompile state{};
        cmd->extract_pipeline_state(state);
        auto pipeline = program->get_pipeline(state.hash);
        if (pipeline.pipeline == VK_NULL_HANDLE)
            pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                &device, state, Vulkan::CommandBuffer::CompileMode::Sync);
        if (pipeline.pipeline == VK_NULL_HANDLE)
            throw std::runtime_error("Mixed prewarm driver compile failed");
    };
    for (const auto& stage : modules.ordered.orderedStages)
        compile(stage.spirv);
    compile(modules.ordered.guardedExport);
    for (const auto& code : modules.boundary.stages)
        compile(code);
    compile(modules.boundary.prepare);
    compile(modules.boundary.commit);
    device.submit(cmd); // Empty semantic command stream; recycles same-Device command buffer.
}
inline reo_gpu_catalog::Bootstrap build(const std::filesystem::path& directory,
                                        const reo_gpu_catalog::CatalogAssets& catalogue,
                                        const reo_gpu_catalog::Proofs& catalogueProof,
                                        const Assets& assets, const Proofs& proof = {}) {
    // These choices match the scoped ledger's fresh parallel5/resume generic4
    // contracts. A fresh generic capacity echo cannot silently admit zero mixed jobs.
    if (catalogue.kernels[0].kind != reo_gpu_catalog::KernelKind::ParallelV5Literal ||
        catalogue.kernels[0].resumeKind != reo_gpu_catalog::KernelKind::GenericV4Literal ||
        catalogue.kernels[0].resumeSpirv.digest.empty())
        throw std::invalid_argument(
            "Mixed composition requires selected literal parallel5 fresh and generic4 resume2EA");
    auto out = reo_gpu_catalog::build(directory, catalogue, catalogueProof);
    if (!out.registry || out.registry->programs.size() != 8 ||
        out.registry->programs[0]->bindingId != 0x2ea02b3628231f11ull)
        throw std::invalid_argument(
            "Mixed composition requires complete exact eight-image catalogue");
    const auto& image = out.registry->programs[0]->exactImage;
    auto modules = load(directory, assets, image, proof);
    const bool ready = out.readyToInstall && proof.ordered.complete() && proof.boundary.complete();
    if (ready && (!out.registry->programs[0]->canResume ||
                  !out.registry->programs[0]->literalSourcePreserved))
        throw std::runtime_error(
            "Reviewed mixed scope requires existing2EA fresh/resume literal guard capabilities");
    auto config = reo_resident_live::makeHybridArrayOwnerConfig(out.shaders, modules.ordered,
                                                                modules.boundary);
    auto instantiate = config.factory;
    auto selected = std::make_shared<const reo_resident_live::ShaderBundle>(out.shaders);
    auto selectedModules = std::make_shared<const Modules>(std::move(modules));
    config.factory = [instantiate, selected, selectedModules](Vulkan::Device& device,
                                                              ParallelGS::GSInterface& gs) {
        reo_gpu_catalog::prewarm(device, *selected);
        prewarm(device, *selectedModules);
        return instantiate(device, gs);
    };
    out.readyToInstall = ready;
    config.enabled = ready;
    config.fullProtocolCoverage = ready;
    out.owner = std::move(config);
    return out;
}
} // namespace reo_gpu_mixed_catalog
