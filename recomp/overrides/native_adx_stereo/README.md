# Guarded synchronous keyed stereo/downmix adapter

This default-off adapter replaces only File #1 US lower kernels `127C80`
(separate channels) and `1278B8` (downmix) within the domain below. Root build,
bootstrap and candidate-preparation wiring are deliberately outside this folder.
No game, media device or imported asset is run by the isolated checks. Linked
candidate validation and actual game-call activity remain pending.

Build with `REO_GAME_FILE1` and numeric `REO_BUILD_NATIVE_ADX_STEREO=1`, then call
`reo_native_adx_stereo::install(runtime)` after final ELF/function registration
and before execution. Exact environment `REO_NATIVE_ADX_STEREO=1` is separately
required. Feature absent/zero and File #2 expose an inline false installer.
Neither the original selector `127FC8` nor global `20C7A8` is modified. Existing
original policy continues selecting whichever lower kernel it selected before.
SJ/ADXB/ADXT/RNA, refill, clock, loop, pause, reset and stop policy are untouched.

## Identity and lifetime

Installation requires both actual generated function pointers
`sub_00127C80_0x127c80` and `sub_001278B8_0x1278b8`. It captures them before any
publication; an arbitrary occupied registry entry is insufficient. Both current
registry bindings must remain this adapter's wrappers on each native dispatch.
Both original bodies and the nibble table are hashed at install and before each
preparation:

| Original interval | SHA-256 |
| --- | --- |
| `127C80..<127FC8`, 840 bytes | `4a4e6da9bbda1a2a0b83c2f7bb31e777aeeb912c751b0a8a0694ce16c366f9ff` |
| `1278B8..<127C7C`, 964 bytes | `fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab` |
| `239BE8..<239C28`, 64 bytes | `67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f` |

The independent [original-word oracle](../../../docs/native-media/ADX_STEREO_ORACLE.md)
and [native core proof](../../../game/native/adx_stereo/README.md) pin the original
File #1 ELF. Downmix padding NOP `127C7C` is outside its function body.

The adapter accepts one runtime and exact RDRAM pointer for one lifetime.
A no-thread `ExternalWorker` token uses the real pre-run registration gate;
stop permanently disables native dispatch. The runtime strongly retains it.
`join=true` is valid because no private worker or borrowed input survives the
synchronous call, and the matching runtime lifecycle joins guest host threads
before releasing memory. An accepted owner is never reassigned to a reload,
second runtime or reused address. Missing/wrong initial bindings fail before
claiming ownership, allowing an early bootstrap pass to retry later.

Publication failure may leave either or both disabled wrappers installed. Both
captured originals are already initialized; every such wrapper delegates once.
No retry recaptures an installed wrapper. Allocation, preparation and install
failure never claim native body completion. The original stub overrides and
runtime functions are both registered only after lifecycle admission.

Before taking its own recursive `GuestExecutionScope`, dispatch checks authentic
`ps2ActualGuestExecutionDepth`. External/manual calls fall back. The supported
runtime exposes no current-context identity query; this admits normal registered
calls already under the guest owner, not arbitrary external context invocation.
The recursive scope serializes the whole borrow, preparation and commit. Exact
entry PC, non-delay-slot state, runtime/RAM identity and a non-stopping runtime
are required.

## Admitted guest calls

* Signed canonical word arguments in `a0..t3`, SP and RA; requested block count
  **1..512**. Coefficients `t2/t3` additionally lie within signed16. Wider original
  values, despite original halfword truncation, conservatively fall back.
* Encoded `a0`; left PCM `a2`; left history `a3`; right PCM `t0`; right history
  `t1`. Key pointer is the word at **caller SP+0**. Signed multiplier/addend are
  halfwords at **caller SP+8** and **caller SP+16**. All eighteen caller argument
  bytes are protected, including unread gaps; only the halfwords are interpreted.
* Ordinary nonzero halfword-aligned 32 MiB RAM spans: `36*floor(count/2)` encoded
  bytes, `64*floor(count/2)` bytes per output, four bytes per history and two key
  bytes. The full capacity is admitted even if a marker uses less. Count one
  reads/writes no input/output; conservative two-byte aligned/disjoint anchors
  are still required for those three pointers.
* SP aligned to sixteen, with the complete 112-byte dead frame and eighteen-byte
  caller arguments in RAM. RA nonzero, word-aligned, canonical ordinary RAM,
  outside all operand/frame/argument/body/table intervals. Interior entry PCs or
  calls already in a delay slot fall back.
* Every encoded/output/history/key/frame/caller-argument/body/table interval is
  pairwise disjoint. Unsupported original aliases retain original handling.
  The full unsigned16 initial key domain is allowed. No borrowed guest address
  escapes this synchronous invocation.

Native preparation calls the independent typed core and validates its resulting
counts, extents, output sizes, return and history-publication metadata before any
guest mutation. The core owns both PCM vectors. Short input, identity/layout
refusal, exceptions or either allocation failure delegates to the captured
original **once**, with unchanged RAM and context. There is no catch-and-fallback
path after the first guest write. Commit performs no allocation, callback,
scheduler service or suspension.

