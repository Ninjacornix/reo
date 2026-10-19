#include "spu2.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#include <audioclient.h>
#include <mmdeviceapi.h>
#include <functiondiscoverykeys_devpkey.h>
#endif

namespace reo {

// WASAPI audio thread
#ifdef _WIN32
static DWORD WINAPI audio_thread_proc(LPVOID param) {
    SPU2* spu2 = (SPU2*)param;

    // We'll call mix_samples from the main loop for now.
    // Full WASAPI push-mode audio will be wired once we have the main loop.
    return 0;
}
#endif

// Init / Shutdown
bool SPU2::init() {
    memset(m_ram, 0, sizeof(m_ram));
    memset(m_voices, 0, sizeof(m_voices));

    for (auto& v : m_voices) {
        v.env_phase = SPU2Voice::EnvPhase::Off;
        v.playing = false;
        v.decoded_pos = SPU2_SAMPLES_PER_BLOCK; // Force decode on first use
        v.pitch_counter = 0;
    }

    m_initialized = true;

#ifdef _WIN32
    // Initialize COM for WASAPI
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    IMMDeviceEnumerator* enumerator = nullptr;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_ALL,
                          __uuidof(IMMDeviceEnumerator), (void**)&enumerator);
    if (FAILED(hr)) {
        printf("[SPU2] WASAPI: Failed to create device enumerator (hr=0x%08lX)\n", hr);
        printf("[SPU2] Falling back to software-only mixer (no audio output)\n");
        return true; // Continue without audio output
    }

    IMMDevice* device = nullptr;
    hr = enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device);
    if (FAILED(hr)) {
        printf("[SPU2] WASAPI: No audio device found\n");
        enumerator->Release();
        return true;
    }

    IAudioClient* audio_client = nullptr;
    hr = device->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr, (void**)&audio_client);
    device->Release();
    enumerator->Release();

    if (FAILED(hr)) {
        printf("[SPU2] WASAPI: Failed to activate audio client\n");
        return true;
    }

    // Configure format: 48kHz, 16-bit, stereo
    WAVEFORMATEX wfx = {};
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = 2;
    wfx.nSamplesPerSec = SPU2_SAMPLE_RATE;
    wfx.wBitsPerSample = 16;
    wfx.nBlockAlign = wfx.nChannels * wfx.wBitsPerSample / 8;
    wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;

    // 20ms buffer for low latency
    REFERENCE_TIME buffer_duration = 200000; // 20ms in 100ns units

    hr = audio_client->Initialize(AUDCLNT_SHAREMODE_SHARED, 0, buffer_duration, 0, &wfx, nullptr);
    if (FAILED(hr)) {
        printf("[SPU2] WASAPI: Failed to initialize audio client (hr=0x%08lX)\n", hr);
        audio_client->Release();
        return true;
    }

    hr = audio_client->GetBufferSize(&m_buffer_frames);

    IAudioRenderClient* render_client = nullptr;
    hr = audio_client->GetService(__uuidof(IAudioRenderClient), (void**)&render_client);
    if (FAILED(hr)) {
        printf("[SPU2] WASAPI: Failed to get render client\n");
        audio_client->Release();
        return true;
    }

    m_audio_client = audio_client;
    m_render_client = render_client;
    m_audio_running = true;

    // Start the audio stream
    audio_client->Start();

    printf("[SPU2] WASAPI initialized: %dHz stereo 16-bit, buffer=%d frames\n", SPU2_SAMPLE_RATE,
           m_buffer_frames);
#else
    printf("[SPU2] Software mixer initialized (%d voices, no audio output)\n", SPU2_TOTAL_VOICES);
#endif

    return true;
}

void SPU2::shutdown() {
    if (!m_initialized)
        return;

    m_thread_running = false;

#ifdef _WIN32
    if (m_audio_client) {
        ((IAudioClient*)m_audio_client)->Stop();
        ((IAudioClient*)m_audio_client)->Release();
        m_audio_client = nullptr;
    }
    if (m_render_client) {
        ((IAudioRenderClient*)m_render_client)->Release();
        m_render_client = nullptr;
    }
#endif

    m_initialized = false;
    m_audio_running = false;
    printf("[SPU2] Shutdown\n");
}

