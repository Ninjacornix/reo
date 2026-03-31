#pragma once

#include <cstdint>
#include <vector>

namespace reo {

// ── PS2 GS PSMCT32 VRAM Swizzle Tables ────────────────────────────
// The GS stores pixels in a block-swizzled layout, not linearly.
// Pages = 64x32 pixels (8192 bytes), Blocks = 8x8 pixels (256 bytes)

// Block layout within a page (4 rows x 8 cols = 32 blocks)
static const uint8_t gs_blockTable32[4][8] = {
    {  0,  1,  4,  5, 16, 17, 20, 21 },
    {  2,  3,  6,  7, 18, 19, 22, 23 },
    {  8,  9, 12, 13, 24, 25, 28, 29 },
    { 10, 11, 14, 15, 26, 27, 30, 31 }
};

// Pixel layout within an 8x8 block (word index 0-63)
static const uint8_t gs_columnTable32[8][8] = {
    {  0,  1,  4,  5,  8,  9, 12, 13 },
    {  2,  3,  6,  7, 10, 11, 14, 15 },
    { 16, 17, 20, 21, 24, 25, 28, 29 },
    { 18, 19, 22, 23, 26, 27, 30, 31 },
    { 32, 33, 36, 37, 40, 41, 44, 45 },
    { 34, 35, 38, 39, 42, 43, 46, 47 },
    { 48, 49, 52, 53, 56, 57, 60, 61 },
    { 50, 51, 54, 55, 58, 59, 62, 63 }
};

// Get VRAM word address for pixel (x,y) in PSMCT32 format
// bp = base pointer in 64-byte block units, bw = buffer width in 64-pixel units
inline uint32_t gs_pixel_addr32(int x, int y, uint32_t bp, uint32_t bw) {
    uint32_t block = bp
        + (y & ~0x1F) * bw
        + ((x >> 1) & ~0x1F)
        + gs_blockTable32[(y >> 3) & 3][(x >> 3) & 7];
    return ((block << 6) + gs_columnTable32[y & 7][x & 7]) & (1024 * 1024 - 1);
}

// Deswizzle PSMCT32 VRAM region to linear pixel buffer
inline void gs_psmct32_deswizzle(const uint32_t* vram, uint32_t* out,
                                  uint32_t bp, uint32_t bw, int w, int h) {
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            out[y * w + x] = vram[gs_pixel_addr32(x, y, bp, bw)];
}

// Swizzle linear pixels into PSMCT32 VRAM
inline void gs_psmct32_swizzle(uint32_t* vram, const uint32_t* src,
                                uint32_t bp, uint32_t bw, int w, int h) {
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            vram[gs_pixel_addr32(x, y, bp, bw)] = src[y * w + x];
}

// ── PS2 GS PSMT8 (8-bit indexed) VRAM Swizzle Tables ──────────────
// PSMT8 uses 16x4 pixel blocks (64 bytes each), different layout from PSMCT32

// Block layout within a page (8 rows x 4 cols = 32 blocks)
static const uint8_t gs_blockTable8[8][4] = {
    {  0,  1,  4,  5 },
    {  2,  3,  6,  7 },
    {  8,  9, 12, 13 },
    { 10, 11, 14, 15 },
    { 16, 17, 20, 21 },
    { 18, 19, 22, 23 },
    { 24, 25, 28, 29 },
    { 26, 27, 30, 31 }
};

// Pixel layout within a 16x4 block (byte index 0-63)
static const uint8_t gs_columnTable8[4][16] = {
    {  0,  4,  8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60 },
    {  1,  5,  9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61 },
    {  2,  6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62 },
    {  3,  7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63 }
};

// Get VRAM byte address for pixel (x,y) in PSMT8 format
// bp = base pointer in 64-byte block units, bw = buffer width in 64-pixel units
inline uint32_t gs_pixel_addr8(int x, int y, uint32_t bp, uint32_t bw) {
    // PSMT8: pages are 128x64 pixels, blocks are 16x4 pixels
    uint32_t page_x = x / 128;
    uint32_t page_y = y / 64;
    uint32_t page = bp / 32 + page_y * bw + page_x;

    uint32_t px = x - page_x * 128;
    uint32_t py = y - page_y * 64;

    uint32_t block_x = px / 16;
    uint32_t block_y = py / 4;
    uint32_t block = gs_blockTable8[block_y & 7][block_x & 3];

    uint32_t col = gs_columnTable8[py & 3][px & 15];

    return ((page * 32 + block) * 64 + col) & (4 * 1024 * 1024 - 1);
}

/*
 * Graphics Synthesizer Renderer
 *
 * Replaces the PS2 GS with a modern GPU renderer.
 * The GS was a fixed-function rasterizer that received primitives from
 * VU1 (via PATH1/XGKICK), VIF1 (PATH2/DIRECT), or DMA (PATH3).
 *
 * We intercept GS register writes (at 0x12000000+) and GIF packet
 * submissions, convert them to modern draw calls, and render.
 *
 * Current backend: Software framebuffer → Win32 window (GDI blit)
 * Future: Vulkan or paraLLEl-GS for pixel-accurate rendering
 */

// GS privileged register offsets (at 0x12000000)
constexpr uint32_t GS_PMODE    = 0x0000;
constexpr uint32_t GS_SMODE1   = 0x0010;
constexpr uint32_t GS_SMODE2   = 0x0020;
constexpr uint32_t GS_SRFSH    = 0x0030;
constexpr uint32_t GS_SYNCH1   = 0x0040;
constexpr uint32_t GS_SYNCH2   = 0x0050;
constexpr uint32_t GS_SYNCV    = 0x0060;
constexpr uint32_t GS_DISPFB1  = 0x0070;
constexpr uint32_t GS_DISPLAY1 = 0x0080;
constexpr uint32_t GS_DISPFB2  = 0x0090;
constexpr uint32_t GS_DISPLAY2 = 0x00A0;
constexpr uint32_t GS_EXTBUF   = 0x00B0;
constexpr uint32_t GS_EXTDATA  = 0x00C0;
constexpr uint32_t GS_EXTWRITE = 0x00D0;
constexpr uint32_t GS_BGCOLOR  = 0x00E0;
constexpr uint32_t GS_CSR      = 0x1000;
constexpr uint32_t GS_IMR      = 0x1010;
constexpr uint32_t GS_BUSDIR   = 0x1040;
constexpr uint32_t GS_SIGLBLID = 0x1080;

// GIF tag register addresses (set via A+D mode in GIF packets)
// These are "general purpose" registers selected by the GIF tag's REG field
constexpr uint8_t GIF_REG_PRIM    = 0x00;
constexpr uint8_t GIF_REG_RGBAQ   = 0x01;
constexpr uint8_t GIF_REG_ST      = 0x02;
constexpr uint8_t GIF_REG_UV      = 0x03;
constexpr uint8_t GIF_REG_XYZF2   = 0x04;
constexpr uint8_t GIF_REG_XYZ2    = 0x05;
constexpr uint8_t GIF_REG_TEX0_1  = 0x06;
constexpr uint8_t GIF_REG_TEX0_2  = 0x07;
constexpr uint8_t GIF_REG_FOG     = 0x0A;
constexpr uint8_t GIF_REG_XYZF3   = 0x0C;
constexpr uint8_t GIF_REG_XYZ3    = 0x0D;
constexpr uint8_t GIF_REG_AD      = 0x0E;
constexpr uint8_t GIF_REG_NOP     = 0x0F;

// PS2 GS primitive types
enum class GSPrimType : uint8_t {
    Point        = 0,
    Line         = 1,
    LineStrip    = 2,
    Triangle     = 3,
    TriangleStrip = 4,
    TriangleFan  = 5,
    Sprite       = 6,
};

// Vertex as submitted to GS
struct GSVertex {
    float x, y, z;     // Position (GS coordinates: 16.4 fixed → float)
    float s, t, q;     // Texture coordinates
    uint8_t r, g, b, a; // Color
    float fog;
    bool drawing_kick;  // This vertex completes a primitive
};

// GIF tag structure (128 bits)
struct GIFTag {
    uint32_t nloop;     // Number of data iterations
    bool eop;           // End of packet
    bool pre;           // PRIM field enable
    uint16_t prim;      // PRIM register value (if pre=1)
    uint8_t flg;        // Data format: 0=PACKED, 1=REGLIST, 2=IMAGE, 3=DISABLE
    uint8_t nreg;       // Number of registers per iteration
    uint64_t regs;      // Register descriptor list (4 bits each, up to 16)
};

class GSRenderer {
public:
    GSRenderer() = default;
    ~GSRenderer() = default;

