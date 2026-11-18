# Wait-for-start integration checks

Both compilers pass all 75 native suites with the start gate forwarded through
the phased player, canonical session and stable instances. The control test
buffers one source while a peer renders, observes readiness without starting
the inhibited source, releases it at original tick 77, and checks that setting
the gate during playback leaves that playback running. It also checks retained
state across replacement, pause/resume interaction, stale keys and fresh defaults.

The same native libraries pass all 12 combined runtime-factory scenarios and
the game-handle router's three actual-worker workflows on each compiler. The
existing control and router fault suites still detect their three faults each;
the complete factory compiles against audited 130-patch SDK headers on both
compilers. Exact cohorts and ten receipts are recorded in
`tools/native_reconstruction/adxt_start_gate_qualification.json`.

This exposes the previously qualified Playback control through the complete
native owner. It installs no actual guest hook. The guest adapter must preserve
the raw C4+70 byte, mirror readiness at C4+71, and route source/control calls
through the canonical owner. V16 predates this change; its production preflight
is not evidence that this newer gate executes in a linked game. No game or real
audio device was run for this checkpoint, and no stutter fix is claimed.
