#include "iso9660.h"
#include <cstdio>
#include <cstring>
#include <algorithm>

namespace reo {

namespace fs = std::filesystem;

bool Iso9660::open(const std::string& iso_path) {
    m_file.open(iso_path, std::ios::binary);
    if (!m_file) {
        fprintf(stderr, "[ISO] Failed to open: %s\n", iso_path.c_str());
        return false;
    }

    if (!parse_pvd()) {
        fprintf(stderr, "[ISO] Failed to parse Primary Volume Descriptor\n");
        return false;
    }

    // Parse root directory
    m_root.name = "";
    m_root.is_directory = true;
    m_root.lba = m_root_lba;
    m_root.size = m_root_size;
    parse_directory(m_root_lba, m_root_size, m_root);

    printf("[ISO] Opened: %s\n", iso_path.c_str());
    printf("[ISO] Volume: %s\n", m_volume_label.c_str());
    printf("[ISO] Root directory at LBA %u (%u bytes)\n", m_root_lba, m_root_size);

    return true;
}

void Iso9660::close() {
    m_file.close();
}

bool Iso9660::parse_pvd() {
    // Read sector 16 — Primary Volume Descriptor
    uint8_t sector[ISO_SECTOR_SIZE];
    m_file.seekg((uint64_t)ISO_PVD_SECTOR * ISO_SECTOR_SIZE);
    m_file.read((char*)sector, ISO_SECTOR_SIZE);

    if (!m_file)
        return false;

    // Check PVD signature
    // Byte 0: type (1 = PVD)
    // Bytes 1-5: "CD001"
    if (sector[0] != 1 || memcmp(sector + 1, "CD001", 5) != 0) {
        fprintf(stderr, "[ISO] Not a valid ISO 9660 PVD\n");
        return false;
    }

    // Volume label at bytes 40-71 (32 bytes, space-padded)
    char label[33];
    memcpy(label, sector + 40, 32);
    label[32] = '\0';
    // Trim trailing spaces
    for (int i = 31; i >= 0; i--) {
        if (label[i] == ' ')
            label[i] = '\0';
        else
            break;
    }
    m_volume_label = label;

    // Root directory record at byte 156 (34 bytes)
    uint8_t* root_record = sector + 156;
    // LBA of root directory extent (both-endian at offset 2, LE is first)
    m_root_lba = *(uint32_t*)(root_record + 2);
    // Size of root directory extent
    m_root_size = *(uint32_t*)(root_record + 10);

    return true;
}

void Iso9660::parse_directory(uint32_t lba, uint32_t size, IsoDirectoryEntry& parent) {
    std::vector<uint8_t> dir_data(size);
    m_file.seekg((uint64_t)lba * ISO_SECTOR_SIZE);
    m_file.read((char*)dir_data.data(), size);

    uint32_t pos = 0;
    while (pos < size) {
        uint8_t record_len = dir_data[pos];

        if (record_len == 0) {
            // Move to next sector boundary
            pos = ((pos / ISO_SECTOR_SIZE) + 1) * ISO_SECTOR_SIZE;
            if (pos >= size)
                break;
            continue;
        }

        if (pos + record_len > size)
            break;

        uint8_t* rec = dir_data.data() + pos;

        // Parse directory record fields
        uint32_t entry_lba = *(uint32_t*)(rec + 2);   // LBA (LE)
        uint32_t entry_size = *(uint32_t*)(rec + 10); // Size (LE)
        uint8_t flags = rec[25];
        uint8_t name_len = rec[32];

        bool is_dir = (flags & 0x02) != 0;

        // Extract filename
        char name[256] = {};
        if (name_len > 0 && name_len < 255) {
            memcpy(name, rec + 33, name_len);
            name[name_len] = '\0';
        }

        // Skip "." and ".." entries
        if (name_len == 1 && (name[0] == 0x00 || name[0] == 0x01)) {
            pos += record_len;
            continue;
        }

        // Remove version number (;1) from filename
        char* semi = strchr(name, ';');
        if (semi)
            *semi = '\0';

        // Remove trailing dot
        int nlen = (int)strlen(name);
        if (nlen > 0 && name[nlen - 1] == '.')
            name[nlen - 1] = '\0';

        IsoDirectoryEntry entry;
        entry.name = name;
        entry.lba = entry_lba;
        entry.size = entry_size;
        entry.is_directory = is_dir;

        // Recurse into subdirectories
        if (is_dir && entry_lba != lba) {
            parse_directory(entry_lba, entry_size, entry);
        }

        parent.children.push_back(std::move(entry));
        pos += record_len;
    }
}

const IsoDirectoryEntry* Iso9660::find(const std::string& path) const {
    // Split path and search recursively
    return find_recursive(m_root, path);
}

const IsoDirectoryEntry* Iso9660::find_recursive(const IsoDirectoryEntry& dir,
                                                 const std::string& name) const {
    // Normalize search name (uppercase, no version suffix)
    std::string search = name;
    std::transform(search.begin(), search.end(), search.begin(), ::toupper);

    // Remove leading path separators
    while (!search.empty() && (search[0] == '/' || search[0] == '\\')) {
        search = search.substr(1);
    }

    // Split at first separator
    auto sep = search.find_first_of("/\\");
    std::string first_part, rest;
    if (sep != std::string::npos) {
        first_part = search.substr(0, sep);
        rest = search.substr(sep + 1);
    } else {
        first_part = search;
    }

    for (auto& child : dir.children) {
        std::string child_upper = child.name;
        std::transform(child_upper.begin(), child_upper.end(), child_upper.begin(), ::toupper);

        if (child_upper == first_part) {
            if (rest.empty()) {
                return &child;
            }
            if (child.is_directory) {
                return find_recursive(child, rest);
            }
        }
    }

    return nullptr;
}

bool Iso9660::read_file(const IsoDirectoryEntry& entry, std::vector<uint8_t>& out) {
    out.resize(entry.size);
    m_file.seekg((uint64_t)entry.lba * ISO_SECTOR_SIZE);
    m_file.read((char*)out.data(), entry.size);
    return m_file.good();
}

bool Iso9660::read_sectors(uint32_t lba, uint32_t count, void* buffer) {
    m_file.seekg((uint64_t)lba * ISO_SECTOR_SIZE);
    m_file.read((char*)buffer, (uint64_t)count * ISO_SECTOR_SIZE);
    return m_file.good();
}

bool Iso9660::extract_all(const fs::path& output_dir) {
    fs::create_directories(output_dir);
    extract_recursive(m_root, output_dir);
    return true;
}

void Iso9660::extract_recursive(const IsoDirectoryEntry& dir, const fs::path& base) {
    for (auto& entry : dir.children) {
        fs::path out_path = base / entry.name;

        if (entry.is_directory) {
            fs::create_directories(out_path);
            extract_recursive(entry, out_path);
        } else {
            printf("[ISO] Extracting: %s (%u bytes)\n", out_path.string().c_str(), entry.size);

            std::ofstream out(out_path, std::ios::binary);
            if (!out) {
                fprintf(stderr, "[ISO] Failed to create: %s\n", out_path.string().c_str());
                continue;
            }

            // Read in chunks to handle large files
            uint64_t remaining = entry.size;
            uint64_t file_offset = (uint64_t)entry.lba * ISO_SECTOR_SIZE;
            uint8_t buffer[65536];

            m_file.seekg(file_offset);
            while (remaining > 0) {
                uint32_t chunk = (uint32_t)std::min(remaining, (uint64_t)sizeof(buffer));
                m_file.read((char*)buffer, chunk);
                out.write((char*)buffer, chunk);
                remaining -= chunk;
            }
        }
    }
}

} // namespace reo
