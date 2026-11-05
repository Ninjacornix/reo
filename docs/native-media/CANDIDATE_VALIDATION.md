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
It must complete before its results can be interpreted. The matching native-on
repeat is pending. No game speed or rendering-path change is made for these tests.

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
