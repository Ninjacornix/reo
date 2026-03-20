#pragma once

#include <cstdint>
#include <vector>

namespace reo {

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

    // Vsync signal for timing
    bool vsync_triggered() const { return m_vsync_flag; }
    void clear_vsync() { m_vsync_flag = false; }

    const char* backend_name() const;

private:
    // GIF packet parsing
    GIFTag parse_gif_tag(const uint8_t* data);
    void process_gif_packet(const uint8_t* data, uint32_t size);
    void process_packed_data(const GIFTag& tag, const uint8_t* data);
    void process_reglist_data(const GIFTag& tag, const uint8_t* data);

    // Register write handling (from GIF A+D or direct register writes)
    void write_internal_reg(uint8_t reg, uint64_t value);

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

        // Frame buffer settings
        uint32_t frame_base = 0;     // VRAM base pointer for framebuffer
        uint32_t frame_width = 640;  // Framebuffer width in pixels
        uint32_t frame_psm = 0;     // Pixel storage mode

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
