# V38 ordinary room transition and native resource acceptance

Completed session `20261109-065827-488` reaches **Outbreak scenario room 4 from
room 1 through ordinary door input**, returns to ready gameplay and accepts
ordinary movement in the destination. The 300-second case then closes normally
with **zero native audio underruns**, joined owners and exit 0. This is one
actual route acceptance case; aggregate Step 3 closure is recorded separately.

The [qualification](../../tools/native_reconstruction/native_media_v38_room_transition_qualification.json)
binds the final runner/check, completed v16 driver, independent passive observer,
audio trace, native reports, static door evidence and matching V38 sources.
The offline analysis launches no game/build, accesses no live process/window and
modifies no earlier capture. Private analysis is retained under
`build-native-sjuni/v38-room-transition-analysis-v1`.

The V38 executable SHA256 is
`1f6853aad57b6125d6ed3f20d5ed0ddd853fc67fb5a1330da7e8da5b5aa597a5`,
from source revision `ad93542da65d327af65422031ee1c4f3d58d35b7`.
Launch and observer identity agree on PID 334112, creation FILETIME
134386775151610598 and the launcher's private executable copy. The final runner
reports `bounded case passed expected media outcomes`; its launcher and observer
exit 0. The launcher check records 301.6093777 seconds, duration completed,
no native/media error, no forced cleanup and no constructed launcher UI window.

The driver uses the private session controller file, normal stick input and
press/release Cross. It requests no focus, sends no global keyboard input and
writes no guest memory. Waypoints `(8950,12800)` and `(9200,12800)`, measured
facing and the projected interaction probe establish the approach. No game code
was changed to make a failed route pass.

The owned static RDT evidence identifies door 2 at offset `0x63108` of
`r0010100.rdt`, destination room 4/door 0, with XZ bounds
`9270..9310` by `12900..13000`. Immediately before Cross, the actor is at
`(9250,12922.4609375)`, height 20, yaw 17602. The projected query
`(9295.686722849268,12917.101520060192)` lies strictly inside those XZ bounds.
The actual game transition supplies admission evidence; actor height alone does
not establish the original vertical-query calculation.

Driver observations measure:

- Ready room 1 at 69.312 seconds.
- Ordinary Cross at 81.890 seconds, first destination room 4/loading phase 3
  observation at 85.031 seconds.
- Room 4 ready, phase 2 and request 0 at **86.453 seconds**.
- Destination stick `(0,23000)` produces **55.36417544 units** of displacement,
  observed at 89.469 seconds. The first two axis attempts produce no displacement
  while the ordinary arrival/turn state finishes; they are retained, not hidden.

The independent passive observer retains **285 samples**, including **198 ready
phase-2 room-4 samples with exactly one human slot**, spanning 212.219 seconds
between its first and last matching observations. All observed visible game
windows remain minimized and no owned-window observation is foreground. Its
receipt records no errors, guest writes, thread suspension, focus request or
desktop capture. These are sampled observations, not continuous focus history.

Native retirement reports **13,456,800 output frames / 11,126,951 signal frames**,
zero underruns, hard failures, queue rejections and submix failures; 28,035
submix calls complete. The independent native worker joins after **66,917 visits**
and one order deferral. A deferral preserves required native order admission;
it is not an audio failure. Source, audio, cue and movie owners join. This
ordinary-file case accepts no queued movie cues; movie reports retain six
sources, 697 delivered pictures and `error=none`.

The audio CSV has **16,840 deduplicated observations**, zero dropped snapshots,
invalid rows, time/counter resets or measured shortage windows. Its last output
counter is 13,455,840 frames with zero underruns; the final native report covers
960 additional frames and remains zero. Trace end is not substituted for final
retirement coverage.

Native resource routing reports the verified mounted import, 86 sources,
`mode=synchronous-exact`, an 8 MiB request limit and the expected immutable import
manifest. Successful native payload milestones reach **256**. The adapter logs
only successes 1–4 and powers of two, so the complete log bounds the lifetime
count to **256–511 successes**; it does not contain an exact final total or isolate
which requests belong specifically to the door transition. No native payload
failure or exception is logged. The original CD facade remains configured as
recorded by launch; this validates the admitted native resource path rather than
claiming all PS2 CD/runtime interfaces were removed.

Earlier evidence is preserved with its actual scope. The 600-second
`20261109-063550-071` case is a successful no-door soak, not a completed route.
Drivers v12 in `20261109-064738-265` and v14 in `20261109-065221-230` did not
establish an admitted door transition. Their later v13/v15 probes encounter
WinError 299 on the old, ending session; both archived game cases still report
normal exit 0, no forced cleanup and zero underruns. The harness corrections
address waypoints, stick strength and actual facing/probe admission. Those
attempts are not presented as fixed game-code defects or successful transitions.

This case has no loopback/WGC recording or subjective synchronization judgment.
It validates one ordinary loaded-room transition, continued destination control,
native resource activity, audio production and retirement. Other routes and
physical endpoint continuity are outside this evidence.
