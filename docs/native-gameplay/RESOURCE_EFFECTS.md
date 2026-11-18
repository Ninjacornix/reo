# Native item-effect dispatcher and depletion lifecycle

`ResourceEffects` implements complete5B2080 using the canonical recipe,
descriptor, World, update and native healing/deployment consumers. It admits an
active item with positive signed quantity and nonzero ownership before reading
its template. The flags masked by4C must equal exactly4 (healing/status),8
(deployment) or40 (the actual constant-zero5B2760 routine). Combined masked bits
do not select an effect. Unsupported required helper capabilities remain typed
failures and preserve earlier changes.

After a successful helper, quantity is reread. Only helper result1 decrements
it. Completion statistics are recorded for the local target actor using the
current descriptor content. Depleted items are destroyed through the actual
model/secondary owner only when the flags captured before the helper contain
40000. Inventory references are deliberately retained: this routine does not
perform the detach/compact operations of the other consumption callers.

The final return mapping is independent of that post-helper quantity gate:
helper4 returns2 even when a synchronous callback changed quantity to zero.
The deployment helper can convert a different descriptor after its message
changes the self-index; the outer routine still rereads and consumes/statistically
records its original input descriptor. Capturing flags before callbacks and
rereading content/quantity afterward preserves the original order.

Both paired compiler comparisons exercise95,238 outer calls across all five owned
ITEM banks and a controlled128-row flag/effect-mask bank. They include1,035
item depletions,6,348 deployments and294 synchronous quantity mutations. The
combined cohorts also rerun the previously qualified healing, deployment,
recipe, inventory, worker/event, weapon and visual consumers. Final UI, room
authority and network sinks remain declared ports; message transcripts establish
arguments/order, not actual delivery. Original5B2080 and the constant-zero helper
execute in full in the comparison oracle.

Native-only capability checks ensure missing UI, unavailable actor messages,
unavailable deployment messages and missing completion context do not cause a
later quantity change or retirement beyond their known prefix. In particular,
missing completion context after a successful heal retains the healed actor and
zero quantity while leaving the item active. Full event-pool requests follow the
existing intentional drop semantics. Parent checks use real native model
retirement and verify retained inventory references, plus natural model capacity.

Exact current source/build identities, paired results and eight parent checks
per compiler are sealed in `native_resource_effects_qualification_v1.json`.
The initial comparison's invalid extended-owner input was excluded from the
admitted primary-owner domain; this does not qualify missing extended actors.

Weapon depletion replacement/cost, transfers, actual UI/network consumers,
extended actors and gameplay installation remain open. The next visual/audio
consumer investigation is [recorded separately](RESOURCE_DEPLETION_INVESTIGATION.md).
Installed V39 is unchanged; Stage4 remains incomplete. No game or physical audio
device was launched for these comparisons.
