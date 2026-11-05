# Complete PCM backend installation boundary

Status: read-only source audit and reviewable patch design, 2026-11-05.
No dependency, native core or game source was changed; no device, game or build
was run. The [standalone PCM owner](../../game/native/pcm/README.md) and
[device-lifetime audit](PCM_DEVICE_LIFETIME.md) supply separate implementation
and source evidence. This document does not claim an installed native backend.

The correct cut is **one complete PCM backend for the runtime session**, selected
before the first public PCM call, including bank-only host-output startup. Every
queue, voice, watermark, clock and shutdown operation must use that same owner.
An operation refused after native publication cannot be retried against unrelated
legacy queues. Full dispatch coverage and complete behavior admission are distinct:
the former can be implemented now; the latter still has explicit gaps below.

## Exact inputs

Use the public reconstructed121 tree based on
`c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`, independently reapplied at
`build-native-sjuni/dependency-workers-reapply-v2`. Its receipt SHA-256 is
`2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8`.
The five PCM/RPC source identities are pinned in
[PCM_OWNER_EXTRACTION.md](PCM_OWNER_EXTRACTION.md); in particular complete
`CriAudio.cpp` is
`39dce6882e561ad69a0112a330ecc4023a98c21365ac2fe8709f838fce4c9a06`.
The dirty active submodule's different audio implementation is excluded.

The exact raylib source is revision
`c1ab645ca298a2801097931d1079b10ff7eb9df8`, `raudio.c` SHA-256
`2d6a2d5b9f86b44b879605f654659c542a317d97477ddfde54683019e8bfeacc`. The
[audio-output transform](../../tools/local_build/prepare_audio_output.py)
changes initialization/device selection, not the callback/unload functions.

## Versioned dispatch patch

Add a private runtime header, for example `cri_audio_backend.h`, defining a
version-1 complete backend interface, interface size/version, supported
capabilities and a strongly owned session instance. It contains ordinary host
types; it must not require game headers or expose a guest context to callbacks.
All eleven current facade exports remain source-compatible. The new runtime
registration function accepts one complete owner, rejects null/partial/wrong
version registrations, and returns an explicit installation status.

A practical C++ static-library boundary is a version-checked abstract interface
owned by `shared_ptr`, rebuilt with the matching toolchain/runtime. It is not a
portable C/plugin ABI. Do not use `atomic<shared_ptr>` with the pinned libc++
configuration; use a short registry mutex and take a strong snapshot, then release
the registry lock before invoking any backend or destroying a possibly last owner.

The facade's selection state is `unselected -> legacy` or
`unselected -> native(session identity)`. The first exported operation seals
legacy selection if installation has not completed. Installation and first use
must serialize at one publication point, so they cannot race into mixed maps.
There is no per-operation fallback or late legacy/native switch. A stopped native
selection remains stopped until its owning runtime is destroyed; it cannot reopen
the old legacy host stream during destructor cleanup.

| Public export | Required selected-owner behavior |
| --- | --- |
| `ensureHostOutput()` | Poll host mixer settings, then ensure the one shared output stream. It must clock/play bank-only menu audio before any CRI PCM arrives; it cannot remain wired to legacy output. |
| `queue(key,bytes,length,endByte)` | Validate zero key/pointer/length, odd bytes and `length>0x4000` before output creation or ticking. Valid requests ensure output, advance the one headless clock once, then copy PCM16 into owned storage. A queue-cap failure follows that advance and leaves `endByte` unchanged. Success returns the source-byte end watermark. |
| `configure(voice,left,right,nch,freq,vol,playing)` | Ensure output and tick once **before** inserting/updating the raw voice. Preserve `min(nch,2)`, zero-rate default then 8..96 kHz clamp, raw unsigned volume, phase, pause/drain and playing-transition debt reset. Preserve old/new traversal timing described below. |
| `consumed(key)` | Tick once before lookup, including an unknown key; return zero for unknown keys. Watermark units are source bytes actually popped/skipped/discarded, not device frames. |
| `render(stereo,frames)` | Select frame clock even for zero frames; capture all stream gains in actual voice-map order; render CRI, then release PCM/owner state locks before bank mixing, then apply master gain and final clamp. Null output can advance CRI without bank output. |
| `discard(key)` | No clock tick. Existing queue becomes empty and consumed becomes queued. Unknown key is a no-op. |
| `drain(voice)` | No clock tick. Only an existing playing voice with nonempty left queue enters drain; accepted PCM remains owned. Unknown/ineligible voice is a no-op. |
| `release(voice)` | No clock tick. Erase that raw voice/order binding; invalidate its native voice token, retain its channels and every other voice. Unknown key is a no-op. |
| `queuedSamples(key)` | No clock tick. Return queued halfword/sample count, zero for unknown keys. Do not call `consumed` to implement this query. |
| `reset()` | Reset stream routes and PCM voice/channel maps/handle generations, reset clock selection/last tick, preserve diagnostic frame totals. Retain a live provider stream and independent bank voices. |
| `shutdown()` | Close admission, fence active calls and the actual stream callback, stop/unload exactly once, reset PCM and then separately reset banks. Idempotent after runtime ExternalWorker join. |

