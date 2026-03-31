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

    if (!m_nbd.parse(nbd_data, nbd_size)) {
        printf("[NBD-RENDER] Failed to parse NBD data\n");
        return false;
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

    printf("[NBD-RENDER] Ready: %d triangles, scale=%.2f\n",
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

    const float screen_cx = 320.0f; // Center of 640-wide screen
    const float screen_cy = 224.0f; // Center of 448-tall screen

    // Count total triangles for packet sizing
    int total_tris = 0;
    for (auto& s : model.strips) {
        total_tris += std::max(0, (int)s.indices.size() - 2);
    }
    if (total_tris == 0) return;

    // Emit setup packet: FRAME, ZBUF, SCISSOR, XYOFFSET, TEST
    // GIF tag: NLOOP=6, EOP=0, FLG=PACKED(0), NREG=1, REG=A+D(0x0E)
    {
        uint64_t tag_lo = 6 | (0ULL << 15); // NLOOP=6, no EOP
        tag_lo |= (1ULL << 60); // NREG=1
        uint64_t tag_hi = 0x0E; // A+D
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        // FRAME_1: FBP=0 (page 0), FBW=10 (640/64), PSM=0 (PSMCT32), FBMSK=0
        uint64_t frame = 0 | (10ULL << 16) | (0ULL << 24);
        emit_qw(m_gif_packet, frame, GS_FRAME_1);

        // ZBUF_1: ZBP=0x88 (after framebuffer), PSM=0, ZMSK=0
        uint64_t zbuf = 0x88 | (0ULL << 24) | (0ULL << 32);
        emit_qw(m_gif_packet, zbuf, GS_ZBUF_1);

        // SCISSOR_1: 0..639, 0..447
        uint64_t scissor = 0 | (639ULL << 16) | (0ULL << 32) | (447ULL << 48);
        emit_qw(m_gif_packet, scissor, GS_SCISSOR_1);

        // XYOFFSET_1: offset = (0,0) in 4-bit fixed point
        uint64_t xyoffset = 0;
        emit_qw(m_gif_packet, xyoffset, GS_XYOFFSET_1);

        // TEST_1: enable Z test, method=GREATER_EQUAL(2), no alpha test
        uint64_t test = (0ULL) | (2ULL << 17); // ZTE=1 at bit 16, ZTST=2 at bits 17-18
        test |= (1ULL << 16); // ZTE enable
        emit_qw(m_gif_packet, test, GS_TEST_1);

        // PRIM: TRIANGLE with Gouraud shading
        uint64_t prim = PRIM_TRIANGLE | (1ULL << 3); // IIP=1 (Gouraud)
        emit_qw(m_gif_packet, prim, GS_PRIM);
    }

    // Emit triangles from triangle strips
    // Each triangle = 3 vertices, each vertex needs RGBAQ + XYZ2
    // GIF tag per batch: NLOOP=tri_count*3, NREG=2, REGS=RGBAQ,XYZ2
    // Max NLOOP = 0x7FFF, so batch in groups

    // Simple directional lighting
    float light_dir[3] = { 0.3f, 0.7f, 0.6f };
    float len = sqrtf(light_dir[0]*light_dir[0] + light_dir[1]*light_dir[1] + light_dir[2]*light_dir[2]);
    light_dir[0] /= len; light_dir[1] /= len; light_dir[2] /= len;

    // Collect all triangles first
    struct ScreenTri {
        int16_t x[3], y[3];
        uint32_t z[3]; // Z for depth buffer (larger = further)
        uint8_t r[3], g[3], b[3];
    };
    std::vector<ScreenTri> tris;
    tris.reserve(total_tris);

    for (auto& strip : model.strips) {
        for (int i = 0; i + 2 < (int)strip.indices.size(); i++) {
            uint32_t i0 = strip.indices[i];
            uint32_t i1 = strip.indices[i + 1];
            uint32_t i2 = strip.indices[i + 2];

            // Skip degenerate triangles
            if (i0 == i1 || i1 == i2 || i0 == i2) continue;

            // Flip winding for odd triangles (triangle strip convention)
            if (i & 1) std::swap(i1, i2);

            if (i0 >= model.vertices.size() || i1 >= model.vertices.size() ||
                i2 >= model.vertices.size()) continue;

            // Skip long-edge triangles (seam/connection tris that look like artifacts)
            {
                auto& v0 = model.vertices[i0];
                auto& v1 = model.vertices[i1];
                auto& v2 = model.vertices[i2];
                auto dist2 = [](const AmoVertex& a, const AmoVertex& b) {
                    float dx = a.x-b.x, dy = a.y-b.y, dz = a.z-b.z;
                    return dx*dx + dy*dy + dz*dz;
                };
                float max_edge2 = std::max({dist2(v0,v1), dist2(v1,v2), dist2(v0,v2)});
                if (max_edge2 > 15.0f * 15.0f) continue; // Skip edges > 15 units
            }

            ScreenTri tri;
            uint32_t idx[3] = { i0, i1, i2 };

            for (int v = 0; v < 3; v++) {
                auto& vert = model.vertices[idx[v]];

                // Simple orthographic projection: X→screen X, Y→screen Y (inverted)
                float sx = (vert.x - m_cam_x) * m_scale + screen_cx;
                float sy = screen_cy - (vert.y - m_cam_y) * m_scale;

                // GS uses 4-bit subpixel fixed point
                tri.x[v] = (int16_t)(sx * 16.0f);
                tri.y[v] = (int16_t)(sy * 16.0f);
                tri.z[v] = (uint32_t)((vert.z - m_cam_z) * 1000.0f + 0x7FFFFF);

                // Lighting
                float shade = 0.3f; // ambient
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

    // Emit in batches (max ~5000 tris per GIF tag due to NLOOP limit)
    const int MAX_BATCH = 5000;
    int remaining = (int)tris.size();
    int offset = 0;

    while (remaining > 0) {
        int batch = std::min(remaining, MAX_BATCH);
        bool is_last = (remaining - batch <= 0);

        // GIF tag: NLOOP = batch*3 (3 vertices per tri),
        // FLG=PACKED(0), NREG=2, REGS=[RGBAQ, XYZ2]
        uint64_t nloop = (uint64_t)batch * 3;
        uint64_t tag_lo = nloop;
        if (is_last) tag_lo |= (1ULL << 15); // EOP
        tag_lo |= (2ULL << 60); // NREG=2
        uint64_t tag_hi = 0x51; // REG: RGBAQ(1), XYZ2(5) → 0x51
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        for (int t = 0; t < batch; t++) {
            auto& tri = tris[offset + t];
            for (int v = 0; v < 3; v++) {
                // PACKED RGBAQ: R at byte[0], G at byte[4], B at byte[8], A at byte[12]
                // Each component is in the low byte of its 32-bit field
                uint8_t qw_rgbaq[16] = {};
                qw_rgbaq[0] = tri.r[v];
                qw_rgbaq[4] = tri.g[v];
                qw_rgbaq[8] = tri.b[v];
                qw_rgbaq[12] = 0x80; // Alpha
                size_t off_r = m_gif_packet.size();
                m_gif_packet.resize(off_r + 16);
                memcpy(m_gif_packet.data() + off_r, qw_rgbaq, 16);

                // PACKED XYZ2: X at dword[0], Y at dword[1], Z at dword[2]
                // X and Y are 12.4 fixed point (value * 16) in lower 16 bits
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

} // namespace reo
