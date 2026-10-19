#pragma once
// New private stream ABI; never uses the offline per-job cold-array ABI.
#include "ordered_stream_abi.hpp"
#include "resident_program_bank.hpp"
#include <array>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
namespace reo_gpu_array_bridge {
namespace stream = reo_gpu_ordered_mesh;
static_assert(stream::SparseTreeBase == 138496u && stream::SparseTreeWords == 524288u &&
                  stream::MapCapacityWords == 662784u && stream::BufferBytes[5] == 2651136u,
              "Sparse index shader/refs allocation ABI differs");
static_assert(stream::SparseEventsPerJob == 130u && stream::SparseClearGrid == 8192u,
              "Sparse event/clear grid ABI differs");
enum class StageRole : uint8_t { InputSnapshot, Geometry, OrderedCompose, RigidStqCarry };
// Exact private sparse shader grids. Host arithmetic computes only launch
// dimensions from bounded raw tape/job counts, never geometry or row values.
enum class Dispatch : uint8_t {
    One,
    SparseTreeClear,
    SparseEventScatter,
    SparseRowSnapshots,
    PerJob
};
struct Stage {
    std::string name;
    std::vector<uint32_t> spirv;
    StageRole role = StageRole::Geometry;
    Dispatch dispatch = Dispatch::PerJob;
};
struct Proofs {
    // Each flag needs named exact source/module/evidence pins. None is inferred
    // from the earlier72 independently replayed cold-array controls.
    bool typedLiveInput = false, orderedStateCarry = false, geometry = false;
    bool orderedHistoryAndClip = false, terminalAliases = false, sourceGuards = false;
    bool fullEffects = false, guardedAuthoritativeCommit = false, sameOwnerConsumer = false;
    bool rigidGeometry = false, rigidOrderedStqCarry = false;
    bool rigidIntegerCarry = false, mixedStageOrder = false;
    bool complete() const noexcept {
        return typedLiveInput && orderedStateCarry && geometry && orderedHistoryAndClip &&
               terminalAliases && sourceGuards && fullEffects && guardedAuthoritativeCommit &&
               sameOwnerConsumer && rigidGeometry && rigidOrderedStqCarry && rigidIntegerCarry &&
               mixedStageOrder;
    }
};
struct Bundle {
    uint64_t exactImageBinding = 0;
    std::array<uint8_t, 16384> exactImage{};
    std::vector<Stage> orderedStages;
    std::vector<uint32_t> guardedExport;
    Proofs proofs{};
    bool activationRequested = false;
};
struct Input {
    std::vector<stream::Command> commands;
    std::vector<std::array<uint8_t, 16>> rawRows;
    std::vector<stream::Job> jobs;
    std::vector<stream::Echo> echoes;
    bool empty() const noexcept {
        return jobs.empty();
    }
};
class Pipeline {
    Vulkan::Device& device_;
    Bundle bundle_;
    std::vector<Vulkan::Program*> stages_;
    Vulkan::Program* export_ = nullptr;
    std::array<Vulkan::BufferHandle, 8> banks_{};
    static constexpr uint32_t GlobalResultWords = 64;
    void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& bank, VkPipelineStageFlags stage,
                 VkAccessFlags2 access) {
        cmd.buffer_barrier(bank, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, stage,
                           access);
    }
    void upload(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& bank, size_t at, const void* data,
                size_t bytes) {
        if (!bytes)
            return;
        if (!data || (at & 3u) || (bytes & 3u) || at + bytes > bank.get_create_info().size)
            throw std::out_of_range("Ordered stream raw/metadata upload bounds");
        barrier(cmd, bank, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        const auto* raw = static_cast<const uint8_t*>(data);
        // vkCmdUpdateBuffer permits at most64KiB in one update. This is literal
        // copying, not lane scatter, geometry conversion or host bank gathering.
        for (size_t n = 0; n < bytes; n += 65536u) {
            const size_t count = std::min<size_t>(65536u, bytes - n);
            cmd.update_buffer_inline(bank, at + n, count, raw + n);
        }
        cmd.buffer_barrier(bank, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    Vulkan::Program* program(const std::vector<uint32_t>& code) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Missing pinned ordered-stream SPIR-V");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0xffu;
        for (unsigned b = 0; b < 8; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = sizeof(stream::Push);
        auto* p = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!p || !p->get_pipeline_layout())
            throw std::runtime_error("Ordered stream program creation failed");
        const auto& r = p->get_pipeline_layout()->get_resource_layout();
        if (r.descriptor_set_mask != 1 || r.bindless_descriptor_set_mask ||
            r.sets[0].storage_buffer_mask != 0xffu ||
            r.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT || r.push_constant_range.offset ||
            r.push_constant_range.size != sizeof(stream::Push) ||
            r.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Ordered stream requires its own eight-SSBO/push16 interface");
        for (unsigned b = 0; b < 8; ++b)
            if (r.sets[0].meta[b].array_size != 1 ||
                r.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Ordered stream binding differs");
        return p;
    }
    void copy(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& destination, size_t to,
              const Vulkan::Buffer& source, size_t from, size_t bytes) {
        barrier(cmd, source, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        barrier(cmd, destination, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(destination, to, source, from, bytes);
        cmd.buffer_barrier(destination, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }

  public:
    Pipeline(Vulkan::Device& device, Bundle bundle) : device_(device), bundle_(std::move(bundle)) {
        if (!bundle_.activationRequested || !bundle_.proofs.complete() ||
            !bundle_.exactImageBinding || bundle_.orderedStages.empty() ||
            bundle_.guardedExport.empty())
            throw std::runtime_error("Ordered stream activation lacks explicitly scoped proofs");
        constexpr std::array<const char*, 14> expectedOrder{
            "tape_validate",   "provenance_clear", "provenance_scatter", "row_versions",
            "prefix_prepare",  "geometry_mode1",   "geometry_mode2",     "packet_compose",
            "rigid_stq_carry", "history_resolve",  "terminal_mode1",     "terminal_mode2",
            "carry_fixup",     "event_certify"};
        constexpr std::array<Dispatch, 14> expectedDispatch{Dispatch::One,
                                                            Dispatch::SparseTreeClear,
                                                            Dispatch::SparseEventScatter,
                                                            Dispatch::SparseRowSnapshots,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob,
                                                            Dispatch::PerJob};
        constexpr std::array<StageRole, 14> expectedRoles{
            StageRole::InputSnapshot,  StageRole::InputSnapshot,  StageRole::InputSnapshot,
            StageRole::InputSnapshot,  StageRole::InputSnapshot,  StageRole::Geometry,
            StageRole::Geometry,       StageRole::OrderedCompose, StageRole::RigidStqCarry,
            StageRole::OrderedCompose, StageRole::Geometry,       StageRole::Geometry,
            StageRole::OrderedCompose, StageRole::OrderedCompose};
        if (bundle_.orderedStages.size() != expectedOrder.size())
            throw std::invalid_argument("Incomplete mixed ordered stage sequence");
        for (size_t stage = 0; stage < expectedOrder.size(); ++stage)
            if (bundle_.orderedStages[stage].name != expectedOrder[stage] ||
                bundle_.orderedStages[stage].dispatch != expectedDispatch[stage] ||
                bundle_.orderedStages[stage].role != expectedRoles[stage])
                throw std::invalid_argument(
                    "Reordered/missing mixed geometry, STQ, VI12/VI14 carry or event stage");
        bool input = false, geometry = false, compose = false, rigidStq = false;
        for (const auto& stage : bundle_.orderedStages) {
            if (stage.name.empty())
                throw std::invalid_argument("Unnamed ordered module");
            input |= stage.role == StageRole::InputSnapshot;
            geometry |= stage.role == StageRole::Geometry;
            compose |= stage.role == StageRole::OrderedCompose;
            rigidStq |= stage.role == StageRole::RigidStqCarry;
            stages_.push_back(program(stage.spirv));
        }
        if (!input || !geometry || !compose || !rigidStq)
            throw std::invalid_argument(
                "Missing GPU input/geometry/ordered compose/rigid STQ carry stages");
        export_ = program(bundle_.guardedExport);
        for (unsigned b = 0; b < 8; ++b) {
            Vulkan::BufferCreateInfo c{};
            c.domain = Vulkan::BufferDomain::Device;
            c.size = stream::BufferBytes[b];
            c.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                      VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            banks_[b] = device_.create_buffer(c);
            if (!banks_[b])
                throw std::runtime_error("Ordered stream bank allocation failed");
        }
        // request_program runs on the existing GS Device, before first dispatch.
    }
    uint64_t exactImageBinding() const noexcept {
        return bundle_.exactImageBinding;
    }
    bool exactImage(const std::array<uint8_t, 16384>& image) const noexcept {
        return image == bundle_.exactImage;
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const Input& in,
                 reo_resident_live::ProgramBank& authoritative,
                 const reo_gpu_mesh_pool::MeshPool& pool,
                 const std::vector<reo_gpu_mesh_pool::MeshPool::Slice>& slices) {
        if (in.jobs.empty() || in.jobs.size() > stream::MaxJobs ||
            in.jobs.size() != in.echoes.size() || in.jobs.size() != slices.size() ||
            in.commands.empty() || in.commands.size() > stream::MaxCommands ||
            in.rawRows.size() + 1024u > stream::MaxRawRows || pool.owner() != &device_)
            throw std::invalid_argument("Incomplete bounded ordered stream input");
        for (const auto& s : slices)
            pool.validate(s);
        for (size_t j = 0; j < in.jobs.size(); ++j) {
            const auto& p = in.jobs[j];
            if (p.operation != 4 || p.maxPairs != 65536 || p.top > 1023 || p.itop > 1023 ||
                !p.capacity || p.capacity > 256 || (p.selector != 1 && p.selector != 2) ||
                p.reserved || in.echoes[j].kindCountFlags[0] != 1 ||
                in.echoes[j].kindCountFlags[1] != 39 || (in.echoes[j].qwords[0][0] & 32767u) != 39)
                throw std::invalid_argument(
                    "First live ordered families are exact rigid39/weighted39 resume");
        }
        const stream::Push push{uint32_t(in.jobs.size()), stream::MaxJobs,
                                uint32_t(in.commands.size()), uint32_t(in.rawRows.size() + 1024u)};
        // One initial full bank/state copy per group, from the current GPU
        // authority. There is no perjob CPU/GPU16KiB input-bank snapshot.
        copy(cmd, *banks_[0], 0, authoritative.state(), 0, 632);
        copy(cmd, *banks_[1], 0, authoritative.data(), 0, 16384);
        const std::array<uint32_t, 64> zero{};
        std::vector<uint32_t> result(64u + in.jobs.size() * 64u, 0u);
        for (size_t j = 0; j < in.jobs.size(); ++j)
            result[64u + j * 64u] = uint32_t(stream::Status::Pending);
        upload(cmd, *banks_[3], 0, result.data(), result.size() * 4u);
        copy(cmd, *banks_[3], 0, authoritative.completion(), 32, 4);
        upload(cmd, *banks_[1], 16384, in.rawRows.data(), in.rawRows.size() * 16u);
        upload(cmd, *banks_[6], 0, in.echoes.data(), in.echoes.size() * sizeof(stream::Echo));
        upload(cmd, *banks_[7], 0, zero.data(), 64);
        upload(cmd, *banks_[7], size_t(stream::JobMetaBase) * 4, in.jobs.data(),
               in.jobs.size() * sizeof(stream::Job));
        upload(cmd, *banks_[7], size_t(stream::CommandBase) * 4, in.commands.data(),
               in.commands.size() * sizeof(stream::Command));
        for (size_t stage = 0; stage < stages_.size(); ++stage) {
            for (const auto& bank : banks_)
                barrier(cmd, *bank, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd.set_program(stages_[stage]);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *banks_[b]);
            cmd.push_constants(&push, 0, sizeof(push));
            const auto grid = bundle_.orderedStages[stage].dispatch;
            const uint32_t groups =
                grid == Dispatch::One               ? 1u
                : grid == Dispatch::SparseTreeClear ? stream::SparseClearGrid
                : grid == Dispatch::SparseEventScatter
                    ? (push.commandCount + push.jobCount * stream::SparseEventsPerJob + 63u) / 64u
                : grid == Dispatch::SparseRowSnapshots ? 16u * (push.jobCount + 1u)
                                                       : push.jobCount;
            cmd.dispatch(groups, 1, 1);
        }
        // The peer-owned guarded export validates ALL statuses and final row
        // references before touching authority. A failed transaction publishes
        // only sticky completion; a blind state/data transfer is forbidden.
        for (const auto& bank : banks_)
            barrier(cmd, *bank, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        for (const auto* bank :
             {&authoritative.state(), &authoritative.data(), &authoritative.completion()})
            barrier(cmd, *bank, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(export_);
        cmd.set_storage_buffer(0, 0, *banks_[0]);
        cmd.set_storage_buffer(0, 1, *banks_[1]);
        cmd.set_storage_buffer(0, 2, *banks_[4]);
        cmd.set_storage_buffer(0, 3, *banks_[5]);
        cmd.set_storage_buffer(0, 4, *banks_[3]);
        cmd.set_storage_buffer(0, 5, authoritative.state());
        cmd.set_storage_buffer(0, 6, authoritative.data());
        cmd.set_storage_buffer(0, 7, authoritative.completion());
        cmd.push_constants(&push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
        for (size_t j = 0; j < slices.size(); ++j) {
            const auto& slice = slices[j];
            copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::Events),
                 slice.offsets[reo_gpu_mesh_pool::MeshPool::Events], *banks_[2], j * 16640u, 16400);
            copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::NativeVertices),
                 slice.offsets[reo_gpu_mesh_pool::MeshPool::NativeVertices], *banks_[4], j * 32768u,
                 32768);
            // These are composed GPU bytes, not six encoded history references.
            copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::History),
                 slice.offsets[reo_gpu_mesh_pool::MeshPool::History], *banks_[2], j * 16640u + 32u,
                 96);
            copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                 slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape], *banks_[3],
                 (GlobalResultWords + j * 64u) * 4u, 48);
            // Every downstream mesh sees global transaction failure, even when
            // its own first12 result words preceded a later failed job.
            copy(cmd, pool.bank(reo_gpu_mesh_pool::MeshPool::CompletionTape),
                 slice.offsets[reo_gpu_mesh_pool::MeshPool::CompletionTape] + 32u,
                 authoritative.completion(), 32, 4);
        }
    }
};
} // namespace reo_gpu_array_bridge
