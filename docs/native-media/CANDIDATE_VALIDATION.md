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
adds the default-off stereo/downmix adapter. Its 140-unit preflight passed; the
2,365-unit full build is running. Neither build includes the later standalone
PCM owner or predictor-service extension. Those cores remain independent work.

Both use the exact owned File #1 ELF, verified bundled LLVM/MinGW, reconstructed
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
| `adx-mono-pcm-v4c` | Repeat in progress with background private-controller admission, bounded state observation and verbose per-poll movie logging omitted. The observer has confirmed the natural transition into cinematic phase; final playback/shutdown/native-call evidence is pending. |

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
sealed coherent linked candidate remain necessary. Keep original selection,
game speed and unsupported-call fallback unchanged.
