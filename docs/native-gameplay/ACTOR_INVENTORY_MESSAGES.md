# Native interaction and inventory publication

Status: qualified on both compilers; not installed. Stage4 remains incomplete.
Installed V39 is unchanged. No game, output device or window/input action ran.

The update Owner now exposes the typed `record_actor_message` entry. The shared
publisher admits eight of the sixteen67E230 selector branches, including the
previously qualified action7 and status14 paths. Selector0 and13 are actual
no-message branches; this count is not eight packet encoders or full coverage.

| Selector | Native known payload | Original declared length |
| --- | --- | --- |
|0/13|No message after the real actor/phase/authority/suppression gates.|None|
|4|Interaction kind/mode, inherited interaction resource and detail byte.|8|
|10|Explicit two-resource action pair and four canonical carried IDs.|16|
|12|Four canonical carried IDs.|8|
|15|Four extra IDs from storage1..4; storage0 is preserved and not sent.|8|

Interaction resourceC7A remains the inherited hit/interaction field. The new
detailC7B and explicit pairCAA/CAB fields have distinct semantic storage; they
are not aliases for current equipment, action flags or the inventory arrays.
These payloads read the canonical Actor and `InventorySlots`; they introduce no
second inventory or byte-addressed live state. Higher-level pair/detail writers
still require migration.

All admitted actor messages share one phase/pause/category/authority/status4/
selector-suppression gate and final channel dispatch implementation. The earlier
status14 and action7 methods delegate to it. Snapshot values are captured before
synchronous room-owner lookup, which can change mode and live fields. Final
dispatch rereads raw mode while retaining those earlier values. Channel slot255
remains integer256 and room-owner UINT32_MAX+1 wraps as in the original.
The actual Owner facade uses this same publisher.

Only known initialized fields are typed. Source headers2/3 are zero; unknown
trailing padding is not a native schema. In particular, the length16 pair
message has six known payload bytes and additional unproven padding. An actual
transport must implement framing/encoding explicitly; it cannot copy a C++
object as though it were the original stack buffer. The four-byte18DBB0 calls
are bounded actor-to-stack copy ports in the oracle; their calling branches
execute completely. Other helpers retain the prior explicit port contracts.

Both compilers pass53,603,432 combined assertions with identical observations.
The new six-branch matrix has1,179,648 publication cases,116,624 typed message
observations,58,440 room-owner lookups and19 refusal/lifecycle groups. Full
phase/mode pairs, request/inventory byte patterns, primary slot/channel pairs,
category/authority gates, suppression and synchronous payload/mode mutation are
included. No-message cases produce no sink calls. Existing327,680 status cases
and393,216 action cases, including124,301 changed peer-request records, remain
unchanged after the common-gate refactor. Parent builds and all eight integration
tests per compiler pass.

Exact identities are sealed in `native_actor_inventory_message_qualification_v1.json`,
SHA256287517ab88eda5b360404c067c87b40e4c51d0e133510db85a5fb1e72be62614.

Selectors1/2/3/5/6/8/9/11 remain unsupported when reached. Position/combat/model
state and their real helper consumers are not replaced with opaque native byte
arrays. Actual inventory/action callers, receiver/queue/transport consumers,
remaining gameplay families, semantic World save/load and coherent game
installation remain open.

Follow-up: [actor state and periodic publication](ACTOR_STATE_MESSAGES.md) adds
selector2 and its actual classification/selected-gauge helpers. The immutable
inventory qualification above remains the earlier eight-branch checkpoint.
