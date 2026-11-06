# Pad RAM capture coordination

Status: isolated cooperating writer infrastructure and actual bridge source
instrumentation. Capture flag2 remains off in normal launches. No game/device
was run, no SDK/frozen packet/core files were changed and no runtime library
was linked. The runtime capture factory remains a separate admission task.

## Problem and actual body

`recomp/overrides/reo_hw_bridge.cpp::pad2FeederLoop` is a host thread, not a
guest thread. It snapshots `g_pad2.rdram`, `workAddr` and sockets under
`g_pad2.m`, releases that mutex, then writes the port work word and Pad record
data through the final sequence field. The previous source wrappers fall back
to ordinary copies when no advanced source target exists. Neither a guest lock,
CD configuration seal nor absent graphics Service excludes this writer.

The source now conditionally acquires a v2 `CpuWriter` **after** copying dynamic
addresses and releasing `g_pad2.m`, before the first RAM write. Its lexical
lifetime covers the work word, all socket record writes and final sequence
publication. It does not reacquire `g_pad2.m` while held. Input polling,
automatic/script input, vector address snapshot and host state remain outside
the writer scope. The flag0/1 record-writing body is unchanged.

`pad2RegisterSocket` appends host socket metadata and starts the actual thread;
`pad2SetWorkAddr` only publishes host metadata. Neither performs immediate RAM
writes. HLE Pad RPC replies elsewhere in `onSifRpc` run on the actual guest
caller and are covered by the real guest execution boundary, not this worker
token. Changing the work address does not revoke a worker's already copied old
address; guarding the complete copied batch handles that race without relying
on a current-address snapshot as a fence.

## Versioned coordinator

New implementation:
`game/native/ram_capture/v2/cpu_authority_gate.{hpp,cpp}`.
It derives the v1 protocol from commit
`8229cc2e5133d240a693c877a3ffaeeceb4850f4` without modifying the v1 files.
Namespace: `reo::native::ram_capture::v2`.

| API | Contract |
| --- | --- |
| `try_cpu_group(backing)` | Short metadata mutex only; refuses `writer_busy` if a writer is waiting/active, `graphics_owned` after any graphics attempt, or `unavailable` after capture withdrawal. |
| `wait_cpu_group(backing)` | Reserves fixed waiting metadata with no active group, then admits behind older writer tickets/current writer. Later writers cannot overtake it. Qualified bounded-writer profile only. |
| `begin_cpu_writer(backing)` | Announces waiting before waiting for all admitted groups and another active writer to retire. No registry mutex is held over RAM/source operations. |
| `begin_graphics(backing)` | Sets sticky graphics exclusion, then waits for copy groups and all waiting/active writers. Writers remain legal while graphics activity exists; original source guards still apply. |
| `withdraw_cpu_capture()` | Permanently denies ALL future CPU groups, then waits for every existing copy group. It supplies no generic serialization for original writers after withdrawal. |
| `observe(backing)` | Read-only counts plus sticky graphics and global capture-disabled state; observation is not admission. |
| `process_coordinator()` | One app-linked instance shared with the actual Service/bridge/runtime factory; no per-translation-unit singleton. |

There are16 fixed backing entries,16 CPU-group slots per backing and16 writer
slots per backing. CPU/writer tokens are move-only, generation qualified and
thread confined. Releases validate the issuing thread. Metadata uses no dynamic
container/allocation. Backing entries and sticky exclusions are never recycled
to guess an incarnation change; a pointer being reused can conservatively lose
capture availability.

Waiting readers and writers share monotonic arrival tickets. Older writers keep
their place, a later writer cannot overtake a pending reader, and a stream of
new readers cannot starve an older writer. A waiting reader is not counted as
an active group and holds no RAM pin. Ticket exhaustion refuses with capacity;
it never wraps. Sticky graphics or global capture withdrawal wakes pending
readers, frees their reserved slots and returns an explicit refusal with no
token. Cleanup also retires reservations on a wait exception.

A CPU group covers only related bounded copies. It must end before decoding,
provider/output setup, guest callbacks, input work or any yielding wait.
The writer announces/waits outside guest/RPC/source/protocol/Pad dependencies
needed by those copies. Same-thread CPU group→writer/graphics and
writer→writer/graphics waits return typed `self_wait` before effects. Withdrawal
also refuses a wait on the caller's own group. A self-wait is a programming
contract failure; a qualified feeder never owns a CPU group. No pin can be
transferred to the feeder and drained by its own thread.

Reader completion and writer admission/release synchronize through the actual
coordinator mutex/CV. Several CPU groups are permitted; this is not a general
writer lock for arbitrary callers using a group to mutate RAM. The runtime
factory additionally retains actual exclusive guest execution for its typed
control operations.

## Exhaustion preserves input

