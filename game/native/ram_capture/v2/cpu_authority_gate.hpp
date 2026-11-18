#pragma once
#include <array>
#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <mutex>
#include <thread>

namespace reo::native::ram_capture::v2 {
// Versioned cooperating-writer extension. This gate is neither RAM lifetime
// ownership nor proof that every noncooperating CPU/GPU/device writer is closed.
enum class Status {ok,invalid_backing,capacity,graphics_owned,writer_busy,self_wait,unavailable};
inline constexpr std::size_t maximum_backings=16,maximum_groups=16,maximum_writers=16;
class Coordinator;
class CpuGroup final {
public:
    CpuGroup()=default;CpuGroup(CpuGroup&&)noexcept;CpuGroup& operator=(CpuGroup&&)noexcept;~CpuGroup();
    CpuGroup(const CpuGroup&)=delete;CpuGroup& operator=(const CpuGroup&)=delete;
    explicit operator bool()const noexcept{return owner_!=nullptr;}void release()noexcept;
private:
    friend class Coordinator;Coordinator* owner_{};std::size_t backing_{},slot_{};std::uint64_t generation_{};
};
class CpuWriter final {
public:
    CpuWriter()=default;CpuWriter(CpuWriter&&)noexcept;CpuWriter& operator=(CpuWriter&&)noexcept;~CpuWriter();
    CpuWriter(const CpuWriter&)=delete;CpuWriter& operator=(const CpuWriter&)=delete;
    explicit operator bool()const noexcept{return owner_!=nullptr;}void release()noexcept;
private:
    friend class Coordinator;Coordinator* owner_{};std::size_t backing_{},slot_{};std::uint64_t generation_{};
};
class GraphicsActivity final {
public:
    GraphicsActivity()=default;GraphicsActivity(GraphicsActivity&&)noexcept;GraphicsActivity& operator=(GraphicsActivity&&)noexcept;~GraphicsActivity();
    GraphicsActivity(const GraphicsActivity&)=delete;GraphicsActivity& operator=(const GraphicsActivity&)=delete;
    explicit operator bool()const noexcept{return owner_!=nullptr;}void release()noexcept;
private:
    friend class Coordinator;Coordinator* owner_{};std::size_t backing_{};
};
template<class T>struct Result {Status status;T value;};
struct Observation {bool known{},graphics_ever{};std::uint32_t cpu_groups{},graphics_waiting{},graphics_active{},writers_waiting{},writers_active{};bool cpu_capture_disabled{};std::uint32_t readers_waiting{};};
class Coordinator final {
public:
    Coordinator()=default;Coordinator(const Coordinator&)=delete;Coordinator& operator=(const Coordinator&)=delete;
    // Nonblocking apart from the short metadata mutex. One group covers the
    // complete bounded related copy. End BEFORE codecs/providers/guest callbacks.
    [[nodiscard]]Result<CpuGroup> try_cpu_group(const void*)noexcept;
    // Qualified synchronous writers only: reserve finite waiting metadata, not
    // a group, and wait behind older writer tickets/current writer. Later
    // writers cannot overtake this reader. No pin exists while waiting.
    // May hold guest/RPC ONLY if the actual bounded writer body is proven not
    // to wait on/reacquire those dependencies. Otherwise use nonblocking try.
    // Own reader/writer waits are refused; graphics/withdrawal cancel the wait.
    [[nodiscard]]Result<CpuGroup> wait_cpu_group(const void*);
    // Announce waiting before dropping the registry mutex into CV.wait. Caller
    // MUST hold no guest/RPC/source/protocol/Pad lock or dependency needed by an
    // admitted group. All groups are bounded memcpy, never asynchronous jobs.
    // No dropped input: a refused writer is an explicit owner invariant error.
    [[nodiscard]]Result<CpuWriter> begin_cpu_writer(const void*);
    // Metadata exhaustion must withdraw capture, not break working input.
    // Permanently denies ALL future groups, then drains existing copies. Caller
    // holds no dependencies needed by those copies; own-pin wait is refused
    // before effects. After success original writers may continue uncoordinated:
    // this is capture withdrawal, not a generic writer-serialization guarantee.
    [[nodiscard]]Status withdraw_cpu_capture();
    // Same sticky graphics exclusion as v1; wait for copy AND writer drain.
    // Writers remain legal while graphics is active (existing source guards
    // still apply). Declare activity before all RAM-affecting Service fields.
    [[nodiscard]]Result<GraphicsActivity> begin_graphics(const void*);
    [[nodiscard]]Observation observe(const void*)const noexcept;
private:
    struct Slot {std::thread::id thread;std::uint64_t generation{},ticket{};bool used{},waiting{};};
    struct Entry {
        const void* backing{};std::array<Slot,maximum_groups> readers{};std::array<Slot,maximum_writers> writers{};
        std::uint32_t groups{},graphics_waiting{},graphics_active{},writers_waiting{},writers_active{},readers_waiting{};std::uint64_t next_ticket{};bool graphics_ever{};
    };
    mutable std::mutex mutex_;std::condition_variable changed_;std::array<Entry,maximum_backings> entries_{};bool cpu_capture_disabled_{};
    std::size_t find_or_create(const void*)noexcept;
    void release_cpu(std::size_t,std::size_t,std::uint64_t)noexcept;
    void release_writer(std::size_t,std::size_t,std::uint64_t)noexcept;
    void release_graphics(std::size_t)noexcept;
    friend class CpuGroup;friend class CpuWriter;friend class GraphicsActivity;
};
// Outlive every call/token. No per-TU singleton and no allocation in metadata.
// Reader/writer tokens must move/use/release on the issuing thread.
Coordinator& process_coordinator()noexcept;
} // namespace reo::native::ram_capture::v2
