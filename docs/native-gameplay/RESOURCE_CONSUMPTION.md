# Native item consumption and visibility

`ResourceConsumption` binds the existing recipe, inventory, descriptor, primary
model and update/statistics owners. It introduces no second actor, resource or
event pool. The four direct routines5B4550/5B46A0/5B4900/5B4990 now execute through
those actual consumers. Missing, foreign or retired required identities refuse.
An empty actor capability represents the source's null actor branch.

Decrement preserves signed-halfword wrapping. Depletion removes the actor's item
reference, compacts its actual inventory and retires the primary/shared-secondary
instances through the existing lifecycle. These callers destroy the input low
byte, unlike recipe primitives which sometimes reload the descriptor self index.
Consumption gives flag40000 priority over flag80000; the latter replaces content
and resets quantity only when the resulting content is3717. The separate transform
routine does not perform that quantity reset. Both record the original content
through the canonical completion statistics before testing template flags.

The local-actor predicate1B0340 now has one World implementation, also used by
owned recipes and opcode135. Local event capture uses the actual update clock
and scenario. A full cooperative pool preserves completion writes and reports
dropped events. Absent statistics/scenario refuses before subsequent item work.
The event-free decrement routine remains usable without statistics.

Destroy5B4900 dereferences the low16 resource only in its local event branch.
Nonlocal cleanup uses the low byte, so a wider unused argument is admitted there.
Other reached low16 descriptor indices outside the native256-slot owner refuse.
Visibility5B5850 now sets/clears the existing model's80000000 flag using the low
switch byte. Visibility itself changes during the subsequent common frame pass.

Both compilers pass154,880,240 combined assertions each, including1,638,404
consumption calls,128 actual model/inventory/event compositions and eight refusal
groups. Coverage includes all five owned ITEM banks, controlled priority and
replacement templates, the complete signed quantity domain, all modes, inactive
and null cases, owner and self-index differences, duplicate inventory references,
completion state and actual event lists. The full65,536 nonlocal destroy index
domain is exercised separately. All use/visibility regressions pass2,789,309
assertions each; the current script comparisons pass14,080,853 each. Both parent
builds and eight integration tests pass, including a production-linked consume
that retires a real model, removes inventory and records the actual event.

Exact source, executable and receipt identities are sealed in
`native_resource_consumption_qualification_v1.json`. The initial GCC cohort failed
on misleading fixture indentation; its frozen evidence is retained, and the
corrected fixture passes both compilers without relaxing warnings.

The subsequent [inventory callers](RESOURCE_INVENTORY_CALLERS.md) now supply
5B4460/5B45E0/5B47F0 and the typed message frontend. Health/status item effects,
ownership transfer, inventory UI and game caller installation remain open. No game or audio
device was launched for this qualification. Installed V39 is unchanged; Stage4
remains incomplete.
