# Native outer owned-resource use

`ResourceDepletion::use_owned` supplies5B1F30 through the same canonical
descriptor, cost/replacement, model, shared-secondary, debris, audio and weapon
owners. It is not installed in the game. Stage4 remains incomplete.

The source clears descriptor flag40 before checking activity, quantity or owner.
Inactive or nonpositive-quantity records then set40 and return0. An unowned
positive record returns0 with40 cleared. Metadata bit1 selects the actual native
cost operation; its known mutation prefix survives later capability failures.
The outer caller rereads quantity after that operation, decrements only for
policy1 and reports1 when a nonzero policy leaves positive quantity before that
decrement. If quantity becomes nonpositive, the saved metadata40000 flag controls
both actual owned destruction and return2. Without that flag the depleted record
and result1 remain. Policy3 overrides the result to3 even when redirected
replacement did nothing or changed the quantity/content.

No inventory detach/compaction, selected-slot clearing, completion event or
extra speed adjustment is added. Destruction retires actual primary and shared
secondary instances using the existing canonical lifecycle. Actor/inventory
references intentionally remain for their later callers to handle.

Both compilers pass277,182,080 combined assertions with identical observations.
The added outer-use cases include393,216 descriptor/quantity/metadata cases
across all five owned ITEM sections and a controlled bank,2,032 live cases using
actual models and consumers, four actual retirement combinations and an
unavailable-metadata prefix. Live coverage includes all eighteen stock WMD
absences, redirected self indices, null/zero equipment selection, category gates
and mode-dependent loading. The broader cost/depletion regression still runs.
Sixteen explicit lifecycle cases exercise primary/secondary combinations,
quantity1/2 and both destruction-flag values with retained inventory references.

The first comparisons exposed the incorrect return2 placement in the initial
candidate and its fixture expectation. The original5B2024 branch bypasses both
destruction and the5B2034 assignment when40000 is clear. The final code follows
that branch; failed cohorts are retained. Complete original5B1F30 executes and
its instruction words are audited against the owned overlay. Final file-read
and audio ports retain the explicit contracts documented in
[stock WMD absence](WEAPON_WMD_ABSENCE.md).

Both parent builds and eight integration checks per compiler pass. The final
source/cohort identities are sealed in
`native_owned_resource_use_qualification_v1.json`, SHA256
a510727d692efd01115f27180268c697123fefe0da8306e725f070eecb90a80b.

Actor item-operation callers, ownership/transfer, UI and actual gameplay
installation remain open. Installed V39 is unchanged. No game, physical audio
device or window/input action was used.