The capture profile admits at most64 copied socket records in one guarded
batch: one optional4-byte work word plus64 records of at most128 bytes. This is
a NEW capture admission limit; original registration has no such count limit.
On overflow, EVERY original socket still receives its input writes after
capture is withdrawn and existing copies retire. No vector truncation occurs.

If writer metadata is exhausted or this capture bound is exceeded, the actual helper withdraws capture and drains
all existing groups before continuing the original writes. It prints one clear
capture-unavailable error. It neither terminates the game nor skips a Pad frame
or switches input/graphics/CD modes. Future capture operations refuse before
effects. This is **not** per-operation legacy fallback for capture or a promise
to serialize arbitrary original writers after capture is disabled.

## Conditional wait while holding guest/RPC ownership

Ordinary `writer_busy` must not be turned into a routine unsupported audio RPC.
The blocking API is permitted only with a retained, actual config-off authority
proving that the cooperating writer never needs the caller's guest/RPC/Pad or
source/protocol locks. It is not a generic promise for any `CpuWriter` caller.
The independent thread first captures its addresses under `g_pad2.m`, drops it,
then waits before any RAM write. Its admitted body has at most64 records and no
guest/RPC/Pad reacquisition, provider or guest callback.

The preserved source wrappers still matter. Fresh126
`source_instruction_access.hpp::copyBytesForBank→selectedTarget` takes the
atomic `anyActualOwnerBound()==false` fast path. Its pre-entry invalidation
returns when enrollment is false; `copyBytes` then does the ordinary bounded
copy. For this profile there is no registry lookup/virtual target/source-lock
or journal-lock dependency. A bound/tombstoned owner or enrollment flag would
invalidate that proof. Generic wrapper code can otherwise take such locks;
the implementation does not remove or bypass it.

`parallel_backend.cpp` publishes actual enrollment from its selected resident
configuration. The runtime owner must retain actual config-off/no-Service,
zero global source owner and no enrollment authority over the **waiting
interval and copy**, not merely check zero once or hold a pin later. A waiting
reader has no pin; deferred enrollment can precede actual Service construction.
Without that retained transition exclusion, waiting under guest/RPC locks is
not admitted. Nonblocking `try_cpu_group` remains available for other callers.

The actual single Pad writer makes a normal qualified wait depend on its
current bounded critical section. Generic callers can have up to the finite
older writer queue. Tickets prevent starvation, but no hard wall-clock latency
bound is claimed under OS descheduling. No CPU group spans decoding, output
setup or a guest callback.

## Actual instrumentation witness and lifetime

`ReoHwBridge::nativeSoundRamWriterCoordinator(PS2Runtime&) const noexcept`
returns the actual v2 coordinator only when the body was compiled with
`REO_BUILD_NATIVE_SOUND_RAM_CAPTURE>=2`, this bridge is the actual singleton,
its runtime is the supplied runtime, and current nonnull RDRAM equals the
backing recorded after successful bridge initialization. Otherwise it returns
null. The backing field is unconditional to avoid class layout depending on the
flag; matching rebuild/cohort qualification still remains mandatory.

Root review caught an initial placement error: clearing the witness before the
old double-init return would invalidate it on the second
`applyOutbreakOverrides`. The corrected source clears only after that return,
publishes after the full successful init, preserves same-runtime double init,
refuses a foreign runtime, and clears before shutdown/Pad stop. A failed first
init cannot mint a witness.

The root-owned actual Service hook uses a first-declared v2
`GraphicsActivity` and exposes `nativeSoundRamCaptureCoordinatorV2()`.
A runtime owner must require the same coordinator from both actual bodies and
verify the coherent linked/source flag2 cohort. A pointer/version witness alone
does not retain the bridge or RAM, prove all writers covered, or exclude reset.
The admitted outer owner must retain the real runtime/backing/bridge lifecycle
through all calls; `reoPad2Stop` joins the actual thread before RAM destruction.
No Runtime stop flag invalidates an already admitted short copy's storage.

## Isolated verification

`v2/verify.py` pins the full fresh126-v5 SDK receipt
`2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0`, all126
patches/source hashes and sealed unrelated V8 inputs. The compiler dependency
lists reject dirty active SDK or older SDK headers, including project-qualified
`third_party/PS2Recomp/...` includes. The existing sealed source catalogues are
copied only after receipt/output hash checks. No private header fallback exists.

The unit fixture exercises133 assertions covering reader/writer barriers, exclusive
writers, pending-writer reader refusal, graphics waiting through both kinds of
work, sticky graphics rejection, writer legality with graphics active,
same-thread refusal, moves/capacity, global withdrawal with an active copy and
allocation-free metadata.
Additional tests exercise adversarial reader/writer ticket order, older-writer
fairness, waiting-versus-active counts, finite waiter capacity and pending
reader cancellation on graphics/withdrawal. Private boundary variants seed the
counter near maximum or inject an exception after reservation, validating
no-wrap refusal and cleanup without adding production test hooks.

