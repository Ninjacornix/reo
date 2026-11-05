# SJUNI synchronization, errors and numeric boundaries

Static contract review, 2026-11-05. File #1 US `SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
This supports the dependency-inventory stage of the
[native reconstruction plan](../NATIVE_RECONSTRUCTION_PLAN.md), using the
[existing SJUNI mapping](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md).
No game, build, guest execution, attachment or live-memory inspection occurred.
No replacement, runtime change or shared annotation was made.

The complete original bodies at `0x140000..0x14083C` were read, including all
branches and delay slots. The calls to the shared guard were traced through
their registered scheduler callbacks, and the default error path was traced to
its synchronous lower callback. Findings below distinguish local instruction
semantics from unresolved caller and host-runtime admission.

## Synchronization boundary

SJUNI has no object-specific lock. Only the admitted mutation paths below call
the shared CRI tag-one guard. Reset, destruction and inspection need an external
ordering contract before an independent native owner can safely replace them.

| Operation / source | Entry and leave evidence | Locally established ordering |
| --- | --- | --- |
| [Get `0x140300`](../../recomp/config/output/sub_00140300_0x140300.cpp) | Enter at `0x140358`; leave at `0x140410` | Invalid selector reports/clears output before any guard. Every valid selector enters, including empty-list and non-splitting refusal. List/free-list writes and output span publication precede leave. |
| [Put `0x140438`](../../recomp/config/output/sub_00140438_0x140438.cpp) | Enter at `0x140498`; tail leave at `0x14056C` | Selector check, signed positive-length check and payload-pointer check occur first. Tail traversal, adjacency merge or free-node allocation happen inside. Exhaustion callback also happens inside; return after callback reaches leave. |
| [Unget `0x140590`](../../recomp/config/output/sub_00140590_0x140590.cpp) | Enter at `0x1405F0`; tail leave at `0x1406B4` | Same pre-entry admission as Put. Head merge/prepend and exhaustion callback happen inside. |
| [Pool init `0x140020`](../../recomp/config/output/sub_00140020_0x140020.cpp), [release `0x140070`](../../recomp/config/output/sub_00140070_0x140070.cpp), [create `0x1400C0`](../../recomp/config/output/sub_001400C0_0x1400c0.cpp) | No guard call in these complete bodies | Global reference count, first/last-reference pool clears and active-slot selection are plain memory operations. Construction publishes fields before its unguarded reset call. |
| [Destroy `0x1401A8`](../../recomp/config/output/sub_001401A8_0x1401a8.cpp), [reset `0x1401F8`](../../recomp/config/output/sub_001401F8_0x1401f8.cpp) | No guard call | Destroy clears the object; reset rewrites borrowed node links and all four heads. Neither establishes quiescence against another operation. |
| [Set error callback `0x1401E8`](../../recomp/config/output/sub_001401E8_0x1401e8.cpp) | Context store `0x1401E8`, callback store in return delay slot `0x1401F0` | Pair update is ordered as context then callback, without a local guard or atomic-pair primitive. |
| [Byte sum `0x140288`](../../recomp/config/output/sub_00140288_0x140288.cpp), [availability `0x1406D8`](../../recomp/config/output/sub_001406D8_0x1406d8.cpp), [queue-node count `0x140768`](../../recomp/config/output/sub_00140768_0x140768.cpp), [free-node count `0x1407A8`](../../recomp/config/output/sub_001407A8_0x1407a8.cpp) | No guard call | Read-only list traversal does not provide a consistent concurrent snapshot. Queue-node count also lacks selector validation. |
| [Split descriptor `0x1407E0`](../../recomp/config/output/sub_001407E0_0x1407e0.cpp), [identifier `0x1401E0`](../../recomp/config/output/sub_001401E0_0x1401e0.cpp) | No guard call | Standalone descriptor arithmetic and a plain identifier-pointer load. The guarded Get path uses the split helper on stack temporaries. |

No local `SYNC`, atomic compare/exchange, thread-owner check, interrupt mask,
semaphore acquisition or per-object lock field appears in these SJUNI bodies.
That does not prove they race in actual use: callers may already serialize them.
It does mean an arbitrary host mutex cannot be justified solely from this code.

