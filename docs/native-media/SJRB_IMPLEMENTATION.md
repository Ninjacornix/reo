# Native SJRB owned ring implementation

Status: standalone Stage3 component, qualified 2026-11-06. No runtime/game integration,
device execution, game launch or full build. This implements one ring owner;
it does not retire the original global SJRB module or ADXT player.

The [original-word oracle](SJRB_ORACLE.md) was generated and inspected by this
implementation's author **before** native implementation. No blind-independent
authorship is claimed. Native algorithm/header/unit source were then frozen
before the fixture transport/comparator was written. Original expected fixtures
and shared instruction engines remain unchanged.

## Implemented source contract

[sjrb.hpp](../../game/native/sjrb/sjrb.hpp) and
[sjrb.cpp](../../game/native/sjrb/sjrb.cpp) implement complete operations for one
owned ring: free/data acquisition, publication/return, modulo-matching Unget,
peek/count, reset and four selected transfer counters. `Chunk::split` implements
the admitted original `1407E0` span split. The source identity and exact owned
intervals are recorded in the original oracle document.

| Original behavior | Native behavior in the admitted domain |
| --- | --- |
| Get grants `min(capacity-position+extension,available,requested)` under tag1 | Same signed selection; selected modulo position, availability and acquisition total update in original order. Empty grants retain a non-null storage identity. |
| Put data adds readable count before maintaining mirrored extension/wrapped start, then adds publication total | Same ordering, exact physical bytes and unsigned 32-bit counter wrap. Free Put only returns capacity and updates its total. |
| Unget restores availability/position only if modulo previous position matches | Same signed wrapped word arithmetic and remainder. Even a mismatch subtracts acquisition total after a returning error; its descriptor length is reread after that callback. |
| Peek stores grant before leaving tag1; invalid selector reports error, grants zero and can return true for request zero | Same guard/error/store ordering and numeric result. Negative peek/count observations remain numeric and cause no payload access. |
| Invalid Get/Put/Unget selector clears descriptor before error callback | Same for current, admitted positive input spans. Void method completion is not invented as an original numeric return. |
| Count is unguarded; invalid selector invokes error then returns zero | Same. Valid read-only count/total observations are allowed within a serialized callback. |
| Nonpositive length or null pointer Put/Unget exits before tag1 | Same before storage/epoch validation; these are explicit no-ops, not reports of a successful publication. |
| Reset clears positions/counts/four totals without clearing backing | Same visible numeric/storage effects, plus explicit native incarnation invalidation. |

Add/subtract use unsigned-bit word arithmetic and bit-cast back to signed32;
there is no signed-overflow UB. Original total words wrap modulo 2^32. Unget
uses the original wrapped `position+capacity-length` expression before signed
remainder, rather than a guessed positive-modulo normalization. Positive
capacity excludes architectural divide-by-zero; signed division cannot meet
the `INT_MIN/-1` UB case because the divisor is positive.

## Backing, chunks and admission

`Ring` validates **the whole geometry** before allocating or calling hooks:
capacity>0, `0<=extension<=capacity`, and capacity+extension<=INT32_MAX. Allocation
of the complete physical backing succeeds before a usable owner exists; failure
throws before any ring or callback effect. This includes the original real PCM
16384+192 and encoded-sector 2048+36 byte profiles. It deliberately excludes
arbitrary extensions larger than capacity, negative/zero capacities and borrowed
null or insufficiently sized backing.

`Chunk` retains a private `shared_ptr` to actual fixed-size storage. It contains
an offset, signed byte count and incarnation, with no exposed data pointer,
guest address, runtime object or register file. Checked `read/write` copies
validate the current incarnation and complete physical range every time. No
raw mutable span can escape and later bypass reset invalidation. Ring destruction
does not free storage still held by a chunk; that chunk remains usable in its
orphaned storage incarnation. A chunk cannot be returned into another Ring.

Reset advances the storage incarnation while retaining physical bytes; old
positive chunks then refuse Ring admission and all byte access. Counter
exhaustion refuses reset before hooks rather than reusing an incarnation.
Lifetime equality is independent of original numeric position equality.

`make_span` explicitly admits an arbitrary current in-backing numeric span.
There is deliberately **no invented original linear lease rule**: repeated Put,
publication without prior Get and availability beyond capacity are permitted
if the physical span is safe, as in the original. The native window owner must
add its separate exactly-once borrow/publication discipline. Copying a Chunk
duplicates a strong storage reference; it is not another original acquisition.

Before-effects refusals preserve outputs, ring state and hook counts:

- Foreign storage, stale positive chunks, positive extents outside physical
  backing, escaped byte-copy ranges and aliased/negative-prefix split descriptors.
- Negative Get requests and a negative selected availability for Get, because
  an original negative grant can create an unsafe subsequent position. The
  original negative-request fixture remains an explicit excluded observation.
- Invalid pool/which for the original unchecked total setter/getter. Generic
  Get/Put/Unget/count/peek invalid selectors retain their original error path.
- Mutating Ring reentry or incarnation exhaustion. These are explicit native
  safety policies, not claims that original callbacks reject such operations.

Null or nonpositive Put/Unget remains the original early no-op even for an old
descriptor. A numeric length edit cannot authorize byte access: subsequent
read/write and positive Ring admission still check the complete physical extent.

## Copy and callback review

