# File #1 movie control caller audit

2026-11-09. This is a static audit of owned original words and the current native
replacement. It does not record a game pause, injected error, or recovery test,
and does not close Step 3.

The retail collection movie viewer has completion and skip controls. An active
movie pause button is not part of the reviewed viewer state machine. Requiring
such a button solely to reproduce an old decoder API would add a feature rather
than validate this caller.

| Boundary | Verified source behavior | Consequence for closure |
| --- | --- | --- |
| Collection playback `o1:57B730` | Starts through `570180`, polls readiness through `5704D0`, completion through `5703F0`, and calls `5705D0` on input masked with `30` at `57B8AC`. Its bounded startup wait also stops the movie. | Exercise actual EOF, replay and skip, including companion queued audio and retirement. This body does not dispatch active-movie pause/resume. |
| Public pause | Owned main vtable `22DCE8+28` contains `15F3F0`; the native public-entry hook routes that operation to `Session::pause` for an active native source. Direct generated-source references found by the audit belong to internal source startup/completion. | Native worker pause/resume tests remain relevant. The direct reference search does not prove there are no indirect game callers. Keep the public pause route; do not invent a retail input binding. |
| Engine suspension `o0:37AA40` | Loads the same vtable slot `28` at `37AA60`, calls it with pause `1` at `37AA64/68`, then runs the original audio/I/O suspension calls. The reviewed direct caller is HDD maintenance worker `1BD160`, at `1BD170`, after `SleepThread`. | There is a concrete indirect game pause caller. The mapping now explicitly labels the pause and support suspension sequence. The native hook covers it, but ordinary DVD gallery playback does not test the HDD-maintenance path. Preserve this distinction; direct-target search alone would miss it. |
| Error consumer `o0:37A5A0` | Status is read through vtable slot `20` (`160060`) and stored at game context `+80`. Status `4` branches at `37A674` to `37A790`, which calls `37A4E0`; EOF `3` takes a separate branch to `37A780`, which calls the same destroy routine. | Error is a required game-facing terminal condition. A standalone worker error test proves neither execution of this branch nor return to the caller's menu. |
| Native error publication | `native_host_movie/runtime_adapter.cpp::status()` returns `4` for native `State::error`. `Session::Impl::run` catches a source failure, retires player/standby/frame resources and keeps the control owner available for a later start. | A bounded actual game test should demonstrate original cleanup, menu progress, successful subsequent playback and joined shutdown. No fallback to the old decoder is required or appropriate. |
| Temporary renderer interface | Immutable native BGRA pictures are copied through `render_bridge.h` to the current game renderer. | This interface remains explicit until rendering migration. It is not a requirement to reproduce old media decode/transport workers. |

The audit compares 671 commented words and 69 omitted zero words in eight
complete original intervals to the owned main ELF and overlays. The public vtable and
selected branch/call words are checked directly. All discovered direct call
sites are also checked against owned ELF words. The reproducible command is:

```powershell
python tools/native_reconstruction/audit_media_control_callers.py --output build-native-sjuni/media-control-caller-audit-v3
```

The direct reference search covers generated main and overlay `.cpp` sources.
It recognizes original J/JAL comments targeting `15F3F0` and `37AA40`; it cannot exclude
dynamic vtable calls, runtime mutation, mods, another build, or File #2.
Different overlapping generated source bodies can contain the same original
call site, so source-file counts are not distinct runtime call-site counts.

The verified `37AA40` row in `SYMBOLS_MOVIE_FLOW.md` and its annotation now use
`pause_current_movie_and_suspend_support_services_candidate`. The confidence
remains `probable`: the pause dispatch is directly verified, while the broader
support-service role and runtime reachability remain bounded. Only this row's
name, confidence detail and rationale changed. Original file bytes and the
pre-refresh index are retained in
`build-native-sjuni/media-control-mapping-correction-baseline-v1`.
Refreshing all 17,069 annotations retained the static call graph and source
snapshot; the correction receipt checks their identity before and afterward.

For the remaining game error test, a one-shot private diagnostic fault can run
inside the session worker after a verified selected cue has published actual
frames. Throwing through the existing inner failure handler tests ownership
cleanup and native error publication. Record the unique test request, cue,
generation and frame; observe status `4`, the original destroy path, menu
recovery and a fresh successful playback. This tests an injected worker failure,
not a naturally reproduced decoder defect. Do not damage an owned asset/cache,
write a guest completion state, or treat an unrelated failure as expected.

Media retirement is now a bounded admission question. The
[retail effect descriptor audit](RETAIL_EFFECT_DESCRIPTOR_AUDIT.md) accounts for
all 265 matching owned room-script members: all 74 descriptors select animated
textures, none arms the numbered effect-movie path. That supports the named
five-scenario stock cohort, not global deletion of IPU support. The shared
`1CC260 -> 15E6A0` initializer has other delegated work and must not be replaced
wholesale with a no-op. Arbitrary SJ/raw-memory/file producers and nonzero
before-PCM callbacks remain explicit unsupported profiles; the actual finite
queued scene/gallery consumers have their native replacement and separate
admission tests. Final runtime/build dependency deletion belongs to Stage 6.

Step 3 still needs the coherent candidate's resource/room transition evidence,
actual queued consumer/retirement evidence, final movie control/error coverage,
and A/V synchronization evidence. Historical intermittent hitches remain
unconfirmed causes; clean retests must retain that limitation. Gameplay and
in-engine cutscene rendering migrate in Stages 4/5.