### Shared tag-one machinery

The entry chain is [SJ wrapper `0x13F258`](../../recomp/config/output/sub_0013F258_0x13f258.cpp)
→ [force tag 1 `0x1416D0`](../../recomp/config/output/sub_001416D0_0x1416d0.cpp)
→ [generic enter `0x1415E0`](../../recomp/config/output/sub_001415E0_0x1415e0.cpp).
The matching leave chain is [SJ wrapper `0x13F270`](../../recomp/config/output/sub_0013F270_0x13f270.cpp)
→ [force tag 1 `0x1416E8`](../../recomp/config/output/sub_001416E8_0x1416e8.cpp)
→ [generic leave `0x141640`](../../recomp/config/output/sub_00141640_0x141640.cpp).
This is shared with SJRB and other CRI services, not scoped to one SJUNI instance.

| Original state / exact PCs | Contract |
| --- | --- |
| Enter pair `0x2649E0/+4`; `0x1415F4..0x141604` | If callback is NULL, return without even updating generic depth/tag. Otherwise synchronously call `enter(context)` first. The numeric tag is not passed to that callback. |
| Generic depth `0x22A5F0`, outer tag `0x22A5F4`; `0x141608..0x14162C` | After the enter callback returns, store this tag only if depth was zero, then increment the shared 32-bit depth. Nested entry still called the enter callback; depth is not thread-local. |
| Leave pair `0x2649E8/+4`; `0x141650..0x141674` | If leave callback is NULL, return without updating depth/tag. Otherwise decrement shared depth first. This path does not reject an unmatched leave or clamp a negative generic depth. |
| `0x141678..0x1416A8` | Only exact new depth zero compares outer tag with this leave tag, reports mismatch if unequal, then clears the outer tag. Nonzero depth skips the tag check. |
| `0x1416AC..0x1416B4` | Invoke the current leave callback on every admitted leave, not just the outermost one. It reloads the callback pair at this point. |
| [Register enter `0x141DF0`](../../recomp/config/output/sub_00141DF0_0x141df0.cpp), [register leave `0x141E08`](../../recomp/config/output/sub_00141E08_0x141e08.cpp) | Separate unguarded stores of context followed by callback, without resetting generic depth/tag. Installing/removing only one hook has asymmetric accounting. |

Tag mismatch calls [formatted lower error `0x141800`](../../recomp/config/output/sub_00141800_0x141800.cpp)
at `0x14169C`, using owned string `0x23DBA8` and the saved/current numeric tags.
It then continues if the diagnostic returns. In this mismatch path the callback
can run before the final leave-hook reload. If it changes/removes that hook, the
initial non-NULL test is not a final snapshot: the later `JALR` has no second
NULL check. This is a conditional mutation hazard, not an observed crash or
permission to change callback order.

### Installed scheduler hooks

The reviewed first-reference setups
[four-worker `0x12B638`](../../recomp/config/output/sub_0012B638_0x12b638.cpp)
at `0x12B680..0x12B69C` and
[extended `0x12C1D0`](../../recomp/config/output/sub_0012C1D0_0x12c1d0.cpp)
at `0x12C20C..0x12C228` install entry `0x12A968` and leave `0x12A9F0`, both with
context zero. Matching last-reference teardown
[base `0x12B800`](../../recomp/config/output/sub_0012B800_0x12b800.cpp)
at `0x12B860..0x12B874` and
[extended `0x12C388`](../../recomp/config/output/sub_0012C388_0x12c388.cpp)
at `0x12C3F8..0x12C40C` clears the two pairs separately. These are concrete static
installation paths; their existence is not proof of the live hook state.

[Entry hook `0x12A968`](../../recomp/config/output/sub_0012A968_0x12a968.cpp)
uses a second shared depth at `0x210480`. At zero it gets the current thread ID,
calls ChangeThreadPriority with configured value `0x210460`, stores that syscall's
**return value** at `0x217D70`, records current ID at `0x217D74`, and conditionally
resumes guard worker ID `0x2104D8`. It then increments this depth on every call.
The relevant PCs are `0x12A978..0x12A9D4`. There is no CAS or mutex acquisition.

