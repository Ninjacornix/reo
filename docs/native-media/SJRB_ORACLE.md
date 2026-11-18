# Original-word SJRB queue oracle

Status: bounded synthetic original execution, geometry corrected 2026-11-06. No game, process,
audio device, SDK/full build, native queue implementation or runtime change.
This closes a queue-contract pilot needed by the
[ADX stream boundary](ADX_STREAM_NATIVE_BOUNDARY.md); it does not close an
ADXT decode window, stream player or playback-clock migration.

## Reference and execution

[sjrb_oracle.py](../../tools/native_reconstruction/sjrb_oracle.py) executes
the owned File1 ELF instruction words for the complete `13F7D8..140000`
SJRB family and actual `1407E0..14083C` span split. These include module
reference/init/release, fixed-pool create/destroy, reset, error registration,
Get/Put/Unget, count/peek, backing/capacity/extension and transfer-total accessors.
Creation scans the actual 256-record pool; there is no heap-allocation hook.
Backing is separately mapped caller storage, including extension and guards.
SJUNI queue operations and a host ring implementation are never substituted.

| Input | SHA-256 |
| --- | --- |
| `game_data/SLUS_207.65` | `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46` |
| `13F7D8..140000` original text | `43267f4a90d33777e2bc4f75c3d3867f04d6dc459704d0d9709162273c4bd596` |
| `1407E0..14083C` original split | `7686ce72fb6cc995c05c8f4498a1e746cb308ff9a8ff2d5f99d322544cffe422` |
| Actual vtable `224C28[30]` | `13ab97d9e638744bb82fba08078b3f12f4f087862da10d15da1c9e13e868738d` |
| Actual UUID `23DA58[10]` | `a0dc963e91254115785fce386e05a752e21f3116e4c14fe318b4d5b84d23492f` |

Address/size notation in this table is hexadecimal. Generated source is the
existing `build-native-sjuni/candidate-work-v6/project/recomp/config/output`
cohort. Its source-comment audit matches **532 unique words**, with **13 omitted
zero words and no omitted nonzero word**. The fixture records each source-file
hash, whole ELF hash and unchanged imported engine hashes. Generated source is
an audit companion; instruction fetching always uses the ELF.

The unchanged [integer engine](../../tools/native_reconstruction/sjuni_oracle.py),
[EE MAC engine](../../tools/native_reconstruction/ee_mac_oracle.py) and
[signed DIV extension](../../tools/native_reconstruction/adx_stereo_oracle.py)
supply lower64 instruction semantics. The new local extension implements only
the reached secondary-bank `DIV1` (`70A2001A` at `13FE50`) and reports reached
BREAK instructions. No loop teleport, modulo-return hook or queue grant hook
exists. Branch delay and branch-likely behavior remain explicit.

`DIV1` is independently checked on nine hand-authored positive/negative,
remainder, zero-quotient and `INT_MIN/-1` inputs. The tests additionally compile
the **exact pinned code-generator DIV1 emission** with GCC and LLVM; both match
the authored results and preserve the first HI/LO bank. Zero divisors,
noncanonical operands and reserved encodings fail before changing the banks.
This qualifies scalar results, not EE division latency or pipeline interlocks.

## Explicit external boundary

Only these external calls are bounded hooks:

| Call | Admitted model |
| --- | --- |
| `13F258/13F270` | Serialized tag1 enter/leave depth, including nested reset during create. No real CRI lock, guest scheduling or cross-thread proof. |
| `107C68` | Byte memset within the original pool only, at most `4000` hexadecimal bytes. |
| `107AB0` | Nonoverlapping byte memcpy entirely within the admitted backing plus extension; at most 16384 decimal bytes in v4 (8192 in retained v3). Every read/write is retained. Overlap or escaped extents refuse. |
| `13F288` | Returning diagnostic event. The actual default `13F7D8` thunk executes before reaching this boundary. No process-termination policy is invented. |
| Synthetic `FFFF00` | Returning error callback with actual arguments, guard depth and before-callback descriptor/object state. One explicit input script edits a descriptor length to inspect the original continuation. |