No private legacy path may access its old maps while native selection is active.
The fallback legacy implementations should be separate internal functions, so
an exported method cannot accidentally recurse into dispatch. Preserve existing
optional diagnostic/capture behavior or report a clearly narrower capability;
diagnostic mirrors must never become a second PCM queue owner.

## Pre-run installation and runtime ownership

1. Validate supported File #1/native build, interface version, source-qualified
   provider and actual runtime identity. Construct native queue storage, finite
   metadata/order buffers and host owner before any callback is published.
2. Reserve the untouched facade selection transaction. Register the owner as a
   `PS2Runtime::ExternalWorker` after final initialization/ELF load and before
   `run()` seals registration. Keep a strong runtime-owned reference.
3. Publish the complete backend in one final registry operation. If publication
   fails after worker registration, leave the worker inert: accepted registrations
   have no unregister operation. An inert owner must stop/join safely and must
   never publish a callback. Legacy remains available only if no native state or
   stream was exposed.
4. The selected owner may lazily create the stream when the existing facade first
   asks for output. Serialize provider creation/retry separately from PCM state;
   never call provider functions while holding the PCM, bank or registry mutex.
   No device readiness means native headless operation, not a legacy queue retry.
5. `requestStop()` only closes admission/signals stop. It is nonblocking,
   idempotent and safe concurrently; it must not detach, unload, wait, enter guest
   execution or destroy a possibly active callback lease.
6. `join()` from a non-callback owner thread waits its own admitted producer calls,
   fences/removes the callback and joins the host owner. Return true only after
   no admitted I/O/callback can use its runtime/state. A failed fence retains
   storage and reports incomplete shutdown; a timeout is not lifetime proof.

The normal runtime exit at `ps2_runtime.cpp:3731..3735` joins guest producers
before ExternalWorkers. Destructor fallback and early run unwinding can invoke
ExternalWorker join earlier. Therefore the PCM owner cannot rely solely on
normal guest-join ordering: it needs its own admission gate and in-flight call
leases. The runtime's worker list retains the owner through later
`ps2_cri_audio::shutdown()` and destruction; that later facade call must recognize
the already joined backend and must not reopen output or double-reset banks.

The present source supports a single process-global facade. The first native cut
should admit one matching runtime instance per process; do not imply arbitrary
concurrent/sequential runtime replacement without a qualified registry protocol.

## Provider fence and lock order

For the exact raylib source:

| Function / source line | Source-level ordering |
| --- | --- |
| `OnSendAudioDataToDevice`, 2487 | Holds `AUDIO.System.lock` over tracked-buffer traversal, mixing-format reads and callback invocation. |
| `ReadAudioBufferFramesInInternalFormat`, 2344 | Calls `audioBuffer->callback` synchronously before returning. |
| `SetAudioStreamCallback`, 2216 | Acquires the same system lock before replacing the callback pointer. |
| `UntrackAudioBuffer`, 748 | Acquires that lock, removes the buffer from the tracked list and clears its links. |
| `UnloadAudioBuffer`, 621 | Untracks first; only afterward destroys converter and buffer storage. |
| `CloseAudioDevice`, 524 | Uninitializes the system mutex before `ma_device_uninit`. It is not an admitted replacement for a prior PCM-stream fence. |

