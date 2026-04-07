#include "tim2_loader.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>

namespace reo {

bool Tim2Loader::load(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) return false;

    auto size = file.tellg();
    file.seekg(0);
    std::vector<uint8_t> data((size_t)size);
    file.read((char*)data.data(), size);

    return load(data.data(), (uint32_t)data.size());
}

bool Tim2Loader::load(const uint8_t* data, uint32_t size) {
    m_textures.clear();
    return parse_tim2(data, size);
}

bool Tim2Loader::parse_tim2(const uint8_t* data, uint32_t size) {
    if (size < 16) return false;

    // TIM2 signature: "TIM2" (0x54494D32)
    if (data[0] != 'T' || data[1] != 'I' || data[2] != 'M' || data[3] != '2') {
        fprintf(stderr, "[TIM2] Invalid signature\n");
        return false;
    }

    uint8_t version = data[4];
    uint8_t alignment = data[5]; // 0 = 16-byte header, nonzero = 0x80-byte header
    uint16_t tex_count;
    memcpy(&tex_count, data + 6, 2);

    // RE Outbreak extension: globalTextureId at offset 8
    uint16_t global_tex_id;
    memcpy(&global_tex_id, data + 8, 2);

    printf("[TIM2] Version %d, alignment=%d, %d texture(s), globalTexId=%u\n",
           version, alignment, tex_count, global_tex_id);

    uint32_t hdr_size = alignment ? 0x80 : 16;
    uint32_t offset = hdr_size;

    for (int i = 0; i < tex_count && offset < size; i++) {
        if (offset + 48 > size) break;

        uint32_t total_size;
        memcpy(&total_size, data + offset, 4);
        if (total_size == 0 || offset + total_size > size) break;

        Tim2Texture tex{};
        tex.global_tex_id = global_tex_id;

        if (decode_texture(data + offset, total_size, tex)) {
            m_textures.push_back(std::move(tex));
        }
        offset += total_size;
    }

    return !m_textures.empty();
}

