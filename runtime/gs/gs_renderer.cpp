#include "gs_renderer.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

// stb_image_write is already compiled in raylib — just declare what we need
extern "C" int stbi_write_png(const char *filename, int w, int h, int comp,
                               const void *data, int stride_in_bytes);

// ── Screenshot + Toast state ────────────────────────────────────────

#define TOAST_DURATION_MS  2500
#define TOAST_FADE_MS       500
#define TOAST_PADDING       8

static bool     s_screenshot_requested = false;
static int      s_screenshot_counter   = 0;
static char     s_toast_msg[256]       = {0};
static uint32_t s_toast_start          = 0;

namespace reo {

// ── Win32 window proc ───────────────────────────────────────────────

#ifdef _WIN32
static LRESULT CALLBACK gs_wndproc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    case WM_DESTROY:
        return 0;
    case WM_KEYDOWN:
        if (wp == VK_F12)
            s_screenshot_requested = true;
        return 0;
    }
    return DefWindowProcA(hwnd, msg, wp, lp);
}
#endif

// ── Init / Shutdown ─────────────────────────────────────────────────

bool GSRenderer::init(int width, int height, bool fullscreen, bool headless) {
    m_width = width;
    m_height = height;
    m_fullscreen = fullscreen;

    memset(m_vram, 0, sizeof(m_vram));
    memset(m_regs, 0, sizeof(m_regs));

    // GS CSR defaults (revision ID for late-model PS2)
    m_regs[GS_CSR >> 4] = 0x55;

    // Allocate software framebuffer (magenta = visible proof of life if GIF clears it)
    m_framebuffer = new uint32_t[width * height];
    for (int i = 0; i < width * height; i++) {
        m_framebuffer[i] = 0xFFFF00FF; // Magenta (ABGR)
    }

    // Initialize drawing state
    m_draw.scissor_x1 = width - 1;
    m_draw.scissor_y1 = height - 1;
    m_draw.vtx_count = 0;
    m_draw.vtx_kick = 3; // Triangle by default

    if (!headless) {
        // Create Win32 window
        if (!create_window()) {
            printf("[GS] Warning: Could not create window, running headless\n");
        }
    }

    printf("[GS] Renderer initialized: %dx%d %s%s\n",
           width, height, fullscreen ? "fullscreen" : "windowed",
           headless ? " (headless)" : "");
    printf("[GS] Backend: Software rasterizer%s\n",
           headless ? " (framebuffer only)" : " → GDI blit");

    return true;
}

bool GSRenderer::create_window() {
#ifdef _WIN32
    WNDCLASSA wc = {};
    wc.lpfnWndProc = gs_wndproc;
    wc.hInstance = GetModuleHandleA(nullptr);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.lpszClassName = "REO_GS";
    RegisterClassA(&wc);

    DWORD style = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
    RECT rect = {0, 0, m_width, m_height};
    AdjustWindowRect(&rect, style, FALSE);

    HWND hwnd = CreateWindowA("REO_GS", "REO - Resident Evil Outbreak: Recompiled",
                               style, CW_USEDEFAULT, CW_USEDEFAULT,
                               rect.right - rect.left, rect.bottom - rect.top,
                               nullptr, nullptr, wc.hInstance, nullptr);
    if (!hwnd) return false;

    m_hwnd = hwnd;
    m_hdc = GetDC(hwnd);

    // Set up BITMAPINFO for GDI blitting
    auto* bmi = new BITMAPINFO();
    memset(bmi, 0, sizeof(BITMAPINFO));
    bmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi->bmiHeader.biWidth = m_width;
    bmi->bmiHeader.biHeight = -m_height; // Top-down
    bmi->bmiHeader.biPlanes = 1;
    bmi->bmiHeader.biBitCount = 32;
    bmi->bmiHeader.biCompression = BI_RGB;
    m_bmp_info = bmi;

    return true;
#else
    return false;
#endif
}

void GSRenderer::shutdown() {
    printf("[GS] Renderer shutdown\n");

#ifdef _WIN32
    if (m_hdc && m_hwnd) {
        ReleaseDC((HWND)m_hwnd, (HDC)m_hdc);
    }
    if (m_hwnd) {
        DestroyWindow((HWND)m_hwnd);
    }
    delete (BITMAPINFO*)m_bmp_info;
    m_bmp_info = nullptr;
#endif

    delete[] m_framebuffer;
    m_framebuffer = nullptr;
}

// ── GS register access ─────────────────────────────────────────────

uint64_t GSRenderer::read_register(uint32_t offset) {
    uint32_t idx = (offset & 0x1FFF) >> 4;
    if (idx < 256) {
        return m_regs[idx];
    }
    return 0;
}

void GSRenderer::write_register(uint32_t offset, uint64_t value) {
    uint32_t idx = (offset & 0x1FFF) >> 4;
    if (idx < 256) {
        m_regs[idx] = value;
    }

    switch (offset & 0x1FFF) {
    case GS_CSR:
        if (value & 0x08) {
            m_vsync_flag = false;
        }
        break;

    case GS_BGCOLOR:
        // BGCOLOR is the GS background color shown when no display circuit is active.
        // It does NOT clear the drawing framebuffer — the game clears by drawing sprites.
        break;

    case GS_DISPFB1:
    case GS_DISPFB2: {
        // Display framebuffer pointer: tells us where the game's framebuffer is in VRAM
        m_draw.frame_base = (value & 0x1FF) * 2048;  // Base pointer (in 64-byte units * 32)
        m_draw.frame_width = ((value >> 9) & 0x3F) * 64;
        m_draw.frame_psm = (value >> 15) & 0x1F;
        break;
    }

    default:
        break;
    }
}

// ── GIF tag parsing ─────────────────────────────────────────────────

GIFTag GSRenderer::parse_gif_tag(const uint8_t* data) {
    GIFTag tag;

    uint64_t lo = *(const uint64_t*)(data);
    uint64_t hi = *(const uint64_t*)(data + 8);

    tag.nloop = lo & 0x7FFF;
    tag.eop   = (lo >> 15) & 1;
    tag.pre   = (lo >> 46) & 1;
    tag.prim  = (lo >> 47) & 0x7FF;
    tag.flg   = (lo >> 58) & 0x3;
    tag.nreg  = (lo >> 60) & 0xF;
    if (tag.nreg == 0) tag.nreg = 16; // 0 means 16

    tag.regs = hi;

    return tag;
}

// ── GIF packet processing ───────────────────────────────────────────

