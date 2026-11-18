#include "stream_window.hpp"
#include <algorithm>
#include <bit>
#include <climits>
#include <limits>
#include <stdexcept>
#include <utility>

namespace reo::native::adx_window::v2 {
namespace {
Config checked(Config c) {
    if (c.channels < 1 || c.channels > 2 || c.source_config.capacity != source::encoded_capacity)
        throw std::invalid_argument("Window2 fixed physical geometry");
    return c;
}
bool bounded(std::int64_t n) noexcept { return n >= 0 && n <= INT32_MAX; }
source::HeaderGeometry geometry(const adx_header::Loop& h) noexcept {
    return {std::bit_cast<std::int32_t>(h.positions[1]), std::bit_cast<std::int32_t>(h.positions[3]),
            std::bit_cast<std::int32_t>(h.positions[0]), std::bit_cast<std::int32_t>(h.positions[2])};
}
}
struct Identity { bool alive{true}, stopped{}; };
class StreamWindowOwner::Scope final {
public:
    explicit Scope(StreamWindowOwner& w) noexcept : owner_(w) { owner_.busy_ = true; }
    ~Scope() { owner_.busy_ = false; }
private: StreamWindowOwner& owner_;
};
StreamWindowOwner::StreamWindowOwner(Config c, std::shared_ptr<const resources::ByteView> view,
    std::unique_ptr<source::Backend> backend, std::shared_ptr<adx_header::KeyContext> keys, Hooks hooks, Bootstrap initial)
    : config_(checked(c)), hooks_(hooks), keys_(std::move(keys)), identity_(std::make_shared<Identity>()),
      pcm_({c.channels, initial.pcm_cursor, initial.queued_pcm_bytes}, {this, pcm_guard, pcm_publication}, 0xa5) {
    if (!keys_) throw std::invalid_argument("Window2 retained key context required");
    header_.configured_key = c.configured_key; header_.output_channels = static_cast<std::int32_t>(c.channels);
    header_.borrowed_pcm = {pcm::capacity / 2, (pcm::capacity + pcm::extension) / 2, 1};
    loop_.seamless_enabled = c.seamless_enabled;
    // All fixed PCM/staging/identity storage exists before constructing the
    // source or consuming its one-use link. No allocation follows that effect.
    source_ = std::make_unique<source::SharedEncodedSource>(c.source_config, std::move(view), std::move(backend),
        source::InitialLoop{{}, -1, source::FileTargetAction::none, source::DecoderLimitAction::none, c.loop_enabled},
        initial.source, source::Hooks{this, source_target, {this, source_enter, source_leave, source_error}});
    auto linked = source_->take_window_link();
    if (linked.status != source::Status::completed) throw std::logic_error("Fresh Window2 source link");
    link_.emplace(std::move(linked.link));
}
StreamWindowOwner::~StreamWindowOwner() { identity_->alive = false; }
Request StreamWindowOwner::request() const noexcept {
    Request r; if (!stopped_ && !fault_) r.identity_ = identity_; return r;
}
Status StreamWindowOwner::service(const Request& request) noexcept {
    if (busy_) return Status::busy;
    if (request.identity_ != identity_ || !identity_->alive) return Status::invalid_request;
    if (fault_) return Status::owned_fault;
    if (stopped_ || identity_->stopped) return Status::closed;
    return outer_.phase == OuterPhase::header ? service_header() : service_decode(request);
}
Snapshot StreamWindowOwner::snapshot() const noexcept {
    Snapshot s;
    s.outer = outer_; s.engine = engine_; s.predictor = predictor_; s.header = header_;
    s.loop = loop_; s.ready = ready_; s.source = source_->snapshot(); s.pcm = pcm_.snapshot();
    s.phase = phase_; s.sample_limit = link_->snapshot().sample_limit; s.odd_result = odd_;
    s.stopped = stopped_; s.fault = fault_; s.source_batch_held = input_.has_value(); s.pcm_write_held = output_.has_value();
    s.last_error = last_error_; return s;
}
void StreamWindowOwner::source_enter(void* p) noexcept {
    auto& w = *static_cast<StreamWindowOwner*>(p);
    if (w.hooks_.guard) w.hooks_.guard(w.hooks_.context, 0, true);
}
void StreamWindowOwner::source_leave(void* p) noexcept {
    auto& w = *static_cast<StreamWindowOwner*>(p);
    if (w.normal_input_get_) { w.outer_.encoded = w.source_->snapshot().consumers[0]; w.outer_.encoded_bound = true; }
    if (w.hooks_.guard) w.hooks_.guard(w.hooks_.context, 0, false);
}
void StreamWindowOwner::source_error(void* p, std::int32_t) noexcept {
    auto& w = *static_cast<StreamWindowOwner*>(p); w.fault_ = true; w.last_error_ = Status::source_failure;
}
void StreamWindowOwner::source_target(void* p, const source::TargetObservation& transition) noexcept {
    auto& w = *static_cast<StreamWindowOwner*>(p);
    if (w.hooks_.target) w.hooks_.target(w.hooks_.context, transition, w.snapshot());
}
void StreamWindowOwner::pcm_guard(void* p, std::uint32_t c, bool entering) noexcept {
    auto& w = *static_cast<StreamWindowOwner*>(p);
    if (!entering && w.normal_output_get_) {
        const auto grant = w.pcm_.snapshot().producer[c]; w.outer_.pcm_grants[c] = {grant.offset, grant.bytes};
        w.outer_.pcm_bound[c] = true;
    }
    if (w.hooks_.guard) w.hooks_.guard(w.hooks_.context, c + 1, entering);
}
void StreamWindowOwner::pcm_publication(void* p, std::uint32_t c, const pcm::View& v) noexcept {
    auto& w = *static_cast<StreamWindowOwner*>(p);
    if (w.hooks_.pcm) w.hooks_.pcm(w.hooks_.context, c, v, w.snapshot());
}
void StreamWindowOwner::notice(Notice n, std::int32_t value) noexcept {
    if (hooks_.notice) hooks_.notice(hooks_.context, n, value, snapshot());
}
bool StreamWindowOwner::disarm() noexcept {
    if (!link_ || !link_->valid()) return false;
    if (link_->configure(last_valid_geometry_, -1, INT32_MAX, source::FileTargetAction::none,
                         source::DecoderLimitAction::none) != source::Status::completed) return false;
    return source_->begin_shutdown() == source::Status::completed;
}
Status StreamWindowOwner::fail(Status error) noexcept {
    fault_ = true; stopped_ = true; identity_->stopped = true; last_error_ = error; phase_ = Phase::fault;
    (void)disarm(); return error;
}
bool StreamWindowOwner::sync_geometry() noexcept {
    const auto h = geometry(header_.loop); const auto total = header_.base.total_samples;
    if (h.loop_start_bytes < 0 || h.loop_end_bytes < h.loop_start_bytes || h.loop_start_samples < 0 ||
        h.loop_end_samples < h.loop_start_samples || std::uint32_t(h.loop_end_samples) > total ||
        h.loop_end_bytes > config_.source_config.byte_length) return false;
    const auto current = link_->snapshot();
    if (link_->configure(h, current.sample_limit, current.target_sectors, current.file_action,
                         current.decoder_action) != source::Status::completed) return false;
    last_valid_geometry_ = h; return true;
}
bool StreamWindowOwner::numeric_admission() const noexcept {
    constexpr std::int32_t samples = 2432, encoded = samples / 32 * 2 * 18;
    return bounded(std::int64_t(outer_.decoded_samples) + samples) && bounded(std::int64_t(outer_.encoded_bytes) + encoded) &&
        bounded(std::int64_t(outer_.sample_progress) + samples) && bounded(std::int64_t(outer_.encoded_progress) + encoded) &&
        bounded(std::int64_t(outer_.position) + samples) && bounded(std::int64_t(engine_.decoded_total) + samples) &&
        bounded(std::int64_t(header_.output_cursor) + samples) &&
        bounded(std::int64_t(loop_.iterations) + 1) && bounded(std::int64_t(loop_.seamless_samples) + outer_.decoded_samples);
}
bool StreamWindowOwner::borrow_one(std::int32_t maximum, bool normal) noexcept {
    if (input_) return false;
    normal_input_get_ = normal;
    auto result = source_->borrow_batch({source::BatchShape::one, maximum, 0});
    normal_input_get_ = false;
    if (result.batch.count()) input_.emplace(std::move(result.batch));
    return result.status == source::Status::completed && input_.has_value() && !fault_;
}
bool StreamWindowOwner::finish_input(source::FinishPlan plan) noexcept {
    const bool already_faulted = fault_;
    if (!input_ || source_->finish_batch(*input_, plan) != source::Status::completed || (!already_faulted && fault_)) return false;
    input_.reset(); return true;
}
Status StreamWindowOwner::service_header() noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::owned_fault;
    if (stopped_) return Status::closed;
    if (outer_.phase != OuterPhase::header) return Status::inactive;
    if (!adx_header::supported_fp_environment()) return Status::unsupported_profile;
    Scope scope(*this); return header_impl();
}
Status StreamWindowOwner::header_impl() noexcept {
    phase_ = Phase::header;
    if (!borrow_one(4096, false)) return fail(Status::source_failure);
    const auto n = input_->bytes(0);
    if (n < 0 || n > 4096) return fail(Status::source_failure);
    if (n < 16) return finish_input({source::FinishKind::consume_single_prefix, 0}) ? Status::completed : fail(Status::source_failure);
    if (input_->read_into(0, std::span(header_bytes_).first(static_cast<std::size_t>(n))) != source::Status::completed)
        return fail(Status::source_failure);
    const auto parsed = adx_header::decode_header(std::span<const std::uint8_t>(header_bytes_).first(static_cast<std::size_t>(n)), header_, *keys_);
    if (!sync_geometry()) return fail(Status::unsupported_profile);
    if (parsed.ahx_diagnostic) notice(Notice::ahx_header);
    if (parsed.status != adx_header::Status::completed) return fail(Status::header_refusal);
    if (header_.base.total_samples > INT32_MAX - 31u) return fail(Status::numeric_limit);
    if (parsed.source_result == 0 || parsed.source_result > n)
        return finish_input({source::FinishKind::consume_single_prefix, 0}) ? Status::completed : fail(Status::source_failure);
    if (parsed.source_result < 0) {
        if (!finish_input({source::FinishKind::consume_single_prefix, 0})) return fail(Status::source_failure);
        notice(Notice::rejected_header); outer_.phase = OuterPhase::rejected; return Status::completed;
    }
    outer_.accepted_header_bytes = parsed.source_result;
    if (!finish_input({source::FinishKind::consume_single_prefix, parsed.source_result})) return fail(Status::source_failure);
    outer_.phase = OuterPhase::decoding; return Status::completed;
}
void StreamWindowOwner::set_request_size(std::int32_t n) noexcept {
    outer_.max_request = n;
    engine_.request_setting = n; engine_.request_over_96 = n / 96;
    engine_.request_copy = n; engine_.request_over_1536 = n / 1536;
}
Status StreamWindowOwner::configure_ready() noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::owned_fault;
    if (stopped_) return Status::closed;
    Scope scope(*this); return ready_impl();
}
Status StreamWindowOwner::ready_impl() noexcept {
    if (outer_.phase != OuterPhase::decoding) return Status::inactive;
    if (header_.active_channels != static_cast<std::int32_t>(config_.channels) || header_.active_block_bytes != 18 ||
        header_.active_samples_per_block != 32 || !header_.base.total_samples) return fail(Status::unsupported_profile);
    const auto rate = header_.base.frequency;
    if (rate != 24000 && rate != 44100 && rate != 48000) return fail(Status::unsupported_profile);
    const bool loop = header_.loop.count > 0;
    const auto request = (static_cast<std::int32_t>(rate / 60) * 3 / (loop ? 1 : 2) + 64) / 64 * 64;
    const auto h = last_valid_geometry_;
    if (loop && h.loop_end_samples <= h.loop_start_samples) return fail(Status::unsupported_profile);
    const auto target = loop ? static_cast<std::int32_t>((std::int64_t(h.loop_end_bytes) + 2047) / 2048) : INT32_MAX;
    if (link_->configure(h, loop ? h.loop_start_samples : static_cast<std::int32_t>(header_.base.total_samples), target,
        loop ? source::FileTargetAction::file_loop : source::FileTargetAction::none,
        loop ? source::DecoderLimitAction::first_snapshot : source::DecoderLimitAction::seamless) != source::Status::completed)
        return fail(Status::source_failure);
    phase_ = Phase::ready; set_request_size(request); outer_.sample_progress = outer_.encoded_progress = 0;
    if (loop) {
        loop_.target_sectors = target; loop_.padding_bytes = (2048 - h.loop_end_bytes % 2048) % 2048;
        loop_.span_samples = h.loop_start_samples;
    }
    ready_.format = 16; notice(Notice::format, ready_.format); // Actual124E88 tag0 output depth.
    ready_.frequency = static_cast<std::int32_t>(rate); notice(Notice::frequency, ready_.frequency);
    ready_.channels = header_.active_channels; notice(Notice::channels, ready_.channels);
    // Original12C8D8 total setter is a NOOP. Retain metadata, not a fabricated
    // external notification. Tag0 also skips the format2 history-offset setter.
    ready_.total_samples = static_cast<std::int32_t>(header_.base.total_samples);
    const bool ainf = std::bit_cast<std::int32_t>(header_.ainf.value) > 0;
    ready_.pitch = config_.pitch_offset + (ainf ? std::bit_cast<std::int16_t>(header_.ainf.code) : 0);
    notice(Notice::pitch, ready_.pitch);
    const auto pan = [](std::int32_t configured, std::int32_t metadata, std::int32_t fallback) noexcept {
        if (configured == -128) return metadata == -128 ? fallback : metadata;
        return metadata == -128 ? configured : configured + metadata;
    };
    for (std::uint32_t c = 0; c < config_.channels; ++c) {
        ready_.pans[c] = pan(config_.pans[c], ainf ? std::bit_cast<std::int16_t>(header_.ainf.halves[c]) : -128,
            config_.channels == 1 ? 0 : c == 0 ? -15 : 15);
        notice(c == 0 ? Notice::pan_left : Notice::pan_right, ready_.pans[c]);
    }
    ready_.play = true; notice(Notice::play, 1); ready_.phase = ReadyState::Phase::configured; return Status::completed;
}
void StreamWindowOwner::reset_decoder() noexcept {
    // Selective 125248/135020 stop, followed by 12C9A0/12CC80 start.
    engine_.phase = EnginePhase::idle; predictor_.phase = EnginePhase::idle;
    header_.predictor.history = {}; // Actual135020 clears exactly eight history bytes; key/coefficients remain.
    outer_.end_when_empty = false; outer_.accepted_header_bytes = 0;
    outer_.decoded_samples = outer_.encoded_bytes = outer_.position = 0;
    outer_.sample_progress = outer_.encoded_progress = 0; outer_.max_request = INT32_MAX;
    const auto action = link_->snapshot().decoder_action;
    if (link_->set_sample_limit(-1, action) != source::Status::completed) { (void)fail(Status::source_failure); return; }
    outer_.phase = OuterPhase::header;
}
Status StreamWindowOwner::limit_impl() noexcept {
    phase_ = Phase::limit; const auto state = link_->snapshot(); const auto h = state.header;
    switch (state.decoder_action) {
    case source::DecoderLimitAction::none: return Status::completed;
    case source::DecoderLimitAction::seamless: return seamless_impl();
    case source::DecoderLimitAction::first_snapshot:
        loop_.saved = header_.predictor; loop_.saved_valid = true;
        outer_.sample_progress = 0; loop_.span_samples = h.loop_end_samples - h.loop_start_samples;
        if (link_->set_sample_limit(loop_.span_samples, source::DecoderLimitAction::repeat) != source::Status::completed)
            return fail(Status::source_failure);
        outer_.encoded_progress = h.loop_start_bytes; outer_.position = h.loop_start_samples;
        return Status::completed;
    case source::DecoderLimitAction::repeat:
        // File-backed profile ALWAYS borrows/consumes actual padding, including
        // when the runtime loop flag has since been disabled. No Ring reset.
        if (!borrow_one(loop_.padding_bytes, false)) return fail(Status::source_failure);
        if (input_->bytes(0) < loop_.padding_bytes) notice(Notice::repeat_padding_short);
        if (!finish_input({source::FinishKind::consume_single_prefix, input_->bytes(0)})) return fail(Status::source_failure);
        outer_.sample_progress = 0; loop_.span_samples = h.loop_end_samples - h.loop_start_samples;
        if (link_->set_sample_limit(loop_.span_samples, source::DecoderLimitAction::repeat) != source::Status::completed)
            return fail(Status::source_failure);
        outer_.encoded_progress = h.loop_start_bytes; outer_.position = h.loop_start_samples;
        if (!loop_.saved_valid) return fail(Status::unsupported_profile);
        header_.predictor.history = loop_.saved.history; header_.predictor.key = loop_.saved.key;
        ++loop_.iterations; return Status::completed;
    }
    return fail(Status::unsupported_profile);
}
Status StreamWindowOwner::seamless_impl() noexcept {
    if (!loop_.seamless_enabled) return Status::completed;
    if (input_) return fail(Status::source_failure);
    auto batch = source_->borrow_batch({source::BatchShape::two, INT32_MAX, INT32_MAX});
    if (batch.batch.count()) input_.emplace(std::move(batch.batch));
    if (batch.status != source::Status::completed || !input_ || input_->count() != 2 || fault_)
        return fail(Status::source_failure);
    const auto first = input_->bytes(0), second = input_->bytes(1);
    if (first < 0 || second < 0 || std::int64_t(first) + second > static_cast<std::int64_t>(encoded_.size()))
        return fail(Status::source_failure);
    if (input_->read_into(0, std::span(encoded_).first(static_cast<std::size_t>(first))) != source::Status::completed ||
        input_->read_into(1, std::span(encoded_).subspan(static_cast<std::size_t>(first), static_cast<std::size_t>(second))) != source::Status::completed)
        return fail(Status::source_failure);
    const auto bytes = std::span<const std::uint8_t>(encoded_);
    if (first < 16 || bytes[0] != 0x80 || bytes[1] != 1) {
        loop_.seamless_enabled = false;
        return finish_input({source::FinishKind::restore_reverse, 0}) ? Status::completed : fail(Status::source_failure);
    }
    const auto length = std::bit_cast<std::int16_t>(static_cast<std::uint16_t>((std::uint16_t(bytes[2]) << 8) + bytes[3] + 4));
    if (length < 0) return fail(Status::unsupported_profile); // Preserved unowned original negative-extent cut.
    const auto find = [](std::span<const std::uint8_t> span) noexcept -> std::int32_t {
        for (std::size_t i = 0; i + 1 < span.size(); i += 2)
            if (span[i] == 0x80 && span[i + 1] == 0) return static_cast<std::int32_t>(i);
        return -1;
    };
    const auto in_first = length <= first ? find(bytes.subspan(static_cast<std::size_t>(length), static_cast<std::size_t>(first - length))) : -1;
    const auto in_second = in_first < 0 ? find(bytes.subspan(static_cast<std::size_t>(first), static_cast<std::size_t>(second))) : -1;
    if (in_first < 0 && in_second < 0) {
        if (!finish_input({source::FinishKind::restore_reverse, 0})) return fail(Status::source_failure);
        loop_.seamless_enabled = false; return Status::completed;
    }
    const source::FinishPlan plan = in_first >= 0 ? source::FinishPlan{source::FinishKind::consume_first_prefix_restore_second, length + in_first}
        : source::FinishPlan{source::FinishKind::consume_second_prefix_consume_first, in_second};
    if (!finish_input(plan)) return fail(Status::source_failure);
    loop_.seamless_samples += outer_.decoded_samples;
    const auto previous_request = engine_.request_setting;
    reset_decoder(); if (fault_) return Status::owned_fault;
    const auto parsed = header_impl();
    if (parsed != Status::completed) return parsed;
    if (outer_.phase != OuterPhase::decoding) { loop_.seamless_enabled = false; return Status::completed; }
    if (header_.active_channels != static_cast<std::int32_t>(config_.channels)) return fail(Status::unsupported_profile);
    set_request_size(previous_request);
    if (link_->set_sample_limit(static_cast<std::int32_t>(header_.base.total_samples), source::DecoderLimitAction::seamless) != source::Status::completed)
        return fail(Status::source_failure);
    outer_.encoded_progress = outer_.sample_progress = 0; return Status::completed;
}
Status StreamWindowOwner::service_decode(const Request& request) noexcept {
    if (busy_) return Status::busy;
    if (request.identity_ != identity_ || !identity_->alive) return Status::invalid_request;
    if (fault_) return Status::owned_fault;
    if (stopped_ || identity_->stopped) return Status::closed;
    if (outer_.phase != OuterPhase::decoding) return Status::inactive;
    if (!adx_header::supported_fp_environment()) return Status::unsupported_profile;
    if (!numeric_admission()) return Status::numeric_limit;
    if (engine_.phase != EnginePhase::idle || predictor_.phase != EnginePhase::idle || input_ || output_)
        return Status::busy;
    Scope scope(*this); return decode_impl();
}
Status StreamWindowOwner::decode_impl() noexcept {
    const auto limit = link_->snapshot().sample_limit;
    if (limit >= 0 && outer_.sample_progress >= limit) {
        const auto action = limit_impl(); if (action != Status::completed) return action;
    }
    // Reload the end flag after the limit action. Its source/decoder identities
    // remain this graph; there is no implicit I/O service or outer-state retest.
    if (outer_.end_when_empty && !source_->snapshot().ring.data) { outer_.phase = OuterPhase::ended; return Status::completed; }
    phase_ = Phase::input;
    if (!borrow_one(INT32_MAX, true)) return fail(Status::source_failure);
    auto n = input_->bytes(0);
    if (n < 0 || n > static_cast<std::int32_t>(encoded_.size()) ||
        input_->read_into(0, std::span(encoded_).first(static_cast<std::size_t>(n))) != source::Status::completed)
        return fail(Status::source_failure);
    if (n >= 4 && encoded_[0] == 0x80 && encoded_[1] == 1) {
        outer_.phase = OuterPhase::ended;
        // Short malformed records in the original can discard a live descriptor
        // before a subsequent Get. Do not fabricate an equivalent credit return.
        if (n < 16) return fail(Status::unsupported_profile);
        const auto length = std::bit_cast<std::int16_t>(static_cast<std::uint16_t>((std::uint16_t(encoded_[2]) << 8) + encoded_[3] + 4));
        if (length < 0) return fail(Status::unsupported_profile);
        if (length > n) return finish_input({source::FinishKind::consume_single_prefix, 0}) ? Status::completed : fail(Status::source_failure);
        outer_.encoded.bytes = length;
        if (!finish_input({source::FinishKind::consume_single_prefix, length})) return fail(Status::source_failure);
        for (std::int32_t pass = 0; pass <= source::encoded_capacity; ++pass) {
            if (!borrow_one(INT32_MAX, true)) return fail(Status::source_failure);
            n = input_->bytes(0);
            if (n < 0 || n > static_cast<std::int32_t>(encoded_.size()) ||
                input_->read_into(0, std::span(encoded_).first(static_cast<std::size_t>(n))) != source::Status::completed)
                return fail(Status::source_failure);
            std::int32_t zeros = 0; while (zeros < n && !encoded_[static_cast<std::size_t>(zeros)]) ++zeros;
            outer_.encoded.bytes = zeros;
            if (!finish_input({source::FinishKind::consume_single_prefix, zeros})) return fail(Status::source_failure);
            if (zeros < n || !n) return Status::completed;
        }
        return fail(Status::source_failure);
    }
    if (outer_.position >= static_cast<std::int32_t>(header_.base.total_samples)) {
        outer_.phase = OuterPhase::ended;
        return finish_input({source::FinishKind::consume_single_prefix, 0}) ? Status::completed : fail(Status::source_failure);
    }
    if (pcm_.snapshot().rings[0].free / 2 < 32)
        return finish_input({source::FinishKind::consume_single_prefix, 0}) ? Status::backpressure : fail(Status::source_failure);
    engine_.input_offset = input_->offset(0); engine_.input_blocks = n / 18;
    engine_.input_bound = true;
    engine_.consumed_bytes = engine_.produced_samples = 0; engine_.phase = EnginePhase::requested;
    phase_ = Phase::output; normal_output_get_ = true;
    auto reservation = pcm_.reserve(); normal_output_get_ = false;
    if (reservation.status != pcm::Status::completed) return fail(Status::pcm_failure);
    output_.emplace(std::move(reservation.lease));
    const auto grant = output_->grant(0);
    engine_.sample_offset = grant.offset / 2; engine_.available_samples = std::min(grant.bytes / 2, outer_.max_request);
    const auto current_limit = link_->snapshot().sample_limit;
    engine_.remaining_samples = current_limit < 0 ? 0x1fffffff : current_limit - outer_.sample_progress;
    const auto remaining = engine_.remaining_samples;
    if (remaining < 0 || remaining > INT32_MAX - 31) return fail(Status::numeric_limit);
    const auto budget = (remaining + 31) / 32, padding = 31 - (remaining + 31) % 32;
    auto window = (pcm::capacity / 2 - engine_.sample_offset + 31) / 32;
    if (budget < window && engine_.sample_offset + window * 32 - padding < pcm::capacity / 2) ++window;
    const auto available = (engine_.available_samples + (remaining < engine_.available_samples ? padding : 0)) / 32;
    const auto channels = static_cast<std::int32_t>(config_.channels);
    const auto groups = std::min({engine_.input_blocks / channels, available, budget, window});
    if (groups < 0 || groups > 76) return fail(Status::unsupported_profile);
    const auto units = groups * channels;
    phase_ = Phase::codec;
    const auto route = channels == 1 ? adx_workspace::Route::mono : config_.downmix ? adx_workspace::Route::downmix_7_over_10 : adx_workspace::Route::stereo;
    auto admission = adx_workspace::prepare_into(route, std::span<const std::uint8_t>(encoded_).first(static_cast<std::size_t>(n)), units,
        {left_, channels == 1 ? std::span<std::int16_t>{} : std::span<std::int16_t>(right_)});
    if (admission.status != adx_workspace::Status::admitted || !admission.prepared) return fail(Status::codec_refusal);
    predictor_.input_offset = input_->offset(0); predictor_.requested_units = units;
    predictor_.channels = config_.channels; predictor_.configured = true;
    predictor_.left_offset = grant.offset; predictor_.right_offset = channels == 2 ? grant.offset : 0;
    predictor_.phase = EnginePhase::processing; engine_.phase = EnginePhase::processing;
    const auto p = header_.predictor;
    const auto result = adx_workspace::execute(std::move(*admission.prepared), {{p.history[0], p.history[1]}, {p.history[2], p.history[3]}, p.key[0]},
        {p.coefficients[0], p.coefficients[1], std::bit_cast<std::int16_t>(p.key[1]), std::bit_cast<std::int16_t>(p.key[2])});
    header_.predictor.history = {result.state.left.newest, result.state.left.previous, result.state.right.newest, result.state.right.previous};
    header_.predictor.key[0] = result.state.key;
    predictor_.completed_units = result.kernel_return; predictor_.phase = EnginePhase::ready;
    if (channels == 2 && result.kernel_return > 0 && (result.kernel_return & 1)) odd_ = 1;
    engine_.consumed_bytes = result.kernel_return * 18;
    engine_.produced_samples = result.kernel_return * 32 / channels;
    if (result.kernel_return >= budget * channels) engine_.produced_samples -= padding;
    const auto valid = std::min(engine_.produced_samples, static_cast<std::int32_t>(header_.base.total_samples) - outer_.position);
    if (engine_.produced_samples < 0 || valid < 0 || engine_.consumed_bytes < 0 || engine_.consumed_bytes > n)
        return fail(Status::codec_refusal);
    phase_ = Phase::staged_pcm;
    const auto count = result.samples_per_plane;
    if (pcm_.stage(*output_, {std::span<const std::int16_t>(left_).first(count),
        channels == 1 ? std::span<const std::int16_t>{} : std::span<const std::int16_t>(right_).first(count)}, engine_.produced_samples, valid) != pcm::Status::completed)
        return fail(Status::pcm_failure);
    predictor_.phase = EnginePhase::idle;
    engine_.decoded_total += engine_.produced_samples; header_.output_cursor += engine_.produced_samples;
    engine_.phase = EnginePhase::ready;
    phase_ = Phase::encoded_credit;
    if (!finish_input({source::FinishKind::consume_single_prefix, engine_.consumed_bytes})) return fail(Status::source_failure);
    phase_ = Phase::pcm_credit;
    if (pcm_.publish(*output_) != pcm::Status::completed) return fail(Status::pcm_failure);
    output_.reset(); phase_ = Phase::counters;
    outer_.decoded_samples += valid; outer_.encoded_bytes += engine_.consumed_bytes; outer_.position += valid;
    outer_.sample_progress += valid; outer_.encoded_progress += engine_.consumed_bytes;
    header_.output_cursor = 0; engine_.phase = EnginePhase::idle; predictor_.phase = EnginePhase::idle;
    phase_ = Phase::idle; return Status::completed;
}
source::ServiceResult StreamWindowOwner::service_source() noexcept {
    if (busy_) return {source::Status::reentrant_call};
    if (fault_) return {source::Status::invariant_fault};
    if (stopped_) return {source::Status::closed};
    Scope scope(*this); auto result = source_->service();
    if (result.status == source::Status::provider_failure && !source_->snapshot().ledger_fault && !fault_) {
        // An actual I/O error is measured source state, not proof its already
        // queued decoder bytes or credits are corrupt. Preserve that original
        // buffered continuation and return the error to the control caller.
        last_error_ = Status::source_failure; return result;
    }
    if (result.status != source::Status::completed || fault_) {
        (void)fail(Status::source_failure);
        if (result.status == source::Status::completed) result.status = source::Status::invariant_fault;
    }
    return result;
}
Status StreamWindowOwner::set_loop_enabled(bool enabled) noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::owned_fault;
    if (stopped_) return Status::closed;
    return source_->set_loop_enabled(enabled) == source::Status::completed ? Status::completed : fail(Status::source_failure);
}
Status StreamWindowOwner::set_source_paused(std::uint8_t paused) noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::owned_fault;
    if (stopped_) return Status::closed;
    return source_->set_paused(paused) == source::Status::completed ? Status::completed : fail(Status::source_failure);
}
Status StreamWindowOwner::request_source_stop() noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::owned_fault;
    if (stopped_) return Status::closed;
    Scope scope(*this);
    return source_->request_stop() == source::Status::completed ? Status::completed : fail(Status::source_failure);
}
pcm::ReadResult StreamWindowOwner::borrow_pcm(std::int32_t bytes) noexcept {
    if (busy_) return {pcm::Status::busy, {}};
    Scope scope(*this);
    return pcm_.read(bytes);
}
Status StreamWindowOwner::finish_pcm(pcm::ReadLease& lease) noexcept {
    if (busy_) return Status::busy;
    Scope scope(*this);
    return pcm_.finish(lease) == pcm::Status::completed ? Status::completed : Status::pcm_failure;
}
Status StreamWindowOwner::read_pcm_backing(std::uint32_t c, std::span<std::uint8_t> out) const noexcept {
    return pcm_.read_backing(c, out) == pcm::Status::completed ? Status::completed : Status::pcm_failure;
}
Status StreamWindowOwner::stop_decode() noexcept {
    if (busy_) return Status::busy;
    if (fault_) return Status::owned_fault;
    Scope scope(*this); stopped_ = true; identity_->stopped = true;
    return pcm_.stop() == pcm::Status::completed ? Status::completed : Status::retirement_pending;
}
Status StreamWindowOwner::retire_on_control_thread() noexcept {
    if (busy_) return Status::busy;
    if (phase_ == Phase::retired) return Status::completed;
    if (!stopped_) return Status::retirement_pending;
    Scope scope(*this);
    const bool already_joined = source_->snapshot().joined;
    if (!already_joined && !disarm()) return Status::retirement_pending;
    const auto source_state = source_->snapshot();
    if (source_state.ledger_fault) return Status::owned_fault;
    // A still-whole source batch can be explicitly restored after disarm. A
    // partial/invalid disposition will refuse and keep the source fence blocked.
    if (input_ && !finish_input({source::FinishKind::restore_reverse, 0})) return Status::owned_fault;
    if (output_) {
        if (pcm_.snapshot().phase != pcm::Phase::reserved || pcm_.restore(*output_) != pcm::Status::completed)
            return Status::retirement_pending;
        output_.reset();
    }
    phase_ = Phase::retiring;
    if (!already_joined) {
        const auto result = source_->service();
        if (result.status != source::Status::completed) return Status::owned_fault;
        if (!source_->finalize_shutdown_and_join()) return Status::retirement_pending;
    }
    if (pcm_.stop() != pcm::Status::completed || pcm_.retire() != pcm::Status::completed) return Status::retirement_pending;
    phase_ = Phase::retired; return Status::completed;
}
} // namespace reo::native::adx_window::v2
