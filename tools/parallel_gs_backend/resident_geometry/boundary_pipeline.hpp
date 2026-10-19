#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace reo_gpu_boundary {
enum class Scope : uint8_t { OfflineComponent, ScopedLive };
struct Proofs {
    bool exactPinnedComponentAssets = false, gpuInputPreparation = false;
    bool guardedAuthoritativePublication = false, sharedDeviceProtocol = false;
    bool complete() const noexcept {
        return exactPinnedComponentAssets && gpuInputPreparation &&
               guardedAuthoritativePublication && sharedDeviceProtocol;
    }
};
constexpr std::array<const char*, 8> StageNames{"prefix_mode1",   "prefix_mode2", "geometry_mode1",
                                                "geometry_mode2", "suffix_mode1", "suffix_mode2",
                                                "control",        "fallback"};
constexpr std::array<const char*, 8> StageSHA256{
    "8ba55cfd0225e2b0d0043e5541357bbea465b649cf4637864dd72a7604335675",
    "f75c38dfdb801759e410756822bac80fd93f9b86709b0dc0e152dd7e034d78a0",
    "cd1b601604c8ec75b13cf5a475ead2813522cb3aadedc5c2301cace97105f349",
    "2ac5b6f52c97d25fc7d020857f39dcf57099529bf681d72624256f23e991a93c",
    "8ee40cd15ceb29420bc3a1029b98a2ebf9d41e4d3242be617fcdf625c478cfc5",
    "32f70b7bbc6a5d16fd56ff51b67aa8094563eb1bbca6a1dc9dcce6d394ab62d8",
    "3e8a461b76e4a89db8845402b635c6f4594c905d9795568e6d2e78b85f694726",
    "6af3cc8d8e3d7806f4825d656cbc3a5ad54f8c7f0bf6656f8856cecc7a352731"};
