# Actual runtime sound RAM capture: design and qualification gates

Status: retained design and source-catalogue snapshot, 2026-11-06. The source
basis below predates the subsequent writer, selected-renderer and concrete
memory-owner implementations. Their current qualification is recorded in
[Pad coordination](PAD_RAM_CAPTURE_COORDINATION.md),
[selected GS profile](GS_SOUND_RAM_PROFILE.md) and
[RuntimeMemory](NATIVE_SOUND_RAM_MEMORY_OWNER.md). The latter now implements the
private acquisition/copy provider and passes isolated protocol/object checks;
actual capability acquisition, complete publication and a rebuilt game remain
unvalidated. The design below records the obligations used to review that work.
The frozen aggregate1 and grouped bank adapter3 remain unchanged. The separately
qualified [Aggregate2 composition](NATIVE_AUDIO_AGGREGATE_V2.md) now joins the
grouped contract to the complete audio table; it still needs a real provider.
The [strict address helper](NATIVE_SOUND_ADDRESS_DOMAIN.md) is implemented and
tested independently. It supplies no RAM capability or copy implementation.

## Original source basis and design gates

The SDK companion is final126-v5, not the superseded v4 source:
`build-native-sjuni/dependency-ram-reapply-v5`, full reapply receipt
`2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0`.
Its separate `CriAudioRamCapture.h` is
`2505ea1838df71edd5bf6c87f88934cf303d2c533e8bd3e24dee3a2c7fea3147`.
The [companion source qualification](NATIVE_SOUND_RAM_CAPTURE_DISPATCH.md)
establishes its admitted-call transport, not a built-in provider or factory.

| Actual source path | Observed protection / required treatment |
| --- | --- |
| `native_cd_owner/runtime_adapter.cpp`, `configureWithReceipt` / `try_seal` | Actual observed synchronous branch, retained issued seal, lifecycle sentinel and process-sticky asynchronous-attempt exclusion; no environment inference. Reviewed separately in [CD seal review](CD_RAM_CONFIGURATION_SEAL_REVIEW.md). |
| final126 `ps2_runtime.cpp`, `ps2ActualGuestExecutionDepth` | Positive actual depth means this thread holds that Runtime's recursive guest execution ownership. It does not serialize arbitrary host workers or retain RAM by itself. Never acquire guest ownership underneath an existing RPC lock. |
| final126 `ps2_memory.cpp`, initialize/destruction | Fresh actual EE and IOP allocations are separate; factory captures both exact backings before publication. The selected external-worker registration must drain accepted calls before either storage can be destroyed or rebound. |
| `resident_geometry/parent/parent_owner_service.hpp:65..81` | Actual `GraphicsActivity` starts before RAM-affecting Service members, even without a NativeTarget or published natural owner; declared first, destroyed last. Factory uses the actual process Coordinator, not a fabricated per-provider gate. Any prior Service attempt permanently excludes that backing from this narrow CPU profile. |
| final126 `ps2_gs_gpu.cpp:3810..3826,3930..3943`, `Kernel/Stubs/GS.cpp:1080` | Backend readback callback owns a Result vector. The actual caller copies to the supplied guest destination after control completion; no queued callback captures that guest destination. Software transfer also copies on the caller. Actual caller ownership and all alternate entry paths still belong in the writer catalogue. |
| final126 `ps2_memory.cpp:1218..1256` | SPR-to-RAM DMA copies at kick on the caller. Existing guest ownership must cover this caller; range alias interpretation must not turn SPR/MMIO into an admitted ordinary RAM source. |
| `reo_hw_bridge.cpp:119..130` | Bridge VU pointers alias physical EE apertures. Initial capture profile conservatively excludes those physical ranges for reads **and writes**, including ordinary EE aliases. This is an explicit refusal, not proof that every upstream VIF worker writes EE. |
| final126 `ps2_memory.cpp:431..434,1763..1779` | Upstream async VIF uses owned chain input and separately allocated VU1 code/data. Do not conflate these with the bridge's EE aliases. Other worker callbacks/publications require the independent all-writer audit. |
| `reo_hw_bridge.cpp:2309..2449`, `pad2FeederLoop` | **Confirmed missing writer exclusion:** thread snapshots work/socket destinations under `g_pad2.m`, then writes actual guest RAM after releasing it, without GuestExecutionScope. CD seal and CpuGroup do not cover these writes. |
| `reo_hw_bridge.cpp:2455..2482` | Socket/work addresses can be registered dynamically. A momentary registry snapshot cannot exclude already copied destinations or future registrations. Need a writer-participating bounded read reservation or an actual retained never-started mode seal that prevents future starts before effects. Never disable working input to qualify capture. |
| final126 `Kernel/Syscalls/RPC.cpp:1159` | Current source tree has one actual PCM queue producer: normalized EE chunk passed to public `ps2_cri_audio::queue`. The queue wrapper must stage bytes before the bridge's output setup; it cannot forward the raw guest borrow as if coherence were already solved. |
| `pcm_bridge/session_bridge.cpp:171..184` | `queue` calls `ensure_output` before copying into the core. A RAM read/group/parent reservation may not remain held across that provider callback path. Use prebudgeted staging, release the group, then call the unchanged bridge. |

