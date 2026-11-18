# Bounded serial worker

`SerialWorker` owns one joinable thread and a fixed, preallocated pending-task
ring. It has no game/runtime headers and creates no global worker. This is an
independent lifecycle component; this directory does not install it into the game.

```cpp
#include "serial_worker.hpp"
using namespace reo::native::tasks;

SerialWorker worker(16); // Positive pending capacity; excludes the active task.
Task task = [] { /* synthetic or independently owned work */ };
const auto result = worker.submit(std::move(task));
// result: SubmitStatus::accepted, ::full, or ::stopping.
worker.request_stop(StopMode::drain);
const bool joined = worker.join();
```

The namespace exposes `Task = std::function<void()>`,
`Publish = void (*)(void*) noexcept`, `SubmitStatus`, and `StopMode`.
`SerialWorker` also aliases `Task` and `Publish`. Its public operations are:

- `explicit SerialWorker(std::size_t pending_capacity)`; zero throws
  `std::invalid_argument`. Allocation/thread-creation failures propagate normally.
- `SubmitStatus submit(Task task, Publish publish = nullptr, void* context = nullptr)`.
- `void request_stop(StopMode)` with `drain` or `cancel_pending`.
- `bool join()`; returns false for self-join and true after successful external join.
- `std::uint64_t failed_tasks() const noexcept`.

Construct tasks and their provider captures before admission, and move the built
task into `submit` to avoid a caller-side `std::function` copy. Admission reserves
a preallocated slot/index under the mutex, swaps in the task outside the mutex,
then publishes and marks the slot prepared under the mutex. The worker waits for
the first reserved entry to be prepared, preserving admission order even if a
later submit finishes preparing sooner. The reservation is the admission point:
a concurrent stop includes it, and join waits for it to finish preparing. This
also keeps moved-from callable destruction outside the mutex on standard
libraries which move small targets during `std::function::swap`. No queue storage
is allocated during submit. Rejected task parameters are destroyed after
unlocking. Capacity includes reserved/preparing entries, while one further task
may already have been claimed by the worker. The constructor allocates one extra
task slot for that active task, alongside the fixed pending-index ring/free list.
Callable move/swap cleanup on a thread preparing its own submission must not
join or destroy this worker, or wait for work behind its reservation. That would
wait for the enclosing submit to finish from inside itself; it is not worker
self-join and `join()` does not detect it. Nonblocking reentrant submission/stop
is permitted outside the queue mutex. The caller must also keep the worker alive
until its submit call returns.

On acceptance, the optional publication callback runs under the queue mutex
before the worker can claim the task. It runs exactly once, and never runs on
`full` or `stopping`. It must be short, nonblocking, nonreentrant, and nonthrowing;
in particular it must not call worker methods or destroy captured providers.
The context is borrowed only for that call. A task can start before `submit`
returns, so publish all required externally visible admission state in that
callback. The worker runs tasks in admission order.

Stop rejects further admission. `drain` runs all admitted tasks; `cancel_pending`
skips queued task bodies while allowing an already claimed task to finish.
Cancellation is sticky: a later drain request cannot undo it. The worker itself
releases canceled captures after any active task, outside the queue mutex;
`request_stop` does not wait for capture release. Completed/throwing task captures
are also released outside the queue mutex, before it claims another task. Capture
destructors may call worker methods subject to the lifetime/self-join rules and
the producer-side preparation restriction above. Task invocation exceptions,
including an empty `std::function` invocation,
are contained and counted; later tasks still run. The counter saturates at
`UINT64_MAX`.

Request stop before joining, otherwise join waits for a future stop request.
Concurrent external joins serialize outside the queue mutex. A successful join
includes completion and release of active and canceled task/provider captures.
Self-join is rejected before locking the join mutex, including when another
thread is already joining. A thread-local identity marker avoids depending on
reusable operating-system thread IDs; it does not own a worker/service.

The owner must outlive all concurrent method calls. Destruction requests pending
cancellation and joins; it can therefore wait for an active task indefinitely if
that task never finishes. Never destroy the worker from its own task or capture
destructor: that ownership violation terminates rather than detaching a thread
which still accesses the destroyed object. Capture destructors must not throw.
These are ownership requirements, not an interruption mechanism for active work.

## Standalone validation

From the repository root, using GCC and Ninja on PATH:

```text
cmake -S game/native/tasks -B build-function-index/native-tasks-cmake -G Ninja -DCMAKE_CXX_COMPILER=g++
cmake --build build-function-index/native-tasks-cmake
ctest --test-dir build-function-index/native-tasks-cmake --output-on-failure
```

Or compile the independent component and tests directly:

```text
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror -pthread -O2 game/native/tasks/serial_worker.cpp game/native/tasks/serial_worker_tests.cpp -o build-function-index/native-tasks-tests/serial_worker_tests.exe
```

The synthetic checks cover FIFO across ring wrap, full/stopped rejection without
publication, publication visibility, no ordinary submitting-thread allocation
during admission of prebuilt tasks, rejected/completed/canceled capture reentry
outside the queue lock, cancellation escalation, active lifetime, concurrent
joiners, self-join while an external join waits, task exceptions followed by
successful work, concurrent producers racing stop, and destructor stop/join.
CTest bounds the run to 30 seconds to expose deadlocks. These checks do not run
the game, validate its adapter integration, benchmark latency, or replace a race
detector. No active-task interruption is claimed.
