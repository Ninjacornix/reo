# Native bounded-cost route component

2026-11-10. Qualified bounded component; **retail work admission and Stage4 are
incomplete**. No game run or installation occurred; V39 is unchanged.

Native818B70/818E30 now use the same graph, actor facts/status, edge predicates
and canonical flag bank through the actual UpdateOwner. This policy scans all
four neighbor slots and ignores actor occupancy. It uses local visited scratch
and the original10000 sentinel and strict comparisons. It is not a general
shortest-path replacement for the ranked policies.

The original early exits matter. A later root direct edge preserves an earlier
recursive candidate's cost and secondary node, even while selecting the direct
target. Inside recursion, a direct target can replace a cheaper prior branch
and end the scan. Source==destination writes10000. A failure writes source node/
position outputs but leaves the caller's cost untouched. These behaviors compare
against both complete original bodies.

The native API exposes a deterministic edge-work limit, default65536, and returns
`unavailable` with `budget_exhausted` when it cannot finish within that allowance.
It commits no approximate route. The original has no equivalent explicit limit;
exhaustion is a native admission boundary, not a claimed matching original
failure or a measured game slowdown. No wall clock or game-speed change is used.

Both compilers pass23,092,224 checks, including81,928 completed cost comparisons
and the earlier ranked/edge/condition/bank suites. Synthetic checks cover every
unsigned cost halfword, sentinel boundaries, ordered/direct/cyclic paths,
occupancy independence and exact work-limit boundaries. Nine synthetic work
exhaustions and one invalid-node refusal remain explicit.

The retail cohort asks20,004 sampled queries with a deliberately lower4096-edge
verification limit. Of these,16,378 complete and match the original;3,626 exceed
the limit and do not run an original comparison. The wider default allowance is
not claimed qualified by this cohort. Closing those work-admission cells remains
required before a coherent native game candidate uses the policy unrestricted.

Both parent builds and all ten current integration tests pass. The source/output
and actual Owner binary identities are sealed by
`tools/native_reconstruction/qualify_cost_navigation_v1.py` in
`native_cost_navigation_qualification_v1.json`. Only the comparison fixture uses
the declared original zero/FF scratch-fill port; production has typed local
state and no guest-addressed scratch memory.

The later [graph adoption](NAVIGATION_COST_GRAPH_RESEARCH.md) supersedes the
retail work-budget admission count above: all20004 sampled cost queries now
complete through the actual API. Bounded original-comparison limits remain
explicit, and installed V39 is unchanged.

Next are outer/cross-room dispatch and actual actor destination/AI consumers,
with redundant-work reduction and broader admission comparisons for the costly
searches. The known r041 ordinal gate, remaining gameplay families, real asset
loading, semantic saves and coherent native game acceptance stay open.