On a valid live provider, join must retain the callback owner, then call
`SetAudioStreamCallback(stream,nullptr)`, `StopAudioStream(stream)`, and
`UnloadAudioStream(stream)` on one serialized provider-control thread. The
callback-null operation waits for an earlier invocation holding the system lock;
untracking prevents future tracked-buffer access. Only after both return can the
callback slot's strong owner lease be cleared and native storage reset/released.
This covers the registered route, not manually captured callback pointers,
concurrent double unload, unverified providers or device recreation.

The callback has no userdata parameter. A private session-scoped trampoline can
take a strong owner snapshot from a short protected slot; publish that slot before
registering/playing and retain it until the real fence. The callback may acquire
the PCM owner/core locks while the audio-system lock is held. Thus no producer or
join path may hold registry/PCM/bank/guest locks across detach/stop/unload. A
separate provider-lifecycle mutex is acceptable only if the callback never needs
it. No guest/RPC callback or RAM access belongs on this device thread.

Current RPC callers often hold `g_dtx_rpc_mutex` while entering the facade.
Their admitted state work can follow RPC -> owner -> core. The audio callback
must never acquire that RPC lock, and provider lifecycle calls must not occur
inside an owner/core critical section. Bank mixing runs after owner/core locks
are released. A registry snapshot never remains locked while invoking an owner.
Avoid destructing a last owner/lease under these locks as well.

The 48 kHz float32 stereo stream's provider input request is bounded to 512 frames
by `ReadAudioBufferFramesInMixingFormat`'s 4096-byte input buffer divided by eight
bytes per frame. This supports the native core's larger default frame bound for
this provider. It does not admit arbitrary public manual `render` sizes.

Device initialization occurs in runtime `initialize()` before native pre-run
installation; headless mode may have no device. A reset while the stream is ready
must not accidentally enable simultaneous headless advancement before the next
callback: preserve the source's `ready || externalClock` suppression. If device
state/version has changed unexpectedly, do not treat `IsAudioDeviceReady()==false`
as a fence receipt. Source-qualified device changes and other audio streams still
need their own lifecycle validation; PCM join must precede runtime device close.

## Raw IDs, order transactions and remaining protocol ownership

Keep raw RPC metadata in the adapter, mapping to native handles; the core must
not interpret guest addresses. Preserve actual raw voice-map traversal using the
explicit mix-order contract in [PCM_RENDER_ORDER.md](PCM_RENDER_ORDER.md), not key
sorting, insertion order assumptions or native slot order. Gains are sampled at
the original render boundary, before CRI rendering; bank gain/master order stays
separate. Host setting polling remains on the producer/control path.

For an existing voice, configure ticks with the old configuration/order, then
updates it. For a new raw voice, source ticking occurs before map insertion/rehash.
A transaction must preserve old contributing order for that one headless advance,
then publish the post-insertion order before releasing the owner lock. Staging a
new inactive native voice is possible only if it does not reorder contributing
voices or add an extra tick. Calling `advance_headless(now)` followed by another
clocked configure is wrong when the 250 ms cap leaves further catch-up.

Unknown raw `consumed` queries similarly require exactly one tick then zero.
Known typed-handle queries already tick; a wrapper must not tick twice. For any
new facade primitive, record whether it polls settings, advances time or merely
inspects state before composing existing core methods.

RNA destroy at RPC line 2093 releases the host voice before erasing its metadata.
SJRMT destroy at line 2153 erases ring metadata with **no PCM channel close**.
The legacy PCM numeric channel therefore persists until reset. A source-compatible
first queue extraction can retain that same numeric mapping until reset; it must
not claim to have repaired guest ring incarnations. Alternatively, explicit ring
generation qualification requires a focused RPC protocol patch: capture generation
at queue/binding time, retain it in pending credit records, and query that generation
at retirement. Closing a channel blindly on SJRMT destroy loses retained samples
and can misattribute old pending credit after handle reuse.

