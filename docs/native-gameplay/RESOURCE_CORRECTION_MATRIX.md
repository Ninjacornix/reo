# One matrix for resource part six and attachment correction

The original662DB0 attachment consumer reads matrix180. That is the same
matrix written as part index5 by6B45C0 and primary static construction.
The earlier native projections stored `correction` and `parts[5]` separately,
so composing those individually qualified components could use stale data.

ResourceModel now owns the six matrices once. The named `correction` reference
always denotes `parts[5]`; constructor input initializes that matrix, and WMD/
static writes and retirement operate on the same value. Copy/move remains
disabled, so this reference cannot point into a different model after relocation.
This is ordinary native object ownership, without a guest byte-layout overlay.

Both compilers pass53,903,725 current frame assertions, explicitly comparing
correction identity/value with original180 on every compared model state.
The full attachment regression also passes18,837 checks,3,320 attachment cases
and56,905 original calls per compiler, including template imports, special
attachment routes, primary model order and lifetime guards. Parent libraries
compile. Exact sources and outputs are bound in
`native_resource_correction_matrix_qualification_v1.json`.

The model also has typed category/draw-tag fields for construction; this
checkpoint does not claim the uninstalled factory or renderer consumer is
complete. This corrects a native component composition error, not an established
cause of the player's earlier slowdown. No game was launched; Stage4 remains open.
