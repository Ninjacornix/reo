# Native media candidate validation

Status: in progress, 2026-11-05. Independent decoder/service/PCM comparisons are
recorded in their respective module documents. This record separates linked
availability, executed native calls and observed playback. No whole-media
migration, waveform equivalence or speedup is established.

## Sealed builds

V4 source `1d57c00fb2b9b1e798c94d0f68a82e1fdf20e678`, manifest
`4de90bbfd860e4a9982e9ce6072e19107935c780a432b1483d526d14234ba20c`,
passed its 138-unit authored/runtime preflight. Its full build was interrupted
without a completion receipt; the original log is retained. Resume reused
verified ordinary objects, rebuilt archives and linked all 2,363 units, with
753 reused. Executable SHA-256:
`f9b7af0b05b3dbbad7ee557087ab19a42663efaa4afc14d4ed706436a4674492`.
No private runtime archive was substituted for this coherent source build.

V5 source `6a095697abac1ce32df548d1671de7187d6c1057`, manifest
`7f35cce0958df29167ee1f7b0d84ad197ebf4ec2ec738921824e0d4865c8c324`,
adds the default-off stereo/downmix adapter. Its 140-unit preflight and
2,365-unit full build passed (140 verified objects reused). Executable SHA-256:
`492a4315a3e3637db770adc87314b5f5ce1a08afa048920dbf98b302fb933f91`.
Neither build includes the later standalone
PCM owner or predictor-service extension. Those cores remain independent work.

These builds use the exact owned File #1 ELF, verified bundled LLVM/MinGW, reconstructed
121-patch dependency source and pinned audio provider described in the
[resource validation record](../native-resources/CANDIDATE_VALIDATION.md).

## Controlled V4 sessions

Private images/cards/logs are under `build-native-sjuni/playtests`. Player builds
and saves are separate. PAK mode uses an intentionally unavailable ISO path;
native resource/scalar/SJUNI/CD owner replacements are disabled in these audio
tests. Native keyed mono is requested with its separate post-commit trace enabled.

| Session | Measured evidence and limitation |
| --- | --- |
| `adx-mono-pcm-v4` | 591.406 seconds, ordinary owned window close, exit 0. Mono installation recorded, **zero executed native mono proofs**. The observer could not confirm character selection; renderer capture shows that menu. Movie activity in the background does not establish the scenario opening. Audio counters: 21,490,718 signal / 2,240 underrun frames. Extremely verbose movie diagnostics and repeated whole-log reads affected the test harness; this is not performance evidence. |
| `adx-mono-pcm-v4b` | 129.078 seconds, ordinary owned close, exit 0. Mono installation, zero native mono proofs; no confirmed cinematic/gameplay route. Signal 4,172,158, underrun 0. Bounded observer stopped after menu confirmation retries; background controller admission was absent. |
| `adx-mono-pcm-v4c` | 432.437 seconds, background private-controller admission, bounded state observation and verbose per-poll movie logging omitted. Two ordinary Cross confirmations, no cinematic skip; stable gameplay observed after 346.125 observer seconds. Renderer capture shows the playable bar. Actor position changes from `(8396,13156)` to `(8337.844,13205.433)` after ordinary Up. Owned close exits 0. Two post-commit native mono calls decode 5 and 15 blocks (640 PCM samples); stereo remains original in V4. Signal 18,290,162 / underrun 115,904 frames. This establishes bounded native mono execution and progress, not waveform/timing equivalence. |

The helper now latches the verified character idle state instead of reading the
entire growing movie log on every poll. The harness supplies the existing
`REO_COOP_TEST_INPUT=1` gate, which admits only its private controller mapping in
the background; it does not enable global keyboard capture. An isolated fake
process/state test reaches cinematic/gameplay without any diagnostics log.
Report analyzers now stream verbose logs and hash them incrementally.

The completed sessions' `adx-analysis.json` records log/source/process identities.
Installation remains availability only. PCM artifacts are bounded producer queue
prefixes, with possible raw-channel reuse/overwrite; a matching name alone does
not identify an asset or speaker output. The byte comparator reports exact
differences without converting them into a playback-quality verdict.

## Observed admission gap

