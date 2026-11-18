# Native scenario-specific room rules

Status, 2026-11-09: the complete File #1 `191` wrapper and `1B3C40` room-rule body have a native implementation and independent original-body comparisons. This is a partial Stage 4 checkpoint. No game caller or complete stock script is installed by this work.

`apply_scenario_room_rules` consumes the canonical World session scenario/room, canonical FlagState, and the existing ordered SceneControls owner. It stores no cloned room, scenario or actor flag bank. The scenario is an optional **16-bit** value: instruction `1B3C50` is `LHU` (`942443DA`), so absence refuses and explicit zero is valid. Values `0102` and `FFFF` must not alias scenario two.

For scenario two, room `1F` disables every live type-three linked control only when secondary flag 496 is set. Authored IDs and type-three modes do not filter the traversal. The disabled list sentinel suppresses the mutation. The native traversal is bounded and respects the existing ordered owner and stale identity rules.

Room `23` has deliberately ordered owner-zero primary flag operations: primary 111 sets 112; scenario 298 sets 113 and then the newly read 112/113 can set 114, while a false scenario 298 clears 113; finally a false primary 111 clears 112. Flag 114 is never cleared by this body. In particular, an initially set 112 can set 114 before the final clear of 112. Actual `5705F0`, `5704B0` and `570550` bodies verify the owner-zero target in both mode profiles. These writes do not introduce notifications.

Whole-Program admission requires an available scenario and the actual canonical flags provider before earlier effects. An unrelated flag sink or a separate snapshot refuses. Offline dispatch still uses canonical owner zero rather than the per-actor flag proxy, and the three-actor coordinator checks readiness before changing the selected context or shared flag state.

The LLVM and GCC cohorts each perform 12,941,245 assertions, including 10,240 direct complete-original room-rule invocations and 6,144 new dispatch invocations. The complete-original cases cover five scenario values, four room values, all 64 combinations of relevant flags, disabled/enabled linked lists, four raw modes, type-three modes zero through four and a typed generic type-three node. Offline dispatch includes actor categories zero through four and relation variants, plus real three-actor coordination. Counts overlap and are not unique instruction coverage. The independent original instruction comments are checked against the hash-verified owned ELF and overlay.

The test-only indirect lookup prefers an actually defined original body over a missing-symbol throw stub with the same numeric address. This matters because the main room-rule body names `sub_005705F0`, while the actual overlay implementation is `o2_005705F0`. The generated fixture executes that real overlay body; no production MIPS execution or raw guest state was added.

Native algorithm masks now cover 317 ordinary and 290 offline bindings out of 432, including original no-op entries. This count does not establish complete provider coverage, stock runtime reachability, game caller admission, renderer consumption or whole-game equivalence. Missing event factories, authored programs, remaining providers and actual game validation remain open. Stage 4 remains incomplete.

Evidence: `build-native-sjuni/gameplay-scenario-llvm-v27/receipt.json`, `build-native-sjuni/gameplay-scenario-gcc-v19/receipt.json`, and [v14 qualification](../../tools/native_reconstruction/gameplay_scenario_qualification_v14.json). Prior cohorts and their receipts remain unchanged. No game, window or live process was accessed.
