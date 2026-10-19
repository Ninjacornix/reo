#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace reo {

/*
 * CRI ADX Audio Decoder
 *
 * ADX is CRI Middleware's proprietary audio format used for streamed
 * music and ambient sounds. It uses ADPCM with a custom predictor.
 *
 * Format:
 *   - Header: signature (0x8000), data offset, encoding type, block size,
 *     sample bitdepth, channel count, sample rate, total samples
 *   - Data: ADPCM blocks (typically 18 bytes/block → 32 samples)
 *   - Loop info: embedded in header
 *
 * RE Outbreak uses ADX for room ambient tracks and some music.
 */

struct AdxHeader {
    uint16_t data_offset;
    uint8_t encoding_type; // 3 = standard ADX, 4 = AHX
    uint8_t block_size;    // Usually 18
    uint8_t sample_bits;   // Usually 4
    uint8_t channel_count;
    uint32_t sample_rate;
    uint32_t total_samples;
    uint16_t highpass_freq;
    uint8_t version; // 3 or 4
    bool has_loop;
    uint32_t loop_start;
    uint32_t loop_end;
};

class AdxDecoder {
  public:
    AdxDecoder() = default;

    bool open(const std::string& path);
    bool open(const uint8_t* data, uint32_t size);

    // Decode samples (interleaved int16 for stereo)
    int decode(int16_t* output, int max_samples);

    // Seek to sample position
    void seek(uint32_t sample);

    // Reset to beginning
    void reset();

    const AdxHeader& header() const {
        return m_header;
    }
    bool is_open() const {
        return m_open;
    }

  private:
    bool parse_header();
    int16_t decode_sample(int channel, int32_t nibble);

    AdxHeader m_header = {};
    std::vector<uint8_t> m_data;
    uint32_t m_position = 0; // Current byte position in data
    bool m_open = false;

    // ADPCM state per channel
    struct ChannelState {
        int32_t prev[2]; // Previous 2 samples
        int32_t coef[2]; // Predictor coefficients
    };
    ChannelState m_channels[2] = {};
};

} // namespace reo
