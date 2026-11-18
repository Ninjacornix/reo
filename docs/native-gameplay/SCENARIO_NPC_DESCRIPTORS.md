# Native scenario NPC descriptors and startup inventory

The Session owns64 typed persistent NPC descriptors. `Owner::load_scenario_npcs`
reads the matching named NPC file through the retained native scenario archive
and commits a bounded, staged import. Reset follows complete683A90. The separate
ten-live-actor pool retains its existing lifecycle owner.

The importer follows complete1D45F0 after successful file acquisition. It walks
the group-relative directories, limits descriptor writes to64 and preserves
previous fields outside the routine's writes. Template IDs other than1D force
control mode0. The native source bytes stay immutable. The original rewrites
the source mode word. Mode dispatch uses the full source word, while the stored
control mode narrows to a byte. Mode2 copies one four-byte value, a second word
and a low-half alias. Malformed extents preserve the previous descriptors.

Complete684010 enables the first matching template/random-policy entry and uses
the canonical Session RNG and AI control registrations. Template64 in scenario1
skips registration. Complete6841E0 changes the first disabled entry's placement.
Complete6842B0 preserves mask priority, signed health admission, byte narrowing
and the two synchronized behavior flags. Complete684450 disables the first
matching entry. Their source names remain provisional where behavior is open.

Scenario opcodes3A and3D now execute through the same descriptors and real
resource table. 3A reads a signed halfword template ID, allocates once before
searching and inserts into the first eligible inventory with space. A full
earlier inventory permits searching a later duplicate. Allocation survives
absent matches and full inventories. 3D reads a signed byte template ID, finds
the first matching nonzero resource with the requested content and stores its
resource slot. Existing38/39/173 grants share the extracted592A90 allocator.

LLVM and GCC each pass73,374,071 identical scenario checks. These include517
imports with all five hash-verified owned NPC files, seven atomic refusals,
16,384 complete descriptor primitive calls and2,048 ordinary/offline inventory
dispatches. Every comparison executes the complete original bodies against
owned instruction words. File acquisition/formatting and memory library calls
are declared fixture ports. The prior actor inventory comparisons also pass.

The direct archive cohorts pass3,875 checks each over176 exact member payloads,
including all five NPC loads through the actual Update entry point. Seven
parent integration tests pass with both compilers. The initial parent link
failure exposed an undeclared AI-registration dependency. A shared controls
library now supplies that dependency to the scenario and AI owners.
`gameplay_scenario_qualification_v23.json` seals these receipts and source hashes.
The opcode ledger contains347 ordinary and319 offline bindings out of432,
including original no-op bindings.

Live NPC construction, actual startup command consumers80/81/88/89/8A/8B/8C,
absent-roster ID mapping, resource-owner detachment, model/AI preparation and
gameplay installation remain open. Installed gameplay remains V39 and Stage4
remains incomplete. No game, audio or network test ran for this component.
