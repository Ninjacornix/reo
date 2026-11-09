# V36 audio shortage during item-icon resource loading

Step 3's audio resilience gate failed in completed session
`20261109-035604-197`. The game exits normally and native owners join, but
the output records **90,208 underrun frames**, equivalent to 1.879333 seconds
at 48 kHz. Normal exit and zero hard failures do not make this a clean audio
run. No fix is established by this investigation.

The existing audio-control analyzer parses all 27,550 snapshots with zero
drops, invalid rows or counter/time resets. Twelve observation windows account
for the entire final underrun count. Slots 0/generation 6 and 1/generation 2
are playing and affected together; their equal per-stream shortages must not
be added to double the aggregate output count. Slot 2/generation 18 remains
active but not playing and has no observed shortage.

## Measured timeline

| Audio trace lines / game ticks | Host interval (ms) | Output advance | New aggregate underrun frames |
| --- | ---: | ---: | ---: |
| 31185 → 31188 / 12934 → 12935 | 548.9063 | 26,400 | 18,208 |
| 31188 → 31191 / 12935 → 12936 | 1400.5004 | 67,200 | 67,200 |
| Remaining ten shortage windows during catch-up | Within the following 92.0868 ms | 4,800 | 4,800 |

The complete measured shortage region is QPC nanoseconds
`288179283391900..288181324887100`, spanning 2041.4952 ms. Output advances
98,400 frames; signal advances only the original 8,192 queued frames. The
first shortage is exactly `26400 - 8192 = 18208`. The native output callback
keeps running while controller/decoder service stops progressing normally.

Before the first gap, both affected voices have 8,192 PCM frames queued, or
170.667 ms at 48 kHz. Encoded input is already abundant: 62,480 and 62,028 bytes
in their 65,536-byte buffers. After the two long gaps, encoded input is still
62,368 and 61,916 bytes; decoded totals have advanced only 1,920 samples and
copied totals 9,600 samples per stream. Source observations are fresh at the
snapshot endpoints. This does not resemble an empty encoded-input buffer.

As service catches up, the late-sample debt becomes skipped PCM. At the final
shortage observation each affected voice reports 6,912 late plus 83,296 skipped
samples, totaling 90,208. More encoded prefetch would not repair this measured
failure to service the already buffered sources.

The final native output has 22,024,320 frames, zero hard failures, queue
rejections or submix failures, and joined source/output owners. The trace's last
observation is 22,023,840 frames with the same 90,208 underruns; the final owner
report covers the remaining 480 frames.

## Resource and game-progress evidence

`stderr.log:4579` records a synchronous native resource operation at
`288179283533100..288179831798400`, **548.2653 ms**, covering almost all of
the first service gap. It reads virtual LBA 17,543,824, 133 sectors, destination
`00BA23C0`, and succeeds with 272,384 bytes. The adjacent CRI-server diagnostic
attributes 548.373 ms to step 3 and 548.316 ms to three `SifCallRpc` calls.
This measures the resource-operation boundary; it does not isolate physical
disk latency from locks, provider work, memory copying or host scheduling.

The actual facade route starts `NETBIO00.DAT` at virtual LBA 17,440,187. The
request maps to byte offset 212,248,576, exactly the owned
`NETBIO00.DAT/0/516`, `romdata_usa.afs/itemicon.img`, plus sector padding.
The 271,616-byte member rehashes to
`1cc0786c41d16d94eeb72a9ab0d7625c35fa44def3069c895936c40eddbfde6f`;
the remaining 768 bytes are zero. The full padded read hashes to
`469e031cdd6b438f4005bce444ee95fc409981204a28178cc32a0c814149e912`.
The neighboring hot PC `o2:6D83C0` belongs to the mapped item-icon texture/CLUT
initialization body. This identifies the resource and a useful reproduction
interaction, not the precise cause of either long operation.

The first VBLANK ownership wait is 532.481 ms, last owner 6. The next is
1399.492 ms, last owner 5, matching the second long service gap. No inner
stack or per-operation measurement identifies that second 1.4-second cause.
Do not attribute it to the resource read merely because the events are adjacent.

