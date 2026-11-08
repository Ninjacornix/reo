# File #1 LSC game binding boundaries

Status: static implementation research during the V21 build. No LSC game binding
is installed and no LSC game playback is claimed. The existing original-qualified
queue and native dynamic source cores remain separate from this missing adapter.

The owned ELF hash is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
`build-native-sjuni/lsc-game-admission-static-v1.json` retains hashes for thirteen
generated sources and verifies 955 instruction comments against that ELF. Some
sources overlap, so this is not 955 unique functions or independent instructions.

| Public entry | Verified data flow and effect |
| --- | --- |
| `12A658` | Loads the LSC child from C4+`94`, forwards the filename argument to `13CD10`, and checks a negative result. It is a full-file enqueue wrapper, not LSC construction. |
| `13CD10` | Tail-calls enqueue `13CD38` with range words `0,0,FFFFF`. These retain the queue's full-file sentinel semantics. |
| `12A6B8` | Resolves a filename/range through `129E18` and `129F70` using C4+`B0`, then calls `13CD38` with the resolved three range words. |
| `13CD38` | Admits fewer than sixteen queued entries, allocates the next sequence from the preceding physical slot, stores/checksums the filename, copies the range and advances the queue cursor/count. The existing queue core already models this boundary. |
| `12A780` | Stops the current ADXT source, enters the original critical section, resets the input/stream interface, sets C4 source mode to `4`, supplies signed C4+`3E` shifted by eleven to `13D358`, leaves the critical section, starts the LSC child through `13CF10` and sets C4+`98` to `1`. |
| `12A830` | Delegates C4+`94` to `13D468`, which stores the low argument byte at child+`3` (queue repeat). |
| `12A8F0` | Delegates to `13D0D0`; its first entry returns child+`24`, the queued count. It is not a stop/clear operation. |
| `12A928` | With idle C4 state, delegates to `13CED0`, which clears count/cursors only when the LSC state is stopped. Active C4 state bypasses that clear. |

The exact engine caller at `1AEA48` queues a resolved range through `12A6B8`.
At `1AEAC0`, the caller starts the LSC source through `12A780`. The source named
`sub_001AE740` contains several guest entries and overlaps the separately emitted
`sub_001AEA70` body. Its filename alone does not establish that execution entering
at `1AE740` reaches every following call. Preserve exact PCs in further audits.

The runtime adapter must do more than allow the three currently refused producer
entries. It needs the complete enqueue/control/query lifecycle, retained native
names and validated mounted ranges, a generation-scoped LSC child identity,
source-mode/readiness mirroring, sequence/count/status behavior and actual
source/output retirement. Sequence numbers and an observed guest pointer are
metadata; neither grants file or current-source authority.

Prepare immutable clip/range evidence outside canonical control admission. Queue
mutation and native decoder/source observations must then use that same audio
owner; a future movie query may run concurrently through its captured capability.
Do not run the original lower producer alongside the native input or invent
progress when a file completion has not published into the source ring. Preserve
the existing regular-loop versus LSC-repeat distinction, notification ordering,
full-file sentinel and single-use input lifetime.

Still to establish: real caller queue/repeat/callback profiles, precise original
LSC child construction/reuse admission, source mode/error/EOF/restart behavior,
and the complete game service schedule. The current ordinary profile continues
to refuse unsupported LSC producers before original producer effects.
