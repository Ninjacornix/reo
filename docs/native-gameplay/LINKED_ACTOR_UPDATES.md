# Native linked actor updates

The canonical Update Owner now adopts the admitted6BBBA0 linked actor pass.
It uses the actual World-owned fifty-node pool, Session clock and expanded
enemy descriptors. The current callback admission is the native scripted
6BA880 family; other required active callbacks return unavailable. No original
function pointer, MIPS context or guest RAM exists in production.

The pass walks live links from tail to head, clears descriptor R45 mask10hex
before each active callback, then performs the additional native pose rebuild
unless targeting C94 mask4 suppresses it. First-use C8B initializes the previous
collision-center cache by transforming the local center through the direction
basis. Translation is excluded. Every visited actor, including inactive ones,
has transient marker C98 cleared. The first differential cohort caught the
inactive branch omission before installation. Fresh pool allocations now own
known-zero frame state; scripted construction also supplies known targeting
state from the original cleared allocation.

The countdown starts at5, extracted from owned o0 byte37FD80. Only a change in
the simulation clock's seconds byte decrements it. Counter arithmetic wraps
through a signed byte before testing; positive results defer expiry, otherwise
the countdown resets to5. A seconds jump counts once. This adds no wall clock,
catch-up ticks or game-speed change. Every invocation clears the four source
work counters and publishes the clock-mode factor1/2.

Every periodic pass visits the canonical256 expiry bytes. FF is disabled;
decrement1 expires toFF and emits a notice, while decrement0 wraps toFF without
a notice. Publication requires message phase1/2, owner_mode other than1 and
route mode0/1. The actual StatePublication owner sends a typed ActorExpiryMessage.
A missing or failed sink increments publication_failures and simulation
continues. This records failure rather than claiming delivery.

Source5A74F0 initializes packet bytes0=49hex,1=6,3=ordinal,4=FF, then routes
through the complete1AFDD0 body. Bytes2 and5 are uninitialized. Native messages
retain initialized semantic fields and do not treat those bytes as a wire
contract. The initial observation fixture placed ordinal at byte2; its first
positive expiry case rejected that projection and it was corrected. The
transport owner still needs actual framing, admission and receiver migration.

Ordinary workers invoke this owner at Worker::scenario_actors when bound.
Unbound owners retain the existing required worker port. Cinematic code can
explicitly invoke the same joined owner without committing the gameplay clock
or running unrelated tasks. Ordinary paused workers still skip it. Binding
rejects foreign/missing ownership and duplicates; reentry and closure during
publication report busy. Closing removes the registration before World teardown.

Both compiler World comparisons pass1,635,380 checks with7,469,778 original
calls. New coverage includes768 composed callback cases,512 expiry cases across
all signed countdown patterns and all256 TTL patterns, and eight full pools
with400 actors, mixed head/tail insertion and active/inactive branches. Actual
original callback order matches canonical live links. Three ownership/profile
refusals remain explicit. Model, animation, movement and pose comparisons remain
in the same current-source cohort. Five parent gameplay tests pass on each
compiler, including actual Update clock authority, pause, failed publication,
reentry, closure and a real cinematic movement callback. Owned asset/construction
regression passes5,681 checks and330 real constructions on each compiler.

Reproduce using animation/verify_world_playback.py, verify_actor_assets.py and
the native actor-assets, target-metrics, collision-workers, cooperative-events
and AI-owner CTest entries. Use fresh output directories and the owned corpus.
The qualification records exact source/build hashes and full scenario regression.
No game was launched and no new speedup was measured. Scene bank loading,
cinematic lifecycle callers, other active callback families and game installation
remain open. Step4 remains incomplete and the PC stays awake.
