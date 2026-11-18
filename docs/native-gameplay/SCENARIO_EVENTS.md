# Canonical countdown scenario events

Opcode D1 now constructs its actual kind6 countdown event through the sole
`Update::Owner::scenario_events()` factory. It uses Update's existing three
banks of ten `EventTasks`, the same `FlagState`, and the eight canonical
`FlagTimers`. It adds no second task pool, flag bank or timer counter bank.

The complete691010/5B92B0 bodies select bank0 unless actual1B02D0 reports
mode0, in which case the selected actor chooses banks0..2. An out-of-range
selection returns before payload access. An occupied active slot returns
without clearing or overwriting it. An inactive admitted slot is cleared,
initialized and receives all five full argument words. Kind6 is the only
admitted callback family because it covers every D1 record in the five owned
EVBs; other callback families remain explicit unsupported profiles.

Bank0 calls actual5BA470. Its enable, alternate-counter and blink selectors
read primary-local flag bank0 (`4B9A80`), distinct from shared scenario flags.
The callback retires a disabled event through5B93B0, initializes its style and
phase, and registers the HUD only when the canonical inventory owner byte is
zero. Alternate banks use actual5BAED0, which tail-calls5B93B0 and retires the
record on its next update. It is not a return-only callback. Update uses the
already-qualified ascending physical event pass and preserves its canonical
selection transitions.

`present_timer_hud()` consumes the actual registered event and canonical
timers. Complete5BA530/5BA8D0 semantics produce typed20-byte sprite packets:
minute/second/hundredth decomposition, glyph positions/regions, color, signed
pulse arithmetic, and the positive hidden-counter early return. The latter
retains the presentation request and skips restore/acknowledgement. A normal
frame acknowledges the request. GPU texture translation and packet submission
remain the Stage5 boundary; no renderer callback performs gameplay via MIPS.

Whole-program admission validates kind, physical slot and bounded selectors,
requires a factory bound to the same World, and refuses a missing, foreign or
closed owner before any script prefix. Update injects its canonical factory;
NativeSession publishes the same owner. Script replacement does not destroy
already constructed event tasks. Factory close unregisters and retires its
own records before Update seals its child stores. Arbitrarily externally
disabled generic tasks do not establish the original clear/unregister
contract and therefore remain an explicit refusal.

The independent HUD comparison passed8,847,393 checks and720,899 cases on
each compiler. The complete factory, task loop, retirement and presentation
comparison passed224,527 checks on each compiler, with96 mode/selection/slot
cases,2,592 scheduler passes,2,784 presentations,1,960 registrations and172
unregistrations. It compares all272 bytes of every one of the30 source event
records through a test-only semantic projection. The fixture deliberately
opposes local-primary and shared-scenario flags to verify the bank identity.
Original bodies, callback/glyph tables, native sources and borrowed real
CMake archives are retained and hashed in the private cohorts.

The final full interpreter pair (`scenario-events-vm-{llvm,gcc}-v2`) passed
569,132,415 checks per compiler, including144 ordinary/offline programs with
288 authored D1 commands and the canonical Update caller. It audits12,169 owned instruction
comments. The current28-parent pair passed without drift, including the
dialogue response/cache contracts and pose callbacks. The actual all548
descriptor light test also passed on both compilers through current
NativeSession/SessionRooms/Lighting. These are exact captured cohorts; later
independent component changes require their own final combined checks.

The original-code tests caught the alternate-bank retirement and the phase2
reset before final qualification. Earlier failed snapshots and the original
full-VM link-gap cohort are retained. No game, UI or audio device ran.

The real admission pair advances ordinary `r001.evb` from block2+3420/D1 to
block2+3600/EE. All five EVBs still refuse complete admission. The171-bank
inventory remains34 ordinary and27 offline admitted banks. All offline EVB
frontiers remain1A8. `audit_scenario_opcode_frontier.py` records every authored
role0 instruction, rather than treating the first frontier as the complete
remaining work:

| Ordinary unsupported opcode | Authored instructions across five EVBs |
|---|---:|
|60|14|
|63|2|
|64|1|
|6C|8|
|D0|8|
|EE|8|
|106|2|
|108|1|
|132|1|
|151|4|
|153|18|
|169|8|
|172|2|

These77 instructions use13 distinct opcodes among4,837 encoded role0 records.
They include conditional and potentially unreachable records; this is static
authored coverage, not observed runtime reachability. Offline additionally
contains333 unsupported instructions in its distinct dispatcher profile.
Native frame terminal services, actual host installation, platform input,
transport/media ownership and semantic saves remain Stage4 acceptance gates.
