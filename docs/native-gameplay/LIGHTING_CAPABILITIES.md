# Shared lighting capabilities

The existing scenario `Lighting` remains the sole primary64-light owner. The
new `gameplay_lighting::Pool` borrows it; it has no shadow pool or live payload
copy. Room commands and temporary consumers share capacity, allocation order
and retirement. A snapshot is an immutable value, not a live pointer.

Temporary handles bind an owner, reset epoch, physical slot and allocation
generation. Reset, retirement and slot reuse invalidate them. They cannot
replace or retire a later occupant or another owner's light. Epoch/generation
exhaustion refuses allocation rather than wrapping. The owner outlives its
facades; destroying a facade does not clear the owner's lights. Explicit facade
close clears the primary pool only.

Room-bank bindings deliberately retain their existing physical-slot semantics,
including removal of a reused slot. This source behavior was already qualified
and is unchanged. Room import, masks, selection, auxiliary reset and pool counts
also remain unchanged. This is a typed access extension to that implementation,
not a second implementation of room lighting.

Current evidence is sealed in
`tools/native_reconstruction/native_lighting_capabilities_qualification_v1.json`.
Both LLVM and GCC pass4,712,151 allocation/retirement checks,5,109,765 checks
against all166 owned LIG sections,14,080,853 combined scenario checks and the
four parent world/collision tests. The focused oracle executes complete
6B2FA0/6B3020/6B3090 bodies; its only declared leaf ports are bounded copy and
clear. Existing script tests also compare facade snapshots to original records.

Early standalone-pool prototype receipts are retained but superseded by the
`lighting-canonical-*` cohorts. The failed first combined fixture included a
header inside an anonymous namespace; v2 fixes the fixture include placement.

No game was launched or installed. The timed5D85E0 task, actual actor lighting
tag, transient constructors, auxiliary allocation/selection, rendering
consumers and coherent Stage4 game acceptance remain open.
