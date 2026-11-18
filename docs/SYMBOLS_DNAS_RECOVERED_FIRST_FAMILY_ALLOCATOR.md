# O5 first-family allocator: complete owners and decoded diagnostics

Static File #1 US review, 2026-11-05. Owned o5/insdnas.bin, runtime overlay7, base6E0000, SHA-256 **97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e**. This notebook supports six authoritative rows **refined in place** in [DNAS memory](SYMBOLS_DNAS_MEMORY.md), covering dispatcher6E2828's18 spans from [the o5 copied-data inventory](STATIC_DNAS_O5_RECOVERY_INVENTORY.md). It adds no duplicate imported rows, string functions or fragment credit. No guest execution/emulation, game, build, network request, attachment, live-memory read, owned-image change or generated/runtime-code edit occurred.

## Complete review and restoration limits

Unique private [review_dnas_o5_allocator.py](../tools/function_index/review_dnas_o5_allocator.py) independently rereads the18-key metadata table7096A0, original entry/paired descriptors, exception records and both schedules, then reconstructs copied words and verifies exact original payload restoration. It binds each actual clear entry call and writes the [addressed listing](../build-function-index/dnas-o5-allocator-review/words.txt) and [receipt](../build-function-index/dnas-o5-allocator-review/receipt.json). All1726 listed words were read:577 reconstructed words and1149 clear words. The577 include125 unchanged exception words,246 branch-skipped inline ASCII/NUL words and331 instruction/padding words. All202 direct branch targets land in reviewed code regions; no instruction field remains undecoded.

Six joined owners account for1251 instruction/padding words plus246 inline-data words. An additional229 clear words recheck already mapped initialization/reference/statistics between those owners. EE MULT's optional encoded GPR destination is preserved, including byte accounting at6E14F4; it writes the run-byte product toA2 as well as HI/LO.

**All18 paired forward descriptors are skipped by the reviewed paths.** Every owner contains only the corresponding even-mode entry calls to6E2828, never a forward restore call. Some recovered tail paths exit earlier. Exact paired-metadata arithmetic restoration proves what applying that independent schedule would produce; it does not prove that the guest executes it on return. The payload-end branches skip odd-mode descriptor data and continue ordinary allocator work. This resolves all18 previously pending first-family restore bindings locally. No unrelated external transform/reset mechanism, concurrent-entry safety or runtime header state is inferred.

| Complete owner, end exclusive | Protected starts, common6E prefix | Complete original interval SHA-256 |
| --- | --- | --- |
|6E0698..6E0838|0794|`a65e3fee403bfc336f2a0a8d4b71ba42317b8030038e0c57275d127af8451ea9`|
|6E0838..6E0F38|0918,0AAC,0C1C,0D30,0E40|`3dc0c2548e877f75d0e059ec4ae3561f0a044a5794f3b3ea2cfe391efa489e38`|
|6E0F38..6E1B44|0FC8,1230,1314,1400,1728,1848,1954|`ecf4608f3e1231e6706e2f2b1b06cd921cbf3ffc1342b50681db1be213b4b263`|
|6E1ED0..6E2204|1F50,2168|`f15abe6c1530617ce5f09cc75757ae908aabcc7ab3f9f1fbd6ddcce35aef8007`|
|6E2208..6E23A4|2280|`854af2d987e2b2ff682158ab91a0a88333f1b46487a40065d9419b7ebfaf71f5`|
|6E23A8..6E2778|2430,26D8|`bb0fdf80242e61925290c3f5803001219fe060d3811b261fb0a070557bd1a5b8`|

These are independently hash-bound o5 owners. The [o4 allocator](SYMBOLS_NETDNAS_RECOVERED_PRIVATE_ALLOCATOR_AND_DIAGNOSTICS.md) has similar local mechanics but different overlay identity, code addresses, arena, metadata and policy state. Shared structure is not permission to substitute one overlay's globals or protected selectors into the other. Header-self-pointer/cache effects were not performed or simulated; arbitrary aliases into code/header/control state are not admitted by this local review.

