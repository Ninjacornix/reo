# SJUNI remote, SJX and DTX boundary

Static inventory, 2026-11-05. This document specifies the boundary a future native SJUNI adapter must preserve. It implements no adapter and reports no runtime test, audio playback, reproduced failure or measured slowdown. No game, build, replay, guest execution, process attachment or live-memory inspection was performed.

The local EE SJUNI pointer, remote IOP SJUNI handle and SJX binding identity are **three different objects**. A local queue replacement must not collapse them. The original transport carries borrowed span descriptors; the current runtime also has a separate compatibility implementation whose state and playback policy are not identical to the original IOP implementation.

All guest addresses, offsets, sizes, selectors and PCs below are hexadecimal unless a decimal unit is stated. `IOP:` addresses are module-relative, never resident EE PCs.

## Evidence and applicability

The owned main ELF is `game_data/SLUS_207.65`, SHA-256 `06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`. Original instruction comments were read from the complete generated intervals and important bytes independently read from that ELF. The owned `build-function-index/owned-iop/cri_adx_driver.irx` has SHA-256 `456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7`; its original symbols, complete inspected function bytes and actual registrations supply the remote evidence. The [IOP provenance and read-only inspector](../SYMBOLS_CRI_SJRMT_OWNED_IOP_SERVER_CONTRACTS.md) identify the source ISO member and explicitly separate IOP and EE namespaces.

Earlier wording that the remote implementation was unavailable in the [initial SJX notebook](../SYMBOLS_CRI_SJX_BRIDGE_AND_RPC_BOUNDARIES.md) is superseded by the later owned-server investigation. This report does not edit those historical notebooks or import new mapping credit. The remote constructor/reset/count and SJX callbacks below have additional direct instruction evidence; complete behavioral equivalence of every EE and IOP SJUNI method is not established here.

## Creation is paired, not one object crossing an interface

| Original evidence | Contract relevant to a native adapter |
| --- | --- |
| [`13DB48`](../../recomp/config/output/sub_0013DB48_0x13db48.cpp), PCs `13DB80..13DB9C`, `13DC50..13DC58` | Default configuration is 16 paired slots and IOP arena size `41000`; it clears 32 physical paired records, each `18` bytes, at `221480`. The configured count has no local cap against those physical records. |
| `13DCC0..13DCD0` | Calls remote `140B98(1, IOP_cursor, 100)`, then advances IOP cursor by `100`. This is **256 bytes of node storage**, not 256 bytes of audio payload. |
| [`140B98`](../../recomp/config/output/sub_00140B98_0x140b98.cpp), PCs `140BB4..140BD8` | Packs `{mode,nodes,node_bytes}` at `264600`, requests operation `22` with three input words and one output word through `139460`; returns the copied response word. Wire RPC number is `422`, not direct DTX function `2`. |
| IOP `sjrmt_uni_create:658C..65CC`, call at `65B0`; `SJUNI_Create:5AB4..5B7C` | Actual handler loads the three words and calls IOP SJUNI. Constructor scans 64 records of `30` bytes, stores node base at object `+C`, and stores signed-truncating `node_bytes/16` at `+10`. For this caller, `100` means **16 nodes**. |
| IOP `SJUNI_Reset:5BC8..5C48` | Builds a free chain over those external nodes, zeroes node span words `+8/+C`, and clears the four queue heads. Reset does not invent a byte-capacity payload buffer. As locally, zero/negative node-count admission is not repaired by this body. |
| `13DCD4..13DCF4`, call at `13DD58` | Calls local EE `1400C0(1, 221780 + 100*slot, 100)`, stores its pointer in paired-record `+8`. This is a separate EE pool object with separate EE node storage. This **direct constructor call** must be covered even if a higher ADX adapter is intercepted. |
| `13DDA0..13DDB8` | Writes `{IOP_cursor,4000}` to paired-record `+10/+14`, passes its address to local SJ vtable slot `20`, pool `0`, then advances cursor by `4000`. The payload is a **borrowed 16 KiB IOP-addressed span** represented by the local EE queue. The constructor did not allocate it. |
| `13DDBC..13DDD0` | Registers `(localSJ,remoteSJ,1)` through `141490`; stores the returned EE binding pointer in paired-record `+C`. Each slot consumes `100 + 4000` IOP bytes; 16 default slots consume exactly `41000`. |

Node storage, payload storage and stream records therefore have independent ownership and address domains. The local stream can legitimately contain a pointer naming IOP payload memory. Treating every chunk pointer as an ordinary host pointer, or treating the remote constructor's node-storage span as payload capacity, changes the contract.

