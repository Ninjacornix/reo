#pragma once
#include "../adx_sequence/clip.hpp"
#include "../adxt_shared_source/shared_source.hpp"
#include "../lsc_queue/queue.hpp"
#include <array>
#include <limits>

namespace reo::native::adxt_phased_player { class Player; }
namespace reo::native::adxt_control_session { class Session; }
namespace reo::native::adxt_lsc_input {
inline constexpr std::uint32_t byte_domain = 0x7ffff800;
inline constexpr std::uint32_t sample_domain = 0x7fffffe0;
struct Config {
    std::uint32_t channels{1}, frequency{48000}, catalogue_entries{8192}, journal_entries{8};
    std::uint32_t encoded_capacity{8192};
};
enum class Status { completed, closed, busy, invalid_asset, invalid_key, capacity, numeric_limit,
    unsupported_profile, no_memory, source_failure, already_bound, fault };
struct Identity;
class AssetKey final {
public: AssetKey() = default;
private:
    friend class Input;
    std::weak_ptr<const Identity> identity_;
    std::uint32_t slot_{std::numeric_limits<std::uint32_t>::max()};
};
struct Registration { Status status{Status::invalid_asset}; AssetKey key; };
struct EntryResult { Status status{Status::invalid_key}; std::int32_t sequence{-1}; };
class Input;
class Notification {
public:
    virtual ~Notification() = default;
    // May enqueue prepared keys or change queue controls. No nested service,
    // source publication, worker joins or owner destruction is admitted here.
    virtual void empty(Input&) noexcept = 0;
};
struct Journal {
    std::uint32_t byte_begin{}, byte_end{}, sample_begin{}, sample_end{}, asset{};
};
struct Snapshot {
    lsc_queue::Snapshot queue;
    std::array<Journal,16> journal;
    std::uint32_t journal_entries{}, registered_assets{}, planned_bytes{}, planned_samples{},
        published_bytes{}, consumed_bytes{}, decoder_base{}, file_state{}, file_progress{}, preparing_assets{};
    std::uint64_t accepted_reads{}, completed_reads{}, unavailable_reads{}, notifications{}, diagnostics{};
    Status error{Status::completed};
    bool bound{}, started{}, decoder_ended{}, closing{}, joined{}, abandoned{};
};
enum class Header { ready, pending, invalid };
// Externally serialized control owner. The origin is a fixed virtual address
// budget, not a file-length claim; only the exclusive backend reads committed
// retained asset ranges. No caller can supply source/decoder progress.
class Input final {
public:
    [[nodiscard]] static std::shared_ptr<Input> create(Config, std::shared_ptr<Notification> = {});
    ~Input();
    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;
    [[nodiscard]] Registration register_asset(std::string_view, std::shared_ptr<const adx_sequence::Clip>,
        lsc_queue::Range = {0,0,0xfffff}) noexcept;
    [[nodiscard]] EntryResult enqueue(const AssetKey&) noexcept;
    [[nodiscard]] Status start() noexcept;
    [[nodiscard]] Status stop() noexcept;
    [[nodiscard]] Status pause(std::int32_t) noexcept;
    [[nodiscard]] Status repeat(std::int32_t) noexcept;
    // Original queue minimum semantics: signed invalid values diagnose and
    // retain the previous value. Applied to the lower file on its next open,
    // not retroactively to an already accepted read/current file.
    [[nodiscard]] Status minimum(std::int32_t) noexcept;
    // An accepted next clip being prepared on a native worker holds the decoder
    // at its header boundary instead of reporting EOF. This is not progress.
    [[nodiscard]] Status preparing_assets(std::uint32_t) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    [[nodiscard]] std::shared_ptr<const resources::ByteView> origin() const noexcept;
    [[nodiscard]] std::uint32_t channels() const noexcept;
    [[nodiscard]] std::uint32_t frequency() const noexcept;
    [[nodiscard]] std::uint32_t capacity() const noexcept;
private:
    friend class adxt_phased_player::Player;
    friend class adxt_control_session::Session;
    struct State;
    class Backend;
    explicit Input(std::shared_ptr<State>);
    std::shared_ptr<State> state_;
    [[nodiscard]] bool valid(const AssetKey&) const noexcept;
    [[nodiscard]] std::unique_ptr<adxt_refill::Backend> take_backend();
    void before_source(const adxt_shared_source::Snapshot&) noexcept;
    void after_source(const adxt_shared_source::Snapshot&, bool success) noexcept;
    void after_decoder(const adxt_shared_source::Snapshot&, std::uint32_t actual_base, bool ended) noexcept;
    [[nodiscard]] Status service_queue() noexcept;
    [[nodiscard]] Header next_header(std::uint32_t actual_base) const noexcept;
    void request_stop() noexcept;
};
}
