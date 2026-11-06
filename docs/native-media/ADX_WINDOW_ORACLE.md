# Original tag0 ADXB decode-window transaction

Status: bounded original-word evidence, 2026-11-06. No game, device, process,
full build, native window implementation or runtime change. This closes the
serialized **input-borrow → real output reservations → actual kernel → result/
wrap → return/publication/ack** pilot from
[ADX_STREAM_NATIVE_BOUNDARY.md](ADX_STREAM_NATIVE_BOUNDARY.md). Header parsing,
coefficients, refill/file/LSC, loop/drain, playback-clock authority, scheduling
and RNA/PCM credit ownership remain outside it.

## Complete entry and source boundary

[adx_window_oracle.py](../../tools/native_reconstruction/adx_window_oracle.py)
executes actual owned File1 instructions. Top-level service starts at `12D638`,
with original outer state2 and prepared, header-admitted tag0 records. The real
dispatcher calls `12D590`; outer state3 subsequently prevents another service
pass. Calling `12D590` unconditionally would omit that state gate.

The executed chain includes:

```text
12D638 -> 12D590 -> 12CFD8: actual input SJRB acquisition/admission
  1251A8 / 125230: bind actual encoded grant and request phase
  125768 -> 125698:
    12CEB8: actual per-channel SJRB output reservations
    125370 -> 1252D0 / 125318: original budget geometry and request wrappers
    135078 -> actual1276D8 / 127FC8 ->127C80 or1278B8 kernels
    125518: original completed-word accounting and actual halfword wrap copy
    135048; 124840: actual default completion callback
  12D338:
    actual1407E0 split, input free Put and data Unget
    optional observation callback; channel data Put and unused free Unget
    actual accounting and125278 acknowledgement
```

Get/Put/Unget/count/peek/creation/reset and split execute the actual SJRB/split
words from the [SJRB oracle](SJRB_ORACLE.md). There is no host-ring grant/result
substitution and no native algorithm import. Real request geometry selects how
much the real kernels execute; neither codec result nor consumed byte/sample
count is scripted. Stereo wrapper doubling, odd input suffixes, marker prefix
effects, signed division and result-budget gap arithmetic remain original.

Callback distinction matters: the inner constructor installs `124810`, but the
actual outer constructor replaces it with `12CEB8`. The closed transactions
execute that **real outer ring reservation callback** and actual default
completion `124840`. A separate direct helper case executes actual `124810`
and demonstrates its offset/remaining computation without pretending it acquires
any SJ span. Callback counts are not audio frames played or scheduler updates.

Owned ELF SHA-256:
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Every loaded original interval has an explicit SHA-256 in the new script and
fixture. Highlights:

| Original interval, exclusive end | SHA-256 |
| --- | --- |
| `12D638..12D678` state dispatcher | `166986473a6bc25e0204900fe64bdc7e99ef36eb86ad9c4e4c570bc2cc49aaa0` |
| `12D590..12D638` complete outer service | `ea9d31163ce39ecb857b2eb99b5ee6d5759083ece71649176eedbb456402104e` |
| `12CEB8..12D334` reserve and input service | `7f0c781a139520332f00fc528928fbd277702219d132b1057b71b738a67e14a9` |
| `12D338..12D4FC` publication | `003927f1732877ad02c642fb4ee8668112a3650d4f83e92b3d898e732c3e5645` |
| `1254F8..125764` mono wrap, result and worker | `dec2a85829ac4aca052d388a647a0d8c7849a595b421bdfe1d6a0123e4f76192` |
| `124810..124860` original default callbacks | `318e91cf582de1ee96b4a495c071466a9f1a41ad333f96e2953a16d0e46fb61a` |

Generated source audit uses the existing v6 project source cohort: **2146 unique
commented words +30 omitted zero words, no omitted nonzero words**. All 2176
loaded words come from the ELF; generated files only audit correspondence.

## Frozen input profile and physical storage

The CLI serializes the entire authored transcript/profile before expected
execution, hashes it, then reloads it for replay. The frozen profile declares
one/two channels, ADX encoding3, four-bit samples, 18-byte/32-sample blocks,
44100 metadata frequency, exact coefficients/history/key and callback bindings.
The harness seeds already admitted outer/inner/predictor fields explicitly;
it does not claim to run their header parser, trigonometric coefficients or
constructors. Actual ring initialization/creation and every producer reservation/
publication/advance use original instructions.
Coefficients, history and key are authored scalar inputs. Their reachability
from a particular real file/header is not established by this fixture.