void GSRenderer::process_gif_packet(const uint8_t* data, uint32_t size) {
    uint32_t offset = 0;

    static uint64_t totalPackets = 0;
    static uint64_t totalTags = 0;
    totalPackets++;

    while (offset + 16 <= size) {
        GIFTag tag = parse_gif_tag(data + offset);
        offset += 16; // Skip the tag itself
        totalTags++;

        static int tagLog = 0;
        if (tagLog < 50) {
            uint64_t lo = *(const uint64_t*)(data + offset - 16);
            uint64_t hi = *(const uint64_t*)(data + offset - 8);
            printf("[GS-GIF] tag #%llu: nloop=%u nreg=%u flg=%u eop=%d pre=%d prim=0x%X regs=0x%llX raw=[0x%llX 0x%llX] (pkt#%llu, %u bytes remain)\n",
                   (unsigned long long)totalTags, tag.nloop, tag.nreg, tag.flg,
                   tag.eop ? 1 : 0, tag.pre ? 1 : 0, tag.prim,
                   (unsigned long long)tag.regs, (unsigned long long)lo, (unsigned long long)hi,
                   (unsigned long long)totalPackets, size - offset);
            tagLog++;
        }

        if (tag.nloop == 0) {
            if (tag.eop) break;
            continue;
        }

        // If PRE is set, apply the PRIM value
        if (tag.pre) {
            write_internal_reg(GIF_REG_PRIM, tag.prim);
        }

        switch (tag.flg) {
        case 0: // PACKED mode
        {
            uint32_t data_size = tag.nloop * tag.nreg * 16;
            uint32_t available = size - offset;
            if (data_size > available) {
                // Process what we have — some games send short packets
                if (available >= 16) {
                    GIFTag adjusted = tag;
                    uint32_t total_regs = available / 16;
                    adjusted.nloop = total_regs / adjusted.nreg;
                    if (adjusted.nloop == 0 && total_regs > 0) {
                        adjusted.nloop = 1;
                        adjusted.nreg = (uint8_t)total_regs;
                    }
                    process_packed_data(adjusted, data + offset);
                }
                offset = size;
            } else {
                process_packed_data(tag, data + offset);
                offset += data_size;
            }
            break;
        }
        case 1: // REGLIST mode
        {
            uint32_t data_size = tag.nloop * tag.nreg * 8;
            // Align to 16 bytes
            data_size = (data_size + 15) & ~15;
            uint32_t available = size - offset;
            if (data_size > available) {
                if (available >= 8) {
                    GIFTag adjusted = tag;
                    uint32_t total_regs = available / 8;
                    adjusted.nloop = total_regs / adjusted.nreg;
                    if (adjusted.nloop == 0 && total_regs > 0) {
                        adjusted.nloop = 1;
                        adjusted.nreg = (uint8_t)total_regs;
                    }
                    process_reglist_data(adjusted, data + offset);
                }
                offset = size;
            } else {
                process_reglist_data(tag, data + offset);
                offset += data_size;
            }
            break;
        }
        case 2: // IMAGE mode (direct VRAM transfer)
        {
            uint32_t data_size = tag.nloop * 16;
            if (offset + data_size > size) data_size = size - offset;

            // Write pixel data to GS VRAM using swizzled addressing
            if (m_transfer.dir == 0 && m_transfer.rrw > 0 && m_transfer.rrh > 0) {
                const uint32_t* src32 = (const uint32_t*)(data + offset);
                uint32_t* vram32 = (uint32_t*)m_vram;
                int num_pixels = data_size / 4;
                int pixel_idx = 0;

                // dbp/dbw are already in GS register units (64-byte blocks / 64-pixel widths)
                uint32_t dbp_blocks = m_transfer.dbp / 64;  // Convert byte offset back to block units
                uint32_t dbw_pages = m_transfer.dbw / 64;   // Convert pixel width back to page units

                if (m_transfer.dpsm == 0) { // PSMCT32 — swizzled write
                    for (int py = 0; py < m_transfer.rrh && pixel_idx < num_pixels; py++) {
                        for (int px = 0; px < m_transfer.rrw && pixel_idx < num_pixels; px++) {
                            int x = m_transfer.dsax + px;
                            int y = m_transfer.dsay + py;
                            uint32_t word_addr = gs_pixel_addr32(x, y, dbp_blocks, dbw_pages);
                            vram32[word_addr] = src32[pixel_idx++];
                        }
                    }
                } else {
                    // Non-PSMCT32: linear fallback
                    uint32_t dest = m_transfer.dbp + m_transfer.dsay * m_transfer.dbw * 4
                                  + m_transfer.dsax * 4;
                    uint32_t copy_size = std::min(data_size, (uint32_t)(sizeof(m_vram) - dest));
                    if (dest < sizeof(m_vram) && copy_size > 0) {
                        memcpy(m_vram + dest, data + offset, copy_size);
                    }
                }

                static int imgLog = 0;
                if (imgLog < 5) {
                    printf("[GS] IMAGE upload: %u bytes to VRAM dbp=%u dbw=%u at (%d,%d) %dx%d\n",
                           data_size, dbp_blocks, dbw_pages,
                           m_transfer.dsax, m_transfer.dsay,
                           m_transfer.rrw, m_transfer.rrh);
                    imgLog++;
                }
            }
            offset += data_size;
            break;
        }
        default:
            // Disabled or invalid
            return;
        }

        if (tag.eop) break;
    }
}

