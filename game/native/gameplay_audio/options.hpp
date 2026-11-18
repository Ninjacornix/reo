#pragma once
#include "routing.hpp"

namespace reo::native::gameplay_audio {
class StreamLevels {
  public:
    virtual ~StreamLevels() = default;
    // Bind the existing ordinary stream channel owner; values are original
    // seven-bit maxima, not a second music/ADX playback implementation.
    virtual bool maximum(unsigned channel, std::uint8_t value) noexcept = 0;
};
struct SettingsResult {
    bool banks{}, streams{};
};
class GainControl final {
  public:
    bool apply(CommandSink&, std::int32_t port, std::uint32_t value) noexcept;
    bool zero_gate() const noexcept {
        return zero_gate_;
    }

  private:
    bool zero_gate_{}; // Source game gate, distinct from backend mute state.
};
class Settings final {
  public:
    Settings(gameplay_session::Options& options, CommandSink& commands, StreamLevels& streams)
        : options_(&options), commands_(&commands), streams_(&streams) {}
    bool mode() noexcept;
    SettingsResult effects() noexcept;
    bool music() noexcept;
    GainControl& gain_control() noexcept {
        return gain_;
    }

  private:
    gameplay_session::Options* options_;
    CommandSink* commands_;
    StreamLevels* streams_;
    GainControl gain_;
};
// Real control command consumer, shared with gameplay Owner's engine.
class SessionCommands final : public CommandSink {
  public:
    explicit SessionCommands(std::shared_ptr<banks::Session>);
    bool apply(const banks::Command&) noexcept override;
    bool bound_to(const banks::Session& value) const noexcept {
        return engine_.get() == &value;
    }

  private:
    std::shared_ptr<banks::Session> engine_;
};
} // namespace reo::native::gameplay_audio
