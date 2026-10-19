#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "parent/gpu_payload_lease.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>
#include <vector>

namespace reo_gpu_vif_upload {
struct ColdControl {
    std::array<uint32_t, 4> row{}, column{};
    uint32_t cycle = 0, mode = 0, mask = 0, reserved = 0;
};
struct Push {
    uint32_t command, payloadBytes, tops, reserved;
};
static_assert(sizeof(ColdControl) == 48 && sizeof(Push) == 16);
// Construct only beside the SAME owner's whole2EA banks, not from untrusted
// buffers passed across Route/UI. Private wrapper must own bank+uploader as one
// lifetime; Granite does not expose a public Buffer device-identity accessor.
class ResidentVifUnpack {
    Vulkan::Device& device_;
    const Vulkan::Buffer& data_;
    const Vulkan::Buffer& completion_;
    Vulkan::Program* program_ = nullptr;
    Vulkan::BufferHandle control_, payload_;
    Vulkan::BufferHandle make(size_t bytes, const void* initial) {
        Vulkan::BufferCreateInfo ci{};
        ci.domain = Vulkan::BufferDomain::Device;
        ci.size = bytes;
        ci.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                   VK_BUFFER_USAGE_TRANSFER_DST_BIT;
        auto b = device_.create_buffer(ci, initial);
        if (!b)
            throw std::runtime_error("Resident UNPACK allocation failed");
        return b;
    }