The local SJUNI UUID at main `23DA78` and owned IOP UUID at `IOP:9940` are the same 16 bytes: `a34f532e97afd211a5270060089448bc`. That confirms the interface identity in these two owned artifacts. It does not make their object addresses interchangeable or prove all method implementations equivalent. UUID lookup copies bytes; it does not return a host object address.

## Stable guest layouts and retained identities

| Object | Guest-visible fields used at this boundary | Retention and direct access |
| --- | --- | --- |
| EE paired record, stride `18` | `+0` reservation byte; `+4` remote stream handle; `+8` local stream pointer; `+C` EE SJX binding pointer; `+10/+14` original IOP payload span | Constructor populates the record once; `13DF20` reserves an existing record, and `13DF98` merely clears its reservation byte. Reserving/releasing a group does not create/destroy its streams. |
| EE PS2RNA group, stride `60` | Paired-record pointers at `+8+4*channel`; DTR pointers at `+10+4*channel`; retained source SJ pointers at `+18+4*channel`; remote RNA identity at `+20` | `13E810..13E818` saves paired records; `13E890..13E8A4` reads paired `+4` into remote create input; `13E910..13E920` passes paired `+8` as DTR destination; `13E9D0..13E9E0` retains source streams. The valid intended channel domain must be preserved separately; arrays are not generally bounded by these loops. |
| EE SJX binding, stride `14`, 32 slots at `229A90` | `+0` active byte; `+2` generation halfword; `+4` local SJ; `+8` remote SJ; `+C` source pool; `+10` remote **binding** identity | `141510..141540` stores fields and sends `{localSJ,remoteSJ,pool,EE_binding_pointer}` to operation `0`; its result at `141548` becomes `+10`. This remote binding is distinct from binding `+8`'s remote SJ. |
| IOP SJX binding, stride `14`, 32 slots at `IOP:116A0` | `+4` IOP SJ; `+8` EE SJ value; `+C` opposite pool; `+10` EE binding pointer | `IOP:6D8C..6DD0` reverses the two stream endpoints, changes incoming pool `1` to `0` and every other incoming value to `1`, saves the EE binding pointer and returns the IOP binding pointer. It does not return an IOP stream pointer. |
| Local SJ object | Object word `0` is a guest vtable pointer; slots `C/10/14/18/1C/20/24/28` are destroy/UUID/reset/get/unget/put/byte-count/availability | Reviewed external consumers dereference the vtable and invoke guest methods; they do not directly read SJUNI free-chain or queue-head fields. This is a bounded observation for the traced consumers, not an all-program no-peeking proof. A host-only object without a callable guest facade breaks these uses. |

[`13F1C8`](../../recomp/config/output/sub_0013F1C8_0x13f1c8.cpp) returns `group.pair[channel]->localSJ`; [`13F1E0`](../../recomp/config/output/sub_0013F1E0_0x13f1e0.cpp) returns the paired remote stream handle. Neither retains another reference, validates the channel or normalizes identities. [`12C560`](../../recomp/config/output/sub_0012C560_0x12c560.cpp) and [`12C598`](../../recomp/config/output/sub_0012C598_0x12c598.cpp) read group through context `+C`, select paired remote `+4`, call remote byte-count operation `29` with pools `1/0`, and logically shift the result right by one. Those upper counts are halfword units, not a reason to change SJ queue byte units or reinterpret errors as signed sample counts.

The diagnostic [`1314E0`](../../recomp/config/output/sub_001314E0_0x1314e0.cpp) separately obtains channel-zero local and remote handles, calls local vtable byte counts, and queries remote counts. It reinforces that the identities coexist and are independently observable.

## Descriptor round trip and payload movement

For the paired audio path, the ownership cycle is:

