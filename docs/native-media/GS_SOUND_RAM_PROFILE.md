# Retained selected-GS profile for sound RAM capture

Status: source implementation and isolated qualification, 2026-11-06. No runtime
RAM factory, native-audio activation, bootstrap/CMake change, linked game, device
or full library build is supplied here. This capability closes selected-backend
configuration/rebinding; it does not by itself authorize reading guest RAM.

## Observed actual backend, retained selection

The actual application type is `reo_parallel_backend::Config`.
`ParallelBackend` owns its value in `config_`; no setter or later assignment
changes `residentGeometry.enabled`. Its actual successful init invokes the
resident owner factory only when that field is true. Observing no current
NativeTarget would miss deferred parent/array construction, so that observation
is insufficient.

The new pure `soundRamProfileObservedV1(Backend&)` performs a dynamic_cast to the
actual concrete ParallelBackend and checks its live, immutable geometry-disabled
configuration, plus actual enrollment=false and any-owner-bound=false. Tombstones
and other bindings are conservatively refused. Drawing, presentation, movies,
pipeline cache, filtering and other ordinary configuration are not disabled.
The actual factory attaches this probe as identified callable metadata. The
Backend object/vtable is not wrapped; existing dynamic_cast diagnostics continue
to inspect the same concrete instance.

SDK patch [0126](../../third_party/patches/ps2recomp/0126-seal-selected-gs-sound-ram-profile.patch)
adds a separate versioned header, `gs_sound_ram_profile.h`, without changing the
published audio V1/V2 tables or PS2Runtime/GS class layouts. The private Route
implementation does change and requires a coherent rebuilt SDK.

```cpp
gs_backend_bridge::SoundRamProfileResultV1
acquireSoundRamProfileBeforeRunV1(PS2Runtime&) noexcept;

// result.status; result.lease is move-only
lease.matches(runtime, actualEE, actualIOP);
lease.incarnation();
lease.factory_generation();
lease.release();
```

The actual gateway acquires the real short pre-run setup lease and a process
control reservation before observing actual EE/IOP/VRAM pointers, normal32MiB
geometry and `&runtime.gs() == g_gsInstance`. It submits an owned reply through
the existing GS owner/FIFO. That pure metadata probe pins the actual successfully
selected Route/backend incarnation and registered factory generation. A plain
unprovenanced legacy Route.start or mismatching factory generation cannot issue
the new lease. A software/failed selection, enabled resident geometry, enrollment
or any existing owner returns explicit unavailability/unsupported status.

The lease freezes factory replacement and Route start/stop/rebinding until
released. Snapshot generation mismatches refuse before the old working backend
is touched. `tryRegisterFactoryV1` and `tryStopV1` return typed refusal; existing
throwing `registerFactory` diagnoses retained-selection conflict with an
exception. The legacy noexcept stop/destructor cannot report recoverable refusal:
calling them with a live lease is an explicit illegal-lifecycle invariant, never
permission to silently return and free backing storage. Normal supported teardown
must release native-audio authority before reaching them.

## Control races, cancellation and teardown

`Route::start` checks admission before the old stop/close. A short control
reservation spans the transition, but **no metadata or execution mutex** is held
while old backends close, factory/init callbacks run or candidate resources retire.
Execution retains its existing Route serialization. New profile probing uses
try_lock rather than waiting behind another GPU execution. The concrete probe is
pure, bounded metadata only; it must not perform GPU/provider/guest work, reenter
Route/registration, allocate or log.

A boolean `any selection pinned?` test followed by global mutation would race
another Runtime's initializer. Allocation-free, same-thread-nested
`GlobalGsControlV1` therefore reserves the **whole** actual Runtime.initialize,
GS::init and GS worker-join scopes before any effects. It excludes profile mint
while global backing geometry, GS identity or worker ownership changes. Nested
initializeÃ¢â€ â€™GS initÃ¢â€ â€™GS join/control is explicit; foreign simultaneous controls
refuse instead of waiting under guest/RPC/provider/owner locks.