void GSRenderer::process_packed_data(const GIFTag& tag, const uint8_t* data) {
    uint32_t pos = 0;

    for (uint32_t loop = 0; loop < tag.nloop; loop++) {
        for (uint8_t r = 0; r < tag.nreg; r++) {
            uint8_t reg = (tag.regs >> (r * 4)) & 0xF;
            const uint8_t* qw = data + pos;

            switch (reg) {
            case GIF_REG_PRIM: {
                uint64_t val = *(const uint64_t*)qw;
                write_internal_reg(GIF_REG_PRIM, val);
                break;
            }
            case GIF_REG_RGBAQ: {
                m_draw.r = qw[0];
                m_draw.g = qw[4];
                m_draw.b = qw[8];
                m_draw.a = qw[12];
                // Q is in the upper 32 bits of the last dword
                uint32_t q_bits = *(const uint32_t*)(qw + 12);
                memcpy(&m_draw.q, &q_bits, 4);
                if (m_draw.q == 0.0f) m_draw.q = 1.0f;
                break;
            }
            case GIF_REG_ST: {
                memcpy(&m_draw.s, qw, 4);
                memcpy(&m_draw.t, qw + 4, 4);
                // Q from RGBAQ
                break;
            }
            case GIF_REG_UV: {
                // Fixed point 14.0 UV → float
                uint32_t u = *(const uint32_t*)qw & 0x3FFF;
                uint32_t v = (*(const uint32_t*)qw >> 16) & 0x3FFF;
                m_draw.s = (float)u / 16.0f;
                m_draw.t = (float)v / 16.0f;
                break;
            }
            case GIF_REG_XYZF2:
            case GIF_REG_XYZF3: {
                // PACKED XYZF: X[31:0], Y[31:0], Z/F interleaved
                // X and Y are 16.4 fixed point in the lower 16 bits
                uint32_t raw_x = *(const uint32_t*)(qw + 0);
                uint32_t raw_y = *(const uint32_t*)(qw + 4);
                uint32_t raw_z = *(const uint32_t*)(qw + 8) & 0xFFFFFF;
                uint8_t fog = qw[11];

                GSVertex vtx;
                vtx.x = (float)(raw_x & 0xFFFF) / 16.0f - m_draw.offset_x;
                vtx.y = (float)(raw_y & 0xFFFF) / 16.0f - m_draw.offset_y;
                vtx.z = (float)raw_z / (float)0xFFFFFF;
                vtx.r = m_draw.r;
                vtx.g = m_draw.g;
                vtx.b = m_draw.b;
                vtx.a = m_draw.a;
                vtx.s = m_draw.s;
                vtx.t = m_draw.t;
                vtx.q = m_draw.q;
                vtx.fog = (float)fog / 255.0f;
                vtx.drawing_kick = (reg == GIF_REG_XYZF2); // XYZF3 = no kick

                submit_vertex(vtx);
                break;
            }
            case GIF_REG_XYZ2:
            case GIF_REG_XYZ3: {
                uint32_t raw_x = *(const uint32_t*)(qw + 0);
                uint32_t raw_y = *(const uint32_t*)(qw + 4);
                uint32_t raw_z = *(const uint32_t*)(qw + 8);

                GSVertex vtx;
                vtx.x = (float)(raw_x & 0xFFFF) / 16.0f - m_draw.offset_x;
                vtx.y = (float)(raw_y & 0xFFFF) / 16.0f - m_draw.offset_y;
                vtx.z = (float)raw_z / (float)0xFFFFFFFF;
                vtx.r = m_draw.r;
                vtx.g = m_draw.g;
                vtx.b = m_draw.b;
                vtx.a = m_draw.a;
                vtx.s = m_draw.s;
                vtx.t = m_draw.t;
                vtx.q = m_draw.q;
                vtx.fog = m_draw.fog_val;
                vtx.drawing_kick = (reg == GIF_REG_XYZ2);

                submit_vertex(vtx);
                break;
            }
            case GIF_REG_AD: {
                // A+D: lower 64 bits = data, upper 8 bits of high qword = register address
                uint64_t val = *(const uint64_t*)qw;
                uint8_t ad_reg = qw[8];
                write_internal_reg(ad_reg, val);
                break;
            }
            case GIF_REG_FOG: {
                m_draw.fog_val = (float)qw[12] / 255.0f;
                break;
            }
            case GIF_REG_NOP:
            default:
                break;
            }

            pos += 16; // Each packed register is 128 bits
        }
    }
}

void GSRenderer::process_reglist_data(const GIFTag& tag, const uint8_t* data) {
    uint32_t pos = 0;

    for (uint32_t loop = 0; loop < tag.nloop; loop++) {
        for (uint8_t r = 0; r < tag.nreg; r++) {
            uint8_t reg = (tag.regs >> (r * 4)) & 0xF;
            uint64_t val = *(const uint64_t*)(data + pos);

            write_internal_reg(reg, val);
            pos += 8;
        }
    }
}

// ── Internal register writes ────────────────────────────────────────