## State and internal allocation

Initialization709D00 is the reference count; page size711B0C, shift711B10 and mask711B14 are initialized to4096,12,FFFhex. Arena711BC0 has5E800hex bytes. Additive address adjustment711B20 and index origin711B24 derive page indices; last admitted index is711B28.711B2C serves page-map and size-class-head indexing. Free-run list711B38 and cached20-byte record711B68 retain next/previous links at+0/+4, start/end at+8/+C and size+10. Slab headers retain page base+4, u16 slot bytes/exponent+8/+A, free/total counts+C/+E and bitmap+10.

Policy words:711B4C enables internal allocation-failure notice;711B50 stops internal allocation/resize in a NOP loop and makes release return;711B54 forces resize movement;711B58 enables public OOM notice;711B5C maps zero-size allocation toNULL and zero-size resize to release;711B60 requests allocation zero-fill;711B64 requests D0 capacity fill. Semaphore711B18 and guard depth711B1C are separate. Last diagnostic context is711B6C; counters711B70/74/78 count allocation/resize/release attempts.711B7C is byte accounting,711B80 page-unit accounting; high-water exports retain their existing clear contracts.

6E0698(size) reads711B50 once. Nonzero enters NOP6E06B8..06D0 and branches back without reloading; a later flag clear is not noticed by that local loop. Otherwise unsigned wrap of size+pageSize yieldsNULL. Size<=pageSize/2 uses6E0318's power-of-two slab allocation, minimum16; larger sizes use6E0108's rounded page extent. A NULL with711B4C enabled enters recovered0794, skips inline `allocation failed.` bytes and calls6E0080. That original callback is JR/NOP, preservesV0 and does not terminate. Successful allocation with711B60 enabled memset-zeroes exactly requestedSize bytes, then returns the saved pointer. It does not locally check initialization or take a lock. Internal size0 may still select a minimum slab when the public zero-size policy does not suppress the call.

## Internal resize6E0838

Inputs oldPointer=a0,newSize=a1. The same one-read711B50 stop gate precedes pageIndex=((oldPointer+711B20)>>shift)-711B24. Recovered0918 rejects unsigned pageIndex<shift or pageIndex>711B28 with a `junk pointer` notice andNULL. The lower bound is literally the shift value, not an invented host arena boundary.

Map kind2 denotes a page-run start: require page alignment, count following kind3 continuation entries and derive oldCapacity=pageCount*pageSize. With711B54 clear, reuse oldPointer when oldCapacity>=newSize and oldCapacity-pageSize<newSize. Kind>=4 is treated as a slab-header pointer: require slot alignment, derive slot bitmap bit and reject a set free bit as already free. With711B54 clear and newSize<slotCapacity, reuse when newSize>slotCapacity/2 or slotCapacity==16. A new size equal to the slot capacity does not satisfy this slab reuse branch. Kind0/1/3 reports wrong-page and returnsNULL. Modified/already-free/wrong-page notices invoke empty6E0088.

Movement calls6E0698(newSize). NULL preserves the old allocation. NonNULL copies min(oldCapacity,newSize) through resident memcpy_forward when both are nonzero, releases old via6E0F38 and returns new. No arbitrary-pointer rescue, host realloc call or transactional allocator-state guarantee is inferred. The separate6F9B58 adapter explicitly releases the old allocation if this resize returnsNULL; its wrapper behavior remains distinct from this owner's preservation on allocation failure.

## Internal release6E0F38

NULL returns. NonNULL with refcount0 restores its frame and tail-calls empty6E0088 with `malloc() has never been called.`; stop flag711B50 returns. Page-index bounds match resize. Invalid bounds restore the frame and tail-call the empty notice callback. No normalized integer status is promised.

