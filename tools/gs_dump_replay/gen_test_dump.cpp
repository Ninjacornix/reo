/*
 * Generate a synthetic GS dump for testing the replay tool.
 *
 * Creates a minimal .gs dump that draws:
 *   - A blue background
 *   - A red triangle
 *   - A green sprite (rectangle)
 *
 * This validates the full pipeline: file parsing → GIF tag processing →
 * vertex submission → rasterization → BMP output.
 *
 * Build: cl gen_test_dump.cpp /Fe:gen_test_dump.exe
 * Run:   gen_test_dump.exe test_dump.gs
 *        reo-gs-replay.exe test_dump.gs --verbose
 */

#include <cstdio>
#include <cstring>
#include <cstdint>

static FILE* g_file;

static void write_u8(uint8_t v) { fwrite(&v, 1, 1, g_file); }
static void write_u32(uint32_t v) { fwrite(&v, 4, 1, g_file); }
static void write_u64(uint64_t v) { fwrite(&v, 8, 1, g_file); }

// Build a GIF tag (128 bits)
static void write_gif_tag(uint32_t nloop, bool eop, bool pre, uint16_t prim,
                           uint8_t flg, uint8_t nreg, uint64_t regs) {
    uint64_t lo = 0;
    lo |= (uint64_t)(nloop & 0x7FFF);
    lo |= (uint64_t)(eop ? 1 : 0) << 15;
    lo |= (uint64_t)(pre ? 1 : 0) << 46;
    lo |= (uint64_t)(prim & 0x7FF) << 47;
    lo |= (uint64_t)(flg & 0x3) << 58;
    lo |= (uint64_t)(nreg & 0xF) << 60;
    write_u64(lo);
    write_u64(regs);
}

// Build an A+D register write (128 bits: data[64] + addr[8] + pad[56])
static void write_ad(uint8_t reg, uint64_t data) {
    write_u64(data);
    write_u64((uint64_t)reg);
}

// Build a PACKED RGBAQ (128 bits)
static void write_rgbaq(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    // PACKED RGBAQ: R[7:0] at byte 0, G[7:0] at byte 4, B[7:0] at byte 8, A[7:0] at byte 12
    uint32_t rr = r, gg = g, bb = b, aa = a;
    write_u32(rr);
    write_u32(gg);
    write_u32(bb);
    write_u32(aa);  // A + Q (Q=1.0f in upper bits, but A is what matters)
}

// Build a PACKED XYZ2 (128 bits) — triggers drawing kick
static void write_xyz2(float x, float y, float z) {
    // PACKED XYZ2: X as 16.4 fixed point in lower 16 bits of dword 0
    //              Y as 16.4 fixed point in lower 16 bits of dword 1
    //              Z as 32-bit uint in dword 2
    uint32_t fx = (uint32_t)(x * 16.0f) & 0xFFFF;
    uint32_t fy = (uint32_t)(y * 16.0f) & 0xFFFF;
    uint32_t fz = (uint32_t)(z * (float)0xFFFFFFFF);
    write_u32(fx);
    write_u32(fy);
    write_u32(fz);
    write_u32(0);
}

