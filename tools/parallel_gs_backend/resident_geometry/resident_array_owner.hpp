#pragma once
// Concrete bounded same-Device whole2EA owner. SOURCE ONLY, not enrolled.
// Include using the root private-gs-b and root pooled helper include directories.
#include "parent/parent_owner_service.hpp"
#include "natural/native_owner_target.hpp"
#include "resident_vif_commands.h"
#include "resident_program_bank.hpp"
#include "resident_pooled_strip.hpp"
#include "resident_vif_unpack_extended.h"
#include "resident_material.hpp"
#include "resident_backend_factory.hpp"
#include "gs_interface.hpp"
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <filesystem>
#include "typed_stream_builder.hpp"
#include "owner_timing.hpp"
#include "boundary_pool.hpp"
#include "multi_effect/live_multi_path.hpp"
#include "multi_effect/pooled_tail.hpp"
#include "static_group/static_group_config.hpp"

namespace reo_resident_live {
struct ArrayShaderBundle {
    std::vector<uint32_t> whole2ea, strip, unpack;
    uint64_t whole2eaBinding = 0;
    std::vector<ProgramModule> programs;
    std::vector<uint32_t> effectValidate, bytePatch, pooledTail;
    reo_gpu_array_bridge::Bundle orderedStream{};
    reo_gpu_boundary::Bundle boundary{};
    reo_gpu_static_consumer::LiveBundle multiEffect{};
    std::vector<reo_gpu_static_consumer::LiveBundle> multiEffects{};
    reo_parent_install::Configuration parent{};  // Default-off, no hook installer.
    reo_parent_natural::Configuration natural{}; // Default-off; complete source closure required.
    reo_gpu_static_group::Configuration staticGroup{}; // Default-off, scoped root enrollment only.
};
class ParallelArrayOwner final : public SemanticOwner {
#ifdef REO_STATIC_OWNER_OFFLINE_FIXTURE
    friend struct StaticOwnerFixtureAccess;
#endif

