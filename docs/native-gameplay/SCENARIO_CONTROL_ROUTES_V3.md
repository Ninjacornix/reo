# Correct typed route and model-reference ownership

Status, 2026-11-09: type-zero owns an optional full-width route destination. Type-two now owns `ControlModelReference { model, descriptor }` in its independent optional `model_reference` field. These are each one canonical pair; there is no parallel route-pair copy in type two. Original `680B40` rejects type two before reading a destination, while `6B5C60` reads its model byte/descriptor word. The earlier generic destination label for type-two fields was unproven and is corrected before installation.

`first_route` behavior is unchanged: first type zero/two with full authored ID matching a narrowed request, ignoring enabled state, respecting the disabled list sentinel. Both final primitive query cohorts pass 12,600 assertions and 4,096 complete original queries. Historical q1/q2 receipts and copied source headers remain unchanged.

The actual native route target adapter retains the canonical SceneControls owner and SceneControlId. It returns a freshly queried destination only for type zero; type two has no invented route destination. The separate collision qualification compares that adapter through the full original `680B40` consumer, including post-effect rereads and stale identity refusal.

The schema also adds optional type-zero matrix-selection fields (model slot, descriptor and resource class) and optional type-two matrix resource class. Missing values are unavailable, not zero defaults. Type-two's model/descriptor fields are reused; mode byte `71` remains the existing refresh parameter. These additions are source-identified state only in this query checkpoint: the matrix selector/evaluator and immutable table work remain unqualified and are excluded from its completion claim.

Evidence: `build-native-sjuni/gameplay-route-controls-llvm-v4/receipt.json`, `build-native-sjuni/gameplay-route-controls-gcc-v3/receipt.json` and [primitive query qualification](../../tools/native_reconstruction/native_scene_control_routes_qualification_v3.json). The actual route consumer has its independent collision qualification. No game or live process was accessed. Stage 4 remains incomplete.
