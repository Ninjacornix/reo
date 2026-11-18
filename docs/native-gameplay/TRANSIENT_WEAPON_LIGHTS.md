# Native transient weapon lights

Status2026-11-12: actual6B24F0 construction,5D83D0 lifetime and weapon consumer
are implemented and qualified. Stage4 remains incomplete. No game or device
was launched for this work.

`TransientLights` borrows the canonical Update owner and scene Lighting. It
allocates one task through Update's existing linked scheduler, then independently
attempts primary and auxiliary light allocation in the scene's existing arrays.
Either pool can fill without rolling back the other light. A task can exist
with neither child, then retire through the original callback cadence. It does
not retain an actor requirement after construction: those lights may outlive
the actor that supplied their initial surface tag.

The auxiliary pool now has its own typed generation-safe handles, using the
same canonical Lighting domain and reset epoch. No second light array exists.
World/Update and Lighting must outlive the borrowed component and its tasks.
Closing during scheduler execution returns busy. A room reset cannot make an
old task write into a recycled light; stale capabilities report failure and
retire the old task while preserving the new lights.

`TransientWeaponEffects` supplies the actual light operation to the firing
owner. Task-pool exhaustion is the original normal no-effect return. The other
three effect families still require their own consumers; absence refuses when
reached. This supersedes only the6B24F0 port limitation in the earlier
[weapon caller checkpoint](WEAPON_ACTIONS.md).

Both compilers pass7,269,137 checks:1,310,720 callback states,1,368 auxiliary
pool allocations,77 actual owner/adapter cases and294 original/native callback
frames. Comparisons execute the complete constructor/callback and both original
light pools, including independent full pools, full task admission, exact
definitions, quadratic attenuation, retained values, actor retirement,
busy close, foreign owners and room-reset reuse. Original task allocation and
retirement use declared controlled ports; native cases use the real canonical
Update scheduler. Policy-only cases separately capture releases/retirement.
Both native library targets build with strict warnings on LLVM and GCC.

Current primary-light regressions also pass4,712,151 checks per compiler.
Evidence: `tools/native_reconstruction/native_transient_weapon_lights_qualification_v1.json`;
immutable `build-native-sjuni/transient-light-owner-{llvm,gcc}-v3/receipt.json`.
Failed drafts remain retained, including the initial mistaken cubic policy
(the complete source proves a quadratic), fixture sign warnings and the
comparison-cache generated filename mismatch.

Remaining work includes actual pose/contact/flight effect families, complete
session/frame composition, scenario admission and installed-game verification.
These light checks do not establish a performance improvement or complete
native gameplay acceptance.
