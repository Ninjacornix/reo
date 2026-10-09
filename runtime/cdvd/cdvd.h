#pragma once

#include <cstdint>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <vector>

namespace reo {

/*
 * CDVD — Disc I/O Replacement
 *
 * Redirects all CD/DVD reads to extracted game files on the local filesystem.
 * The PS2 game reads sectors from the DVD; we translate sector offsets
 * to file paths using a pre-built file table from the ISO extraction step.
 */

class CDVD {
public:
    explicit CDVD(const std::filesystem::path& game_data_root);
    ~CDVD();
    CDVD(const CDVD&) = delete;
    CDVD& operator=(const CDVD&) = delete;

    // Read file by PS2 path (e.g., "cdrom0:\\DATA\\NETBIO00.DAT;1")
    bool read_file(const std::string& ps2_path, std::vector<uint8_t>& out);

    // Read raw 2048-byte sectors from the disc image (REO_ISO, or the raw volume of a
    // mounted drive root). False if no image is available or the range is outside it.
    bool read_sectors(uint32_t lba, uint32_t count, void* buffer);

    // ISO9660 lookup of a PS2 path ("cdrom0:\\DIR\\FILE.EXT;1" or "\\DIR\\FILE.EXT;1"):
    // start sector and byte size, as sceCdSearchFile reports them.
    bool search_file(const std::string& ps2_path, uint32_t& lba, uint32_t& size);

    bool has_image() const { return m_image != nullptr; }

    // Check if a file exists on the virtual disc
    bool file_exists(const std::string& ps2_path) const;

    // Get file size
    uint32_t file_size(const std::string& ps2_path) const;

    // Translate PS2 path to local filesystem path
    std::filesystem::path resolve_path(const std::string& ps2_path) const;

private:
    std::filesystem::path m_root;
    std::unordered_map<std::string, std::filesystem::path> m_file_map;

    void* m_image = nullptr;          // FILE* (ISO) or HANDLE (raw volume)
    bool m_imageIsVolume = false;
    uint64_t m_imageSize = 0;

    void build_file_map();
    void open_image();
    std::string normalize_ps2_path(const std::string& path) const;
};

} // namespace reo
