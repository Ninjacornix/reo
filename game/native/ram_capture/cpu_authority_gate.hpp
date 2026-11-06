#pragma once
#include <array>
#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <mutex>
#include <thread>

namespace reo::native::ram_capture {
// Conservative first profile: any graphics Service attempt makes that backing
// permanently ineligible for CPU capture in this process. No opaque readback,
// pending-operation inspection, GPU synchronization or guest lock is supplied.
enum class Status { ok, invalid_backing, capacity, graphics_owned, self_wait };
inline constexpr std::size_t maximum_backings=16, maximum_groups=16;
class Coordinator;
// Thread-confined synchronous copy scope: acquire, move/use and release on the
// same thread. It is not an asynchronous writer/job lease.
class CpuGroup final {
public:
    CpuGroup()=default;
    CpuGroup(CpuGroup&&) noexcept;
    CpuGroup& operator=(CpuGroup&&) noexcept;
    ~CpuGroup();
    CpuGroup(const CpuGroup&)=delete;
    CpuGroup& operator=(const CpuGroup&)=delete;
    explicit operator bool()const noexcept{return owner_!=nullptr;}
    void release() noexcept;
private:
    friend class Coordinator;
    Coordinator* owner_{};
    std::size_t backing_{},slot_{};
    std::uint64_t generation_{};
};
class GraphicsActivity final {
public:
    GraphicsActivity()=default;
    GraphicsActivity(GraphicsActivity&&) noexcept;
    GraphicsActivity& operator=(GraphicsActivity&&) noexcept;
    ~GraphicsActivity();
    GraphicsActivity(const GraphicsActivity&)=delete;
    GraphicsActivity& operator=(const GraphicsActivity&)=delete;
    explicit operator bool()const noexcept{return owner_!=nullptr;}
    void release() noexcept;
private:
    friend class Coordinator;
    Coordinator* owner_{};
    std::size_t backing_{};
};
template<class T>struct Result {Status status;T value;};
struct Observation {bool known{},graphics_ever{};std::uint32_t cpu_groups{},graphics_waiting{},graphics_active{};};
// Outlive every token and call. Fixed metadata, no dynamic allocation. One CPU
// group covers ALL related copies; release it before decoding/provider calls.
// A group does not retain RAM or establish caller/guest/CD writer authority.
class Coordinator final {
public:
    Coordinator()=default;
    Coordinator(const Coordinator&)=delete;
    Coordinator& operator=(const Coordinator&)=delete;
    [[nodiscard]] Result<CpuGroup> try_cpu_group(const void* backing) noexcept;
    // Graphics construction only, outside guest/RPC/source/protocol locks.
    // Refuses a same-thread wait; otherwise waits only existing bounded copies.
    // Declare the returned guard before ALL RAM-affecting Service fields so it
    // dies last, after worker/device work has actually retired.
    [[nodiscard]] Result<GraphicsActivity> begin_graphics(const void* backing);
    [[nodiscard]] Observation observe(const void* backing)const noexcept;
private:
    struct Slot {std::thread::id thread;std::uint64_t generation{};bool used{};};
    struct Entry {
        const void* backing{};
        std::array<Slot,maximum_groups> slots{};
        std::uint32_t groups{},waiting{},graphics{};
        bool graphics_ever{};
    };
    mutable std::mutex mutex_;
    std::condition_variable changed_;
    std::array<Entry,maximum_backings> entries_{};
    std::size_t find_or_create(const void*) noexcept;
    void release_cpu(std::size_t,std::size_t,std::uint64_t) noexcept;
    void release_graphics(std::size_t) noexcept;
    friend class CpuGroup;
    friend class GraphicsActivity;
};
// One app-linked instance, not a per-TU header singleton. Future runtime capture
// must separately qualify its actual graphics instrumentation/build cohort.
Coordinator& process_coordinator() noexcept;
} // namespace reo::native::ram_capture