bool Tim2Loader::decode_texture(const uint8_t* hdr, uint32_t total_size, Tim2Texture& tex) {
    // Per-texture header (48 bytes):
    //  [0:4]   total_size
    //  [4:8]   clut_size (palette data size)
    //  [8:12]  image_size (pixel data size)
    //  [12:14] header_size
    //  [14:16] clut_color_count
    //  [16]    imageFormat
    //  [17]    mipmapLevels
    //  [18]    clutType (bit 0x80 = CSM2, no rearrangement)
    //  [19]    imageType (1=RGB16, 2=RGB24, 3=RGBA32, 4=IDX4, 5=IDX8)
    //  [20:22] width
    //  [22:24] height
    //  [24:32] gsTex0
    //  [32:40] gsTex1
    //  [40:44] gsTexaFbaPabe
    //  [44:48] gsTexClut

    uint32_t clut_size, image_size;
    uint16_t header_size, clut_colors;
    memcpy(&clut_size, hdr + 4, 4);
    memcpy(&image_size, hdr + 8, 4);
    memcpy(&header_size, hdr + 12, 2);
    memcpy(&clut_colors, hdr + 14, 2);

    tex.pixel_format = hdr[16];
    tex.mipmap_count = hdr[17];
    tex.clut_type = hdr[18];
    tex.image_type = hdr[19];
    memcpy(&tex.width, hdr + 20, 2);
    memcpy(&tex.height, hdr + 22, 2);
    memcpy(&tex.gs_tex0, hdr + 24, 8);
    memcpy(&tex.gs_tex1, hdr + 32, 8);
    tex.has_clut = (clut_size > 0);
    tex.clut_colors = clut_colors;

    const char* type_names[] = {"?", "RGB16", "RGB24", "RGBA32", "IDX4", "IDX8"};
    const char* type_name = (tex.image_type <= 5) ? type_names[tex.image_type] : "UNK";
    printf("[TIM2] Texture: %dx%d type=%s(%d) clut=0x%02X colors=%d\n",
           tex.width, tex.height, type_name, tex.image_type,
           tex.clut_type, clut_colors);

    // Extract pixel data
    const uint8_t* pixel_data = hdr + header_size;
    const uint8_t* clut_data_ptr = pixel_data + image_size;

    if (image_size > 0 && header_size + image_size <= total_size) {
        tex.pixel_data.assign(pixel_data, pixel_data + image_size);
    }

    if (clut_size > 0 && header_size + image_size + clut_size <= total_size) {
        tex.clut_data.assign(clut_data_ptr, clut_data_ptr + clut_size);

        // CLUT rearrangement for INDEXED8 in CSM1 mode
        // Swap entries 8-15 with 16-23 within each 32-entry block
        if (tex.image_type == 5 && !(tex.clut_type & 0x80)) {
            rearrange_clut(tex.clut_data.data(), clut_colors);
        }
    }

    // Decode to RGBA8888
    tex.rgba_data.resize(tex.width * tex.height * 4);

    switch (tex.image_type) {
        case 5: { // IDX8 - 8-bit indexed
            if (tex.pixel_data.size() < tex.width * tex.height) break;
            if (tex.clut_data.size() < (size_t)clut_colors * 4) break;

            for (uint32_t i = 0; i < tex.width * tex.height; i++) {
                uint8_t idx = tex.pixel_data[i];
                if (idx < clut_colors) {
                    uint32_t ci = idx * 4;
                    tex.rgba_data[i * 4 + 0] = tex.clut_data[ci + 0]; // R
                    tex.rgba_data[i * 4 + 1] = tex.clut_data[ci + 1]; // G
                    tex.rgba_data[i * 4 + 2] = tex.clut_data[ci + 2]; // B
                    // PS2 alpha: 0x80 = fully opaque, scale to 0xFF
                    uint8_t a = tex.clut_data[ci + 3];
                    tex.rgba_data[i * 4 + 3] = (a >= 0x80) ? 0xFF : (a << 1);
                } else {
                    // Out-of-range index: magenta
                    tex.rgba_data[i * 4 + 0] = 255;
                    tex.rgba_data[i * 4 + 1] = 0;
                    tex.rgba_data[i * 4 + 2] = 255;
                    tex.rgba_data[i * 4 + 3] = 255;
                }
            }
            break;
        }
        case 4: { // IDX4 - 4-bit indexed
            if (tex.pixel_data.size() < (tex.width * tex.height + 1) / 2) break;
            if (tex.clut_data.size() < (size_t)clut_colors * 4) break;

            for (uint32_t i = 0; i < tex.width * tex.height; i++) {
                uint8_t byte = tex.pixel_data[i / 2];
                uint8_t idx = (i & 1) ? (byte >> 4) : (byte & 0x0F);
                if (idx < clut_colors) {
                    uint32_t ci = idx * 4;
                    tex.rgba_data[i * 4 + 0] = tex.clut_data[ci + 0];
                    tex.rgba_data[i * 4 + 1] = tex.clut_data[ci + 1];
                    tex.rgba_data[i * 4 + 2] = tex.clut_data[ci + 2];
                    uint8_t a = tex.clut_data[ci + 3];
                    tex.rgba_data[i * 4 + 3] = (a >= 0x80) ? 0xFF : (a << 1);
                }
            }
            break;
        }
        case 3: { // RGBA32
            if (tex.pixel_data.size() < tex.width * tex.height * 4) break;
            for (uint32_t i = 0; i < tex.width * tex.height; i++) {
                tex.rgba_data[i * 4 + 0] = tex.pixel_data[i * 4 + 0];
                tex.rgba_data[i * 4 + 1] = tex.pixel_data[i * 4 + 1];
                tex.rgba_data[i * 4 + 2] = tex.pixel_data[i * 4 + 2];
                uint8_t a = tex.pixel_data[i * 4 + 3];
                tex.rgba_data[i * 4 + 3] = (a >= 0x80) ? 0xFF : (a << 1);
            }
            break;
        }
        case 2: { // RGB24
            if (tex.pixel_data.size() < tex.width * tex.height * 3) break;
            for (uint32_t i = 0; i < tex.width * tex.height; i++) {
                tex.rgba_data[i * 4 + 0] = tex.pixel_data[i * 3 + 0];
                tex.rgba_data[i * 4 + 1] = tex.pixel_data[i * 3 + 1];
                tex.rgba_data[i * 4 + 2] = tex.pixel_data[i * 3 + 2];
                tex.rgba_data[i * 4 + 3] = 255;
            }
            break;
        }
        case 1: { // RGB16 (ABGR1555)
            if (tex.pixel_data.size() < tex.width * tex.height * 2) break;
            for (uint32_t i = 0; i < tex.width * tex.height; i++) {
                uint16_t px;
                memcpy(&px, tex.pixel_data.data() + i * 2, 2);
                tex.rgba_data[i * 4 + 0] = ((px >>  0) & 0x1F) << 3; // R
                tex.rgba_data[i * 4 + 1] = ((px >>  5) & 0x1F) << 3; // G
                tex.rgba_data[i * 4 + 2] = ((px >> 10) & 0x1F) << 3; // B
                tex.rgba_data[i * 4 + 3] = (px & 0x8000) ? 255 : 0;  // A
            }
            break;
        }
        default:
            printf("[TIM2] Unsupported image type %d\n", tex.image_type);
            // Fill with magenta
            for (uint32_t i = 0; i < tex.width * tex.height; i++) {
                tex.rgba_data[i * 4 + 0] = 255;
                tex.rgba_data[i * 4 + 2] = 255;
                tex.rgba_data[i * 4 + 3] = 255;
            }
            break;
    }

    return true;
}