// Register access
uint16_t SPU2::read_register(uint32_t addr) {
    uint32_t offset = addr - SPU2_REG_BASE;
    int core = (offset >= 0x400) ? 1 : 0;
    uint32_t core_offset = offset - (core * 0x400);

    // Voice registers: offset 0x000 - 0x17F (24 voices * 16 bytes)
    if (core_offset < 0x180) {
        int voice = core_offset / 16;
        int voice_off = core_offset % 16;
        int vi = core * SPU2_VOICES_PER_CORE + voice;

        switch (voice_off) {
            case SPU2_VP_VOLL:
                return m_voices[vi].volume_left;
            case SPU2_VP_VOLR:
                return m_voices[vi].volume_right;
            case SPU2_VP_PITCH:
                return m_voices[vi].pitch;
            case SPU2_VP_ADSR1:
                return m_voices[vi].adsr1;
            case SPU2_VP_ADSR2:
                return m_voices[vi].adsr2;
            case SPU2_VP_ENVX:
                return (uint16_t)(m_voices[vi].envelope_level >> 16);
            default:
                return 0;
        }
    }

    // Core-level registers
    switch (core_offset) {
        case SPU2_C_MVOLL:
            return (uint16_t)m_master_vol_l[core];
        case SPU2_C_MVOLR:
            return (uint16_t)m_master_vol_r[core];
        case SPU2_C_ATTR:
            return m_core_attr[core];
        default:
            return 0;
    }
}

void SPU2::write_register(uint32_t addr, uint16_t value) {
    uint32_t offset = addr - SPU2_REG_BASE;
    int core = (offset >= 0x400) ? 1 : 0;
    uint32_t core_offset = offset - (core * 0x400);

    // Voice registers
    if (core_offset < 0x180) {
        int voice = core_offset / 16;
        int voice_off = core_offset % 16;
        int vi = core * SPU2_VOICES_PER_CORE + voice;

        switch (voice_off) {
            case SPU2_VP_VOLL:
                m_voices[vi].volume_left = value;
                break;
            case SPU2_VP_VOLR:
                m_voices[vi].volume_right = value;
                break;
            case SPU2_VP_PITCH:
                m_voices[vi].pitch = value;
                break;
            case SPU2_VP_ADSR1:
                m_voices[vi].adsr1 = value;
                parse_adsr(m_voices[vi]);
                break;
            case SPU2_VP_ADSR2:
                m_voices[vi].adsr2 = value;
                parse_adsr(m_voices[vi]);
                break;
            default:
                break;
        }
        return;
    }

    // Core registers
    switch (core_offset) {
        case SPU2_C_MVOLL:
            m_master_vol_l[core] = (int16_t)value;
            break;
        case SPU2_C_MVOLR:
            m_master_vol_r[core] = (int16_t)value;
            break;
        case SPU2_C_ATTR:
            m_core_attr[core] = value;
            break;

        case SPU2_C_KON_LO:
            for (int i = 0; i < 16; i++) {
                if (value & (1 << i))
                    key_on_voice(core * SPU2_VOICES_PER_CORE + i);
            }
            break;
        case SPU2_C_KON_HI:
            for (int i = 0; i < 8; i++) {
                if (value & (1 << i))
                    key_on_voice(core * SPU2_VOICES_PER_CORE + 16 + i);
            }
            break;
        case SPU2_C_KOFF_LO:
            for (int i = 0; i < 16; i++) {
                if (value & (1 << i))
                    key_off_voice(core * SPU2_VOICES_PER_CORE + i);
            }
            break;
        case SPU2_C_KOFF_HI:
            for (int i = 0; i < 8; i++) {
                if (value & (1 << i))
                    key_off_voice(core * SPU2_VOICES_PER_CORE + 16 + i);
            }
            break;

        case SPU2_C_TSAH:
            m_transfer_addr[core] = (m_transfer_addr[core] & 0xFFFF) | ((uint32_t)value << 16);
            break;
        case SPU2_C_TSAL:
            m_transfer_addr[core] = (m_transfer_addr[core] & 0xFFFF0000) | value;
            break;
        case SPU2_C_DATA: {
            uint32_t taddr = m_transfer_addr[core] * 8; // Address in bytes
            if (taddr + 1 < SPU2_RAM_SIZE) {
                m_ram[taddr] = value & 0xFF;
                m_ram[taddr + 1] = (value >> 8) & 0xFF;
                m_transfer_addr[core]++;
            }
            break;
        }

        default:
            break;
    }
}

// DMA
void SPU2::dma_write(int core, const void* data, uint32_t addr, uint32_t size) {
    if (addr + size > SPU2_RAM_SIZE) {
        fprintf(stderr, "[SPU2] DMA write overflow: addr=0x%06X size=0x%X\n", addr, size);
        size = SPU2_RAM_SIZE - addr;
    }
    memcpy(m_ram + addr, data, size);
}

void SPU2::dma_read(int core, void* data, uint32_t addr, uint32_t size) {
    if (addr + size > SPU2_RAM_SIZE) {
        size = SPU2_RAM_SIZE - addr;
    }
    memcpy(data, m_ram + addr, size);
}