void GSRenderer::write_internal_reg(uint8_t reg, uint64_t value) {
    // Store raw register value for texture lookups etc.
    if (reg < 128) m_regs[reg] = value;

    static int regLog = 0;
    if (regLog < 50) {
        printf("[GS-REG] write reg=0x%02X val=0x%llX\n", reg, (unsigned long long)value);
        regLog++;
    }

    switch (reg) {
    case GIF_REG_PRIM: {
        // PRIM register: primitive type and drawing attributes
        m_draw.prim_type = (GSPrimType)(value & 0x7);
        m_draw.gouraud   = (value >> 3) & 1;
        m_draw.texture   = (value >> 4) & 1;
        m_draw.fog       = (value >> 5) & 1;
        m_draw.alpha_blend = (value >> 6) & 1;
        m_draw.aa        = (value >> 7) & 1;

        // Reset vertex count for new primitive
        m_draw.vtx_count = 0;

        switch (m_draw.prim_type) {
        case GSPrimType::Point:         m_draw.vtx_kick = 1; break;
        case GSPrimType::Line:          m_draw.vtx_kick = 2; break;
        case GSPrimType::LineStrip:     m_draw.vtx_kick = 2; break;
        case GSPrimType::Triangle:      m_draw.vtx_kick = 3; break;
        case GSPrimType::TriangleStrip: m_draw.vtx_kick = 3; break;
        case GSPrimType::TriangleFan:   m_draw.vtx_kick = 3; break;
        case GSPrimType::Sprite:        m_draw.vtx_kick = 2; break;
        }
        break;
    }
    case 0x18: { // XYOFFSET_1 — Drawing offset
        // OFX: bits 0-15 (16.4 fixed point), OFY: bits 32-47 (16.4 fixed point)
        m_draw.offset_x = (float)(value & 0xFFFF) / 16.0f;
        m_draw.offset_y = (float)((value >> 32) & 0xFFFF) / 16.0f;
        break;
    }
    case 0x19: { // XYOFFSET_2 — Drawing offset (context 2, treat same)
        m_draw.offset_x = (float)(value & 0xFFFF) / 16.0f;
        m_draw.offset_y = (float)((value >> 32) & 0xFFFF) / 16.0f;
        break;
    }
    case 0x40: { // SCISSOR_1
        m_draw.scissor_x0 = (int)(value & 0x7FF);
        m_draw.scissor_x1 = (int)((value >> 16) & 0x7FF);
        m_draw.scissor_y0 = (int)((value >> 32) & 0x7FF);
        m_draw.scissor_y1 = (int)((value >> 48) & 0x7FF);
        break;
    }
    case 0x50: { // BITBLTBUF — transfer destination setup
        m_transfer.dbp = (uint32_t)((value >> 32) & 0x3FFF) * 64; // Dest base ptr (in bytes)
        m_transfer.dbw = (uint32_t)((value >> 48) & 0x3F) * 64;   // Dest buffer width (pixels)
        m_transfer.dpsm = (uint32_t)((value >> 56) & 0x3F);       // Dest pixel format
        break;
    }
    case 0x51: { // TRXPOS — transfer position
        m_transfer.dsax = (int)((value >> 32) & 0x7FF);
        m_transfer.dsay = (int)((value >> 48) & 0x7FF);
        break;
    }
    case 0x52: { // TRXREG — transfer size
        m_transfer.rrw = (int)(value & 0xFFF);
        m_transfer.rrh = (int)((value >> 32) & 0xFFF);
        break;
    }
    case 0x53: { // TRXDIR — transfer direction
        m_transfer.dir = (int)(value & 0x3);
        break;
    }
    case 0x4C: { // FRAME_1
        m_draw.frame_base = (uint32_t)(value & 0x1FF) * 2048;
        m_draw.frame_width = (uint32_t)((value >> 16) & 0x3F) * 64;
        m_draw.frame_psm = (uint32_t)((value >> 24) & 0x3F);
        break;
    }
    case 0x01: { // RGBAQ (via A+D)
        m_draw.r = value & 0xFF;
        m_draw.g = (value >> 8) & 0xFF;
        m_draw.b = (value >> 16) & 0xFF;
        m_draw.a = (value >> 24) & 0xFF;
        // Q is in bits 63:32
        uint32_t q_bits = (uint32_t)(value >> 32);
        memcpy(&m_draw.q, &q_bits, 4);
        if (m_draw.q == 0.0f) m_draw.q = 1.0f;
        break;
    }
    case 0x02: { // ST (via A+D)
        uint32_t s_bits = (uint32_t)(value & 0xFFFFFFFF);
        uint32_t t_bits = (uint32_t)(value >> 32);
        memcpy(&m_draw.s, &s_bits, 4);
        memcpy(&m_draw.t, &t_bits, 4);
        break;
    }
    case 0x03: { // UV (via A+D)
        uint32_t u = value & 0x3FFF;
        uint32_t v = (value >> 16) & 0x3FFF;
        m_draw.s = (float)u / 16.0f;
        m_draw.t = (float)v / 16.0f;
        break;
    }
    case 0x04: { // XYZF2 (via A+D, with drawing kick)
        GSVertex vtx;
        vtx.x = (float)(value & 0xFFFF) / 16.0f - m_draw.offset_x;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f - m_draw.offset_y;
        vtx.z = (float)((value >> 32) & 0xFFFFFF) / (float)0xFFFFFF;
        vtx.r = m_draw.r; vtx.g = m_draw.g; vtx.b = m_draw.b; vtx.a = m_draw.a;
        vtx.s = m_draw.s; vtx.t = m_draw.t; vtx.q = m_draw.q;
        vtx.fog = (float)((value >> 56) & 0xFF) / 255.0f;
        vtx.drawing_kick = true;
        submit_vertex(vtx);
        break;
    }
    case 0x05: { // XYZ2 (via A+D, with drawing kick)
        GSVertex vtx;
        vtx.x = (float)(value & 0xFFFF) / 16.0f - m_draw.offset_x;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f - m_draw.offset_y;
        vtx.z = (float)((value >> 32) & 0xFFFFFFFF) / (float)0xFFFFFFFF;
        vtx.r = m_draw.r; vtx.g = m_draw.g; vtx.b = m_draw.b; vtx.a = m_draw.a;
        vtx.s = m_draw.s; vtx.t = m_draw.t; vtx.q = m_draw.q;
        vtx.fog = m_draw.fog_val;
        vtx.drawing_kick = true;
        submit_vertex(vtx);
        break;
    }
    case 0x0C: { // XYZF3 (via A+D, no drawing kick)
        GSVertex vtx;
        vtx.x = (float)(value & 0xFFFF) / 16.0f - m_draw.offset_x;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f - m_draw.offset_y;
        vtx.z = (float)((value >> 32) & 0xFFFFFF) / (float)0xFFFFFF;
        vtx.r = m_draw.r; vtx.g = m_draw.g; vtx.b = m_draw.b; vtx.a = m_draw.a;
        vtx.s = m_draw.s; vtx.t = m_draw.t; vtx.q = m_draw.q;
        vtx.fog = (float)((value >> 56) & 0xFF) / 255.0f;
        vtx.drawing_kick = false;
        submit_vertex(vtx);
        break;
    }
    case 0x0D: { // XYZ3 (via A+D, no drawing kick)
        GSVertex vtx;
        vtx.x = (float)(value & 0xFFFF) / 16.0f - m_draw.offset_x;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f - m_draw.offset_y;
        vtx.z = (float)((value >> 32) & 0xFFFFFFFF) / (float)0xFFFFFFFF;
        vtx.r = m_draw.r; vtx.g = m_draw.g; vtx.b = m_draw.b; vtx.a = m_draw.a;
        vtx.s = m_draw.s; vtx.t = m_draw.t; vtx.q = m_draw.q;
        vtx.fog = m_draw.fog_val;
        vtx.drawing_kick = false;
        submit_vertex(vtx);
        break;
    }
    case 0x47: { // TEST_1 — pixel test control
        m_draw.alpha_test_enable = value & 1;
        m_draw.alpha_test_method = (value >> 1) & 7;
        m_draw.alpha_test_ref = (value >> 4) & 0xFF;
        m_draw.alpha_test_fail = (value >> 12) & 3;
        break;
    }
    case 0x48: { // TEST_2 — same as TEST_1 for context 2
        m_draw.alpha_test_enable = value & 1;
        m_draw.alpha_test_method = (value >> 1) & 7;
        m_draw.alpha_test_ref = (value >> 4) & 0xFF;
        m_draw.alpha_test_fail = (value >> 12) & 3;
        break;
    }
    case 0x0A: { // FOG (via A+D)
        m_draw.fog_val = (float)((value >> 56) & 0xFF) / 255.0f;
        break;
    }
    default:
        break;
    }
}

// ── Vertex submission and primitive assembly ────────────────────────

void GSRenderer::submit_vertex(const GSVertex& vtx) {
    // Add vertex to buffer
    int idx = m_draw.vtx_count % 4;
    m_draw.vtx_buf[idx] = vtx;
    m_draw.vtx_count++;

    if (!vtx.drawing_kick) return;

    if (m_draw.vtx_count >= m_draw.vtx_kick) {
        kick_primitive();
    }
}

