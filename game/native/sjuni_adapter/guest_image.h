#pragma once

// Temporary migration boundary. This file knows the guest wire layout; the
// independently buildable SJUNI core does not include it.
#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>
#include <limits>
#include <span>
#include <utility>
#include <vector>

namespace reo::sjuni::bridge {

class Memory {
public:
    explicit Memory(std::span<std::byte> bytes) : bytes_(bytes) {}
    bool contains(std::uint32_t address, std::size_t count) const noexcept {
        return count <= (std::uint64_t{1} << 32) - address &&
               address <= bytes_.size() && count <= bytes_.size() - address;
    }
    bool read32(std::uint32_t address, std::uint32_t& result) const noexcept {
        if (!contains(address, 4)) return false;
        result = 0;
        for (unsigned i = 0; i != 4; ++i)
            result |= std::uint32_t(std::to_integer<unsigned char>(bytes_[address + i])) << (8 * i);
        return true;
    }
    bool write32(std::uint32_t address, std::uint32_t value) const noexcept {
        if (!contains(address, 4)) return false;
        for (unsigned i = 0; i != 4; ++i)
            bytes_[address + i] = std::byte((value >> (8 * i)) & 255u);
        return true;
    }

private:
    std::span<std::byte> bytes_;
};

struct Profile {
    std::uint32_t object_base{};
    std::uint32_t object_slots{};
    std::uint32_t vtable{};
    std::uint32_t uuid{};
    std::uint32_t max_nodes{4096};
};

struct RawNode {
    std::array<std::uint32_t, 4> words{};
    bool operator==(const RawNode&) const = default;
};

struct Image {
    std::uint32_t address{};
    std::array<std::uint32_t, 12> words{};
    std::vector<RawNode> nodes;
    std::uint8_t mode() const noexcept { return std::uint8_t(words[1] >> 8); }
    std::uint32_t node_base() const noexcept { return words[3]; }
};

enum class Admission {
    accepted, wrong_identity, unavailable_memory, invalid_node_storage,
    overlapping_storage, invalid_chain
};

inline bool overlaps(std::uint32_t a, std::size_t an,
                     std::uint32_t b, std::size_t bn) noexcept {
    return std::uint64_t(a) < std::uint64_t(b) + bn &&
           std::uint64_t(b) < std::uint64_t(a) + an;
}

inline bool node_index(const Image& image, std::uint32_t address,
                       std::uint32_t& index) noexcept {
    if (address < image.node_base()) return false;
    const std::uint32_t offset = address - image.node_base();
    index = offset / 16u;
    return offset % 16u == 0 && index < image.nodes.size();
}

// Every metadata node belongs to exactly one of the free/four queued lists.
// This rejects cycles, duplicate membership and links outside the supplied pool
// before executing a native operation. It does not validate payload ownership.
inline bool valid_chains(const Image& image) {
    std::vector<bool> seen(image.nodes.size());
    std::size_t visited = 0;
    for (std::size_t head = 5; head != 10; ++head) {
        auto pointer = image.words[head];
        while (pointer != 0) {
            std::uint32_t index;
            if (!node_index(image, pointer, index) || seen[index]) return false;
            seen[index] = true;
            ++visited;
            pointer = image.nodes[index].words[0];
        }
    }
    return visited == image.nodes.size();
}

// All-or-nothing read: caller's Image is unchanged when admission fails.
inline Admission read_image(Memory memory, const Profile& profile,
                            std::uint32_t address, Image& destination) {
    if (profile.object_slots == 0 || address % 4 != 0 || address < profile.object_base ||
        (address - profile.object_base) % 48u != 0 ||
        (address - profile.object_base) / 48u >= profile.object_slots)
        return Admission::wrong_identity;
    Image image;
    image.address = address;
    if (!memory.contains(address, 48)) return Admission::unavailable_memory;
    for (std::size_t i = 0; i != image.words.size(); ++i)
        memory.read32(address + std::uint32_t(4 * i), image.words[i]);
    if (image.words[0] != profile.vtable || image.words[2] != profile.uuid ||
        (image.words[1] & 255u) != 1u)
        return Admission::wrong_identity;
    const auto count = std::bit_cast<std::int32_t>(image.words[4]);
    if (count <= 0 || std::uint32_t(count) > profile.max_nodes ||
        std::uint32_t(count) > std::numeric_limits<std::uint32_t>::max() / 16 ||
        image.node_base() == 0 || image.node_base() % 4 != 0)
        return Admission::invalid_node_storage;
    const auto node_bytes = std::size_t(count) * 16;
    if (!memory.contains(image.node_base(), node_bytes))
        return Admission::unavailable_memory;
    if (overlaps(address, 48, image.node_base(), node_bytes))
        return Admission::overlapping_storage;
    image.nodes.resize(std::size_t(count));
    for (std::size_t i = 0; i != image.nodes.size(); ++i)
        for (unsigned word = 0; word != 4; ++word)
            memory.read32(image.node_base() + std::uint32_t(16 * i + 4 * word),
                          image.nodes[i].words[word]);
    if (!valid_chains(image)) return Admission::invalid_chain;
    destination = std::move(image);
    return Admission::accepted;
}

// Admission precedes every write. Metadata-only mirroring leaves the object's
// callback/context/identity and each node's untouched word +4 intact.
inline bool mirror_queues(Memory memory, const Image& image) noexcept {
    if (image.nodes.size() > std::numeric_limits<std::uint32_t>::max() / 16 ||
        !memory.contains(image.address, 48) ||
        !memory.contains(image.node_base(), image.nodes.size() * 16))
        return false;
    for (std::size_t i = 0; i != image.nodes.size(); ++i) {
        const auto base = image.node_base() + std::uint32_t(16 * i);
        memory.write32(base, image.nodes[i].words[0]);
        memory.write32(base + 8, image.nodes[i].words[2]);
        memory.write32(base + 12, image.nodes[i].words[3]);
    }
    for (unsigned i = 5; i != 10; ++i)
        memory.write32(image.address + 4 * i, image.words[i]);
    return true;
}

} // namespace reo::sjuni::bridge