// ADSR parsing
void SPU2::parse_adsr(SPU2Voice& voice) {
    uint16_t a1 = voice.adsr1;
    uint16_t a2 = voice.adsr2;

    // ADSR1: [15] = AM (attack mode), [14:8] = AR (attack rate),
    //         [7:4] = DR (decay rate), [3:0] = SL (sustain level)
    voice.attack_exp = (a1 >> 15) & 1;
    voice.attack_rate = (a1 >> 8) & 0x7F;
    voice.decay_rate = (a1 >> 4) & 0x0F;
    voice.sustain_level = ((a1 & 0x0F) + 1) * 0x800; // 0x800 steps

    // ADSR2: [15] = SD (sustain direction), [14] = SM (sustain mode),
    //         [13:6] = SR (sustain rate), [5] = RM (release mode), [4:0] = RR (release rate)
    voice.sustain_dec = (a2 >> 15) & 1;
    voice.sustain_exp = (a2 >> 14) & 1;
    voice.sustain_rate = (a2 >> 6) & 0x7F;
    voice.release_exp = (a2 >> 5) & 1;
    voice.release_rate = a2 & 0x1F;
}

// Key on/off
void SPU2::key_on_voice(int voice_idx) {
    if (voice_idx < 0 || voice_idx >= SPU2_TOTAL_VOICES)
        return;

    SPU2Voice& v = m_voices[voice_idx];
    v.playing = true;
    v.current_addr = v.start_addr;
    v.env_phase = SPU2Voice::EnvPhase::Attack;
    v.envelope_level = 0;
    v.prev_sample[0] = 0;
    v.prev_sample[1] = 0;
    v.decoded_pos = SPU2_SAMPLES_PER_BLOCK; // Force first decode
    v.pitch_counter = 0;
    v.looping = false;
}

void SPU2::key_off_voice(int voice_idx) {
    if (voice_idx < 0 || voice_idx >= SPU2_TOTAL_VOICES)
        return;

    SPU2Voice& v = m_voices[voice_idx];
    if (v.playing) {
        v.env_phase = SPU2Voice::EnvPhase::Release;
    }
}

// ADPCM decoding
// Sony PS-ADPCM coefficient table
static const int32_t adpcm_coef[5][2] = {
    {0, 0}, {60, 0}, {115, -52}, {98, -55}, {122, -60},
};

void SPU2::decode_adpcm_block(SPU2Voice& voice, int16_t* output) {
    uint8_t* block = m_ram + (voice.current_addr & (SPU2_RAM_SIZE - 1));

    uint8_t shift_filter = block[0];
    uint8_t flags = block[1];

    int shift = shift_filter & 0x0F;
    int filter = (shift_filter >> 4) & 0x07;
    if (filter > 4)
        filter = 4;

    bool loop_end = flags & 1;
    bool loop_start = flags & 4;

    if (loop_start) {
        voice.loop_addr = voice.current_addr;
        voice.looping = true;
    }

    int32_t f0 = adpcm_coef[filter][0];
    int32_t f1 = adpcm_coef[filter][1];

    for (int i = 0; i < SPU2_SAMPLES_PER_BLOCK; i++) {
        int nibble_byte = block[2 + i / 2];
        int32_t nibble = (i & 1) ? (nibble_byte >> 4) : (nibble_byte & 0x0F);

        if (nibble > 7)
            nibble -= 16;

        int32_t sample = (nibble << 12) >> shift;
        sample += (voice.prev_sample[0] * f0 + voice.prev_sample[1] * f1 + 32) >> 6;

        sample = std::clamp(sample, -32768, 32767);

        voice.prev_sample[1] = voice.prev_sample[0];
        voice.prev_sample[0] = sample;

        output[i] = (int16_t)sample;
    }

    voice.current_addr += SPU2_BLOCK_SIZE;

    if (loop_end) {
        if (voice.looping) {
            voice.current_addr = voice.loop_addr;
        } else {
            voice.playing = false;
            voice.env_phase = SPU2Voice::EnvPhase::Off;
        }
    }
}

