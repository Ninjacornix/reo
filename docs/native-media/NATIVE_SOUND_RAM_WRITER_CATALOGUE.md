# Native sound RAM writer catalogue

Status: source audit for the first conservative capture profile. No game,
device, sampler or binary decompiler was run for this audit. SDK references
below mean the exact fresh126 source in
`build-native-sjuni/dependency-ram-reapply-v5`, not the dirty active dependency.
The receipt SHA256 is
`2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0`.

## Findings that affect admission

`ps2ActualGuestExecutionDepth(runtime)>0`, synchronous CD configuration and no
advanced parent Service do **not** establish authority over arbitrary32MiB EE
spans. The actual Pad2 feeder is a separate host writer without the guest lock.
Its registration mutex originally protected address publication, then was
released before the work word and socket records were written. A release fence
on the sequence field is not a reader/writer reservation.

The new cooperating Pad writer closes that specific edge when the actual bridge
and the parent Service are compiled coherently with capture flag2 and use the
same v2 coordinator. Flag0/1 still has the original independent Pad writer and
must not qualify this capture profile. See
[Pad coordination](PAD_RAM_CAPTURE_COORDINATION.md).

Async CD is another confirmed writer outside guest execution: both original
detached completion and native CD owner call `ReoHwBridge::readCdSectors`
**before** acquiring `GuestExecutionScope` for the callback. The actual
configuration receipt/seal must exclude that worker mode; an environment string
or a momentarily empty queue cannot do so.

The bridge's RDRAM-backed VU aliases are real, but the SDK async VIF worker uses
separately allocated VU1 buffers. This audit did not establish an async SDK
worker→bridge-interpreter→EE-alias write edge. Conservative VU aperture refusal
is appropriate; describing those EE aliases as proven SDK async destinations
would conflate two implementations.

## Actual execution boundary

SDK `ps2_runtime.cpp::dispatchLoop` retains real `GuestExecutionScope` around
guest steps. SDK `Kernel/Syscalls/Thread.cpp::StartThread` does the same for each
guest host thread. INTC/DMAC handlers in `Interrupt.cpp`, VBLANK dispatch and
alarm callbacks in `Helpers/Runtime.h` explicitly acquire it before executing
guest code. `rpcInvokeFunction` also acquires it before callback setup/dispatch.
Generated/registered game functions, handwritten synchronous overrides and
their synchronous library calls therefore share this admission boundary when
entered through those actual paths.

That is conditional caller evidence, not an intrinsic property of `memcpy`, a
function name or a public SDK method. Direct native/test/plugin callers that
invoke a guest stub or memory API outside those paths remain unsupported.
`GuestExecutionReleaseScope` deliberately releases **all** recursive levels in
blocking/yield paths. Capture must check actual depth and hold it continuously
for its own short bounded operation, calling no guest function, provider,
decoder or yielding wait while the CPU-copy group is retained.

## Concrete writer families

`L/` below abbreviates `ps2xRuntime/src/lib/` inside the exact fresh126 SDK.
Ranges are half-open and bounds depend on the original method's checks.

