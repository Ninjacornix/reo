# Native auxiliary resource lists and inventory transfer

Status: qualified on both compilers; uninstalled. Stage4 is incomplete.
InstalledV39 is unchanged. No game or physical audio device was launched.

The canonical Session now owns the first four eight-ID auxiliary lists from
4BAC52, independently of live actor inventory and entity lifetime. The native
facade admits primary indices0..3 after the original signed-low8 conversion;
negative and extended indices refuse. It does not model neighboring globals or
guess an arbitrary-memory continuation. List IDs are native logical resource
slots, not guest pointers. Save/load and other list producers remain required.

5B5F10 retains active existing entries without owner checks, grouping them by
the actual template byte15hex. Eligible new input must be active, lack template
flag40 and match owner(index+1). It clears each accepted claim and appends without
deduplication. Each group holds at most eight; final emission orders groups3/2/1/0
and stops after eight total IDs. Accepted count and claim effects include inputs
later truncated from that output. No accepted input means no list rewrite.
Unknown groups or a missing bounded input refuse while retaining preceding claim
effects; they do not invent entries or roll back.

5B6180 removes every matching nonzero ID before testing activity, then rebuilds
only if a match existed. Absent matches preserve inactive original entries.
5B6300 always rebuilds from active entries and returns the emitted count. The
original code's twelve-entry emission limit cannot overflow an eight-entry
valid input here: removal leaves at most seven survivors, regroup at most eight.
Neither operation changes descriptor ownership, destroys resources or deduplicates.

The actual5F6800 actor caller uses those lists and the existing resource-frame
release owner. It requires category0 and retains the distinct mode0/local,
mode1/nonlocal and other-mode bypass rules. Selected equipment is detached before
the already-transferred02000000 and first-slot gates. The flag is committed before
testing only carried0/storage0; a later nonzero slot does not bypass this gate.
Carried IDs are submitted first, then all32 storage IDs only for character6.
Both inventory banks clear after handling even when no IDs were accepted or when
the non-character6 storage bank was not transferred. Mode!=1 then sets the same
canonical D92 bit2000 without changing the existing notice payload bytes.

These mechanics are preserved from the original. The auxiliary lists' exact
original gameplay name and all later recovery consumers remain separate evidence.
The caller is a required dependency of terminal/gauge transitions; this component
does not itself complete those transitions or install native gameplay.

Both compilers pass582,692,210 combined assertions with identical observations.
New coverage includes294,912 direct append/remove/regroup cases over all five
owned ITEM sections plus a controlled grouping/flag bank,393,216 actor-transfer
cases,48 actual primary/shared-secondary model-retirement cases, one explicit
32-accepted/eight-emitted case and eight refusal/lifetime groups. The32-byte
session-list span has unchanged source guards. All89,072 source allocations and
releases balance in the combined resource suite. Prefix checks cover a short
bounded input after an accepted claim and an extended actor after the earlier
transfer flag; list state also survives actor retirement.

The first build caught a conflict introduced by the preceding clock work: the
shared test context and several generators both added HI/LO. The shared header
is restored, and only the cooperative generator now adds its required fields.
Current clock/message/hit comparisons pass70,212,138 assertions per compiler
with unchanged observations. Existing immutable source snapshots and seals are
retained. No production runtime/register machinery was added by this repair.
Both parent builds and all eight integration tests per compiler pass. Exact
identities: `native_resource_auxiliary_lists_qualification_v1.json`.

Other auxiliary-list producers/consumers, semantic native save/load, terminal and
periodic-gauge transition binding, coherent game installation and representative
acceptance remain open.
