# Independent native SJUNI core

This C++20 library implements the admitted local linked-span queue contract. It
has no PS2Recomp, guest RAM, register, syscall, renderer, payload allocation or
payload-copy dependency. It does not redirect game functions. The temporary
bridge and its original-word comparisons are separate integration work.

`Pool` allocates a fixed metadata vector and validation scratch at construction.
Queue operations, reset, queries and snapshot import do not allocate. Snapshot
export can allocate in the caller's destination vector; reserve/reuse it when
exporting from hooks. Borrowed payload storage is identified only by
`Span { uint64_t region; int64_t offset; int32_t bytes; }` and is never read.

The public interface is [sjuni.hpp](sjuni.hpp); implementation is
[sjuni.cpp](sjuni.cpp). Native node IDs are indices `0..capacity-1`; the null link
is `no_node == UINT32_MAX`. Four lists and the free list retain exact node order.
A whole get pushes its node to the free list and keeps that node's stale span.
The guest node's untouched external word is not core state: the bridge must
preserve it while mirroring links and descriptors.

## Admitted domain

- Capacity is a positive 32-bit signed count. Zero/negative legacy work-size
  behavior is outside this constructor's admitted domain.
- Every node belongs exactly once to one of five acyclic lists. Import validates
  the entire snapshot before publishing it, rejects wrong capacity/invalid links,
  duplicate or missing nodes, and retains the previous logical state on rejection.
- Queued spans have nonzero region, positive signed length and a representable
  signed 64-bit end offset. Stale free-node spans can contain any native values.
- Region zero denotes a null payload. Ignored null/nonpositive put/unget spans
  follow original admission order; invalid selector reports `-3` first.
- Offset/length arithmetic must be representable. Signed zero and negative get
  requests are supported when the resulting offset and positive remainder fit;
  a negative returned prefix length is not silently clamped.
- Adjacent merge requires the same region ID and equal numeric end/start offsets.
  The bridge must establish coherent regions for original numeric adjacency,
  including IOP storage. Cross-region original adjacency and guest address wrap
  are not automatically equivalent. Region extents and borrowed lifetime remain
  the caller/bridge's responsibility.
- The Pool and referenced input/output objects remain alive during all enclosing
  calls. Direct output overlap with internal nodes is not exposed by this API.
  Imported snapshots cannot invent unsupported original pointer alias semantics.
- External scheduling provides exclusion when needed. No internal mutex or
  thread-local ownership emulates the original priority handoff.

Byte sums intentionally wrap at 32 bits using unsigned arithmetic and bit
conversion. Queries have no synchronization hooks. Invalid selectors for the
originally checked methods synchronously report `-3`; the originally unchecked
node-count selector is instead an explicit unsupported admission. No queue
operation fabricates an original success/error return register.

## Callbacks, preflight and fallback

`Hooks` contains a context and plain enter/leave/error function pointers. These
callbacks are synchronous, may reenter the same Pool and may import a valid new
snapshot. They must return normally; C++ exception unwinding, destruction of the
active Pool and concurrent unsynchronized access are outside the admitted policy.

Guard placement follows the original methods: valid get always enters/leaves;
put/unget enter only after initial selector/positive/non-null admission; invalid
selector callbacks occur outside; exhaustion callbacks occur inside. Exhaustion
does not retry after a reentrant callback supplies a node. Invalid get clears its
output after the callback; invalid availability initializes its output before
the callback and does not clear it again afterward.

`check_get`, `check_put` and `check_unget` perform pure preflight. An unsupported
preflight result changes no logical state/output and invokes no hooks or errors.
The executing methods perform this same check before entry, so the bridge can
keep unsupported streams on their original implementation without prior effects.
Input put/unget spans are reread after enter to preserve admitted hook mutation.

An arbitrary enter callback can invalidate earlier arithmetic admission. The
executing methods detect this after entry, leave the section and return
`callback_contract_violation`. **Hooks already ran: this result never permits
automatic fallback to an older original object.** Hook mutations remain visible,
while the outer operation has made no queue/output mutation. The integration
must prove that installed hooks preserve admission, or retain that instance on
the original path before invoking it. Error/leave reentry has no subsequent queue
arithmetic in the enclosing operation.

`Result::completed` describes completion of the native control path, including
ignored spans or original error callbacks. It is not a guest boolean success ABI.

## Standalone build and tests

The local implementation was compiled with MinGW GCC in release and assertion
debug configurations, with warnings treated as errors:

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror -O2 `
    game/native/sjuni/sjuni.cpp game/native/sjuni/sjuni_tests.cpp `
    -o build-native-sjuni/sjuni_tests.exe
./build-native-sjuni/sjuni_tests.exe

g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror -O0 -g -D_GLIBCXX_ASSERTIONS `
    game/native/sjuni/sjuni.cpp game/native/sjuni/sjuni_tests.cpp `
    -o build-native-sjuni/sjuni_tests_debug.exe
./build-native-sjuni/sjuni_tests_debug.exe
```

The static library can be built separately:

```powershell
g++ -std=c++20 -O2 -c game/native/sjuni/sjuni.cpp -o build-native-sjuni/sjuni.o
ar rcs build-native-sjuni/libreo_native_sjuni.a build-native-sjuni/sjuni.o
g++ -std=c++20 game/native/sjuni/sjuni_tests.cpp `
    build-native-sjuni/libreo_native_sjuni.a -o build-native-sjuni/sjuni_library_tests.exe
./build-native-sjuni/sjuni_library_tests.exe
```

Alternatively, [CMakeLists.txt](CMakeLists.txt) defines the static library and
CTest target:

```powershell
cmake -S game/native/sjuni -B build-native-sjuni/cmake
cmake --build build-native-sjuni/cmake
ctest --test-dir build-native-sjuni/cmake --output-on-failure
```

The eleven focused synthetic groups check queue/free order, stale descriptors,
all four queues, modes 0/1/2/255, positive/zero/negative requests, adjacency and
region separation, exhausted-pool merge, synchronous error/output ordering,
reentry without retry, snapshot validation/roundtrip, unsupported arithmetic with
no effects, changed enter inputs, post-enter contract violation, wrapped sums and
zero queue/import/reset allocations over 10,000 sequences. These tests use
explicit expected contracts, not an imported copy of the implementation. They
are not original-execution parity, real-consumer integration or performance
evidence. Native bridge/oracle validation remains a separate requirement before
any game redirection.