    bool init(int width, int height, bool fullscreen, bool headless = false);
    void shutdown();

    // Access the raw framebuffer (RGBA8888, width * height pixels)
    const uint32_t* framebuffer() const { return m_framebuffer; }
    uint32_t* framebuffer_mut() { return m_framebuffer; }
    int fb_width() const { return m_width; }
    int fb_height() const { return m_height; }

    // Access VRAM (4MB, same as PS2 GS)
    uint8_t* vram() { return m_vram; }
    const uint8_t* vram() const { return m_vram; }
    static constexpr uint32_t VRAM_SIZE = 4 * 1024 * 1024;

    // GS register access (from MMIO at 0x12000000)
    uint64_t read_register(uint32_t offset);
    void write_register(uint32_t offset, uint64_t value);

    // GIF packet submission (the 3 paths)
    void submit_path1(const void* data, uint32_t size);  // From VU1 XGKICK
    void submit_path2(const void* data, uint32_t size);  // From VIF1 DIRECT
    void submit_path3(const void* data, uint32_t size);  // From GIF DMA

    // Frame control
    void begin_frame();
    void end_frame();
    void present();

    // Screenshot (F12) — saves PNG + shows toast
    void take_screenshot();
    void draw_toast();
    // Draw toast into an external pixel buffer (for overlay compositing)
    void draw_toast_to(uint32_t* buf, int buf_w, int buf_h);

