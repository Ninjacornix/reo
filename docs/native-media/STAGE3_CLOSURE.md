# Stage 3 closure checklist

Current direction, 2026-11-08: [modernize and remove PS2-specific systems](../NATIVE_MODERNIZATION_DIRECTION.md).
The older checklist below records the reconstruction route. A complete modern
replacement can retire those internal requirements; preserving old movie ring,
transfer and scheduler implementations is not a closure requirement by itself.

Current File #1 status:

| Boundary | Established evidence | Remaining work |
| --- | --- | --- |
| Resource/audio ownership | Coherent native mount, ordinary ADX workers and PCM/bank/RAM composition install and join through the real launcher-core route. [Queued preparation](NATIVE_AUDIO_QUEUE_PREPARATION.md) and the [engine cue binding](NATIVE_AUDIO_CUE_CONTROLLER.md) pass 80 native suites, 34 real-asset adapter cases and 10 detected faults on each compiler. [Real-asset admission](OWNED_AUDIO_CUE_ADMISSION.md) checks all 8,910 structural ADX members. | A new coherent queued-binding game retest, accounting for 89 inline-loop refusals where queued use requires them, and retirement/representative resource and room transitions. |
| Converted movies | [Preparation](../../tools/native_media_import/README.md) covers 201 references / 200 physical movies; the native OS reader validates 216,998 pictures. Full game opening/scenario/looping backgrounds and bar gameplay run with original MWSFD slots zero in observations. | Final coherent candidate control/error/transition coverage and A/V synchronization. Sampling is not proof that every old path is unreachable. |
| Native controls | [Player/session](../../game/native/host_movie/README.md) pause/resume, EOF/restart, loop, replacement, stale-command refusal, decode error and recovery pass on both compilers. [Game input](NATIVE_MP4_V27_GAME_CONTROLS.md) validates movie skips and gameplay Pause/Exit/movement. | Account for required game-facing active-movie pause/error callers; standalone behavior does not itself validate those callers. |
| Packaging | [V28](NATIVE_MP4_CANDIDATE_V28.md) completes the real launcher-core route with automatic verified preparation; SDK profile publication is implemented. | Avalonia UI route is separate from the tested core harness. Do not continue listing automatic preparation as unimplemented. |
| Audio resilience | [Native read-ahead](NATIVE_AUDIO_PREFETCH.md) passes 78 native suites, 28 adapter scenarios and 10 detected injected faults on each compiler; controlled blocked-read tolerance improves. [V31](NATIVE_MP4_CANDIDATE_V31.md) completes the game route with the actual 64 KiB profile and zero recorded underruns. | Historical incident cause remains unknown; one clean retest does not establish its fix. |
| Retirement | Ordinary native workers replace their old producer/transport path on the tested route. [Audit](MEDIA_RETIREMENT_AUDIT.md) records the remaining shared initializer and effect-MOV consumer. | Account for required effect/queued-source consumers before retiring their shared support. Guest control and renderer interfaces remain explicit until stages 4/5; final build dependency removal belongs to stage 6. |

The [V26 capture](NATIVE_MP4_CANDIDATE_V26.md) retains an 830.546 ms public movie
freeze with an 841.3405 ms producer-publication gap. Later matched and repeated
runs do not reproduce it; its cause is unconfirmed. The [V29 trace](NATIVE_MP4_CANDIDATE_V29.md)
localizes 17,376 audio-underrun frames to 383.3659 ms while controller service
continues every 16.6-16.8 ms. The [V30 runs](NATIVE_MP4_CANDIDATE_V30.md) are clean
without a refill/scheduling change. Useful source-detail telemetry is now
available for another occurrence; clean runs do not supply a root cause.

Step 3 now closes on native resource/media consumers working in the game,
converted assets where useful, complete playback and audible synchronization,
pause/skip/repeat/error/shutdown and room transitions, measured stutter retests,
and retirement of the replaced PS2 media paths. A temporary game ABI bridge must
remain explicit until its callers migrate. Do not require an unused legacy
profile merely because a historical test or implementation modeled it.
Step 3 remains incomplete; the conditional PC sleep action has not run.

The user is away; subjective A/V synchronization remains unconfirmed. In-engine
cutscene rendering belongs to the gameplay/rendering migration, not MP4 asset
conversion. The temporary tiled renderer interface is a stage 5 migration item,
not a claim of fully native presentation or a reason to reconstruct PS2 media.

## Historical reconstruction checklist and checkpoints

Status: active work, starting at local commit `959d2198`. This is a gate checklist,
not a weighted percentage. Passing more isolated tests does not substitute for
consumer integration or game transition evidence.

