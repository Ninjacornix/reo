#pragma once

#include <cstdint>
#include <atomic>

namespace reo {

/*
 * SPU2 — Sound Processing Unit 2
 *
 * The PS2 SPU2 has 2 cores, each with 24 voices (48 total).
 * Each voice plays ADPCM compressed audio from 2MB of dedicated sound RAM.
 * Hardware effects include reverb, pitch modulation, and noise generation.
 *
 * Our replacement:
 *   - Software ADPCM decoder
 *   - Software voice mixer
 *   - Software reverb (based on SPU2 algorithm)
 *   - Output via WASAPI (Windows)
 */

// SPU2 constants
constexpr int SPU2_NUM_CORES = 2;
constexpr int SPU2_VOICES_PER_CORE = 24;
constexpr int SPU2_TOTAL_VOICES = SPU2_NUM_CORES * SPU2_VOICES_PER_CORE;
constexpr int SPU2_RAM_SIZE = 2 * 1024 * 1024; // 2 MB
constexpr int SPU2_SAMPLE_RATE = 48000;
constexpr int SPU2_SAMPLES_PER_BLOCK = 28;
constexpr int SPU2_BLOCK_SIZE = 16; // bytes

// SPU2 register base addresses
constexpr uint32_t SPU2_REG_BASE = 0x1F900000;
constexpr uint32_t SPU2_CORE0_BASE = 0x1F900000;
constexpr uint32_t SPU2_CORE1_BASE = 0x1F900400;

// Per-voice register offsets (relative to core base + voice*16)
constexpr uint32_t SPU2_VP_VOLL = 0x00;
constexpr uint32_t SPU2_VP_VOLR = 0x02;
constexpr uint32_t SPU2_VP_PITCH = 0x04;
constexpr uint32_t SPU2_VP_ADSR1 = 0x06;
constexpr uint32_t SPU2_VP_ADSR2 = 0x08;
constexpr uint32_t SPU2_VP_ENVX = 0x0A;
constexpr uint32_t SPU2_VP_VOLXL = 0x0C;
constexpr uint32_t SPU2_VP_VOLXR = 0x0E;

// Core register offsets (relative to core base)
constexpr uint32_t SPU2_C_ATTR = 0x019A;    // Core attributes
constexpr uint32_t SPU2_C_KON_HI = 0x01A0;  // Key on (voices 16-23)
constexpr uint32_t SPU2_C_KON_LO = 0x01A2;  // Key on (voices 0-15)
constexpr uint32_t SPU2_C_KOFF_HI = 0x01A4; // Key off (voices 16-23)
constexpr uint32_t SPU2_C_KOFF_LO = 0x01A6; // Key off (voices 0-15)
constexpr uint32_t SPU2_C_TSAH = 0x01A8;    // Transfer start address high
constexpr uint32_t SPU2_C_TSAL = 0x01AA;    // Transfer start address low
constexpr uint32_t SPU2_C_DATA = 0x01AC;    // Transfer data
constexpr uint32_t SPU2_C_MVOLL = 0x0190;   // Master volume left
constexpr uint32_t SPU2_C_MVOLR = 0x0192;   // Master volume right

struct SPU2Voice {
    uint32_t start_addr;   // Start address in SPU2 RAM
    uint32_t loop_addr;    // Loop address
    uint32_t current_addr; // Current playback position

    uint16_t volume_left;
    uint16_t volume_right;
    uint16_t pitch; // Pitch (4096 = 44100 Hz base)

    // ADPCM decoding state
    int32_t prev_sample[2]; // Previous 2 samples for ADPCM prediction

    // Decoded sample buffer
    int16_t decoded[SPU2_SAMPLES_PER_BLOCK];
    int decoded_pos; // Current position in decoded buffer

    // Pitch interpolation counter (12.12 fixed point)
    uint32_t pitch_counter;

    // Envelope
    uint16_t adsr1;
    uint16_t adsr2;
    int32_t envelope_level;
    enum class EnvPhase { Off, Attack, Decay, Sustain, Release } env_phase;

    // ADSR rates
    uint16_t attack_rate;
    uint16_t decay_rate;
    uint16_t sustain_level;
    uint16_t sustain_rate;
    uint16_t release_rate;
    bool attack_exp;  // Exponential attack mode
    bool sustain_dec; // Sustain decrease direction
    bool sustain_exp; // Sustain exponential mode
    bool release_exp; // Exponential release mode

    bool key_on;
    bool key_off;
    bool looping;
    bool playing;
};

class SPU2 {
  public:
    SPU2() = default;
    ~SPU2() {
        shutdown();
    }

    bool init();
    void shutdown();

    // Register access (from IOP)
    uint16_t read_register(uint32_t addr);
    void write_register(uint32_t addr, uint16_t value);

    // DMA transfer (IOP → SPU2 RAM)
    void dma_write(int core, const void* data, uint32_t addr, uint32_t size);
    void dma_read(int core, void* data, uint32_t addr, uint32_t size);

    // Generate audio samples (called from audio thread or main loop)
    void mix_samples(int16_t* output, int num_samples);

    // SPU2 RAM access
    uint8_t* ram() {
        return m_ram;
    }

    // Called each frame to process key on/off events
    void process_keys();

  private:
    void decode_adpcm_block(SPU2Voice& voice, int16_t* output);
    void process_envelope(SPU2Voice& voice);
    int32_t get_interpolated_sample(SPU2Voice& voice);
    void parse_adsr(SPU2Voice& voice);
    void key_on_voice(int voice_idx);
    void key_off_voice(int voice_idx);

    SPU2Voice m_voices[SPU2_TOTAL_VOICES] = {};
    uint8_t m_ram[SPU2_RAM_SIZE] = {};

    // Core registers
    uint16_t m_core_attr[2] = {};
    int16_t m_master_vol_l[2] = {};
    int16_t m_master_vol_r[2] = {};

    // Transfer state per core
    uint32_t m_transfer_addr[2] = {};

    // WASAPI state
    bool m_initialized = false;
    bool m_audio_running = false;
    void* m_audio_client = nullptr;  // IAudioClient*
    void* m_render_client = nullptr; // IAudioRenderClient*
    uint32_t m_buffer_frames = 0;

    // Audio thread
    std::atomic<bool> m_thread_running{false};
    void* m_audio_thread = nullptr;
};

} // namespace reo
