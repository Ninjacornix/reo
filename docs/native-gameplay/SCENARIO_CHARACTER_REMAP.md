# Native missing-character mapping and startup aliases

Opcode84 now builds the missing0..7 character list from the canonical primary
roster and remaps active NPC descriptor IDs, the128 four-entry room asset rows
and all256 enemy spawn records. It uses the full signed population word and
preserves the old mapping tail. Actor activity has no effect on roster presence.
Inactive NPC descriptors and FFFF room IDs retain their previous values.

The source's enemy variant range is decimal60..69. Its last two indices read
the adjacent placement-request byte and current interpreter channel. NPC aliases
208/209 read those same two values. Native consumers now resolve those cases
through the actual two owners. The placement request retains its full byte
value. Existing placement and cutscene producers still write their observed
zero/one values. No guest-addressed storage is introduced by this operation.

The missing list stores eight bytes. IDs200..207 use those bytes,208 uses the
placement request and209 uses the interpreter channel. NPC/room mapping adds200.
Enemy variant mapping adds70 and narrows back to a byte. Word-ID commands
80/81/88 and halfword-ID commands89/8A/8B/8C now admit these two additional
aliases through the same canonical owners.

Whole-program preflight checks known bounded roster storage and NPC/room alias
indices. Offline coordination performs that check before owner/flag staging.
The actual remap checks again before any writes. Negative signed population
values follow the original empty-roster loop. Missing actors, unknown counts,
closed Worlds and out-of-profile alias indices refuse with prior state intact.

LLVM and GCC each pass181,261,433 identical checks in the complete current
scenario cohort. There are4,096 new ordinary/offline remap dispatches across
all six channels and seven refusal cases. The comparison executes complete
owned68FC00 and checks every mapped NPC, room pair and enemy record. Current
placement, cutscene, NPC command and enemy-import regressions also pass,
including full-byte placement-request values and the two extra command aliases.

Seven parent tests pass with each compiler. The real Update worker test checks
the empty roster, aliased room ID209, preserved placement byte255 and repeated
enemy variant mapping68->69->70 through the same interpreter. Direct archive
regression passes14,206 checks per compiler over186 exact members.
`gameplay_scenario_qualification_v25.json` seals the evidence. The ledger contains
355 ordinary and327 offline bindings out of432, including original no-op bindings.

Live NPC/enemy actor and model construction, remaining scenario commands,
real room/resource/input/network/save consumers and native game acceptance
remain open. Installed gameplay remains V39 and Step4 remains incomplete.
These are component comparisons with no running-game performance measurement.