1. Local SJUNI pool `0` initially owns the borrowed IOP payload span. [DTR](../SYMBOLS_CRI_DTR_STREAM_DMA_AND_PS2RNA_SERVICE.md) obtains source stream pool `1` and local destination pool `0`, splits metadata to a transfer quantum, and submits the actual source-to-IOP **payload DMA**. Only after DMA status completes does DTR put the destination span into local pool `1` and return the source span to source pool `0`.
2. EE SJX collector [`140FB8`](../../recomp/config/output/sub_00140FB8_0x140fb8.cpp) gets local binding pool `1`. PCs `141024..141048` emit a `10`-byte descriptor: command byte `0`, source pool byte, generation halfword, remote **binding** identity, original pointer and original length. `141058..141070` invoke GetChunk with request `7FFFFFFF`. It scans 32 bindings, takes up to 128 descriptors, then writes the block count. It reserves spans; it does not copy payload bytes.
3. The command block starts with count at `+0` and descriptors at `+10`. SJX DTX ID `0` transports the descriptor block, separately from the DTR payload transfer. Owned IOP `sjx_rcvcbf_iop:6B3C..6BE8` resolves descriptor `+4` as an **IOP binding pointer**, reads binding `+4` as the IOP stream, and puts the borrowed span into remote pool `1` (`6B88..6BB0`). No payload-copy loop occurs in that callback.
4. After the IOP consumer returns free spans to its stream pool `0`, IOP `sjx_sndcbf_iop:6BE8..6D08` obtains that pool and emits descriptors whose `+4` is the saved **EE binding pointer** (`6C84..6CA8`). It preserves the span words and pool byte; it does not substitute the remote SJ handle for the binding.
5. EE completion [`140F18`](../../recomp/config/output/sub_00140F18_0x140f18.cpp), PCs `140F78..140F90`, treats descriptor `+4` as an EE binding pointer, reads binding `+4` as the local SJ, and calls PutChunk into the descriptor's original pool. For the paired cycle this is local pool `0`. The returned span becomes reusable. Completion is not equivalent to permission to manufacture extra free bytes.

The other collector `141158` has the same original complete bytes as `140FB8`; the other receiver `1410C8` instead always puts into pool `1`. These distinct entry policies must remain distinct. The IOP has the corresponding separate `sjx_rcvcbf:6970..6A1C` and `sjx_sndcbf:6A1C..6B3C` pair. Do not merge all four callbacks under one inferred direction.

**Generation is carried, not validated by these original receivers.** Both EE receiving callbacks and both complete inspected IOP receiving callbacks branch on command byte and dereference the binding, but never read descriptor halfword `+2` for a generation comparison. EE `1415D0` only increments binding generation locally; it sends no reset RPC. Adding generation rejection could be a later safety change, but it is not an equivalence claim for the original receiver.

[`13ED28`](../../recomp/config/output/sub_0013ED28_0x13ed28.cpp) imposes a concrete consolidation requirement: before starting each DTR it requires local pool-zero byte count to equal group capacity `4000` (`13ED88..13EDAC`), gets/puts/gets the pool span (`13EDF8..13EE48`), and asserts that the resulting single span length equals that capacity (`13EE54..13EE84`). Mode-one adjacent merging and original pointer/length conservation are therefore observable requirements, not optional optimizations. Returning unrelated fragments or credit before ownership permits it can fail this contract even if total counters look plausible.

## DTX acknowledgement and teardown are separate lifetimes

The [complete DTX notebook](../SYMBOLS_CRI_DTX_TRANSFER_CONTEXT_AND_ACKNOWLEDGEMENT.md) describes the original `44`-byte context, ID-zero SJX versus ID-one RNA command mailboxes, callback fields and cache/DMA operations. The essential original ordering in `139198` is:

| Original PCs | Ordering that remains visible |
| --- | --- |
| `1391CC..1391DC` | Inflight byte must equal `1`; local signed sequence must be strictly less than trailing uncached sequence. No modular wrap comparison is implemented. |
| `1391E4..13920C` | Cache synchronization precedes completion callback `(context,EE_payload,payload_length)`. The callback may return queue spans. |
| `139210..13921C` | Only after the callback, clear inflight and copy observed sequence. |
| `139250..139278` | Fill callback reserves outgoing descriptors, then increments/writes sequence. |
| `13927C..1392E0` | Cache publication and SIF DMA submission precede saving DMA result and setting inflight; there is no local DMA-failure recovery in this DTX body. |

Mailbox acknowledgement, payload-DMA completion, queue commitment and audio consumption are separate events. A native queue must not silently collapse them into synchronous completion or derive original game updates from their counts. The original mailbox has `880` total bytes, of which `40` is trailing transport storage; a maximum descriptor block needs `10 + 80*10 = 810` bytes.

Global paired teardown `13DE40` destroys remote SJ first (`13DE78`), local SJ via vtable `C` next (`13DE94`), unregisters binding next (`13DEA8`), then clears the current paired record. It does not independently join a transfer before those operations. Unregister `141588` sends binding `+10` then clears only active byte (`1415B0..1415BC`); stale pointer/pool/generation fields remain. Group teardown `13EAC0` releases DTR records, destroys the remote voice and clears pair reservation bytes; it does not destroy the globally paired streams.

