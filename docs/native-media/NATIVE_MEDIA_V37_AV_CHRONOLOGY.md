# V37 unexpected audio shortage: video and collector chronology

Completed background case `20261109-051101-488` has **107,328 unexpected native
audio underrun frames** despite joined owners and 95,612 reported native service
visits. The deliberate early movie-worker failure is separately identified;
it does not explain this later audio shortage. Step 3 remains open.

The source is sealed V37 revision `c8928c05ab3276a8c0a666bff9508b60b686aa17`,
executable SHA256
`0d1b9faa538d7a052a4b87fcee0e6c7ceecc614993445078904311850971ab51`.
No compiler/cohort load was deliberately scheduled during this acceptance case.
That does not establish an otherwise idle Windows host or isolate every
external scheduling, storage or graphics event.

## Unexpected shortage occurs during normal recovered playback

All 23,919 audio-control snapshots parse with zero drops, invalid rows or
counter/time resets. There are **134** positive underrun windows, totaling
107,328 frames. The analyzer's largest-window list retains only 32 entries;
this chronology derives the complete set from all adjacent valid snapshots.
The full region is QPC nanoseconds
`292677056549600..292679623174800`, spanning **2566.6252 ms**.

The first affected after-snapshot is audio CSV line 13193: slot 0/generation 3
is playing, queued PCM is zero, encoded input is 20 bytes, and decoded/copied
samples are both 8,363,072. This is an input-empty observation rather than a
full encoded buffer. Source-request completion details have separate
investigation evidence; neither aggregate worker visits nor this timing
correlation identifies an inner I/O/lock/scheduling cause.

The shortage falls **174.2583995..176.8250247 seconds** after the first picture
publication of the recovered full E3 playback, movie generation 6. All 6,144
generation-6 ordinals `0..6143` are retained; its final picture publishes
**28.1386586 seconds after** the shortage region ends. This is not normal movie
EOF or a queued transition to the next movie clip.

The intentional failure belongs to generation 4. Its ordinal-120 test log
occurs after that generation's last retained publication and before generation
5's first publication. This brackets it at
`292500632856800..292501327577200`; its log has no independent QPC field.
Even the later bracket endpoint precedes the audio shortage by **175.7289724
seconds**. Do not assign the uncommitted fault iteration a fabricated exact
timestamp or merge that earlier expected error with this later failure.

## Game/video continue while external collectors have a shorter gap

| Observation overlapping the shortage region | Measurement |
| --- | --- |
| Native movie publications | 77 fresh pictures; maximum overlapping interval **38.1350 ms** |
| Game movie-consumer requests | 77 requests, all fresh; maximum overlapping interval **34.3279 ms** |
| Game presentation-loop starts | Maximum overlapping interval **17.6039 ms**, trace `dropped=0` |
| Window-only capture | 47 retained frames inside the region; a **450.3657 ms** frame-timestamp interval overlaps its beginning |
| Process-only loopback capture | A **440.0000 ms** packet-timestamp interval overlaps the beginning; reported flags remain zero |

The movie producer/consumer traces both report zero drops. Across the entire
full E3 generation, the maximum publication interval is 40.8889 ms and recorded
backpressure stays zero. Native decoding/publication, game frame acquisition
and presentation-loop observations do not show a matching multi-second freeze.
This distinguishes the incident from the earlier long movie-publication stall.

The two collector intervals are specifically:

| Collector | Before (QPC-equivalent ns) | After (QPC-equivalent ns) | Interval |
| --- | ---: | ---: | ---: |
| WGC `SystemRelativeTime`, indices 4230 → 4231 | 292676821893400 | 292677272259100 | 450.3657 ms |
| WGC observed QPC, same indices | 292676810701900 | 292677259005800 | 448.3039 ms |
| Loopback packet QPC | 292676768501500 | 292677208501500 | 440.0000 ms |

These are gaps between retained observations. They do not prove loss of a
physical display/audio endpoint, identify one shared Windows cause, or establish
that capture itself caused source starvation. The longer native source-request
waits begin before and extend after these shorter collector gaps. A shared
host event is a hypothesis, not a confirmed explanation for the entire shortage.

After the collector gap, all 47 captured central image regions are distinct.
The comparison uses only the owned window's retained 128×96 grayscale frames,
central coordinates `[16,112) × [24,72)`, excluding the title/frame borders.
This establishes changing pixels in that region, not a reference-picture
identity, final scanout or a physical synchronization judgment. No captured
sample in the interval is foreground or minimized.

The WGC frame `SystemRelativeTime` is sometimes ahead of the separately queried
observed QPC in this case. Preserve both raw fields; their difference must not
be presented as a measured physical transfer/display latency without a
separately established interpretation/calibration.

## Consequences for A/V analysis and attribution

Process loopback retains 242 packets/116,160 frames inside the shortage region,
with zero flags. Its packet timeline nevertheless contains the explicit
440 ms QPC jump. Therefore an analysis must use packet QPC and cumulative sample
mapping, splitting discontinuous time intervals as necessary; uniform
`sample_index / 48000 + capture_start` would hide the timestamp gap. The
capture's zero discontinuity/timestamp-error flags do not independently prove
continuous application sound or physical endpoint output.

The only logged slow native resource read is
`292490419261100..292490592434100`, about 186.5 seconds before the shortage.
It is not a temporally matching resource operation. Absence of another such log
does not rule out uninstrumented provider, file or OS work. Normal movie EOF,
the earlier injected movie failure, and a global game/video freeze are not
supported explanations for this interval.

The generic session correctly retains media error flags from the intentional
movie failure. The unexpected final audio counter is a separate failed gate:
all movie-control recovery checks and joined retirement cannot cancel it.
Native source completion needs a concrete candidate and controlled retest.
No root cause or fix, physical A/V synchronization, or Step 3 completion is
claimed here.

Evidence is `build-native-sjuni/native-media-v37-av-chronology-v1/analysis.json`,
the completed session, native traces, window-only frame timestamps/central
hashes, process-only packet timestamps, exact capture command/helper identities
and sealed V37 source/build inputs. This is read-only offline analysis: no
game, process attachment, input, window action, source edit or build ran.
