# Native actor and resource animation audio

`BasicAudio` connects the reached native animation audio interface to the actual
`gameplay_audio::Owner` and existing bank Session. It implements complete
1B8BB0/1B8B20/1B8C70 frontends with actual5B4CE0 resource selection, reading
the canonical Actor, SceneResources and ResourceTemplates. It checks genuine
World/RNG identity rather than copying actor state into an audio shadow.

Category0 actor cues use slot+4; category1 alternate cues use bank13. Resource
cues preserve the nonzero-category0/6/25 remaps and the category0 descriptor
active/template255 guards. The signed template byte only qualifies a request;
it is not a bank or event. In particular, -2 admits the same identity bank while
-1 suppresses the cue. Resource bank selection is slot+8. Original discarded
owner arguments do not become the separate program-offset tag.

Bank pending/unavailable/command outcomes are retained in `last_result`, not
converted into fabricated playback success. The source callers ignore these
returns; native frontends do not throw merely because an actual bank command
is unavailable. Absent native resources or stale/foreign actors refuse with a
clear error. Surface, node and scenario-remapped routes remain explicitly
unsupported in this checkpoint; it does not close all player event consumers.

Fresh LLVM/GCC comparisons each pass404221 checks with1680 complete frontend
cases,312 real commands (96 actor/96 alternate/120 resource),107520 exact mixed
frames and7456 nonzero samples. Seven reached identity/unsupported refusals are
checked. Source positional/projection bodies and request producers execute in
the oracle. A controlled valid128-sequence bank is installed in all fourteen
real native ports; source commands drive an independent Session for request
state and exact PCM comparison. The resource-template profile includes actual
bounded version3 imports. This is not a real-device listening or game run.

The oracle's inverse-camera/listener and final composed projection inputs are
explicit surroundings reused from the audio qualification. Shared region
selection is already available in the existing collision region owner and
must be reused by subsequent surface routes; a second volume pool is not
justified. Runtime named-bank/room installation and game acceptance remain open.
