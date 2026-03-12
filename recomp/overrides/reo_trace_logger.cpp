/*
 * REO Execution Trace Logger — Implementation
 *
 * Binary trace format for comparing reo_recomp execution against PCSX2.
 * Enable: set REO_TRACE=1 environment variable before running reo_recomp.
 *
 * The output file (reo_trace.bin) can be analyzed with reo-trace-compare
 * alongside a PCSX2 GS dump to find divergences.
 */

#include "reo_trace_logger.h"
#include <cstdlib>
#include <cstring>
#include <algorithm>

// Reuse trace format definitions
namespace reo_trace {
    constexpr uint32_t TRACE_MAGIC   = 0x544F4552; // "REOT"
    constexpr uint32_t TRACE_VERSION = 1;

    enum EventType : uint8_t {
        EVT_DMA_GIF       = 0x10,
        EVT_DMA_VIF1      = 0x11,
        EVT_GS_REG_WRITE  = 0x20,
        EVT_VU_START      = 0x30,
        EVT_VU_END        = 0x31,
        EVT_XGKICK        = 0x32,
        EVT_VSYNC          = 0x40,
        EVT_STUB_CALL      = 0x60,
        EVT_OVERRIDE_CALL  = 0x61,
    };
}

bool ReoTraceLogger::init() {
    const char* env = getenv("REO_TRACE");
    if (!env || strcmp(env, "1") != 0) {
        return false; // Tracing not requested
    }

    const char* path = getenv("REO_TRACE_FILE");
    if (!path) path = "reo_trace.bin";

    m_file = fopen(path, "wb");
    if (!m_file) {
        printf("[TRACE] ERROR: Cannot open trace file '%s'\n", path);
        return false;
    }

    m_start = std::chrono::steady_clock::now();
    m_sequence = 0;

    // Write header
    uint32_t magic = reo_trace::TRACE_MAGIC;
    uint32_t version = reo_trace::TRACE_VERSION;
    uint32_t crc = 0; // TODO: game CRC
    uint32_t flags = 0;
    uint64_t timestamp = (uint64_t)time(nullptr);

    fwrite(&magic, 4, 1, m_file);
    fwrite(&version, 4, 1, m_file);
    fwrite(&crc, 4, 1, m_file);
    fwrite(&flags, 4, 1, m_file);
    fwrite(&timestamp, 8, 1, m_file);

    printf("[TRACE] Tracing enabled → %s\n", path);
    return true;
}

void ReoTraceLogger::shutdown() {
    if (m_file) {
        printf("[TRACE] Trace complete: %llu events recorded\n",
               (unsigned long long)m_sequence.load());
        fclose(m_file);
        m_file = nullptr;
    }
}

uint32_t ReoTraceLogger::elapsed_us() {
    auto now = std::chrono::steady_clock::now();
    return (uint32_t)std::chrono::duration_cast<std::chrono::microseconds>(now - m_start).count();
}

void ReoTraceLogger::write_event(uint8_t type, const void* payload, uint32_t payload_size) {
    if (!m_file) return;

    // Event header: sequence(8) + timestamp_us(4) + type(1) + reserved(3) = 16 bytes
    uint64_t seq = m_sequence.fetch_add(1);
    uint32_t ts = elapsed_us();
    uint8_t reserved[3] = {0, 0, 0};

    fwrite(&seq, 8, 1, m_file);
    fwrite(&ts, 4, 1, m_file);
    fwrite(&type, 1, 1, m_file);
    fwrite(reserved, 3, 1, m_file);

    // Payload
    if (payload && payload_size > 0) {
        fwrite(payload, 1, payload_size, m_file);
    }
}

// ── Event loggers ───────────────────────────────────────────────────

void ReoTraceLogger::log_dma_gif(uint32_t madr, uint32_t qwc,
                                  const uint8_t* data, uint32_t data_size) {
    struct {
        uint32_t madr, qwc;
        uint8_t first[64];
    } payload;
    payload.madr = madr;
    payload.qwc = qwc;
    memset(payload.first, 0, 64);
    if (data && data_size > 0) {
        memcpy(payload.first, data, std::min(data_size, (uint32_t)64));
    }
    write_event(reo_trace::EVT_DMA_GIF, &payload, sizeof(payload));
}

void ReoTraceLogger::log_dma_vif1(uint32_t madr, uint32_t qwc, uint32_t tadr,
                                   const uint8_t* data, uint32_t data_size) {
    struct {
        uint32_t madr, qwc, tadr;
        uint8_t first[64];
    } payload;
    payload.madr = madr;
    payload.qwc = qwc;
    payload.tadr = tadr;
    memset(payload.first, 0, 64);
    if (data && data_size > 0) {
        memcpy(payload.first, data, std::min(data_size, (uint32_t)64));
    }
    write_event(reo_trace::EVT_DMA_VIF1, &payload, sizeof(payload));
}

void ReoTraceLogger::log_gs_reg_write(uint32_t offset, uint64_t value) {
    struct {
        uint32_t offset;
        uint32_t pad;
        uint64_t value;
    } payload = {offset, 0, value};
    write_event(reo_trace::EVT_GS_REG_WRITE, &payload, sizeof(payload));
}

void ReoTraceLogger::log_vu_start(int unit, uint32_t addr) {
    struct {
        uint32_t unit, addr;
    } payload = {(uint32_t)unit, addr};
    write_event(reo_trace::EVT_VU_START, &payload, sizeof(payload));
}

void ReoTraceLogger::log_vu_end(int unit, uint32_t cycles) {
    struct {
        uint32_t unit, cycles;
    } payload = {(uint32_t)unit, cycles};
    write_event(reo_trace::EVT_VU_END, &payload, sizeof(payload));
}

void ReoTraceLogger::log_xgkick(const void* data, uint32_t size) {
    struct {
        uint32_t size;
        uint8_t first[64];
    } payload;
    payload.size = size;
    memset(payload.first, 0, 64);
    if (data && size > 0) {
        memcpy(payload.first, data, std::min(size, (uint32_t)64));
    }
    write_event(reo_trace::EVT_XGKICK, &payload, sizeof(payload));
}

void ReoTraceLogger::log_vsync(uint32_t frame) {
    write_event(reo_trace::EVT_VSYNC, &frame, sizeof(frame));
}

void ReoTraceLogger::log_stub_call(uint32_t addr, uint32_t a0, uint32_t a1) {
    struct {
        uint32_t addr, a0, a1;
    } payload = {addr, a0, a1};
    write_event(reo_trace::EVT_STUB_CALL, &payload, sizeof(payload));
}

void ReoTraceLogger::log_override_call(uint32_t addr, uint32_t a0, uint32_t a1) {
    struct {
        uint32_t addr, a0, a1;
    } payload = {addr, a0, a1};
    write_event(reo_trace::EVT_OVERRIDE_CALL, &payload, sizeof(payload));
}