    Vulkan::Device& device_;
    ParallelGS::GSInterface& gs_;
    ArrayShaderBundle shaders_;
    std::shared_ptr<ProgramBank> whole_;
    std::unique_ptr<reo_gpu_pooled_strip::Strip> strip_;
    std::unique_ptr<reo_gpu_vif_upload::ResidentVifUnpack> unpack_;
    std::unique_ptr<reo_parent_install::Service> parent_;
    std::shared_ptr<reo_parent_natural::NativeTarget> natural_;
    std::unique_ptr<EffectValidate> effects_;
    std::unique_ptr<BytePatch> patch_;
    std::vector<std::unique_ptr<reo_gpu_static_consumer::LivePath>> multi_;
    std::unique_ptr<reo_gpu_static_consumer::PooledTail> pooledTail_;
    std::unique_ptr<reo_gpu_mesh_pool::MeshPool> pool_;
    struct Job {
        uint64_t ordinal;
        reo_gpu_mesh_pool::MeshPool::Slice slice;
        uint32_t selector = 0;
        bool array = false;
        bool boundary = false;
        std::shared_ptr<reo_gpu_static_consumer::LiveJob> multi{};
        Vulkan::BufferHandle tail{};
        uint32_t finalPrim = 0;
        bool tailPublished = false;
        reo_gpu_static_consumer::LivePath* multiPath = nullptr;
        std::shared_ptr<reo_gpu_static_group::Run> staticGroup{};
        uint32_t staticLocal = 0;
    };
    std::vector<Job> jobs_;
    uint64_t epoch_ = 0, generation_ = 0, lastEnqueued_ = 0, lastRetired_ = 0;
    bool failed_ = false, needsPublicationCheck_ = false;
    Vulkan::BufferHandle staging_;
    size_t stagingBytes_ = 0;
    struct StreamCounters {
        uint64_t eligible = 0, declined = 0, groupsRecorded = 0, launchesRecorded = 0;
        uint64_t rawQwords = 0, boundaries = 0, maxGroup = 0, idempotentCycleWrites = 0;
        std::array<uint64_t, 3> eligibleBySelector{}, recordedBySelector{}, actualFastVertices{};
        std::array<uint64_t, 3> completeGpuBoundaryBySelector{};
        uint64_t unknownSelectorBoundary = 0, adBoundary = 0, initBoundary = 0, foreignBoundary = 0,
                 non39Boundary = 0;
        uint64_t stagedBoundaryRecorded = 0, stagedBoundaryRetired = 0, boundaryFastVertices = 0;
        uint64_t specializedBoundaryControls = 0, actualBoundaryGenericFallbacks = 0;
    } streamCounters_;
    std::ofstream streamLog_;
    reo_gpu_array_bridge::Builder streamBuilder_;
    std::vector<Operation> heldOperations_;
    uint32_t heldBytes_ = 0, cycleMirror_ = 0, modeMirror_ = 0;
    uint64_t lastAccepted_ = 0;
    std::unique_ptr<reo_gpu_array_bridge::Pipeline> stream_;
    std::unique_ptr<reo_gpu_boundary::Pipeline> boundary_;
    void retireParentUploads(const Vulkan::Fence& fence) {
        if (!parent_)
            return;
        auto keys = parent_->retireActualUploads(fence);
        // Service releases its protocol lock before any source callback.
        try {
            if (natural_)
                for (const auto& key : keys)
                    natural_->ownerAfterActualT2(key);
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
#include "static_group/owner_static_members.inc"
    bool stagedBoundary(const Operation& operation) const {
        if (!boundary_ || operation.kind != Kind::Launch || !operation.program ||
            operation.program->bindingId != boundary_->binding() ||
            !boundary_->image(operation.program->exactImage) ||
            !operation.program->literalSourcePreserved)
            return false;
        if (operation.effect.type == LiteralEffect::Type::None)
            return !operation.resume && operation.startPC == 0u;
        if (operation.effect.type == LiteralEffect::Type::MaterialAD)
            return true;
        const uint32_t rawCount = operation.effect.echo[4] & 32767u;
        return operation.effect.type == LiteralEffect::Type::Strip &&
               (rawCount == 16u || rawCount == 35u);
    }
    void logStream(const char* event) {
        if (!streamLog_)
            return;
        streamLog_
            << "{\"event\":\"" << event << "\",\"eligible_launches\":" << streamCounters_.eligible
            << ",\"declined_launches\":" << streamCounters_.declined
            << ",\"groups_recorded\":" << streamCounters_.groupsRecorded
            << ",\"array_launches_recorded\":" << streamCounters_.launchesRecorded
            << ",\"raw_qwords\":" << streamCounters_.rawQwords
            << ",\"boundaries\":" << streamCounters_.boundaries
            << ",\"largest_group\":" << streamCounters_.maxGroup
            << ",\"idempotent_cycle_writes\":" << streamCounters_.idempotentCycleWrites
            << ",\"rigid_eligible\":" << streamCounters_.eligibleBySelector[1]
            << ",\"weighted_eligible\":" << streamCounters_.eligibleBySelector[2]
            << ",\"rigid_recorded\":" << streamCounters_.recordedBySelector[1]
            << ",\"weighted_recorded\":" << streamCounters_.recordedBySelector[2]
            << ",\"rigid_actual_retired_fast_vertices\":" << streamCounters_.actualFastVertices[1]
            << ",\"weighted_actual_retired_fast_vertices\":"
            << streamCounters_.actualFastVertices[2] << ",\"rigid_complete_GPU_boundaries\":"
            << streamCounters_.completeGpuBoundaryBySelector[1]
            << ",\"weighted_complete_GPU_boundaries\":"
            << streamCounters_.completeGpuBoundaryBySelector[2]
            << ",\"unknown_selector_boundaries\":" << streamCounters_.unknownSelectorBoundary
            << ",\"AD6_boundaries\":" << streamCounters_.adBoundary
            << ",\"init_boundaries\":" << streamCounters_.initBoundary
            << ",\"foreign_image_boundaries\":" << streamCounters_.foreignBoundary
            << ",\"non39_boundaries\":" << streamCounters_.non39Boundary
            << ",\"staged_boundary_recorded\":" << streamCounters_.stagedBoundaryRecorded
            << ",\"staged_boundary_actual_retired\":" << streamCounters_.stagedBoundaryRetired
            << ",\"boundary_actual_fast_vertices\":" << streamCounters_.boundaryFastVertices
            << ",\"specialized_boundary_controls\":" << streamCounters_.specializedBoundaryControls
            << ",\"actual_boundary_generic_fallbacks\":"
            << streamCounters_.actualBoundaryGenericFallbacks
            << ",\"static_groups\":" << staticCounters_.groups
            << ",\"static_max_group\":" << staticCounters_.maxGroup
            << ",\"static_retired_calls\":" << staticCounters_.retired
            << ",\"static_actual_fast_groups\":" << staticCounters_.fastGroups
            << ",\"static_complete_GPU_groups\":" << staticCounters_.completeGpuGroups
            << ",\"static_input_vertices\":" << staticCounters_.inputVertices
            << ",\"normal_graphics_readbacks\":0,\"enqueue_is_completion\":false}\n";
        streamLog_.flush();
    }
    Batch single(const Operation& operation) const {
        Batch batch{};
        batch.epoch = epoch_;
        batch.bankGeneration = generation_;
        batch.operations.push_back(operation);
        batch.payloadBytes = uint32_t(operation.payload.size());
        return batch;
    }
    bool streamLaunch(const Operation& operation) const {
        return stream_ && operation.kind == Kind::Launch && operation.program && operation.resume &&
               operation.program->bindingId == stream_->exactImageBinding() &&
               stream_->exactImage(operation.program->exactImage) &&
               operation.program->literalSourcePreserved && operation.orderedStream &&
               operation.orderedStream->exactRawTop && operation.orderedStream->exactRawTag &&
               (operation.orderedStream->selector == 1 || operation.orderedStream->selector == 2) &&
               operation.orderedStream->inputCount == 39 &&
               operation.effect.type == LiteralEffect::Type::Strip &&
               operation.effect.echo[1] == 39 && (operation.effect.echo[4] & 32767u) == 39 &&
               operation.effect.vertexCapacity > 0 && operation.effect.vertexCapacity <= 256;
    }
    void flushStream() {
        if (heldOperations_.empty())
            return;
        ++streamCounters_.boundaries;
        if (streamBuilder_.jobs() == 0) {
            // Leading raw uploads without an admitted launch still belong to
            // the ordinary GPU path; do not drop them when an epoch closes.
            Batch batch{};
            batch.epoch = epoch_;
            batch.bankGeneration = generation_;
            batch.operations = heldOperations_;
            batch.payloadBytes = heldBytes_;
            enqueueDirect(batch);
        } else {
            if (!pool_)
                pool_ = std::make_unique<reo_gpu_mesh_pool::MeshPool>(device_, MaxLaunches, epoch_);
            std::vector<const Operation*> launches;
            std::vector<reo_gpu_mesh_pool::MeshPool::Slice> slices;
            for (const auto& operation : heldOperations_)
                if (operation.kind == Kind::Launch) {
                    launches.push_back(&operation);
                    slices.push_back(pool_->allocate());
                }
            if (launches.size() != streamBuilder_.jobs())
                throw std::logic_error("Ordered stream launch accounting differs");
            if (!gs_.prepare_resident_recording_projected())
                throw std::runtime_error("Array stream overlaps incomplete ordinary GS input");
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                stream_->enqueue(cmd, streamBuilder_.input(), *whole_, *pool_, slices);
            });
            for (size_t job = 0; job < launches.size(); ++job) {
                const auto& operation = *launches[job];
                const auto& slice = slices[job];
                const auto contract = echo(operation.effect);
                if (validateLiteralEnvelope(operation.effect) != 1u)
                    throw std::logic_error("An AD/init boundary entered a mesh array");
                // Each raw nonempty PRE determines its projected material in
                // ordinal order. Actual queue/PRIM projection waits the last
                // genuinely certified tail; no speculative CPU queue reset.
                const uint32_t literalPrim = (contract.qwords[0][1] >> 15u) & 2047u;

                if (!gs_.prepare_resident_recording_projected())
                    throw std::runtime_error("Array mesh publication overlaps ordinary GS input");
                ParallelGS::ResidentMaterial material{};
                if (!gs_.prepare_resident_material_projected(operation.effect.vertexCapacity,
                                                             literalPrim, material))
                    throw std::runtime_error("Unsupported array material/feedback/register state");
                reo_gpu_pooled_strip::Parameters parameters{};
                ParallelGS::RegisterState registers{};
                if (material.registers.size() != sizeof(registers))
                    throw std::logic_error("Projected material register ABI mismatch");
                std::memcpy(&registers, material.registers.data(), sizeof(registers));
                const auto& context = registers.ctx[registers.prim.desc.CTXT];
                parameters.limits = {operation.effect.vertexCapacity, 0,
                                     operation.effect.vertexCapacity, 0};
                parameters.offsetScissorLo = {
                    int32_t(context.xyoffset.desc.OFX), int32_t(context.xyoffset.desc.OFY),
                    int32_t(context.scissor.desc.SCAX0), int32_t(context.scissor.desc.SCAY0)};
                parameters.scissorHi = {int32_t(context.scissor.desc.SCAX1),
                                        int32_t(context.scissor.desc.SCAY1), 0, 0};
                std::memcpy(parameters.material.data(), &material.primitive.state, 24);
                auto tail = pooledTail_ ? pooledTail_->allocate() : Vulkan::BufferHandle{};
                gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                    cmd.buffer_barrier(whole_->command(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT);
                    cmd.update_buffer_inline(whole_->command(), 0, sizeof(contract), &contract);
                    cmd.buffer_barrier(whole_->command(), VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT,
                                       VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                       VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
                    effects_->enqueue(cmd, *whole_, *pool_, slice);
                    strip_->enqueue(cmd, *pool_, slice, parameters, whole_->completion());
                    if (tail)
                        pooledTail_->enqueue(cmd, *pool_, slice, whole_->completion(), *tail,
                                             uint32_t(generation_), literalPrim,
                                             operation.resume ? 4u : 0u);
                });
                if (!gs_.submit_resident_material_projected(
                        material, strip_->inputs(*pool_, slice, operation.effect.vertexCapacity)))
                    throw std::runtime_error(
                        "Array material changed during same-Device submission");
                jobs_.push_back({operation.ordinal, slice, operation.orderedStream->selector, true,
                                 false, nullptr, tail, literalPrim, false});
                lastEnqueued_ = operation.ordinal;
                ++streamCounters_.recordedBySelector[operation.orderedStream->selector];
            }
            needsPublicationCheck_ = true;
            ++streamCounters_.groupsRecorded;
            streamCounters_.launchesRecorded += launches.size();
            streamCounters_.maxGroup =
                std::max<uint64_t>(streamCounters_.maxGroup, launches.size());
            logStream("array_group_recorded_not_retired");
        }
        heldOperations_.clear();
        heldBytes_ = 0;
        streamBuilder_.clear();
    }
    void acceptStream(const Batch& batch) {
        validate(batch);
        cold(batch);
        requireOwner(batch.epoch, batch.bankGeneration);
        preflightParent(batch);
        uint64_t ordinal = lastAccepted_;
        size_t count = jobs_.size() + streamBuilder_.jobs();
        // Validate BEFORE holding raw input or mutating the GPU. Registered
        // generic GPU continuations remain the fallback for split boundaries.
        for (const auto& operation : batch.operations)
            if (operation.kind == Kind::Launch) {
                if (findMulti(operation)) {
                    if (operation.ordinal != ordinal + 1 || ++count > MaxLaunches)
                        throw std::runtime_error(
                            "Multi-effect held launch ordinal/capacity mismatch");
                    validateLiteralEnvelope(operation.effect);
                    ordinal = operation.ordinal;
                    continue;
                }
                bool registered = operation.program->bindingId == shaders_.whole2eaBinding,
                     resumeCovered = false, literalCovered = false;
                for (const auto& module : shaders_.programs)
                    if (module.bindingId == operation.program->bindingId) {
                        registered = true;
                        resumeCovered = module.canResume;
                        literalCovered = operation.resume ? module.resumeLiteralSourcePreserved
                                                          : module.freshLiteralSourcePreserved;
                    }
                if (!registered || (operation.resume && !resumeCovered) ||
                    (operation.program->literalSourcePreserved && !literalCovered) ||
                    operation.ordinal != ordinal + 1 || ++count > MaxLaunches)
                    throw std::runtime_error("Unregistered or unordered array-owner launch");
                validateLiteralEnvelope(operation.effect);
                ordinal = operation.ordinal;
            }
        for (const auto& operation : batch.operations) {
            if (operation.kind == Kind::Launch) {
                if (streamLaunch(operation)) {
                    if (!streamBuilder_.room(0, 1) || heldOperations_.size() == MaxOperations)
                        flushStream();
                    streamBuilder_.launch(operation);
                    heldOperations_.push_back(operation);
                    ++streamCounters_.eligible;
                    ++streamCounters_.eligibleBySelector[operation.orderedStream->selector];
                } else {
                    flushStream();
                    enqueueDirect(single(operation));
                    ++streamCounters_.declined;
                    const uint32_t selector =
                        operation.orderedStream ? operation.orderedStream->selector : 0u;
                    if (selector == 1u || selector == 2u)
                        ++streamCounters_.completeGpuBoundaryBySelector[selector];
                    else
                        ++streamCounters_.unknownSelectorBoundary;
                    if (operation.effect.type == LiteralEffect::Type::MaterialAD)
                        ++streamCounters_.adBoundary;
                    else if (operation.effect.type == LiteralEffect::Type::None)
                        ++streamCounters_.initBoundary;
                    const bool sameImage =
                        stream_
                            ? (operation.program->bindingId == stream_->exactImageBinding() &&
                               stream_->exactImage(operation.program->exactImage))
                            : boundary_ && (operation.program->bindingId == boundary_->binding() &&
                                            boundary_->image(operation.program->exactImage));
                    if (!sameImage)
                        ++streamCounters_.foreignBoundary;
                    if (operation.orderedStream && operation.orderedStream->inputCount != 39)
                        ++streamCounters_.non39Boundary;
                    logStream("launch_used_registered_complete_GPU_path");
                }
                lastAccepted_ = operation.ordinal;
            } else {
                // An identical CYCLE store commutes with held raw39 meshes:
                // stream inputs already have exact raw rows, and GPU UNPACK
                // never mutates CYCLE. Still record the full GPU register write
                // and publication check; only avoid splitting this mesh group.
                if (operation.kind == Kind::Control && operation.controlByte == 32u &&
                    operation.payload.size() == 4u) {
                    uint32_t bits = 0;
                    std::memcpy(&bits, operation.payload.data(), 4);
                    if (bits == cycleMirror_) {
                        enqueueDirect(single(operation));
                        ++streamCounters_.idempotentCycleWrites;
                        continue;
                    }
                }
                const uint32_t rows = reo_gpu_array_bridge::Builder::rawWriteRows(
                    operation, cycleMirror_, modeMirror_);
                if (rows) {
                    if (!streamBuilder_.room(rows) || heldOperations_.size() == MaxOperations ||
                        heldBytes_ + operation.payload.size() > MaxBatchBytes)
                        flushStream();
                    streamBuilder_.rawWrite(operation, cycleMirror_, modeMirror_);
                    heldOperations_.push_back(operation);
                    heldBytes_ += uint32_t(operation.payload.size());
                    streamCounters_.rawQwords += rows;
                } else {
                    flushStream();
                    enqueueDirect(single(operation));
                    if (operation.kind == Kind::Control && operation.payload.size() == 4) {
                        uint32_t bits = 0;
                        std::memcpy(&bits, operation.payload.data(), 4);
                        if (operation.controlByte == 32)
                            cycleMirror_ = bits;
                        if (operation.controlByte == 36)
                            modeMirror_ = bits;
                    }
                    logStream("control_or_unsupported_upload_closed_epoch");
                }
            }
        }
    }

