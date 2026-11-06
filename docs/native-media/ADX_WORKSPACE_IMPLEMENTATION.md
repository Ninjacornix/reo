# Allocation-free ADX workspace implementation and qualification

Status: independently buildable codec dependency, qualified 2026-11-06. There is
no Source2, Window2, controller, runtime adapter or default enable in this change.
It removes allocation from admitted scalar decoding; it does not establish an
audio/game performance improvement or close the rest of native ADXT ownership.

## Implemented boundary

[`adx_workspace.hpp`](../../game/native/adx_workspace/adx_workspace.hpp) exposes
`prepare_into` followed by move-consuming `execute`. Encoded and PCM storage is
caller-owned; no guest addresses, register file, runtime headers, vector result,
thread, callback or retained pointer in the result exists. Preparation performs
bounded raw marker/extent inspection and byte-disjointness/alignment checks.
It writes no PCM/state on refusal. Execution receives State and Parameters by
value and writes only the admitted PCM prefix, returning exact kernel count,
stop side, byte/sample counts, key and selective history commits as values.

The prepared view must remain stable, alive and externally serialized, and be
moved once into execution. Default/copy construction is unavailable; no generic
incarnation or duplicate-use detector is claimed. Calling execute with a
moved-from view or changing bytes between preparation/execution violates the
caller contract. The component is not an owned source credit token. No failure
or original fallback occurs inside an admitted execute.

The [contract](ADX_WORKSPACE_CONTRACT.md) gives the exact expression order and
physical domain: at most 8,228 encoded physical bytes and 8,288 signed16 PCM
samples per plane, with actual source grant limits stricter than backing size.
It preserves original low32 arithmetic, ASR12 and clamp ordering; odd/nonpositive
returns; early marker prefix effects; extra left-key advancement on a right
stereo marker; and clipped-channel-before-7/10 mixing. No host FP or codec
library is used. Frozen mono/stereo/downmix/predictor implementations are not
changed or called by this module.

In the future owner, allocation and full workspace budgeting precede accepted
loop effects; actual input preparation may follow the real loop action and
borrow. The owner must prove its admission invariants or retain an owned fault
after effects. This implementation does not promise a preparation done on stale
pre-loop input remains valid or that preparation can never refuse.

## Honest source freeze

The author had already seen the original scalar/window/shared expectations.
After source-derived implementation and synthetic units, these files were
frozen **before** developing the new projection/comparator:

| File | SHA-256 |
| --- | --- |
| `adx_workspace.cpp` | `72de3d64a21ba50b597e7d6fbf306de302dad18b3283b54f82dbe7f59cb61422` |
| `adx_workspace.hpp` | `3151d276d75ee706d64aca4e63f9d8ee95d649234413849b85f43a4ca58ef68d` |
| `adx_workspace_tests.cpp` | `19443163fe9ee55ad4dfda93b3c9c863b2cbe586b3394babd3674009a501cd4a` |
| `frozen_identity.json` | `b52699a4b76474dccc21f349ba3205c8ad46ed88b4ad8f2052c0f28d7d71da8f` |

Core, header, unit and CMake bytes did not change after that freeze. Both native
comparisons matched on the first attempt; no arithmetic adjustment followed
expected-result inspection. Transport case identifiers normalize names with
spaces; no expected PCM/state is sent to the compiled probe.

## Original evidence and comparisons

Authority remains owned File1 ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The new original generator freezes authored input and source-entry projections
before expected observations. It reuses unchanged mono/stereo EE/MAC/division
engines and complete original kernel words. New synthetic output allocation
geometry and request registers are set before the first original instruction;
no old engine bound/global is changed and no loop is teleported.

`build-native-sjuni/adx-workspace-original-v1` contains:

| Artifact | SHA-256 |
| --- | --- |
| `inputs.json` | `fc4531a4c31260772b3c421098e3a60004cd0d329181959ec4728a9a7aa696ee` |
| `expected.json` | `decdcf4a2ac9b7fe3446671dcbcfe0989437fc1cb0324b0acc328edcc64caecb` |
| `manifest.json` | `7eca662e783d19646bcbcf7d4dd3b9c490ce0b3678c3626f65f20d203d2addb5` |
| `projection-validation.json` | `83125bf0b09cc816403d1ab9074d993873c72690fabdc35a61b7b9c34ec44d82` |

All **901 cases pass under both GCC and LLVM**: **890 admitted** and **11
physical-profile refusal controls**, comparing **437,440 PCM halfwords**.
Breakdown:

| Source | Cases / observation |
| --- | --- |
| Frozen scalar/large fixtures | 104 mono + 522 stereo/selector/downmix + 21 large = 647 rows; 636 fit the workspace profile, 11 deliberately do not. Their original observations remain unmodified. |
| Window1 projections | 38 actual kernel entry media/state profiles. |
| Shared39 projections | 196 actual kernel entry profiles, including full requests, long streams, key/history changes and seamless headers. A codec reached before a later source partial is qualified only as that codec input, not a successful enclosing transaction. |
| New authored edges | 20 direct original-word cases: mono 259-block PCM edge, stereo 228-pair physical edge and odd 457 return, stricter 227-pair actual-source extent, 1,152/2,240/2,432 full requests on each route, huge requested counts stopped by 2/20-byte markers, and long prefix/right-marker cases. |

