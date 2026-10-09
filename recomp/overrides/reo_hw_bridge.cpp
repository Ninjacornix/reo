/*
 * REO Hardware Bridge — Implementation
 *
 * Bridges PS2Recomp's code execution to REO's hardware subsystems:
 *   - GIF DMA → GSRenderer (software rasterizer)
 *   - VIF1 DMA → VIF command parser → VU1 execution → XGKICK → GSRenderer
 *   - GS register writes → GSRenderer
 *   - VU0 micro mode → VUInterpreter
 *
 * PS2 DMA channel base addresses:
 *   0x10008000 = VIF0 (to VU0)
 *   0x10009000 = VIF1 (to VU1 — primary geometry path)
 *   0x1000A000 = GIF  (to GS — direct GIF packets)
 *   0x1000B000 = fromIPU
 *   0x1000B400 = toIPU
 *   0x1000C000 = SIF0 (IOP → EE)
 *   0x1000C400 = SIF1 (EE → IOP)
 *   0x1000D000 = fromSPR
 *   0x1000D400 = toSPR
 *
 * VIF1 command opcodes (bits 31:24 of VIFcode):
 *   0x00 = NOP
 *   0x01 = STCYCL
 *   0x04 = ITOP
 *   0x05 = STMOD
 *   0x10 = FLUSH/FLUSHE/FLUSHA
 *   0x14 = MSCAL  — Start VU1 at address
 *   0x15 = MSCALF — Start VU1 at address (stall until VIF idle)
 *   0x17 = MSCNT  — Continue VU1 from current PC
 *   0x20 = STMASK
 *   0x30 = STROW
 *   0x31 = STCOL
 *   0x50 = DIRECT — Send data directly to GIF (PATH2)
 *   0x51 = DIRECTHL — Same, with stall
 *   0x60-0x7F = UNPACK — Upload data to VU1 memory
 */

#include "reo_hw_bridge.h"
#include "reo_trace_logger.h"
#include "runtime/gs/gs_renderer.h"
#include "runtime/vu/vu_interpreter.h"
#include "runtime/input/input.h"
#include "runtime/cdvd/cdvd.h"
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

namespace ps2_syscalls { bool hleSignalSema(uint32_t semaId); }
namespace ps2_stubs { uint32_t hleIopRebootCount(); }
#ifdef _WIN32
#include <windows.h>
#endif

ReoHwBridge* ReoHwBridge::s_instance = nullptr;

ReoHwBridge::ReoHwBridge() = default;

ReoHwBridge::~ReoHwBridge() {
    shutdown();
}

bool ReoHwBridge::init(PS2Runtime& runtime) {
    // Guard against double init (applyOutbreakOverrides is called twice)
    if (m_runtime != nullptr) {
        printf("[HW-BRIDGE] Already initialized, skipping re-init\n");
        return true;
    }

    m_runtime = &runtime;
    s_instance = this;

    printf("[HW-BRIDGE] Initializing hardware bridge...\n");

    // Initialize GS renderer in headless mode (no window — raylib handles display)
    m_gs = new reo::GSRenderer();
    if (!m_gs->init(640, 448, false, /*headless=*/true)) {
        printf("[HW-BRIDGE] ERROR: Failed to initialize GS renderer\n");
        return false;
    }

    // Get VU memory pointers from PS2Recomp's RDRAM
    // VU addresses map through PS2Memory::translateAddress():
    //   0x11000000 → phys 0x11000000 → masked to rdram offset 0x01000000
    //   0x11004000 → phys 0x11004000 → masked to rdram offset 0x01004000
    //   0x11008000 → phys 0x11008000 → masked to rdram offset 0x01008000
    //   0x1100C000 → phys 0x1100C000 → masked to rdram offset 0x0100C000
    uint8_t* rdram = runtime.memory().getRDRAM();

    uint8_t* vu0_code = rdram + (PS2_VU0_CODE_BASE & PS2_RAM_MASK);
    uint8_t* vu0_data = rdram + (PS2_VU0_DATA_BASE & PS2_RAM_MASK);
    uint8_t* vu1_code = rdram + (PS2_VU1_CODE_BASE & PS2_RAM_MASK);
    uint8_t* vu1_data = rdram + (PS2_VU1_DATA_BASE & PS2_RAM_MASK);

    // Initialize VU interpreters
    m_vu0 = new reo::VUInterpreter(0, vu0_code, PS2_VU0_CODE_SIZE,
                                       vu0_data, PS2_VU0_DATA_SIZE);

    m_vu1 = new reo::VUInterpreter(1, vu1_code, PS2_VU1_CODE_SIZE,
                                       vu1_data, PS2_VU1_DATA_SIZE);

    // Wire VU1 XGKICK → GS PATH1
    m_vu1->set_xgkick_callback([](const void* data, uint32_t max_size, void* user) {
        auto* gs = static_cast<reo::GSRenderer*>(user);
        gs->submit_path1(data, max_size);
    }, m_gs);

    // Wire VU0 XGKICK → GS PATH1 (VU0 can also XGKICK, though rare)
    m_vu0->set_xgkick_callback([](const void* data, uint32_t max_size, void* user) {
        auto* gs = static_cast<reo::GSRenderer*>(user);
        gs->submit_path1(data, max_size);
    }, m_gs);

    // Initialize input system
    m_input = new reo::Input();
    m_input->init();

    // Initialize CDVD filesystem (reads from game_data/)
    auto cdRoot = PS2Runtime::getIoPaths().cdRoot;
    if (!cdRoot.empty()) {
        m_cdvd = new reo::CDVD(cdRoot);
        printf("[HW-BRIDGE] CDVD initialized: %s\n", cdRoot.string().c_str());
    }

    // Register callbacks with PS2Memory
    PS2Memory::HwBridgeCallbacks memCb;
    memCb.onDmaStart = &ReoHwBridge::onDmaStart;
    memCb.onGsRegWrite = &ReoHwBridge::onGsRegWrite;
    memCb.user = this;
    runtime.memory().setHwBridge(memCb);

    // Register callbacks with PS2Runtime
    PS2Runtime::HwBridgeVtable rtVt;
    rtVt.onVuStart = &ReoHwBridge::onVuStart;
    rtVt.getFramebuffer = &ReoHwBridge::getFramebuffer;
    rtVt.onSifRpc = &ReoHwBridge::onSifRpc;
    rtVt.user = this;
    runtime.setHwBridgeVt(rtVt);

    printf("[HW-BRIDGE] Bridge initialized:\n");
    printf("[HW-BRIDGE]   GS: headless software rasterizer (640x448)\n");
    printf("[HW-BRIDGE]   VU0: interpreter (%u bytes code, %u bytes data)\n",
           PS2_VU0_CODE_SIZE, PS2_VU0_DATA_SIZE);
    printf("[HW-BRIDGE]   VU1: interpreter (%u bytes code, %u bytes data)\n",
           PS2_VU1_CODE_SIZE, PS2_VU1_DATA_SIZE);
    printf("[HW-BRIDGE]   DMA: GIF + VIF1 interception active\n");

    // Initialize trace logger (only active if REO_TRACE=1)
    ReoTraceLogger::instance().init();

    return true;
}

