# Native direct AI goal dispatch

The Update Owner runs the original reevaluation policy and then dispatches
goals 0, 6, and 14 from the resulting canonical actor state. The comparison
checks their identities against the owned 16-entry table at `0x8294C0`.
The three implemented handlers complete on the first dispatch.

- Goal 0 preserves state. Goal 6 resets the goal through the same canonical
  goal setter.
- Goal 14 resets both goal and action when motion class leaves `0x3B`. While
  that class persists, the goal initializes counters 10 and 180, decrements
  the active counter, and schedules reaction events 2 and 3 on expiry.
  It uses the existing reaction policy and the Session RNG.

LLVM and GCC each pass 131,841 direct goal comparisons, including all
65,536 countdown and RNG seed values, all motion bytes, and a reevaluation
that changes the selected goal before dispatch. The full original dispatcher
and admitted goal callbacks run in the comparison. The suite also checks
14 unavailable goal profiles and all thirteen parent tests pass on both
compilers. See `native_gameplay_ai_goal_dispatch_qualification_v1.json`.

The other callbacks and immediate redispatch paths remain open. The original
dispatcher loops when a goal callback returns nonzero. None of the three
qualified callbacks returns nonzero. The live outer AI caller and gameplay
acceptance remain open.
