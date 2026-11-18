# Ordinary primary record bootstrap

`initialize_primary_records(World&)` implements the source-backed bootstrap
clear `66A730`: eight ordinary `0x10E0` records, totaling `0x8700` bytes.
Production creates eight typed Actors in the canonical World's existing
entity owner and publishes them into its actual primary slots. It does not
allocate a parallel actor array or retain guest-layout record bytes.

This API admits bootstrap before any primary record exists. It refuses
existing records, busy or closed worlds, and insufficient entity capacity.
It prepares all identities before publishing any primary slot; a failed
preparation retires the unpublished identities. Other linked actors, pools,
session state and population metadata remain owned by their existing owners.
Existing actor leases survive later World retirement.

The actual clear grants zero secondary history, category override `FAC`,
surface flags `CE2`, and cleared head state. Native fields whose general
defaults are nonzero use the existing source-clear initializer. Resolved
model, geometry and alignment capabilities remain absent until their actual
producers supply them. Generic `Actor` construction does not grant this
bootstrap state.

The clear also establishes zero AI execution and route components. The native
route failure default of -1 is replaced by the source-cleared output link 0.
The source 10AC profile pointer is null: the optional weight profile remains
absent until actual AI initialization selects an authored profile.

Every `actor.slot` remains zero after the clear, including records physically
stored in slots one through seven. The later source producer is `5EB520` at
`5EB598`, which assigns indices over the actual `primary_population` after
its voice-archive and stream-stage preparation calls. The bootstrap helper does not
move that later producer earlier or infer its result.

Paired `primary-actor-records-{gcc,llvm}-v3` comparisons each pass 2,233,691
checks. They execute complete original `66A730` and complete original SDK
clear `107C68` for 64 cases, checking every cleared byte and both outside
guards. The native projection checks all eight canonical Actors, zero
capabilities including AI/route zero and absent profile pointer, distinct
identities, preserved unrelated state, bootstrap-only
refusal, eight capacity rollback profiles, reentry under the actual World
guard, and 512 retained actor lifetimes. No memory-clear observation stub is
substituted for the original SDK routine.

The wider `5EAEB0` caller is also word-audited to establish the clear's actual
startup position, before its auxiliary and linked pool resets. That complete
caller is neither executed nor implemented by this helper. Full startup,
later slot publication, model loading and installed game acceptance remain
separate obligations. The canonical Update adoption test uses this actual
bootstrap before its primary/auxiliary frame traversals.
