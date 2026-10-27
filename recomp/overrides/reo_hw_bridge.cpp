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
#include "network/native/netcnf_profile.h"
#include "network/native/private_usb_keyboard.h"
#include "network/native/automatic_account.h"
#include "network/native/game_addresses.h"
#include "reo_trace_logger.h"
#include "runtime/gs/gs_renderer.h"
#include "runtime/vu/vu_interpreter.h"
#include "runtime/input/input.h"
#include "runtime/input/pad2_rumble.h"
#include "runtime/memory_card/card_rpc.h"
#include "runtime/cdvd/cdvd.h"
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <map>
#include <string>
#include "source_instruction_access.hpp"
#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <xinput.h>
#endif

void reoPad2Stop();

namespace ps2_syscalls {
bool hleSignalSema(uint32_t semaId);
}
namespace ps2_stubs {
uint32_t hleIopRebootCount();
}

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

    uint8_t* vu0_code = rdram + (PS2_VU0_CODE_BASE & ps2RamBackingMask());
    uint8_t* vu0_data = rdram + (PS2_VU0_DATA_BASE & ps2RamBackingMask());
    uint8_t* vu1_code = rdram + (PS2_VU1_CODE_BASE & ps2RamBackingMask());
    uint8_t* vu1_data = rdram + (PS2_VU1_DATA_BASE & ps2RamBackingMask());

    // Initialize VU interpreters
    m_vu0 = new reo::VUInterpreter(0, vu0_code, PS2_VU0_CODE_SIZE, vu0_data, PS2_VU0_DATA_SIZE);

    m_vu1 = new reo::VUInterpreter(1, vu1_code, PS2_VU1_CODE_SIZE, vu1_data, PS2_VU1_DATA_SIZE);

    // Wire VU1 XGKICK → GS PATH1
    m_vu1->set_xgkick_callback(
        [](const void* data, uint32_t max_size, void* user) {
            auto* gs = static_cast<reo::GSRenderer*>(user);
            gs->submit_path1(data, max_size);
        },
        m_gs);

    // Wire VU0 XGKICK → GS PATH1 (VU0 can also XGKICK, though rare)
    m_vu0->set_xgkick_callback(
        [](const void* data, uint32_t max_size, void* user) {
            auto* gs = static_cast<reo::GSRenderer*>(user);
            gs->submit_path1(data, max_size);
        },
        m_gs);

    // Initialize input system
    m_input = new reo::Input();
    m_input->init();

    // Initialize CDVD filesystem (reads from game_data/)
    auto cdRoot = PS2Runtime::getIoPaths().cdRoot;
    if (!cdRoot.empty()) {
        m_cdvd = new reo::CDVD(cdRoot);
        printf("[HW-BRIDGE] CDVD initialized: %s\n", cdRoot.string().c_str());
    }

    // Graphics pipeline. Default "upstream": PS2Recomp's own VIF1 -> VU1 -> GIF arbiter
    // -> GS -> presentation path (its VU1 decodes per PCSX2's VUops tables). The bridge's
    // duplicate VIF1/VU1/GS path (REO_GFX=bridge) mis-decodes VU lower instructions and is
    // kept only for comparison (docs/DIVERGENCES.md D24).
    const char* gfx = std::getenv("REO_GFX");
    m_bridgeGfx = gfx && std::strcmp(gfx, "bridge") == 0;
    printf("[HW-BRIDGE] graphics pipeline: %s\n",
           m_bridgeGfx ? "bridge (reo VU1/GS)" : "upstream (PS2Recomp VIF1/VU1/GS)");

    if (m_bridgeGfx) {
        // Register callbacks with PS2Memory
        PS2Memory::HwBridgeCallbacks memCb;
        memCb.onDmaStart = &ReoHwBridge::onDmaStart;
        memCb.onGsRegWrite = &ReoHwBridge::onGsRegWrite;
        memCb.user = this;
        runtime.memory().setHwBridge(memCb);
    }

    // Register callbacks with PS2Runtime
    PS2Runtime::HwBridgeVtable rtVt;
    rtVt.onVuStart = &ReoHwBridge::onVuStart; // VU0 VCALLMS (upstream only stubs VU0 micro)
    rtVt.getFramebuffer = m_bridgeGfx ? &ReoHwBridge::getFramebuffer : nullptr;
    rtVt.onSifRpc = &ReoHwBridge::onSifRpc;
    rtVt.user = this;
    runtime.setHwBridgeVt(rtVt);

    printf("[HW-BRIDGE] Bridge initialized:\n");
    printf("[HW-BRIDGE]   GS: headless software rasterizer (640x448)\n");
    printf("[HW-BRIDGE]   VU0: interpreter (%u bytes code, %u bytes data)\n", PS2_VU0_CODE_SIZE,
           PS2_VU0_DATA_SIZE);
    printf("[HW-BRIDGE]   VU1: interpreter (%u bytes code, %u bytes data)\n", PS2_VU1_CODE_SIZE,
           PS2_VU1_DATA_SIZE);
    printf("[HW-BRIDGE]   DMA: GIF + VIF1 interception active\n");

    // Initialize trace logger (only active if REO_TRACE=1)
    ReoTraceLogger::instance().init();

    return true;
}

void ReoHwBridge::shutdown() {
    reoPad2Stop();
    ReoTraceLogger::instance().shutdown();
    m_network.reset();
    m_privateKeyboard.reset();
    m_netProfile.reset();

    if (m_gs) {
        printf("[HW-BRIDGE] Stats: gif_packets=%llu vif1_dmas=%llu vu0_runs=%llu "
               "vu1_runs=%llu gs_reg_writes=%llu\n",
               (unsigned long long)m_gifPackets, (unsigned long long)m_vif1Dmas,
               (unsigned long long)m_vu0Runs, (unsigned long long)m_vu1Runs,
               (unsigned long long)m_gsRegWrites);
    }

    delete m_cdvd;
    m_cdvd = nullptr;
    if (m_input) {
        m_input->shutdown();
        delete m_input;
        m_input = nullptr;
    }
    delete m_vu1;
    m_vu1 = nullptr;
    delete m_vu0;
    m_vu0 = nullptr;
    if (m_gs) {
        m_gs->shutdown();
        delete m_gs;
        m_gs = nullptr;
    }

    if (s_instance == this)
        s_instance = nullptr;
    m_runtime = nullptr;
}

// ── PS2Memory callback: DMA channel start ───────────────────────────

void ReoHwBridge::onDmaStart(uint32_t channelBase, uint32_t madr, uint32_t qwc, uint32_t tadr,
                             const uint8_t* rdram, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);

    switch (channelBase) {
        case 0x1000A000: {
            // GIF DMA (PATH3) — forward GIF packets to GS renderer
            self->m_gifPackets++;

            if (qwc > 0) {
                // Normal mode: data at madr, qwc quadwords
                uint32_t phys = madr & ps2RamBackingMask();
                uint32_t bytes = qwc * 16;
                if (phys + bytes <= ps2RamBackingBytes) {
                    REO_TRACE_DMA_GIF(madr, qwc, rdram + phys, bytes);
                    self->m_gs->submit_path3(rdram + phys, bytes);
                }
            } else {
                // Source chain mode: follow DMA tags from tadr until END/REFE
                uint32_t curTag = tadr;
                int chainDepth = 0;
                constexpr int MAX_CHAIN = 256;
                while (chainDepth < MAX_CHAIN) {
                    uint32_t physTag = curTag & ps2RamBackingMask();
                    if (physTag + 16 > ps2RamBackingBytes)
                        break;

                    uint64_t tag;
                    reo_source_instrumentation::copyBytes(&tag, rdram + physTag, sizeof(tag));
                    uint16_t tagQwc = (uint16_t)(tag & 0xFFFF);
                    uint32_t tagId = (uint32_t)((tag >> 28) & 0x7);
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
                        uint32_t phys = dataAddr & ps2RamBackingMask();
                        uint32_t bytes = tagQwc * 16;
                        if (phys + bytes <= ps2RamBackingBytes) {
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
                            uint32_t nextAddr = tagAddr & ps2RamBackingMask();
                            if (nextAddr + 16 <= ps2RamBackingBytes && nextAddr != 0) {
                                static int skipLog = 0;
                                if (skipLog < 10) {
                                    printf("[HW-BRIDGE] GIF: skipping sentinel REFE/QWC=0, chain "
                                           "continues at 0x%08X\n",
                                           nextAddr);
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
                printf(
                    "[HW-BRIDGE] GIF DMA: madr=0x%08X qwc=%u tadr=0x%08X (total packets: %llu)\n",
                    madr, qwc, tadr, (unsigned long long)self->m_gifPackets);
                logCount++;
            }
            break;
        }
        case 0x10009000: {
            // VIF1 DMA — parse VIF commands to find UNPACK/MSCAL/DIRECT
            self->m_vif1Dmas++;

            if (qwc > 0) {
                uint32_t phys = madr & ps2RamBackingMask();
                uint32_t bytes = qwc * 16;
                if (phys + bytes <= ps2RamBackingBytes)
                    REO_TRACE_DMA_VIF1(madr, qwc, tadr, rdram + phys, bytes);
                self->processVif1Dma(madr, qwc, rdram);
            } else {
                REO_TRACE_DMA_VIF1(madr, 0, tadr, nullptr, 0);
                self->processVif1DmaChain(tadr, rdram);
            }

            static int logCount = 0;
            if (logCount < 8) {
                printf("[HW-BRIDGE] VIF1 DMA: madr=0x%08X qwc=%u tadr=0x%08X (total: %llu)\n", madr,
                       qwc, tadr, (unsigned long long)self->m_vif1Dmas);
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

void ReoHwBridge::onVuStart(int unit, uint32_t addr, uint8_t* rdram, R5900Context* ctx,
                            void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);
    self->executeVu(unit, addr, rdram, ctx);
}

// ── PS2Runtime callback: get rendered framebuffer ───────────────────

const uint32_t* ReoHwBridge::getFramebuffer(int* width, int* height, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);
    if (!self->m_gs)
        return nullptr;

    int w = self->m_gs->fb_width();
    int h = self->m_gs->fb_height();
    *width = w;
    *height = h;

    const uint32_t* src = self->m_gs->framebuffer();
    if (!src)
        return nullptr;

    // Overlay buffer: copy framebuffer and draw debug info on top
    static uint32_t* overlay = nullptr;
    static int overlay_size = 0;
    if (!overlay || overlay_size != w * h) {
        delete[] overlay;
        overlay = new uint32_t[w * h];
        overlay_size = w * h;
    }
    reo_source_instrumentation::copyBytes(overlay, src, w * h * sizeof(uint32_t));

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
    static const uint8_t font_R[] = {0x7C, 0x42, 0x42, 0x7C, 0x48, 0x44, 0x42};
    static const uint8_t font_E[] = {0x7E, 0x40, 0x40, 0x7C, 0x40, 0x40, 0x7E};
    static const uint8_t font_O[] = {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C};
    static const uint8_t font_digits[][7] = {
        {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, {0x08, 0x18, 0x08, 0x08, 0x08, 0x08, 0x1C},
        {0x3C, 0x42, 0x02, 0x1C, 0x20, 0x40, 0x7E}, {0x3C, 0x42, 0x02, 0x1C, 0x02, 0x42, 0x3C},
        {0x04, 0x0C, 0x14, 0x24, 0x7E, 0x04, 0x04}, {0x7E, 0x40, 0x7C, 0x02, 0x02, 0x42, 0x3C},
        {0x3C, 0x40, 0x7C, 0x42, 0x42, 0x42, 0x3C}, {0x7E, 0x02, 0x04, 0x08, 0x10, 0x10, 0x10},
        {0x3C, 0x42, 0x42, 0x3C, 0x42, 0x42, 0x3C}, {0x3C, 0x42, 0x42, 0x3E, 0x02, 0x42, 0x3C},
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
    int digits[8];
    int nd = 0;
    if (fc == 0)
        digits[nd++] = 0;
    else
        while (fc > 0 && nd < 8) {
            digits[nd++] = fc % 10;
            fc /= 10;
        }
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
    uint32_t phys = madr & ps2RamBackingMask();
    uint32_t bytes = qwc * 16;
    if (phys + bytes > ps2RamBackingBytes)
        return;

    processVifCommands(rdram + phys, bytes, rdram);
}

void ReoHwBridge::processVif1DmaChain(uint32_t tadr, const uint8_t* rdram) {
    // Walk DMA chain tags
    constexpr int MAX_CHAIN = 256; // Safety limit
    uint32_t currentTag = tadr;

    for (int i = 0; i < MAX_CHAIN; i++) {
        uint32_t physTag = currentTag & ps2RamBackingMask();
        if (physTag + 16 > ps2RamBackingBytes)
            break;

        uint64_t tag;
        reo_source_instrumentation::copyBytes(&tag, rdram + physTag, sizeof(tag));

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
            uint32_t phys = dataAddr & ps2RamBackingMask();
            uint32_t bytes = tagQwc * 16;
            if (phys + bytes <= ps2RamBackingBytes) {
                processVifCommands(rdram + phys, bytes, rdram);
            }
        }

        if (endChain || irq)
            break;
    }
}

void ReoHwBridge::processVifCommands(const uint8_t* data, uint32_t size, const uint8_t* rdram) {
    uint32_t pos = 0;

    while (pos + 4 <= size) {
        uint32_t vifcode;
        reo_source_instrumentation::copyBytes(&vifcode, data + pos, 4);

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
                // VU1 TPC is 11 bits: the address wraps (PCSX2 vu1ExecMicro: addr & 0x7FF, << 3).
                uint32_t vuAddr = ((uint32_t)immediate & 0x7FFu) * 8;
                pos += 4;

                m_vu1Runs++;
                m_vu1->start(vuAddr);
                m_vu1->run(65536);

                static int logCount = 0;
                if (logCount < 16) {
                    printf("[HW-BRIDGE] VIF1 MSCAL: VU1 start @0x%04X (run #%llu)\n", vuAddr,
                           (unsigned long long)m_vu1Runs);
                    logCount++;
                }
                break;
            }
            case 0x15: // MSCALF
            {
                // VU1 TPC is 11 bits: the address wraps (PCSX2 vu1ExecMicro: addr & 0x7FF, << 3).
                uint32_t vuAddr = ((uint32_t)immediate & 0x7FFu) * 8;
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
                if (pos + 4 <= size)
                    pos += 4; // Skip mask data word
                break;

            case 0x30: // STROW
                pos += 4;
                if (pos + 16 <= size)
                    pos += 16; // Skip 4 words
                break;

            case 0x31: // STCOL
                pos += 4;
                if (pos + 16 <= size)
                    pos += 16; // Skip 4 words
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
                        case 0x0:
                            bytesPerVector = 16;
                            break; // S-32 (4x32)
                        case 0x1:
                            bytesPerVector = 16;
                            break; // S-16 (4x16, expanded)
                        case 0x2:
                            bytesPerVector = 16;
                            break; // S-8 (4x8, expanded)
                        case 0x4:
                            bytesPerVector = 8;
                            break; // V2-32
                        case 0x5:
                            bytesPerVector = 4;
                            break; // V2-16
                        case 0x6:
                            bytesPerVector = 2;
                            break; // V2-8
                        case 0x8:
                            bytesPerVector = 12;
                            break; // V3-32
                        case 0x9:
                            bytesPerVector = 6;
                            break; // V3-16
                        case 0xA:
                            bytesPerVector = 3;
                            break; // V3-8
                        case 0xC:
                            bytesPerVector = 16;
                            break; // V4-32
                        case 0xD:
                            bytesPerVector = 8;
                            break; // V4-16
                        case 0xE:
                            bytesPerVector = 4;
                            break; // V4-8
                        case 0xF:
                            bytesPerVector = 2;
                            break; // V4-5 (packed 16-bit)
                        default:
                            bytesPerVector = 16;
                            break;
                    }

                    uint32_t dataBytes = num * bytesPerVector;
                    // Align to 32 bits
                    dataBytes = (dataBytes + 3) & ~3;
                    pos += 4;

                    // Copy unpack data to VU1 data memory
                    // The VU interpreter already points at the right rdram region
                    uint32_t vuDst = (uint32_t)immediate * 16; // Destination in bytes
                    if (pos + dataBytes <= size && format == 0x0C &&
                        vuDst + num * 16 <= PS2_VU1_DATA_SIZE) {
                        // Fast path for V4-32 (most common): direct 128-bit copy
                        uint8_t* vu1_data =
                            m_vu1->state().vf[0].f == 0
                                ? nullptr
                                : nullptr; // Can't directly access VU data memory here
                        // The VUInterpreter constructor stored the data_mem pointer,
                        // but we need the bridge's pointer. Use the rdram offset.
                        // VU1 data memory is at rdram + (0x1100C000 & ps2RamBackingMask())
                        uint8_t* vu1_data_mem =
                            const_cast<uint8_t*>(rdram) + (PS2_VU1_DATA_BASE & ps2RamBackingMask());
                        reo_source_instrumentation::copyBytes(vu1_data_mem + vuDst, data + pos,
                                                              num * 16);
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
    reo_source_instrumentation::EntryScope sourceEntry(m_runtime, ctx);
    reo_source_instrumentation::rejectOwnedCpuGraphics(m_runtime);
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
            REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_vf[i]) = _mm_loadu_ps(vs.vf[i].f);
        }

        // Copy VI registers
        for (int i = 0; i < 16; i++) {
            REO_SOURCE_WRITE(rdram, ctx, ctx->vi[i]) = vs.vi[i];
        }

        // Copy status
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_q) = vs.q;
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_p) = 0; // VU0 has no P register (EFU)
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_acc) =
            _mm_set_ps(vs.acc[3], vs.acc[2], vs.acc[1], vs.acc[0]);
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_mac_flags) = vs.status;
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_clip_flags) = vs.clip_flag;
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_clip_flags2) = 0;
        REO_SOURCE_WRITE(rdram, ctx, ctx->vu0_status) = 0; // Clear running status
    }

    static int logCount = 0;
    if (logCount < 16) {
        printf("[HW-BRIDGE] VU%d micro @0x%04X completed (run #%llu)\n", unit, addr,
               (unsigned long long)counter);
        logCount++;
    }
}

