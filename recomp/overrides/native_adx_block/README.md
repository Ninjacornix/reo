# Guarded keyed mono ADX block adapter

Status: implemented and host-tested with default-off build/override wiring;
linked-candidate and live game-call validation remain pending. This adapter replaces only original File #1 US `main:001276D8` when
every admission below succeeds. It does not change SJ, ADXB/ADXT, RNA, media clock,
loop, pause, stop, refill or voice policy.

Build `REO_GAME_FILE1` and numeric `REO_BUILD_NATIVE_ADX_BLOCK=1`, then call
`reo_native_adx_block::install(runtime)` after final ELF/function registration and
before first run. Exact environment `REO_NATIVE_ADX_BLOCK=1` is independently
required. Absent/zero build feature and File #2 provide an inline false installer.
The post-registration bootstrap installer reports failed installation rather
than infer activity from a saved option.

## Identity, installation and lifetime

The installer requires the actual generated original function pointer
`sub_001276D8_0x1276d8`, not merely an occupied registry entry. It captures that
pointer before publication, along with one runtime and its exact RDRAM pointer.
Missing/wrong initial binding fails without claiming the process owner, so an
early apply pass can safely retry after function registration. An accepted owner
is one-shot; reload, second-runtime adoption and pointer-address reuse are refused.

The complete resident kernel `1276D8..1278B4` (exclusive end) must hash to
`f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115`;
the owned 64-byte nibble table `239BE8..239C28` must hash to
`67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f`.
Both are rechecked before each native preparation. The underlying independent
[kernel oracle](../../../docs/native-media/ADX_DECODE_ORACLE.md) pins the owned
ELF and complete 119-word body. No other codec or function is admitted by name.

A tiny `PS2Runtime::ExternalWorker` token uses the actual public runtime
registration gate to refuse installation after execution/stop starts. It has no
thread; `requestStop` permanently disables native dispatch and `join=true` is
valid because no private worker or borrowed payload survives a synchronous call.
Runtime teardown must join guest host threads first, as the matching lifecycle
patch does. This token does not track arbitrary external/manual calls or certify
their lifetime. The runtime strongly retains the token. Registration/allocation
failure leaves the original binding, or a disabled published wrapper which
delegates to its already captured original once. No retry can recapture itself.

Before adding its own recursive guest scope, the wrapper checks the runtime's
authentic `ps2ActualGuestExecutionDepth`. Non-guest manual calls fall back. The
runtime has no public current-context-identity API; this admits normal registered
calls made under the existing guest owner, not arbitrary external context use.
Exact entry PC, runtime/RAM, current wrapper binding and non-stopping runtime are
also required. Installation itself is serialized by guest execution.

## Initial admitted call domain

* Canonical sign-extended word arguments in `a0..t3`, SP and RA; count `1..16`.
  Register coefficients `t0/t1` and key multiplier `t3` additionally lie in signed16
  range. The original truncates these through shift/sign-extension; wider inputs
  intentionally retain original handling. Addend is the original signed halfword
  at **caller SP+0**; its following bytes are not interpreted or changed.
* Ordinary non-null 32 MiB RAM spans: encoded `18*count` bytes, output `64*count`
  bytes, history four bytes and key two bytes, all halfword aligned. Full capacity
  is checked even if an early marker would use less. Input is borrowed only
  during the synchronous native decode.
* SP is 16-byte aligned, with its complete 80-byte dead frame and addend halfword
  inside RAM. RA is a nonzero, canonical, aligned ordinary-RAM address, outside
  all operand/frame/argument/text/table spans. Calls already in a delay slot or
  at an interior PC fall back.
* All encoded/output/history/key/frame/addend/text/table ranges are pairwise
  disjoint. Aliased original behavior is preserved through original fallback;
  no native alias equivalence is assumed. The original key's full unsigned16
  initial domain remains allowed, including values above `7FFF`.

The bounded native [core](../../../game/native/adx_block/adx_block.hpp) produces
newly owned PCM and result state entirely before guest publication. Allocation,
short input, limit, argument or identity refusal falls back exactly once with
unchanged input context/RAM. There is no fallback catcher around commit. The
commit has no allocation, callback, suspension or guest service call.

Original dead-frame effects are retained: nine lower64 stores of the incoming
`s0..s7` and FP at `SP-80+[0,8,..64]`. The last eight frame bytes remain untouched;
SP, callee-saved GPR values and their upper lanes remain preserved. Commit writes
only produced PCM, key when at least one block completed, and history only when
the original normal-completion path publishes it. A marker after prior blocks
retains prefix PCM/key while leaving the whole external history unchanged. A
first marker writes neither key nor history. Defined v0 and return PC are set,
with original final `branch_pc=1278AC`. Volatile GPR/MAC observations are not an
ABI contract and are not reconstructed. Instruction-level preemption timing is
also not reproduced; the initial bound limits one call to 512 PCM samples.

## Activity evidence and verification

Separate exact `REO_NATIVE_ADX_BLOCK_TRACE=1` enables a saturating atomic body
counter emitted **after commit** for calls 1–4 and powers of two. Install notice
and native body count are separate. Disabled/uncovered/refused calls do not count.
No per-sample logs or speed claims are made.

```powershell
python recomp/overrides/native_adx_block/tests/run_checks.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --runtime-headers build-native-sjuni/dependency-workers-reapply-v2 `
  --output build-native-sjuni/adx-adapter-checks/gcc
```

The same driver passes with bundled LLVM/MinGW 20251216 and its scoped runtime
DLL PATH. Each compiler completes 27 checks, including actual patched-header
object compilation with no runtime link. Enabled mock builds use C++20, `-O1`,
`-Wall -Wextra -Wpedantic -Werror`; real-header mode excludes existing runtime
unused-local/parameter warnings.

The independent frozen 104-case fixture contributes **101 positive-count cases**
to this narrower adapter. For each, tests compare all 32 MiB RAM against expected
PCM/history/key plus exact original frame saves, and the full mock context against
the selective ABI update. Its three nonpositive cases deliberately remain outside
this pilot. Additional checks cover 83 argument/overlap refusals, allocation
failure then successful reuse, actual-scope admission, disabled/numeric-zero/
File #2 builds, exact/mutated body/table, binding/RAM/runtime mismatch, late
registration, publication failure, stop and trace sampling.

Receipts: `build-native-sjuni/adx-adapter-checks/{gcc,llvm}/receipt.json`. Identity
bytes and synthetic expected-value transports live only in ignored output; no
original instruction arrays are committed. These checks do not establish a linked
game candidate, game-call activity, a performance gain, complete streaming/stop
parity or behavior outside the stated admitted domain.