The geometry makes both original Put copies provably bounded/nonoverlapping:
the prefix source ends at/before extension<=capacity and its mirror starts at
capacity+offset; a wrapped tail is at/beyond capacity while its destination
starts at zero and has length<=extension<=capacity. Every admitted source/end
lies within capacity+extension. Therefore publication has no fallible memory
admission left after its first counter write. It does not retry or fall back.

Callers externally serialize all Ring and Chunk operations. Explicit synchronous
enter/leave/error hooks model the source boundary; there is no invented SPSC
atomic protocol, lock, scheduler or background thread. Callbacks are nonthrowing.
Guard hooks are observation-only, and mutating Ring reentry refuses. An active
positive span modified by an enter hook is detected and produces
`callback_contract_violation` after paired leave: hooks already ran, so callers
must **never** treat that result as permission to restart an original call.

The admitted error callback can observe ring and descriptor state or change the
active Unget descriptor length. Mismatch subtraction rereads that value, as
the original does. General reentrant reset/destroy/stop/rebind and destroying
the Ring or its callback context during an enclosing call remain outside the
profile. A shared backing reference is not a codec-worker join or callback
lifetime fence; the future owner must close admission and join outside playback.

## Qualification

Historical freeze record: `game/native/sjrb/frozen_identity.json`.

| Frozen file | SHA-256 |
| --- | --- |
| `sjrb.cpp` | `29a888b091cf7284876cabcab0aa78062632e6192d98782edc0b065d926d25a2` |
| `sjrb.hpp` | `95263a5391293bd7f4a5d9607cabb57a3ae565ae9eee0d3f38d290f5cc45a37b` |

Both GCC and LLVM standalone native units passed **32,880 assertions** before
comparison. That count includes 32,767 repeated free-Put completion checks in
the bounded signed-count-overflow test; it is not 32,880 distinct scenarios.
Other units cover ownership after destruction, stale/foreign refusal before
effects, full wrap/mirror bytes, exact-end/suffix splits, original permissive
repeated returns, callback continuation/store order, no-op paths, guard-mutation
errors, reentry refusal and total overflow. Strict warnings are errors.

Corrected v4 original-cohort qualification: GCC and LLVM each passed
**30 admitted cases / 165 calls** without
changing the frozen core: 1,650 numeric state words, 192,160 physical backing
bytes, 42,240 descriptor bytes, 206 guard events, 10 returning error/diagnostic
observations and 18 defined numeric returns. Retained paired receipts:
`build-native-sjuni/sjrb-native-parity-v2/gcc/receipt.json` and
`build-native-sjuni/sjrb-native-parity-v2/llvm/receipt.json`.
The frozen core/header were unchanged across qualification. LLVM parity ran
after the private-game-test quiet period ended; no compiler jobs overlapped it.

Geometry correction: the earlier v3 corpus and paired
`sjrb-native-parity-v1/{gcc,llvm}` receipts remain byte-for-byte unchanged. Their
8192+192 byte case is a smaller synthetic profile, **not** actual PCM capacity;
the prior documentation's actual-geometry claim was wrong. Owned `1315E0` stores
`2000/2060` halfword values, then doubles both capacity and extension before
`13F8A8`: actual capacity=`4000` bytes, extension=`C0`, physical extent=`40C0`.
The v4 cohort adds that **16384+192 byte** case and renames the smaller test.
All 24 current oracle tests pass, including ten actual constructor-word checks;
this is static caller evidence, not a complete ADXT constructor oracle. Native
core/header hashes and every frozen v3 input/output remain unchanged. The
historical native freeze record still intentionally identifies the original
v3 fixture seen at implementation time. The comparator pins and accepts both
retained cohorts, using v4 by default.

The comparator generates commands only from the separately frozen original
input transcript (SHA `0fbd6dc535541105733bcc295cf0494132e52ca391df63e244f3a70b14240a35`).
The native executable receives no expected state or output. Original fixture
SHA is `f59c20e67e99bdf6a1d023dd4c4e5667278ea675b27181005e4e28d4c35955c9`.
Actual observations and input commands are retained per case. A failed comparison
preserves observations and reports differing fields; it does not rewrite a
fixture or select an expected-driven implementation.

Original init/create only seed the standalone owner's initial logical state;
their pool scans, constructor callbacks and global reference effects are not
native comparison claims. Six cases are explicitly excluded: global second
object/destroy/reuse, module references, pool exhaustion, both zero-capacity
partials and negative Get. Original UUID/backing guest-pointer return addresses
have no typed numeric counterpart and are excluded; those operations' unchanged
state still compares. Guest ABI/register/stack writes, raw global record identity
fields and generic libc-hook dispatch boundaries have no native layout equivalent.

## Remaining complete owner work

Global 256-record/module lifecycle and raw guest callback adaptation remain
separate. No source actor/movie/audio route selects this library yet. A future
adapter must establish its owned scope, object/incarnation and storage lifetime
before effects; it cannot project safety from a PID, raw numeric pointer or an
unchanged source signature alone.

The next closure is the real outer ADXB acquire/reserve/decode/wrap/result/
publication transaction with these rings and existing tested kernels. Header
admission/coefficient calculation, refill/source versions, loop/drain, authoritative
stream scheduling, stop/join and RNA/PCM credits remain the distinct obligations
in [ADX_STREAM_NATIVE_BOUNDARY.md](ADX_STREAM_NATIVE_BOUNDARY.md). This component
establishes no gameplay speedup or complete-player migration.
