# Bank budget v2: independent source review

Status: source-only review, 2026-11-05. No confirmed defect found in the reviewed
budget, asset ownership, admission or callback-retirement paths. This is a
qualified code-review result, not a hardware, integration or performance claim.
No build, executable, game or device was run for this review; no candidate source
was changed.

The reviewed v2 is explicitly a post-expectations allocator/admission revision.
Its prior DSP oracle results were already available. It does not acquire a new
blind-implementation claim by retaining the original arithmetic.

## Identity and existing evidence

The inspected files match cohort identity
`cf5e4299be1bc3f2a804b32a9e6b0dc57d248052b1fe655b56bd77d6ccca5091`:

| File | SHA-256 |
| --- | --- |
| [budget.hpp](../../game/native/audio_banks/v2/budget.hpp) | `3dbdbc041f77de5ccb1c199759a8d7dd74915131bf73bb36f118e907d0055a18` |
| [session.hpp](../../game/native/audio_banks/v2/session.hpp) | `0a4730e9fd27f74828d8990e5f7b953d32d8577ee0d0e6e5ea0a421b10503063` |
| [session.cpp](../../game/native/audio_banks/v2/session.cpp) | `effb9e73154dc0ac37c9e17325c74c8824ebe3e8fd8b165849fbd68776a8f9f6` |
| [algorithms.hpp](../../game/native/audio_banks/v2/algorithms.hpp) | `463f3f0f910ca6ee00b190818ea8cf961fe5fae2ae35b2b3d9a535e46328af00` |
| [algorithms.cpp](../../game/native/audio_banks/v2/algorithms.cpp) | `8dd0a54adc0838e0fa3d555e928da3a30e5cb7a5e48483ba14ba299ba74eb24b` |

`derive.py` also checks the historical v1 freeze, including all three shared
`source_*.inc` files, before comparing the generated v2 implementation. The
callback ownership reasoning below includes those shared record/member/mix files,
not just the v2 wrappers.

Existing GCC and bundled LLVM unit receipts each record **218 assertions**, with
no changed cohort files. They exercise exact capture/preparation byte boundaries,
asset-count refusal, failure injection at each preparation allocation, malformed
and cross-session input, paused allocation racing reset, retained prepared assets,
old-clip retirement, weak-control-block retention, paused final deallocation and
concurrent preparations. These are not 218 distinct test cases.

Both existing original-source regression receipts record 18 cases, 252 actions,
13,004 float words, 12,768 gain calls and zero differences. That finite synthetic
regression supports the retained DSP contract; it does not independently prove
every allocation interleaving or runtime packet/guest lifetime.

Receipts under `build-native-sjuni/audio-bank-budget-v2`:

| Receipt | SHA-256 |
| --- | --- |
| `gcc-unit/receipt.json` | `c459a6a0211dc6b04c2d65a03b157a6accea7f25965a34e6c8bfbe1f8d523422` |
| `llvm-unit/receipt.json` | `4b2308616f86b5880f487b6bf4c5ceb76c86dfe7565f958d5f8b36d7fa7b04b6` |
| `gcc-original/receipt.json` | `ca5e9d5965a659a1e00b9770e46a1d8b9a05624222be80517d2c002f7a88662d` |
| `llvm-original/receipt.json` | `c4d4d55e08bf0f58cb76ba499ad2c439e90549640bc1eef00ba244f2927dbc26` |

## Allocation and final-control-block ownership

`Budget::allocate` reserves requested bytes under its mutex **before** calling the
upstream source. Concurrent or paused allocations therefore consume the same
limit. Its subtraction-based check avoids addition overflow. A null upstream
result or exception refunds those bytes; successful source allocation increments
the cumulative allocation counter. `BudgetExceeded` means budget refusal, while
upstream exceptions become `bad_alloc`/`no_memory`. The refusal counter counts
budget refusals, not every upstream failure.

`Budget::deallocate` calls the source before refunding bytes, without holding the
budget mutex across user code. Consequently a paused free remains charged.
`AssetAllocator` checks multiplication overflow and retains a strong Budget.
Its allocator rebind copies both Budget and AssetLease. This matters because an
`allocate_shared` allocator can outlive destruction of its contained object:
neither the resource nor the asset-count lease depends on that object's members
still existing when the final control block is freed.

Only the allocator used by `acquire_asset` has `refund_asset_ = true`. It holds
the Budget directly and refunds the asset count after its deallocation returns.
Other asset allocators retain that lease but do not separately refund the count.
Allocator-copy destruction does not refund anything. Thus one captured bank can
own many buffers, cache nodes and clip control blocks while consuming one asset
count until all those allocations/control blocks have gone away. There is no
lease/control-block ownership cycle: the lease's own control allocator has a
Budget but no reference back to that lease.