// ── SIF RPC callback: handle IOP module calls ───────────────────────

// SIF RPC module IDs (PS2 IOP modules)
static constexpr uint32_t SIF_FILEIO = 0x80000001;
static constexpr uint32_t SIF_PADMAN = 0x80000100;
static constexpr uint32_t SIF_MCSERV = 0x80000400;
static constexpr uint32_t SIF_CDVD = 0x80000592;
static constexpr uint32_t SIF_LIBSD = 0x80000701;

// Helper: read a uint32 from rdram
static inline uint32_t rdramRead32(const uint8_t* rdram, uint32_t addr) {
    uint32_t phys = addr & ps2RamBackingMask();
    if (phys + 4 > ps2RamBackingBytes)
        return 0;
    uint32_t v;
    reo_source_instrumentation::copyBytesForBank(rdram, &v, rdram + phys, 4);
    return v;
}

// Helper: write a uint32 to rdram
static inline void rdramWrite32(uint8_t* rdram, uint32_t addr, uint32_t val) {
    uint32_t phys = addr & ps2RamBackingMask();
    if (phys + 4 > ps2RamBackingBytes)
        return;
    reo_source_instrumentation::copyBytesForBank(rdram, rdram + phys, &val, 4);
}

// ── libpad2 / dbcman pad data (IOP side) ────────────────────────────────
// SLUS-20765 uses libpad2 on libdbc. scePad2CreateSocket (EE 0x180378) hands dbcman an
// EE buffer of two 0x80-byte records; the IOP keeps refreshing them and the EE picks the
// record with the larger sequence word (+0x7C) (EE 0x180970). Record layout as read by
// scePad2GetState/GetButtonProfile/Read (EE 0x180680/0x1805B0/0x1804D8):
//   +0 state (0 none, 1 stable/readable, 2/3 busy executing a command)  +2 data length  +3 profile length
//   +4 valid word  +0x1C data bytes then profile bytes  +0x7C sequence
// Profile = 40-bit mask of libpad2 button ids (0..15 digital, packed LSB-first; 0x10..0x1F
// and 0x23..0x26 8-bit). Records are built exactly as the disc's DualShock2 driver
// ds2u_s1 (IOP/MODULES/DRIVE.DAT module 3, FUN_00001170) builds them for a pad in
// digital mode (SIO id 0x41): +1 = 6, +2 = 2, +3 = 4, profile F9 FF 00 00 (no L3/R3), and
// the raw active-low SIO bytes b0 (SELECT L3 R3 START UP RIGHT DOWN LEFT) and
// b1 (L2 R2 L1 R1 TRIANGLE CIRCLE CROSS SQUARE) repacked in button-id order:
//   d0 = (b0 & 1) | ((b0 & 0xF8) >> 2) | (b1 << 6)   d1 = b1 >> 2
// Input: REO_PAD_SCRIPT="<sec>:<BTN>[+<BTN>][:<holdSec>],..." (seconds since start,
// default hold 0.2 s) for reproducible headless runs.
namespace {
struct Pad2Feeder {
    std::mutex m;
    std::vector<uint32_t> sockets; // EE record-pair buffers
    uint32_t workAddr = 0;         // sceDbcSetWorkAddr area: per-port connection words
    uint32_t nextSocketId = 0;
    std::atomic<uint32_t> outputSocket{UINT32_MAX};
    std::atomic<uint32_t> motors{0};
    uint8_t* rdram = nullptr;
    bool started = false;
    std::atomic<bool> stop{false};
    std::thread thread;
    struct Press {
        double t, hold;
        uint16_t mask;
    };
    std::vector<Press> script;
    std::atomic<uint16_t> lastPressed{0}; // for the debug panel
    std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
};
Pad2Feeder g_pad2;

uint16_t pad2ButtonBit(const std::string& n) {
    static const char* names[16] = {"SELECT",   "L3",     "R3",    "START", "UP", "RIGHT",
                                    "DOWN",     "LEFT",   "L2",    "R2",    "L1", "R1",
                                    "TRIANGLE", "CIRCLE", "CROSS", "SQUARE"};
    for (int i = 0; i < 16; ++i)
        if (n == names[i])
            return (uint16_t)(1u << i);
    return 0;
}

void pad2ParseScript() {
    const char* e = std::getenv("REO_PAD_SCRIPT");
    if (!e)
        return;
    std::string all(e), item;
    size_t p = 0;
    while (p <= all.size()) {
        size_t q = all.find(',', p);
        item = all.substr(p, q == std::string::npos ? std::string::npos : q - p);
        p = (q == std::string::npos) ? all.size() + 1 : q + 1;
        size_t c1 = item.find(':');
        if (c1 == std::string::npos)
            continue;
        size_t c2 = item.find(':', c1 + 1);
        Pad2Feeder::Press pr{std::atof(item.substr(0, c1).c_str()),
                             c2 == std::string::npos ? 0.2 : std::atof(item.substr(c2 + 1).c_str()),
                             0};
        std::string btns =
            item.substr(c1 + 1, c2 == std::string::npos ? std::string::npos : c2 - c1 - 1);
        size_t b = 0;
        while (b <= btns.size()) {
            size_t pl = btns.find('+', b);
            pr.mask |=
                pad2ButtonBit(btns.substr(b, pl == std::string::npos ? std::string::npos : pl - b));
            b = (pl == std::string::npos) ? btns.size() + 1 : pl + 1;
        }
        if (pr.mask)
            g_pad2.script.push_back(pr);
    }
    fprintf(stderr, "[PAD2] script: %zu presses\n", g_pad2.script.size());
}

uint16_t pad2AutomaticAccount(uint8_t* rd, double now) {
    namespace account = reo_network::automatic_account;
    if (!rd || !account::enabled() || !account::armed.load()) return 0;
    static account::Flow flow;
    static unsigned generation = 0;
    static double nextStatusRead = 0;
    static std::string status;
    const unsigned attempt = account::generation.load();
    if (generation != attempt) {
        generation = attempt; flow = {}; status.clear(); nextStatusRead = 0;
    }
    if (now >= nextStatusRead) {
        status = account::status();
        nextStatusRead = now + .25;
    }
    const auto suffix = " " + std::to_string(attempt);
    if (status == "error" + suffix) account::completed.store(true);
    if (status != "ready" + suffix && status != "typed" + suffix) return 0;
    const auto byte = [rd](uint32_t address) {
        return reo_source_instrumentation::bankRead(rd, rd + address);
    };
    const auto word = [rd](uint32_t address) {
        uint32_t value = 0;
        reo_source_instrumentation::copyBytesForBank(rd, &value, rd + address, sizeof(value));
        return value;
    };
    account::Menu menu;
#if defined(REO_GAME_FILE2)
    menu.gameFile2 = true;
    menu.cardStage = byte(reo_network::game::menu.step + 0x160);
    menu.cardDialog = byte(reo_network::game::menu.step + 0x161);
    menu.cardKind = word(reo_network::game::menu.step + 0x180);
    menu.cardMessage = word(reo_network::game::menu.step + 0x16C);
    menu.cardDelay = int32_t(word(reo_network::game::menu.step + 0x184));
#endif
    menu.originalEditorReady = attempt != 0 && account::editorReadyGeneration.load() == attempt;
    menu.step = byte(reo_network::game::menu.step); menu.substep = byte(reo_network::game::menu.substep);
    menu.cursor = int16_t(word(reo_network::game::menu.cursor)); menu.delay = int16_t(word(reo_network::game::menu.delay));
    menu.upperDelay = int16_t(word(reo_network::game::menu.delay) >> 16);
    menu.choice = byte(reo_network::game::menu.choice);
    if (menu.step == 6 && word(reo_network::game::menu.profileStage) == 5) {
        const uint32_t profile = word(reo_network::game::menu.profileWork);
        if (profile >= 0x100000 && profile <= ps2RamBackingBytes - 0x50) {
            menu.profileStage = byte(profile + 0x20);
            menu.profileCursor = byte(profile + 0x10);
            menu.profileReady = byte(profile + 0x4C) == 1 && byte(profile + 0x24) > 0;
        }
    }
    const uint32_t keyboard = word(reo_network::game::menu.keyboardWork);
    menu.keyboardValid = keyboard >= 0x100000 && keyboard <= ps2RamBackingBytes - 0x700;
    if (menu.keyboardValid) {
        menu.keyboardActive = byte(keyboard + 0x28) == 1;
        menu.keyboardDone = byte(keyboard + 0x36) != 0;
    }
    menu.keyboardDelay = byte(reo_network::game::menu.keyboardDelay);
    menu.passwordPresent = byte(reo_network::game::menu.password) != 0;
    const auto decision = flow.tick(menu, now, true, status == "typed" + suffix);
    if (decision.requestPassword) std::fprintf(stderr, "\n[COOP-AUTO] password-ready %u\n", attempt);
    if (decision.submitted) {
        account::completed.store(true);
        std::fprintf(stderr, "[COOP-AUTO] login-submitted %u\n", attempt);
    }
    switch (decision.button) {
        case account::Button::Confirm: return pad2ButtonBit("CROSS");
        case account::Button::Up: return pad2ButtonBit("UP");
        case account::Button::Down: return pad2ButtonBit("DOWN");
        default: return 0;
    }
}

// Test-only route through original guest handlers. These reads observe menu state;
// the only output is ordinary pad input, never a guest state/PC write.
uint16_t pad2TestRoute(uint8_t* rd, double now) {
    static const int target = []() {
        const char* e = std::getenv("REO_TEST_ROUTE");
        if (!e)
            return 0;
        if (std::strcmp(e, "title") == 0)
            return 5;
        if (std::strcmp(e, "main-menu") == 0)
            return 1;
        if (std::strcmp(e, "scenario") == 0)
            return 2;
        if (std::strcmp(e, "character") == 0)
            return 3;
        if (std::strcmp(e, "gameplay") == 0)
            return 4;
        if (std::strcmp(e, "network-connect") == 0)
            return 6;
        if (std::strcmp(e, "network-account") == 0)
            return 7;
        if (std::strcmp(e, "network-login") == 0)
            return 8;
        if (std::strcmp(e, "network-auto") == 0)
            return 9;
        fprintf(stderr, "[TEST-ROUTE] invalid REO_TEST_ROUTE=%s; disabled\n", e);
        return 0;
    }();
    static bool done = false;
    static double pressUntil = 0, releaseUntil = 0;
    static uint16_t button = 0;
    static unsigned attempts = 0;
    static uint32_t lastState = ~0u;
    static uint32_t lastSelectionState = ~0u;
    static bool networkSelected = false, profileChosen = false, editorChosen = false;
    static bool passwordInputReady = false, loginSubmitPulse = false;
    if (!target || done || !rd)
        return 0;
    if (now > (target >= 6 ? 300 : target == 4 ? 180 : 120)) {
        fprintf(stderr, "[TEST-ROUTE] timeout t=%.3f; automatic input disabled\n", now);
        done = true;
        return 0;
    }
    // Stop cinematic Start immediately when original room state is reached: a
    // held Start crossing that boundary would open the gameplay inventory.
    if (target == 4 && reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) == 2u) {
        fprintf(stderr, "[TEST-ROUTE] reached gameplay t=%.3f modal=%u; automatic input disabled\n",
                now, reo_source_instrumentation::bankRead(rd, rd + (0x4BADEEu)));
        done = true;
        button = 0;
        return 0;
    }
    if (now < pressUntil)
        return button;
    if (loginSubmitPulse) {
        fprintf(stderr,
                "[TEST-ROUTE] login-submitted t=%.3f; Entry input sent, authentication not "
                "verified; automatic input disabled\n",
                now);
        done = true;
        button = 0;
        return 0;
    }
    if (now < releaseUntil)
        return 0;
    auto word = [rd](uint32_t a) {
        uint32_t value = 0;
        reo_source_instrumentation::copyBytesForBank(rd, &value, rd + a, sizeof(value));
        return value;
    };
    auto pointer = [](uint32_t a, uint32_t bytes) {
        // Reject null, MMIO and unrelated aliases before dereferencing.
        return a >= 0x100000u && a < ps2RamBackingBytes && bytes <= ps2RamBackingBytes - a;
    };
    const uint32_t front = word(reo_network::game::frontMenu);
    uint32_t state = 0;
    if (pointer(front, 0x74u)) {
        state = word(front) & 0x00FFFFFFu;
        if (state != lastState) {
            fprintf(stderr, "[TEST-ROUTE] t=%.3f front=%08x state=%06x\n", now, front, state);
            lastState = state;
        }
        // 57F620 accepts input in byte +1 == 5. 5811F0's idle stage is +1 == 2.
        const bool mainMenu = (state & 0xFFFFu) == 0x0501u;
        const bool scenario = (state & 0xFFFFu) == 0x0202u && word(front + 0x64u) == 0;
        const uint32_t selection = (target == 3 || target == 4) ? word(0x32442Cu) : 0;
        const bool hasSelection = pointer(selection, 0x24u);
        const uint32_t selectionState = hasSelection ? word(selection + 4u) : 0;
        const bool selectionReady = hasSelection && word(selection + 0x20u) == 0;
        if ((target == 3 || target == 4) && selectionState != lastSelectionState) {
            fprintf(stderr, "[TEST-ROUTE] t=%.3f selection=%08x state=%08x\n", now, selection,
                    selectionState);
            lastSelectionState = selectionState;
        }
        const bool character = selectionReady && (selectionState & 0xFFFFu) == 0x0109u;
        const bool title = state ==
#if defined(REO_GAME_FILE2)
            0x030100u;
#else
            0x030200u;
#endif
        if ((target == 5 && title) || (target == 1 && mainMenu) ||
            (target == 2 && scenario) || (target == 3 && character)) {
            fprintf(stderr, "[TEST-ROUTE] reached %s t=%.3f state=%06x; automatic input disabled\n",
                    target == 5   ? "title"
                    : target == 1 ? "main-menu"
                    : target == 2 ? "scenario"
                                  : "character",
                    now, state);
            done = true;
            return 0;
        }
        if (title
#if defined(REO_GAME_FILE2)
            || state == 0x020000u // Original frontend opening movie; Start skips it.
#endif
        )
            button = pad2ButtonBit("START"); // 580110, title prompt
        else if (target >= 6 && mainMenu && word(front + 0x64u) == 0) {
            const auto cursor = reo_source_instrumentation::bankRead(rd, rd + front + 0xCu);
            button = pad2ButtonBit(cursor == 1 ? "CROSS" : "DOWN");
            if (cursor == 1)
                networkSelected = true;
        } else if (target >= 2 && mainMenu && word(front + 0x64u) == 0)
            button = pad2ButtonBit("CROSS"); // confirm SINGLE PLAY
        else if (target >= 3 && scenario && (!hasSelection || (selectionState & 0xFFFFu) == 0))
            button = pad2ButtonBit("CROSS"); // enter original scenario selection
        else if (target >= 3 && selectionReady && (selectionState & 0xFFFFu) == 0x0108u)
            button = pad2ButtonBit("CROSS"); // 5838E0: idle scenario, debounce timer expired
        else if (target == 4 && character)
            button = pad2ButtonBit("CROSS"); // 584D90: original character idle/timer gate
        else if (target == 4 && hasSelection && (selectionState & 0xFFFFu) == 0x050Bu)
            button = pad2ButtonBit("CROSS"); // 587640 case5: difficulty, no +20 timer gate
        else
            button = 0;
    } else
        button = 0;
    if (target >= 6 && networkSelected) {
        if (target == 9 && reo_network::automatic_account::armed.load()) {
            std::fprintf(stderr, "[TEST-ROUTE] native network reached; account provider takes over\n");
            done = true;
            return 0;
        }
        const auto byte = [rd](uint32_t address) {
            return reo_source_instrumentation::bankRead(rd, rd + address);
        };
        const uint8_t step = byte(reo_network::game::menu.step), substep = byte(reo_network::game::menu.substep);
        static uint32_t lastNetworkState = ~0u;
        const uint32_t networkState = uint32_t(step) | uint32_t(substep) << 8;
        if (networkState != lastNetworkState) {
            std::fprintf(stderr, "[TEST-ROUTE] network t=%.3f step=%u substep=%u cursor=%d choice=%u\n",
                now, unsigned(step), unsigned(substep), int(int16_t(word(reo_network::game::menu.cursor))), unsigned(byte(reo_network::game::menu.choice)));
            lastNetworkState = networkState;
        }
        if (target == 6 && profileChosen && (step == 7 || step == 31 || step == 33)) {
            fprintf(stderr,
                    "[TEST-ROUTE] original network connection phase reached t=%.3f step=%u; "
                    "automatic input disabled\n",
                    now, step);
            done = true;
            return 0;
        }
        if (target == 7 && editorChosen && step == 45) {
            fprintf(
                stderr,
                "[TEST-ROUTE] original account editor launched t=%.3f; automatic input disabled\n",
                now);
            done = true;
            return 0;
        }
        if (step == 1 && substep == 1 && int16_t(word(reo_network::game::menu.delay) >> 16) <= 0)
            button = pad2ButtonBit("CROSS");
        else if (step == 2 && (substep == 4 || substep == 21) && int16_t(word(reo_network::game::menu.delay) >> 16) <= 0)
            button = pad2ButtonBit(byte(reo_network::game::menu.choice) ? "UP" : "CROSS");
        else if ((step == 3 || step == 4) && substep == 2 && int16_t(word(reo_network::game::menu.delay)) == 0)
            button = pad2ButtonBit(int16_t(word(reo_network::game::menu.cursor)) == 0 ? "CROSS" : "UP");
        else if (step == 6 && word(reo_network::game::menu.profileStage) == 5) {
            const uint32_t menu = word(reo_network::game::menu.profileWork);
            if (pointer(menu, 0x50)) {
                const uint8_t stage = byte(menu + 0x20);
                if (profileChosen && stage != 1 && (target == 6 || stage == 13)) {
                    fprintf(stderr,
                            "[TEST-ROUTE] network profile confirm t=%.3f stage=%u accepted=%u; "
                            "automatic input disabled\n",
                            now, stage, stage == 18);
                    done = true;
                    return 0;
                }
                if (stage == 1 && byte(menu + 0x4C) == 1 && byte(menu + 0x24) > 0) {
                    const uint8_t cursor = byte(menu + 0x10);
                    button = pad2ButtonBit(cursor == 2 ? "CROSS" : "DOWN");
                    if (cursor == 2)
                        profileChosen = true;
                }
            }
        } else if ((target == 7 || target == 8) && profileChosen && step == 44 && substep == 1 &&
                   int16_t(word(reo_network::game::menu.delay)) == 0) {
            const auto cursor = int16_t(word(reo_network::game::menu.cursor));
            button = pad2ButtonBit(cursor == 1 ? "CROSS" : "DOWN");
            if (cursor == 1)
                editorChosen = true;
        } else if (target == 8 && editorChosen && step == 49 && substep == 1)
            button = pad2ButtonBit("CROSS");
        else if (target == 8 && editorChosen && step == 46) {
            button = 0;
            if (substep == 11) {
                static bool passwordKeyboardStarted = false;
                const uint32_t keyboard = word(reo_network::game::menu.keyboardWork);
                const bool validKeyboard = keyboard >= 0x100000u && keyboard <= 0x2000000u - 0x700u;
                const auto inputDelay = byte(reo_network::game::menu.keyboardDelay);
                if (!passwordKeyboardStarted && validKeyboard && byte(keyboard + 0x28) == 1 &&
                    inputDelay > 0) {
                    passwordKeyboardStarted = true;
                    fprintf(stderr,
                            "[TEST-ROUTE] password-editor-warmup t=%.3f work=%08x delay=%u\n", now,
                            keyboard, unsigned(inputDelay));
                }
                // 5809B0 discards input during the eight polls armed by 5805A0.
                if (!passwordInputReady && passwordKeyboardStarted && validKeyboard &&
                    byte(keyboard + 0x28) == 1 && byte(keyboard + 0x36) == 0 && inputDelay == 0) {
                    fprintf(stderr,
                            "[TEST-ROUTE] password-input-ready t=%.3f work=%08x; awaiting original "
                            "USB keyboard input\n",
                            now, keyboard);
                    passwordInputReady = true;
                }
                return 0;
            }
            if (substep == 1 && int16_t(word(reo_network::game::menu.delay)) == 0) {
                const auto cursor = int16_t(word(reo_network::game::menu.cursor));
                const bool hasPassword = byte(reo_network::game::menu.password) != 0;
                if (passwordInputReady && hasPassword) {
                    button = pad2ButtonBit(cursor == 0 ? "CROSS" : "UP");
                    if (cursor == 0)
                        loginSubmitPulse = true;
                } else if (!passwordInputReady && cursor == 1) {
                    button = pad2ButtonBit("CROSS");
                }
            }
        }
    }
    if (target == 4 && reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) == 0x0Eu) {
        // Original cinematic input handler accepts skip only in these substates.
        const uint8_t stage = reo_source_instrumentation::bankRead(rd, rd + (0x4BADD1u));
        button = (stage == 4u || stage == 8u) ? pad2ButtonBit("START") : 0;
    }
    if (!button) {
        const uint32_t card = word(0x326F10u);
        // 1C2940 dispatches mode +1 == 1 to 1C2D00. Its case +2 == 3
        // accepts LEFT/CROSS; +0x38 is the YES(0)/NO(1) cursor, +0x10 a debounce timer.
        if (pointer(card, 0x3Cu) &&
            reo_source_instrumentation::bankRead(rd, rd + (card + 1)) == 1 &&
            reo_source_instrumentation::bankRead(rd, rd + (card + 2)) == 3 &&
            word(card + 0x10u) == 0 && word(card + 0x38u) <= 1)
            button = pad2ButtonBit(word(card + 0x38u) ? "LEFT" : "CROSS");
    }
    if (!button)
        return 0;
    if (++attempts > (target >= 6 ? 50u : target == 4 ? 20u : 12u)) {
        fprintf(stderr, "[TEST-ROUTE] input retry limit t=%.3f; automatic input disabled\n", now);
        done = true;
        return 0;
    }
    pressUntil = now + 0.2;
    releaseUntil = now + 0.6;
    fprintf(stderr, "[TEST-ROUTE] t=%.3f press=%04x state=%06x attempt=%u\n", now, button, state,
            attempts);
    return button;
}

