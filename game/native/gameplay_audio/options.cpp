#include "options.hpp"
#include <stdexcept>

namespace reo::native::gameplay_audio {
bool GainControl::apply(CommandSink& commands, std::int32_t port, std::uint32_t gain) noexcept {
    if (gain == 0) {
        if (!commands.apply(banks::SetMuted{true}))
            return false;
        zero_gate_ = true;
    } else if (zero_gate_) {
        if (!commands.apply(banks::SetMuted{false}))
            return false;
        zero_gate_ = false;
    }
    if (port == -1)
        return commands.apply(banks::SetAllVolumes{static_cast<std::uint16_t>(gain)});
    return commands.apply(
        banks::SetPortVolume{static_cast<std::uint8_t>(port), static_cast<std::uint16_t>(gain)});
}
bool Settings::mode() noexcept {
    return commands_->apply(banks::SetMono{options_->audio_mode == 1});
}
SettingsResult Settings::effects() noexcept {
    const float ratio = static_cast<float>(options_->effects_volume) / 7.0f;
    const bool applied = gain_.apply(*commands_, -1, static_cast<std::uint32_t>(256.0f * ratio));
    const auto maximum =
        static_cast<std::uint8_t>(static_cast<std::uint32_t>(127.0f * ratio) & 127);
    const bool first = streams_->maximum(1, maximum);
    const bool second = streams_->maximum(2, maximum);
    return {applied, first && second};
}
bool Settings::music() noexcept {
    const float ratio = static_cast<float>(options_->music_volume) / 7.0f;
    return streams_->maximum(
        0, static_cast<std::uint8_t>(static_cast<std::uint32_t>(127.0f * ratio) & 127));
}
SessionCommands::SessionCommands(std::shared_ptr<banks::Session> engine)
    : engine_(std::move(engine)) {
    if (!engine_)
        throw std::invalid_argument("Native audio commands require a bank session");
}
bool SessionCommands::apply(const banks::Command& command) noexcept {
    return engine_->apply({&command, 1}).status == banks::Status::ok;
}
} // namespace reo::native::gameplay_audio
