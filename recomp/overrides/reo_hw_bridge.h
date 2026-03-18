/*
 * REO Hardware Bridge
 *
 * Connects PS2Recomp's runtime (which executes recompiled game code)
 * to REO's hardware emulation subsystems (GS renderer, VU interpreter).
 *
 * Without this bridge, PS2Recomp runs game code but all hardware writes
 * (GIF packets, GS registers, VU programs) go nowhere. The bridge
 * intercepts these events and forwards them to real implementations.
 *
 * Architecture:
 *   PS2Recomp (code execution)
 *       │
 *       ├── DMA GIF channel → bridge → GSRenderer::submit_path3()
 *       ├── DMA VIF1 channel → bridge → VIF parser → VU1 start / PATH2
 *       ├── GS register writes → bridge → GSRenderer::write_register()
 *       ├── VU0 micro start → bridge → VUInterpreter::start() + run()
 *       └── UploadFrame → bridge → GSRenderer::framebuffer()
 *
 *   The bridge runs the reo::GSRenderer in headless mode (no window).
 *   PS2Recomp's raylib window reads the rendered framebuffer via callback.
 */

#pragma once

#include "ps2_runtime.h"

namespace reo {
    class GSRenderer;
    class VUInterpreter;
    class Input;
    class CDVD;
}

class ReoHwBridge {
public:
    ReoHwBridge();
    ~ReoHwBridge();

    // Initialize the bridge and all subsystems.
    // Must be called after PS2Runtime::initialize() and before run().
    bool init(PS2Runtime& runtime);

    // Shutdown and cleanup
    void shutdown();

    // Get the singleton (created by init, destroyed by shutdown)
    static ReoHwBridge* instance() { return s_instance; }

private:
    // PS2Memory callback: DMA channel start
    static void onDmaStart(uint32_t channelBase, uint32_t madr, uint32_t qwc,
                           uint32_t tadr, const uint8_t* rdram, void* user);

    // PS2Memory callback: GS privileged register write
    static void onGsRegWrite(uint32_t offset, uint64_t value, void* user);

    // PS2Runtime callback: VU microprogram execution
    static void onVuStart(int unit, uint32_t addr, uint8_t* rdram,
                          R5900Context* ctx, void* user);

    // PS2Runtime callback: get rendered framebuffer
    static const uint32_t* getFramebuffer(int* width, int* height, void* user);

    // PS2Runtime callback: unhandled SIF RPC
    static bool onSifRpc(uint32_t sid, uint32_t rpcNum,
                         uint32_t sendBuf, uint32_t sendSize,
                         uint32_t recvBuf, uint32_t recvSize,
                         uint8_t* rdram, void* user);

    // Process VIF1 DMA data stream (extract UNPACK, MSCAL, DIRECT commands)
    void processVif1Dma(uint32_t madr, uint32_t qwc, const uint8_t* rdram);

    // Process VIF1 DMA chain mode
    void processVif1DmaChain(uint32_t tadr, const uint8_t* rdram);

    // Parse a block of VIF commands
    void processVifCommands(const uint8_t* data, uint32_t size, const uint8_t* rdram);

    // Execute VU0/VU1 microprogram
    void executeVu(int unit, uint32_t addr, uint8_t* rdram, R5900Context* ctx);

    PS2Runtime* m_runtime = nullptr;
    reo::GSRenderer* m_gs = nullptr;
    reo::VUInterpreter* m_vu0 = nullptr;
    reo::VUInterpreter* m_vu1 = nullptr;
    reo::Input* m_input = nullptr;
    reo::CDVD* m_cdvd = nullptr;

public:
    // Input access for pad overrides
    reo::Input* input() { return m_input; }
private:

    // Statistics
    uint64_t m_gifPackets = 0;
    uint64_t m_vif1Dmas = 0;
    uint64_t m_vu0Runs = 0;
    uint64_t m_vu1Runs = 0;
    uint64_t m_gsRegWrites = 0;

    static ReoHwBridge* s_instance;
};
