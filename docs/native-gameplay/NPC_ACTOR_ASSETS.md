# Primary substitution and auxiliary NPC actor assets

The original v1 evidence below qualifies **primary-character substitution**
through 1AA740, not auxiliary NPC construction. Connecting that route to
6837C0 in the first constructor implementation was incorrect. The corrected
API names it `read_substituted_model`; actual NPCs use `read_npc` with the
resident 1D0800 / 1CD710 / 1CD340 route described below. Historical v1 receipts
remain valid for their filename and payload comparisons, but do not establish
the mistaken NPC-constructor association.

ActorAssets supplies actual File1 substituted N and HP model bundles through its
existing immutable asset/skeleton cache. Source1AA740's nonzeroBB4 filename
routes select N(BB4-1), with minimum two decimal digits, or HP(character) for
definition1. The BB4==0 primary/appearance path remains a separate owner and
is explicitly refused by the primary substitution API.

The full owned ROM alias table identifies133 actual members:125 NPC bundles
and eight HP character bundles. Lookup uses their exact AFS ordinals and checks
the common archive's1342-entry profile and member name. A duplicate HP03 display
basename is not treated as an identity or arbitrarily selected. Native ordinal
lookup and the ordinary/alternate name routes share one member cache;11 actual
NPC bundles are also reached by ordinary actor definitions. Each mutable model
instance remains independent.

Seven actual NPC skeleton sections have length metadata6552 while their25
complete records occupy6460 bytes. Their record-count/tree traversal matches
the complete original1A2E00 and helper bodies, which select records by count and
record sizes. The explicit SkeletonExtent::bounded_records profile validates
that traversal within the supplied section and requires exact physical record
consumption. It never pads missing bytes or rewrites an asset. The ordinary
declared-extent importer keeps its existing strict contract.

Both compiler asset cohorts pass201,260 checks, including66,815 filename cases
executed through the complete source-word-audited1AA740. Its actual owned
formatting literals are used; file acquisition is a declared failed-read
observation port. Native retained archive reads run separately in the same
executable and verify all133 payloads against independently indexed, pinned
member hashes, skeleton node counts and590 model parts. All133 independent
model instances publish their initial poses. Baseline406-model/330-construction
owned tests retain their5,681 passing checks, and all nine parent CTest entries
pass on both compilers.

Both current World cohorts pass2,654,203 checks and7,731,483 original calls.
New skeleton coverage compares all133 real forests and5,023 nodes, including
all seven oversized length metadata cases, against original initialization and
pose rebuilding. It also rejects266 truncated inputs and verifies that the
generic declared-extent profile still rejects those seven noncanonical headers.
Existing World, animation, movement, cutscene command/track and descriptor
comparisons remain in that same current-source cohort.

Reproduce using generate_npc_actor_members.py, verify_npc_actor_assets.py and
animation/verify_world_playback.py with --npc-assets pointing at the completed
asset receipt/package. Use explicit compiler/CMake/build/data-root arguments,
the pinned owned descriptor/animation corpora and fresh output folders. The
evidence seal is native_npc_actor_assets_qualification_v1.json. The first compiler
attempt exposed missing register helpers in the test-only original scaffolding;
the failed receipts remain preserved and both corrected cohorts pass.

NPC state construction through the ten-actor pool, actual motion/head/attachment
ownership, scene assignment/callback scheduling, installed native gameplay and
complete Step4 acceptance remain open. No game was launched, and this asset
qualification does not establish a measured performance improvement.

The corrected auxiliary route uses the low byte of the NPC model identity
without subtracting one. Model class 1 selects `HN%02u.NBD`; other classes
select `N%02u.NBD`. Width is a minimum, including three-digit identities.
Class 1 therefore does not select a primary `HP` character bundle. Full resident
source-word audits cover 1D0800, 1CF300, 1CF090, 1CF320, 1CD710 and 1CD340.
The resident loader distinguishes model and texture prefixes. Only model content
is admitted here; texture/material submission remains part of the renderer
boundary. Alternate `_N` model selection is not enabled by this default
constructor profile.

`generate_auxiliary_actor_members.py` reproduces 233 exact auxiliary aliases:
125 N members and 108 HN members. Their union contains 149 model identities.
The native reader checks exact ROM ordinal, archive cardinality and display
name, then uses the same retained immutable cache and bounded skeleton reader.
All 246 kind-1 headers in the supported scene inventory select an existing
member. Missing combinations fail explicitly; N88 does not fall back to HN88.

Both corrected compiler asset cohorts pass 988,863 checks. They compare 262,144
auxiliary filename selections against complete original 1CD710/1CD340, across
the 16-bit input domain, four model classes and ten slot namespaces. The low-byte
narrowing is independently source-audited in 1D0800. All 233 actual auxiliary
payloads, skeleton counts, model parts, independent instances and initial poses
are verified. The previous 66,815 primary substitution filename comparisons and
133 payload checks also run in the same executable. Nine parent tests and the
existing 406-model / 330-constructor regression pass on both compilers.

Corrected receipts are `auxiliary-actor-assets-{llvm,gcc}-v1`. Native construction
uses definition profile v3 and is described in NPC_ACTOR_CONSTRUCTION.md. Full
scene ownership, motion content, native game installation and Step 4 acceptance
remain open. These are offline checks, not measured gameplay improvements.

Current corrected World cohorts additionally compare all 233 auxiliary forests
and 12,475 nodes against original initialization/rebuilding: 2,687,826 checks,
7,989,320 original calls and 466 truncated-input refusals on each compiler.
See CUTSCENE_NPC_CONSTRUCTION.md for scene composition and its remaining gates.