// Envelope processing
void SPU2::process_envelope(SPU2Voice& voice) {
    // Simplified ADSR — ramp linearly for now, can add exponential later
    switch (voice.env_phase) {
        case SPU2Voice::EnvPhase::Attack: {
            int step = (0x7FFF / std::max((int)voice.attack_rate, 1));
            voice.envelope_level += step;
            if (voice.envelope_level >= 0x7FFF) {
                voice.envelope_level = 0x7FFF;
                voice.env_phase = SPU2Voice::EnvPhase::Decay;
            }
            break;
        }
        case SPU2Voice::EnvPhase::Decay: {
            int target = voice.sustain_level;
            int step =
                std::max(1, (voice.envelope_level - target) / std::max((int)voice.decay_rate, 1));
            voice.envelope_level -= step;
            if (voice.envelope_level <= target) {
                voice.envelope_level = target;
                voice.env_phase = SPU2Voice::EnvPhase::Sustain;
            }
            break;
        }
        case SPU2Voice::EnvPhase::Sustain:
            // Sustain — gradually decrease or hold
            if (voice.sustain_dec) {
                voice.envelope_level -=
                    std::max(1, voice.envelope_level / std::max((int)voice.sustain_rate, 1));
                if (voice.envelope_level < 0)
                    voice.envelope_level = 0;
            }
            break;
        case SPU2Voice::EnvPhase::Release: {
            int step = std::max(1, voice.envelope_level / std::max((int)voice.release_rate * 4, 1));
            voice.envelope_level -= step;
            if (voice.envelope_level <= 0) {
                voice.envelope_level = 0;
                voice.env_phase = SPU2Voice::EnvPhase::Off;
                voice.playing = false;
            }
            break;
        }
        case SPU2Voice::EnvPhase::Off:
        default:
            break;
    }
}

// Sample interpolation
int32_t SPU2::get_interpolated_sample(SPU2Voice& voice) {
    // Advance pitch counter
    voice.pitch_counter += voice.pitch;

    // Check if we need to advance to next sample(s)
    while (voice.pitch_counter >= 0x1000) {
        voice.pitch_counter -= 0x1000;
        voice.decoded_pos++;

        if (voice.decoded_pos >= SPU2_SAMPLES_PER_BLOCK) {
            if (!voice.playing)
                return 0;
            decode_adpcm_block(voice, voice.decoded);
            voice.decoded_pos = 0;
        }
    }

    // Linear interpolation between current and next sample
    int pos = voice.decoded_pos;
    int next = (pos + 1 < SPU2_SAMPLES_PER_BLOCK) ? pos + 1 : 0;
    int32_t frac = voice.pitch_counter & 0xFFF;

    int32_t s0 = voice.decoded[pos];
    int32_t s1 = voice.decoded[next];

    return s0 + ((s1 - s0) * frac >> 12);
}

// Main mixer
void SPU2::mix_samples(int16_t* output, int num_samples) {
    memset(output, 0, num_samples * 2 * sizeof(int16_t));

    for (int s = 0; s < num_samples; s++) {
        int32_t left_acc = 0;
        int32_t right_acc = 0;

        for (int v = 0; v < SPU2_TOTAL_VOICES; v++) {
            SPU2Voice& voice = m_voices[v];
            if (!voice.playing)
                continue;

            // Get interpolated sample
            int32_t sample = get_interpolated_sample(voice);
            if (!voice.playing)
                continue; // May have stopped during decode

            // Process envelope
            process_envelope(voice);

            // Apply envelope
            sample = (sample * voice.envelope_level) >> 15;

            // Apply voice volume (signed 16-bit: -0x8000 to 0x7FFF)
            int32_t vol_l = (int16_t)voice.volume_left;
            int32_t vol_r = (int16_t)voice.volume_right;

            left_acc += (sample * vol_l) >> 15;
            right_acc += (sample * vol_r) >> 15;
        }

        // Apply master volume (per-core, both cores mixed to output)
        // For simplicity, use core 0 master volume
        int32_t mvl = m_master_vol_l[0] ? m_master_vol_l[0] : 0x3FFF;
        int32_t mvr = m_master_vol_r[0] ? m_master_vol_r[0] : 0x3FFF;

        left_acc = (left_acc * mvl) >> 15;
        right_acc = (right_acc * mvr) >> 15;

        // Clamp to 16-bit
        output[s * 2 + 0] = (int16_t)std::clamp(left_acc, -32768, 32767);
        output[s * 2 + 1] = (int16_t)std::clamp(right_acc, -32768, 32767);
    }

    // Push to WASAPI if available
#ifdef _WIN32
    if (m_audio_running && m_render_client && num_samples > 0) {
        IAudioClient* client = (IAudioClient*)m_audio_client;
        IAudioRenderClient* render = (IAudioRenderClient*)m_render_client;

        uint32_t padding = 0;
        client->GetCurrentPadding(&padding);
        uint32_t available = m_buffer_frames - padding;

        uint32_t to_write = std::min(available, (uint32_t)num_samples);
        if (to_write > 0) {
            BYTE* buffer = nullptr;
            HRESULT hr = render->GetBuffer(to_write, &buffer);
            if (SUCCEEDED(hr) && buffer) {
                memcpy(buffer, output, to_write * 2 * sizeof(int16_t));
                render->ReleaseBuffer(to_write, 0);
            }
        }
    }
#endif
}

void SPU2::process_keys() {
    // Called each frame — currently key on/off is handled immediately
    // in write_register. This is a placeholder for batched processing.
}

} // namespace reo