An owned read-only pool sample during V4 recorded stereo requests of 2, 210 and
300 blocks. The original 1..16 adapter admission therefore excludes most of those
sampled windows. `adx-predictor-snapshots.json` retains the executable/process
identity and 30 bounded pool copies. Copies are not atomic decoder-call arguments
or completed native execution proof.

The [large original-word corpus](ADX_LARGE_BLOCK_ORACLE.md) independently
executes counts through 513 and long marker prefixes before any proposed 512
bound is admitted. Expanded adapter frame/range/refusal checks and a newly
sealed coherent linked candidate remain necessary for live wider admission.
Host checks now pass both compilers: 18 admitted large original cases, three
513-block original-once refusals and 20 expanded range/alias refusals. The
production delta changes only both count caps and their installation messages;
decoder arithmetic and source-header cohorts are unchanged. A private V6
validation revision was sealed from V5 plus those two production CPP files.
Keep original selection,
game speed and unsupported-call fallback unchanged.

## V6 wider ADX admission and movie-stutter investigation

V6 private validation revision `f64a013e4a7177827e8a96b38d0505e55592aa7d`
adds the two 512-block adapter CPP changes to V5. Manifest SHA-256:
`5457ead9e2fbbc1faa6438a49dead4c20155db3b653756e51c7f39100ff2d504`.
The 140-unit preflight and 2,365-unit full build passed; the latter reused the
140 verified preflight objects. Executable SHA-256:
`751745ca084bf7c80389de8bb6ac021d8304211736be72ff22754be9ad774a9a`.
The compile plan and SDK headers match V5. Interrupted generation left two
additional headers in V5's project, explaining conservative cache misses; they
were neither excluded from hashing nor copied into V6 to fabricate cache hits.
Future staging is outside compiler input roots. V6 remains immutable.

`adx-original-pcm-v6` is the same-binary original-decoder baseline: native
resource/CD/SJUNI/scalar and both ADX replacements disabled. Two normal Cross
confirmations, no skip inputs; stable gameplay observed at 349.157 observer
seconds. Ordinary owned window close exits 0. No native ADX execution is expected
or claimed. The user reported occasional movie stutter during this run. The
approximate observation, owned process/build identity, screenshot and frozen log
tail are retained in `manual-incidents/movie-stutter-1.json` and its companion
tail under that session. A single capture does not time or demonstrate a hitch.

This run used `REO_GPU_SHOT_EVERY_SECONDS=5`. The diagnostic path reacquires and
presents the shared target, waits for GPU copy completion, maps the image and
synchronously writes a BMP on the graphics owner. It can affect timing and is a
confound, not a confirmed explanation of the user's symptom. The repeat
`adx-original-pacing-v6` disables these screenshots and enables the existing
bounded, in-memory frame timing trace; records export after graphics teardown.
Both the screenshot-free baseline and matching native-on repeat have now
completed. No game speed or rendering-path change was made for these tests.

The offline `tools/native_reconstruction/analyze_movie_pacing.py` reports CPU
presentation-return intervals, capture-stage durations, record loss and exact
CSV/log references. Approximate movie windows require adjacent advancing clock
samples within two seconds; numeric resets and missing windows are unclassified.
These logs omit decoder/generation identity, so monotonic generation changes
cannot be excluded. The scanout marker is a backend-vsync return timestamp,
and the following span includes presenter preparation. Its
four focused tests cover a brief 80 ms hitch hidden among otherwise short
intervals, missing presentation stages, clock resets/gaps and corrupt timings.
These observations cannot establish actual display scanout, original game-update
rate, decoder latency or a root cause. No movie-stutter fix is proven yet.

### Completed screenshot-free pair

Both runs used the same V6 executable, fresh private cards, character route,
two ordinary Cross confirmations and no cinematic skips. Only the two ADX
native switches differ, apart from the private timing output path and session
identities. Other native subsystem switches remain off. Each reached stable
gameplay and exited 0 after an ordinary owned window close.

