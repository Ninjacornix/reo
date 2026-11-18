# Native encoded refill qualification

Status: isolated typed core and paired host qualification, 2026-11-06. No game,
audio device, process attachment, full game build or runtime adapter was added.
The parent standalone CMake project includes this component. This closes a
bounded encoded-refill owner profile, not full
ADXT/header/loop/playback-clock/RNA credit ownership.

The [design](ADXT_REFILL_NATIVE_CONTRACT.md) is implemented in
[game/native/adxt_refill](../../game/native/adxt_refill/README.md). It owns one
real SJRB ring, one retained producer grant and one genuine consumer data lease.
Workers cannot access ring storage. Existing SJRB, AsyncReadOwner,
ResourceSession and SerialWorker implementations remain unchanged. The original
oracle was already seen; the native core was then frozen before comparator
development, with no blind-authoring claim:

| Identity | SHA-256 |
| --- | --- |
| `adxt_refill.cpp` | `a1c1a8d92c3c3e3f458ea1d46f6ead4ca96f7ada0bdf58f9a7ca6c04f9537a04` |
| `adxt_refill.hpp` | `36f0cfa764f94309f172f2adee5da8a3e60352c42416338597b7d4a5be14d00c` |
| `frozen_identity.json` | `05e2ba6e5880ca3e81915c749dbfb0d5b9f96a1cdb32823d1ecacb293e64231e` |

The private ring can have both producer and consumer credit outstanding. The
checked native invariant includes these held bytes; `data+free==capacity` alone
is not required. Strong chunks retain actual backing; move-only consumer tokens
expose only bounded reads. Explicit finish returns consumed prefix then unread
suffix through actual SJRB. Destructors never return consumer credit on an
arbitrary thread. Stale/foreign/duplicate returns refuse before effects.

The real provider is an unchanged AsyncReadOwner with one request slot and
bounded output plus exact-read staging. A completed result is consumed once,
copied to the retained grant, and published with source-derived prefix/suffix,
counter, retry and target-callback ordering. Producer error returns the grant;
wrong identity/overacceptance retains it in terminal error because retirement is
unproven. No original fallback follows side effects.

Ordinary pause/stop/close preserves accepted publication and already-buffered
data. Stop is not join, and no per-stream operation resets shared PCM/bank state.
Replacement/reset requires stopped, drained ring, no pending provider and no
consumer credit. Explicit terminal shutdown signals admission closure;
finalization refuses while pending/borrowed and only then joins outside ring,
provider/data/RPC/guest locks. Emergency destruction is separately documented
teardown policy. Provider workers and all owner methods obey the design's
external serialization/nonreentry contract.

## Measured host qualification

Both GCC15.2 and LLVM host runs pass2151 assertions. Most are the full wrapped
payload comparison; this count is not a scenario count. Checks include actual
blocked ByteView I/O through AsyncReadOwner, nonblocking close/stop signal,
retained provider lifetime, accepted-result publication then true worker join;
actual partial-destination failure/bad_alloc isolation and read-limit refusal;
wrap and simultaneous producer/consumer conservation; lost/moved/foreign/
duplicate lease handling; callback mutation refusal; ID exhaustion and safe
replacement. Standalone CMake/Ninja builds14 units/actions; CTest1/1 passes.

The [original cohort](ADXT_REFILL_ORACLE.md) remains frozen unchanged. Both paired
compiler runs pass all29 input classifications:25 admitted cases, one constructor
refusal for2049-byte partial-sector geometry, and three before-effect pending
reset/refill-reuse refusals. Compare97 source/ring/callback/read observations and
79,872 data bytes. Expected data views execute190 actual original SJRB
Get/Unget calls (7165 instructions) on copies of the frozen observed state and
verify restored credit. The derived projection is frozen before native output.
Only authored input reaches the C++ runner.

Final receipts:

- `build-native-sjuni/adxt-refill-native-parity-v2/gcc/receipt.json`, SHA-256
  `0ef1a9c548dae9051dc7253dff5181e9a74bde5425c17bdd390f2f897f60ee52`.
- `build-native-sjuni/adxt-refill-native-parity-v2/llvm/receipt.json`, SHA-256
  `7c699d0ba738b4b34456aeae2a371761a056f400fc5c3400afb3f1c4f057da8a`.
- Standalone `build-native-sjuni/adxt-refill-cmake-gcc/Testing/Temporary/LastTest.log`.

V1 receipts are preserved. V2 tightens refusal validation and records transport/
comparator hashes; core and dependency hashes stayed frozen through both runs.

## Comparison limits and next integration

Owned I/O result staging intentionally changes unpublished free-space physical
bytes relative to original inline writes. Production exposes no backing reader;
parity covers admitted published data and state/callback boundaries. Stack,
volatile registers, instruction scheduling and raw intermediate free backing
are excluded. Original unsafe pending reset/reuse/late-write observations remain
untouched; the native API refuses them rather than inventing original generation
suppression. A scripted provider close is not a proven original OS I/O fence.

This profile admits encoded capacities2048/4096/8192 plus36 and exact whole-sector
in-view ranges. Caller admission must retain immutable, pinned content; generic
ByteView size alone proves neither byte identity nor immutability. Actual mount/
cvFs/LSC/header integration, partial-final-sector padding, borrowed handles,
cooperative global open/stop waits and module lifetime remain outside the core.

Future Window v2 must share this one owner's actual DataLease, replacing the
frozen window's private encoded ring. It also needs independent larger request
qualification (source1152/2240 versus current256), long totals beyond4096, and
owned mutating loop callbacks that run before admission. No request clipping,
second ring, hidden stream reset or global experimental rendering path is
justified by these results.
