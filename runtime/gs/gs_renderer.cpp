#include "gs_renderer.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif

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

    case GS_BGCOLOR: {
        uint8_t r = value & 0xFF;
        uint8_t g = (value >> 8) & 0xFF;
        uint8_t b = (value >> 16) & 0xFF;
        // Fill framebuffer with background color
        if (m_framebuffer) {
            uint32_t color = (0xFF << 24) | (b << 16) | (g << 8) | r;
            for (int i = 0; i < m_width * m_height; i++) {
                m_framebuffer[i] = color;
            }
        }
        break;
    }

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

            // Copy pixel data to GS VRAM
            if (m_transfer.dir == 0 && m_transfer.rrw > 0 && m_transfer.rrh > 0) {
                uint32_t dest = m_transfer.dbp + m_transfer.dsay * m_transfer.dbw * 4
                              + m_transfer.dsax * 4;
                uint32_t copy_size = std::min(data_size, (uint32_t)(sizeof(m_vram) - dest));
                if (dest < sizeof(m_vram) && copy_size > 0) {
                    memcpy(m_vram + dest, data + offset, copy_size);
                    static int imgLog = 0;
                    if (imgLog < 5) {
                        printf("[GS] IMAGE upload: %u bytes to VRAM@0x%X (%dx%d)\n",
                               copy_size, dest, m_transfer.rrw, m_transfer.rrh);
                        imgLog++;
                    }
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
                vtx.x = (float)(raw_x & 0xFFFF) / 16.0f;
                vtx.y = (float)(raw_y & 0xFFFF) / 16.0f;
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
                vtx.x = (float)(raw_x & 0xFFFF) / 16.0f;
                vtx.y = (float)(raw_y & 0xFFFF) / 16.0f;
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
        // Contains the offset applied to vertex coordinates
        // We handle this implicitly through the coordinate system
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
        vtx.x = (float)(value & 0xFFFF) / 16.0f;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f;
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
        vtx.x = (float)(value & 0xFFFF) / 16.0f;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f;
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
        vtx.x = (float)(value & 0xFFFF) / 16.0f;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f;
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
        vtx.x = (float)(value & 0xFFFF) / 16.0f;
        vtx.y = (float)((value >> 16) & 0xFFFF) / 16.0f;
        vtx.z = (float)((value >> 32) & 0xFFFFFFFF) / (float)0xFFFFFFFF;
        vtx.r = m_draw.r; vtx.g = m_draw.g; vtx.b = m_draw.b; vtx.a = m_draw.a;
        vtx.s = m_draw.s; vtx.t = m_draw.t; vtx.q = m_draw.q;
        vtx.fog = m_draw.fog_val;
        vtx.drawing_kick = false;
        submit_vertex(vtx);
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
        // TEX0 register has texture base, width, format
        uint64_t tex0 = m_regs[0x06];
        uint32_t tbp0 = (uint32_t)(tex0 & 0x3FFF) * 64;  // Texture base (bytes)
        uint32_t tbw = (uint32_t)((tex0 >> 14) & 0x3F) * 64; // Tex buffer width (pixels)
        uint32_t tw = 1 << ((tex0 >> 26) & 0xF); // Texture width
        uint32_t th = 1 << ((tex0 >> 30) & 0xF); // Texture height
        if (tw == 0) tw = 1;
        if (th == 0) th = 1;
        if (tbw == 0) tbw = tw;

        float u0 = v0.s, v0t = v0.t;
        float u1 = v1.s, v1t = v1.t;

        int sx = x1 - x0;
        int sy = y1 - y0;
        if (sx <= 0 || sy <= 0) return;

        for (int y = y0; y <= y1; y++) {
            float ft = (sy > 0) ? (float)(y - y0) / (float)sy : 0;
            for (int x = x0; x <= x1; x++) {
                float fs = (sx > 0) ? (float)(x - x0) / (float)sx : 0;
                int tu = (int)(u0 + fs * (u1 - u0)) & (tw - 1);
                int tv = (int)(v0t + ft * (v1t - v0t)) & (th - 1);

                // Sample PSMCT32 texture from VRAM
                uint32_t vram_off = tbp0 + (tv * tbw + tu) * 4;
                if (vram_off + 4 <= sizeof(m_vram)) {
                    uint8_t r = m_vram[vram_off];
                    uint8_t g = m_vram[vram_off + 1];
                    uint8_t b = m_vram[vram_off + 2];
                    uint8_t a = m_vram[vram_off + 3];
                    // Modulate with vertex color
                    r = (uint8_t)((r * v1.r) >> 7);
                    g = (uint8_t)((g * v1.g) >> 7);
                    b = (uint8_t)((b * v1.b) >> 7);
                    plot_pixel(x, y, r, g, b, a);
                }
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
                // Flat shading: use first vertex color
                r = v0.r; g = v0.g; b = v0.b; a = v0.a;
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

void GSRenderer::present() {
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