void GSRenderer::kick_primitive() {
    if (!m_framebuffer) return;

    static uint64_t kickCount = 0;
    kickCount++;
    static int kickLog = 0;
    if (kickLog < 20) {
        printf("[GS-DRAW] kick #%llu: prim=%d vtx_count=%d\n",
               (unsigned long long)kickCount, (int)m_draw.prim_type, m_draw.vtx_count);
        kickLog++;
    }

    switch (m_draw.prim_type) {
    case GSPrimType::Triangle: {
        if (m_draw.vtx_count < 3) return;
        int base = (m_draw.vtx_count - 3) % 4;
        rasterize_triangle(
            m_draw.vtx_buf[(base + 0) % 4],
            m_draw.vtx_buf[(base + 1) % 4],
            m_draw.vtx_buf[(base + 2) % 4]
        );
        break;
    }
    case GSPrimType::TriangleStrip: {
        if (m_draw.vtx_count < 3) return;
        int base = (m_draw.vtx_count - 3) % 4;
        rasterize_triangle(
            m_draw.vtx_buf[(base + 0) % 4],
            m_draw.vtx_buf[(base + 1) % 4],
            m_draw.vtx_buf[(base + 2) % 4]
        );
        break;
    }
    case GSPrimType::TriangleFan: {
        if (m_draw.vtx_count < 3) return;
        int last = (m_draw.vtx_count - 1) % 4;
        int prev = (m_draw.vtx_count - 2) % 4;
        rasterize_triangle(
            m_draw.vtx_buf[0],    // Fan center
            m_draw.vtx_buf[prev],
            m_draw.vtx_buf[last]
        );
        break;
    }
    case GSPrimType::Sprite: {
        if (m_draw.vtx_count < 2) return;
        int base = (m_draw.vtx_count - 2) % 4;
        rasterize_sprite(
            m_draw.vtx_buf[(base + 0) % 4],
            m_draw.vtx_buf[(base + 1) % 4]
        );
        break;
    }
    case GSPrimType::Point: {
        auto& v = m_draw.vtx_buf[(m_draw.vtx_count - 1) % 4];
        plot_pixel((int)v.x, (int)v.y, v.r, v.g, v.b, v.a);
        break;
    }
    default:
        break;
    }
}

// ── Software rasterizer ─────────────────────────────────────────────

void GSRenderer::plot_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    if (x < m_draw.scissor_x0 || x > m_draw.scissor_x1 ||
        y < m_draw.scissor_y0 || y > m_draw.scissor_y1)
        return;
    if (x < 0 || x >= m_width || y < 0 || y >= m_height)
        return;

    // Alpha test (TEST_1 register)
    if (m_draw.alpha_test_enable) {
        bool pass = false;
        switch (m_draw.alpha_test_method) {
        case 0: pass = false; break;          // NEVER
        case 1: pass = true; break;           // ALWAYS
        case 2: pass = (a < m_draw.alpha_test_ref); break;   // LESS
        case 3: pass = (a <= m_draw.alpha_test_ref); break;  // LEQUAL
        case 4: pass = (a == m_draw.alpha_test_ref); break;  // EQUAL
        case 5: pass = (a >= m_draw.alpha_test_ref); break;  // GEQUAL
        case 6: pass = (a > m_draw.alpha_test_ref); break;   // GREATER
        case 7: pass = (a != m_draw.alpha_test_ref); break;  // NOTEQUAL
        }
        if (!pass) {
            if (m_draw.alpha_test_fail == 0) return; // KEEP: don't write pixel
            // FB_ONLY, ZB_ONLY, RGB_ONLY not fully implemented yet
            if (m_draw.alpha_test_fail == 2) return; // ZB_ONLY: skip framebuffer
        }
    }

    uint32_t color = ((uint32_t)a << 24) | ((uint32_t)b << 16) | ((uint32_t)g << 8) | r;

    if (m_draw.alpha_blend && a < 255) {
        // Simple alpha blending
        uint32_t dst = m_framebuffer[y * m_width + x];
        uint8_t dr = dst & 0xFF;
        uint8_t dg = (dst >> 8) & 0xFF;
        uint8_t db = (dst >> 16) & 0xFF;

        uint32_t alpha = a;
        uint32_t inv_alpha = 255 - a;

        r = (uint8_t)((r * alpha + dr * inv_alpha) / 255);
        g = (uint8_t)((g * alpha + dg * inv_alpha) / 255);
        b = (uint8_t)((b * alpha + db * inv_alpha) / 255);

        color = 0xFF000000 | ((uint32_t)b << 16) | ((uint32_t)g << 8) | r;
    }

    m_framebuffer[y * m_width + x] = color;
}

void GSRenderer::rasterize_sprite(const GSVertex& v0, const GSVertex& v1) {
    // Sprite: axis-aligned rectangle from v0 to v1
    int x0 = std::max((int)v0.x, m_draw.scissor_x0);
    int y0 = std::max((int)v0.y, m_draw.scissor_y0);
    int x1 = std::min((int)v1.x, m_draw.scissor_x1);
    int y1 = std::min((int)v1.y, m_draw.scissor_y1);

    if (m_draw.texture) {
        // Textured sprite: sample from VRAM
        uint64_t tex0 = m_regs[0x06];
        static int texLog = 0;
        if (texLog < 5) {
            printf("[GS-SPRITE] Textured: (%d,%d)-(%d,%d) TEX0=0x%016llX UV=(%.1f,%.1f)-(%.1f,%.1f)\n",
                   x0, y0, x1, y1, (unsigned long long)tex0,
                   v0.s, v0.t, v1.s, v1.t);
            fflush(stdout);
            texLog++;
        }
        uint32_t tbp0 = (uint32_t)(tex0 & 0x3FFF);  // Texture base (64-byte block units)
        uint32_t tbw = (uint32_t)((tex0 >> 14) & 0x3F); // Tex buffer width (64-pixel units)
        uint32_t tw = 1 << ((tex0 >> 26) & 0xF); // Texture width
        uint32_t th = 1 << ((tex0 >> 30) & 0xF); // Texture height
        uint32_t psm = (uint32_t)((tex0 >> 20) & 0x3F);
        if (tw == 0) tw = 1;
        if (th == 0) th = 1;
        if (tbw == 0) tbw = 1;

        float u0 = v0.s, v0t = v0.t;
        float u1 = v1.s, v1t = v1.t;

        int sx = x1 - x0;
        int sy = y1 - y0;
        if (sx <= 0 || sy <= 0) return;

        const uint32_t* vram32 = (const uint32_t*)m_vram;

        for (int y = y0; y <= y1; y++) {
            float ft = (sy > 0) ? (float)(y - y0) / (float)sy : 0;
            for (int x = x0; x <= x1; x++) {
                float fs = (sx > 0) ? (float)(x - x0) / (float)sx : 0;
                int tu = (int)(u0 + fs * (u1 - u0)) & (tw - 1);
                int tv = (int)(v0t + ft * (v1t - v0t)) & (th - 1);

                // Sample texture from VRAM using swizzled addressing
                uint32_t pixel;
                if (psm == 0) { // PSMCT32
                    uint32_t word_addr = gs_pixel_addr32(tu, tv, tbp0, tbw);
                    pixel = vram32[word_addr];
                } else if (psm == 0x13) { // PSMT8 — 8-bit indexed with CLUT
                    // Fetch palette index from VRAM
                    uint32_t byte_addr = gs_pixel_addr8(tu, tv, tbp0, tbw);
                    uint8_t index = m_vram[byte_addr];

                    // CLUT lookup: CBP (bits 37-50 of TEX0) in 64-byte block units
                    uint32_t cbp = (uint32_t)((tex0 >> 37) & 0x3FFF);
                    // CLUT stores 256 RGBA entries at CBP*64 bytes in VRAM
                    // CSM=0 (storage mode 1): CLUT entries are swizzled in 2x8 blocks
                    // For simplicity, read linearly — works for CSM1 with CSA=0
                    uint32_t clut_byte_off = cbp * 64 + index * 4;
                    if (clut_byte_off + 4 <= sizeof(m_vram))
                        memcpy(&pixel, m_vram + clut_byte_off, 4);
                    else
                        pixel = 0;
                } else if (psm == 0x14) { // PSMT4 — 4-bit indexed with CLUT
                    // Fetch 4-bit index from VRAM (2 pixels per byte)
                    uint32_t byte_addr = gs_pixel_addr8(tu / 2, tv, tbp0, tbw);
                    uint8_t byte_val = m_vram[byte_addr];
                    uint8_t index = (tu & 1) ? (byte_val >> 4) : (byte_val & 0xF);

                    uint32_t cbp = (uint32_t)((tex0 >> 37) & 0x3FFF);
                    uint32_t clut_byte_off = cbp * 64 + index * 4;
                    if (clut_byte_off + 4 <= sizeof(m_vram))
                        memcpy(&pixel, m_vram + clut_byte_off, 4);
                    else
                        pixel = 0;
                } else {
                    pixel = 0xFF808080; // Unsupported PSM — show grey
                }

                uint8_t r = pixel & 0xFF;
                uint8_t g = (pixel >> 8) & 0xFF;
                uint8_t b = (pixel >> 16) & 0xFF;
                uint8_t a = (pixel >> 24) & 0xFF;

                // Modulate with vertex color
                r = (uint8_t)((r * v1.r) >> 7);
                g = (uint8_t)((g * v1.g) >> 7);
                b = (uint8_t)((b * v1.b) >> 7);
                plot_pixel(x, y, r, g, b, a);
            }
        }
    } else {
        // Flat colored sprite
        for (int y = y0; y <= y1; y++) {
            for (int x = x0; x <= x1; x++) {
                plot_pixel(x, y, v1.r, v1.g, v1.b, v1.a);
            }
        }
    }
}