    void requireOwner(uint64_t epoch, uint64_t generation) const {
        if (failed_)
            throw std::runtime_error("Resident GPU semantic owner failed");
        if (!whole_ || epoch != epoch_ || generation != generation_)
            throw std::runtime_error("Foreign/stale resident VIF GPU bank");
    }
    bool awaitingAuthenticFirstEntry() const noexcept {
        return authenticFirstEntryRequested() &&
               (!shaders_.parent.cold || !shaders_.parent.cold->capturedEntry);
    }
    void constructParent() {
        if (parent_)
            return;
        if (awaitingAuthenticFirstEntry())
            return;
        if (shaders_.natural.requested)
            shaders_.parent.session = reo_parent_natural::issueActualColdSession();
        if (shaders_.parent.enabled) {
            try {
                parent_ = std::make_unique<reo_parent_install::Service>(
                    device_, gs_, whole_, *unpack_, shaders_.parent, epoch_, generation_);
            } catch (...) {
                failed_ = true;
                throw;
            }
        }
        // Scoped-live natural binding is installed only after its authentic
        // entry image reached the actual initial upload fence below.
        if (shaders_.natural.requested && !authenticFirstEntryRequested()) {
            if (!parent_ || !shaders_.natural.actualRuntime)
                throw std::runtime_error(
                    "Natural owner binding requires actual persistent Service/Runtime");
            natural_ = std::make_shared<reo_parent_natural::NativeTarget>(
                *parent_, shaders_.parent.cold, shaders_.natural, shaders_.parent.session, epoch_);
            reo_parent_natural::installActualOwnerTarget(natural_);
        }
    }
    void cold(const Batch& batch) {
        if (whole_) {
            if (shaders_.parent.enabled && !parent_ && !awaitingAuthenticFirstEntry())
                throw std::runtime_error("Configured parent service failed initialization; "
                                         "CPU/native fallback forbidden");
            if (batch.cold)
                throw std::runtime_error(
                    "Authoritative resident bank cannot be reinitialized from CPU shadow");
            requireOwner(batch.epoch, batch.bankGeneration);
            return;
        }
        if (!batch.cold)
            throw std::runtime_error("First resident GPU batch requires cold raw banks");
        auto modules = shaders_.programs;
        if (modules.empty())
            modules.push_back({shaders_.whole2eaBinding, shaders_.whole2ea});
        whole_ = std::make_shared<ProgramBank>(device_, modules, batch.cold->state.data(),
                                               batch.cold->data.data());
        strip_ = std::make_unique<reo_gpu_pooled_strip::Strip>(device_, shaders_.strip);
        reo_gpu_vif_upload::ColdControl control{};
        control.row = batch.cold->row;
        control.column = batch.cold->column;
        control.cycle = batch.cold->cycle;
        control.mode = batch.cold->mode;
        control.mask = batch.cold->mask;
        unpack_ = std::make_unique<reo_gpu_vif_upload::ResidentVifUnpack>(
            device_, shaders_.unpack, whole_->data(), whole_->completion(), control);
        effects_ = std::make_unique<EffectValidate>(device_, shaders_.effectValidate);
        patch_ = std::make_unique<BytePatch>(device_, shaders_.bytePatch);
        epoch_ = batch.epoch;
        generation_ = batch.bankGeneration;
        cycleMirror_ = batch.cold->cycle;
        modeMirror_ = batch.cold->mode;
        constructParent();
    }
    static reo_gpu_path1_metadata::GpuEchoContract echo(const LiteralEffect& effect) {
        reo_gpu_path1_metadata::GpuEchoContract result{};
        static_assert(sizeof(result) == sizeof(effect.echo));
        std::memcpy(&result, effect.echo.data(), sizeof(result));
        return result;
    }
    static uint32_t validateLiteralEnvelope(const LiteralEffect& effect) {
        if (uint32_t(effect.type) > uint32_t(LiteralEffect::Type::MaterialAD))
            throw std::invalid_argument("Unknown resident literal event type");
        const auto contract = echo(effect);
        const uint32_t kind = effect.type == LiteralEffect::Type::Strip        ? 1u
                              : effect.type == LiteralEffect::Type::MaterialAD ? 2u
                                                                               : 0u;
        if (contract.kindCountFlags[0] != kind || contract.kindCountFlags[3])
            throw std::invalid_argument("Incorrect literal event echo kind");
        if (!kind) {
            for (const auto word : effect.echo)
                if (word)
                    throw std::invalid_argument("Init/noevent contract contains literal effects");
            return 0;
        }
        const auto& header = contract.qwords[0];
        if ((header[0] & 0xffff0000u) || !(header[0] & 32768u) || ((header[1] >> 26u) & 3u) ||
            header[3])
            throw std::invalid_argument("Unproved literal GIF command envelope");
        if (kind == 1) {
            if (((header[1] >> 28u) & 15u) != 3u || ((header[1] >> 14u) & 1u) != 1u ||
                header[2] != 0x412u || !effect.vertexCapacity || effect.vertexCapacity > 256 ||
                contract.kindCountFlags[1] > 256)
                throw std::invalid_argument("Unproved literal strip command envelope");
        } else {
            if (((header[1] >> 28u) & 15u) != 1u || ((header[1] >> 14u) & 1u) != 0u ||
                header[2] != 14 || header[0] != (32768u | 6u))
                throw std::invalid_argument("Unproved literal AD6 command envelope");
            constexpr uint32_t addresses[6]{0x3b, 0x14, 0x06, 0x08, 0x34, 0x36};
            for (unsigned q = 0; q < 6; ++q)
                if (contract.qwords[q + 1][2] != addresses[q] || contract.qwords[q + 1][3])
                    throw std::invalid_argument("Unproved literal AD6 address envelope");
        }
        return kind;
    }
    void prepareStaging(size_t bytes) {
        if (staging_ && stagingBytes_ >= bytes)
            return;
        Vulkan::BufferCreateInfo info{};
        info.domain = Vulkan::BufferDomain::CachedHost;
        info.size = bytes;
        info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        staging_ = device_.create_buffer(info);
        stagingBytes_ = bytes;
        if (!staging_)
            throw std::runtime_error("Resident completion/read boundary staging allocation failed");
    }
    void preflightParent(const Batch& batch) const {
        if (parent_)
            parent_->requireHealthy();
        for (const auto& op : batch.operations)
            if (op.kind == Kind::OpaqueLeaseUnpack) {
                if (!parent_)
                    throw std::runtime_error(
                        "Opaque parent upload has no persistent factory service");
                parent_->validateUpload(op);
            }
    }
    void appendUploads(Vulkan::CommandBuffer& cmd, const std::vector<const Operation*>& uploads) {
        for (const auto* operation : uploads)
            if (operation->kind == Kind::Control)
                unpack_->enqueueControlWrite(cmd, operation->controlByte, operation->payload.data(),
                                             uint32_t(operation->payload.size()));
            else if (operation->kind == Kind::Unpack)
                unpack_->enqueue(cmd, operation->command, operation->latchedTops,
                                 operation->payload.data(), uint32_t(operation->payload.size()));
            else if (operation->kind == Kind::OpaqueLeaseUnpack) {
                if (!parent_)
                    throw std::runtime_error("Opaque parent upload has no actual owner");
                parent_->appendUpload(cmd, *operation);
            } else if (operation->kind == Kind::DataWrite)
                patch_->enqueue(cmd, *whole_, whole_->data(), operation->controlByte,
                                operation->payload.data(), uint32_t(operation->payload.size()));
            else if (operation->kind == Kind::ControlByteWrite)
                patch_->enqueue(cmd, *whole_, unpack_->controls(), operation->controlByte,
                                operation->payload.data(), uint32_t(operation->payload.size()));
            else
                throw std::logic_error("Not an upload/control operation");
    }
    reo_gpu_static_consumer::LivePath* findMulti(const Operation& op) const {
        for (const auto& path : multi_)
            if (path->covers(op))
                return path.get();
        return nullptr;
    }
    const Vulkan::Buffer& receiptBank(const Job& job) const {
        return job.staticGroup ? *job.staticGroup->output.receipts
               : job.multi     ? *job.multi->receipt
                               : pool_->bank(reo_gpu_mesh_pool::MeshPool::CompletionTape);
    }
    VkDeviceSize receiptOffset(const Job& job) const {
        return job.staticGroup ? uint64_t(job.staticLocal) * 48u
               : job.multi     ? 0u
                               : job.slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape];
    }
    Job* latestTail() {
        for (auto i = jobs_.rbegin(); i != jobs_.rend(); ++i)
            if (i->multi || i->tail)
                return &*i;
        return nullptr;
    }
    const Vulkan::Buffer& tailCertificate(const Job& job) const {
        return job.multi ? job.multi->item.output->bank(3) : *job.tail;
    }
    bool publishTail(Job& job, const uint32_t* certificate, const Retired& receipt) {
        if (job.tailPublished)
            return true;
        if (receipt.status || !receipt.ended || receipt.epoch != epoch_ ||
            receipt.bankGeneration != generation_ || receipt.ordinal != job.ordinal ||
            certificate[0] || certificate[1] != 1u || certificate[4] != uint32_t(generation_) ||
            certificate[5] != 0u || certificate[6] != reo_gpu_static_consumer::Magic ||
            certificate[7] != 1u || certificate[8] != 1u || certificate[9] != 1u ||
            certificate[10] != 1u)
            return false;
        bool accepted =
            job.multi ? job.multiPath->retire(*job.multi, receipt)
                      : gs_.adopt_resident_gpu_tail(&device_, job.tail,
                                                    reo_gpu_static_consumer::FinalQueueBase * 4u,
                                                    epoch_, generation_, job.finalPrim, true);
        if (accepted)
            job.tailPublished = true;
        return accepted;
    }

