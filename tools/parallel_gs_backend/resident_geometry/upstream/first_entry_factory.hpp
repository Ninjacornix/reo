#pragma once
#include "resident_array_owner.hpp"
#include "enrollment/catalogue_enrollment.hpp"
#include "parent/parent_configure.hpp"
#include "setter_assets.hpp"
#include "state_packet_assets197900.hpp"
#include "allocator_assets.hpp"
#include "bounded_graphics_entry_filter.h"
#include <chrono>
#include <cstdio>

namespace reo_gpu_upstream {
enum class FirstEntryPackage { Setter5A, StatePacket197900 };
struct FirstEntryAssetDirectories {
    std::filesystem::path parent;   // Exact parent and transport pins below.
    std::filesystem::path upstream; // Exact selected setter/state asset pins.
};
struct FirstEntryFactory {
    reo_resident_live::OwnerConfig owner;
    std::shared_ptr<const reo_resident_live::Registry> registry;
    std::shared_ptr<const reo_parent_natural::BoundedGraphicsEntryFilter> selector;
    FirstEntryPackage entryPackage;
    static constexpr bool CompleteSelectionReady = false;
    static constexpr bool ViewportActualDeviceCertified = false;
    static void requireBoundedProgramShape(std::span<const uint32_t> words) {
        const size_t bytes = words.size() * 4u;
        if (words.size() < 5u || words[0] != 0x07230203u)
            throw std::invalid_argument("First-entry prewarm requires exact SPIRV module shape");
        if (bytes <= 128u * 1024u)
            return;
        // Oversize modules require their independently proved exact size/hash.
        // Its immutable loader pin is also checked again at this boundary.
        if (bytes == 133068u) {
            std::vector<uint8_t> raw(bytes);
            std::memcpy(raw.data(), words.data(), bytes);
            if (reo_gpu_catalog::sha256(raw) ==
                "38e1ddb70d27594ea89b0c6c03b754f864906bab46f8eb0fc1091de3e94c2656")
                return;
        }
        if (bytes == 163084u) {
            std::vector<uint8_t> raw(bytes);
            std::memcpy(raw.data(), words.data(), bytes);
            if (reo_gpu_catalog::sha256(raw) ==
                "e3de3913287411c4443a915fe8e956a8d467e4dcee0af2c251efd38fe7422b60")
                return;
        }
        throw std::invalid_argument(
            "First-entry prewarm module exceeds its exact bounded size/hash catalogue");
    }
    template <class Visit>
    static void forEachBoundedProgram(const reo_gpu_palette_parent::Modules& selected,
                                      const Visit& visit) {
        visit(selected.sourceBytePatch, 4u, 16u, "raw-source-byte-patch");
        visit(selected.setter196010, 8u, sizeof(Parameters), "setter5ABC");
        for (const auto& module : selected.setter196010Additional)
            visit(module, 8u, sizeof(Parameters), "setter-additional");
        for (const auto& module : selected.statePacket197900)
            visit(module, 11u, sizeof(Parameters), "state197900-stage");
        visit(selected.statePacketAllocator, 7u, sizeof(Parameters), "state197900-allocator");
        visit(selected.statePacketQueueHeaders, 7u, sizeof(Parameters), "state197900-headers");
        visit(selected.statePacketQueueJournal, 7u, sizeof(Parameters), "state197900-journal");
        visit(selected.composition18F6A0, 6u, sizeof(Parameters), "whole-transform-wrapper");
        visit(selected.matrix191280, 5u, sizeof(Parameters), "matrix191280");
        visit(selected.perspective18F710, 6u, sizeof(Parameters), "perspective-exact-effects");
        const auto& bundle = selected.viewport18F970;
        if (bundle.size() < 8u || bundle[0] != ViewportBundleMagic || bundle[1] != 1u ||
            bundle[2] != ViewportModuleCount || bundle[3] != sizeof(ViewportParameters) ||
            bundle[4] != 412u || bundle[5] != ViewportCarryWords ||
            bundle[6] != ViewportTransactionWords || bundle[7])
            throw std::invalid_argument("First-entry viewport fragment bundle ABI differs");
        size_t at = 8u;
        constexpr const char* names[] = {"viewport-init",
                                         "viewport-root",
                                         "viewport-a",
                                         "viewport-b",
                                         "viewport-scissor",
                                         "viewport-projection",
                                         "viewport-matrix",
                                         "viewport-packet-start",
                                         "viewport-packet-payload",
                                         "viewport-packet-return",
                                         "viewport-finalize"};
        for (unsigned part = 0; part < ViewportModuleCount; ++part) {
            if (at >= bundle.size())
                throw std::invalid_argument("First-entry viewport bundle is truncated");
            const auto count = bundle[at++];
            if (count < 5u || count > bundle.size() - at)
                throw std::invalid_argument("First-entry viewport fragment size differs");
            visit(std::span<const uint32_t>(bundle.data() + at, count), 13u,
                  sizeof(ViewportParameters), names[part]);
            at += count;
        }
        if (at != bundle.size())
            throw std::invalid_argument("First-entry viewport bundle has extra words");
        visit(selected.viewportAllocator18DDD0, 7u, sizeof(Parameters), "viewport-allocator");
        visit(selected.viewportQueueHeaders, 7u, sizeof(Parameters), "viewport-headers");
        visit(selected.viewportQueueJournal, 7u, sizeof(Parameters), "viewport-journal");
    }
    static void validateBoundedProgramShapes(const reo_gpu_palette_parent::Modules& selected) {
        forEachBoundedProgram(selected, [](std::span<const uint32_t> words, uint32_t, uint32_t,
                                           const char*) { requireBoundedProgramShape(words); });
    }
    static void prewarmBounded(Vulkan::Device& device,
                               const reo_gpu_palette_parent::Modules& selected, FirstEntryPackage) {
        // Reject every CPU-known shape before owning a command buffer.
        validateBoundedProgramShapes(selected);
        auto command = device.request_command_buffer(Vulkan::CommandBuffer::Type::Generic);
        if (!command)
            throw std::runtime_error("First-entry prewarm command allocation failed");
        try {
            const auto compile = [&](std::span<const uint32_t> words, uint32_t buffers,
                                     uint32_t pushBytes, const char* label) {
                requireBoundedProgramShape(words);
                Vulkan::ResourceLayout shape{};
                shape.sets[0].storage_buffer_mask = (1u << buffers) - 1u;
                shape.push_constant_size = pushBytes;
                for (uint32_t binding = 0; binding < buffers; ++binding)
                    shape.sets[0].meta[binding].array_size = 1;
                const auto started = std::chrono::steady_clock::now();
                auto* program = device.request_program(words.data(), words.size() * 4u, &shape);
                if (!program || !program->get_pipeline_layout())
                    throw std::runtime_error("First-entry same-Device prewarm program unavailable");
                const auto& actual = program->get_pipeline_layout()->get_resource_layout();
                if (actual.descriptor_set_mask != 1u || actual.bindless_descriptor_set_mask ||
                    actual.sets[0].storage_buffer_mask != shape.sets[0].storage_buffer_mask ||
                    actual.push_constant_range.offset ||
                    actual.push_constant_range.size != pushBytes ||
                    actual.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
                    throw std::invalid_argument("First-entry prewarm physical shader ABI differs");
                for (uint32_t binding = 0; binding < buffers; ++binding)
                    if (actual.sets[0].meta[binding].array_size != 1u ||
                        actual.stages_for_bindings[0][binding] != VK_SHADER_STAGE_COMPUTE_BIT)
                        throw std::invalid_argument(
                            "First-entry prewarm physical storage binding differs");
                command->set_program(program);
                Vulkan::DeferredPipelineCompile state{};
                command->extract_pipeline_state(state);
                auto pipeline = program->get_pipeline(state.hash);
                if (pipeline.pipeline == VK_NULL_HANDLE)
                    pipeline = Vulkan::CommandBuffer::build_compute_pipeline(
                        &device, state, Vulkan::CommandBuffer::CompileMode::Sync);
                if (pipeline.pipeline == VK_NULL_HANDLE)
                    throw std::runtime_error("First-entry same-Device driver prewarm failed");
                const double milliseconds = std::chrono::duration<double, std::milli>(
                                                std::chrono::steady_clock::now() - started)
                                                .count();
                std::fprintf(stderr,
                             "[GPU-FIRST-ENTRY-PREWARM] module=%s bytes=%zu ms=%.3f "
                             "semantic_dispatches=0 cold_numeric_seeds=0\n",
                             label, words.size() * 4u, milliseconds);
            };
            forEachBoundedProgram(selected, compile);
        } catch (...) {
            // No descriptor/bank/dispatch was recorded. Return the command to
            // Device even on ABI/driver refusal so close cannot strand a frame.
            device.submit_discard(command);
            throw;
        }
        device.submit_discard(command);
    }
    // This selects one bounded cold entry and retains the finite math catalogue. Every later source
    // and VU admission still uses the real owner guards. No CPU fallback is
    // introduced after numerical ownership, and complete selection stays off.
    void installBeforeBoot(reo_resident_live::OwnerConfig& destination) const {
        if (!selector || !registry || !registry->authenticColdComponentEnrollment ||
            !owner.enabled || owner.fullProtocolCoverage ||
            !owner.authenticColdComponentEnrollment || !owner.factory || registry->complete() ||
            !registry->programs.empty() || registry->literalEffect)
            throw std::logic_error(
                "Bounded first-entry package lost its separate component admission");
        reo_resident_live::registerBeforeBoot(registry);
        destination = owner;
    }
    static FirstEntryFactory build(PS2Runtime& runtime, const reo_gpu_catalog::Bootstrap& catalogue,
                                   const FirstEntryAssetDirectories& directories,
                                   FirstEntryPackage package) {
        if (package != FirstEntryPackage::Setter5A &&
            package != FirstEntryPackage::StatePacket197900)
            throw std::invalid_argument("Unknown finite native first-entry package");
        if (!catalogue.registry || catalogue.registry->programs.size() != 8u ||
            catalogue.shaders.programs.size() != 8u)
            throw std::invalid_argument(
                "Native first-entry factory requires the exact pinned eight-image catalogue");
        const auto specifications = reo_gpu_catalog::imageSpecs();
        for (size_t index = 0; index < specifications.size(); ++index) {
            const auto& actual = catalogue.registry->programs[index];
            const auto& module = catalogue.shaders.programs[index];
            const auto& expected = specifications[index];
            if (!actual || actual->bindingId != expected.bindingId ||
                module.bindingId != expected.bindingId ||
                actual->startPCs != expected.freshEntries || module.spirv.size() < 5u ||
                module.spirv[0] != 0x07230203u ||
                reo_gpu_catalog::sha256(std::vector<uint8_t>(
                    actual->exactImage.begin(), actual->exactImage.end())) != expected.digest)
                throw std::invalid_argument(
                    "Native first-entry catalogue image/entry/module identity differs");
        }
        reo_resident_live::ArrayShaderBundle shaders;
        shaders.programs = catalogue.shaders.programs;
        shaders.strip = catalogue.shaders.strip;
        shaders.unpack = catalogue.shaders.unpack;
        shaders.effectValidate = catalogue.shaders.effectValidate;
        shaders.bytePatch = catalogue.shaders.bytePatch;
        auto& parent = shaders.parent;
        parent.enabled = true;
        parent.tier = reo_parent_live::AdmissionTier::OfflineComponent;
        const auto load = [&](const char* name, const char* digest) {
            return reo_parent_install::pinnedParentModule(directories.parent / name, digest);
        };
        parent.producer.prepare =
            load("parent_prepare.spv",
                 "f93c456703ba80fa360feaa8457810ae2a760639e366927e0ad0128fb290bbb9");
        parent.producer.leaf = load(
            "palette_leaf.spv", "265789b868f79589c4b448f31f734f190450bec4a4730e10d4a6167d41e52986");
        parent.producer.finish =
            load("parent_finish.spv",
                 "c07a1d7756b2cd3129c89ecf614210cfc5c9b1202c844256abea982a72548145");
        parent.producer.commit =
            load("parent_commit.spv",
                 "e1c6b58ec6a542eafbaebf9a7ebb602d3433e73ba3c372eabb04cb1d7acc3b0c");
        parent.transport.mailbox =
            load("parent_return_mailbox.spv",
                 "09b181c774cafcc695f2df5e448fbde8f9e6bc1c192e258d0820454f9dcfca60");
        parent.transport.relay =
            load("parent_completion_relay.spv",
                 "856371c7f53e2925922a44bc219cb354498115c8f44c28a8ddf26b2c64f4f8b6");
        if (shaders.unpack !=
            load("vif_unpack.spv",
                 "a8a74f3017d22f15bf0a8e346bcecefe8037271642c02ce4571db0ec6d96c396"))
            throw std::invalid_argument(
                "Native first-entry factory requires the proved raw UNPACK module");
        shaders.pooledTail = load(
            "pooled_tail.spv", "d6573a4179e53b87959ddaf0aa280b7da0d5302e68051e40758725536135e344");
        const uint32_t entry = package == FirstEntryPackage::Setter5A ? 0x196010u : 0x197900u;
        const uint32_t command = package == FirstEntryPackage::Setter5A ? 0x5au : 0u;
        parent.producer.sourceBytePatch =
            setterAsset(directories.upstream / "raw_byte_patch.spv",
                        "08ba20089316e27575d7e4b007074c23e661c094fb6929631f65cea8875447c3");
        attachSetterAssets(parent.producer, directories.upstream);
        attachStatePacket197900Assets(parent.producer, directories.upstream, true);
        attachViewportAssets(parent.producer, directories.upstream / "viewport", true);
        attachViewportAllocatorAsset(parent.producer, directories.upstream / "viewport", true);
        parent.producer.matrix191280 =
            setterAsset(directories.upstream / "matrix191280.spv",
                        "d4acf7edb74f498da615af0bf6979e9bab9f3d2f00cb8adc86775faeb214c4ac");
        parent.producer.perspective18F710 =
            setterAsset(directories.upstream / "perspective18f710_effects.spv",
                        "99abd0f43f71bb246f918f037c2053fb7de1eb55398986e16543c4d50ad03452");
        parent.producer.composition18F6A0 =
            setterAsset(directories.upstream / "composition18f6a0.spv",
                        "e3de3913287411c4443a915fe8e956a8d467e4dcee0af2c251efd38fe7422b60");
        validateBoundedProgramShapes(
            parent.producer); // Before actual Device/backend construction; no Runtime RAM exists.
        constexpr uint32_t roots[] = {0x196010u, 0x197900u, 0x191280u, 0x18f710u, 0x1921b0u,
                                      0x18f570u, 0x18fdf0u, 0x18f970u, 0x18fce0u, 0x18f880u,
                                      0x18f7e0u, 0x197490u, 0x18f6a0u};
        // These compiled guarded bodies are registered by the concrete native
        // bootstrap before this factory. No guest RAM/code image exists yet.
        for (const auto root : roots) {
            if (!runtime.hasFunction(root))
                throw std::invalid_argument(
                    "Finite retained entry omits its registered compiled original body");
            const auto body = runtime.lookupFunction(root);
            if (!body)
                throw std::invalid_argument("Finite retained original body is absent");
            parent.retainedEntryBodies.push_back({root, body});
        }
        parent.boundedRetainedInvocations = true;
        shaders.natural.requested = true;
        shaders.natural.authenticColdComponentEnrollment = true;
        shaders.natural.authenticColdComponentEntry = entry;
        shaders.natural.authenticColdSetterCommand = command;
        shaders.natural.actualRuntime = &runtime;
        shaders.natural.authenticColdComponentBody =
            runtime.hasFunction(entry) ? runtime.lookupFunction(entry) : nullptr;
        if (!shaders.natural.authenticColdComponentBody || parent.gates.ready() ||
            parent.producerProofs.complete() || shaders.natural.coverage.complete())
            throw std::invalid_argument("Native first-entry package cannot claim complete source "
                                        "selection or omit its real registered body");
        auto registry = std::make_shared<reo_resident_live::Registry>();
        // Partial VU execution is not admitted by this EE entry package. These
        // explicit component fields are separate from the catalogue's proofs.
        registry->authenticColdComponentEnrollment = true;
        auto identities =
            catalogue.registry; // Retained eight-image metadata, never a partial VU registration.
        auto selected =
            reo_parent_natural::retainBoundedGraphicsEntryFilter(runtime, entry, command);
        auto modules = std::make_shared<const reo_gpu_palette_parent::Modules>(parent.producer);
        auto owner = reo_resident_live::makeAuthenticColdComponentOwnerConfig(std::move(shaders));
        auto instantiate = owner.factory;
        owner.factory = [instantiate, selected, registry, identities, modules,
                         package](Vulkan::Device& device, ParallelGS::GSInterface& gs) {
            // Backend initialization precedes guest GUI/fade execution. The
            // existing persistent Device cache serves both this compile and
            // the later real ColdEntry; no numerical bank is created here.
            prewarmBounded(device, *modules, package);
            return instantiate(device, gs);
        };
        return {std::move(owner), std::move(registry), std::move(selected), package};
    }
};
} // namespace reo_gpu_upstream
