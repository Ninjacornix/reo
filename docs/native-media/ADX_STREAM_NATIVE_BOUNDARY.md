# Native ADX stream ownership boundary

Status: read-only Stage3 inventory, 2026-11-05. No game, audio device, build,
new instruction execution, dependency change or current-candidate change was
performed. This document distinguishes existing tested components, static
original-source contracts and a proposed next implementation.

The next useful complete unit is **one ADX decode-window transaction with real
ring borrows and publication**, not another predictor phase helper. A complete
native ADXT player additionally needs header admission, sources/refill, loop and
clock policy, output transfer/credit, controls and stopped-owner lifetime. None
of those follows from a predictor reaching `ready`.

## What the existing native components establish

| Component | Reusable contract | Still outside that contract |
| --- | --- | --- |
| [Mono](../../game/native/adx_block/adx_block.hpp), [stereo/downmix](../../game/native/adx_stereo/adx_stereo.hpp) | Independently compared keyed 18-byte/32-sample kernels, signed history/key effects, markers, original return words; larger original-word corpus includes requests through 513. | Header/coefficients, ring lifetime, source position, publishing PCM, loop/stop, scheduling. Results own vectors and can fail allocation; they are not a no-refusal in-place codec interface. |
| [Predictor control/service](../../game/native/adx_control/README.md) | Nine phase/configuration/window helpers plus synchronous `135078` dispatch and ready/completed publication. | `SpanToken` owns no storage. Scalar window adapters do not implement `125370` budget geometry or `125518` result/wrap accounting. `cancel` is not a fence. A `Decoder` must be fully admitted before its noexcept/no-refusal call. |
| [SJUNI](../../game/native/sjuni/sjuni.hpp) and [temporary bridge](../../game/native/sjuni_adapter/queue_bridge.h) | Original linked-node get/put/unget/count semantics and bounded guest-image interchange. | **SJRB is a different implementation.** ADXT's encoded and PCM rings use SJRB positions, counts and mirrored wrap storage, not SJUNI nodes. Region tokens and a successful get do not supply a storage lease. |
| [ResourceSession](../../game/native/resources/resource_session.hpp), [AsyncReadOwner](../../game/native/resource_io/async_read_owner.hpp), [MountedReader](../../game/native/resources_windows/mounted_reader.hpp) | Exact bounded byte/sector reads, retained views, owned asynchronous results, ticket identity and publication suppression. | ADXF/LSC request ordering, SJ borrows, ADX EOF/marker/loop policy or audio credits. Cancellation does not interrupt an active provider read; immutable view size alone does not prove immutable underlying content across refills. |
| [PCM bridge](../../game/native/pcm_bridge/session_bridge.hpp), [candidate runtime binding](NATIVE_PCM_BACKEND.md) | One shared queue/voice owner, source-byte watermarks, clock/gain/order behavior and output lifetime. | Compressed decoding, ADXT sample position, DTR/SJX reply identities and raw-handle incarnations. Per-stream stop must not reset/shutdown the entire shared PCM/bank session. |

The older `media/adx/AdxDecoder` is not an admitted substitute: the existing
[boundary inventory](BOUNDARY_INVENTORY.md) records its header, nibble, stereo,
seek and partial-block differences. Do not use it as the reference for this cut.

## Still guest-owned state and effects

Addresses, offsets and workarea geometry in the following state table are
hexadecimal original-layout evidence, not a proposed native layout. Ordinary
prose block/sample counts are decimal. These are three separate decoder/playback
records plus separate queues.

