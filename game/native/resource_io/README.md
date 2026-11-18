# Owned asynchronous resource reads

`AsyncReadOwner` is an independent native payload owner. It uses a private
`ResourceSession` for exact staged reads and one joined `SerialWorker` for FIFO
execution. It has no game/runtime headers, guest addresses, environment switches,
disk-format interpretation or user callbacks. This is not a migrated DVCI/SRD
request, cancellation or completion protocol.

```cpp
using namespace reo::native::resource_io;
AsyncReadOwner owner({16, 8 * 1024 * 1024, 32 * 1024 * 1024});
auto submitted = owner.submit(immutable_view, offset, count);
if (submitted.status == SubmitStatus::accepted) {
    auto result = owner.poll(submitted.ticket);
    // pending: retain the ticket; ready: outcome owns its bytes exactly once.
    // Inspect outcome.status; failures carry no partial payload.
}
owner.shutdown();
const bool joined = owner.join();
```

All four constructor limits must be positive. Construction may throw allocation
or thread-creation exceptions. Operational refusals and read failures use typed
statuses; there is no automatic retry or guessed recovery.

A ticket holds a weak owner identity and a private nonwrapping request ID. It
cannot be serialized, forged through the API, accepted by another owner, or
resurrected when an owner's address is reused. IDs are consumed on reservation;
even a later preparation/allocation failure does not recycle one. The configured
final ID is emitted at most once, after which submissions report exhaustion.

Each preparing, queued, active or ready request retains one of `max_requests`
preallocated slots. Thus ignored ready results retain capacity and cannot grow
an unbounded completion queue. Submission reserves **twice** its requested byte
count before publishing the ticket: the owned output plus `ResourceSession`'s
temporary exact-read staging. Checked subtraction/division avoids offset, budget
and multiplication overflow. Metadata and queued callables are separately bounded
by the request count. Zero-length reads still retain a slot but reserve zero
payload bytes. A caller-consumed result owns its allocation independently and no
longer counts against this owner's budget.

`poll` transfers a ready result once. Concurrent polls have one winner; consumed
or cancelled tickets become invalid. `cancel` suppresses publication, including
an active read's eventual result. It does not interrupt provider I/O or return a
queued/active request's slot or byte reservation early. Ready cancellation frees
the buffer outside the mutex before returning its reservation. The immutable
view is retained by a private session handle until the task closes it. Its read
lease/session reference is released before result publication or slot release;
other caller references or concurrent submission preparation may still retain
the provider. Join also waits for that submission preparation to finish.

`shutdown` marks the owner closed, suppresses every outstanding result, discards
ready buffers and signals the worker to drain. Queued tasks release their views
without beginning provider reads. An already claimed active read may finish,
including its staging allocation; its result is suppressed. `shutdown` does not
wait for a blocked provider. `join` requires prior shutdown and returns `false`
otherwise. A successful join waits for worker/capture completion, concurrent
submission preparation, discarded buffers and owner-held provider release, then
closes/drains the private resource session. Concurrent joins are supported.
Caller-retained input views and consumed results are outside this lifetime.

Providers must honor `ByteView`'s immutable, nonblocking `size()` contract and
must not retain the supplied staging span after `read()` returns; their
destructors must also be finite and nonblocking. Reads may block and may reenter
`submit`, `poll`, `cancel` or `shutdown`: no provider method/destructor runs under
the owner mutex. A read running on this worker receives `false` from self-join.
Never perform a blocking join/drain, destroy the owner, or wait for work queued
behind oneself from a provider's metadata/read/destructor callback. In particular,
a metadata/destructor call on an admitting thread must not join its own still
active submission. The owner must outlive every public call. Destruction performs
shutdown/join and terminates on an unjoinable self-destruction contract violation;
it never detaches a thread that can still access its state. Providers with an
unbounded blocking read necessarily make external join/destruction wait.

Synthetic checks cover owned exact/zero-length output, positive limits and
refusals, ignored ready quota, 2x staging budget, pending/active/ready cancellation,
blocked-provider shutdown, release before join, failures after partial writes,
short reads and exceptions, ticket/owner identity and address reuse, finite ticket
exhaustion, arithmetic extremes, provider reentry/self-join and concurrent polling
and submission/stop races. They access no actual disk/import/game/process.

Standalone CMake build (also usable as a subdirectory after the dependency targets):

```powershell
cmake -S game/native/resource_io -B build-native-sjuni/resource-io-cmake -G Ninja `
  -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe
cmake --build build-native-sjuni/resource-io-cmake
ctest --test-dir build-native-sjuni/resource-io-cmake --output-on-failure
```

Direct GCC/LLVM checks use only `async_read_owner.cpp`, its tests,
`../resources/resource_session.cpp` and `../tasks/serial_worker.cpp`, with C++20,
threads and `-Wall -Wextra -Wpedantic -Werror`. No parent game build is required.