int main(int argc, char* argv[]) {
    const char* path = (argc > 1) ? argv[1] : "test_dump.gs";

    g_file = fopen(path, "wb");
    if (!g_file) {
        printf("Cannot open %s\n", path);
        return 1;
    }

    // ── GS Dump Header ─────────────────────────────────────
    write_u32(0xDEADBEEF);  // CRC (dummy)
    write_u32(0);            // state_size = 0 (no frozen state)

    // ── Record 1: Set up registers via PATH3 A+D mode ─────
    // GIF tag: nloop=4 (4 register writes), flg=0 (PACKED), nreg=1, reg=AD(0xE)
    write_u8(0);  // type = Transfer
    write_u8(2);  // path = PATH3

    // Calculate transfer size: 16 (tag) + 4 * 16 (4 packed AD writes) = 80 bytes
    write_u32(80);

    // GIF tag: 4 iterations, EOP, PACKED mode, 1 reg per loop, reg = A+D
    write_gif_tag(4, true, false, 0, 0, 1, 0x0E);

    // Write SCISSOR_1 (reg 0x40): x0=0, x1=639, y0=0, y1=447
    uint64_t scissor = (uint64_t)0 | ((uint64_t)639 << 16) |
                       ((uint64_t)0 << 32) | ((uint64_t)447 << 48);
    write_ad(0x40, scissor);

    // Write FRAME_1 (reg 0x4C): base=0, width=10 (640/64), psm=0 (PSMCT32)
    uint64_t frame = (uint64_t)0 | ((uint64_t)10 << 16) | ((uint64_t)0 << 24);
    write_ad(0x4C, frame);

    // Write XYOFFSET_1 (reg 0x18): offset applied to vertices
    // Typically (2048<<4, 2048<<4) but we use (0,0) for simplicity
    write_ad(0x18, 0);

    // Write ZBUF_1 (reg 0x4E): z-buffer setup
    write_ad(0x4E, 0);

    // ── Record 2: Draw a red triangle via PATH3 ────────────
    // PRIM = Triangle (3), Gouraud OFF, no texture, no fog, no alpha
    write_u8(0);  // type = Transfer
    write_u8(2);  // path = PATH3

    // GIF tag: 3 vertices, PACKED mode, 2 regs (RGBAQ + XYZ2), pre=1 prim=Triangle(3)
    // nloop=3, nreg=2, regs = RGBAQ(0x01) + XYZ2(0x05) = 0x51
    // Transfer size: 16 (tag) + 3 * 2 * 16 (3 loops, 2 regs, 16 bytes each) = 112 bytes
    write_u32(112);

    // PRIM value for triangle: type=3 (triangle), IIP=0 (flat), rest=0
    write_gif_tag(3, true, true, 3, 0, 2, 0x51);

    // Vertex 0: Red at (200, 100)
    write_rgbaq(255, 0, 0, 128);
    write_xyz2(200.0f, 100.0f, 0.0f);

    // Vertex 1: Red at (400, 350)
    write_rgbaq(255, 0, 0, 128);
    write_xyz2(400.0f, 350.0f, 0.0f);

    // Vertex 2: Red at (100, 350)
    write_rgbaq(255, 0, 0, 128);
    write_xyz2(100.0f, 350.0f, 0.0f);

    // ── Record 3: Draw a green sprite (rectangle) ──────────
    write_u8(0);  // type = Transfer
    write_u8(2);  // path = PATH3

    // Sprite needs 2 vertices, PRIM=6 (sprite)
    // nloop=2, nreg=2, regs = RGBAQ + XYZ2
    // Transfer size: 16 + 2*2*16 = 80 bytes
    write_u32(80);

    write_gif_tag(2, true, true, 6, 0, 2, 0x51);

    // Corner 0: Green at (450, 50)
    write_rgbaq(0, 255, 0, 128);
    write_xyz2(450.0f, 50.0f, 0.0f);

    // Corner 1: Green at (600, 200)
    write_rgbaq(0, 255, 0, 128);
    write_xyz2(600.0f, 200.0f, 0.0f);

    // ── Record 4: VSync ────────────────────────────────────
    write_u8(1);  // type = VSync
    write_u8(0);  // field = 0

    // ── Record 5: Second frame — draw a blue sprite for background ──
    write_u8(0);
    write_u8(2);
    write_u32(80);
    write_gif_tag(2, true, true, 6, 0, 2, 0x51);
    write_rgbaq(40, 40, 180, 128);
    write_xyz2(0.0f, 0.0f, 0.0f);
    write_rgbaq(40, 40, 180, 128);
    write_xyz2(640.0f, 448.0f, 0.0f);

    // Draw a white triangle on top
    write_u8(0);
    write_u8(2);
    write_u32(112);
    write_gif_tag(3, true, true, 3, 0, 2, 0x51);
    write_rgbaq(255, 255, 255, 128);
    write_xyz2(320.0f, 50.0f, 0.0f);
    write_rgbaq(255, 255, 255, 128);
    write_xyz2(500.0f, 400.0f, 0.0f);
    write_rgbaq(255, 255, 255, 128);
    write_xyz2(140.0f, 400.0f, 0.0f);

    // VSync frame 2
    write_u8(1);
    write_u8(0);

    fclose(g_file);

    printf("Generated test GS dump: %s\n", path);
    printf("  Frame 1: red triangle + green sprite on black background\n");
    printf("  Frame 2: white triangle on blue background\n");
    return 0;
}