| Owner / entry points | State and effects that must move together |
| --- | --- |
| ADXT, sixteen `C4` records at`20F3C8`; `1315E0`, `131918` | Caller workarea is aligned/borrowed. Owns ADXB`+4`, file`+8`, RNA`+C`, original input ring`+10`, current input`+14`, PCM rings`+18[]`, LSC`+94`, optional peak meter. Each PCM backing has`2000` halfword capacity plus`60` halfword extension: `40C0` physical bytes/channel. Encoded-ring geometry is separately sector-rounded with a`24`-byte extension. Constructor/rollback and all children have distinct release obligations. |
| Outer ADXB, sixteen `9C` records at`217D88`; `12C9D8`, `12CB58` | Borrows input SJ`+8` and output SJ`+C[]`; retains current encoded span`+14` and channel output spans`+1C[]`. State`+1`, format/end flags, header copy`+58`, limits`+38/+3C`, sample counters`+2C/+34/+40`, encoded counters`+30/+44` and header bytes`+98` are distinct. Callback/context pairs`+48/+4C` and`+50/+54` affect control and publication. Destroying the inner decoder does not itself destroy these borrowed SJs. |
| Inner ADXB, sixteen `E4` records at`20B958`; `124860`, `125698` | Borrows PCM base`+3C`, capacity`+40`, total spacing`+44`; has predictor`+8`, engine phase`+4`, encoded pointer`+48`, blocks`+4C`, channel/block/sample geometry`+50..+64`, reservation outputs`+68/+6C/+70`, result samples/bytes`+90/+94`. Default reserve/completion callbacks`+78/+7C`, `+80/+84` are independently replaceable. Header, configured key and loop-snapshot history/key are additional state. |
| Predictor, sixteen `3C` records at`21B7B8`; `134DE0`, `135078` | Phase`+C`, completed word`+10`, mode`+14`, input/count/output positions`+18..+24`, four history halfwords`+28..+2F`, coefficients`+30/+32`, key triple`+34/+36/+38`. Release clears the record without a worker join or ring return. |
| SJRB, `13F8A8`, `13FA88`, `13FBF8`, `13FD58` | Caller backing`+1C`, capacity`+20`, extension`+24`; data/free counts, separate read/write positions and acquisition/return totals. Get can grant across the logical end into extension. Data Put mirrors/copies wrap bytes; Unget depends on matching the last modulo position. Counts are not generic contiguous immutable views. |

The constructors locally permit some zero/large channel counts without proving
fixed-array safety. A first native owner must explicitly admit one or two
channels and real backing extents; existing unchecked inputs are not native
allocation instructions. An SJMEM start's declared`0x40000000` capacity is not
proof that caller memory has that extent.

### Source, header, borrow and publication chain

For the reviewed tag 0 ADX route, the meaningful synchronous chain is:

```text
ADXF/LSC/memory/external-SJ source -> encoded SJRB data
  12CCE0 header admission -> outer state2
  12D590: idle? 12CFD8 acquire encoded span/request lower work
    1251A8 encoded pointer + block count; 125230 engine requested
    125698:
      12CEB8 reserve per-channel PCM spans
      125370 calculate window/budget -> mono/stereo request wrappers
      135078 -> actual mono/stereo-selector kernel (synchronous)
      125518 collect result + wrap copy; 135048 lower ack
      completion callback(context,encodedBytes,samples) -> engine ready
    12D338:
      return encoded consumed prefix; unget unread suffix
      for each channel: optional PCM callback, publish valid prefix,
                        unget unused free suffix
      advance outer counters; 125278 acknowledge engine ready
  PCM SJRB -> DTR/local SJUNI -> DTX/SJRMT -> selected PCM sink
```

Concrete boundaries from the original source:

- `12CCE0` borrows header input, may defer/unget, reject unsupported format, copy
  an SPSD header or consume only a parsed prefix. Other format tags retain
  different source ownership rules. `1249E8` still owns ADX/AHX/header-version,
  key, history, coefficient, loop and extension setup; coefficient computation
  `126510` has floating-point/trig/exception semantics not supplied by the typed
  block kernels. Tag0 alone is not proof of the keyed18-byte/32-sample domain.
- `12CFD8` handles finite sample limits, optional limit callback, end marker and
  zero padding on the end-marker continuation. Original-word replay confirms that ordinary leading zero input can instead enter decode (see ADX_WINDOW_ORACLE.md). Tags`A/F` explicitly
  return a span before forwarding its pointer; a uniform retained-span rule
  across every format would be wrong. A first keyed-ADX owner excludes these
  plugin routes rather than pretending they share its lifetime.
- `12CEB8` reserves every decoded channel but derives offset/available budget
  from the first channel. It does not prove other grants are equally large.
  Validate physical bounds/all channels before host writes; preserve actual
  grants and ordering rather than inventing equal SJ returns.
