# Native AI frame

The Update Owner now runs the admitted `0x812460` frame as one operation.
It resets the original fields on the actor's input frame and execution state,
then checks the session gate, actor inhibition, shared control-pending byte,
session hit suppression, and actor status bit `0x20`. The input reset runs
even when a gate blocks the remaining work.

On an admitted call, observations run before goal dispatch, which runs before
the active-room action. This composes the native target cache, scene scan,
inventory, and RNG with direct goals 0, 6, and 14 and active-room actions 0
and 1. The result identifies the phase where a required path is unavailable.

The session gate is supplied explicitly at the native entry. The original
world setup at `0x5EB520` sets its byte to 2 before setup work and clears it
afterward. The gate still needs a live producer in the native room/session
flow. The existing hit-suppression and actor control-pending fields are
reused directly.

Both compilers pass 1,024 original frame comparisons, including 331 gated
calls and all combinations of the five gates. The observer regression also
passes 4,096 profiles. One off-room action case checks that the native entry
returns the unavailable action status after finishing the preceding phases.
The reference fixture uses a single navigation node, empty scene records,
controlled walls, and the declared heading and collision ports. All thirteen
parent tests pass. See `native_gameplay_ai_frame_qualification_v1.json`.

The remaining goal/action handlers, live scheduling and room setup,
coherent native game installation, and gameplay acceptance remain open.
