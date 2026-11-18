# Auxiliary actor postprocessing

`AuxiliaryActorPostprocess` implements complete `6832F0` over the existing
canonical ten-record `AuxiliaryActorPool`. It reads the selected primary's room
for each reached active node. That room can differ from `World.room`; the
latter still supplies the actual scene flag channel's room index. A missing
selected primary refuses instead of supplying an inferred room.

For an admitted node, the pass calls the real `581870` scene consumer first,
then clears auxiliary bit `0x80`, handles status bit 31 through the same bound
equipment owner as primary postprocessing, applies actual `6660B0` surface
transitions, and calls `61A820`. This ordering differs from the primary pass.
There is no auxiliary head-reaction or statistics tail in this body. Off-room
nodes advance without clearing their pending bits. No visibility gate is
added to this outer traversal.

The original inactive-node branch at `68330C` goes to the loop condition
without advancing the list pointer. That profile does not terminate.
Production returns `inactive_nonadvancing`, identifies that actor, and keeps
effects already completed on earlier nodes. It does not reinterpret the
branch as an inactive-node skip. World/pool guards release on every return;
retained actor leases remain valid across retirement and physical-slot reuse.

`ActorPostprocessWorkers` adopts this pass at the existing
`Worker::auxiliary_actor_postprocess` position, after primary postprocessing
and before hit-region workers. It uses the same canonical Update owner's
World, records, channel state and flags. Primary and auxiliary result reports
are retained separately and clear together at the queue-reset boundary.

Paired `auxiliary-actor-postprocess-{gcc,llvm}-v3` receipts each pass 58,062
checks, 544 complete original executions, 854 controlled equipment calls,
772 classified-floor observations, 16 original inactive-loop observations,
eight unavailable-owner prefixes and eight retirement/reuse lifetime cases.
Inactive cases include both the first node and a later node after actual
earlier-node effects. Test-only preemption is restricted to the original
auxiliary loop, making its repeated unchanged node observable without adding
a production CPU or register model.

Complete original bodies are word-audited against the pinned owned ELF and
overlays. Real canonical scene records, flags, imported collision Grids and
the original no-work secondary selection participate. The equipment arm is
an explicit controlled test boundary, and the floor reference returns the
same native Grid classification. Nontrivial secondary dynamics retain their
separate full-body qualification. Concrete reached attacks, whole startup
ownership and full Stage 4 acceptance remain separate work.
