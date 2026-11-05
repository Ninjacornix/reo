# Native disc-stream scalar core

Status: independently compiled C++20 scalar implementation, checked against
original-word fixtures. No game entry, cvFs backend, native CD owner, SRD device,
resource provider or decoder has been redirected. No runtime library is used.

[The API](disc_stream.hpp) uses ordinary FileState/Settings values, typed
diagnostics/statuses and opaque 64-bit BufferId/RequestId values. IDs are never
treated as pointers or used in address arithmetic. The core has no guest
addresses, register/RAM model, wire-layout copies, interpreter, automatic threads,
global mutable state or I/O. Original sector/count arithmetic remains explicit
wrapping 32-bit arithmetic to preserve the scalar contract.

Operations are seek, tell, status, transferred, request and update. FileStatus
must use the four declared values. RequestStatus returned by a hook must use one
of its ten declared values. Zero opaque IDs represent absence. A null FileState
is supported by the pointer-taking operations and reports a typed diagnostic;
update requires a FileState reference.

## Admitted hook contract

Hooks supply guard entry/exit, diagnostics, cache-range observation, SRD
create/prepare/status/wait/destroy and CD/server calls. They return normally,
preserve FileState/Settings, and do not reenter operations on that file.
Observers may inspect the intermediate state. The module does not synchronize
concurrent callers. The owner must serialize use and retain any objects borrowed
by its hooks.

The cache hook receives an opaque destination and wrapping byte count. A
compatibility bridge may translate this to its inclusive address range. Prepare
receives the four mode byte values; only the first three are refreshed on submit.
Wait has no result because this original scalar caller does not consume it.
Unknown RequestStatus is a contract violation throwing logic_error; there is no
rollback or original fallback guarantee after a throwing/invalid hook.

The implementation deliberately retains distinctions established by the oracle:

- Invalid-file, negative-count and null-buffer diagnostics precede busy/zero
  handling. Busy calls return zero without admitting a request.
- Zero requests mark ready while retaining old completed count. Positive
  requests can clamp to zero and still reach preparation.
- Create failure stores an absent request ID. Prepare failure destroys the ID
  while retaining it in FileState, along with the other residual fields.
- Synchronous completion stores requested sectors; async completion stores
  accepted sectors. Queries do not pump completion.
- Terminal update changes the state/counts before destroy, then clears the ID
  before leaving the guard. Pending states retain it.
- Seek clamps signed values after word wrapping. Unrecognized origins still
  clamp the previous cursor and clear completed count.

A retained destroyed ID is an observed residual field, not a guarantee that a
real provider will accept another operation on it.

## Independent comparison

The [original oracle](../../../tools/native_reconstruction/dvci_oracle.py) reads
the pinned owned ELF and executes six original bodies through the existing
integer interpreter. It imports no native implementation. The
[comparison driver](../../../tools/native_reconstruction/compare_dvci.py)
regenerates those fixtures and rejects a supplied fixture that differs.

Its generated test-only bridge imports the synthetic wire layout into typed
state and mirrors owned fields back while retaining every untouched byte.
It maps synthetic buffer/request addresses to native IDs; all layout and address
knowledge stays in this bridge. It compares:

| Boundary | Compared observations |
| --- | --- |
| Every operation | Defined return bits and complete final handle/mode/destination-probe snapshot |
| Every hook | Kind/order, guard depth and complete before/after snapshots |
| Diagnostic | Diagnostic string identity mapped from typed reason |
| Cache range | Start and wrapping inclusive end, constructed by the test bridge |
| Prepare | Request ID, starting sector, accepted sectors, destination ID and four pointed mode bytes |
| Wait/destroy/status | Request identity; status also compares the consumed scripted response |
| Create/prepare | Consumed scripted response |
| CD sync | Consumed poll argument zero |

Excluded observations are unused volatile argument registers, unused hook return
registers (including wait), raw void update return registers and the address
identity of the mode buffer. Prepare compares its pointed bytes instead. The
native core does not simulate registers to manufacture these observations.
Original instruction PCs/step counts establish fixture provenance and are not
native execution targets.

```powershell
python tools/native_reconstruction/compare_dvci.py --fixtures build-native-sjuni/dvci-oracle-fixtures.json
```

GCC 15.2, C++20, -O1 -Wall -Wextra -Wpedantic -Werror: six focused native test
groups pass. Across 51 original-word cases, **178 calls, 159 defined returns,
142 hook events and 462 complete snapshots match**. Receipt and generated
test-only source are under build-native-sjuni/disc-stream-verification.

The directory also has a standalone CMake library/test project. It does not
modify or automatically join the parent native/game build.

These tests admit scripted external results with no I/O or reentry. They do not
establish real SRD/device error/wait effects, EOF padding, stop/close, callbacks,
scheduling, DMA visibility, borrowed payload lifetime or CRI/SJ publication
parity. Those remain gates in the
[request-boundary review](../../../docs/native-resources/CVFS_REQUEST_BOUNDARY.md)
and [oracle scope](../../../docs/native-resources/DVCI_ORACLE.md).
