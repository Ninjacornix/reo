#pragma once

#include <cstdint>
#include <vector>
#include "nbd_parser.h"
#include "amo_parser.h"
#include "tim2/tim2_loader.h"

namespace reo {

/*
 * NBD Renderer — converts parsed AMO geometry into GIF A+D packets
 * and submits them directly to the GS renderer.
 *
 * This bypasses the game's VU1 transform pipeline and renders geometry
 * using pre-transformed screen-space coordinates via GIF PATH3.
 *
 * Now supports textured rendering using TIM2 textures from TEX chunks.
 */
class NbdRenderer {
public:
    NbdRenderer() = default;

    // Parse NBD data from a memory buffer and prepare for rendering.
    bool load(const uint8_t* nbd_data, uint32_t nbd_size);

    // Render the loaded model. Call once per frame.
    // Uses reo_gs_submit_path3_direct to send GIF packets.
    void render();

    // Set a simple camera transform (orthographic projection for now)
    void set_camera(float cx, float cy, float cz, float scale);

    bool loaded() const { return m_loaded; }
    const AmoModel& model() const { return m_amo.model(); }

    // Access loaded textures
    int texture_count() const { return (int)m_textures.size(); }
    const Tim2Texture* texture(int index) const {
        return (index >= 0 && index < (int)m_textures.size()) ? &m_textures[index] : nullptr;
    }

private:
    // Build GIF A+D packet for triangle rendering
    void build_triangle_packet(const AmoModel& model);

    // Upload a texture to GS VRAM (via GIF IMAGE mode)
    void upload_texture_to_vram(const Tim2Texture& tex, int slot);

    NbdParser m_nbd;
    AmoParser m_amo;
    Tim2Loader m_tim2;
    bool m_loaded = false;

    // Camera
    float m_cam_x = 0, m_cam_y = 80, m_cam_z = 0;
    float m_scale = 2.0f;

    // Loaded textures (decoded from TEX chunk)
    std::vector<Tim2Texture> m_textures;

    // Pre-built GIF packets
    std::vector<uint8_t> m_gif_packet;           // Geometry
    std::vector<std::vector<uint8_t>> m_tex_packets; // Texture uploads
};

} // namespace reo