| Writer/call chain | Destination and relevant locks/lifetime | Capture disposition |
| --- | --- | --- |
| `PS2Runtime::dispatchLoop` / `StartThread` → registered game function/override → stores, libc copy/fill | Guest-selected EE/SPR/Context; real guest scope around steps. Scheduler/backedge/syscall waits can release it, then reacquire before continuing. | Excluded from a short capture operation by the same real guest mutex; never retain a copy group across a guest call/wait. |
| `Interrupt.cpp` INTC/DMAC/VBLANK and `Helpers/Runtime.h::ensureAlarmWorkerRunning` → handler | Handler-selected EE/stack; real guest scope before function invocation. Callback context is host storage. | Same exclusion while capture retains actual guest scope. Stack reservation itself changes host allocator bookkeeping only. |
| `L/Kernel/Syscalls/Helpers/Runtime.h::rpcInvokeFunction` → callback | Guest callback stack and callback-selected EE; helper acquires guest scope. Callees retain their explicit waits. | No capture group may span this call. Reacquire a fresh bounded group for later completion metadata. |
| `recomp/overrides/reo_hw_bridge.cpp::pad2FeederLoop` | Independent `std::thread`; copied dynamic work address4B and one of each socket's two0x80-byte records. `g_pad2.m` was released before writes. | Confirmed counterexample in flag0/1. Flag2 actual body now takes a v2 cooperating writer over the complete batch after snapshot/unlock. |
| `reo_cd_async.h::worker→complete→ReoHwBridge::readCdSectors` | Masked EE destination, `count*2048`; disk read happens before callback guest scope. Detached legacy worker has no equivalent qualified configuration receipt. | Refuse legacy detached-worker build. Native capture requires actual native-owner synchronous-mode seal; do not infer from `REO_CD_ASYNC=0` alone. |
| `native_cd_owner/runtime_adapter.cpp::Session::perform→readCdSectors` | Same EE sector span; worker admission/stop/join owns mapping, but guest scope starts after payload I/O. | Exclude actual asynchronous configuration with the retained real synchronous seal. Stop/empty queue alone is insufficient. |
| `native_resource_reads/runtime_adapter.cpp` synchronous reader | `ram+destination`, checked sector byte extent; actual runtime/backing and nonzero guest depth checked before read. Reader lease owns resource/provider operation. | Runs on guest caller; safe against another held guest scope only if async CD and other writers are independently closed. The resource lease alone is not a RAM range lock. |
| `ReoHwBridge::onSifRpc` FILEIO/CD/MC/network/keyboard/profile helpers | Payload/read-result/receive-selected EE spans; CDVD serializes file access, service objects own sockets/files. Some operations write via direct `fread`/archive read, others through `rdramWrite32`/source copy helpers. | Actual SDK SIF calls reach these synchronously inside guest execution. No independent guest-writing service thread was found in these native transports; direct external vtable invocation is unsupported. |
| `L/Kernel/Stubs/CD.cpp::sceCdRead/sceCdReadChain/sceCdStRead` and TOC helpers | Sector destinations and caller response/TOC buffers; read failure can zero destination. | Synchronous guest-stub path. Do not confuse these with the separate asynchronous override. |
| `L/Kernel/Stubs/MemoryCard.cpp` and `recomp/overrides/reo_memory_card.h::Request::transfer` | Checked canonical EE destination or owned128KiB host scratch; source hooks for EE copies. Original request thread invokes backends. | Guest request/dispatcher path, not a separate RAM-writing host worker. Caller-context requirement still applies. |
| `L/Kernel/Stubs/SIF.cpp::sceSifSetDma` | Up to32 captured DMA descriptors; guest→guest forward copies, or `iopDest[j]=*getConstMemPtr(...)` for owned sound arena. DTX notification can write additional guest state or queue PCM. | Synchronous guest path; importantly, IOP writes bypass the new companion table. Actual guest exclusion is required, not a claim that every IOP writer uses `NativeSoundRamCall`. |
| `SIF.cpp::sceSifGetOtherData` | IOP sound arena→EE plus EE receive descriptor at+0x10/+0x14/+0x18. Generic EE transfers remain separate caller domain. | Companion-selected sound path uses explicit tagged operations. Default/generic path is synchronous guest code, with original bytewise semantics. |
| `L/Kernel/Syscalls/RPC.cpp::SifCallRpc` and direct builtin sound service | EE ABI/client/server metadata, payload transport, query results, compat busy field; original forward RPC copy clamps to1MiB. | New companion path captures these under one accepted SoundCall; each bounded operation must independently obtain actual RAM authority. Other SIDs remain synchronous caller context. |
| RPC sound arena initialization / checksum backfill | Actual2MiB IOP allocation, not EE address alias; status/table/storage zero and16-bit slot writes under `g_rpc_mutex`. | Native companion batches qualify exact IOP backing and same session gate. Guest mutex covers normal game callers; registry lock alone is not a general external-reader reservation. |
| RPC `collectSjxReplies` / RNA consumption | Playback clock advances host channel/voice credit; guest publication copies `SjxReply` records into `transfer.eeWorkAddr+16+n*16` and writes command count, under `g_dtx_rpc_mutex`. | Reply publication is on the synchronous DTX/SIF caller, not the audio callback. Host audio timing itself is not an independent guest writer. |
| `CriAudio`/`ReoSoundBanks` audio callback and `runtime/audio/host_bridge.h` gain hooks | Device output, owned PCM/voice/bank state and host atomic mixer/routes. Mixer IPC is a separate host mapping. | No EE/IOP destination in these reviewed callback/gain implementations. Future providers must not reintroduce raw guest pointers into callbacks. |
| `L/ps2_memory.cpp::writeIORegister` SPR channels8/9 | `fromSPR`:16B quads into checked EE offsets; `toSPR`: scratchpad writes. Transfer executes at kick, updates IO registers and raises DMAC completion. | Synchronous MMIO caller path; no host SPR worker here. Source hooks alone do not supply no-parent coherence. |
| `L/ipu/ps2_ipu.cpp::drainOut` reached by IPU MMIO/DMA | `g_host.mem(madr,n*16)` resolves checked EE or SPR; copies decoded output, then updates DMA registers. Host callbacks bound in `PS2Memory::initialize`. | CPU decode/DMA processing is synchronous caller work in the reviewed implementation. Native movie GPU work below does not turn this pointer into an independent CPU worker destination. |
| `L/Kernel/Stubs/GS.cpp::sceGsExecStoreImage→GS::consumeLocalToHostBytes→gsBackendTransfer` | Guest-selected EE destination. GS worker fills owned `shared_ptr<Result>::bytes`; caller copies to guest only after control completion. | GPU worker does not retain guest destination. `gsBackendControl` wait itself does not release guest scope; caller retains it for final copy. |
| Software `GS::consumeLocalToHostBytes` | Copies software local-to-host FIFO bytes to caller destination on caller thread. | Same synchronous guest store-image caller; software raster worker writes VRAM/frame storage, not this guest destination. |
| `parallel_backend.cpp::readTransfer/materializeTransfer/readVram/capture` | Backend-local FIFO, result bytes, frame RGBA or mapped GS VRAM. | These are not EE/IOP stores. The SDK caller copy above is the relevant EE publication. Parent-specific GPU publications are separately excluded by Service activity. |
| SDK async VIF `State::run→processVIF1Data` MPG/UNPACK/VU execution | Owned chain bytes; dedicated `m_vu1Code`16KiB, `m_vu1Data`16KiB and VU state. Queue mutex/CV controls work; no guest scope in worker. | Async writes confirmed, but those buffers are allocated separately from EE. No automatic authority over the corresponding virtual-aperture aliases follows. See aperture section. |
| VIF/native-movie deferred DMA publication closures | `m_ioRegisters` channel/tag fields plus pending interrupt state, under actual IO lock; IRQ handlers acquire guest scope before guest execution. | Do not classify IO-register completion as an EE payload store. Parent Service methods that publish opaque ownership remain excluded even before a range appears. |
| `ReoHwBridge::processVifCommands/executeVu` bridge mode and VU0 `onVuStart` | Bridge interpreter code/data pointers alias EE offsets described below; VU0 also writes host Context lanes. | Bridge DMA callback is synchronous at `writeIORegister` kick; VU0 callback comes from guest execution. No SDK async-worker→bridge write edge proved. Initial profile conservatively refuses all alias apertures. |
| `native_movie_position/runtime_adapter.cpp::dispatch→commit` | Qualified movie descriptor fields, latest-position words and saved stack slots; explicit real guest scope before commit. | Synchronous guest override. The movie position core does not create an asynchronous RAM writer. |
| Movie IMAGE/compressed-frame GPU worker path | Retained source-qualified GPU image/control objects; queued final channel publication takes actual IO lock. CPU source/decoder commit occurs on caller. | Not a generic EE write capability. Review actual provider implementations/cohort before expanding beyond this path; parent activity gate does not replace movie source identity. |
| `network/native/game_netcode.h` correction/cadence and `world_sync.cpp::worldTick/Calls` | Actor/world/caller records on guest owner; network thread boundary uses value objects and socket buffers. | Actual override world/frame entry supplies guest execution. Transport-thread statistics/reset do not take guest RAM. Unknown external callers remain unsupported. |
| `PS2Runtime::guestCalloc/guestRealloc`, guest kernel state initialization, ELF load, memory initialize/cleanup | Caller heap spans or entire EE/IOP/SPR allocations; heap mutex protects allocator metadata, not all RAM. Reset/reallocation is a lifecycle operation. | Must be pre-run/retired or actual guest caller. Retain real runtime/backing incarnation through outer drain; never use a pointer/hash as a reset exclusion proof. |