  public:
    ResidentVifUnpack(Vulkan::Device& device, const std::vector<uint32_t>& shader,
                      const Vulkan::Buffer& sameOwnerData,
                      const Vulkan::Buffer& sameOwnerCompletion, const ColdControl& cold)
        : device_(device), data_(sameOwnerData), completion_(sameOwnerCompletion) {
        if (shader.size() < 5 || shader[0] != 0x07230203 || cold.reserved ||
            data_.get_create_info().domain != Vulkan::BufferDomain::Device ||
            data_.get_create_info().size != 16384 ||
            completion_.get_create_info().domain != Vulkan::BufferDomain::Device ||
            completion_.get_create_info().size < 48)
            throw std::invalid_argument("Invalid same-owner UNPACK cold banks");
        Vulkan::ResourceLayout layout{};
        layout.sets[0].storage_buffer_mask = 0x0fu;
        for (unsigned b = 0; b < 4; ++b)
            layout.sets[0].meta[b].array_size = 1;
        layout.push_constant_size = sizeof(Push);
        program_ = device_.request_program(shader.data(), shader.size() * 4, &layout);
        if (!program_ || !program_->get_pipeline_layout())
            throw std::runtime_error("UNPACK shader creation failed");
        const auto& c = program_->get_pipeline_layout()->get_resource_layout();
        if (c.descriptor_set_mask != 1 || c.bindless_descriptor_set_mask ||
            c.sets[0].storage_buffer_mask != 0x0fu ||
            c.stages_for_sets[0] != VK_SHADER_STAGE_COMPUTE_BIT || c.push_constant_range.offset ||
            c.push_constant_range.size != sizeof(Push) ||
            c.push_constant_range.stageFlags != VK_SHADER_STAGE_COMPUTE_BIT)
            throw std::runtime_error("Unexpected explicit UNPACK interface");
        for (unsigned b = 0; b < 4; ++b)
            if (c.sets[0].meta[b].array_size != 1 ||
                c.stages_for_bindings[0][b] != VK_SHADER_STAGE_COMPUTE_BIT)
                throw std::runtime_error("Unexpected UNPACK binding");
        control_ = make(sizeof(cold), &cold);
        std::array<uint8_t, 4096> zero{};
        payload_ = make(zero.size(), zero.data());
    }
    ResidentVifUnpack(const ResidentVifUnpack&) = delete;
    ResidentVifUnpack& operator=(const ResidentVifUnpack&) = delete;
    void enqueueControlWrite(Vulkan::CommandBuffer& cmd, uint32_t byteOffset, const void* bits,
                             uint32_t bytes) {
        // Actual STROW/STCOL/STCYCL/STMOD/STMASK command bits only. Never replace
        // GPU-updated ROW from a stale CPU shadow before each UNPACK.
        if (!bits || !((byteOffset == 0 && bytes == 16) || (byteOffset == 16 && bytes == 16) ||
                       (byteOffset <= 40 && (byteOffset & 3u) == 0 && bytes == 4)))
            throw std::invalid_argument("Not a supported VIF control-register write");
        cmd.buffer_barrier(*control_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*control_, byteOffset, bytes, bits);
        cmd.buffer_barrier(*control_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                               VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
    }
    void enqueue(Vulkan::CommandBuffer& cmd, uint32_t command, uint32_t latchedTops,
                 const void* raw, uint32_t bytes) {
        // Copies raw bytes. VN/VL lane extension/scatter/masks/ROW addition run
        // only on GPU. VIF command size parsing is CPU command coordination.
        const uint32_t op = (command >> 24) & 127u;
        if (!raw || !bytes || bytes > 4096 || (bytes & 3) || ((op & 96u) != 96u) ||
            ((op & 3u) == 3u && ((op >> 2) & 3u) != 3u))
            throw std::invalid_argument("Unsupported or incomplete resident UNPACK command");
        cmd.buffer_barrier(*payload_, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT);
        cmd.update_buffer_inline(*payload_, 0, bytes, raw);
        cmd.buffer_barrier(*payload_, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_WRITE_BIT, VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        for (const auto* b :
             {&data_, &completion_, static_cast<const Vulkan::Buffer*>(control_.get())})
            cmd.buffer_barrier(*b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_READ_BIT | VK_ACCESS_2_MEMORY_WRITE_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(program_);
        cmd.set_storage_buffer(0, 0, data_);
        cmd.set_storage_buffer(0, 1, *payload_);
        cmd.set_storage_buffer(0, 2, *control_);
        cmd.set_storage_buffer(0, 3, completion_);
        const Push p{command, bytes, latchedTops, 0};
        cmd.push_constants(&p, 0, sizeof(p));
        cmd.dispatch(1, 1, 1);
    }
    void enqueueResident(Vulkan::CommandBuffer& cmd, uint32_t command, uint32_t latchedTops,
                         const reo_palette_lease::Payload& lease, uint64_t session,
                         uint64_t bankGeneration, uint64_t allocation, uint32_t guestSource) {
        // The first certified source envelope is the original248-vector pose
        // upload. Broader producers remain explicitly outside this proposal.
        if (command != 0x6cf80000u || latchedTops > 1023u)
            throw std::invalid_argument("Unproved GPU palette payload UNPACK envelope");
        constexpr uint32_t bytes = 248u * 16u;
        reo_palette_lease::validate(lease, device_, completion_, session, bankGeneration,
                                    allocation, guestSource, bytes);
        if (lease.buffer.get() == &data_ || lease.buffer.get() == control_.get())
            throw std::invalid_argument("Immutable palette payload aliases destination/control");
        cmd.buffer_barrier(*lease.buffer, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                           VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                           VK_ACCESS_2_SHADER_STORAGE_READ_BIT);
        const std::array<const Vulkan::Buffer*, 3> banks{&data_, &completion_, control_.get()};
        for (const auto* b : banks)
            cmd.buffer_barrier(*b, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                               VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                               VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                               VK_ACCESS_2_SHADER_STORAGE_READ_BIT |
                                   VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT);
        cmd.set_program(program_);
        cmd.set_storage_buffer(0, 0, data_);
        cmd.set_storage_buffer(0, 1, *lease.buffer, 0, bytes);
        cmd.set_storage_buffer(0, 2, *control_);
        cmd.set_storage_buffer(0, 3, completion_);
        const Push push{command, bytes, latchedTops, 0};
        cmd.push_constants(&push, 0, sizeof(push));
        cmd.dispatch(1, 1, 1);
        // No update_buffer_inline copies stale CPU palette bits over this GPU
        // source. Lifetime belongs to the immutable queued operation/prefix.
    }
    const Vulkan::Buffer& controls() const {
        return *control_;
    }
    const void* ownerDeviceIdentity() const noexcept {
        return &device_;
    }
    const void* destinationBankIdentity() const noexcept {
        return &data_;
    }
    const void* completionBankIdentity() const noexcept {
        return &completion_;
    }
    // No normal readback, GPU wait, CPU lane conversion or fake DMA completion.
};
} // namespace reo_gpu_vif_upload