No callback invents an SJ return, a completed decoder result, resource read,
allocation or PCM transfer. ABI checks verify restored SP and actual lower64
callee-saved registers after each successful original call. Raw `v0` is kept
as observation only for void methods; it is not promoted into a return contract.

## Frozen pilot and observed behavior

The CLI writes a separate input transcript **before its expected-output replay**,
hashes it, then reloads that file to execute the cases. Inputs are authored
operations, bytes and explicit callback edits; outputs are not embedded in
those inputs. Paths are never overwritten. No candidate native algorithm was
read or imported to derive expected values.

Current v4 retained evidence:

- `build-native-sjuni/sjrb-oracle-v4/original-fixture-inputs.json`, SHA
  `0fbd6dc535541105733bcc295cf0494132e52ca391df63e244f3a70b14240a35`.
- `build-native-sjuni/sjrb-oracle-v4/original-fixture.json`, 57,167,846 bytes,
  SHA `f59c20e67e99bdf6a1d023dd4c4e5667278ea675b27181005e4e28d4c35955c9`.

Earlier v3 evidence is preserved byte-for-byte. Its 8192+192 byte case was
incorrectly called actual PCM geometry; it is a **smaller synthetic** case.
It does not establish the real PCM capacity. The new v4 corrects that label
and adds the real 16384+192 byte case without rewriting any v3 evidence:

- `build-native-sjuni/sjrb-oracle-v3/original-fixture-inputs.json`, SHA
  `13dc90fbcfa9a6380c3bb664f9de0ef89597023ce77eaee347064efc155f9564`.
- `build-native-sjuni/sjrb-oracle-v3/original-fixture.json`, 54,832,356 bytes,
  SHA `e0cef81bc8d6c546481a0258c3a66f13ef42d9f3ec94e5a61aa2e1a52fbca021`.
- `build-native-sjuni/sjrb-isa-checks/qualification-yipwa0ga.json`, exact micro
  harness, compiler/binary hashes and both compiler results; SHA
  `5b8eac14c2fe08aeb0c67fe163dcc0818eb6f35bf02ceebb99bb76df5a5bfb81`.

The v4 corpus has **36 cases, 248 original calls, 11,021 instructions and
530 unique visited words**. Two calls intentionally terminate with partial
evidence. The other 246 return with balanced substituted guards and preserved
callee-saved ABI. This is finite coverage, not exhaustive behavior or a native
parity comparison. Fifteen interval words are unvisited: padding/unreachable
NOPs, the null-error count branch and additional zero-capacity BREAK sites.

Coverage includes:

- Empty/short/zero grants, clipping to availability and contiguous extension,
  peek without reservation, both pool selectors and negative-request observation.
- Exact-end reuse, beginning-of-buffer mirror copies, extension-to-start wrap
  copies, both input/output borrows and original split prefix/suffix returns.
  Both Unget branches accept a suffix pointer at `base+capacity` by modulo
  comparison; the data-pool branch executes actual `DIV1`/`MFHI1`.
- No-extension geometry, one-sector encoded-ring geometry of 2048+36 bytes,
  the smaller synthetic 8192+192 case and actual ADXT PCM geometry of
  **16384+192 bytes**. These are physical backing
  extents, not merely declared guest capacities.
- Reset, fixed-pool exhaustion, destroy/reuse, second-object creation, module
  references, whole-pool clearing without clearing/freeing caller backing,
  selected transfer counters and 32-bit counter wrap.
- Invalid selectors, null error callbacks on Unget mismatch, default returning
  error routing, zero/null/nonpositive Put/Unget early exits and unaligned
  descriptor copies. Invalid-selector peek with request zero returns **1**
  while reporting the error and granting zero.

