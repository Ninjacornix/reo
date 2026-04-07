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
 *   TEX  (0x00584554) - TIM2 textures (OB-LZ77 compressed)
 *   TID  (0x00444954) - Texture ID references (room NBDs, AFS indices)
 *   AMO  (0x004F4D41) - Animated model objects (geometry + skeleton)
 *   AHI  (0x00494841) - Animation/hit data
 *
 * TEX chunk format:
 *   [compressed_size:4][compressed_data:compressed_size] × texCount
 *   Each compressed blob decompresses (OB-LZ77) to a complete TIM2 file.
 */

constexpr uint32_t NBD_TYPE_TEX = 0x00584554; // "TEX\0"
constexpr uint32_t NBD_TYPE_TID = 0x00444954; // "TID\0"
constexpr uint32_t NBD_TYPE_AMO = 0x004F4D41; // "AMO\0"
constexpr uint32_t NBD_TYPE_AHI = 0x00494841; // "AHI\0"

struct NbdChunk {
    uint32_t type;      // Chunk type (TEX/AMO/AHI)
    uint32_t offset;    // Offset within NBD file to chunk data
    uint32_t size;      // Chunk data size in bytes
    uint32_t count;     // Sub-item count (e.g. number of textures)
};

// A single decompressed TIM2 blob from a TEX chunk
struct NbdTexEntry {
    uint32_t compressed_size;     // Size in the TEX chunk
    std::vector<uint8_t> tim2;    // Decompressed TIM2 file data
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

    // Extract and decompress all textures from a TEX chunk.
    // Returns a vector of decompressed TIM2 blobs.
    std::vector<NbdTexEntry> extract_textures(int chunk_index) const;

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
