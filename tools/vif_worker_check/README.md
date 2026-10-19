# Isolated VIF transaction worker check

This is a bounded independent ownership/scheduling prototype. It is **not a
live runtime patch**. Candidate code is
`build-ninja/m2-vif-worker-prototype/ordered_worker.h`; the original runtime
source and headers remain unchanged. The coordinator owns build/run
serialization. The implementation agent has not built or run this fixture.

The original synchronous VIF write holds EE/IO ownership for about 113 ms;
recorded outer VBlank admission waits overlap that work by median 99.68%.
Moving execution to a single owner permits IRQ and ready audio guests to
acquire EE while a submitting main thread waits. Original IRQ, however,
submits/polls PATH3 before waking the music server. Blocking that PATH3 behind
the VIF job still delays the sleeping producer. This fixture makes that
limitation explicit rather than claiming that a thread move alone fixes music.

## Build/run (coordinator only)

First build the current Release runtime once through the coordinator's existing
workflow. Then run from a Developer Command Prompt or through `cmd /c`:

```
tools\vif_worker_check\run.bat third_party\PS2Recomp\out\build validation1
```

Use a fresh suffix. Existing output is never deleted or overwritten. The
runner builds one fixture, records fresh source hashes, runs synthetic cases
and compares exact serial/worker output. It does not launch a game or change
guest audio. Native performance/quality acceptance cannot follow from this
isolated test. `REO_GS_THREAD=0` removes an unrelated GS worker from fixture
ownership; this is a verification control, not the proposed native setting.
The linked runtime library must match the recorded source revision: this
runner hashes sources but does not rebuild or prove library/source identity.

## Implemented worker contract

- Accepted jobs own their bytes and privileged capture snapshot; normal/SPR
  source pointers must be copied upstream before calling this API.
- One bounded FIFO includes VIF transactions, PATH3 packets, display captures,
  register writes, reset and fences. Active and queued owned input consume
  both the byte and descriptor limits. Completion tickets retained by callers
  and downstream GS storage are separately owned, not included in that limit.
- Execution runs without the queue/publication mutex. It never acquires guest
  CPU. Potentially blocking submission/wait must happen outside **all** guest
  and IO scopes; the fixture uses real nested `GuestExecutionReleaseScope`.
- Busy DMA publication uses a separate mutex-protected **fixture model**, not
  live `PS2Memory` registers. STR stays set until the exact executor returns;
  reads do not clear it, QWC reaches zero only at that modeled completion,
  and D_STAT channel bits are emitted only for successful execution. This
  small model does not implement real tag-chain walking, masks, TIE, INTC or
  DMAC callbacks. It cannot replace the live DMA controller.
- Caller completion waits for execution. Merely accepting owned bytes into
  the FIFO is deliberately **not** modeled as PATH3 transport completion.
- Stop closes acceptance, cancels pending jobs, wakes capacity/completion
  waiters and joins active execution before resources are freed. Cooperative
  fixture gates observe stop. An actual interpreter call is bounded by its
  cycle limit but is not interrupted mid-run; no new live stop hook exists.
- Executor failure poisons that generation and cancels its remaining jobs.
  A new worker instance has a new generation after the old owner is joined;
  no old success/completion crosses that boundary.

## Meaningful checks

The same binary feeds the unmodified real VIF/VU/GIF/GS pipeline directly on
one thread and through the candidate worker. Exact output includes all VIF
registers, complete VU state/code/data, callback snapshots before/after real
MSCAL/MSCNT, ordered emitted GIF packet bytes, privileged display captures,
and final 4 MiB VRAM. Independent oracles exercise real XTOP/XITOP and the E
delay pair, persistent MSCNT PC/state, MPG/UNPACK wrapping, split MPG payload,
MSKPATH3 FIFO/unmask, DIRECTHL, and reset retirement of an incomplete payload.
Original FLUSH-family no-op behavior is preserved for serial parity; parity
does not establish hardware-correct concurrent barrier semantics.

Deterministic gates test source-copy lifetime, retained busy/tag/address state,
busy-channel overwrite rejection, actual byte/job capacity blocking, active
and pending stop, generation reinitialization, and exception retirement.
The scheduling case holds two real nested EE scopes, releases their full
depth while waiting, and proves IRQ/ready guest admission by real D_CTRL IO
reads. An IRQ PATH3/capture queued behind a gated VIF cannot overtake it.
The sleeping music guest remains unwoken until the original IRQ dependency
clears: this is the required negative control. No PCM reply accounting changes.

These are synthetic streams, not complete captured room workloads. Existing
four complete VIF capture buffers are small DIRECT inputs and would not prove
room MSCAL throughput. No native FPS/audio gain is asserted.

## Exact live integration barriers

| Boundary | Requirement before enabling a native worker |
| --- | --- |
| DMA preparation | Under short IO ownership, walk tags and own every input byte including normal/SPR and TTE; preserve ASP/ASR/TADR/TAG/TIE and invalid/empty-chain behavior. No recursive IO-held path may wait for capacity or completion. |
| VIF state | Route register/reset writes and parser carry through the owner. CPU reads use a coherent published snapshot. Direct reads requiring results fence outside EE/IO; busy polls observe real state. |
| VU memory | Worker owns the active runtime code/data/interpreter. Map or fence every direct alias/getter and latch TOP/ITOP. Existing bridge aliases cannot be assumed identical to the runtime arrays. |
| GIF ownership | Worker owns path masks, masked PATH3 FIFO and arbiter. Live IRQ/main cannot submit into the same unsynchronized arbiter concurrently. |
| Future output order | A VIF job reserves the output prefix before its future PATH1/PATH2 bytes exist. Later PATH3 and capture commands retain their ordered positions. Current GS-prefix capture is insufficient unless deferred through this queue or an explicit future-token protocol. |
| IRQ PATH3 polling | Original IRQ polls transport before waking CRI. To service sleeping producers during VIF, explicitly separate copied bounded GIF-input acceptance from later arbitration/raster completion using proven DMA/GIF semantics. It is not acceptable to clear STR on read or mark a not-yet-accepted transfer complete. The blocking fixture deliberately does not solve this boundary. |
| VIF flush commands | FLUSHE waits for prior relevant VU execution; FLUSH adds PATH1/2 transfer; FLUSHA includes PATH3; MSCALF adds PATH1/2 synchronization. A blanket FIFO fence and existing no-ops are not a full hardware implementation, especially while PATH3 is masked. |
| GS capacity | Worker capacity/GS waits must not require the guest CPU or any IO lock held by a waiting caller/IRQ. A GS output token must never wait cyclically on a producer blocked behind that same token. |
| Publication/IRQ | Publish true DMA progress/STR/QWC/D_STAT under short IO ownership, then release IO before posting interrupt work. Remove the current CHCR read-to-clear shortcut for the owned channels. Do not invoke guest code from the worker. |
| Stop/reset | Close submission, cancel/drain the defined generation, wake every input/output/CPU waiter, join before freeing RAM/VU/GS, and invalidate future output tokens. No stale capture, callback or D_STAT may enter a reinitialized runtime. |

Because these live barriers are not yet implemented, a source-only movement of
`processPendingTransfers` to `std::thread` must not be integrated. The candidate
is the independently testable foundation and dependency proof requested for
that case, with an explicit synchronous caller completion contract.
