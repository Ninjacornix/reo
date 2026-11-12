# Script actor-room predicates and offline AI profile selection

Opcode `150` now uses canonical World actor activity, status and room through
complete `693300`/`666080` semantics. Selector 4 aliases the selected primary;
other admitted selectors address physical slots 0–7. The room argument narrows
to an unsigned halfword. A nonzero final word requires an active actor without
status bits `5E0` in that room. A zero final word negates the **entire** match,
so inactive, retired and status-excluded actors also satisfy it. A failed
condition preserves the actual nested/else scan and condition-depth behavior.
An out-of-domain actor selector is an explicit native admission refusal.

Offline opcode `1A1` executes complete `702650`: mode zero selects a physical
primary slot, with no selector-4 alias; every nonzero mode scans the canonical
unsigned Session primary population and selects every matching character.
Only active actors with nonzero `ai_control` invoke the actual existing
`gameplay_ai::select_weight_profile` owner of complete `8123E0` behavior.
The ordinary binding remains its original no-op. The AI primitive is shared
through the dedicated `reo_native_gameplay_ai_execution` CMake target; its
implementation and authored profile table are unchanged.

Profile arguments are signed words. Values 20 and above preserve the source
no-op without requiring an ExecutionState. A candidate actor requiring a
profile below 20 must have its real ExecutionState; negative profile pointers
remain outside the admitted native content extent. Missing or excessive
population refuses character scans. Whole-program preflight validates these
current capabilities before earlier script effects, and each command checks
again at execution. Missing native primary generations are inactive slots.

Both immutable full-interpreter comparisons pass **564,346,033 checks** each:
4,096 actual ordinary/offline room-predicate dispatches, 5,880 actual offline
profile dispatches and seven explicit admission/provider refusal cases. The
room fixtures vary each actor separately and cover all eight selected-slot
alias destinations, positive and negative conditions, nested conditions and
else scanning. Profile cases cover every physical slot, character scans,
noncanonical nonzero modes, zero/partial/full populations, activity/AI gates,
unchanged execution fields and weight banks, signed negative refusals and
large no-op profiles.

Complete original `693300`, `666080`, `702650` and `8123E0` execute alongside
the actual original dispatchers. The qualifier verifies 11,292 original
instruction comments against the owned images, including the separate owned
AI overlay, and retains all twenty 56-byte profile rows. Memory copy and zero-fill library
calls remain declared oracle ports; they are not production AI providers.
The independent [AI execution proof](AI_EXECUTION_STATE.md) qualifies the shared
primitive itself. Both current CMake cohorts pass all 14 parent tests with no
recorded source drift, including the AI target split and compilation of the
separately qualified cinematic playback owner.

All 171 hash-verified owned script banks are checked through actual native
Program admission against baseline `17fc84d7`. Full admission remains 31
ordinary and 26 offline. All five EVBs still refuse later unsupported commands:

| EVB | Ordinary next refusal (block, offset) | Offline next refusal (block, offset) |
|---|---|---|
| r001 | `170` (2, 1748) | `1A5` (1, 3444) |
| r002 | `156` (1, 3480) | `156` (1, 3480) |
| r028 | `108` (2, 288) | `1A5` (1, 2216) |
| r035 | `D0` (2, 212) | `1A5` (1, 2668) |
| r041 | `156` (1, 4844) | `156` (1, 4844) |

These are complete-import refusals at block-relative positions, not observed
runtime execution. Coverage is 360 ordinary and 333 offline table entries,
including original no-ops. The [qualification record](../../tools/native_reconstruction/native_actor_script_commands_qualification_v1.json)
retains the exact VM, admission and parent receipts. The later cinematic
close-reentrancy guard and stream-adapter work have separate source snapshots.
No installed native gameplay, complete session bootstrap, semantic save
adoption or Stage 4 completion is claimed.