## VU storage: distinguish the two paths

Fresh126 `include/runtime/ps2_memory.h` defines virtual VU windows. The actual
bridge constructs its own interpreters with `rdram+(base&backingMask)`:

| Storage | Virtual window | EE physical alias interval |
| --- | --- | --- |
| Bridge VU0 code | `0x11000000`,4KiB | `[0x01000000,0x01001000)` |
| Bridge VU0 data | `0x11004000`,4KiB | `[0x01004000,0x01005000)` |
| Bridge VU1 code | `0x11008000`,16KiB | `[0x01008000,0x0100c000)` |
| Bridge VU1 data | `0x1100c000`,16KiB | `[0x0100c000,0x01010000)` |

SDK `ps2_memory.cpp::initialize` allocates **separate** `m_vu1Code` and
`m_vu1Data` arrays. Its async enqueue captures owned chain data and calls
`processVIF1Data`; MPG/UNPACK copies target those separate arrays. Runtime VU1
callbacks execute the same separate arrays. `m_hwBridge.onDmaStart` is called
synchronously when the DMA is kicked; it is not invoked again by the queued
worker. The default upstream graphics mode does not register bridge DMA
interception; bridge VU0 callback remains installed for guest VCALLMS.

The first capture profile should refuse intersections with **all** listed EE
aliases for sources and destinations, including ordinary EE aliases of those
physical offsets. That is a conservative unsupported-domain policy, not a
claim that every byte is asynchronously modified in the current default mode.
Actual scratchpad is a distinct16KiB allocation and is outside the canonical
EE/IOP profile. Exact32MiB EE windows must be validated before the permissive
SDK guest resolver; unsupported segments/wrapping must not be normalized into
a guessed valid span.

