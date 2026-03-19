#include "reo_netbio.h"
#include <cstring>
#include <algorithm>
#include <cctype>

bool NetbioReader::open(const char* path) {
    close();
    m_file = fopen(path, "rb");
    if (!m_file) {
        fprintf(stderr, "[NETBIO] Failed to open: %s\n", path);
        return false;
    }

    // Read AFS header
    char sig[4];
    fread(sig, 1, 4, m_file);
    if (sig[0] != 'A' || sig[1] != 'F' || sig[2] != 'S') {
        fprintf(stderr, "[NETBIO] Not an AFS file: %s\n", path);
        fclose(m_file);
        m_file = nullptr;
        return false;
    }

    uint32_t count;
    fread(&count, 4, 1, m_file);
    if (count > 65536) {
        fprintf(stderr, "[NETBIO] Too many files: %u\n", count);
        fclose(m_file);
        m_file = nullptr;
        return false;
    }

    // Read TOC
    m_entries.resize(count);
    for (uint32_t i = 0; i < count; i++) {
        fread(&m_entries[i].offset, 4, 1, m_file);
        fread(&m_entries[i].size, 4, 1, m_file);
        snprintf(m_entries[i].name, sizeof(m_entries[i].name), "file_%04u", i);
    }

    // Try to read filename table (extra TOC entry after all files)
    uint32_t ft_off, ft_sz;
    fread(&ft_off, 4, 1, m_file);
    fread(&ft_sz, 4, 1, m_file);
    if (ft_off > 0 && ft_sz >= count * 48) {
        for (uint32_t i = 0; i < count; i++) {
            fseek(m_file, ft_off + i * 48, SEEK_SET);
            char name[33] = {};
            fread(name, 1, 32, m_file);
            name[32] = '\0';
            // Trim
            for (int j = 31; j >= 0; j--) {
                if (name[j] == '\0' || name[j] == ' ') name[j] = '\0';
                else break;
            }
            if (strlen(name) > 0) {
                strncpy(m_entries[i].name, name, 32);
                m_entries[i].name[32] = '\0';
            }
        }
    }

    printf("[NETBIO] Opened %s: %u files\n", path, count);
    return true;
}

void NetbioReader::close() {
    if (m_file) {
        fclose(m_file);
        m_file = nullptr;
    }
    m_entries.clear();
    m_base_offset = 0;
}

uint32_t NetbioReader::read_file(int index, void* buffer, uint32_t max_size) {
    if (!m_file || index < 0 || index >= (int)m_entries.size()) return 0;

    const auto& e = m_entries[index];
    uint32_t read_size = std::min(e.size, max_size);
    fseek(m_file, m_base_offset + e.offset, SEEK_SET);
    return (uint32_t)fread(buffer, 1, read_size, m_file);
}

uint32_t NetbioReader::read_file_to_ram(int index, uint8_t* rdram, uint32_t dest_addr,
                                         uint32_t ram_size) {
    if (!m_file || index < 0 || index >= (int)m_entries.size()) return 0;

    const auto& e = m_entries[index];
    uint32_t phys = dest_addr & 0x1FFFFFF;
    uint32_t max_size = ram_size - phys;
    uint32_t read_size = std::min(e.size, max_size);

    fseek(m_file, m_base_offset + e.offset, SEEK_SET);
    uint32_t actual = (uint32_t)fread(rdram + phys, 1, read_size, m_file);

    printf("[NETBIO] Loaded [%d] '%s' (%u bytes) → 0x%08X\n",
           index, e.name, actual, dest_addr);
    return actual;
}

int NetbioReader::find_file(const char* name) const {
    for (int i = 0; i < (int)m_entries.size(); i++) {
        if (_stricmp(m_entries[i].name, name) == 0) return i;
    }
    return -1;
}

int NetbioReader::parse_inner_afs(int netbio_index, std::vector<NetbioEntry>& inner_entries) {
    if (!m_file || netbio_index < 0 || netbio_index >= (int)m_entries.size()) return 0;

    const auto& outer = m_entries[netbio_index];
    uint32_t base = m_base_offset + outer.offset;

    // Read inner AFS header
    fseek(m_file, base, SEEK_SET);
    char sig[4];
    fread(sig, 1, 4, m_file);
    if (sig[0] != 'A' || sig[1] != 'F' || sig[2] != 'S') return 0;

    uint32_t count;
    fread(&count, 4, 1, m_file);
    if (count > 65536) return 0;

    inner_entries.resize(count);
    for (uint32_t i = 0; i < count; i++) {
        fread(&inner_entries[i].offset, 4, 1, m_file);
        fread(&inner_entries[i].size, 4, 1, m_file);
        // Adjust offset to be relative to the DAT file, not the inner AFS
        inner_entries[i].offset += base;
        snprintf(inner_entries[i].name, sizeof(inner_entries[i].name), "file_%04u", i);
    }

    // Read filename table
    uint32_t ft_off, ft_sz;
    fread(&ft_off, 4, 1, m_file);
    fread(&ft_sz, 4, 1, m_file);
    if (ft_off > 0 && ft_sz >= count * 48) {
        for (uint32_t i = 0; i < count; i++) {
            fseek(m_file, base + ft_off + i * 48, SEEK_SET);
            char name[33] = {};
            fread(name, 1, 32, m_file);
            name[32] = '\0';
            for (int j = 31; j >= 0; j--) {
                if (name[j] == '\0' || name[j] == ' ') name[j] = '\0';
                else break;
            }
            if (strlen(name) > 0) {
                strncpy(inner_entries[i].name, name, 32);
                inner_entries[i].name[32] = '\0';
            }
        }
    }

    printf("[NETBIO] Inner AFS '%s': %u files\n", m_entries[netbio_index].name, count);
    return (int)count;
}
