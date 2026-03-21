/*
 * GS Dump Replay Tool
 *
 * Reads PCSX2 GS dump files (.gs) and replays them through the REO
 * GSRenderer, saving each frame as a BMP file.
 *
 * This validates the GS renderer pipeline independently of the recompiled
 * game code — feeding it known-good GIF packets captured from PCSX2.
 *
 * Usage:
 *   reo-gs-replay <dump.gs> [--out-dir <dir>] [--max-frames N] [--verbose]
 *
 * PCSX2 GS dump capture:
 *   In PCSX2, press Shift+F8 while running a game to start/stop recording.
 *   The dump is saved to the PCSX2 snaps/ directory as a .gs file.
 *
 * PCSX2 GS Dump format (v2.x, new header):
 *   If first u32 == 0xFFFFFFFF:
 *     uint32_t marker           = 0xFFFFFFFF (new format)
 *     uint32_t blob_size        - Size of header blob
 *     GSDumpHeader header_blob  - Contains: struct fields + serial + screenshot
 *     uint8_t  state[header.state_size] - Real frozen GS state (regs + 4MB VRAM)
 *     uint8_t  initial_regs[8192]       - GS internal register file
 *   Else (legacy):
 *     uint32_t crc
 *     uint32_t state_size
 *     uint8_t  state[state_size]
 *     uint8_t  initial_regs[8192]
 *   Records (repeated until EOF):
 *     uint8_t type
 *       0 = Transfer: uint8_t path (0=PATH1old,1=PATH2,2=PATH3,3=PATH1new), uint32_t size, data[size]
 *       1 = VSync:    uint8_t field
 *       2 = ReadFIFO: uint32_t size
 *       3 = Registers: 8192 bytes (GS internal register state)
 */

#include "runtime/gs/gs_renderer.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

// ── BMP writer ──────────────────────────────────────────────────────

static bool write_bmp(const char* path, const uint32_t* pixels, int width, int height) {
    FILE* f = fopen(path, "wb");
    if (!f) return false;

    uint32_t row_size = width * 3;
    uint32_t row_padded = (row_size + 3) & ~3;
    uint32_t pixel_size = row_padded * height;
    uint32_t file_size = 54 + pixel_size;

    uint8_t header[54] = {};
    header[0] = 'B'; header[1] = 'M';
    memcpy(header + 2, &file_size, 4);
    uint32_t offset = 54;
    memcpy(header + 10, &offset, 4);

    uint32_t dib_size = 40;
    memcpy(header + 14, &dib_size, 4);
    memcpy(header + 18, &width, 4);
    int neg_height = -height; // Top-down
    memcpy(header + 22, &neg_height, 4);
    uint16_t planes = 1;
    memcpy(header + 26, &planes, 2);
    uint16_t bpp = 24;
    memcpy(header + 28, &bpp, 2);

    fwrite(header, 1, 54, f);

    // Write pixel data (BGR, padded rows)
    std::vector<uint8_t> row(row_padded, 0);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uint32_t px = pixels[y * width + x];
            row[x * 3 + 0] = (px >> 16) & 0xFF; // B
            row[x * 3 + 1] = (px >> 8)  & 0xFF;  // G
            row[x * 3 + 2] =  px         & 0xFF;  // R
        }
        fwrite(row.data(), 1, row_padded, f);
    }

    fclose(f);
    return true;
}

// ── PCSX2 v2.x GSDumpHeader ────────────────────────────────────────

struct PCSX2DumpHeader {
    uint32_t state_version;
    uint32_t state_size;       // Uncompressed state size (regs + 4MB VRAM)
    uint32_t serial_offset;
    uint32_t serial_size;
    uint32_t crc;
    uint32_t screenshot_width;
    uint32_t screenshot_height;
    uint32_t screenshot_offset;
    uint32_t screenshot_size;
};

// ── GS Dump reader ──────────────────────────────────────────────────

enum GsDumpRecordType : uint8_t {
    RECORD_TRANSFER  = 0,
    RECORD_VSYNC     = 1,
    RECORD_READFIFO  = 2,
    RECORD_REGISTERS = 3,
};

