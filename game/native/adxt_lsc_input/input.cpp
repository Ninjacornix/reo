#include "input.hpp"
#include "../resources/bounded_view.hpp"
#include <algorithm>
#include <optional>
#include <stdexcept>
#include <vector>

namespace reo::native::adxt_lsc_input {
struct Identity {};
namespace {
class Origin final : public resources::ByteView {
public:
    std::uint64_t size() const noexcept override { return byte_domain; }
    resources::ReadResult read(std::uint64_t, std::span<std::byte>) const override {
        // A virtual origin is never read directly, including unavailable holes.
        // The exclusive backend supplies actual retained request snapshots.
        return {resources::Status::invalid_view, 0};
    }
};
bool same(lsc_queue::Range a, lsc_queue::Range b) noexcept {
    return a.parent == b.parent && a.first_sector == b.first_sector && a.sectors == b.sectors;
}
}
struct Input::State : std::enable_shared_from_this<State> {
    struct Asset { std::shared_ptr<const lsc_queue::Name> name; std::shared_ptr<const adx_sequence::Clip> clip; lsc_queue::Range range; };
    Config config;
    std::shared_ptr<const Identity> identity = std::make_shared<Identity>();
    std::shared_ptr<const resources::ByteView> origin = std::make_shared<Origin>();
    std::shared_ptr<Notification> notification;
    std::weak_ptr<Input> owner;
    std::vector<Asset> assets;
    std::unique_ptr<lsc_queue::Queue> queue;
    Snapshot report;
    std::optional<std::uint32_t> pending_asset;
    std::optional<Journal> current_file;
    std::uint32_t occupied{}, threshold{6553}, request_limit{8192}, configured_limit{};
    bool wanted{}, servicing{};

