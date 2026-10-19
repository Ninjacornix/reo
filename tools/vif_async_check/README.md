# Resumable VIF input cursor candidate

Implemented in `build-ninja/m2-vif-async-integration/vif_cursor.h`. This is an
isolated preparatory parser component using the **actual unchanged runtime
VIF/VU/GIF implementation**. It is not installed in the game and does not
implement an asynchronous DMA/VU pipeline. The implementation agent has not
compiled or run it. The coordinator owns validation after native runs finish.

## Build and compare

```
tools\vif_async_check\run.bat third_party\PS2Recomp\out\build validation1
```

Choose a fresh suffix; the runner refuses to overwrite existing validation.
It builds only this fixture against the current Release runtime library, records
source hashes, executes tests and compares full state output bytes. The
coordinator must verify that the library actually matches the source revision.
It neither rebuilds the runtime nor launches the native game.

The fixture imports the frozen worker fixture's real backend, preserving that
fixture and its completed validation1. It executes real MPG, UNPACK, MSCAL,
MSCALF, MSCNT, XTOP/XITOP, E-delay behavior, GIF arbitration, display capture and
GS drawing. Snapshot comparison includes all VIF registers, complete VU state,
all code/data bytes, ordered GIF and VU callback snapshots, captures and all
4 MiB of VRAM. Every byte split in the finite input corpus is checked, as are
byte quotas 1/2/3/4/7/16/63/65536 with a one-command quota and a deliberate
dependency pause before execution. The corpus includes all UNPACK format
codes, row/column/mask, skipped and filled cycles, mode-2 row feedback,
DIRECT/DIRECTHL, partial MPG, code/data wrapping, MSCALF and reset of an
incomplete payload. Stop, generation replacement, incomplete headers,
capacity rejection and the declared zero-IMM DIRECT size have separate checks.

The original-IRQ control models two ordered VIF entries, exact completion
before each count retirement, and an ideal instantaneous later PATH3.
It demonstrates the pre-PATH3 VIF/count dependency even with perfect PATH3.
The count/tickets/STR in that control are explicitly a fixture model; the
test does **not** install actual guest DMAC handlers or claim original game
instructions were executed. The frozen previous fixture separately validated
actual nested EE release and real IRQ/ready-guest IO admission.

## Implemented contract

One owner serializes this cursor, VIF registers, VU uploads/execution and GIF
arbitration. There are no new locks, runtime fields or ABI changes.

`resume(input, size, budget, readiness)` returns:

- Bytes copied from this call, commands actually executed and total executed
  input bytes. Copied input is **not** a hardware DMA-consumed quantity.
- Explicit input start, generation, command word, opcode, header byte count,
  payload size/progress, STCYCL and recorded TOPS/ITOPS.
- Input exhaustion, incomplete input, quota, VU/GIF/both dependency wait,
  or stopped.

The cursor owns at most one complete command, with an explicit input bound
(default 1 MiB plus its header). This bounds copying and descriptor work per
resume call. It does **not** time-bound execution of one command: a real
MSCAL can still synchronously take 113 ms. There is no mid-VU cancellation.

An incomplete payload publishes the same CODE/NUM/INT values as the old
synchronous parser; data uploads and callbacks wait for full payload.
Readiness is queried before executing a complete dependency command.
A denied query preserves registers/callback output from that query point
and the complete owned command. Resuming executes it once. Dependency labels
are conservative scheduling metadata, not a new implementation of PS2 status
bits or all FLUSH/path-specific hardware barriers.

`synchronous()` drains quotas through the same resumable API. It preserves
the old parser's deferred payload model, including its existing synchronous
FLUSH-family no-ops. Reusing the original parser avoids a second independent
UNPACK implementation; it receives only complete commands and retains no
partial carry for cursor-managed streams. Do not mix direct partial calls
to the old parser with this cursor for the same memory owner.

`stop()` rejects new input and discards unexecuted owned bytes. Oversized
commands stop the cursor and throw before payload allocation or execution.
`reinitialize()` retires the cursor generation only; the external owner must
first quiesce execution and perform real FBRST/runtime initialization. These
APIs neither clear STR nor raise D_STAT/DMAC. No audio accounting is changed.

## Remaining native integration

This stage does not replace the production synchronous wrapper. The next stage
needs a parser-owned pending VU launch instead of the production parser's
inline callback, partial DMA/FIFO consumption separate from owned copying,
real wait-for-VU/VEW and flush rules, and tag-IRQ queue continuation. VU code,
data and resulting GIF output need one ordered owner; uploads cannot race
previous VU writes. XTOP and ITOP must be latched at launch. GS display capture
must reserve the future PATH1 output prefix rather than snapshot only packets
already enqueued. Genuine STR completion may precede VU end at a supported
hardware command boundary; it may not be manufactured for a whole batch.