void ReoHwBridge::shutdown() {
    ReoTraceLogger::instance().shutdown();

    if (m_gs) {
        printf("[HW-BRIDGE] Stats: gif_packets=%llu vif1_dmas=%llu vu0_runs=%llu "
               "vu1_runs=%llu gs_reg_writes=%llu\n",
               (unsigned long long)m_gifPackets, (unsigned long long)m_vif1Dmas,
               (unsigned long long)m_vu0Runs, (unsigned long long)m_vu1Runs,
               (unsigned long long)m_gsRegWrites);
    }

    delete m_cdvd; m_cdvd = nullptr;
    if (m_input) { m_input->shutdown(); delete m_input; m_input = nullptr; }
    delete m_vu1; m_vu1 = nullptr;
    delete m_vu0; m_vu0 = nullptr;
    if (m_gs) { m_gs->shutdown(); delete m_gs; m_gs = nullptr; }

    if (s_instance == this) s_instance = nullptr;
    m_runtime = nullptr;
}

// ── PS2Memory callback: DMA channel start ───────────────────────────

void ReoHwBridge::onDmaStart(uint32_t channelBase, uint32_t madr, uint32_t qwc,
                              uint32_t tadr, const uint8_t* rdram, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);

    switch (channelBase) {
    case 0x1000A000: {
        // GIF DMA (PATH3) — forward GIF packets to GS renderer
        self->m_gifPackets++;

        if (qwc > 0) {
            // Normal mode: data at madr, qwc quadwords
            uint32_t phys = madr & PS2_RAM_MASK;
            uint32_t bytes = qwc * 16;
            if (phys + bytes <= PS2_RAM_SIZE) {
                REO_TRACE_DMA_GIF(madr, qwc, rdram + phys, bytes);
                self->m_gs->submit_path3(rdram + phys, bytes);
            }
        } else {
            // Source chain mode: follow DMA tags from tadr until END/REFE
            uint32_t curTag = tadr;
            int chainDepth = 0;
            constexpr int MAX_CHAIN = 256;
            while (chainDepth < MAX_CHAIN) {
                uint32_t physTag = curTag & PS2_RAM_MASK;
                if (physTag + 16 > PS2_RAM_SIZE) break;

                uint64_t tag;
                memcpy(&tag, rdram + physTag, sizeof(tag));
                uint16_t tagQwc = (uint16_t)(tag & 0xFFFF);
                uint32_t tagId  = (uint32_t)((tag >> 28) & 0x7);
                uint32_t tagAddr = (uint32_t)((tag >> 32) & 0x7FFFFFFF);
                // Upper 64 bits of tag QW can be data (TTE mode)

                static int chainLog = 0;
                if (chainLog < 30) {
                    printf("[HW-BRIDGE] GIF chain[%d]: tag@0x%08X id=%u qwc=%u addr=0x%08X\n",
                           chainDepth, curTag, tagId, tagQwc, tagAddr);
                    chainLog++;
                }

                if (tagQwc > 0) {
                    uint32_t dataAddr;
                    if (tagId == 0 || tagId == 3 || tagId == 4) {
                        // REFE/REF/REFS: data at tagAddr
                        dataAddr = tagAddr;
                    } else {
                        // CNT/NEXT/CALL/RET/END: data follows inline
                        dataAddr = curTag + 16;
                    }
                    uint32_t phys = dataAddr & PS2_RAM_MASK;
                    uint32_t bytes = tagQwc * 16;
                    if (phys + bytes <= PS2_RAM_SIZE) {
                        REO_TRACE_DMA_GIF(dataAddr, tagQwc, rdram + phys, bytes);
                        self->m_gs->submit_path3(rdram + phys, bytes);
                    }
                }

                // Advance to next tag based on ID
                if (tagId == 7) {
                    // END — stop chain
                    break;
                } else if (tagId == 0) {
                    // REFE — normally "reference end" but RE Outbreak uses
                    // a sentinel REFE/QWC=0 at display list buffer start.
                    // The ADDR field (masked to RAM) points to the real chain.
                    if (tagQwc == 0 && chainDepth == 0) {
                        uint32_t nextAddr = tagAddr & PS2_RAM_MASK;
                        if (nextAddr + 16 <= PS2_RAM_SIZE && nextAddr != 0) {
                            static int skipLog = 0;
                            if (skipLog < 10) {
                                printf("[HW-BRIDGE] GIF: skipping sentinel REFE/QWC=0, chain continues at 0x%08X\n", nextAddr);
                                skipLog++;
                            }
                            curTag = nextAddr;
                            chainDepth++;
                            continue;
                        }
                    }
                    break;
                } else if (tagId == 1) {
                    // CNT — next tag is after this tag + data
                    curTag = curTag + 16 + tagQwc * 16;
                } else if (tagId == 2) {
                    // NEXT — next tag at tagAddr
                    curTag = tagAddr;
                } else if (tagId == 3 || tagId == 4) {
                    // REF/REFS — next tag follows this one
                    curTag = curTag + 16;
                } else {
                    // CALL/RET — not supported yet, break
                    break;
                }
                chainDepth++;
            }
        }

        static int logCount = 0;
        if (logCount < 8) {
            printf("[HW-BRIDGE] GIF DMA: madr=0x%08X qwc=%u tadr=0x%08X (total packets: %llu)\n",
                   madr, qwc, tadr, (unsigned long long)self->m_gifPackets);
            logCount++;
        }
        break;
    }
    case 0x10009000: {
        // VIF1 DMA — parse VIF commands to find UNPACK/MSCAL/DIRECT
        self->m_vif1Dmas++;

        if (qwc > 0) {
            uint32_t phys = madr & PS2_RAM_MASK;
            uint32_t bytes = qwc * 16;
            if (phys + bytes <= PS2_RAM_SIZE)
                REO_TRACE_DMA_VIF1(madr, qwc, tadr, rdram + phys, bytes);
            self->processVif1Dma(madr, qwc, rdram);
        } else {
            REO_TRACE_DMA_VIF1(madr, 0, tadr, nullptr, 0);
            self->processVif1DmaChain(tadr, rdram);
        }

        static int logCount = 0;
        if (logCount < 8) {
            printf("[HW-BRIDGE] VIF1 DMA: madr=0x%08X qwc=%u tadr=0x%08X (total: %llu)\n",
                   madr, qwc, tadr, (unsigned long long)self->m_vif1Dmas);
            logCount++;
        }
        break;
    }
    default:
        // Other DMA channels (VIF0, SIF, SPR, etc.) — not handled yet
        break;
    }
}

// ── PS2Memory callback: GS register write ───────────────────────────