// Opt-in test steering through the original analog-input path. The target is
// world X/Z; camera and actor state are observed, never changed by this helper.
// Original 1B0B80 maps gameplay buttons through 2343C0 + profile(3243EC)*12.
// UI button meanings remain unchanged; this helper selects an actor action.
uint16_t pad2TestActorAction(const uint8_t* rd, uint32_t actionMask) {
    if (!rd || reo_source_instrumentation::bankRead(rd, rd + (0x3243ECu)) >= 3u || !actionMask)
        return 0;
    const char* physical[] = {"TRIANGLE", "CROSS", "CIRCLE"};
    const uint32_t table =
        0x2343C0u + uint32_t(reo_source_instrumentation::bankRead(rd, rd + (0x3243ECu))) * 12u;
    for (uint32_t i = 0; i < 3u; ++i) {
        uint32_t mapped;
        reo_source_instrumentation::copyBytesForBank(rd, &mapped, rd + table + i * 4u,
                                                     sizeof(mapped));
        if ((mapped & actionMask) == actionMask)
            return pad2ButtonBit(physical[i]);
    }
    return 0;
}

uint16_t pad2TestWorldTarget(uint8_t* rd, double now, reo::DualShock2State& pad) {
    struct Target {
        float x = 0, z = 0, radius = 40;
        bool enabled = false;
        Target() {
            const char* value = std::getenv("REO_TEST_WORLD_TARGET");
            if (!value)
                return;
            const int fields = std::sscanf(value, "%f,%f,%f", &x, &z, &radius);
            enabled = fields >= 2 && std::isfinite(x) && std::isfinite(z) &&
                      std::fabs(x) < 1000000 && std::fabs(z) < 1000000 && std::isfinite(radius) &&
                      radius >= 1 && radius <= 1000;
            if (!enabled)
                std::fprintf(stderr, "[TEST-WALK] invalid target; disabled\n");
        }
    };
    static const Target target;
    static bool done = false;
    static double started = -1, nextReport = 0;
    static uint16_t startingRoom = 0;
    if (!target.enabled || done || !rd)
        return 0;
    auto half = [rd](uint32_t address) {
        uint16_t value;
        reo_source_instrumentation::copyBytesForBank(rd, &value, rd + address, sizeof(value));
        return value;
    };
    auto scalar = [rd](uint32_t address) {
        float value;
        reo_source_instrumentation::copyBytesForBank(rd, &value, rd + address, sizeof(value));
        return value;
    };
    const uint16_t room = half(0x3243DCu);
    if (started >= 0 && (reo_source_instrumentation::bankRead(rd, rd + (0x4BAE07u)) != 0 ||
                         room != startingRoom || now - started > 180)) {
        std::fprintf(
            stderr, "[TEST-WALK] stopped t=%.3f room=%u destination=%u request=%u door=%u\n", now,
            room, half(0x3243E2u), reo_source_instrumentation::bankRead(rd, rd + (0x4BAE07u)),
            reo_source_instrumentation::bankRead(rd, rd + (0x4BAE05u)));
        done = true;
        return 0;
    }
    if (reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) != 2u ||
        reo_source_instrumentation::bankRead(rd, rd + (0x4BADEEu)) != 0 ||
        reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) != 0 ||
        reo_source_instrumentation::bankRead(rd, rd + (0x4BADF8u)) != 0 ||
        reo_source_instrumentation::bankRead(rd, rd + (0x4BAE8Du)) != 0 ||
        reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu)) >= 4u ||
        reo_source_instrumentation::bankRead(rd, rd + (0x4BAE07u)) != 0)
        return 0;
    static const bool enemyTest = std::getenv("REO_TEST_ENEMIES") != nullptr;
    const uint32_t actor = 0x4A5C30u +
        (enemyTest ? 0u : uint32_t(reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu)))) * 0x10E0u;
    if (!reo_source_instrumentation::bankRead(rd, rd + (actor)) ||
        (enemyTest ? int16_t(half(actor + 0x544u)) <= 0
                   : reo_source_instrumentation::bankRead(rd, rd + (actor + 0xBD0u)) != 0))
        return 0;
    const float x = scalar(actor + 0x38u), z = scalar(actor + 0x40u);
    const double cx = double(scalar(0x324144u)) - scalar(0x324138u);
    const double cz = double(scalar(0x32414Cu)) - scalar(0x324140u);
    if (!std::isfinite(x) || !std::isfinite(z) || !std::isfinite(cx) || !std::isfinite(cz) ||
        cx * cx + cz * cz < 0.000001)
        return 0;
    if (started < 0) {
        started = now;
        startingRoom = room;
        std::fprintf(stderr,
                     "[TEST-WALK] start t=%.3f room=%u actor=%08x xyz=%.3f,%.3f target=%.3f,%.3f\n",
                     now, room, actor, x, z, target.x, target.z);
    }
    const double dx = double(target.x) - x, dz = double(target.z) - z;
    if (dx * dx + dz * dz <= double(target.radius) * target.radius) {
        std::fprintf(stderr, "[TEST-WALK] target reached t=%.3f xyz=%.3f,%.3f request=%u\n", now, x,
                     z, reo_source_instrumentation::bankRead(rd, rd + (0x4BAE07u)));
        done = true;
        return 0;
    }
    constexpr double tau = 6.2831853071795864769;
    // Original 6621F0 adds the camera/stick headings with low four bits clear.
    const int16_t camera = static_cast<int16_t>(int(std::atan2(cx, cz) * 65536 / tau) & 0xFFF0);
    const double relative = std::atan2(dx, dz) - double(camera) * tau / 65536;
    pad.left_x = uint8_t(std::clamp(int(std::lround(128 - 127 * std::sin(relative))), 0, 255));
    pad.left_y = uint8_t(std::clamp(int(std::lround(128 - 127 * std::cos(relative))), 0, 255));
    if (now >= nextReport) {
        nextReport = now + 1;
        std::fprintf(stderr,
                     "[TEST-WALK] t=%.3f xyz=%.3f,%.3f distance=%.3f camera=%d stick=%u,%u "
                     "frame=%.3f class=%x\n",
                     now, x, z, std::sqrt(dx * dx + dz * dz), camera, pad.left_x, pad.left_y,
                     scalar(actor + 0x1E4u), half(actor + 0x1F2u));
    }
    // Walk for the final approach so the original root-motion step can settle
    // inside a small interaction target without repeatedly overshooting it.
    return dx * dx + dz * dz > 10000 ? pad2TestActorAction(rd, 0x10u) : 0;
}

// Unattended room exercise, opt-in and input-only. Pause for original loading,
// cutscenes/dialogs; resume in the newly reached room without altering state.
bool pad2TestRoomSoak(uint8_t* rd, double now, reo::DualShock2State& pad, uint16_t& buttons) {
    static const bool enabled = [] {
        const char* v = std::getenv("REO_TEST_ROOM_SOAK");
        return v && std::strcmp(v, "1") == 0;
    }();
    if (!enabled)
        return false;
    buttons = 0;
    if (!rd)
        return true;
    static double last = -1, active = 0, nextReport = 0;
    const auto byte = [rd](uint32_t a) { return reo_source_instrumentation::bankRead(rd, rd + a); };
    // A queued scenario request can remain3 during otherwise interactive room
    // play. Let the original input handlers arbitrate it, as with a real pad.
    // Cancel a recognized pickup dialog through its own ordinary Circle input.
    if (byte(0x4badd0) == 2 && byte(0x755ec4) == 1 && byte(0x4baded) < 4) {
        const uint32_t actor = 0x4a5c30u + uint32_t(byte(0x4baded)) * 0x10e0u;
        if (byte(actor + 8) == 1 && byte(actor + 9) == 0x16) {
            last = now;
            if (std::fmod(now, 3.) < .18)
                buttons = pad2ButtonBit("CIRCLE");
            return true;
        }
    }
    const bool ready = byte(0x4badd0) == 2 && !byte(0x4badee) && !byte(0x755ec4) &&
                       !byte(0x4badf8) && !byte(0x4bae8d) && byte(0x4baded) < 4;
    const double dt = last < 0 ? 0 : std::min(.1, std::max(0., now - last));
    last = now;
    if (!ready)
        return true;
    const uint32_t actor = 0x4a5c30u + uint32_t(byte(0x4baded)) * 0x10e0u;
    if (!byte(actor) || byte(actor + 0xbd0))
        return true;
    active += dt;
    const unsigned phase = unsigned(active / 6.) % 4;
    const double within = std::fmod(active, 6.);
    if (phase == 0)
        pad.left_y = 24;
    else if (phase == 1)
        pad.left_x = 232;
    else if (phase == 2)
        pad.left_y = 232;
    else
        pad.left_x = 24;
    if (within > 2. && within < 2.18)
        buttons = pad2ButtonBit("CROSS");
    if (within > 4. && within < 4.6) {
        pad.left_x = pad.left_y = 128;
        buttons = pad2ButtonBit("R1");
        if (within > 4.25 && within < 4.43)
            buttons |= pad2ButtonBit("CROSS");
    }
    if (now >= nextReport) {
        nextReport = now + 2;
        float x = 0, z = 0;
        uint16_t room = 0;
        reo_source_instrumentation::copyBytesForBank(rd, &x, rd + actor + 0x38, 4);
        reo_source_instrumentation::copyBytesForBank(rd, &z, rd + actor + 0x40, 4);
        reo_source_instrumentation::copyBytesForBank(rd, &room, rd + 0x3243dc, 2);
        fprintf(stderr,
                "[TEST-ROOM-SOAK] t=%.3f active=%.3f room=%u xyz=%.3f,%.3f phase=%u stick=%u,%u "
                "buttons=%04x\n",
                now, active, room, x, z, phase, pad.left_x, pad.left_y, buttons);
    }
    return true;
}