`dtxAllocUrpcHandleLocked` scans 4096 candidates and then returns its base even if
occupied. CREATE assigns into raw maps, so IDs are not incarnation identities.
The actual File #1 profile in `recomp/overrides/reo_override.cpp:1795..1796` uses
`[001E0000,001EFF00)` and default stride `20` hexadecimal: 2040 possible numeric
IDs across object kinds. This is a potential bound only after validating that
actual profile and proving queued keys originate from its SJRMT map. It is not
4096 distinct voices or an arbitrary-facade bound. Retaining all historical channel
keys at 96,000 samples each would reserve about 391.68 MB for 2040 channels; choose
such a memory cost deliberately rather than silently using a smaller unsafe cap.
The different `01F18000` range in dependency `applyRecvxDtxCompat` belongs to
Code Veronica and is not File #1 Outbreak's capacity evidence.

The pending/reply ledger remains RPC-owned: successful queue returns an end-byte
watermark; whole SJ replies become eligible with the existing `0x6000` lead;
playback retirement updates consumed prefixes separately. Host copy/device output
does not authorize a new guest reply, free-chunk identity or immediate ring reuse.

## Admitted inputs, errors and concrete blockers

All valid admitted operations must complete in the selected owner. Existing queue
validation/capacity rejection can map to `false` with unchanged `endByte`; preserve
the original tick-before-cap ordering. Native construction/registration failure
before publication can retain the complete legacy backend. After publication,
allocation failure, slot exhaustion, missing order or unsupported domain cannot
silently retry legacy or masquerade as a successful void configure.

The other facade exports have no error return. Before default activation, either
prove their full reachable admitted domain, extend the core/bridge with exact
behavior, or add an explicitly reviewed protocol-level error path. Logging an
unsupported configuration while skipping a required voice is not equivalence.
The first implementation may remain a default-off bounded candidate and report
an explicit diagnostics failure; this is not general fallback/lifecycle proof.

Concrete source facts distinguish exclusions from retail-game evidence:

- `PS2RNA_CREATE` stores both supplied SJ handles without a distinctness or
  ownership check. `configurePcmVoice` resolves each independently. Two RNA
  records can name the same ring; two SJX records can resolve to one destination;
  stereo left/right can be the same raw ring. Thus sharing/aliasing is reachable
  through accepted HLE input, even though no captured retail session is shown to
  issue it. Exclusive native channels are a narrower domain, not a source theorem.
- Source configure accepts raw voice zero, zero/missing left, disabled channels,
  and stereo with missing right. Rendering skips `!left` without starvation;
  missing right with a nonzero left accrues starvation/debt. Do not map both cases
  to one disabled state or simply reject all void configurations. A latent raw
  descriptor/per-voice empty helper channel is a possible adapter design, but
  needs independent fixtures before becoming an admitted translation.
- Shared channels make consumption depend on voice traversal. Same-channel stereo
  can perform two deque pops and may reach undefined empty-pop behavior; do not
  invent a safe arithmetic result and call it source parity. A complete native
  domain needs explicit sharing/alias policy and original-defined-input evidence.
- Native finite capacity, generation/counter exhaustion and manual render bounds
  are explicit admission rules. The HLE source's global maps are not equivalently
  bounded by the current native defaults. Raw-ring reset/close/reuse cannot be
  solved by treating a uint32 handle as a durable native lease.

## Patch and validation sequence

Follow the [dependency patch workflow](../../third_party/patches/README.md).
The audited baseline has 121 patch files through `0120`; read the actual series,
not the README's historical 0099 count. Prepare the focused dispatch/lifecycle
change as the next numbered patch in a separate reconstructed checkout. Reapply
the full series to another clean base, compile the affected runtime/backend
against matching headers/toolchain, and seal a fresh private candidate. Never
reuse an old runtime archive with the new dispatch header.

Before game activation, independently exercise all eleven exports, untouched
legacy selection, absent/wrong/partial ABI installation, first-call races,
failure-before-publication, owner stop while a producer/callback is active,
self-join refusal, real provider fence order and repeated idempotent shutdown.
Test headless configure insertion across a >250 ms gap and unknown consumed
queries to catch double advancement. Add the missing/zero channel, shared-channel,
capacity and qualified raw-generation cases before broadening their domains.

Then run separate opt-out/native sessions with source/build identities, actual
native method evidence, bounded producer PCM comparisons, unskipped media,
pause/transition/reset/destroy and normal window-close join receipts. Mock fences
prove only the owner protocol; real raylib/device close and callback races need
their own evidence. Successful byte comparisons do not prove speaker/mix timing,
all supported editions, a performance improvement or completed native media.