// PCSX2 v2.x transfer paths
enum GsDumpPath : uint8_t {
    PATH1_OLD = 0,
    PATH2     = 1,
    PATH3     = 2,
    PATH1_NEW = 3,
};

struct GsDumpStats {
    uint64_t transfers[4] = {};  // PATH1old, PATH2, PATH3, PATH1new
    uint64_t transfer_bytes[4] = {};
    uint64_t vsyncs = 0;
    uint64_t reg_writes = 0;
    uint64_t frames_saved = 0;
};

static bool read_u8(FILE* f, uint8_t* out) {
    return fread(out, 1, 1, f) == 1;
}

static bool read_u32(FILE* f, uint32_t* out) {
    return fread(out, 4, 1, f) == 1;
}

// Apply GS privileged register space (8192 bytes = PS2 GS regs at 0x12000000-0x12001FFF)
// PCSX2 stores this as 512 entries x 16 bytes, mapped to register offsets 0x0000-0x1FF0.
// Key registers: PMODE(0x00), DISPFB1(0x70), DISPLAY1(0x80), BGCOLOR(0xE0), CSR(0x1000)
static void apply_initial_regs(reo::GSRenderer& gs, const uint8_t* regs, bool verbose) {
    printf("[GS-REPLAY] Applying privileged register space (8192 bytes)\n");

    int applied = 0;
    for (int i = 0; i < 512; i++) {
        uint64_t lo;
        memcpy(&lo, regs + i * 16, 8);

        if (lo == 0) continue;

        uint32_t offset = i * 0x10;  // Privileged register offset
        gs.write_register(offset, lo);
        applied++;

        if (verbose && applied <= 20) {
            const char* name = "?";
            switch (offset) {
            case 0x0000: name = "PMODE"; break;
            case 0x0010: name = "SMODE1"; break;
            case 0x0020: name = "SMODE2"; break;
            case 0x0070: name = "DISPFB1"; break;
            case 0x0080: name = "DISPLAY1"; break;
            case 0x0090: name = "DISPFB2"; break;
            case 0x00A0: name = "DISPLAY2"; break;
            case 0x00E0: name = "BGCOLOR"; break;
            case 0x1000: name = "CSR"; break;
            }
            printf("  [0x%04X] %-10s = 0x%016llX\n", offset, name, (unsigned long long)lo);
        }
    }
    printf("[GS-REPLAY]   Applied %d non-zero registers\n", applied);
}

// Load VRAM from frozen state.
// The freeze state format (version 9): first ~509 bytes are GS environment,
// then 4MB of VRAM data follows.
static void load_frozen_state(reo::GSRenderer& gs, const uint8_t* state, uint32_t state_size) {
    constexpr uint32_t VRAM_SIZE = reo::GSRenderer::VRAM_SIZE; // 4MB

    if (state_size <= VRAM_SIZE) {
        printf("[GS-REPLAY] State too small for VRAM (%u bytes)\n", state_size);
        return;
    }

    uint32_t env_size = state_size - VRAM_SIZE;
    printf("[GS-REPLAY] Frozen state: %u bytes env + %u bytes VRAM\n", env_size, VRAM_SIZE);

    // Load VRAM
    memcpy(gs.vram(), state + env_size, VRAM_SIZE);

    // Count non-zero VRAM bytes for diagnostic
    int nonzero_pages = 0;
    for (uint32_t page = 0; page < VRAM_SIZE; page += 8192) {
        bool has_data = false;
        for (uint32_t j = 0; j < 8192 && !has_data; j += 4) {
            uint32_t val;
            memcpy(&val, gs.vram() + page + j, 4);
            if (val != 0 && val != 0xFF000000) has_data = true;
        }
        if (has_data) nonzero_pages++;
    }
    printf("[GS-REPLAY]   VRAM: %d/%d 8KB pages with data\n",
           nonzero_pages, VRAM_SIZE / 8192);

    // Parse environment block for privileged registers
    // The env block starts with some version/flag fields, then has
    // register-like data. Apply known privileged register offsets.
    if (env_size >= 0x30) {
        // Try to find PMODE, DISPFB1, DISPLAY1, BGCOLOR in the env
        // These are at specific offsets in the PCSX2 freeze format
        // but the exact layout varies. We'll rely on the initial_regs
        // block for internal registers instead.
        printf("[GS-REPLAY]   Environment block: %u bytes (privileged regs)\n", env_size);
    }

    // Verify texture VRAM content with swizzle
    {
        const uint32_t* vram32 = (const uint32_t*)gs.vram();
        // TBP0=10784, TBW=8, read pixel (100,100)
        uint32_t test_addr = reo::gs_pixel_addr32(100, 100, 10784, 8);
        uint32_t test_pixel = vram32[test_addr];
        printf("[GS-REPLAY]   VRAM verify: pixel(100,100) at TBP0=10784 TBW=8 → addr=%u pixel=0x%08X\n",
               test_addr, test_pixel);
        // Also check a few more
        for (int ty = 0; ty < 448; ty += 100) {
            uint32_t addr = reo::gs_pixel_addr32(256, ty, 10784, 8);
            uint32_t px = vram32[addr];
            uint8_t r = px & 0xFF, g = (px >> 8) & 0xFF, b = (px >> 16) & 0xFF;
            printf("[GS-REPLAY]     tex(256,%d): R=%u G=%u B=%u (addr=%u)\n", ty, r, g, b, addr);
        }
    }
}

