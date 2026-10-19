#pragma once
#include "resident_parallel_owner.hpp"
#include "resident_vif_live_hooks.h"
#include "literal_command_provenance.h"
#include "sha256.hpp"
#include <array>
#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <set>
#include <string>
#include <utility>

namespace reo_gpu_catalog {
enum class KernelKind {
    GenericV3,
    GenericV4Refined,
    ParallelV4,
    ParallelV5Refined,
    GenericV4Literal,
    ParallelV5Literal,
    ParallelWeightedV6
};
struct ImageSpec {
    const char* digest;
    uint64_t bindingId;
    std::vector<uint32_t> freshEntries;
};
// Generated independently from the immutable reached-image census. Byte PCs,
// never MPG upload offsets or VIF immediate instruction indices.
#include "catalogue_specs.inl"
struct Asset {
    std::string relativePath, digest;
};
struct KernelAsset {
    Asset image, spirv, resumeSpirv;
    KernelKind kind = KernelKind::GenericV3, resumeKind = KernelKind::GenericV4Refined;
};
struct CatalogAssets {
    std::array<KernelAsset, 8> kernels;
    // strip, raw UNPACK, effect validator, raw byte patch (in this order).
    std::array<Asset, 4> auxiliary;
};
struct ProgramProof {
    bool completeSetup = false, completeGeometry = false, completeClipping = false;
    bool completeCarry = false, orderedEffects = false, exactTermination = false;
    bool retainedFullCallParity = false, liveFreshEntryCoverage = false;
    bool residentResumeParity = false;
    bool freshLiteralSourcePreserved = false, resumeLiteralSourcePreserved = false;
    // Explicit per-program GPU launch admission: claims genuine RETAINED-COLD
    // DEVICE parity evidence for the pinned kernel against an independent
    // gold, restricted to the listed fresh entry PCs (always a subset of the
    // census freshEntries and never PC 0 without its own device cases).
    bool gpuLaunchAdmitted = false;
    std::vector<uint32_t> admittedFreshPCs;
    bool complete() const noexcept {
        return completeSetup && completeGeometry && completeClipping && completeCarry &&
               orderedEffects && exactTermination && retainedFullCallParity &&
               liveFreshEntryCoverage;
    }
};
struct Proofs {
    std::array<ProgramProof, 8> programs{};
    bool fullReachedRegistry = false, mappedBankCoherence = false, gpuLiteralEffects = false;
    bool literalPoliciesCertified = false, ownerProtocolCertified = false;
    // Opts the selected package into explicit incremental enrollment (see
    // Registry::allowIncrementalFallback). Only the packager sets this, never
    // by default.
    bool incrementalEnrollment = false;
    // Opts the incremental package into per-program launch admission (see
    // Registry::perProgramAdmission). Only the packager sets this, never by
    // default, and it never relaxes the per-image proof requirements.
    bool perProgramAdmission = false;
};
inline std::vector<uint8_t> readPinned(const std::filesystem::path& directory, const Asset& asset) {
    const std::filesystem::path relative(asset.relativePath);
    if (relative.empty() || relative.is_absolute() || asset.digest.size() != 64)
        throw std::invalid_argument("Missing immutable GPU catalogue asset identity");
    for (const auto& element : relative)
        if (element == "..")
            throw std::invalid_argument("Invalid catalogue asset path");
    std::ifstream stream(directory / relative, std::ios::binary);
    if (!stream)
        throw std::runtime_error("Missing immutable GPU catalogue asset: " + asset.relativePath);
    std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(stream)),
                               std::istreambuf_iterator<char>());
    if (!stream.eof() && !stream.good())
        throw std::runtime_error("Incomplete GPU catalogue asset read");
    if (bytes.empty() || sha256(bytes) != asset.digest)
        throw std::runtime_error("GPU catalogue asset SHA256 mismatch: " + asset.relativePath);
    return bytes;
}
inline std::vector<uint32_t> readSpirv(const std::filesystem::path& directory, const Asset& asset) {
    auto raw = readPinned(directory, asset);
    if ((raw.size() & 3) || raw.size() < 20)
        throw std::invalid_argument("Incomplete GPU catalogue SPIR-V");
    std::vector<uint32_t> words(raw.size() / 4);
    std::memcpy(words.data(), raw.data(), raw.size());
    if (words[0] != 0x07230203)
        throw std::invalid_argument("GPU catalogue SPIR-V header mismatch");
    return words;
}
inline bool generic(KernelKind kind) {
    return kind == KernelKind::GenericV3 || kind == KernelKind::GenericV4Refined ||
           kind == KernelKind::GenericV4Literal;
}
struct PrewarmResult {
    uint64_t bindingId = 0;
    double hostCompileMilliseconds = 0;
    bool resumeModule = false;
};
inline std::vector<PrewarmResult> prewarm(Vulkan::Device&, const reo_resident_live::ShaderBundle&);
struct Bootstrap {
    std::shared_ptr<const reo_resident_live::Registry> registry;
    reo_resident_live::ShaderBundle shaders;
    reo_resident_live::OwnerConfig owner;
    bool readyToInstall = false;
};
inline Bootstrap build(const std::filesystem::path& assetDirectory, const CatalogAssets& assets,
                       const Proofs& proof = {}) {
    Bootstrap out;
    auto registry = std::make_shared<reo_resident_live::Registry>();
    std::set<uint64_t> ids;
    const auto specifications = imageSpecs();
    for (size_t i = 0; i < specifications.size(); ++i) {
        const auto& specification = specifications[i];
        const auto& asset = assets.kernels[i];
        if (!specification.bindingId || !ids.insert(specification.bindingId).second ||
            asset.image.digest != specification.digest)
            throw std::invalid_argument("GPU catalogue binding/image mismatch");
        if (!generic(asset.kind) && i != 0)
            throw std::invalid_argument("Parallel2EA selected for another exact image");
        const bool separateResume = !asset.resumeSpirv.digest.empty();
        if (separateResume &&
            (!generic(asset.resumeKind) || asset.resumeSpirv.relativePath.empty()))
            throw std::invalid_argument(
                "Resume module must be a pinned complete generic operation4 kernel");
        if (!generic(asset.kind) && !separateResume && proof.programs[i].residentResumeParity)
            throw std::invalid_argument(
                "Parallel2EA MSCNT requires a separate generic resume module");
        if (proof.perProgramAdmission && !proof.incrementalEnrollment)
            throw std::invalid_argument(
                "Per-program launch admission requires explicit incremental enrollment");
        if (proof.perProgramAdmission && !proof.programs[i].gpuLaunchAdmitted &&
            !proof.programs[i].admittedFreshPCs.empty())
            throw std::invalid_argument("Admission PCs declared without a device evidence claim");
        auto image = readPinned(assetDirectory, asset.image);
        if (image.size() != reo_resident_live::CodeBytes)
            throw std::invalid_argument("GPU catalogue image must be full16KiB");
        auto program = std::make_shared<reo_resident_live::Program>();
        std::memcpy(program->exactImage.data(), image.data(), image.size());
        program->bindingId = specification.bindingId;
        program->startPCs = specification.freshEntries;
        const auto& p = proof.programs[i];
        const bool complete = p.complete();
        program->completeSetup = complete && p.completeSetup;
        program->completeGeometry = complete && p.completeGeometry;
        program->completeClipping = complete && p.completeClipping;
        program->completeCarry = complete && p.completeCarry;
        program->orderedEffects = complete && p.orderedEffects;
        program->exactTermination = complete && p.exactTermination;
        program->canResume =
            complete && (generic(asset.kind) || separateResume) && p.residentResumeParity;
        // Per-program launch admission: only a fully proven program with the
        // packager's device-evidence claim may receive admittedFreshPCs, and
        // every admitted PC must be a census fresh entry. Registry completeness
        // is unaffected (it describes coverage, not ownership).
        if (proof.perProgramAdmission && p.gpuLaunchAdmitted) {
            if (!complete)
                throw std::invalid_argument(
                    "GPU launch admission requires the full completion proof set");
            for (const auto pc : p.admittedFreshPCs) {
                if ((pc & 7u) || pc >= reo_resident_live::CodeBytes || pc == 0u ||
                    std::find(specification.freshEntries.begin(), specification.freshEntries.end(),
                              pc) == specification.freshEntries.end())
                    throw std::invalid_argument("Admitted fresh PC is not a proven census entry");
            }
            if (p.admittedFreshPCs.empty())
                throw std::invalid_argument(
                    "GPU launch admission requires at least one device-proven entry");
            program->gpuAdmitted = true;
            program->admittedFreshPCs = p.admittedFreshPCs;
        }
        // Static full-initializer/header audit proves these raw source policies
        // for exactly eight images. Actual literal protocol proof is separate.
        program->entryZeroHasNoEvent = true;
        program->variableOutputCount = generic(asset.kind);
        program->inputTagOffsetFromTop = 1;
#ifdef REO_GPU_CATALOG_LITERAL_REUSE
        // A guard capability belongs to the selected compiled module, not its
        // ancestor shader. Unguarded weightedv6 remains false unless separately
        // composed and proved; the packager refuses that unsupported claim.
        program->literalSourcePreserved = complete && p.freshLiteralSourcePreserved &&
                                          (!program->canResume || p.resumeLiteralSourcePreserved);
#else
        if (p.freshLiteralSourcePreserved || p.resumeLiteralSourcePreserved)
            throw std::runtime_error("Literal capability requires matching private reuse ABI");
#endif
        registry->programs.push_back(program);
        auto resumeCode =
            separateResume ? readSpirv(assetDirectory, asset.resumeSpirv) : std::vector<uint32_t>{};
        reo_resident_live::ProgramModule module{program->bindingId,
                                                readSpirv(assetDirectory, asset.spirv),
                                                program->canResume, std::move(resumeCode)};
#ifdef REO_GPU_CATALOG_LITERAL_REUSE
        module.freshLiteralSourcePreserved = complete && p.freshLiteralSourcePreserved;
        module.resumeLiteralSourcePreserved = complete && p.resumeLiteralSourcePreserved;
#endif
        out.shaders.programs.push_back(std::move(module));
    }
    out.shaders.strip = readSpirv(assetDirectory, assets.auxiliary[0]);
    out.shaders.unpack = readSpirv(assetDirectory, assets.auxiliary[1]);
    out.shaders.effectValidate = readSpirv(assetDirectory, assets.auxiliary[2]);
    out.shaders.bytePatch = readSpirv(assetDirectory, assets.auxiliary[3]);
    registry->literalEffect = [](const reo_resident_live::Program& program,
                                 const reo_resident_live::LiteralCommands& raw, bool resume,
                                 uint32_t startPC, uint32_t top,
                                 reo_resident_live::LiteralEffect& effect) {
        if (!program.accepts(startPC, resume))
            return false;
        const reo_resident_live::LiteralPolicy policy{program.entryZeroHasNoEvent,
                                                      program.variableOutputCount,
                                                      program.inputTagOffsetFromTop};
        return reo_resident_live::describeLiteralLaunch(raw, policy, resume, startPC, top, effect);
    };
    registry->fullReachedRegistry = proof.fullReachedRegistry;
    registry->mappedBankCoherence = proof.mappedBankCoherence;
    registry->gpuLiteralEffects = proof.gpuLiteralEffects;
    registry->literalPoliciesCertified = proof.literalPoliciesCertified;
    registry->allowIncrementalFallback = proof.incrementalEnrollment;
    registry->perProgramAdmission = proof.perProgramAdmission;
    out.registry = registry;
    out.owner = reo_resident_live::makeResidentOwnerConfig(out.shaders);
    auto instantiate = out.owner.factory;
    auto selected = std::make_shared<const reo_resident_live::ShaderBundle>(out.shaders);
    out.owner.factory = [instantiate, selected](Vulkan::Device& device,
                                                ParallelGS::GSInterface& gs) {
        prewarm(device, *selected);
        return instantiate(device, gs);
    };
    // Full installation needs a complete registry plus owner protocol proof.
    // Incremental installation additionally requires the packager's explicit
    // opt-in; per-launch fallback (never GPU for unadmitted programs) keeps it
    // safe, with per-program admission allowed only for packager-declared
    // device-proven images. No partial/diagnostic catalogue installs without
    // that opt-in.
    out.readyToInstall = (registry->complete() && proof.ownerProtocolCertified) ||
                         (proof.incrementalEnrollment && proof.ownerProtocolCertified);
    out.owner.enabled = out.readyToInstall;
    out.owner.fullProtocolCoverage = out.readyToInstall;
    return out;
}
inline void installBeforeBoot(const Bootstrap& bootstrap) {
    if (!bootstrap.readyToInstall || !bootstrap.registry || !bootstrap.owner.enabled ||
        !bootstrap.owner.fullProtocolCoverage || !bootstrap.owner.factory)
        throw std::runtime_error("GPU catalogue requires complete "
                                 "reached/protocol/effect/coherence proof before installation");
    if (!bootstrap.registry->complete() && !bootstrap.registry->allowIncrementalFallback)
        throw std::runtime_error(
            "GPU catalogue requires a complete registry without explicit incremental enrollment");
    reo_resident_live::registerBeforeBoot(bootstrap.registry);
}
inline std::vector<PrewarmResult> prewarm(Vulkan::Device& device,
                                          const reo_resident_live::ShaderBundle& bundle) {
    if (bundle.programs.size() != 8)
        throw std::invalid_argument("Prewarm requires the complete selected catalogue");
    auto cmd = device.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
    if (!cmd)
        throw std::runtime_error("GPU catalogue prewarm command allocation failed");
    std::vector<PrewarmResult> results;
    auto compile = [&](const std::vector<uint32_t>& code, uint32_t buffers, uint32_t push,
                       uint64_t binding, bool resume = false) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Invalid prewarm shader");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = (1u << buffers) - 1u;
        for (unsigned b = 0; b < buffers; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = push;
        const auto start = std::chrono::steady_clock::now();
        auto* program = device.request_program(code.data(), code.size() * 4, &layout);
        if (!program || !program->get_pipeline_layout())
            throw std::runtime_error("Prewarm module creation failed");
        cmd->set_program(program);
        Vulkan::DeferredPipelineCompile state{};
        cmd->extract_pipeline_state(state);
        // Synchronous real driver compilation populates Program::add_pipeline
        // and the SAME Device cache. No descriptors, dispatch or guest bank.
        auto pipeline = program->get_pipeline(state.hash);
        if (pipeline.pipeline == VK_NULL_HANDLE)
            pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                &device, state, Vulkan::CommandBuffer::CompileMode::Sync);
        if (pipeline.pipeline == VK_NULL_HANDLE)
            throw std::runtime_error("GPU catalogue prewarm pipeline compilation failed");
        results.push_back(
            {binding,
             std::chrono::duration<double, std::milli>(std::chrono::steady_clock::now() - start)
                 .count(),
             resume});
    };
    for (const auto& module : bundle.programs) {
        compile(module.spirv, 7, 32, module.bindingId);
        if (!module.resumeSpirv.empty())
            compile(module.resumeSpirv, 7, 32, module.bindingId, true);
    }
    compile(bundle.strip, 9, 0, 0);
    compile(bundle.unpack, 4, 16, 0);
    compile(bundle.effectValidate, 5, 0, 0);
    compile(bundle.bytePatch, 3, 16, 0);
    // End/recycle the empty command buffer through the ordinary same-device
    // lifecycle. It contains no semantic GPU commands or bank mutations.
    device.submit(cmd);
    return results;
}
} // namespace reo_gpu_catalog
