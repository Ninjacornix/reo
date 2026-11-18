# Native actor snapshot publication

Status: qualified on both compilers; uninstalled.
Stage4 remains incomplete. InstalledV39 is unchanged; no game was launched.

`ActorMessageSelector::snapshot` supplies67E230 selector1 through the existing
UpdateOwner/StatePublication, canonical actor and shared suppression word. The
typed payload preserves action bytes, raw XYZ float bits, signed yaw/health,
status, resource/aiming fields, low room byte and selected-primary gauge band.
It uses the actual existing664D00 classification and667F90/668C80 gauge logic.
Category1 alone initializes the low model-variant byte. Other categories leave
that optional field unavailable; untouched stack padding is not a native wire
format. The declared original44-byte length is framing evidence, not a packed
native struct layout.

Four separate canonical optional fields supply the previously unmapped state:

| Source view | Native field | Mechanical evidence |
| --- | --- | --- |
| C80 | interaction_resource |5F2B70 copies the requested item's descriptor ID after writing C7F. This differs from C7A/C7C/C7D/C7F. |
| BC8 | aim_pitch_adjustment |586AA0 updates/clamps input or target pitch;5D76D0 combines it with CD4 for directional pose weights. |
| CD4 | aim_target_pitch |65ED70 initializes it on target selection;5D76D0 reads the signed sum with BC8. The broader target-angle producer remains open. |
| CDC | aim_target_index |65ED70 stores the selected target's B98 or FF;586AA0 resolves that index through the target table. |

These roles have owned instruction-word audits. They do not establish every
actor-family overlay or migrate the corresponding writers/import. Missing
required fields return unavailable after the source classification mutation.
No unknown field silently becomes zero. Existing canonical room/grid/action/
inventory/variant fields are reused without duplicates.

Capture completes before744638 becomes1 and before any mapped-room lookup.
Recursive selector1 requests therefore suppress themselves. A lookup can mutate
actor fields and mode; payload stays captured, while final dispatch rereads mode.
Missing/rejected delivery retains the committed classification and suppression.
World's next actor/frame reset uses this same word.

Both compilers pass73,525,738 combined checks with identical observations:
589,824 new cases,231,191 captured messages and116,867 mapped-room lookups. The
matrix covers full action/aiming halfword domains, dispersed raw float bits,
all relevant gates, callback mutations, recursive requests and ten capability/
lifetime refusal groups. Two native World frames use actual UpdateOwner
publication and verify within-frame suppression and subsequent reset; other
frame providers remain declared. The complete earlier cooperative/event/message/
hit/gauge matrices also run. Both parent builds and all eight integration tests
per compiler pass. Evidence:
`native_actor_snapshot_message_qualification_v1.json`.

An earlier verifier metadata string incorrectly described selector1 as a float
conversion path. Original selector1 copies raw XYZ. Selector5 contains those
conversions. New metadata is corrected; older sealed receipts are unchanged.
Actual queue/receiver/transport, selectors3/5/6/8/9/11, real state producers,
recovery/UI consumers, installation and representative game acceptance remain
open.
