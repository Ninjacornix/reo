#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace reo {

/*
 * TIM2 Texture Loader
 *
 * TIM2 (.tm2) is Sony's PS2 texture format.
 * RE Outbreak stores textures as OB-LZ77-compressed TIM2 files inside TEX chunks.
 *
 * TIM2 format:
 *   Header: "TIM2", version, alignment, texture count, globalTextureId (RE OB extension)
 *   Per texture: total_size, clut_size, image_size, header_size, pixel type, GS regs
 *   Pixel data + CLUT data follows
 *
 * Supported pixel types (imageType field):
 *   1 = RGB16  (PSMCT16)
 *   2 = RGB24  (PSMCT24)
 *   3 = RGBA32 (PSMCT32)
 *   4 = IDX4   (PSMT4, 4-bit indexed with CLUT)
 *   5 = IDX8   (PSMT8, 8-bit indexed with CLUT)
 */

struct Tim2Texture {
    uint32_t width;
    uint32_t height;
    uint8_t  pixel_format;   // PS2 GS pixel storage format (imageFormat field)
    uint8_t  image_type;     // 1=RGB16, 2=RGB24, 3=RGBA32, 4=IDX4, 5=IDX8
    uint8_t  clut_type;      // CLUT format flags (bit 0x80 = CSM2/no rearrangement)
    uint8_t  mipmap_count;
    bool     has_clut;       // Has color lookup table (palette)
    uint16_t clut_colors;    // Number of CLUT entries
    uint16_t global_tex_id;  // RE Outbreak extension (globalTextureId)

    // GS register values (from TIM2 header)
    uint64_t gs_tex0;
    uint64_t gs_tex1;

    // Raw pixel data (before CLUT application)
    std::vector<uint8_t> pixel_data;
    // Raw CLUT data (RGBA32 palette entries)
    std::vector<uint8_t> clut_data;

    // Decoded pixel data (converted to RGBA8888)
    std::vector<uint8_t> rgba_data;
};

class Tim2Loader {
public:
    Tim2Loader() = default;

    // Load from file
    bool load(const std::string& path);

    // Load from memory (for embedded textures in .tex/.nbd containers)
    bool load(const uint8_t* data, uint32_t size);

    // Get loaded textures
    int texture_count() const { return (int)m_textures.size(); }
    const Tim2Texture& texture(int index) const { return m_textures[index]; }

    // OB LZ77 decompression (RE Outbreak's custom 16-bit word compression)
    // Returns decompressed data, or empty vector on failure.
    static std::vector<uint8_t> decompress_ob_lz77(const uint8_t* input, uint32_t input_size);

    // Legacy LZSS (kept for compatibility, but OB LZ77 is the correct format)
    static bool decompress_lzss(const uint8_t* input, uint32_t input_size,
                                std::vector<uint8_t>& output);

private:
    bool parse_tim2(const uint8_t* data, uint32_t size);
    bool decode_texture(const uint8_t* hdr, uint32_t total_size, Tim2Texture& tex);
    void rearrange_clut(uint8_t* clut, int color_count);

    std::vector<Tim2Texture> m_textures;
};

} // namespace reo