Latest checkpoint (2026-11-08): V19 selects the ordinary native audio backend
but stops at an admission refusal before source playback. The mono-pan
correction is qualified and [V20 links](ADXT_CANDIDATE_V20_BUILD.md). Its game run
passes mono admission but [stops at missing mixer order](ADXT_CANDIDATE_V20_ORDER.md)
before native source PCM playback. The [canonical movie audio capability](MOVIE_CANONICAL_AUDIO_SOURCE.md)
and [game handle/prepared-graph handoff](MOVIE_GAME_HANDLE_HANDOFF.md) pass both
compiler cohorts with real source workers and declared video/component ports.
They are not actual movie hooks or paced GPU/A-V evidence. User-authorized
[old build cleanup](OLD_BUILD_CLEANUP_20261108.md) cleared the storage gate.
Both compilers pass the full 78-suite native cohort, the bounded order adapter's
21 scenarios/eight runtime faults, and five actual SDK130 units. A new matching
game candidate and live retest are next. Three-source order is required by the
earlier original capture and is still unresolved. Stage 3 is incomplete; the
user's conditional PC sleep request has not been executed.

The reconstruction plan requires matching resource loading/completion behavior,
audio/movie output and lifecycle transitions. Its first selected edition is
File #1 US. File #2 admission requires its own address/behavior validation.
Stages 4-6 remain separate; no runtime dependency is removed by this checklist.

| Required boundary | Existing evidence | Remaining closure work |
| --- | --- | --- |
| Native resource/PAK reads | Verified imported files/ranges, native mount/reader, bounded read owner, guarded synchronous game payload tests. | Include those same sources and selections in the final coherent candidate; retest loading, cancel/reopen, room/resource transitions and shutdown. |
| Compressed audio ownership | Native ADX codecs, header/window/refill, real source workers, ADXT Session, service clocks, regular loops and bounded LSC owners have separate comparisons. | Bind admitted consumers to the canonical native Session and actual service ordering; validate live loop/LSC, pause, replacement and source/output retirement. |
| PCM/bank/RAM output | V11/V12 prove complete-backend selection and joined retirement. V13 links the qualified SID 1 / RPC 0x10 reply and completes the same cinematic/gameplay route without that refusal, with joined retirement. [Late cinematic hitch evidence](AUDIO_CANDIDATE_V13_STUTTER.md) remains explicit. | Validate combined native player/output routes across representative rooms and packet/bank domains; resolve the outstanding hitch with additional incident evidence. |
| Movie timing and video | Native clocks, controls, frames, lifecycle and timestamps have comparisons. All 201 File #1 movies decode/present 216,998 independently counted pictures on the GPU after rebuild. Pending service matches 515 original cases on both compilers. | Bind the logical/physical movie owner and service providers to game scheduling and source controls; qualify skip/recovery and error profiles. |
| Whole movie/audio behavior | Existing original/native historical opening runs; new owners have standalone and offscreen evidence. | Full-stream I/P/B, decode/reorder/skip, pause/resume/frame step, repeat/stop/rebuild, error/EOF and audible A/V validation through the selected native graph. |
| Coherent game integration | Separate earlier candidates validate narrower cuts; new media cores are not linked by those old binaries. | Build a fresh source/compiler/dependency-identified candidate, verify actual native handshakes/body execution, and run matched original/native media and resource transitions. |

Completion requires an evidence reference for every admitted boundary and an
explicit list of unsupported profiles. Unsupported required consumers cannot be
made successful by falling back after native effects, dropping frames/audio or
inventing completion. Existing controls must preserve original game speed;
diagnostics must not silently select experimental rendering or VU paths.

The stable [ADXT instance facade](ADXT_INSTANCE_OWNERSHIP_CONTRACT.md) now passes
actual source/peer-retirement and detected-fault checks with both compilers;
the combined project has 72 passing standalone suites. It is not a game ABI
binding. The [two-slot priming checkpoint](MOVIE_PRIMING_RESULTS.md) now separates
logical capacity from decoder/reorder storage and passes all 201 owned movie
streams with two ready pictures before playback. Actual scheduler/control/source
binding and paced game validation are still required.

The [external native submix](NATIVE_AUDIO_SUBMIX_RESULTS.md) now composes real
native player workers with the complete bank/output model through one callback.
It qualifies private/outer fence separation and preserves the null-profile
reference observations. Its native-stream profile admits cold wire reset before
the first native producer, but still refuses original PCM production and later
reset. Actual source/control/reset binding and a coherent
game candidate are required before this becomes an admitted game route.

