# Native actor model binding

Prepared model assets now attach to the actual canonical World actor through
bind_actor_model_asset. Each attachment creates a fresh mutable Instance and
Playback owner. Actor.model_asset retains the immutable bundle for later
rendering and reconstruction. Asset I/O completes through ActorAssets before
the simulation owner invokes the binding operation.

The new objects are prepared before publication. Foreign, retired and closed
actor identities refuse. Model replacement revokes the actor's old constraint
owner and cached joint-two pose. Previously retained model, animation,
constraint and joint-snapshot leases retain their original objects. A new
occupant of the same primary slot receives a separate generation identity.

Model assets also expose the original812 halfword part count through the
bounded native1A31B0 query. It finds the first complete type2 selector.
Its first lookup uses an unsigned root count, while the following ordinal
lookup uses a signed root count. A matched directory with a negative signed
count therefore returns zero. The first implementation missed that edge case.
The corrected comparison also covers first matches with unconsumed size,
length and following records, full-word selector distinctions and truncated
consumed fields. The native asset stores the result's low halfword.

Both compilers pass425,095,888 current scenario checks, including4,100 complete
original part-query calls and seven bounded refusals. The owned asset and
binding suite passes3,483 checks per compiler, including406 loads, independent
part counts from1 through31, four live bindings and four binding refusals.
The lifetime test releases its asset reader and caller reference while the
canonical actor retains the asset. It then verifies release after world closure
and the final actor lease. Five current parent tests also pass per compiler.
`native_actor_model_binding_qualification_v1.json` seals the component evidence.

This supplies model resource ownership and metadata for the native actor
constructors. Actual actor construction, material task registration, motion
and sound acquisition, game caller installation and Step4 acceptance remain
open. Rendering part visibility and submission use their later native consumer.