// Opt-in acceptance route. Every transition observes original guest state; only
// ordinary controller buttons/axes are emitted, including through long GS waits.
bool pad2TestInteractQuit(uint8_t* rd, double now, reo::DualShock2State& pad, uint16_t& buttons) {
    static const bool enabled = []() {
        const char* value = std::getenv("REO_TEST_INTERACT_QUIT");
        return value && std::strcmp(value, "1") == 0;
    }();
    if (!enabled)
        return false;
    buttons = 0;
    if (!rd)
        return true;
    enum Stage {
        WaitRoom,
        ReleaseBoot,
        Approach,
        Settle,
        Face,
        ReleaseFace,
        Interact,
        Message,
        PickupRelease,
        PickupConfirm,
        PickupFinish,
        InventoryOpen,
        InventoryView,
        InventoryClose,
        Select,
        ReleaseSelect,
        MenuReady,
        Up,
        ReleaseUp,
        Confirm,
        ReleaseConfirm,
        Yes,
        ReleaseYes,
        Quit,
        ReturnMenu,
        ResultsRelease,
        ResultsConfirm,
        ResultsFinish,
        CardRelease,
        CardChooseExit,
        CardReleaseExit,
        CardConfirm,
        CardFinish,
        Done
    };
    enum CardAction { NoCardAction, CardAcknowledge, CardDecline, CardExit };
    static Stage stage = WaitRoom;
    static double started = -1, entered = 0, nextReport = 0;
    static bool messageObserved = false;
    static bool pickupObserved = false;
    static bool resultsAcknowledged = false;
    static bool idleObservation = false;
    static unsigned idleUpdates = 0, faceRecoveries = 0;
    static uint32_t idleFrame = 0;
    static uint16_t idleYaw = 0;
    static double idleX = 0, idleZ = 0;
    static uint32_t confirmingCard = 0;
    static CardAction confirmingCardAction = NoCardAction;
    static uint8_t pickupHandle = 0, pickupItem = 0;
    static uint8_t inventoryBeforePickup[4] = {};
    static const char* names[] = {"wait-room",
                                  "release-boot",
                                  "approach",
                                  "settle",
                                  "face",
                                  "release-face",
                                  "interact",
                                  "message-expiry",
                                  "pickup-release",
                                  "pickup-confirm",
                                  "pickup-finish",
                                  "inventory-open",
                                  "inventory-view",
                                  "inventory-close",
                                  "select",
                                  "release-select",
                                  "menu-ready",
                                  "up",
                                  "release-up",
                                  "confirm",
                                  "release-confirm",
                                  "yes",
                                  "release-yes",
                                  "quit",
                                  "return-main-menu",
                                  "results-release",
                                  "results-confirm",
                                  "results-finish",
                                  "card-release",
                                  "card-choose-exit",
                                  "card-release-exit",
                                  "card-confirm",
                                  "card-finish",
                                  "done"};
    auto word = [rd](uint32_t a) {
        uint32_t v;
        reo_source_instrumentation::copyBytesForBank(rd, &v, rd + a, sizeof(v));
        return v;
    };
    auto half = [rd](uint32_t a) {
        uint16_t v;
        reo_source_instrumentation::copyBytesForBank(rd, &v, rd + a, sizeof(v));
        return v;
    };
    auto scalar = [rd](uint32_t a) {
        float v;
        reo_source_instrumentation::copyBytesForBank(rd, &v, rd + a, sizeof(v));
        return v;
    };
    auto valid = [](uint32_t a, uint32_t size) {
        return a >= 0x100000u && a < ps2RamBackingBytes && size <= ps2RamBackingBytes - a;
    };
    auto resultsWork = [&]() {
        // Original 603740/sub2 calls ovl9 8270D0. Its 826FE0 initializer
        // stores the shared allocation at 893800, not the front-overlay cache.
        const uint32_t work = word(0x893800u);
        return word(0x810000u) == 0x336F574Du && word(0x810004u) == 9u &&
                       reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) == 0x0Du &&
                       reo_source_instrumentation::bankRead(rd, rd + (0x4BADD1u)) == 2u &&
                       work == word(0x324424u) && valid(work, 0x320u)
                   ? work
                   : 0u;
    };
    auto resultsReady = [&](uint32_t work) {
        // 827524..52C requires Cross alone (translated edge 10), after
        // debounce31E. With no awards, it enters mode3/countdown10 directly.
        return work && reo_source_instrumentation::bankRead(rd, rd + (work)) == 1u &&
               reo_source_instrumentation::bankRead(rd, rd + (work + 1u)) == 0u &&
               reo_source_instrumentation::bankRead(rd, rd + (work + 2u)) == 0u &&
               int16_t(half(work + 0x31Eu)) <= 0 && word(work + 0x210u) == 0u &&
               reo_source_instrumentation::bankRead(rd, rd + (0x324489u)) == 1u &&
               reo_source_instrumentation::bankRead(rd, rd + (0x4BAE76u)) &&
               reo_source_instrumentation::bankRead(rd, rd + (0x4BAE77u));
    };
    auto mainMenuReady = [&](uint32_t work) {
        // 1B8140 schedules slot4 callback57F1F0; 1B7CB0 makes it live (8).
        // 57F240 initializes task+8, installs57FDE0 and clears the quit reason.
        // BIN/1.DAT's registered header id2 proves these addresses belong to
        // the freshly loaded frontend. 5D4898 is stale while ovl2 occupies it.
        return word(0x570000u) == 0x336F574Du && word(0x570004u) == 2u &&
               reo_source_instrumentation::bankRead(rd, rd + (0x3243F8u)) == 1u &&
               half(0x3163D0u) == 8u && word(0x3163D4u) == 0x57F1F0u &&
               reo_source_instrumentation::bankRead(rd, rd + (0x3163D8u)) == 1u &&
               word(0x3163E4u) == 0x57FDE0u && valid(work, 0x224u) &&
               reo_source_instrumentation::bankRead(rd, rd + (work)) == 1u &&
               reo_source_instrumentation::bankRead(rd, rd + (work + 1u)) == 5u &&
               reo_source_instrumentation::bankRead(rd, rd + (0x324489u)) == 0u;
    };
    auto cardWork = [&]() {
        // Original603740/sub7 calls1C2940 after1C2600(2,1). Observe only
        // that exact operation and its original allocation while ovl2 is live.
        const uint32_t work = word(0x326F10u);
        const uint64_t expected =
            uint64_t(word(0x32440Cu)) +
            (reo_source_instrumentation::bankRead(rd, rd + (0x3243C0u)) ? 0xA0000u : 0x2BF000u);
        return word(0x570000u) == 0x336F574Du && word(0x570004u) == 3u &&
                       reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) == 0x0Du &&
                       reo_source_instrumentation::bankRead(rd, rd + (0x4BADD1u)) == 7u &&
                       word(0x70DFE8u) == 0x4BADD0u && expected == work && valid(work, 0xF4u) &&
                       word(work + 0x20u) == 2u && word(work + 0x1Cu) == 1u
                   ? work
                   : 0u;
    };
    auto cardAction = [&](uint32_t work) {
        if (!work)
            return NoCardAction;
        const uint8_t mode = reo_source_instrumentation::bankRead(rd, rd + (work + 1u)),
                      sub = reo_source_instrumentation::bankRead(rd, rd + (work + 2u));
        const uint32_t message = word(work + 0x2Cu), cursor = word(work + 0x38u);
        // 1C3C90 sub6/99 and1C4970 sub99 accept an acknowledgment edge
        // then return0; these terminal branches do not format or write.
        if ((mode == 2u && (sub == 6u || sub == 99u)) || (mode == 4u && sub == 99u))
            return CardAcknowledge;
        // 1C3C90/sub2 uses1C3C40: op2 reads rawCross10. Cursor1 returns0
        // before any1C0DC0 format/1C09D0 write. Require the exact original
        // message/action pairs; all other prompts remain neutral diagnostics.
        const uint32_t operation = word(work + 0x3Cu);
        const bool knownDecline = (operation == 2u && message == 0x13u) ||
                                  (operation == 1u && message == 0x0Eu) ||
                                  (operation == 0u && message == 0x0Au);
        if (mode == 2u && sub == 2u &&
            reo_source_instrumentation::bankRead(rd, rd + (work + 3u)) == 1u &&
            word(work + 0x30u) == 1u && cursor == 1u && knownDecline)
            return CardDecline;
        // 1C4CA0/sub1: cursor1 retries1C2600; cursor0 returns0 and exits.
        // Do not retry or carry Cross into a newly initialized card operation.
        if (mode == 8u && sub == 1u && word(work + 0x30u) == 1u && cursor <= 1u &&
            message == (reo_source_instrumentation::bankRead(rd, rd + (0x3243C0u)) ? 0x35u : 0x37u))
            return CardExit;
        return NoCardAction;
    };
    auto go = [&](Stage next) {
        std::fprintf(
            stderr, "[TEST-INTERACT-QUIT] t=%.3f %s -> %s phase=%u room=%u ui=%u/%u/%u/%u\n", now,
            names[stage], names[next], reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)),
            half(0x3243DCu), reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)),
            reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)),
            reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)),
            reo_source_instrumentation::bankRead(rd, rd + (0x755EC3u)));
        stage = next;
        entered = now;
        idleObservation = false;
        idleUpdates = 0;
    };
    auto stop = [&](const char* reason) {
        buttons = 0;
        pad.left_x = pad.left_y = 128u;
        const uint32_t observedActor =
            0x4A5C30u +
            uint32_t(reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu))) * 0x10E0u;
        const bool actorReadable =
            reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu)) < 4u &&
            valid(observedActor, 0x10E0u);
        std::fprintf(
            stderr,
            "[TEST-INTERACT-QUIT] stopped t=%.3f stage=%s reason=%s messageProof=%u pickupProof=%u "
            "actor=%u/%u/%u/%u selected=%u expected=%u ui=%u\n",
            now, names[stage], reason, unsigned(messageObserved), unsigned(pickupObserved),
            actorReadable ? reo_source_instrumentation::bankRead(rd, rd + (observedActor + 8u))
                          : 0u,
            actorReadable ? reo_source_instrumentation::bankRead(rd, rd + (observedActor + 9u))
                          : 0u,
            actorReadable ? reo_source_instrumentation::bankRead(rd, rd + (observedActor + 10u))
                          : 0u,
            actorReadable ? reo_source_instrumentation::bankRead(rd, rd + (observedActor + 11u))
                          : 0u,
            actorReadable ? reo_source_instrumentation::bankRead(rd, rd + (observedActor + 0xC7Au))
                          : 0u,
            pickupHandle, reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)));
        go(Done);
    };
    // 1B06F0 supplies current/previous converted held reports and normalized
    // left axes. The 2B09E2 fetched report is inverted during guest processing;
    // accept either neutral representation instead of requiring its transient
    // active-low value. Converted history proves the release was consumed.
    auto released = [&]() {
        const uint16_t fetched = half(0x2B09E2u);
        return now - entered >= 0.12 && word(0x324308u) == 0 && word(0x32430Cu) == 0 &&
               half(0x324264u) == 0 && half(0x324266u) == 0 &&
               (fetched == 0 || fetched == 0xFFFFu) &&
               std::abs(int(reo_source_instrumentation::bankRead(rd, rd + (0x2B09E6u))) - 128) <= 1 &&
               std::abs(int(reo_source_instrumentation::bankRead(rd, rd + (0x2B09E7u))) - 128) <= 1;
    };
    if (stage == Done)
        return true;
    if (started >= 0 && now - started > 180) {
        stop("180-second phase2 deadline");
        return true;
    }
    if (stage == WaitRoom) {
        if (reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) == 2u &&
            half(0x3243DCu) == 1u &&
            reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu)) < 4u) {
            started = now;
            go(ReleaseBoot);
        }
        return true;
    }
    if (stage < ReturnMenu &&
        (half(0x3243DCu) != 1u || reo_source_instrumentation::bankRead(rd, rd + (0x4BAE07u)))) {
        stop("unexpected room transition");
        return true;
    }
    static const bool weaponPickup = std::getenv("REO_TEST_WEAPON_PICKUP") != nullptr;
    // This offline diagnostic selects Kevin in slot 0. Pin that actor for the
    // test instead of following a global selector from the asynchronous worker.
    const uint32_t actor = 0x4A5C30u +
        (weaponPickup ? 0u : uint32_t(reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu)))) * 0x10E0u;
    if (stage <= PickupFinish &&
        (reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)) != 2u ||
         reo_source_instrumentation::bankRead(rd, rd + (0x4BADEDu)) >= 4u ||
         !valid(actor, 0x10E0u) || !reo_source_instrumentation::bankRead(rd, rd + (actor)) ||
         (weaponPickup ? int16_t(half(actor + 0x544u)) <= 0
                       : reo_source_instrumentation::bankRead(rd, rd + (actor + 0xBD0u)) != 0) ||
         reo_source_instrumentation::bankRead(rd, rd + (0x4BADF8u)) ||
         reo_source_instrumentation::bankRead(rd, rd + (0x4BAE8Du)) ||
         reo_source_instrumentation::bankRead(rd, rd + (0x4BADEEu))))
        return true;
    // Original interaction can select a nearby pickup before the proposed
    // world message. Its UI must be completed through its own original input
    // handler, rather than being blocked by the gameplay UI guard.
    if (stage <= Message && reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) &&
        !(stage == Interact && reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) == 1u &&
          reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)) == 1u &&
          reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)) == 0x16u))
        return true;
    const double x = scalar(actor + 0x38u), z = scalar(actor + 0x40u);
    const double targetX = weaponPickup ? 8460.0 : 8420.0;
    const double targetZ = weaponPickup ? 13014.0 : 13020.0;
    const double faceX = weaponPickup ? 8494.0 : 8420.0;
    const double faceZ = weaponPickup ? 12923.0 : 12945.0;
    const double dx = targetX - x, dz = targetZ - z;
    auto steer = [&](double heading, double magnitude) {
        constexpr double tau = 6.2831853071795864769;
        const double cx = double(scalar(0x324144u)) - scalar(0x324138u);
        const double cz = double(scalar(0x32414Cu)) - scalar(0x324140u);
        if (!std::isfinite(cx) || !std::isfinite(cz) || cx * cx + cz * cz < 0.000001)
            return false;
        const int16_t camera = static_cast<int16_t>(int(std::atan2(cx, cz) * 65536 / tau) & 0xFFF0);
        const double relative = heading - double(camera) * tau / 65536;
        auto axis = [&](double component) {
            double delta = magnitude * component;
            // The guest removes a per-axis dead zone, which otherwise snaps
            // shallow facing angles onto a cardinal direction.
            if (weaponPickup && std::abs(component) > 0.001)
                delta = std::copysign(41.0 + (magnitude - 41.0) * std::abs(component), component);
            return uint8_t(std::clamp(int(std::lround(128 - delta)), 0, 255));
        };
        pad.left_x = axis(std::sin(relative));
        pad.left_y = axis(std::cos(relative));
        return true;
    };
    auto projectionInside = [&](double margin = 0) {
        constexpr double tau = 6.2831853071795864769;
        const double yaw = double(int16_t(half(actor + 0x92u))) * tau / 65536;
        const double distance = double(scalar(actor + 0x1B4u)) + 46;
        const double px = x + distance * std::sin(yaw), pz = z + distance * std::cos(yaw);
        if (!std::isfinite(distance)) return false;
        if (weaponPickup) {
            // Stand on the accessible side of the bar and face the original
            // handle-3 item. Let the game's own pickup range test decide reach.
            const double tx = faceX - x, tz = faceZ - z;
            const double length = std::sqrt(tx * tx + tz * tz);
            return length > 0 && (tx * std::sin(yaw) + tz * std::cos(yaw)) / length > 0.99;
        }
        return px >= 8390 + margin && px <= 8450 - margin &&
               pz >= 12900 + margin && pz <= 12990 - margin;
    };
    auto settledIdle = [&]() {
        // A converted neutral report does not finish the walking/turning
        // animation. Wait for original idle, then observe unchanged position
        // and yaw across two distinct actor-animation frame publications.
        // Re-reading unchanged RAM during a GS stall cannot satisfy this.
        if (!released() || reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)) != 1u ||
            reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)) != 0u ||
            !std::isfinite(x) || !std::isfinite(z) || !std::isfinite(scalar(actor + 0x1E4u))) {
            idleObservation = false;
            idleUpdates = 0;
            return false;
        }
        const uint32_t frame = word(actor + 0x1E4u);
        const uint16_t yaw = half(actor + 0x92u);
        if (!idleObservation || std::fabs(x - idleX) > 0.25 || std::fabs(z - idleZ) > 0.25 ||
            yaw != idleYaw) {
            idleObservation = true;
            idleUpdates = 0;
            idleX = x;
            idleZ = z;
            idleYaw = yaw;
            idleFrame = frame;
            return false;
        }
        if (frame != idleFrame) {
            idleFrame = frame;
            ++idleUpdates;
        }
        return idleUpdates >= 2u;
    };
    auto observePickup = [&]() {
        if (pickupObserved)
            return true;
        if (!pickupItem)
            return false;
        uint8_t inventory[4];
        for (unsigned slot = 0; slot < 4; ++slot)
            inventory[slot] =
                reo_source_instrumentation::bankRead(rd, rd + (actor + 0xC84u + slot));
        unsigned slot = 0;
        while (slot < 4 && inventory[slot] != pickupItem)
            ++slot;
        if (slot == 4)
            return false;
        pickupObserved = true;
        const uint32_t item = 0x3C5630u + uint32_t(pickupHandle) * 0x3Cu;
        std::fprintf(stderr,
                     "[TEST-INTERACT-QUIT] PICKUP PROOF handle=%u item=%u slot=%u "
                     "before=%u/%u/%u/%u after=%u/%u/%u/%u owner=%u world=%u active=%u type=%04x quantity=%u metadata=%u\n",
                     pickupHandle, pickupItem, slot, inventoryBeforePickup[0],
                     inventoryBeforePickup[1], inventoryBeforePickup[2], inventoryBeforePickup[3],
                     inventory[0], inventory[1], inventory[2], inventory[3], half(item + 0x28u),
                     reo_source_instrumentation::bankRead(rd, rd + (item + 3u)),
                     reo_source_instrumentation::bankRead(rd, rd + (item)), half(item + 6u),
                     half(item + 0x24u), reo_source_instrumentation::bankRead(rd, rd + item + 0x2bu));
        return true;
    };
    if (now >= nextReport) {
        nextReport = now + 2;
        std::fprintf(stderr,
                     "[TEST-INTERACT-QUIT] t=%.3f stage=%s xyz=%.3f,%.3f held=%08x/%08x raw=%04x "
                     "ui=%u/%u/%u/%u actor=%u/%u/%u/%u action=%08x/%08x busy=%u quit=%u/%u\n",
                     now, names[stage], x, z, word(0x324308u), word(0x32430Cu), half(0x2B09E2u),
                     reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)),
                     reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)),
                     reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)),
                     reo_source_instrumentation::bankRead(rd, rd + (0x755EC3u)),
                     reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)),
                     reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)),
                     reo_source_instrumentation::bankRead(rd, rd + (actor + 10u)),
                     reo_source_instrumentation::bankRead(rd, rd + (actor + 11u)),
                     word(actor + 0xF78u), word(actor + 0xF80u),
                     reo_source_instrumentation::bankRead(rd, rd + (0x4BAE0Au)),
                     reo_source_instrumentation::bankRead(rd, rd + (0x4BAE76u)),
                     reo_source_instrumentation::bankRead(rd, rd + (0x4BAE77u)));
        if (stage >= ReturnMenu) {
            const uint32_t work = resultsWork();
            std::fprintf(stderr,
                         "[TEST-INTERACT-QUIT] RETURN STATE phase=%u/%u overlay=%u/%u "
                         "callback=%08x task=%u/%u front=%08x reason=%u results=%08x mode=%u/%u/%u "
                         "debounce=%d awards=%u\n",
                         reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)),
                         reo_source_instrumentation::bankRead(rd, rd + (0x4BADD1u)),
                         word(0x570004u), word(0x810004u), word(0x3163D4u), half(0x3163D0u),
                         reo_source_instrumentation::bankRead(rd, rd + (0x3163D8u)),
                         word(0x324424u),
                         reo_source_instrumentation::bankRead(rd, rd + (0x324489u)), work,
                         work ? reo_source_instrumentation::bankRead(rd, rd + (work)) : 0u,
                         work ? reo_source_instrumentation::bankRead(rd, rd + (work + 1u)) : 0u,
                         work ? reo_source_instrumentation::bankRead(rd, rd + (work + 2u)) : 0u,
                         work ? int16_t(half(work + 0x31Eu)) : 0, work ? word(work + 0x210u) : 0u);
            const uint32_t card = cardWork();
            if (card)
                std::fprintf(stderr,
                             "[TEST-INTERACT-QUIT] CARD STATE work=%08x mode=%u/%u/%u "
                             "operation=%u/%u message=%u cursor=%u timer=%u confirm=%u purpose=%u "
                             "result=%08x port0=%u ready=%u action=%u\n",
                             card, reo_source_instrumentation::bankRead(rd, rd + (card + 1u)),
                             reo_source_instrumentation::bankRead(rd, rd + (card + 2u)),
                             reo_source_instrumentation::bankRead(rd, rd + (card + 3u)),
                             word(card + 0x20u), word(card + 0x1Cu), word(card + 0x2Cu),
                             word(card + 0x38u), word(card + 0x10u), word(card + 0x30u),
                             word(card + 0x3Cu), word(0x326C74u), word(0x326C78u),
                             word(card + 0x40u), unsigned(cardAction(card)));
        }
    }
    switch (stage) {
        case ReleaseBoot:
            if (released())
                go(Approach);
            break;
        case Approach:
            if (!std::isfinite(x) || !std::isfinite(z)) {
                stop("invalid actor position");
                break;
            }
            if (dx * dx + dz * dz <= 64)
                go(Settle);
            else if (steer(std::atan2(dx, dz), 127) && dx * dx + dz * dz > 10000) {
                buttons = pad2TestActorAction(rd, 0x10u);
                if (!buttons)
                    stop("invalid original run mapping");
            }
            break;
        case Settle:
            if (settledIdle())
                go(projectionInside(8) ? Interact : Face);
            break;
        case Face:
            // Aim inside the rectangle rather than stopping at its first edge.
            // Root motion continues after the neutral report is consumed.
            if (projectionInside(8))
                go(ReleaseFace);
            // Original 1A6090 removes 40/41 raw units per axis; 6621F0 then
            // ignores processed magnitudes below 16. Raw magnitude 72 remains
            // above that gate at every angle (minimum 19), unlike 48 or 64.
            else if (!steer(std::atan2(faceX - x, faceZ - z), 72))
                stop("invalid facing camera");
            break;
        case ReleaseFace:
            if (settledIdle()) {
                if (projectionInside())
                    go(Interact);
                else if (++faceRecoveries > 4u)
                    stop("four settled facing recoveries exhausted");
                else {
                    constexpr double tau = 6.2831853071795864769;
                    const double yaw = double(int16_t(half(actor + 0x92u))) * tau / 65536;
                    const double distance = double(scalar(actor + 0x1B4u)) + 46;
                    std::fprintf(stderr,
                                 "[TEST-INTERACT-QUIT] FACING RECOVERY attempt=%u xyz=%.3f,%.3f "
                                 "query=%.3f,%.3f yaw=%d idleUpdates=%u\n",
                                 faceRecoveries, x, z, x + distance * std::sin(yaw),
                                 z + distance * std::cos(yaw), int(int16_t(half(actor + 0x92u))),
                                 idleUpdates);
                    // Reapproach only after actual settled displacement; every
                    // adjustment still uses the original controller and movement.
                    go(dx * dx + dz * dz > 24.0 * 24.0 ? Approach : Face);
                }
            }
            break;
        case Interact: {
            if (reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)) == 1u &&
                reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)) == 0x16u) {
                pickupHandle = reo_source_instrumentation::bankRead(rd, rd + (actor + 0xC7Au));
                const uint32_t item = 0x3C5630u + uint32_t(pickupHandle) * 0x3Cu;
                if (!pickupHandle || !valid(item, 0x3Cu) ||
                    reo_source_instrumentation::bankRead(rd, rd + (item)) != 1u ||
                    !reo_source_instrumentation::bankRead(rd, rd + (item + 2u))) {
                    stop("invalid original pickup selection");
                    break;
                }
                pickupItem = reo_source_instrumentation::bankRead(rd, rd + (item + 2u));
                bool alreadyHeld = false;
                for (unsigned slot = 0; slot < 4; ++slot) {
                    inventoryBeforePickup[slot] =
                        reo_source_instrumentation::bankRead(rd, rd + (actor + 0xC84u + slot));
                    alreadyHeld |= inventoryBeforePickup[slot] == pickupItem;
                }
                if (alreadyHeld) {
                    stop("selected pickup already in inventory");
                    break;
                }
                std::fprintf(stderr,
                             "[TEST-INTERACT-QUIT] PICKUP SELECTED handle=%u item=%u record=%08x "
                             "state=%u/%u/%u/%u\n",
                             pickupHandle, pickupItem, item,
                             reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)),
                             reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)),
                             reo_source_instrumentation::bankRead(rd, rd + (actor + 10u)),
                             reo_source_instrumentation::bankRead(rd, rd + (actor + 11u)));
                go(PickupRelease);
                break;
            }
            const uint32_t task = word(0x4A5C20u);
            if (reo_source_instrumentation::bankRead(rd, rd + (0x4BAE0Au)) && valid(task, 0x18u) &&
                half(task + 0x12u) == 0x001Cu && word(task + 0x14u) == 0x6B6880u) {
                messageObserved = true;
                std::fprintf(stderr,
                             "[TEST-INTERACT-QUIT] MESSAGE PROOF task=%08x id=%04x callback=%08x "
                             "countdown=%u\n",
                             task, half(task + 0x12u), word(task + 0x14u), half(task + 0x0Cu));
                go(Message);
            } else {
                // Retry a normal press/release edge if the initial press lands
                // while the actor is finishing an animation.
                buttons = (!weaponPickup || std::fmod(now - entered, 1.0) < 0.4)
                    ? pad2TestActorAction(rd, 0x20u) : 0;
                if (!buttons && !weaponPickup)
                    stop("invalid original interaction mapping");
            }
            break;
        }
        case Message:
            // Original 6B6880 expires task+0C and clears 4BAE0A without a button.
            if (!reo_source_instrumentation::bankRead(rd, rd + (0x4BAE0Au)) && released())
                go(Select);
            break;
        case PickupRelease:
            // Selection is first observed during the pickup animation (sub3/UI0).
            // Live guest byte reads can briefly disagree during that startup;
            // wait neutrally for its original confirmation state before acting.
            // The existing phase2 deadline still bounds a pickup that never opens.
            if (released() && reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)) == 1u &&
                reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)) == 0x16u &&
                reo_source_instrumentation::bankRead(rd, rd + (actor + 0xC7Au)) == pickupHandle &&
                reo_source_instrumentation::bankRead(rd, rd + (actor + 10u)) == 5u &&
                reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) == 1u)
                go(PickupConfirm);
            break;
        case PickupConfirm: {
            if (observePickup()) {
                go(PickupFinish);
            } else if (reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)) != 1u ||
                       reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)) != 0x16u ||
                       reo_source_instrumentation::bankRead(rd, rd + (actor + 0xC7Au)) !=
                           pickupHandle ||
                       reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) != 1u) {
                // UI closure or a transfer state is not cancellation evidence.
                // Release immediately, then observe original inventory publication
                // and recovery instead of sending another button during transfer.
                go(PickupFinish);
            } else {
                // Original 66CFE0/sub5 -> 5F49D0 confirms with actor F78 bit20.
                // Resolve that action through the actual profile, as in gameplay.
                buttons = pad2TestActorAction(rd, 0x20u);
                if (!buttons)
                    stop("invalid original pickup confirmation mapping");
            }
            break;
        }
        case PickupFinish: {
            const bool acquired = observePickup();
            if (released() && reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) == 0u &&
                reo_source_instrumentation::bankRead(rd, rd + (actor + 8u)) == 1u &&
                reo_source_instrumentation::bankRead(rd, rd + (actor + 9u)) == 0u) {
                if (acquired)
                    go(weaponPickup ? InventoryOpen : Select);
                else
                    stop("resolved idle without pickup inventory proof");
            }
            break;
        }
        case InventoryOpen:
            if (reo_source_instrumentation::bankRead(rd, rd + 0x755EC4u) == 1u)
                go(InventoryView);
            else
                buttons = pad2ButtonBit("START");
            break;
        case InventoryView:
            // Leave the actual inventory visible for screenshot evidence.
            if (now - entered >= 15.0 && released())
                go(InventoryClose);
            break;
        case InventoryClose:
            if (!reo_source_instrumentation::bankRead(rd, rd + 0x755EC4u))
                go(Select);
            else
                buttons = pad2ButtonBit("START");
            break;
        case Select:
            if (reo_source_instrumentation::bankRead(rd, rd + (0x4BAE94u)) ||
                reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) == 4u)
                go(ReleaseSelect);
            else
                buttons = pad2ButtonBit("SELECT");
            break;
        case ReleaseSelect:
            if (released())
                go(MenuReady);
            break;
        case MenuReady:
            if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC4u)) == 4u &&
                reo_source_instrumentation::bankRead(rd, rd + (0x755EC0u)) == 1u &&
                reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)) == 0u) {
                if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 10u)
                    go(Up);
                else if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 9u)
                    go(Confirm);
                else
                    stop("unexpected options row");
            }
            break;
        case Up:
            if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 9u)
                go(ReleaseUp);
            else if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 10u)
                buttons = pad2ButtonBit("UP");
            else
                stop("options direction overshot quit row");
            break;
        case ReleaseUp:
            if (released())
                go(Confirm);
            break;
        case Confirm:
            if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 9u &&
                reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)) == 1u)
                go(ReleaseConfirm);
            else if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 9u &&
                     reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)) == 0u) {
                // Original options 6ECDE0 reads the profile-mapped 4BAE90 action.
                buttons = pad2TestActorAction(rd, 0x20u);
                if (!buttons)
                    stop("options confirmation action unavailable in control profile");
            } else
                stop("unexpected quit confirmation state");
            break;
        case ReleaseConfirm:
            if (released())
                go(Yes);
            break;
        case Yes:
            if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) != 9u ||
                reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)) != 1u)
                stop("confirmation closed before YES");
            else if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC3u)) == 0u)
                go(ReleaseYes);
            else
                buttons = pad2ButtonBit("LEFT");
            break;
        case ReleaseYes:
            if (released())
                go(Quit);
            break;
        case Quit:
            if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 11u ||
                (reo_source_instrumentation::bankRead(rd, rd + (0x4BAE76u)) &&
                 reo_source_instrumentation::bankRead(rd, rd + (0x4BAE77u)))) {
                std::fprintf(
                    stderr,
                    "[TEST-INTERACT-QUIT] QUIT REQUEST observed row=%u sub=%u flags=%u/%u\n",
                    reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)),
                    reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)),
                    reo_source_instrumentation::bankRead(rd, rd + (0x4BAE76u)),
                    reo_source_instrumentation::bankRead(rd, rd + (0x4BAE77u)));
                go(ReturnMenu);
            } else if (reo_source_instrumentation::bankRead(rd, rd + (0x755EC1u)) == 9u &&
                       reo_source_instrumentation::bankRead(rd, rd + (0x755EC2u)) == 1u &&
                       reo_source_instrumentation::bankRead(rd, rd + (0x755EC3u)) == 0u) {
                buttons = pad2TestActorAction(rd, 0x20u);
                if (!buttons)
                    stop("final quit action unavailable in control profile");
            } else
                stop("unexpected final quit state");
            break;
        case ReturnMenu: {
            const uint32_t front = word(0x324424u);
            if (mainMenuReady(front) && released()) {
                std::fprintf(
                    stderr,
                    "[TEST-INTERACT-QUIT] MAIN MENU PROOF front=%08x mode=%u/%u reason=%u "
                    "callback=%08x overlay=%u messageProof=%u pickupProof=%u resultsProof=%u\n",
                    front, reo_source_instrumentation::bankRead(rd, rd + (front)),
                    reo_source_instrumentation::bankRead(rd, rd + (front + 1u)),
                    reo_source_instrumentation::bankRead(rd, rd + (0x324489u)), word(0x3163D4u),
                    word(0x570004u), unsigned(messageObserved), unsigned(pickupObserved),
                    unsigned(resultsAcknowledged));
                go(Done);
            } else if (!resultsAcknowledged && resultsReady(resultsWork())) {
                go(ResultsRelease);
            } else if (cardAction(cardWork()) != NoCardAction) {
                go(CardRelease);
            }
            break;
        }
        case ResultsRelease: {
            const uint32_t work = resultsWork();
            if (!resultsReady(work))
                go(ReturnMenu);
            else if (released() && half(work + 8u) == 0u && word(0x324210u) == 0u)
                go(ResultsConfirm);
            break;
        }
        case ResultsConfirm: {
            const uint32_t work = resultsWork();
            if (work && reo_source_instrumentation::bankRead(rd, rd + (work)) == 3u) {
                resultsAcknowledged = true;
                std::fprintf(
                    stderr,
                    "[TEST-INTERACT-QUIT] RESULTS PROOF work=%08x mode=%u countdown=%u edge=%04x\n",
                    work, reo_source_instrumentation::bankRead(rd, rd + (work)),
                    word(work + 0x318u), half(work + 8u));
                go(ResultsFinish);
            } else if (resultsReady(work)) {
                // Results reads raw translated324210, not the gameplay profile's
                // mapped4BAE90. Emit only physical Cross, and release on progress.
                buttons = pad2ButtonBit("CROSS");
            } else {
                // The original transition can advance before this feeder samples
                // mode3. Release immediately; never carry Cross into the save UI.
                go(ResultsFinish);
            }
            break;
        }
        case ResultsFinish:
            // Original603740 advances its countdown/resources/save flow itself.
            // Unknown memory-card prompts receive no automatic confirmation.
            if (released())
                go(ReturnMenu);
            break;
        case CardRelease: {
            const uint32_t card = cardWork();
            const CardAction action = cardAction(card);
            if (action == NoCardAction)
                go(ReturnMenu);
            else if (released() && half(card + 10u) == 0u && word(0x324210u) == 0u &&
                     (action == CardAcknowledge || word(card + 0x10u) == 0u)) {
                std::fprintf(stderr,
                             "[TEST-INTERACT-QUIT] CARD VERIFIED work=%08x mode=%u/%u/%u "
                             "message=%u cursor=%u purpose=%u action=%u\n",
                             card, reo_source_instrumentation::bankRead(rd, rd + (card + 1u)),
                             reo_source_instrumentation::bankRead(rd, rd + (card + 2u)),
                             reo_source_instrumentation::bankRead(rd, rd + (card + 3u)),
                             word(card + 0x2Cu), word(card + 0x38u), word(card + 0x3Cu),
                             unsigned(action));
                if (action == CardExit && word(card + 0x38u) == 1u)
                    go(CardChooseExit);
                else {
                    confirmingCard = card;
                    confirmingCardAction = action;
                    go(CardConfirm);
                }
            }
            break;
        }
        case CardChooseExit: {
            const uint32_t card = cardWork();
            if (cardAction(card) != CardExit)
                go(ReturnMenu);
            else if (word(card + 0x38u) == 0u)
                go(CardReleaseExit);
            else if (word(card + 0x10u) == 0u)
                buttons = pad2ButtonBit("LEFT");
            break;
        }
        case CardReleaseExit: {
            const uint32_t card = cardWork();
            if (cardAction(card) != CardExit || word(card + 0x38u) != 0u)
                go(ReturnMenu);
            else if (released() && half(card + 10u) == 0u && word(0x324210u) == 0u &&
                     word(card + 0x10u) == 0u) {
                confirmingCard = card;
                confirmingCardAction = CardExit;
                go(CardConfirm);
            }
            break;
        }
        case CardConfirm: {
            const uint32_t card = cardWork();
            if (card != confirmingCard || cardAction(card) != confirmingCardAction ||
                (confirmingCardAction == CardExit && word(card + 0x38u) != 0u)) {
                std::fprintf(stderr,
                             "[TEST-INTERACT-QUIT] CARD INPUT RELEASE work=%08x action=%u "
                             "observed=%08x phase=%u/%u\n",
                             confirmingCard, unsigned(confirmingCardAction), card,
                             reo_source_instrumentation::bankRead(rd, rd + (0x4BADD0u)),
                             reo_source_instrumentation::bankRead(rd, rd + (0x4BADD1u)));
                go(CardFinish);
            } else
                buttons = pad2ButtonBit("CROSS"); // Verified raw translated edge10.
            break;
        }
        case CardFinish:
            if (released())
                go(ReturnMenu);
            break;
        default:
            break;
    }
    return true;
}

