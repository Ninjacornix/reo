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

// VRAM layout for NbdRenderer textures
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
        for (auto& entry : tex_entries) {
            Tim2Loader loader;
            if (loader.load(entry.tim2.data(), (uint32_t)entry.tim2.size())) {
                for (int i = 0; i < loader.texture_count(); i++) {
                    m_textures.push_back(loader.texture(i));
                }
            }
        }
        printf("[NBD-RENDER] Loaded %d textures\n", (int)m_textures.size());
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

    const auto& mdl = m_amo.model();

    // Default camera: look at model center from a reasonable distance
    m_cam_x = (mdl.bbox_min[0] + mdl.bbox_max[0]) * 0.5f;
    m_cam_y = (mdl.bbox_min[1] + mdl.bbox_max[1]) * 0.5f;
    float dz = mdl.bbox_max[2] - mdl.bbox_min[2];
    float dy = mdl.bbox_max[1] - mdl.bbox_min[1];
    float dx = mdl.bbox_max[0] - mdl.bbox_min[0];
    float span = std::max({dx, dy, dz});
    m_cam_z = mdl.bbox_max[2] + span * 1.5f; // Pull back from model
    m_fov = 60.0f;

    build_triangle_packet(mdl);
    m_loaded = true;

    printf("[NBD-RENDER] Ready: %d textures, %d verts, cam=(%.1f,%.1f,%.1f)\n",
           (int)m_textures.size(), (int)mdl.vertices.size(),
           m_cam_x, m_cam_y, m_cam_z);
    return true;
}

