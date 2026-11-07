# Native game-control bridge results

Both compiler cohorts pass **75 native suites**, including the new stable
instance control workflow and a clock-import attempt from a live queue
notification. The combined runtime factory passes all 12 scenarios with the
updated libraries on both compilers. The complete factory also compiles against
the audited 130-patch production SDK headers on both compilers.

Three injected faults are detected on each compiler: losing the time base when
opening a replacement, retiring an existing source before rejecting a conflicting
seamless loop request, and importing clock globals during active service. These
are actual source/lifecycle checks; they do not compare a wrapper with a second
copy of its implementation.

The first V1 cohort passed all 75 suites with LLVM but GCC rejected the new probe
fixture's statement formatting under `-Werror=misleading-indentation`. V2 splits
that line without changing production code or fixture behavior. The V1 receipt
and exact 412-input source snapshot remain retained under
`build-native-sjuni/adxt-game-control/v1-source`. Fresh V2 builds pass on both
compilers; the failed GCC build is not qualified.

`tools/native_reconstruction/adxt_game_control_qualification.json` records the
source/compiler/archive identities and eight receipts. No game, real audio
device, or actual runtime acquisition is exercised by these model factory
checks. Original public ABI effects and idle-handle semantics, actual source and
callback binding, reset admission, scheduler/movie providers and coherent live
A/V transitions remain required before Step 3 closes.
