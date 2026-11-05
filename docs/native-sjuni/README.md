# SJUNI native reconstruction: dependency inventory

2026-11-05. File #1 US only. Status: first-stage static inventory and interface
proposal; native core, adapter and runtime validation remain outstanding.
The mapping/comparison baseline is local commit `733a8ed`.

The initial pilot replaces the **local EE SJUNI metadata queues**. Remote IOP
SJUNI, SJRB/SJMEM, DTR DMA, SJX/DTX acknowledgement and audio decoding remain
explicit dependencies. In particular, a local SJUNI span may name IOP storage;
its numeric pointer is not necessarily an EE-memory or host-memory pointer.

## Evidence and reproduction

Start with the [owned-word SJUNI contract](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md),
[paired stream construction](../SYMBOLS_CRI_PAIRED_LOCAL_IOP_STREAM_POOLS.md),
[SJX bridge](../SYMBOLS_CRI_SJX_BRIDGE_AND_RPC_BOUNDARIES.md),
[DTR consumers](../SYMBOLS_CRI_DTR_STREAM_DMA_AND_PS2RNA_SERVICE.md) and
[owned IOP server](../SYMBOLS_CRI_SJRMT_OWNED_IOP_SERVER_CONTRACTS.md).
The original File #1 ELF SHA-256 is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.

The [machine inventory](inventory.json) records reviewed interval hashes,
original-word checks, direct graph edges, global-reference candidates and
aligned pointer-word candidates. It stores no executable byte arrays.
Regenerate using the local function database and owned inputs:

```powershell
python tools/native_reconstruction/inventory_sjuni.py
```

The current snapshot checks **112 main-image intervals**, **6,188 matching
instruction comments** and **146 omitted zero words**, with no nonzero omissions
or conflicts. It retains **27 external direct edges**, **66 global-reference
candidates** and **nine main pointer-word candidates**. Those are evidence
counts, not counts of native functions implemented. A second generation produced
an identical file; a synthetic incorrect ELF was rejected before analysis.

The checker also verifies the owned CRI IOP module's identity, nine original
symbol bounds/interval hashes and its UUID match with the local interface. It
records current runtime-source hashes, recorded/local submodule revisions,
dirty-state filenames and patch-file hashes. Applied-patch completeness and
matching compiled-library identity remain unverified; no dependency is modified.

The checker rejects changed ELF, catalogue or selected indexed source identities,
conflicting comments, omitted nonzero words and unexpected overlay callers. It
does not execute generated C++, start a process or compile anything. Zero words
omitted from comments are accounted for separately. Indexed refs and direct edges
remain bounded graph evidence, not complete alias analysis. The pointer-word
search covers file-backed main ELF segments; it excludes overlays and BSS.

## Native status

| Milestone | Status | Evidence / remaining work |
| --- | --- | --- |
| Local mechanics mapped | Reviewed statically | Four linked lists, free-node list, mode-dependent split/merge and borrowed payloads. |
| Construction and retained users | Initial inventory reviewed | Ownership paths below; global candidates and direct edges retained in JSON. |
| Error, arithmetic and synchronization contract | Static review | [Synchronization/error findings](SYNCHRONIZATION_AND_ERRORS.md); host scheduling parity remains open. |
| Remote/runtime boundary | Static review | [Remote/DTX findings](REMOTE_AND_DTX_BOUNDARY.md); current fallback semantics require reconciliation. |
| Native interface | Proposed | [Contract and adapter design](CONTRACT_AND_ADAPTER.md); admission and ownership rules require implementation checks. |
| Core implemented / adapter integrated | Pending | No entry points redirected. |
| Behavior comparisons / real-consumer validation | Pending | No game, audio, DMA, replay or performance run in this stage. |
| Consumers migrated / dependency removed | Pending | All existing runtime dependencies remain. |

## Construction and retained-pointer map

All addresses and field offsets below are hexadecimal. Counts written as ordinary
numbers are decimal. These are original source paths, not measured live objects.

