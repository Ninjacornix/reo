# DTX compatibility layout admission snapshot

Status: independent source and isolated compile/concurrency checks for public
patch `0122-dtx-layout-snapshot-for-native-admission.patch`. No game, device,
runtime library link, full dependency build or active checkout mutation.

The patch adds `PS2_RUNTIME_HAS_DTX_LAYOUT_SNAPSHOT` and
`ps2_syscalls::dtxCompatLayoutSnapshot()` to the actual runtime header. Its
implementation acquires both existing `g_rpc_mutex` and `g_dtx_rpc_mutex` with
`std::scoped_lock`, then returns `g_dtxCompatLayout` by value. The getter does not
call `resetDtxRpcStateUnlocked`, publish PCM state, allocate handles, increment a
counter or write a layout field.

## Qualified source inputs

| Input | SHA-256 / recorded revision |
| --- | --- |
| Pinned upstream base | `c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` |
| New patch | `e3fdf4985998b6f96a5d755d0953603a3d4fc9da723f4b0d9aa1c5d22bd99c13` |
| Prior full122 receipt | `807a1740889dbd4ffccede3074f59d90bfae7088032753f4b805a2dfaa1af475` |
| Fresh full123 receipt | `8f8a001fd50b1bad9c9da8729888b1f682e75c8321bdfd1076da085db52baeb8` |
| Fresh `ps2_syscalls.h` | `f2f69bc7d6e8c01d61ad8166e49ce368b5b009f504ba688976a7ff850dded3d7` |
| Fresh `Kernel/Syscalls/RPC.cpp` | `c3b4a106b41d9d3991de4dbc6a80f68c5c88151e67953f976590f504ed000ee9` |
| Sealed V6 `build-kit.json` | `5457ead9e2fbbc1faa6438a49dead4c20155db3b653756e51c7f39100ff2d504` |
| Existing V6 generation receipt | `57449942f568de9c6f579ee58309d2a50ae16f0cdb69a36b43fbc96329c14e01` |

Fresh source: `build-native-sjuni/dependency-pcm-profile-reapply-v1`.
Prior122 source: `build-native-sjuni/dependency-pcm-dispatch-stop-fence-v2`.
Both recorded HEADs are the pinned upstream base; the public patch series is
applied as the corresponding worktree changes. Every ordered prior patch hash,
all 247 source files and exact file sets are checked against their receipts;
`.git` administration is explicitly excluded. Exactly two source files differ
between122 and123. Removing only the getter/declaration additions recovers the
prior files byte-for-byte after line-ending normalization. Reverse patch
`git apply --reverse --check` passes against123 without altering it. No force
application or checkout/reset is used.

The complete setter, clearer and reset body are unchanged from122. In particular,
the existing setter/clearer each still hold **both** mutexes, assign the layout,
then call `resetDtxRpcStateUnlocked()` exactly once. That existing reset invokes
PCM reset and clears pending/RPC maps; the new getter does not acquire those
effects merely by reading the layout.

## Copy and locking behavior

The real `PS2DtxCompatLayout` currently contains seven `uint32_t` fields:

| Field | Snapshot meaning |
| --- | --- |
| `rpcSid` | Configured compatibility RPC SID |
| `urpcObjBase`, `urpcObjLimit`, `urpcObjStride` | Declared raw object interval/stride |
| `urpcFnTableBase`, `urpcObjTableBase` | Declared guest table addresses |
| `dispatcherFuncAddr` | Declared dispatcher address |

The test includes the **actual fresh123 `ps2_syscalls.h` and `ps2_runtime.h`**;
there is no substitute layout declaration. It asserts the exact return type is a
value, the real type is trivially copyable and its current size is seven words.
Every field is compared explicitly. A caller's input changed after `set` does
not modify stored state; a previously returned snapshot remains unchanged after
another `set` or `clear`; modifying a returned copy does not write the global.

Clear assigns `{}`, so six fields become zero while **`urpcObjStride` returns to
its real type default `0x20`**. It is not a seven-zero-word operation. The cleared
layout fails `isConfigured`, `hasUrpcObjectRange` and `hasUrpcTables` as expected.

[harness.cpp](../../tools/native_reconstruction/dtx_layout_snapshot/harness.cpp)
executes three exact extracted bodies, unmodified. A reset boundary observer
replaces the unrelated full RPC reset implementation only in this small harness;
it checks both mutexes are owned and counts calls. It is not a replacement for
the runtime's real reset implementation. Getter-only reads leave its count
unchanged, whereas set/clear account for their existing calls exactly.