constexpr std::array<size_t, 8> Bytes{1536, 32768, 16640, 256, 32768, 256, 256, 32};
struct Bundle {
    std::array<std::vector<uint32_t>, 8> stages;
    std::vector<uint32_t> prepare, commit;
    uint64_t exactImageBinding = 0;
    std::array<uint8_t, 16384> exactImage{};
    Proofs proofs{};
    bool activationRequested = false;
};
struct Authority {
    const Vulkan::Device* owner = nullptr;
    const Vulkan::Buffer* state = nullptr;
    const Vulkan::Buffer* data = nullptr;
    const Vulkan::Buffer* completion = nullptr;
};
struct alignas(16) Echo {
    std::array<uint32_t, 4> kindCountFlags{};
    std::array<std::array<uint32_t, 4>, 7> qwords{};
    std::array<std::array<uint32_t, 4>, 8> padding{};
};
struct Job {
    uint32_t entryPC, maxPairs, top, itop, operation, capacity, selector, reserved;
};
struct Push {
    uint32_t count, capacity, reserved0, reserved1;
};
struct Request {
    uint32_t entryPC = 0, top = 0, itop = 0, operation = 4, capacity = 256;
    Echo echo{};
};
static_assert(sizeof(Echo) == 256 && sizeof(Job) == 32 && sizeof(Push) == 16);
class Pipeline {
    Vulkan::Device& device_;
    Bundle bundle_;
    Scope scope_;
    std::array<Vulkan::BufferHandle, 8> banks_{};
    std::array<Vulkan::Program*, 8> stages_{};
    Vulkan::Program *prepare_ = nullptr, *commit_ = nullptr;
    Vulkan::Program* program(const std::vector<uint32_t>& code) {
        if (code.size() < 5 || code[0] != 0x07230203)
            throw std::invalid_argument("Missing boundary SPIR-V");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0xffu;
        layout.push_constant_size = 16;
        for (unsigned b = 0; b < 8; ++b)
            layout.sets[0].meta[b].array_size = 1;
        auto* p = device_.request_program(code.data(), code.size() * 4, &layout);
        if (!p || !p->get_pipeline_layout())
            throw std::runtime_error("Boundary program creation failed");
        const auto& a = p->get_pipeline_layout()->get_resource_layout();
        if (a.descriptor_set_mask != 1 || a.bindless_descriptor_set_mask ||
            a.sets[0].storage_buffer_mask != 0xffu ||
            a.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT || a.push_constant_range.offset ||
            a.push_constant_range.size != 16 ||
            a.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Boundary eight-SSBO/push16 interface differs");
        for (unsigned b = 0; b < 8; ++b)
            if (a.sets[0].meta[b].array_size != 1 ||
                a.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Boundary binding differs");
        return p;
    }
    static void shape(const Vulkan::Buffer* b, size_t bytes) {
        if (!b || b->get_create_info().domain != Vulkan::BufferDomain::Device ||
            b->get_create_info().size != bytes ||
            !(b->get_create_info().usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT))
            throw std::invalid_argument("Boundary requires exact same-owner GPU authority shape");
    }
    void barrier(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& b, VkPipelineStageFlags stage,
                 VkAccessFlags2 access) {
        cmd.buffer_barrier(b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT, stage,
                           access);
    }

  public:
    Pipeline(Vulkan::Device& device, Bundle bundle, Scope scope = Scope::ScopedLive)
        : device_(device), bundle_(std::move(bundle)), scope_(scope) {
        if (scope_ == Scope::ScopedLive &&
            (!bundle_.activationRequested || !bundle_.proofs.complete() ||
             !bundle_.exactImageBinding))
            throw std::runtime_error("Boundary live owner scope is unproved/default-off");
        if (scope_ == Scope::ScopedLive) {
            std::vector<uint8_t> image(bundle_.exactImage.begin(), bundle_.exactImage.end());
            if (bundle_.exactImageBinding != 0x2ea02b3628231f11ull ||
                reo_gpu_catalog::sha256(image) !=
                    "2ea02b3628231f113edc3fe580f80c1d6ed45c98a7c98f9f83005665f8ad32ce")
                throw std::invalid_argument(
                    "Boundary live image differs from the exact proved2EA program");
        }
        // OfflineComponent is a visibly labeled numerical caller seam. It does
        // not set or satisfy production flags and creates no alternate Device.
        for (unsigned i = 0; i < 8; ++i) {
            std::vector<uint8_t> raw(bundle_.stages[i].size() * 4);
            std::memcpy(raw.data(), bundle_.stages[i].data(), raw.size());
            if (reo_gpu_catalog::sha256(raw) != StageSHA256[i])
                throw std::invalid_argument(
                    "Not the exact root-proved control-b boundary shader asset");
            stages_[i] = program(bundle_.stages[i]);
        }
        const auto digest = [](const std::vector<uint32_t>& code) {
            std::vector<uint8_t> raw(code.size() * 4);
            std::memcpy(raw.data(), code.data(), raw.size());
            return reo_gpu_catalog::sha256(raw);
        };
        if (digest(bundle_.prepare) !=
                "20cca747a0f64979adf1aa059986cf5c22650d8379eccf8d319536c2035bd4f4" ||
            digest(bundle_.commit) !=
                "6c2529a95dfa43fe8708d9b52a34119ae17d1ffe3f54d6788fbc0255cc0c4b8b")
            throw std::invalid_argument("Boundary integer preparation/publication asset differs");
        prepare_ = program(bundle_.prepare);
        commit_ = program(bundle_.commit);
        for (unsigned b = 0; b < 8; ++b) {
            Vulkan::BufferCreateInfo info{};
            info.domain = Vulkan::BufferDomain::Device;
            info.size = Bytes[b];
            info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                         VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            banks_[b] = device_.create_buffer(info);
            if (!banks_[b])
                throw std::runtime_error("Boundary staging allocation failed");
        }
    }
    uint64_t binding() const noexcept {
        return bundle_.exactImageBinding;
    }
    bool image(const std::array<uint8_t, 16384>& image) const noexcept {
        return image == bundle_.exactImage;
    }
    Scope scope() const noexcept {
        return scope_;
    }
    void copy(Vulkan::CommandBuffer& cmd, const Vulkan::Buffer& destination, size_t to,
              const Vulkan::Buffer& source, size_t from, size_t bytes) {
        if (!bytes || to + bytes > destination.get_create_info().size ||
            from + bytes > source.get_create_info().size)
            throw std::out_of_range("Boundary GPU transfer range");
        barrier(cmd, source, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        barrier(cmd, destination, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.copy_buffer(destination, to, source, from, bytes);
        cmd.buffer_barrier(destination, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    void enqueue(Vulkan::CommandBuffer& cmd, const Authority& owner, const Request& request) {
        if (owner.owner != &device_)
            throw std::invalid_argument("Boundary Device differs from current GS owner");
        shape(owner.state, 632);
        shape(owner.data, 16384);
        shape(owner.completion, 48);
        if (owner.state == owner.data || owner.state == owner.completion ||
            owner.data == owner.completion || request.top > 1023 || request.itop > 1023 ||
            (request.operation != 0 && request.operation != 4) || !request.capacity ||
            request.capacity > 256 || request.echo.kindCountFlags[0] > 2)
            throw std::invalid_argument("Unsupported boundary launch envelope");
        copy(cmd, *banks_[0], 0, *owner.state, 0, 632);
        copy(cmd, *banks_[1], 0, *owner.data, 0, 16384);
        const uint32_t zero[64]{};
        barrier(cmd, *banks_[3], VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*banks_[3], 0, sizeof(zero), zero);
        copy(cmd, *banks_[3], 32, *owner.completion, 32, 4);
        const Job job{request.operation == 4 ? 0x3ff8u : request.entryPC,
                      65536,
                      request.top,
                      request.itop,
                      request.operation,
                      request.capacity,
                      0,
                      0};
        for (unsigned binding : {6u, 7u})
            barrier(cmd, *banks_[binding], VK_PIPELINE_STAGE_TRANSFER_BIT,
                    VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*banks_[6], 0, sizeof(request.echo), &request.echo);
        cmd.update_buffer_inline(*banks_[7], 0, sizeof(job), &job);
        const Push push{1, 1, 0, 0};
        for (unsigned stage = 0; stage < 9; ++stage) {
            for (const auto& bank : banks_)
                barrier(cmd, *bank, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
            cmd.set_program(stage == 0 ? prepare_ : stages_[stage - 1]);
            for (unsigned b = 0; b < 8; ++b)
                cmd.set_storage_buffer(0, b, *banks_[b]);
            cmd.push_constants(&push, 0, 16);
            cmd.dispatch(1, 1, 1);
        }
        for (const auto& bank : banks_)
            barrier(cmd, *bank, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        for (const auto* bank : {owner.state, owner.data, owner.completion})
            barrier(cmd, *bank, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_2_SHADER_STORAGE_READ_BIT | VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(commit_);
        for (unsigned b = 0; b < 4; ++b)
            cmd.set_storage_buffer(0, b, *banks_[b]);
        cmd.set_storage_buffer(0, 4, *banks_[6]);
        cmd.set_storage_buffer(0, 5, *owner.state);
        cmd.set_storage_buffer(0, 6, *owner.data);
        cmd.set_storage_buffer(0, 7, *owner.completion);
        const uint32_t contract[4]{request.operation, request.echo.kindCountFlags[0],
                                   request.capacity, 0};
        cmd.push_constants(contract, 0, 16);
        cmd.dispatch(1, 1, 1);
    }
    const Vulkan::Buffer& state() const {
        return *banks_[0];
    }
    const Vulkan::Buffer& data() const {
        return *banks_[1];
    }
    const Vulkan::Buffer& events() const {
        return *banks_[2];
    }
    const Vulkan::Buffer& result() const {
        return *banks_[3];
    }
    const Vulkan::Buffer& native() const {
        return *banks_[4];
    }
    const Vulkan::Buffer& history() const {
        return *banks_[5];
    }
    // Views remain until the NEXT enqueue. Production copies immutable pooled
    // outputs immediately; an offline caller may GPU-copy diagnostic snapshots.
};
} // namespace reo_gpu_boundary
