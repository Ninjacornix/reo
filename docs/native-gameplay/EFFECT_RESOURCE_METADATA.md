# Native effect geometry and material tracks

`gameplay_effects::Geometry` imports owned NBD model-object channel lists and
effect-root mesh palettes into immutable typed metadata. `MaterialTracks` imports
the common efdata material curves needed by those meshes and implements complete
original590790 sampling. It retains no guest addresses, resource tokens or CPU
context. Renderer resource conversion/submission remains Stage5; native visual
lifetime, selected real consumers and gameplay installation remain Stage4 work.

The corpus contains all six physically named EF*.NBD members in the owned File1
inventory, each paired with its same-number efdata file from the same archive.
There are two physical EF01 members and one each EF02/28/35/41. Basenames do not
establish runtime reachability. Extraction verifies each exact ISO member hash
and changes no original asset.

Original1D3350 supplies the root/palette contract. Root identity is raw node44,
through packed2 to nodeC6; mesh palette is raw40, through packedA to node174.
Raw node0 instead becomes nodeC4. The existing native Skeleton calls these
`track`, `static_index`, and `palette_index` respectively; metadata uses the
actual consumed fields rather than inferring meaning from those names. Root
lookup is first matching signed16 identity, independently of efdata's logical
group map. Each root's material ordinal selects an actual owned mesh.

Model objects'50000 lists supply common material-curve indices. Stock type4
objects report more children than are physically contained, but the original
required-tag lookup returns early. The importer follows that bounded consumed
lookup instead of eagerly reading unneeded later records. It refuses a consumed
extent outside the asset. Mesh channel counts above8 and root palette rows above16
are outside the selected published-piece profile. Native channels preserve full
indices and optional curves; kind11 stores1 minus sampled value/16, while other
kinds preserve the supplied prior material value.

Both compilers pass **134,194 checks**, covering454 root constructors,1038 mesh
lists,24,576 original root queries,8272 material samples, malformed extents,
missing indices and retained ownership across all six physical assets. The
oracle executes complete1D3350, its real forest packing/duplication/static-node
initialization, actual1A34B0/1A3500 list extraction,372720 and590790/590B10.
Only private resource allocation/lookup/release and cache bookkeeping are
declared external seams.454 allocations and454 releases balance. Each complete
body is instruction-word checked against the owned ELF/o0/o2 artifacts. This is
offline SDK-profile evidence, not physical PS2 exceptions, measured rendering
speed or game acceptance.

One EF35 root is explicitly unadmitted: ordinal48, identity53. Its authored
interval contains nodes150/151, but only node150 is reachable from that root.
Original packing therefore produces one node;1D3350 nevertheless reads a second
old workspace node. A native palette is not invented for that leftover state.
No part in the paired efdata35 catalogue references identity53. Other root
identities and admitted palettes still import and compare normally.

Across1458 authored parts,24 use missing resource/material profiles. These
include resource2/30 in early banks and EF41 group38 material2/resource198.
Their runtime use remains unknown. EF41 root38 has only two authored meshes,
while group38 requests a third; its group37 has the valid two. The periodic
family explicitly selects variant0 for logical36/37/38. **All three selected
groups pass complete geometry, material and transform admission in all six
banks**, including EF41's valid group37. Every consumed periodic material slot
is actually written by a kind11 curve; no guessed initial material value is
needed for this family. Other profiles remain refused, not silently rendered
with an arbitrary mesh or zero-index material.

Reproduce extraction with `import_effect_geometry.py --output <fresh-directory>`;
comparison with `verify_effect_geometry.py --compiler <LLVM-or-GCC> --corpus
build-native-sjuni/effect-geometry-owned-v1 --output <fresh-directory>`.
Final receipts: effect-geometry-llvm-v9 and effect-geometry-gcc-v3 under
build-native-sjuni. Earlier source-discovery failures are retained. They corrected
over-eager nested parsing and an initial metadata-field assumption; they were
not game runs or observed runtime bugs. The native visual consumer is separate
work and is not claimed complete by this resource qualification.