The production-body fixture extracts the complete actual Pad loop, writer
helper, registration, work publication, rumble/stop, bridge witness and complete
init/shutdown bodies. Only input/window/device/source surroundings are mocked.
It runs File1, File2 and flagoff variants. Actual `std::thread` and stop/join
execute; an admitted copy prevents every first work/socket write. Capacity
withdrawal waits an already admitted copy, then input continues and capture
stays unavailable. Init tests cover successful/double/foreign/failed/shutdown
witness boundaries.
The65-socket case checks that an active copy drains before the first write,
capture stays unavailable and the65th socket receives its original record.
The normal-writer wait fixture runs a pending reader while modeled caller
guest/RPC locks remain held; the actual complete Pad body finishes before the
copy is admitted. A deterministic mock barrier pauses the writer solely for
this test; it is not part of the production bounded body.

A negative control removes only the actual writer guard and must report Pad
writes overlapping an admitted copy. Its fake byte observer locks all fixture
RAM operations, so the counterexample does not itself introduce a C++ data race.
Full real `reo_hw_bridge.cpp` objects compile with actual fresh SDK/production
headers for File1 flag2, File2 flag2 and flagoff on both GCC/LLVM. These objects
are not linked with a real device or game.

The verifier suppresses the existing source's unused `frame` counter warning in
the extracted body rather than changing original Pad behavior. Earlier failed
driver trials and superseded raw source/identity cohorts remain in the ignored
build outputs; they are not rewritten as final successes.

## Remaining authority

This closes the cooperating Pad worker only. Actual sync-CD configuration,
canonical EE/IOP backing and VU aperture exclusion, complete other-writer
catalogue, source/asset staging and safe RPC completion admission remain
separate requirements. See
[RAM writer catalogue](NATIVE_SOUND_RAM_WRITER_CATALOGUE.md) and
[capture companion](NATIVE_SOUND_RAM_CAPTURE_DISPATCH.md). No production RAM
capture factory is admitted merely because these unit/object checks pass.

## Final source and proof identities

Current v2 cohort identity:
`ead54bf16757b176801e5b56c3fda34a087cb5fbd0ca963fa4160dc5eb65c4ee`.
It was frozen as the first wait/limit qualification candidate; the following
successful receipts establish its qualification without rewriting that freeze
record. This is not a blind freeze before historical expectations were seen.

| Source | SHA256 |
| --- | --- |
| `v2/cpu_authority_gate.hpp` | `10d6455e922cf8f8edb1ecf1d655389d25e46d84cd352124ed719aece3b0687e` |
| `v2/cpu_authority_gate.cpp` | `b703306ab49e1ede66737ca6b31313359a8d15a33316358eaa250a287ab381bb` |
| `recomp/overrides/reo_hw_bridge.h` | `bcbeef406f483677e4777bab8b4c6b2028f7830060deb5094e85db4d3f221130` |
| `recomp/overrides/reo_hw_bridge.cpp` | `bc89559586915089579a4f6dc562217c41b9f12bf885132b3944ff6c81c30343` |

Both full unit/body/boundary/object cohorts pass with empty source and include
postcheck drift lists:

| Receipt | SHA256 |
| --- | --- |
| `build-native-sjuni/pad-ram-coordination/gcc-wait-v1/receipt.json` | `fb67348b5058749963dc7a413b26137db163441d3b33d37fb8c79e26eeafe918` |
| `build-native-sjuni/pad-ram-coordination/llvm-wait-v1/receipt.json` | `55ab34b3e52869a0db0388d07709176681eabc5dac3e99dcab3f78616f235e99` |

The parent-owned actual Service2 constructor/header probes were independently
checked against their recorded hashes, passed on both compilers with166
qualified includes and empty drift lists:

| Receipt | SHA256 |
| --- | --- |
| `build-native-sjuni/ram-capture-gate/gcc-service-v2-ticket-final/receipt.json` | `974929c3eab7b820bfd68752384788c9dbd8631bd6206c71a2d62902d7130c27` |
| `build-native-sjuni/ram-capture-gate/llvm-service-v2-ticket-final/receipt.json` | `508019efbc13b707e9b901366f17658e39bc603046e8287b900943b7f4725c19` |

The new standalone CMake target is `reo_native_ram_capture_v2`, with optional
`REO_NATIVE_RAM_CAPTURE_V2_TESTS` and CTest `ram_capture_writer_gate`.
The parent also integrated this target into `game/native` and reported the
selected Release CTest passing on GCC and LLVM. Capture flags are not enabled
by that build-target registration. No full game or device test is represented
by these receipts.
