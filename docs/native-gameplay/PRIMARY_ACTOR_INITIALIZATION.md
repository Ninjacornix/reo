# Native default primary initialization and restore

`initialize_primary_defaults` now supplies the fresh/default branch of 66A750
after actual primary model loading. It requires the canonical primary identity,
matching native model/playback owners, zero model substitution and the eight
owned character profiles. It does not infer a saved-state override or custom
statistics from absent input. Those branches require their own consumers.

The operation preserves AI control, visibility, appearance, actor room/position,
root-motion outputs and existing playback channels. It sets the original
contact identity and model group, initializes part visibility, native default
health/class, scales and modifiers, binds the three actual motion families,
clears the two impulse vectors, and assigns the owned body/local-shape and
contact-region profiles. Real native mirrored constraints are initialized under
the existing signed-pause rule. Body priority uses the original preserved AI
control byte. Final auxiliary flags and color-fade reset retain source order.

The distinct primary motion bank at original 4EA8C0 is now represented by a
separate native family. The audited initial 1B2130/1B2150 clear policy supplies
its empty state; common and scene loading do not replace it with cutscene body
content. An empty binding is not successful animation playback: consuming an
absent curve still refuses. Default motion aliases retain the original reset
identities independently of future active animation selections.

`restore_primary_slot` supplies the explicit restore branch selected by a
nonzero notification-pending byte with pause zero. A nonzero canonical exit
request bypasses constraints and pose restoration. Otherwise real constraints
initialize, and any nonzero saved coordinate or yaw restores the saved action
pose. An entirely zero pose is deliberately ignored. Both branches apply the
same final flags and fade reset. The selector/caller adoption remains open.
`select_primary_appearance` separately supplies complete 663170.

Both LLVM and GCC pass 1,544,218 checks, including 32,768 initializations,
4,096 restore cases, 65,536 appearance setters, 128 actual enabled-constraint
cases and a primary actor shared-bank publication. The reference executes
complete owned 66A750, 663170, 65FAB0 and 6EFAF0 bodies; the constraint call is a
declared observation port with the actual native constraint implementation
checked separately. Default cases cover all eight characters and primary slots,
every signed pause pattern, ordinary/HP model classes, health-status masks and
preserved AI values. Restore covers all exit-request bytes and every combination
of nonzero saved XYZ/yaw. Existing model instances, channels and unrelated
state remain checked. Custom substitution is explicitly refused by this API.

The audit also corrected a native NPC field association. Constructor byte4 is
the NPC motion-character index; it is independent of AI control at FF0. The
previous constructor and its reference check both incorrectly reused
`ai_control` for byte4. `NpcActorState::motion_character` now owns byte4, the
cleared AI byte remains zero, and the reference checks both original locations.
The earlier constructor evidence does not prove that mistaken field identity.
This is a pre-installation native correction, not a reproduced game symptom.

Reproduce with `generate_primary_actor_definitions.py` and
`verify_primary_actor_initialization.py`, explicit compiler/CMake/private build/
data-root paths and fresh output folders. Current default/restore evidence is
`primary-actor-initialization-{llvm,gcc}-v2`. The initial v1 fixture compile
failed because its oracle lacked the equality macro used by the complete
restore body; that fixture was corrected with warnings still enabled.

Current `primary-init-{world,npc,scene,behavior,humanoid}-{llvm,gcc}-v1`
regressions also pass: 2,799,371 World checks / 8,216,138 original calls,
483 supported NPC constructors, 113 missing-model refusals, 1,096 scene passes,
32,768 behavior cases, 919 shared-bank comparisons and thirteen parent tests.
The combined source/evidence seal is
`native_primary_actor_initialization_qualification_v1.json`.

Custom statistics, saved-state override, complete primary model reuse/release,
scene lifecycle ownership and installation remain open. The installed game is
still V39. No game was launched and Step 4 remains incomplete.