void GSRenderer::rasterize_triangle(const GSVertex& v0, const GSVertex& v1, const GSVertex& v2) {
    // Bounding box
    int minx = std::max((int)std::min({v0.x, v1.x, v2.x}), m_draw.scissor_x0);
    int miny = std::max((int)std::min({v0.y, v1.y, v2.y}), m_draw.scissor_y0);
    int maxx = std::min((int)std::max({v0.x, v1.x, v2.x}), m_draw.scissor_x1);
    int maxy = std::min((int)std::max({v0.y, v1.y, v2.y}), m_draw.scissor_y1);

    // Edge function for barycentric coordinates
    float area = (v1.x - v0.x) * (v2.y - v0.y) - (v2.x - v0.x) * (v1.y - v0.y);
    if (fabsf(area) < 0.001f) return; // Degenerate triangle

    float inv_area = 1.0f / area;

    // Texture state (if TME enabled)
    uint64_t tex0 = m_regs[0x06];
    uint32_t tbp0 = (uint32_t)(tex0 & 0x3FFF);
    uint32_t tbw = (uint32_t)((tex0 >> 14) & 0x3F);
    uint32_t psm = (uint32_t)((tex0 >> 20) & 0x3F);
    uint32_t tw = 1 << ((tex0 >> 26) & 0xF);
    uint32_t th = 1 << ((tex0 >> 30) & 0xF);
    const uint32_t* vram32 = (const uint32_t*)m_vram;

    for (int y = miny; y <= maxy; y++) {
        for (int x = minx; x <= maxx; x++) {
            float px = (float)x + 0.5f;
            float py = (float)y + 0.5f;

            // Barycentric coordinates
            float w0 = ((v1.x - px) * (v2.y - py) - (v2.x - px) * (v1.y - py)) * inv_area;
            float w1 = ((v2.x - px) * (v0.y - py) - (v0.x - px) * (v2.y - py)) * inv_area;
            float w2 = 1.0f - w0 - w1;

            if (w0 < 0 || w1 < 0 || w2 < 0) continue;

            // Interpolate color
            uint8_t r, g, b, a;
            if (m_draw.gouraud) {
                r = (uint8_t)std::clamp((int)(w0 * v0.r + w1 * v1.r + w2 * v2.r), 0, 255);
                g = (uint8_t)std::clamp((int)(w0 * v0.g + w1 * v1.g + w2 * v2.g), 0, 255);
                b = (uint8_t)std::clamp((int)(w0 * v0.b + w1 * v1.b + w2 * v2.b), 0, 255);
                a = (uint8_t)std::clamp((int)(w0 * v0.a + w1 * v1.a + w2 * v2.a), 0, 255);
            } else {
                r = v0.r; g = v0.g; b = v0.b; a = v0.a;
            }

            // Texture sampling (if TME enabled in PRIM)
            if (m_draw.texture && tw > 0 && th > 0) {
                // Interpolate texture coordinates
                float s = w0 * v0.s + w1 * v1.s + w2 * v2.s;
                float t = w0 * v0.t + w1 * v1.t + w2 * v2.t;

                // Convert ST to pixel coordinates (ST are 0..1 or 0..texsize depending on context)
                // For DECAL/MODULATE mode, ST are normalized (0..1 range)
                int tu = (int)(s * tw) % (int)tw;
                int tv = (int)(t * th) % (int)th;
                if (tu < 0) tu += tw;
                if (tv < 0) tv += th;

                uint32_t pixel;
                if (psm == 0) { // PSMCT32
                    uint32_t word_addr = gs_pixel_addr32(tu, tv, tbp0, tbw);
                    pixel = vram32[word_addr];
                } else if (psm == 0x13) { // PSMT8
                    uint32_t byte_addr = gs_pixel_addr8(tu, tv, tbp0, tbw);
                    uint8_t index = m_vram[byte_addr];
                    uint32_t cbp = (uint32_t)((tex0 >> 37) & 0x3FFF);
                    uint32_t clut_byte_off = cbp * 64 + index * 4;
                    if (clut_byte_off + 4 <= sizeof(m_vram))
                        memcpy(&pixel, m_vram + clut_byte_off, 4);
                    else
                        pixel = 0;
                } else if (psm == 0x14) { // PSMT4
                    uint32_t byte_addr = gs_pixel_addr8(tu / 2, tv, tbp0, tbw);
                    uint8_t byte_val = m_vram[byte_addr];
                    uint8_t index = (tu & 1) ? (byte_val >> 4) : (byte_val & 0xF);
                    uint32_t cbp = (uint32_t)((tex0 >> 37) & 0x3FFF);
                    uint32_t clut_byte_off = cbp * 64 + index * 4;
                    if (clut_byte_off + 4 <= sizeof(m_vram))
                        memcpy(&pixel, m_vram + clut_byte_off, 4);
                    else
                        pixel = 0;
                } else {
                    pixel = 0xFF808080;
                }

                uint8_t tr = pixel & 0xFF;
                uint8_t tg = (pixel >> 8) & 0xFF;
                uint8_t tb = (pixel >> 16) & 0xFF;
                uint8_t ta = (pixel >> 24) & 0xFF;

                // Modulate: vertex color × texture (PS2 GS TFX=0)
                r = (uint8_t)((r * tr) >> 7);
                g = (uint8_t)((g * tg) >> 7);
                b = (uint8_t)((b * tb) >> 7);
                // PS2 alpha: 0x80 = fully opaque
                a = (ta >= 0x80) ? a : (uint8_t)((a * ta) >> 7);
            }

            plot_pixel(x, y, r, g, b, a);
        }
    }
}

