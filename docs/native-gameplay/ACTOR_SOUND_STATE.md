# Canonical actor sound and projectile metadata

Status: producer/state checkpoint, not complete audio or gameplay integration.
The installed game still uses guest-backed gameplay; Stage4 remains incomplete.

`Actor::sound_state` retains the actual554 allocation/gate byte and33 bank12
program byte. `Actor::projectile_variant` retains actualCF2. Generic Actor
construction leaves both unknown. The actual ordinary full-record clear supplies
known zero, while `LinkedModelPool` supplies zero from its actual6BA260 pool clear
(50 records ofD90 bytes). The small1F0 pose-work clear does not reach554 orCF2
and grants neither capability. No new mutable actor copy or guest-memory record
was introduced.

The complete66A730/107C68 comparison passes2,242,399 checks on each compiler,
including64 whole8700-byte source clears,64 canonical bootstraps,512 retained
actor lifetimes, capacity/busy refusals and explicit33/554/CF2 comparisons for
all eight records. Generic actors remain unknown. Both final30-parent cohorts
also pass with the matching new actor layout. The linked-domain source audit
binds its50?D90=2A620 clear and separate168-record effect domain to pinned words.

This checkpoint also tracks the coordinated World header prerequisites: the
read-only sole cinematic-controller accessor and ResourceBootstrap/SessionResources
friend declarations. These add no World fields or clocks. They permit the real
existing controller/resource owners to borrow canonical state; they do not
construct replacement controllers or claim full application adoption.

The consumers are implemented and being qualified separately. Complete1B9310
must distinguish unknown metadata from the known silent pair00/00. Its554 value
is an outer gate, while33 supplies the bank12 program tag;1AC7F0 replaces its
incoming554 argument. Nonzero metadata must come from actual population/model
producers, including6BB040/1B92B0/1B92E0. CF2's changing attack producers
6BEA20/6BFAA0 also remain separate work. No guessed nonzero tag/variant is
installed, and these optional fields do not prove those larger functions ported.

Evidence is sealed by
`tools/native_reconstruction/native_actor_sound_state_qualification_v1.json`.
Historical source/archive snapshots retain their exact layout identities; future
consumers must rebuild against this header rather than overlay it on old archives.
