#pragma once
// Concrete bounded same-Device whole2EA owner. SOURCE ONLY, not enrolled.
// Include using the root private-gs-b and root pooled helper include directories.
#include "resident_vif_commands.h"
#include "resident_program_bank.hpp"
#include "resident_pooled_strip.hpp"
#include "resident_vif_unpack_extended.h"
#include "resident_material.hpp"
#include "resident_backend_factory.hpp"
#include "gs_interface.hpp"
#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>

namespace reo_resident_live {
// Bounded first-failure diagnostics: print once per process exactly the
// precondition that refused the first failing batch, then the relevant
// internal state at the gate. Subsequent failures in the same process are
// silent to keep the log noise low (the printed first case already conveys
// the engineering signal).
inline std::atomic<bool> owner_first_batch_refusal{false};
struct ShaderBundle {
    std::vector<uint32_t> whole2ea, strip, unpack;
    uint64_t whole2eaBinding = 0;
    std::vector<ProgramModule> programs;
    std::vector<uint32_t> effectValidate, bytePatch;
};
class ParallelWhole2eaOwner final : public SemanticOwner {
    Vulkan::Device& device_;
    ParallelGS::GSInterface& gs_;
    ShaderBundle shaders_;
    std::unique_ptr<ProgramBank> whole_;
    std::unique_ptr<reo_gpu_pooled_strip::Strip> strip_;
    std::unique_ptr<reo_gpu_vif_upload::ResidentVifUnpack> unpack_;
    std::unique_ptr<EffectValidate> effects_;
    std::unique_ptr<BytePatch> patch_;
    std::unique_ptr<reo_gpu_mesh_pool::MeshPool> pool_;
    struct Job {
        uint64_t ordinal;
        reo_gpu_mesh_pool::MeshPool::Slice slice;
        // Retained launch identity, for verifier-rejection capture/recovery.
        uint32_t slot = 0;
        reo_gpu_whole_pooled::Push push{};
        reo_gpu_path1_metadata::GpuEchoContract contract{};
        // Exact-image binding recorded at enqueue: the recovery replays
        // against THIS image, never whichever image is uploaded/matched later.
        uint64_t bindingId = 0, imageDigest = 0;
    };
    std::vector<Job> jobs_;
    uint64_t epoch_ = 0, generation_ = 0, lastEnqueued_ = 0, lastRetired_ = 0;
    bool failed_ = false, needsPublicationCheck_ = false;
    // Park state (mixed-execution fallback). When the certified whole-owner
    // verifier refuses a prefix job (an out-of-cert-envelope literal packet,
    // kernel status 21), the owner parks instead of failing the session: the
    // sticky result is terminal for GPU geometry, ownership flows back to the
    // CPU through the normal export handoff, and the pool stops recording. A
    // genuine GS reset (prepareGsReset) is the only park exit.
    bool parked_ = false;
    uint32_t parkStatus_ = 0;
    uint64_t parkOrdinal_ = 0;
    unsigned parkedDrops_ = 0;
    Vulkan::BufferHandle staging_;
    size_t stagingBytes_ = 0;
    // Retained pre-launch snapshots: the exact device state/data bank bytes
    // captured BEFORE each launch's kernel dispatch (device-side copy recorded
    // ahead of the kernel in the same command). On a verifier refusal the
    // refused ordinals' retained snapshots are what recovery replays from. The
    // ring index is the launch's enqueue rank inside the live retirement
    // window, bounded by MaxLaunches; a park stops dispatch, so the refused
    // slots stay intact until the owner reads them or is destroyed. The
    // controls ring keeps the 48-byte VIF control block (ROW/COL/cycle/mode/
    // mask) in the same layout, so recovery restores the launch-time VIF
    // controls along with the VU state/data.
    Vulkan::BufferHandle snapshotState_, snapshotData_, snapshotControls_;
    struct FailedLaunch {
        uint64_t ordinal = 0;
        uint64_t bindingId = 0, imageDigest = 0;
        uint32_t status = 0, slot = 0;
        bool valid = false;
        reo_gpu_whole_pooled::Push push{};
        reo_gpu_path1_metadata::GpuEchoContract contract{};
    };
    // Every pre-publication wrapper refusal (own status 20..24) this owner has
    // parked on, in ordinal order. Recovery reads the whole list (ordered,
    // one retained record per refused ordinal) and consumes it; later parked
    // drains may append leftovers, each still readable exactly once.
    std::vector<FailedLaunch> refusedLaunches_;
    // FNV-1a 64 over the certified exact image (identity pinning only; the
    // runtime-side capture digest uses the same function).
    static uint64_t imageDigestOf(const uint8_t* data, size_t bytes) {
        uint64_t hash = 0xcbf29ce484222325ull;
        for (size_t i = 0; i < bytes; ++i) {
            hash ^= data[i];
            hash *= 0x100000001b3ull;
        }
        return hash;
    }
    void requireOwner(uint64_t epoch, uint64_t generation) const {
        if (failed_)
            throw std::runtime_error("Resident GPU semantic owner failed");
        if (!whole_ || epoch != epoch_ || generation != generation_)
            throw std::runtime_error("Foreign/stale resident VIF GPU bank");
    }
    void cold(const Batch& batch) {
        if (whole_) {
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
        whole_ = std::make_unique<ProgramBank>(device_, modules, batch.cold->state.data(),
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
    void appendUploads(Vulkan::CommandBuffer& cmd, const std::vector<const Operation*>& uploads) {
        for (const auto* operation : uploads)
            if (operation->kind == Kind::Control)
                unpack_->enqueueControlWrite(cmd, operation->controlByte, operation->payload.data(),
                                             uint32_t(operation->payload.size()));
            else if (operation->kind == Kind::Unpack)
                unpack_->enqueue(cmd, operation->command, operation->latchedTops,
                                 operation->payload.data(), uint32_t(operation->payload.size()));
            else if (operation->kind == Kind::DataWrite)
                patch_->enqueue(cmd, *whole_, whole_->data(), operation->controlByte,
                                operation->payload.data(), uint32_t(operation->payload.size()));
            else if (operation->kind == Kind::ControlByteWrite)
                patch_->enqueue(cmd, *whole_, unpack_->controls(), operation->controlByte,
                                operation->payload.data(), uint32_t(operation->payload.size()));
            else
                throw std::logic_error("Not an upload/control operation");
    }

  public:
    // Complete source protocol is not an enrollment/fidelity certificate. Full
    // reached shaders, consumers and producer routes still need root proof.
    static constexpr bool FullProtocolCoverage = false;
    ParallelWhole2eaOwner(Vulkan::Device& device, ParallelGS::GSInterface& gs, ShaderBundle shaders)
        : device_(device), gs_(gs), shaders_(std::move(shaders)) {
        if ((shaders_.programs.empty() &&
             (!shaders_.whole2eaBinding || shaders_.whole2ea.empty())) ||
            shaders_.strip.empty() || shaders_.unpack.empty() || shaders_.effectValidate.empty() ||
            shaders_.bytePatch.empty())
            throw std::invalid_argument("Resident owner requires immutable shader bindings");
        const char* grouped = std::getenv("REO_GS_RESIDENT_MESH_BATCH");
        gs_.set_resident_material_batching(grouped && grouped[0] == '1');
    }
    ~ParallelWhole2eaOwner() override {
        try {
            drainBeforeEpochReset();
        } catch (...) {
        }
    }
    void enqueue(const Batch& batch) override {
        if (parked_) {
            // Small admission/settle race window: a guest launch recorded
            // before the runtime observed the park reaches a parked owner.
            // Drop the batch (no records, no pointers advanced) so the GS
            // worker stays healthy; the CPU fallback continues from the last
            // committed GPU bank state. Bounded: the runtime stops admitting
            // once it observes the park, so only a few batches can arrive.
            if (!pool_ && parkedDrops_ < 8) {
                ++parkedDrops_;
                std::fprintf(stderr, "[GPU-MIXED] parked enqueue drop ops=%zu payload=%u\n",
                             batch.operations.size(), batch.payloadBytes);
            }
            return;
        }
        validate(batch);
        // Validate whole command batch BEFORE cold bank allocation or mutation.
        uint64_t ordinal = lastEnqueued_;
        size_t count = jobs_.size();
        for (const auto& op : batch.operations)
            if (op.kind == Kind::Launch) {
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
                    op.ordinal != ordinal + 1 || ++count > MaxLaunches) {
                    // Bounded first-failure diagnostic: the exact precondition
                    // that refused the first failing launch is captured so the
                    // guard can be safely addressed.
                    if (owner_first_batch_refusal.exchange(true) == false) {
                        const char* reject = "unknown";
                        if (!registered)
                            reject = "unregistered bindingId (not whole2eaBinding and not in "
                                     "programs[])";
                        else if (op.resume && !resumeCovered)
                            reject = "op.resume AND module.canResume=false";
                        else if (op.program->literalSourcePreserved && !literalReuseCovered)
                            reject = "literalSourcePreserved AND module resume/fresh "
                                     "literal-source-preserved=false";
                        else if (op.effect.vertexCapacity > 256)
                            reject = "op.effect.vertexCapacity>256";
                        else if (op.effect.type == LiteralEffect::Type::Strip &&
                                 !op.effect.vertexCapacity)
                            reject = "Strip type with vertexCapacity==0";
                        else if (op.ordinal != ordinal + 1)
                            reject = "ordinal gap (expected next after lastEnqueued_)";
                        else if (count >= MaxLaunches)
                            reject = "count>=MaxLaunches (batch overflow)";
                        std::fprintf(
                            stderr,
                            "[GPU-MIXED] first batch-validation refusal reason=%s ordinal=%llu "
                            "lastEnqueued_=%llu bindingId=%llu whole2eaBinding=%llu resume=%u "
                            "canResume=%u literalSourcePreserved=%u literalReuseCovered=%u "
                            "vertexCapacity=%u effectType=%d count=%zu MaxLaunches=%zu\n",
                            reject, static_cast<unsigned long long>(op.ordinal),
                            static_cast<unsigned long long>(lastEnqueued_),
                            static_cast<unsigned long long>(op.program->bindingId),
                            static_cast<unsigned long long>(shaders_.whole2eaBinding),
                            op.resume ? 1u : 0u, resumeCovered ? 1u : 0u,
                            op.program->literalSourcePreserved ? 1u : 0u,
                            literalReuseCovered ? 1u : 0u, op.effect.vertexCapacity,
                            int(op.effect.type), count, size_t(MaxLaunches));
                    }
                    throw std::runtime_error(
                        "Resident owner cannot execute this full program/event class");
                }
                validateLiteralEnvelope(op.effect);
                ordinal = op.ordinal;
            }
        cold(batch);
        requireOwner(batch.epoch, batch.bankGeneration);
        std::vector<const Operation*> uploads;
        for (const auto& op : batch.operations) {
            if (op.kind != Kind::Launch) {
                uploads.push_back(&op);
                continue;
            }
            if (!pool_) {
                pool_ = std::make_unique<reo_gpu_mesh_pool::MeshPool>(device_, MaxLaunches, epoch_);
                // Retained pre-launch snapshot ring, allocated with the same
                // lifetime as the slice pool. Indexed by enqueue rank.
                Vulkan::BufferCreateInfo snapshotInfo{};
                snapshotInfo.domain = Vulkan::BufferDomain::Device;
                snapshotInfo.size = size_t(MaxLaunches) * StateBytes;
                snapshotInfo.usage =
                    VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
                snapshotState_ = device_.create_buffer(snapshotInfo);
                snapshotInfo.size = size_t(MaxLaunches) * DataBytes;
                snapshotData_ = device_.create_buffer(snapshotInfo);
                snapshotInfo.size =
                    size_t(MaxLaunches) * 48u; // VIF controls: ROW/COL/cycle/mode/mask/pad
                snapshotControls_ = device_.create_buffer(snapshotInfo);
                if (!snapshotState_ || !snapshotData_ || !snapshotControls_)
                    throw std::runtime_error("Retained pre-launch snapshot allocation failed");
            }
            const uint32_t slot = static_cast<uint32_t>(jobs_.size());
            const auto slice = pool_->allocate();
            const auto contract = echo(op.effect);
            const uint32_t expectedKind = validateLiteralEnvelope(op.effect);
            // Original PACKED PRE=1 applies PRIM before consuming any payload.
            // The validated literal strip header resets the original vertex
            // assembly queue through its handler, including retained strip
            // history. No synthetic reset is allowed for AD/noevent effects.
            if (expectedKind == 1u) {
                const uint32_t literalPrim = (contract.qwords[0][1] >> 15u) & 2047u;
                gs_.write_register(ParallelGS::RegisterAddr(0x00), uint64_t(literalPrim));
            }
            // PATH1 ordering: PS2 hardware preempts pending PATH2 data with
            // PATH1 VU work. The projected admission is the same helper the
            // array owner proves (array stream publication): it records the
            // launch between the last ordinary triangle and the strip's
            // future vertices, leaving the queued vertices untouched for the
            // ordinary continuation. The live mixed trial diagnosed the
            // strict guard refusing at a standing open-strip state
            // ([RESIDENT-REFUSAL] vertexQueueCount=3) exactly here.
            if (!gs_.prepare_resident_recording_projected())
                throw std::runtime_error(
                    "Projected resident recording refused by GS admission guard");
            ParallelGS::ResidentMaterial material{};
            reo_gpu_pooled_strip::Parameters parameters{};
            if (expectedKind == 1u) {
                const uint32_t literalPrim = (contract.qwords[0][1] >> 15u) & 2047u;
                if (!gs_.prepare_resident_material_projected(op.effect.vertexCapacity, literalPrim,
                                                             material))
                    throw std::runtime_error(
                        "Unsupported projected resident material/feedback/register state");
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
            const reo_gpu_whole_pooled::Push push{op.startPC,          op.maxPairs, op.top, op.itop,
                                                  op.resume ? 4u : 0u, 256,         0,      0};
            // Synchronous recorder borrows the GS-owned triangle_setup_cmd.
            // Each producer is before its native triangle setup; binning/direct
            // follow in the renderer's existing submission order. No command
            // handle or lambda escapes, and no per-launch queue submit occurs.
            gs_.record_resident_command([&](Vulkan::CommandBuffer& cmd) {
                appendUploads(cmd, uploads);
                uploads.clear();
                // Retained PRE-LAUNCH snapshot: device-side copy of the exact
                // bank bytes this kernel will consume, recorded ahead of the
                // dispatch inside the same command. On a verifier rejection the
                // failed job's retained slot is the recovery replay input.
                // Granite's copy_buffer takes destination FIRST (dst, dst_offset,
                // src, src_offset, size). The snapshot ring is the destination;
                // the live bank is the source. (Reversing these is a silent state
                // wipe: the live bank gets overwritten from the snapshot slot.)
                cmd.buffer_barrier(whole_->state(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.buffer_barrier(*snapshotState_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
                cmd.copy_buffer(*snapshotState_, size_t(slot) * StateBytes, whole_->state(), 0,
                                StateBytes);
                cmd.buffer_barrier(whole_->data(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.buffer_barrier(*snapshotData_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
                cmd.copy_buffer(*snapshotData_, size_t(slot) * DataBytes, whole_->data(), 0,
                                DataBytes);
                // Launch-time VIF control state (ROW/COL/cycle/mode/mask) in the
                // same pre-dispatch instant, so recovery restores the complete
                // VIF control snapshot along with the VU registers and data.
                cmd.buffer_barrier(unpack_->controls(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd.buffer_barrier(*snapshotControls_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                   VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                   VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
                cmd.copy_buffer(*snapshotControls_, size_t(slot) * 48u, unpack_->controls(), 0,
                                48u);
                cmd.buffer_barrier(
                    *snapshotState_, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
                cmd.buffer_barrier(
                    *snapshotData_, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
                cmd.buffer_barrier(
                    *snapshotControls_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                    VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
                whole_->enqueue(cmd, op.program->bindingId, push, contract, *pool_, slice);
                effects_->enqueue(cmd, *whole_, *pool_, slice);
                if (expectedKind == 1u)
                    strip_->enqueue(cmd, *pool_, slice, parameters, whole_->completion());
            });
            if (expectedKind == 1u) {
                const uint32_t literalPrim = (contract.qwords[0][1] >> 15u) & 2047u;
                if (!gs_.prepare_resident_material_projected(op.effect.vertexCapacity, literalPrim,
                                                             material)) {
                    // Bounded first-failure diagnostic for the material
                    // projection guard. The exact precondition that rejected
                    // the first failing job is needed before this guard can
                    // be either safely widened or confidently enforced; the
                    // gpuinc22 certSeed placeholder was not a real adoption
                    // and the rejection here pre-empts it.
                    std::fprintf(
                        stderr,
                        "[GPU-MIXED] prepare_resident_material_projected refusal ordinal=%llu "
                        "vertexCapacity=%u literalPrim=0x%03x imageDigest=%016llx binding=%llu\n",
                        static_cast<unsigned long long>(op.ordinal), op.effect.vertexCapacity,
                        literalPrim,
                        imageDigestOf(op.program->exactImage.data(), op.program->exactImage.size()),
                        static_cast<unsigned long long>(op.program->bindingId));
                    throw std::runtime_error(
                        "Unsupported projected resident material/feedback/register state");
                }
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
                // The raw tag carries an observable internal-Q reset that
                // six independent register writes omit. Keep the validated
                // PRE0 packet intact, including its original queue behavior.
                gs_.gif_transfer(0, contract.qwords.data(), 112u);
            }
            // Retain every recorded launch until its real receipt is read.
            // The slot also identifies its pre-launch recovery snapshots.
            // Omitting this record leaves lastEnqueued_ at zero, rejects the
            // next launch and makes the first dispatch invisible to retire().
            jobs_.push_back(
                {op.ordinal, slice, slot, push, contract, op.program->bindingId,
                 imageDigestOf(op.program->exactImage.data(), op.program->exactImage.size())});
            lastEnqueued_ = op.ordinal;
            needsPublicationCheck_ = true;
        }
        if (!uploads.empty()) {
            if (!gs_.prepare_resident_recording_projected())
                throw std::runtime_error("Projected resident upload refused by GS admission guard");
            gs_.record_resident_command(
                [&](Vulkan::CommandBuffer& cmd) { appendUploads(cmd, uploads); });
            needsPublicationCheck_ = true;
        }
    }
    std::vector<Retired> retire(Barrier, uint64_t epoch, uint64_t generation) override {
        requireOwner(epoch, generation);
        if (parked_) {
            // Parked owner: the sticky verifier already failed once and the
            // pool accepts no further work. Drain any defensive leftover,
            // report the latched park status, and keep the GS worker healthy
            // (the empty-prefix retires normal post-park barriers rely on).
            // Leftover jobs still get retained as refused-tail replay inputs
            // (their recorded commands executed under the sticky gate, so
            // their pre-dispatch snapshot slots are valid), so the recovery
            // can replay the COMPLETE refused sequence, not just the first.
            gs_.flush();
            device_.wait_idle();
            std::vector<Retired> results;
            results.reserve(jobs_.size());
            for (const auto& job : jobs_) {
                results.push_back(
                    {epoch_, generation_, job.ordinal, 0, 0, parkStatus_, true, false});
                if (parkStatus_ >= 20u && parkStatus_ <= 24u)
                    refusedLaunches_.push_back({job.ordinal, job.bindingId, job.imageDigest,
                                                parkStatus_, job.slot, true, job.push,
                                                job.contract});
            }
            if (!jobs_.empty())
                lastRetired_ = jobs_.back().ordinal;
            jobs_.clear();
            pool_.reset();
            needsPublicationCheck_ = false;
            return results;
        }
        // Genuine explicit guest boundary, once per DMA/wait rather than mesh.
        // Retaining immutable output slices until this real device retirement
        // avoids overwrite even if GS queued the native draw but did not submit.
        gs_.flush();
        device_.wait_idle();
        const size_t bytes = jobs_.size() * 64u + 4u;
        prepareStaging(bytes);
        auto cmd = device_.request_command_buffer();
        if (pool_)
            for (size_t i = 0; i < jobs_.size(); ++i) {
                const auto& slice = jobs_[i].slice;
                pool_->validate(slice);
                for (const auto binding : {reo_gpu_mesh_pool::MeshPool::CompletionTape,
                                           reo_gpu_mesh_pool::MeshPool::ExpansionStatus})
                    cmd->buffer_barrier(pool_->bank(binding), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                        VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                        VK_PIPELINE_STAGE_TRANSFER_BIT,
                                        VK_ACCESS_2_TRANSFER_READ_BIT);
                cmd->copy_buffer(*staging_, i * 64u,
                                 pool_->bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                                 slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape], 48);
                cmd->copy_buffer(*staging_, i * 64u + 48u,
                                 pool_->bank(reo_gpu_mesh_pool::MeshPool::ExpansionStatus),
                                 slice.offsets[reo_gpu_mesh_pool::MeshPool::ExpansionStatus], 16);
            }
        cmd->buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, jobs_.size() * 64u, whole_->completion(), 32, 4);
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        device_.submit(cmd, &fence);
        fence->wait();
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Actual GPU completion metadata mapping failed");
        std::vector<Retired> results;
        results.reserve(jobs_.size());
        uint32_t globalError = 0;
        std::memcpy(&globalError, mapped + jobs_.size() * 64u, 4);
        // Bounded, env-gated diagnostic (REO_RESIDENT_REFUSAL_DIAG=1); see the
        // loop below. At most 48 failing prints per owner lifetime.
        const bool refusalDiag = []() {
            const char* e = std::getenv("REO_RESIDENT_REFUSAL_DIAG");
            return e && e[0] == '1';
        }();
        unsigned diagPrints = 0;
        for (size_t i = 0; i < jobs_.size(); ++i) {
            uint32_t words[16]{};
            std::memcpy(words, mapped + i * 64u, 64);
            // Per-job status is the job's OWN evidence: its wrapper completion
            // status, or its effect/expansion status when the wrapper succeeded
            // (a refused effect must not be accounted as a clean ordinal). The
            // bank-global sticky word deliberately does NOT fold into clean
            // earlier jobs' reported status: it poisons later dispatches (they
            // bounce with the stale value in their own word0) and the latch
            // below still carries it. Truthful per-job status is what lets
            // verifier-rejection recovery replay exactly the refused tail.
            const uint32_t ownStatus = words[0] ? words[0] : words[12] ? words[12] : 0u;
            const uint32_t error = words[0]    ? words[0]
                                   : words[8]  ? words[8]
                                   : words[12] ? words[12]
                                               : globalError;
            // A nonzero per-job completion word silently latches failed_ in
            // this scan, so name the ordinal and the raw completion words.
            if (refusalDiag && error && diagPrints < 32) {
                ++diagPrints;
                std::fprintf(
                    stderr,
                    "[RESIDENT-JOBFAIL] ordinal=%llu error=0x%08x status=0x%08x w0=0x%08x "
                    "w1=0x%08x w3=0x%08x w5=0x%08x w6=0x%08x w8=0x%08x w12=0x%08x jobs=%zu i=%zu\n",
                    static_cast<unsigned long long>(jobs_[i].ordinal), error, ownStatus, words[0],
                    words[1], words[3], words[5], words[6], words[8], words[12], jobs_.size(), i);
            }
            results.push_back({epoch_, generation_, jobs_[i].ordinal, words[1], words[6], ownStatus,
                               words[5] != 0, false});
            if (error) {
                // Park (mixed execution): the sticky verifier refused this prefix
                // job. The stickiness is terminal for the GPU geometry pipeline
                // (whether the refusal was recoverable via CPU replay, or a
                // committed/sticky-folded error). Ownership flows back to the
                // CPU and the session keeps running. The runtime side sees the
                // status riding this same retire result and mirrors the park
                // through s_residentOwnerParked so its admission gate stays
                // consistent — until an explicit fenced backend reinitialization
                // exists, the only safe post-rejection state is "no more GPU
                // launches in this epoch".
                //
                // Every refused job's retained PRE-LAUNCH snapshot (captured
                // before its dispatch) is what recovery replays from. The whole
                // refused tail, in ordinal order, not just the first.
                if (ownStatus >= 20u && ownStatus <= 24u)
                    refusedLaunches_.push_back({jobs_[i].ordinal, jobs_[i].bindingId,
                                                jobs_[i].imageDigest, error, jobs_[i].slot, true,
                                                jobs_[i].push, jobs_[i].contract});
                const bool firstPark = !parked_;
                if (firstPark) {
                    parked_ = true;
                    parkStatus_ = error;
                    parkOrdinal_ = jobs_[i].ordinal;
                    std::fprintf(
                        stderr,
                        "[GPU-MIXED] owner-park status=0x%08x ordinal=%llu ownStatus=0x%08x "
                        "pairs=%u events=%u ended=%u jobs=%zu — CPU ownership restored, GPU "
                        "admissions disabled (no fenced reinitialization yet)\n",
                        error, static_cast<unsigned long long>(jobs_[i].ordinal), ownStatus,
                        words[1], words[6], words[5] != 0 ? 1u : 0u, jobs_.size());
                }
            }
            failed_ |= error != 0;
        }
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
        if (globalError && !parked_) {
            parked_ = true;
            parkStatus_ = globalError;
            parkOrdinal_ = 0;
            std::fprintf(stderr,
                         "[GPU-MIXED] owner-park status=0x%08x ordinal=- shared-sticky jobs=%zu — "
                         "CPU ownership restored, GPU admissions disabled\n",
                         globalError, jobs_.size());
        }
        failed_ |= globalError != 0;
        if (refusalDiag && globalError && diagPrints < 48) {
            ++diagPrints;
            std::fprintf(stderr, "[RESIDENT-JOBFAIL] globalError=0x%08x jobs=%zu\n", globalError,
                         jobs_.size());
        }
        if (globalError && jobs_.empty() && !parked_)
            throw std::runtime_error("Resident UNPACK/control GPU bank failed");
        if (!jobs_.empty())
            lastRetired_ = jobs_.back().ordinal;
        // GPU→ordinary-GIF tail adoption: deliberately NOT implemented for
        // whole2ea (the gpuinc22 certSeed placeholder used manufactured
        // metadata, not real ST/RGBA/Q/vertex-history outputs from GPU
        // execution — adopt_resident_gpu_tail() validates only the cert shape,
        // so a fabricated cert would silently publish uninitialized GS state
        // into the next ordinary GIF packet). The array owner performs real
        // adoption via a pinned pooledTail shader; whole2ea needs an
        // equivalent producer before adoption is safe to re-enable.
        jobs_.clear();
        pool_.reset();
        needsPublicationCheck_ = false;
        return results;
    }
    void readData(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        if (!whole_ || !destination || !bytes || offset >= DataBytes || bytes > DataBytes - offset)
            throw std::out_of_range("Explicit guest resident bank read bounds");
        if (!jobs_.empty())
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
        device_.submit(cmd, &fence);
        fence->wait();
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
        if (!jobs_.empty())
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
        device_.submit(cmd, &fence);
        fence->wait();
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Resident VIF control read mapping failed");
        std::memcpy(destination, mapped + offset - aligned, bytes);
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
    }
    void retainFailedLaunch(std::vector<RetainedLaunchFailure>& out) override {
        // Recovery readback of the REFUSED TAIL's retained PRE-LAUNCH
        // snapshots: the exact device state/data/controls bytes each refused
        // kernel was recorded to consume (copied before its dispatch), plus
        // each job's retained push, literal-effect contract and exact-image
        // binding (bindingId + FNV-1a digest of the certified image). The
        // snapshot buffers outlive the slice pool (pool_.reset() in retire
        // does not touch them), and a park stops all further dispatch, so no
        // later launch can overwrite a refused slot. Ordered by ordinal.
        // Consumption is exactly-once: the list is cleared after the read, so
        // a later parked drain may append NEW leftovers that stay readable
        // once, while a repeat read with nothing new returns an empty vector
        // (the runtime treats that as "nothing replayable left").
        if (!out.empty())
            throw std::invalid_argument("Retained launch failure target was not empty");
        if (refusedLaunches_.empty())
            return;
        if (!whole_ || !snapshotState_ || !snapshotData_ || !snapshotControls_)
            throw std::runtime_error("Verifier rejection has no retained pre-launch snapshot");
        constexpr size_t recordBytes = StateBytes + DataBytes + 48u;
        prepareStaging(recordBytes * refusedLaunches_.size());
        gs_.flush();
        auto cmd = device_.request_command_buffer();
        for (const Vulkan::BufferHandle* buffer :
             {&snapshotState_, &snapshotData_, &snapshotControls_})
            cmd->buffer_barrier(**buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                                VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        for (size_t i = 0; i < refusedLaunches_.size(); ++i) {
            const auto& source = refusedLaunches_[i];
            cmd->copy_buffer(*staging_, i * recordBytes, *snapshotState_,
                             size_t(source.slot) * StateBytes, StateBytes);
            cmd->copy_buffer(*staging_, i * recordBytes + StateBytes, *snapshotData_,
                             size_t(source.slot) * DataBytes, DataBytes);
            cmd->copy_buffer(*staging_, i * recordBytes + StateBytes + DataBytes,
                             *snapshotControls_, size_t(source.slot) * 48u, 48u);
        }
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        device_.submit(cmd, &fence);
        fence->wait();
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Retained pre-launch snapshot mapping failed");
        out.reserve(refusedLaunches_.size());
        for (size_t i = 0; i < refusedLaunches_.size(); ++i) {
            const auto& source = refusedLaunches_[i];
            const auto* base = mapped + i * recordBytes;
            RetainedLaunchFailure record{};
            record.available = true;
            record.ordinal = source.ordinal;
            record.status = source.status;
            record.bindingId = source.bindingId;
            record.imageDigest = source.imageDigest;
            static_assert(sizeof(source.push) == 8u * 4u, "Retained push word count mismatch");
            std::memcpy(record.push, &source.push, sizeof(source.push));
            static_assert(sizeof(source.contract) == 32u * 4u,
                          "Retained echo contract word count mismatch");
            std::memcpy(record.echo.data(), &source.contract, sizeof(source.contract));
            std::memcpy(record.state.data(), base, StateBytes);
            std::memcpy(record.data.data(), base + StateBytes, DataBytes);
            std::memcpy(record.controls.data(), base + StateBytes + DataBytes, 48u);
            out.push_back(std::move(record));
        }
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
        refusedLaunches_.clear(); // Exactly-once readback.
    }
    // Distinct synchronous CPU->GPU handoff. Never touches cold()/batch.cold;
    // it either constructs the bank from the current CPU handoff (first import)
    // or overwrites the persistent state/data/controls buffers in place, both
    // under the live epoch/bank-generation check. Never called with semantic
    // work unretired.
    void importHandoff(const Handoff& handoff) override {
        if (failed_)
            throw std::runtime_error("Resident GPU semantic owner failed");
        if (!handoff.epoch || !handoff.bankGeneration)
            throw std::invalid_argument("Handoff lacks a live epoch/bank identity");
        if (!whole_) {
            auto modules = shaders_.programs;
            if (modules.empty())
                modules.push_back({shaders_.whole2eaBinding, shaders_.whole2ea});
            whole_ = std::make_unique<ProgramBank>(device_, modules, handoff.state.data(),
                                                   handoff.data.data());
            strip_ = std::make_unique<reo_gpu_pooled_strip::Strip>(device_, shaders_.strip);
            reo_gpu_vif_upload::ColdControl control{};
            control.row = handoff.row;
            control.column = handoff.column;
            control.cycle = handoff.cycle;
            control.mode = handoff.mode;
            control.mask = handoff.mask;
            unpack_ = std::make_unique<reo_gpu_vif_upload::ResidentVifUnpack>(
                device_, shaders_.unpack, whole_->data(), whole_->completion(), control);
            effects_ = std::make_unique<EffectValidate>(device_, shaders_.effectValidate);
            patch_ = std::make_unique<BytePatch>(device_, shaders_.bytePatch);
            epoch_ = handoff.epoch;
            generation_ = handoff.bankGeneration;
            return;
        }
        requireOwner(handoff.epoch, handoff.bankGeneration);
        if (!jobs_.empty())
            throw std::logic_error("CPU->GPU handoff before actual semantic retirement");
        reo_gpu_vif_upload::ColdControl control{};
        control.row = handoff.row;
        control.column = handoff.column;
        control.cycle = handoff.cycle;
        control.mode = handoff.mode;
        control.mask = handoff.mask;
        gs_.flush();
        // Synchronous inline import of the current architectural state, full
        // data bank, and VIF controls. The buffer usage bits (STORAGE|TRANSFER)
        // allow inline host writes into the persistent Device buffers.
        auto cmd = device_.request_command_buffer();
        cmd->buffer_barrier(whole_->state(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd->update_buffer_inline(whole_->state(), 0, StateBytes, handoff.state.data());
        cmd->buffer_barrier(whole_->state(), VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT);
        cmd->buffer_barrier(whole_->data(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd->update_buffer_inline(whole_->data(), 0, DataBytes, handoff.data.data());
        cmd->buffer_barrier(whole_->data(), VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT);
        cmd->buffer_barrier(unpack_->controls(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd->update_buffer_inline(unpack_->controls(), 0, sizeof(control), &control);
        cmd->buffer_barrier(unpack_->controls(), VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT);
        Vulkan::Fence fence;
        device_.submit(cmd, &fence);
        fence->wait();
    }
    // Distinct synchronous GPU->CPU handoff: read the current architectural
    // state, full data bank and VIF controls back with a genuine device fence.
    void exportHandoff(Handoff& handoff) override {
        // Parked export is the mixed-mode ownership restore: the CPU takes
        // the last committed GPU bank state (the failed job never committed).
        if (failed_ && !parked_)
            throw std::runtime_error("Resident GPU semantic owner failed");
        requireOwner(handoff.epoch, handoff.bankGeneration);
        if (!jobs_.empty())
            throw std::logic_error("GPU->CPU handoff before actual semantic retirement");
        constexpr size_t total = StateBytes + DataBytes + 48u;
        prepareStaging(total);
        gs_.flush();
        auto cmd = device_.request_command_buffer();
        cmd->buffer_barrier(whole_->state(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, 0, whole_->state(), 0, StateBytes);
        cmd->buffer_barrier(whole_->data(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, StateBytes, whole_->data(), 0, DataBytes);
        cmd->buffer_barrier(unpack_->controls(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, StateBytes + DataBytes, unpack_->controls(), 0, 48u);
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        device_.submit(cmd, &fence);
        fence->wait();
        const auto* mapped = static_cast<const uint8_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("GPU->CPU handoff mapping failed");
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
        if (!whole_)
            return;
        if (parked_)
            return;
        if (failed_)
            throw std::runtime_error("Resident GPU owner has an unpublishable failed transaction");
        if (!needsPublicationCheck_)
            return;
        // A GS external-effect/presentation/read boundary may synchronize once
        // for the pending prefix. Never a per-mesh readback or graphics result.
        // Literal GS state is write-only command metadata; a failed GPU echo/
        // program/expansion must halt before any derived output becomes visible.
        gs_.flush();
        prepareStaging(4);
        auto cmd = device_.request_command_buffer();
        cmd->buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                            VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                            VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        cmd->copy_buffer(*staging_, 0, whole_->completion(), 32, 4);
        cmd->buffer_barrier(*staging_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                            VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_HOST_BIT,
                            VK_ACCESS_2_HOST_READ_BIT);
        Vulkan::Fence fence;
        device_.submit(cmd, &fence);
        fence->wait();
        const auto* mapped = static_cast<const uint32_t*>(
            device_.map_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT));
        if (!mapped)
            throw std::runtime_error("Resident sticky event status mapping failed");
        const uint32_t status = *mapped;
        device_.unmap_host_buffer(*staging_, Vulkan::MEMORY_ACCESS_READ_BIT);
        if (status) {
            failed_ = true;
            // Session-fatal role: this exact block runs at most once per owner
            // lifetime (failed_ latches), so the print is bounded by design;
            // the status value rides the session-fatal message as well.
            char buffer[32]{};
            std::snprintf(buffer, sizeof(buffer), "0x%08x", status);
            std::fprintf(stderr, "[RESIDENT-STICKY] status=%s jobs=%zu lastEnqueued=%llu\n", buffer,
                         jobs_.size(), static_cast<unsigned long long>(lastEnqueued_));
            throw std::runtime_error(std::string("GPU program/event verification failed (status=") +
                                     buffer + ") before GS effect publication");
        }
        needsPublicationCheck_ = false;
    }
    void drainBeforeEpochReset() override {
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
        snapshotState_.reset();
        snapshotData_.reset();
        snapshotControls_.reset();
        epoch_ = 0;
        generation_ = 0;
        lastEnqueued_ = 0;
        lastRetired_ = 0;
        stagingBytes_ = 0;
        failed_ = false;
        parked_ = false;
        parkStatus_ = 0;
        parkOrdinal_ = 0;
        needsPublicationCheck_ = false;
        refusedLaunches_.clear();
    }
    void prepareGsReset(uint64_t newEpoch) override {
        // A parked owner accepts a genuine GS reset: it is exactly the
        // owner-controlled cold reset that clears the sticky verifier state.
        if (!newEpoch || (failed_ && !parked_) || !jobs_.empty() || lastRetired_ != lastEnqueued_)
            throw std::runtime_error("GS reset attempted before resident semantic retirement");
        if (whole_) {
            if (newEpoch < epoch_)
                throw std::runtime_error("GS reset moved resident epoch backward");
            gs_.flush();
            device_.wait_idle();
            // Persistent state_, data_, completion_ and UNPACK controls remain
            // on this same Device. No stale CPU bank is copied over them.
            pool_.reset();
            epoch_ = newEpoch;
            if (parked_) {
                // The shared sticky verifier word (completion word 8, the
                // byte range the kernel preserves across launches) is cleared
                // by this owner-controlled cold reset, matching the bank
                // protocol: sticky until owner reset, then re-armed.
                const uint32_t zero = 0;
                auto clear = device_.request_command_buffer();
                clear->buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                      VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                                      VK_PIPELINE_STAGE_TRANSFER_BIT,
                                      VK_ACCESS_2_TRANSFER_WRITE_BIT);
                clear->update_buffer_inline(whole_->completion(), 32, 4, &zero);
                clear->buffer_barrier(whole_->completion(), VK_PIPELINE_STAGE_TRANSFER_BIT,
                                      VK_ACCESS_2_TRANSFER_WRITE_BIT,
                                      VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                                      VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT);
                Vulkan::Fence fence;
                device_.submit(clear, &fence);
                fence->wait();
                parked_ = false;
                parkStatus_ = 0;
                parkOrdinal_ = 0;
                failed_ = false;
                needsPublicationCheck_ = false;
                refusedLaunches_.clear();
            }
        }
    }
};
inline OwnerConfig makeResidentOwnerConfig(ShaderBundle shaders) {
    auto immutable = std::make_shared<const ShaderBundle>(std::move(shaders));
    OwnerConfig configuration{};
    configuration.factory = [immutable](Vulkan::Device& device, ParallelGS::GSInterface& gs) {
        return std::make_unique<ParallelWhole2eaOwner>(device, gs, *immutable);
    };
    // Root must supply complete reached/producer/effect/coherence proofs before
    // explicitly enabling this factory in the normal game's private Config.
    configuration.enabled = false;
    configuration.fullProtocolCoverage = false;
    return configuration;
}
} // namespace reo_resident_live