[Leave hook `0x12A9F0`](../../recomp/config/output/sub_0012A9F0_0x12a9f0.cpp)
decrements this second depth; exact new zero conditionally suspends the guard
worker, gets the **current** thread ID and changes its priority using `0x217D70`.
It does not select the restore thread from `0x217D74`. Negative hook depth is
clamped to zero at `0x12AA40..0x12AA48`, unlike the generic tag depth above.
Do not rename the saved return value to “previous priority” without establishing
the active syscall/runtime return contract.

[Resume helper `0x12B0F0`](../../recomp/config/output/sub_0012B0F0_0x12b0f0.cpp)
returns immediately for worker ID zero; otherwise it queries status and calls
ResumeThread only for status word `8` or `0xC`.
[Suspend helper `0x12B158`](../../recomp/config/output/sub_0012B158_0x12b158.cpp)
also skips ID zero; status `8`/`0xC` skips suspension, other statuses call
SuspendThread. Neither checks the ReferThreadStatus return before reading its
stack status word. These are status-conditioned operations, not a wait/join or
positive-ID validation.

The reviewed syscall leaves are [ChangeThreadPriority `0x1144B0`](../../recomp/config/output/sub_001144B0_0x1144b0.cpp)
(`v1=0x29`), [GetThreadId `0x114510`](../../recomp/config/output/sub_00114510_0x114510.cpp)
(`0x2F`), [ReferThreadStatus `0x114520`](../../recomp/config/output/sub_00114520_0x114520.cpp)
(`0x30`), [SuspendThread `0x114590`](../../recomp/config/output/sub_00114590_0x114590.cpp)
(`0x37`) and [ResumeThread `0x1145B0`](../../recomp/config/output/sub_001145B0_0x1145b0.cpp)
(`0x39`). Their bodies issue `SYSCALL`; host scheduler behavior is outside this
instruction-only proof. The guard worker [entry `0x12ABA0`](../../recomp/config/output/sub_0012ABA0_0x12aba0.cpp)
repeatedly calls [counter increment `0x12AB88`](../../recomp/config/output/sub_0012AB88_0x12ab88.cpp)
until the stop word changes, then acknowledges and exits. It is not a conventional
mutex-owner thread waiting on a queue.

## Error behavior and callback reentry

The per-object callback is word `+0x28`, context `+0x2C`. Calls are synchronous
`callback(context, -3)` when non-NULL. The same code reports invalid selectors
and free-node exhaustion; it does not identify their cause by distinct codes.

| Path / exact PCs | Relative to guard | State when callback runs and continuation |
| --- | --- | --- |
| Sum invalid selector `0x140298..0x1402B4` | Outside | No list access; callback first, then force returned sum zero. |
| Get invalid selector `0x140330..0x140350` | Outside | Callback sees the previous output contents. After it returns, length and pointer are cleared. With no callback, the same output clears occur. |
| Put invalid selector `0x140460..0x14047C` | Outside | Reports before dereferencing the input descriptor; returns without append or enter/leave. |
| Unget invalid selector `0x1405B8..0x1405D4` | Outside | Same selector-first ordering; no prepend or enter/leave. |
| Availability invalid selector `0x1406F4..0x140714` | Outside | `*outLength=0` is written **before** callback lookup/call. Returned predicate is forced zero afterward, but output is not cleared again: a callback alias can change it. |
| Put free-node exhaustion `0x140518..0x14053C` | Inside | Failed merge/empty free list is established; no new node append was performed. Callback may mutate state. Original operation does not retry allocation after callback; it proceeds to leave. |
| Unget free-node exhaustion `0x14064C..0x140670` | Inside | Same no-retry rule and guarded callback context. |

