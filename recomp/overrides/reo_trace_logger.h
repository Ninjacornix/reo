/*
 * REO Execution Trace Logger
 *
 * Lightweight binary trace logger for recording hardware events during
 * reo_recomp execution. Output can be compared against PCSX2 GS dumps
 * or trace logs to validate correctness.
 *
 * Enable via environment variable: REO_TRACE=1
 * Output file: reo_trace.bin (or REO_TRACE_FILE=path)
 *
 * The trace captures:
 *   - All DMA transfers (GIF, VIF1)
 *   - All GS register writes
 *   - All VU microprogram executions
 *   - VSync/frame boundaries
 *   - Stub function calls
 *   - Override function calls
 */

#pragma once
#include <cstdint>
#include <cstdio>
#include <chrono>
#include <atomic>

class ReoTraceLogger {
public:
    static ReoTraceLogger& instance() {
        static ReoTraceLogger s_logger;
        return s_logger;
    }

    bool init();
    void shutdown();
    bool enabled() const { return m_file != nullptr; }

    // Hardware events
    void log_dma_gif(uint32_t madr, uint32_t qwc, const uint8_t* data, uint32_t data_size);
    void log_dma_vif1(uint32_t madr, uint32_t qwc, uint32_t tadr, const uint8_t* data, uint32_t data_size);
    void log_gs_reg_write(uint32_t offset, uint64_t value);
    void log_vu_start(int unit, uint32_t addr);
    void log_vu_end(int unit, uint32_t cycles);
    void log_xgkick(const void* data, uint32_t size);
    void log_vsync(uint32_t frame);

    // Code events
    void log_stub_call(uint32_t addr, uint32_t a0, uint32_t a1);
    void log_override_call(uint32_t addr, uint32_t a0, uint32_t a1);

    // Stats
    uint64_t event_count() const { return m_sequence; }

private:
    ReoTraceLogger() = default;
    ~ReoTraceLogger() { shutdown(); }

    void write_event(uint8_t type, const void* payload, uint32_t payload_size);
    uint32_t elapsed_us();

    FILE* m_file = nullptr;
    std::atomic<uint64_t> m_sequence{0};
    std::chrono::steady_clock::time_point m_start;
};

// Convenience macros for conditional tracing
#define REO_TRACE_DMA_GIF(madr, qwc, data, sz) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_dma_gif(madr, qwc, data, sz); } while(0)

#define REO_TRACE_DMA_VIF1(madr, qwc, tadr, data, sz) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_dma_vif1(madr, qwc, tadr, data, sz); } while(0)

#define REO_TRACE_GS_REG(off, val) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_gs_reg_write(off, val); } while(0)

#define REO_TRACE_VU_START(unit, addr) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_vu_start(unit, addr); } while(0)

#define REO_TRACE_VU_END(unit, cyc) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_vu_end(unit, cyc); } while(0)

#define REO_TRACE_XGKICK(data, sz) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_xgkick(data, sz); } while(0)

#define REO_TRACE_VSYNC(frame) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_vsync(frame); } while(0)

#define REO_TRACE_STUB(addr, a0, a1) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_stub_call(addr, a0, a1); } while(0)

#define REO_TRACE_OVERRIDE(addr, a0, a1) \
    do { if (ReoTraceLogger::instance().enabled()) \
        ReoTraceLogger::instance().log_override_call(addr, a0, a1); } while(0)
