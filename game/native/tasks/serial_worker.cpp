#include "serial_worker.hpp"

#include <exception>
#include <limits>
#include <numeric>
#include <stdexcept>

namespace reo::native::tasks {

thread_local const SerialWorker* SerialWorker::running_worker_ = nullptr;

std::size_t SerialWorker::checked_capacity(std::size_t capacity) {
    if (capacity == 0)
        throw std::invalid_argument("SerialWorker pending capacity must be positive");
    if (capacity == std::numeric_limits<std::size_t>::max())
        throw std::length_error("SerialWorker capacity leaves no active-task slot");
    return capacity;
}

SerialWorker::SerialWorker(std::size_t pending_capacity)
    : capacity_(checked_capacity(pending_capacity)), slots_(capacity_ + 1), pending_(capacity_),
      free_slots_(capacity_ + 1), prepared_(capacity_ + 1), free_count_(capacity_ + 1) {
    std::iota(free_slots_.begin(), free_slots_.end(), std::size_t{0});
    thread_ = std::thread([this] {
        running_worker_ = this;
        run();
        running_worker_ = nullptr;
    });
}

SerialWorker::~SerialWorker() noexcept {
    request_stop(StopMode::cancel_pending);
    // Destruction by this worker cannot safely detach a thread still using this
    // object. It violates the explicit ownership/lifetime contract.
    if (!join())
        std::terminate();
}

SubmitStatus SerialWorker::submit(Task task, Publish publish, void* publication_context) {
    std::size_t slot = 0;
    {
        std::lock_guard lock(queue_mutex_);
        if (stopping_)
            return SubmitStatus::stopping;
        if (count_ == capacity_)
            return SubmitStatus::full;
        // Reserve admission/order before touching the callable. A reserved head
        // blocks later prepared entries, preserving FIFO across concurrent
        // submits. A concurrent stop includes this accepted reservation.
        slot = free_slots_[--free_count_];
        prepared_[slot] = 0;
        pending_[tail_] = slot;
        tail_ = tail_ + 1 == capacity_ ? 0 : tail_ + 1;
        ++count_;
    }
    // Some standard libraries move/destroy small callable objects in swap.
    // Keep even moved-from target destruction outside the queue mutex.
    slots_[slot].swap(task);
    {
        std::lock_guard lock(queue_mutex_);
        if (publish)
            publish(publication_context);
        prepared_[slot] = 1;
    }
    ready_.notify_one();
    return SubmitStatus::accepted;
}

void SerialWorker::request_stop(StopMode mode) {
    {
        std::lock_guard lock(queue_mutex_);
        stopping_ = true;
        if (mode == StopMode::cancel_pending)
            cancel_pending_ = true;
    }
    ready_.notify_one();
}

bool SerialWorker::join() {
    // Checking the thread-local marker does not race join modifying thread_,
    // and checking before the mutex avoids deadlock against an external join.
    if (running_worker_ == this)
        return false;
    std::lock_guard join_lock(join_mutex_);
    if (thread_.joinable())
        thread_.join();
    return true;
}

std::uint64_t SerialWorker::failed_tasks() const noexcept {
    return failed_.load(std::memory_order_relaxed);
}

void SerialWorker::run() noexcept {
    for (;;) {
        std::size_t slot = 0;
        bool execute = false;
        {
            std::unique_lock lock(queue_mutex_);
            ready_.wait(lock, [this] {
                return (count_ != 0 && prepared_[pending_[head_]] != 0) ||
                       (stopping_ && count_ == 0);
            });
            if (count_ == 0)
                return;
            slot = pending_[head_];
            head_ = head_ + 1 == capacity_ ? 0 : head_ + 1;
            --count_;
            execute = !cancel_pending_;
        }
        {
            if (execute) {
                try {
                    slots_[slot]();
                } catch (...) {
                    // Only the worker writes this counter; external readers are
                    // atomic. Saturate rather than wrapping a long-lived count.
                    const auto failed = failed_.load(std::memory_order_relaxed);
                    if (failed != std::numeric_limits<std::uint64_t>::max())
                        failed_.store(failed + 1, std::memory_order_relaxed);
                }
            }
            Task finished;
            slots_[slot].swap(finished);
            // Finished/canceled captures die here, before this slot is made
            // available. Both swap and destruction are outside the queue lock.
        }
        {
            std::lock_guard lock(queue_mutex_);
            free_slots_[free_count_++] = slot;
        }
    }
}

} // namespace reo::native::tasks
