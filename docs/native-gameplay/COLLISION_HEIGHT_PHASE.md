# Native ordered collision-height consumer

`update_collision_heights` composes the qualified primary post-movement policy,
native auxiliary actor leases and secondary ground solver in the `5DA680` order.
Primary actors use physical slot order. Auxiliary actors use the scene owner's
supplied list order. The secondary solver follows both primary-layout passes.

The source height-layer switch is true during primary and auxiliary processing,
then false before secondary wall processing. Native code expresses this as
local room-view options passed to the actual consumers. It does not change
immutable geometry or retain a global compatibility byte. Secondary wall work
remains a required distinct native owner and receives the false option.

Duplicate auxiliary leases, null leases and aliases of primary actors refuse
before geometric writes. A missing primary pose stops before auxiliary work.
A later auxiliary failure retains preceding primary/auxiliary effects and
reports the failing ordinal. Unknown secondary probe states retain their prior
floor/displacement effects and are reported. Exceptions from the secondary wall
owner also retain preceding effects; there is no rollback or legacy retry.

Both compiler cohorts pass 25 integration checks using actual World actors,
auxiliary actor leases, the real native post-move and ground components, and an
explicit secondary wall fixture. These checks cover ordering, the phase option,
early admission, partial failures and continued operation after an exception.
The complete `5DA680` instruction range was statically checked against the owned
overlay. This cohort does not execute that original orchestration body; the
children retain their separate original-body qualifications.

Evidence: [collision-height phase qualification](../../tools/native_reconstruction/native_gameplay_collision_phase_qualification_v1.json).
Both complete native CMake graphs also compile the latest World, scenario and
update owners under their declared floating-point options.

Actual auxiliary/secondary spawning, model poses, the secondary wall owner and
game worker installation remain Stage 4 requirements. No game launch or new
performance measurement is claimed.
