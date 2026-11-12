# Secondary pose dynamics

`game/native/gameplay_world/secondary_pose_dynamics.cpp` implements the complete
owned `61A820` selector and `61AAA0` dynamics for all four descriptor rows in
`70F490`. It uses native `Actor`, `animation::Instance`, topology links, and
`SecondaryPoseHistory`; production has no emulated memory or register model.

`reset_secondary_pose_history` represents the admitted part of `61A620`.
The original initializer explicitly clears XYZ for four chains with two joints
each, leaving each 36-byte record's remaining 24 bytes untouched. The four owned
profile lists expose exactly one chain, so the native state retains two vectors.
An absent actor history means its real initializer/import has not established
that state. Actual source callers are `66B8E0` at `66B900` and `683B90` at
`683F9C`; creation/lifecycle integration must use those actual calling paths.

The selector retains the original active/visible/contact-bit gates. Signed16 session-state one (`324200`)
while unpaused requires the separate `FAC` category override: values 0, 1, 3,
and 4 select category zero; other known values select no work. An absent override
is unavailable. Other modes, including paused cinematic mode, consume the actor's
category. The category-zero model-variant branch indexes the ordinary variant
table with the **character** byte, exactly as the source does. Category one
indexes its selected table with the model variant. Ordinary/high category-zero
paths perform `61B920` contacts before checking the dynamics profile, including
the source appearance gate that follows the ordinary table read.

`61AAA0` captures node 21's world matrix, computes the body-plane normal from
node 10, and evolves two persistent displacement vectors. The four node ranges
are `[36,38)`, `[73,75)`, `[75,77)`, and `[73,75)`. The owned rows use spring gain
1.5, history damping 0.8, gravity `(0,-10,0)`, and joint plane thicknesses 8 and
13. Only profile three changes the normal-table index. Optional `-1` plane and
angle-clamp branches are unreachable for these owned descriptor rows; arbitrary
new descriptors are not admitted. Both original `370420` and `370570` compute
the first input minus the second, with different load ordering.

New local axes preserve sampled parameters, caches, local translation, and
fourth components. A prepared copy of the model rebuilds the selected subtree
through the existing qualified hierarchical pose implementation and publishes a
new immutable snapshot. `193240` starts with unit incoming scale. The generic
`patch_local_poses_and_rebuild` also accepts explicit incoming scales for
`193260` callers and an explicit root-sibling policy. The head convenience
method includes root siblings, as `193260` does. Validation/computation failures
leave the model's local/world state and snapshot unchanged.

The selector finally applies the original `70F680` topology recipe using
`patch_links_preserving_world`. Its source changes links after world publication;
the current immutable world snapshot therefore remains valid. Contacts and
dynamics preceding a later unavailable result can already have applied, just
as source-order work precedes the failing boundary; enclosing owners must use
their own staged copies when they require transactionality across that pass.

The standalone qualifier is
`tools/native_reconstruction/animation/verify_secondary_pose_dynamics.py`.
It pins and word-audits all complete source bodies against the owned retail
ELF and owned `o0`/`o2` overlays, including both initializer callers. Every
transitive native include and test helper is copied and hashed before compiling.
Original register/SIMD surroundings exist only inside the standalone test.

Final GCC evidence: `build-native-sjuni/secondary-dynamics-gcc-v17/receipt.json`.
The matching LLVM output is
`build-native-sjuni/secondary-dynamics-llvm-v17/receipt.json`.
Each successful run performs 4,249,167 checks, covering 1,536 complete dynamics continuations, 7,929 complete
selector calls, 256 complete `193260` model publications plus a local-only API
case, 1,536 retained snapshot lifetimes, 16 selector gates, four refusals, and
the initializer's cleared/untouched bytes. P07 is used for profile zero and
HP07 for profiles one through three. These are owned model/profile matches;
the qualifier does not treat arbitrary topology transplantation as content.
Earlier failures remain in separate versioned output directories.

This evidence covers finite FP32 operation under the existing native arithmetic
profile, not physical PS2 exceptional floating point behavior. It proves these
native helpers and their source order; scene installation, a full Stage 4
acceptance, and a game run require their separate integration evidence.

`initialize_cleared_actor_defaults` now establishes zero FAC and zero history
for actual cleared-record owners. The complete `5F1290` (0x10E0 bytes) and
`682D10` (0x1170 bytes) clears cover both fields; generic `Actor` construction
still leaves them unknown. Paired v18 receipts add these complete source audits
and cleared-state admission checks (4,249,171 checks each). Scene-primary pool
tests also verify dirty old history/override values survive retained leases while
the replacement starts cleared. The auxiliary pool original-body comparison
checks the same zero fields on every initial allocation and reuse.

The other actual `61A620` callers remain distinct: `66B8E0` is secondary-action
entry zero, and `683B90` instantiates 64 room auxiliary descriptors. Neither is
the cinematic NPC constructor. `1AFF90` in action entry is a mode-routed network
room-ownership claim (`o9:811970` / `o8:811140`), not an audio request; complete
entry adoption requires that real provider and its `66B960` continuation.
