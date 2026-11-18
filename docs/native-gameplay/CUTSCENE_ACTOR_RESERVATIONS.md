# Cinematic character reservations

Status: qualified native requested/reserved character sets on both compilers.
Uninstalled; full primary scene assignment and Step4 remain incomplete.

`CutsceneActorReservations` owns two bounded32-byte lists. Scene initialization
copies requested characters, fills unused storage with88 and clears assignments.
Assignments append even duplicate characters. Query255 always succeeds; other
queries compare with signed list bytes. Thus a stored128 matches query-128,
not query128. This is the actual5F0CF0 distinction, not a guessed unsigned set.
The owner is separate from `MissingCharacters`, which serves NPC construction.

Full5F0C60/5F0CF0/5F0D90 bodies match the pinned owned overlay and execute in
`cutscene-reservations-{llvm,gcc}-v1`. Both pass870,427 checks,389 initializations,
133,384 queries,8,326 appends and388 explicit refusals. Coverage includes all
valid lengths, all byte values, signed/unsigned queries,255, duplicates, full
storage, reinitialization and a native alias-safe input view. The fixture's only
external operations are bounded fill/copy. The native header and CMake test
also build and pass without original bodies.

Negative/oversized original copy lengths and overflowing original appends are
outside admission. Native input beyond32 and a full reservation list refuse
without changing the previous state. No out-of-bounds source execution is used
as a specification for unsafe native behavior.

These are the state primitives used by5F0DC0. Complete actor choice, selection
preference, typed cloning, temporary slot binding and model handoff still need
composition. The class does not register live Actors or provide a second roster.
No game was run or installed and no slowdown cause or improvement is inferred.
