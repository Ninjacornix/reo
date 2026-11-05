#include "pcm.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <mutex>
#include <stdexcept>
#include <vector>

namespace reo::native::pcm {
struct SessionIdentity {};
namespace {
constexpr std::uint32_t output_rate = 48000;
struct Ref {
    std::uint32_t slot{UINT32_MAX};
    std::uint64_t generation{};
};
bool same(Ref a, Ref b) {
    return a.slot == b.slot && a.generation == b.generation;
}
struct ChannelSlot {
    bool active{}, retired{};
    std::uint64_t generation{1}, queued{}, consumed{};
    std::size_t head{}, count{};
};
struct VoiceSlot {
    bool active{}, retired{};
    std::uint64_t generation{1};
    Ref left, right;
    VoiceInfo info;
};
} // namespace
struct Session::State {
    Config config;
    std::shared_ptr<const SessionIdentity> identity = std::make_shared<SessionIdentity>();
    mutable std::mutex mutex;
    bool closed{};
    std::vector<ChannelSlot> channels;
    std::vector<VoiceSlot> voices;
    std::vector<Ref> mix_order;
    std::size_t mix_order_count{};
    bool explicitly_ordered{};
    std::vector<std::int16_t> samples;
    Statistics stats;
    Clock timing;
    explicit State(Config c, std::int64_t now)
        : config(c), channels(c.max_channels), voices(c.max_voices), mix_order(c.max_voices),
          samples(c.channel_samples * c.max_channels) {
        timing.last_tick_ns = now;
    }
    bool valid(Ref r) const {
        return r.slot < channels.size() && channels[r.slot].active &&
               channels[r.slot].generation == r.generation;
    }
    bool uses(const VoiceSlot& v, Ref r) const {
        return v.active &&
               (same(v.left, r) || (v.info.channels == Channels::stereo && same(v.right, r)));
    }
    std::int16_t front(Ref r) const {
        return samples[std::size_t(r.slot) * config.channel_samples + channels[r.slot].head];
    }
    void pop(Ref r) {
        auto& c = channels[r.slot];
        c.head = (c.head + 1) % config.channel_samples;
        --c.count;
        c.consumed += 2;
    }
    template <class Slot> void invalidate(Slot& slot) {
        slot.active = false;
        if (slot.generation == config.max_generation)
            slot.retired = true;
        else
            ++slot.generation;
    }
    Status preflight_frames(std::uint32_t frames) const {
        if (frames > config.max_render_frames)
            return Status::invalid_input;
        if (frames > config.max_counter - stats.output_frames)
            return Status::counter_limit;
        if (!frames)
            return Status::ok;
        unsigned playing = 0;
        for (const auto& v : voices)
            if (v.active && v.info.playing && v.info.channels != Channels::disabled &&
                ++playing > 2 && !explicitly_ordered)
                return Status::unsupported_mix;
        for (const auto& v : voices)
            if (v.active && v.info.playing && v.info.channels != Channels::disabled) {
                const auto allowance = std::uint64_t(frames) * 2 + 2;
                if (v.info.late_samples > config.max_counter ||
                    allowance > config.max_counter - v.info.late_samples)
                    return Status::counter_limit;
                const auto available = valid(v.left) ? channels[v.left.slot].count : 0;
                if (available > config.max_counter - v.info.skipped_samples)
                    return Status::counter_limit;
            }
        return Status::ok;
    }
    void frames_locked(float* output, std::uint32_t frames) {
        if (output)
            std::fill(output, output + std::size_t(frames) * 2, 0.0f);
        for (std::uint32_t frame = 0; frame < frames; ++frame) {
            float left = 0, right = 0;
            bool starved = false;
            const auto count = explicitly_ordered ? mix_order_count : voices.size();
            for (std::size_t position = 0; position < count; ++position) {
                auto& v = voices[explicitly_ordered ? mix_order[position].slot : position];
                auto& i = v.info;
                if (!v.active || !i.playing || i.channels == Channels::disabled)
                    continue;
                const bool stereo = i.channels == Channels::stereo;
                auto available = [&] {
                    return valid(v.left) && channels[v.left.slot].count &&
                           (!stereo || (valid(v.right) && channels[v.right.slot].count));
                };
                while (i.late_samples && available()) {
                    pop(v.left);
                    if (stereo)
                        pop(v.right);
                    --i.late_samples;
                    ++i.skipped_samples;
                }
                if (i.draining && !available()) {
                    i.draining = false;
                    i.playing = false;
                    i.late_samples = 0;
                    i.phase = 0;
                    continue;
                }
                if (!available()) {
                    starved = true;
                    i.phase += i.frequency / static_cast<double>(output_rate);
                    const auto missing = static_cast<std::uint64_t>(i.phase);
                    i.late_samples += missing;
                    i.phase -= static_cast<double>(missing);
                    continue;
                }
                const float level = std::min(i.volume, 256u) / 256.0f / 32768.0f * i.gain;
                left += front(v.left) * level;
                right += (stereo ? front(v.right) : front(v.left)) * level;
                i.phase += i.frequency / static_cast<double>(output_rate);
                while (i.phase >= 1.0) {
                    if (!available())
                        break;
                    pop(v.left);
                    if (stereo)
                        pop(v.right);
                    i.phase -= 1.0;
                }
            }
            if (output) {
                output[std::size_t(frame) * 2] = std::clamp(left, -1.0f, 1.0f);
                output[std::size_t(frame) * 2 + 1] = std::clamp(right, -1.0f, 1.0f);
            }
            ++stats.output_frames;
            stats.signal_frames += (left != 0 || right != 0);
            stats.underrun_frames += starved;
        }
    }
    Status advance_locked(std::int64_t now) {
        if (timing.frame_clock || now <= timing.last_tick_ns)
            return Status::ok;
        const auto elapsed =
            static_cast<std::uint64_t>(now) - static_cast<std::uint64_t>(timing.last_tick_ns);
        if (elapsed > std::numeric_limits<std::uint64_t>::max() / output_rate)
            return Status::clock_limit;
        const auto frames = static_cast<std::uint32_t>(
            std::min<std::uint64_t>(output_rate / 4, elapsed * output_rate / 1000000000ULL));
        if (!frames)
            return Status::ok;
        const auto status = preflight_frames(frames);
        if (status != Status::ok)
            return status;
        frames_locked(nullptr, frames);
        timing.last_tick_ns += std::int64_t(std::uint64_t(frames) * 1000000000ULL / output_rate);
        return Status::ok;
    }
    void reset_locked(std::int64_t now) {
        explicitly_ordered = false;
        mix_order_count = 0;
        for (auto& c : channels)
            if (c.active)
                invalidate(c);
        for (auto& v : voices)
            if (v.active)
                invalidate(v);
        timing = {false, now};
    }
};

Session::Session(Config c, std::int64_t now) {
    if (!c.max_channels || !c.max_voices || !c.channel_samples || !c.max_enqueue_bytes ||
        c.max_enqueue_bytes % 2 || !c.max_render_frames || c.max_render_frames < 12000 ||
        !c.max_generation || !c.max_counter ||
        c.channel_samples > std::numeric_limits<std::size_t>::max() / c.max_channels ||
        c.channel_samples > std::numeric_limits<std::uint64_t>::max() / 2)
        throw std::invalid_argument("Invalid bounded PCM configuration");
    state_ = std::make_unique<State>(c, now);
}
Session::~Session() = default;
Result<Channel> Session::create_channel() noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, {}};
    for (std::uint32_t i = 0; i < s.channels.size(); ++i) {
        auto& c = s.channels[i];
        if (c.active || c.retired)
            continue;
        c.active = true;
        c.queued = c.consumed = 0;
        c.head = c.count = 0;
        Channel h;
        h.owner_ = s.identity;
        h.slot_ = i;
        h.generation_ = c.generation;
        return {Status::ok, h};
    }
    return {Status::capacity, {}};
}
Result<Voice> Session::create_voice() noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, {}};
    for (std::uint32_t i = 0; i < s.voices.size(); ++i) {
        auto& v = s.voices[i];
        if (v.active || v.retired)
            continue;
        v.active = true;
        s.explicitly_ordered = false;
        s.mix_order_count = 0;
        v.left = {};
        v.right = {};
        v.info = {};
        Voice h;
        h.owner_ = s.identity;
        h.slot_ = i;
        h.generation_ = v.generation;
        return {Status::ok, h};
    }
    return {Status::capacity, {}};
}
// Private handle checks are written in member methods: clients cannot fabricate
// native slot/generation/session identity from a numeric legacy handle.
#define CHANNEL_VALID(h) ((h).owner_.lock() == s.identity && s.valid({(h).slot_, (h).generation_}))
#define VOICE_VALID(h)                                                                             \
    ((h).owner_.lock() == s.identity && (h).slot_ < s.voices.size() &&                             \
     s.voices[(h).slot_].active && s.voices[(h).slot_].generation == (h).generation_)
