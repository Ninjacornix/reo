#include "sofdec_decoder.h"
#include <cstdio>
#include <cstring>
#include <fstream>

namespace reo {

bool SofdecDecoder::open(const std::string& path) {
    std::ifstream file(path, std::ios::binary | std::ios::ate);
    if (!file) {
        fprintf(stderr, "[SFD] Failed to open: %s\n", path.c_str());
        return false;
    }

    auto size = file.tellg();
    file.seekg(0);
    m_data.resize((size_t)size);
    file.read((char*)m_data.data(), size);

    if (!parse_sfd_header()) {
        fprintf(stderr, "[SFD] Invalid SFD file: %s\n", path.c_str());
        return false;
    }

    m_open = true;
    m_finished = false;
    m_position = 0;

    printf("[SFD] Opened: %s (%dx%d @ %dfps)\n", path.c_str(), m_video_width, m_video_height,
           m_video_fps);
    return true;
}

void SofdecDecoder::close() {
    m_data.clear();
    m_video_stream.clear();
    m_audio_stream.clear();
    m_open = false;
}

bool SofdecDecoder::parse_sfd_header() {
    // SFD files are MPEG Program Streams
    // Look for MPEG-PS pack start code: 0x000001BA
    if (m_data.size() < 12)
        return false;

    // Check for MPEG-PS start code
    if (m_data[0] == 0x00 && m_data[1] == 0x00 && m_data[2] == 0x01 && m_data[3] == 0xBA) {
        // MPEG-2 PS
        m_video_width = 512; // Default for PS2 FMVs, actual size in sequence header
        m_video_height = 448;
        m_video_fps = 30;
        return true;
    }

    // Some SFD files have a CRI header before the MPEG data
    // Look for "SofdecStream" or "CRID" signature
    if (memcmp(m_data.data(), "CRID", 4) == 0) {
        // CRI container — skip header to find MPEG data
        // TODO: Parse CRI header for stream info
        m_video_width = 512;
        m_video_height = 448;
        m_video_fps = 30;
        return true;
    }

    return false;
}

bool SofdecDecoder::decode_video_frame(uint8_t* rgba_output, int* width, int* height) {
    if (!m_open || m_finished)
        return false;

    // TODO: Demux MPEG-PS to extract video packets
    // TODO: Decode MPEG-1/2 video frame
    // TODO: Convert YCbCr → RGBA

    *width = m_video_width;
    *height = m_video_height;

    // For now, return a black frame
    memset(rgba_output, 0, m_video_width * m_video_height * 4);

    return true;
}

int SofdecDecoder::decode_audio(int16_t* output, int max_samples) {
    // TODO: Extract ADX audio stream from MPEG-PS
    // TODO: Decode ADX audio
    return 0;
}

void SofdecDecoder::seek(uint32_t ms) {
    // TODO: Seek to nearest I-frame
}

bool SofdecDecoder::demux_next_packet() {
    // TODO: MPEG-PS demuxer
    // Read pack headers (0x000001BA)
    // Read PES packets (0x000001E0 = video, 0x000001BD = private/ADX audio)
    return false;
}

} // namespace reo
