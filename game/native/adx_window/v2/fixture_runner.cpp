// Authored inputs only. This runner never reads an original expected snapshot.
#include "stream_window.hpp"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

namespace w = reo::native::adx_window::v2;
namespace s = reo::native::adxt_shared_source;
namespace old = reo::native::adxt_refill;
namespace resources = reo::native::resources;
namespace {
void require(bool v, const char* message) { if (!v) throw std::runtime_error(message); }
std::vector<std::uint8_t> unhex(const std::string& text) {
    std::vector<std::uint8_t> out;
    if (text != "-") for (std::size_t i = 0; i < text.size(); i += 2) out.push_back(static_cast<std::uint8_t>(std::stoul(text.substr(i, 2), nullptr, 16)));
    return out;
}
std::string hex(std::span<const std::uint8_t> bytes) {
    constexpr char digits[] = "0123456789abcdef"; std::string out; out.reserve(bytes.size() * 2);
    for (const auto b : bytes) { out += digits[b >> 4]; out += digits[b & 15]; } return out;
}
template<class Range> void numbers(const Range& values) {
    std::cout << '['; bool comma = false;
    for (const auto n : values) { if (comma) std::cout << ','; comma = true; std::cout << static_cast<std::int64_t>(n); }
    std::cout << ']';
}
void ring(const reo::native::sjrb::Snapshot& r) {
    std::cout << '[' << r.capacity << ',' << r.extension << ',' << r.data << ',' << r.free << ',' << r.write << ',' << r.read;
    for (const auto n : r.totals) std::cout << ',' << n;
    std::cout << ']';
}
void source_values(const s::Snapshot& x) {
    std::cout << '[' << x.state << ',' << x.accepted_sectors << ',' << x.progress_sectors << ',' << x.cumulative_bytes << ',' << x.retries << ',' << unsigned(x.paused)
        << ',' << x.in_flight << ',' << x.service_requested << ',' << x.stop_requested << ',' << x.close_requested << ',' << x.source_open << ',' << x.producer.offset << ',' << x.producer.bytes << ']';
}
void coordinate(bool bound, int role, int offset, std::optional<int> bytes = {}) {
    std::cout << '[' << (bound ? role : 0) << ',' << (bound ? offset : 0);
    if (bytes) std::cout << ',' << *bytes;
    std::cout << ']';
}
void state(const w::Snapshot& x, const reo::native::adx_header::KeyContext& keys, unsigned channels) {
    const auto& o = x.outer; const auto& i = x.engine; const auto& p = x.predictor; const auto& d = x.header;
    std::cout << "{\"outer\":{\"phase\":" << unsigned(o.phase) << ",\"endflag\":" << o.end_when_empty << ",\"input\":";
    coordinate(o.encoded_bound, 1, o.encoded.offset, o.encoded.bytes); std::cout << ",\"pcm\":[";
    for (unsigned c = 0; c < channels; ++c) { if (c) std::cout << ','; coordinate(o.pcm_bound[c], 2 + static_cast<int>(c), o.pcm_grants[c].offset, o.pcm_grants[c].bytes); }
    std::cout << "],\"counters\":[" << o.decoded_samples << ',' << o.encoded_bytes << ',' << o.position << ',' << o.max_request << ',' << x.sample_limit << ',' << o.sample_progress << ',' << o.encoded_progress
        << "],\"header_bytes\":" << o.accepted_header_bytes << "},\"inner\":{\"phase\":" << unsigned(i.phase) << ",\"input\":";
    coordinate(i.input_bound, 1, i.input_offset);
    std::cout << ",\"values\":[" << i.input_blocks << ',' << i.sample_offset << ',' << i.available_samples << ',' << i.remaining_samples << ',' << i.decoded_total << ',' << d.output_cursor << ',' << i.produced_samples << ',' << i.consumed_bytes
        << "],\"request_settings\":[" << i.request_setting << ',' << i.request_over_96 << ',' << i.request_copy << ',' << i.request_over_1536 << "]},\"predictor\":{\"phase\":" << unsigned(p.phase)
        << ",\"completed\":" << p.completed_units << ",\"mode\":" << p.channels << ",\"input\":";
    coordinate(p.configured, 1, p.input_offset); std::cout << ",\"requested\":" << p.requested_units << ",\"left\":";
    coordinate(p.configured, 2, p.left_offset); std::cout << ",\"right\":"; coordinate(p.configured && p.channels == 2, 3, p.right_offset);
    std::cout << ",\"history\":"; numbers(d.predictor.history); std::cout << ",\"coefficients\":"; numbers(d.predictor.coefficients); std::cout << ",\"key\":"; numbers(d.predictor.key);
    std::cout << "},\"header\":{\"phase\":" << d.header_phase << ",\"base\":[" << +d.base.encoding << ',' << +d.base.bits << ',' << +d.base.block_bytes << ',' << +d.base.channels << ',' << d.base.frequency << ',' << d.base.total_samples << ',' << d.base.samples_per_block
        << "],\"filter\":" << d.filter << ",\"tag\":" << d.format_tag << ",\"configured_key\":"; numbers(d.configured_key);
    std::cout << ",\"loop\":[" << d.loop.count << ',' << d.loop.enabled << ',' << d.loop.index;
    for (const auto n : d.loop.positions) std::cout << ',' << n;
    std::cout << "],\"ainf\":{\"value\":" << d.ainf.value << ",\"payload\":\"" << hex(d.ainf.payload) << "\",\"halves\":[" << d.ainf.code << ',' << d.ainf.halves[0] << ',' << d.ainf.halves[1]
        << "]},\"borrowed_pcm\":[" << d.borrowed_pcm.capacity_samples << ',' << d.borrowed_pcm.spacing_samples << ',' << d.borrowed_pcm.binding_role << "],\"active_pcm\":[" << d.active_pcm.capacity_samples << ',' << d.active_pcm.spacing_samples << ',' << d.active_pcm.binding_role
        << "],\"output_channels\":" << d.output_channels << ",\"active\":[" << d.active_channels << ',' << d.active_block_bytes << ',' << d.active_samples_per_block << "]},\"main\":[" << unsigned(x.ready.phase) << ',' << x.loop.padding_bytes << ',' << x.loop.target_sectors << ',' << x.loop.span_samples << ',' << x.loop.iterations << ',' << x.loop.seamless_samples << ',' << x.loop.seamless_enabled << ',' << i.request_setting
        << "],\"saved_history\":"; numbers(x.loop.saved.history); std::cout << ",\"saved_key\":"; numbers(x.loop.saved.key);
    std::cout << ",\"source\":"; source_values(x.source);
    std::cout << ",\"source_loop\":[" << x.source.loop.sample_limit << ',' << x.source.loop.target_sectors << ',' << x.source.loop.enabled << ',' << x.source.loop.header.loop_start_bytes << ',' << x.source.loop.header.loop_end_bytes << ',' << x.source.loop.header.loop_start_samples << ',' << x.source.loop.header.loop_end_samples << "],\"rings\":[";
    ring(x.source.ring);
    for (unsigned c = 0; c < channels; ++c) { std::cout << ','; ring(x.pcm.rings[c]); }
    std::cout << "],\"odd\":" << x.odd_result << ",\"keys\":[" << keys.module_references;
    for (const auto n : keys.fallback) std::cout << ',' << n;
    std::cout << "]}";
}
class View final : public resources::ByteView {
public:
    explicit View(std::vector<std::uint8_t> bytes) : bytes_(std::move(bytes)) {}
    std::uint64_t size() const noexcept override { return bytes_.size(); }
    resources::ReadResult read(std::uint64_t at, std::span<std::byte> out) const override {
        if (at > bytes_.size() || out.size() > bytes_.size() - at) return {resources::Status::invalid_range, 0};
        for (std::size_t i = 0; i < out.size(); ++i) out[i] = std::byte(bytes_[static_cast<std::size_t>(at) + i]);
        return {resources::Status::ok, out.size()};
    }
private: std::vector<std::uint8_t> bytes_;
};
class Script final : public s::Backend {
    struct Job { std::shared_ptr<const resources::ByteView> view; std::uint64_t offset, id; std::uint32_t sectors; std::vector<std::byte> bytes; bool written{}; };
    std::vector<Job> jobs_; std::optional<std::size_t> pending_;
public:
    int status{}, acceptance{-999}; bool declined_error{}, inline_write{};
    old::Acceptance submit(std::shared_ptr<const resources::ByteView> view, std::uint64_t offset, std::uint32_t count, std::uint64_t id) noexcept override {
        const auto accepted = acceptance == -999 ? static_cast<int>(count) : acceptance;
        if (accepted > 0) { jobs_.push_back({std::move(view), offset, id, static_cast<std::uint32_t>(accepted), {}, false}); pending_ = jobs_.size() - 1; if (inline_write) write_job(*pending_); }
        return {accepted, declined_error};
    }
    void write_job(std::size_t index) {
        require(index < jobs_.size(), "Unknown authored job"); auto& job = jobs_[index]; require(!job.written, "Duplicate authored write");
        job.bytes.resize(static_cast<std::size_t>(job.sectors) * 2048);
        require(job.view->read(job.offset, job.bytes).status == resources::Status::ok, "Private exact read"); job.written = true;
    }
    old::Completion poll() noexcept override {
        if (!pending_) return {};
        auto& job = jobs_[*pending_];
        if (status != 1 && status != 3) return {old::BackendState::pending, job.id, {}};
        pending_.reset();
        if (status == 3 || !job.written) { job.view.reset(); return {old::BackendState::error, job.id, {}}; }
        job.view.reset(); return {old::BackendState::complete, job.id, std::move(job.bytes)};
    }
    bool shutdown_and_join() noexcept override { return !pending_; }
};
struct Observer {
    w::StreamWindowOwner* owner{}; reo::native::adx_header::KeyContext* keys{}; unsigned channels{}; int action{-1}; bool suppress{};
    void begin(const char* kind) const { std::cout << "{\"action\":" << action << ",\"kind\":\"" << kind << '"'; }
    void finish(const w::Snapshot& value) const {
        std::cout << ",\"state\":"; state(value, *keys, channels); std::cout << ",\"pcm_backing_sha256\":[";
        for (unsigned c = 0; c < channels; ++c) {
            if (c) std::cout << ',';
            std::array<std::uint8_t, w::pcm::capacity + w::pcm::extension> bytes{};
            if (owner->read_pcm_backing(c, bytes) != w::Status::completed) std::terminate();
            const auto digest = reo_native_image_identity::sha256(bytes.data(), static_cast<std::uint32_t>(bytes.size()));
            std::cout << '"' << hex(digest) << '"';
        }
        std::cout << "]}\n";
    }
    static void guard(void* p, std::uint32_t r, bool entering) noexcept {
        auto& o = *static_cast<Observer*>(p); if (o.suppress) return;
        o.begin(entering ? "E" : "L"); std::cout << ",\"ring\":" << r; o.finish(o.owner->snapshot());
    }
    static void notice(void* p, w::Notice n, std::int32_t value, const w::Snapshot& snapshot) noexcept {
        auto& o = *static_cast<Observer*>(p); o.begin("N"); std::cout << ",\"notice\":" << unsigned(n) << ",\"value\":" << value; o.finish(snapshot);
    }
    static void publication(void* p, std::uint32_t c, const w::pcm::View& view, const w::Snapshot& snapshot) noexcept {
        auto& o = *static_cast<Observer*>(p); std::vector<std::uint8_t> bytes(static_cast<std::size_t>(view.bytes()));
        if (view.read_into(bytes) != w::pcm::Status::completed) std::terminate();
        o.begin("P"); std::cout << ",\"ring\":" << c + 1 << ",\"bytes\":" << view.bytes() << ",\"payload\":\"" << hex(bytes) << '"'; o.finish(snapshot);
    }
    static void target(void* p, const s::TargetObservation& transition, const w::Snapshot& snapshot) noexcept {
        auto& o = *static_cast<Observer*>(p); auto before = snapshot; before.source = transition.before; before.sample_limit = transition.before.loop.sample_limit;
        o.begin("T"); o.finish(before);
    }
    void end(w::Status status) const {
        begin("end"); std::cout << ",\"status\":" << unsigned(status) << ",\"pcm_backings\":[";
        for (unsigned c = 0; c < channels; ++c) {
            if (c) std::cout << ',';
            std::array<std::uint8_t, w::pcm::capacity + w::pcm::extension> bytes{};
            require(owner->read_pcm_backing(c, bytes) == w::Status::completed, "PCM backing observation"); std::cout << '"' << hex(bytes) << '"';
        }
        std::cout << ']'; finish(owner->snapshot());
    }
};
}
int main(int argc, char** argv) { try {
    require(argc == 2, "Authored wire path required"); std::ifstream input(argv[1]); require(bool(input), "Wire open");
    w::Config config; int loop, seamless, position, seed_bytes, pcm_queued; std::string encoded;
    input >> config.channels >> config.downmix >> loop >> seamless >> position >> seed_bytes >> pcm_queued >> encoded;
    require(bool(input), "Constructor input"); config.loop_enabled = loop != 0; config.seamless_enabled = seamless != 0;
    config.configured_key = {23456, 7, 65527}; // Literal authored original setup, not an observed output.
    const auto bytes = unhex(encoded); auto view = std::make_shared<View>(bytes);
    config.source_config.byte_length = static_cast<std::int32_t>(bytes.size());
    auto keys = std::make_shared<reo::native::adx_header::KeyContext>(); auto backend = std::make_unique<Script>(); auto* script = backend.get();
    Observer observer; observer.keys = keys.get(); observer.channels = config.channels;
    w::StreamWindowOwner owner(config, view, std::move(backend), keys, {&observer, Observer::guard, Observer::notice, Observer::publication, Observer::target},
        {{position, seed_bytes / 2048, std::span(bytes).first(static_cast<std::size_t>(seed_bytes))}, 0, pcm_queued});
    observer.owner = &owner; const auto request = owner.request(); observer.end(w::Status::completed);
    std::string kind;
    while (input >> observer.action >> kind) {
        w::Status status = w::Status::completed;
        if (kind == "header") status = owner.service_header();
        else if (kind == "ready") status = owner.configure_ready();
        else if (kind == "decode") status = owner.service(request);
        else if (kind == "source_stop") status = owner.request_source_stop();
        else if (kind == "source") {
            input >> script->status >> script->acceptance >> script->declined_error >> script->inline_write;
            const auto result = owner.service_source();
            if (result.status != s::Status::completed && result.status != s::Status::provider_failure) status = w::Status::source_failure;
        } else if (kind == "write_job") { std::size_t id; input >> id; script->write_job(id); }
        else if (kind == "consume_pcm") {
            int n; input >> n; observer.suppress = true; auto read = owner.borrow_pcm(n);
            if (read.status != w::pcm::Status::completed || owner.finish_pcm(read.lease) != w::Status::completed) status = w::Status::pcm_failure;
            observer.suppress = false; // Explicit external batch API; compare its stable final state only.
        } else throw std::runtime_error("Unsupported authored whole-owner action");
        require(bool(input), "Malformed action"); observer.end(status);
        if (owner.snapshot().fault) break;
    }
} catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; } }
