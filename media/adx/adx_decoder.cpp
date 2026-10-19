#include "adx_decoder.h"
#include <cstdio>
#include <cstring>
#include <cmath>
#include <fstream>

namespace reo {

bool AdxDecoder::open(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file)
        return false;

    auto size = file.tellg();
    file.seekg(0);
    m_data.resize((size_t)size);
    file.read((char*)m_data.data(), size);

    return open(m_data.data(), (uint32_t)m_data.size());
}

bool AdxDecoder::open(const uint8_t* data, uint32_t size) {
    if (size < 4)
        return false;

    m_data.assign(data, data + size);

    if (!parse_header()) {
        fprintf(stderr, "[ADX] Failed to parse header\n");
        return false;
    }

    reset();
    m_open = true;
    return true;
}

bool AdxDecoder::parse_header() {
    if (m_data.size() < 6)
        return false;

    // ADX signature: 0x80 0x00
    if (m_data[0] != 0x80 || m_data[1] != 0x00) {
        fprintf(stderr, "[ADX] Invalid signature\n");
        return false;
    }

    // Data offset (big-endian uint16 at offset 2)
    m_header.data_offset = (m_data[2] << 8) | m_data[3];

    // Check for "(c)CRI" signature at data_offset - 2
    if (m_header.data_offset < 6 || m_header.data_offset > m_data.size()) {
        return false;
    }

    m_header.encoding_type = m_data[4];
    m_header.block_size = m_data[5];
    m_header.sample_bits = m_data[6];
    m_header.channel_count = m_data[7];
    m_header.sample_rate = (m_data[8] << 24) | (m_data[9] << 16) | (m_data[10] << 8) | m_data[11];
    m_header.total_samples =
        (m_data[12] << 24) | (m_data[13] << 16) | (m_data[14] << 8) | m_data[15];
    m_header.highpass_freq = (m_data[16] << 8) | m_data[17];
    m_header.version = m_data[18];

    // Calculate predictor coefficients from highpass frequency
    double cutoff = (double)m_header.highpass_freq;
    double sr = (double)m_header.sample_rate;
    double a = sqrt(2.0) - cos(2.0 * 3.14159265358979 * cutoff / sr);
    double b = sqrt(2.0) - 1.0;
    double c = (a - sqrt((a + b) * (a - b))) / b;

    m_channels[0].coef[0] = (int32_t)(c * 2.0 * 4096.0);
    m_channels[0].coef[1] = (int32_t)(-(c * c) * 4096.0);
    m_channels[1].coef[0] = m_channels[0].coef[0];
    m_channels[1].coef[1] = m_channels[0].coef[1];

    printf("[ADX] %dHz %dch %d samples (%s)\n", m_header.sample_rate, m_header.channel_count,
           m_header.total_samples, m_header.encoding_type == 3 ? "ADX" : "AHX");

    return true;
}

void AdxDecoder::reset() {
    m_position = m_header.data_offset + 4; // Skip past "(c)CRI" marker
    for (auto& ch : m_channels) {
        ch.prev[0] = 0;
        ch.prev[1] = 0;
    }
}

void AdxDecoder::seek(uint32_t sample) {
    // TODO: Calculate byte offset for given sample
    reset();
}

int16_t AdxDecoder::decode_sample(int channel, int32_t nibble) {
    // Sign-extend 4-bit nibble
    if (nibble > 7)
        nibble -= 16;

    auto& ch = m_channels[channel];
    int32_t sample = nibble + ((ch.coef[0] * ch.prev[0] + ch.coef[1] * ch.prev[1]) >> 12);

    // Clamp
    if (sample > 32767)
        sample = 32767;
    if (sample < -32768)
        sample = -32768;

    ch.prev[1] = ch.prev[0];
    ch.prev[0] = sample;

    return (int16_t)sample;
}

int AdxDecoder::decode(int16_t* output, int max_samples) {
    if (!m_open)
        return 0;

    int samples_decoded = 0;

    while (samples_decoded < max_samples && m_position + m_header.block_size <= m_data.size()) {
        for (int ch = 0;
             ch < m_header.channel_count && m_position + m_header.block_size <= m_data.size();
             ch++) {
            const uint8_t* block = m_data.data() + m_position;

            // First 2 bytes: scale (big-endian)
            int32_t scale = (block[0] << 8) | block[1];

            // Remaining bytes: 4-bit ADPCM nibbles
            int samples_in_block = (m_header.block_size - 2) * 2;

            for (int i = 0; i < samples_in_block && samples_decoded < max_samples; i++) {
                int byte_idx = 2 + i / 2;
                int32_t nibble;
                if (i & 1) {
                    nibble = block[byte_idx] & 0x0F;
                } else {
                    nibble = (block[byte_idx] >> 4) & 0x0F;
                }

                int16_t sample = decode_sample(ch, nibble * scale);

                if (m_header.channel_count == 1) {
                    output[samples_decoded++] = sample;
                } else {
                    output[samples_decoded * 2 + ch] = sample;
                    if (ch == m_header.channel_count - 1) {
                        samples_decoded++;
                    }
                }
            }

            m_position += m_header.block_size;
        }
    }

    return samples_decoded;
}

} // namespace reo