void ReoHwBridge::onGsRegWrite(uint32_t offset, uint64_t value, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);
    self->m_gsRegWrites++;
    REO_TRACE_GS_REG(offset, value);
    self->m_gs->write_register(offset, value);
}

// ── PS2Runtime callback: VU microprogram start ──────────────────────

void ReoHwBridge::onVuStart(int unit, uint32_t addr, uint8_t* rdram,
                             R5900Context* ctx, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);
    self->executeVu(unit, addr, rdram, ctx);
}

// ── PS2Runtime callback: get rendered framebuffer ───────────────────

const uint32_t* ReoHwBridge::getFramebuffer(int* width, int* height, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);
    if (!self->m_gs) return nullptr;

    int w = self->m_gs->fb_width();
    int h = self->m_gs->fb_height();
    *width = w;
    *height = h;

    const uint32_t* src = self->m_gs->framebuffer();
    if (!src) return nullptr;

    // Overlay buffer: copy framebuffer and draw debug info on top
    static uint32_t* overlay = nullptr;
    static int overlay_size = 0;
    if (!overlay || overlay_size != w * h) {
        delete[] overlay;
        overlay = new uint32_t[w * h];
        overlay_size = w * h;
    }
    memcpy(overlay, src, w * h * sizeof(uint32_t));

    // Debug overlay: colored bar + "REO" text + frame counter
    static int frame_counter = 0;
    frame_counter++;

    // Color cycling bar at top (2 rows)
    uint8_t r = (uint8_t)((frame_counter * 3) & 0xFF);
    uint8_t g = (uint8_t)((frame_counter * 5 + 85) & 0xFF);
    uint8_t b = (uint8_t)((frame_counter * 7 + 170) & 0xFF);
    uint32_t bar_color = 0xFF000000 | ((uint32_t)b << 16) | ((uint32_t)g << 8) | r;
    for (int y = 0; y < 2 && y < h; y++)
        for (int x = 0; x < w; x++)
            overlay[y * w + x] = bar_color;

    // Simple bitmap font for "REO" + frame number
    static const uint8_t font_R[] = {0x7C,0x42,0x42,0x7C,0x48,0x44,0x42};
    static const uint8_t font_E[] = {0x7E,0x40,0x40,0x7C,0x40,0x40,0x7E};
    static const uint8_t font_O[] = {0x3C,0x42,0x42,0x42,0x42,0x42,0x3C};
    static const uint8_t font_digits[][7] = {
        {0x3C,0x42,0x42,0x42,0x42,0x42,0x3C},
        {0x08,0x18,0x08,0x08,0x08,0x08,0x1C},
        {0x3C,0x42,0x02,0x1C,0x20,0x40,0x7E},
        {0x3C,0x42,0x02,0x1C,0x02,0x42,0x3C},
        {0x04,0x0C,0x14,0x24,0x7E,0x04,0x04},
        {0x7E,0x40,0x7C,0x02,0x02,0x42,0x3C},
        {0x3C,0x40,0x7C,0x42,0x42,0x42,0x3C},
        {0x7E,0x02,0x04,0x08,0x10,0x10,0x10},
        {0x3C,0x42,0x42,0x3C,0x42,0x42,0x3C},
        {0x3C,0x42,0x42,0x3E,0x02,0x42,0x3C},
    };
    auto draw_glyph = [&](const uint8_t* glyph, int cx, int cy, uint32_t color) {
        for (int row = 0; row < 7; row++)
            for (int col = 0; col < 7; col++)
                if (glyph[row] & (0x80 >> col)) {
                    int px = cx + col, py = cy + row;
                    if (px >= 0 && px < w && py >= 0 && py < h)
                        overlay[py * w + px] = color;
                }
    };
    uint32_t white = 0xFFFFFFFF;
    draw_glyph(font_R, 4, 3, white);
    draw_glyph(font_E, 12, 3, white);
    draw_glyph(font_O, 20, 3, white);

    // Frame number
    int fc = frame_counter;
    int digits[8]; int nd = 0;
    if (fc == 0) digits[nd++] = 0;
    else while (fc > 0 && nd < 8) { digits[nd++] = fc % 10; fc /= 10; }
    for (int i = 0; i < nd; i++)
        draw_glyph(font_digits[digits[nd - 1 - i]], 32 + i * 8, 3, white);

    // F12 screenshot: capture GS framebuffer (clean, no overlay), then show toast
#ifdef _WIN32
    {
        static bool f12_was_down = false;
        bool f12_down = (GetAsyncKeyState(VK_F12) & 0x8000) != 0;
        if (f12_down && !f12_was_down && self->m_gs) {
            self->m_gs->take_screenshot();
        }
        f12_was_down = f12_down;
    }
#endif

    // Draw toast notification into overlay (bottom-right)
    if (self->m_gs) {
        self->m_gs->draw_toast_to(overlay, w, h);
    }

    return overlay;
}

// ── VIF1 DMA processing ────────────────────────────────────────────

void ReoHwBridge::processVif1Dma(uint32_t madr, uint32_t qwc, const uint8_t* rdram) {
    uint32_t phys = madr & PS2_RAM_MASK;
    uint32_t bytes = qwc * 16;
    if (phys + bytes > PS2_RAM_SIZE) return;

    processVifCommands(rdram + phys, bytes, rdram);
}

void ReoHwBridge::processVif1DmaChain(uint32_t tadr, const uint8_t* rdram) {
    // Walk DMA chain tags
    constexpr int MAX_CHAIN = 256; // Safety limit
    uint32_t currentTag = tadr;

    for (int i = 0; i < MAX_CHAIN; i++) {
        uint32_t physTag = currentTag & PS2_RAM_MASK;
        if (physTag + 16 > PS2_RAM_SIZE) break;

        uint64_t tag;
        memcpy(&tag, rdram + physTag, sizeof(tag));

        uint16_t tagQwc = (uint16_t)(tag & 0xFFFF);
        uint32_t id = (uint32_t)((tag >> 28) & 0x7);
        uint32_t addr = (uint32_t)((tag >> 32) & 0x7FFFFFF0);
        bool irq = (tag >> 31) & 1;

        // Data follows the tag in most modes
        uint32_t dataAddr = 0;
        bool endChain = false;

        switch (id) {
        case 0: // REFE: addr, end chain
            dataAddr = addr;
            endChain = true;
            break;
        case 1: // CNT: data follows tag
            dataAddr = currentTag + 16;
            currentTag = currentTag + 16 + tagQwc * 16;
            break;
        case 2: // NEXT: data follows tag, next tag at addr
            dataAddr = currentTag + 16;
            currentTag = addr;
            break;
        case 3: // REF: data at addr, next tag follows
            dataAddr = addr;
            currentTag = currentTag + 16;
            break;
        case 5: // CALL: like CNT but pushes return
            dataAddr = currentTag + 16;
            currentTag = addr;
            break;
        case 7: // END: data follows tag, end chain
            dataAddr = currentTag + 16;
            endChain = true;
            break;
        default:
            endChain = true;
            break;
        }

        if (tagQwc > 0 && dataAddr != 0) {
            uint32_t phys = dataAddr & PS2_RAM_MASK;
            uint32_t bytes = tagQwc * 16;
            if (phys + bytes <= PS2_RAM_SIZE) {
                processVifCommands(rdram + phys, bytes, rdram);
            }
        }

        if (endChain || irq) break;
    }
}

