#include "afs_archive.h"
#include <cstdio>
#include <cstring>
#include <fstream>

namespace reo {

namespace fs = std::filesystem;

bool AfsArchive::open(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) {
        fprintf(stderr, "[AFS] Failed to open: %s\n", path.c_str());
        return false;
    }

    auto size = file.tellg();
    file.seekg(0);
    m_data.resize((size_t)size);
    file.read((char*)m_data.data(), size);

    return parse();
}

bool AfsArchive::open(const uint8_t* data, uint32_t size) {
    m_data.assign(data, data + size);
    return parse();
}

bool AfsArchive::parse() {
    if (m_data.size() < 8)
        return false;

    // Check signature: "AFS\0"
    if (m_data[0] != 'A' || m_data[1] != 'F' || m_data[2] != 'S' || m_data[3] != '\0') {
        fprintf(stderr, "[AFS] Invalid signature\n");
        return false;
    }

    uint32_t file_count = *(uint32_t*)(m_data.data() + 4);
    printf("[AFS] Archive contains %u files\n", file_count);

    if (file_count > 65536) {
        fprintf(stderr, "[AFS] Suspicious file count: %u\n", file_count);
        return false;
    }

    m_entries.clear();
    m_entries.reserve(file_count);

    // Read TOC entries (offset, size pairs starting at byte 8)
    uint32_t toc_offset = 8;
    for (uint32_t i = 0; i < file_count; i++) {
        if (toc_offset + 8 > m_data.size())
            break;

        AfsEntry entry;
        entry.offset = *(uint32_t*)(m_data.data() + toc_offset);
        entry.size = *(uint32_t*)(m_data.data() + toc_offset + 4);

        // Generate default name
        char name[32];
        snprintf(name, sizeof(name), "file_%04u", i);
        entry.name = name;

        m_entries.push_back(entry);
        toc_offset += 8;
    }

    // Look for filename table
    // The last TOC entry after all files often points to a filename table
    // Each entry is 32 bytes (null-padded filename)
    if (file_count > 0) {
        // The filename table location is stored as an extra TOC entry after the file entries
        uint32_t ft_toc_offset = 8 + file_count * 8;
        if (ft_toc_offset + 8 <= m_data.size()) {
            uint32_t ft_offset = *(uint32_t*)(m_data.data() + ft_toc_offset);
            uint32_t ft_size = *(uint32_t*)(m_data.data() + ft_toc_offset + 4);

            if (ft_offset > 0 && ft_offset + ft_size <= m_data.size() &&
                ft_size >= file_count * 48) {
                printf("[AFS] Found filename table at 0x%08X\n", ft_offset);
                for (uint32_t i = 0; i < file_count; i++) {
                    uint32_t name_offset = ft_offset + i * 48;
                    if (name_offset + 32 <= m_data.size()) {
                        char name[33] = {};
                        memcpy(name, m_data.data() + name_offset, 32);
                        name[32] = '\0';
                        // Trim trailing nulls/spaces
                        for (int j = 31; j >= 0; j--) {
                            if (name[j] == '\0' || name[j] == ' ')
                                name[j] = '\0';
                            else
                                break;
                        }
                        if (strlen(name) > 0) {
                            m_entries[i].name = name;
                        }
                    }
                }
            }
        }
    }

    return true;
}

bool AfsArchive::extract(int index, std::vector<uint8_t>& out) const {
    if (index < 0 || index >= (int)m_entries.size())
        return false;

    const auto& entry = m_entries[index];
    if (entry.offset + entry.size > m_data.size()) {
        fprintf(stderr, "[AFS] Entry %d extends beyond archive\n", index);
        return false;
    }

    out.assign(m_data.data() + entry.offset, m_data.data() + entry.offset + entry.size);
    return true;
}

bool AfsArchive::extract_all(const fs::path& output_dir) const {
    fs::create_directories(output_dir);

    for (int i = 0; i < (int)m_entries.size(); i++) {
        std::vector<uint8_t> data;
        if (!extract(i, data))
            continue;

        fs::path out_path = output_dir / m_entries[i].name;
        std::ofstream file(out_path, std::ios::binary);
        if (file) {
            file.write((const char*)data.data(), data.size());
            printf("[AFS] Extracted: %s (%u bytes)\n", m_entries[i].name.c_str(),
                   m_entries[i].size);
        }
    }

    return true;
}

} // namespace reo