Status Session::set_mix_order(std::span<const Voice> order) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    const auto active = std::count_if(s.voices.begin(), s.voices.end(),
                                      [](const auto& voice) { return voice.active; });
    if (order.size() != static_cast<std::size_t>(active))
        return Status::invalid_input;
    for (std::size_t i = 0; i < order.size(); ++i) {
        if (!VOICE_VALID(order[i]))
            return Status::invalid_handle;
        for (std::size_t j = 0; j < i; ++j)
            if (order[i].slot_ == order[j].slot_)
                return Status::invalid_input;
    }
    for (std::size_t i = 0; i < order.size(); ++i)
        s.mix_order[i] = {order[i].slot_, order[i].generation_};
    s.mix_order_count = order.size();
    s.explicitly_ordered = true;
    return Status::ok;
}
Status Session::close_channel(const Channel& h) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!CHANNEL_VALID(h))
        return Status::invalid_handle;
    for (const auto& v : s.voices) {
        if (s.uses(v, {h.slot_, h.generation_}))
            return Status::channel_in_use;
    }
    s.invalidate(s.channels[h.slot_]);
    return Status::ok;
}
Status Session::release(const Voice& h) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!VOICE_VALID(h))
        return Status::invalid_handle;
    s.invalidate(s.voices[h.slot_]);
    s.explicitly_ordered = false;
    s.mix_order_count = 0;
    return Status::ok;
}
Status Session::configure(const Voice& h, const VoiceConfig& c, std::int64_t now) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!VOICE_VALID(h))
        return Status::invalid_handle;
    if (c.channels != Channels::disabled && c.channels != Channels::mono &&
        c.channels != Channels::stereo)
        return Status::invalid_input;
    const bool has_left =
        c.left.slot_ != UINT32_MAX || c.left.generation_ != 0 || !c.left.owner_.expired();
    const bool has_right =
        c.right.slot_ != UINT32_MAX || c.right.generation_ != 0 || !c.right.owner_.expired();
    if ((c.channels != Channels::disabled || has_left) && !CHANNEL_VALID(c.left))
        return Status::invalid_handle;
    if (c.channels == Channels::stereo && !CHANNEL_VALID(c.right))
        return Status::invalid_handle;
    if (c.channels != Channels::stereo && has_right)
        return Status::invalid_input;
    const Ref left{c.left.slot_, c.left.generation_}, right{c.right.slot_, c.right.generation_};
    if (c.channels == Channels::stereo && same(left, right))
        return Status::unsupported_alias;
    for (std::size_t n = 0; n < s.voices.size(); ++n)
        if (n != h.slot_ && ((has_left && s.uses(s.voices[n], left)) ||
                             (c.channels == Channels::stereo && s.uses(s.voices[n], right))))
            return Status::unsupported_alias;
    const auto advanced = s.advance_locked(now);
    if (advanced != Status::ok)
        return advanced;
    auto& v = s.voices[h.slot_];
    auto& i = v.info;
    bool playing = c.playing;
    if (playing)
        i.draining = false;
    else if (i.draining)
        playing = true;
    v.left = left;
    v.right = right;
    i.channels = c.channels;
    i.frequency = std::clamp(c.frequency ? c.frequency : 48000u, 8000u, 96000u);
    i.volume = c.volume;
    if (playing != i.playing)
        i.late_samples = i.skipped_samples = 0;
    i.playing = playing;
    return Status::ok;
}
Status Session::gain(const Voice& h, float gain) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!VOICE_VALID(h))
        return Status::invalid_handle;
    if (!std::isfinite(gain) || gain < 0 || gain > 8)
        return Status::invalid_input;
    s.voices[h.slot_].info.gain = gain;
    return Status::ok;
}
Result<std::uint64_t> Session::enqueue(const Channel& h, std::span<const std::byte> bytes,
                                       std::int64_t now) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, 0};
    if (!CHANNEL_VALID(h))
        return {Status::invalid_handle, 0};
    if (bytes.empty() || !bytes.data() || bytes.size() % 2 ||
        bytes.size() > s.config.max_enqueue_bytes)
        return {Status::invalid_input, 0};
    auto& c = s.channels[h.slot_];
    if (bytes.size() > s.config.max_counter - c.queued)
        return {Status::counter_limit, 0};
    const auto advanced = s.advance_locked(now);
    if (advanced != Status::ok)
        return {advanced, 0};
    if (bytes.size() / 2 > s.config.channel_samples - c.count)
        return {Status::capacity, 0};
    for (std::size_t i = 0; i < bytes.size(); i += 2) {
        const auto bits = static_cast<std::uint16_t>(
            std::to_integer<unsigned>(bytes[i]) | (std::to_integer<unsigned>(bytes[i + 1]) << 8));
        const auto sample =
            bits < 32768 ? static_cast<std::int16_t>(bits)
                         : static_cast<std::int16_t>(static_cast<std::int32_t>(bits) - 65536);
        s.samples[std::size_t(h.slot_) * s.config.channel_samples +
                  (c.head + c.count) % s.config.channel_samples] = sample;
        ++c.count;
    }
    c.queued += bytes.size();
    return {Status::ok, c.queued};
}
Result<std::uint64_t> Session::consumed(const Channel& h, std::int64_t now) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, 0};
    if (!CHANNEL_VALID(h))
        return {Status::invalid_handle, 0};
    const auto status = s.advance_locked(now);
    return {status, status == Status::ok ? s.channels[h.slot_].consumed : 0};
}
Status Session::discard(const Channel& h) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!CHANNEL_VALID(h))
        return Status::invalid_handle;
    auto& c = s.channels[h.slot_];
    c.head = c.count = 0;
    c.consumed = c.queued;
    return Status::ok;
}
Status Session::drain(const Voice& h) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!VOICE_VALID(h))
        return Status::invalid_handle;
    auto& v = s.voices[h.slot_];
    if (v.info.playing && s.valid(v.left) && s.channels[v.left.slot].count) {
        v.info.draining = true;
        v.info.late_samples = 0;
    }
    return Status::ok;
}
StopResult Session::stop(const Voice& h, bool unreturned, std::uint32_t raw_rate) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, {}};
    if (!VOICE_VALID(h))
        return {Status::invalid_handle, {}};
    auto& v = s.voices[h.slot_];
    const auto left = s.valid(v.left) ? s.channels[v.left.slot].count : 0;
    const auto right = v.info.channels == Channels::stereo && s.valid(v.right)
                           ? s.channels[v.right.slot].count
                           : 0;
    if (unreturned && std::max(left, right) > std::uint64_t(raw_rate ? raw_rate : 48000u) * 3 / 2) {
        for (auto ref : {v.left, v.info.channels == Channels::stereo ? v.right : Ref{}})
            if (s.valid(ref)) {
                auto& c = s.channels[ref.slot];
                c.head = c.count = 0;
                c.consumed = c.queued;
            }
        s.invalidate(v);
        s.explicitly_ordered = false;
        s.mix_order_count = 0;
        return {Status::ok, StopAction::cut};
    }
    if (v.info.playing && left) {
        v.info.draining = true;
        v.info.late_samples = 0;
    }
    return {Status::ok, StopAction::drain};
}
Status Session::render(std::span<float> output) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (output.size() % 2 || output.size() / 2 > s.config.max_render_frames ||
        (!output.empty() && !output.data()))
        return Status::invalid_input;
    const auto frames = static_cast<std::uint32_t>(output.size() / 2);
    const auto status = s.preflight_frames(frames);
    if (status != Status::ok)
        return status;
    s.timing.frame_clock = true;
    s.frames_locked(output.data(), frames);
    return Status::ok;
}
Status Session::advance_frames(std::uint32_t frames) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    const auto status = s.preflight_frames(frames);
    if (status != Status::ok)
        return status;
    s.timing.frame_clock = true;
    s.frames_locked(nullptr, frames);
    return Status::ok;
}
Status Session::advance_headless(std::int64_t now) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    return s.advance_locked(now);
}
Status Session::select_frame_clock() noexcept {
    return advance_frames(0);
}
Result<ChannelInfo> Session::inspect(const Channel& h) const noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, {}};
    if (!CHANNEL_VALID(h))
        return {Status::invalid_handle, {}};
    const auto& c = s.channels[h.slot_];
    return {Status::ok, {c.count, c.queued, c.consumed}};
}
Result<VoiceInfo> Session::inspect(const Voice& h) const noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return {Status::closed, {}};
    if (!VOICE_VALID(h))
        return {Status::invalid_handle, {}};
    return {Status::ok, s.voices[h.slot_].info};
}
Status Session::copy_samples(const Channel& h, std::span<std::int16_t> output) const noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    if (!CHANNEL_VALID(h))
        return Status::invalid_handle;
    const auto& c = s.channels[h.slot_];
    if (output.size() != c.count)
        return Status::invalid_input;
    for (std::size_t i = 0; i < c.count; ++i)
        output[i] = s.samples[std::size_t(h.slot_) * s.config.channel_samples +
                              (c.head + i) % s.config.channel_samples];
    return Status::ok;
}
Statistics Session::statistics() const noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    return s.stats;
}
Clock Session::clock() const noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    return s.timing;
}
Status Session::reset(std::int64_t now) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (s.closed)
        return Status::closed;
    s.reset_locked(now);
    return Status::ok;
}
void Session::shutdown(std::int64_t now) noexcept {
    auto& s = *state_;
    std::lock_guard lock(s.mutex);
    if (!s.closed) {
        s.reset_locked(now);
        s.closed = true;
    }
}
#undef CHANNEL_VALID
#undef VOICE_VALID
std::uint32_t paced_budget(PacedState& state, std::uint32_t rate, std::uint32_t channels, bool left,
                           bool right, std::uint64_t now) noexcept {
    const auto bytes_per_sec =
        std::uint64_t(rate ? rate : 48000u) * (channels ? channels : 2u) * 2u;
    auto delta = state.last_ns ? now - state.last_ns : 0;
    state.last_ns = now;
    delta = std::min<std::uint64_t>(delta, 250000000ULL);
    const auto rings = std::max(1u, unsigned(left) + unsigned(right));
    return static_cast<std::uint32_t>(bytes_per_sec * delta / (1000000000ULL * rings));
}
} // namespace reo::native::pcm