void ReoHwBridge::processVifCommands(const uint8_t* data, uint32_t size, const uint8_t* rdram) {
    uint32_t pos = 0;

    while (pos + 4 <= size) {
        uint32_t vifcode;
        memcpy(&vifcode, data + pos, 4);

        uint8_t cmd = (vifcode >> 24) & 0x7F; // Bits 30:24 (bit 31 = IRQ)
        uint16_t immediate = vifcode & 0xFFFF;
        uint8_t num = (vifcode >> 16) & 0xFF;

        switch (cmd) {
        case 0x00: // NOP
            pos += 4;
            break;

        case 0x01: // STCYCL
            pos += 4;
            break;

        case 0x04: // ITOP
            pos += 4;
            break;

        case 0x05: // STMOD
            pos += 4;
            break;

        case 0x10: // FLUSHE
        case 0x11: // FLUSH
        case 0x13: // FLUSHA
            pos += 4;
            break;

        case 0x14: // MSCAL — Start VU1 microprogram at immediate * 8
        {
            uint32_t vuAddr = (uint32_t)immediate * 8;
            pos += 4;

            m_vu1Runs++;
            m_vu1->start(vuAddr);
            m_vu1->run(65536);

            static int logCount = 0;
            if (logCount < 16) {
                printf("[HW-BRIDGE] VIF1 MSCAL: VU1 start @0x%04X (run #%llu)\n",
                       vuAddr, (unsigned long long)m_vu1Runs);
                logCount++;
            }
            break;
        }
        case 0x15: // MSCALF
        {
            uint32_t vuAddr = (uint32_t)immediate * 8;
            pos += 4;

            m_vu1Runs++;
            m_vu1->start(vuAddr);
            m_vu1->run(65536);
            break;
        }
        case 0x17: // MSCNT — Continue VU1 from current PC
        {
            pos += 4;

            m_vu1Runs++;
            // Don't reset PC, just continue
            m_vu1->state().running = true;
            m_vu1->run(65536);
            break;
        }

        case 0x20: // STMASK
            pos += 4;
            if (pos + 4 <= size) pos += 4; // Skip mask data word
            break;

        case 0x30: // STROW
            pos += 4;
            if (pos + 16 <= size) pos += 16; // Skip 4 words
            break;

        case 0x31: // STCOL
            pos += 4;
            if (pos + 16 <= size) pos += 16; // Skip 4 words
            break;

        case 0x50: // DIRECT — Send data to GIF (PATH2)
        case 0x51: // DIRECTHL
        {
            uint32_t qwc = immediate;
            pos += 4;
            uint32_t bytes = qwc * 16;
            if (pos + bytes <= size) {
                m_gs->submit_path2(data + pos, bytes);
                pos += bytes;
            } else {
                pos = size; // Bail
            }
            break;
        }

        default: {
            // Check for UNPACK commands (0x60-0x7F)
            if (cmd >= 0x60 && cmd <= 0x7F) {
                // UNPACK: upload data to VU1 data memory
                // num = number of vectors to write
                // immediate = VU1 destination address (in 128-bit units)
                // cmd[3:0] = format (V4-32, V3-32, V2-32, etc.)
                uint8_t format = cmd & 0x0F;
                bool usn = (vifcode >> 14) & 1; // Unsigned
                bool flg = (vifcode >> 15) & 1; // Use mask

                // Calculate source data size based on format
                uint32_t bytesPerVector = 0;
                switch (format) {
                case 0x0: bytesPerVector = 16; break; // S-32 (4x32)
                case 0x1: bytesPerVector = 16; break; // S-16 (4x16, expanded)
                case 0x2: bytesPerVector = 16; break; // S-8 (4x8, expanded)
                case 0x4: bytesPerVector = 8;  break; // V2-32
                case 0x5: bytesPerVector = 4;  break; // V2-16
                case 0x6: bytesPerVector = 2;  break; // V2-8
                case 0x8: bytesPerVector = 12; break; // V3-32
                case 0x9: bytesPerVector = 6;  break; // V3-16
                case 0xA: bytesPerVector = 3;  break; // V3-8
                case 0xC: bytesPerVector = 16; break; // V4-32
                case 0xD: bytesPerVector = 8;  break; // V4-16
                case 0xE: bytesPerVector = 4;  break; // V4-8
                case 0xF: bytesPerVector = 2;  break; // V4-5 (packed 16-bit)
                default:  bytesPerVector = 16; break;
                }

                uint32_t dataBytes = num * bytesPerVector;
                // Align to 32 bits
                dataBytes = (dataBytes + 3) & ~3;
                pos += 4;

                // Copy unpack data to VU1 data memory
                // The VU interpreter already points at the right rdram region
                uint32_t vuDst = (uint32_t)immediate * 16; // Destination in bytes
                if (pos + dataBytes <= size && format == 0x0C && vuDst + num * 16 <= PS2_VU1_DATA_SIZE) {
                    // Fast path for V4-32 (most common): direct 128-bit copy
                    uint8_t* vu1_data = m_vu1->state().vf[0].f == 0 ?
                        nullptr : nullptr; // Can't directly access VU data memory here
                    // The VUInterpreter constructor stored the data_mem pointer,
                    // but we need the bridge's pointer. Use the rdram offset.
                    // VU1 data memory is at rdram + (0x1100C000 & PS2_RAM_MASK)
                    uint8_t* vu1_data_mem = const_cast<uint8_t*>(rdram) + (PS2_VU1_DATA_BASE & PS2_RAM_MASK);
                    memcpy(vu1_data_mem + vuDst, data + pos, num * 16);
                }
                // For non-V4-32 formats, we'd need format conversion here.
                // For now, skip the data.

                pos += dataBytes;
            } else {
                // Unknown VIF command — skip just the command word
                pos += 4;
            }
            break;
        }
        }
    }
}

// ── VU execution ────────────────────────────────────────────────────