    // Vsync signal for timing
    bool vsync_triggered() const { return m_vsync_flag; }
    void clear_vsync() { m_vsync_flag = false; }

    const char* backend_name() const;

    // Register write handling (from GIF A+D or direct register writes)
    void write_internal_reg(uint8_t reg, uint64_t value);

private:
    // GIF packet parsing
    GIFTag parse_gif_tag(const uint8_t* data);
    void process_gif_packet(const uint8_t* data, uint32_t size);
    void process_packed_data(const GIFTag& tag, const uint8_t* data);
    void process_reglist_data(const GIFTag& tag, const uint8_t* data);

    // Vertex / primitive submission
    void submit_vertex(const GSVertex& vtx);
    void kick_primitive();

    // Software rasterizer
    void rasterize_triangle(const GSVertex& v0, const GSVertex& v1, const GSVertex& v2);
    void rasterize_sprite(const GSVertex& v0, const GSVertex& v1);
    void plot_pixel(int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void dump_framebuffer_bmp(const char* path);

    // Win32 window management
    bool create_window();
    void blit_framebuffer();

    int m_width = 640;
    int m_height = 448;
    bool m_fullscreen = false;
    bool m_vsync_flag = false;

    // GS register state (privileged)
    uint64_t m_regs[256] = {};

    // VRAM (4MB, same as PS2 GS)
    uint8_t m_vram[4 * 1024 * 1024] = {};

    // Software framebuffer (RGBA8888, native resolution)
    uint32_t* m_framebuffer = nullptr;

    // Current GS drawing state (set by register writes from GIF packets)
    struct {
        GSPrimType prim_type = GSPrimType::Triangle;
        bool gouraud = true;
        bool texture = false;
        bool fog = false;
        bool aa = false;
        bool alpha_blend = false;

        // Current color/texcoord being built
        uint8_t r = 128, g = 128, b = 128, a = 128;
        float s = 0, t = 0, q = 1.0f;
        float fog_val = 0;

        // XY offset (subtracted from vertex coordinates)
        float offset_x = 0;
        float offset_y = 0;

        // Texture state
        uint32_t tex_base = 0;       // TEX0 base pointer in VRAM (bytes)
        uint32_t tex_width = 0;      // Texture buffer width (pixels)
        uint32_t tex_w = 0;          // Texture width (pixels)
        uint32_t tex_h = 0;          // Texture height (pixels)

        // Frame buffer settings
        uint32_t frame_base = 0;     // VRAM base pointer for framebuffer
        uint32_t frame_width = 640;  // Framebuffer width in pixels
        uint32_t frame_psm = 0;     // Pixel storage mode

        // Alpha test (TEST_1 register)
        bool alpha_test_enable = false;
        uint8_t alpha_test_method = 1;   // 0=NEVER 1=ALWAYS 2=LESS 3=LEQUAL 4=EQUAL 5=GEQUAL 6=GREATER 7=NOTEQUAL
        uint8_t alpha_test_ref = 0;
        uint8_t alpha_test_fail = 0;     // 0=KEEP 1=FB_ONLY 2=ZB_ONLY 3=RGB_ONLY

        // Scissor
        int scissor_x0 = 0, scissor_y0 = 0;
        int scissor_x1 = 639, scissor_y1 = 447;

        // Vertex buffer for building primitives
        GSVertex vtx_buf[4];
        int vtx_count = 0;
        int vtx_kick = 0;  // How many vertices needed to complete a primitive
    } m_draw;

    // VRAM transfer state (BITBLTBUF/TRXPOS/TRXREG/TRXDIR)
    struct {
        uint32_t dbp = 0;    // Dest base pointer (bytes)
        uint32_t dbw = 0;    // Dest buffer width (pixels)
        uint32_t dpsm = 0;   // Dest pixel storage mode
        int dsax = 0;        // Dest X position
        int dsay = 0;        // Dest Y position
        int rrw = 0;         // Transfer width
        int rrh = 0;         // Transfer height
        int dir = 0;         // Direction (0=host→local)
    } m_transfer;

    // Win32 handles
    void* m_hwnd = nullptr;       // HWND
    void* m_hdc = nullptr;        // HDC (for GDI blitting)
    void* m_bmp_info = nullptr;   // BITMAPINFO*
};

} // namespace reo
