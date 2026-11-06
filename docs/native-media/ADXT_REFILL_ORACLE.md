# Original ADXT encoded-refill oracle

Status: bounded synthetic original-word qualification, 2026-11-06. No game,
device, process attachment, real file I/O provider or complete ADXT player was
run. The oracle imports no native refill algorithm. Its expected observations
come from original EE instructions and real SJRB operations; explicitly scripted
cvFs boundary responses and physical write times are **inputs**.

[Owner inventory](ADXT_PLAYER_OWNER_NEXT.md) explains why this owner is needed.
The existing typed decode window still has request limit 256 versus the
source-derived 1152/2240 examples, total limit 4096, private-ring conservation
admission, and read-only staged callbacks. This oracle does not change those
integration blockers or qualify mutating loop callbacks.

## Identity and reproduced boundary

Executable: owned `game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
The new [oracle](../../tools/native_reconstruction/adxt_refill_oracle.py)
executes complete `130800` refill, reached through actual `130B78` lifecycle
service. It also executes original initializer `130108`, explicit-limit start
`130698→130620`, threshold/request/target/callback setters, pause, stop and
nonblocking close controls. Initial owned-open flag `+45=1` is a declared
already-open input, not an emulated successful open.

| Loaded original interval, exclusive end | SHA-256 |
| --- | --- |
| `130108..130218` | `d52e6d240130169793eed4a19d74b5139e40c41d6b7de13b02d6cc2a1afe2ff2` |
| `130420..130D44` | `b2639127d95411cd463eb4772bcd408a232ce0a98089c9d5c5330152700b45fd` |
| `130E18..130E58` | `58939e6073707bc7291ee907cb04786eed6d9f895580e5c44d501f0161c018ce` |
| `13F7D8..140000` SJRB | `43267f4a90d33777e2bc4f75c3d3867f04d6dc459704d0d9709162273c4bd596` |
| `1407E0..14083C` split | `7686ce72fb6cc995c05c8f4498a1e746cb308ff9a8ff2d5f99d322544cffe422` |

All 1,214 loaded words are checked against the owned ELF. Generated audit
companion `candidate-work-v6/project/recomp/config/output` matched 1,180 comments
plus 34 omitted zero words, no omitted nonzero word. Actual source bodies are
not distributed by the fixture. Complete loaded intervals include unexecuted
entries; loading them is not coverage or proof of open/wait/destroy paths.

The unchanged `WindowInstructions` integer engine and bounded runner are reused
without their codec/window setup. Its lower engines remain unchanged. No new
instruction semantics or loop teleport is introduced. Fixture hashes pin all
six imported/oracle source files and the existing generated ISA references.
Original delay slots, branches, selective stack stores and ABI restoration run
through the ordinary instruction runner. No full volatile-GPR, libc side-effect,
preemption or timing equivalence is claimed.

## Frozen cohort and checks

Inputs are written to a new file **before replay**; an existing input or output
path is refused. Each case uses actual ring initialization/create and operation
words to establish read/write position and occupancy. Capacities are 2048,
4096 or 8192 bytes with the actual encoded extension 36; files are finite
synthetic patterns of at most 16,384 bytes. Actual per-channel PCM geometry
remains 16,384+192 bytes; it is not exercised by this refill owner.

Final private cohort:

- `build-native-sjuni/adxt-refill-oracle-v2/original-fixture-inputs.json`, SHA-256
  `1f6253974eb701d83a6912dadcdcb09c321cae533009c8ca9dc2030c16e10572`.
- `build-native-sjuni/adxt-refill-oracle-v2/original-fixture.json`, 11,949,122
  bytes, SHA-256 `366dcf38ac63e9d2c88c4be1392e9914d82925c87e0e5e1fbcc506aad7706b52`.
- 29 cases, 18,337 original instructions, 760 distinct visited words, 58 actual
  lifecycle calls, 30 scripted read requests, 64 status responses, 3 read-only
  target callbacks and 2 external-close calls. No partial refusal in this cohort.
- 208 of 222 refill body words visited; this is finite coverage, not every
  branch/input. Full physical backing with guards, descriptor/ring state,
  original stores, stack observations, callback state and read/write order are
  retained. Output size is bounded; no 32MiB RAM dumps are produced.

Twenty checks in
[test_adxt_refill_oracle.py](../../tools/native_reconstruction/test_adxt_refill_oracle.py)
pass, including exact deep replay of every frozen case, current source/engine
identity, source comment audit, guard bytes, real ring entry/callback order,
accepted prefixes, wrap mirroring, control ordering and fail-closed script bounds.
Run with `python -m unittest discover -s tools/native_reconstruction -p
test_adxt_refill_oracle.py -v`. To generate a new cohort, use the oracle's
`--output` with an unused path; never overwrite an earlier cohort.

The earlier v1 cohort is preserved. Its unaligned wrap input at position 3072
provided less than one sector of physical grant but scripted acceptance of one
sector, so the harness truthfully refused that external response after the
original borrow. This was an input-domain error, not a missing EE instruction.
V2 uses position 2060: a 2072-byte grant admits one sector across the logical end,
and actual SJRB publication mirrors the 12 wrapped bytes and returns the suffix.
No v1 expected result was rewritten.

## Observed original ordering

| Case family | Original-word observation |
| --- | --- |
| Inline provider write | Even when bytes are written during `ReqRd`, the submission pass leaves data unpublished. A later status1 pass publishes. Completion does not submit another request in that same pass. |
| Partial acceptance | Requested two sectors, accepted one: the full 4096-byte free grant remains held while pending. Completion uses accepted count `+1C`, puts 2048 data bytes, then ungets the free suffix. It does not use a later actual-byte result. |
| Consumer during pending | Existing data can be consumed and returned while the writer holds free space. Observed data/free 1024/1024 plus held 2048 equals capacity4096; requiring data+free==capacity would reject a legitimate state. |
| Request callback observation | `ReqRd` sees inflight byte1 while stored reserved pointer/length are still zero. Those fields are stored after the external request returns. No invented generation or atomic submission state is inserted. |
| Pending/error | Status2 leaves the original span held. Status3 returns the full free span and enters the original retry path. Nonpositive acceptance also returns the grant; retry increments only when the subsequent scripted status is3. Limit2 produces state4 on the third failed request; negative retry limit suppresses that increment path. |
| Backpressure/zero | Full data and exact threshold equality prevent new request. A physical grant shorter than one sector, a zero max-sector cap, or a final partial-sector remainder can still execute seek and `ReqRd(0)`. The partial-sector case stays reading rather than fabricating byte-tail completion. |
| Pause | Exact pause byte1 blocks new submission. Pending completion still publishes while paused. |
| Stop/close | Actual `1306E0` sets deferred stop for an inflight state2 read. Completion publishes its accepted data first; a later lifecycle pass reaches stopped state. The deferred close request from nonblocking `130520` follows that ordering. The close hook observes record file field already zero because the original call delay slot clears it. |
| Target/finite limit | A target-equality callback sees progress and cleared reservation fields; a distinct finite cumulative-sector limit can terminate without target callback. Hooks here are read-only observations. |
| Reset/reuse | `130620` clears inflight/reservation fields without a ring return or provider cancel. A scripted late writer still addresses its retained synthetic destination. Resetting/reusing the ring can let that write replace newly published bytes without changing queue counts. This is not safe native admission. |

## External hooks and unresolved lifetime

Only external guard enter/leave, bounded pool memset/nonoverlapping ring memcpy,
read-only errors/target callbacks, and cvFs boundaries are hooked. `135F50`
status, `135D60` seek, `135DC8` read acceptance and `135C80` close are declared
script responses. The harness records requested sectors, exact destination,
accepted count and whether physical write is inline or a later explicit action.
Positive acceptance is bounded by the actual request and retained backing.
No ring grant, split, publication, retry, stop transition or decoded result is
replaced by a host implementation.

Harness `observation_id` identifies a scripted external write; it is **not** an
original generation, cancellation token or scheduler job. In the reset/close
late-write case the input explicitly allows a writer after the close hook. This
shows that the harness has not invented suppression. It does **not** prove that
the real cvFs close permits such a write, nor that close fences it. Actual
provider stop/join/close behavior must be qualified separately before freeing
or reusing native storage.

The cooperative wait wrappers `130748/130560`, actual cvFs open/file-pool scan,
global module lifetime, mutating callbacks, negative/overflowed geometry and
concurrent/reentrant owner actions are not qualified here. A future typed owner
must retain storage through an accepted provider request and a demonstrated
completion/stop fence; incarnation rules are an explicit native safety policy,
not retrospective edits to these original expected observations. Full header,
codec/loop, clock and RNA-credit ownership remains separate.
