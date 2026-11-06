# Original ADXT estimated-clock, pause and rebase evidence

Status: original-word evidence, 2026-11-06. No native estimated-clock owner,
runtime hook, device timestamp, game run or stutter diagnosis is supplied by this
oracle. The separate [integer raw-clock core](ADXT_INTEGER_CLOCK.md) already has
native comparisons. This new evidence closes additional arithmetic and control
questions for its future estimated-clock owner.

The [oracle and tests](../../tools/native_reconstruction/adxt_estimated_clock_oracle)
execute complete original `132160` estimate, `132458` centisecond conversion,
`132E50` pause/resume and a bounded `133058` discard/rebase profile. They retain
the real integer-query/ADXB/RNA/SJRB getter chain. No external hook supplies a
sample-position result. Prepared records and queue counts are explicit synthetic
inputs; no actual playing stream or concurrent scheduler is reconstructed.

## Source and FP authority

Authority is owned File1 ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Seventeen existing integer intervals plus nine new intervals are pinned. The
new source audit matches416 instruction comments and eight omitted zero words,
with no missing nonzero word; the integer audit separately matches374 comments
and four omitted zeros. Loading a body is not execution coverage.

The new FP worker uses the actual FINAL127 runtime macros and CVT helper from
the reproducibly reapplied SDK. Receipt SHA-256 is
`909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a`.
Each reached FP opcode has an audited original-word emission. The generated
reference switch uses that exact emitted statement, including complete guarded
division and register/memory conversions. Independent generic opcode selection
is compared with that emission for all41 observed words. New ordered comparisons
and false/likely branches are added in the new worker only; old math/header
workers and ISA engines remain unchanged.

The1,128 micro inputs include signed zero, subnormals, finite boundaries,
infinities, quiet/signaling NaNs, FCR flags and all four host rounding modes for
CVT.W. Both compiler workers match every micro's exact reference. Their literal
micro results also match each other in this corpus, without normalization.
This establishes the current runtime's emitted behavior under these exact host
toolchains, not PS2 hardware FPU equivalence or all exceptional values.

Compiler identities:

| Compiler | SHA-256 |
| --- | --- |
| GCC15.2, `C:/msys64/mingw64/bin/g++.exe` | `51911fb398529fa19769da935279c1a8a56f1c3508b2df295624aaa3dae34aa5` |
| Bundled UCRT LLVM21.1.8, `x86_64-w64-mingw32-clang++.exe` | `f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3` |

Each worker child PATH begins with its exact compiler's bin for DLL resolution.
An initial additional unittest invocation omitted that path for LLVM and failed
its loader handshake. The test environment was corrected; worker source/binary,
frozen inputs and expected results remained unchanged. No failed-handshake test
is counted as a completed original operation.

## Frozen inputs and complete observations

The131 authored cases and micro inputs were frozen before collecting any new
expected results. Freeze records oracle, imported engines, actual source ranges,
emissions, runtime macro/helper and input hashes. No native estimated-clock
implementation was used as an expected-value provider.

Both compilers execute136 operations:135 return, one retains an honest partial
cut. They execute18,588 original instructions and1,549 FP steps. Their entire
case objects agree, including state, outputs/guards, full FPR/FCR bits, ordered
memory writes, reached addresses and external-boundary observations. Cases cover
raw/estimated modes and state branches, nominal positive/negative drift near60ms,
recursive resynchronization and counter wrap, paused/noncanonical pause bytes,
tick wrap, high unsigned conversion paths, terminal depth scaling, zero
denominators and multi-operation pause/resume/query sequences.

Two important literal observations:

- Rebase can store a new baseline while publishing the **old estimate** on that
  call. The nominal +60ms input produces drift bits`42700001` (one float ULP
  above60), so it rebases; the nominal -60ms input produces`C26FFFF1`, whose
  magnitude is below60, so it does not. These are consequences of the original
  expression order. No epsilon, nominal-time rounding or symmetric rewrite is
  applied.
