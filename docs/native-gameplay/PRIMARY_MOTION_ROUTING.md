# Primary cinematic motion routing

Status: native routing primitives and playback composition, not enabled primary
cinematic callbacks or installed gameplay. Step4 remains incomplete; installed
game remains V39. No game or performance measurement was run.

Runtime node track IDs now belong to each mutable animation `Instance`.
Authored `Skeleton` data remains shared and immutable. Binding, sampling, pose
capture, link capture and blending consume the instance's current IDs. Independent
model/playback copies retain independent routing. Temporary changes in the primary
bank do not mutate the secondary bank.

The routing primitives reproduce the source's count/category query, bounded
temporary zeroing and restoration for primary classes0/1. Counts are decimal:
22 or36 for ordinary primary models,22 or73 for class1. An absent token returns
true in the compatibility query but grants no valid clearing/configuration input.
Out-of-capacity native prefixes refuse before mutation, rather than invoking the
source diagnostic and continuing outside an admitted model.

The owned layout audit compares all46 P/HP/EP assets and complete source words.
All27 class0/1 assets match the restored36/73-node prefixes. P07/HP07 have seven
additional nodes whose existing routing must survive. Raw class2 indexing reaches
the adjacent function-address table beginning with5D2480/5D2790; it is not admitted
as a track layout. The generated native arrays contain only verified class0/1
data. No fallback from class2 to class0 is invented. The audit/generation receipt
is `primary-motion-layout-audit-v3`, reproduced with
`audit_primary_motion_layouts.py --output <fresh-path> --emit-layouts`.

Both `primary-motion-routing-{llvm,gcc}-v3` cohorts pass5271957 checks, including
7168 complete compatibility-query comparisons,64 owned36/73-track playback cases,
64 controlled22-track cases,1024 original continuation comparisons,64 accessory
tail cases and256 explicit refusals. Complete5D1DA0/5D1EA0 surround the original
58B9A0/58C130 calls. Both model banks' routing, channels, sampled parameters,
caches, matrices and root history are compared. The1A0D70 packed-header identity
lookup is an explicit test port; actual1A1FD0 packing executes and its count is
checked independently. The broader World oracle retains its existing lookup path.

No stock22-track body clip was found in the admitted89-member scene motion
catalogue. That test explicitly truncates an owned36-track raw container to its
first22 curve records and updates count/extent; it is a controlled input, not a
claim of a captured game asset. Real P00/HP00 and P07/HP07 skeletons execute.

World and primary model regressions are `primary-routing-world-{llvm,gcc}-v1`
and `primary-routing-models-{llvm,gcc}-v1`. The combined seal is
`tools/native_reconstruction/native_primary_motion_routing_qualification_v1.json`.
Actual5D1F20/5D2240 wrapper adoption, primary6BA880/67BFF0 composition, remaining
motion profiles and full scene entry/update/exit remain required. Existing linked
cinematic behavior and its explicit sparse-bank limits remain unchanged here.
