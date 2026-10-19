#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace reo {

/*
 * CRI Sofdec Video Decoder
 *
 * Sofdec (.SFD) is CRI Middleware's video container format.
 * Container: MPEG Program Stream
 * Video: MPEG-1 or MPEG-2 (usually 30fps, 512x448 or similar)
 * Audio: ADX (CRI ADPCM)
 *
 * Used for FMV cutscenes in RE Outbreak.
 *
 * Strategy: Parse the SFD container to extract the MPEG video stream
 * and ADX audio stream, then decode with standard MPEG decoder (or FFmpeg).
 */

class SofdecDecoder {
  public:
    SofdecDecoder() = default;

    bool open(const std::string& path);
    void close();

    // Decode next video frame (RGBA output)
    bool decode_video_frame(uint8_t* rgba_output, int* width, int* height);

    // Decode audio samples (interleaved int16)
    int decode_audio(int16_t* output, int max_samples);

    // Seek to timestamp (milliseconds)
    void seek(uint32_t ms);

    bool is_open() const {
        return m_open;
    }
    bool is_finished() const {
        return m_finished;
    }

    int video_width() const {
        return m_video_width;
    }
    int video_height() const {
        return m_video_height;
    }
    int video_fps() const {
        return m_video_fps;
    }

  private:
    bool parse_sfd_header();
    bool demux_next_packet();

    std::vector<uint8_t> m_data;
    uint32_t m_position = 0;
    bool m_open = false;
    bool m_finished = false;

    int m_video_width = 0;
    int m_video_height = 0;
    int m_video_fps = 30;

    // Demuxed streams
    std::vector<uint8_t> m_video_stream;
    std::vector<uint8_t> m_audio_stream;
};

} // namespace reo