Physical byte geometry is deliberately explicit:

- Encoded ring: 2048-byte capacity +36-byte extension, one admitted sector profile.
- PCM per channel: **16384-byte capacity +192-byte extension =16576 bytes**.
  Inner geometry is 8192 **halfwords** capacity and8288 halfwords spacing.
  Stereo backing is physically adjacent at the original8288-halfword spacing.
  Whole-arena/input guards remain separate; no fictitious inter-channel gap.
- Disjoint synthetic outer/inner/predictor records, actual read-only vtable/UUID/
  nibble table, declared selector/odd flag and bounded stack/scratch storage.

The PCM byte conversion is the corrected `1315E0` source contract in the SJRB
document. The previous8192-byte smaller SJRB test is not actual PCM capacity.
No prior SJRB fixture, engine, native core or receipt was changed for this work.

External guard/error/diagnostic boundaries and the optional observational PCM
callback are the only control hooks. Generic memset is
bounded to the original pool; memcpy must stay entirely inside one real backing,
be nonoverlapping and at most16384 bytes. Optional PCM callbacks observe actual
context/channel/pointer/length and bytes; they do not return invented queue grants,
change results or cancel. The source default error thunk is pinned/available
before its external diagnostic boundary; these admitted cases do not exercise
that error path. All admitted cases finish without
error/diagnostic callbacks.

## Measured synthetic results

Final evidence:

- `build-native-sjuni/adx-window-oracle-v5/original-fixture-inputs.json`, SHA
  `55a7b1bdda757fbeeb764e3766453b062bab9f692e5da7f2ea23eefe5d8dcbee`.
- `build-native-sjuni/adx-window-oracle-v5/original-fixture.json`, 19,009,182 bytes,
  SHA `62dfa91bf99698bc10c84356e8320912967cefadbd6a83feb95f453122fafeff`.
- Oracle source SHA
  `43396670b83eb676ebc1a73d4f75ceee339fa003e45751ed7f419df2272a16fc`.

**33 cases** comprise 32 outer transaction cases and one constructor-default
reservation helper. They execute 47 top-level service passes, one helper and
six actual consumer ring calls, plus 295 original setup calls. **118066 original
instructions** comprise 105973 transaction/helper/consumer instructions and 12093
setup instructions. **1879 unique words** were visited; this is bounded coverage,
not every branch. Every service/helper returned with restored SP/callee-saved
lower64 registers and balanced substituted guards. There were **zero partial
failures**, 52 observational PCM callbacks, unchanged guards/tables and balanced
final ring capacities; no synthetic request silently disappears.

Cases cover normal mono/stereo/downmix, empty/three-byte/zero-budget progress,
partial 35-sample budgets, outer total clipping, one-byte/unpaired-block suffixes,
actual encoded input split/wrap, per-channel PCM wrap, near-end partial budgets,
output backpressure/recovery, first/left/right/prefix markers, outer end-marker
continuations, zero-filled input observations and disabled optional callbacks.

Selected distinctions established by actual execution:

| Case | Observed result |
| --- | --- |
| Four mono blocks |128 samples published, 72 encoded bytes consumed, completed word 4. |
| Four stereo/downmix pairs |128 samples/channel, 144 encoded bytes, completed word 8. |
| Finite 35-sample mono budget |35 produced/published samples but 36 encoded bytes (two blocks) consumed; kernel scratch contains full decoded blocks. Stereo consumes 72 bytes for the same 35 samples/channel. |
| Outer total clipped to 35 |Inner still produces 128 samples and consumes 72 bytes; only 35 samples are published. History/key/consumption and unpublished scratch are not rolled back. |
| PCM start 16352 bytes |One 32-sample block crosses by 16 samples. Actual halfword wrap copies execute before observation callback; SJRB publication then performs its own byte wrap copy. |
| Input start 2020 bytes, eight blocks |Actual bounded grants/suffix returns span several service passes; all 144 encoded bytes consumed with read/write positions 116. |
| Backpressure: only 32 bytes free |No request geometry/kernel execution until actual consumer Get/Put returns 64 bytes. Then one 32-sample block proceeds; later shortage again makes no hidden decode. |
| Marker after prefix |Published/consumed prefix and key advancement survive, while the kernels leave histories uncommitted. Right-marker partial scratch remains observable but is not automatically published. |

