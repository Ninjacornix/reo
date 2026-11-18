# Native shared humanoid motion publication

`HumanoidMotionOwner` publishes prepared immutable motion content into the
canonical World on its simulation thread. Preparation remains separate from
publication: capture `snapshot()` on the owner thread, prepare a new snapshot
off-thread, then submit it to `publish()` on the owner thread. The owner and
World APIs are synchronous, not a concurrent shared-pointer registry. The
borrowed World must outlive the owner; outstanding preparation must be joined
by the eventual scene lifecycle before destroying its readers.

Each explicit actor binding names a semantic bank family and, for character
banks, a character. These are native content identities, without original
addresses or resource tokens. NPC construction records the three original
constructor bindings. Their identities remain fixed if mutable character or
motion-style fields subsequently change. Constructing an older prepared NPC
resolves the currently adopted banks before allocation. Scripted phase zero
records its selected body/general identity; phase one retains that identity
even if the rate-mode byte changes.

Publication preflights every explicit binding and retains actors, playback and
previous resources before changing anything. A missing required bank or
incompatible model refuses the entire publication. Successful publication
updates all bindings before retiring previous leases. World mutation and owner
publication/closure remain blocked throughout commit and lease retirement.
Animation channels, frame timing, blend state, model identity, phase and root
motion are preserved. Unaliased independent actor resources are untouched.

Snapshots carry immutable revision identities. Only the same publication or a
direct child of the current publication can replace it; stale siblings, skipped
ancestors and independent roots are refused. A compound preparation must
therefore publish each prepared parent in order. This is an explicit current
API contract, not automatic merging of background load results.

A World admits one live content owner. Before adoption, standalone components
can use their explicit supplied banks. An adopted empty owner, or a closed
adopted owner, cannot silently fall back to stale constructor content. Closing
an old owner does not unregister its replacement. Required resource consumers
report unavailability after owner closure.

The focused actual-archive test covers NPC normal/HN bindings, old prepared
construction, atomic failed preflight, stale siblings, fixed identities,
preserved playback state, scripted identity selection, publication during an
actual NPC update, reentrant lease retirement and closure. The scripted selector
case intentionally refuses invalid motion after selecting the real bank; it
does not claim successful curve playback. Asset, original World, constructor,
scene and behavior receipts provide the separate regression evidence.

Both LLVM and GCC pass the focused 30-check archive case: four publications,
25 rebound resources, eight refusals, two scripted binding checks, a guarded
NPC update and one observed lease retirement. Each current-source asset cohort
also passes 919 original-bank cases and all thirteen parent tests. Current
World cohorts pass 2,799,371 checks / 8,216,138 original calls; behavior passes
32,768 cases. Current construction and scene cohorts repeat 483 supported
constructors, 113 explicit absent-model refusals and 1,096 scene passes.

Reproduce publication and asset checks with
`verify_humanoid_motion_assets.py --publication`, explicit compiler, CMake,
private build and owned data-root paths, and a fresh output directory. Evidence
folders are `humanoid-motion-publication-{llvm,gcc}-v1` and
`humanoid-publication-{world,behavior,npc,scene}-{llvm,gcc}-v1`. Their source and
output hashes are checked by
`native_humanoid_motion_publication_qualification_v1.json`. No game was launched.

The installed game remains V39. Actual scene lifecycle adoption, primary actor
bindings, remaining sparse scripted wrappers, other action/curve consumers,
the eleven-NPC capacity conflict and coherent native gameplay acceptance remain
open. This component does not complete Step 4 or establish a measured speedup.
