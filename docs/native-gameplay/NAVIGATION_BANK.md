# Native room variants and navigation bank

2026-11-10. Qualified component; **Stage4 remains incomplete**. V39 is unchanged.
No game run, live process access, performance measurement or installation took
place for this work.

`gameplay_session::RoomVariants` now owns the128 selected room-variant bytes
used at original4B9D20. Unknown values remain distinct from0. A real initializer
or importer must supply each needed value; the new ordinary script opcode5A
also writes this same canonical Session owner through the real World. It stores
the low byte of its32-bit value. Out-of-profile room indices refuse, rather than
writing outside the owner. The distinct offline5A handler is still unsupported.

The World owns one lazily constructed `gameplay_navigation::Bank` that borrows
its own Session's map. Binding a loaded immutable SGL asset rereads those variants
and selects the last matching descriptor for each room. Occupancy is cleared for
all128 rooms and128 node slots. Four mutable per-actor byte visit masks belong to
the loaded asset lifetime. Rebinding the same asset preserves those visits;
loading another asset starts from its authored initial bytes. Clearing room
bindings does not manufacture a new loaded asset or discard visits. An unknown
required variant refuses binding before changing the previous state.

Script writes change the variant map without silently rebinding an existing
room selection; the original68ECA0 likewise has no bind callback. The real World
composition test exercises the sequence: initial binding, script write, retained
old selection, explicit rebind and changed selection. World closure seals the
bank and rejects further mutation or access. World-dependent programs also
reject a closed World before executing their prefix.

Complete original815E70 mode2, its accessors and8194F0 compare with the native
bank. Clearing an actor's visits clears exactly that mask and removes only its
bit from every occupancy byte; the other three masks and other actor bits are
preserved. Native actor admission is0..3, not a claim that the original validates
its actor index. Mode0/1 setup callbacks and actual resource loading remain open.

Both compilers pass3,354,950 navigation checks, including the earlier nearest/
reverse-action comparisons,327,680 occupancy cells and6,912 visit cells over all
five owned SGL inputs. The current full VM suites pass19,719,138 checks each,
including32,768 direct68ECA0 cases,60 actual ordinary dispatcher cases,4 real
World/bank compositions and7 refusals. Both parent builds and all nine current
integration tests pass. The failed first VM fixture packaging run is retained;
the final run includes and freezes the new fixture. No historical source pins
were used.

Evidence is sealed by
`tools/native_reconstruction/qualify_navigation_bank_v1.py` in
`tools/native_reconstruction/native_navigation_bank_qualification_v1.json`.
`verify_gameplay_navigation.py` and the current full
`gameplay_scenario/verify.py` reproduce the comparisons. The earlier immutable
input qualification remains historical evidence for its own source snapshot.

Next are condition admission through the existing actor AI-control field and
scenario strided flag bank, then cross-room links and route/action consumers.
The whole session initializer, actual SGL load caller, remaining script/action/
AI families, semantic saves and coherent native game installation/acceptance
remain required for Stage4. Renderer submission remains Stage5.
