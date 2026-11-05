# Guarded File1 picture-position adapter pilot

This separately compiled pilot binds original `16F338` only when built for
File1 with `REO_BUILD_NATIVE_MOVIE_POSITION=1` and exact
`REO_NATIVE_MOVIE_POSITION=1`. It has **no bootstrap, CMake or candidate-preparer
wiring**, so existing V7 builds do not include or enable it. It does not replace
movie clocks, change speed, select rendering paths or establish a stutter fix.

Production files are
`recomp/overrides/native_movie_position/runtime_adapter.{h,cpp}`. Numerical work
calls the independently qualified `game/native/movie_position` core exactly once
after admission and before the first guest write. The frozen original fixture
remains `build-native-sjuni/movie-position-oracle-v1/original-fixture.json`, SHA-256
`232d07ee2991cb07f25bc65247db597aa2a85f6080ef8d1bff47c45b5fa94822`.

## Admission and caller contract

* Install is pre-run only, through the matching runtime external-worker gate.
  A no-thread lifecycle token permanently disables native admission on stop.
  The process captures one Runtime/RAM identity; another runtime cannot replace
  it. Function/stub publication failures leave native admission disabled.
* A call must enter from an already-held authentic guest-execution scope.
  Adding a recursive scope does not manufacture that eligibility. Runtime/RAM,
  stopping state, exact entry PC and all qualified function bindings are checked
  again before preparation. Out-of-profile work calls the captured original
  function exactly once before adapter RAM/context effects.
* Five original arithmetic/getter bodies, the known caller and following callee,
  plus the36-byte rate and256-byte quotient-normalization tables are SHA-256
  checked at install and dispatch. All seven expected function registry pointers
  must still identify those actual original generated functions; the target alone
  changes to the adapter after installation. An unrelated override is not an
  admitted provider. Exact hashes/ranges are recorded in the adapter source.
* Only normal physical32MiB RAM, verified through BOTH compile-time size and
  actual `ps2RamBackingBytes` before image/table reads, and bounded aligned source/descriptor/stack spans,
  canonical lower64 pointer/SP/RA arguments and a non-delay-slot entry are
  admitted. The nine-rate index is checked before numeric work, even if the
  disabled side-input path would not read that index in original code.
* The main pointer must be present in the original eight-slot registry at22F18C
  with nonzero state. This is current scoped membership, not an invented lifetime
  generation. No native pointer is retained across the call.
* Only the reviewed caller return `16EDF8` is admitted, with a0==s3 and the
  descriptor equal to caller stack[SP+30]. Original `16EC90` sets that return at
  `16EDF0`; after return it reloads a0/a1/a2 before calling `16F438`, without
  consuming v0 or relying on the preceding function's volatile scratch state.
  Unknown callers and partial continuation entries retain original execution.

## Defined embedded layouts and selective effects

The original `16F798` constructor sets main1B30=main+1F00. `170630` reserves
private picture records at backend+13C with80-byte hexadecimal stride; configured
count is admitted only in1..16. Therefore the backend may be embedded in the full
main allocation, and the descriptor is embedded in the backend. Treating either
entire containing object as disjoint from its child would reject the real layout.

The pilot instead qualifies these exact structural embeddings. The main accessed
prefix through1B34 and complete backend extentA0C are disjoint. The descriptor is
an exact configured private-slot address with a bounded80-byte hexadecimal
extent. All sixteen slots end before getter fields9D8/A08, so writes cannot
change their own source observations. Arbitrary descriptor/backend aliases,
source/stack aliases, code/table/registry overlaps, invalid slots/counts and
out-of-table indices are refused. Caller frame[SP,SP+90) and child frame belowSP
remain disjoint from source objects and protected code/data.

The owned original instruction-body closure is ordinary-RAM arithmetic after those
qualified bindings: getters, product/ratio and signed quotient have no device,
callback or guest-release operation. The current runtime's lookup records
dispatch history but does not itself schedule guest work. The adapter holds
guest execution throughout prepare/commit. This supports the scoped final-state
pilot; it is not proof of instruction-level interleaving or observer equivalence.

