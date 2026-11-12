# Ordinary actor voice archives and requests

`ActorVoiceArchiveAssets` indexes the eight owned actor archives inside File #1
`NETBIO01.DAT` → `adxsnd.afs` → members 401–408 (`vo00100.afs` through
`vo00107.afs`). Each archive has 1,000 members. The audit verifies every ADX
member's name, length and SHA-256 against the pinned File #1 asset inventory.
Immutable bounded member views retain their actual source; no archive payload is
copied into a second catalog or actor state.

`StreamAssetCatalog::add_actor_voice_archives` atomically certifies those eight
indexes before sealing. The existing `StreamInstances` owner holds the five
ordinary loaded selections, initially unavailable. Complete original 1BA440
stores **character + 1** in 4BAE71[slot], rather than the SDK archive lookup index
plus one. Characters 8–255 are proved filename misses and establish a known zero.
An unavailable native catalog preserves prior state and returns `unbound`.
Slots 5–7 are the original no-op in the actual 5EB520 startup profile. Complete
1BA330 clears exactly five selections; it does not establish the separate NPC
marker at index 5.

`ActorVoiceStartupEffects` supplies the real archive operation to the existing
5EB520 `PrimaryActorModels::start_roster` path and delegates its other explicit
operations to the supplied owner. It preserves source ordering: archive requests
precede background work, slot assignment and model construction. A refused
background operation leaves the successfully activated prefix intact.

`ActorVoiceRequests` implements complete 1BA250 for ordinary actors. It borrows
the same World, explicit StreamChannels, backend, camera/listener context and
canonical audio tick. A negative member returns before resolving the actor;
unknown loaded capability, busy stream admission or missing clock never
manufactures success. The source phase gate admits phases other than 1 and 2.
The request uses the already qualified 1BA170 stream logic and actual native
spatial attenuation. A reused paused request returns zero without a new spatial
volume update, as the source does. There is no invented active/visible gate.
The NPC/common archive selection remains unavailable until its actual producer
is adopted. NativeSession's SceneChannels bitmask is a different owner from
StreamChannels; the caller supplies one explicit stream owner.

`verify_actor_voice_archives.py` compares complete word-audited 1BA440,
1AB450, 1AB2F0, 1AB050 and 1BA330 against actual native archive selections.
SDK archive open/poll and bounded standard string operations are declared test
boundaries. Both compilers pass 3,285,213 checks, 2,048 native activations and
2,050 complete original cases, including unknown versus missing capabilities,
busy admission, exact five-byte clearing and retained member lifetimes. These
tests start no decoder source and open no audio device. The first GCC fixture
failed because its synthetic attenuation table had an invalid zero first word;
the failed snapshot and log remain preserved.

`verify_actor_voice_caller.py` compares complete 1BA250, 1BA170 and their reached
stream bodies against real canonical actors and channel snapshots. Controlled
SDK output primitives expose ordering and intermediate state; disabled feature
flags and the separately qualified 1B94B0 spatial boundary are explicit. A
second concrete request uses the real StreamInstances backend and an owned ADX
member, advancing its actual source worker and decoder without an audio device.
The paired caller fixtures compare 192 complete original returns, 1,825 source
calls and 4,353 checks; the concrete decoder copies 640 samples in the sealed
cohort. Three prefix refusals include busy startup, background refusal after
archive publication, and a missing request tick after the source phase query.
The startup bridge uses a canonical NativeSession and SessionStartup; remaining
render/resource operations are declared test surroundings. This is not a full
authored launch or proof of the complete dialogue state machine.

The next actual frontend is overlay 6B97D0, called by 6B9590. It owns separate
0x98-byte dialogue records at 74DD40 (16 entries, actual 6B7810 clear and 6B7890
allocator), text buffers and UI presentation operations. Its actor pointer is
record +0x5C and voice member is +0x58. Its three 1BA250 call sites do not justify
inserting voice requests into an unrelated animation callback. Those record
producers and presentation dependencies require their own complete adoption.
