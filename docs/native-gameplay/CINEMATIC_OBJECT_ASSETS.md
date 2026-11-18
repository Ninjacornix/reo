# Cinematic object asset ownership

Status: component qualification passed on LLVM and GCC; uninstalled. Step4
remains incomplete. No game was launched or speedup measured.

`CinematicObjectAssets` reads the actual destination scenario archive while
keeping the cinematic request area/scene/suffix separate. It retains immutable
bundle bytes, material/part counts, the first-root skeleton and inverse bind
matrices. Each playback instance owns independent mutable pose state. A missing
skeleton produces no instance; missing archive members remain explicit. Reads
and preparation occur outside simulation invocations, with a protected shared
definition cache and no game clock mutation.

The selected owned set contains452 bundles.450 canonical numeric requests read
the matching archive bytes; two unusually padded names do not round-trip the
original numeric formatter and are not invented aliases.450 bundles have
skeletons, with at most25 nodes in the first root. Two have neither skeleton nor
model sections. The one14-part model retains all fourteen parts. The original
constructor requests an8-part allocation, but allocator reuse and rendering
capacity have not been established; this is not a proven overflow or slowdown.
Other forest roots remain in retained source bytes for later renderer work.

Complete1D13F0,1D25B0 and1D2C00 plus their root-packing, static pose and inverse
matrix routines run in controlled original comparisons. The renderer defaults,
literal allocation request and normal/alternate loader argument contracts are
observed. Actual archive reads are checked independently.1CE110/1AAAD0 remain
declared loader/renderer boundaries, and allocators/texture handles use bounded
ports. This does not claim their full combined implementation.

The source constructor produces local pose and inverse bind matrices, not a
published gameplay world pose. Native assets retain inverse bind data separately
from each instance's runtime joints. Bitwise comparisons cover all owned nodes,
parameters, local/inverse matrices and parent/child/sibling identities.

The original attachment scale view aliases material-index entries30..35 in cold
object storage. All452 bundles have at most three materials; verified cleared
construction leaves these unused entries zero. Native assets expose this as
immutable zero-gain metadata rather than a simulated work buffer. Models with
more than30 materials have no admitted scale. This does not authorize applying
the cold invariant to unknown live mutations.

Both cinematic-object-assets-{llvm,gcc}-v5 cohorts pass214,814 checks:452 imports,
450 actual archive requests,1,808 complete controlled constructors,12,232 node
comparisons,1,976 material entries,924 part/material count cases and14 malformed
or unavailable refusals. Concurrent cached reads and independent instances pass.
All five dependent CMake parents pass on both compilers; the new library builds
through CMake as well. Earlier failures are retained: V1 nested fixture stacks,
V2/V3 the newly distinguished inverse bind data, and V4 an unbounded synthetic
negative-count fixture. No failed evidence was removed.

Evidence: `tools/native_reconstruction/native_cinematic_object_assets_qualification_v1.json`.
Actual scene object construction/publication, the55 unresolved descriptor model
occurrences, merged-scene identity, motion/media preparation, full scene lifetime
and installed native gameplay acceptance remain open. Renderer submission belongs
to Step5; this component does not close Step4.
