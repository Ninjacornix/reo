# Bounded cost-route graph candidate: proof and remaining checks

2026-11-10. Bounded candidate component qualified. The existing bounded
depth-first cost API remains selected. This document does not close a Stage4
gate or claim a measured game slowdown fix. Installed gameplay remains V39.

`graph_cost_route` requires all four edge predicates at every authored node to
be known for the same immutable, serialized query snapshot. Otherwise it returns
unavailable without changing route outputs. That is more conservative than the
existing path-dependent admission, so any later adoption must preserve its
existing bounded fallback rather than treating whole-graph refusal as no path.

The graph reformulation follows these source properties:

- A recursive node with an admitted direct target edge eventually overwrites
  earlier branch results and exits at its first direct edge. With all predicates
  known and without callback effects, that node can be a terminal whose only
  effective edge is that direct edge. This preserves the source's forced direct
  choice even when an earlier recursive branch was cheaper.
- Other recursive nodes choose a strictly cheaper child result below10000.
  Every cost is an unsigned halfword and the path visits at most128 nodes, so
  accumulated integers stay below2^23 and are exact in the admitted FP32
  profile. Nonnegative paths can lose cycles without increasing cost; reverse
  shortest distances therefore recover the winning numeric cost.
- Root selection stays a separate source-ordered loop. A root direct edge
  changes its selected node while retaining any earlier best cost and secondary
  node. Root self edges also need a separate case: the source calls its recursive
  helper on the already-marked root before subsequent edges forbid reentry.
- Secondary selection excludes both the original root and the recursive owner.
  Without the second exclusion, a zero-cost cycle can incorrectly take the first
  hop by returning through its owner to a later sibling. Ordered slot comparison
  then retains the source's first strict minimum.

The implementation uses bounded arrays, one full edge-admission pass, at most
two reverse distance passes and a maximum of two128-by128 vertex scans. There
is no recursion, guest scratch allocation, source register context or dependency
on enumerating simple paths in production. Edge-admission, relaxation and vertex
scan counts are explicit; no wall-clock performance result is claimed.

Both compilers pass63606968 checks with753902 completed candidate original
comparisons.753666 controlled calls cover all4096 directed four-node graphs,
three weights and all ordered endpoints,8192 seeded four-node graphs,4096 seeded
six-node graphs and explicit zero-cycle/root-self counterexamples. One unknown
graph refuses without changing output. The candidate admits all20004 sampled
retail-data queries;16378 match the existing results already compared to complete
originals.235 additional formerly over-budget retail queries complete extended
source comparisons.3391 remain source-unverified at observation limits (49 query
limits and3342 total-work limits), with exact query identities retained in JSON.
One two-entry guard self-test contributes the other extended completion.

Extended v3/v4 reference runs timed out because their dispatcher-only guard
missed source recursion implemented as a jump to an internal label. v5 caught
CRLF in the label match. v6 observes the generated test-only recursive entry
label, retains every source instruction and verifies both entries in a known
two-entry call. Limits are16384 entries per extended query and2000000 total
extended entries. Limited rows are not counted as source matches. Failed
receipts/logs remain; these harness failures are not native game failures.

Observed candidate maxima are204 edge admissions,284 relaxations and5151 vertex
scans across these profiles. Both parent builds and all ten integration tests
pass. Evidence: `build-native-sjuni/navigation-graph-{llvm,gcc}-v6/receipt.json`,
matching `navigation-graph-parent-*-v3.log`/`navigation-graph-tests-*-v3.log`
and `tools/native_reconstruction/native_navigation_cost_graph_qualification_v1.json`.

Before adoption: preserve low-budget/root-direct behavior, honest work accounting
and bounded fallback for unknown graph records, then requalify actual local/Owner
consumers. Keep complete original matches distinct from the3391 bounded reference
contexts; a graph proof is not a captured game test. Existing initialized-cost,
authored-condition, actual scene loading and coherent gameplay acceptance gates
remain. The candidate is not yet selected by the route API or installed game.