// Extract framebuffer from VRAM using swizzled addressing
// bp = base pointer in 64-byte block units, bw = buffer width in 64-pixel units
static void extract_fb_from_vram(reo::GSRenderer& gs, uint32_t bp, uint32_t bw,
                                  int width, int height) {
    const uint32_t* vram32 = (const uint32_t*)gs.vram();
    uint32_t* fb = gs.framebuffer_mut();
    if (!fb || !vram32) return;

    int fb_w = gs.fb_width();
    int fb_h = gs.fb_height();
    int copy_w = (width > 0 && width < fb_w) ? width : fb_w;
    int copy_h = (height > 0 && height < fb_h) ? height : fb_h;
    if (bw == 0) bw = 1;

    for (int y = 0; y < copy_h; y++) {
        for (int x = 0; x < copy_w; x++) {
            uint32_t word_addr = reo::gs_pixel_addr32(x, y, bp, bw);
            uint32_t pixel = vram32[word_addr];

            // VRAM stores RGBA, our framebuffer uses ABGR
            uint8_t r = pixel & 0xFF;
            uint8_t g = (pixel >> 8) & 0xFF;
            uint8_t b = (pixel >> 16) & 0xFF;
            uint8_t a = (pixel >> 24) & 0xFF;

            fb[y * fb_w + x] = (a << 24) | (b << 16) | (g << 8) | r;
        }
    }
}

// ── Main ────────────────────────────────────────────────────────────

