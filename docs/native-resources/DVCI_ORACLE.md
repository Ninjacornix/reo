# Original-word DVCI scalar oracle

2026-11-05. Offline synthetic execution only. No game, scheduler, process,
dependency or native CD-owner implementation was run or changed.

[`dvci_oracle.py`](../../tools/native_reconstruction/dvci_oracle.py) executes six
complete owned File #1 US bodies through the existing
[`sjuni_oracle.Machine.instruction`](../../tools/native_reconstruction/sjuni_oracle.py).
It supplies a separate bounded dispatch loop and synthetic memory; it imports
no native DVCI algorithm and requires no integer-engine extension. This closes a
scalar fixture boundary for the [next resource step](CVFS_REQUEST_BOUNDARY.md),
not the complete request/device/consumer contract.

| Original body | Included contract |
| --- | --- |
| [`139C30..139CC4`](../../recomp/config/output/sub_00139C30_0x139c30.cpp) | Seek origins, signed clamp, word wrap and completed-count clearing |
| [`139CC8..139D00`](../../recomp/config/output/sub_00139CC8_0x139cc8.cpp) | Logical-sector cursor query |
| [`139D00..139EA4`](../../recomp/config/output/sub_00139D00_0x139d00.cpp) | Request validation, accepted count, field writes and sync/async scalar transitions |
| [`1396D0..139794`](../../recomp/config/output/sub_001396D0_0x1396d0.cpp) | Consume scripted SRD states through the owned jump table |
| [`139FA8..139FE0`](../../recomp/config/output/sub_00139FA8_0x139fa8.cpp) | State query without service |
| [`139FE8..13A034`](../../recomp/config/output/sub_00139FE8_0x139fe8.cpp) | Completed-sector-to-byte word shift, only in state 1 |

Ends are exclusive. The owned ELF SHA-256 is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
`Elf` rejects another identity before interpreting any instruction. The updater
table is read from the same image at `23CA60`, forty bytes; every destination
must remain in the admitted update body. Fixtures retain body/table hashes and
interpreter/generator hashes, never instruction arrays.

Fresh comparison of these six complete source bodies against the owned ELF
verified **231 instruction comments plus seven omitted zero words**, with zero
conflicts or omitted nonzero words. Generated cases visit 228 distinct PCs of
the 238 words in these body intervals. This is observed trace coverage within
the declared domain, not exhaustive input or scheduler coverage.

## Explicit external boundary

Only these calls are substituted:

- Guard enter/leave `141700/141778` and diagnostic `1395F8`.
- Cache-range operation `115058`.
- SRD create/prepare/status/wait/destroy
  `137340/137468/137608/137738/1373C8`.
- CD sync and shared server calls `100D78/137E90/137D80`.

Each hook records its call PC, arguments, guard depth, scripted return and
before/after handle/mode/destination-probe snapshots. Hook responses preserve
other registers and memory and invoke no reentrant callback. These are explicit
fixture assumptions, not recovered full callee clobber or device contracts.
An opaque SRD identity has no implemented request object behind it. SRD state
0..9 is selected by the fixture, and then the original updater instructions and
table determine the DVCI transition.

Unknown instructions, fetches outside the six bodies, unmapped/unaligned
accesses, an instruction-cap overrun, unknown handle/SRD identities, unbalanced
guards, DVCI states outside 0..3 and scripted SRD states outside 0..9 reject.
Sync-mode fixtures admit 0, 1 and 2 to cover equality-to-1 versus the async path.
Void update returns retain raw `v0` only as an observation; no result ABI is
invented.

## Reproduce and use

```powershell
python tools/native_reconstruction/dvci_oracle.py --output build-native-sjuni/dvci-oracle-fixtures.json
python -m unittest discover -s tools/native_reconstruction -p test_dvci_oracle.py -v
```

Result: **51 cases / 178 calls; 12 tests pass.** Output contains synthetic initial
state, byte-sized pre-writes, the external hook plan, original-PC traces, defined
returns and observed memory at each boundary. A native differential test must
apply that same initial state and hook plan, compare defined returns and every
observable field/event, and exclude raw void-return observations.

Covered distinctions include invalid/null requests, busy and zero requests,
seek origins/clamp/wrap, full/clamped acceptance, all ten updater table states,
create/prepare refusal and queries that do not service work. In particular:

- `139E6C` stores original requested sectors on the synchronous path; the async
  success path stores accepted sectors at `139744`.
- Zero requests retain prior completed count; busy zero requests do not change
  state. A missing destination diagnoses even for a zero request.
- A positive request clamped to zero still calls cache-range and SRD preparation.
  Under **scripted preparation success**, it can return zero with state 2. This
  does not prove that real device preparation succeeds at EOF.
- A failed prepare invokes destroy while leaving the DVCI request pointer stored;
  terminal update destroys before its subsequent pointer clear. Snapshots retain
  these residual fields and ordering rather than normalizing them.

No payload I/O, EOF padding, actual SRD wait/error side effects, stop/close,
callback reentry, thread interleaving, guest execution locks, DMA visibility or
CRI/SJ reservation publication is implemented. Destination snapshots are a
64-byte synthetic probe, not a claim to have read a resource. Complete native
DVCI migration still requires those gates from the request-boundary review.
