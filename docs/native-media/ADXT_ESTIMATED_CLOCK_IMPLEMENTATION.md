# Native prepared estimated clock

Status: bounded independent clock qualified, 2026-11-06. This is part of stage 3;
actual stream/player/device integration remains open.

The [native clock](../../game/native/adxt_estimated_clock/estimated_clock.hpp)
implements estimate, centiseconds, pause/resume, and the already-busy
discard/rebase service profile from the [contract](ADXT_ESTIMATED_CLOCK_CONTRACT.md).
It reuses the unchanged integer query core with prepared queue observations.
Per-stream origins and pause/play bytes are separate from shared mode, rate,
counter, rebase selector, service-busy word, and raw drift bits. No host clock,
worker, device call, guest address, register file or runtime helper is used.

The native source was frozen before its comparison fixture, after the earlier
[original evidence](ADXT_ESTIMATED_CLOCK_ORACLE.md) had been seen. Both exact
GCC15.2 and bundled UCRT LLVM21.1.8 pass:

- **127 admitted cases / 132 operations**, with exact typed state, ratio outputs,
  centisecond return bits, and diagnostic/critical event order. The enhanced
  comparison also checks state at every such event by applying the original
  ordered writes up to its actual observation index.
- **22 unit checks**, including allocation denial, reentry refusal, tick/counter
  wrap, unchanged and noncanonical pause arguments, six unsupported FP modes,
  preserved accrued FP flags, and early zero-divisor/service/queue refusals.
- A threshold mutant changing positive60 to60.001 differs on **two cases**.
  A mutant publishing the refreshed estimate on a rebase differs on **12 cases**.
  Both must differ; neither modifies production source or original observations.
- Parent Release build and selected `adxt_estimated_clock` CTest. The parent now
  registers34 suites; this count is not a migration percentage.

The implementation retains the actual statement order and signed low-word
conversion. Nominal +60 yields drift `42700001`, triggers rebase, and returns940
while storing a1000 baseline. The nominal negative counterpart falls below the
threshold in magnitude. Unsigned baseline conversion and signed terminal
conversion stay distinct. Shared mode restoration and counter wrap are literal.
Centisecond comparison uses the original low return word established by its
final `mfc1 v0` and return instructions; the inherited oracle's generic
`return_is_defined=false` annotation was not silently changed.

Four of the131 frozen original cases are **not parity successes**. The three
zero-denominator cases can complete in the existing runtime with exceptional FP
values; this finite native profile refuses before effects. Discard with service
word0 reaches an unowned worker in original evidence; native refusal precedes
its diagnostic and critical boundary. Each refusal preserves all prepared state
and emits no events. The original partial and exceptional records stay intact.

The first native comparison checked final state and event kinds. The second
added actual state at those events without changing the core or reference
execution. Both cohorts and the earlier fixture source are preserved locally.
Original FPR/FCR scratch registers, stack writes, raw memory ABI, concurrent
scheduling, queue credit ownership and physical audio consumption are outside
this typed-state proof. Hooks observe state; they do not operate a device.

Inputs are pinned in `game/native/adxt_estimated_clock/manifest.json`; script,
fixture, receipts and parent builds are pinned in `qualification.json`. The two
comparison receipts under `build-native-sjuni/adxt-estimated-clock/` are:

| Receipt | SHA-256 |
| --- | --- |
| `native-gcc-v2/receipt.json` | `1dff6553d6102a85c21e0f49329f521c44ff700fbea67dc4a5804687d31c9664` |
| `native-llvm-v2/receipt.json` | `4540572a1c2c4216049c7fe827a5532ad49d82ee75b978445113db39416cc59b` |

`verify.py --cxx <exact compiler> --original gcc-v1|llvm-v1 --output <fresh scoped
directory>` validates frozen source and original hashes before comparisons and
checks source again afterward. No game process was launched and no audio device
opened for this work. RNA/DTR credit ownership, final-sector/LSC source support
and full player integration remain the next stage-3 boundaries.
