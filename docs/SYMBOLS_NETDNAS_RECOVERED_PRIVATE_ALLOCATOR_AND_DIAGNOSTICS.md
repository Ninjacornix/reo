# Recovered private allocator owners and inline diagnostic payloads

Static File #1 US research, 2026-11-05. Owned o4/netdnas.bin, runtime5, base6E0000, SHA-256 **8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16**. This review joins clear control flow to18 reconstructed spans in [the primary recovery inventory](STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md), resolving **six logical owners**, rather than inventing18 functions for the spans. It supersedes the three partial callback contracts in [private allocator boundaries](SYMBOLS_NETDNAS_PRIVATE_ALLOCATOR.md), whose initialization/reference/statistics findings remain applicable. The adjacent [page/slab allocation helpers](SYMBOLS_NETDNAS_PAGE_AND_SLAB_ALLOCATION.md) supply fully reviewed dependencies.

Only copied integer data was reconstructed and inspected. No guest execution, emulation, game, build, network request, attachment, live-memory access, original-image change or generated/runtime-code edit occurred. The original source catalogue and denominator remain unchanged.

| Guest entry / source | Proposed label | Confidence | Evidence and remaining uncertainty |
| --- | --- | --- | --- |
| [o4 0x6E8178](../recomp/config/output_ovl/o4/o4_006E8178_0x6e8178.cpp) | `allocate_private_slab_or_page_run_with_optional_failure_notice_and_zero_fill_candidate` | High complete clear/recovered owner; valid arena invariants inherited | Rejects size+page overflow, selects slab for size<=page/2 else rounded page-run helper, optionally reports failure and zeros requested bytes. Nonzero stop flag enters a permanent local NOP loop. One protected span contains failure notice only; it is not an independent allocator. |
| [o4 0x6E8318](../recomp/config/output_ovl/o4/o4_006E8318_0x6e8318.cpp) | `resize_private_block_by_capacity_reuse_or_allocate_copy_release_candidate` | High complete joined owner; malformed heap admission partial | Validates page index/type/alignment/free bit, reuses sufficiently close capacity under policy, otherwise allocates/copies min(oldCapacity,newSize)/releases old. Failure preserves old allocation. Five protected diagnostic spans belong to this single owner through6E8A18. |
| [o4 0x6E8A18](../recomp/config/output_ovl/o4/o4_006E8A18_0x6e8a18.cpp) | `release_private_page_run_or_slab_slot_and_coalesce_free_records_candidate` | High complete joined metadata/list/bitmap flow; valid heap invariants inherited | NULL returns. Checks initialization/page bounds/type/alignment/free bit; marks/coalesces page runs, returns slab bits, reinserts formerly full slabs and recursively reclaims fully free slab storage. Seven diagnostic spans include original strings; no stable integer return status. |
| [o4 0x6E99B0](../recomp/config/output_ovl/o4/o4_006E99B0_0x6e99b0.cpp) | `wait_guard_and_count_private_allocation_with_zero_size_policy_candidate` | High complete joined callback flow; synchronization success unverified | Waits792898, increments allocation-attempt counter/depth, requires initialized arena and optional zero-size policy, delegates6E8178, decrements depth/signals, optionally reports OOM after unlock. Recursion/initialization error paths and persistent depth edge are detailed below. |
| [o4 0x6E9CE8](../recomp/config/output_ovl/o4/o4_006E9CE8_0x6e9ce8.cpp) | `wait_guard_and_count_private_release_callback_candidate` | High complete joined callback flow; synchronization success unverified | Waits792898, increments release counter and depth, stores diagnostic context, rejects nonzero old depth through notice, otherwise6E8A18(originalPointer), decrements depth and signals. Return is not normalized independently of SignalSema. |
| [o4 0x6E9E88](../recomp/config/output_ovl/o4/o4_006E9E88_0x6e9e88.cpp) | `wait_guard_and_count_private_resize_with_null_and_zero_size_policy_candidate` | High complete joined callback flow; synchronization success unverified | Waits792898, counts resize, guards depth, admits initialized arena, routes NULL old pointer to allocate and optional zero-size to release, otherwise6E8318; signals before optional OOM notice and returns saved pointer. |

