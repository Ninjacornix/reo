# Scene motion-family release

Status: native component qualification, not installed gameplay. Stage4 remains
incomplete; installed game remains V39. No game or performance measurement was
run for this component.

`HumanoidMotionAssets::release_scene_families` now prepares the shared-bank
effects of complete1B1E50: execute families0,1,2 in the general/head, alternate
and all prepared character banks, clear their range headers and invalidate the
default-loaded gate. Primary, scene-body and scene-face banks remain unchanged.
An unknown character bank remains unavailable. This is not the additional
bank/pool cleanup performed by5ED340.

All2000 logical rows and token slots5..1999 clear. Reserved token slots0..4 and
the bank kind survive. A known zero range therefore differs from an empty bank;
actual owned assets exercise this case. Repeated release preserves the same
reserved resources. Immutable child publications preserve old snapshots and
leases, and the live owner rebinds aliases without resetting model/channel state.

The composition check found an additional caller distinction. Whole-model
configuration58C970 reads a token table using `200*(key/100)+key%100`, without
reading the bank range header. Generic58CE60 lookup uses the header, including
its zero width. `Playback::configure_whole` now preserves its fixed-table rule
and admits the qualified known-zero strided profile. Unknown/sparse profiles,
negative keys and out-of-capacity accesses remain unavailable. Clip-to-model
topology checks still apply.

Evidence compares full owned original bodies and actual asset provenance. The
bank cohort checks all slots/rows, exact release counts, repeated cleanup and
20000 post-release queries across sparse, strided200 and strided500 profiles.
The shared cohort covers all eight prepared character banks, missing character
banks, retained body/face/primary resources and actual default restoration. Live
publication exercises retained actor models, channel time and scene-body aliases.
Whole-model playback compares configuration and continued sampling/root/channel
state, including nonzero reserved rows from owned retail assets after cleanup.

Receipts are `scene-motion-family-clear-{llvm,gcc}-v2`,
`humanoid-scene-families-{llvm,gcc}-v2`,
`scene-motion-playback-{llvm,gcc}-v2` and
`primary-scene-families-{llvm,gcc}-v1` under `build-native-sjuni`.
The combined source/evidence seal is
`tools/native_reconstruction/native_scene_motion_family_release_qualification_v1.json`.
Original heap identities, raw packing, file acquisition and the pair cursor
remain declared observation ports, not claims of complete original allocator or
renderer execution. Full cinematic ownership and installed acceptance remain open.
