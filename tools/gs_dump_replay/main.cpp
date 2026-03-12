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
 * PCSX2 GS Dump format:
 *   Header:
 *     uint32_t crc              - Game CRC32
 *     uint32_t state_size       - Size of frozen GS state
 *     uint8_t  state[state_size] - Frozen state (regs + VRAM snapshot)
 *   Records (repeated until EOF):
 *     uint8_t type
 *       0 = Transfer: uint8_t path, uint32_t size, uint8_t data[size]
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

    // BMP file header (14 bytes)
    uint32_t row_size = width * 3;
    uint32_t row_padded = (row_size + 3) & ~3;
    uint32_t pixel_size = row_padded * height;
    uint32_t file_size = 54 + pixel_size;

    uint8_t header[54] = {};
    header[0] = 'B'; header[1] = 'M';
    memcpy(header + 2, &file_size, 4);
    uint32_t offset = 54;
    memcpy(header + 10, &offset, 4);

    // DIB header (40 bytes)
    uint32_t dib_size = 40;
    memcpy(header + 14, &dib_size, 4);
    memcpy(header + 18, &width, 4);
    int neg_height = -height; // Top-down
    memcpy(header + 22, &neg_height, 4);
    uint16_t planes = 1;
    memcpy(header + 26, &planes, 2);
    uint16_t bpp = 24;
    memcpy(header + 28, &bpp, 2);
    // Compression = 0 (BI_RGB), rest = 0

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

// ── GS Dump reader ──────────────────────────────────────────────────

enum GsDumpRecordType : uint8_t {
    RECORD_TRANSFER  = 0,
    RECORD_VSYNC     = 1,
    RECORD_READFIFO  = 2,
    RECORD_REGISTERS = 3,
};

struct GsDumpHeader {
    uint32_t crc;
    uint32_t state_size;
};