Before each channel callback, encoded input has already been returned/unget.
For stereo, the second callback observes channel 0 already published while its
own channel remains reserved. Therefore neither callback nor a later refusal
permits restarting the complete original transaction.

The final fixture retains full before/after outer/inner/predictor records,
all ring positions/counts/totals, exact input/PCM scratch+extension+guard bytes,
stack/scratch bytes, declared returns/raw void observations and ordered original
writes. Trace/callback write indices locate interleaving precisely; callbacks
also retain actual payload bytes, whole-plane hashes and base-prefix bytes.
This captures the early wrap copy before callback independently of the later
SJRB copy. Captured stack depth is400 hexadecimal bytes; observed deepest write
wasF0 below SP. General volatile-GPR/MAC equivalence to hooked libc is not claimed.

## Additional source correction: zero padding

The earlier static notebook's broad leading-zero description needs qualification.
At `12D0C0`, a non-`8001` header branches directly to ordinary input admission
at `12D210`. Leading zero bytes are therefore **not** universally discarded.
The zero-skipping loop is reached on the outer end-marker continuation.

Actual cases show 24 zero input bytes decode one block/32 samples and leave six
bytes; five zero bytes preceding a normal block leave a five-byte suffix after
decoding. Conversely a 16-byte `8001` end record followed by 24 zeros consumes the
record and padding, enters outer state 3 and invokes no kernel. The same record
followed by an ordinary 18-byte block leaves that block queued; subsequent
`12D638` service does not decode while outer state 3. No header/loop restart policy
is inferred from these facts. The existing source notebook is not modified here.

## ISA qualification and staged failures

The first preserved v1 run stopped honestly at **`04620005` BLTZL at12CF88**:
the unchanged base integer engine lacks REGIMM rt2/3. No function was replaced
to bypass it. The new oracle adds a local single-instruction BLTZL/BGEZL layer;
actual delay instructions still execute through the ordinary runner, and a
false likely branch annuls its delay. Existing integer/MULT/DIV/DIV1 engines
remain unchanged.

The new layer has signed64 condition/target microchecks, taken/annulled-delay
runner checks and both-compiler checks of the **exact emitted original BLTZL
block** from the pinned generated callback. GCC and LLVM pass the authored
negative/zero/positive/full64 cases. Retained receipt:
`build-native-sjuni/adx-window-isa-checks/qualification-u15pnkak.json`, SHA
`880789a999ca9df4468ad1d102f0a23d22d9a1bfd690894c7fcaa72d088c803d`.
Unknown encodings, read-only-table stores, unowned fetches, escaped memory and
instruction bounds remain fail-closed.

Stages are preserved, not rewritten: v1 records the ISA gap; v2 executes the
initial service cut; v3 adds the real outer state gate/end-marker cases; v4 makes
header seed/profile explicit; v5 adds write-index/physical callback observations.
Only v5 is the final complete pilot. All **19 tests pass**, including live replay
of the full frozen transcript and both compiler branch checks.

## Admission and remaining work

This pilot admits bounded one/two-channel symmetric output positions/occupancy,
requests at most 256 samples, total samples 1..4096, at most 512 encoded synthetic
bytes, complete backing/extension, seeded valid keyed coefficients/history and
observation-only callbacks. Unequal channel grants refuse harness admission;
the original reserve callback derives its budget only from channel 0 and does
not establish safety for a shorter second channel. Cross-thread/reentrant
cancel/stop/rebind, arbitrary aliasing, insufficient physical extension, invalid
channels/divisors, plugins and header/parser failure continuations remain outside.

A typed native window owner can now be authored/frozen separately, then compared
against this original evidence with actual owned rings and kernels. It must admit
all channels/storage/callback lifetimes before processing, retain actual borrows,
preserve distinct completed/consumed/produced/published units and establish a
post-effect failure policy. Native SJRB storage/incarnation safety is separate
from the original permissive numeric spans; neither replaces a worker join or
the higher source/loop/clock/credit owners. No gameplay speedup, slowdown cause
or full-stream/native-player completion is claimed.

Reproduce to a new evidence directory:

```powershell
python tools/native_reconstruction/adx_window_oracle.py --output build-native-sjuni/adx-window-oracle-new/original-fixture.json
python -m unittest discover -s tools/native_reconstruction -p test_adx_window_oracle.py -v
```
