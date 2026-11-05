# Native read-only resource core

Status: independently built native library and synthetic contract tests. No CDVD,
FIO, CRI, decoder or game entry point has been redirected. This does not claim
that resource consumers have migrated or that PS2 dependencies have been removed.

The library contains three boundaries:

- [ByteView](byte_view.hpp): an immutable-size provider of positioned byte reads.
- [VirtualFileView](virtual_file_view.hpp): a validated snapshot backed by the
  existing `runtime/assets/virtual_afs.h` `Source`/`VirtualFile` implementation.
- [ResourceSession](resource_session.hpp): generation handles, bounded exact
  reads, provider leases, close and explicit shutdown/drain.

There are no guest addresses/registers, guest syscall wrappers, sectors, runtime headers,
environment switches, mutable global library state or automatic I/O threads.
The session uses native synchronization; synchronous reads execute on their
calling threads. The existing AFS parser/range engine is reused, not duplicated.

## View admission and lifetime

`VirtualFileView::create` requires segments sorted by virtual offset, without
overlap or wrapping/out-of-file extents. Each segment has exactly one backing:
`Source` or byte vector. File-backed offsets must fit `streamoff` and the captured
source length. Memory-backed segments start at byte zero, as in the existing
VirtualFile engine, and fit their byte vector; nonzero memory `sourceOffset` is
rejected explicitly. Holes are admitted and read as zero padding. A completely
sparse view can have a large 64-bit length without allocating its holes.

The snapshot copies segment metadata and deep-copies referenced memory buffers,
sharing each private copy across segments that originally shared that buffer.
File sources are privately reopened through the existing `Source` constructor,
with captured-size agreement checked. Private source metadata therefore cannot
be changed by later edits to the caller's Source object. Its transient/open-on-
demand setting is retained. Windows stored extended-path prefixes are converted
back to constructor input form before that reopen, since reapplying the existing
readablePath helper to its own result is not idempotent under MinGW filesystem.

**Backing file bytes must remain externally immutable for the view lifetime.**
This library neither snapshots file content nor continuously checks hashes,
filesystem identity or external hard-link mutation. Size agreement at mount is
not proof of content immutability. Callers also must not concurrently mutate the
input VirtualFile/Source metadata during view creation. Memory input is frozen
after creation; provider metadata and size must remain immutable afterward.

Creation returns `invalid_view`, `source_failure` or `no_memory` with no view on
failure. Deep-copy/mount memory is separate from the per-read limit.

## Session and read contract

Configure `max_read_bytes`, `max_handles` and the generation ceiling at session
construction; each is positive. The default maximum read is 8 MiB. Session
construction may throw for invalid configuration/allocation; operational open,
read and view-creation allocation failures use typed `no_memory` results.

`open` retains a shared immutable provider and its length. Handles contain a
slot, generation and weak session identity; they are native opaque values, not
guest/wire tokens. Close invalidates future lookups immediately. A reused slot
advances generation; after its final configured generation it retires instead
of wrapping. Retired slots still consume the configured slot budget. A handle
from a different or destroyed session cannot become valid in a new session,
even if object addresses are reused.

`read_exact` validates handle, 64-bit extent and read limit before provider I/O.
It captures a shared provider lease while holding the registry mutex, increments
the active-read count and releases that mutex. It then allocates a bounded
temporary buffer and calls the provider. Only exact successful completion copies
the bytes to the caller's destination. Every failure returns zero bytes and
leaves that destination unchanged, including provider partial writes, short
success, exceptions and temporary-buffer allocation failure. Provider
`no_memory` remains `no_memory`; other provider failures become `source_failure`.

A valid zero-length read at EOF succeeds without provider I/O or a temporary
buffer. Out-of-range empty offsets still reject. `size` returns captured metadata,
without a provider call. ByteView implementations must honor native buffer bounds,
report exact successful counts, keep size immutable/nonblocking and only write
the supplied buffer; arbitrary external side effects cannot be rolled back.

## Shutdown and concurrency

No registry mutex is held during provider reads, provider size queries or final
provider destruction. Close can complete while a previously accepted read blocks;
that read retains its original provider and can finish successfully even after
the slot is reused. Closing a handle does not cancel already accepted work.

`shutdown` refuses new work and invalidates every handle, releasing idle registry
providers outside the lock. Already accepted reads retain their leases and may
still commit exact output. `drain` waits for the active-read count to reach zero;
provider lease release finishes before that count signals zero. Use
`shutdown_and_drain` or stop submissions externally before draining; drain alone
while open is not a barrier against new work starting afterward.

Do not call drain from a provider read/destructor belonging to that same active
read; it would wait on itself. Keep the ResourceSession and caller buffers alive
until their methods finish, and coordinate destruction with outstanding callers.
Shared external ownership of a provider can outlive drain; drain releases session
read leases, not unrelated owners. No guest callbacks, asynchronous cancellation,
completion queue, mutable stream cursor or thread pool is supplied.

## Validation

Eight focused synthetic groups cover cross-segment/file/memory/gap reads, frozen
metadata/bytes, malformed/overlapping/nonwrapping extents, 64-bit sparse/EOF edges,
bounded requests, provider partial/short/throwing failures, deterministic allocation
failure, generation reuse/retirement/session identity, concurrent close/reuse and
shutdown/drain while a fake provider is blocked. Weak lifetime checks verify that
an in-flight provider remains alive until the accepted read releases it.
Windows synthetic file-backed views also use Unicode filenames.

The direct GCC 15.2 build passed with warnings treated as errors:

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic -Werror -O1 -pthread -I . `
    game/native/resources/resource_session.cpp `
    game/native/resources/virtual_file_view.cpp `
    game/native/resources/resource_tests.cpp `
    -o build-native-sjuni/native_resource_tests.exe
./build-native-sjuni/native_resource_tests.exe
```

The standalone CMake static-library build and CTest also passed, using the
installed Visual Studio CMake/Ninja binaries with the same MinGW compiler:

```powershell
cmake -S game/native/resources -B build-native-sjuni/resources-cmake -G Ninja `
    -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe -DCMAKE_BUILD_TYPE=Release
cmake --build build-native-sjuni/resources-cmake --parallel 2
ctest --test-dir build-native-sjuni/resources-cmake --output-on-failure
```

CMake/Ninja were passed by their absolute installed paths in the local run.
Only synthetic files/providers were used. These tests are neither original-game
I/O parity nor resource/decoder integration or performance measurements. Mount
identity, concrete consumer EOF/padding policy and completion/stop ownership
remain prerequisites to connecting the library to existing adapters.
