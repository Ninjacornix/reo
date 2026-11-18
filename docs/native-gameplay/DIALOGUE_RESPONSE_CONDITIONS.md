# Native dialogue response definitions and conditions

The canonical dialogue pool now owns the 512 signed flag-duration counters read by the SP condition dispatcher. The second SP table is imported as immutable 48-byte response definitions, preserving physical-row aliases and retaining the original cue resource. Live response selection and reply state are not installed by this checkpoint.

`DialogueResponseProgram` validates both table bounds and each referenced row. The owned corpus contains 270 SP banks and 79,859 referenced response rows. References to the same physical row retain the same key; consumers must share mutable state for that key rather than copying it per selection.

`evaluate_dialogue_condition` borrows the existing World, canonical actor identities, pool flag bank, session random generator, scenario flags and resource metadata. Its admitted leaves cover every condition kind found in those 270 owned banks. Missing reached capabilities return unavailable; unsupported phase-dependent scratch roles remain explicit. An unknown dispatcher kind returns zero, while kind FF returns one.

The resource-trait leaf calls the complete native 5B5350 translation over the actor's existing inventory and the actual resource/template owners. Its signed low-byte selector, character-six storage rules and unreachable selector-two storage branch follow the original. This helper is a resource query; it is not the scenario flag query. Scenario flags use 5F8330, and bounded byte flags use 5709B0.

Flag durations advance only through the explicit complete 6B80A0 operation. Set bits increment with signed-word wrap, and unset bits reset their counter to zero. The cold 6B7610 projection clears both flags and durations. Record clear 6B7810 preserves both. Duration conditions divide signed counters by 30 or 60 according to the canonical clock mode; actor elapsed conditions retain their separate unsigned divide-by-60 behavior.

The partner builder translates the 6B819C..6B8218 segment reached within 6B8130. It writes four signed character bytes after clearing them to -1, preserves order and duplicates, and skips actors with the same character. It requires the actual population capability. A fifth different character is refused before the original's write would cross into DB0, retaining the completed four-byte prefix. Full-record clears establish four known zero bytes; generic Actor construction leaves this capability unknown. This is the admitted list-building phase, not a replacement for the complete response worker.

A cross-domain offset audit corrected dialogue prefix selection: original 6B7C64 and 6B7C9C read B99, already represented by `Actor::motion_style`. The previous dialogue projection incorrectly used health `class_marker`, whose source byte is B9B. The new full constructor/update comparisons seed opposite values for these two fields, export both offsets independently and assert that the prefix follows motion style. Historical dialogue seals retain their original source hashes and are superseded for this mapping by this checkpoint.

Two original auxiliary leaves contain a nonadvancing inactive-node branch: 5F80F0 skips the next-pointer load after an inactive node, and 5F81A0 does likewise. The native evaluator refuses this reached profile. The test-only original bodies remain unchanged; an observer interrupts exactly at the inactive input read, so qualification neither invents a retail result nor runs the infinite loop indefinitely. Other source quirks retained include target-health's primary-array read after an auxiliary existence check, linked-count operation one acting as greater-than, and the distinct full-word versus boolean comparisons in the distance leaves.

Paired GCC and LLVM receipts in `native_dialogue_response_conditions_qualification_v1.json` bind these exact domains:

| Domain | Checks per compiler | Source coverage |
| --- | ---: | --- |
| Response program | 4,358,844 | 270 owned banks; 1,620,000 complete mode-zero getters; malformed rows, aliases and retained lifetime |
| Condition dispatcher and concrete pool | 3,915,944 | 398,664 complete condition cases; 3,528 controlled inactive-node entry interruptions; 787 constructors and 1,176 pool updates |
| Flag durations | 2,101,248 | 4,096 complete steps and 2,097,152 counter comparisons |
| Durations in the concrete pool | 2,298,936 | Complete construction/update, record reuse, counter persistence and callback reentry guards |
| Inventory traits | 1,181,211 | 393,216 cases over five owned item-template banks and one controlled bank |
| Partner list | 8,203 | 3,475 complete inactive-actor profiles and 621 bounded overflow-prefix profiles |
| Actual primary clear adoption | 2,237,276 | 64 complete 66A730 clears, eight canonical records and 512 retained leases |

Every original body is word-audited against the pinned owned ELF/overlays. Reference memory and generated MIPS bodies exist only in the tests. Earlier fixture compile failures, the initial leaf-field mapping correction and the diagnosed source-loop timeouts remain recorded rather than being removed.

The complete 6B7E40 orchestration, active request/cooldown selection in 6B8130, response monitors, mutable reply state and complete 1D41F0 room-bank publication still require integration. Selector-eleven publication already has a canonical owner in `Publication`, including the existing 667F90 gauge helper, and must be reused. The later text renderer and timed-message visibility producer remain separate. No game run, audio device, application-frame acceptance or full Stage 4 completion is claimed here.
