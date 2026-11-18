# Native cross-room navigation

2026-11-10. Bounded component qualification; Stage4 remains incomplete. No game
was launched, installed or performance-tested. Installed gameplay remains V39.

The native Bank now supplies817470 and its recursive817820 search through the
actual UpdateOwner, canonical actor/room flags and existing immutable SGL data.
Search scratch is local; persistent actor visits have the same single Bank owner.
The ephemeral flag snapshot is read-only during this serialized, callback-free
query. It does not create another mutable flag owner.

Traversal preserves first direct paired-link match, adjacency exactly1, candidate
visit marking before recursive traversal, and no rollback of that search mask.
It also preserves the unusual final-recursion-result behavior: a later failed
branch can overwrite an earlier successful branch. The outer caller makes a
fresh visit snapshot per candidate pair. It publishes source candidate visits
only when the selected first node equals the chosen source link's node.

The source's link destination-room byte+4 and signed paired-link halfword+A are
read directly from their retained authored operands; the remaining bytes stay
unnamed. Early actor status8/80 or empty candidate sets leave all output fields
untouched. A later no-path result writes only link=-1. Successful node/position,
link and persistent-visit outputs compare against the complete original caller.

The collector's unspecified initial cost remains an explicit boundary. The
strict default invents no zero and requires a known earlier value or a cost
writer before use. The second root collection can inherit the first one's
proven final scalar. Recursive calls conservatively require a writer rather
than recreating old source stack contents as native game state.

A separate `initialize_collection_cost` profile deliberately initializes that
scalar to zero at **every collector entry**. This removes an undefined input,
but can alter ordering when the original happened to retain a different value.
The test-only reference dispatcher applies the same declared initialization
before running the complete original instructions. This profile is disabled by
default; its comparisons are not claims of unmodified source equivalence or
acceptance in the actual game. No global change to the lower local route's
qualified cost-write behavior is made.

Both compilers pass29,554,496 checks, including259 recursive search comparisons
and4,473 outer route comparisons. Of those4,732 completed cross-room queries,
1,115 use the strict original profile and3,617 select the explicit initialization
profile (including early denials that never need collection).3,704 completed
queries use the five owned retail inputs.189 queries remain unavailable: five
controlled initialization/work/depth cases and184 additional retail contexts.
Those contexts are admission boundaries, not diagnosed retail slowdowns.

The complete original107AB0 copy executes in the oracle, alongside817470,
817820,819370, the existing collectors and local policies. All ten parent
integration tests pass per compiler, including actual Owner closure/identity,
canonical state and explicit initialization behavior. Native bounds are256
links,16 collector results,128 recursive depth and4,096 collector calls by
default; exhausted work never returns an approximate successful route.

Evidence: `build-native-sjuni/navigation-cross-{llvm,gcc}-v1/receipt.json`,
the matching `navigation-cross-parent-*` and `navigation-cross-tests-*` logs,
and `tools/native_reconstruction/native_cross_room_navigation_qualification_v1.json`.
The qualifier verifies frozen source, output and concrete parent binary hashes.

Actor route-state and destination mutation, actual AI execution, wider cost and
content admission, real loading, semantic saves and coherent native gameplay
installation/acceptance remain open. This component does not close Stage4.
