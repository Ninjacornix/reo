# Owned script frontiers after interpreter v11

Status, 2026-11-09: both compiler receipts agree on the complete output hashes for the bounded v11 script inventory. All 171 selected member payload hashes were verified: 166 RDT and five EVB files, containing 347 declared code candidates. All 171 banks remain open in both dispatch profiles. No complete stock Program is admitted or installed.

Known ordinary prefixes now contain 90 distinct opcode candidates, up from 73 at v10. The leading ordinary frontiers are `131` (53 occurrences), `0B4` (41), `0B1` (40), `0D0` (38), `191` (23), `094` (18) and `0B0` (13). Paths now cross qualified `135` and the qualified `155`/`180` conditions. Inventory v5 models both condition alternatives, including condition nesting and scanner effects; an invalid `180` selector has only its failing branch. It does not assume a fallthrough through an unsupported handler.

Offline prefixes now contain 149 distinct opcode candidates, up from 143. Their leading frontiers are `0B1` (415), `0B0` (343), `0F2` (212), `191` (148), `0D0` (139), `058` (113), `100` (113), `166` (88), `0B4` (82) and `131` (79). Counts can overlap between conservative alternatives; they are not measured gameplay frequency or disjoint room totals.

`131` is still unsupported. Its node reset and halfword stores additionally create periodic callback `5D9680` through `5D9630`. A correct native replacement must own the task's flags, timer phases, captured position and actual effect creation contract. A fake task callback would not close that frontier.

Declared ranges are upper bounds, not proven bytecode lengths. Unknown initial saved pointers, unsupported providers and handlers, five SGL files, 81 unnamed archive members and indirect references remain explicit unknowns. Static graph alternatives do not establish real runtime reachability or production admission. Stage 4 remains incomplete.

Evidence: `build-native-sjuni/gameplay-script-content-{llvm,gcc}-v8/receipt.json`, [v11 native qualification](../../tools/native_reconstruction/gameplay_scenario_qualification_v11.json) and [native action-choice contracts](SCENARIO_ACTION_CHOICES.md). No game or live process was accessed by these checks.
