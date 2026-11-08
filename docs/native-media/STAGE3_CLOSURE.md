# Stage 3 closure checklist

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
