#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace reo {

/*
 * NBD (NETBIO Data) Parser
 *
 * NBD files are the master 3D data containers in RE Outbreak.
 * Chunk directory at offset 0: entries of [type:4][offset:4][size:4][count:4]
 * terminated by an all-zero entry, padded to 16-byte boundary (0x40).
 *
 * Known chunk types:
 *   TEX  (0x00584554) - TIM2 textures (may be LZSS compressed)
 *   AMO  (0x004F4D41) - Animated model objects (geometry + skeleton)
 *   AHI  (0x00494841) - Animation/hit data
 */

constexpr uint32_t NBD_TYPE_TEX = 0x00584554; // "TEX\0"
constexpr uint32_t NBD_TYPE_AMO = 0x004F4D41; // "AMO\0"
constexpr uint32_t NBD_TYPE_AHI = 0x00494841; // "AHI\0"

struct NbdChunk {
    uint32_t type;      // Chunk type (TEX/AMO/AHI)
    uint32_t offset;    // Offset within NBD file to chunk data
    uint32_t size;      // Chunk data size in bytes
    uint32_t count;     // Sub-item count (e.g. number of textures)
};

class NbdParser {
public:
    NbdParser() = default;

    // Parse from memory buffer
    bool parse(const uint8_t* data, uint32_t size);

    // Parse from file
    bool parse(const std::string& path);

    int chunk_count() const { return (int)m_chunks.size(); }
    const NbdChunk& chunk(int index) const { return m_chunks[index]; }

    // Find chunks by type. Returns indices into chunk array.
    std::vector<int> find_chunks(uint32_t type) const;

    // Get pointer to chunk data within the original buffer.
    // Caller must ensure the original buffer outlives the returned pointer.
    const uint8_t* chunk_data(int index) const {
        if (index < 0 || index >= (int)m_chunks.size() || !m_data) return nullptr;
        return m_data + m_chunks[index].offset;
    }

    // Access the full NBD buffer
    const uint8_t* data() const { return m_data; }
    uint32_t data_size() const { return m_size; }

private:
    bool parse_directory();

    std::vector<NbdChunk> m_chunks;
    const uint8_t* m_data = nullptr; // Non-owning pointer to parsed buffer
    uint32_t m_size = 0;
    std::vector<uint8_t> m_owned_data; // Owned copy when loading from file
};

} // namespace reo
