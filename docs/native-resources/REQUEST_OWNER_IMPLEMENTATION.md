# Resource request owner implementation status

2026-11-05. An opt-in runtime-destruction boundary is implemented and checked in
isolation. This is not a completed native cvFs backend.

The [independent serial worker](../../game/native/tasks/README.md) owns a bounded
preallocated queue and joinable thread. Standalone checks cover FIFO, admission,
publication, stop/drain/cancel, capture lifetime, exceptions and join rules.
All four suites in the combined `game/native` CMake project pass.

The [CD owner adapter](../../recomp/overrides/native_cd_owner/README.md) retains
original File #1 disc request/completion behavior while replacing detached worker
lifetime in the selected candidate. Thirteen host scenarios and real-header
compilation pass. Callback continuation PCs retain their original context.

Public [patch 0120](../../third_party/patches/ps2recomp/0120-runtime-external-worker-lifecycle.patch)
adds strongly owned runtime workers, pre-run registration, nonblocking stop and
joins before VIF/GS/kernel teardown. Exception guards retain captured stack state
until game-thread join and clear presentation callbacks before their local target
disappears. The full 121-patch series reapplies in a second clean checkout, with
byte-identical results. The real runtime translation unit passes syntax checking.
Exact-method/unwind tests, 500 races and fail-closed checks pass using
`tools/native_reconstruction/verify_external_worker_lifecycle.py`.

The active dependency checkout is preserved. Patch/syntax checks do not establish
a matching linked library. The [candidate preparation workflow](../../tools/native_reconstruction/NATIVE_CANDIDATE_PREPARATION.md)
uses commit-pinned source, audited dependency inputs, current asset headers and
the direct C audio provider absent from the old SJUNI kit. Independently supplied
stock libraries/recompiler are retained only after identity checks.

Remaining gates:

- Linked candidate and original/native playback, loading and shutdown.
- Stable edition/content/virtual-layout mount identity.
- Mid-game stop/close/reuse of borrowed guest targets and SJ spans.
- Original error/status publication, including throwing or short/failing I/O.
- Original request/completion comparisons and explicit EOF/padding.

No compatibility component is removed by these checks. The worker core is native;
its adapter still uses guest state/callbacks, disc-sector translation and the PS2
runtime until their remaining consumers migrate.