Independent presentation telemetry has zero drops and a 1400.6559 ms start
gap at frame ticks 12966 → 12967. The actor clock journal has a **2024.5933 ms**
gap between rows 10446 and 10447: different actor callbacks retain the same
global clock 8950, room counter 4475 and service count 6208. Repeated actor
callbacks are not additional game updates. These records corroborate stalled
game progress while native output continues.

The actor journal is bounded: 16,384 retained records and 5,012 dropped. Its
normal analyzer accepts only eligible gameplay, deduplicates global updates
and splits invalid epochs. The incident's request field is 3, so it is excluded
from the analyzer's eligible gameplay speed ratio. The local same-clock gap
above is a direct field observation, not a claimed whole-session speed ratio
or an adjustment to those eligibility rules. The earlier eligible segment is
69.9667 game seconds over 70.0248 host seconds; that does not erase this later
stall.

## Native service boundary and candidate fix

The sealed V36 adapter handles original group entry `132C08` by calling
`Binding::service`. It imports guest clock/control state, calls native
`Instances::service`, mirrors guest status, then records its output snapshot.
The native control session services source completions, decoder, playback,
RNA and transfer work. Consequently, native file reading and device output
already have workers, but PCM replenishment still depends on that guest group
being serviced.

The smallest candidate improvement is an independently scheduled **native**
refill pump under the existing `adxt_control_owner::Owner::run` serialization.
It can call `Instances::service` with the last actual guest tick cached by a
valid group call. It must not call `Binding::service`, read guest RAM, import
guest clocks, adopt game handles, mirror fields or publish guest clock state.
Gate operation until a real guest tick/configuration has been admitted, and
join the pump before the canonical owner is retired.

Source-level constraints are explicit:

- `adxt_service_group::Group::service` has no per-tick rate gate. Native service
  can replenish bounded buffers repeatedly with the same cached tick.
- `Player::set_tick` stores that tick. Playback admission can set `tick_base`,
  while clock queries and pause/rebase controls use actual caller ticks. Never
  substitute elapsed host time or advance original game counters.
- The configured 30 Hz divisor sizes decoder request quanta in
  `StreamWindowOwner::ready_impl`; it is not a reason to throttle a native
  refill worker to guest progress. Keep the divisor and the 48 kHz device rate.
- Preserve pause, start inhibition, source identity, output ordering, pending
  metadata/header fences, finite/loop EOF, replacement and cancellation. A full
  native `Instances::service` can also admit pending replacements, so startup
  and control ordering require tests rather than assuming it only copies PCM.
- Immutable file pins and resource views must outlive all accepted reads.
  `PinnedFile` currently serializes seek/`ReadFile` with a per-file mutex;
  controller ownership must not be held waiting for a guest or completing a
  resource copy. Native input/output owners must retain their existing join
  fences.

This pump can protect audio from withheld guest service. It does not fix the
game's synchronous resource-loading stall. That boundary needs separate native
request/completion ownership or verified preparation of the item-icon resource;
releasing an unknown guest execution lock around a direct guest-memory write
is not a safe shortcut.

A meaningful controlled test holds **guest service** for two seconds after
ordinary native voices reach steady playback, while file and output workers
continue. Compare current and candidate behavior with the same data and output
cadence: baseline must demonstrate starvation, candidate must preserve PCM,
zero underruns, exact sample counts/digests, paused-peer behavior and unchanged
cached tick/divisor/time base. Repeat through source replacement and joined
shutdown, and test queued pending-header ownership separately. A separate
bounded ~550 ms resource-provider delay can test insulation from the measured
resource operation. Freezing all input I/O for two seconds exceeds the finite
64 KiB/PCM headroom and is a different guarantee.

After those tests, run an ordinary game retest including first inventory/icon
initialization. Do not close Step 3 or call the new pump a confirmed fix until
the candidate has actually passed its controlled and game tests. The V29
incident had regular controller service and different evidence; this V36
incident must not retroactively supply its missing root cause.

Evidence: `build-native-sjuni/native-media-v36-audio-incident-v1`, with complete
audio analysis, normal game-clock analysis and `incident-evidence.json`.
The new read-only correlation helper and qualification bind original log/trace,
import/member identities and sealed V36 sources. No game, process, input or
window access occurred in this investigation.
