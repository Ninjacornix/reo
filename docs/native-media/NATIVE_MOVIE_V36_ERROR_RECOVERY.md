# V36 game-facing movie error and recovery

The private background acceptance case `20261109-040503-909` completes the
required injected movie-worker failure, original caller cleanup, return to the
movie list, full replay, another replay/skip and a scenario-playlist start/skip.
This establishes game-facing error recovery for that native File #1 route.
It does not establish a naturally occurring codec defect or complete Step 3.

Sealed source revision is `2140b453cb275baf8de1e78835c21b6e53128bd7`,
launcher context `0665014aa0ec5b7b58afcdf269564b5989ac8074`, and executable SHA256
`eb50b048f8ce4b42101e277ecce20734117b7613d59f4433edcd2f485d3d6229`.
The ordinary input-only driver records every gate passing in 285.609 seconds.
The game then closes normally: exit 0, no forced cleanup, joined owners, total
361.8323261 seconds. No desktop window is constructed by the core harness.

## Injected failure and observed recovery

The test-only worker fault requires both the exact admitted E3 native asset
key and private background mode. It is armed once for the lifetime of the
canonical native `Session` worker. After an actual decoded/transferred/readback
picture reaches ordinal 120, it throws through the existing source-failure
handler. The handler closes player/standby sources, retires frame resources,
publishes native `State::error` and leaves its control owner available.
No prepared asset is corrupted and no guest completion state is manufactured.

`stderr.log:2601` identifies generation 4, the expected asset key and ordinal
120. Line 2602 records exactly one
`[NATIVE-HOST-MOVIE-ERROR] Injected native movie acceptance worker failure`.
The native public status hook emits that line when returning game status `4`.
The original status-4 branch in `o0:37A5A0` routes to `37A4E0`; observed gallery
state then returns from active playback to the movie list. The original branch
and cleanup sequence are corroborated by the prior owned-word audit; this
case does not contain a separate instruction-by-instruction trace of cleanup.

The optional `failed source destroyed` log is correctly absent. Original
`37A4E0` first calls vtable slot `1C` (Stop) at `37A528`, then slot `14`
(Destroy) at `37A544`. Native Stop clears `started` and the generation before
Destroy. The optional Destroy log is conditioned on `started` still being true
and the native state being error, so its absence cannot be used to reject this
normal original Stop-then-Destroy path.

| Generation | Producer evidence | Observed outcome |
| --- | --- | --- |
| 4 | 120 retained publications, ordinals `0..119`, lines `348..467` | Worker fault logged at actual ordinal 120; source error reaches original caller and gallery returns to list. |
| 6 | All 6,144 consecutive ordinals `0..6143`, lines `497..6640` | Same canonical session accepts a fresh generation and reaches full E3 EOF. Maximum publication interval 55.925 ms; no backpressure. |
| 8 | 130 publications, ordinals `0..129` | Second replay passes the fault point without reinjection; ordinary Circle skip returns to list. |
| 10 | 132 publications, ordinals `0..131`; source-start log declares nine clips | Queued scenario playlist starts and is deliberately skipped. This is not a complete nine-clip playback claim. |

The fault is thrown before its final iteration trace row is committed, so
ordinal 120 is evidenced by the explicit fault log rather than a retained
producer publication row. Generation 4's partial trace is expected and must
not be described as a full movie. Generation numbering continues through menu
sources; the canonical session is retained while individual engines/sources
are stopped and reopened.

The complete producer/consumer traces retain 9,243 and 9,217 rows respectively,
both `dropped=0`. The final native movie report records 11 source starts,
9,137 delivered frames, joined shutdown and current `error=none`. That final
current-source state does not erase the earlier intentional error.

## Audio, launcher status and retained earlier attempts

Native output records 16,321,920 frames and **zero underrun frames**, hard
failures, queue rejections or submix failures. Source/output owners join. The
audio-control analyzer parses 20,423 snapshots with zero dropped/invalid rows
or counter/time resets and finds no shortage windows. The cue owner accepts
and finishes four commands, has no failures or remaining records and joins.
“Finished” here includes cancelled/failed-source command retirement; it does
not mean four complete soundtracks reached EOF.

The generic launcher-core check deliberately remains
`native GameSession check failed`, with native/media error flags true and
`Movies: native media error (see session logs)`. The launcher observes and keeps
the diagnostic error even though later playback recovers. This is honest error
reporting for an expected-fault test; it is not a generic clean-session pass.
Acceptance comes from the separately recorded one-shot fault identity, recovery
gates, complete fresh playback, exact final counters and normal retirement.
The closing log also retains `Error during program execution: PS2 Thread Exit`;
exit 0 and joined retirement are recorded independently. No error-free-log
claim is made.

Earlier case `20261109-034932-081` remains preserved. Driver v2 incorrectly
required the optional Destroy error log and failed that test assertion after
the gallery had already recovered. A v3 helper has a retained syntax failure.
The v4 continuation observes recovery and starts replay, but the bounded game
run ends while its observer is still waiting, retaining WinError 299 and a last
observed replay frame of 5052. That case exits 0 without forced cleanup; the
observer exception is not evidence of a game crash or completed replay.
The new v5 case supplies the full end-to-end evidence instead of rewriting
those earlier results.

The separate normal V36 gameplay case
[fails audio resilience](NATIVE_AUDIO_V36_RESOURCE_STALL.md) with 90,208 underrun
frames during resource/service stalls. This clean-audio gallery failure test
does not cancel that finding. A native refill improvement and its controlled
and game retests remain outstanding. No V37 integration or Step 3 completion
is claimed here, and the conditional PC sleep gate remains closed.

Evidence: `build-native-sjuni/movie-error-v36-qualification-v1/analysis.json`,
the completed sessions above, the retained driver versions, sealed V36 sources
and source/build/package identities in the accompanying qualification. This
audit only reads completed evidence; it performs no game, process, input or
window actions.
