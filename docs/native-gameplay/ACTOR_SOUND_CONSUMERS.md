# Native actor sound consumers and projectile parent variants

Status: bounded source/native owner contracts. No game, audio device or power
action was used; Stage4 and installed native gameplay acceptance remain open.

`CanonicalActorSoundOffsets` reads the existing optional33 program byte from
canonical actors. `CanonicalProjectileParentVariant` reads the existing optional
CF2 byte. Both reject foreign/stale IDs and unknown metadata. The actual full-record
clear producers are documented in[ACTOR_SOUND_STATE.md](ACTOR_SOUND_STATE.md).
These readers introduce no new mutable metadata tables.

`CanonicalActorOffsetSound` supplies1B9310's real554/33 gate, then the existing
bank12 `gameplay_audio::Owner` spatial/RNG/routing/PCM path. Unknown metadata
refuses; the known00/00 pair returns without audio.554's outer gate value is
not a fabricated bank/program:1AC7F0 overwrites that incoming argument.33 is
the actual program tag. The frontend retains the native result, including ignored
or unavailable audio outcomes. Existing packed actor audio can borrow the same
canonical33 reader.

Both compilers pass the complete1B9310 gate over all65,536 metadata pairs and
four full-width event profiles:262,144 cases,1,048,569 checks. The separate
owned-audio contract passes65,792 original frontend cases and460,732 checks
per compiler, comparing two independent native audio/RNG owners and actual
weapon01.snd data. It observes52,842 matching nonzero PCM channel values.
The independent256-event control renders2048 frames per request: a64-frame
window was too short to establish nonzero audio, and the earlier failed cohorts
are retained. No synthetic tone replaced the actual asset.

With actual known-zero clear metadata, all six owned effect-bank contracts now
complete the splitting arc's sound gate, four real descriptor7 child allocations,
same-pass continuation (five callbacks), and all child retirements. The six cases
require78 subsequent pool passes in total. The actualCF2 reader and retained
linked-pass quantum also admit the variantFF timed-projectile initializer.
Generic and small pose actors still have unknown metadata and refuse.

Receipts: `actor-offset-sound-policy-{llvm,gcc}-v1` and
`actor-sound-ownership-{llvm,gcc}-v5`. The latter use the matching current
projectile-owner source/archive graph, including the enlarged immutable visual
output. Earlier Actor/visual header layouts are not overlaid on those archives.

Actual nonzero population metadata assignment6BB040/1B92B0/1B92E0, copy-family
producers such as58EE50, changingCF2 attack producers and application audio-host
adoption remain separate requirements. Controlled metadata inputs are not a claim
that those larger gameplay functions are complete.