`139110` disables DTX submission and services all active contexts in a loop until inflight clears before remote destruction. There is no timeout. Native sidecar storage must survive callbacks/queued descriptors until a deliberately specified quiescence point. Guest-visible destruction ordering must remain documented separately from safe host-memory reclamation; the existing guest order alone does not prove concurrent teardown safe.

## Current compatibility source is a separate implementation

This is a source snapshot, not a statement about which library a running executable linked. The parent checkout records PS2Recomp gitlink `c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f`; the initialized submodule reports the same HEAD and has local changes, including the runtime files below. No dependency changes or build were made in this investigation. Local source hashes, rather than the clean commit alone, identify this compatibility implementation.

[`reo_override.cpp:1782`](../../recomp/overrides/reo_override.cpp:1782) configures service `90000200` and opaque URPC range `001E0000..001EFF00`, leaving handler-table bases zero. [`PS2DtxCompatLayout`](../../third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime.h:409) defaults handle stride to `20`. RPC source first permits an existing hardware-bridge handler, then uses configured guest URPC handlers only when a table entry exists; otherwise its fallback handles the service. The override does not replace `1400C0` or make local SJUNI objects opaque.

| Current source evidence | Static compatibility boundary or divergence |
| --- | --- |
| [`Helpers/State.h:385`](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/State.h:385), `DtxSjxState`, `DtxSjrmtState` | Host maps retain separate SJX endpoints, EE binding address, generation, and remote stream counters. Handles are numeric guest values, not host pointers. The allocator checks multiple object maps; its exhaustion path returns the base again, so perpetual uniqueness is not guaranteed merely by configuring a range. |
| [`RPC.cpp:2080`](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp:2080), cases `20/21/22` | All three stream types share `DtxSjrmtState`. UNI case `22` takes `{mode,nodes,node_bytes}` but stores `node_bytes` as ring `wkSize`, initializes that many `roomBytes`, and treats node base as `wkAddr`. For the original paired caller this is `100` bytes, whereas the owned constructor means 16 metadata nodes plus separately borrowed `4000` payload. This is a demonstrated **representation/semantic difference**, not a reproduced playback fault. |
| `RPC.cpp:2125..2128`, case `24` | Compatibility UUID is synthesized from word `53524D54`, handle, address and size; owned EE/IOP SJUNI expose the fixed UUID bytes above. A native facade must not infer real SJUNI identity from the fallback's synthetic identifier. |
| `RPC.cpp` cases `25..2A` | Reset/get/unget/put/count/availability operate ring counters and offsets, pools effectively `0/1`, instead of four linked borrowed-span lists. Unget/Put consume length, without preserving all span identity/layout semantics of original SJUNI. Capacity clamping and default-size normalization are compatibility policies, not original invalid-input behavior. |
| [`RPC.cpp:901`](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp:901), `dtxApplySjxPayload` | Resolves descriptor binding handle through host map, checks line, and rejects nonzero stored generation mismatches. Non-audio route copies into the fallback ring; audio route queues through host audio and retains a reply. This is more than the original metadata-only IOP Put callback. A native SJUNI change must preserve the actual chosen compatibility route or replace it coherently. |
| [`RPC.cpp:681`](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp:681), `collectSjxReplies` | Pending audio keeps original whole-chunk reply identity while separately crediting consumed prefixes to counters. It can enqueue the whole reply when `consumed + kIopPcmBufferBytes >= endByte`, rather than simply after complete host consumption. Do not summarize this as exactly the original IOP consumption or as an unconditional immediate reply. |
| [`RPC.cpp:1146`](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp:1146), `noteDtxSifDmaTransfer`; [`Stubs/SIF.cpp:734`](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp:734) | Matching host DMA notification increments the mailbox footer ticket, applies ID-zero SJX or ID-one RNA commands, consumes compatibility streams, then publishes SJX replies. Original guest `139198` subsequently observes the ticket and dispatches its completion callback. Neither the ticket nor the source comment proves active audio parity. |

The audio-specific route overwrites some counters using `4000` capacity at current `RPC.cpp:704` and `RPC.cpp:1022`, so it would be incorrect to conclude from constructor `wkSize=100` alone that all current audio is constrained to 256 bytes. The non-audio ring representation and the constructor/reset/general-operation contracts still differ. Their actual reachability and symptom impact remain unmeasured.