Conservative physical EE exclusions, derived from actual bridge pointers and VU
sizes, are `[0x01000000,0x01001000)`, `[0x01004000,0x01005000)`,
`[0x01008000,0x0100c000)`, `[0x0100c000,0x01010000)`. The last two may be merged.
Do not mask first and accidentally accept an unsupported VU virtual address as
ordinary EE. Reject intersections on both sides of forward/control operations.
This choice does not change rendering/VIF settings or claim those aliases are
the only host writers.

The independent all-writer catalogue is being prepared against these same
sources. Until the Pad2 feeder and any additional unscoped writers have an
actual exclusion capability, this table does **not** close production coherence.
A hash, Target lookup, depth integer, boolean profile flag, environment value or
currently empty queue is insufficient. No unsafe memcpy factory is authorized
by the existing tests.

Root approved a separately versioned Coordinator2 design; v1 stays frozen.
The pending interface is `ram_capture::v2::process_coordinator()` with the same
`try_cpu_group`/`begin_graphics` shape and an added `begin_cpu_writer` RAII scope.
A Pad writer announces before its bytes and waits for existing copy groups outside
Guest/RPC/gPad locks; the nonblocking reader API returns `writer_busy` while a
writer waits/runs. That ordinary Pad interval cannot become a routine unsupported
RPC result: early refusal may leave no qualified completion metadata. A separate
fair waiting-copy admission is being qualified for the actual bounded writer
profile. The actual Pad body must cover every RAM write through final
sequence publication, including copied old work/socket addresses. Graphics
attempts still make CPU capture permanently ineligible. Root owns actual Service
instrumentation/build integration; a private BodyCaps value must be minted by
that actual instrumented linked body for the selected Runtime/backing, not by a
caller-supplied bool, header macro or version number alone. The agreed actual
bridge witness is `nativeSoundRamWriterCoordinator(runtime)`, returning the same
v2 process Coordinator only for the actual singleton/Runtime/backing and compiled
instrumented body; frozen source/build receipts remain a separate qualification.
No such production factory is implemented here yet. The actual writer and
Service bodies are being qualified separately; those tests do not install sound
capture or prove its complete liveness contract.

Coordinator2 also has permanent process-wide capture withdrawal. If Pad cannot
obtain bounded writer metadata, it closes future CPU-group admission, drains
existing groups outside Guest/RPC/gPad dependencies, diagnoses capture unavailable
and continues original input writes. Reader capacity refusal must never kill or
silently skip controller input. Factory operations diagnose that withdrawal and
refuse new memory effects; an already retained group remains valid through its
bounded copy. This is actual writer-authority loss, distinct from rejecting an
accepted mapping merely because Runtime stop was signaled.

## Proposed owner and admission API

New implementation belongs under `recomp/overrides/native_sound_ram`. The public
factory is a pre-run atomic composite installation operation, not a constructor
that accepts an arbitrary caller-supplied `RAM is safe` boolean. It must obtain
and retain the actual CD seal and concrete writer/read authority, bind the fresh
Runtime/EE/IOP incarnation, and register the **same** strong wrapper owner used by
the complete audio table and SDK companion. Preparation may allocate fixed
storage; no memory operation becomes available before successful publication.