void pad2FeederLoop() {
    try {
        uint32_t frame = 0;
        while (!g_pad2.stop.load()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
            const double now =
                std::chrono::duration<double>(std::chrono::steady_clock::now() - g_pad2.t0).count();
            uint16_t pressed = 0;
            for (const auto& pr : g_pad2.script)
                if (now >= pr.t && now < pr.t + pr.hold)
                    pressed |= pr.mask;
            reo::DualShock2State hostPad;
            hostPad.reset();
            uint8_t* routeRam = nullptr;
            {
                std::lock_guard<std::mutex> l(g_pad2.m);
                routeRam = g_pad2.rdram;
            }
            pressed |= pad2TestRoute(routeRam, now);
            pressed |= pad2AutomaticAccount(routeRam, now);
            // Live input (runtime/input: keyboard and XInput, same bit order), only while this
            // process owns the foreground window so typing elsewhere does not press buttons.
            if (ReoHwBridge* br = ReoHwBridge::instance()) {
                if (reo::Input* in = br->input()) {
                    bool focused = true;
#ifdef _WIN32
                    DWORD pid = 0;
                    if (HWND fg = GetForegroundWindow())
                        GetWindowThreadProcessId(fg, &pid);
                    focused = (pid == GetCurrentProcessId());
#endif
                    if (focused) {
                        in->update();
                        hostPad = in->get_pad(0);
                        pressed |= (uint16_t)~hostPad.buttons;
                    } else {
                        const char* testInput = std::getenv("REO_COOP_TEST_INPUT");
                        const char* privateMap = std::getenv("REO_LAUNCHER_PAD_MAP");
                        if (testInput && !strcmp(testInput, "1") && privateMap && *privateMap) {
                            in->update_controllers_only();
                            hostPad = in->get_pad(0);
                            pressed |= (uint16_t)~hostPad.buttons;
                        }
                    }
                }
            }
            // Manual or timed-script input takes precedence over automatic steering.
            const bool manualStick = std::abs(int(hostPad.left_x) - 128) > 32 ||
                                     std::abs(int(hostPad.left_y) - 128) > 32;
            if (!pressed && !manualStick) {
                uint16_t testButtons = 0;
                if (pad2TestRoomSoak(routeRam, now, hostPad, testButtons))
                    pressed |= testButtons;
                else if (pad2TestInteractQuit(routeRam, now, hostPad, testButtons))
                    pressed |= testButtons;
                else
                    pressed |= pad2TestWorldTarget(routeRam, now, hostPad);
            }
            g_pad2.lastPressed = pressed;
            const uint16_t data = (uint16_t)~pressed; // active-low
            // Keep digital directions independent from the analog sticks. Both
            // games use a neutral left stick plus D-pad for tank controls;
            // synthesizing a deflection here selects camera-relative movement.
            // Keyboard and analog test steering supply their own stick values.
            std::vector<uint32_t> socks;
            uint8_t* rd = nullptr;
            uint32_t work = 0;
            {
                std::lock_guard<std::mutex> l(g_pad2.m);
                socks = g_pad2.sockets;
                rd = g_pad2.rdram;
                work = g_pad2.workAddr;
            }
            if (!rd)
                continue;
            // sceDbcGetDepNumber (EE 0x188D90) requires the port's word in the work area to be 1.
            if (work && (work & ps2RamBackingMask()) + 4 <= ps2RamBackingBytes) {
                const uint32_t connected = 1;
                reo_source_instrumentation::copyBytesForBank(rd, rd + (work & ps2RamBackingMask()),
                                                             &connected, 4); // port 0
            }
            ++frame;
            for (uint32_t base : socks) {
                const uint32_t b0 = base & ps2RamBackingMask(), b1 = (base + 0x80) & ps2RamBackingMask();
                if (b1 + 0x80 > ps2RamBackingBytes)
                    continue;
                uint32_t s0, s1;
                reo_source_instrumentation::copyBytesForBank(rd, &s0, rd + b0 + 0x7C, 4);
                reo_source_instrumentation::copyBytesForBank(rd, &s1, rd + b1 + 0x7C, 4);
                uint8_t* rec = rd + ((s0 <= s1) ? b0 : b1);
                reo_source_instrumentation::bankCell(rd, rec + 0) =
                    1; // libpad2 state: 0 none, 1 stable/readable, 2/3 busy (game 0x1A6760)
                // Original ds2u_s1 FUN_1170's 0x73 analog report, consumed by
                // libpad2/game 0x1A6760: six raw SIO bytes and profile 0x000FFFFF.
                reo_source_instrumentation::bankCell(rd, rec + 1) = 10;
#if defined(REO_GAME_FILE2)
                // File #2 requires DUALSHOCK 2 analog mode: 0x13CB90 accepts only pad mode
                // 's' (0x73), which libpad2 0x1E8510 sets when the profile has bits in
                // 0xFFF00000. That mode reads 18 data bytes (buttons, sticks, then the 12
                // pressure bytes R L U D Tri Cir X Sq L1 R1 L2 R2); otherwise the game
                // reopens its pause menu every frame (0x619740).
                constexpr uint8_t dataBytes = 18;
#else
                constexpr uint8_t dataBytes = 6;
#endif
                reo_source_instrumentation::bankCell(rd, rec + 2) = dataBytes;
                reo_source_instrumentation::bankCell(rd, rec + 3) = 4;
                const uint32_t valid = 1;
                reo_source_instrumentation::copyBytes(rec + 4, &valid, 4);
                const uint8_t sb0 = (uint8_t)(data & 0xFF), sb1 = (uint8_t)(data >> 8);
                reo_source_instrumentation::bankCell(rd, rec + 0x1C) = sb0;
                reo_source_instrumentation::bankCell(rd, rec + 0x1D) = sb1;
                reo_source_instrumentation::bankCell(rd, rec + 0x1E) = hostPad.right_x;
                reo_source_instrumentation::bankCell(rd, rec + 0x1F) = hostPad.right_y;
                reo_source_instrumentation::bankCell(rd, rec + 0x20) = hostPad.left_x;
                reo_source_instrumentation::bankCell(rd, rec + 0x21) = hostPad.left_y;
#if defined(REO_GAME_FILE2)
                static constexpr const char* pressureOrder[12] = {
                    "RIGHT", "LEFT", "UP", "DOWN", "TRIANGLE", "CIRCLE",
                    "CROSS", "SQUARE", "L1", "R1", "L2", "R2"};
                for (int i = 0; i < 12; ++i)
                    reo_source_instrumentation::bankCell(rd, rec + 0x22 + i) =
                        (pressed & pad2ButtonBit(pressureOrder[i])) ? 0xFF : 0x00;
                // Profile 0x3FFFFFFF: digital, both sticks and all 12 pressure bytes.
                reo_source_instrumentation::bankCell(rd, rec + 0x2E) = 0xFF;
                reo_source_instrumentation::bankCell(rd, rec + 0x2F) = 0xFF;
                reo_source_instrumentation::bankCell(rd, rec + 0x30) = 0xFF;
                reo_source_instrumentation::bankCell(rd, rec + 0x31) = 0x3F;
#else
                reo_source_instrumentation::bankCell(rd, rec + 0x22) = 0xFF;
                reo_source_instrumentation::bankCell(rd, rec + 0x23) = 0xFF;
                reo_source_instrumentation::bankCell(rd, rec + 0x24) = 0x0F;
                reo_source_instrumentation::bankCell(rd, rec + 0x25) = 0;
#endif
                std::atomic_thread_fence(std::memory_order_release);
                const uint32_t seq = std::max(s0, s1) + 1;
                reo_source_instrumentation::copyBytes(rec + 0x7C, &seq, 4); // publish last
            }
        }
    } catch (const reo_parent_natural::OwnedSourceFailure&) {
        g_pad2.stop.store(true, std::memory_order_release);
    }
}

