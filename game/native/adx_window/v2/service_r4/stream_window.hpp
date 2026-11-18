#pragma once
#include "../../../adx_header/adx_header.hpp"
#include "../../../adx_pcm_store/v2/pcm_store.hpp"
#include "../../../adx_workspace/adx_workspace.hpp"
#include "../../../adxt_shared_source/shared_source.hpp"
#include "../../../adxt_playback/playback.hpp"
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>
#include <vector>

// Independent composed owner. See the composition contract and implementation
// qualification for the admitted profile; game/player integration is separate.
namespace reo::native::adx_window::service_r4 {
namespace source = adxt_shared_source;
namespace pcm = adx_pcm::v2;
enum class Status { completed, inactive, backpressure, busy, closed, invalid_request,
    unsupported_profile, numeric_limit, header_refusal, source_failure, pcm_failure,
    codec_refusal, owned_fault, retirement_pending };
enum class Phase { idle, limit, header, ready, input, output, codec, staged_pcm,
    encoded_credit, pcm_credit, counters, fault, retiring, retired };
enum class OuterPhase : std::uint8_t { idle, header, decoding, ended, rejected };
enum class EnginePhase : std::uint32_t { idle, requested, processing, ready };
struct Outer {
    OuterPhase phase{OuterPhase::header}; bool end_when_empty{};
    source::Grant encoded; std::array<source::Grant, 2> pcm_grants{};
    bool encoded_bound{}; std::array<bool, 2> pcm_bound{};
    std::int32_t decoded_samples{}, encoded_bytes{}, position{}, max_request{128},
        sample_progress{}, encoded_progress{}, accepted_header_bytes{};
};
struct Engine {
    EnginePhase phase{EnginePhase::idle};
    bool input_bound{};
    std::int32_t input_offset{}, input_blocks{}, sample_offset{}, available_samples{},
        remaining_samples{}, decoded_total{}, produced_samples{}, consumed_bytes{};
    std::int32_t request_setting{}, request_over_96{}, request_copy{}, request_over_1536{};
};
struct PredictorControl {
    EnginePhase phase{EnginePhase::idle};
    std::uint32_t channels{}; bool configured{};
    std::int32_t input_offset{}, requested_units{}, completed_units{}, left_offset{}, right_offset{};
};
struct LoopState {
    std::int32_t padding_bytes{}, target_sectors{}, span_samples{}, iterations{}, seamless_samples{};
    adx_header::Predictor saved; bool saved_valid{}, seamless_enabled{};
};
struct ReadyState {
    enum class Phase : std::uint8_t { waiting=1, configured=2 } phase{Phase::waiting};
    std::int32_t frequency{}, channels{}, total_samples{}, format{}, pitch{}, history_offset{};
    std::array<std::int32_t, 2> pans{};
    bool play{};
};
struct Snapshot {
    Outer outer; Engine engine; PredictorControl predictor; adx_header::DecoderState header;
    LoopState loop; ReadyState ready;
    source::Snapshot source; pcm::Snapshot pcm;
    Phase phase{Phase::idle}; std::int32_t sample_limit{-1}; std::uint32_t odd_result{};
    bool stopped{}, fault{}, source_batch_held{}, pcm_write_held{};
    Status last_error{Status::completed};
    std::int32_t service_divisor{60};
};
enum class Notice { ahx_header, rejected_header, repeat_padding_short, format,
    frequency, channels, pitch, pan_left, pan_right, play };
struct Hooks {
    void* context{};
    void (*guard)(void*, std::uint32_t ring, bool entering) noexcept {};
    void (*notice)(void*, Notice, std::int32_t value, const Snapshot&) noexcept {};
    void (*pcm)(void*, std::uint32_t channel, const pcm::View&, const Snapshot&) noexcept {};
    void (*target)(void*, const source::TargetObservation&, const Snapshot&) noexcept {};
};
struct Config {
    source::Config source_config{.capacity=source::encoded_capacity, .threshold=source::encoded_capacity,
        .maximum_request_bytes=source::encoded_capacity, .maximum_sectors=4, .retry_limit=2};
    std::uint32_t channels{1}; bool downmix{}, loop_enabled{}, seamless_enabled{};
    adx_header::Key configured_key{};
    std::int32_t service_divisor{60};
    std::int16_t pitch_offset{}; std::array<std::int16_t, 2> pans{};
    source::CapacityProfile source_capacity{source::CapacityProfile::fixed_8k};
};
struct Bootstrap {
    source::PreparedPrefix source;
    std::int32_t pcm_cursor{}, queued_pcm_bytes{};
};
struct Identity;
class Request final {
public: Request() = default;
private:
    friend class StreamWindowOwner;
    std::shared_ptr<const Identity> identity_;
};

// One source/decoder/PCM control graph. No independent mutable source alias
// escapes; workers touch private backend results only. All callers, shared key
// contexts and observer views require external serialization. Destruction is
// emergency control-thread backend teardown, not a successful ordinary retire.
class StreamWindowOwner final : public adxt_playback::Pcm {
public:
    StreamWindowOwner(Config, std::shared_ptr<const resources::ByteView>,
        std::unique_ptr<source::Backend>, std::shared_ptr<adx_header::KeyContext>,
        Hooks = {}, Bootstrap = {});
    ~StreamWindowOwner() override;
    StreamWindowOwner(const StreamWindowOwner&) = delete;
    StreamWindowOwner& operator=(const StreamWindowOwner&) = delete;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    adxt_playback::Status data_bytes(std::uint32_t, std::uint32_t&) noexcept override;
    adxt_playback::Padding silence(std::uint32_t) noexcept override;
    [[nodiscard]] Request request() const noexcept;
    // Scheduled decoder entry: retries a deferred header, decodes active data,
    // or remains inactive. No implicit source poll or RNA reconfiguration.
    [[nodiscard]] Status service(const Request&) noexcept;
    [[nodiscard]] Status service_header() noexcept;
    [[nodiscard]] Status configure_ready() noexcept;
    [[nodiscard]] Status service_decode(const Request&) noexcept;
    [[nodiscard]] source::ServiceResult service_source() noexcept;
    // Changes the input to the next ready configuration, not an active request.
    [[nodiscard]] Status set_service_divisor(std::int32_t) noexcept;
    [[nodiscard]] Status set_loop_enabled(bool) noexcept;
    [[nodiscard]] Status set_source_paused(std::uint8_t) noexcept;
    [[nodiscard]] Status request_source_stop() noexcept;
    [[nodiscard]] pcm::ReadResult borrow_pcm(std::int32_t bytes) noexcept;
    [[nodiscard]] Status finish_pcm(pcm::ReadLease&) noexcept;
    [[nodiscard]] Status stop_decode() noexcept;
    [[nodiscard]] Status retire_on_control_thread() noexcept;
    [[nodiscard]] Status read_pcm_backing(std::uint32_t, std::span<std::uint8_t>) const noexcept;
private:
    class Scope;
    Config config_; Hooks hooks_;
    std::shared_ptr<adx_header::KeyContext> keys_;
    std::shared_ptr<Identity> identity_;
    pcm::Store pcm_;
    adxt_playback::StorePcm padding_;
    bool padding_active_{};
    std::vector<std::uint8_t> encoded_;
    std::array<std::uint8_t, 4096> header_bytes_{};
    std::array<std::int16_t, adx_workspace::maximum_pcm_samples_per_plane> left_{}, right_{};
    std::unique_ptr<source::SharedEncodedSource> source_;
    std::optional<source::WindowLink> link_;
    std::optional<source::ReadBatch> input_;
    std::optional<pcm::WriteLease> output_;
    Outer outer_; Engine engine_; PredictorControl predictor_;
    adx_header::DecoderState header_; LoopState loop_; ReadyState ready_;
    source::HeaderGeometry last_valid_geometry_;
    Phase phase_{Phase::idle}; Status last_error_{Status::completed};
    std::uint32_t odd_{};
    bool busy_{}, stopped_{}, fault_{}, normal_input_get_{}, normal_output_get_{};
    static void source_enter(void*) noexcept;
    static void source_leave(void*) noexcept;
    static void source_error(void*, std::int32_t) noexcept;
    static void source_target(void*, const source::TargetObservation&) noexcept;
    static void pcm_guard(void*, std::uint32_t, bool) noexcept;
    static void pcm_publication(void*, std::uint32_t, const pcm::View&) noexcept;
    void notice(Notice, std::int32_t = 0) noexcept;
    [[nodiscard]] Status fail(Status) noexcept;
    [[nodiscard]] bool disarm() noexcept;
    [[nodiscard]] bool sync_geometry() noexcept;
    [[nodiscard]] bool numeric_admission() const noexcept;
    [[nodiscard]] Status header_impl() noexcept;
    [[nodiscard]] Status ready_impl() noexcept;
    [[nodiscard]] Status limit_impl() noexcept;
    [[nodiscard]] Status seamless_impl() noexcept;
    [[nodiscard]] Status decode_impl() noexcept;
    [[nodiscard]] bool borrow_one(std::int32_t, bool normal) noexcept;
    [[nodiscard]] bool finish_input(source::FinishPlan) noexcept;
    void set_request_size(std::int32_t) noexcept;
    void reset_decoder() noexcept;
};
} // namespace reo::native::adx_window::service_r4