| Observation | `adx-original-pacing-v6` | `adx-native-pacing-v6` |
| --- | ---: | ---: |
| Run seconds | 371.484 | 369.531 |
| Stable gameplay, observer seconds | 346.625 | 340.750 |
| Frame rows / dropped | 21,362 / 0 | 21,985 / 0 |
| Approximate movie presentation intervals | 17,748 | 17,751 |
| Movie CPU return interval p99 | 35.7173 ms | 19.1154 ms |
| Movie intervals above 50 ms | 22 | 2 |
| Maximum sampled movie interval | 240.602 ms | 188.602 ms |
| Maximum interval across whole run | 271.2678 ms | 1,343.8642 ms |
| Audio underrun frames reported | 0 | 0 |
| Post-commit native decoder call lower bounds | 0 | mono 32; stereo 4,096 |

This pair shows a useful reduction in sampled movie presentation gaps, **not a
controlled causal proof or complete stutter fix**. OS asset-cache state, run
order and timing-dependent request boundaries were not independently controlled.
Both native decoders changed together. Remaining native movie gaps of 188.602
and 154.437 ms occur chiefly between neighboring backend frame spans. The
1.344-second whole-run gap is outside the approximate movie classification;
it remains recorded and unresolved rather than being discarded as irrelevant.
No GPU/display timing or unique-picture identity was captured.

The byte comparator found three identical same-name PCM artifacts: two 768,000
byte stereo planes and one 128,128 byte mono file. The other two 768,000 byte
files agree through byte 491,519 and then differ. Logs show that the same raw
voice/channel IDs restart at different accumulated byte positions: original
`startByte=622592`, native `startByte=491520`. Comparing the available 145,408
bytes from those respective restart offsets yields **exact equality in both
planes** (`pcm-restart-prefix-comparison.json`). This supports a changed dump
layout at the observed restart, not an observed arithmetic defect there. The
offsets come from playback-watermark logs, not independently asset-qualified
queue events; do not promote this to complete waveform or asset equivalence.

Full per-session reports and hashes are in `adx-analysis.json`,
`movie-pacing-analysis.json/.md`, `pcm-comparison.json` and the bounded restart
comparison beneath the private sessions. The
[movie investigation](MOVIE_STUTTER_INVESTIGATION.md) separates measured
symptoms from source-defined candidates and the missing timing boundaries.

### Combined resource/decoder integration

`media-native-pacing-v6` enables native synchronous resource reads, the SJUNI
setting, quiescent DVCI scalar setting and both ADX decoders together, with CD
async/worker still off. Same immutable V6 executable, PAK input, fresh private
cards, character confirmations and no skips; periodic GPU captures absent.
It reaches gameplay at 355.750 observer seconds and exits 0 after an ordinary
owned close (417.609 run seconds). Setup includes verifying the imported source
files and is slower than the decoder-only runs.

Actual execution lower bounds are 1,024 successful native payload reads, 64 mono
and 8,192 stereo calls. No native payload failure is logged. SJUNI and scalar
settings/installation do not supply executed-body proof in this session, whose
corresponding traces are absent. Audio reports total 19,084,800 output frames
and zero underruns. The 17,759 approximately classified movie presentation
intervals have p99 19.0278 ms, maximum 32.6193 ms and zero intervals above 50 ms.
This is bounded integration evidence, not proof of universally smooth playback,
unique-picture progress, subjective audio quality or which replacement improved
timing. Background development checks and asset-cache/run order remain
uncontrolled. Existing counters can miss repeated images and unsampled states.
The player subsequently reported that they did not notice the earlier stutters
in the last run. Its private `movie-smoother-user-observation.json` preserves
that subjective observation alongside the owned process/build identity; it does
not assign an exact timestamp or prove every playback state is covered.

The next coherent candidate adds the reviewed provider close-order fix and
bounded [movie-owner timing](../../tools/native_reconstruction/movie_timing/README.md).
The offline [work analyzer](../../tools/native_reconstruction/movie_timing/ANALYZER_README.md)
preserves partial exports and correlates measured wait/control spans with frame
gaps; it does not add nested durations into a causal diagnosis. The V6 executable
contains neither of these additions.

### Complete PCM backend V7

