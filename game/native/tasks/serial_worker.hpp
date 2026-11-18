#pragma once

#include <atomic>
#include <condition_variable>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <mutex>
#include <thread>
#include <vector>

namespace reo::native::tasks {

using Task = std::function<void()>;
using Publish = void (*)(void*) noexcept;

enum class SubmitStatus { accepted, full, stopping };
enum class StopMode { drain, cancel_pending };

// One owned thread and a fixed pending-task ring. No global worker/service.
// The owner must outlive all method calls and must never be destroyed by its
// own task or capture destructor. Task/capture destructors must not throw.
class SerialWorker final {
  public:
    using Task = reo::native::tasks::Task;
    using Publish = reo::native::tasks::Publish;

    explicit SerialWorker(std::size_t pending_capacity);
    ~SerialWorker() noexcept;
    SerialWorker(const SerialWorker&) = delete;
    SerialWorker& operator=(const SerialWorker&) = delete;
    SerialWorker(SerialWorker&&) = delete;
    SerialWorker& operator=(SerialWorker&&) = delete;

    // Build the function/captures before calling. The preallocated queue only
    // swaps the already-built Task outside the queue mutex. Rejected task
    // destruction is also outside it. On acceptance publish runs under that mutex before the
    // worker can claim the task; it must be short, nonblocking and nonreentrant.
    // Callable move/swap cleanup on a submitting thread must not join/destroy
    // this worker or wait for its queued work: its own reserved head is not yet
    // prepared, so that would wait for this submit to finish from inside itself.
    [[nodiscard]] SubmitStatus submit(Task task, Publish publish = nullptr,
                                      void* publication_context = nullptr);

    // Stop is monotonic: cancel_pending can upgrade drain, never the reverse.
    // Cancellation affects queued tasks, not one already claimed by the worker.
    // Pending captures are released by the worker outside the queue mutex.
    void request_stop(StopMode mode);

    // Request stop first, otherwise this waits for a future stop request.
    // Concurrent joins serialize. Self-join returns false before acquiring the
    // join mutex, including while another thread is already joining this worker.
    // A true return means all active/canceled queued captures have been released.
    [[nodiscard]] bool join();
    [[nodiscard]] std::uint64_t failed_tasks() const noexcept;

  private:
    static std::size_t checked_capacity(std::size_t capacity);
    void run() noexcept;

    const std::size_t capacity_;
    // One extra task slot belongs to the active task. The pending ring contains
    // indices, so no Task move, swap or destruction happens under queue_mutex_.
    std::vector<Task> slots_;
    std::vector<std::size_t> pending_, free_slots_;
    std::vector<unsigned char> prepared_;
    std::size_t free_count_;
    std::size_t head_{0}, tail_{0}, count_{0};
    bool stopping_{false}, cancel_pending_{false};
    std::mutex queue_mutex_;
    std::condition_variable ready_;
    std::mutex join_mutex_;
    std::atomic<std::uint64_t> failed_{0};
    std::thread thread_;
    // Per-thread identity only, not a worker/service singleton. Unlike storing a
    // thread::id this remains correct after an exited thread's id is reused.
    static thread_local const SerialWorker* running_worker_;
};

} // namespace reo::native::tasks
