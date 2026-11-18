# V37: controlled game test of independent native audio service

Status, 2026-11-09: the same executable reproduces audio starvation with its
native service worker disabled, then avoids that starvation with the worker
enabled while the actual guest service call is deliberately withheld for two
seconds. This establishes a causal fix for the producer's dependency on guest
servicing under this controlled condition. It does not prove every historical
stutter fixed or physical audio continuity.

The [qualification record](../../tools/native_reconstruction/native_audio_v37_controlled_game_qualification_v1.json)
binds both completed sessions to PID/creation identity, private executable,
sealed source/build/package, diagnostic events, native control traces,
read-only observations and the original game-clock analyzer. This analysis
launches no game, accesses no live process/window and modifies no prior evidence.

## Same build, explicit diagnostic switch

V37 runtime source is `c8928c05ab3276a8c0a666bff9508b60b686aa17`; executable SHA-256
is `0d1b9faa538d7a052a4b87fcee0e6c7ceecc614993445078904311850971ab51`.
The sealed build verifies 2,417 units, reusing 2,415. The supplied launcher revision
is `89abdece`, artifact cohort v8; its cross-test assembly hash is retained.

Both tests use the real launcher core, private game executable copy, verified
native media/resource profile, fresh private unlocked card, original menu route
to Outbreak and background manual-gameplay fixture. No Avalonia window is
constructed. Both finish normally with game exit 0, no forced cleanup, joined
audio/source/cue/movie owners, and no reported native hard failure.

The sealed diagnostic code permits the fault only with explicit background-test
and control-stall settings. It waits for room 1, gameplay phase 2 and an actually
playing native stream with at least 8,000 queued samples. It then sleeps for
2,000 ms **outside canonical native controller admission**, so the guest cannot
service its audio group while an independent worker remains free to do so.
One additional diagnostic flag disables the worker's tick/context admission for
the baseline. These flags are private test conditions, not normal player options.

| Observation | Worker disabled: `20261109-044822-736` | Worker enabled: `20261109-045249-009` |
| --- | --- | --- |
| Measured withheld interval | 2,000.2468 ms | 2,000.6558 ms |
| Guest audio tick, begin → end | 3,086 → 3,086 | 3,093 → 3,093 |
| Native output frames, begin → end | 2,453,280 → 2,549,280 | 2,456,640 → 2,552,640 |
| Output frames advanced | 96,000 | 96,000 |
| Native underruns, begin → end | 0 → **87,808** | 0 → **0** |
| Playing stream's queued samples, begin → end | 8,192 → 0 | 8,192 → 8,192 |
| Final native underrun count | **93,088** | **0** |
| Joined worker's actual service visits | 0 | 35,677 |
| Order deferrals | 0 | 0 |
| Game lifetime / game exit | 182.089 s / 0 | 182.102 s / 0 |
| Launcher diagnostic check | **Fails the nonzero-underrun requirement, as intended** | Passes |

The baseline's launcher check must remain failed. A normal process exit and
joined owners do not turn its measured audio loss into a passing audio test.
The candidate passes both retirement and the zero-underrun requirement.

## Native traces confirm starvation and catch-up

The baseline control CSV contains 20,937 stream rows representing 9,562 distinct
global observations. The candidate contains 19,107 rows / 9,001 observations.
Both retain zero drops, invalid rows or counter/time resets. Global output
counters appear on multiple stream rows; the analysis deduplicates observations
and never multiplies their underrun totals by the number of streams.

Baseline starvation is exact: **96,000 output frames − 8,192 initially
queued samples = 87,808 missing frames**. The first post-stall observation records
native slot 1/generation 1 playing, not draining, with an empty stereo queue and
87,808 late samples. This is a playing-source shortage, not finite EOF handling.

After guest servicing resumes, eleven further counter increases of 480 frames
add **5,280** catch-up underrun frames. At QPC 291,159.1990401 s, approximately
114.175 ms after the injected interval ends, that source is still playing with
8,192 queued samples, zero remaining late samples and **93,088 skipped samples**.
Those measured skips preserve the mixer’s existing catch-up accounting; they
are not erased or relabeled by the candidate.

In the enabled case, the first post-stall observation retains the same native
slot/generation, playing state, full 8,192-sample stereo queue and zero late or
skipped samples. Copied samples reach **104,192 = 8,192 + 96,000**, while decoded
samples reach 112,384 and the encoded ring contains 63,488 bytes. Native decode,
source polling and PCM refill progressed while the guest audio tick stayed
unchanged. Its final trace and native retirement counters both remain zero.

The other retained native source, slot 0/generation 3, is not playing at these
observations and retains its 8,192-sample queue. Its presence does not multiply
the aggregate loss or supply an EOF explanation for the playing source.

## Matching source and clock semantics

During each controlled interval, at least two independent read-only observations
retain the same original slot-1 request: ordinary file mode, two channels,
backend argument 0, root-relative start sector **10,413**, sector count **2,546**,
and service divisor **30**. Native source snapshots in both runs retain 48 kHz,
volume 256, gain 1 and a 65,536-byte encoded capacity.

Across the four inventoried root containers, the verified owned inventory
contains exactly one matching extent: `NETBIO01.DAT/0/10`,
`adxsnd.afs/s010100a.adx`, 5,212,998 file
bytes and 4,633,715 samples/channel. Its SHA-256 is
`b4c1d88e1b01d3d8e1410c93995940daa649055d48f7952c7bbde9420993ad81`.
This identity comes from the exact root-relative extent and header metadata;
the canonical filename was not separately traced at native start. The imported
view is sector bounded, so its extent includes archive padding beyond file bytes.

The original game-clock analysis preserves its per-actor deduplication, clock
quantum, room/mode and eligibility semantics. Each run has the same retained
eligible room-1 epoch: 5,460 actor observations representing **2,099 ordinary
updates**, step 2, 69.9667 game seconds. Their host durations are 72.1464 and
72.2082 seconds, including the deliberate two-second guest stop. These ratios
are not normal-speed benchmark results. The worker supplies no synthetic game
tick and the test does not accelerate game logic to hide a shortage.

The game-clock recorder's configured 300-second window is unfinished at the
normal 180-second close (`closed=0`), with zero dropped, invalid or unpublished
records in the retained period. The background observer records 164 baseline
and 155 candidate samples; all observed game windows remain minimized and none
is foreground. These one-Hz observations are not continuous focus history or
physical presentation evidence.

## What this confirms and leaves open

The [isolated regression](NATIVE_AUDIO_INDEPENDENT_SERVICE.md) established the
same mechanism with real owned audio and exact PCM preservation. This paired
game test now confirms its production integration: native source/cue work runs
under the canonical owner without guest RAM reads, continues through withheld
guest group service, and joins on normal shutdown. The worker-disabled run
reproduces the predicted loss on the very same executable.

The injected stall deliberately holds guest progress. The worker preserves audio
production through it; it does not remove that guest/visual stall. In particular,
this pair does not prove a fix for the original 548 ms resource read, the separate
1.4-second ownership delay, every loading stall or historical movie hitch.

Parallel compiler and I/O regression workloads deliberately load the machine,
so this is not an isolated performance microbenchmark. No physical endpoint
recording, display capture or subjective A/V judgment is included. Those limits
remain separate from the measured, controlled fix for native producer starvation.
Other Step 3 acceptance and normal-play retests remain separate gates.