## Exact frame and selective ABI effects

Both kernels subtract 112 bytes from SP and store incoming low64 `s0..s7` and FP
at new-SP offsets `20,28,...60` (hex). Normal stereo's local words are requested
count at `0`, left/right history pointers at `4/8`, signed multiplier/addend at
`C/10`, completed pairs at `14`, and requested whole pairs at `18`. Downmix has
the same first five words and requested whole pairs at `14`; `18..1F` stays
untouched. Normal `1C..1F` and both `68..6F` gaps stay untouched. Only these
original word/low64 slots are written, rather than clearing/copying the frame.

The adapter publishes only produced PCM. It publishes the key when one or more
pairs completed **or a right marker advanced the left key**. Histories are
published only on normal completion, including count one's unchanged pairs.
Both markers bypass history publication even after prior PCM/key effects. Odd
normal counts return the original requested value while decoding whole pairs
only. Downmix histories remain individual channel values. Disjoint owned staging
allows bulk PCM publication; original cross-plane/key/PCM store interleaving is
not claimed equivalent for aliases or concurrent observers outside guest ownership.

SP, RA, saved registers, upper register lanes and unrelated context remain as at
entry. Defined `v0` and return PC are set; final `branch_pc` is `127FC0` for stereo
and `127C74` for downmix, matching the final JR instructions. Original volatile
GPR/MAC observations and intermediate preemption points are not reconstructed.
The finite bound caps one call at 256 pairs / 8,192 samples per channel:
9,216 encoded bytes and two 16,384-byte output planes. The larger synchronous
region retains the earlier no-intermediate-preemption limitation.

## Checks and activity evidence

```powershell
python -B recomp/overrides/native_adx_stereo/tests/run_checks.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --runtime-headers build-native-sjuni/dependency-workers-reapply-v2 `
  --output build-native-sjuni/adx-stereo-adapter-checks/gcc
```

The same driver supports bundled LLVM/MinGW. Enabled host checks use C++20,
`-O1 -Wall -Wextra -Wpedantic -Werror`. The actual patched runtime-header object
check excludes its existing unused-variable/parameter warnings, and does not
link or execute the real runtime.

**166 positive-count direct lower-kernel cases** (83 per kernel) come from the
frozen independent PCM fixture plus a separate original-word ABI export. Tests
seed the export's exact synthetic history/key addresses, SP, incoming saved-GPR
sentinels, caller arguments and initial frame bytes. They compare all 32 MiB RAM
against expected PCM/history/key and the **actual original final 112 frame
bytes**, including untouched holes; no frame-pointer relocation or native frame
synthesis supplies fixture expectations. Full mock context is compared against
the selective ABI update. Original selector-wrapper cases and nonpositive calls
remain outside this lower-adapter proof.

PCM fixture SHA-256:
`a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0`.
Separate ABI fixture SHA-256:
`2973e5606dfa1eefcc24c5007c55294cec770bb7910983a08293b7408a22e275`.
The driver pins exporter and original engine hashes; original bytes and synthetic
fixture transports are generated only under ignored `build-native-sjuni` output.

GCC and LLVM each pass 33 driver commands, including the actual-header object
compile. Each runs 166 original-fixture full-RAM/context checks, 232 refusal
checks, 40 trace checks and eight allocation/failure-reuse checks, plus the
installation/lifecycle scenarios. Additional host checks cover both missing/wrong original bindings, all four
runtime/stub partial-publication stages, changed bodies/table, stop, manual
calls, runtime/RAM mismatch, allocation refusal followed by success, both modes'
argument/range/overlap refusals, feature absent/zero, File #2 and trace sampling.
These are synthetic lifecycle tests, not real teardown or linked-game evidence.

Separate exact `REO_NATIVE_ADX_STEREO_TRACE=1` enables independent saturating
post-commit counters for stereo and downmix, sampled at calls 1..4 and powers of
two. Installation is logged separately. Refused or original calls never count.
Current small-suite receipts are
`build-native-sjuni/adx-stereo-adapter-checks/{gcc,llvm}-large-bound/receipt.json`.
No speed, audible-quality or complete streaming/lifecycle claim follows from
host checks. Default-off CMake/bootstrap wiring is available through
`REO_BUILD_NATIVE_ADX_STEREO` and the sealed candidate preparer's
`--adx-stereo-adapter`. Bootstrap installs after final function registration.
A controlled linked-candidate test is still required before actual native
activity can be asserted.

The [large original-word corpus](../../../docs/native-media/ADX_LARGE_BLOCK_ORACLE.md)
covers the expanded count bound. The runner in
`../native_adx_block/tests/run_large_checks.py` passes twelve large stereo/downmix
native cases, two count-513 original-once refusals and twelve expanded range/alias
refusals with each compiler. Exact original frames, marker prefixes and
odd-count returns are preserved. No header, selector or decoder arithmetic
change accompanies the bound expansion.