- `125370` mixes encoded block units, per-channel sample budgets and output
  halfword positions. It uses signed truncating divisions and 32-bit arithmetic.
  Stereo doubles the selected request in the wrapper. `125518` uses the original
  completed **word**, including odd stereo behavior, to derive consumed encoded
  bytes and produced samples, adjusts the final budget gap, then performs one
  wrap copy. Its stereo budget threshold multiplies by channel count; the Code
  Veronica comparison has a real difference here and is not replacement code.
- Do not derive accounting from only `pairs_decoded`, PCM-vector size or bytes
  inspected. Odd stereo requests can leave an unpaired encoded block unread
  while returning the original odd request word. Early markers can retain
  prefix PCM/key effects while leaving histories uncommitted. Window budget and
  outer total-position clipping add further distinctions.
- `12D338` returns encoded input **before** PCM publication. Its optional
  callback is `(context,channel,spanPointer,spanBytes)` and runs before that
  channel's Put. It may observe already changed input ownership. Restarting the
  whole original call after any callback/Put/return would duplicate effects.
  Decoder completion callback`+80/+84` is different; its default`124840` advances
  inner offset/total counters. Do not merge these callbacks or counters.

### Player state above a decode window

| Concern | Existing original owner / required complete-player behavior |
| --- | --- |
| Start/source choice | `131B60` resets output SJs and starts header service. File`131C50`, external SJ`131D18`, memory`133630/133708`, AFS`133490` and seamless LSC`12A780` bind different borrowed/owned sources and asynchronous work. Source type controls destruction; no universal close/free is valid. LSC filename entries borrow strings, and AFS resolution adds member/range identity. |
| Refill/file end | `130800` retains a free-ring reservation through pending I/O, publishes accepted sector counts on completion, returns it on failure and preserves retry/target/progress state. `130B78` processes deferred stop/close/open only at its admitted phase. Positive read acceptance, file EOF, ADX marker, sample limit and decoded end are different events. |
| Loop | `133FE0` derives block-rounded startup requests/loop padding and callbacks. `133870` snapshots history/key at the first loop start; `133928` restores them and resets the appropriate sample/byte accounting. File rewind`133AB8` is separate. Memory reset/skip and seamless next-header`133D10` consume different spans; seamless accumulation`+A4` is not a simple seek. |
| Buffer/play/end/drain | `1343B8` starts from occupancy/free/end thresholds and can publish silence at decode end. `134530` enters drain only when every output queue is short. `1345F0` normalizes silence grants across channels, tracks added silence`+A8`, and uses maximum remaining queue occupancy plus RNA occupancy before requesting stop. Native EOF must not immediately discard accepted PCM. |
| Pause/start inhibit | `132E50` changes pause byte`+72`, requested RNA play and timing baselines/counters; `133058` has separate paused-discard/rebase behavior. `+70` inhibits start; `+71` records the threshold condition even when inhibited/paused. A device pause boolean is insufficient. |
| Frequency/volume/pan | Header rate reaches RNA`12C7E0 ->13EF80`; the original admits48000 divisors/even quotients with explicit error paths, unlike the PCM bridge's broader rate clamp. `1327B8` combines requested attenuation`+40` with decoder metadata; RNA clamps attenuation to[-999,0] and applies its source table/command mapping. Pan`132638/133B48` combines overrides and AINF, with-128 unset and RNA[-15,15] clamp. These are not direct linear PCM gains. Preserve the existing command mapping until separately proved. |
| Position/clock | `132028` computes decoded minus RNA occupancy minus channel0 queued samples, then applies seamless/base offsets`+A4/+88`. `132160` estimates from service ticks/baseline`+9C/+A0`, with pause and drift rebase behavior. `131F60` uses a different fixed RNA0/48000 route. None is a measured DAC timestamp or permission to change game simulation speed. |
| Stop/destroy | Inner stop`125248/135020` resets phase/history but returns no SJ reservations and joins no work. Local cleanup`131D98` disables transfer/play/decoder, destroys current input only for memory mode2 and does not itself stop file/LSC. Public`131E38` additionally requests those source stops; `131918` destroys multiple children and caller-buffer views. Desired-state flags and pool clearing are not native lifetime fences. |

Header/loop/predictor snapshots must retain history, key, logical compressed
position, sample limits, source incarnation and pending read/reservation state
as appropriate. Restoring only a byte offset or using the allocating standalone
decoder's reset/seek cannot implement these transitions.

