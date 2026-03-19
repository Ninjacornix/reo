#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <cstdio>

// Lightweight NETBIO/AFS reader that reads directly from disc files
// without loading entire archives into memory.
struct NetbioEntry {
    uint32_t offset;    // Offset within the DAT file
    uint32_t size;      // Size in bytes
    char name[33];      // Filename (null-terminated)
};

class NetbioReader {
public:
    bool open(const char* path);
    void close();

    int file_count() const { return (int)m_entries.size(); }
    const NetbioEntry& entry(int index) const { return m_entries[index]; }

    // Read a file by index into a buffer. Returns bytes read, or 0 on error.
    uint32_t read_file(int index, void* buffer, uint32_t max_size);

    // Read a file by index directly into guest RAM at the given address.
    uint32_t read_file_to_ram(int index, uint8_t* rdram, uint32_t dest_addr,
                              uint32_t ram_size);

    // Find file by name (case-insensitive). Returns index or -1.
    int find_file(const char* name) const;

    // Parse nested AFS archive at a given NETBIO file index
    // Returns the inner file count, populates inner_entries
    int parse_inner_afs(int netbio_index, std::vector<NetbioEntry>& inner_entries);

private:
    FILE* m_file = nullptr;
    uint32_t m_base_offset = 0;  // For nested archives
    std::vector<NetbioEntry> m_entries;
};