SJRMT response-size quirks also cross this boundary: original `140E20` requests only one response word yet copies the second output word; the owned server `IOP:67E8` writes two. `139460` ignores transport status and preserves shared response storage. Fixing that discrepancy or changing failure behavior should be a separate reviewed change with explicit compatibility tests, not an accidental side effect of a local queue rewrite.

## Requirements for the first native adapter stage

- Preserve a stable 32-bit **guest facade** for the local object and callable guest vtable routes, including the direct `13DD58 -> 1400C0` creation path. Keep host pointers in sidecar state. Trace/fix every bypass before declaring the old guest layout removable.
- Keep typed identities for local SJ, remote SJ, EE binding, remote binding and DMA context. Preserve guest-visible paired/group/binding layouts and their borrowed-pointer lifetimes while unmodified consumers still dereference them.
- Keep node capacity separate from payload byte capacity; preserve all four pools, mode-one split/adjacent merge rules, FIFO/Unget ordering, original span identities, callback/error behavior and valid-input arithmetic. DTR and SJX own reservations across calls.
- Preserve the reviewed pool routing and whole-span consolidation needed by `13ED28`; reserve, data-ready, returned-free, DMA-done and playback-credit transitions need separate states even if their host implementation is faster.
- Keep the current remote compatibility implementation outside the first local-only change unless its replacement also supplies coherent RPC/SJX/audio/DTX semantics. Freezing that boundary exposes the known mismatches; it does not certify it as correct. Full remote reconstruction would additionally need original IOP SJUNI method/consumer and playback-policy parity checks.
- Specify quiescence and reclamation for destroyed/reset objects, callbacks, queued descriptors and recycled handles. Generation checks, timeout behavior, exhaustion, malformed spans, response-size correction or different game-speed timing are intentional later changes, not presumed equivalence.

No runtime tests were performed. Useful later isolated tests should cover the exact paired construction (`100` node bytes plus `4000` payload), distinct local/remote/binding identities, source-to-destination DTR ownership, descriptor return through EE binding, two callback pool policies, adjacent-fragment consolidation, reset with outstanding reservations, stale binding/generation, remote-count halfword adapters, and last-reference teardown with a pending acknowledgement. These are validation requirements, not claims that test infrastructure or a native implementation already exists.

## Remaining unknowns

- Which playback paths and compatibility branches are reached during the player's incidents; no cost or correctness diagnosis follows from this inventory.
- Complete EE-versus-IOP SJUNI equivalence for methods beyond the directly inspected constructor/reset/count and connected callbacks; same UUID alone is insufficient.
- All indirect consumers and every direct peek into a local SJUNI object outside this traced paired/DTR/SJX/ADX boundary. Reviewed callers predominantly use the vtable, but global absence is not proved.
- Original IOP audio-buffer/read-ahead timing versus host early whole-reply threshold and prefix counter credit; the full owned audio service must constrain a replacement.
- Safe host reclamation when original teardown destroys a stream before unregistering its binding; the original bodies provide no standalone concurrent-quiescence proof.
- Which modified runtime source hashes correspond to the user's current executable and matching static libraries. This report is not build provenance.

## Snapshot hashes and repeatable inspection

The inspector `python build-function-index/read_insns.py main <entry...>` reads original comments only; `python build-function-index/owned-iop/inspect_iop.py <symbol...>` decodes owned bytes only. Neither runs guest code. Main bytes can be independently checked through `tools/function_index/index.py:Elf.read`. This report is the sole written artifact for this task.

