# Native NPC actor construction

The [primary initialization audit](PRIMARY_ACTOR_INITIALIZATION.md) corrects a
separate constructor field identity: NPC motion-character byte4 is not the
AI-control byte at FF0. The canonical NPC component now retains byte4
separately, and its reference check validates both locations. Current paired
`primary-init-npc-{llvm,gcc}-v1` constructor and corresponding scene regressions
pass. Earlier evidence did not prove the incorrectly shared field identity.

`NpcActorConstruction` composes the original 6837C0 state contract through the
canonical ten-actor auxiliary pool, immutable owned assets, independent native
model/animation objects, collision profiles and actor-owned hit definitions.
Preparation completes content reads and allocations before publishing an actor.
Closed/busy owners, absent banks/models and capacity exhaustion are explicit.

The initial implementation incorrectly used 1AA740's primary substitution
filename route for NPC construction. Its 505-case v1 state comparisons used an
observed model/part-count port and did not prove that association. The corrected
implementation uses the distinct resident 1D0800 route: raw low-byte model ID,
N for ordinary model classes and HN for class 1. It never substitutes HP based
on character or subtracts one from an auxiliary model identity. Historical
receipts and failed scene tests are retained; the corrected cohorts below
supersede the earlier NPC asset-association claim.

Definition profile v3 contains 149 identities from the exact N/HN alias union
and 246 actual supported scene headers. It decodes 716450 + 20*id: model identity,
style/subtype, signed health, scale and height parameter. Metadata identity is
the low halfword of the constructor argument; model loading separately narrows
to the low byte. The model class is narrowed to one byte. All admitted rows have
contact selector 0 and use the four owned hit definitions from its actual table.
Other profiles are refused.

Creation adopts the actual body/local collision profiles, binds three required
motion-bank references and a single animation channel, initializes source
state/health/scale/room, and starts part visibility enabled except part 1 for
classes other than 1. Class 1 claims the actual four-slot attachment owner;
exhaustion produces the source's admitted absent/FF attachment. Native code does
not retain guest model-work, callback or contact-buffer addresses.

Both corrected compiler cohorts pass 20,023 checks: 483 supported constructors
and 113 absent-model refusals across all 149 identities and classes 0/1/2/255,
including wrapped arguments. Complete source-word-audited 6837C0 comparisons
cover state, scale, health, styles, collision, visibility, room, bank references
and attachment requests. Allocation/model ports are declared observations;
actual native assets, model/animation objects and pool operations run separately
in the same executable. The independent asset cohort verifies filename routing.

Checks include 48 pool retirements, actual actor/attachment exhaustion, missing
banks, closed owners and reentrant construction/closure from a cutscene voice
callback. All ten parent tests and the existing 5,681-check owned constructor
regression pass on each compiler. Receipts are
`npc-actor-construction-{llvm,gcc}-v3`; reproduce with
`generate_auxiliary_actor_members.py`, `generate_npc_actor_definitions.py` and
`verify_npc_actor_construction.py`, explicit build/data-root/compiler paths and
fresh output folders.

The motion bindings currently come from required external owners. Tests use
distinct known bank identities and do not prove actual motion content selection
or run the NPC animation callback. Attachment/model/AB0 consumers still require
their native ownership audit. Scene assignment is a separate adapter documented
in CUTSCENE_NPC_CONSTRUCTION.md. Game installation and full Step 4 acceptance
remain open. No game or sound device was opened for these comparisons.