| Producer / user | Retained representation and operations | Migration consequence |
| --- | --- | --- |
| `12A1E8`, `15E6A0` / `12A388`, `15EA00` | Shared initialization/release calls `140020` / `140070`. | Preserve first/last reference behavior; movie and audio lifetimes overlap. |
| `13DB48` | Creates local SJUNI at `13DD58`, mode 1, node area `221780 + 100*i`, size `100` bytes = 16 nodes. Saves result at paired record `+8`. | Preserve local handle identity across users; node bytes are metadata capacity. |
| `13DB48` | Paired records `221480`, stride `18`: remote `+4`, local `+8`, binding `+C`, initial borrowed payload span `+10/+14`. Publishes `{IOP cursor,4000}` to local pool 0 at `13DDB4`. | A 16 KiB borrowed IOP span must not become a 256-byte owned ring. |
| `141490` | SJX binding `229A90`, stride `14`: local `+4`, remote `+8`, selector `+C`, remote binding ID `+10`. Sends local address and binding address through RPC. | Pointer escape crosses the process-local queue abstraction; preserve wire tokens while the remote protocol remains. |
| `13DF20`, `13DF98` | Reserve/release paired record byte 0. | Releasing a channel reservation does not destroy its shared stream. |
| `13E770` | Group `223880`, stride `60`: paired pointers `+8+4*i`; DTR pointers `+10+4*i`; original input streams `+18+4*i`. Passes paired local stream as DTR destination at `13E918`. | Original decoder input and paired destination are distinct stream objects. Do not redirect every SJ call to SJUNI. |
| `138AB8` | DTR record `21BC08`, stride `40`: source SJ `+4`, destination SJ `+8`, in-flight spans `+C/+14`. | Both source and destination reservations outlive the call while DMA is pending. |
| `138650`, `138BE0` | Generic SJ Get/Unget/Put calls around DMA completion and stop; destination is typed SJUNI only through the group constructor above. | Preserve when each pool regains ownership. The core must not copy or free payload bytes. |
| `140FB8`, `141158` | Collect from binding-selected local pool through vtable `+18`; emit borrowed span and remote/generation metadata. | Reservations escape in descriptors until completion callback. |
| `140F18`, `1410C8` | Return through vtable `+20`; first uses descriptor selector, second always pool 1. | Keep callback pool policies distinct. A completion is not interchangeable with unget. |
| `12C4E0`, `12C520`, `13ECB0`, `13ECF0` | Follow group → pair → local, invoke byte count vtable `+24`, then convert by two. | Keep byte sums, halfword units and node counts separate. |
| `13ED28` | Counts pool 0, then Get/Put/Get/Put to consolidate free storage before starting DTR. Requires one span of `4000`. | Queue order and adjacency merging are behaviorally observable. |
| `13F1C8` → `1314E0` | Returns local handle; diagnostic consumer invokes counts for pools 1 and 0 at `131530/131548`. | Handle escapes through a public accessor, even outside ordinary transfer service. |
| `13EAC0` | Releases DTR slots, remote group and paired reservations. | Shared local SJUNI remains alive. Stop/quiescence belongs to upper callers. |
| `13DE40` | Remote destroy → local vtable destructor at `13DE94` → SJX unregister → clear paired record; frees owned IOP arena last. | Existing order does not itself prove that callbacks/DMA are quiescent. Never recycle a native handle on reservation release alone. |

The current direct-call graph has one external local-constructor caller, the
paired-pool initializer. Most queue users call through vtables. The 27 external
direct edges into `140000..14083F` also include the general span-split helper
`1407E0`, used by ADXB, file streaming, ADXT, DTR and MPEG/Sofdec parsers. Those
calls establish a shared descriptor helper, **not** that every input is SJUNI.
Keep that helper separate from the first queue replacement.

The exact aligned main-ELF word search finds nine pointer words, all in the
reviewed SJUNI vtable. It does not rule out computed pointers, remote copies,
overlay tables or callbacks installed dynamically.

## Direct layout and state ownership

The reviewed paired consumers obtain the object's vtable at `object+0` and call
its methods; their reads at `pair+8`, `group+8` and `DTR+8` are fields of the
**containing records**, not direct reads of SJUNI queue heads. No external
queue-head or node mutation was established in those reviewed paths. This is a
bounded negative result; neither the graph nor the pointer-word search proves
all aliases have been closed.

The original layout remains observable: the 64 pooled objects at `228C98` are
48 bytes each; nodes live in the caller's supplied arrays. Reset writes node
links and payload descriptors; destroy clears the object but does not free
nodes or payload. A native adapter must mirror these updates or establish that
every observer has migrated. An opaque host pointer written into `pair+8` would
break remaining generated consumers and remote-token packing.

## Questions to close before redirecting entries

1. Finish field-access closure for handles that escape through SJX/RPC and
   `13F1C8`; trace IOP treatment of EE tokens and node storage separately.
2. Establish original/current host critical-section behavior, callback reentry
   and teardown quiescence. A recursive mutex proposal is not scheduler parity.
3. Reconcile remote compatibility fallback capacities/UUIDs with the owned IOP
   implementation. Verify dispatch into that fallback before attributing impact.
4. Define admitted input domains from callers, especially signed requests,
   wrapped arithmetic, aliased output descriptors and callback side effects.
5. Preserve an independent original implementation for operation-sequence
   comparison. No C++ compilation, synthetic parity run or game retest has yet
   been performed for the new core, which is still pending.

Next deliverable: implement the independently testable native core after its
admitted-domain contract is explicit, then build the temporary adapter without
enabling it by default. Compatibility removal follows consumer migration and
validation in the [transition plan](../NATIVE_RECONSTRUCTION_PLAN.md).
