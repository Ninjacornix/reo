#include "nbd_renderer.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

// From reo_hw_bridge.cpp
extern void reo_gs_submit_path3_direct(const void* data, uint32_t bytes);
extern uint8_t* reo_gs_vram();
extern uint32_t reo_gs_vram_size();

// GS VRAM swizzle addressing (inline functions from gs_renderer.h)
#include "runtime/gs/gs_renderer.h"

namespace reo {

// VRAM layout for NbdRenderer textures (chosen to avoid framebuffer/zbuffer)
// Framebuffer: pages 0-139 (640*448*4 = ~1.1MB)
// Z-buffer: FBP=0x88 = pages 136-275
// Our textures start at page 320 = TBP 320*32 = 10240 blocks
static constexpr uint32_t TEX_VRAM_START_BLOCK = 10240; // ~2.5MB into VRAM
static constexpr uint32_t CLUT_VRAM_START_BLOCK = 14336; // ~3.5MB into VRAM

bool NbdRenderer::load(const uint8_t* nbd_data, uint32_t nbd_size) {
    m_loaded = false;
    m_gif_packet.clear();
    m_textures.clear();
    m_tex_packets.clear();

    if (!m_nbd.parse(nbd_data, nbd_size)) {
        printf("[NBD-RENDER] Failed to parse NBD data\n");
        return false;
    }

    // Extract and decompress textures from TEX chunk
    auto tex_indices = m_nbd.find_chunks(NBD_TYPE_TEX);
    if (!tex_indices.empty()) {
        auto tex_entries = m_nbd.extract_textures(tex_indices[0]);
        printf("[NBD-RENDER] Extracted %d compressed textures\n", (int)tex_entries.size());

        for (auto& entry : tex_entries) {
            Tim2Loader loader;
            if (loader.load(entry.tim2.data(), (uint32_t)entry.tim2.size())) {
                for (int i = 0; i < loader.texture_count(); i++) {
                    m_textures.push_back(loader.texture(i));
                    printf("[NBD-RENDER] Texture %d: %dx%d type=%d globalId=%d\n",
                           (int)m_textures.size() - 1,
                           m_textures.back().width, m_textures.back().height,
                           m_textures.back().image_type,
                           m_textures.back().global_tex_id);
                }
            }
        }

        // Upload textures to GS VRAM
        upload_textures_to_vram();
    }

    // Find AMO chunk
    auto amo_indices = m_nbd.find_chunks(NBD_TYPE_AMO);
    if (amo_indices.empty()) {
        printf("[NBD-RENDER] No AMO chunk found\n");
        return false;
    }

    const auto& amo_chunk = m_nbd.chunk(amo_indices[0]);
    const uint8_t* amo_data = m_nbd.chunk_data(amo_indices[0]);
    if (!amo_data) return false;

    if (!m_amo.parse(amo_data, amo_chunk.size)) {
        printf("[NBD-RENDER] Failed to parse AMO data\n");
        return false;
    }

    // Center camera on model
    const auto& mdl = m_amo.model();
    m_cam_x = (mdl.bbox_min[0] + mdl.bbox_max[0]) * 0.5f;
    m_cam_y = (mdl.bbox_min[1] + mdl.bbox_max[1]) * 0.5f;
    m_cam_z = (mdl.bbox_min[2] + mdl.bbox_max[2]) * 0.5f;

    // Scale to fit 640x448 screen
    float dx = mdl.bbox_max[0] - mdl.bbox_min[0];
    float dy = mdl.bbox_max[1] - mdl.bbox_min[1];
    float span = std::max(dx, dy);
    if (span > 0) m_scale = 400.0f / span;

    build_triangle_packet(mdl);
    m_loaded = true;

    printf("[NBD-RENDER] Ready: %d textures, scale=%.2f\n",
           (int)m_textures.size(), m_scale);
    return true;
}

void NbdRenderer::set_camera(float cx, float cy, float cz, float scale) {
    m_cam_x = cx;
    m_cam_y = cy;
    m_cam_z = cz;
    m_scale = scale;
    if (m_loaded) {
        m_gif_packet.clear();
        build_triangle_packet(m_amo.model());
    }
}

void NbdRenderer::render() {
    if (!m_loaded || m_gif_packet.empty()) return;
    reo_gs_submit_path3_direct(m_gif_packet.data(), (uint32_t)m_gif_packet.size());
}

// Helper: write a 128-bit (16-byte) quadword to the packet
static void emit_qw(std::vector<uint8_t>& pkt, uint64_t lo, uint64_t hi) {
    size_t off = pkt.size();
    pkt.resize(off + 16);
    memcpy(pkt.data() + off, &lo, 8);
    memcpy(pkt.data() + off + 8, &hi, 8);
}

// GIF A+D register addresses
enum GSReg : uint64_t {
    GS_PRIM    = 0x00,
    GS_RGBAQ   = 0x01,
    GS_ST      = 0x02,
    GS_XYZ2    = 0x05,
    GS_TEX0_1  = 0x06,
    GS_TEX1_1  = 0x14,
    GS_XYOFFSET_1 = 0x18,
    GS_SCISSOR_1  = 0x40,
    GS_TEST_1  = 0x47,
    GS_FRAME_1 = 0x4C,
    GS_ZBUF_1  = 0x4E,
};

void NbdRenderer::upload_textures_to_vram() {
    uint8_t* vram = reo_gs_vram();
    if (!vram) {
        printf("[NBD-RENDER] No GS VRAM available\n");
        return;
    }
    uint32_t vram_size = reo_gs_vram_size();

    uint32_t tex_block = TEX_VRAM_START_BLOCK;
    uint32_t clut_block = CLUT_VRAM_START_BLOCK;

    for (int i = 0; i < (int)m_textures.size(); i++) {
        auto& tex = m_textures[i];

        if (tex.image_type == 5 && !tex.pixel_data.empty()) {
            // Upload PSMT8 pixel data using swizzled addressing
            uint32_t tbw = tex.width / 64; // Buffer width in 64-pixel units
            if (tbw == 0) tbw = 1;

            for (uint32_t y = 0; y < tex.height; y++) {
                for (uint32_t x = 0; x < tex.width; x++) {
                    uint32_t src_idx = y * tex.width + x;
                    if (src_idx >= tex.pixel_data.size()) break;
                    uint32_t addr = gs_pixel_addr8(x, y, tex_block, tbw);
                    if (addr < vram_size) {
                        vram[addr] = tex.pixel_data[src_idx];
                    }
                }
            }

            // Upload CLUT (256 RGBA32 entries) linearly at clut_block
            uint32_t clut_byte_off = clut_block * 64;
            if (!tex.clut_data.empty() && clut_byte_off + tex.clut_data.size() <= vram_size) {
                memcpy(vram + clut_byte_off, tex.clut_data.data(), tex.clut_data.size());
            }

            // Store VRAM locations for later use in rendering
            tex.gs_tex0 = build_tex0(tex_block, tbw, 0x13, tex.width, tex.height, clut_block);

            printf("[NBD-RENDER] Uploaded texture %d: %dx%d PSMT8 to VRAM block %u, CLUT at %u\n",
                   i, tex.width, tex.height, tex_block, clut_block);

            // Advance to next slot (256x256 PSMT8 = 256 pages = 8192 blocks)
            tex_block += (tex.width * tex.height) / 64 + 1;
            clut_block += 16; // 1024 bytes / 64 = 16 blocks per CLUT
        }
    }
}

uint64_t NbdRenderer::build_tex0(uint32_t tbp, uint32_t tbw, uint32_t psm,
                                  uint32_t width, uint32_t height, uint32_t cbp) {
    // Encode GS TEX0 register
    uint64_t tex0 = 0;
    tex0 |= (uint64_t)(tbp & 0x3FFF);                     // TBP0 [13:0]
    tex0 |= (uint64_t)(tbw & 0x3F) << 14;                 // TBW [19:14]
    tex0 |= (uint64_t)(psm & 0x3F) << 20;                 // PSM [25:20]

    // TW/TH are log2 of dimensions
    uint32_t tw = 0, th = 0;
    for (uint32_t w = width; w > 1; w >>= 1) tw++;
    for (uint32_t h = height; h > 1; h >>= 1) th++;
    tex0 |= (uint64_t)(tw & 0xF) << 26;                   // TW [29:26]
    tex0 |= (uint64_t)(th & 0xF) << 30;                   // TH [33:30]

    tex0 |= (uint64_t)1 << 34;                            // TCC=1 (use alpha)
    tex0 |= (uint64_t)0 << 35;                            // TFX=0 (modulate)
    tex0 |= (uint64_t)(cbp & 0x3FFF) << 37;               // CBP [50:37]
    tex0 |= (uint64_t)0 << 51;                            // CPSM=0 (PSMCT32)
    tex0 |= (uint64_t)0 << 55;                            // CSM=0 (CSM1)
    tex0 |= (uint64_t)0 << 56;                            // CSA=0
    tex0 |= (uint64_t)1 << 61;                            // CLD=1 (load CLUT)

    return tex0;
}

void NbdRenderer::build_triangle_packet(const AmoModel& model) {
    m_gif_packet.clear();

    if (model.vertices.empty() || model.strips.empty()) return;

    const float screen_cx = 320.0f;
    const float screen_cy = 224.0f;
    bool has_textures = !m_textures.empty();
    bool has_uvs = !model.texcoords.empty();

    // Count total triangles
    int total_tris = 0;
    for (auto& s : model.strips) {
        total_tris += std::max(0, (int)s.indices.size() - 2);
    }
    if (total_tris == 0) return;

    // Emit setup packet: FRAME, ZBUF, SCISSOR, XYOFFSET, TEST, TEX0, PRIM
    {
        int nreg = has_textures ? 8 : 6;
        uint64_t tag_lo = (uint64_t)nreg | (0ULL << 15); // NLOOP, no EOP
        tag_lo |= (1ULL << 60); // NREG=1
        uint64_t tag_hi = 0x0E; // A+D
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        // FRAME_1: FBP=0, FBW=10, PSM=0
        uint64_t frame = 0 | (10ULL << 16) | (0ULL << 24);
        emit_qw(m_gif_packet, frame, GS_FRAME_1);

        // ZBUF_1: ZBP=0x88, PSM=0, ZMSK=0
        uint64_t zbuf = 0x88 | (0ULL << 24) | (0ULL << 32);
        emit_qw(m_gif_packet, zbuf, GS_ZBUF_1);

        // SCISSOR_1: 0..639, 0..447
        uint64_t scissor = 0 | (639ULL << 16) | (0ULL << 32) | (447ULL << 48);
        emit_qw(m_gif_packet, scissor, GS_SCISSOR_1);

        // XYOFFSET_1: 0,0
        emit_qw(m_gif_packet, 0, GS_XYOFFSET_1);

        // TEST_1: ZTE=1, ZTST=GREATER_EQUAL(2)
        uint64_t test = (1ULL << 16) | (2ULL << 17);
        emit_qw(m_gif_packet, test, GS_TEST_1);

        if (has_textures) {
            // TEX0_1: use first texture
            emit_qw(m_gif_packet, m_textures[0].gs_tex0, GS_TEX0_1);

            // TEX1_1: bilinear filtering off (nearest neighbor)
            uint64_t tex1 = 0; // LCM=0, MXL=0, MMAG=0 (nearest), MMIN=0 (nearest)
            emit_qw(m_gif_packet, tex1, GS_TEX1_1);
        }

        // PRIM: TRIANGLE with Gouraud + texture mapping
        uint64_t prim = 3; // TRIANGLE
        prim |= (1ULL << 3); // IIP=1 (Gouraud)
        if (has_textures && has_uvs) {
            prim |= (1ULL << 4); // TME=1 (texture mapping enable)
        }
        emit_qw(m_gif_packet, prim, GS_PRIM);
    }

    // Directional lighting
    float light_dir[3] = { 0.3f, 0.7f, 0.6f };
    float len = sqrtf(light_dir[0]*light_dir[0] + light_dir[1]*light_dir[1] + light_dir[2]*light_dir[2]);
    light_dir[0] /= len; light_dir[1] /= len; light_dir[2] /= len;

    // Collect triangles
    struct ScreenTri {
        int16_t x[3], y[3];
        uint32_t z[3];
        uint8_t r[3], g[3], b[3];
        float u[3], v[3]; // Texture coordinates
    };
    std::vector<ScreenTri> tris;
    tris.reserve(total_tris);

    for (auto& strip : model.strips) {
        for (int i = 0; i + 2 < (int)strip.indices.size(); i++) {
            uint32_t i0 = strip.indices[i];
            uint32_t i1 = strip.indices[i + 1];
            uint32_t i2 = strip.indices[i + 2];

            if (i0 == i1 || i1 == i2 || i0 == i2) continue;
            if (i & 1) std::swap(i1, i2);

            if (i0 >= model.vertices.size() || i1 >= model.vertices.size() ||
                i2 >= model.vertices.size()) continue;

            // Skip long-edge triangles (seam artifacts)
            {
                auto& v0 = model.vertices[i0];
                auto& v1 = model.vertices[i1];
                auto& v2 = model.vertices[i2];
                auto dist2 = [](const AmoVertex& a, const AmoVertex& b) {
                    float dx = a.x-b.x, dy = a.y-b.y, dz = a.z-b.z;
                    return dx*dx + dy*dy + dz*dz;
                };
                float max_edge2 = std::max({dist2(v0,v1), dist2(v1,v2), dist2(v0,v2)});
                if (max_edge2 > 15.0f * 15.0f) continue;
            }

            ScreenTri tri;
            uint32_t idx[3] = { i0, i1, i2 };

            for (int v = 0; v < 3; v++) {
                auto& vert = model.vertices[idx[v]];

                float sx = (vert.x - m_cam_x) * m_scale + screen_cx;
                float sy = screen_cy - (vert.y - m_cam_y) * m_scale;

                tri.x[v] = (int16_t)(sx * 16.0f);
                tri.y[v] = (int16_t)(sy * 16.0f);
                tri.z[v] = (uint32_t)((vert.z - m_cam_z) * 1000.0f + 0x7FFFFF);

                // Lighting
                float shade = 0.3f;
                if (idx[v] < model.normals.size()) {
                    auto& n = model.normals[idx[v]];
                    float dot = n.nx * light_dir[0] + n.ny * light_dir[1] + n.nz * light_dir[2];
                    if (dot > 0) shade += dot * 0.7f;
                }
                shade = std::min(shade, 1.0f);

                // With textures: vertex color modulates texture (use white-ish for full texture color)
                if (has_textures && has_uvs) {
                    tri.r[v] = (uint8_t)(shade * 255);
                    tri.g[v] = (uint8_t)(shade * 255);
                    tri.b[v] = (uint8_t)(shade * 255);
                } else {
                    tri.r[v] = (uint8_t)(shade * 180);
                    tri.g[v] = (uint8_t)(shade * 200);
                    tri.b[v] = (uint8_t)(shade * 160);
                }

                // UV coordinates
                if (has_uvs && idx[v] < model.texcoords.size()) {
                    tri.u[v] = model.texcoords[idx[v]].u;
                    tri.v[v] = model.texcoords[idx[v]].v;
                } else {
                    tri.u[v] = 0;
                    tri.v[v] = 0;
                }
            }

            tris.push_back(tri);
        }
    }

    // Emit in batches
    // With textures: each vertex needs ST + RGBAQ + XYZ2 = 3 regs
    // Without: RGBAQ + XYZ2 = 2 regs
    bool textured = has_textures && has_uvs;
    int regs_per_vert = textured ? 3 : 2;
    const int MAX_BATCH = textured ? 3500 : 5000; // Lower batch with more regs
    int remaining = (int)tris.size();
    int offset = 0;

    while (remaining > 0) {
        int batch = std::min(remaining, MAX_BATCH);
        bool is_last = (remaining - batch <= 0);

        uint64_t nloop = (uint64_t)batch * 3;
        uint64_t tag_lo = nloop;
        if (is_last) tag_lo |= (1ULL << 15); // EOP
        tag_lo |= ((uint64_t)regs_per_vert << 60); // NREG

        uint64_t tag_hi;
        if (textured) {
            // REGS: ST(2), RGBAQ(1), XYZ2(5) → 0x215
            tag_hi = 0x512; // Read as nibbles right-to-left: 2=ST, 1=RGBAQ, 5=XYZ2
        } else {
            tag_hi = 0x51; // RGBAQ(1), XYZ2(5)
        }
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        for (int t = 0; t < batch; t++) {
            auto& tri = tris[offset + t];
            for (int v = 0; v < 3; v++) {
                if (textured) {
                    // PACKED ST: S (float) at [31:0], T (float) at [63:32], Q=1.0 at [95:64]
                    uint8_t qw_st[16] = {};
                    float s = tri.u[v], st_t = tri.v[v], q = 1.0f;
                    memcpy(qw_st + 0, &s, 4);
                    memcpy(qw_st + 4, &st_t, 4);
                    memcpy(qw_st + 8, &q, 4);
                    size_t off_s = m_gif_packet.size();
                    m_gif_packet.resize(off_s + 16);
                    memcpy(m_gif_packet.data() + off_s, qw_st, 16);
                }

                // PACKED RGBAQ
                uint8_t qw_rgbaq[16] = {};
                qw_rgbaq[0] = tri.r[v];
                qw_rgbaq[4] = tri.g[v];
                qw_rgbaq[8] = tri.b[v];
                qw_rgbaq[12] = 0x80;
                size_t off_r = m_gif_packet.size();
                m_gif_packet.resize(off_r + 16);
                memcpy(m_gif_packet.data() + off_r, qw_rgbaq, 16);

                // PACKED XYZ2
                uint32_t px = (uint32_t)(uint16_t)tri.x[v];
                uint32_t py = (uint32_t)(uint16_t)tri.y[v];
                uint32_t pz = tri.z[v];
                uint8_t qw_xyz[16] = {};
                memcpy(qw_xyz + 0, &px, 4);
                memcpy(qw_xyz + 4, &py, 4);
                memcpy(qw_xyz + 8, &pz, 4);
                size_t off_x = m_gif_packet.size();
                m_gif_packet.resize(off_x + 16);
                memcpy(m_gif_packet.data() + off_x, qw_xyz, 16);
            }
        }

        offset += batch;
        remaining -= batch;
    }

    printf("[NBD-RENDER] Built GIF packet: %d triangles (%s), %zu bytes\n",
           (int)tris.size(), textured ? "textured" : "vertex-lit", m_gif_packet.size());
}

} // namespace reo
