# V38: controlled guest-service stall in the actual game

V38 preserves native audio production through a deliberately withheld guest
service call. Completed session `20261109-061633-454` finishes with **zero native
audio underrun frames**, joined owners and normal exit 0. This confirms the
independent-service behavior in the new resident-audio candidate. It does not
close Step 3 or establish physical audio continuity, cold movie/audio alignment,
or a fix for every historical stutter.

The [qualification](../../tools/native_reconstruction/native_audio_v38_controlled_game_qualification.json)
binds the completed runner/check, original stderr and native control CSV,
read-only background observations, analysis helper and sealed build/package.
This investigation reads completed files only; it runs no game/build, accesses
no live process or window, changes no prior capture and hashes no large assets.

## Candidate and controlled condition

The package records source revision
`ad93542da65d327af65422031ee1c4f3d58d35b7` and executable SHA256
`1f6853aad57b6125d6ed3f20d5ed0ddd853fc67fb5a1330da7e8da5b5aa597a5`.
The launch, archived running identity, observer and runner agree on that
executable. The observed process is PID 329096 with creation FILETIME
134386750102622045 and the launcher's private `reo_launcher_game.exe` path.
The six relevant implementation bodies match both the immutable V38 input kit
and actual `candidate-work-v38-retry1/project` sources.

The diagnostic is explicitly gated to the background test, room 1, gameplay
phase 2 and a playing stream with at least 8,000 queued samples. It withholds
guest progress for 2,000 ms **outside native controller admission**. Native
service remains enabled. It publishes an actual previously observed guest tick;
the independent worker does not invent a clock or read guest RAM to advance it.

The completed 180-second launcher case passes its native launch/retirement,
stall-handshake, source-worker, zero-underrun and background-window checks.
The check reports 181.5425513 seconds elapsed, no forced cleanup, no native/media
error and no constructed launcher UI window. It uses the existing unlocked-card
gameplay fixture, not a claim about normal player progression or a speed benchmark.

## Measured result and historical comparison

| Observation | V37 worker disabled | V37 worker enabled | V38 worker enabled |
| --- | ---: | ---: | ---: |
| Session | `20261109-044822-736` | `20261109-045249-009` | `20261109-061633-454` |
| Measured withheld interval | 2,000.2468 ms | 2,000.6558 ms | **2,001.0005 ms** |
| Guest tick, begin to end | 3,086 to 3,086 | 3,093 to 3,093 | **3,073 to 3,073** |
| Native output frames advanced | 96,000 | 96,000 | **96,480** |
| Native underruns, begin to end | 0 to 87,808 | 0 to 0 | **0 to 0** |
| Playing source's queued samples | 8,192 to 0 | 8,192 to 8,192 | **8,192 to 7,712** |
| Final native underruns | 93,088 | 0 | **0** |
| Joined native service-worker visits | 0 | 35,677 | **36,887** |

V38 stderr lines 3156 and 3162 bracket QPC nanoseconds
296455458036000 through 296457459036500. Native output advances from 2,441,760
to 2,538,240 frames while the guest tick stays fixed. Output counters are sampled
under native admission and printed with adjacent diagnostic timestamps; they are
not individual callback timestamps. Their 480-frame granularity must not be
converted into an exact physical wall-clock measurement.

The [V37 paired test](NATIVE_AUDIO_V37_CONTROLLED_GAME.md) disabled and enabled the
worker on the **same V37 executable**. Its predicted deficit was exactly
96,000 minus 8,192 = 87,808 frames, followed by 5,280 additional catch-up frames
to the final 93,088. V38 is a different executable with resident preparation and
refill changes. Its result preserves the established service fix; this is not a
new same-build worker-disabled V38 pair or evidence that residency itself caused
the improvement in this particular guest-stall case.

## Trace coverage and source state

The native control CSV retains **19,960 stream rows / 9,264 distinct global
observations**, schema 2, with zero dropped snapshots, invalid rows, time/counter
resets or shortage windows. Aggregate output counters are deduplicated across
stream rows. The largest observation gap is 2,016.1018 ms around the deliberately
withheld guest service; this gap does not mean the native worker stopped.

The nearest preceding CSV snapshot ends **15.0748 ms before** the diagnostic
begin. It is guest tick 3,072, and native slot 1/generation 1 has an initial
source request in flight, zero decoded/copied samples and is not playing. It is **not** the diagnostic's later,
primed 8,192-sample start observation. Subtracting those CSV source counters would
incorrectly include initial preparation in the purported stall-only work.

The first following CSV observation starts **0.0256 ms after** the diagnostic end,
at the unchanged diagnostic tick 3,073. Slot 1/generation 1 is playing, not draining,
at 48 kHz, volume 256/gain 1, with 7,712 samples in each channel, zero late/skipped
samples, 112,384 decoded samples and 104,192 copied samples. Its encoded ring holds
63,488 of 65,536 bytes with no request in flight. The other source, slot
0/generation 3, is not playing and retains its 8,192-sample queue; it is not a
second contribution to the aggregate underrun count.

The final retained snapshot has 7,394,880 output frames and zero underruns. Final
native reports separately cover **960 more output frames** and end at 7,395,840
frames, 5,157,191 signal frames, zero underruns, zero hard failures, zero queue
rejections and zero submix failures across 15,408 submix calls. Source/worker
reports are joined, with zero order deferrals. Cue owners join with zero accepted
requests in this ordinary-file scenario; it is not a queued-gallery acceptance
test. Movie owners also report joined, six sources, 698 delivered frames and
`error=none`. Normal shutdown's `PS2 Thread Exit` text is not a game crash; exit
and launcher retirement both report 0.

## Background observations and limits

The passive observer retains 158 samples over its 158.89-second lifetime and
790 owned-window records. All 158 visible-window observations are minimized;
none of the 790 window records is foreground. The receipt reports zero errors,
no focus request, no desktop read, no guest writes and no suspended threads.
Its implementation enumerates and reads window state; this is approximately
one-Hz sampled evidence, not continuous focus history. No WGC/loopback capture
or subjective A/V confirmation was requested in this controlled-stall route.

The first V38 build attempt remains retained separately: resource compilation
failed while renaming a temporary `game-icon.rc` preprocessing file with
`Permission denied`. The successful retry package and its exact executable are
the runtime evidence here; the earlier tool failure is not a runtime crash.

The intentional guest/visual stall remains visible to game progress. This check
establishes that native audio production survives that condition and retires
cleanly. It does not identify the physical cause of earlier resource/read waits,
prove uninterrupted speaker output or evaluate the ongoing cold-gallery,
decode-error recovery and room-soak tests. Step 3 remains open pending those gates.
