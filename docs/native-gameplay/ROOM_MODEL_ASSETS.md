# Static room models and persistent saved poses

The actual static pose writer is `1D2CB0`. `1CDFE0` selects it for resource
IDs1800..1FFF and supplies the current128-matrix bank at49FA10 and the saved
bank at4A3C20. The normal `1D0A70/1CE110` and alternate `1AA4C0/1CF560`
loader paths reach this common callback. It imports each raw skeleton root,
builds the original node poses, copies every nonnegative signed static-index
matrix into both banks, and publishes group counts, first-model mappings,
control bytes and first-node origins. Its separate control search begins at
local node1, excluding the root; matrix publication still visits root0.

`RoomModelAsset` now performs that import from the actual immutable NBD bytes
using the existing native Skeleton and Instance owners. It also uses the
qualified model-part reader for the physical part count. Its matrices are
immutable authored definitions, not another mutable gameplay pose bank.
The bounded profile rejects malformed root intervals, unavailable numeric
conversions, physical pose slots outside128 and unsupported part capacities.

`NativeSession` owns one `RoomModels` saved bank across room generations.
The current bank remains the active room's existing SceneModels. The actual
cold5EAEB0 clear establishes zero saved/current poses and group bytes;
5D7D60 establishes FFFFFFFF styles. No identity pose is invented. The actual
FF room-cache initialization is retained, and cache comparisons use the low
bytes of the three request fields, as5EBE30 does.

On a new room, the application reads its actual `_H.BIN`-selected NBD resource,
prepares current matrices and loaded-part visibility, validates the room
record/model capabilities, then publishes the new graph and commits the saved
bank. A same-room cache hit preserves current script changes and does not
overwrite saved poses or reload the asset. Before retirement, the application
captures live values from the existing model-binding owner, so a bound
object/matrix target also survives in an untouched current slot. Retired
generations remain readable through their existing leases.

The explicit `restore_poses_and_styles` operation adopts only the corresponding
5D7D60 subproducer. Matrix channels, bindings, camera and other reset effects
remain separate owners' work. This operation alone is not complete cinematic
restoration. Required teardown failures now surface as frame_failure while
cleanup completes, rather than being reported as successful retirement.

SessionRooms no longer rejects every current placement. It checks the actual
constructor branch: an active grid, current-room selection, flag1, explicit
shape early-out and model-binding flag8. A required model must have a loaded
physical part and pose in this actual asset. Unsupported bindings, including
an unavailable retirement contract, still refuse. The currently admitted
owned r0417300 room has69 actual model poses/parts and71 skeleton nodes;
its current-object count remains zero. Broader positive-instance application
acceptance still requires those rooms' full script/provider admission.

LLVM and GCC each pass the independent v8 comparison:11,843 checks, three
owned NBDs (r0417300, r0010100, r0023200), four root groups,264 published poses,
six ordinary loads, six actual byte-cache hits, six pose/style restorations,
28,679 original calls and12 paired SDK allocations/releases. Every current
and saved matrix, all128 style/visibility slots and all24 group records are
compared, including untouched entries. Complete1D2CB0 and its importer/math
dependencies execute, together with original1A31B0 part counting and the
defined normal-mode5EBE30/1D0A70 cache/visibility paths. The cold producer's
clear/cache call contracts are instruction-audited; whole application startup
is not executed by this comparison.

Renderer allocation, texture/shadow work, wall/floor loading, cooperative I/O
and camera reset are explicit observation boundaries in the bank projection.
The model-import boundary invokes the actual original part-count and static
pose bodies on the owned bytes. Full renderer loading and the alternate
cache-miss loader are not newly qualified by this fixture. The latter remains
an explicit unbound oracle branch. Separate existing RoomResources and
model-asset receipts retain their own narrower authorities.

Exact private receipts:
`build-native-sjuni/room-model-assets-{llvm,gcc}-v8/receipt.json`.
V1 lacked the conversion header; v2 exposed the control-search root mistake;
v4's fixture placed model data across an original global and was corrected to
an independent buffer; v6's nested oracle stacks overlapped and were corrected
to independent stacks. The retained failed folders are not game failures.
No original instruction/register/RAM machinery is linked into production.

The final application receipts are
`build-native-sjuni/session-rooms-{llvm,gcc}-v7/receipt.json`:21,728 native
room checks,32,000 independent original loader/mask checks and1,246 application
checks. Both tested executables' source/library closures are captured (729
inputs,59 native archives). The actual `_H.BIN`-indexed r0417300.nbd SHA256 is
`6d49570f8148054ef35d81ba6e64680740c8ff3288cdbd81bf92425ce3c546c3`, identical
to the original-producer fixture's independently inventoried ISO payload.
The application tests cover actual loaded assets, current versus saved poses,
same-room cache behavior, bound matrix targets across retirement, unavailable
binding refusal and explicit teardown failure reporting.

Both current25-parent cohorts pass without source drift:
`build-native-sjuni/session-rooms-parents-{llvm,gcc}-v6/receipt.json` (827 inputs).
They include the new actual dialogue and linked-flight contracts and the current
cinematic descriptor/view consumers. Parent v5's LLVM build exposed the unused
oracle-only equality friend in the standalone dialogue test; that test-only
conditional was fixed before this final pair. App v7 also corrects the earlier
qualifier's source-closure omission for the separately tested application
executable; production identities and outcomes are unchanged from v6.

Seal: `tools/native_reconstruction/native_room_models_qualification_v1.json`.
This work does not install a game candidate or complete the remaining scenario,
terminal frame-service, host input/network/media or semantic-save acceptance.
