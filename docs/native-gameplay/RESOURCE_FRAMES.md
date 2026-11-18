# Native resource frame consumers

`ResourceFrames` implements primary resource visibility/ownership updates and
weapon WMD playback using the canonical World, SceneResources and ResourceModels
owners. `CommonModelWork` and `WeaponModelWork` are actual native update consumers
for the existing 64-model pass; they contain no guest addresses or CPU context.
This component is not installed in the game and does not close Stage 4.

The common callback preserves inactive-model early return, the sign-bit visibility
flag, signed ownership-tag conversion, the four primary actors, owner status
retirement, room/visibility filters, selected/nonselected filters and the owner's
surface-material draw layer. Releasing an active descriptor retires its actual
primary model through the existing owner and clears the descriptor attachment
flag. Secondary attachments remain an explicit missing consumer at this checkpoint.
Extended actors, room-pulse queries, required reconstruction and the nonattached
1904A0 pose variant also refuse when reached. Their meaningful no-action gates
are preserved; an unavailable required operation is not treated as successful.

Weapon playback preserves six part programs and all seven completion bytes,
phase-zero reset, other-phase no-op, empty parts/curves, per-scalar completion,
signed 16-bit time wrapping and exactly two ticks per invocation. A finished
scalar contributes zero on later updates while unfinished channels continue;
a fully finished part retains its previous matrix. Part matrices preserve all
four W lanes. The static-base translation extraction in the original callback
is unused and is not added to the curve's translation. Base copying under the
owner status gate uses a supplied immutable, asset-identified set of up to six
poses. These controlled pose inputs are not a claim that NBD asset loading has
been migrated. Replacing the actor's bank behind an existing selected program
is an explicit invalid binding, rather than a native raw-buffer alias.

The comparison driver executes complete owned 5932F0/6B45C0 bodies, the original
WMD selector/sampler, resource allocator/retirement and required matrix helpers.
The source's unit-axis initialization and static-pose table are explicit fixture
surroundings. Actual owned WMD bytes are independently extracted and hash checked.
The original CPU context and synthetic RAM exist only in this oracle.

Each compiler checks 20,818,529 assertions, 207 common-update cases, 2,013 weapon
cases and 190,464 consecutive playback frames. Fourteen cases additionally vary
static-copy counts from zero to six across reset/other phases. Fifteen native
safety/refusal cases cover foreign/retired owners, unsupported callback branches,
missing or mismatched pose assets, required bank bindings and secondary release.
The actual native ResourceModels update also executes weapon work that retires
its current model, with the resulting pass compared to complete 590EA0.
Both parent libraries and four existing World/contact integration tests pass.
Exact frozen sources, original word audits and all outputs are bound in
`native_resource_frames_qualification_v1.json`. Failed fixture/build cohorts are
retained separately; they are not successful comparison evidence.

Factory construction, real asset loading on weapon changes, remaining callback
families, shared secondary release, game installation and representative gameplay
acceptance remain open. No game run or performance improvement is claimed.