| Complete original interval, end exclusive | Words | SHA-256 of original bytes |
| --- | ---: | --- |
| `13DB48..13DE40` | 190 | `20813b0c4b1ae8629af2a0940fe7f2e63766dd71187cc55af23da7c25941c51d` |
| `13DE40..13DF20` | 56 | `092a929d0e9a57b696fa98f88febfd4b49eca31a84daf4a4c55b71ce8fea60fd` |
| `13E770..13EAC0` | 212 | `a86158ca903639e0753502c9f67e875cb486f3ff654135afcd0cd79e57cdfd12` |
| `13EAC0..13EB88` | 50 | `1c7849340cdf616cd99d7b34caa2c6f3fb7ffc4734f4231a1a50fb690277dd7e` |
| `13ED28..13EEE4` | 111 | `1a8e042fe11bb35ba9f4e13b04d7968aa7a11908a6ed802fe63304c1e6ce6fe0` |
| `13F1C8..13F1DC` | 5 | `b7539e6cd04203b97a098257e76f822273c205a83e7992ae2ae57dc4aff0b5f2` |
| `13F1E0..13F1F4` | 5 | `3965cc14cffa14ad2350296d2f8bd82efd000c98fb477372d3ff4b86b0f2583d` |
| `140B98..140BEC` | 21 | `793bfbf3b996c552bcddc8d8e223f2f0beae67e182db83d04e49399abf24bd4a` |
| `140F18..140FB4` | 39 | `480671764bb2123b2025bc2006aea4e651b6b362dce5d8a5960e965c5613f831` |
| `140FB8..1410C8` / `141158..141268` | 68 each | `b28678757337818a7efb0d9f761983f05b4939d95223b61404ad565fa8e1ed5c` |
| `1410C8..141158` | 36 | `4d2f6f53748e11296f850c8ad8a4fd76dd38a2b1e766d61dc8e9cc88b1886b2f` |
| `141490..141588` | 62 | `99da7a12505644cefe909dcce7cb4530d7a4746b55d1c5a0ff2ac42f002ab1de` |
| `141588..1415CC` | 17 | `065752c6154a05b6f24aa4b2bdb97349c08a2d3b3217d80fdedb08bed4cefbf0` |
| `1415D0..1415E0` | 4 | `c7c4e5ca6523d92ea863f45d29af40fd46199fe84797af5e608d2c99582d24b6` |
| `139198..1392F8` | 88 | `09c3d4707022c19e4bec922ed5a9d3eebde4843d7d9ef7315984a8d0eafde97d` |
| `139110..139174` | 25 | `92707ed5c5629841b27c6f756e2aaccb0cb8a0621170f1a733babe04e7d0d0b8` |
| `139460..139568` | 66 | `6450ba5b6f2dce2c0ab15abf2e116490b1dc5a9e03f0fa2b8abce9223f0cf227` |
| `12C560..12C594` | 13 | `c3d9f7bde6443fe633726c65e36b6fff96e51d6e607b899380716643d614b700` |
| `12C598..12C5CC` | 13 | `a1020f5adee9f7871b00f09e9b819a0cdc5412b2c201f347a4bfd3279976c7af` |

| Complete inspected IOP function | Bytes | SHA-256 |
| --- | ---: | --- |
| `sjrmt_uni_create:658C` | 64 | `c37367afdfae438926d47fec23383a41d9a40e3b9ae53bd051fe0faad9f61806` |
| `SJUNI_Create:5AB4` | 200 | `73ad0a472f3d915266572e22ac141c38da3542881529448a17516d7004d302c5` |
| `SJUNI_Reset:5BC8` | 128 | `b850d0e4e6cce93e5a9fbd7cc4da9178fcbd72a96a7533c888bc0ca619d263a2` |
| `SJUNI_GetNumData:5C48` | 116 | `885e5216e1f4e1297eca10a0559292982096862e3096acc73105f1d5830b2cd7` |
| `sjx_create_rmt:6D28` | 192 | `1d91ad3a10e140788a6df69d40021dc3a3bb5fe854b13a561fff7055c38ef99d` |
| `sjx_rcvcbf_iop:6B3C` | 172 | `3f83f9feeeb21afde96056a898c967a73fc91a1f2d1f70a7743ea75abe11f36c` |
| `sjx_sndcbf_iop:6BE8` | 288 | `a2fe800459cbec1553d2c24798930eb4c28ace2d3dffd79a608212027b6cfd6a` |
| `sjx_rcvcbf:6970` | 172 | `6ad55412b6f3dd949975e4932f206b8a9da89275ccd575ba4758b404034eb1c8` |
| `sjx_sndcbf:6A1C` | 288 | `0d4d864cc47b1c2eee7d83d471984f0541aabc3e4930f7ef8ffc9ce0563ce138` |

| Modified/current source snapshot | SHA-256 |
| --- | --- |
| `recomp/overrides/reo_override.cpp` | `3c07a747bdab6f4979198475ae31cea9ba2b4f4a1790ceccef9f763dd21aff67` |
| `third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime.h` | `d0f0d4811e09dde6af0c1bd025ac046241e044fd29c3dcf975b4b114530545ee` |
| `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/State.h` | `4cab412ab2c6a54e3ff14a6f619ce61c850cae8e3b80d92d86c3bef22eb1b4b8` |
| `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp` | `3c9f279e0431182fc6f932638c5e62e99ed91e1d33239d2a8a7af291f0a143d9` |
| `third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp` | `d7a33d8ad3c5c348b1698f1340457301d177b94c63c66e247c445b2c7fcba985` |
