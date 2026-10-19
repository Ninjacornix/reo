#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <filesystem>

namespace reo {

/*
 * AFS Archive Parser
 *
 * AFS is CRI's archive format used by Capcom for PS2 games.
 * RE Outbreak stores most game data in AFS archives named NETBIOxx.DAT
 *
 * Format:
 *   Header: "AFS\0" signature, file count (uint32 LE)
 *   TOC: Array of {offset, size} pairs (uint32 LE each)
 *   File data at specified offsets
 *   Optional: filename table at end of archive
 */

struct AfsEntry {
    uint32_t offset;
    uint32_t size;
    std::string name; // From filename table, if present
};

class AfsArchive {
  public:
    AfsArchive() = default;

    bool open(const std::string& path);
    bool open(const uint8_t* data, uint32_t size);

    int file_count() const {
        return (int)m_entries.size();
    }
    const AfsEntry& entry(int index) const {
        return m_entries[index];
    }

    // Extract a single file by index
    bool extract(int index, std::vector<uint8_t>& out) const;

    // Extract all files to a directory
    bool extract_all(const std::filesystem::path& output_dir) const;

  private:
    bool parse();

    std::vector<uint8_t> m_data;
    std::vector<AfsEntry> m_entries;
};

} // namespace reo
