#include "amo_parser.h"
#include <cstdio>
#include <cstring>
#include <cfloat>
#include <algorithm>

namespace reo {

int AmoParser::find_array(const uint8_t* data, uint32_t size, uint8_t flag_type,
                          uint32_t& out_count, uint32_t& out_data_size) const {
    // Scan for flag-tagged array header: [flags:4][count:4][size:4]
    // Flags format: 0x00XX0000 where XX is the flag type
    uint32_t target_flags = (uint32_t)flag_type << 16;

    for (uint32_t off = 0; off + 12 <= size; off += 4) {
        uint32_t flags;
        memcpy(&flags, data + off, 4);
        if (flags != target_flags) continue;

        uint32_t count, array_size;
        memcpy(&count, data + off + 4, 4);
        memcpy(&array_size, data + off + 8, 4);

        if (count == 0 || count > 100000) continue;
        if (array_size == 0 || array_size > size) continue;

        // Data size = array_size - 12 (next header), except possibly the last array
        uint32_t data_bytes = (array_size > 12) ? array_size - 12 : array_size;

        // Verify the data region fits
        uint32_t data_start = off + 12;
        if (data_start + data_bytes > size) {
            // Last array — use remaining bytes
            data_bytes = size - data_start;
        }

        out_count = count;
        out_data_size = data_bytes;
        return (int)data_start;
    }

    return -1;
}

bool AmoParser::parse(const uint8_t* data, uint32_t size) {
    m_model = AmoModel{};

    if (size < 16) return false;

    // AMO main header: [version:4][num_parts:4][total_size:4][flags:4]
    uint32_t version, num_parts, total_size;
    memcpy(&version, data, 4);
    memcpy(&num_parts, data + 4, 4);
    memcpy(&total_size, data + 8, 4);

    printf("[AMO] Parsing: version=%u, parts=%u, size=%u bytes\n",
           version, num_parts, total_size);

    parse_vertices(data, size);
    parse_normals(data, size);
    parse_texcoords(data, size);
    parse_strips(data, size);
    parse_materials(data, size);

    // Compute bounding box
    m_model.bbox_min[0] = m_model.bbox_min[1] = m_model.bbox_min[2] = FLT_MAX;
    m_model.bbox_max[0] = m_model.bbox_max[1] = m_model.bbox_max[2] = -FLT_MAX;
    for (auto& v : m_model.vertices) {
        m_model.bbox_min[0] = std::min(m_model.bbox_min[0], v.x);
        m_model.bbox_min[1] = std::min(m_model.bbox_min[1], v.y);
        m_model.bbox_min[2] = std::min(m_model.bbox_min[2], v.z);
        m_model.bbox_max[0] = std::max(m_model.bbox_max[0], v.x);
        m_model.bbox_max[1] = std::max(m_model.bbox_max[1], v.y);
        m_model.bbox_max[2] = std::max(m_model.bbox_max[2], v.z);
    }

    int total_tris = 0;
    for (auto& s : m_model.strips) {
        total_tris += std::max(0, (int)s.indices.size() - 2);
    }

    printf("[AMO] Loaded: %d vertices, %d normals, %d UVs, %d strips (%d triangles)\n",
           (int)m_model.vertices.size(), (int)m_model.normals.size(),
           (int)m_model.texcoords.size(), (int)m_model.strips.size(), total_tris);
    printf("[AMO] Bounds: (%.1f,%.1f,%.1f) to (%.1f,%.1f,%.1f)\n",
           m_model.bbox_min[0], m_model.bbox_min[1], m_model.bbox_min[2],
           m_model.bbox_max[0], m_model.bbox_max[1], m_model.bbox_max[2]);

    return !m_model.vertices.empty() && !m_model.strips.empty();
}

bool AmoParser::parse_vertices(const uint8_t* data, uint32_t size) {
    uint32_t count, data_size;
    int off = find_array(data, size, 0x07, count, data_size);
    if (off < 0) return false;

    uint32_t vert_count = data_size / 12;
    m_model.vertices.resize(vert_count);
    memcpy(m_model.vertices.data(), data + off, vert_count * 12);
    return true;
}

bool AmoParser::parse_normals(const uint8_t* data, uint32_t size) {
    uint32_t count, data_size;
    int off = find_array(data, size, 0x08, count, data_size);
    if (off < 0) return false;

    uint32_t norm_count = data_size / 12;
    m_model.normals.resize(norm_count);
    memcpy(m_model.normals.data(), data + off, norm_count * 12);
    return true;
}

bool AmoParser::parse_texcoords(const uint8_t* data, uint32_t size) {
    uint32_t count, data_size;
    int off = find_array(data, size, 0x0A, count, data_size);
    if (off < 0) return false;

    uint32_t uv_count = data_size / 8;
    m_model.texcoords.resize(uv_count);
    memcpy(m_model.texcoords.data(), data + off, uv_count * 8);
    return true;
}

bool AmoParser::parse_strips(const uint8_t* data, uint32_t size) {
    uint32_t count, data_size;
    int off = find_array(data, size, 0x04, count, data_size);
    if (off < 0) return false;

    // Triangle strips: count-prefixed groups of uint32 vertex indices
    // [strip_length:4][idx0:4][idx1:4]...[idxN:4]
    const uint8_t* p = data + off;
    const uint8_t* end = p + data_size;

    while (p + 4 <= end) {
        uint32_t strip_len;
        memcpy(&strip_len, p, 4);
        p += 4;

        if (strip_len == 0 || strip_len > 10000) break;
        if (p + strip_len * 4 > end) break;

        AmoTriStrip strip;
        strip.indices.resize(strip_len);
        memcpy(strip.indices.data(), p, strip_len * 4);
        p += strip_len * 4;

        m_model.strips.push_back(std::move(strip));
    }

    return !m_model.strips.empty();
}

bool AmoParser::parse_materials(const uint8_t* data, uint32_t size) {
    uint32_t count, data_size;
    int off = find_array(data, size, 0x13, count, data_size);
    if (off < 0) return false;

    // Material data: starts with ambient[4], diffuse[4], specular[4] as floats
    if (data_size >= 48) {
        AmoMaterial mat;
        memcpy(mat.ambient, data + off, 16);
        memcpy(mat.diffuse, data + off + 16, 16);
        memcpy(mat.specular, data + off + 32, 16);
        m_model.materials.push_back(mat);
    }

    return true;
}

} // namespace reo
