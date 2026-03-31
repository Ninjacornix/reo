#include "nbd_parser.h"
#include <cstdio>
#include <cstring>
#include <fstream>

namespace reo {

bool NbdParser::parse(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) return false;

    auto size = file.tellg();
    file.seekg(0);
    m_owned_data.resize((size_t)size);
    file.read((char*)m_owned_data.data(), size);

    m_data = m_owned_data.data();
    m_size = (uint32_t)m_owned_data.size();
    return parse_directory();
}

bool NbdParser::parse(const uint8_t* data, uint32_t size) {
    m_owned_data.clear();
    m_data = data;
    m_size = size;
    return parse_directory();
}

bool NbdParser::parse_directory() {
    m_chunks.clear();

    if (!m_data || m_size < 16) return false;

    // Chunk directory at offset 0: [type:4][offset:4][size:4][count:4] per entry
    // Terminated by all-zero entry (typically at offset 0x30)
    uint32_t pos = 0;
    while (pos + 16 <= m_size) {
        uint32_t type, offset, size, count;
        memcpy(&type, m_data + pos, 4);
        memcpy(&offset, m_data + pos + 4, 4);
        memcpy(&size, m_data + pos + 8, 4);
        memcpy(&count, m_data + pos + 12, 4);

        // End of directory: all-zero entry
        if (type == 0 && offset == 0) break;

        // Validate offset + size fits within file
        if (offset < m_size && offset + size <= m_size) {
            NbdChunk chunk;
            chunk.type = type;
            chunk.offset = offset;
            chunk.size = size;
            chunk.count = count;
            m_chunks.push_back(chunk);

            char type_str[5] = {};
            memcpy(type_str, &type, 4);
            printf("[NBD] Chunk: %s  offset=0x%06X  size=0x%06X  count=%u\n",
                   type_str, offset, size, count);
        }

        pos += 16;
    }

    printf("[NBD] Parsed %d chunks from %u bytes\n", (int)m_chunks.size(), m_size);
    return !m_chunks.empty();
}

std::vector<int> NbdParser::find_chunks(uint32_t type) const {
    std::vector<int> result;
    for (int i = 0; i < (int)m_chunks.size(); i++) {
        if (m_chunks[i].type == type) {
            result.push_back(i);
        }
    }
    return result;
}

} // namespace reo