// ── GIF path submission ─────────────────────────────────────────────

void GSRenderer::submit_path1(const void* data, uint32_t size) {
    // PATH1: VU1 → GIF → GS (via XGKICK)
    if (size < 16) return;
    process_gif_packet((const uint8_t*)data, size);
}

void GSRenderer::submit_path2(const void* data, uint32_t size) {
    // PATH2: VIF1 → GIF → GS (via DIRECT/DIRECTHL)
    if (size < 16) return;
    process_gif_packet((const uint8_t*)data, size);
}

void GSRenderer::submit_path3(const void* data, uint32_t size) {
    // PATH3: GIF DMA → GS
    if (size < 16) return;
    process_gif_packet((const uint8_t*)data, size);

    // Dump framebuffer to BMP after a few submissions for proof of life
    static int dumpCount = 0;
    if (dumpCount < 5 && m_framebuffer) {
        dumpCount++;
        if (dumpCount == 3) {
            dump_framebuffer_bmp("reo_fb_dump.bmp");
        }
    }
}

// Placed here to keep it inside the reo namespace

void GSRenderer::dump_framebuffer_bmp(const char* path) {
    if (!m_framebuffer) return;

    FILE* f = fopen(path, "wb");
    if (!f) { printf("[GS] Failed to write %s\n", path); return; }

    // BMP header
    uint32_t imgSize = m_width * m_height * 4;
    uint32_t fileSize = 54 + imgSize;
    uint8_t header[54] = {};
    header[0] = 'B'; header[1] = 'M';
    *(uint32_t*)(header + 2) = fileSize;
    *(uint32_t*)(header + 10) = 54;
    *(uint32_t*)(header + 14) = 40;
    *(int32_t*)(header + 18) = m_width;
    *(int32_t*)(header + 22) = -m_height; // Top-down
    *(uint16_t*)(header + 26) = 1;
    *(uint16_t*)(header + 28) = 32;
    fwrite(header, 1, 54, f);

    // Write BGRA pixels (BMP uses BGRA order, our framebuffer is ABGR / RGBA)
    for (int i = 0; i < m_width * m_height; i++) {
        uint32_t px = m_framebuffer[i];
        uint8_t r = px & 0xFF;
        uint8_t g = (px >> 8) & 0xFF;
        uint8_t b = (px >> 16) & 0xFF;
        uint8_t a = (px >> 24) & 0xFF;
        uint8_t bgra[4] = { b, g, r, a };
        fwrite(bgra, 1, 4, f);
    }
    fclose(f);
    printf("[GS] Framebuffer dumped to %s (%dx%d)\n", path, m_width, m_height);
}

// ── Frame control ───────────────────────────────────────────────────

void GSRenderer::begin_frame() {
    // Process Win32 messages
#ifdef _WIN32
    if (m_hwnd) {
        MSG msg;
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                // Signal exit
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }
    }
#endif
}

void GSRenderer::end_frame() {
    m_vsync_flag = true;
}

