# Scene-record eligibility bank and opcode164

The canonical native FlagState now owns the distinct256-bit scene-record
eligibility bank corresponding to the32 bytes at original4BAA30..4BAA50.
It is independent of scenario/secondary flags and the following scenario-owner
tags. Opcode164 executes the complete694390 set-bit semantics through that
owner, with no notification. Both ordinary and offline dispatch tables use this
handler; the offline category/relation gates remain distinct and unchanged.

Program import requires a four-byte payload and an ID below256. Out-of-profile
IDs refuse before program installation; canonical writes also refuse them
without changing state. The original code has unbounded address arithmetic;
native code does not reproduce aliases into subsequent owners. Whole-program
flag-provider preflight occurs before earlier instructions mutate counters.

FlagStateSnapshot includes the typed bank, and its in-memory restore/copy keeps
all bits. No serialized native snapshot/version exists for FlagStateSnapshot;
the legacy gameplay_save::LiveState/container format is separate and unchanged.
Semantic session save/resume remains a Stage4 integration requirement.

Both compiler complete interpreter comparisons pass433,999,075 checks each.
The new cases include16,384 complete original694390 handler calls and5,376
actual ordinary/offline dispatcher calls covering every admitted ID, all five
offline categories and all four room relations. They compare all bank words,
neighboring state preservation, canonical snapshot round trips, no-notification
behavior, invalid IDs, truncated payload and missing whole-program providers.
The five existing CMake parents plus native script-program tests pass on both
compilers after rebuilding.

The actual native Program/closure loader was separately built against immutable
copies of current native source and real CMake native libraries. All171 owned
members are individually hash-checked; both compilers produce identical
before/after results. Native admission remains28 ordinary and23 offline banks.
The first refusal advances in four EVBs and one ordinary RDT; complete scenario
EVBs remain refused:

| Bank | Before164 cut | After164 cut |
|---|---|---|
| r001.evb, both profiles |block1 +3148,164|block1 +3244,166|
| r002.evb, both profiles |block1 +3248,164|block1 +3336,166|
| r028.evb, both profiles |block1 +1960,164|block1 +2040,166|
| r035.evb, ordinary |block1 +2612,164|block2 +156,150|
| r035.evb, offline |block1 +2612,164|block1 +2620,1A1|
| r041.evb, both profiles |block1 +4844,156|unchanged|
| r0283000.rdt, ordinary |block8 +400,164|block8 +508,094|

These offsets are relative to the table block, unlike absolute prefix-model
offsets in the integration audit. The native closure also validates records
encountered during conditional scans. That is why r041's first refusal is156
although the conservative executed-prefix model encounters164 first. Neither
result establishes runtime reachability or complete native scene/game ownership.

The [qualification record](../../tools/native_reconstruction/native_scene_record_eligibility_qualification_v1.json)
links the frozen full-interpreter and owned-program receipts. Opcode165's clear
and matching descriptor-control retirement, actual eligibility consumers,
remaining opcodes/providers, session/cinematic owners and installed acceptance
remain open.
