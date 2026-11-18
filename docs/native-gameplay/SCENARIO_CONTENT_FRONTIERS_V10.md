# Owned script frontiers after interpreter v10

Status, 2026-11-09: the existing bounded importer/inventory was rerun against the frozen v10 binding ledger. Both compiler receipts agree on every output hash. All 171 selected owned member payload hashes were verified: 166 RDT and five EVB members, with 347 declared code candidates. This remains a partial static inventory; all 171 banks are open in both dispatch profiles.

Ordinary known prefixes now contain 73 distinct opcode candidates, up from 66 at v9. Their paths cross qualified `104`/`105` and expose additional unknown continuations. The leading ordinary frontiers are `135` (58 occurrences), `131` (42), `0D0` (20), `0B4` (15), `155` (14), `0B1` (9), `0F3` (8) and `191` (7). Counts can overlap between alternatives and are not a partition of rooms or a runtime frequency measurement.

The offline graph still contains 143 distinct candidate opcodes. Its leading frontiers are `0B1` (415), `0B0` (343), `135` (234), `0F2` (212), `191` (148), `0D0` (139) and `100` (113). A native binding mask does not establish that its caller can supply the required live and saved native owners.

Next-object ranges remain upper bounds, not proven bytecode lengths. Conservative condition and context alternatives do not prove real gameplay reachability. Unsupported handlers, unknown saved entries, five SGL files, 81 unnamed archive members and indirect content references remain explicit unknowns. No complete stock Program is admitted, installed or executed by this inventory.

Evidence: `build-native-sjuni/gameplay-script-content-{llvm,gcc}-v7/receipt.json`, [v10 native qualification](../../tools/native_reconstruction/gameplay_scenario_qualification_v10.json) and [typed control contracts](SCENARIO_TYPED_CONTROLS.md). The private output folders retain exact payload provenance, candidate lists, frontiers and full output hashes. Stage 4 remains incomplete.
