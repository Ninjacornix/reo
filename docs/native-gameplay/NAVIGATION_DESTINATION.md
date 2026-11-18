# Native actor destination setup

2026-11-10. Bounded component qualification; Stage4 remains incomplete and
installed gameplay remains V39. No game was launched or performance-tested.

Complete816890 now sets the destination on the actual optional World actor route
component through the UpdateOwner. It reuses canonical room, position, motion
class, auxiliary status, transient marker, slot/AI/status, session room and flags.
The same Bank supplies nearest nodes, visit reset, occupancy, route/action update
and local/cross-room policies. No second actor or navigation state is introduced.

The implementation preserves the destination/completion/refresh prefix, nearest
selection, visit reset before routing, action normalization and previous-action
write. The local-room branch applies height rules for actions1/2/8/9, or the
source turn-window and50/100 distance gates for other actions. It preserves
the distinct link-node bypass, current-room transient-marker failure and final
position/node substitution, including the off-room finalization path.

Original370140 biases a zero **Z** delta with the owned0x38D1B717 constant. The
already-qualified contact helper biases X, so destination setup instead calls
the shared native quadrant math with the correct Z adjustment. The complete
original370140/192180/1226F0/120908/122140/1224A8/191EF0 chain and complete
817100/191D10 distance routines run in the reference. Polynomial and other
constants are checked against the pinned main ELF and o0 image.

Both compilers pass40,202,873 checks, including15,884 completed destination calls:
6,668 use retail navigation inputs,11,276 use the strict profile and4,608 select
the previously declared collector-initialization correction. The correction
remains disabled by default and retains its prior limits. These profiles are
not claims of captured live-game stack values or installed game acceptance.
Two controlled cases refuse explicitly: nonfinite destination and a slot without
the admitted four-actor visit capability. Their preceding writes remain visible.

Both parent builds and all ten integration tests pass. The first reference build
omitted the new o0 declaration shim and failed compilation on both compilers;
those v1 receipts remain. v2 includes the shim, complete audited bodies and all
retail destination cases. No original body was replaced to obtain a pass.

Evidence: `build-native-sjuni/navigation-destination-{llvm,gcc}-v2/receipt.json`,
matching `navigation-destination-parent-*`/`navigation-destination-tests-*`
logs and `tools/native_reconstruction/native_navigation_destination_qualification_v1.json`.

Initial/current-node producers, filtered navigation/collision queries, complete
AI/movement and room transitions, broader work/content admission, actual loading,
semantic saves and coherent native gameplay installation/acceptance remain open.
This qualifies destination setup without closing Stage4.