## PCM queue source ownership

The reviewed production SDK call site is
`RPC.cpp::dtxApplySjxPayload`: after source normalization and
`chunkLen<=32MiB-sourceAddr`, it calls
`ps2_cri_audio::queue(ring,rdram+sourceAddr,chunkLen,endByte)` under
`g_dtx_rpc_mutex`, in the synchronous SIF/guest path. The facade's public API
also accepts arbitrary `const uint8_t*`; standalone tests use owned host arrays.
That signature does not establish EE, IOP or immutable host provenance.
The later `0x4000` room-bytes accounting/default ring size is **not** the input
admission check. The actual check is in `CriAudio.cpp::queue`: it rejects null,
zero, odd-byte or greater-than`0x4000` lengths **before** invoking the native
callback or legacy output setup. Thus16KiB staging covers the accepted public
facade domain. Stopping the audit at the RPC caller alone would miss this
callee guard and incorrectly label the bound as a new refusal policy.

The existing native PCM/aggregate bridge can call output/provider setup before
copying queue bytes. It must not receive a raw guest borrow whose authority
ended earlier or whose group remains held across provider setup. A new runtime
wrapper must reserve finite staging **before allocation**, classify the actual
source, obtain a short real read group for the whole extent, copy at most the
existing admitted16KiB, release that group, then call child queue/output/core with owned
bytes. It must retain the outer call and mapping incarnation throughout.
IOP or immutable host sources need their own explicit provenance/lease; do not
infer them from a public pointer falling outside EE. An unknown pointer is a
refusal, not permission for raw `memcpy` or per-operation legacy fallback.

## What remains unproved

This source catalogue does not prove arbitrary RAM-writing callers absent.
Public memory/vtable APIs, dynamically registered overrides, external debugger
writes, an unreviewed future native worker, and a mismatched source/build cohort
can invalidate the proposed profile. The actual writer families above must
match the linked candidate and lifecycle. A source search or observed empty
queue is not a reservation.

The reviewed Windows pinned-resource read uses `SetFilePointerEx` plus
`ReadFile(...,nullptr)` under its file mutex and returns after the synchronous
read; it does not retain the caller output in an overlapped I/O job. Resource
mount/manifest reads write owned host blobs. These facts are separate from the
actual CD override mode seal and do not qualify arbitrary future providers.

