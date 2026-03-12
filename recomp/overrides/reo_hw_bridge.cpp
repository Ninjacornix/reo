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
#include <cstdio>
#include <cstring>

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
            // Chain mode: follow DMA tags from tadr
            uint32_t physTag = tadr & PS2_RAM_MASK;
            if (physTag + 16 <= PS2_RAM_SIZE) {
                uint64_t tag;
                memcpy(&tag, rdram + physTag, sizeof(tag));
                uint16_t tagQwc = (uint16_t)(tag & 0xFFFF);
                uint32_t addr = (uint32_t)((tag >> 32) & 0x7FFFFFF0);
                uint32_t phys = addr & PS2_RAM_MASK;
                uint32_t bytes = tagQwc * 16;
                if (phys + bytes <= PS2_RAM_SIZE && bytes > 0) {
                    REO_TRACE_DMA_GIF(addr, tagQwc, rdram + phys, bytes);
                    self->m_gs->submit_path3(rdram + phys, bytes);
                }
            }
        }

        static int logCount = 0;
        if (logCount < 8) {
            printf("[HW-BRIDGE] GIF DMA: madr=0x%08X qwc=%u (total packets: %llu)\n",
                   madr, qwc, (unsigned long long)self->m_gifPackets);
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

    *width = self->m_gs->fb_width();
    *height = self->m_gs->fb_height();
    return self->m_gs->framebuffer();
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
