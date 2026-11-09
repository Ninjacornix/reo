#pragma once
#include "options.hpp"
#include "../gameplay_scenario/stream_channels.hpp"

namespace reo::native::gameplay_audio {
// Bind the existing three-channel owner and its existing decoder/output
// backend. Both outlive this borrowed settings binding; no stream state copy.
class StreamLevelsBinding final : public StreamLevels {
  public:
    StreamLevelsBinding(gameplay_scenario::StreamChannels& channels,
                        gameplay_scenario::StreamBackend& backend) noexcept
        : channels_(&channels), backend_(&backend) {}
    bool maximum(unsigned channel, std::uint8_t value) noexcept override {
        if (channel >= 3)
            return false;
        return gameplay_scenario::stream_accepted(
            channels_->maximum(static_cast<std::uint8_t>(channel), value, *backend_));
    }

  private:
    gameplay_scenario::StreamChannels* channels_;
    gameplay_scenario::StreamBackend* backend_;
};
} // namespace reo::native::gameplay_audio
