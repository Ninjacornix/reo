# Runtime bank capture: qualification and remaining lease boundary

Status: source-only review of the final125 reconstruction and current authored
adapters. No runtime CaptureSource factory, game run, device access or source
mutation is performed by this review. Identity fields and positive guest depth
alone are insufficient to select the native bank backend.

## Qualified inputs

Final125 checkout is `build-native-sjuni/dependency-bank-reapply-v3`, base
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`. Full-reapply receipt SHA256 is
`3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a`;
public0124 patch SHA256 is
`1c08f9667edee15dbeeb0e332b12473d0ae77433519dde22c32e1c329f7fa377`.
The earlier125v1 header evidence in the packet adapter's historical cohort1 is
not substituted for these final control paths.

Relevant final125 source identities:

| Source | SHA256 |
| --- | --- |
| `ps2_runtime.cpp` | `c800ae703c4ffb973991654593314d53330aabf4062722a5f9ef4ee4f1bf278d` |
| `ps2_runtime.h` | `eba72ce2d25e3a82e6a3026195f2f4b3b624bea83d3d571c67ab0da5c59cfa1e` |
| `Kernel/Syscalls/RPC.cpp` | `51f17d2c361c7208264fe774095b0911f44b58a05555c52dbbe677ea3f07c88f` |
| `Kernel/Syscalls/Helpers/Runtime.h` | `295695b54a30ed43b3f484df492277a6d66ceefa8b024dfb4bef801c678b3ff6` |
| `Kernel/Syscalls/Helpers/State.h` | `4cab412ab2c6a54e3ff14a6f619ce61c850cae8e3b80d92d86c3bef22eb1b4b8` |
| `ps2_iop.cpp` | `c8d942c50b4f9baa39593d23c956041ef4e65311b932b0ff50539488ab8a133a` |
| `ps2_memory.cpp` | `8e89a7143b7037dffd6de139ba8fcc48d0200b042ce51d4716b784e26d6cd2ea` |
| `source_instruction_access.hpp` | `8ab696f5b6c2949f37963023f210c7b1048e1a07977c236fb953e766dd720a7f` |
| `parent_natural_dispatch.cpp` | `e2ac997392a359a461d50cb1763f834296303bd158b33fee8f53687d3baf0ddf` |

Authored RAM-writer/canonical-source paths also inspected:

| Source | SHA256 at review |
| --- | --- |
| `recomp/overrides/reo_cd_async.h` | `4125d30beb465e7882e6f01864162a27873a1d4c74ffc7001a6587248a625fd2` |
| `native_cd_owner/runtime_adapter.cpp` | `bc7eb7ec0436eeefc6e1921fa636031480bb79c0ef74625bb75ea1b0efb14c39` |
| `native_resource_reads/runtime_adapter.cpp` | `f7fa81bf432f6c5d54d71aefc569443fdb88d8d84070fc66c88d216bd50df00e` |
| `reo_hw_bridge.cpp` | `cddc54d725edf9826a3338beff682ebd9a6132d5380406c6c72e0c0e3b444b7c` |
| `natural/native_owner_target.hpp` | `bc1f1ebd7569e0e7d6097304da35348a0b4f742f8ccd8e726e787df20217e1dc` |

## What guest execution actually excludes

`GuestExecutionScope` calls `enterGuestExecution`/`leaveGuestExecution`.
The real implementation (`ps2_runtime.cpp:740..787,2678..2745`) maintains a
thread-local map of actual recursive depth for each Runtime, backed by that
Runtime's recursive guest mutex. `ps2ActualGuestExecutionDepth(runtime)` observes
this map; it does not synthesize ownership or acquire the mutex. ReleaseScope
unlocks EVERY held level and removes the depth entry, then reacquires after its
body. A positive value therefore means this thread currently holds that guest
mutex, not that all host writers obey it.

Main dispatch holds the scope (`ps2_runtime.cpp:2611`), as do guest host-thread
loops (`Thread.cpp:474`), alarm callbacks (`Helpers/Runtime.h:222`), interrupt
callbacks (`Interrupt.cpp:305,415,433`) and RPC guest callback invocation
(`Helpers/Runtime.h:388`). Their ordinary CPU stores and synchronous file/CD
reads exclude one another while the scope remains held. `fioRead` reads directly
into guest memory at `FileIO.cpp:190..225`; ordinary `sceCdRead`/chain/stream
helpers synchronously pass guest destinations to the reader. These functions do
not themselves acquire a guest scope: they rely on their actual guest caller.

Guest waits deliberately release the scope. `waitReleasingGuest`
(`Helpers/Runtime.h:23..42`) explicitly drops its host mutex before guest
reacquisition because reversing this order deadlocks. Async VIF drain similarly
drops the FIFO mutex, releases guest execution, waits, drops FIFO ownership and
then reacquires guest execution (`ps2_memory.cpp:106..120`). Parent/source
control waits also have explicit ReleaseScopes. A capture provider cannot call
an arbitrary flush/wait and assume the initially observed depth protected its
bytes throughout that operation.

## Actual sound entry paths and lock ranks

`SifCallRpc` is called as a guest syscall/override. It does not construct a new
GuestExecutionScope itself. The normal guest caller already holds the scope;
it takes recursive `g_sif_call_rpc_mutex` at `RPC.cpp:1628..1630`, classifies the
sound SID/RPC and retains one SoundCall before the sound transport payload copy.
The command helper takes `g_rpc_mutex` at `RPC.cpp:463..486`, performs driver
adoption/status work, ensures output and enters the packet callback while that
mutex remains held. There is no ReleaseScope in that command helper or the
bank packet/core path.

The direct `ps2_iop::handleRPC` path calls public
`handleSoundDriverRpcService` (`ps2_iop.cpp:21..43`, `RPC.cpp:572..590`). Neither
function acquires guest execution. A host caller of that API can have depth0.
The bank factory must refuse that context before source capture; it must not
try to acquire guest execution while already under an RPC mutex. Public bank
queries without guest input can have a separate host-safe typed state path;
that does not authorize direct guest RAM reply writes.

The normal order relevant to capture is:

1. Existing actual guest execution ownership.
2. `g_sif_call_rpc_mutex` for the syscall path.
3. Outer SoundCall ownership; registry locks are short snapshots, not held
   across backend or memory callbacks.
4. `g_rpc_mutex` for command/adoption work; DTX controls have their separate
   documented `g_rpc_mutex`/`g_dtx_rpc_mutex` handling in final125.
5. Adapter transaction for owned prefix/query/reset/mix, then inner bank data
   lock. Producer capture/decode releases adapter transaction, but the caller's
   guest and RPC ownership remains held.
6. Pure gain-provider reads during bank mix. Asset allocation/free may occur
   on control paths under transaction; its provider must be nonreentrant.

CaptureSource callbacks run outside adapter transaction. Its factory should
observe existing guest ownership, never acquire guest under `g_rpc_mutex`, and
never acquire `g_rpc_mutex` from a gain/allocation/provider callback. Output
callbacks must use their already-admitted aggregate render and cannot acquire
guest execution or wait for a producer to complete.

## Concrete counterexample: asynchronous CD writes bypass guest ownership

Both current asynchronous CD routes write actual guest RAM before taking guest
execution:

- Legacy `reo_cd_async::complete`, `reo_cd_async.h:67..88`, invokes
  `readCdSectors(...,ram)` on its detached host worker, then takes a guest scope
  only for completion callback execution.
- Scoped `native_cd_owner::Session::perform`, `runtime_adapter.cpp:75..86`,
  invokes the same read before its completion GuestExecutionScope. Its owned
  stop/join lifecycle improves lifetime; it does not serialize that payload
  write against an EE reader.
- `ReoHwBridge::readCdSectors`, `reo_hw_bridge.cpp:2565..2572`, passes
  `rdram + physical_destination` directly to `read_sectors`. No guest mutex or
  bank region lease encloses that write. Bounds/lifecycle checks do not establish
  nonoverlap with arbitrary bank descriptors.

Therefore an EE with depth>0 can copy an overlapping HD/BD/TQ range while that
worker writes it. This review has not reproduced such an overlap in gameplay;
the source counterexample is enough to reject a general coherence claim.
The parent reports V7/V8 configured both async modes0, but those test settings
are not a reusable runtime capability. Do not silently disable a game path or
infer writer quiescence from an environment string, a current empty queue or a
stop flag. An already-started writer can still own memory.

The synchronous native-resource reader is different:
`native_resource_reads::configure` requires `REO_CD_ASYNC=0`; `tryRead` checks
the actual Runtime/RAM and real guest depth, then writes synchronously under
that caller (`runtime_adapter.cpp:196..220`). Its ReadLease counts provider
calls for lifecycle. It is not a general exclusion lease against a separately
enabled asynchronous CD writer.

Other identified writers include guest libc copy/fill/file reads, synchronous
memory-card reads, RPC copies/zero/status replies, ADX/movie adapter commits,
and synchronous SPR-to-RAM DMA (`ps2_memory.cpp:1218..1256`). Their relevant
production call paths execute on guest/interrupt scopes. GPU/raster targets
mostly use distinct VRAM/VU/owned buffers; their source ownership still matters
even when no physical RAM write is observed. This is a bounded current-source
writer inventory, not proof about arbitrary external HwBridge callbacks or
future modules. Such extensions must join the same declared writer profile.

## Canonical source reads are another boundary

When native parent/graphics source ownership is active, physically mapped RAM
can contain stale numerical data that is deliberately opaque to CPU code.
`ps2ParentBeforeFastRead` routes to `ControlTarget::read`
(`parent_natural_dispatch.cpp:116..129`). `NativeTarget::read`
(`native_owner_target.hpp:1480..1499`) checks held/pending accesses and upstream
opaque ranges under source/protocol mutexes. The gateway's raw read hook rejects
overlaps with opaque RAM; it does not authorize CPU reconstruction of those
numbers. Real current Context/source-entry ownership is also required.

`copyBytesForBank` is an existing canonical-access helper
(`source_instruction_access.hpp:193..208,247..249`), not a ready budgeted lease
for this adapter. In its owned branch it:

- requires real source Context and guest scope;
- invokes a point read guard, whose mutexes are released on return;
- allocates an ordinary temporary vector, outside the v2 asset/control
  allocators, and limits transfers to1MiB while a bank part may be2MiB;
- can request Runtime stop/throw an OwnedSourceFailure on an opaque/invalid
  source access.

The examined point-read path checks/refuses; it does not itself flush GPU work
or retain a bulk read permit across caller memcpy. A generic flush elsewhere
can release guest execution. Neither a successful earlier check followed by
unqualified memcpy, nor chunking this helper and ignoring its allocations,
establishes the requested budget/coherence contract. Existing guarded-read
machinery is useful source evidence, but no general allocation-free
`copy_canonical_into_owned_span` or region read lease is exposed here.

## Minimal implementable qualification and missing APIs

A conservative first factory can be specified, but is not issued by current
identity fields alone. It requires an actual sealed setup receipt tied to:

1. This started executable/build and Runtime; actual32MiB RDRAM/backing and
   its incarnation; the outer registered owner retaining that mapping through
   the complete accepted SoundCall.
2. Actual guest depth>0 on the same host thread for each bounded copy, with
   no nested guest release, callback, I/O or flush in the copy operation.
3. An actually configured synchronous RAM-writer profile: asynchronous CD
   routes never started/registered for this session, not merely disabled now.
4. Canonical CPU-owned source storage. A conservative profile must exclude
   active/pending parent source ownership through its actual setup contract;
   a current no-target lookup alone is not a lifetime capability.
5. Complete packet/bank ranges in that exact RAM backing, acquired before
   capture. Unqualified host pointers from direct submitBank require a separate
   immutable host-asset lease or refusal; generic address plausibility is not it.

Current async `configure` APIs return void and keep active/session state private.
Their booleans/environment settings do not expose a reusable sealed writer
receipt. The guest-depth observer is real, but supplies no asset-region claim.
Those facts are why this review does not implement a supposedly qualified
RuntimeCaptureSource factory yet.

For broader coexistence, add a real writer/read protocol: async CD reserves
each destination range BEFORE task publication, retains it through actual I/O
and release, and a reader obtains a nonoverlapping range claim before copying.
All relevant writers must participate. A conflicting packet read must refuse
before effects; a conflict at a later bank command retains the accepted prefix
and reports refusal without legacy replay. Waiting for an overlapping writer
while holding guest/RPC ownership can deadlock against completion needing those
same locks. An immutable asset snapshot supplied by its typed loader is another
valid boundary.

Active parent ownership needs a separately qualified canonical read/copy
operation into an already-budgeted destination. Its source owner must retain
the actual range/epoch/source admission throughout copy, honor opaque refusal,
and avoid unbudgeted temporary vectors. A point guard is not that API. If a
required source fence needs guest release, it must occur at an explicit earlier
boundary outside RPC critical sections, with an actual retained range claim
covering the gap; do not hide it inside CaptureSource.

Finally, `runtime.isStopRequested()` is not a RAM incarnation change. Final125
Runtime teardown joins registered workers before destroying/reinitializing
memory; an accepted outer call can finish while stop is already set. Factory
admission must reject NEW outer calls after stop, while retained accepted
capabilities remain valid until outer drain. Only then stop/join the adapter and
inner sessions. Reset of native bank epoch is separate from RAM identity and
still prevents stale prepared-bank installation.

Until these actual configuration/read capabilities are supplied, keep native
bank runtime selection unavailable. Preserve existing game/render paths and
report the unclosed capture boundary explicitly.