void ReoHwBridge::executeVu(int unit, uint32_t addr, uint8_t* rdram, R5900Context* ctx) {
    reo::VUInterpreter* vu = (unit == 0) ? m_vu0 : m_vu1;
    uint64_t& counter = (unit == 0) ? m_vu0Runs : m_vu1Runs;
    counter++;

    REO_TRACE_VU_START(unit, addr);
    vu->start(addr);
    vu->run(65536);
    REO_TRACE_VU_END(unit, 0); // TODO: actual cycle count

    // Copy VU0 state back to R5900Context (macro mode expects results in COP2 regs)
    if (unit == 0) {
        const reo::VUState& vs = m_vu0->state();

        // Copy VF registers back to R5900Context VU0 registers
        for (int i = 0; i < 32; i++) {
            ctx->vu0_vf[i] = _mm_loadu_ps(vs.vf[i].f);
        }

        // Copy VI registers
        for (int i = 0; i < 16; i++) {
            ctx->vi[i] = vs.vi[i];
        }

        // Copy status
        ctx->vu0_q = vs.q;
        ctx->vu0_p = 0; // VU0 has no P register (EFU)
        ctx->vu0_acc = _mm_set_ps(vs.acc[3], vs.acc[2], vs.acc[1], vs.acc[0]);
        ctx->vu0_mac_flags = vs.status;
        ctx->vu0_clip_flags = vs.clip_flag;
        ctx->vu0_clip_flags2 = 0;
        ctx->vu0_status = 0; // Clear running status
    }

    static int logCount = 0;
    if (logCount < 16) {
        printf("[HW-BRIDGE] VU%d micro @0x%04X completed (run #%llu)\n",
               unit, addr, (unsigned long long)counter);
        logCount++;
    }
}

// ── SIF RPC callback: handle IOP module calls ───────────────────────

// SIF RPC module IDs (PS2 IOP modules)
static constexpr uint32_t SIF_FILEIO  = 0x80000001;
static constexpr uint32_t SIF_PADMAN  = 0x80000100;
static constexpr uint32_t SIF_MCSERV  = 0x80000400;
static constexpr uint32_t SIF_CDVD    = 0x80000592;
static constexpr uint32_t SIF_LIBSD   = 0x80000701;

// Helper: read a uint32 from rdram
static inline uint32_t rdramRead32(const uint8_t* rdram, uint32_t addr) {
    uint32_t phys = addr & PS2_RAM_MASK;
    if (phys + 4 > PS2_RAM_SIZE) return 0;
    uint32_t v;
    memcpy(&v, rdram + phys, 4);
    return v;
}

// Helper: write a uint32 to rdram
static inline void rdramWrite32(uint8_t* rdram, uint32_t addr, uint32_t val) {
    uint32_t phys = addr & PS2_RAM_MASK;
    if (phys + 4 > PS2_RAM_SIZE) return;
    memcpy(rdram + phys, &val, 4);
}