The [V14 incident retest](SIF_INIT_RPC_STALL.md) narrows a measured 1.45-second
movie hitch to the host `SifInitRpc` initializer. Its inner lease/lock/logging
cause is unresolved. The qualified bounded stage probe is linked in V15. That
run does not reproduce the large stall: sampled movie intervals peak at
41.0778 ms and audio reports zero underruns. No initializer policy changed,
so this is not a confirmed fix; the historical disc-read explanation is not
substituted for missing attribution.

The timestamp and complete short-video gates have advanced beyond the earlier
first-frame boundary. All 201 hash-verified File #1 SFD members (2.26 GB) contain
no C0-DF or BD audio packets, so this edition's audio gate is its separate ADX
game-consumer route. Native embedded-audio demux is not substituted for that
actual integration requirement. The next work is broader video coverage and
logical/physical game scheduling, alongside separate ADX/output integration.

The [resource mount handoff](NATIVE_MEDIA_RESOURCE_HANDOFF.md) now gives media
consumers the same validated immutable source ownership. Both compilers check
late/foreign refusal and real mono/stereo imported sources after the declared
runtime, mount and trees disappear, matching the qualified PCM baseline. These
tests retain explicit runtime/bridge ports; final game resource transitions and
source/control/scheduler consumers remain required. Native integer volume and
live host route gains are also qualified through the instance/output boundary.

The [controller admission guard](ADXT_CONTROL_OWNER_RESULTS.md) closes native
controls before source teardown, including a caller already waiting at stop.
It passes real worker/private-render fencing and three injected faults on both
compilers; the combined native project now has 73 passing suites. Fifteen
aggregate scenarios include controller destruction with an accepted outer
callback. Actual runtime registration and game callers remain unbound.

The [attenuation integration](ADXT_ATTENUATION_PLAYER_RESULTS.md) now consumes
the original signed volume units and owned integer table through the phased
player and stable instances. Both compilers pass 74 native suites, five instance
workflows, 15 aggregate scenarios and real imported mono/stereo sources at the
correct table volumes. This advances source controls; it is still separate from
the guest API/runtime/scheduler and whole movie/audio transition gates.

The attenuation profile also admits immutable sequences and dynamic LSC queues
after checking the sealed clip metadata invariant. Both compilers pass the
74-suite cohort and the combined callback with a dynamic source and stereo peer.
This removes the earlier conservative native refusal; actual guest callbacks,
runtime registration and source/service callers remain required.

The explicit [native source runtime factory](NATIVE_AUDIO_MEDIA_FACTORY.md)
now registers the canonical source owner alongside the same real RAM/device
composition. Both compiler protocol cohorts pass 12 scenarios and complete
production-header object checks. Its acquisition/device ports remain declared
fixtures, and the bootstrap still selects the prior route. A complete guest
source/control/clock/reset adapter is required before this factory can be used
for the coherent game candidate.

The [stable game-control bridge](ADXT_GAME_CONTROL_RESULTS.md) now exposes the
qualified clocks, quiescent global import, paused discard and persistent
time-base/loop controls. Both compilers pass 75 suites, three detected admission/
replacement faults, 12 combined factory scenarios and production-header checks.
The original public ABI and idle-handle semantics still need their actual guest
binding; native API coverage alone does not close that boundary.

The [V16 production preflight](NATIVE_MEDIA_COHERENT_PREFLIGHT_V16.md) passes all
182 authored/runtime units with the actual bundled toolchain and coordinated
130-patch SDK source cohort. It links no game and installs no new source hooks.
The [handle admission reader](ADXT_GAME_HANDLE_ADMISSION.md) separately checks
actual constructor layouts' independent 16/40/32 slot domains; live guest
admission and the remaining ABI/lifetime boundary are still required.

The [guest handle router](ADXT_GAME_HANDLE_ROUTER.md) now connects prepared game
identities to the same native instance owner. Both compilers pass real-worker
mapping/reuse tests and detect three ownership faults. It retains both stereo
transfer reservations and awaits actual source join before reuse. Its original
ABI hooks and runtime admission are not installed, and it is outside V16's kit.

The [wait-for-start control](ADXT_START_GATE_RESULTS.md) now reaches the native
player through the stable facade. Both compiler cohorts preserve buffering,
readiness, exact release tick and replacement/pause behavior. This closes a
missing native control exposed by the engine caller audit; the guest hook and
the remaining source/service/ABI work are still required.

The [game service-divisor control](ADXT_SERVICE_DIVISOR_RESULTS.md) now preserves
the engine's explicit 30 Hz setting. Both compilers pass 77 native suites,
96 original ready rows, 192 native channel cases and three detected faults.
The distinct window ABI supports the larger loop request through the existing
bounded workspace; the guest hook remains uninstalled.
