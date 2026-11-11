# Native primary appearance assets

`ActorAssets::read_primary` now reads the real zero-BB4 primary appearance
assets through the exact full-path aliases in the File 1 executable ROM table.
Model class zero selects `Pxx_yy.NBD`; exactly one selects `HPxx.NBD` and ignores
appearance; every other class selects `EPxx_yy.NBD`. Character and appearance
are independent unsigned bytes. They are not normalized to the eight ordinary
characters or to a guessed number of costumes during filename selection.

The owned admission profile contains 46 exact members: 19 P, 19 EP and eight HP.
Characters 0–4 have appearances 0/1; characters 5–7 also have appearance 2 in
the P and EP families. Unknown combinations refuse rather than selecting a
different costume, another model family or an ambiguous duplicate basename.
The native reader verifies the 1,342-member archive, ordinal, name and bounded
member/section extents. Assets retain their original bounded bytes; model
instances and pose snapshots are independent native owners.

Both compilers pass 2,299,848 checks in the expanded actor asset cohort.
Primary coverage imports all 46 actual members, compares their raw bytes and
part counts, rebuilds 1,973 skeleton nodes, verifies independent mutable model
instances and checks the shared HP cache identity. Four missing combinations
refuse explicitly. Existing 133 primary-substitution and 233 auxiliary assets
also pass, alongside the 406-model scripted baseline.

The complete source-word-audited 1AA740 executes 327,680 primary filename cases:
all character/appearance byte pairs for classes 0/1/2/255, plus every
model-class/character byte pair. The oracle verifies the requested path, stack
return and the original slot-at-least-20 clearing before the read. Formatting
uses the actual owned literals. The archive acquisition port returns a
controlled failed read after observing the path. These cases establish filename
selection and preceding clear effects; successful original model/texture
packing is not claimed by this oracle. Native successful asset reads and pose
construction are checked separately against independently hashed archive bytes.

Reproduce with `generate_primary_actor_members.py` and
`verify_npc_actor_assets.py`, explicit compiler/CMake/private build/data-root
paths and fresh output folders. Paired evidence is
`primary-actor-assets-{llvm,gcc}-v2`; all thirteen parent tests pass. The source
and evidence seal is `native_primary_actor_assets_qualification_v1.json`.

Full primary initialization, model reuse/retirement callers, shared motion
bindings, full scene lifecycle and coherent native game installation remain
open. Texture/material submission belongs to Stage 5. No game was launched,
and Step 4 remains incomplete.
