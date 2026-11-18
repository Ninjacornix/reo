# Owned script frontiers after native scenario room rules

Status, 2026-11-09: both compiler receipts agree on all output hashes for the v14-ledger inventory. All 171 selected member hashes were verified: 166 RDT and five EVB members, with 347 declared code candidates. There are 156 ordinary and 157 offline banks with unresolved conservative flow frontiers, compared with 171 each in v13. The remaining 15/14 banks have no frontier under this bounded prefix model; this is not complete native Program admission, full payload/provider validation or runtime reachability.

Native `191` now follows the complete [scenario-two room-rule body](SCENARIO_ROOM_RULES.md). The explored ordinary prefix grows from 100 to 103 distinct opcodes; offline remains 149. New continuations reveal further work rather than establishing that those paths actually ran.

Leading ordinary frontiers are `131` (55 occurrences), `0D0` (49), `100` (28), `094` (21) and `0F3` (9). Leading offline frontiers are `0F2` (212), `0D0` (139), `058` (113), `100` (113), `166` (88), `131` (79) and `094` (71). Counts overlap between conservative alternatives and are not measured gameplay frequencies. Parent work on the actual `131` effect owner is intentionally not included until its qualification is frozen.

Remaining unknowns include unsupported providers and handlers, full record payload admission, native caller installation, initial saved entries, five SGL files, 81 unnamed members, indirect references and variant content. Next-object extents remain upper bounds rather than bytecode lengths. A closed conservative prefix does not prove every authored entry, externally scheduled script, all assets, co-op behavior or whole-game equivalence. No stock Program was installed and Stage 4 remains incomplete.

Evidence: `build-native-sjuni/gameplay-script-content-{llvm,gcc}-v11/receipt.json` and [v14 qualification](../../tools/native_reconstruction/gameplay_scenario_qualification_v14.json). No game, window or live process was accessed.
