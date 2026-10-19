#pragma once
// Private owner-side proposal; not added to runtime public headers or f.
#include "device.hpp"
#include "command_buffer.hpp"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <stdexcept>
namespace reo_palette_lease {
struct Identity {
    uint64_t session = 0, bankGeneration = 0, allocationGeneration = 0, productionOrdinal = 0;
    uint32_t guestPayload = 0, bytes = 0;
};
// The creator is the SAME GS Device owner and retains buffers in its submitted
// prefix. Runtime transports an opaque shared lifetime, never GPU output bytes.
// This internal structure is not an admission API for arbitrary BufferHandles;
// live issuance must use the owner's own allocation registry because Granite
// exposes no public Buffer Device identity. The fixture creates every buffer
// using its sole Device. A matching pointer label is not proof of foreign buffers.
struct Payload {
    const Vulkan::Device* device = nullptr;
    Vulkan::BufferHandle buffer;
    const Vulkan::Buffer* completion = nullptr;
    std::shared_ptr<const void> lifetime;
    Identity identity{};
    uint32_t sourceOffset = 0;
};
inline void validate(const Payload& p, const Vulkan::Device& owner,
                     const Vulkan::Buffer& completion, uint64_t session, uint64_t bankGeneration,
                     uint64_t allocation, uint32_t guestSource, uint32_t bytes) {
    if (p.device != &owner || !p.buffer || p.completion != &completion || !p.lifetime || !session ||
        !bankGeneration || !allocation || !p.identity.productionOrdinal ||
        p.identity.session != session || p.identity.bankGeneration != bankGeneration ||
        p.identity.allocationGeneration != allocation || p.identity.guestPayload != guestSource ||
        p.identity.bytes != bytes || p.sourceOffset != 0 || !bytes || bytes > 4096 || (bytes & 3u))
        throw std::invalid_argument("Foreign/stale/incomplete immutable GPU payload lease");
    const auto& b = p.buffer->get_create_info();
    if (b.domain != Vulkan::BufferDomain::Device || b.size < bytes ||
        !(b.usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) || p.buffer.get() == &completion)
        throw std::invalid_argument("GPU payload bank range/domain/alias differs");
}
// Needed at DMA extraction, chain concatenation and incomplete VIF retention.
// streamOffset names the concatenated RAW parser byte position, not pointer
// identity or content hash. An unknown/cross-allocation origin fails closed.
struct Origin {
    uint32_t streamOffset = 0, guestAddress = 0, bytes = 0;
    uint64_t allocationGeneration = 0;
};
inline bool contiguousPayload(const Origin* spans, size_t count, uint32_t at, uint32_t bytes,
                              uint32_t guestSource, uint64_t allocation) {
    if (!spans || !count || !bytes || !allocation)
        return false;
    uint64_t cursor = at, end = uint64_t(at) + bytes, guest = guestSource;
    for (size_t i = 0; i < count && cursor < end; ++i) {
        const auto& span = spans[i];
        const uint64_t begin = span.streamOffset, finish = begin + span.bytes;
        if (finish <= cursor)
            continue;
        if (begin > cursor || span.allocationGeneration != allocation)
            return false;
        const uint64_t delta = cursor - begin, available = finish - cursor,
                       take = available < end - cursor ? available : end - cursor;
        if (uint64_t(span.guestAddress) + delta != guest)
            return false;
        cursor += take;
        guest += take;
    }
    return cursor == end;
}
// Required private Operation addition (proposal, not present in candidate-f):
// shared_ptr<const Payload> gpuPayload; uint32_t rawGuestSource;
// uint64_t sourceAllocationGeneration. Queue snapshots keep the token alive.
// CPU literal provenance MUST mark covered GPU-generated rows unknown;
// it cannot synthesize command effects by reading stale host palette bytes.
} // namespace reo_palette_lease