// dbcman sockets are generic devices: class 1 = pad (libpad2, EE 0x180378), class 2 =
// memory card (libmc2, EE 0x187970). Only pad sockets get pad records.
uint32_t pad2RegisterSocket(uint8_t* rdram, uint32_t eeBuf, uint32_t devClass) {
    std::lock_guard<std::mutex> l(g_pad2.m);
    g_pad2.rdram = rdram;
    const uint32_t id = g_pad2.nextSocketId++;
    if (devClass == 1u &&
        std::find(g_pad2.sockets.begin(), g_pad2.sockets.end(), eeBuf) == g_pad2.sockets.end())
        g_pad2.sockets.push_back(eeBuf);
    fprintf(stderr, "[PAD2] dbc socket %u class %u buffer 0x%08X%s\n", id, devClass, eeBuf,
            devClass == 1u ? " (pad)" : "");
    if (devClass != 1u)
        return id;
    if(g_pad2.outputSocket==UINT32_MAX || eeBuf==g_pad2.sockets.front()) {
        g_pad2.outputSocket=id;
        g_pad2.motors.store(0,std::memory_order_relaxed);
    }
    if (!g_pad2.started) {
        g_pad2.started = true;
        pad2ParseScript();
        g_pad2.thread = std::thread(pad2FeederLoop);
    }
    return id;
}

void pad2SetWorkAddr(uint8_t* rdram, uint32_t addr) {
    std::lock_guard<std::mutex> l(g_pad2.m);
    g_pad2.rdram = rdram;
    g_pad2.workAddr = addr;
    fprintf(stderr, "[PAD2] dbc work area 0x%08X\n", addr);
}
} // namespace

// Debug-panel lines (PS2Runtime::setDebugPanelProvider, installed by reo_bootstrap.cpp).
void reoDebugPanelText(std::string& out) {
    static const char* names[16] = {"SELECT", "L3",     "R3",    "START", "UP", "RIGHT",
                                    "DOWN",   "LEFT",   "L2",    "R2",    "L1", "R1",
                                    "TRI",    "CIRCLE", "CROSS", "SQUARE"};
    const uint16_t p = g_pad2.lastPressed.load();
    out += "pad:";
    if (!p)
        out += " -";
    for (int i = 0; i < 16; ++i)
        if (p & (1u << i)) {
            out += ' ';
            out += names[i];
        }
    out += '\n';
    char line[128];
    uint8_t* rd = nullptr;
    size_t sockets = 0;
    {
        std::lock_guard<std::mutex> l(g_pad2.m);
        rd = g_pad2.rdram;
        sockets = g_pad2.sockets.size();
    }
    std::snprintf(line, sizeof(line), "pad sockets %zu  script presses %zu", sockets,
                  g_pad2.script.size());
    out += line;
    out += '\n';
    if (rd) {
        uint32_t keys = 0;
        reo_source_instrumentation::copyBytesForBank(rd, &keys, rd + 0x324218,
                                                     4); // system keys (held), sub_001B0DB0
        std::snprintf(line, sizeof(line), "game pad state %u  sys keys %04X",
                      reo_source_instrumentation::bankRead(rd, rd + (0x2B0A10)), keys & 0xFFFF);
        out += line;
        out += '\n';
        // Resident code overlays (MWo3 header: +4 id, +0x1C name), see tools/overlay_extract.py.
        for (uint32_t base : {0x370000u, 0x570000u, 0x6E0000u, 0x810000u}) {
            if (std::memcmp(rd + base, "MWo3", 4) != 0)
                continue;
            uint32_t id = 0;
            reo_source_instrumentation::copyBytesForBank(rd, &id, rd + base + 4, 4);
            char name[17] = {};
            reo_source_instrumentation::copyBytesForBank(rd, name, rd + base + 0x1C, 16);
            std::snprintf(line, sizeof(line), "ovl %06X: id %u %s", base, id, name);
            out += line;
            out += '\n';
        }
    }
    out += "keys: WASD dpad  Space X  E O\n"
           "      Q []  R /\\  Enter START\n"
           "      Bksp SELECT  1/2 L1/R1  3/4 L2/R2\n";
}

// Stop the pad feeder before guest RAM goes away (reo_bootstrap.cpp, after runtime.run()).
void reoPad2RumbleFrame() {
#ifdef _WIN32
    const auto speeds=g_pad2.motors.load(std::memory_order_relaxed);
    XINPUT_VIBRATION vibration{WORD(speeds),WORD(speeds>>16)};
    XInputSetState(0,&vibration);
#endif
}
void reoPad2Stop() {
    g_pad2.motors.store(0,std::memory_order_relaxed);
    reoPad2RumbleFrame();
    g_pad2.stop = true;
    if (g_pad2.thread.joinable())
        g_pad2.thread.join();
}

