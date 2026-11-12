# Cinematic object attachment math

Status: component qualification passed on both compilers; not installed.
Step4 remains incomplete.

attach_cinematic_object implements5717C0 after the caller selects the actual
parent model, full node ordinal and required source scale view. It copies the
real node world matrix, normalizes its three XYZ axes, transforms the scaled
offset and adds that to the object's position. Local rotation then updates only
basis XYZ. Copied matrix W lanes and translation stay intact: the resulting
object position can differ from its basis translation. Existing object angle
controls remain unchanged.

The first comparison caught a precision error in the initial implementation:
ordinary actor rotation converts turns through191F80, while this helper multiplies
unsigned turns directly by the owned2pi value and divides by65536. A new native
compose_euler_radians entry preserves190A10's exact input route. Existing actor
turn conversion is unchanged. The normalizer shares the existing qualified
constraint-math implementation, including its zero-vector policy.

Both cinematic-object-attachments-{llvm,gcc}-v3 cohorts pass2,097,176 checks over
262,144 attachments: all65,536 turn values on each of four owned skeletons,131,072
actor-parent and131,072 category10-parent original lookup paths,32,768 actual
zero-axis inputs and255,052 cases with distinct position/basis translation.
Thirteen native guard cases cover full-width node bounds and malformed commands.
Original5717C0, normalization, direction, rotation and basis product bodies run
completely and match owned instruction words. Source parent matrices project
actual native models from P07_00, HP07, HN54 and HN88 with controlled root poses;
original packing/construction is not newly executed. Nonaffine W-lane preservation
is an explicit controlled numeric case, not recorded gameplay.

Parent scale remains required caller data. The controlled category10 input tests
do not prove how actual constructed object model-work fieldsB4/B8/BC should map
to a native asset profile. That mapping must be established before real command
installation; an invented unit scale would hide missing evidence. Authored parent
selection and stream cadence also remain open. Both compilers pass all five
current dependent CMake parents.

Evidence: tools/native_reconstruction/native_cinematic_object_attachments_qualification_v1.json.
No game was run and no performance improvement is claimed.
