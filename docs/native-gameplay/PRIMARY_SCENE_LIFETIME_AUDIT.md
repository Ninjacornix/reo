# Scene roster and physical-model lifetime follow-up

Status: static owned-word audit plus strengthened original initializer execution.
Temporary model-cache admission remains closed. Step4 is incomplete.

`primary-scene-model-lifetime-audit-v1/receipt.json` checks twelve complete main/o2
bodies against pinned File1 bytes, including5ED340,5ED770,1AA740,66A750, construction,
cache retirement and motion cleanup wrappers. This static receipt does not run a
game or a complete entry/exit sequence.

The strengthened initializer fixture starts Actor.model-work at a different
bounded address from its physical slot. Previously it prefilled the value fresh
initialization was meant to store, so it could not witness that store. Both
`primary-model-pointer-{llvm,gcc}-v1` cohorts now pass39,837,137 checks and fifteen
parents:167,969 fresh comparisons explicitly repoint to the slot and4,351 restore
comparisons retain the prior pointer. Existing custom statistics, saved overrides,
selectors and actual model/constraint cases remain included. This improves the
test evidence; it does not change native gameplay behavior.

These boundaries must be preserved by the scene owner:

| Source/state | Established behavior |
| --- | --- |
| 4BAEA0 | Authored canonical primary population. It is not the eligible scene-roster count. |
| 5ED340 /38EDCC | Hides every visited canonical actor, filters by status/mode/room, and rebuilds a compact eligible count. |
| 38ED90 /38ED88 /38ECE8 | Compact character entries have companion original slots and status words. These stores are not interchangeable. |
| 38ECDC | Preparation remaps the original one-based preference into the eligible list. Do not infer this from World.selected_actor. |
| Eight physical character bytes | Preparation resets the count without clearing every byte.5F1400 searches all eight, including entries beyond the count. Capture those bytes; do not replace them withFF automatically. |
| Scenario23hex, mode6 | A one-eligible-entry/room13hex branch can append another actor's character, status and original slot. Its meaning remains numeric until the scene owner consumes it. |
| 5ED770 | Calls5ED340 before releasing selected descriptor resources. It visits16 descriptors and sets BA4 bit80 only through the authored population, then clears temporary bases. |
| 1AA740 /66A750 | Resource loading builds physical work by Actor.slot and calls the initializer. Fresh initialization repoints Actor.model-work; restore bypasses that store. |

The next native preparation cannot simply copy the authored population into the
scene roster. It needs the actual eligible filters, mode/room state, companion
metadata, preference remapping and bounded special branch. The current choice
and construction APIs accept a captured roster; they do not claim to produce it.
`CutscenePrimaryRoster.eligible_count` denotes the eligible38EDCC count at that
boundary, independently of `Session.primary_population`.

The follow-up source read establishes another ownership constraint:5ED340 calls
5F1290, which clears/reinitializes the temporary player records. When invoked
from5ED770, this happens before the selected descriptor5EC270 calls. The source
cache resources therefore outlive that actor-record reset. Native resource rows
cannot depend solely on resolving the old temporary EntityId. A scoped native
exit transaction needs independent physical-slot resource ownership and explicit
retirement authority, rather than a public stale-identity bypass.

The choice API now admits a preference anywhere in the eight captured physical
entries, including tail entries beyond `eligible_count`. The earlier profile
required preference<=count and could unnecessarily refuse a bounded source case.
`cutscene-physical-preference-{llvm,gcc}-v1` passes56,686 original comparisons and
all548 raw descriptors with every preference0..8. Both current construction/cache
regressions also pass117,002 checks. Preferences beyond eight remain unadmitted.

5ED340 also calls1B1E50 and pointer-table release helpers. That combines cleanup
and header resets beyond the already qualified5F0C00 family0 release. Preserve
their exact reserved-slot/header behavior before implementing native scene cleanup.

Physical cache rows need native resource ownership across distinct main/temporary
Actor identities. Inactive or absent canonical actors cannot acquire fabricated
model capability during return. Complete entry/exit, cleanup and resume-dispatch
tests must establish the transfer rules before that admission is opened. No
performance cause, game installation or Step4 completion is inferred here.