### Scheduling and PCM credits are separate owners

`132C08` guards a service pass, scans active outer ADXB records through`12D678`,
then active ADXT records through`134C58`, then RNA`12C798 ->13EEE8`. The tag0
worker`125698` directly calls synchronous`135078`. Standalone pool scans
`125818/135170` do not establish another concurrent worker requirement.
The direct-edge index identifies callers of`132C08` including`12A130`,
`12A1A8`, `12C078`, `12C138`, `132CD8` and paused rebase`133058`; computed/
registered callbacks remain outside that direct-call list's completeness.

The existing CRI worker notebooks describe grouped callbacks, guest sleep/wake,
priority handoff and stop acknowledgements. Service tick`20F3C4` has both public
and interrupt producers. Stall thresholds count service passes, not elapsed
milliseconds or game updates. A native implementation needs one authoritative
stream scheduler and explicit serialization; running both scans on arbitrary
host threads would create new races. Seeing a guest stop acknowledgement before
`ExitDeleteThread` is not an operating-system thread join.

Refill/decode belongs on that admitted media control/worker path. The existing
device renderer must remain a bounded PCM consumer, without resource I/O,
compressed decoding, guest callbacks or joins on its audio callback.

The output credit chain must not be collapsed into decode completion:

- `138650` DTR holds selected source/destination spans until DMA status says
  complete, then returns source free and publishes destination data. Its grants
  and transfers use an alignment quantum; they are not audio samples played.
- `13ED28/13EEE8` operate paired local SJUNI/remote SJRMT and deferred RNA commands.
  Multiple DTX service scans in one invocation are not duplicate host frames.
- Current runtime RPC copies PCM through the selected PCM owner, then retains
  original reply identity and an end-byte watermark in its pending ledger.
  Accepted host copying releases a payload borrow but does not itself authorize
  a guest SJ reply/ring reuse. The existing lead/consumption policy, partial
  retirements and pending replies remain distinct from device frames.
- Reuse PCM bridge `queue/configure/consumed/drain/discard/release` through one
  selected session; do not open a second output owner. Two channel queue calls
  are not an atomic stereo transaction. Bypassing DTR requires a separately
  qualified publication/credit binding. Raw-ID reuse is not an incarnation;
  typed native PCM handles can invalidate lifetimes, but the compatibility
  bridge intentionally preserves some raw channels until reset.

Independent bank/RPC producers and global bank lifetime remain outside an ADX
stream stop. Do not use shared backend `reset/shutdown` as per-track cleanup.

## Smallest next complete owner contract

Implement a bounded **tag 0 keyed ADX window owner** first, with native SJRB
semantics and explicit storage. This closes a real borrow-to-return transaction;
it remains below the complete player policies above. Initially keep original
header/ADXT/RNA callers as a qualified compatibility boundary, not as proof those
callers have become native.

1. **Admit before processing.** Require one/two channels, 4-bit samples,
   18 encoded bytes/32 samples per block, valid coefficients/key/history,
   a captured stereo/downmix selector,
   checked source/output extents and arithmetic bounds. Allocate arenas/metadata
   outside the admitted processing phase. Every source refill carries a retained
   read-only resource view with an admitted content-version policy, or an owned
   result, and a stream/incarnation/job identity. Copying into the owned encoded
   ring makes that job's bytes stable; retaining a view alone is not a content
   snapshot for future reads/loops.
2. **Reserve actual rings.** Own the encoded data borrow and each free PCM
   reservation, including suffixes and physical wrap extension. Tokens identify
   validated regions plus offsets; they are not pointers or ownership by
   themselves. Preserve the original get/order/grants and window calculation.
   A shortage/refusal has an explicit lease-unwind path, never whole-call guest
   fallback after effects.
3. **Prepare and decode with a retained lease.** Resolve codecs, storage and
   allocation before invoking the typed no-refusal service. Current vector
   kernels need either successful private result preparation under exclusive
   state ownership or a future qualified preallocated-output API. A failed
   vector decode must not be converted into a fabricated zero completed result.
   Hold encoded/PCM backing until all codec accesses finish; record original
   return units separately from inspected bytes and generated samples.