void Tim2Loader::rearrange_clut(uint8_t* clut, int color_count) {
    // CSM1 CLUT rearrangement for PSMT8 (256-color palettes)
    // Within each 32-entry block, swap entries 8-15 with entries 16-23
    // This matches PS2 GS hardware CLUT storage order
    if (color_count < 32) return;

    uint8_t temp[4];
    int blocks = color_count / 32;
    for (int b = 0; b < blocks; b++) {
        int base = b * 32;
        for (int i = 0; i < 8; i++) {
            int a = (base + 8 + i) * 4;
            int c = (base + 16 + i) * 4;
            // Swap entries [8+i] and [16+i]
            memcpy(temp, clut + a, 4);
            memcpy(clut + a, clut + c, 4);
            memcpy(clut + c, temp, 4);
        }
    }
}

// RE Outbreak custom 16-bit word LZ77 decompression
// Based on OBSld::decompress() from libthanatos/REOF2
std::vector<uint8_t> Tim2Loader::decompress_ob_lz77(const uint8_t* input, uint32_t input_size) {
    if (input_size < 2) return {};

    // Work in 16-bit words
    uint32_t word_count = input_size / 2;
    const uint16_t* words = (const uint16_t*)input;

    std::vector<uint16_t> output;
    output.reserve(word_count * 4); // Estimate

    uint32_t pos = 0;

    while (pos < word_count) {
        // Read 16-bit control word
        uint16_t ctrl = words[pos++];

        for (int bit = 15; bit >= 0; bit--) {
            if (pos >= word_count) break;

            if (ctrl & (1 << bit)) {
                // Compressed token
                uint16_t mode = words[pos++];
                uint32_t count = mode >> 11;       // top 5 bits
                uint32_t offset = mode & 0x7FF;    // bottom 11 bits

                if (count == 0 && offset == 0) {
                    // Termination sentinel
                    goto done;
                }

                if (count == 0) {
                    // Extended count from next word
                    if (pos >= word_count) goto done;
                    count = words[pos++];
                }

                if (offset == 0) {
                    // Zero-fill RLE
                    for (uint32_t j = 0; j < count; j++) {
                        output.push_back(0);
                    }
                } else {
                    // Back reference
                    uint32_t src_pos = (uint32_t)output.size() - offset;
                    for (uint32_t j = 0; j < count; j++) {
                        if (src_pos + j < output.size()) {
                            output.push_back(output[src_pos + j]);
                        } else {
                            output.push_back(0);
                        }
                    }
                }
            } else {
                // Literal 16-bit word
                output.push_back(words[pos++]);
            }
        }
    }

done:
    // Convert uint16_t array back to bytes
    std::vector<uint8_t> result(output.size() * 2);
    memcpy(result.data(), output.data(), result.size());
    return result;
}

// Legacy LZSS (standard 4KB sliding window) — kept for compatibility
bool Tim2Loader::decompress_lzss(const uint8_t* input, uint32_t input_size,
                                  std::vector<uint8_t>& output) {
    output.clear();
    output.reserve(input_size * 4);

    uint8_t window[4096];
    memset(window, 0, sizeof(window));
    int win_pos = 0xFEE;

    uint32_t pos = 0;

    while (pos < input_size) {
        uint8_t flags = input[pos++];

        for (int bit = 0; bit < 8 && pos < input_size; bit++) {
            if (flags & (1 << bit)) {
                uint8_t byte = input[pos++];
                output.push_back(byte);
                window[win_pos] = byte;
                win_pos = (win_pos + 1) & 0xFFF;
            } else {
                if (pos + 1 >= input_size) break;

                uint8_t lo = input[pos++];
                uint8_t hi = input[pos++];

                int offset = lo | ((hi & 0xF0) << 4);
                int length = (hi & 0x0F) + 3;

                for (int j = 0; j < length; j++) {
                    uint8_t byte = window[(offset + j) & 0xFFF];
                    output.push_back(byte);
                    window[win_pos] = byte;
                    win_pos = (win_pos + 1) & 0xFFF;
                }
            }
        }
    }

    return true;
}

} // namespace reo