Private V7 freezes source `f4ec2248c9652834c4e6e76dd6be331993d5a6ad`,
kit manifest `736a17112a98725e8c768d823157028c6183e0a8817e1720b7fd56ca1803511f`
and executable `007ae82ac9538b40b27d229db6cec2e83e1ec21ced292dc915be144c0be2fa18`.
All 124 public dependency patches were reapplied to the pinned base before
building matching runtime libraries, game objects and backend. Preflight passes
145 units in 271.031 seconds; the full 2,370-unit build reuses those 145 matching
objects and passes in 866.344 seconds. The build receipt records no precompiled
PS2 runtime reuse. Native PCM stays opt-in; the player build is unchanged.

Both runs enable native synchronous PAK reads, SJUNI, DVCI scalar and ADX
decoders. CD async/worker remain off. Only `REO_NATIVE_PCM` differs, apart from
private identities/output paths. Fresh cards, two ordinary Cross confirmations,
no cinematic skips, no periodic GPU screenshots. The V7 binary includes the
reviewed provider device/mutex close ordering fix and bounded schema-1
movie-owner timings; it does not include the later movie-position adapter.

| Observation | `media-legacy-pcm-v7` | `media-native-pcm-v7` |
| --- | ---: | ---: |
| Run seconds / exit | 454.922 / 0 | 363.546 / 0 |
| Gameplay observed, observer seconds | 361.875 | 345.781 |
| Approximate movie return intervals | 18,348 | 17,749 |
| Movie interval p99 | 17.6363 ms | 17.9097 ms |
| Movie intervals above 50 ms | 0 | 4 |
| Maximum sampled movie interval | 34.2693 ms | 1,098.2157 ms |
| Output frames reported | 20,723,040 | 16,990,560 |
| Frames with signal reported | 18,735,858 | 14,962,642 |
| Starved output frames reported | 0 | 40,256 |

The original backend supplies 431 periodic CRI windows. The native backend
supplies its own final counters: absent legacy starvation windows are **not**
zero native starvation. Native selection is proved by the installation at stderr
line 259 and final joined report at line 8,284: 2,040 channel slots, 2,041 voices,
391,680,000 PCM bytes and 4 MiB metadata. All 35,397 device callbacks complete;
output starts and its stream fence joins. Hard failures and queue rejections are
zero. Successful method counts are ensure 100, queue 11,188, configure 271,785,
consumed 539,397, render 35,397, drain 5, queued-samples 8, reset 1 and shutdown 1.
Discard and release have no executed-body coverage in this run. Successful
callbacks and nonzero signal do not establish speaker waveform equivalence.

The native run observes normal gameplay, a one-second Up input and changed local
actor coordinates, then Start changes modal state 0 to 1 and Circle restores 0.
It returns to unpaused gameplay and closes normally through its owned window.
The original-run controls check occurred later, found phase 4 rather than its
required unpaused phase 2, and sent no input. Thus this is not a matched controls,
pause, death, restart or repeated-load comparison; menu modal state alone does
not establish movie/audio pause semantics.

The four native movie gaps are 1,098.2157, 422.8647, 297.5084 and 54.6346 ms.
The three largest chiefly occur between neighboring graphics capture spans
(CSV lines 12,370–12,371, 12,445–12,446 and 18,971–18,972). No retained movie-work
event overlaps those three. Schema 1 retained only its first 4,096 slow events;
14,369 later native events and 15,194 original events were dropped. Aggregate
counts remain available, but missing details prevent attributing those gaps.
The 54.6346 ms gap overlaps a 52.1549 ms owner-control span containing a
46.7995 ms batch-fence wait; nested elapsed observations are not added or
assigned causal responsibility. No per-window native starvation timestamps
were recorded, so audio starvation cannot be aligned with these gaps.

The native run's worse tail and starvation are unresolved and block accepting
this backend as the default. These unequal-duration, single-order tests also
have uncontrolled asset-cache, OS scheduling and concurrent development work;
they do not prove native PCM caused the difference. Preserve both failures and
clean lifecycle evidence. Bank/RPC producers still bypass the PCM facade and
retain legacy global ownership. Reports are in each session's
`pcm-analysis.json`, `movie-pacing-analysis.json/.md`,
`movie-work-analysis.json/.md` and `controls-observation.json` beneath
`build-native-sjuni/playtests/`.