4. **Collect, wrap and commit.** Apply the exact result/budget arithmetic and
   extension copies, then outer clipping/accounting. Retain unpublished scratch
   writes for parity comparisons. Return the consumed encoded prefix, unget its
   suffix and publish/return channel prefixes/suffixes in original order. Treat
   the first externally visible return/callback/Put as a commit boundary;
   arbitrary rollback is no longer valid afterward.
5. **Publish to one sink protocol.** The first cut can publish native PCM rings
   while the existing qualified transport remains their consumer. A later
   direct-PCM sink must retain per-channel accepted/end/consumed watermarks and
   source reply/credit identities as applicable; it must not equate enqueue
   success with playback or fabricate SJ returns.
6. **Stop and reuse explicitly.** Close new admission, mark cancellation and
   suppress stale publication by incarnation/job identity; outside join drains
   active codec and admitted callbacks before reclaiming borrowed arenas. Return
   every outstanding reservation once. Retain a cancelled resource read's view
   until the read owner releases it; cancellation is not an I/O fence. Reuse
   creates a new incarnation, so an old completion cannot target a new track.

The original scalar `cancel` remains unchanged: a synchronous decoder may be
followed by completed/ready stores even after scripted cancel/release reentry.
The native owner's stop/join policy is a separate lifecycle contract, not
something inferred from that phase reset. An initial oracle/owner can admit
no reentrant user callback (or observation-only callbacks) and cancellation
between completed transactions. Reentrant stop/rebind inside the before-Put
callback requires a separate original-word continuation proof; it must not be
silently treated as rollback-safe or claimed covered by an epoch check.

## Can a closed window be original-word-oracled without fake SJ returns?

**Yes, for a bounded declared domain; this oracle is not implemented yet.**
Execute the original outer input/reservation/service/result/publication bodies
and actual SJRB get/put/unget/count/reset bodies over guarded caller backing,
with real split/wrap-copy helpers and the original mono/stereo kernels. A
scripted vtable that simply returns chosen spans would miss reservation totals,
modulo matching, mirror writes and double returns—the very ownership being
tested. Native SJUNI cannot stand in for SJRB on the expected side.

The existing integer engine, tested EE MAC extension and nonzero DIV layer are
useful foundations. SJRB Unget also uses the second division bank (`DIV1`),
which needs its own instruction/overflow/HI1/LO1 qualification rather than being
treated as ordinary DIV. Bound/check capacities and divisors before host memory
access; preserve original trap behavior as an explicit rejected oracle domain.
The optimized memcpy path may need a documented bounded byte-copy primitive
with recorded accesses; this is different from inventing queue grants. Null
optional CRI guard/error callbacks can keep the first fixture domain free of
unmodeled guest/kernel scheduling. Unknown instructions/calls still fail closed.

Start after independently validated header setup, with actual key/history and
geometry seeded as inputs. This proves a decode window, not header parsing,
trigonometric coefficients or a complete resource-to-speaker player. Use real
kernel execution instead of the service oracle's scripted result hook.

Required comparison cases include empty/short encoded input, zero output budget,
one/two channels, positive requests, exact-end and extension wrap, partial final
sample budgets, input/output suffix return, early left/right markers, odd stereo
results, downmix, repeated service/ack and balanced exhaustion/reuse. Compare all
ring records/positions/counts/totals, full scratch/extension bytes and guards,
predictor/inner/outer records, histories/keys, callback order and publication
units—not just audible PCM or a success count. Later add real limit/loop callback
bodies, starvation/restart, stop/rebind continuations and source generations;
cross-thread cancellation needs host lifecycle tests in addition to sequential
instruction evidence.

### Concrete evidence inputs and remaining blockers

Existing expected-side evidence is the owned File #1 ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`,
the unchanged [SJUNI integer engine](../../tools/native_reconstruction/sjuni_oracle.py),
[phase](../../tools/native_reconstruction/adx_phase_oracle.py),
[service](ADX_SERVICE_ORACLE.md), [mono](ADX_DECODE_ORACLE.md),
[stereo](ADX_STEREO_ORACLE.md) and [larger block](ADX_LARGE_BLOCK_ORACLE.md)
oracles. Their retained fixtures/receipts establish those narrow contracts;
they do not contain a closed SJRB/window transaction or full ADXT loop fixture.
The static notebooks linked below supply caller/field maps, not new executions.