The profile gateway also owns this reservation before identity reads. Its private
generation permit authorizes only that outer gateway's queued probe; a nested
initializer cannot use it to mint while initialization continues. The owned reply
has a bounded metadata cancellation handshake. On cancellation/queue failure it
marks the reply cancelled and releases any abandoned selection pin **before**
dropping global control. A late callback checks cancellation before accessing GS
identity and never dereferences a dead caller/Runtime or mints a late lease.

Factory captures and closed/candidate Backend objects retire outside metadata
locks. The fixed metadata mutex is placement-constructed in static storage with
no registered destructor, avoiding a global Route shutdown using a mutex already
destroyed in another translation unit. This is fixed process administration,
not an audio callback allocation or a retained game/device owner.

The existing actual Runtime destructor drains external workers before guest/GS/
memory destruction. Normal run completion also calls
`joinExternalWorkersOrTerminate()` before `ps2GsJoinWorker()`, and its unwind
guards drain owners. The complete audio wrapper must retain this selection lease
until all outer calls drain and the actual output fence succeeds. Its release
uses only the short metadata mutex: it queues no GS work and joins no worker, so
it can run after GS stop signaling without waiting for a GS join that itself
requires lease release. Actual GS join refuses outstanding authority **before**
requesting/joining the worker or changing backend storage. Failed audio drain/
fence must retain authority and block destructive teardown, rather than claim a
successful shutdown.

`matches` is a retained identity comparison; it intentionally does not reject an
already accepted call because Runtime.stop was signaled. The lease does not own
the Runtime/EE/IOP by itself. Production factory publication must retain it in
the same real external-worker/complete-audio owner that enforces the lifetime
ordering above. Standalone metadata, a copied pointer, a hash, a headermacro or a
caller-supplied boolean is not that ownership proof.

## Linked instrumentation and remaining RAM authority

`reo_parallel_backend::nativeSoundRamWriterCoordinatorV2()` is compiled in the
actual backend translation unit. It returns the actual
`Service::nativeSoundRamCaptureCoordinatorV2()` only with the coherent capture
flag>=2, otherwise nullptr. A later factory must compare it with the actual
ReoHwBridge witness and app-linked process Coordinator2, with matching source and
build inputs. This linked body witness is separate from the generic config-only
profile probe.

Complete capture still requires actual Runtime/RAM/parent lifetimes, real guest
ownership, retained observed-sync CD seal, qualified Pad writer coordination,
canonical grouped copies and explicit unsupported-range handling. The retained
config-off/zero-owner/enrollment conditions must cover fair waiting **and** copy,
not just the final CPU pin. Arbitrary external registry/setter invocations,
unqualified direct memory access or a second unrelated Runtime are outside this
declared production profile. No game feature is disabled to obtain this lease.

## Reproduction and evidence

[prepare_patch.py](../../tools/native_reconstruction/gs_sound_ram_profile/prepare_patch.py)
checks the full126-v5 source/patch receipts, writes only a fresh isolated author
subset and reproduces0126. The full public127-patch series is then reapplied from
recorded base `c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f` into another clean checkout.
Active SDKs, sealed kits and earlier source/test cohorts are not edited.

Final full127 source: `build-native-sjuni/dependency-gs-sound-profile-reapply-v4`.
Reapply receipt:
`909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a`.
Patch SHA-256:
`bea5a843348b02a1b3abeeeea78ede6cb27236d2e6a64e0f19807d9ce193f38c`.
Actual profile header:
`d99bf2fa5724b6c152725eaa2ca9d95e87527cdf812add82f92e18a9a724be9b`.

The [source cohort](../../tools/native_reconstruction/gs_sound_ram_profile/cohort_identity.json)
records raw authored/app and fresh reapply identities. Author output uses LF;
this Windows Git reapply emits CRLF. Both raw source identities are retained,
universal-newline source text agrees, and compiled objects consume the exact
fresh reapply bytes. No algorithm or observation is normalized to conceal a
test difference.

