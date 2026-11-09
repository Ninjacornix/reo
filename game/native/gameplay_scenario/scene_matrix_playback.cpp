#include "scene_matrix_programs.hpp"
#include <bit>
#include <exception>
namespace reo::native::gameplay_scenario {
namespace {
std::int16_t increment(std::int16_t value) noexcept {
    return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(value) + 1u));
}
}
SceneMatrixStatus SceneMatrixPrograms::source_type(std::size_t index,std::uint8_t value) noexcept {
    if(closed_)return SceneMatrixStatus::closed;
    if(index>=channels_.size())return SceneMatrixStatus::invalid_channel;
    channels_[index]->source_type=value;return SceneMatrixStatus::completed;
}
SceneMatrixPlaybackResult SceneMatrixPrograms::advance(
    std::size_t index, bool double_quantum, SceneMatrixSoundSink *sound) noexcept {
    SceneMatrixPlaybackResult result;
    if (closed_) {
        result.status = SceneMatrixStatus::closed;
        return result;
    }
    if (index >= channels_.size()) {
        result.status = SceneMatrixStatus::invalid_channel;
        return result;
    }
    auto &channel = *channels_[index];
    if (channel.playback != 1 && channel.playback != 2)
        return result;
    if (channel.curve >= 236 || channel.model_slot >= 128) {
        result.status = SceneMatrixStatus::unadmitted_profile;
        return result;
    }
    const auto &group = tables_.groups[channel.curve / 4];
    const auto sound_index = group.sounds[channel.curve % 4];
    const auto sounds = sound_index < 0 ? std::span<const SceneMatrixSound>{}
                                       : tables_.sounds[std::size_t(sound_index)];
    if (!sounds.empty() && (!sound || !sound->admitted() ||
                            !models_.state().sound_resources[channel.model_slot])) {
        result.status = SceneMatrixStatus::unavailable_sound;
        return result;
    }
    const auto base = models_.pose(channel.model_slot);
    if (!base) {
        result.status = SceneMatrixStatus::unadmitted_profile;
        return result;
    }
    try {
        transform_math::require_profile();
        if (channel.playback == 1) {
            channel.time = channel.segment = channel.sound_cursor = 0;
            channel.playback = 2;
            channel.matrix = *base;
        }
        const unsigned count = double_quantum ? 2 : 1;
        for (unsigned quantum = 0; quantum < count; ++quantum) {
            if (channel.curve >= 236 || channel.model_slot >= 128) {
                result.status = SceneMatrixStatus::unadmitted_profile;
                return result;
            }
            const auto &current_group = tables_.groups[channel.curve / 4];
            const auto current_keys = tables_.curves[current_group.curves[channel.curve % 4]];
            const auto current_sound_index = current_group.sounds[channel.curve % 4];
            const auto current_sounds = current_sound_index < 0 ? std::span<const SceneMatrixSound>{}
                : tables_.sounds[std::size_t(current_sound_index)];
            if (!current_sounds.empty() && (!sound || !sound->admitted() ||
                                            !models_.state().sound_resources[channel.model_slot])) {
                result.status = SceneMatrixStatus::unavailable_sound;
                return result;
            }
            if (channel.segment < 0 ||
                std::size_t(channel.segment) + 1 >= current_keys.size() ||
                (channel.sound_cursor != -1 &&
                 (channel.sound_cursor < 0 ||
                  (!current_sounds.empty() &&
                   std::size_t(channel.sound_cursor) >= current_sounds.size())))) {
                result.status = SceneMatrixStatus::unadmitted_profile;
                return result;
            }
            const auto current = current_keys[std::size_t(channel.segment)];
            const auto next = current_keys[std::size_t(channel.segment) + 1];
            const float difference = next.value - current.value;
            const float product = difference * float(std::int32_t(channel.time) - current.time);
            const float divided = product / float(next.time - current.time);
            const float value = divided + current.value;
            // Unknown transform modes preserve the prior matrix in6B4BA0.
            if (channel.transform <= 3) {
                const auto current_base=models_.pose(channel.model_slot);
                if(!current_base){result.status=SceneMatrixStatus::unadmitted_profile;return result;}
                channel.matrix = evaluate_value(*current_base, channel.transform, value);
            }
            channel.time = increment(channel.time);
            ++result.quanta;
            if (!current_sounds.empty() && channel.sound_cursor != -1) {
                const auto ordinal=std::size_t(channel.sound_cursor);
                const auto event = current_sounds[ordinal];
                if (event.time < channel.time) {
                    const auto &position = channel.matrix[3];
                    if (!sound->emit({position[0], position[1], position[2]},
                                     *models_.state().sound_resources[channel.model_slot],
                                     std::uint16_t(event.event))) {
                        result.status = SceneMatrixStatus::sound_refused;
                        return result;
                    }
                    ++result.sounds;
                    channel.sound_cursor = ordinal + 1 == current_sounds.size()
                                               ? std::int16_t(-1)
                                               : increment(channel.sound_cursor);
                }
            }
            if (next.time < channel.time) {
                channel.segment = increment(channel.segment);
                if (std::size_t(channel.segment) + 1 == current_keys.size()) {
                    channel.playback = 0;
                    channel.progress = 2;
                    break;
                }
            }
        }
    } catch (const std::exception &) {
        result.status = SceneMatrixStatus::unsupported_numeric;
    }
    return result;
}
}