Pool-full construction instead returns NULL at `0x140120..0x140124`, without
calling the SJUNI error callback. Valid Put/Unget with nonpositive input length
or NULL payload pointer silently skip, before guard entry. Empty Get and a short
Get in a mode other than one return an empty output without an error callback.
There is no active-object, provenance, “last reservation,” duplicate-span,
payload-capacity, pointer-range or cycle-validation error in these bodies.

The default callback [entry `0x140000`](../../recomp/config/output/sub_00140000_0x140000.cpp)
discards incoming context/code and tails through
[text adapter `0x13F288`](../../recomp/config/output/sub_0013F288_0x13f288.cpp)
to [lower publisher `0x1418A8`](../../recomp/config/output/sub_001418A8_0x1418a8.cpp)
with owned `0x23DA88`, exactly `SJUNI Error` followed by NUL. The publisher copies
127 bytes into shared `0x22A638` through
[bounded copy `0x10B5F8`](../../recomp/config/output/sub_0010B5F8_0x10b5f8.cpp),
then optionally calls the lower pair `0x2649F0/+4` with `(context, sharedText)`.
This short literal is terminated and padded within that bound; the publisher
does not independently write the final byte of the 128-byte shared area.
It has no local permanent loop, throw or process-termination instruction.

Lower callback registration [entry `0x141DB0`](../../recomp/config/output/sub_00141DB0_0x141db0.cpp)
itself enters/leaves tag one. Thus error handling can nest this same guard even
without explicitly getting another SJUNI chunk. Shared error text has no lifetime
snapshot; a nested lower error can overwrite the text observed by the outer
callback. Its formatter dependency and final external callback remain adapter
dependencies, not evidence that every error should abort the stream.

Reentry conclusions are bounded:

- Balanced same-thread nested guard calls increment/decrement both reviewed
  nesting layers when the installed pairs remain stable. No thread-owner check
  proves that a second host thread should share that depth or bypass exclusion.
- An exhaustion callback runs while the original operation is guarded and can
  call other stream operations. A nonrecursive host mutex would change that
  behavior; moving callback delivery outside the guard would also change ordering.
- A callback can reset/destroy the object, alter callback registration, return
  nodes or modify an aliased output. There is no SJUNI reentry flag or rollback.
  The original failed Put/Unget still does not retry after such a callback.
- A callback that does not return prevents the local leave from being reached.
  C++ exceptions, asynchronous error posting or automatic retry would introduce
  contracts absent from these original bodies.
- Put/Unget inspect the caller descriptor before entry, then read it again after
  the enter hook. A mutating custom hook or unsynchronized caller can change the
  admitted fields. Native “copy once before lock” is not automatically equivalent.

The Get/Put/Unget bodies do not normalize `v0` to a portable success/error status.
Their observable span/callback effects must not be replaced by an invented bool
or error-return interpretation without checking the consumers.

## Numeric and alias boundaries

The ordinary API domain below assumes incoming scalar arguments are canonical
sign-extended 32-bit guest values. Original argument registers are 64-bit; `DADDU`
preserves them, while loads and `ADDIU`/`ADDU`/`SUBU`/`SLL`/`SRA` use the stated
word-width behavior. Some `SLT`/`SLTIU` comparisons see the full register value.
Do not promote this to an unrestricted host `size_t`/pointer API or rely on C++
signed overflow to reproduce word wrap.

