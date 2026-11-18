#include "playback.hpp"
#include <algorithm>
#include <bit>
#include <stdexcept>

namespace reo::native::adxt_playback {
namespace {
bool valid(State s) noexcept {
    const auto p=static_cast<unsigned>(s.phase);
    return p>=2 && p<=5 && s.request_samples>0 && s.request_samples<=8192 &&
        (!s.stopping_transfer || s.phase==Phase::draining);
}
}
Playback::Playback(State s):state_(s) {
    if (!valid(s)) throw std::invalid_argument("Playback control profile");
}
Status Playback::fail() noexcept { state_.fault=true; return Status::fault; }
Status Playback::set_paused_flag(bool v) noexcept {
    if (busy_) return Status::busy;
    if (state_.fault) return Status::fault;
    state_.paused=v; return Status::completed;
}
Status Playback::set_start_inhibit(bool v) noexcept {
    if (busy_) return Status::busy;
    if (state_.fault) return Status::fault;
    state_.inhibit=v; return Status::completed;
}
Status Playback::finish(Output& out) noexcept {
    state_.stopping_transfer=true;
    const auto stopped=out.stop_transfer();
    if (stopped==Status::pending) return Status::pending;
    if (stopped!=Status::completed) return fail();
    if (out.play(false)!=Status::completed || out.through()!=Status::completed) return fail();
    state_.stopping_transfer=false; state_.phase=Phase::ended;
    return Status::completed;
}
Status Playback::service(Decoder d, Pcm& pcm, Output& out) noexcept {
    if (busy_) return Status::busy;
    if (state_.fault) return Status::fault;
    if (d.channels<1 || d.channels>2 || d.samples_per_block<=0 || d.samples_per_block>8192)
        return Status::invalid_input;
    if (state_.phase==Phase::ended) return Status::completed;
    busy_=true;
    struct Exit { bool& value; ~Exit(){value=false;} } exit{busy_};
    if (state_.stopping_transfer) return finish(out);
    const auto request=static_cast<std::uint32_t>(state_.request_samples);
    std::uint32_t queued{},free{};
    if (state_.phase==Phase::buffering) {
        if (out.queued_samples(queued)!=Status::completed || queued>8192 ||
            out.free_samples(free)!=Status::completed || free>8192) return fail();
        const bool wait=queued<2*request && free>static_cast<std::uint32_t>(d.samples_per_block) && !d.ended;
        if (!wait) {
            if (!state_.inhibit) {
                if (!state_.paused) {
                    if (out.play(true)!=Status::completed) return fail();
                    state_.estimate_base=0; state_.tick_base=d.tick;
                }
                state_.phase=Phase::playing;
            }
            // 134438 branches directly to the byte store at134478 when
            // inhibited. This flag also records an inhibited admission.
            state_.started=true;
        }
        if (d.ended) {
            // Original stereo buffering requests twice as many samples PER
            // channel. Do not replace this with the draining request below.
            const auto result=pcm.silence(request*d.channels);
            if (result.status==Status::busy)
                return state_.phase==Phase::buffering ? Status::busy : fail();
            if (result.status!=Status::completed || result.samples>request*d.channels) return fail();
        }
        return Status::completed;
    }
    if (state_.phase==Phase::playing) {
        if (!d.ended) return Status::completed;
        for (std::uint32_t c=0;c<d.channels;++c) {
            std::uint32_t bytes{};
            if (pcm.data_bytes(c,bytes)!=Status::completed || bytes>16384 || (bytes&1)) return fail();
            if (bytes>=64) return Status::completed;
        }
        state_.phase=Phase::draining; state_.padding_samples=0;
        return Status::completed;
    }
    // Preserve both RNA observations; they are distinct original queries.
    if (out.queued_samples(queued)!=Status::completed || queued>8192) return fail();
    const auto padding=pcm.silence(request);
    if (padding.status==Status::busy) return Status::busy;
    if (padding.status!=Status::completed || padding.samples>request) return fail();
    state_.padding_samples+=padding.samples; // original modulo-32-bit word
    std::uint32_t maximum{};
    for (std::uint32_t c=0;c<d.channels;++c) {
        std::uint32_t bytes{};
        if (pcm.data_bytes(c,bytes)!=Status::completed || bytes>16384 || (bytes&1)) return fail();
        maximum=std::max(maximum,bytes/2);
    }
    if (out.queued_samples(queued)!=Status::completed || queued>8192) return fail();
    const auto remaining=std::bit_cast<std::int32_t>(maximum+queued-state_.padding_samples);
    return remaining>0 ? Status::completed : finish(out);
}

StorePcm::StorePcm(adx_pcm::v2::Store& store,std::uint32_t channels):store_(store),channels_(channels) {
    if (channels<1 || channels>2) throw std::invalid_argument("PCM channel profile");
    const auto s=store_.snapshot();
    for (std::uint32_t c=0;c<channels;++c)
        if (s.rings[c].capacity!=adx_pcm::v2::capacity)
            throw std::invalid_argument("PCM owner channel mismatch");
    if (channels==1 && s.rings[1].capacity) throw std::invalid_argument("PCM owner channel mismatch");
}
Status StorePcm::data_bytes(std::uint32_t channel,std::uint32_t& bytes) noexcept {
    if (fault_ || channel>=channels_) return Status::fault;
    const auto s=store_.snapshot();
    if (s.fault || s.retired || s.rings[channel].data<0) return Status::fault;
    bytes=static_cast<std::uint32_t>(s.rings[channel].data); return Status::completed;
}
Padding StorePcm::silence(std::uint32_t maximum) noexcept {
    if (fault_) return {Status::fault,0};
    if (maximum>16384) return {Status::invalid_input,0};
    const auto before=store_.snapshot();
    if (before.fault || before.stopped || before.retired) return {Status::fault,0};
    if (held_ || before.write_id || before.read_id) return {Status::busy,0};
    auto result=store_.reserve();
    if (result.status==adx_pcm::v2::Status::busy) return {Status::busy,0};
    if (result.status!=adx_pcm::v2::Status::completed) { fault_=true; return {Status::fault,0}; }
    held_.emplace(std::move(result.lease));
    auto samples=maximum;
    for (std::uint32_t c=0;c<channels_;++c)
        samples=std::min(samples,static_cast<std::uint32_t>(held_->grant(c).bytes/2));
    const auto zero=std::span<const std::int16_t>(zero_).first(samples);
    const adx_pcm::v2::Pcm input{zero,channels_==2?zero:std::span<const std::int16_t>{}};
    if (store_.stage(*held_,input,static_cast<std::int32_t>(samples),static_cast<std::int32_t>(samples))!=adx_pcm::v2::Status::completed ||
        store_.publish(*held_)!=adx_pcm::v2::Status::completed) {
        fault_=true; return {Status::fault,0}; // actual lease remains owned
    }
    held_.reset(); return {Status::completed,samples};
}
} // namespace reo::native::adxt_playback
