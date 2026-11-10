# Bounded cost-route graph candidate: proof and remaining checks

2026-11-10. Bounded graph formulation and actual cost/local/Owner API adoption
qualified. The installed game remains V39. No measured slowdown fix or Stage4
completion is claimed.

`graph_cost_route` requires all four edge predicates at every authored node to
be known for the same immutable, serialized query snapshot. Otherwise it returns
unavailable without changing route outputs. That is more conservative than the
path-dependent admission. The cost API preserves bounded enumeration as fallback
instead of treating whole-graph refusal as no path.

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

The subsequent adoption cohort preserves first-direct and small-budget behavior,
counts graph admission, construction, relaxation and selection work, and requires
a conservative16*N+28 edge budget before dispatch. Vertex scans have a separate
2*N*N bound. Unknown graph preparation commits no output and the original native
enumeration continues within the remaining budget. Actual Owner tests exercise an
eight-node chain, local API metadata, budget13 refusal, and successful fallback
when only an unused target node's outgoing slot is malformed.

Both compilers pass63898732 identical checks. All20004 sampled retail cost
queries and sampled local queries complete without budget refusals. The old
enumeration baseline remains separate (16378 complete,3626 budget refusals).
Actual cost/local API graph uses total75833/9561; observed maxima are688 edge
inspections and5151 vertex scans. Completed original comparisons total82085 cost
API calls,56772 local calls and753667 separately exercised graph calls.

The shared extended-original allowance completes157 cost API,156 local and one
guard self-test call.3469 cost and3256 local contexts remain source-unverified
at the recorded limits. These repeated function contexts are not unique incidents;
their exact identities are in the hashed receipts. This cohort's limits differ
from the earlier candidate-only cohort because it verifies both actual APIs.

Both parent builds and ten integration tests pass. The first LLVM CTest launch
lacked its compiler runtime DLL directory and executed no tests; rerunning with
the matching PATH passes without source changes. Evidence is sealed by
`native_navigation_cost_adoption_qualification_v1.json` (SHA256
`01378069de863da3c0736b6cb83ea30474a17180c542b2aa20cb460eb3847abd`).
Initialized-cost, authored-condition, full AI/movement, real scene loading,
native saves and coherent gameplay installation/acceptance remain open.