static void print_usage(const char* prog) {
    printf("Usage: %s <dump.gs> [options]\n", prog);
    printf("Options:\n");
    printf("  --out-dir <dir>     Output directory for BMP frames (default: gs_frames)\n");
    printf("  --max-frames <N>    Stop after N frames (default: 30)\n");
    printf("  --verbose           Print detailed transfer info\n");
    printf("  --stats-only        Print stats without saving frames\n");
    printf("  --width <W>         Framebuffer width (default: 640)\n");
    printf("  --height <H>        Framebuffer height (default: 448)\n");
    printf("  --vram-frame        Extract framebuffer from VRAM instead of software FB\n");
    printf("\nCapture a GS dump in PCSX2 by pressing Shift+F8 during gameplay.\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    const char* dump_path = argv[1];
    std::string out_dir = "gs_frames";
    int max_frames = 30;
    bool verbose = false;
    bool stats_only = false;
    int fb_width = 640;
    int fb_height = 448;
    bool vram_frame = false;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "--out-dir") == 0 && i + 1 < argc) {
            out_dir = argv[++i];
        } else if (strcmp(argv[i], "--max-frames") == 0 && i + 1 < argc) {
            max_frames = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--verbose") == 0) {
            verbose = true;
        } else if (strcmp(argv[i], "--stats-only") == 0) {
            stats_only = true;
        } else if (strcmp(argv[i], "--width") == 0 && i + 1 < argc) {
            fb_width = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--height") == 0 && i + 1 < argc) {
            fb_height = atoi(argv[++i]);
        } else if (strcmp(argv[i], "--vram-frame") == 0) {
            vram_frame = true;
        } else {
            printf("Unknown option: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }

    // Open dump file
    FILE* f = fopen(dump_path, "rb");
    if (!f) {
        printf("Error: Cannot open '%s'\n", dump_path);
        return 1;
    }

    // Get file size
    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    printf("=== REO GS Dump Replay ===\n");
    printf("File: %s (%ld bytes, %.1f MB)\n", dump_path, file_size, file_size / (1024.0 * 1024.0));

    // Read first u32 to determine format
    uint32_t first_word;
    if (!read_u32(f, &first_word)) {
        printf("Error: Cannot read header\n");
        fclose(f);
        return 1;
    }

    uint32_t crc = 0;
    std::vector<uint8_t> state;
    std::string serial;

    if (first_word == 0xFFFFFFFF) {
        // ── New format (PCSX2 v2.x) ──
        uint32_t blob_size;
        if (!read_u32(f, &blob_size)) {
            printf("Error: Cannot read header blob size\n");
            fclose(f);
            return 1;
        }

        printf("Format: PCSX2 v2.x (new header, blob=%u bytes)\n", blob_size);

        // Read header blob
        std::vector<uint8_t> blob(blob_size);
        if (fread(blob.data(), 1, blob_size, f) != blob_size) {
            printf("Error: Truncated header blob\n");
            fclose(f);
            return 1;
        }

        // Parse GSDumpHeader struct (9 x uint32_t = 36 bytes)
        if (blob_size < sizeof(PCSX2DumpHeader)) {
            printf("Error: Header blob too small\n");
            fclose(f);
            return 1;
        }

        PCSX2DumpHeader hdr;
        memcpy(&hdr, blob.data(), sizeof(hdr));

        crc = hdr.crc;
        printf("CRC:      0x%08X\n", hdr.crc);
        printf("State:    version=%u, size=%u bytes (%.1f MB)\n",
               hdr.state_version, hdr.state_size, hdr.state_size / (1024.0 * 1024.0));

        // Extract serial
        if (hdr.serial_size > 0 && hdr.serial_offset + hdr.serial_size <= blob_size) {
            serial.assign((const char*)blob.data() + hdr.serial_offset, hdr.serial_size);
            printf("Serial:   %s\n", serial.c_str());
        }

        // Screenshot info
        if (hdr.screenshot_size > 0) {
            printf("Preview:  %ux%u (%u bytes)\n",
                   hdr.screenshot_width, hdr.screenshot_height, hdr.screenshot_size);
        }

        // Read real frozen state
        state.resize(hdr.state_size);
        if (fread(state.data(), 1, hdr.state_size, f) != hdr.state_size) {
            printf("Error: Truncated state data (need %u bytes)\n", hdr.state_size);
            fclose(f);
            return 1;
        }
    } else {
        // ── Legacy format ──
        crc = first_word;
        uint32_t state_size;
        if (!read_u32(f, &state_size)) {
            printf("Error: Cannot read state size\n");
            fclose(f);
            return 1;
        }

        printf("Format: Legacy\n");
        printf("CRC:    0x%08X\n", crc);
        printf("State:  %u bytes\n", state_size);

        state.resize(state_size);
        if (state_size > 0 && fread(state.data(), 1, state_size, f) != state_size) {
            printf("Error: Truncated state data\n");
            fclose(f);
            return 1;
        }
    }

    // Read initial register file (8192 bytes)
    std::vector<uint8_t> initial_regs(8192);
    if (fread(initial_regs.data(), 1, 8192, f) != 8192) {
        printf("Warning: Could not read full initial register block\n");
    }

    long records_offset = ftell(f);
    long records_size = file_size - records_offset;
    printf("Records:  %ld bytes (%.1f KB) starting at offset 0x%lX\n",
           records_size, records_size / 1024.0, records_offset);

    // Initialize GS renderer (headless — no window)
    auto* gs_ptr = new reo::GSRenderer();
    auto& gs = *gs_ptr;
    if (!gs.init(fb_width, fb_height, false, /*headless=*/true)) {
        printf("Error: Failed to initialize GS renderer\n");
        fclose(f);
        return 1;
    }

    // Load frozen state (VRAM + environment)
    if (!state.empty()) {
        load_frozen_state(gs, state.data(), (uint32_t)state.size());
    }

    // Apply initial register file
    apply_initial_regs(gs, initial_regs.data(), verbose);

    // If --vram-frame, save the initial VRAM as frame 0
    // Use DISPFB1 register to find framebuffer location
    // DISPFB1 format: FBP[8:0]=bits 0-8, FBW[5:0]=bits 9-14, PSM[4:0]=bits 15-19
    uint32_t disp_fbp = 0;  // FBP in 2048-byte page units
    uint32_t disp_fbw = 8;  // FBW in 64-pixel units (default 512px)
    // Try to read from privileged register space
    {
        uint64_t dispfb1;
        memcpy(&dispfb1, initial_regs.data() + 0x70, 8); // DISPFB1 at offset 0x70
        if (dispfb1 != 0) {
            disp_fbp = dispfb1 & 0x1FF;  // FBP in 2048-byte units
            disp_fbw = (dispfb1 >> 9) & 0x3F;
            if (disp_fbw == 0) disp_fbw = 8;
            printf("[GS-REPLAY] DISPFB1: FBP=%u (base=0x%X), FBW=%u (%u px)\n",
                   disp_fbp, disp_fbp * 2048, disp_fbw, disp_fbw * 64);
        }
    }
    // Convert FBP (2048-byte page units) to bp (64-byte block units): FBP * 32
    uint32_t fb_bp = disp_fbp * 32;

    if (vram_frame && !stats_only) {
        extract_fb_from_vram(gs, fb_bp, disp_fbw, fb_width, fb_height);
    }

    // Create output directory
    if (!stats_only) {
#ifdef _WIN32
        _mkdir(out_dir.c_str());
#else
        mkdir(out_dir.c_str(), 0755);
#endif
        printf("Output: %s/frame_NNNN.bmp\n", out_dir.c_str());
    }

    printf("Max frames: %d\n\n", max_frames);

    // Process records
    GsDumpStats stats;
    std::vector<uint8_t> transfer_buf;
    int frame_num = 0;

    while (!feof(f) && frame_num < max_frames) {
        uint8_t type;
        if (!read_u8(f, &type)) break;

        switch (type) {
        case RECORD_TRANSFER: {
            uint8_t path;
            uint32_t size;
            if (!read_u8(f, &path) || !read_u32(f, &size)) goto done;

            if (path > 3) {
                printf("Warning: Invalid path %u at offset 0x%llX, skipping %u bytes\n",
                       path, (unsigned long long)(ftell(f) - 6), size);
                fseek(f, size, SEEK_CUR);
                break;
            }

            stats.transfers[path]++;
            stats.transfer_bytes[path] += size;

            // Read transfer data
            if (size > transfer_buf.size()) {
                transfer_buf.resize(size);
            }
            if (fread(transfer_buf.data(), 1, size, f) != size) goto done;

            // Submit to GS renderer
            // PATH1_OLD (0) and PATH1_NEW (3) both go to PATH1 (VU1→GIF)
            switch (path) {
            case PATH1_OLD:
            case PATH1_NEW: gs.submit_path1(transfer_buf.data(), size); break;
            case PATH2:     gs.submit_path2(transfer_buf.data(), size); break;
            case PATH3:     gs.submit_path3(transfer_buf.data(), size); break;
            }

            if (verbose) {
                const char* path_names[] = {"PATH1old", "PATH2", "PATH3", "PATH1new"};
                printf("  Transfer %s: %u bytes", path_names[path], size);
                if (size >= 16) {
                    uint64_t lo;
                    memcpy(&lo, transfer_buf.data(), 8);
                    uint32_t nloop = lo & 0x7FFF;
                    uint8_t flg = (lo >> 58) & 3;
                    uint8_t nreg = (lo >> 60) & 0xF;
                    if (nreg == 0) nreg = 16;
                    const char* flg_names[] = {"PACKED", "REGLIST", "IMAGE", "DISABLED"};
                    printf(" [tag: nloop=%u flg=%s nreg=%u]",
                           nloop, flg_names[flg], nreg);
                }
                printf("\n");
            }
            break;
        }

        case RECORD_VSYNC: {
            uint8_t field;
            if (!read_u8(f, &field)) goto done;

            stats.vsyncs++;
            frame_num++;

            // Save frame as BMP
            if (!stats_only) {
                char bmp_path[512];
                snprintf(bmp_path, sizeof(bmp_path), "%s/frame_%04d.bmp",
                         out_dir.c_str(), frame_num);

                // If --vram-frame, extract from VRAM; otherwise use software FB
                if (vram_frame) {
                    extract_fb_from_vram(gs, fb_bp, disp_fbw, fb_width, fb_height);
                }

                const uint32_t* fb = gs.framebuffer();
                if (fb) {
                    int w = gs.fb_width(), h = gs.fb_height();
                    int nonzero = 0;
                    for (int i = 0; i < w * h; i++) {
                        if (fb[i] != 0) nonzero++;
                    }

                    if (write_bmp(bmp_path, fb, w, h)) {
                        stats.frames_saved++;
                        printf("[Frame %4d] Saved %s (field=%d, %d non-zero pixels)\n",
                               frame_num, bmp_path, field, nonzero);
                    }
                }
            } else {
                printf("[Frame %4d] VSync (field=%d) | PATH1: %llu PATH2: %llu PATH3: %llu\n",
                       frame_num, field,
                       (unsigned long long)(stats.transfers[0] + stats.transfers[3]),
                       (unsigned long long)stats.transfers[1],
                       (unsigned long long)stats.transfers[2]);
            }
            break;
        }

        case RECORD_READFIFO: {
            uint32_t size;
            if (!read_u32(f, &size)) goto done;
            fseek(f, size, SEEK_CUR);
            break;
        }

        case RECORD_REGISTERS: {
            uint8_t regs[8192];
            size_t read = fread(regs, 1, 8192, f);
            if (read != 8192) {
                printf("Warning: Short register block (%zu bytes), trying to continue\n", read);
            }

            stats.reg_writes++;

            // Apply as privileged register space (same format as initial_regs)
            int applied = 0;
            for (int i = 0; i < 512; i++) {
                uint64_t lo;
                memcpy(&lo, regs + i * 16, 8);
                if (lo != 0) {
                    gs.write_register(i * 0x10, lo);
                    applied++;
                }
            }

            if (verbose) {
                printf("  Registers: applied %d non-zero entries\n", applied);
            }
            break;
        }

        default:
            printf("Warning: Unknown record type 0x%02X at offset 0x%llX\n",
                   type, (unsigned long long)(ftell(f) - 1));
            goto done;
        }
    }

done:
    fclose(f);
    gs.shutdown();
    delete gs_ptr;

    // Print summary
    printf("\n=== Replay Summary ===\n");
    printf("Frames:     %d (%llu saved as BMP)\n",
           frame_num, (unsigned long long)stats.frames_saved);
    printf("PATH1old (VU1):   %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[0],
           (unsigned long long)stats.transfer_bytes[0]);
    printf("PATH1new (VU1):   %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[3],
           (unsigned long long)stats.transfer_bytes[3]);
    printf("PATH2 (VIF→GIF):  %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[1],
           (unsigned long long)stats.transfer_bytes[1]);
    printf("PATH3 (DMA→GIF):  %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[2],
           (unsigned long long)stats.transfer_bytes[2]);
    printf("Register blocks:  %8llu\n", (unsigned long long)stats.reg_writes);

    uint64_t total_bytes = stats.transfer_bytes[0] + stats.transfer_bytes[1] +
                           stats.transfer_bytes[2] + stats.transfer_bytes[3];
    printf("Total GIF data:   %llu bytes (%.1f MB)\n",
           (unsigned long long)total_bytes, total_bytes / (1024.0 * 1024.0));

    if (frame_num > 0) {
        uint64_t path1_total = stats.transfer_bytes[0] + stats.transfer_bytes[3];
        printf("Avg/frame:        %.1f KB PATH1, %.1f KB PATH2, %.1f KB PATH3\n",
               path1_total / (frame_num * 1024.0),
               stats.transfer_bytes[1] / (frame_num * 1024.0),
               stats.transfer_bytes[2] / (frame_num * 1024.0));
    }

    return 0;
}
