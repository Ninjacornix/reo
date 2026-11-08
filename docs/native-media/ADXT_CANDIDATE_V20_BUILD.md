# V20 linked; game retest pending

Status: build passed. No V20 game session has been prepared or run.

The isolated mono admission correction described in
[ADXT channel pan admission](ADXT_CHANNEL_PAN_ADMISSION.md) links successfully
with the same 17-entry header cohort as V19. The separate discard entry and the
new canonical movie audio capability are outside this executable.

| Artifact | Identity |
| --- | --- |
| Isolated source revision | `261a6a023e509afeb196944e03c468cb586461c4` |
| Sealed input manifest SHA-256 | `2feb53049629412d410e44495d723142f3412de8923111654400fc00ab07b997` |
| Executable SHA-256 | `9fe82de93d40eeed9b81e511d854442fc7d3dc1962558a0511893e9ffe7487d8` |
| Build log SHA-256 | `74438f6d79390f7a539815aa2e73555443c8ef3d0395af45925c4d916b58877e` |

Of 2,412 units, the ordinary compiler worker reuses 2,411 verified objects and
recompiles the changed ordinary adapter. The recorded elapsed time is 160.828
seconds. Outputs and the complete result remain under
`build-native-sjuni/candidate-work-v20` and `candidate-game-v20`.

Disk capacity prevents a reliable follow-up game test: C: fell below 1 GB free
and was last observed near 0.5 GB. The cause of the global disk growth has not
been established. The cached retry's output estimate is not a measurement of
whole-machine disk demand or peak space. No game success follows from the
successful link. Preserved caches, failed runs and original receipts have not
been deleted. Lossless compression and all recorded executable hash checks are
retained in the build directory; a failed LZX recompression attempt is explicitly
recorded as partial, with all 30 checked playtest images still matching their
original manifests.

The next game test must show the corrected startup, actual native source PCM
signal and ordinary source controls/lifecycle. Then Stage 3 still requires its
broader required audio consumers, logical/physical movie graph, resource/room
transitions and paced A/V validation. The historical movie stutter remains
unresolved. Do not put the PC to sleep until the complete Stage 3 checklist is
satisfied.