For map kinds<4, kind1 reports already free;0/3 report wrong page. Kind2 requires page alignment, marks its start and following kind3 entries as1, counts run pages, subtracts units and full run bytes from accounting, and optionally fills the runD0. It uses cached711B68 or allocates a20-byte record, then immediately writes its start/end/size without a local NULL check after that fresh allocation. It inserts the free run by address, coalesces adjacent records, updates next/previous links and may recursively release a consumed leftover record. The diagnostic `freelist is destroyed.` calls empty6E0080 and continues common handling; it does not establish safe corrupted-list recovery. Scans rely on valid initialization, ordering and termination invariants.

For slab map pointers>=4, it validates alignment, rejects a set free bit, optionally fills slot bytesD0, sets the free bit, increments u16 remaining count and subtracts slot bytes from711B7C. A transition to remaining1 reinserts a formerly full slab into its class list. Only the alternate remaining!=1 branch compares remaining to total for full-slab reclamation. A fully free slab is unlinked by traversal, map entry becomes kind2, separately allocated header storage is recursively released when header!=pageBase, page accounting is balanced and the base page is recursively released. No independent finite traversal bound or malformed bitmap safety guarantee appears locally.

## Allocation/release/resize callbacks

6E1ED0,6E2208 and6E23A8 decode their entry islands **before** waiting on711B18 through WaitSema114660. They increment attempt counters711B70/78/74 and store context strings containing `_sce_dnas_malloc()`, `_sce_dnas_free()` and `_sce_dnas_realloc()`. WaitSema/SignalSema114640 returns are unchecked. The depth check follows the wait; it does not prove same-thread recursive-deadlock prevention or that executable-range decoding is serialized.

Each saves old depth, writes old+1 and admits only newDepth==1. Rejection restores old depth, invokes empty6E0088 with `recursive call.`, signals, and returnsNULL for allocation/resize. Release returns without independent status normalization.

Allocation requires709D00!=0. In that state711B5C plus size0 selectsNULL; otherwise call6E0698. Normal completion decrements depth and signals before optionally reporting OOM through empty6E0080 when711B58 is enabled. A NULL for size0 with zero-size policy enabled bypasses OOM notice; other NULLs may report. Reporting does not terminate or change savedNULL.

Resize with initialized arena and enabled zero-size policy releases old and returnsNULL when newSize0. Otherwise NULL old routes6E0698(newSize), nonNULL old routes6E0838(old,newSize). Normal completion decrements depth/signals before the same OOM policy. An uninitialized nonNULL old first reports never-called and locally resets oldNULL, then still takes the missing-init warning route.

**Missing-initialization edge:** allocation/resize's `call _sce_dnas_malloc_init() first.` paths signal/returnNULL without normal depth decrement, so starting at0 leaves depth1. Recursion rejection restores old depth instead. Release has no outer reference-count admission: it invokes internal release, which handles missing initialization, then decrements depth normally. These are literal original branches, not reproduced failures or implemented fixes.

## Catalogue fragments and limits

The four generated fragments6E0920,6E1F5C,6E228C and6E243C are resolved **inside** the owners, rather than promoted to callable APIs:0920 is a branch-delay LUI;1F5C is allocation-counter increment/inline-data-skip continuation;228C is a release-counter update prefix;243C is resize-counter address setup. Corresponding rows in [residual classification](SYMBOLS_DNAS_RESIDUAL_CLASSIFICATION.md) retain exact original encoded bytes and their source links, now with complete ownership classification. One-byte partitions around them are parts of instructions or inline data, not independent functions.

Empty diagnostic targets6E0080/0088 have no current o5 catalogue entries and remain support context only. Their strings now clarify the allocator's own validation branches but do not show that any allocation, spin or failed operation occurred in a playtest. No performance measurement, current contention, cryptographic guarantee or native replacement is claimed. Original source-comment audits are separate from reconstruction/branch/ownership proofs.
