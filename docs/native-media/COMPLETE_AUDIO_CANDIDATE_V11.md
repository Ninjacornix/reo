# Complete audio candidate V11: bounded live validation

Status: separate candidate built; native and original opening runs completed,
2026-11-06. Actual complete-backend installation, memory capability acquisition,
PCM/packet activity and normal joined teardown are now observed. General audio
equivalence, the unsupported read diagnostic and the user's intermittent
stutters remain unresolved. Stage3 remains in progress.

## Coherent build identity

The candidate uses root source revision
`13073276d2253b76b0e49689c3cddfce91d04b90`, the fully reapplied127-patch SDK,
and actual bundled UCRT LLVM21.1.8. The corrected preparer from `42791a7`
explicitly includes both native bank-library sources. The chosen older root
source revision keeps the game/header inputs identical to V10; later standalone
Source2, workspace and clock work is not silently added to this live candidate.

V10 passed154 authored/runtime checks and compiled2,379 units, then failed
linking because the preparer omitted `audio_banks/v2/algorithms.cpp`. It never
linked or launched. V11 is a fresh immutable kit and independent work/output
directory, adding that already committed source. Every existing header is
byte-identical to V10. Verified object/receipt pairs were copied and their
ordinary source/header/option/compiler signatures rechecked: **2,380 units,
2,379 reused**, successful full link,169.531 seconds. A precompiled PS2 runtime
archive was not imported. The new algorithm object is compiled with the same
strict FP and coherent capture2 flags.

| Input / result | SHA-256 |
| --- | --- |
| Owned File1 ELF | `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46` |
| Reapplied SDK receipt | `909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a` |
| Preparer | `d1846e946b28642e4d45b5bc2fcfe000a2c91b92314d2a1736e76bc9fa55cd4b` |
| V11 kit manifest | `3f6308c2f6cd59cc5daca4d3dd5261e3b6caadb2b356910f059bb74e80d6b2f4` |
| Compiler driver | `f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3` |
| Linked executable | `622559322384b8561789e8dbf9123e4203a8c42108a5426cc762e6c46375777d` |

The build driver reverified all5,601 compiler/sysroot receipt entries. Private
build receipts and logs are under `build-native-sjuni/candidate-work-v11`;
the kit is `candidate-inputs-v11`, output `candidate-game-v11`. V10's failed
link remains in `candidate-work-v10/compile-logs/link.log` and its result JSON.
Seven planner tests include a source-closure check against the standalone bank
CMake target, alongside the generated/runtime capture-definition checks.

## Controlled route and its limits

The private plan/configs are `build-native-sjuni/audio-comparison-v11`.
Native ran first, then original, using the same executable/hash and imported
PAK data, fresh private memory cards, character route, two ordinary Cross
confirmations and no movie skip. Both drivers began about71 seconds after
supervisor startup. Native audio was selected by exact `REO_NATIVE_AUDIO=1`;
the comparison set0. Standalone native PCM and native movie-position selection
were0 in both; resource/SJUNI/scalar/mono/stereo adapters and existing rendering
configuration matched. Dumps, screenshots and per-bank path logging were off.

Both observed the cinematic and unpaused gameplay, then moved the local actor
and opened/closed the menu. Actor0 moved from approximately
`(8396,0,13156)` to `(8330.639648,0,13211.557617)` in both runs. Menu observations
return to phase2/modal0/paused0. These checks do not prove audible pause behavior,
waveform equivalence or identical NPC state.

The native supervisor also records one transient permission-denied read of its
private `input.json` during the walk check. The actor/control observations still
complete, with the same observed local movement as the comparison. This harness
error is retained separately from the game's zero fatal-log finding; the run is
not labeled free of all test-harness errors.

| Session under `build-native-sjuni/playtests` | Elapsed seconds | Result |
| --- | ---: | --- |
| `audio-native-v11` | 404.125 | Actual complete installation, gameplay/control observations, WM_CLOSE, exit0; no fatal log finding. |
| `audio-legacy-v11` | 442.265 | Original audio selection, gameplay/control observations, WM_CLOSE, exit0; no fatal log finding. |

The longer original run includes more post-movie gameplay idle time. There is
one run per selection, with uncontrolled cache/driver/host variance; no repeated
performance acceptance or controlled fix/retest claim is made. The image/memory
observations use the exact private PID, creation time and executable identity.
Both game processes exited before offline analysis. Player saves/builds were
not used as the test output.

## Actual native installation and retirement

The native log confirms complete PCM/bank/RAM installation with391,680,000 PCM
bytes. This executes the real pre-run factory and RuntimeMemory acquisition,
rather than the isolated fake acquisition contexts. Its final output report is:

| Native output counter | Value |
| --- | ---: |
| Owner joined / output started | 1 /1 |
| Output frames | 18,355,680 |
| Signal frames | 16,355,570 |
| Underrun frames | 0 |
| Hard failures / queue rejections | 0 /0 |

The memory owner retires with **zero active slots and operations**. Its actual
operation counts are preserved below; counts are attempts, with refusals
separate. They are not claims that every possible operation was exercised.

| Operation | Attempts | Refused |
| --- | ---: | ---: |
| Begin /end | 190 /190 | 0 /0 |
| Read | 968 | 0 |
| Control | 439 | 0 |
| Forward | 0 | 0 |
| Packet snapshot | 166 | 0 |
| Optional owned-packet log | 166 | 166 |
| Packet capture | 166 | 0 |
| Direct bank capture | 0 | 0 |
| PCM capture | 12,187 | 0 |
| Retirement | 1 | 0 |

The SDK outer drain, child/device fence and Memory retirement all reach their
reported normal completion. This is bounded real-path evidence for that order;
it does not close unexercised forward/direct-bank, every shutdown race or all
bank producer lifetimes.

**Diagnostic gap remains:** the report contains167 diagnostics and first word
65540. In the actual frozen schema this first report decodes to stage`read`,
status`unsupported`; operation-failure words occupy a smaller numeric range.
It is not the optional log stage. All166 optional logging calls are expected
to refuse because that logger is absent, but they do not explain away the first
read diagnostic. The SDK can reject an uncovered RPC or unsupported metadata
before invoking Memory.read; zero provider read refusals does not clear that
path. The aggregate report lacks the RPC/request identity, so the exact call
and its consequences remain unknown. No unsupported request is silently retried
through a legacy backend. Further bounded diagnostic identity evidence is needed
before declaring the complete request domain supported.

## Measured timing and audio observations

The original backend's433 report windows contain20,853,600 output frames,
18,853,970 signal frames and16,320 underrun frames. The native final report
contains zero underruns. Native final totals lack per-window timestamps; they
cannot be aligned to an individual movie gap. Run durations/output-start times
and report coverage differ, so these totals are not a rate or speed comparison.

| CPU presentation-return intervals | Count | p99 ms | Maximum ms | Above50ms |
| --- | ---: | ---: | ---: | ---: |
| Native, whole observed run | 22,980 | 21.3056 | 114.2532 | 2 |
| Original, whole observed run | 26,082 | 21.9990 | 677.7755 | 3 |
| Native, approximate sampled movie windows | 18,584 | 21.3950 | 42.5331 | 0 |
| Original, approximate sampled movie windows | 19,396 | 22.1026 | 677.7755 | 1 |

Frame captures have22,984 native and26,084 original rows, zero telemetry drops.
These are CPU return intervals, not screen scanout or original game updates.
Movie windows use sampled log context without decoder-generation identity.
One original678ms symptom and the absence of a native50ms movie interval in this
pair do not establish a stutter cause/fix. The user's report that an earlier run
felt smooth remains consistent with an intermittent symptom.

The sparse movie-work export saw19,415 native slow events, retained4,157 unique
and omitted15,258; original saw20,211, retained4,158 and omitted16,053. Exports
are after join, not live complete traces. A native74.7951ms interval overlaps
61.0114ms of retained owner-control elapsed time; an original62.9249ms interval
overlaps46.9463ms. The longest original677.7755ms interval has no retained event
overlap. Missing events/descheduling prevent a causal conclusion. Nested elapsed
events are not added as separate CPU work.

## Analysis and next work

[`analyze_audio_candidate.py`](../../tools/native_reconstruction/analyze_audio_candidate.py)
records installation, output and RAM reports separately from saved settings,
keeps all diagnostics/refusals and requires exact schema/launch consistency.
Six synthetic tests cover missing/duplicate proof, incomplete retirement,
counter/schema errors, conflicting selections and retained faults. Each session
contains `audio-candidate-analysis.json`, `movie-pacing-analysis.json/.md` and
`movie-work-analysis.json/.md`, alongside raw logs, frame/work CSVs, actor/control
and owned close/exit receipts. The analysis manifest records their hashes.

Remaining work includes identifying the unsupported request, broader rooms and
bank domains, shared Source2/Window2 composition, playback/estimated-clock and
RNA/DTR credit ownership, LSC and movie controls. The new standalone components
are not yet live player replacements. No default enable, compatibility-runtime
removal, full stage3 completion or accepted speedup follows this opening pair.
