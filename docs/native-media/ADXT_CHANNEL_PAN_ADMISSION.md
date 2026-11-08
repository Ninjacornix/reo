# Native ADXT mono startup admission

Step 3 remains open. The first actual ordinary-source selection reached its
native admission guard but did not reach the menus or prove source playback.
The startup refusal and clean worker retirement are separate observations.

V18 compiled all 2,411 units but did not link: the candidate recipe omitted
`game/native/afs_source_range/afs_source_range.cpp`, which supplies
`afs_source_range::prepare_open`. The isolated V19 revision
`9d9dd5f5c8ccf2f47516d2aaae2aeca522a8b973` adds that unit. Its 3,840 headers
and all existing sources match V18. All 2,411 previous objects pass the worker's
signature checks; only the missing unit compiles before the successful link.
The failed V18 inputs and log remain intact.

V19 executable SHA-256:
`917d3adf73786f7dca71612bda8195afa631251f131dacb0b1ddb412293b2a40`.
Its private session is `build-native-sjuni/playtests/adxt-ordinary-v19`, PID
225516, creation identity `134385865901231844`. The 22.859-second run exits zero
after the native admission guard stops startup. The selected backend reports
`native_sources=1`, joined source/output ownership, 480 private output frames,
zero signal frames, zero underruns and no hard failures or queue rejections.
These totals do not establish successful playback.

At stderr line 885 the adapter refuses `loop-pan-pitch-profile` for `20F550`.
The preserved original V17b capture independently shows the relevant values:

| Handle | Channels | Pan +42 | Pan +44 | Pitch +46 | Raw loop +6C |
| --- | --- | --- | --- | --- | --- |
| 20F3C8 | 2 | -128 | -128 | 0 | 1 |
| 20F48C | 2 | -128 | -128 | 0 | 1 |
| 20F550 | 1 | -128 | 0 | 0 | 1 |

The original constructor's `131844..131868` loop stores `-128` only for the
configured number of channels. A mono handle's second pan field is unused and
can retain old bytes. The adapter incorrectly required both fields to equal
`-128`; its fixture also initialized both, hiding this case.

The correction checks pan +44 only for two-channel handles. The fixture now
preserves the original mono shape, checks admission with zero, then poisons the
unused field with `4321` while continuing the real source/PCM workflow. Separate
negative cases still require refusal for an unsupported active mono pan and an
unsupported second stereo pan. Deliberately restoring the old mono check and
removing the active stereo check must be detected at runtime.

The test supervisor originally labeled V19's zero exit as having no fatal
diagnostic because its classifier did not recognize native ADXT admission
stops. The classifier now recognizes the explicit refusal/fatal markers, with
three tests covering refusal followed by clean retirement, post-selection
failure and healthy retirement. The original V19 run receipt is unchanged;
`native-adxt-refusal-analysis.json` retains the corrected failed-test finding.

V20 is an isolated correction over V19: only the controls-admission function
changes, and that function's source bytes match the current root implementation. Its
revision is `261a6a023e509afeb196944e03c468cb586461c4`. It retains the original
17-entry candidate header cohort; the separate discard entry remains outside
this candidate. Build, corrected startup and actual playback still require
their own results. This finding does not explain or fix the cinematic stutter.

Both compiler cohorts pass 18 declared-port adapter scenarios and detect six
runtime faults, including requiring the unused mono pan and ignoring the active
second stereo pan. All four real SDK130 adapter/handle/source/factory objects
compile in both cohorts. Native archive bodies are unchanged; their 77-suite
qualification is inherited, not rerun. The
[channel-admission qualification](../../tools/native_reconstruction/adxt_channel_pan_qualification.json)
retains source hashes and exact receipts. These fixtures do not replace the
corrected candidate's game test.