## Ownership, copied-data proof and actual restore distinction

New isolated [review_dnas_primary_allocator.py](../tools/function_index/review_dnas_primary_allocator.py) independently rereads52 original exception records, descriptors, selector schedules and original payload bytes; recomputes all18 candidates and verifies their **paired-metadata** exact restores. It creates an [addressed listing](../build-function-index/dnas-primary-allocator-review/words.txt) and [receipt](../build-function-index/dnas-primary-allocator-review/receipt.json), including owner hashes and202 checked direct branch targets. All1726 listed words were read:577 reconstructed words plus1149 clear words. Of577 candidate words,246 are branch-skipped inline ASCII/NUL data and331 are instructions/padding;125 exception words remain unchanged during arithmetic. The six credited owners account for1251 instruction/padding words plus246 inline-data words. The remaining229 clear words recheck already mapped initialization/reference/statistics between those owners. No instruction field remains undecoded; original ASCII data is explicitly classified as data.

All18 entries bind to real clear JAL70BA68 calls with literal payload anchors and even mode IDs. Their entry branches skip junk/header bytes. Each adjacent odd-mode descriptor reproduces original encoded bytes **if applied as copied-data arithmetic**. However **none of these six owners calls that forward restore**: the clear branch at each payload end skips its odd descriptor and proceeds directly into ordinary allocator code. Some recovered branches/tail returns exit before even reaching that end branch. This resolves the inventory's18 noncanonical restore bindings as **absent from these joined paths**, not as a canonical restore hidden at another nearby address. No claim is made that an unrelated external mechanism cannot later transform the span. Header/ cache writes, live decode state and thread behavior were not performed or simulated.

The common metadata-relative base6E7B60 is **not a whole-function entrance**. Actual6E7B60 and6E7B68 are separate JR/NOP diagnostic callbacks already documented as empty;6E7B70 begins a separate page allocator. The protected spans here contain diagnostics and some callback/release/validation operations, not a giant function starting at that common base.

| Joined owner, end exclusive | Protected starts | Complete original interval SHA-256 |
| --- | --- | --- |
|6E8178..6E8318|8274|`83773ffed6c0840d45c754784d24812eb897b31b5cea94702e353c79ba90c396`|
|6E8318..6E8A18|83F8,858C,86FC,8810,8920|`5ec665d9b458f476d60006bb01705fe5cb7fe56059fdc10f46e4686bfa18d166`|
|6E8A18..6E9624|8AA8,8D10,8DF4,8EE0,9208,9328,9434|`a85c0fab25e0a52cad319bcf2d2ad8bc63f6ebdf5a0c0431fc051e2c2232fb13`|
|6E99B0..6E9CE4|9A30,9C48|`48213b30e9024f42be0091adf10bddfc4695d41c47d9b59f8410821acc0c1794`|
|6E9CE8..6E9E84|9D60|`e2dec72f9a85f8efb76f764c16eea5a5704336b776f0a7fce55e7ec9ed3c1f98`|
|6E9E88..6EA258|9F10,A1B8|`72c7186ce264e3d8d13eeeb11e2604d3af635a110878d8dab3c2c674960ee861`|

Protected starts abbreviate the common6E prefix. Catalogue6E8318 ends inside its first diagnostic string at6E841C; eight following one-byte catalogue intervals are interior text, not new recovered entrances. Catalogue6E99B0 ends inside its context string at6E9A68;6E9CE8 ends inside its string at6E9D94. These source-less fragments retain their identities and receive no rows.6E9E88's source ends at6E9F28 inside a counter update; the independently traced continuation completes the operation. Every owner has a balanced stack/register return or explicitly restored tail call, apart from the documented intentional infinite loops. No native API implementation or arbitrary-heap safety proof follows from this structural review.

## State and internal allocation6E8178

The already reviewed arena initializes page size79288C to1000hex, shift792890 to12decimal, page mask792894 toFFFhex. State words below retain numeric identities where policy intent is inferred:

| State | Complete reviewed local use |
| --- | --- |
|7616F0|Arena initialization/reference count|
|792898|Semaphore handle passed to WaitSema/SignalSema|
|79289C|Guard depth shared by three public callbacks|
|7928A0/A4|Additive address base / page-index origin|
|7928A8/AC|Last admitted page index / page map and class-head array|
|7928B8 /7928E8|Free-run list head / cached20-byte free-record pointer|
|7928CC|Enable internal allocation-failure notice|
|7928D0|Stop internal allocation/resize in a NOP loop; release returns early|
|7928D4|Force resize movement rather than capacity reuse|
|7928D8|Enable public OOM notice after unlock|
|7928DC|Zero-size allocation returnsNULL; zero-size resize releases|
|7928E0|Zero requested allocation bytes after success|
|7928E4|Fill allocated/released capacity withD0 through reviewed helpers|
|7928EC|Last diagnostic context-string pointer|
|7928F0/F4/F8|Allocation/resize/release attempt counters|
|792900 /7928FC|Allocated page-unit / byte counters|

Allocation preserves requested size inS0 and starts resultNULL. If7928D0 is nonzero, it enters NOP8198..81B0 and branches back without reloading the flag; this is a local infinite loop, not a wait that notices a later flag clear. With flag zero it rejects unsigned wrap of size+pageSize. Requests<=pageSize/2 call6E7DF8(size), whose minimum slab slot is16; larger requests call6E7BE8(size), whose page rounding/list/map behavior is separately reviewed. No local initialization or lock check occurs here.

After a NULL result,7928CC enables protected failure message `allocation failed.` and a call to empty6E7B60. This does not terminate or throw. If7928E0 is nonzero and result nonNULL, it calls memset(result,0,requestedSize), then returns the preserved pointer. Zeroing uses requested bytes, not full capacity. Internal size0 can still select a minimum slab; the public zero-size policy may suppress that call.

## Internal resize6E8318

Inputs oldPointer=a0,newSize=a1.7928D0 nonzero enters a second NOP loop with no flag reload. Otherwise pageIndex=((oldPointer+7928A0)>>shift)-7928A4, using32-bit guest address arithmetic. The recovered first span rejects unsigned pageIndex<shift or pageIndex>7928A8 with `junk pointer` diagnostics andNULL. The lower bound is literally the shift word, not an invented host arena-start comparison.

It reads map[pageIndex]. Kind2 is a page-run start: require (oldPointer+base)&pageMask==0, then count following kind3 map entries and derive oldCapacity=pageCount*pageSize. With force-move flag clear, oldCapacity>=newSize and oldCapacity-pageSize<newSize return oldPointer directly. Otherwise move. Kind>=4 is treated as a slab-header pointer: require alignment to u16 slot bytes+8, derive slot index from masked address>>u16 exponent+A, and reject a set free bitmap bit as `chunk is already free.` Old capacity is the slot byte count. With force-move clear and newSize<oldCapacity, reuse occurs if newSize>oldCapacity/2 or oldCapacity==16. Equality newSize==oldCapacity does not satisfy this slab reuse branch. Kind0/1/3 reaches `pointer to wrong page.` andNULL.

For movement it calls6E8178(newSize). NULL returnsNULL with old block retained. NonNULL copies min(oldCapacity,newSize) through memcpy_forward when both counts are nonzero, then calls6E8A18(oldPointer), returns new pointer. It performs no host realloc call and no validated arbitrary-pointer recovery. Original map/list/header invariants and pointer disjointness remain inherited. Modified/misaligned pointer diagnostics returnNULL before the copy/release path.

## Internal release6E8A18

NULL returns immediately. NonNULL with refcount0 restores the full frame and tail-calls empty6E7B68 with `malloc() has never been called.`; an active stop flag returns. Page-index bounds match internal resize. Invalid bounds restore the frame and tail-call empty6E7B68 with the corresponding string; no stable status is assigned by that empty callback.

For map kinds<4, kind1 reports `page is already free.`; kind0/3 report wrong page. Kind2 requires page alignment, marks the start and following kind3 continuation entries as kind1, counts units, decrements page and byte accounting and optionally fills the released runD0. The EE MULT instruction at6E8FD4 has an explicit GPR destinationa2 as well as HI/LO: the byte-counter subtraction uses **runCount*pageSize**, not one page. The private decoder preserves EE's three-register MULT form; dropping its destination would misread this flow.