Production capture remains unavailable until the actual runtime/bridge/init
incarnation, sync-CD seal, v2 Pad and Service instrumentation, strict source AND
destination domain checks, accepted outer-call lifetime, finite staging, and
safe ABI/control completion admission are jointly qualified. No change in this
audit silently disables async CD, switches graphics modes, enables experimental
rendering or changes game speed.

The initial Pad implementation's witness clear was placed before the existing
double-init return; root review caught that it would invalidate a successful
witness on the second `applyOutbreakOverrides`. The corrected actual body keeps
the witness across same-runtime double init, rejects a foreign runtime, clears
before shutdown and never issues it after a failed first init. The dedicated
coordination document records final tests and cohort identities.

## Repository source pins

These are observed working-tree byte identities for the reviewed source, not
a claim that a future executable contains them. The complete fresh126 SDK is
pinned by its receipt above; all relevant SDK paths refer to that tree. The
Pad/Service instrumentation must additionally match the final linked cohort.

| Source | SHA256 |
| --- | --- |
| recomp/overrides/reo_hw_bridge.cpp | bc89559586915089579a4f6dc562217c41b9f12bf885132b3944ff6c81c30343 |
| recomp/overrides/reo_hw_bridge.h | bcbeef406f483677e4777bab8b4c6b2028f7830060deb5094e85db4d3f221130 |
| recomp/overrides/reo_cd_async.h | 4125d30beb465e7882e6f01864162a27873a1d4c74ffc7001a6587248a625fd2 |
| recomp/overrides/native_cd_owner/runtime_adapter.cpp | ceb169ef93e6952fc73626c97f04ea06690c6f07be045420d60feb82e42ccd07 |
| recomp/overrides/native_cd_owner/ram_configuration.h | f8774e85e56938ff116425d13025c4647924392a5af883171bd1a58f95978649 |
| recomp/overrides/native_resource_reads/runtime_adapter.cpp | f7fa81bf432f6c5d54d71aefc569443fdb88d8d84070fc66c88d216bd50df00e |
| recomp/overrides/native_movie_position/runtime_adapter.cpp | 47155fc8f23d3470b7b4f700632054baf35341c3375035b1dfb8aa78fbf4e13a |
| recomp/overrides/reo_memory_card.h | 0226b477aee292bcf47e4f3987f3744202fe9fd834f58c4e639e26c078ff2c77 |
| runtime/audio/host_bridge.h | d2c2f3411214d5443dd65753d5ffed5655975633d92038f3b6f52bf6f59be759 |
| runtime/cdvd/cdvd.cpp | aff60bf1c8dd40e8d8d9b3f9b9b667f218dd331e524e6125330972529de91f46 |
| game/native/resources_windows/pinned_file.cpp | 48a8b40920cf5588a29d85fb89f22d62d7d73efe2ba8b5ee5d71404abd9b7bfc |
| game/native/resources_windows/mounted_resources.cpp | 717474b3c6a23d946f13c596d9be6e8718c3afe71ae1098a6adf0c7827936183 |
| network/native/game_netcode.h | d9f982350cac7751b0ddc78ed3556cc002ee40e4bc86df8474f0c25d31f0bf49 |
| network/native/world_sync.cpp | 336c7d61ed3e228f57d418486bbb32c3357b1402c3b81f9bcf2afaafd6212ef2 |
| network/native/native_netcode.h | 4c49f556c8a1d96d3ff527edafc8f8fa59f59ec14d8c6d1a57db5404be34e5f6 |
| tools/parallel_gs_backend/parallel_backend.cpp | 92b86841b46e1b53cd5991594f98cec633c94cb4d2c9654b8fafd338c87802ab |
| tools/parallel_gs_backend/resident_geometry/parent/parent_owner_service.hpp | 1bf955c4135b8aa32e9075241c1fe466566efac3b3f05ade7e3b08a880875316 |
| game/native/ram_capture/v2/cpu_authority_gate.hpp | 10d6455e922cf8f8edb1ecf1d655389d25e46d84cd352124ed719aece3b0687e |
| game/native/ram_capture/v2/cpu_authority_gate.cpp | b703306ab49e1ede66737ca6b31313359a8d15a33316358eaa250a287ab381bb |
