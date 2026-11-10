# Cross-room navigation: source boundaries under investigation

2026-11-10. Initial static investigation, followed by the separately qualified
[bounded link collector](NAVIGATION_LINK_COLLECTION.md). Recursive cross-room
traversal and the actor consumer are still open. Stage4 remains incomplete and
the installed game remains V39.

Complete8179F0 collects links that match signed room/variant bytes, have a clear
caller visit byte and pass819360. Its direction parameter reverses the local
route endpoints. Both branches call817DB0 with policy1; the later stack flag
controls whether node/XYZ metadata is emitted, not the route policy. Earlier
working interpretations of the two caller flags must not become implementation
assumptions. The new bounded collector preserves those distinctions.

The collector reuses the float at its stack+138 for route cost. No initialization
of that float occurs before collection. Local817DB0's same-node path does not
write cost, so a same-node candidate can inherit an earlier route's cost or an
unspecified initial stack value. That float affects candidate sorting. Native
code must either require an explicit known initial-cost profile or record a
deliberate deterministic initialization correction; silently calling an invented
zero a measured original value would be incorrect. The separate local route
primitive should continue preserving its already-qualified cost-write behavior.

The collector uses a quadratic pairwise cost sort, swapping associated outputs
together. Equal comparisons skip a direct swap, but indirect swaps can reorder
ties; a generic stable sort is not automatically equivalent. Its swap loads one
link id withLBU beforeSH. The current native input budget admits at most256
links, so admitted ids fit in a byte; widening that input profile requires
revisiting the truncation behavior rather than assuming unrestricted16-bit ids.

The817470 caller supplies sixteen-element id/node/XYZ areas. The original does
not check append capacity in8179F0. A native sixteen-result admission profile
would be an explicit bound based on that caller, not an original local check.
Other caller profiles require separate evidence.

Observed link consumers establish signed destination-room byte+4 and a signed
paired-link halfword+A. Other tail operands are still retained as authored
encoding. Do not infer all destination variant/node/transition meanings from
one table sample. Cross-room search uses the existing shared visit masks and
byte adjacency matrix, so these must reuse the World bank rather than become
another mutable navigation state copy.

The bounded collector now supplies explicit cost provenance, original ordering
comparisons and actual canonical flag/visit consumers. The raw maximum link group
sizes in the five owned inputs are6,13,9,6,6, below its sixteen-result profile.
The [bounded cross-room implementation](NAVIGATION_CROSS_ROOM.md) now preserves
recursive/outer traversal with strict and explicitly initialized profiles kept
distinct. Actor route-state mutation remains next. No game
capture, slowdown diagnosis or performance measurement is claimed here.
