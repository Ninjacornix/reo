# Ordinary primary roster startup

`PrimaryActorModels::start_roster` implements the complete bounded ordering of
owned overlay function 5EB520, including its 5EB350 model/room phase. The context
borrows the existing World/Update, actor assets, humanoid motion assets, scenario
archive and equipment context. It uses canonical primary EntityIds and the
existing model cache and motion publication owner; it creates no second roster.

The actual 5EB520 slot loop follows voice/background/stream-stage work. It writes
the physical index to each admitted record's slot byte. The earlier 66A730 clear
keeps all eight slot bytes zero. That clear also establishes the numeric zero AI
execution and route components: the route output link is explicitly 0, while the
cleared 10AC weight-profile pointer remains absent. Selecting authored profile 0
requires the real AI initializer.

Startup publishes setup gate 3243D2=2 on entry. Voice requests 1BA440 are reached
only for slots 0..4. Source 1AF6A0 sets the render background; it is not an I/O wait.
Source 5EC3A0 checks the distinct stream-stage byte 3243FE; a known zero reaches the
second background call and 1B0510 before publishing 1. Unknown stage state refuses.

The roster model phase invokes actual native archive model preparation and
initialization for each slot, then applies the owned 70C110 room rows. The four
kind rows have room bytes 1,1,8,27. Network kind 3 indexes by character parity;
other network kinds admit only their four authored entries. A reached out-of-row
read or source uninitialized row pointer is refused after its completed model
prefix. A saved initialization snapshot skips room reads/writes as in the source.
Resident-file loading mode 0 still lacks the actual 377560/3777B0 model route and
is explicitly unavailable after its earlier completed resource prefix.

Source 1D1A80 uses the real immutable humanoid default-bank publication and keeps
old model/motion leases alive. Source 1D1C50 loads the separate room motion table;
it is not the humanoid character overlay loader. The startup does not invent a
1D1B10 overlay call at that location. The actual active-actor 66ACD0/66AC50 phase
sets both elapsed counters to UINT32_MAX, imports the producer's 747400 height,
zeros the gauge/modifiers, preserves the adjacent linked model variant, and runs
canonical AI initialization in mode 0. Scenario NPC and enemy imports use the
existing Update owner and ScenarioArchive.

External consumers remain explicit `PrimaryStartupEffects` operations, including
voice archive activation, background/render submission, 1B0510, all 18DCB0 pumps,
actor resource setup and later scenario resource/script loaders. 18DCB0 calls
18D6C0, 1A0D90 and 18C000; it is not discarded as an ignored getter. There is no
successful default provider. Roster kind 4BADF0 and runtime 747400 heights are
optional producer facts, not invented owned-table literals. Normal completion
clears setup and stream-stage gates. A refusal keeps prior stores, imports,
cache/model publications and gates, and releases only the native busy guard.

Paired `primary-roster-startup-{gcc,llvm}-v2` receipts pass 9,876 checks each,
including 58 complete original 5EB520/5EB350 returns (27 roster profiles and 31
retries), 31 controlled external interruption prefixes, 129 matrix model
applications, 2,515 guard observations, 48 refusals and 36 actor/model lifetimes.
The test-only source interruptions represent unavailable external capabilities;
they do not assert that the original caller handles resource failures by
returning a native status. The complete normal-return comparisons execute the
actual stream-stage, gauge and resource-mode wrapper bodies too. Inherited
model/AI/import helpers remain declared independently qualified source boundaries,
while their actual native owners run in these tests.

`primary-roster-startup-assets-v2/receipt.json` verifies the exact 12 consumed
assets against the pinned File#1 inventory: eight Pxx_00.NBD models, PC_000.BIN,
and r001.npc/e001.emd/sgl_e001.emd. The ordinary clear's separate paired v3
qualification executes actual 66A730 and actual 107C68, passing 2,233,691 checks
per compiler. Snapshot manifests remain immutable. Unrelated top-level native
and scenario CMake drift is recorded in the startup receipts.

Qualification runs without starting the game, submitting audio or rendering, or
performing power actions. Complete original-body and canonical-owner receipts
are recorded separately; this owner alone does not establish full Stage 4.
