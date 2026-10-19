#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace reo {

/*
 * ISO 9660 Filesystem Parser
 *
 * PS2 games use standard ISO 9660 (with Joliet extensions sometimes)
 * on DVD-5 or DVD-9 media. Sector size is 2048 bytes.
 *
 * This parser reads the ISO filesystem to extract:
 *   1. SYSTEM.CNF (contains BOOT2 = path to main ELF)
 *   2. The main ELF executable (SLUS_207.65 for RE Outbreak US)
 *   3. All game data files (NETBIOxx.DAT archives, etc.)
 */

constexpr int ISO_SECTOR_SIZE = 2048;
constexpr int ISO_PVD_SECTOR = 16; // Primary Volume Descriptor at sector 16

struct IsoDirectoryEntry {
    std::string name;
    uint32_t lba;  // Logical Block Address (sector number)
    uint32_t size; // File size in bytes
    bool is_directory;
    std::vector<IsoDirectoryEntry> children;
};

class Iso9660 {
  public:
    Iso9660() = default;

    bool open(const std::string& iso_path);
    void close();

    // Get the root directory listing (recursive)
    const IsoDirectoryEntry& root() const {
        return m_root;
    }

    // Find a file by path (e.g., "SLUS_207.65")
    const IsoDirectoryEntry* find(const std::string& path) const;

    // Read file contents by LBA and size
    bool read_file(const IsoDirectoryEntry& entry, std::vector<uint8_t>& out);

    // Read raw sectors
    bool read_sectors(uint32_t lba, uint32_t count, void* buffer);

    // Extract everything to a directory
    bool extract_all(const std::filesystem::path& output_dir);

    // Get volume label
    const std::string& volume_label() const {
        return m_volume_label;
    }

  private:
    bool parse_pvd();
    void parse_directory(uint32_t lba, uint32_t size, IsoDirectoryEntry& parent);
    const IsoDirectoryEntry* find_recursive(const IsoDirectoryEntry& dir,
                                            const std::string& name) const;
    void extract_recursive(const IsoDirectoryEntry& dir, const std::filesystem::path& base);

    std::ifstream m_file;
    IsoDirectoryEntry m_root;
    std::string m_volume_label;
    uint32_t m_root_lba = 0;
    uint32_t m_root_size = 0;
};

} // namespace reo
