# Cold humanoid bank state

Status: qualified native bank projection, not installed gameplay. Step4 remains
incomplete and the installed game is V39.

`HumanoidMotionAssets::initial_banks(bool default_loaded_gate)` prepares the
primary, general/head, alternate and eight character banks cleared by1B2150.
Each bank has the source's known zero header, strided kind0, zero logical rows
and absent tokens. This requires no file reads and grants no unknown animation
data. Scene-body and scene-face profiles remain unavailable. The existing
`base()` convenience profile remains unchanged: its unprepared character banks
remain unavailable.

The default-loaded gate is an explicit caller input because1B2150 does not write
4BAE0F. Tests execute complete1B2150, including1B2120/1B2130/1B2140, from nonzero
bank memory and gate bytes0,1,128. They compare the eleven represented banks and
gate preservation, then execute1D1A80, actual selected-character overlays and
1B1E50. A nonzero gate skips default reads exactly as in the original; selected
character overlays preserve the other known-empty banks. Native cold snapshots
and earlier leases remain unchanged throughout.

Both `humanoid-cold-banks-{llvm,gcc}-v1` cohorts pass478084 native checks and
14223695 original checks over1098 bank cases, including120000 cold absent-token
queries. Thirteen parent tests pass per compiler. The live owner accepts a cold
root on a fresh World, publishes its default-load child, and rejects an unrelated
root replacement as stale. The seal is
`tools/native_reconstruction/native_cold_humanoid_banks_qualification_v1.json`.

Other1B2150 NPC/object bank arrays and its flag table are executed by the
comparison fixture but are not newly represented by this projection. Bounded
raw fills, file acquisition, packed-resource identity and heap release remain
declared observation ports. This change does not install a scene owner, enable
primary cinematic updates, or establish full entry/exit acceptance.