For this inventory, twelve original intervals were independently matched against
the current generated source comments and owned ELF: **990 unique commented
words, 20 omitted zero words, no omitted nonzero word**. Generated source files
can contain several logical entries; the interval boundaries below, not the
file header's entire range, define the audited bodies. Selected new metadata:

| Original interval, exclusive end | Body SHA-256 |
| --- | --- |
| `125370..125458` window admission | `da81bada36321a3c952587f5a35920e5d366e209591bdd952ad886b37b552bd8` |
| `125518..125698` result/wrap | `6453e1065ab63946b3b6b7a850f1a5cd97d38a96a3fc18e42709b020617092b4` |
| `125698..125764` synchronous orchestration | `297c8a7bce8814e3d23bbecb4596ba692028672b705b317a86ebd9ad2160ebc0` |
| `12CEB8..12CFD8` PCM reservation callback | `bcfe7cb825da5a39f23d8bf4202333f0087bc0530989343732d498b9a161a60b` |
| `12CFD8..12D334` input/end/admission | `f659e94d5dc34ea79887c5ab155afbb646258d00b2e36ac72e711e6a9ce647c7` |
| `12D338..12D4FC` span publication | `003927f1732877ad02c642fb4ee8668112a3650d4f83e92b3d898e732c3e5645` |
| `13FA88..13FBF4` SJRB Get | `740f8f4d2a8d93fb8dd42033f795bb2391212715f8a3e55d841f4fbf3bf9fe93` |
| `13FBF8..13FD58` SJRB Put | `ade26c93553684181eee21fd27401263ccaad5f316091740f6a582b418fdbf13` |
| `13FD58..13FEF0` SJRB Unget | `acfe2605d8938ebba67876575da61e3b2ab737b7ae10a0188dbbe05fbe049b55` |

Also checked: split`1407E0..14083C`, service pass`132C08..132CD8`, and ADXT state
dispatch`134C58..134D1C`. This is static correspondence, not execution coverage.

Concrete blockers before retiring the guest ADXT owner are native SJRB parity;
closed-window original-word fixtures; admitted header/key/coefficient parsing;
source/LSC refill and retained read/filename ownership; loop snapshot/seek and
end/drain continuations; scheduling/stop acknowledgement; and a qualified RNA/
PCM credit/control/position binding with real incarnations. Resource read and
PCM sink interfaces already exist, but no combined stream owner currently
connects all these obligations. No slowdown cause, speedup or completion
percentage is inferred from this inventory.

Source notebooks: [header/input/output](../SYMBOLS_ADXB_HEADER_INPUT_AND_OUTPUT_SERVICE.md),
[window math](../SYMBOLS_ADXB_DECODE_WINDOW_AND_WRAP_ACCOUNTING.md),
[inner phases](../SYMBOLS_ADXB_DECODER_LIFETIME_HEADER_AND_PHASE.md),
[snapshots/callbacks](../SYMBOLS_ADXB_KEY_SELECTION_SNAPSHOT_AND_PCM_CALLBACKS.md),
[SJRB](../SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md),
[ADXT construction/stop](../SYMBOLS_ADXT_CONSTRUCTION_START_STOP_AND_DIAGNOSTICS.md),
[loop/drain](../SYMBOLS_ADXT_HEADER_LOOP_AND_DRAIN_TRANSITIONS.md),
[source/LSC controls](../SYMBOLS_ADXT_SEAMLESS_LSC_SOURCE_CONTROLS.md),
[sample clock](../SYMBOLS_ADXT_SAMPLE_POSITION_AND_ESTIMATED_CLOCK.md),
[RNA adapters](../SYMBOLS_ADXRNA_PS2RNA_INTERFACE_ADAPTERS.md),
[DTR](../SYMBOLS_CRI_DTR_STREAM_DMA_AND_PS2RNA_SERVICE.md),
[worker loops](../SYMBOLS_CRI_WORKER_LOOPS_AND_PRIORITY_HANDOFF.md),
[worker stop](../SYMBOLS_CRI_WORKER_CREATION_AND_STOP_ACK.md), and
[PCM extraction/credits](PCM_OWNER_EXTRACTION.md).