The isolated suite compiles exact Route code and actual pure metadata expressions
with explicitly fake GPU/Runtime surroundings. It covers12 successful fresh-
process scenarios, two expected illegal-lifecycle exits and two private negative
controls, with21 recorded checks including compilation. There are32 paired races
each for stop/pin, factory replacement/pin and global-control/pin. It exercises
same-thread nested control, failed init/generation/probe, busy execution, enabled
geometry, enrollment/bindings, cancellation before/after probe and late cancelled
replies. The actual Runtime destructor **prefix** is executed with fake external
workers/storage to demonstrate audio drain before GS stop/backing retirement;
this is not execution of the whole runtime or a game. Removing the early drain
or global-control exclusion fails its respective private negative control.

Both compilers separately compile four complete actual source objects: Route,
Runtime, GS and actual ParallelBackend with flag2. Final object checks use the
fresh matching SDK, current authored bodies and **sealed V8** graphics/raylib
headers, with every consumed sealed member checked against the build-kit
manifest. The compile-plan and existing owned generated catalogue receipt are
pinned; old SDK headers and loose active/build-ninja/private build headers are
rejected. Before/after include checks qualify the current authored source
cohort. Earlier loose-header object trials remain preserved but are superseded.

The complete prior126 companion/PCM/bank regression driver is adapted only for
127 patch count/output paths, retaining its original expected observations and
negative controls. No actual Vulkan/device/audio/game execution, full library
build, runtime-RAM authority or performance improvement follows from these checks.

Final identified cohort SHA-256:
`c2d2d7f3eed64182be837fc3dd420576a1e076c091298b2ceee31af65b8bb56f`.
The [qualification chain](../../tools/native_reconstruction/gs_sound_ram_profile/qualification.json)
SHA-256 is `cf4a748a6ebac3cc0e08e8f421a7c398f2f0cdd4a67178175c44b3ffe4f65b52`.
It identifies the authoritative final127-v4 tree, exact patch/header/app bytes,
all six final receipts and the sealed graphics/generation inputs. Earlier v1?v3
sources and failed/intermediate object/unit trials remain preserved.

Receipts under ignored `build-native-sjuni/gs-sound-ram-profile`:

| Receipt | SHA-256 | Result |
| --- | --- | --- |
| `gcc-unit-sealed/receipt.json` | `513c944a160e0d5cdaf3d37c90177ef2730363704423ce3a7b8d2c3a3ab37cd3` |21 checks PASS, including expected negative exits |
| `llvm-unit-sealed/receipt.json` | `3dd55fde47fbd7032a375928d5e1529cf5c806153f73de9c7ab53ed9f67a3a68` | Same PASS |
| `gcc-objects-final/receipt.json` | `35810fe7228d4c6f7e28fae698843b16aefde50795a0e4d67717bdbcc18b2020` | Four full objects /229 identified project inputs PASS |
| `llvm-objects-final/receipt.json` | `c71338244d956bab117ddfd38ba079afe9275903af2791bac8819e643467a620` | Same PASS |
| `gcc-regressions-final/receipt.json` | `7d2155aeb373bbc4dd7c5ac042dd47062ad275b79d1876798c86108830f75511` |32 companion cases plus prior suites/original observations PASS |
| `llvm-regressions-final/receipt.json` | `94355ee35776789c596165c96c236a774c14d325e96ed522fbda6456ccb39ebb` | Same PASS |

Final object inputs use sealed V8 manifest
`435ae2791088c3061ffd2caa3617924daa9d1b8815eb441512f4c9f50e5b4ea0`,
compile-plan `45d04b5734479a6c97270f9fe2e6788b50dfebc049837d8eeea88cda27ef0c02`,
and owned generation receipt
`864b997e4b0db93b281a50513919232483b43ad0e43df8ad0ebd0552438aa5e3`.
System headers are outside the229 project-input count; compiler executables are
separately hashed. SDK, authored, generated and consumed-include postchecks are
empty. No older private build folder supplies final SDK/graphics/raylib headers.
