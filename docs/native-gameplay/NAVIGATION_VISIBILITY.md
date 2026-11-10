# Native navigation visibility and current-node selection

2026-11-10. Bounded component qualification; Stage4 is incomplete and installed
gameplay remains V39. No game was launched or performance-tested.

Native81A340 now calls the existing native collision sampler, triangle/type
filter and ordered first-hit query. The synchronous view borrows the scene's
wall grid, dynamic triangles and filter state. Include/exclude and dynamic-kind
arguments are set to the source caller's1FFFF/0/0, while canonical disabled and
slot-state inputs are retained. No new mutable collision owner is introduced.

The segment starts at query Y+10 and ends at **query Y+20**, independent of the
target's height. The original ignores certain first-hit kinds; it does not keep
searching for a later blocking kind. Static-before-dynamic ordering, disabled
types and type1 slot-state admission compare through complete original bodies.

Filtered8171E0/8171C0 preserves the exact pairwise distance sort. Source s1 is
also the swap temporary, so when all candidates block, the last swapped old-head
node can be returned instead of -1. The native code retains this source behavior
and has a controlled comparison for it. This is not a diagnosed retail bug.
Empty filtered candidate sets return completed/-1; incomplete sampling or
nonfinite inputs remain unavailable. Unfiltered empty input retains its earlier
uninitialized-source admission boundary.

Complete813BD0 and815BC0 now select filtered/unfiltered policies using canonical
motion class, status, auxiliary status and the route component's distinct105B
selection mode. The actual UpdateOwner resolves its World Actor and Bank, then
publishes the selected current node as in812540's entry prefix. That prefix is
statically word-audited; the rest of812540 is **not** executed or claimed migrated.
Absent route state and foreign/retired/closed actor capabilities refuse normally.

Both compilers pass40,293,789 checks, including68 visibility cases,3,408 filtered
nearest queries,6,144 motion/status policy predicates and480 node-selection
cases. The3,334 retail-node cases use authored SGL coordinates with a **controlled
empty grid**, not captured retail room geometry. Controlled static/dynamic
triangles exercise actual collision and first-hit behavior. Two nonfinite or
incompletely sampled contexts refuse. All earlier navigation, actor and
destination comparison counts are retained.

The reference executes the complete81A340/8171E0/8171C0/815BC0/813BD0 bodies,
579980 sampler/filter/triangle chain, and the full acos/square-root SDK bodies.
There is no clear-path geometry stub or host-acos replacement. The pinned main
ELF load segments and owned o2 image supply original-only test data; production
does not load guest RAM or execute those original register-context bodies.
Finite SDK comparisons do not claim physical exceptional-value parity.

Both parent builds and all ten integration checks pass, including actual Owner
publication, absent route capability and foreign/closed identity handling.
The v1 reference builds failed on a copied loop variable warning; v2 fixed that,
v3 added actor-policy coverage, and v4 added ordered-hit/slot-state checks and an
explicit test-only cstring include after GCC's parent build exposed its absence.
Failed receipts/logs remain. No original instructions were changed to get a pass.

Evidence: `build-native-sjuni/navigation-visibility-{llvm,gcc}-v4/receipt.json`,
`navigation-visibility-parent-*-v2.log`, `navigation-visibility-tests-*-v1.log`
and `tools/native_reconstruction/native_navigation_visibility_qualification_v1.json`.

Real scene loading and collision-owner binding, the remaining812540 AI work,
movement/transition callers, broad cost/content admission, semantic saves and
coherent native gameplay installation/acceptance remain required. This component
does not close Stage4.
