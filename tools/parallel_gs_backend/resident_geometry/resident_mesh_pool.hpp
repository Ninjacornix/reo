#pragma once
#include "device.hpp"
#include "command_buffer.hpp"
#include "resident_draw.hpp"
#include <array>
#include <cstdint>
#include <stdexcept>

namespace reo_gpu_mesh_pool {
// Immutable per-mesh output ranges on the existing GS Device. The caller owns
// this whole pool through a real GS completion timeline/epoch. No vertex data
// are mapped, transformed, copied to the host or counted by the coordinator.
class MeshPool {
    Vulkan::Device& device_;
    std::array<Vulkan::BufferHandle, 8> buffers_{};
    std::array<VkDeviceSize, 8> strides_{};
    uint32_t slots_ = 0, next_ = 0;
    uint64_t epoch_ = 0;
    static VkDeviceSize align(VkDeviceSize value, VkDeviceSize alignment) {
        return ((value + alignment - 1) / alignment) * alignment;
    }

  public:
    enum Binding : unsigned {
        NativeVertices,
        History,
        Events,
        Positions,
        Attributes,
        Primitives,
        CompletionTape,
        ExpansionStatus
    };
    static constexpr uint32_t Capacity = 256;
    static constexpr std::array<VkDeviceSize, 8> Bytes{
        Capacity * 128u, 96u, 16400u, Capacity * 3u * 16u, Capacity * 3u * 24u,
        Capacity * 32u,  48u, 16u};
    struct Slice {
        const MeshPool* pool = nullptr;
        uint32_t slot = 0;
        uint64_t epoch = 0;
        std::array<VkDeviceSize, 8> offsets{};
    };
    MeshPool(Vulkan::Device& device, uint32_t slots, uint64_t epoch)
        : device_(device), slots_(slots), epoch_(epoch) {
        if (!slots || slots > 2048)
            throw std::invalid_argument("Invalid bounded mesh pool capacity");
        const VkDeviceSize alignment =
            device.get_gpu_properties().limits.minStorageBufferOffsetAlignment;
        for (unsigned binding = 0; binding < buffers_.size(); ++binding) {
            strides_[binding] = align(Bytes[binding], alignment ? alignment : 1);
            Vulkan::BufferCreateInfo info{};
            info.domain = Vulkan::BufferDomain::Device;
            info.size = strides_[binding] * slots;
            info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT |
                         VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            buffers_[binding] = device.create_buffer(info);
            if (!buffers_[binding])
                throw std::runtime_error("Mesh output pool allocation failed");
        }
    }
    MeshPool(const MeshPool&) = delete;
    MeshPool& operator=(const MeshPool&) = delete;
    Slice allocate() {
        if (next_ == slots_)
            throw std::overflow_error("Mesh pool full; actual completion is required before reuse");
        Slice s{};
        s.pool = this;
        s.slot = next_++;
        s.epoch = epoch_;
        for (unsigned b = 0; b < buffers_.size(); ++b)
            s.offsets[b] = strides_[b] * s.slot;
        return s;
    }
    void validate(const Slice& s) const {
        if (s.pool != this || s.epoch != epoch_ || s.slot >= next_)
            throw std::invalid_argument("Foreign, stale or unallocated mesh slice");
        for (unsigned b = 0; b < buffers_.size(); ++b)
            if (s.offsets[b] != strides_[b] * s.slot)
                throw std::invalid_argument("Altered mesh slice range");
    }
    void bind_output(Vulkan::CommandBuffer& cmd, unsigned set, unsigned targetBinding, Binding bank,
                     const Slice& s) const {
        validate(s);
        const unsigned b = unsigned(bank);
        cmd.set_storage_buffer(set, targetBinding, *buffers_[b], s.offsets[b], Bytes[b]);
    }
    ParallelGS::ResidentPrimitiveInputs draw_inputs(const Slice& s, uint32_t capacity) const {
        validate(s);
        if (!capacity || capacity > Capacity)
            throw std::invalid_argument("Invalid declared mesh draw capacity");
        ParallelGS::ResidentPrimitiveInputs in{};
        in.owner = &device_;
        in.positions = buffers_[Positions];
        in.attributes = buffers_[Attributes];
        in.primitives = buffers_[Primitives];
        in.positionOffset = s.offsets[Positions];
        in.attributeOffset = s.offsets[Attributes];
        in.primitiveOffset = s.offsets[Primitives];
        in.primitiveCount = capacity;
        // Set only after the admitted GPU expansion path also gates completion
        // status and initializes every unused capacity slot to a dead triangle.
        in.exactFixedTopologyCertificate = false;
        return in;
    }
    const Vulkan::Buffer& bank(Binding b) const {
        return *buffers_[unsigned(b)];
    }
    uint32_t used() const {
        return next_;
    }
    uint64_t epoch() const {
        return epoch_;
    }
    const Vulkan::Device* owner() const {
        return &device_;
    }
    // Deliberately no rewind. Keep the pool immutable until real retirement,
    // then construct another epoch-owned pool; enqueue alone cannot recycle it.
};
} // namespace reo_gpu_mesh_pool