The implementation will maintain a finite pool of16 slots, each containing
65,536 preallocated packet bytes. Payload cost is1,048,576 bytes, plus separately
reported fixed token/counter/owner administration. Generations are bounded and
never wrap. A NativeScope token binds owner/session nonce, slot, generation,
exact accepted SoundCall address and originating thread. SDK already retains
that accepted call; the provider does not reacquire admission or move/retain the
call beyond its scope. End releases a valid token even after a refused begin or
later operation. Refused begin leaves an inert token and does not read guest
payload or change audio/RPC state.

`begin` checks exact Runtime/backings and actual guest context, then reserves
only bounded context/storage. It holds **no** guest-range, graphics, source or
parent lock across the RPC, guest callback or NativeScope lifetime. An accepted
outer call paused before begin remains valid after stop. Neither begin nor an
operation treats `Runtime.isStopRequested()` as permission to discard the
accepted mapping. Only outer drain permits RAM-owner retirement.

The companion table is exactly final126 `NativeSoundRamApiV1`: begin/end,
read_batch, control_batch, copy_forward, snapshot_packet, log_owned_packet,
report. Its `void*` is the same wrapper pointer as the complete audio tables.
Private callbacks are not exposed as an unregistered RAM helper that can be
called with a fabricated lifecycle proof.

## Bounded memory-operation rules

For every operation, before any guest/host memory effect:

1. Validate token/call/session/generation/thread, actual current backing equality
   and current actual guest ownership. Do not reacquire guest under RPC locks.
2. Preflight **all** ranges and kinds, extent arithmetic, counts, actual mapped
   geometry, canonical address tags, forbidden physical apertures and supported
   writer/parent profile. Invalid later items must leave every earlier item
   untouched. Metadata preflight performs no payload reads.
3. Validate live caller-owned host spans against actual EE/IOP address intervals
   using checked integer extents, not undefined pointer subtraction. Read
   destinations/control sources must not secretly alias guest RAM. Reject
   overlapping host output spans when batch ordering would hide an alias.
4. Obtain one actual process Coordinator2 CpuGroup covering the entire bounded
   operation, while retaining the actual guest ownership and configuration
   seals. Guest ownership excludes other admitted guest callers; the group
   excludes the independent cooperating Pad writer. No second invented range
   lock is implied. A waiting admission must retain the actual selected-backend
   config-off authority throughout its wait, before the group exists. This
   excludes normal renderer transitions that could otherwise make Pad's source
   wrappers wait on journal/source dependencies held by the guest caller.
   No registry/source/guest release or provider call occurs while the resulting
   group is held. Refusal must precede all payload effects.
5. Copy/apply the fully preflighted batch with nonthrowing bounded operations,
   then release every range/parent/CpuGroup reservation before returning.

EE admits only the four exact32MiB windows `[0,0x02000000)`,
`[0x20000000,0x22000000)`, `[0x80000000,0x82000000)` and
`[0xa0000000,0xa2000000)`, with a nonwrapping physical interval wholly inside
that same window and the actual normal32MiB allocation. Do not use
`ps2ResolveGuestPointer` as standalone admission: its emulator semantics mask
physical addresses beyond the backing and can return offset0 for unsupported
segments. Scratchpad, MMIO, other mirrors and aperture intersections refuse.
IOP is a distinct explicit space tag with ordinary offsets wholly inside the
actual2MiB allocation, never guessed from an EE alias. Zero-length behavior
will match the actual final126 caller contract; it cannot authorize a disguised
out-of-range nonempty interval.

`copy_forward` preflights/reserves both source and destination together, then
performs the original increasing-address **bytewise evolving-source** copy.
Overlapping destination-after-source repeats newly written bytes as the original
does; replacing it with memmove or independent read snapshots would be wrong.
The factory does not introduce a global1MiB clamp: the SDK RPC caller applies its
own original clamp while the IOP status path retains its full qualified extent.