struct GsDumpStats {
    uint64_t transfers[3] = {};  // PATH1, PATH2, PATH3
    uint64_t transfer_bytes[3] = {};
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

static void apply_frozen_regs(reo::GSRenderer& gs, const uint8_t* state, uint32_t state_size) {
    // PCSX2 frozen state starts with GS privileged registers
    // The exact layout depends on the PCSX2 version, but the first
    // portion is typically the privileged register block.
    // We apply what we can recognize.

    if (state_size < 256) return;

    printf("[GS-REPLAY] Applying frozen state (%u bytes)\n", state_size);

    // The frozen state layout (PCSX2 1.6+):
    //   Bytes 0-8191: GS internal registers (512 x 16 bytes)
    //   Then: VRAM (4MB), etc.
    // For privileged registers, we look at offsets we know:

    // PMODE at offset 0x00
    if (state_size >= 16) {
        uint64_t pmode;
        memcpy(&pmode, state + 0, 8);
        if (pmode != 0) {
            gs.write_register(0x0000, pmode);
            printf("[GS-REPLAY]   PMODE = 0x%016llX\n", (unsigned long long)pmode);
        }
    }

    // DISPFB1/DISPLAY1 at offset 0x70/0x80
    if (state_size >= 0x90) {
        uint64_t dispfb1, display1;
        memcpy(&dispfb1, state + 0x70, 8);
        memcpy(&display1, state + 0x80, 8);
        gs.write_register(0x0070, dispfb1);
        gs.write_register(0x0080, display1);
        printf("[GS-REPLAY]   DISPFB1 = 0x%016llX\n", (unsigned long long)dispfb1);
    }

    // BGCOLOR at offset 0xE0
    if (state_size >= 0xF0) {
        uint64_t bgcolor;
        memcpy(&bgcolor, state + 0xE0, 8);
        if (bgcolor != 0) {
            gs.write_register(0x00E0, bgcolor);
            printf("[GS-REPLAY]   BGCOLOR = 0x%016llX\n", (unsigned long long)bgcolor);
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

    // Read header
    GsDumpHeader header;
    if (!read_u32(f, &header.crc) || !read_u32(f, &header.state_size)) {
        printf("Error: Invalid GS dump header\n");
        fclose(f);
        return 1;
    }

    printf("=== REO GS Dump Replay ===\n");
    printf("File: %s\n", dump_path);
    printf("CRC:  0x%08X\n", header.crc);
    printf("State size: %u bytes\n", header.state_size);

    // Read frozen state
    std::vector<uint8_t> state(header.state_size);
    if (header.state_size > 0) {
        if (fread(state.data(), 1, header.state_size, f) != header.state_size) {
            printf("Error: Truncated state block\n");
            fclose(f);
            return 1;
        }
    }

    // Initialize GS renderer (headless — no window)
    // Heap-allocate: GSRenderer has 4MB m_vram which would overflow the stack
    auto* gs_ptr = new reo::GSRenderer();
    auto& gs = *gs_ptr;
    if (!gs.init(fb_width, fb_height, false, /*headless=*/true)) {
        printf("Error: Failed to initialize GS renderer\n");
        fclose(f);
        return 1;
    }

    // Apply frozen register state
    if (!state.empty()) {
        apply_frozen_regs(gs, state.data(), header.state_size);
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

            if (path > 2) {
                printf("Warning: Invalid path %u, skipping %u bytes\n", path, size);
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
            switch (path) {
            case 0: gs.submit_path1(transfer_buf.data(), size); break;
            case 1: gs.submit_path2(transfer_buf.data(), size); break;
            case 2: gs.submit_path3(transfer_buf.data(), size); break;
            }

            if (verbose) {
                printf("  Transfer PATH%d: %u bytes", path + 1, size);
                if (size >= 16) {
                    // Show first GIF tag
                    uint64_t lo, hi;
                    memcpy(&lo, transfer_buf.data(), 8);
                    memcpy(&hi, transfer_buf.data() + 8, 8);
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

                const uint32_t* fb = gs.framebuffer();
                if (fb) {
                    // Count non-zero pixels for diagnostic
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
                       (unsigned long long)stats.transfers[0],
                       (unsigned long long)stats.transfers[1],
                       (unsigned long long)stats.transfers[2]);
            }
            break;
        }

        case RECORD_READFIFO: {
            uint32_t size;
            if (!read_u32(f, &size)) goto done;
            // Skip FIFO read data — not relevant for replay
            fseek(f, size, SEEK_CUR);
            break;
        }

        case RECORD_REGISTERS: {
            // GS internal register state dump (8192 bytes in PCSX2)
            // Contains the A+D register file (256 registers x 16 bytes each
            // = 4096 for data + 4096 for addresses)
            uint8_t regs[8192];
            if (fread(regs, 1, 8192, f) != 8192) {
                // Might be a different size in some PCSX2 versions
                // Try to recover
                printf("Warning: Short register block, trying to continue\n");
            }

            stats.reg_writes++;

            // Apply key registers we understand
            // Register file is 64 entries of 128 bits (data[8] + addr[8])
            for (int i = 0; i < 256; i++) {
                uint64_t data_val;
                uint8_t reg_addr;
                memcpy(&data_val, regs + i * 16, 8);
                reg_addr = regs[i * 16 + 8];

                if (data_val != 0) {
                    gs.write_register(reg_addr * 0x10, data_val);
                }
            }

            if (verbose) {
                printf("  Registers: applied %d register block\n", 256);
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
    printf("PATH1 (VU1→GIF):  %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[0],
           (unsigned long long)stats.transfer_bytes[0]);
    printf("PATH2 (VIF→GIF):  %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[1],
           (unsigned long long)stats.transfer_bytes[1]);
    printf("PATH3 (DMA→GIF):  %8llu transfers, %12llu bytes\n",
           (unsigned long long)stats.transfers[2],
           (unsigned long long)stats.transfer_bytes[2]);
    printf("Register blocks:  %8llu\n", (unsigned long long)stats.reg_writes);

    uint64_t total_bytes = stats.transfer_bytes[0] + stats.transfer_bytes[1] + stats.transfer_bytes[2];
    printf("Total GIF data:   %llu bytes (%.1f MB)\n",
           (unsigned long long)total_bytes, total_bytes / (1024.0 * 1024.0));

    if (frame_num > 0) {
        printf("Avg/frame:        %.1f KB PATH1, %.1f KB PATH2, %.1f KB PATH3\n",
               stats.transfer_bytes[0] / (frame_num * 1024.0),
               stats.transfer_bytes[1] / (frame_num * 1024.0),
               stats.transfer_bytes[2] / (frame_num * 1024.0));
    }

    return 0;
}