The **254 newly replayed direct calls** execute **8,679,227 original
instructions**. Including admitted reused observations, the fixture represents
11,154,368 original instructions. Original output/state is never supplied by a
native decoder. Refusals are explicitly new physical admission policy, not a
claim the original routine refused those calls. Oversized old output capacities
are represented by the minimum out-of-profile 8,289-sample native refusal span;
the original larger allocation/results remain in their frozen source fixture.

The comparator checks exact raw return, complete PCM capacity including untouched
suffix, input immutability, guards, key/history and selective commits, completed
work, and consumed/inspected extents. Expected marker side derives from actual
original history/key writes. Consumed bytes and samples project the observed
original PCM store count through fixed 18-byte/32-sample geometry; no Python
predictor or sample decoder is implemented. Full guest frames, volatile GPR/MAC
contents and intermediate scheduling are outside this typed value contract.

The projection audit separately executes **all 72 original Window1/Shared39
transcripts, 6,628,676 instructions**, capturing raw media at each actual codec
entry without changing words/state or supplying codec results. All **234
entries** match the frozen reconstruction, closing the assumption about possible
encoded writes earlier in the enclosing operation. It does not infer isolated
kernel PCM by reversing later wrap/publication; each projected input is instead
replayed through the real original direct kernel.

## Host checks and receipts

GCC 15.2 and LLVM 21.1.7 each pass **284 assertions** with **zero allocation
attempts**, including ordinary/array/aligned allocation denial over admission
and execution, before-effects short spans/aliases, raw signed counts, partial
marker state, physical edges, guards and real request sizes. Both standalone
CMake/Ninja builds and **CTest 1/1** pass.

| Receipt | SHA-256 |
| --- | --- |
| `build-native-sjuni/adx-workspace-host-v1/qualification.json` | `cad31eb8999fd325e60c3a5cf00b17931bfeedef704877ae8316a430365ab294` |
| `build-native-sjuni/adx-workspace-parity-v1/gcc/receipt.json` | `4943b867d749952f1df5243f4932855931c3d8d80608204bcb56b6b0359eee60` |
| `build-native-sjuni/adx-workspace-parity-v1/llvm/receipt.json` | `d5a43592a18ac2ca61533ec864655996c1e022a756d80b0a1e8f57037912e361` |

CMake CTest logs are under
`build-native-sjuni/adx-workspace-cmake-v1/{gcc,llvm}/Testing/Temporary/LastTest.log`.
Qualification artifacts are bounded PCM/state records, not full RAM dumps.
No game, actual provider, audio device, runtime build, bootstrap or default
selection changed. Source2 ledger/target ownership and Window2 integration still
require their own qualification before this dependency can replace a live path.

## Additional bundled UCRT LLVM qualification

The earlier LLVM rows above used **PATH LLVM 21.1.7** at
`C:/msys64/mingw64/bin/clang++.exe`, compiler SHA-256
`1a8a4bd52c0eb56a4b95aa21865f1d6733b38b7eb1cd76263ad5349019da890a`.
They are preserved evidence and must not be labeled the launcher's bundled
compiler. A separate added cohort uses the actual bundled **UCRT LLVM 21.1.8**:

```text
C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/
llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe
SHA-256 f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3
```

The bundled bin directory is prepended to **every child PATH**, including probe
and CTest runs. The receipt records version 21.1.8, target
`x86_64-w64-windows-gnu`, resource directory, exact commands/output hashes and
unchanged source freeze. This added compiler passes **284 unit assertions,
zero allocation attempts, 901/901 original comparisons and standalone CMake /
CTest 1/1**. Frozen core/header/unit/CMake bytes and all old receipts remain
unchanged.

Additional receipts under `build-native-sjuni/pinned-adx-qualification-v1`:

| Artifact | SHA-256 |
| --- | --- |
| `workspace/qualification.json` | `8c81581645e77c1f6d1e5091525ac9d06a43ebcb6a3ffdcbe6b15114a7e60e40` |
| `workspace/parity/receipt.json` | `29ec74cbeba55b1200418e1aff25c521b5b8896901eec35ed801d89dc15e3a43` |

The matching added header-native and actual emitted-FP qualifications are
recorded in [header implementation](ADX_HEADER_IMPLEMENTATION.md) and
[original math proof](ADX_HEADER_MATH_ORACLE.md); their compiler provenance is
kept separate from the older PATH results.

The parent `game/native` project includes this as its twenty-eighth standalone
suite. The selected `adx_workspace` test also passes in both parent Release
builds (`build-native-sjuni/cmake` with GCC 15.2 and `cmake-llvm` with the bundled
UCRT LLVM 21.1.8). No other frozen component needed changes for this integration.
