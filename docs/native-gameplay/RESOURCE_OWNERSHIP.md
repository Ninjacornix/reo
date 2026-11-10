# Native resource claims and ownership primitives

`ResourceOwnership` composes the actual canonical inventory, descriptor, model,
collision and resource-factory owners. Its constructor requires the same frame,
World, resource and template binding; borrowed owners outlive calls. It owns no
parallel actor table, guest-addressed arena or successful callback replacement.
The implementation is not installed. Stage4 remains incomplete.

Claim tags are a separate native byte from the owner halfword. Setting an active
record narrows actor+1 to a byte, so actorFF stores0. Per-record clearing has an
explicit FF wildcard. Conflict testing and bulk clearing compare the full
low-byte-actor+1 value, so FF means256 and matches no byte tag. All operations
preserve inactive tags and other descriptor fields. These reproduce5B15D0,
5B1610,5B1670,5B16D0 and5B1710 without treating the tags as host locks.

593060 admission uses the actual primary actor inventory content query. Metadata
08000000 prevents carrying another item of the same content, including inactive
matching inventory descriptors because the original query does not check them.
Scenario23 additionally excludes34BC/34BD alongside34BE, and34BE alongside
either34BC or34BD. Scenario identity is required only after the earlier gates.
The current primary profile admits indices0..3; extended actor resolution remains
unavailable. An inactive resource returns false before actor access.

5B1760 assignment publishes descriptor flag1 before admission, retaining it on
rejection/result2. Success writes the owner, clears kind, sets800/clears400,
narrows signed templateC+2 into the shape byte and releases actual primary and
shared-secondary instances. It neither inserts inventory nor clears a claim.

5B1DE0 validates both active owned records and cross-owner admission before
releasing instances. It swaps the semantic descriptor fields while preserving
each location's owner and self ID. Claims, saved placement, flags, quantity,
template and content move with the item. Equal input IDs retain their original
behavior. Unknown original padding has no native state representation.

5B1BF0 publishes flag1 on both active inputs before checking world/owned roles.
After admission, the incoming record takes the owner and shape/800 updates. The
dropped record takes its room, authored ID, orientation variant and inherited
C00 bits, with the actual eight-row orientation/shape profile. The incoming400
bit is cleared after that copy. Nonzero kind uses its saved position/yaw and
clears kind; otherwise current position/angles are copied. The incoming instances
are released and the dropped item is constructed through `ResourceFactory::place`,
including current immutable floor data, RNG, model replacement and shared proxy
allocation. A full primary pool retains the already committed transfer and
return1. Unavailable profiles preserve the known prefix and throw.

Comparisons cover590,081 claim cases,393,216 admission cases and394,752 cases
for each of assignment, owned swap and world exchange. Each latter count has
393,216 descriptor/admission cases and1,536 actual lifecycle/construction cases.
All five owned ITEM sections, a controlled uniqueness profile and four actual
primary NBD inputs participate. Saved/current placement, prior model/proxy
combinations, all eight orientation variants, claim tags, signed fields and
equal IDs are compared. Four natural capacity cases cover empty/full primary
and shared-secondary pools; nine refusal groups retain their measured prefix.

Complete original bodies and the real593060/5F2210 query execute. Bounded clear,
descriptor/angle copy, resource geometry and floor ports retain their declared
contracts; original padding bytes are not a native schema. The original file
instruction words are audited. Existing recipe, cost, depletion, sound, visual
and inventory regressions remain included. An initial GCC fixture lacked loop
braces and failed its warning-as-error check; production comparisons passed on
LLVM before that fixture formatting correction.

Both final compiler cohorts pass322,792,673 combined assertions with identical
observations and balanced77,024 source allocations/releases. Both parent builds
and eight integration checks per compiler pass. The current unpinned scenario
regressions pass14,080,853 checks per compiler, covering327 ordinary and300 offline
bindings, including intentional no-ops; this is not complete VM coverage.
Identities are sealed in `native_resource_ownership_qualification_v1.json`,
SHA25688ca2d23e0b56c947678cf67796f3a13e9df7762edb5622a745076fe4d22325b.

Higher-level pickup, peer cleanup, action journals, position markers, authority
statistics/network/UI callers, authored saved-placement producers, extended
actors and actual game installation remain open. Adding these primitive fields
does not complete semantic World save/load. Installed V39 remains unchanged; no
game, audio output device or window/input action was used.