| Evidence | Numeric or alias contract |
| --- | --- |
| `0x140134..0x140180` | Work byte size converts to node count by signed truncation toward zero: negative input gets a word `+15` adjustment, then arithmetic right shift four. Positive trailing bytes are discarded. Mode stores only low eight bits; mode comparisons use signed `LB` equal to exactly one. |
| `0x1401F8..0x140258` | Reset initializes at least the first node for constructor-reachable zero/negative node counts; it is not a safe empty-node-array reset. Positive count requires enough writable borrowed 16-byte records. Raw field value `INT32_MIN` is a separate edge: initial word `count-1` wraps positive, so the ordinary “nonpositive skips linking” shorthand does not cover arbitrary direct field corruption. The constructor's divide-by-16 result cannot itself be `INT32_MIN`. |
| `0x140204..0x140238` | The reset loop reloads object node count while writing nodes. Node storage overlapping the object is not admitted by this review. Node word `+4` is left untouched. All four queue heads are cleared at `0x140260..0x140278`. |
| `0x14030C`, `0x140444`, `0x14059C`, `0x1406DC` | Unsigned selector<4 admits only the four queue indices. Negative canonical selectors reject. In contrast, `0x140768..0x140770` does unchecked word-scaled address arithmetic; it does not inherit that rejection. |
| `0x140388..0x1403C8` | Get compares requested count with signed head length. Requested>=head length returns the entire span and frees the node in every mode, even if requested is larger. Smaller requests split only in mode one; other modes grant nothing. There is no nonnegative-request check. |
| `0x1407F0..0x140838` | Split sets prefix length to signed min(original length, requested), subtracts at word width for the remainder and computes remainder pointer with word addition, or NULL when remainder length is zero. It moves descriptors only, never payload bytes. |
| Get plus split above | For ordinary positive length L and request zero in mode one, output is `{originalPointer,0}` and head remains the same descriptor. This differs from empty-list `{NULL,0}`. For request -1, the instructions imply prefix length -1, remaining length L+1 and remaining pointer originalPointer-1, subject to word wrap. This is static arithmetic, not a reproduced session. |
| `0x140734..0x140754` | Availability always writes the full head length. Mode one returns headLength>=requested using signed comparison; other modes require exact equality. Nonempty positive-length head plus negative request can therefore return true in mode one. In other modes a request greater than the head can report false although Get would return that whole head. It is not a min-grant query. |
| `0x140480..0x140490`, `0x1405D8..0x1405E8` | Put/Unget admit only positive signed incoming lengths and non-NULL payload pointers, but the descriptor pointer itself must be readable. Invalid selector is checked before descriptor dereference. They do not check that the payload belongs to any previous reservation. |
| `0x1404F8..0x140510`, `0x140628..0x140644` | Adjacency pointers and merged lengths use word additions, with no overflow/capacity rejection. Positive admitted lengths can merge to a negative signed length after wrap. Host pointer arithmetic beyond an actual allocation is not a substitute for this guest numeric address comparison. |
| `0x1402D0..0x1402E8`, `0x140798`, `0x1407D0` | Byte sums and node counts accumulate at word width, without overflow or cycle guards. Tail/list cycles can make traversal unbounded; Put's tail traversal holds the shared section during that traversal. |
| `0x140398..0x1403BC` | Whole Get copies output descriptor, unlinks the head, then pushes its node onto the shared free list. Payload/length fields in that freed node are not scrubbed. Payload storage remains borrowed. Output aliasing object/node fields can affect this precise ordering and is not proven admitted. |
| `0x1407E0..0x140838` | The observed Get call uses prefix==input on a stack descriptor and a separate remainder. That alias is supported. Arbitrary prefix/remainder overlap or overlap with queue links is not established by the eight-byte copy sequence. |
| `0x140054..0x14005C`, `0x140080..0x14008C` | Module reference count increments/decrements at word width; only exact old zero init or exact new zero release clears the object pool. No underflow precheck or live-object destructor walk is present. |

## Contracts still needed before a native boundary

### Current host-source follow-up

The checked-out runtime adds useful, bounded source evidence:
[ChangeThreadPriority](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Thread.cpp:1096)
stores `oldPrio`, updates current priority and returns `oldPrio` on success;
invalid/dormant thread or invalid priority paths return an error instead. Thus
the saved CRI value is the old priority **on this implementation's successful
path**, without proving success or original-console equivalence in a session.

The runtime declares a recursive guest-execution mutex in
[ps2_runtime.h](../../third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime.h:675).
[Guest-execution enter/release/reacquire](../../third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_runtime.cpp:2618)
tracks nesting per host thread and runtime, releasing all held levels while
blocked and reacquiring them afterward. The
[guest worker loop](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Thread.cpp:474)
holds that scope across steps. The
[wait helper](../../third_party/PS2Recomp/ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/Runtime.h:28)
temporarily releases it around condition-variable waits.