Two independent synchronization configurations run on each compiler:

- Instrumented lock wrappers contain real `std::mutex` objects and expose lock
  attempts for deterministic gates. Holding either required mutex blocks getter,
  setter and clearer until release: six gates. The reset boundary observer
  verifies both locks remain owned during setter/clearer effects.
- A second executable uses ordinary `std::mutex` globals directly and the same
  exact extracted bodies. This avoids relying only on wrapper behavior.

Each configuration performs 40,000 snapshots against 50,000 alternating sets of
two complete, distinct synthetic layouts. Both satisfy the real layout helper
predicates; neither is claimed as an admitted retail/native backend profile.
No mixed/torn field set is observed. Another 1,000 getter-only reads add no reset
calls. There are 50,030 instrumented assertions and 16 additional real-mutex
assertions per compiler. Bounded stress supplements the actual source lock proof;
it is not an exhaustive proof over all thread schedules.

Two negative controls edit only generated ignored method copies: each removes
one getter mutex while retaining the other. Both executables fail the expected
deterministic held-mutex assertion with exit1. Public patch, source checkouts,
headers and runtime objects remain unchanged by these mutations.

## Actual RPC translation-unit compile

The checks also compile the complete unchanged fresh123 `RPC.cpp` to an object.
They use fresh123 headers, the V6 `runtime106` include/define cohort and sealed
V6 SDK/authored geometry inputs. No older runtime library is linked.

Geometry headers use project-root-qualified `third_party/PS2Recomp/...` includes.
Pointing directly at a separate fresh dependency and also adding the old kit
root creates duplicate physical copies of `#pragma once` runtime definitions.
The verifier therefore stages byte-identical fresh123 source at the expected
relative path under the ignored output cohort and compiles that unchanged RPC
copy. Every consumed runtime header is verified against the123 receipt; older
sealed-kit runtime headers are expressly rejected. SDK/geometry includes are
verified against the sealed V6 manifest, not taken from the active checkout.

Two existing File #1 local instruction catalogues are needed transitively by
unchanged source instrumentation headers. The verifier copies only the outputs
qualified by the existing V6 `generate.json` receipt and verifies their generation
inputs against sealed V6 metadata. The receipt identifies the supported ELF hash;
this check does not read or regenerate the ELF. Generated catalogue contents stay
in ignored output and are not distributed in this report. Their identity hashes
and every consumed include path/hash are recorded in check receipts. This is a
narrow qualified generated-include input, not a private header fallback.

GCC emits existing ignored-attribute warnings from `__m128i` template arguments
in unchanged runtime instrumentation. The complete object compile succeeds;
isolated header/method tests compile with warnings as errors. Actual RPC objects
are compile evidence only, not replacement libraries usable with an existing game.

## Admission limits

The snapshot is a coherent copy of a **global host configuration at one instant**.
It is not a runtime identity, session token, raw-handle incarnation, memory lease
or mutation freeze. After the getter releases its locks, another setter/clearer
can immediately replace the configuration and reset associated RPC/PCM state.
No guest objects, pending requests, bank/provider ownership or callback lifetime
are included. The fields' numeric object interval does not prove a finite bound
on retained PCM channels or all reachable voice configurations.

A native backend installer must still bind the actual runtime/build/session,
serialize configuration changes through its publication/lifetime transaction,
register its ExternalWorker before run, establish declared domain bounds and
prove its actual provider fence. Checking this value and later installing without
such serialization leaves a time-of-check/time-of-use gap. This patch supplies
the missing read-only observation; it does not install or authorize a backend.

## Reproduce

```powershell
python tools/native_reconstruction/dtx_layout_snapshot/verify.py `
  --cxx C:/msys64/mingw64/bin/g++.exe `
  --output build-native-sjuni/dtx-layout-snapshot-checks/gcc
```

Use the existing bundled LLVM compiler and an `llvm` child output directory for
the second run. Final receipts are
`build-native-sjuni/dtx-layout-snapshot-checks/{gcc,llvm}/receipt.json`, including
source/patch/cohort identities, exact extracted method hashes, negative controls,
full commands, output and actual RPC object hashes. Both compiler runs pass.
