#include "nbd_renderer.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

// From reo_hw_bridge.cpp
extern void reo_gs_submit_path3_direct(const void* data, uint32_t bytes);

namespace reo {

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

    printf("[NBD-RENDER] Ready: %d textures, %d triangles, scale=%.2f\n",
           (int)m_textures.size(),
           (int)(m_gif_packet.size() / 16 / 4), m_scale); // rough estimate
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

// GS PRIM types
enum GSPrim : uint64_t {
    PRIM_TRIANGLE      = 3,
    PRIM_TRIANGLE_STRIP = 4,
};

void NbdRenderer::build_triangle_packet(const AmoModel& model) {
    m_gif_packet.clear();

    if (model.vertices.empty() || model.strips.empty()) return;

    const float screen_cx = 320.0f;
    const float screen_cy = 224.0f;

    // Count total triangles
    int total_tris = 0;
    for (auto& s : model.strips) {
        total_tris += std::max(0, (int)s.indices.size() - 2);
    }
    if (total_tris == 0) return;

    // Emit setup packet: FRAME, ZBUF, SCISSOR, XYOFFSET, TEST, PRIM
    {
        uint64_t tag_lo = 6 | (0ULL << 15); // NLOOP=6, no EOP
        tag_lo |= (1ULL << 60); // NREG=1
        uint64_t tag_hi = 0x0E; // A+D
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        // FRAME_1: FBP=0, FBW=10 (640/64), PSM=0 (PSMCT32)
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

        // PRIM: TRIANGLE with Gouraud shading
        uint64_t prim = PRIM_TRIANGLE | (1ULL << 3); // IIP=1
        emit_qw(m_gif_packet, prim, GS_PRIM);
    }

    // Simple directional lighting
    float light_dir[3] = { 0.3f, 0.7f, 0.6f };
    float len = sqrtf(light_dir[0]*light_dir[0] + light_dir[1]*light_dir[1] + light_dir[2]*light_dir[2]);
    light_dir[0] /= len; light_dir[1] /= len; light_dir[2] /= len;

    // Collect all triangles
    struct ScreenTri {
        int16_t x[3], y[3];
        uint32_t z[3];
        uint8_t r[3], g[3], b[3];
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

                float shade = 0.3f;
                if (idx[v] < model.normals.size()) {
                    auto& n = model.normals[idx[v]];
                    float dot = n.nx * light_dir[0] + n.ny * light_dir[1] + n.nz * light_dir[2];
                    if (dot > 0) shade += dot * 0.7f;
                }
                shade = std::min(shade, 1.0f);

                tri.r[v] = (uint8_t)(shade * 180);
                tri.g[v] = (uint8_t)(shade * 200);
                tri.b[v] = (uint8_t)(shade * 160);
            }

            tris.push_back(tri);
        }
    }

    // Emit in batches
    const int MAX_BATCH = 5000;
    int remaining = (int)tris.size();
    int offset = 0;

    while (remaining > 0) {
        int batch = std::min(remaining, MAX_BATCH);
        bool is_last = (remaining - batch <= 0);

        uint64_t nloop = (uint64_t)batch * 3;
        uint64_t tag_lo = nloop;
        if (is_last) tag_lo |= (1ULL << 15); // EOP
        tag_lo |= (2ULL << 60); // NREG=2
        uint64_t tag_hi = 0x51; // RGBAQ(1), XYZ2(5)
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        for (int t = 0; t < batch; t++) {
            auto& tri = tris[offset + t];
            for (int v = 0; v < 3; v++) {
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

    printf("[NBD-RENDER] Built GIF packet: %d triangles, %zu bytes\n",
           (int)tris.size(), m_gif_packet.size());
}

void NbdRenderer::upload_texture_to_vram(const Tim2Texture& tex, int slot) {
    // TODO: Build GIF IMAGE mode packet to upload decoded RGBA texture to GS VRAM
    // This would use GS BITBLTBUF + TRXPOS + TRXREG + TRXDIR registers
    // followed by IMAGE data transfer
    printf("[NBD-RENDER] Texture upload slot %d: %dx%d (not yet implemented)\n",
           slot, tex.width, tex.height);
}

} // namespace reo