It obtains a20-byte free-run record from7928E8, allocating6E8178(20) when cacheNULL, then writes start+8,end+C,size+10. It does not locally test that fresh record allocation forNULL before dereferencing. An empty free list adopts it. Otherwise the body walks address ranges, inserts a disjoint range through next+0/previous+4 links, merges contiguous ranges on either side and unlinks a consumed neighbor; a leftover record can be recursively released after restoring the parent frame. The impossible-state branch reports `freelist is destroyed.` through empty6E7B60 and proceeds to the common leftover-record handling. Ordering, sentinel validity and finite scan bounds rely on initialized valid lists; the diagnostic strings do not prove corrupted lists are safely recoverable.

For slab map pointers>=4 it requires slot alignment, rejects a set bitmap bit as already free, optionally fills exactly slot bytesD0, ORs the free bit, increments u16 remaining+C and subtracts slot bytes from7928FC. A transition to remaining1 reinserts the formerly full header into its class list. Only the alternate remaining!=1 path compares remaining to u16 total+E for full-slab reclamation. A fully free slab is unlinked by next-pointer traversal; its page-map entry becomes kind2. Separately allocated header storage is recursively released when header!=page/data base; then page-sized accounting is balanced and the base page is recursively released through the same owner. No extra bound is imposed on class-list traversal.

This is a release operation without a normalized return value. Several error paths invoke already empty callbacks and return; meaningful allocator diagnostics are therefore not automatically visible in a launcher log. That is static original behavior, not evidence that a particular player's allocation failed.

## Public callbacks, guard depth and zero-size policy

All three clear entry envelopes decode before entering WaitSema114660(handle792898). Their recovered bodies increment the corresponding attempt counter and install context strings containing `_sce_dnas_malloc()`, `_sce_dnas_free()` or `_sce_dnas_realloc()`. These strings support callback-purpose attribution; they do not recover original linkable symbols. WaitSema and SignalSema114640 results are unchecked. The depth check occurs **after** waiting, so this is not a proven same-thread recursive-deadlock prevention scheme or proof that decoding itself is serialized.

Each saves old depth, writes old+1, and admits only when that new value==1. A rejected depth restores the old value, reports `recursive call.` through empty6E7B68, signals and returnsNULL for allocation/resize. Release signals without assigning a separate normalized result.

Allocation additionally requires refcount!=0. If initialized,7928DC!=0 with size0 returnsNULL directly; otherwise it calls internal6E8178. The normal path decrements guard depth and signals before examiningNULL/OOM policy. With NULL and either nonzero size or zero-size policy disabled,7928D8 enables `out of memory.` through empty6E7B60; saved result remainsNULL. The OOM notice executes after unlock and does not force termination.

Resize routes initialized calls as follows: zero-size policy enabled and newSize0 calls6E8A18(oldPointer), returnsNULL; otherwise oldPointerNULL calls6E8178(newSize); nonNULL calls6E8318(oldPointer,newSize). It then decrements depth/signals and applies the same post-unlock OOM notice rule. A nonNULL old pointer with refcount0 first reports `malloc() has never been called.` and locally resets oldPointerNULL, then follows the still-uninitialized warning path.

**Uninitialized edge preserved:** allocation/resize's `call _sce_dnas_malloc_init() first.` paths signal and returnNULL without the normal guard-depth decrement. Starting at depth0 therefore leaves depth1 on that edge. The ordinary initialized route decrements; recursion-rejection restores old depth; release's admitted route also decrements after internal release. No live occurrence or fix is asserted. Release does not add a separate refcount test before invoking internal6E8A18, which handles that case itself.

These contracts establish local ownership and behavior useful for a future native allocator replacement. They do not establish current contention, frequency of these calls, a cause of gameplay slowdown, correctness under arbitrary corrupted heaps, or a tested replacement. The original-comment audit validates catalogue-owned encoded/clear words separately from the copied-data reconstruction and branch/owner checks.

Original-comment audit result:6 rows,1032 verified original words,zero conflicts,37 omitted zero words andzero omitted nonzero words. The246 recovered inline-data words are not counted as instruction semantics merely because some bit patterns resemble opcodes.