    State(Config c, std::shared_ptr<Notification> n) : config(c), notification(std::move(n)) {
        if ((c.channels != 1 && c.channels != 2) ||
            (c.frequency != 24000 && c.frequency != 44100 && c.frequency != 48000) ||
            !c.catalogue_entries || c.catalogue_entries > 8192 || c.journal_entries < 2 || c.journal_entries > 16)
            throw std::invalid_argument("Bounded live LSC input profile");
        assets.resize(c.catalogue_entries);
    }
    void fail(Status error) noexcept { report.error = error; report.file_state = 4; }
    void sweep() noexcept {
        while (report.journal_entries && report.journal[0].byte_end <= report.consumed_bytes &&
               report.journal[0].sample_end <= report.decoder_base) {
            for (unsigned i = 1; i < report.journal_entries; ++i) report.journal[i-1] = report.journal[i];
            report.journal[--report.journal_entries] = {};
        }
    }
    void observe(const adxt_shared_source::Snapshot& source) noexcept {
        if (source.cumulative_bytes < 0 || source.ring.data < 0 || source.ring.free < 0 || source.ring.free > 8192) {
            fail(Status::fault); return;
        }
        std::uint64_t held = 0;
        for (unsigned i = 0; i < source.consumer_count; ++i) {
            if (i >= source.consumers.size() || source.consumers[i].bytes < 0) { fail(Status::fault); return; }
            held += static_cast<unsigned>(source.consumers[i].bytes);
        }
        const auto published = static_cast<std::uint32_t>(source.cumulative_bytes);
        const auto unconsumed = std::uint64_t(source.ring.data) + held;
        if (published < report.published_bytes || published > report.planned_bytes || unconsumed > published) {
            fail(Status::fault); return;
        }
        const auto consumed = published - static_cast<std::uint32_t>(unconsumed);
        if (consumed < report.consumed_bytes) { fail(Status::fault); return; }
        report.published_bytes = published; report.consumed_bytes = consumed;
        occupied = 8192 - static_cast<std::uint32_t>(source.ring.free);
        if (current_file && report.file_state == 2) {
            report.file_progress = (published - current_file->byte_begin) / 2048;
            if (published >= current_file->byte_end) report.file_state = 3;
        }
        sweep();
    }
    void activate() noexcept {
        if (!wanted || !pending_asset || report.closing || report.error != Status::completed || report.file_state == 2) return;
        sweep();
        if (report.journal_entries == config.journal_entries) return; // Explicit bounded backpressure.
        const auto asset = *pending_asset; const auto& metadata = assets[asset].clip->metadata();
        const auto bytes = metadata.view->size(); const auto samples = metadata.header.base.total_samples;
        if (bytes > byte_domain - report.planned_bytes || samples > sample_domain - report.planned_samples) {
            fail(Status::numeric_limit); return;
        }
        if (report.planned_bytes != report.published_bytes) { fail(Status::unsupported_profile); return; }
        Journal entry{report.planned_bytes, report.planned_bytes + static_cast<std::uint32_t>(bytes),
                      report.planned_samples, report.planned_samples + samples, asset};
        report.journal[report.journal_entries++] = entry;
        report.planned_bytes = entry.byte_end; report.planned_samples = entry.sample_end;
        current_file = entry; pending_asset.reset(); report.file_state = 2; report.file_progress = 0;
    }
    struct Port final : lsc_queue::LowerFile, lsc_queue::EmptyNotification, lsc_queue::Errors {
        std::weak_ptr<State> owner_;
        explicit Port(std::shared_ptr<State> s) : owner_(std::move(s)) {}
        bool present() const noexcept override { auto s = owner_.lock(); return s && !s->report.joined; }
        void stop_before_open() noexcept override {
            if (auto s = owner_.lock()) {
                if (s->current_file && s->report.published_bytes < s->current_file->byte_end && !s->report.closing) {
                    s->fail(Status::unsupported_profile); return;
                }
                s->wanted = false; s->report.file_state = 0;
            }
        }
        void close_before_open() noexcept override {
            if (auto s = owner_.lock()) { s->current_file.reset(); s->pending_asset.reset(); }
        }
        void open_range(const lsc_queue::Entry& entry) noexcept override {
            if (auto s = owner_.lock()) {
                for (unsigned i = 0; i < s->report.registered_assets; ++i)
                    if (s->assets[i].name == entry.name && same(s->assets[i].range, entry.range)) {
                        s->pending_asset = i; s->report.file_state = 1; return;
                    }
                s->fail(Status::invalid_asset);
            }
        }
        void set_limit(std::uint32_t value) noexcept override { if (auto s = owner_.lock()) s->configured_limit = value; }
        void thresholds(std::uint32_t minimum, std::uint32_t capacity) noexcept override {
            if (auto s = owner_.lock()) {
                if (capacity != 8192 || minimum > capacity) { s->fail(Status::unsupported_profile); return; }
                s->threshold = minimum; s->request_limit = capacity;
            }
        }
        void position(std::uint32_t value) noexcept override {
            if (auto s = owner_.lock()) {
                if (value) s->fail(Status::unsupported_profile);
                else s->report.file_progress = 0;
            }
        }
        void start() noexcept override { if (auto s = owner_.lock()) { s->wanted = true; s->activate(); } }
        void stop_async() noexcept override {
            if (auto s = owner_.lock()) { s->wanted = false; s->pending_asset.reset(); s->report.file_state = 0; }
        }
        std::int32_t state() noexcept override { auto s = owner_.lock(); return s ? static_cast<std::int32_t>(s->report.file_state) : 4; }
        std::uint32_t progress_sectors() noexcept override { auto s = owner_.lock(); return s ? s->report.file_progress : 0; }
        void report(lsc_queue::Error) noexcept override { if (auto s = owner_.lock()) ++s->report.diagnostics; }
        void notify() noexcept override {
            if (auto s = owner_.lock()) {
                ++s->report.notifications;
                auto owner = s->owner.lock();
                if (owner && s->notification) s->notification->empty(*owner);
            }
        }
    };
};
class Input::Backend final : public adxt_refill::Backend {
    std::shared_ptr<State> state_;
    std::unique_ptr<adxt_refill::Backend> inner_;
    std::shared_ptr<const resources::ByteView> snapshot_;
    std::uint64_t id_{};
    bool pending_{}, joined_{};
public:
    Backend(std::shared_ptr<State> s, std::unique_ptr<adxt_refill::Backend> inner) : state_(std::move(s)), inner_(std::move(inner)) {}
    ~Backend() override {
        if (!joined_) { state_->report.closing = true; state_->report.abandoned = true; (void)inner_->shutdown_and_join(); }
    }
    adxt_refill::Acceptance submit(std::shared_ptr<const resources::ByteView> origin,
        std::uint64_t offset, std::uint32_t sectors, std::uint64_t id) noexcept override {
        auto& s = *state_;
        if (origin != s.origin || pending_ || joined_ || s.report.error != Status::completed ||
            offset != s.report.published_bytes || offset % 2048) { s.fail(Status::fault); return {0, true}; }
        if (s.report.closing) return {};
        if (!sectors || !s.current_file || !s.wanted || s.occupied >= s.threshold || offset >= s.current_file->byte_end) {
            ++s.report.unavailable_reads; return {};
        }
        if (offset < s.current_file->byte_begin) { s.fail(Status::fault); return {0, true}; }
        const auto count = std::min({sectors, (s.current_file->byte_end - static_cast<std::uint32_t>(offset)) / 2048, s.request_limit / 2048});
        if (!count) { ++s.report.unavailable_reads; return {}; }
        const auto& clip = s.assets[s.current_file->asset].clip;
        auto bounded = resources::bounded_view(clip->metadata().view, offset - s.current_file->byte_begin, std::uint64_t(count) * 2048);
        if (bounded.status != resources::Status::ok) { s.fail(Status::no_memory); return {0, true}; }
        const auto accepted = inner_->submit(bounded.view, 0, count, id);
        if (accepted.sectors > static_cast<std::int32_t>(count)) { s.fail(Status::fault); return {accepted.sectors, true}; }
        if (accepted.sectors > 0) { snapshot_ = std::move(bounded.view); id_ = id; pending_ = true; ++s.report.accepted_reads; }
        else if (accepted.error) s.fail(Status::source_failure);
        return accepted;
    }
    adxt_refill::Completion poll() noexcept override {
        auto result = inner_->poll();
        if (result.state == adxt_refill::BackendState::complete || result.state == adxt_refill::BackendState::error) {
            if (!pending_ || result.request_id != id_) state_->fail(Status::fault);
            if (result.state == adxt_refill::BackendState::complete) ++state_->report.completed_reads;
            else state_->fail(Status::source_failure);
            pending_ = false; snapshot_.reset();
        }
        return result;
    }
    bool shutdown_and_join() noexcept override {
        if (joined_) return true;
        state_->report.closing = true;
        if (pending_ || !inner_->shutdown_and_join()) return false;
        joined_ = true; auto& s = *state_; s.report.joined = true;
        s.current_file.reset(); s.pending_asset.reset(); snapshot_.reset();
        s.report.journal_entries = 0; s.report.journal = {}; s.assets.clear();
        s.report.registered_assets = 0; s.notification.reset(); return true;
    }
};
Input::Input(std::shared_ptr<State> state) : state_(std::move(state)) {}
std::shared_ptr<Input> Input::create(Config config, std::shared_ptr<Notification> notification) {
    auto state = std::make_shared<State>(config, std::move(notification));
    auto input = std::shared_ptr<Input>(new Input(state)); state->owner = input;
    auto port = std::make_shared<State::Port>(state);
    state->queue = std::make_unique<lsc_queue::Queue>(lsc_queue::Config{}, port, port, port); return input;
}
Input::~Input() = default;
bool Input::valid(const AssetKey& key) const noexcept {
    return key.identity_.lock() == state_->identity && key.slot_ < state_->report.registered_assets;
}
Registration Input::register_asset(std::string_view name, std::shared_ptr<const adx_sequence::Clip> clip, lsc_queue::Range range) noexcept {
    auto& s = *state_; if (s.report.closing || s.report.decoder_ended) return {Status::closed, {}};
    if (!clip || clip->metadata().header.active_channels != static_cast<std::int32_t>(s.config.channels) ||
        clip->metadata().header.base.frequency != s.config.frequency ||
        (range.sectors != 0xfffff && range.sectors != clip->metadata().view->size() / 2048)) return {};
    if (s.report.registered_assets == s.config.catalogue_entries) return {Status::capacity, {}};
    try {
        auto owned = lsc_queue::Name::prepare(name); const auto index = s.report.registered_assets;
        s.assets[index] = {std::move(owned), std::move(clip), range}; ++s.report.registered_assets;
        AssetKey key; key.identity_ = s.identity; key.slot_ = index; return {Status::completed, std::move(key)};
    } catch (const std::bad_alloc&) { return {Status::no_memory, {}}; }
    catch (...) { return {}; }
}
EntryResult Input::enqueue(const AssetKey& key) noexcept {
    auto& s = *state_; if (s.report.closing || s.report.decoder_ended) return {Status::closed, -1}; if (!valid(key)) return {};
    const auto& asset = s.assets[key.slot_]; const auto sequence = s.queue->enqueue({asset.name, asset.range});
    return {sequence < 0 ? Status::capacity : Status::completed, sequence};
}
Status Input::start() noexcept {
    auto& s = *state_; if (s.report.closing) return Status::closed;
    if (s.report.started) return Status::unsupported_profile;
    s.queue->start(); s.report.started = true; return Status::completed;
}
Status Input::stop() noexcept {
    if (state_->report.closing) return Status::closed;
    // A bound graph is retired by its session key, which fences output first.
    if (state_->report.bound) return Status::unsupported_profile;
    request_stop(); return Status::completed;
}
Status Input::pause(std::int32_t value) noexcept { if (state_->report.closing) return Status::closed; state_->queue->pause(value); return Status::completed; }
Status Input::repeat(std::int32_t value) noexcept { if (state_->report.closing) return Status::closed; state_->queue->repeat(value); return Status::completed; }
Status Input::minimum(std::int32_t value) noexcept { if (state_->report.closing) return Status::closed; state_->queue->minimum(value); return Status::completed; }
Snapshot Input::snapshot() const noexcept { auto out = state_->report; out.queue = state_->queue->snapshot(); return out; }
std::shared_ptr<const resources::ByteView> Input::origin() const noexcept { return state_->origin; }
std::uint32_t Input::channels() const noexcept { return state_->config.channels; }
std::uint32_t Input::frequency() const noexcept { return state_->config.frequency; }
std::unique_ptr<adxt_refill::Backend> Input::take_backend() {
    auto& s = *state_;
    if (s.report.bound || s.report.closing) throw std::invalid_argument("One-use live input binding");
    auto inner = adxt_refill::make_async_backend(8192);
    auto backend = std::make_unique<Backend>(state_, std::move(inner)); s.report.bound = true; return backend;
}
void Input::before_source(const adxt_shared_source::Snapshot& source) noexcept { state_->observe(source); state_->activate(); }
void Input::after_source(const adxt_shared_source::Snapshot& source, bool success) noexcept {
    state_->observe(source); if (!success) state_->fail(Status::source_failure);
}
void Input::after_decoder(const adxt_shared_source::Snapshot& source, std::uint32_t actual_base, bool ended) noexcept {
    if (actual_base < state_->report.decoder_base || actual_base > state_->report.planned_samples) { state_->fail(Status::fault); return; }
    state_->report.decoder_base = actual_base; state_->report.decoder_ended = ended; state_->observe(source);
}
Status Input::service_queue() noexcept {
    auto& s = *state_; if (s.servicing) return Status::busy; if (s.report.closing) return Status::closed;
    s.servicing = true; const auto result = s.queue->service(); s.servicing = false;
    if (s.report.error != Status::completed) return s.report.error;
    return result == lsc_queue::Service::completed ? Status::completed : Status::busy;
}
Header Input::next_header(std::uint32_t actual_base) const noexcept {
    const auto& s = *state_;
    for (unsigned i = 0; i < s.report.journal_entries; ++i) {
        const auto& entry = s.report.journal[i]; if (entry.sample_begin != actual_base) continue;
        if (i + 1 < s.report.journal_entries) {
            const auto& next = s.report.journal[i+1]; const auto& metadata = s.assets[next.asset].clip->metadata();
            return s.report.published_bytes >= next.byte_begin + metadata.header.base.header_bytes ? Header::ready : Header::pending;
        }
        const auto queue = s.queue->snapshot();
        if (s.report.published_bytes < entry.byte_end || s.pending_asset || queue.count > 1 ||
            (queue.count && queue.repeat == 1 && queue.paused != 1)) return Header::pending;
        return Header::ready;
    }
    return Header::invalid;
}
void Input::request_stop() noexcept {
    auto& s = *state_; if (s.report.closing) return;
    s.report.closing = true; s.wanted = false; s.pending_asset.reset(); s.queue->stop();
}
}
