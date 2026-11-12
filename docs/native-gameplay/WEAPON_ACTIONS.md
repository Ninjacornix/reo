# Canonical weapon resource use and firing order

Status2026-11-12: implemented and source-compared component; Stage4 remains
incomplete. No game or device was launched for this work.

`ResourceWeaponActions` implements the complete65EC40 and65E750 control flow
against canonical World, Update statistics, SceneResources, templates, actual
ResourceDepletion/ResourceDeployment, WorldInventory and native BasicAudio.
It clears the pending status bit before the zero-resource return, preserves
category/selected-slot admission, and retains the original resource argument
after depletion clears selection. The result2 tail calls the real inventory
remove operation (5F2120), clears selection/action, then compacts; it does not
add another equipment retirement.

`ResourceWeaponFire` implements65E880 preparation and branch ordering with
owned action offsets, style distances, original-order finite rotation math,
real BasicAudio and WorldResourcePrograms. It rereads action metadata after
synchronous consumers. The public full-width resource entry preserves the
original argument to5823E0. Missing feedback/effect owners refuse when reached.

LLVM and GCC each pass1,479,187 checks:65,536 complete use/refresh cases,
32,768 complete firing cases and51,257 compared feedback/effect callbacks.
Use/refresh exercises all eight physical primary slots, all64 action rows,
depletion results, actual inventory removal/compaction and canonical counters.
Firing compares every supplied matrix/vector bitwise, all64 action rows,
eight character distance columns, both attack branches and mutations during
callbacks. Invalid/stale identities and missing feedback refuse explicitly.
Both CMake weapon targets build with strict warnings.

The full65E880 original and reached math/6B4420 bodies execute in the firing
oracle.665CA0 feedback and5823E0/6B24F0/5DD270/58E6D0 effect constructors are
declared controlled ports in this cohort. It qualifies the caller, not those
constructors. The audio cases deliberately use a template with selectorFF;
audible weapon bank validation remains in the existing independent audio
cohorts. The firing body still needs real transient light, pose/contact work
and visual lifetime owners, frame composition and installed-game acceptance.

Evidence: `tools/native_reconstruction/native_weapon_actions_qualification_v1.json`;
immutable `build-native-sjuni/weapon-fire-{llvm,gcc}-v2/receipt.json` cohorts.
Earlier failed cohorts are retained: missing link closure, missing owned
action-table initialization, a missing original zero-selection helper,
the old four-slot memcpy fixture bound, and a GCC formatting warning.
