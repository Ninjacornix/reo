#pragma once

#include <cstdint>
#include <vector>

namespace reo {

/*
 * AMO (Animated Model Object) Parser
 *
 * AMO format uses flag-tagged data arrays. Each array has a 12-byte header:
 *   [flags:4][count:4][size:4]
 * The size field includes the 12-byte header of the NEXT array (except for the last).
 *
 * Known flag types (bits 23:16 of flags word):
 *   0x02 - Root descriptor (16 bytes)
 *   0x03 - Bone hierarchy (groups of parent indices)
 *   0x04 - Triangle strip indices (count-prefixed groups)
 *   0x05 - Mesh descriptor
 *   0x06 - Material indices per face (uint32)
 *   0x07 - Vertex positions (float3, 12 bytes each)
 *   0x08 - Vertex normals (float3, 12 bytes each)
 *   0x0A - Texture coordinates (float2, 8 bytes each)
 *   0x0B - Vertex weights/colors (16 bytes each)
 *   0x0C - Bone skinning data (12 bytes each)
 *   0x10 - Mesh group descriptors
 *   0x13 - Material properties (ambient/diffuse/specular)
 */

struct AmoVertex {
    float x, y, z;
};

struct AmoNormal {
    float nx, ny, nz;
};

struct AmoTexCoord {
    float u, v;
};

struct AmoTriStrip {
    std::vector<uint32_t> indices;
    int material_index = -1; // Index into materials array (-1 = none)
};

struct AmoMaterial {
    float ambient[4];
    float diffuse[4];
    float specular[4];
};

struct AmoModel {
    std::vector<AmoVertex>   vertices;
    std::vector<AmoNormal>   normals;
    std::vector<AmoTexCoord> texcoords;
    std::vector<AmoTriStrip> strips;
    std::vector<AmoMaterial> materials;

    // Bounding box (computed from vertices)
    float bbox_min[3];
    float bbox_max[3];
};

class AmoParser {
public:
    AmoParser() = default;

    bool parse(const uint8_t* data, uint32_t size);

    const AmoModel& model() const { return m_model; }

private:
    // Find a data array by flag type. Returns offset to data (after header), or -1.
    int find_array(const uint8_t* data, uint32_t size, uint8_t flag_type,
                   uint32_t& out_count, uint32_t& out_data_size) const;

    bool parse_vertices(const uint8_t* data, uint32_t size);
    bool parse_normals(const uint8_t* data, uint32_t size);
    bool parse_texcoords(const uint8_t* data, uint32_t size);
    bool parse_strips(const uint8_t* data, uint32_t size);
    bool parse_materials(const uint8_t* data, uint32_t size);

    AmoModel m_model;
};

} // namespace reo