  public:
    // Complete source protocol is not an enrollment/fidelity certificate. Full
    // reached shaders, consumers and producer routes still need root proof.
    static constexpr bool FullProtocolCoverage = false;
    ParallelArrayOwner(Vulkan::Device& device, ParallelGS::GSInterface& gs,
                       ArrayShaderBundle shaders)
        : device_(device), gs_(gs), shaders_(std::move(shaders)) {
        if (shaders_.natural.authenticColdComponentEnrollment &&
            (!shaders_.natural.requested || !shaders_.parent.enabled ||
             shaders_.parent.tier != reo_parent_live::AdmissionTier::OfflineComponent ||
             (shaders_.natural.authenticColdComponentEntry != 0x196010u &&
              shaders_.natural.authenticColdComponentEntry != 0x197900u &&
              shaders_.natural.authenticColdComponentEntry != 0x18f6a0u &&
              !reo_gpu_upstream::Viewport::supports(
                  shaders_.natural.authenticColdComponentEntry)) ||
             !shaders_.natural.authenticColdComponentBody || shaders_.parent.gates.ready() ||
             shaders_.parent.producerProofs.complete() || shaders_.natural.coverage.complete()))
            throw std::invalid_argument("Cold component admission requires an exact original "
                                        "Setter entry and closed source gates");
        if (shaders_.parent.enabled) {
            if (awaitingAuthenticFirstEntry())
                reo_parent_install::Service::validateDeferredConfiguration(shaders_.parent);
            else
                reo_parent_install::Service::validateConfiguration(shaders_.parent);
        }
        if ((shaders_.programs.empty() &&
             (!shaders_.whole2eaBinding || shaders_.whole2ea.empty())) ||
            shaders_.strip.empty() || shaders_.unpack.empty() || shaders_.effectValidate.empty() ||
            shaders_.bytePatch.empty())
            throw std::invalid_argument("Resident owner requires immutable shader bindings");
        const char* grouped = std::getenv("REO_GS_RESIDENT_MESH_BATCH");
        gs_.set_resident_material_batching(grouped && grouped[0] == '1');
        const char* streamLog = std::getenv("REO_GPU_ORDERED_OWNER_LOG");
        if (streamLog && *streamLog) {
            if (std::filesystem::exists(streamLog))
                throw std::runtime_error("Preserve existing ordered-owner log");
            streamLog_.open(streamLog);
            if (!streamLog_)
                throw std::runtime_error("Ordered-owner log unavailable");
        }
        if (!shaders_.pooledTail.empty())
            pooledTail_ =
                std::make_unique<reo_gpu_static_consumer::PooledTail>(device_, shaders_.pooledTail);
        const auto installMulti = [&](const reo_gpu_static_consumer::LiveBundle& bundle) {
            if (!bundle.activationRequested)
                return;
            for (const auto& installed : multi_)
                if (installed->binding() == bundle.binding)
                    throw std::invalid_argument("Duplicate exact multi-effect binding");
            multi_.push_back(
                std::make_unique<reo_gpu_static_consumer::LivePath>(device_, gs_, bundle));
            if (!pooledTail_)
                pooledTail_ = std::make_unique<reo_gpu_static_consumer::PooledTail>(
                    device_, bundle.pooledTail);
        };
        installMulti(shaders_.multiEffect);
        for (const auto& bundle : shaders_.multiEffects)
            installMulti(bundle);
        if (!pooledTail_)
            throw std::invalid_argument(
                "Projected strip ownership requires the pinned pooled-tail shader");
        if (shaders_.orderedStream.activationRequested)
            stream_ =
                std::make_unique<reo_gpu_array_bridge::Pipeline>(device_, shaders_.orderedStream);
        if (shaders_.boundary.activationRequested)
            boundary_ = std::make_unique<reo_gpu_boundary::Pipeline>(
                device_, shaders_.boundary, reo_gpu_boundary::Scope::ScopedLive);
        if (shaders_.staticGroup.activationRequested) {
            staticBuilder_ =
                std::make_unique<reo_gpu_static_group::TypedBuilder>(shaders_.staticGroup.program);
            staticGroup_ = std::make_unique<reo_gpu_static_group::GroupAdapter>(
                device_, shaders_.staticGroup.modules, shaders_.staticGroup.capacity,
                shaders_.staticGroup.scope, shaders_.staticGroup.proofs,
                shaders_.staticGroup.exporterProofs);
            staticGroup_->prewarm();
            reo_gpu_static_group::prewarmPreviewSource(device_);
        }
        logStream(stream_ ? "ordered_stream_armed_scoped_proofs" : "ordered_stream_default_off");
        logStream(boundary_ ? "staged_boundary_armed_scoped_proofs"
                            : "staged_boundary_default_off");
    }
    ~ParallelArrayOwner() override {
        if (natural_) {
            natural_->ownerStopped();
            reo_parent_natural::stopActualOwnerTarget(natural_);
        }
        try {
            if (parent_) {
                gs_.flush();
                device_.wait_idle();
            }
            drainBeforeEpochReset();
        } catch (...) {
        }
    }
    reo_parent_install::Service* parentHookTarget() {
        if (failed_)
            throw std::runtime_error("Parent frontier reached a failed VU owner");
        flushAllHeld();
        if (parent_)
            parent_->requireHealthy();
        return parent_.get();
    }
    bool authenticFirstEntryRequested() const noexcept override {
        return shaders_.natural.requested &&
               (shaders_.parent.tier == reo_parent_live::AdmissionTier::ScopedLive ||
                (shaders_.parent.tier == reo_parent_live::AdmissionTier::OfflineComponent &&
                 shaders_.natural.authenticColdComponentEnrollment));
    }
    void enrollFirstGraphicsEntry(
        const std::shared_ptr<const reo_parent_natural::ColdEntry>& retained) override {
        if (!retained)
            throw std::invalid_argument("Null first-entry capture");
        const auto& capture = *retained;
        if (!authenticFirstEntryRequested() || !shaders_.parent.enabled || failed_)
            throw std::runtime_error(
                "Actual owner is not configured for authentic first-entry enrollment");
        capture.requireOnOwner();
        if (shaders_.natural.authenticColdComponentEnrollment &&
            (capture.originalEntry() != shaders_.natural.authenticColdComponentEntry ||
             capture.originalBodyIdentity() != shaders_.natural.authenticColdComponentBody ||
             capture.runtime().lookupFunction(capture.originalEntry()) !=
                 capture.originalBodyIdentity()))
            throw std::runtime_error(
                "Cold component capture differs from its actual registered original body");
        if (shaders_.natural.actualRuntime && shaders_.natural.actualRuntime != &capture.runtime())
            throw std::runtime_error(
                "First-entry source differs from the configured actual Runtime");
        if (natural_) {
            natural_->requireHealthy();
            if (natural_->runtimeIdentity() != &capture.runtime() ||
                natural_->ramIdentity() != capture.ramIdentity() ||
                natural_->sprIdentity() != capture.sprIdentity() ||
                natural_->contextIdentity() != &capture.context() || epoch_ != capture.epoch() ||
                generation_ != capture.generation())
                throw std::runtime_error(
                    "Existing first-entry owner has different source/VU identities");
            return;
        }
        if (parent_ || !awaitingAuthenticFirstEntry())
            throw std::runtime_error("First-entry parent source was already seeded");
        try {
            auto source = std::make_shared<reo_parent_install::ColdSource>();
            source->ram = capture.ramIdentity();
            source->spr = capture.sprIdentity();
            source->actualContext = &capture.context();
            source->lifetime = capture.contextLifetime();
            // The FIFO retains the exact same immutable capture allocation.
            source->capturedEntry = retained;
            if (!source->capturedEntry || source->capturedEntry.get() != &capture)
                throw std::runtime_error("First-entry owner lost its retained immutable capture");
            shaders_.parent.cold = std::move(source);
            shaders_.natural.actualRuntime = &capture.runtime();
            if (whole_) {
                if (capture.vuCold())
                    throw std::runtime_error("Existing GPU VU authority cannot be reseeded");
                requireOwner(capture.epoch(), capture.generation());
                constructParent();
            } else {
                if (!capture.vuCold())
                    throw std::runtime_error(
                        "First-entry new VU owner has no current CPU-authoritative cold bank");
                Batch initial{};
                initial.epoch = capture.epoch();
                initial.bankGeneration = capture.generation();
                initial.cold = capture.vuCold();
                cold(initial);
            }
            if (!parent_)
                throw std::runtime_error(
                    "Authentic first-entry did not construct the persistent Service");
            parent_->finishFirstEntryUploadOnOwner(*unpack_);
            capture.requireOnOwner();
            natural_ = std::make_shared<reo_parent_natural::NativeTarget>(
                *parent_, shaders_.parent.cold, shaders_.natural, shaders_.parent.session, epoch_);
            reo_parent_natural::installActualOwnerTarget(natural_);
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    void
    parentControl(const std::function<void(reo_parent_natural::ControlTarget&)>& call) override {
        if (!natural_ || !call)
            throw std::runtime_error("Actual cold owner has no connected natural target");
        natural_->requireHealthy();
        call(*natural_);
    }
    void enqueue(const Batch& batch) override {
        if (parent_)
            parent_->requireHealthy();
        if (staticGroup_)
            acceptStaticBatch(batch);
        else if (stream_ || boundary_)
            acceptStream(batch);
        else {
            enqueueDirect(batch);
            lastAccepted_ = lastEnqueued_;
        }
    }
    void enqueueDirect(const Batch& batch) {
        owner_timing::Scope timing(owner_timing::Enqueue);
        validate(batch);
        // Validate whole command batch BEFORE cold bank allocation or mutation.
        uint64_t ordinal = lastEnqueued_;
        size_t count = jobs_.size();
        for (const auto& op : batch.operations)
            if (op.kind == Kind::Launch) {
                // A configured binding cannot fall through to an old scalar body
                // when its complete immutable image differs from that binding.
                for (const auto& path : multi_)
                    if (path->binding() == op.program->bindingId &&
                        !path->image(op.program->exactImage))
                        throw std::invalid_argument(
                            "Configured multi-effect binding has a different exact image");
                if (auto* path = findMulti(op)) {
                    if (op.ordinal != ordinal + 1 || ++count > MaxLaunches)
                        throw std::runtime_error("Multi-effect launch ordinal/capacity mismatch");
                    validateLiteralEnvelope(op.effect);
                    ordinal = op.ordinal;
                    continue;
                }
                bool registered = op.program->bindingId == shaders_.whole2eaBinding,
                     resumeCovered = false, literalReuseCovered = false;
                for (const auto& module : shaders_.programs)
                    if (module.bindingId == op.program->bindingId) {
                        registered = true;
                        resumeCovered = module.canResume;
                        literalReuseCovered = op.resume ? module.resumeLiteralSourcePreserved
                                                        : module.freshLiteralSourcePreserved;
                    }
                if (!registered || (op.resume && !resumeCovered) ||
                    (op.program->literalSourcePreserved && !literalReuseCovered) ||
                    op.effect.vertexCapacity > 256 ||
                    (op.effect.type == LiteralEffect::Type::Strip && !op.effect.vertexCapacity) ||
                    op.ordinal != ordinal + 1 || ++count > MaxLaunches)
                    throw std::runtime_error(
                        "Resident owner cannot execute this full program/event class");
                validateLiteralEnvelope(op.effect);
                ordinal = op.ordinal;
            }
        cold(batch);
        requireOwner(batch.epoch, batch.bankGeneration);
        preflightParent(batch);
        std::vector<const Operation*> uploads;
        for (const auto& op : batch.operations) {
            if (op.kind != Kind::Launch) {
                uploads.push_back(&op);
                continue;
            }

            if (auto* path = findMulti(op)) {
                // Validate exact full image/material BEFORE any raw PRE write
                // or GPU-authority mutation. The old one-event classifier is
                // deliberately bypassed for this private multi-effect path.
                auto job = [&] {
                    owner_timing::Scope allocation(owner_timing::Allocate);
                    return path->allocate(op, epoch_, generation_);
                }();
                if (!gs_.prepare_resident_recording_projected())
                    throw std::runtime_error("Multi-effect recording overlaps ordinary input");
                ParallelGS::ResidentMaterial material{};
                if (!gs_.prepare_resident_material_projected(
                        256u, (op.effect.echo[5] >> 15u) & 2047u, material))
                    throw std::runtime_error("Multi-effect literal material domain declined");
                gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                    owner_timing::Scope record(owner_timing::Record);
                    appendUploads(cmd, uploads);
                    uploads.clear();
                    path->record(cmd, *whole_, op, *job, material);
                    cmd.buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd.buffer_barrier(*job->receipt, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT);
                    cmd.copy_buffer(*job->receipt, 0, whole_->completion(), 0, 48);
                    // Preserve this job's selector NOW: producer scratch is shared
                    // and will contain a later job by retirement. Word10 of a
                    // multi receipt is reserved and not a completion predicate.
                    if (owner_timing::counters.enabled) {
                        const auto& results = *job->producerBanks[3];
                        cmd.buffer_barrier(results, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                           VK_ACCESS_2_MEMORY_WRITE_BIT,
                                           VK_PIPELINE_STAGE_TRANSFER_BIT,
                                           VK_ACCESS_2_TRANSFER_READ_BIT);
                        cmd.buffer_barrier(*job->receipt, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                           VK_ACCESS_2_TRANSFER_WRITE_BIT,
                                           VK_PIPELINE_STAGE_TRANSFER_BIT,
                                           VK_ACCESS_2_TRANSFER_WRITE_BIT);
                        cmd.copy_buffer(*job->receipt, 40u, results, (64u + 10u) * 4u, 4u);
                    }
                });
                {
                    owner_timing::Scope submit(owner_timing::DrawSubmit);
                    path->submit(*job, material);
                }
                jobs_.push_back({op.ordinal, {}, 0u, false, false, job});
                jobs_.back().multiPath = path;
                lastEnqueued_ = op.ordinal;
                needsPublicationCheck_ = true;
                continue;
            }
            if (!pool_)
                pool_ = std::make_unique<reo_gpu_mesh_pool::MeshPool>(device_, MaxLaunches, epoch_);
            const auto slice = pool_->allocate();
            const auto contract = echo(op.effect);
            const uint32_t expectedKind = validateLiteralEnvelope(op.effect);
            // Nonempty strip PRE is projected for material preparation. Its
            // actual PRIM/queue ownership changes only after the real GPU tail
            // certificate. AD and init do not fabricate a queue reset.
            const uint32_t literalPrim = (contract.qwords[0][1] >> 15u) & 2047u;
            // Completed ordinary draws still flush via their existing tracker.
            // Incomplete IMAGE/no-PRE input retains the old admission guard.
            if (!gs_.prepare_resident_recording_projected())
                throw std::runtime_error(
                    "Resident recording overlaps incomplete ordinary GS input");
            ParallelGS::ResidentMaterial material{};
            reo_gpu_pooled_strip::Parameters parameters{};
            if (expectedKind == 1u) {
                if (!gs_.prepare_resident_material_projected(op.effect.vertexCapacity, literalPrim,
                                                             material))
                    throw std::runtime_error(
                        "Unsupported resident material/feedback/register state");
                ParallelGS::RegisterState registers{};
                if (material.registers.size() != sizeof(registers))
                    throw std::logic_error("Projected material register ABI mismatch");
                std::memcpy(&registers, material.registers.data(), sizeof(registers));
                const auto& context = registers.ctx[registers.prim.desc.CTXT];
                parameters.limits = {op.effect.vertexCapacity, 0, op.effect.vertexCapacity, 0};
                parameters.offsetScissorLo = {
                    int32_t(context.xyoffset.desc.OFX), int32_t(context.xyoffset.desc.OFY),
                    int32_t(context.scissor.desc.SCAX0), int32_t(context.scissor.desc.SCAY0)};
                parameters.scissorHi = {int32_t(context.scissor.desc.SCAX1),
                                        int32_t(context.scissor.desc.SCAY1), 0, 0};
                std::memcpy(parameters.material.data(), &material.primitive.state, 24);
            }
            auto tail = (pooledTail_ && expectedKind == 1u) ? pooledTail_->allocate()
                                                            : Vulkan::BufferHandle{};
            const reo_gpu_whole_pooled::Push push{op.startPC,          op.maxPairs, op.top, op.itop,
                                                  op.resume ? 4u : 0u, 256,         0,      0};
            // Synchronous recorder borrows the GS-owned triangle_setup_cmd.
            // Each producer is before its native triangle setup; binning/direct
            // follow in the renderer's existing submission order. No command
            // handle or lambda escapes, and no per-launch queue submit occurs.
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                appendUploads(cmd, uploads);
                uploads.clear();
                if (stagedBoundary(op)) {
                    // Mixed39 epochs were flushed before this direct boundary.
                    // Pending raw VIF writes execute FIRST against authority.
                    cmd.buffer_barrier(whole_->command(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                       VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                       VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT);
                    cmd.update_buffer_inline(whole_->command(), 0, sizeof(contract), &contract);
                    cmd.buffer_barrier(whole_->command(), VK_PIPELINE_STAGE_TRANSFER_BIT,
                                       VK_ACCESS_2_TRANSFER_WRITE_BIT,
                                       VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                       VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
                    reo_gpu_boundary::Request request{};
                    request.entryPC = op.startPC;
                    request.top = op.top;
                    request.itop = op.itop;
                    request.operation = op.resume ? 4u : 0u;
                    request.capacity = 256;
                    std::memcpy(&request.echo, op.effect.echo.data(), sizeof(op.effect.echo));
                    const reo_gpu_boundary::Authority authority{
                        &device_, &whole_->state(), &whole_->data(), &whole_->completion()};
                    boundary_->enqueue(cmd, authority, request);
                    reo_gpu_boundary::copyOutputs(cmd, *boundary_, authority, *pool_, slice);
                } else
                    whole_->enqueue(cmd, op.program->bindingId, push, contract, *pool_, slice);
                effects_->enqueue(cmd, *whole_, *pool_, slice);
                if (expectedKind == 1u)
                    strip_->enqueue(cmd, *pool_, slice, parameters, whole_->completion());
                if (tail)
                    pooledTail_->enqueue(
                        cmd, *pool_, slice, whole_->completion(), *tail, uint32_t(generation_),
                        (contract.qwords[0][1] >> 15u) & 2047u, op.resume ? 4u : 0u);
            });
            if (expectedKind == 1u) {
                if (!gs_.submit_resident_material_projected(
                        material, strip_->inputs(*pool_, slice, op.effect.vertexCapacity)))
                    throw std::runtime_error(
                        "Resident material changed between command preparation/submission");
            } else if (expectedKind == 2u) {
                constexpr uint32_t addresses[6]{0x3b, 0x14, 0x06, 0x08, 0x34, 0x36};
                // Only write-only, literal command state is prequeued. Every
                // externally visible GS boundary MUST first check the GPU
                // sticky verifier, and subsequent mesh expansion is gated by
                // it. This must not be enrolled without those adapter hooks.
                for (unsigned q = 0; q < 6; ++q) {
                    const auto& literal = contract.qwords[q + 1];
                    if (literal[2] != addresses[q] || literal[3])
                        throw std::runtime_error("Unproved literal AD command envelope");
                }
                // Prequeue the exact source-certified raw command packet.
                // The whole address list and PRE0 envelope were validated
                // before mutation. Ordinary GIF parsing also supplies the
                // genuine nonempty-tag Q1/path effect while retaining the
                // preceding GPU queue and unresolved ST/RGBA lease. Existing
                // GPU EffectValidate/publication guards remain mandatory.
                gs_.gif_transfer(0, contract.qwords.data(), 112u);
            }
            needsPublicationCheck_ = true;
            const bool boundaryJob = stagedBoundary(op);
            jobs_.push_back({op.ordinal, slice, op.orderedStream ? op.orderedStream->selector : 0u,
                             false, boundaryJob, nullptr, tail,
                             (contract.qwords[0][1] >> 15u) & 2047u, false});
            lastEnqueued_ = op.ordinal;
            if (boundaryJob)
                ++streamCounters_.stagedBoundaryRecorded;
        }
        if (!uploads.empty()) {
            if (!gs_.prepare_resident_recording_projected())
                throw std::runtime_error("Resident upload overlaps incomplete ordinary GS input");
            gs_.record_resident_command(
                [&](Vulkan::CommandBuffer& cmd) { appendUploads(cmd, uploads); });
            needsPublicationCheck_ = true;
        }
    }
    std::vector<Retired> retire(Barrier reason, uint64_t epoch, uint64_t generation) override {
        owner_timing::Scope timing(owner_timing::Retire);
        requireOwner(epoch, generation);
        flushAllHeld();
        if (timing.active) {
            const auto r = static_cast<unsigned>(reason);
            if (r < 5u)
                ++owner_timing::counters.retireReasons[r];
            ++owner_timing::counters
                  .retireKinds[jobs_.empty() ? (needsPublicationCheck_ ? 1u : 0u) : 2u];
        }
        // Nothing was enqueued since an ACTUAL validated retirement. Repeated
        // MMIO polling has no new receipt to produce or VU work to wait for.
        // Dirty upload-only prefixes and all launches still take the real fence;
        // independent parent/natural/static protocols retain their own barriers.
        if (!parent_ && !natural_ && !staticGroup_ && !failed_ && jobs_.empty() &&
            !needsPublicationCheck_)
            return {};
        // Genuine explicit guest boundary, once per DMA/wait rather than mesh.
        // This real fence covers producer/export/XG admission and metadata.
        // Immutable draw/image buffers remain owned by the GS render timeline,
        // and the final tail is retained separately after genuine retirement.

        auto* latest = latestTail();
        const size_t bytes = jobs_.size() * 64u + 4u + (latest ? 44u : 0u);
        prepareStaging(bytes);
        auto fence = [&] {
            owner_timing::Scope submit(owner_timing::CompletionSubmit);
            return gs_.submit_resident_completion([&](Vulkan::CommandBuffer& completionCmd) {
                auto* cmd = &completionCmd;
                cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                    VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                    VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
                for (size_t i = 0; i < jobs_.size(); ++i) {
                    if (jobs_[i].staticGroup) {
                        const auto& run = *jobs_[i].staticGroup;
                        const auto& receipt = *run.output.receipts;
                        const auto& cert = run.output.triangles->bank(3);
                        cmd->buffer_barrier(
                            receipt, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                        cmd->buffer_barrier(
                            cert, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                        cmd->copy_buffer(*staging_, i * 64u, receipt,
                                         uint64_t(jobs_[i].staticLocal) * 48u, 48);
                        const uint32_t zeros[4]{};
                        cmd->update_buffer_inline(*staging_, i * 64u + 48u, 16, zeros);
                        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                            VK_ACCESS_2_TRANSFER_WRITE_BIT,
                                            VK_PIPELINE_STAGE_TRANSFER_BIT,
                                            VK_ACCESS_2_TRANSFER_WRITE_BIT);
                        cmd->copy_buffer(*staging_, i * 64u + 48u, cert,
                                         uint64_t(jobs_[i].staticLocal) * 4192u, 4);
                        continue;
                    }
                    if (jobs_[i].multi) {
                        const auto& receipt = *jobs_[i].multi->receipt;
                        const auto& cert = tailCertificate(jobs_[i]);
                        cmd->buffer_barrier(
                            receipt, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                        cmd->buffer_barrier(
                            cert, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                        cmd->copy_buffer(*staging_, i * 64u, receipt, 0, 48);
                        const uint32_t zeros[4]{};
                        cmd->update_buffer_inline(*staging_, i * 64u + 48u, 16, zeros);
                        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                            VK_ACCESS_2_TRANSFER_WRITE_BIT,
                                            VK_PIPELINE_STAGE_TRANSFER_BIT,
                                            VK_ACCESS_2_TRANSFER_WRITE_BIT);
                        cmd->copy_buffer(*staging_, i * 64u + 48u, cert, 0, 4);
                        cmd->copy_buffer(*staging_, i * 64u + 52u, cert, 48, 4);
                        continue;
                    }
                    if (!pool_)
                        throw std::logic_error("Missing actual native receipt pool");
                    const auto& slice = jobs_[i].slice;
                    pool_->validate(slice);
                    for (const auto binding : {reo_gpu_mesh_pool::MeshPool::CompletionTape,
                                               reo_gpu_mesh_pool::MeshPool::ExpansionStatus})
                        cmd->buffer_barrier(
                            pool_->bank(binding), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd->copy_buffer(*staging_, i * 64u,
                                     pool_->bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                                     slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape],
                                     48);
                    cmd->copy_buffer(*staging_, i * 64u + 48u,
                                     pool_->bank(reo_gpu_mesh_pool::MeshPool::ExpansionStatus),
                                     slice.offsets[reo_gpu_mesh_pool::MeshPool::ExpansionStatus],
                                     16);
                }
                cmd->buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                    VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                    VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd->copy_buffer(*staging_, jobs_.size() * 64u, whole_->completion(), 32, 4);
                if (latest) {
                    const auto& cert = tailCertificate(*latest);
                    cmd->buffer_barrier(cert, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                        VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                        VK_PIPELINE_STAGE_TRANSFER_BIT,
                                        VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd->copy_buffer(*staging_, jobs_.size() * 64u + 4u, cert, 0, 44);
                }

                cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                    VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                    VK_ACCESS_2_HOST_READ_BIT);
            });
        }();
        if (parent_)
            parent_->sealActualUploads(fence);
        {
            owner_timing::Scope wait(owner_timing::FenceWait);
            fence->wait();
        }
        retireParentUploads(fence);
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Actual GPU completion metadata mapping failed");
        std::vector<Retired> results;
        results.reserve(jobs_.size());
        uint32_t globalError = 0;
        bool capturedLocalFailure = false;
        std::memcpy(&globalError, mapped + jobs_.size() * 64u, 4);
        for (size_t i = 0; i < jobs_.size(); ++i) {
            uint32_t words[16]{};
            std::memcpy(words, mapped + i * 64u, 64);
            if (jobs_[i].multi)
                jobs_[i].multiPath->reportTiming(*jobs_[i].multi);
            if (owner_timing::counters.enabled && jobs_[i].multi) {
                const auto route = words[10];
                ++owner_timing::counters.routes[route < 4u ? route : 0u];
            }
            uint32_t error = words[0]    ? words[0]
                             : words[8]  ? words[8]
                             : words[12] ? words[12]
                                         : globalError;
            if (jobs_[i].staticGroup) {
                const auto& run = *jobs_[i].staticGroup;
                if (run.output.epoch != epoch_ || run.output.bankGeneration != generation_ ||
                    run.output.launchOrdinals.at(jobs_[i].staticLocal) != jobs_[i].ordinal ||
                    words[11] != jobs_[i].staticLocal || (words[10] != 1u && words[10] != 2u))
                    error = error ? error : 87u;
                if (!error) {
                    ++staticCounters_.retired;
                    staticCounters_.inputVertices += words[9];
                    if (jobs_[i].staticLocal == 0) {
                        if (words[10] == 1u)
                            ++staticCounters_.fastGroups;
                        else
                            ++staticCounters_.completeGpuGroups;
                    }
                }
            }
            if (parent_)
                parent_->observeOwnerSticky(error);
            results.push_back({epoch_, generation_, jobs_[i].ordinal, words[1], words[6], error,
                               words[5] != 0, false});
            // Global sticky invalidates the batch but does not identify its
            // culprit. Select the first independently failed local receipt.
            if ((words[0] || words[8] || words[12]) && !capturedLocalFailure) {
                capturedLocalFailure = true;
                std::fprintf(stderr,
                             "[GPU-ARRAY-FIRST-LOCAL-FAILURE] ordinal=%llu error=%u global=%u "
                             "multi=%u receipt=",
                             static_cast<unsigned long long>(jobs_[i].ordinal), error, globalError,
                             unsigned(bool(jobs_[i].multi)));
                for (auto word : words)
                    std::fprintf(stderr, " %08x", word);
                std::fprintf(stderr, "\n");
                if (jobs_[i].multi)
                    jobs_[i].multiPath->captureFailure(*jobs_[i].multi);
            }
            failed_ |= error != 0;
            if (!error && jobs_[i].array && (jobs_[i].selector == 1u || jobs_[i].selector == 2u))
                streamCounters_.actualFastVertices[jobs_[i].selector] += words[9];
            if (!error && jobs_[i].boundary) {
                ++streamCounters_.stagedBoundaryRetired;
                streamCounters_.boundaryFastVertices += words[9];
                if (words[10] == 1u)
                    ++streamCounters_.specializedBoundaryControls;
                if (words[10] == 2u)
                    ++streamCounters_.actualBoundaryGenericFallbacks;
            }
        }
        if (globalError && !capturedLocalFailure)
            std::fprintf(stderr, "[GPU-ARRAY-UNLOCALIZED-FAILURE] global=%u jobs=%zu\n",
                         globalError, jobs_.size());
        if (latest && !latest->tailPublished) {
            const auto index = size_t(latest - jobs_.data());
            const auto* cert = reinterpret_cast<const uint32_t*>(mapped + jobs_.size() * 64u + 4u);
            if (globalError || !publishTail(*latest, cert, results[index])) {
                if (!failed_) {
                    std::fprintf(stderr,
                                 "[GPU-ARRAY-TAIL-FAILURE] ordinal=%llu global=%u receiptStatus=%u "
                                 "ended=%u certificate=",
                                 static_cast<unsigned long long>(latest->ordinal), globalError,
                                 results[index].status, unsigned(results[index].ended));
                    for (unsigned c = 0; c < 11; ++c)
                        std::fprintf(stderr, " %08x", cert[c]);
                    std::fprintf(stderr, "\n");
                    if (latest->multi)
                        latest->multiPath->captureFailure(*latest->multi);
                }
                results[index].status = results[index].status ? results[index].status : 87u;
                failed_ = true;
            }
        }
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
        if (parent_)
            parent_->observeOwnerSticky(globalError);
        failed_ |= globalError != 0;
        if (globalError && jobs_.empty())
            throw std::runtime_error("Resident UNPACK/control GPU bank failed");
        if (!jobs_.empty())
            lastRetired_ = jobs_.back().ordinal;
        logStream("actual_device_metadata_retired");
        jobs_.clear();
        pool_.reset();
        needsPublicationCheck_ = false;
        return results;
    }
    void readData(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        if (!whole_ || !destination || !bytes || offset >= DataBytes || bytes > DataBytes - offset)
            throw std::out_of_range("Explicit guest resident bank read bounds");
        if (!heldOperations_.empty() || !staticHeld_.empty() || !jobs_.empty())
            throw std::logic_error("Guest bank read before actual semantic retirement");
        const uint32_t aligned = offset & ~3u, end = (offset + bytes + 3u) & ~3u,
                       size = end - aligned;
        prepareStaging(size);
        gs_.flush();
        auto cmd = device_.request_command_buffer();
        cmd->buffer_barrier(whole_->data(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, 0, whole_->data(), aligned, size);
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        {
            owner_timing::Scope submit(owner_timing::UploadSubmit);
            device_.submit(cmd, &fence);
        }
        {
            owner_timing::Scope wait(owner_timing::FenceWait);
            fence->wait();
        }
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Explicit guest VU bank read mapping failed");
        std::memcpy(destination, mapped + offset - aligned, bytes);
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
    }
    void readControls(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        if (!unpack_ || !destination || !bytes || offset >= 48 || bytes > 48 - offset)
            throw std::out_of_range("Explicit resident VIF control read bounds");
        if (!heldOperations_.empty() || !staticHeld_.empty() || !jobs_.empty())
            throw std::logic_error("VIF control read before actual semantic retirement");
        const uint32_t aligned = offset & ~3u, end = (offset + bytes + 3u) & ~3u,
                       size = end - aligned;
        prepareStaging(size);
        gs_.flush();
        auto cmd = device_.request_command_buffer();
        cmd->buffer_barrier(unpack_->controls(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, 0, unpack_->controls(), aligned, size);
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        {
            owner_timing::Scope submit(owner_timing::UploadSubmit);
            device_.submit(cmd, &fence);
        }
        {
            owner_timing::Scope wait(owner_timing::FenceWait);
            fence->wait();
        }
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Resident VIF control read mapping failed");
        std::memcpy(destination, mapped + offset - aligned, bytes);
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
    }
    // Architectural bank exchange for incremental VU execution. Graphical
    // queue/register leases remain on the GS Device; a VU handoff must not
    // replace them with the CPU's stale vertex/attribute shadows.
    void importHandoff(const Handoff& handoff) override {
        owner_timing::Scope timing(owner_timing::Import);
        if (failed_)
            throw std::runtime_error("Array owner has a failed transaction");
        if (!handoff.epoch || !handoff.bankGeneration)
            throw std::invalid_argument("Array handoff lacks a live identity");
        if (shaders_.parent.enabled || shaders_.natural.requested ||
            shaders_.staticGroup.activationRequested)
            throw std::logic_error(
                "Incremental handoff cannot replace a parent/static-group authority protocol");
        if (!heldOperations_.empty() || !staticHeld_.empty() || !jobs_.empty())
            throw std::logic_error("CPU->GPU array handoff before actual retirement");
        if (!whole_) {
            // This is the current CPU bank, not bindCold's boot snapshot.
            auto bank = std::make_shared<ColdBank>();
            bank->state = handoff.state;
            bank->data = handoff.data;
            bank->row = handoff.row;
            bank->column = handoff.column;
            bank->cycle = handoff.cycle;
            bank->mode = handoff.mode;
            bank->mask = handoff.mask;
            Batch first{};
            first.epoch = handoff.epoch;
            first.bankGeneration = handoff.bankGeneration;
            first.cold = std::move(bank);
            cold(first);
            return;
        }
        requireOwner(handoff.epoch, handoff.bankGeneration);
        guardPublishedEffects();
        gs_.flush();
        reo_gpu_vif_upload::ColdControl control{};
        control.row = handoff.row;
        control.column = handoff.column;
        control.cycle = handoff.cycle;
        control.mode = handoff.mode;
        control.mask = handoff.mask;
        auto cmd = device_.request_command_buffer();
        const auto upload = [&](const Vulkan::Buffer& buffer, const void* bytes, size_t size) {
            cmd->buffer_barrier(buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
            cmd->update_buffer_inline(buffer, 0, size, bytes);
            cmd->buffer_barrier(buffer, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT);
        };
        upload(whole_->state(), handoff.state.data(), StateBytes);
        upload(whole_->data(), handoff.data.data(), DataBytes);
        upload(unpack_->controls(), &control, sizeof(control));
        Vulkan::Fence fence;
        {
            owner_timing::Scope submit(owner_timing::UploadSubmit);
            device_.submit(cmd, &fence);
        }
        {
            owner_timing::Scope wait(owner_timing::FenceWait);
            fence->wait();
        }
        cycleMirror_ = handoff.cycle;
        modeMirror_ = handoff.mode;
    }
    void exportHandoff(Handoff& handoff) override {
        owner_timing::Scope timing(owner_timing::Export);
        requireOwner(handoff.epoch, handoff.bankGeneration);
        if (shaders_.parent.enabled || shaders_.natural.requested ||
            shaders_.staticGroup.activationRequested)
            throw std::logic_error(
                "Incremental export cannot bypass a parent/static-group authority protocol");
        if (!heldOperations_.empty() || !staticHeld_.empty() || !jobs_.empty())
            throw std::logic_error("GPU->CPU array handoff before actual retirement");
        guardPublishedEffects();
        gs_.flush();
        prepareStaging(StateBytes + DataBytes + 48u);
        auto cmd = device_.request_command_buffer();
        const auto copy = [&](const Vulkan::Buffer& buffer, size_t offset, size_t size) {
            cmd->buffer_barrier(buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
            cmd->copy_buffer(*staging_, offset, buffer, 0, size);
        };
        copy(whole_->state(), 0, StateBytes);
        copy(whole_->data(), StateBytes, DataBytes);
        copy(unpack_->controls(), StateBytes + DataBytes, 48u);
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        {
            owner_timing::Scope submit(owner_timing::UploadSubmit);
            device_.submit(cmd, &fence);
        }
        {
            owner_timing::Scope wait(owner_timing::FenceWait);
            fence->wait();
        }
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Array handoff readback mapping failed");
        std::memcpy(handoff.state.data(), mapped, StateBytes);
        std::memcpy(handoff.data.data(), mapped + StateBytes, DataBytes);
        reo_gpu_vif_upload::ColdControl control{};
        std::memcpy(&control, mapped + StateBytes + DataBytes, sizeof(control));
        handoff.row = control.row;
        handoff.column = control.column;
        handoff.cycle = control.cycle;
        handoff.mode = control.mode;
        handoff.mask = control.mask;
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
    }
    void guardPublishedEffects() override {
        owner_timing::Scope timing(owner_timing::Guard);
        if (parent_)
            parent_->requireHealthy();
        if (!whole_)
            return;
        flushAllHeld();
        if (failed_)
            throw std::runtime_error("Resident GPU owner has an unpublishable failed transaction");
        if (!needsPublicationCheck_)
            return;
        // A GS external-effect/presentation/read boundary may synchronize once
        // for the pending prefix. Never a per-mesh readback or graphics result.
        // Literal GS state is write-only command metadata; a failed GPU echo/
        // program/expansion must halt before any derived output becomes visible.
        auto* latest = latestTail();
        prepareStaging(latest ? 96u : 4u);
        auto fence = [&] {
            owner_timing::Scope submit(owner_timing::CompletionSubmit);
            return gs_.submit_resident_completion([&](Vulkan::CommandBuffer& completionCmd) {
                auto* cmd = &completionCmd;
                cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                    VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                    VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
                cmd->buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                    VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                    VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd->copy_buffer(*staging_, 0, whole_->completion(), 32, 4);
                if (latest) {
                    const auto& cert = tailCertificate(*latest);
                    cmd->buffer_barrier(cert, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                        VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                        VK_PIPELINE_STAGE_TRANSFER_BIT,
                                        VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd->copy_buffer(*staging_, 4, cert, 0, 44);
                    cmd->buffer_barrier(receiptBank(*latest), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                        VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                        VK_PIPELINE_STAGE_TRANSFER_BIT,
                                        VK_ACCESS_2_TRANSFER_READ_BIT);
                    cmd->copy_buffer(*staging_, 48, receiptBank(*latest), receiptOffset(*latest),
                                     48);
                }

                cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                                    VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                                    VK_ACCESS_2_HOST_READ_BIT);
            });
        }();
        if (parent_)
            parent_->sealActualUploads(fence);
        {
            owner_timing::Scope wait(owner_timing::FenceWait);
            fence->wait();
        }
        retireParentUploads(fence);
        const auto* mapped = static_cast<const uint32_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Resident sticky event status mapping failed");
        uint32_t status = *mapped;
        if (!status && latest && !latest->tailPublished) {
            const auto* words = mapped + 12;
            Retired receipt{epoch_,        generation_, latest->ordinal,
                            words[1],      words[6],    words[0] ? words[0] : words[8],
                            words[5] != 0, false};
            if (!publishTail(*latest, mapped + 1, receipt))
                status = 87u;
        }
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
        if (parent_)
            parent_->observeOwnerSticky(status);
        if (status) {
            failed_ = true;
            throw std::runtime_error(
                "GPU program/event verification failed before GS effect publication");
        }
        needsPublicationCheck_ = false;
    }
    void drainBeforeEpochReset() override {
        if (parent_)
            parent_->requireVuBankResetCertificate();
        flushAllHeld();
        // A VU epoch reset does not reset the GS queue or dynamic attributes.
        // Retain the last genuinely published tail before discarding receipts.
        guardPublishedEffects();
        if (whole_) {
            gs_.flush();
            device_.wait_idle();
        }
        jobs_.clear();
        pool_.reset();
        unpack_.reset();
        strip_.reset();
        effects_.reset();
        patch_.reset();
        whole_.reset();
        staging_.reset();
        epoch_ = 0;
        generation_ = 0;
        lastEnqueued_ = 0;
        lastRetired_ = 0;
        lastAccepted_ = 0;
        stagingBytes_ = 0;
        failed_ = false;
        needsPublicationCheck_ = false;
        heldOperations_.clear();
        heldBytes_ = 0;
        streamBuilder_.clear();
        staticHeld_.clear();
        staticHeldBytes_ = 0;
        staticSelected_ = false;
        if (staticBuilder_)
            staticBuilder_->clear();
    }
    void prepareGsReset(uint64_t newEpoch) override {
        if (natural_)
            natural_->requireHealthy();
        if (!heldOperations_.empty() || !staticHeld_.empty())
            throw std::runtime_error("GS reset attempted with unretired array/static stream");
        if (!newEpoch || failed_ || !jobs_.empty() || lastRetired_ != lastEnqueued_)
            throw std::runtime_error("GS reset attempted before resident semantic retirement");
        if (whole_) {
            if (newEpoch < epoch_)
                throw std::runtime_error("GS reset moved resident epoch backward");
            gs_.flush();
            device_.wait_idle();
            // Persistent state_, data_, completion_ and UNPACK controls remain
            // on this same Device. No stale CPU bank is copied over them.
            if (natural_)
                natural_->ownerGsOnlyResetAfterDrain(newEpoch);
            else if (parent_)
                parent_->gsOnlyResetAfterDrain(newEpoch);
            pool_.reset();
            epoch_ = newEpoch;
        }
    }
};
inline OwnerConfig makeArrayResidentOwnerConfig(ArrayShaderBundle shaders) {
    auto immutable = std::make_shared<const ArrayShaderBundle>(std::move(shaders));
    OwnerConfig configuration{};
    configuration.factory = [immutable](Vulkan::Device& device, ParallelGS::GSInterface& gs) {
        return std::make_unique<ParallelArrayOwner>(device, gs, *immutable);
    };
    // Root must supply complete reached/producer/effect/coherence proofs before
    // explicitly enabling this factory in the normal game's private Config.
    configuration.enabled = false;
    configuration.fullProtocolCoverage = false;
    return configuration;
}
// This explicit component factory admits only authentic cold enrollment. It
// does not set FullProtocolCoverage, any shader proof, or readyForSelection.
inline OwnerConfig makeAuthenticColdComponentOwnerConfig(ArrayShaderBundle shaders) {
    if (!shaders.natural.authenticColdComponentEnrollment || !shaders.natural.requested ||
        !shaders.parent.enabled ||
        shaders.parent.tier != reo_parent_live::AdmissionTier::OfflineComponent ||
        (shaders.natural.authenticColdComponentEntry != 0x196010u &&
         shaders.natural.authenticColdComponentEntry != 0x197900u &&
         shaders.natural.authenticColdComponentEntry != 0x18f6a0u &&
         !reo_gpu_upstream::Viewport::supports(shaders.natural.authenticColdComponentEntry)) ||
        !shaders.natural.authenticColdComponentBody)
        throw std::invalid_argument(
            "Cold component factory lacks an exact original entry admission");
    auto result = makeArrayResidentOwnerConfig(std::move(shaders));
    result.enabled = true;
    result.authenticColdComponentEnrollment = true;
    return result;
}
} // namespace reo_resident_live