bool ReoHwBridge::onSifRpc(uint32_t sid, uint32_t rpcNum,
                            uint32_t sendBuf, uint32_t sendSize,
                            uint32_t recvBuf, uint32_t recvSize,
                            uint8_t* rdram, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);

    // An IOP reboot (SIF_CMD_RESET, D1) wipes IOP memory: reset IOP-resident HLE
    // state (heap, open files) when the runtime's reboot count changes.
    if (self) {
        const uint32_t boots = ps2_stubs::hleIopRebootCount();
        if (boots != self->m_iopBootSeen) {
            self->m_iopBootSeen = boots;
            self->m_iopHeapNext = kIopHeapBase;
            for (auto& f : self->m_fioFds) { if (f) { fclose(f); f = nullptr; } }
            fprintf(stderr, "[HW-BRIDGE:IOP] reboot #%u: HLE IOP heap and fds reset\n", boots);
        }
    }

    switch (sid) {
    case SIF_FILEIO: {
        // HLE FILEIO server (IOP fileio.irx). D2 discovery stage: only fno 0xFF
        // (init, issued by the EE fioInit at 0x1187A0) is answered (see below);
        // every call is logged so the next missing operation is visible. Other
        // functions fail explicitly (-1) rather than faking success.
        static int fioLog = 0;
        if (fioLog < 200) {
            char hex[3 * 32 + 1] = {0};
            char text[64 + 1] = {0};
            if (sendBuf && sendSize) {
                const uint32_t n = std::min<uint32_t>(sendSize, 32);
                for (uint32_t i = 0; i < n; ++i) {
                    const uint8_t b = rdram[(sendBuf + i) & PS2_RAM_MASK];
                    snprintf(hex + i * 3, 4, "%02X ", b);
                }
                const uint32_t m = std::min<uint32_t>(sendSize, 64);
                for (uint32_t i = 0; i < m; ++i) {
                    const uint8_t b = rdram[(sendBuf + i) & PS2_RAM_MASK];
                    text[i] = (b >= 0x20 && b < 0x7F) ? (char)b : '.';
                }
            }
            fprintf(stderr, "[HW-BRIDGE:FIO] fno=0x%X send=0x%08X/%u recv=0x%08X/%u data=[%s] \"%s\"\n",
                    rpcNum, sendBuf, sendSize, recvBuf, recvSize, hex, text);
            fioLog++;
        }
        if (recvBuf && recvSize >= 4) {
            for (uint32_t off = 0; off + 4 <= recvSize && off < 0x40; off += 4)
                rdramWrite32(rdram, recvBuf + off, 0);
            if (rpcNum == 0xFF) {
                // Init reply, verified against PCSX2 (PINE, 2026-10-09): word0 is the
                // IOP fileio version "2800" (EE checks it against "PsIIlibkernl2800"
                // in 0x1189A8), word1 == 2.
                rdramWrite32(rdram, recvBuf, 0x30303832u); // "2800"
                if (recvSize >= 8) rdramWrite32(rdram, recvBuf + 4, 2u);
            } else if (rpcNum == 0x0 && sendBuf && sendSize >= 0x18 && self && self->m_cdvd) {
                // open. Request (EE fio_open 0x118A70): +0 completion sema, +4 EE
                // result address, +8 result size, +0xC flags, +0x10 mode, +0x14 path.
                // recv[0] != 0 = accepted; the result is delivered asynchronously
                // (IOP: cmd 0x80000011 -> copy to EE address, iSignalSema).
                const uint32_t sema    = rdramRead32(rdram, sendBuf + 0x0);
                const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                const uint32_t flags   = rdramRead32(rdram, sendBuf + 0xC);
                std::string path;
                for (uint32_t i = 0x14; i < std::min<uint32_t>(sendSize, 0x14 + 0x400); ++i) {
                    const char ch = (char)rdram[(sendBuf + i) & PS2_RAM_MASK];
                    if (!ch) break;
                    path.push_back(ch);
                }
                int32_t result = -2; // ENOENT
                if ((flags & 0x3) != 0x1) {
                    result = -30;    // EROFS: only O_RDONLY on the disc
                } else if (self->m_cdvd->file_exists(path)) {
                    FILE* f = _wfopen(self->m_cdvd->resolve_path(path).c_str(), L"rb");
                    if (f) {
                        int fd = 0;
                        while (fd < kMaxFioFds && self->m_fioFds[fd]) ++fd;
                        if (fd < kMaxFioFds) { self->m_fioFds[fd] = f; result = fd; }
                        else { fclose(f); result = -24; } // EMFILE
                    }
                }
                if (resAddr && resSize >= 4) rdramWrite32(rdram, resAddr, (uint32_t)result);
                rdramWrite32(rdram, recvBuf, 1u); // accepted
                const bool sig = ps2_syscalls::hleSignalSema(sema);
                fprintf(stderr, "[HW-BRIDGE:FIO] open \"%s\" flags=0x%X -> %d (sema %u %s)\n",
                        path.c_str(), flags, result, sema, sig ? "signaled" : "NOT signaled");
            } else if (rpcNum == 0x2 && sendBuf && sendSize >= 0x18 && self) {
                // read: +0xC fd, +0x10 EE buffer, +0x14 size. On hardware the IOP DMAs
                // the aligned part to the EE buffer and sends unaligned head/tail bytes
                // via cmd 0x80000011; the HLE writes the bytes directly (same end state).
                const uint32_t sema    = rdramRead32(rdram, sendBuf + 0x0);
                const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                const int32_t  fd      = (int32_t)rdramRead32(rdram, sendBuf + 0xC);
                const uint32_t buf     = rdramRead32(rdram, sendBuf + 0x10);
                const int32_t  size    = (int32_t)rdramRead32(rdram, sendBuf + 0x14);
                std::FILE* f = (fd >= 0 && fd < kMaxFioFds) ? self->m_fioFds[fd] : nullptr;
                const uint32_t phys = buf & PS2_RAM_MASK;
                int32_t result = -9; // EBADF
                if (f && size < 0) {
                    result = -22; // EINVAL
                } else if (f && (uint64_t)phys + (uint32_t)size > PS2_RAM_SIZE) {
                    result = -14; // EFAULT
                } else if (f) {
                    result = (int32_t)fread(rdram + phys, 1, (size_t)size, f);
                }
                if (resAddr && resSize >= 4) rdramWrite32(rdram, resAddr, (uint32_t)result);
                rdramWrite32(rdram, recvBuf, 1u); // accepted
                const bool sig = ps2_syscalls::hleSignalSema(sema);
                fprintf(stderr, "[HW-BRIDGE:FIO] read fd=%d buf=0x%08X size=%d -> %d (sema %u %s)\n",
                        fd, buf, size, result, sema, sig ? "signaled" : "NOT signaled");
            } else if (rpcNum == 0x17 && sendBuf && sendSize >= 0x81C) {
                // devctl (EE client 0x11B248): +0xC device name, +0x40C input,
                // +0x80C cmd, +0x810 in len, +0x814 out buf, +0x818 out len.
                // No HDD/network devices are emulated: fail with ENODEV like a PS2
                // without the device, completing the async request.
                const uint32_t sema    = rdramRead32(rdram, sendBuf + 0x0);
                const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                const uint32_t cmd     = rdramRead32(rdram, sendBuf + 0x80C);
                std::string dev;
                for (uint32_t i = 0xC; i < 0xC + 0x40; ++i) {
                    const char ch = (char)rdram[(sendBuf + i) & PS2_RAM_MASK];
                    if (!ch) break;
                    dev.push_back(ch);
                }
                const int32_t result = -19; // ENODEV
                if (resAddr && resSize >= 4) rdramWrite32(rdram, resAddr, (uint32_t)result);
                rdramWrite32(rdram, recvBuf, 1u); // accepted
                const bool sig = ps2_syscalls::hleSignalSema(sema);
                fprintf(stderr, "[HW-BRIDGE:FIO] devctl \"%s\" cmd=0x%X -> %d (no device; sema %u %s)\n",
                        dev.c_str(), cmd, result, sema, sig ? "signaled" : "NOT signaled");
            } else if ((rpcNum == 0x1 || rpcNum == 0x4) && sendBuf && sendSize >= 0x10 && self) {
                // close (1): +0xC fd.  lseek (4): +0xC fd, +0x10 offset, +0x14 whence.
                // Same async completion as open: result to +4, signal sema at +0.
                const uint32_t sema    = rdramRead32(rdram, sendBuf + 0x0);
                const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                const int32_t  fd      = (int32_t)rdramRead32(rdram, sendBuf + 0xC);
                std::FILE* f = (fd >= 0 && fd < kMaxFioFds) ? self->m_fioFds[fd] : nullptr;
                int32_t result = -9; // EBADF
                if (f && rpcNum == 0x1) {
                    fclose(f);
                    self->m_fioFds[fd] = nullptr;
                    result = 0;
                } else if (f && rpcNum == 0x4 && sendSize >= 0x18) {
                    const int32_t off    = (int32_t)rdramRead32(rdram, sendBuf + 0x10);
                    const int32_t whence = (int32_t)rdramRead32(rdram, sendBuf + 0x14);
                    if (whence >= 0 && whence <= 2 && _fseeki64(f, off, whence) == 0) {
                        const long long pos = _ftelli64(f);
                        result = (pos >= 0 && pos <= 0x7FFFFFFF) ? (int32_t)pos : -22; // EINVAL
                    } else {
                        result = -22;
                    }
                }
                if (resAddr && resSize >= 4) rdramWrite32(rdram, resAddr, (uint32_t)result);
                rdramWrite32(rdram, recvBuf, 1u); // accepted
                const bool sig = ps2_syscalls::hleSignalSema(sema);
                fprintf(stderr, "[HW-BRIDGE:FIO] %s fd=%d -> %d (sema %u %s)\n",
                        rpcNum == 0x1 ? "close" : "lseek", fd, result, sema,
                        sig ? "signaled" : "NOT signaled");
            } else if (rpcNum != 0xFF && sendBuf && sendSize >= 0xC) {
                // Any other fileio op uses the same async header (+0 sema, +4 result
                // addr, +8 result size). Complete it with an error so the EE never
                // waits forever, and log it as unimplemented.
                const uint32_t sema    = rdramRead32(rdram, sendBuf + 0x0);
                const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                const int32_t result = -48; // unsupported
                if (resAddr && resSize >= 4) rdramWrite32(rdram, resAddr, (uint32_t)result);
                rdramWrite32(rdram, recvBuf, 1u);
                const bool sig = ps2_syscalls::hleSignalSema(sema);
                fprintf(stderr, "[HW-BRIDGE:FIO] ** UNIMPLEMENTED fno=0x%X -> %d (sema %u %s)\n",
                        rpcNum, result, sema, sig ? "signaled" : "NOT signaled");
            } else {
                rdramWrite32(rdram, recvBuf, 0xFFFFFFFFu);
            }
        }
        return true;
    }

    case SIF_CDVD: {
        static int cdvdLog = 0;
        if (cdvdLog < 50) {
            printf("[HW-BRIDGE:CDVD] rpc func=%u send=0x%08X recv=0x%08X\n",
                   rpcNum, sendBuf, recvBuf);
            cdvdLog++;
        }

        switch (rpcNum) {
        case 0: // cdInit
            printf("[HW-BRIDGE:CDVD] cdInit\n");
            if (recvBuf) rdramWrite32(rdram, recvBuf, 1);
            return true;

        case 1: { // cdRead (sector-based)
            if (!sendBuf) return true;
            uint32_t lba = rdramRead32(rdram, sendBuf);
            uint32_t sectors = rdramRead32(rdram, sendBuf + 4);
            uint32_t bufAddr = rdramRead32(rdram, sendBuf + 8);
            printf("[HW-BRIDGE:CDVD] cdRead: LBA=%u sectors=%u buf=0x%08X\n",
                   lba, sectors, bufAddr);
            // TODO: Raw sector reads need ISO layout table
            if (recvBuf) rdramWrite32(rdram, recvBuf, 1);
            return true;
        }

        case 2: // cdStop
        case 3: // cdPause
        case 4: // cdGetToc
            if (recvBuf) rdramWrite32(rdram, recvBuf, 1);
            return true;

        case 5: { // cdReadFile — read file by PS2 path
            if (!sendBuf || !recvBuf || !self->m_cdvd) break;

            // Detect send buffer format: path string or structured data
            uint32_t sendPhys = sendBuf & PS2_RAM_MASK;
            if (sendPhys >= PS2_RAM_SIZE) break;
            const uint8_t* sendPtr = rdram + sendPhys;

            std::string ps2_path;
            uint32_t destAddr = 0;

            // Check if first bytes look like a path string
            if (sendPtr[0] == 'c' || sendPtr[0] == 'C' ||
                sendPtr[0] == '\\' || sendPtr[0] == '/') {
                ps2_path = (const char*)sendPtr;
                destAddr = rdramRead32(rdram, sendBuf + 256); // dest after path
                if (destAddr == 0) destAddr = recvBuf;
            } else {
                // Structured: {sectors, dest_addr, path...} or similar
                destAddr = rdramRead32(rdram, sendBuf + 4);
                uint32_t pathPhys = (sendBuf + 8) & PS2_RAM_MASK;
                if (pathPhys < PS2_RAM_SIZE) {
                    ps2_path = (const char*)(rdram + pathPhys);
                }
                if (destAddr == 0) destAddr = recvBuf;
            }

            if (!ps2_path.empty()) {
                printf("[HW-BRIDGE:CDVD] cdReadFile: %s → dest=0x%08X\n",
                       ps2_path.c_str(), destAddr);

                std::vector<uint8_t> data;
                if (self->m_cdvd->read_file(ps2_path, data)) {
                    uint32_t destPhys = destAddr & PS2_RAM_MASK;
                    if (destPhys + data.size() <= PS2_RAM_SIZE) {
                        memcpy(rdram + destPhys, data.data(), data.size());
                        printf("[HW-BRIDGE:CDVD] Loaded %zu bytes\n", data.size());
                    }
                    rdramWrite32(rdram, recvBuf, (uint32_t)data.size());
                } else {
                    printf("[HW-BRIDGE:CDVD] File not found: %s\n", ps2_path.c_str());
                    rdramWrite32(rdram, recvBuf, 0);
                }
            }
            return true;
        }

        case 6: { // cdSearchFile — check if file exists, return size
            if (!sendBuf || !recvBuf || !self->m_cdvd) break;

            uint32_t sendPhys = sendBuf & PS2_RAM_MASK;
            if (sendPhys >= PS2_RAM_SIZE) break;
            std::string ps2_path = (const char*)(rdram + sendPhys);

            printf("[HW-BRIDGE:CDVD] cdSearchFile: %s\n", ps2_path.c_str());

            if (self->m_cdvd->file_exists(ps2_path)) {
                uint32_t size = self->m_cdvd->file_size(ps2_path);
                rdramWrite32(rdram, recvBuf + 0, 1);     // LBA (fake)
                rdramWrite32(rdram, recvBuf + 4, size);   // File size
                rdramWrite32(rdram, recvBuf + 8, 0);      // Date
                printf("[HW-BRIDGE:CDVD] Found: size=%u\n", size);
            } else {
                rdramWrite32(rdram, recvBuf + 0, 0);
                rdramWrite32(rdram, recvBuf + 4, 0);
                printf("[HW-BRIDGE:CDVD] Not found\n");
            }
            return true;
        }

        case 7: // cdGetDiskType — PS2DVD
            if (recvBuf) rdramWrite32(rdram, recvBuf, 0x14);
            return true;

        case 12: // cdStatus — ready
            if (recvBuf) rdramWrite32(rdram, recvBuf, 0x0A);
            return true;

        default:
            printf("[HW-BRIDGE:CDVD] unhandled func=%u\n", rpcNum);
            if (recvBuf) rdramWrite32(rdram, recvBuf, 0);
            return true;
        }
        break;
    }

    case SIF_PADMAN: {
        // Pad input — return stable state, actual input handled by reo_pad_read override
        static int padLog = 0;
        if (padLog < 10) {
            printf("[HW-BRIDGE:PAD] rpc func=%u\n", rpcNum);
            padLog++;
        }
        switch (rpcNum) {
        case 0: // padInit
        case 2: // padPortOpen
            if (recvBuf) rdramWrite32(rdram, recvBuf, 1);
            return true;
        case 3: // padGetState → STABLE
            if (recvBuf) rdramWrite32(rdram, recvBuf, 6);
            return true;
        case 4: { // padRead
            if (recvBuf && recvSize >= 32) {
                // Fill with default pad state (all released, analog centered)
                uint32_t recvPhys = recvBuf & PS2_RAM_MASK;
                if (recvPhys + 32 <= PS2_RAM_SIZE) {
                    uint8_t* buf = rdram + recvPhys;
                    memset(buf, 0, 32);
                    buf[0] = 0x00; // success
                    buf[1] = 0x79; // DualShock2
                    buf[2] = 0xFF; // buttons high (released)
                    buf[3] = 0xFF; // buttons low (released)
                    buf[4] = 0x80; // RX
                    buf[5] = 0x80; // RY
                    buf[6] = 0x80; // LX
                    buf[7] = 0x80; // LY

                    // Read live input if available
                    if (self->m_input) {
                        const reo::DualShock2State& pad = self->m_input->get_pad(0);
                        buf[2] = (uint8_t)(pad.buttons >> 8);
                        buf[3] = (uint8_t)(pad.buttons & 0xFF);
                        buf[4] = pad.right_x;
                        buf[5] = pad.right_y;
                        buf[6] = pad.left_x;
                        buf[7] = pad.left_y;
                        memcpy(buf + 8, pad.pressure, 12);
                    }
                }
            }
            return true;
        }
        default:
            if (recvBuf) rdramWrite32(rdram, recvBuf, 0);
            return true;
        }
    }

    case SIF_MCSERV: {
        // Memory card — stub for now
        static int mcLog = 0;
        if (mcLog < 10) {
            printf("[HW-BRIDGE:MC] rpc func=%u\n", rpcNum);
            mcLog++;
        }
        if (recvBuf) rdramWrite32(rdram, recvBuf, 0);
        return true;
    }

    case SIF_LIBSD: {
        // Sound driver — stub
        static int sdLog = 0;
        if (sdLog < 10) {
            printf("[HW-BRIDGE:SD] rpc func=%u\n", rpcNum);
            sdLog++;
        }
        if (recvBuf) rdramWrite32(rdram, recvBuf, 0);
        return true;
    }

    case 0x80000003:   // SIFHEAP (IOP heap)
    case 0x80000006: { // LOADFILE
        static int hlLog = 0;
        const bool isHeap = (sid == 0x80000003);
        if (hlLog < 120) {
            char hex[3 * 48 + 1] = {0};
            if (sendBuf && sendSize) {
                const uint32_t n = std::min<uint32_t>(sendSize, 48);
                for (uint32_t i = 0; i < n; ++i)
                    snprintf(hex + i * 3, 4, "%02X ", rdram[(sendBuf + i) & PS2_RAM_MASK]);
            }
            fprintf(stderr, "[HW-BRIDGE:%s] fno=0x%X send=0x%08X/%u recv=0x%08X/%u data=[%s]\n",
                    isHeap ? "HEAP" : "LOADFILE", rpcNum, sendBuf, sendSize, recvBuf, recvSize, hex);
            hlLog++;
        }
        if (!recvBuf || recvSize < 4) return false;

        if (isHeap) {
            if (!self) return false;
            // HLE IOP heap. The runtime's sceSifSetDma aliases IOP destinations onto
            // EE RAM, so allocations come from IOP 0x88000-0xFFFFF, an EE range that
            // PCSX2 shows unused by this game (D4). Exhaustion fails loudly (0).
            uint32_t& heapNext = self->m_iopHeapNext;
            constexpr uint32_t kHeapEnd = 0x00100000u;
            if (rpcNum == 0x1 && sendBuf && sendSize >= 4) {           // alloc(size)
                const uint32_t size = rdramRead32(rdram, sendBuf);
                const uint32_t aligned = (size + 0xFFu) & ~0xFFu;
                uint32_t addr = 0u;
                if (size && heapNext + aligned <= kHeapEnd) { addr = heapNext; heapNext += aligned; }
                rdramWrite32(rdram, recvBuf, addr);
                fprintf(stderr, "[HW-BRIDGE:HEAP] alloc %u -> 0x%08X%s\n", size, addr,
                        addr ? "" : "  ** HLE IOP heap exhausted; needs a real IOP RAM model **");
                return true;
            }
            if (rpcNum == 0x2) {                                        // free(addr)
                rdramWrite32(rdram, recvBuf, 0u);
                return true;
            }
            return false;
        }

        // LOADFILE
        if (rpcNum == 0xFF) {                                           // init / version
            rdramWrite32(rdram, recvBuf, 0x30303832u); // "2800", verified against PCSX2 (D4)
            return true;
        }
        if ((rpcNum == 0x6 || rpcNum == 0x0) && sendBuf && sendSize >= 8) {
            // 6 = load module from IOP buffer: +0 IOP addr, +4 arg length, args at +0x104.
            // 0 = load module by path: path string at +0x8 (layout probable; logged).
            // HLE: modules are not executed (their services are emulated by HLE
            // servers); return a fresh id and RESIDENT_END (0).
            static int32_t nextModId = 0x10;
            const uint32_t argLen = rdramRead32(rdram, sendBuf + 4);
            std::string args;
            for (uint32_t i = 0; i < std::min<uint32_t>(argLen, 0xFC) && sendSize >= 0x104 + argLen; ++i) {
                const char ch = (char)rdram[(sendBuf + 0x104 + i) & PS2_RAM_MASK];
                args.push_back(ch ? ch : ' ');
            }
            std::string what;
            if (rpcNum == 0x6) {
                // Best effort: IRX module name from the .iopmod-style header if present.
                const uint32_t iopAddr = rdramRead32(rdram, sendBuf);
                char hdr[5] = {0};
                for (int i = 0; i < 4; ++i) hdr[i] = (char)rdram[(iopAddr + i) & PS2_RAM_MASK];
                char buf[64];
                snprintf(buf, sizeof buf, "buffer@IOP 0x%08X (magic %02X%02X%02X%02X)", iopAddr,
                         (uint8_t)hdr[0], (uint8_t)hdr[1], (uint8_t)hdr[2], (uint8_t)hdr[3]);
                what = buf;
            } else {
                for (uint32_t i = 8; i < std::min<uint32_t>(sendSize, 8 + 0x100); ++i) {
                    const char ch = (char)rdram[(sendBuf + i) & PS2_RAM_MASK];
                    if (!ch) break;
                    what.push_back(ch);
                }
            }
            const int32_t id = nextModId++;
            rdramWrite32(rdram, recvBuf, (uint32_t)id);
            if (recvSize >= 8) rdramWrite32(rdram, recvBuf + 4, 0u);
            fprintf(stderr, "[HW-BRIDGE:LOADFILE] load %s args=\"%s\" -> id %d (HLE, not executed)\n",
                    what.c_str(), args.c_str(), id);
            return true;
        }
        return false;
    }

    default: {
        static int unknownLog = 0;
        if (unknownLog < 20) {
            printf("[HW-BRIDGE:SIF] unhandled sid=0x%08X func=%u\n", sid, rpcNum);
            unknownLog++;
        }
        return false; // Not handled — let PS2Recomp deal with it
    }
    }
    return false;
}