bool ReoHwBridge::onSifRpc(uint32_t sid, uint32_t rpcNum, uint32_t sendBuf, uint32_t sendSize,
                           uint32_t recvBuf, uint32_t recvSize, uint8_t* rdram, void* user) {
    auto* self = static_cast<ReoHwBridge*>(user);

    // An IOP reboot (SIF_CMD_RESET, D1) wipes IOP memory: reset IOP-resident HLE
    // state (heap, open files) when the runtime's reboot count changes.
    if (self) {
        const uint32_t boots = ps2_stubs::hleIopRebootCount();
        if (boots != self->m_iopBootSeen) {
            g_pad2.motors.store(0,std::memory_order_relaxed);
            g_pad2.outputSocket=UINT32_MAX;
            self->m_iopBootSeen = boots;
            self->m_iopHeapNext = kIopHeapBase;
            if (self->m_network)
                self->m_network->reset();
            self->m_privateKeyboard.reset();
            self->m_netProfile.reset();
            for (auto& f : self->m_fioFds) {
                if (f) {
                    fclose(f);
                    f = nullptr;
                }
            }
            fprintf(stderr, "[HW-BRIDGE:IOP] reboot #%u: HLE IOP heap and fds reset\n", boots);
        }
    }

    switch (sid) {
        case 0x80000211: {
            const char* path = std::getenv("REO_COOP_KEYBOARD_FILE");
            if (!self || !rdram || !path || !*path)
                return false;
            const auto valid = [](uint32_t address, size_t size) {
                const uint32_t bank = address & 0xFE000000u;
                const uint32_t physical = address & 0x1FFFFFFFu;
                return (bank == 0 || bank == 0x20000000u || bank == 0x80000000u ||
                        bank == 0xA0000000u) &&
                       physical < ps2RamBackingBytes && size <= ps2RamBackingBytes - physical;
            };
            if (sendSize > 0x1000 || recvSize > 0x1000 || !valid(sendBuf, sendSize) ||
                !valid(recvBuf, recvSize))
                return false;
            if (!self->m_privateKeyboard)
                self->m_privateKeyboard = std::make_unique<PrivateUsbKeyboard>(path);
            std::vector<uint8_t> request(sendSize);
            reo_source_instrumentation::copyBytesForBank(rdram, request.data(),
                                                         rdram + (sendBuf & 0x1FFFFFFFu), sendSize);
            const auto reply = self->m_privateKeyboard->call(rpcNum, request, recvSize);
            if (reply.size() != recvSize)
                return false;
            reo_source_instrumentation::copyBytesForBank(rdram, rdram + (recvBuf & 0x1FFFFFFFu),
                                                         reply.data(), reply.size());
            return true;
        }
        case 0x80001101: {
            const char* host = std::getenv("REO_COOP_HOST");
            if (!self || !rdram || !host || !*host)
                return false;
            const auto valid = [](uint32_t address, size_t size) {
                const uint32_t bank = address & 0xFE000000u;
                const uint32_t physical = address & 0x1FFFFFFFu;
                return (bank == 0 || bank == 0x20000000u || bank == 0x80000000u ||
                        bank == 0xA0000000u) &&
                       physical < ps2RamBackingBytes && size <= ps2RamBackingBytes - physical;
            };
            if (sendSize > 0x10000 || recvSize < 4 || recvSize > 0x10000 ||
                !valid(sendBuf, sendSize) || !valid(recvBuf, recvSize))
                return false;
            const auto value = [](const std::vector<uint8_t>& bytes, size_t offset) {
                uint32_t result = 0;
                if (offset + sizeof(result) <= bytes.size())
                    memcpy(&result, bytes.data() + offset, sizeof(result));
                return result;
            };
            if (!self->m_netProfile) {
                if (!self->m_network)
                    self->m_network = std::make_unique<SnapIopTransport>();
                const auto info = self->m_network->call(0x34, std::vector<uint8_t>(0x1C), 0x28);
                const auto dns = self->m_network->call(0x2D, std::vector<uint8_t>(0x1C), 0x124);
                const auto ip = [](uint32_t raw) {
                    char text[16];
                    snprintf(text, sizeof(text), "%u.%u.%u.%u", raw & 255u, (raw >> 8) & 255u,
                             (raw >> 16) & 255u, raw >> 24);
                    return std::string(text);
                };
                reo_network::NetcnfHostProfile profile;
                profile.available = info.size() == 0x28 && value(info, 0x18) == 0 &&
                                    value(info, 0x1C) != 0 && value(dns, 0x18) == 0;
                profile.address = ip(value(info, 0x1C));
                profile.netmask = ip(value(info, 0x20));
                profile.gateway = ip(value(info, 0x24));
                profile.dns1 = ip(value(dns, 0x11C));
                profile.dns2 = ip(value(dns, 0x120));
                self->m_netProfile =
                    std::make_unique<reo_network::NetcnfProfileService>(std::move(profile));
            }
            std::vector<uint8_t> request(sendSize);
            reo_source_instrumentation::copyBytesForBank(rdram, request.data(),
                                                         rdram + (sendBuf & 0x1FFFFFFFu), sendSize);
            const auto reply = self->m_netProfile->call(
                rpcNum, request, recvSize,
                [&](uint32_t address, const uint8_t* bytes, size_t size) {
                    if (!valid(address, size))
                        return false;
                    reo_source_instrumentation::copyBytesForBank(
                        rdram, rdram + (address & 0x1FFFFFFFu), bytes, size);
                    return true;
                });
            if (reply.size() != recvSize)
                return false;
            reo_source_instrumentation::copyBytesForBank(rdram, rdram + (recvBuf & 0x1FFFFFFFu),
                                                         reply.data(), reply.size());
            const char* trace = std::getenv("REO_NET_TRACE");
            if (trace && !strcmp(trace, "1"))
                fprintf(
                    stderr, "[NETCNF] op=%X reply=%d send=%u recv=%u request=%08X,%08X,%08X,%08X\n",
                    rpcNum, static_cast<int32_t>(value(reply, 0)), sendSize, recvSize,
                    value(request, 0), value(request, 4), value(request, 8), value(request, 12));
            return true;
        }
        case 0x01270110: {
            const char* host = std::getenv("REO_COOP_HOST");
            if (!self || !rdram || !host || !*host)
                return false;
            const auto valid = [](uint32_t address, uint32_t size) {
                const uint32_t bank = address & 0xFE000000u;
                const uint32_t physical = address & 0x1FFFFFFFu;
                return (bank == 0 || bank == 0x20000000u || bank == 0x80000000u ||
                        bank == 0xA0000000u) &&
                       physical < ps2RamBackingBytes && size <= ps2RamBackingBytes - physical;
            };
            if (sendSize > 0x10000 || recvSize > 0x10000 || recvSize < 0x1C ||
                !valid(sendBuf, sendSize) || !valid(recvBuf, recvSize)) {
                fprintf(stderr, "[SNIOP] invalid RPC buffers op=%X send=%08X/%u recv=%08X/%u\n",
                        rpcNum, sendBuf, sendSize, recvBuf, recvSize);
                return false;
            }
            if (!self->m_network)
                self->m_network = std::make_unique<SnapIopTransport>();
            std::vector<uint8_t> request(sendSize);
            reo_source_instrumentation::copyBytesForBank(rdram, request.data(),
                                                         rdram + (sendBuf & 0x1FFFFFFFu), sendSize);
            const auto reply = self->m_network->call(rpcNum, request, recvSize);
            if (reply.size() != recvSize)
                return false;
            reo_source_instrumentation::copyBytesForBank(rdram, rdram + (recvBuf & 0x1FFFFFFFu),
                                                         reply.data(), reply.size());
            return true;
        }
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
                        const uint8_t b = reo_source_instrumentation::bankRead(
                            rdram, rdram + ((sendBuf + i) & ps2RamBackingMask()));
                        snprintf(hex + i * 3, 4, "%02X ", b);
                    }
                    const uint32_t m = std::min<uint32_t>(sendSize, 64);
                    for (uint32_t i = 0; i < m; ++i) {
                        const uint8_t b = reo_source_instrumentation::bankRead(
                            rdram, rdram + ((sendBuf + i) & ps2RamBackingMask()));
                        text[i] = (b >= 0x20 && b < 0x7F) ? (char)b : '.';
                    }
                }
                fprintf(stderr,
                        "[HW-BRIDGE:FIO] fno=0x%X send=0x%08X/%u recv=0x%08X/%u data=[%s] \"%s\"\n",
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
                    if (recvSize >= 8)
                        rdramWrite32(rdram, recvBuf + 4, 2u);
                } else if (rpcNum == 0x0 && sendBuf && sendSize >= 0x18 && self && self->m_cdvd) {
                    // open. Request (EE fio_open 0x118A70): +0 completion sema, +4 EE
                    // result address, +8 result size, +0xC flags, +0x10 mode, +0x14 path.
                    // recv[0] != 0 = accepted; the result is delivered asynchronously
                    // (IOP: cmd 0x80000011 -> copy to EE address, iSignalSema).
                    const uint32_t sema = rdramRead32(rdram, sendBuf + 0x0);
                    const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                    const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                    const uint32_t flags = rdramRead32(rdram, sendBuf + 0xC);
                    std::string path;
                    for (uint32_t i = 0x14; i < std::min<uint32_t>(sendSize, 0x14 + 0x400); ++i) {
                        const char ch = (char)reo_source_instrumentation::bankRead(
                            rdram, rdram + ((sendBuf + i) & ps2RamBackingMask()));
                        if (!ch)
                            break;
                        path.push_back(ch);
                    }
                    int32_t result = -2; // ENOENT
                    if ((flags & 0x3) != 0x1) {
                        result = -30; // EROFS: only O_RDONLY on the disc
                    } else if (self->m_cdvd->file_exists(path)) {
                        FILE* f = _wfopen(self->m_cdvd->resolve_path(path).c_str(), L"rb");
                        if (f) {
                            int fd = 0;
                            while (fd < kMaxFioFds && self->m_fioFds[fd])
                                ++fd;
                            if (fd < kMaxFioFds) {
                                self->m_fioFds[fd] = f;
                                result = fd;
                            } else {
                                fclose(f);
                                result = -24;
                            } // EMFILE
                        }
                    }
                    if (resAddr && resSize >= 4)
                        rdramWrite32(rdram, resAddr, (uint32_t)result);
                    rdramWrite32(rdram, recvBuf, 1u); // accepted
                    const bool sig = ps2_syscalls::hleSignalSema(sema);
                    fprintf(stderr, "[HW-BRIDGE:FIO] open \"%s\" flags=0x%X -> %d (sema %u %s)\n",
                            path.c_str(), flags, result, sema, sig ? "signaled" : "NOT signaled");
                } else if (rpcNum == 0x2 && sendBuf && sendSize >= 0x18 && self) {
                    // read: +0xC fd, +0x10 EE buffer, +0x14 size. On hardware the IOP DMAs
                    // the aligned part to the EE buffer and sends unaligned head/tail bytes
                    // via cmd 0x80000011; the HLE writes the bytes directly (same end state).
                    const uint32_t sema = rdramRead32(rdram, sendBuf + 0x0);
                    const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                    const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                    const int32_t fd = (int32_t)rdramRead32(rdram, sendBuf + 0xC);
                    const uint32_t buf = rdramRead32(rdram, sendBuf + 0x10);
                    const int32_t size = (int32_t)rdramRead32(rdram, sendBuf + 0x14);
                    std::FILE* f = (fd >= 0 && fd < kMaxFioFds) ? self->m_fioFds[fd] : nullptr;
                    const uint32_t phys = buf & ps2RamBackingMask();
                    int32_t result = -9; // EBADF
                    if (f && size < 0) {
                        result = -22; // EINVAL
                    } else if (f && (uint64_t)phys + (uint32_t)size > ps2RamBackingBytes) {
                        result = -14; // EFAULT
                    } else if (f) {
                        result = (int32_t)fread(rdram + phys, 1, (size_t)size, f);
                    }
                    if (resAddr && resSize >= 4)
                        rdramWrite32(rdram, resAddr, (uint32_t)result);
                    rdramWrite32(rdram, recvBuf, 1u); // accepted
                    const bool sig = ps2_syscalls::hleSignalSema(sema);
                    fprintf(stderr,
                            "[HW-BRIDGE:FIO] read fd=%d buf=0x%08X size=%d -> %d (sema %u %s)\n",
                            fd, buf, size, result, sema, sig ? "signaled" : "NOT signaled");
                } else if (rpcNum == 0x17 && sendBuf && sendSize >= 0x81C) {
                    // devctl (EE client 0x11B248): +0xC device name, +0x40C input,
                    // +0x80C cmd, +0x810 in len, +0x814 out buf, +0x818 out len.
                    // No HDD/network devices are emulated: fail with ENODEV like a PS2
                    // without the device, completing the async request.
                    const uint32_t sema = rdramRead32(rdram, sendBuf + 0x0);
                    const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                    const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                    const uint32_t cmd = rdramRead32(rdram, sendBuf + 0x80C);
                    std::string dev;
                    for (uint32_t i = 0xC; i < 0xC + 0x40; ++i) {
                        const char ch = (char)reo_source_instrumentation::bankRead(
                            rdram, rdram + ((sendBuf + i) & ps2RamBackingMask()));
                        if (!ch)
                            break;
                        dev.push_back(ch);
                    }
                    const int32_t result = -19; // ENODEV
                    if (resAddr && resSize >= 4)
                        rdramWrite32(rdram, resAddr, (uint32_t)result);
                    rdramWrite32(rdram, recvBuf, 1u); // accepted
                    const bool sig = ps2_syscalls::hleSignalSema(sema);
                    fprintf(
                        stderr,
                        "[HW-BRIDGE:FIO] devctl \"%s\" cmd=0x%X -> %d (no device; sema %u %s)\n",
                        dev.c_str(), cmd, result, sema, sig ? "signaled" : "NOT signaled");
                } else if ((rpcNum == 0x1 || rpcNum == 0x4) && sendBuf && sendSize >= 0x10 &&
                           self) {
                    // close (1): +0xC fd.  lseek (4): +0xC fd, +0x10 offset, +0x14 whence.
                    // Same async completion as open: result to +4, signal sema at +0.
                    const uint32_t sema = rdramRead32(rdram, sendBuf + 0x0);
                    const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                    const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                    const int32_t fd = (int32_t)rdramRead32(rdram, sendBuf + 0xC);
                    std::FILE* f = (fd >= 0 && fd < kMaxFioFds) ? self->m_fioFds[fd] : nullptr;
                    int32_t result = -9; // EBADF
                    if (f && rpcNum == 0x1) {
                        fclose(f);
                        self->m_fioFds[fd] = nullptr;
                        result = 0;
                    } else if (f && rpcNum == 0x4 && sendSize >= 0x18) {
                        const int32_t off = (int32_t)rdramRead32(rdram, sendBuf + 0x10);
                        const int32_t whence = (int32_t)rdramRead32(rdram, sendBuf + 0x14);
                        if (whence >= 0 && whence <= 2 && _fseeki64(f, off, whence) == 0) {
                            const long long pos = _ftelli64(f);
                            result = (pos >= 0 && pos <= 0x7FFFFFFF) ? (int32_t)pos : -22; // EINVAL
                        } else {
                            result = -22;
                        }
                    }
                    if (resAddr && resSize >= 4)
                        rdramWrite32(rdram, resAddr, (uint32_t)result);
                    rdramWrite32(rdram, recvBuf, 1u); // accepted
                    const bool sig = ps2_syscalls::hleSignalSema(sema);
                    fprintf(stderr, "[HW-BRIDGE:FIO] %s fd=%d -> %d (sema %u %s)\n",
                            rpcNum == 0x1 ? "close" : "lseek", fd, result, sema,
                            sig ? "signaled" : "NOT signaled");
                } else if (rpcNum != 0xFF && sendBuf && sendSize >= 0xC) {
                    // Any other fileio op uses the same async header (+0 sema, +4 result
                    // addr, +8 result size). Complete it with an error so the EE never
                    // waits forever, and log it as unimplemented.
                    const uint32_t sema = rdramRead32(rdram, sendBuf + 0x0);
                    const uint32_t resAddr = rdramRead32(rdram, sendBuf + 0x4);
                    const uint32_t resSize = rdramRead32(rdram, sendBuf + 0x8);
                    const int32_t result = -48; // unsupported
                    if (resAddr && resSize >= 4)
                        rdramWrite32(rdram, resAddr, (uint32_t)result);
                    rdramWrite32(rdram, recvBuf, 1u);
                    const bool sig = ps2_syscalls::hleSignalSema(sema);
                    fprintf(stderr,
                            "[HW-BRIDGE:FIO] ** UNIMPLEMENTED fno=0x%X -> %d (sema %u %s)\n",
                            rpcNum, result, sema, sig ? "signaled" : "NOT signaled");
                } else {
                    rdramWrite32(rdram, recvBuf, 0xFFFFFFFFu);
                }
            }
            return true;
        }

        // ── cdvdfsv (IOP CD/DVD file server) used by the game's libcdvd ──────────
        // Layouts per Play! (jpd002/Play-, Source/iop/Iop_Cdvdfsv.cpp). Reads are completed
        // synchronously (the runtime then runs any end callback), so libcdvd's sceCdSync
        // sees them done. Sector data comes from the disc image (reo::CDVD, REO_ISO).
        case 0x80000593: { // S-commands
            static int sLog = 0;
            static const bool cdLogAll =
                std::getenv("REO_CD_LOG") != nullptr; // unlimited CD RPC log
            if (cdLogAll || sLog++ < 40)
                fprintf(stderr, "[HW-BRIDGE:CDS] fn=0x%x\n", rpcNum);
            uint32_t r0 = 1, r1 = 0;
            switch (rpcNum) {
                case 0x03:
                    r0 = 0x14;
                    break; // GetDiskType: PS2 DVD
                case 0x04:
                    r0 = 0;
                    break; // GetError: none
                case 0x0C:
                    r0 = 0x0A;
                    break; // Status: paused
                case 0x05:
                    r0 = 1;
                    r1 = 0;
                    break; // TrayReq: no tray change
                default:
                    r0 = 1;
                    break; // 0x16 Break, 0x22 SetMediaMode, 0x27 DualInfo...
            }
            if (recvBuf && recvSize >= 4)
                rdramWrite32(rdram, recvBuf, r0);
            if (recvBuf && recvSize >= 8)
                rdramWrite32(rdram, recvBuf + 4, r1);
            return true;
        }
        case 0x80000595: { // N-commands
            static int nLog = 0;
            const uint32_t a0 = sendBuf ? rdramRead32(rdram, sendBuf + 0) : 0;
            const uint32_t a1 = sendBuf ? rdramRead32(rdram, sendBuf + 4) : 0;
            const uint32_t a2 = sendBuf ? rdramRead32(rdram, sendBuf + 8) : 0;
            if (rpcNum == 0x01) { // Read {sector, count, dst, mode}
                const uint32_t dst = a2 & ps2RamBackingMask();
                bool ok = false;
                if (self && self->m_cdvd && a1 != 0 && a1 <= 0x4000 &&
                    static_cast<uint64_t>(dst) + static_cast<uint64_t>(a1) * 2048u <= ps2RamBackingBytes)
                    ok = self->m_cdvd->read_sectors(a0, a1, rdram + dst);
                static const bool cdLogAllN = std::getenv("REO_CD_LOG") != nullptr;
                if (cdLogAllN || nLog++ < 60)
                    fprintf(stderr, "[HW-BRIDGE:CDN] read lsn=%u n=%u dst=0x%08X -> %s\n", a0, a1,
                            a2, ok ? "ok" : "FAIL");
                if (recvBuf && recvSize >= 4)
                    rdramWrite32(rdram, recvBuf, 0);
                return true;
            }
            static const bool cdLogAllF = std::getenv("REO_CD_LOG") != nullptr;
            if (cdLogAllF || nLog++ < 60)
                fprintf(stderr, "[HW-BRIDGE:CDN] fn=0x%x args=%08X %08X %08X\n", rpcNum, a0, a1,
                        a2);
            uint32_t r0 = 1;
            if (rpcNum == 0x0E)
                r0 = 2; // NDiskReady: ready
            if (recvBuf && recvSize >= 4)
                rdramWrite32(rdram, recvBuf, r0);
            return true;
        }
        case 0x80000596: // SetPowerOffCallback etc.
            if (recvBuf && recvSize >= 4)
                rdramWrite32(rdram, recvBuf, 1);
            return true;
        case 0x80000597: { // SearchFile: path at +0x24 (+0x20 for 0x124-byte packets)
            const uint32_t pathOff = (sendSize == 0x124) ? 0x20u : 0x24u;
            std::string path;
            if (sendBuf) {
                for (uint32_t i = 0; i < 0x100; ++i) {
                    const uint32_t a = (sendBuf + pathOff + i) & ps2RamBackingMask();
                    if (a >= ps2RamBackingBytes ||
                        reo_source_instrumentation::bankRead(rdram, rdram + (a)) == 0)
                        break;
                    path.push_back(static_cast<char>(
                        reo_source_instrumentation::bankRead(rdram, rdram + (a))));
                }
            }
            uint32_t lba = 0, size = 0;
            const bool found =
                self && self->m_cdvd && !path.empty() && self->m_cdvd->search_file(path, lba, size);
            if (found && sendBuf) {
                rdramWrite32(rdram, sendBuf + 0, lba);  // sceCdlFILE.lsn
                rdramWrite32(rdram, sendBuf + 4, size); // sceCdlFILE.size
            }
            fprintf(stderr, "[HW-BRIDGE:CDSEARCH] \"%s\" -> %s lsn=%u size=%u\n", path.c_str(),
                    found ? "found" : "NOT FOUND", lba, size);
            if (recvBuf && recvSize >= 4)
                rdramWrite32(rdram, recvBuf, found ? 1u : 0u);
            return true;
        }
        case 0x8000059A:
        case 0x8000059C: // DiskReady: 2 = ready
            if (recvBuf && recvSize >= 4)
                rdramWrite32(rdram, recvBuf, 2);
            return true;

        case SIF_CDVD: {
            static int cdvdLog = 0;
            if (cdvdLog < 50) {
                printf("[HW-BRIDGE:CDVD] rpc func=%u send=0x%08X recv=0x%08X\n", rpcNum, sendBuf,
                       recvBuf);
                cdvdLog++;
            }

            switch (rpcNum) {
                case 0: // cdInit
                    printf("[HW-BRIDGE:CDVD] cdInit\n");
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 1);
                    return true;

                case 1: { // cdRead (sector-based)
                    if (!sendBuf)
                        return true;
                    uint32_t lba = rdramRead32(rdram, sendBuf);
                    uint32_t sectors = rdramRead32(rdram, sendBuf + 4);
                    uint32_t bufAddr = rdramRead32(rdram, sendBuf + 8);
                    printf("[HW-BRIDGE:CDVD] cdRead: LBA=%u sectors=%u buf=0x%08X\n", lba, sectors,
                           bufAddr);
                    // TODO: Raw sector reads need ISO layout table
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 1);
                    return true;
                }

                case 2: // cdStop
                case 3: // cdPause
                case 4: // cdGetToc
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 1);
                    return true;

                case 5: { // cdReadFile — read file by PS2 path
                    if (!sendBuf || !recvBuf || !self->m_cdvd)
                        break;

                    // Detect send buffer format: path string or structured data
                    uint32_t sendPhys = sendBuf & ps2RamBackingMask();
                    if (sendPhys >= ps2RamBackingBytes)
                        break;
                    const uint8_t* sendPtr = rdram + sendPhys;

                    std::string ps2_path;
                    uint32_t destAddr = 0;

                    // Check if first bytes look like a path string
                    if (sendPtr[0] == 'c' || sendPtr[0] == 'C' || sendPtr[0] == '\\' ||
                        sendPtr[0] == '/') {
                        ps2_path = (const char*)sendPtr;
                        destAddr = rdramRead32(rdram, sendBuf + 256); // dest after path
                        if (destAddr == 0)
                            destAddr = recvBuf;
                    } else {
                        // Structured: {sectors, dest_addr, path...} or similar
                        destAddr = rdramRead32(rdram, sendBuf + 4);
                        uint32_t pathPhys = (sendBuf + 8) & ps2RamBackingMask();
                        if (pathPhys < ps2RamBackingBytes) {
                            ps2_path = (const char*)(rdram + pathPhys);
                        }
                        if (destAddr == 0)
                            destAddr = recvBuf;
                    }

                    if (!ps2_path.empty()) {
                        printf("[HW-BRIDGE:CDVD] cdReadFile: %s → dest=0x%08X\n", ps2_path.c_str(),
                               destAddr);

                        std::vector<uint8_t> data;
                        if (self->m_cdvd->read_file(ps2_path, data)) {
                            uint32_t destPhys = destAddr & ps2RamBackingMask();
                            if (destPhys + data.size() <= ps2RamBackingBytes) {
                                reo_source_instrumentation::copyBytesForBank(
                                    rdram, rdram + destPhys, data.data(), data.size());
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
                    if (!sendBuf || !recvBuf || !self->m_cdvd)
                        break;

                    uint32_t sendPhys = sendBuf & ps2RamBackingMask();
                    if (sendPhys >= ps2RamBackingBytes)
                        break;
                    std::string ps2_path = (const char*)(rdram + sendPhys);

                    printf("[HW-BRIDGE:CDVD] cdSearchFile: %s\n", ps2_path.c_str());

                    if (self->m_cdvd->file_exists(ps2_path)) {
                        uint32_t size = self->m_cdvd->file_size(ps2_path);
                        rdramWrite32(rdram, recvBuf + 0, 1);    // LBA (fake)
                        rdramWrite32(rdram, recvBuf + 4, size); // File size
                        rdramWrite32(rdram, recvBuf + 8, 0);    // Date
                        printf("[HW-BRIDGE:CDVD] Found: size=%u\n", size);
                    } else {
                        rdramWrite32(rdram, recvBuf + 0, 0);
                        rdramWrite32(rdram, recvBuf + 4, 0);
                        printf("[HW-BRIDGE:CDVD] Not found\n");
                    }
                    return true;
                }

                case 7: // cdGetDiskType — PS2DVD
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 0x14);
                    return true;

                case 12: // cdStatus — ready
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 0x0A);
                    return true;

                default:
                    printf("[HW-BRIDGE:CDVD] unhandled func=%u\n", rpcNum);
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 0);
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
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 1);
                    return true;
                case 3: // padGetState → STABLE
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 6);
                    return true;
                case 4: { // padRead
                    if (recvBuf && recvSize >= 32) {
                        // Fill with default pad state (all released, analog centered)
                        uint32_t recvPhys = recvBuf & ps2RamBackingMask();
                        if (recvPhys + 32 <= ps2RamBackingBytes) {
                            uint8_t* buf = rdram + recvPhys;
                            reo_source_instrumentation::fillBytes(buf, 0, 32);
                            reo_source_instrumentation::memoryCell(buf + 0) = 0x00; // success
                            reo_source_instrumentation::memoryCell(buf + 1) = 0x79; // DualShock2
                            reo_source_instrumentation::memoryCell(buf + 2) =
                                0xFF; // buttons high (released)
                            reo_source_instrumentation::memoryCell(buf + 3) =
                                0xFF; // buttons low (released)
                            reo_source_instrumentation::memoryCell(buf + 4) = 0x80; // RX
                            reo_source_instrumentation::memoryCell(buf + 5) = 0x80; // RY
                            reo_source_instrumentation::memoryCell(buf + 6) = 0x80; // LX
                            reo_source_instrumentation::memoryCell(buf + 7) = 0x80; // LY

                            // Read live input if available
                            if (self->m_input) {
                                const reo::DualShock2State& pad = self->m_input->get_pad(0);
                                reo_source_instrumentation::memoryCell(buf + 2) =
                                    (uint8_t)(pad.buttons >> 8);
                                reo_source_instrumentation::memoryCell(buf + 3) =
                                    (uint8_t)(pad.buttons & 0xFF);
                                reo_source_instrumentation::memoryCell(buf + 4) = pad.right_x;
                                reo_source_instrumentation::memoryCell(buf + 5) = pad.right_y;
                                reo_source_instrumentation::memoryCell(buf + 6) = pad.left_x;
                                reo_source_instrumentation::memoryCell(buf + 7) = pad.left_y;
                                reo_source_instrumentation::copyBytes(buf + 8, pad.pressure, 12);
                            }
                        }
                    }
                    return true;
                }
                default:
                    if (recvBuf)
                        rdramWrite32(rdram, recvBuf, 0);
                    return true;
            }
        }

        case SIF_MCSERV: {
            static reo::memory_card::Service cards([] {
                namespace fs = std::filesystem;
                std::array<fs::path, 2> roots{PS2Runtime::getIoPaths().mcRoot, {}};
#ifdef _WIN32
                if (const wchar_t* card = _wgetenv(L"REO_MC1_ROOT");
                    card && *card && std::wcscmp(card, L":none:") != 0)
                    roots[1] = fs::path(card);
#else
                if (const char* card = std::getenv("REO_MC1_ROOT");
                    card && *card && std::strcmp(card, ":none:") != 0)
                    roots[1] = card;
#endif
                return roots;
            }());
            auto valid = [](uint32_t address, size_t count) {
                const uint32_t bank = address & 0xfe000000u;
                if (bank != 0 && bank != 0x20000000u && bank != 0x80000000u && bank != 0xa0000000u)
                    return false;
                const uint32_t physical = address & 0x1fffffffu;
                return physical < ps2RamBackingBytes && count <= ps2RamBackingBytes - physical;
            };
            auto read = [&](uint32_t address, void* data, size_t count) {
                if (!valid(address, count))
                    return false;
                reo_source_instrumentation::copyBytesForBank(
                    rdram, data, rdram + (address & 0x1fffffffu), count);
                return true;
            };
            auto write = [&](uint32_t address, const void* data, size_t count) {
                if (!valid(address, count))
                    return false;
                reo_source_instrumentation::copyBytesForBank(rdram, rdram + (address & 0x1fffffffu),
                                                             data, count);
                return true;
            };
            std::vector<uint8_t> request(std::min<uint32_t>(sendSize, 1044));
            int result = -5;
            if (sendSize <= 1044 &&
                (sendSize == 0 || read(sendBuf, request.data(), request.size())))
                result = cards.call(rpcNum, request, read, write);
            if (recvBuf && recvSize >= 4)
                write(recvBuf, &result, 4);
            if ((rpcNum == 0x70 || rpcNum == 0xfe) && recvSize >= 12) {
                const uint32_t version = 0x020a;
                write(recvBuf + 4, &version, 4);
                write(recvBuf + 8, &version, 4);
            }
            static unsigned mcLog = 0;
            if (++mcLog <= 48 || result < -2)
                std::fprintf(stderr, "[MC-RPC] command=%02x result=%d bytes=%u\n", rpcNum, result,
                             sendSize);
            return true;
        }

        case SIF_LIBSD: {
            // Sound driver — stub
            static int sdLog = 0;
            if (sdLog < 10) {
                printf("[HW-BRIDGE:SD] rpc func=%u\n", rpcNum);
                sdLog++;
            }
            if (recvBuf)
                rdramWrite32(rdram, recvBuf, 0);
            return true;
        }

        case 0x80001300: // dbcman (libdbc: pad/multitap data buffer control)
        case 0x8000131B:
        case 0x8000131C: {
            // libdbc init (EE 0x188938) binds these three servers and requires the
            // version returned by rpc 0x80001363 (EE 0x1888E0) to satisfy (v >> 8) == 3
            // ("libdbc.a = 3.0"). Minor version unverified. Other calls are logged and
            // answered with zeroed success until their semantics are needed.
            // Decode before clearing a reply: libdbc reuses its request buffer.
            reo::pad2::Output output;
            if(sendBuf && sendSize>=12 && sendSize<=0x1090 && g_pad2.outputSocket!=UINT32_MAX) {
                const uint32_t physical=sendBuf&0x1fffffffu;
                if(physical<ps2RamBackingBytes && sendSize<=ps2RamBackingBytes-physical) {
                    std::vector<uint8_t> request(sendSize);
                    reo_source_instrumentation::copyBytesForBank(rdram,request.data(),rdram+physical,sendSize);
                    const auto previous=g_pad2.motors.load(std::memory_order_relaxed);
                    output=reo::pad2::decodeOutput(rpcNum,g_pad2.outputSocket,request,
                        {uint16_t(previous),uint16_t(previous>>16)});
                    if(output.kind==reo::pad2::OutputKind::Motors) {
                        const uint32_t speeds=output.motors.large | uint32_t(output.motors.small)<<16;
                        g_pad2.motors.store(speeds,std::memory_order_relaxed);
                        if(previous!=speeds && std::getenv("REO_RUMBLE_DIAG"))
                            std::fprintf(stderr,"[PAD-RUMBLE] large=%u small=%u\n",output.motors.large,output.motors.small);
                    }
                }
            }
            static int dbcLog = 0;
            if (dbcLog < 80) {
                char hex[3 * 32 + 1] = {0};
                if (sendBuf && sendSize) {
                    const uint32_t n = std::min<uint32_t>(sendSize, 32);
                    for (uint32_t i = 0; i < n; ++i)
                        snprintf(hex + i * 3, 4, "%02X ",
                                 reo_source_instrumentation::bankRead(
                                     rdram, rdram + ((sendBuf + i) & ps2RamBackingMask())));
                }
                fprintf(
                    stderr,
                    "[HW-BRIDGE:DBC] sid=0x%08X rpc=0x%X send=0x%08X/%u recv=0x%08X/%u data=[%s]\n",
                    sid, rpcNum, sendBuf, sendSize, recvBuf, recvSize, hex);
                dbcLog++;
            }
            // sceDbcCreateSocket (EE 0x188C30): EE record buffer at +0x28 (+0x80 at +0x2C);
            // the reply's socket id at +0x24 is 0 (single pad socket).
            uint32_t socketId = 0;
            if (rpcNum == 0x80001301u && sendBuf && sendSize >= 0x30)
                socketId = pad2RegisterSocket(rdram, rdramRead32(rdram, sendBuf + 0x28),
                                              rdramRead32(rdram, sendBuf + 4));
            // sceDbcSetWorkAddr (EE 0x188BC0): EE area at +4 receives per-port connection words.
            if (rpcNum == 0x80001304u && sendBuf && sendSize >= 8)
                pad2SetWorkAddr(rdram, rdramRead32(rdram, sendBuf + 4));
            bool stateQuery = false;
            if (sendBuf && sendSize >= 12) {
                const uint32_t head[3]{rdramRead32(rdram, sendBuf), rdramRead32(rdram, sendBuf + 4),
                                       rdramRead32(rdram, sendBuf + 8)};
                stateQuery = reo::pad2::isStateQuery(
                    rpcNum, {reinterpret_cast<const uint8_t*>(head), sizeof(head)});
            }
            if (recvBuf && recvSize >= 4) {
                for (uint32_t off = 0; off + 4 <= recvSize && off < 0x40; off += 4)
                    rdramWrite32(rdram, recvBuf + off, 0);
                if (rpcNum == 0x80001363u)
                    rdramWrite32(rdram, recvBuf, 0x0300u); // dbcman 3.0
                if (rpcNum == 0x80001301u && recvSize >= 0x28)
                    rdramWrite32(rdram, recvBuf + 0x24, socketId);
                if(output.kind==reo::pad2::OutputKind::Profile && recvSize>=0x210) {
                    rdramWrite32(rdram,recvBuf+8,1);
                    rdramWrite32(rdram,recvBuf+12,3); // one-bit small + eight-bit large motor
                    rdramWrite32(rdram,recvBuf+0x20c,0);
                }
                // The bridge always reports a connected pad: answer the state
                // query with one byte, 1 (stable), as stamped into the records.
                if (stateQuery && recvSize >= 0x210) {
                    rdramWrite32(rdram, recvBuf + 8, 1);
                    rdramWrite32(rdram, recvBuf + 12, 1);
                    rdramWrite32(rdram, recvBuf + 0x20c, 0);
                }
            }
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
                        snprintf(hex + i * 3, 4, "%02X ",
                                 reo_source_instrumentation::bankRead(
                                     rdram, rdram + ((sendBuf + i) & ps2RamBackingMask())));
                }
                fprintf(stderr, "[HW-BRIDGE:%s] fno=0x%X send=0x%08X/%u recv=0x%08X/%u data=[%s]\n",
                        isHeap ? "HEAP" : "LOADFILE", rpcNum, sendBuf, sendSize, recvBuf, recvSize,
                        hex);
                hlLog++;
            }
            if (!recvBuf || recvSize < 4)
                return false;

            if (isHeap) {
                if (!self)
                    return false;
                // HLE IOP heap. The runtime's sceSifSetDma aliases IOP destinations onto
                // EE RAM, so allocations come from IOP 0x88000-0xFFFFF, an EE range that
                // PCSX2 shows unused by this game (D4). Exhaustion fails loudly (0).
                uint32_t& heapNext = self->m_iopHeapNext;
                constexpr uint32_t kHeapEnd = 0x00100000u;
                if (rpcNum == 0x1 && sendBuf && sendSize >= 4) { // alloc(size)
                    const uint32_t size = rdramRead32(rdram, sendBuf);
                    const uint32_t aligned = (size + 0xFFu) & ~0xFFu;
                    uint32_t addr = 0u;
                    if (size && heapNext + aligned <= kHeapEnd) {
                        addr = heapNext;
                        heapNext += aligned;
                    }
                    rdramWrite32(rdram, recvBuf, addr);
                    fprintf(stderr, "[HW-BRIDGE:HEAP] alloc %u -> 0x%08X%s\n", size, addr,
                            addr ? ""
                                 : "  ** HLE IOP heap exhausted; needs a real IOP RAM model **");
                    return true;
                }
                if (rpcNum == 0x2) { // free(addr)
                    rdramWrite32(rdram, recvBuf, 0u);
                    return true;
                }
                return false;
            }

            // LOADFILE
            if (rpcNum == 9 && sendBuf && sendSize > 8) {
                const char* host = std::getenv("REO_COOP_HOST");
                if (!self || !host || !*host)
                    return false;
                std::string name;
                for (uint32_t i = 8; i < std::min<uint32_t>(sendSize, 8 + 252); ++i) {
                    const char ch = reo_source_instrumentation::bankRead(
                        rdram, rdram + ((sendBuf + i) & ps2RamBackingMask()));
                    if (!ch)
                        break;
                    name.push_back(ch);
                }
                int32_t id = -1;
                if (name == "dev9") {
                    if (!self->m_network)
                        self->m_network = std::make_unique<SnapIopTransport>();
                    const auto reply = self->m_network->call(5, std::vector<uint8_t>(0x1C), 0x1C);
                    int32_t result = -1;
                    if (reply.size() == 0x1C)
                        memcpy(&result, reply.data() + 0x18, sizeof(result));
                    if (result == 0)
                        id = 0x5245; // Native virtual adapter, not an executed IRX.
                }
                rdramWrite32(rdram, recvBuf, static_cast<uint32_t>(id));
                fprintf(stderr, "[SNIOP] module lookup %s -> %d\n", name.c_str(), id);
                return true;
            }
            if (rpcNum == 0xFF) {                          // init / version
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
                for (uint32_t i = 0;
                     i < std::min<uint32_t>(argLen, 0xFC) && sendSize >= 0x104 + argLen; ++i) {
                    const char ch = (char)reo_source_instrumentation::bankRead(
                        rdram, rdram + ((sendBuf + 0x104 + i) & ps2RamBackingMask()));
                    args.push_back(ch ? ch : ' ');
                }
                std::string what;
                if (rpcNum == 0x6) {
                    // Best effort: IRX module name from the .iopmod-style header if present.
                    const uint32_t iopAddr = rdramRead32(rdram, sendBuf);
                    char hdr[5] = {0};
                    for (int i = 0; i < 4; ++i)
                        hdr[i] = (char)reo_source_instrumentation::bankRead(
                            rdram, rdram + ((iopAddr + i) & ps2RamBackingMask()));
                    char buf[64];
                    snprintf(buf, sizeof buf, "buffer@IOP 0x%08X (magic %02X%02X%02X%02X)", iopAddr,
                             (uint8_t)hdr[0], (uint8_t)hdr[1], (uint8_t)hdr[2], (uint8_t)hdr[3]);
                    what = buf;
                } else {
                    for (uint32_t i = 8; i < std::min<uint32_t>(sendSize, 8 + 0x100); ++i) {
                        const char ch = (char)reo_source_instrumentation::bankRead(
                            rdram, rdram + ((sendBuf + i) & ps2RamBackingMask()));
                        if (!ch)
                            break;
                        what.push_back(ch);
                    }
                }
                const int32_t id = nextModId++;
                rdramWrite32(rdram, recvBuf, (uint32_t)id);
                if (recvSize >= 8)
                    rdramWrite32(rdram, recvBuf + 4, 0u);
                fprintf(stderr,
                        "[HW-BRIDGE:LOADFILE] load %s args=\"%s\" -> id %d (HLE, not executed)\n",
                        what.c_str(), args.c_str(), id);
                return true;
            }
            return false;
        }

        default: {
            const char* netTrace = std::getenv("REO_NET_TRACE");
            if (netTrace && !strcmp(netTrace, "1")) {
                static std::mutex traceMutex;
                static std::map<std::pair<uint32_t, uint32_t>, uint32_t> calls;
                std::lock_guard<std::mutex> lock(traceMutex);
                const auto key = std::make_pair(sid, rpcNum);
                if (calls.size() < 128 || calls.contains(key)) {
                    const auto count = ++calls[key];
                    if (count <= 4) {
                        char hex[3 * 48 + 1] = {};
                        for (uint32_t i = 0; sendBuf && i < std::min<uint32_t>(sendSize, 48); ++i)
                            snprintf(hex + i * 3, 4, "%02X ",
                                     reo_source_instrumentation::bankRead(
                                         rdram, rdram + ((sendBuf + i) & ps2RamBackingMask())));
                        fprintf(
                            stderr,
                            "[NET-RPC-MISSING] sid=%08X op=%X send=%08X/%u recv=%08X/%u data=%s\n",
                            sid, rpcNum, sendBuf, sendSize, recvBuf, recvSize, hex);
                    }
                }
            }
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
bool ReoHwBridge::nativeNetworkLinkReady() {
    if (!m_network)
        return false;
    const auto reply = m_network->call(0x50, std::vector<uint8_t>(0x1C), 0x1C);
    int32_t status = 0;
    if (reply.size() == 0x1C)
        memcpy(&status, reply.data() + 0x18, sizeof(status));
    return status > 0;
}

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
                reo_source_instrumentation::copyBytes(fb + y * fbW, pixels + y * width, copyW * 4);
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
