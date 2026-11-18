# Final native route-query source snapshot

Status, 2026-11-09: the final SceneControls header removes an extra trailing blank line reported by `git diff --check`. Query behavior and optional full-width destination ownership are unchanged from [the first route qualification](SCENARIO_CONTROL_ROUTES.md). Historical passed receipts and their copied headers remain unchanged.

Both final compiler cohorts pass 12,600 assertions and 4,096 complete original `5819C0` invocations. They preserve first type-zero/two ordering, full authored IDs versus narrowed requests, ignored enabled flags, disabled-list suppression, absent destinations, fresh identity requery, retirement/replacement and bounded traversal refusal. No new opcode or actual route consumer is installed by this query checkpoint.

The separate new `lookup_scene_route` adapter retains the canonical owner and SceneControlId and rereads destinations; its actual full `680B40` consumer qualification is owned by the collision work and is not claimed by this primitive query receipt. Stage 4 remains incomplete.

Evidence: `build-native-sjuni/gameplay-route-controls-llvm-v3/receipt.json`, `build-native-sjuni/gameplay-route-controls-gcc-v2/receipt.json`, [final qualification](../../tools/native_reconstruction/native_scene_control_routes_qualification_v2.json). No game or live process was accessed.