The commit recreates the original `0x30`-byte frame's saved lower64
S0/S1/S2/S3/RA slots at0/8/10/18/20; bytes28..2F remain untouched. When the actual
side-input flag is nonzero it also writes the nested `0x10`-byte helper
frame's RA16F3E8 at SP-40hex; its other8 bytes remain untouched. Full10FB18 has no
store instructions and adds no stack writes. Disabled side input adds no helper
frame. Only final descriptor10/C/20/24 and conditionally mainF00/F04 are committed.
Raw final v0 is sign-extended exactly; final PC is16EDF8 and branch PC16F42C.
All other context fields, including incoming volatile GPR/MAC observations, are
left alone. This is a selective ABI result, not complete scratch-register parity.

Original intermediate descriptor writes/overwrites are not reproduced. Neither
instruction-level scheduler/preemption behavior nor diagnostic dispatch history,
arbitrary caller semantics, upper-lane intermediate values or asynchronous
external observation is claimed equivalent. The pilot must remain guarded and
default off unless a future integration qualifies its real caller/lifetime and
runtime/library cohort. A runtime object compile is not that live qualification.

## Independent host checks

```powershell
python tools/native_reconstruction/movie_position_adapter/run_checks.py `
  --cxx g++ --output build-native-sjuni/movie-position-adapter-v2/gcc `
  --runtime-headers build-native-sjuni/dependency-pcm-boot-reapply-v3

python tools/native_reconstruction/movie_position_adapter/run_checks.py `
  --cxx clang++ --output build-native-sjuni/movie-position-adapter-v2/llvm `
  --runtime-headers build-native-sjuni/dependency-pcm-boot-reapply-v3
```

The runner reuses unchanged ADX runtime mocks through an adapter-owned wrapper
that adds only the actual-backing-size variable. Only isolated mock compile flags
put this wrapper first; actual-header object flags use the124-patch reconstructed
dependency directly. The original frozen fixture remains unchanged.
The25 original numerical cases are mechanically adapted to the admitted caller:
RA/S3 saved slots, argument stack slot, registry membership, configured pool
metadata and descriptor relocation into its private slot. No arithmetic expected
value is recomputed from the native core. One additional relocation checks the
real main+1F00 backend embedding. Final RAM expectations still come from original
before/after snapshots with only those declared address/ABI substitutions.

For each of the26 admitted cases, the harness compares the entire32MiB RAM and
the selective context result, retaining frame holes, surrounding bytes, caller
frame and unrelated context sentinels. Full RAM is compared in memory; **no
per-case32MiB dumps are written**. Sparse wire inputs/expected deltas and hashed
receipts retain the reviewable evidence. The complete two-compiler output was
about1.8MiB at inspection, rather than multi-GiB fixture duplication.

Twenty-nine refusal variants verify original-once fallback with unchanged RAM
and context on original entry: pointers/extents/alignment/canonical form,
caller/continuation/delay context, aliases, bad rate indices, unregistered/cleared
main, and invalid private-slot count/stride/bounds. Other scenarios cover default
off, image/table/registry changes, stop, manual entry, Runtime/RAM mismatch,
one-shot ownership, repeated install, partial publication failures and sparse
postcommit proof. Numeric-zero/not-built/File2 configurations stay disabled.
New scenarios verify64MiB refusal at install without registry/worker publication
and64MiB post-install original-once fallback with unchanged RAM/context at original
entry. Both compilers also compile the adapter against the actual reconstructed matching
runtime headers; no replacement runtime library is linked.

On2026-11-05 the updated GCC and LLVM checks passed29 command/run checks each.
Receipts are `build-native-sjuni/movie-position-adapter-v2/{gcc,llvm}/receipt.json`;
they contain source/compiler/header hashes, sparse wire hashes, commands and
stdout/stderr. No game/full build, native clock migration or runtime integration
was performed, and existing core/bootstrap/build preparation files were untouched.