// Write directly to the GS renderer's framebuffer (bypasses GIF entirely)
void reo_gs_write_framebuffer(const uint32_t* pixels, int width, int height) {
    auto* self = ReoHwBridge::s_instance;
    if (self && self->m_gs) {
        uint32_t* fb = self->m_gs->framebuffer_mut();
        if (fb) {
            int fbW = self->m_gs->fb_width();
            int fbH = self->m_gs->fb_height();
            int copyW = std::min(width, fbW);
            int copyH = std::min(height, fbH);
            for (int y = 0; y < copyH; y++) {
                memcpy(fb + y * fbW, pixels + y * width, copyW * 4);
            }
        }
    }
}

// Direct GIF PATH3 submission — bypasses DMA, sends GIF data straight to GS
void reo_gs_submit_path3_direct(const void* data, uint32_t bytes) {
    auto* self = ReoHwBridge::s_instance;
    if (self && self->m_gs) {
        self->m_gs->submit_path3(data, bytes);
        static int logC = 0;
        if (logC < 5) {
            printf("[HW-BRIDGE] Direct GIF submit: %u bytes\n", bytes);
            logC++;
        }
    }
}

// Direct VRAM access — upload pixel/CLUT data to GS VRAM at byte offset
uint8_t* reo_gs_vram() {
    auto* self = ReoHwBridge::s_instance;
    return (self && self->m_gs) ? self->m_gs->vram() : nullptr;
}

uint32_t reo_gs_vram_size() {
    return reo::GSRenderer::VRAM_SIZE;
}
