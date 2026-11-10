# Native automatic completion checks

The update Owner now performs37BAF0 automatic completion itself. The delegated
`Worker::scenario_events` boundary is removed. The check still runs during pause,
and in an unpaused worker pass only when the original session-work gate permits
the final phase. Missing scenario/statistics or an unavailable reached condition
returns `statistics_failure`; it does not claim a completed pass.

`CompletionConditions` borrows the actual World, FlagState and ActionChoices.
It supplies all37BCA0 condition kinds: constants, ownership tags, scenario flags,
primary bank0 flags, bounded byte flags, whole-halfword equality, ordered AND/OR,
action-choice row3 and selected-primary activity/status. Unknown low-byte kinds
return false. Both evaluations receive the same rule; the second kind does not
implicitly switch to its second argument. Boolean short circuit is preserved,
including whether an out-of-profile second argument is ever reached.

Ownership comparisons retain the integer selected-actor-plus-one;255 becomes256
and cannot match a byte tag. Flag indices retain the existing owner bounds.
Selected actor status requires the canonical four-primary profile. A retired or
absent primary is inactive. The new512 ownership tags reside once in FlagState's
snapshot;512 is an explicit native admission extent, not a proven original bound.
Their remaining logical/network publication writers still require migration.

Automatic completion preserves seen-byte suppression, rule order, independent
duplicate scoring,32-bit score wrapping, flags, seen writes and actual event
requests. Full event capacity retains earlier score/seen writes and counts drops.
Unavailable later conditions preserve earlier completions and refuse the rest.
The actual Owner supplies its committed update counter and cooperative event pool.
It also owns the canonical ActionChoices used by scripts and conditions; a
foreign injected choice owner is rejected rather than producing divergent state.

Both compilers pass33,664,915 combined assertions each:1,245,427 condition cases,
24,578 automatic passes and14 additional refusal groups, plus the prior explicit
completion/pool suites. Complete owned37BAF0/37BCA0/666080/5709B0 bodies execute.
The16-entry condition table is loaded from owned o0 bytes. Coverage includes all
48 measured mapping entries, five stock rule groups, all256 seen-byte values,
all256 selected-actor and tag values, whole-halfword equality, kind aliases,
short circuit, same-rule second conditions, duplicate events, capacity and
unavailable-prefix ordering. The saturation fixture initially gave its source
events timestamp123 and native events timestamp0; corrected identical inputs
pass without changing production behavior. Both failed snapshots are retained.

Production-linked tests verify paused/unpaused gating, a real completion event,
counter provenance, duplicate suppression, missing initialization and foreign
choice rejection. The initial integration fixture omitted its repeat-point
command; it now uses the actual script repeat sequence. Both parent builds and
eight integration tests pass. Current worker/phase comparisons pass2,048 worker
and4,096 phase cases, including686 committed updates and12 audio-tick cases per
compiler. Their declared completion port uses a controlled always-true rule and
compares actual event values/clock/gates; full stock completion behavior is
compared separately above. This is not transitive original-worker execution.

Exact identities are in `native_automatic_completion_qualification_v1.json`.
Other statistics counters, ownership-tag writers/network delivery, durable
save/export and the remaining gameplay consumers remain open. These native
owners have not been installed in the game. No game/audio device was launched;
installed V39 remains unchanged and Stage4 remains incomplete.