For a split publication/return example, an eight-byte free acquisition publishes
five bytes and returns its three-byte suffix. Reading five bytes, returning two
and ungetting three leaves free=13, data=3, write=5, read=2, acquisition/return
totals `(freeGet,freePut,dataGet,dataPut)=(5,2,2,5)`.

The actual PCM byte geometry is supported by owned constructor `1315E0`:
`1316B8` loads `2000` halfwords, stored at `+30`; `1316C0` loads `2060`
total halfwords, stored at `+34`. `13174C/131750` load those fields;
`131760` subtracts them, `131764` doubles the extension, and `131768` doubles
capacity before the `13F8A8` call at `131770`. Thus capacity is `4000` bytes,
extension `C0` bytes and physical extent `40C0` bytes (16384+192=16576 decimal).
The old 8192-byte label mistakenly treated the `2000` halfword value as bytes.
Tests pin ten actual constructor words; this is static caller evidence, not
complete original constructor execution. V4's oracle maps capacities through
16384 and extensions through 192 bytes; higher values still refuse. Neither
original DIV engine nor native ring arithmetic changed for the correction.

On a mismatched Unget, the original leaves position and availability unchanged
but **still subtracts length from its acquisition total after a returning error
callback**. The explicit callback edit changes the length from six to two;
the continuation rereads it and subtracts two. Restarting the entire operation
or caching the pre-callback length would change those effects. This does not
prove arbitrary callback reentry safe.

Each call retains before/after object words, named counts/positions/totals,
pool hash and active slots, all descriptor spans, complete backing/extension and
guards, stack bytes, ordered reads/writes, hook observations, instruction visits,
raw/defined returns and final MAC banks. These bytes support a later independent
native comparison. The original does not enforce a general lease system; the
oracle observes transfers rather than inventing missing ownership checks.
Hook-preserved caller-saved registers and MAC observations are not a full
volatile-register equivalence claim for original libc/diagnostic implementations.

## Honest failures and limits

The two zero-capacity cases are outside valid ADXT geometry:

- Unget selector1 reaches actual `BREAK7` at `13FE34`, word `000001CD`, before
  division. Its prior stack/guard effects remain recorded; no return is invented.
- Get selector0 reaches `DIV` at `13FAFC`, word `0043001A`, before the later
  compiler-generated zero check. The architectural zero result is undefined,
  so execution refuses at DIV; it does **not** claim to have executed the later
  BREAK. The descriptor count already written remains in the partial snapshot.

No unsupported instruction was reached within the declared successful corpus.
Unknown instructions, unowned fetches, instruction limits and unmapped accesses
remain fail-closed. Earlier stage `sjrb-oracle-v1` preserved only its input file:
execution completed but a relative-path reporting bug prevented result export.
Stage v2 is the earlier 32-case pilot. Stage v3 is the earlier 35-case cohort.
All remain untouched; v4 is authoritative for the corrected actual PCM geometry.

Cross-thread scheduling, interrupt/callback locks, arbitrary aliases, overlapping
memcpy, arbitrary reentrant stop/reset/destroy, negative or unbounded capacities,
and real lifetime fences remain excluded. Two constructor records may reference
one backing in the constructor-only case; concurrent shared-backing operation is
not admitted. Source bytes, encoded/PCM grants and publication totals are not
device playback position or immutable storage leases.

Next: independently implement native SJRB storage/borrow behavior, compare the
retained states/bytes/callback order, then execute the complete original outer
reserve/decode/result/publication chain with real kernels and rings. Header,
coefficient, loop/source/refill, scheduler and audio-credit owners still require
their separate closures from the stream-boundary document.

Reproduce into a new evidence path:

```powershell
python tools/native_reconstruction/sjrb_oracle.py --output build-native-sjuni/sjrb-oracle-new/original-fixture.json
python -m unittest discover -s tools/native_reconstruction -p test_sjrb_oracle.py -v
```

All **24 tests passed**, including both compiler microchecks and static owned
ADXT constructor-word checks. Existing engines,
frozen corpora, runtime/native cores and game binaries were not modified.
