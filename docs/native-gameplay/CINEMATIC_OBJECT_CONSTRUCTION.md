# Cinematic object construction and stream installation

Status: component qualification passed on LLVM and GCC; uninstalled. Step4
remains incomplete. No game was launched or speedup measured.

`CinematicObjectConstruction` now prepares actual object definitions and all
seven immutable streams before simulation. It keeps the descriptor destination
separate from the scene request and uses the retained archive asset owner.
Preparation refuses unknown/missing content, sparse headers, excess capacity
and unadmitted cold material profiles. It does not mutate a live World.

Creation uses the actual sixteen-object World pool. Admission requires a fresh
initialized generation. All requested records are reserved first, in physical
order; CPU models are then constructed in that same order. The header's initial
motion and later animation commands share one canonical field. Model identity
remains separate. Each record retains its immutable asset and independent mutable
model; the two known absent-skeleton assets do not fabricate models. The original
eight part-visibility bytes are initialized explicitly. This does not establish
renderer capacity for the separate fourteen-part model.

The returned current-generation bindings carry the qualified cold attachment
metadata. Prepared streams install directly through `CutsceneObjectTracks`.
Generation reset revokes the bindings while existing leases retain their actual
assets/models. Traversal and destruction stay under World/pool guards. Creation
on a used generation refuses before mutation. Allocation failure retains real
reserved bindings and the constructed prefix for explicit reset; forced allocator
exhaustion is not newly tested.

Both cinematic-object-construction-{llvm,gcc}-v3 cohorts pass372,999 checks.
536 of548 filename-derived descriptor requests have all required models, tested
in four loading modes:2,144 scene object constructions,2,684 objects and2,684
stream groups. Twelve descriptors retain55 unresolved model occurrences. These
include several same-scene variants and99-numbered files; aliases, reachability
or debug-only status are not inferred from their names.

Complete original5ECF90 and5F0610 execute with the actual object headers, exact
request paths and complete1D13F0/material/root/local/inverse construction. The
comparison projects no actor groups; other actor/scenario/media phases remain
declared ports. Renderer, allocator and combined legacy model-loader boundaries
remain explicit. This is not a full original scene execution claim.

Both current World cohorts pass13,276,674 checks, including existing object
timelines, streams, attachments and cinematic actor/model passes. Current model
lifetime cohorts pass150,804 checks and all five dependent CMake parents pass
on both compilers. V1 CMake Windows-path failure and V2 GCC fixture formatting
warning remain in build evidence; paired V3 is the admitted construction result.

Evidence: `tools/native_reconstruction/native_cinematic_object_construction_qualification_v1.json`.
Object motion-bank loading/publication, remaining scene request/phase selection,
reaction and secondary pose work, complete entry/exit and installed native
gameplay acceptance remain open. Step4 is not complete.