void NbdRenderer::set_camera(float cx, float cy, float cz, float scale) {
    m_cam_x = cx; m_cam_y = cy; m_cam_z = cz;
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

static void emit_qw(std::vector<uint8_t>& pkt, uint64_t lo, uint64_t hi) {
    size_t off = pkt.size();
    pkt.resize(off + 16);
    memcpy(pkt.data() + off, &lo, 8);
    memcpy(pkt.data() + off + 8, &hi, 8);
}

enum GSReg : uint64_t {
    GS_PRIM       = 0x00,
    GS_RGBAQ      = 0x01,
    GS_ST         = 0x02,
    GS_XYZ2       = 0x05,
    GS_TEX0_1     = 0x06,
    GS_TEX1_1     = 0x14,
    GS_XYOFFSET_1 = 0x18,
    GS_SCISSOR_1  = 0x40,
    GS_TEST_1     = 0x47,
    GS_FRAME_1    = 0x4C,
    GS_ZBUF_1     = 0x4E,
};

void NbdRenderer::upload_textures_to_vram() {
    uint8_t* vram = reo_gs_vram();
    if (!vram) return;
    uint32_t vram_size = reo_gs_vram_size();

    uint32_t tex_block = TEX_VRAM_START_BLOCK;
    uint32_t clut_block = CLUT_VRAM_START_BLOCK;

    for (int i = 0; i < (int)m_textures.size(); i++) {
        auto& tex = m_textures[i];
        if (tex.image_type != 5 || tex.pixel_data.empty()) continue;

        uint32_t tbw = tex.width / 64;
        if (tbw == 0) tbw = 1;

        // Upload PSMT8 pixel data with swizzled addressing
        for (uint32_t y = 0; y < tex.height; y++) {
            for (uint32_t x = 0; x < tex.width; x++) {
                uint32_t src_idx = y * tex.width + x;
                if (src_idx >= tex.pixel_data.size()) break;
                uint32_t addr = gs_pixel_addr8(x, y, tex_block, tbw);
                if (addr < vram_size) vram[addr] = tex.pixel_data[src_idx];
            }
        }

        // Upload CLUT linearly
        uint32_t clut_byte_off = clut_block * 64;
        if (!tex.clut_data.empty() && clut_byte_off + tex.clut_data.size() <= vram_size) {
            memcpy(vram + clut_byte_off, tex.clut_data.data(), tex.clut_data.size());
        }

        tex.gs_tex0 = build_tex0(tex_block, tbw, 0x13, tex.width, tex.height, clut_block);

        printf("[NBD-RENDER] Uploaded tex %d: %dx%d → VRAM blk %u, CLUT %u\n",
               i, tex.width, tex.height, tex_block, clut_block);

        tex_block += (tex.width * tex.height) / 64 + 1;
        clut_block += 16;
    }
}

uint64_t NbdRenderer::build_tex0(uint32_t tbp, uint32_t tbw, uint32_t psm,
                                  uint32_t width, uint32_t height, uint32_t cbp) {
    uint64_t tex0 = 0;
    tex0 |= (uint64_t)(tbp & 0x3FFF);
    tex0 |= (uint64_t)(tbw & 0x3F) << 14;
    tex0 |= (uint64_t)(psm & 0x3F) << 20;
    uint32_t tw = 0, th = 0;
    for (uint32_t w = width; w > 1; w >>= 1) tw++;
    for (uint32_t h = height; h > 1; h >>= 1) th++;
    tex0 |= (uint64_t)(tw & 0xF) << 26;
    tex0 |= (uint64_t)(th & 0xF) << 30;
    tex0 |= (uint64_t)1 << 34; // TCC=1
    tex0 |= (uint64_t)(cbp & 0x3FFF) << 37;
    tex0 |= (uint64_t)1 << 61; // CLD=1
    return tex0;
}

// ── Perspective projection helpers ──────────────────────────────────

struct Vec3 { float x, y, z; };

static Vec3 v3sub(Vec3 a, Vec3 b) { return {a.x-b.x, a.y-b.y, a.z-b.z}; }
static float v3dot(Vec3 a, Vec3 b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
static Vec3 v3cross(Vec3 a, Vec3 b) {
    return {a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x};
}
static Vec3 v3norm(Vec3 v) {
    float l = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
    if (l < 1e-8f) return {0,0,1};
    return {v.x/l, v.y/l, v.z/l};
}

// Project world point to screen using perspective camera
// Returns false if point is behind camera
static bool project(Vec3 pos, Vec3 cam_pos, Vec3 cam_fwd, Vec3 cam_right, Vec3 cam_up,
                    float fov_rad, float aspect, float near_z,
                    float& sx, float& sy, float& sz) {
    Vec3 local = v3sub(pos, cam_pos);
    float z = v3dot(local, cam_fwd);
    if (z < near_z) return false;

    float x = v3dot(local, cam_right);
    float y = v3dot(local, cam_up);

    float f = 1.0f / tanf(fov_rad * 0.5f);
    float ndcx = (x / z) * f / aspect;
    float ndcy = (y / z) * f;

    // NDC [-1,1] → screen [0,640] / [0,448]
    sx = (ndcx * 0.5f + 0.5f) * 640.0f;
    sy = (0.5f - ndcy * 0.5f) * 448.0f; // Y inverted
    sz = z;
    return true;
}

void NbdRenderer::build_triangle_packet(const AmoModel& model) {
    m_gif_packet.clear();
    if (model.vertices.empty() || model.strips.empty()) return;

    bool has_textures = !m_textures.empty();
    bool has_uvs = !model.texcoords.empty();
    bool textured = has_textures && has_uvs;

    // Camera setup — look toward model center
    const auto& mdl = model;
    Vec3 target = {
        (mdl.bbox_min[0] + mdl.bbox_max[0]) * 0.5f,
        (mdl.bbox_min[1] + mdl.bbox_max[1]) * 0.5f,
        (mdl.bbox_min[2] + mdl.bbox_max[2]) * 0.5f
    };
    Vec3 cam_pos = {m_cam_x, m_cam_y, m_cam_z};
    Vec3 cam_fwd = v3norm(v3sub(target, cam_pos));
    Vec3 world_up = {0, 1, 0};
    Vec3 cam_right = v3norm(v3cross(cam_fwd, world_up));
    Vec3 cam_up = v3cross(cam_right, cam_fwd);

    float fov_rad = m_fov * 3.14159f / 180.0f;
    float aspect = 640.0f / 448.0f;
    float near_z = 0.1f;

    // Directional lighting
    float light_dir[3] = { 0.3f, 0.7f, 0.6f };
    float len = sqrtf(light_dir[0]*light_dir[0] + light_dir[1]*light_dir[1] + light_dir[2]*light_dir[2]);
    light_dir[0] /= len; light_dir[1] /= len; light_dir[2] /= len;

    // Count and collect triangles
    struct ScreenTri {
        int16_t x[3], y[3];
        uint32_t z[3];
        uint8_t r[3], g[3], b[3];
        float u[3], v[3];
    };
    std::vector<ScreenTri> tris;

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
                auto& va = model.vertices[i0];
                auto& vb = model.vertices[i1];
                auto& vc = model.vertices[i2];
                auto dist2 = [](const AmoVertex& a, const AmoVertex& b) {
                    float dx = a.x-b.x, dy = a.y-b.y, dz = a.z-b.z;
                    return dx*dx + dy*dy + dz*dz;
                };
                float max_edge2 = std::max({dist2(va,vb), dist2(vb,vc), dist2(va,vc)});
                if (max_edge2 > 15.0f * 15.0f) continue;
            }

            ScreenTri tri;
            uint32_t idx[3] = { i0, i1, i2 };
            bool visible = true;

            for (int v = 0; v < 3; v++) {
                auto& vert = model.vertices[idx[v]];
                Vec3 pos = {vert.x, vert.y, vert.z};

                float sx, sy, sz;
                if (!project(pos, cam_pos, cam_fwd, cam_right, cam_up,
                             fov_rad, aspect, near_z, sx, sy, sz)) {
                    visible = false;
                    break;
                }

                // GS 12.4 fixed point
                tri.x[v] = (int16_t)(sx * 16.0f);
                tri.y[v] = (int16_t)(sy * 16.0f);
                tri.z[v] = (uint32_t)(std::max(0.0f, std::min(sz * 100.0f, (float)0xFFFFFF)));

                // Lighting
                float shade = 0.3f;
                if (idx[v] < model.normals.size()) {
                    auto& n = model.normals[idx[v]];
                    float dot = n.nx * light_dir[0] + n.ny * light_dir[1] + n.nz * light_dir[2];
                    if (dot > 0) shade += dot * 0.7f;
                }
                shade = std::min(shade, 1.0f);

                if (textured) {
                    tri.r[v] = tri.g[v] = tri.b[v] = (uint8_t)(shade * 255);
                } else {
                    tri.r[v] = (uint8_t)(shade * 180);
                    tri.g[v] = (uint8_t)(shade * 200);
                    tri.b[v] = (uint8_t)(shade * 160);
                }

                if (has_uvs && idx[v] < model.texcoords.size()) {
                    tri.u[v] = model.texcoords[idx[v]].u;
                    tri.v[v] = model.texcoords[idx[v]].v;
                } else {
                    tri.u[v] = tri.v[v] = 0;
                }
            }

            if (visible) tris.push_back(tri);
        }
    }

    if (tris.empty()) return;

    // Emit GS setup registers
    {
        int nreg = textured ? 8 : 6;
        uint64_t tag_lo = (uint64_t)nreg;
        tag_lo |= (1ULL << 60); // NREG=1
        emit_qw(m_gif_packet, tag_lo, 0x0E);

        // FRAME_1
        emit_qw(m_gif_packet, (10ULL << 16), GS_FRAME_1);
        // ZBUF_1
        emit_qw(m_gif_packet, 0x88ULL, GS_ZBUF_1);
        // SCISSOR_1
        emit_qw(m_gif_packet, (639ULL << 16) | (447ULL << 48), GS_SCISSOR_1);
        // XYOFFSET_1
        emit_qw(m_gif_packet, 0, GS_XYOFFSET_1);
        // TEST_1: ZTE=1, ZTST=GEQUAL(2)
        emit_qw(m_gif_packet, (1ULL << 16) | (2ULL << 17), GS_TEST_1);

        if (textured) {
            emit_qw(m_gif_packet, m_textures[0].gs_tex0, GS_TEX0_1);
            emit_qw(m_gif_packet, 0ULL, GS_TEX1_1);
        }

        // PRIM: TRIANGLE + Gouraud + texture
        uint64_t prim = 3 | (1ULL << 3); // TRIANGLE + IIP
        if (textured) prim |= (1ULL << 4); // TME
        emit_qw(m_gif_packet, prim, GS_PRIM);
    }

    // Emit triangles in batches
    int regs_per_vert = textured ? 3 : 2;
    const int MAX_BATCH = textured ? 3500 : 5000;
    int remaining = (int)tris.size();
    int offset = 0;

    while (remaining > 0) {
        int batch = std::min(remaining, MAX_BATCH);
        bool is_last = (remaining - batch <= 0);

        uint64_t nloop = (uint64_t)batch * 3;
        uint64_t tag_lo = nloop;
        if (is_last) tag_lo |= (1ULL << 15);
        tag_lo |= ((uint64_t)regs_per_vert << 60);

        uint64_t tag_hi = textured ? 0x512ULL : 0x51ULL;
        emit_qw(m_gif_packet, tag_lo, tag_hi);

        for (int t = 0; t < batch; t++) {
            auto& tri = tris[offset + t];
            for (int v = 0; v < 3; v++) {
                if (textured) {
                    uint8_t qw[16] = {};
                    float s = tri.u[v], st = tri.v[v], q = 1.0f;
                    memcpy(qw, &s, 4);
                    memcpy(qw + 4, &st, 4);
                    memcpy(qw + 8, &q, 4);
                    size_t p = m_gif_packet.size();
                    m_gif_packet.resize(p + 16);
                    memcpy(m_gif_packet.data() + p, qw, 16);
                }

                {
                    uint8_t qw[16] = {};
                    qw[0] = tri.r[v]; qw[4] = tri.g[v];
                    qw[8] = tri.b[v]; qw[12] = 0x80;
                    size_t p = m_gif_packet.size();
                    m_gif_packet.resize(p + 16);
                    memcpy(m_gif_packet.data() + p, qw, 16);
                }

                {
                    uint8_t qw[16] = {};
                    uint32_t px = (uint32_t)(uint16_t)tri.x[v];
                    uint32_t py = (uint32_t)(uint16_t)tri.y[v];
                    uint32_t pz = tri.z[v];
                    memcpy(qw, &px, 4);
                    memcpy(qw + 4, &py, 4);
                    memcpy(qw + 8, &pz, 4);
                    size_t p = m_gif_packet.size();
                    m_gif_packet.resize(p + 16);
                    memcpy(m_gif_packet.data() + p, qw, 16);
                }
            }
        }
        offset += batch;
        remaining -= batch;
    }

    printf("[NBD-RENDER] Built %d triangles (%s), %zu bytes, perspective FOV=%.0f\n",
           (int)tris.size(), textured ? "textured" : "lit", m_gif_packet.size(), m_fov);
}

} // namespace reo
