#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

namespace reo::native::lsc_queue {
inline constexpr std::size_t slots = 16, maximum_name_bytes = 1024;
class Name final {
public:
    // Copy into sealed storage; callers cannot retain a mutable backing alias.
    [[nodiscard]] static std::shared_ptr<const Name> prepare(std::string_view);
    [[nodiscard]] std::string_view bytes() const noexcept { return value_; }
private:
    explicit Name(std::string_view value) : value_(value) {}
    const std::string value_;
};
struct Range { std::uint32_t parent{}, first_sector{}, sectors{}; };
struct Entry { std::shared_ptr<const Name> name; Range range; };
struct Record { std::uint32_t sequence{}, checksum{}; Entry entry; std::uint32_t status{}, progress{}; };
enum class Error { invalid_argument, invalid_ordinal, missing_sequence, invalid_minimum, missing_file };
class Errors {
public:
    virtual ~Errors() = default;
    virtual void report(Error) noexcept = 0;
};
class EmptyNotification {
public:
    virtual ~EmptyNotification() = default;
    virtual void notify() noexcept = 0;
};
// This control port does not itself prove file identity or async worker lifetime.
// Implementations must retain their lower source and must not reenter the queue.
class LowerFile {
public:
    virtual ~LowerFile() = default;
    [[nodiscard]] virtual bool present() const noexcept = 0;
    virtual void stop_before_open() noexcept = 0;
    virtual void close_before_open() noexcept = 0;
    virtual void open_range(const Entry&) noexcept = 0;
    virtual void set_limit(std::uint32_t) noexcept = 0;
    virtual void thresholds(std::uint32_t minimum, std::uint32_t capacity) noexcept = 0;
    virtual void position(std::uint32_t) noexcept = 0;
    virtual void start() noexcept = 0;
    virtual void stop_async() noexcept = 0;
    [[nodiscard]] virtual std::int32_t state() noexcept = 0;
    [[nodiscard]] virtual std::uint32_t progress_sectors() noexcept = 0;
};
struct Config {
    std::uint32_t capacity_bytes{8192};
    // Validated, empty initial cursor for independent rollover comparisons.
    std::uint32_t initial_slot{}, previous_sequence{};
};
struct Snapshot {
    std::array<Record, slots> records;
    std::uint8_t state{}, transferring{}, repeat{}, paused{};
    std::uint32_t minimum{}, capacity{}, tail{}, head{}, count{}, limit{}, extra{};
    bool file_present{}, servicing{};
};
enum class Service { completed, busy };
// External serialization. Notification callbacks may mutate control/queue APIs,
// including enqueue/start/stop; nested service refuses before any effects.
class Queue final {
public:
    Queue(Config, std::shared_ptr<LowerFile>, std::shared_ptr<EmptyNotification>, std::shared_ptr<Errors>);
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;
    [[nodiscard]] std::int32_t enqueue(Entry) noexcept;
    void clear() noexcept;
    void start() noexcept;
    void stop() noexcept;
    void pause(std::int32_t) noexcept;
    void repeat(std::int32_t) noexcept;
    void minimum(std::int32_t) noexcept;
    [[nodiscard]] Service service() noexcept;
    [[nodiscard]] std::int32_t ordinal(std::int32_t) noexcept;
    [[nodiscard]] std::shared_ptr<const Name> name(std::uint32_t sequence) noexcept;
    [[nodiscard]] std::int32_t status(std::uint32_t sequence) noexcept;
    [[nodiscard]] std::uint32_t progress(std::uint32_t sequence) noexcept;
    [[nodiscard]] Snapshot snapshot() const noexcept;
private:
    std::array<Record, slots> records_{};
    std::shared_ptr<LowerFile> file_;
    std::shared_ptr<EmptyNotification> notification_;
    std::shared_ptr<Errors> errors_;
    std::uint8_t state_{}, transferring_{}, repeat_{}, paused_{};
    std::uint32_t minimum_{}, capacity_{}, tail_{}, head_{}, count_{}, limit_{}, extra_{};
    bool servicing_{};
    [[nodiscard]] const Record* find(std::uint32_t) noexcept;
    void start_head() noexcept;
    void poll_head() noexcept;
    void retire_head() noexcept;
};
}