This establishes a current host serialization mechanism on the inspected entry
paths; it does not establish that every SJ consumer enters through those paths,
or that yielding/wakeup order matches the original CRI priority protocol.
`switchIfOutranked` also has an environment-dependent immediate-switch branch
at `Thread.cpp:46`. Its actual setting and the linked library were not observed.
The new adapter should retain the surrounding runtime scope while those users
remain, rather than assuming a new per-object mutex supersedes it. Source hashes
and submodule/patch context are retained in [inventory.json](inventory.json).

1. **Actual consumers and execution contexts.** Identify which callers already
   hold tag one, which threads call each query/lifecycle method, and whether any
   field/node pointer escapes to code that mutates it directly. This review does
   not claim a complete consumer inventory.
2. **Scheduler and exclusion.** Establish the active host/runtime implementations
   of priority/status/resume/suspend, the meaning of the saved syscall return,
   and why unrelated CRI workers cannot mutate the same queues concurrently.
   The instruction wrappers alone do not prove mutual exclusion or fairness.
3. **Lifecycle and hook stability.** Establish setup/teardown ordering, balanced
   nesting and external serialization of unguarded reset/create/destroy,
   callback-pair changes and module reference count. Preserve the shared CRI
   boundary until its remaining users have migrated.
4. **Callback/reentry admission.** Find the real per-object/lower callback targets,
   whether they reenter, change hooks, reset/destroy owners or alias outputs, and
   whether nonreturning paths are possible. Define synchronous error delivery
   with its exact guard placement before choosing a native callback interface.
5. **Numeric and ownership admission.** Confirm positive work/node sizes,
   canonical scalar widths, selector ranges, request sign, merge-overflow limits,
   acyclic node lists, payload lifetime and forbidden overlap from real callers.
   Missing checks cannot be silently replaced by host undefined behavior or
   presented as validated player inputs.
6. **Adapter-visible results.** Preserve borrowed descriptor identity, whole-span
   grants, split/merge modes, callback order and output mutation. Establish which
   return registers consumers actually use before defining native result types.

These are dependency and admission blockers for implementation, not evidence of
a current crash or measured slowdown. The focused static review is complete;
native reconstruction and behavior validation remain separate stages.

## Evidence audit

The existing static `audit_owned` routine in
[the source-comparison checker](../../tools/function_index/review_recvx_platform_complete_scope.py)
was invoked read-only with the following 45 main-image entries. It matched every
original instruction comment against the hash-checked owned ELF and required all
uncommented words inside the complete catalogue intervals to be zero:
**1,201 verified comments, 41 omitted zero words, zero conflicts and zero omitted
nonzero words**. No receipt or shared index was written by that invocation.

```text
10B5F8
114460 1144B0 114510 114520 114590 1145B0
12A968 12A9F0 12AB88 12ABA0 12B0F0 12B158
12B638 12B800 12C1D0 12C388
13F258 13F270 13F288
140000 140020 140070 1400C0 1401A8 1401E0 1401E8 1401F8
140288 140300 140438 140590 1406D8 140768 1407A8 1407E0
1415E0 141640 1416D0 1416E8 141800 1418A8 141DB0 141DF0 141E08
```

Owned diagnostic bytes at `0x23DA88` and the mismatch format at `0x23DBA8` were
read directly from that ELF. The latter names the original/now tags; it does not
provide a lock-owner identity. Memory-fill and variadic-formatting dependencies
are existing mapped callees, not newly proven host interfaces in this note.

Related prior evidence: [SJRB ownership](../SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md),
[CRI errors](../SYMBOLS_CRI_ERRORS.md),
[worker priority handoff](../SYMBOLS_CRI_WORKER_LOOPS_AND_PRIORITY_HANDOFF.md),
[worker creation/stop](../SYMBOLS_CRI_WORKER_CREATION_AND_STOP_ACK.md) and
[service/thread control](../SYMBOLS_CRI_SERVICE_DISPATCH_AND_THREAD_CONTROL.md).
Unless explicitly decimal, addresses, PCs and structure offsets are hexadecimal.
