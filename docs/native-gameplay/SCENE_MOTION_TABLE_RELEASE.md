# Scene motion token-table cleanup

Status: qualified represented motion-bank effects, not full5ED340 scene cleanup
or installed gameplay. Step4 remains incomplete; installed game remains V39.

`MotionBank::clear_scene_table` preserves the exact1B1BB0 extent: release token
slots0..1599, retain the logical row map and slots1600..1999, then zero the two
range-header bytes as5ED340 does. Kind is preserved. The generic native bank
capacity is not permission to clear an adjacent smaller source bank. Known-zero
and fully empty remain distinct; an unknown header/type refuses before mutation.

`HumanoidMotionAssets::release_scene_tables` prepares one immutable child for
the represented5ED340 motion effects: first the existing family cleanup, then
table cleanup in general/head, scene-body and scene-face banks. Unknown/missing
banks stay unavailable. The primary bank is retained; alternate and character
banks receive family cleanup only. The separate bank at4BAEF0 and the scene's
object/NPC/graphics/task cleanup are outside this projection.

Both `scene-motion-table-{llvm,gcc}-v1` cohorts pass530461 checks, including three
table cases and20000 post-cleanup queries. A bounded biased construction using
owned retail blocks crosses slot1600 and proves that the live tail survives.
Every slot/row, exact release count, repeated cleanup and unknown-header refusal
is compared with the complete release helper. The local test performs the two
header stores separately; it does not claim to execute the entire wrapper there.

`humanoid-scene-tables-{llvm,gcc}-v3` executes complete5ED340 and its complete bank
release helpers twice with actual loaded body/head/common/character assets.
Authored roster and object pools are explicitly absent in these surroundings.
Raw fill, allocation/graphics cleanup, player-pool reset and other non-bank work
are declared observation ports. Scratch and exact family row-map fills are
validated and executed. The fixture therefore proves the represented bank
projection, rather than a successful native implementation of every called
subsystem. Both compilers pass478180 native checks,14257004 original checks and
all thirteen parents; live publication also preserves model/channel state while
rebinding the retired scene-body resource.

The current primary model cohorts, `primary-scene-tables-{llvm,gcc}-v1`, compose
bank cleanup with the scoped temporary reset, selected resident retirement,
canonical return, actual default/selected-character asset restoration and primary
reinitialization. Common overlay1 is an explicit controlled fixture input, not
an inferred current-room motion selector. Full descriptor selection and the real
entry/update/exit caller remain required.

The combined evidence seal is
`tools/native_reconstruction/native_scene_motion_table_release_qualification_v1.json`.
Shared V1 builds were interrupted by the session restart. V2 exposed an overly
narrow fixture fill whitelist; V3 admits the source's exact pinned family row-map
fills as well as the scratch fill. Failed/interrupted receipts are retained.
No game launch or performance improvement is claimed.
