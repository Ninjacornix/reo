# Native action notices, offline peer requests and the shared frame word

Status: qualified on both compilers. Not installed. Stage4 is
incomplete; the installed game remains V39. No game or physical output device
is used by these comparisons.

`StatePublication::actor_action` and the update Owner's `record_actor_action`
supply the67E230 selector7 path. They reuse the existing phase, pause,
category/authority, status4 and selector-suppression gates. Primary channels are
slot+1 as an integer; category1 uses the actual room-owner sink after capture.
The final raw-mode dispatch is reread after synchronous room-owner lookup.

The typed message captures D92, the four DA2..DA5 bytes and existing equipment
field C7F. Type7 and length12 are known, as are zero header bytes2/3. The last
original stack byte is unknown padding and is omitted from the native schema.
The existing inherited `equipment_slot` owns C7F and `interaction_slot` owns
C7A; no second requested-item/resource byte was introduced.

Complete1B02D0 returns whether raw mode is0. Only this offline mode applies the
peer requests after message capture: bit1 and nonzero DA3 select the one-based
peer and write kind2/mode0/current interaction resource; bit4 and nonzero DA4
write kind2/mode1 without replacing that peer's resource; bit100 and nonzero DA4
write kind2/mode0/current resource. That exact order matters when bits and peers
overlap. Existing peer activity is not a gate. Each peer must be a registered
canonical primary; unavailable peers refuse at the reached write and retain any
earlier request mutation. This does not emulate arbitrary array overflow.

Missing final message capability is reported after those offline effects. A
room-owner callback can change mode and actor state; earlier payload values stay
captured, while final dispatch uses the new raw mode. The publisher does not
clear D92. The actual World frame clears it only after its publication service
returns. A native service which reports an unavailable consumer preserves its
known prefix instead of inventing a successful delivery.

## The shared halfword correction

The original World frame resets744638 before each eligible actor. The actor
publisher compares the same halfword to its selector. Earlier native components
kept independent `World::frame_shared_counter` and
`Session::actor_message_suppression` values. Their isolated comparisons did not
connect those views. `frame_shared_counter` is now a reference to the existing
session field, so World preparation and publication share one value.

This follows the separate [D92 producer correction](ACTOR_RESOURCE_OPERATIONS.md).
Both are defects found while composing uninstalled native owners. They are not
measured causes of the player's historical slowdown. The older qualification
seals remain historical source snapshots.

Current checks execute complete original selector7 bodies, all eight admitted
primary peer records, full notice flags, phase/mode pairs, authority/channel
gates, overlapping request bits, and synchronous lookup mutations. Final message
and room-owner endpoints remain declared ports, with true meaning completed
dispatch operation rather than proven delivery. Actual update Owner/World
composition checks the shared reset, suppression, successful publication and
unavailable-consumer prefix. Other message selectors, actual queues/receivers/
transport, pickup/action callers and coherent gameplay installation remain open.

Both compiler cohorts pass45,764,730 combined assertions with identical results:
393,216 action-publication cases,231,448 typed message observations,116,868
room-owner lookups and124,301 changed peer-request records. The request metric
compares resulting records; it does not count every idempotent write. Eight
refusal groups exercise reached missing peers and final capabilities, early
phase gates, invalid actors and closure. Four native World/Owner publication
steps cover successful dispatch, intentional suppression and unavailable-final-
consumer failure. These are invocation observations, not four delivered packets.

Both parent builds and eight integration tests per compiler pass. Current
complete frame/input comparisons pass4,096 cases and291,127 ordered calls per
compiler; native lifetime/canonical-alias checks pass81 assertions. The final
cooperative receipts clarify both selector7 and14 admission; their observations
match the first passed cohorts exactly. Earlier seals are unchanged.

Identities are sealed in `native_actor_action_message_qualification_v1.json`,
SHA2563e8246cd6d911d4baf8b6ef5282d658b2bdc755c35e0d9d7dba8f177bc478176.

The subsequent [interaction/inventory publication](ACTOR_INVENTORY_MESSAGES.md)
adds four payload families and two no-message branches. Their shared actor
gate/channel dispatcher retains this complete action/peer-request comparison.