void GSRenderer::take_screenshot() {
    if (!m_framebuffer) return;

    char filename[512];
    snprintf(filename, sizeof(filename), "screenshot_%04d.png",
             s_screenshot_counter++);

    // Convert framebuffer from internal RGBA to standard RGBA for stb
    // Our format: R=bits0-7, G=bits8-15, B=bits16-23, A=bits24-31
    int pixels = m_width * m_height;
    uint8_t* rgba = (uint8_t*)malloc(pixels * 4);
    if (!rgba) return;

    for (int i = 0; i < pixels; i++) {
        uint32_t px = m_framebuffer[i];
        rgba[i * 4 + 0] = (px >>  0) & 0xFF; // R
        rgba[i * 4 + 1] = (px >>  8) & 0xFF; // G
        rgba[i * 4 + 2] = (px >> 16) & 0xFF; // B
        rgba[i * 4 + 3] = 255;                // A (force opaque)
    }

    stbi_write_png(filename, m_width, m_height, 4, rgba, m_width * 4);
    free(rgba);

    printf("Screenshot saved: %s\n", filename);
    fflush(stdout);

    // Show toast
    snprintf(s_toast_msg, sizeof(s_toast_msg), "%s", filename);
    s_toast_start = (uint32_t)(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
}

void GSRenderer::draw_toast() {
    draw_toast_to(m_framebuffer, m_width, m_height);
}

void GSRenderer::draw_toast_to(uint32_t* buf, int buf_w, int buf_h) {
    if (!buf || s_toast_msg[0] == '\0') return;

    uint32_t now = (uint32_t)(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
    uint32_t elapsed = now - s_toast_start;

    if (elapsed >= (uint32_t)TOAST_DURATION_MS) {
        s_toast_msg[0] = '\0';
        return;
    }

    // Compute alpha (fade out in last TOAST_FADE_MS)
    float alpha = 1.0f;
    if (elapsed > (uint32_t)(TOAST_DURATION_MS - TOAST_FADE_MS)) {
        alpha = (float)(TOAST_DURATION_MS - elapsed) / (float)TOAST_FADE_MS;
    }

    // Draw toast directly into framebuffer (bottom-right corner)
    // Simple bitmap text rendering — no font library needed
    const char* msg = s_toast_msg;
    int msg_len = (int)strlen(msg);
    int char_w = 6, char_h = 10;
    int text_w = msg_len * char_w;
    int box_w = text_w + TOAST_PADDING * 2;
    int box_h = char_h + TOAST_PADDING * 2;
    int box_x = buf_w - box_w - TOAST_PADDING;
    int box_y = buf_h - box_h - TOAST_PADDING;

    if (box_x < 0) box_x = 0;

    uint8_t bg_alpha = (uint8_t)(180 * alpha);
    uint8_t fg_alpha = (uint8_t)(255 * alpha);

    // Draw background box
    for (int y = box_y; y < box_y + box_h && y < buf_h; y++) {
        for (int x = box_x; x < box_x + box_w && x < buf_w; x++) {
            if (x < 0 || y < 0) continue;
            uint32_t& px = buf[y * buf_w + x];
            // Alpha blend: dst = src * alpha + dst * (1 - alpha)
            uint8_t dr = (px >> 0) & 0xFF;
            uint8_t dg = (px >> 8) & 0xFF;
            uint8_t db = (px >> 16) & 0xFF;
            float a = bg_alpha / 255.0f;
            dr = (uint8_t)(dr * (1.0f - a));
            dg = (uint8_t)(dg * (1.0f - a));
            db = (uint8_t)(db * (1.0f - a));
            px = dr | (dg << 8) | (db << 16) | 0xFF000000;
        }
    }

    // Simple 5x7 bitmap font for toast text
    // Each character is 5 columns x 7 rows, packed as 5 bytes (1 byte per column)
    static const uint8_t font_5x7[][5] = {
        // ' ' (space)
        {0x00, 0x00, 0x00, 0x00, 0x00},
        // '0'-'9'
        {0x3E, 0x51, 0x49, 0x45, 0x3E}, // 0
        {0x00, 0x42, 0x7F, 0x40, 0x00}, // 1
        {0x42, 0x61, 0x51, 0x49, 0x46}, // 2
        {0x21, 0x41, 0x45, 0x4B, 0x31}, // 3
        {0x18, 0x14, 0x12, 0x7F, 0x10}, // 4
        {0x27, 0x45, 0x45, 0x45, 0x39}, // 5
        {0x3C, 0x4A, 0x49, 0x49, 0x30}, // 6
        {0x01, 0x71, 0x09, 0x05, 0x03}, // 7
        {0x36, 0x49, 0x49, 0x49, 0x36}, // 8
        {0x06, 0x49, 0x49, 0x29, 0x1E}, // 9
        // '.', '_', 'a'-'z' (lowercase)
        {0x00, 0x60, 0x60, 0x00, 0x00}, // . (11)
        {0x40, 0x40, 0x40, 0x40, 0x40}, // _ (12)
        {0x20, 0x54, 0x54, 0x54, 0x78}, // a (13)
        {0x7F, 0x48, 0x44, 0x44, 0x38}, // b
        {0x38, 0x44, 0x44, 0x44, 0x20}, // c
        {0x38, 0x44, 0x44, 0x48, 0x7F}, // d
        {0x38, 0x54, 0x54, 0x54, 0x18}, // e
        {0x08, 0x7E, 0x09, 0x01, 0x02}, // f
        {0x0C, 0x52, 0x52, 0x52, 0x3E}, // g
        {0x7F, 0x08, 0x04, 0x04, 0x78}, // h
        {0x00, 0x44, 0x7D, 0x40, 0x00}, // i
        {0x20, 0x40, 0x44, 0x3D, 0x00}, // j
        {0x7F, 0x10, 0x28, 0x44, 0x00}, // k
        {0x00, 0x41, 0x7F, 0x40, 0x00}, // l
        {0x7C, 0x04, 0x18, 0x04, 0x78}, // m
        {0x7C, 0x08, 0x04, 0x04, 0x78}, // n
        {0x38, 0x44, 0x44, 0x44, 0x38}, // o
        {0x7C, 0x14, 0x14, 0x14, 0x08}, // p
        {0x08, 0x14, 0x14, 0x18, 0x7C}, // q
        {0x7C, 0x08, 0x04, 0x04, 0x08}, // r
        {0x48, 0x54, 0x54, 0x54, 0x20}, // s
        {0x04, 0x3F, 0x44, 0x40, 0x20}, // t
        {0x3C, 0x40, 0x40, 0x20, 0x7C}, // u
        {0x1C, 0x20, 0x40, 0x20, 0x1C}, // v
        {0x3C, 0x40, 0x30, 0x40, 0x3C}, // w
        {0x44, 0x28, 0x10, 0x28, 0x44}, // x
        {0x0C, 0x50, 0x50, 0x50, 0x3C}, // y
        {0x44, 0x64, 0x54, 0x4C, 0x44}, // z (38)
    };

    auto get_glyph = [&](char c) -> const uint8_t* {
        if (c == ' ') return font_5x7[0];
        if (c >= '0' && c <= '9') return font_5x7[1 + (c - '0')];
        if (c == '.') return font_5x7[11];
        if (c == '_') return font_5x7[12];
        if (c >= 'a' && c <= 'z') return font_5x7[13 + (c - 'a')];
        if (c >= 'A' && c <= 'Z') return font_5x7[13 + (c - 'A')]; // uppercase→lowercase
        return font_5x7[0]; // space for unknown
    };

    int tx = box_x + TOAST_PADDING;
    int ty = box_y + TOAST_PADDING;
    for (int ci = 0; ci < msg_len; ci++) {
        const uint8_t* glyph = get_glyph(msg[ci]);
        for (int col = 0; col < 5; col++) {
            uint8_t bits = glyph[col];
            for (int row = 0; row < 7; row++) {
                if (bits & (1 << row)) {
                    int px = tx + col;
                    int py = ty + row + 1; // +1 for vertical centering
                    if (px >= 0 && px < buf_w && py >= 0 && py < buf_h) {
                        buf[py * buf_w + px] =
                            fg_alpha | (fg_alpha << 8) | (fg_alpha << 16) | 0xFF000000;
                    }
                }
            }
        }
        tx += char_w;
    }
}

void GSRenderer::present() {
    // Poll F12 globally (works even in headless mode / when raylib has focus)
#ifdef _WIN32
    {
        static bool f12_was_down = false;
        bool f12_down = (GetAsyncKeyState(VK_F12) & 0x8000) != 0;
        if (f12_down && !f12_was_down)
            s_screenshot_requested = true;
        f12_was_down = f12_down;
    }
#endif

    // Process screenshot request
    if (s_screenshot_requested) {
        s_screenshot_requested = false;
        take_screenshot();
    }

    // Draw toast overlay into framebuffer
    draw_toast();

    blit_framebuffer();
}

void GSRenderer::blit_framebuffer() {
#ifdef _WIN32
    if (!m_hwnd || !m_hdc || !m_framebuffer || !m_bmp_info) return;

    SetDIBitsToDevice(
        (HDC)m_hdc,
        0, 0,
        m_width, m_height,
        0, 0,
        0, m_height,
        m_framebuffer,
        (BITMAPINFO*)m_bmp_info,
        DIB_RGB_COLORS
    );
#endif
}

const char* GSRenderer::backend_name() const {
    return "Software (GDI blit)";
}

} // namespace reo