`snapshot_packet` copies at most65,536 bytes into the token's reserved owner slot.
Its loan remains immutable through NativeScope end. Initial profile supports one
snapshot loan per scope; a second request returns explicit capacity rather than
overwriting an earlier loan. Logging accepts only that exact owned loan, copies
to an explicitly bounded nonblocking owned sink or returns a diagnostic failure.
It never logs by rereading guest RAM or retains the loan after end. Final126
already keeps diagnostic failure separate from packet gameplay success; counters
must not claim saved/exported data on failure. No filesystem I/O runs under a
RAM reservation.

## Grouped bank provider and PCM staging

A source adapter for bank adapter3 maps snapshot loans to owned packet bytes and
direct guest bank pointers to validated canonical EE offsets. Its
`copy_parts_v1` preflights all HD/BD/TQ ranges, takes one real coherent group,
copies the three already budgeted vectors, and drops the group before returning
to decoder/install. Loaded conditional0x4E must still avoid every unused asset
capture. Source identity comparison is a binding check, not the writer protocol.

Arbitrary direct **host** HD/BD/TQ pointers remain unsupported unless accompanied
by a separately issued immutable asset/borrow lease that covers the full call.
Matching a hash or observing unchanged bytes twice is not that lease. Likewise,
an arbitrary host packet without a recognized owned snapshot loan is outside
the initial production profile.

PCM queue interception uses an ephemeral pool slot and at most0x4000 bytes under
the actual admitted table callback. It validates/stages an eligible EE source
under the same group authority, then releases it **before** forwarding to the
unchanged child queue/ensure-output path. This callback has no explicit
SoundCall parameter; its authority is the existing actual SDK table admission,
not a newly acquired SoundCall that could fail after outer stop. No stage or
range reservation may leak into the audio callback, PCM data lock or provider.
The slot remains owned until the child queue has synchronously copied it.

## Complete wrapper and next version boundary

The composite wrapper strongly owns a child registration and RuntimeRAM owner.
Every one of the11 PCM and8 bank callbacks relays to the corresponding child
function with `child.owner.get()`; the wrapper intercepts queue staging and
provides companion operations. V2 `render_admitted` passes the **same** received
SoundCall into the child. DeviceRenderer continues through the public facade,
and child Host.mix_banks uses that existing admitted call. There is no TLS
selection fallback, new public-facade call or second admission gate.

Initial stop closes the SDK outer gate and signals the child provider only.
Pool/token and inner PCM/packet/bank admission remain usable by accepted calls
until outer drain. Join runs outside callback/guest/RPC/PCM/bank locks; child
output must actually fence before cores clear and RAM authority retires. Any
failed fence retains the child, all mappings, pool and seals for retry. No strong
callback cycle may keep the complete owner alive after successful retirement.

Frozen aggregate1 names the old adapter2 CaptureSource and provider types. Those
types cannot be relabeled as grouped adapter3 proof. The separately identified
mechanical Aggregate2 namespace/packet-alias derivation now preserves existing
DSP/bridge/lifecycle expressions and swaps the explicit provider contract to
adapter3. Its independent combined-source comparisons preserve the raw14
declared post-shutdown closed-query differences; aggregate1 remains immutable.
An inert wrapper can accept aggregate1's child registration for lifecycle tests,
but that cannot activate a qualified grouped bank factory in production.

## Required evidence before publication

Implementation tests must include actual final126 headers/full reapply inputs,
finite pool exhaustion, token/loan stale/foreign/thread reuse, accepted-stop
continuation, snapshot immutability, all-or-nothing late-invalid batches, exact
forward aliases, unsupported IOP/EE/SPR/MMIO/VU cases, nonalias host spans,
grouped graphics/writer races, group release before decode and output setup,
no callback allocation/I/O, failure retry and full composite drain ordering.
Negative controls must demonstrate that unsafe bypasses are detected. Existing
PCM/bank/joint original observations remain independent frozen regressions.

Current blockers are actual Pad2/other-writer capability closure, safe waiting
admission and exact selected graphics/bridge writer qualification, followed by
the concrete provider/factory and coherent integration. Root owns SDK/bootstrap/build integration. These are concrete missing
contracts, not a request to disable game features or assume safe raw reads.
