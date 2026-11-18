# Native linked-control route lookup

Status, 2026-11-09: complete original `5819C0` query semantics are qualified against the native ordered SceneControls owner. This is a consumer dependency checkpoint, not a new script opcode or installed game path.

The lookup suppresses traversal for the disabled list sentinel, narrows the request to an unsigned byte, and returns the first type-zero or type-two node whose full authored ID matches it. The tested byte at `+30` is the **type**, not the enabled byte at `+3C`; enabled state does not filter lookup. Generic typed tags zero/two participate in the identity query even when their destination fields are unavailable.

Types zero and two now optionally own a full pair of 32-bit destination values corresponding to original `+44/+48`. Their earlier `parameter` remains the independent `+6C` field. An absent destination is explicit unavailable state: existing partially projected nodes cannot become fabricated route zero/zero. A consumer that only rejects type two need not demand its destination. A type-zero route consumer must require the explicit destination.

`first_route` returns a checked SceneControlId and status/visit count. Consumers call `get(id)` again after synchronous effects, so changed destination values are reread from the canonical owner and retired/replaced identities refuse. This does not reproduce dangling original pointers or prove native callback/route effects. The contact agent owns the real `680B40` adapter and source comparisons separately.

Both compiler cohorts pass 12,600 assertions, including 4,096 complete original queries across all low-byte requests, ignored high request bits, wider unmatched authored IDs, mixed ordered types, all enabled byte variants and disabled list states. Tests also cover full-width destination projection, post-effect requery, retirement/replacement, empty lists and bounded traversal refusal. The first compile failure due to a missing test-only saved-controls include is retained; production did not change to suppress it.

Evidence: `build-native-sjuni/gameplay-route-controls-llvm-v2/receipt.json`, `build-native-sjuni/gameplay-route-controls-gcc-v1/receipt.json`, and [qualification](../../tools/native_reconstruction/native_scene_control_routes_qualification_v1.json). No game or live process was accessed. Stage 4 remains incomplete.
