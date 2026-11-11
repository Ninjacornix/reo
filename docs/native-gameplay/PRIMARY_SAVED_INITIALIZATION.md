# Native saved primary initialization override

`gameplay_save::decode_primary_start_snapshot` reads the three fields consumed
by 66A750 from the actual legacy second-section encoding: signed health, class
marker and selected equipment. It decodes all eight source slots into native
typed records and refuses a section whose size differs from 0x7000. Remaining
serialized fields retain their existing codec ownership. No process-memory
reader, register context or original pointer enters this decoder.

The canonical Session owns an optional typed initialization snapshot. Presence
enables the imported override; a fresh Session has none. Parsing a save does
not enable a resume, infer the unrelated saved-header flag, or publish to a
running World automatically. The actual resume/scene owner must decide when to
adopt or clear it. This is a bounded semantic save consumer, not a full native
world snapshot implementation.

`initialize_primary_slot` applies the override after default/custom statistics
and before health-class derivation. It preserves maximum health, assigns the
three source fields and derives the equipment action through the canonical
descriptor/template owners. `SceneResources::action_kind` supplies complete
5B4D50: narrow the logical slot to a byte, return zero for inactive or FF
template entries, otherwise read the signed template action. The actor's
zero-equipment branch returns zero without consulting those owners, matching
5F1F70. Signed action values retain their source halfword representation.

Missing required equipment owners, or a template outside the admitted native
table, report unavailability after the preceding saved-field stores. The policy
does not claim completion or discard that prefix. The default-only API refuses
an enabled override before changing the actor; callers use the explicit slot
initialization API for this profile.

The qualification composes actual primary models and motion assets with
constructed descriptor/template assignments, rather than claiming those test
assignments were observed in a game. Comparisons execute complete owned 66A750,
5F1F70 and 5B4D50, including signed health and action values. The existing
constraint and selector-zero RNG observations remain declared boundaries.
Actual native save encode/decode/second-section restoration exercises the same
typed decoder without accessing or changing any player save file.

Both compilers pass 37,637,875 initialization checks, including 65,538 decoded
snapshots, 65,536 saved initializations across all signed health values,
65,792 descriptor queries and nine explicit size/provider/template refusals.
The previous default, custom, restore and setter cases remain in the same
cohort. Every signed action byte is checked, including the actor's independent
zero-equipment path. All fifteen parent tests pass. Current World cohorts also
pass 2,799,371 checks / 8,216,138 complete original calls on both compilers.
The current paired behavior regression passes 32,768 cases as well.

Reproduce with `verify_primary_actor_initialization.py --custom --saved`,
explicit compiler/CMake/private build/data-root paths and fresh output folders.
Receipts are `primary-saved-initialization-{llvm,gcc}-v2`, current World evidence
is `primary-saved-world-{llvm,gcc}-v1`, and the combined seal is
`native_primary_saved_initialization_qualification_v1.json`. The initial v1
fixture failed to compile because adjacent hexadecimal `e+` text formed one
preprocessing number; adding operator whitespace fixed that fixture.

The [branch-selector follow-up](PRIMARY_INITIALIZATION_SELECTOR.md) now supplies
the actual notification/pause decision over native Update state.
Actual resume enabling, primary model reuse/
release, scene lifecycle adoption, a semantic snapshot for the rest of the
World, coherent game installation and every other Step 4 gate remain open.
The installed game is still V39. No game was launched.
