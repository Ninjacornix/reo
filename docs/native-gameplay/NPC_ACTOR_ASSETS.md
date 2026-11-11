# Native NPC and HP actor assets

ActorAssets now supplies actual File1 NPC and HP model bundles through its
existing immutable asset/skeleton cache. Source1AA740's nonzeroBB4 filename
routes select N(BB4-1), with minimum two decimal digits, or HP(character) for
definition1. The BB4==0 primary/appearance path remains a separate owner and
is explicitly refused by this NPC API.

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