- A zero-frequency case completes the current runtime path and records positive
  infinity in its drift field. It is retained as literal evidence; it is not
  labeled an original rejection or automatically admitted by a future native
  finite-domain clock.

Pause updates the estimate baseline separately from the RNA play byte and tick
baseline. Resume stores the new tick origin. Mode1 resynchronization executes
the original recursive raw-query path, restores mode and increments its counter;
other resynchronization selector values retain their original branch behavior.
No service tick is assumed to be a game frame, vblank or audio-device quantum.

## Explicit partial and ownership limits

For the bounded discard profile, service guard`21B754` is prepared nonzero, so
the actual `132C08` body returns through its real busy branch. This qualifies
that arithmetic/control path, not running the complete decoder/audio scheduler.
The guard0 case enters actual service and stops at first unowned instruction
fetch`12D678`. Its prior writes, registers and state remain recorded. Nothing
supplies a fake service result or labels the enclosing operation successful.

External critical enter/leave and diagnostic edges are synchronous observational
hooks. They supply no real lock, worker priority, cancellation, device progress
or callback reentry. Ownership of the queue snapshot, raw-pointer alias rules,
RNA/DTR credits, complete discard service, movie-clock composition and actual
player integration remain separate obligations. A future native clock must
state those contracts before this arithmetic can be wired into a live player.

## Receipts and reproduction

Private artifacts live under `build-native-sjuni/adxt-estimated-clock`:

| Artifact | SHA-256 |
| --- | --- |
| `frozen-v1/inputs.json` | `5c331cac53c96fe53d3e5fef89bf65bee7fa4539f0cc044cfdd859b5fbe2f6c5` |
| `frozen-v1/input-manifest.json` | `2f888a4513ad1968512bc032806de3fccdafbb97aff808dd8f03f5777ecd19c0` |
| Oracle source at freeze | `823172e32b68f1687e714e83e0f9bdce8e26ddf0f05ec47f7e009dd4e9832070` |
| `gcc-v1/receipt.json` | `7e99a4b7fd3d7706836610bb24fd2fb194d08a7d52aa9d0355ffaa10d90ceb25` |
| `llvm-v1/receipt.json` | `15f7ed715fd6dde41fab4e15b6b9721f6f8ac6763efc8e4e61a24d4457ada6c5` |
| Both `expected.json` | `5126e37971045bc06df802d4ff6af299433c79912a76386603903754a866b9c5` |
| Both `micro-qualification.json` | `146421fdc2049fbba9b9d9a7cdb37078e62e66259b512c5f650b45b2845985c1` |

Eight unittest checks pass, re-executing every original transcript and every
generic/reference micro under both existing workers. The receipts preserve exact
compiler commands and worker binary/source identities. Compiled worker sources
have different absolute helper paths; their literal outputs remain compared.

```powershell
python tools/native_reconstruction/adxt_estimated_clock_oracle/oracle.py --freeze --output build-native-sjuni/adxt-estimated-clock/frozen-NEW
python tools/native_reconstruction/adxt_estimated_clock_oracle/oracle.py --frozen build-native-sjuni/adxt-estimated-clock/frozen-NEW --output build-native-sjuni/adxt-estimated-clock/gcc-NEW --compiler C:/msys64/mingw64/bin/g++.exe
python tools/native_reconstruction/adxt_estimated_clock_oracle/oracle.py --frozen build-native-sjuni/adxt-estimated-clock/frozen-NEW --output build-native-sjuni/adxt-estimated-clock/llvm-NEW --compiler <exact-bundled-driver>
python -m unittest discover -s tools/native_reconstruction/adxt_estimated_clock_oracle -p test_oracle.py -v
```

Use fresh artifact directories; old expected observations are never overwritten.
The tests intentionally verify the retained frozen-v1 cohort. No original
payload or compiled original-word worker is added to tracked files.