The acquire failure catch refunds the reserved count when allocation fails.
The current AssetLease constructor is `noexcept` and only moves a shared pointer;
there is no throwing constructor path here that both deallocates a successfully
constructed lease control block and reaches that catch for a second refund.
Weak clip references intentionally keep the control allocator, lease and budget
charged after clip-object destruction. Existing paused-free and final-weak tests
exercise these distinct boundaries.

## Capture, preparation and installation

`Submission` strongly retains State and occupies a bounded generation slot.
Capture verifies its session, live slot/generation and epoch, checks each part's
2 MiB bound, acquires the asset admission, then allocates writable buffers. It
rechecks submission validity after allocation. Preparation verifies the captured
bank's lease/session/epoch, reserves a unique serial under the gate, builds the
immutable bank/cache using the same lease and rechecks the submission afterward.
Allocation/parser refusal destroys partial state without installing it.

Reset advances the epoch while holding the data mutex. A reset during slow
capture/preparation invalidates its old submission/result; a reset after a
successful preparation still leaves install's epoch check. Install holds the
data mutex while checking submission and PreparedBank identity/epoch and replacing
the port. It cannot publish an old asset across a concurrent reset. Consuming
serials on unsuccessful preparation is conservative; exhaustion is explicit.

PreparedBank copies may deliberately retain bytes/count after reset, join or
Session destruction. They own immutable AssetData and its allocation lease, with
only weak session identity. This is retained ownership, not an uncharged cache.
Cross-session or stale installation is refused. `if_unloaded` on an already loaded
port returns skipped before inspecting the unused candidate, without mutation.

Capture/preparation are protected from join by the held Submission producer count,
even though they do not acquire State::Call. Normal operations acquire Call
admission; request_stop closes admission, and join waits for both producers and
calls before clearing state. Already admitted work can finish during stop. Join
refuses an operation/gain callback's self-wait through the Frame chain; a caller
must also release its own Submission objects before joining, as documented.

## Callback retirement and bounds

Current-port AssetData owns its immutable decoded cache throughout the data lock.
Dropping a current-asset Voice reference during mixing therefore cannot destroy
the last clip/control allocator. Old-asset voices instead carry their own clip
and allocation lease after port replacement. Their serial comparison, rather
than a racy `use_count()` decision, forces inactive old clips into fixed retirement
storage. No old clip's last lease is released by that reclamation path.

Before any gain reads or mix mutation, mix_add counts old-asset voices and
requires enough of the 48 retirement slots for all of them. With the data mutex
held, replacement cannot create additional old voices during that callback.
New notes use current immutable caches; once retired, a voice is removed. This
establishes the capacity bound even over several sequence ticks in one call.
An exhausted retirement reserve produces explicit capacity refusal; the adapter
must schedule producer/control drain and handle refusal truthfully.

Install, apply, reset and drain collect retired references into an earlier-declared
Garbage object. Its destruction follows data-lock destruction. Join similarly
clears under the lock and destroys garbage afterward. Garbage has room for 48
retired plus 48 live clips and all 14 port assets. This avoids last asset frees
inside either the callback or the session data mutex on those control paths.

Callback vectors are reserved during State construction: 48 voices, 1025 events
and 65,025 resolved sample layers. The source loops bound one sequence tick to
1024 commands plus terminal events and one resolution to 255 regions times 255
samples; events/samples are cleared and reused. Decoding and decoded-cache growth
occur during preparation, while callback lookup only finds existing entries.
Temporary rejected Voice references still have the current cache as a strong
owner. The review found no candidate callback allocation or last-clip free along
these paths. This does not make the data/gain path lock-free or wait-free.

## Limits that still apply

- The byte limit measures actual typed allocator requests, including rebound
  shared control blocks, hash nodes/buckets, vector capacity, transients and
  outstanding reservations. It excludes heap-internal bookkeeping, fixed session
  scheduler storage, Budget/identity administration and caller/adapter input
  memory. It is not a process RSS limit. Decoded-size checks are additional parser
  bounds, not substitutes for the allocator's peak accounting.
- A custom AllocationSource must support concurrent calls, honor requested size
  and alignment, use symmetric `noexcept` deallocation and retain no borrowed
  source lifetime outside its strong owner. Arbitrary upstream reentry or blocking
  is not proven safe merely because the Budget mutex is released around it.
- Session and Submission objects must retain normal C++ object lifetime during
  concurrent calls. GainProvider must remain pure/noexcept and obey its stated
  no-reentry contract. Self-join refusal does not authorize other recursive
  operations under the data mutex, nor joining while holding one's own producer.
- This standalone design has not established guest capture consistency, wire/RPC
  ordering, whole-runtime producer admission, real callback scheduling, shutdown
  integration or measured audio performance. Existing receipts explicitly say
  integration is uninstalled and no game/device was exercised.

No source change is requested by this review. Future integration should preserve
the same admission-before-allocation boundary, explicit retirement drain/failure
handling and final-control-block accounting rather than treating a port unload
or Session join as proof that every externally retained asset was freed.
