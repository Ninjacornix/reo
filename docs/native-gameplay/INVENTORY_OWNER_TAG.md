# Canonical inventory owner tag

Status: canonical state correction qualified on LLVM and GCC. Not installed in
the game; Stage4 remains incomplete.

The prior native `Session.inventory_modal` boolean was sufficient for the
qualified66B500 truthiness gate, but insufficient for the next inventory owner.
Source5F4F00 reads4BADEE as a byte and compares it with actor slot+1, with explicit
owner tags1..4. Converting that state to true/false would lose which player owns
the inventory before this consumer is migrated.

The canonical session now owns one `inventory_owner` byte. Zero is inactive;
valid player tags retain their identity. Native66B500 continues to test whether
the byte is nonzero. The comparison fixture now imports/exports the exact byte,
seeds all256 values and exercises cooperation updates to each tag1..4. No second
modal boolean or mirrored owner state is introduced.

Both compilers pass32,768 complete66B500 behavior comparisons with2,572,551
ordered trace words. The actual inventory/provider/action bodies remain declared
fixture ports in that cohort; this correction does not claim their migration.
5F4F00's owner interpretation is independently instruction-audited, not claimed
as a fully executed menu implementation. Its6DEE20/6E1430 consumers remain open.
The driver now freezes the current transitive World/model/animation dependencies
instead of relying on the earlier World header layout.

Parent builds include the weapon, shared visual and animation-event consumers;
both compilers and four World/collision regressions pass. Exact evidence is
sealed in `native_inventory_owner_tag_qualification_v1.json`. Historical behavior
receipts remain unchanged and keep their original boolean admission profile.
