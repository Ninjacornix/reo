# Script actor predicates and AI counter command

Opcode `156` now composes the complete `693920` predicate with canonical World
actors, authored population and FlagState. Mode zero selects a physical primary
slot, with selector 4 aliasing the selected actor; mode one selects the first
character match within the full unsigned population. Character lookup includes
inactive rows. Missing matches and other modes fail the condition. Missing
native actor state or an unknown/excessive population refuses admission.

The original eight-entry table at `7408F0` selects these queries:

| Query | Actual predicate |
|---|---|
| 0 | Actor slot equals the full parameter, or parameter bit31 selects its low-four-bit mask. |
| 1 | Character equals the full parameter, or parameter bit31 selects its low-eight-bit mask. |
| 2 | Motion style equals the full parameter. |
| 3 | Actor is inactive/status-excluded; parameter 1 also includes status bit8. |
| 4 | Active, status-admitted actor room equals the **full parameter word**. |
| 5 | Canonical scenario owner tag equals the full `actor.slot + 1`, without byte wrap. |
| 6 | Status bit20 in world mode0, otherwise status bit100. |
| 7 | World mode0 and nonzero AI control. |

Mask shifts retain the source low-five-bit shift count. Status exclusion is
complete `666080`: inactive or any status bit in `5E0`. The fifth argument
compares the complete word against the zero/one predicate result, so values
other than 0/1 fail. Unknown query indices retain a zero result before that
comparison. Missing actor selections instead fail unconditionally. The room
comparison deliberately differs from opcode `150`, which narrows its room
argument to a halfword. Only query5 requests the canonical flag provider, with
the existing 512-tag native extent. Nested/else scan behavior remains owned by
the real Interpreter.

Offline opcode `1A5` executes complete `702A60`: inspect all eight physical
primary slots, independently of authored population, and update only active
actors with nonzero AI control. Each matching actor must already own a real
ExecutionState. Its existing `action_counter` becomes 1 only when the **full
payload word equals 1**; every other word stores zero. Other execution fields
remain unchanged. The ordinary binding remains its original no-op.

Both operations participate in whole-program capability preflight before
earlier script effects, then check their actual state again when executed.
No status query, callback stub, duplicate AI state or guest-memory projection
implements these production commands.

Both fully rebuilt immutable VM cohorts pass **565,098,958 checks** each,
including 58,432 actual ordinary/offline predicate dispatches, 2,560 actual
counter-command dispatches and eight explicit provider/admission refusals.
Complete original `693920`, `666080`, `702A60` and mode getters execute with
the actual dispatchers and exact eight-entry query table. The qualifier checks
11,486 instruction comments against the owned images. Fixtures vary each
physical actor, test high slot/mask values, inactive first character matches,
both world-mode families, every query/default, full expected words, unchanged
execution fields, ignored population for `1A5` and prefix protection on refusal.

Both current CMake cohorts pass all **16 parent tests** with no recorded source
drift, including the model/postprocess worker adapters, cinematic prepared
stream/controller integration, AI execution target, world, construction,
archive, script, collision and cooperative/AI update. These snapshots include
the cinematic close guard. The later auxiliary postprocess/bootstrap forward
and friend declarations are recorded as subsequent `World.hpp` drift in the
immutable admission receipts; no fields or behavior changed in that diff.

Actual native Program admission compares all171 hash-verified owned banks
against baseline `368b653d`. The before implementation and admission probe
compile against that baseline's own Program header, preserving its signature
and object layout. Full admission remains31ordinary/26offline. All five EVBs
still refuse later unsupported commands at these block-relative positions:

| EVB | Ordinary next refusal (block, offset) | Offline next refusal (block, offset) |
|---|---|---|
| r001 | `170` (2, 1748) | `1A8` (1, 3460) |
| r002 | `D0` (2, 20) | `1A8` (1, 4100) |
| r028 | `108` (2, 288) | `1A8` (1, 2232) |
| r035 | `D0` (2, 212) | `1A8` (1, 2684) |
| r041 | `D0` (2, 20) | `1A8` (1, 5852) |

Coverage is361ordinary/335offline table entries, including original no-ops;
these import refusals are not runtime-reachability claims. The
[qualification seal](../../tools/native_reconstruction/native_actor_script_predicates_qualification_v1.json)
retains exact paired receipts and source identities. No installed native
gameplay, complete session bootstrap, semantic save adoption or Stage4
completion is claimed by these components.
