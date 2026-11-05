# Local SJUNI adapter admission and retained consumers

Static/offline review, 2026-11-05. File #1 US only; original ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
This report closes concrete first-pilot admission questions; it does **not**
prove complete alias closure, concurrent safety, runtime interception, native
parity or performance. No game, build, target execution, attachment or memory
capture was used. This Markdown file is the only artifact written for this task.

**Admission conclusion:** keep original construction/lifetime/callback routes,
retain the guest object and all node bytes, and intercept only exact canonical
method-entry PCs for independently registered, validated paired local objects.
Validated read-only methods can use a native imported snapshot on error-free
inputs. The initial mutating path should require **both generic CRI guard
callbacks NULL**, plus complete numeric/alias/state admission before any write.
With live scheduler hooks, delegate the whole mutating operation to its captured
original implementation. Consequently this is a conservative adapter/core pilot;
it is not yet a replacement of ordinary player audio queue mutations.

The original contract remains [the SJUNI notebook](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md).
Use [synchronization/errors](SYNCHRONIZATION_AND_ERRORS.md),
[retained ownership](README.md), [remote boundaries](REMOTE_AND_DTX_BOUNDARY.md)
and [the interface proposal](CONTRACT_AND_ADAPTER.md) alongside these findings.

## Construction and a safe registration point

The current indexed direct-call graph has one external caller of local constructor
`1400C0`: `13DB48` at **13DD58**, returning to **13DD60**. The call setup supplies
mode1, node bytes100hex (256 decimal), and node area `221780+100*slot`.
`13DD64` stores returned `v0` in paired-record `+8`; `13DD6C` tests that return
for NULL. There are32 physical paired records, although default configured use
is16. Neither configured count nor all hypothetical callers are globally proved
bounded by those32 records.

The current generated call at13DD58 first uses
`runtime->lookupFunction(0x1400C0)` when registered and otherwise calls the
generated constructor directly. It writes guest RA13DD60 and requires the
callee to return there before continuing. This is positive static interception
evidence for this caller, not evidence that an installed executable used it.

Recommended first registration procedure:

1. At canonical constructor entry only, capture original RA/arguments and call
   the saved original binding. Do not reimplement its slot scan as part of the
   first queue-adapter change.
2. Register a sidecar only after actual return to the captured caller. Require
   known creator RA13DD60, mode1, exact256-byte node work, admitted node area
   within `221780..223780`, and a non-NULL canonical48-byte object slot within
   `228C98..229898`. Check the returned vtable/UUID/mode/node fields against the
   original construction, and reject overlapping metadata or unexpected tokens.
   Preserve the same returned guest object, not a host pointer.
3. Original constructor writes vtable228C60 at140170, mode at140174, UUID23DA78
   at140178, nodes/count at14017C/140180, callback140000 at140184 and context=self
   in call delay slot14018C. It invokes reset1401F8 before returning the object
   in `v0` at140190. Do not enroll a partially initialized/yielded constructor.
4. Continue original publication:13DDA0..13DDB8 creates the borrowed
   `{IOP_cursor,4000}` span and puts it into local pool0 at13DDB4. Only this
   typed ownership path supports the pilot payload-region registration;256-byte
   node work is not audio payload capacity. Keep the IOP token opaque.

An unrecognized constructor caller must still get the original behavior, but it
does not thereby become an admitted native instance. A sidecar generation does
not make stale raw object addresses distinguishable after slot reuse.

## Callback types, actual writes and known registrations

| Original PCs / source | Exact effect and consequence |
| --- | --- |
| `140184`, `14018C` | Constructor installs object callback140000 and context=self. These are guest function/data tokens. |
| `1401E8..1401F0` | Error registration stores new context `a2` at object+2C first, then stores callback `a1` at object+28 in the return delay slot. No guard, type validation or NULL rejection. Both NULL and arbitrary new callback/context are permitted by this body. |
| `140330..140344`, `140460..140474`, `1405B8..1405CC`, `1406F8..14070C`, `140520..140534`, `140654..140668` | Synchronous object callback uses guest `a0=context`, `a1=-3`. Mechanically this is a `void(context, signed_error)` interface; no portable callback return value is consumed by the queue operation. Preserve 32-bit guest tokens and calling convention. |
| `140000..140018`, `13F288..13F298` | Default callback ignores original context/code and tails to1418A8 with text23DA88, `SJUNI Error`. |
| `1418A8..1418F4` | Copies127 text bytes into22A638, then optionally calls the lower pair2649F0/+4 as `(context, sharedTextPointer)`. This lower callback is a distinct `void(context, text)` interface, not the per-object `(context,-3)` interface. |
| `1AC678..1AC684` | Boot initializer1AC650 registers **1AC640**, contextNULL, through12B620 at1AC680. Do not confuse the callback with neighboring1AC630 (the vblank-counter reader). |
| `1AC640..1AC648` | Actual boot lower callback consists of `JR RA; NOP`: return-only, no fatal loop, queue mutation or text inspection. This narrows one real registration without assuming it always remains installed. |
| `12B62C`, `1280C4`, `16380C`, `133040` | Lower registration remains reachable through generic/movie and ADXT facades.141DB0 stores arbitrary supplied callback/context under the shared tag-one guard. Later installation/removal is possible; no final static callback pair is proved. |

There is no indexed direct edge to1401E8. Its address does occur in local vtable
slot **+2C** (228C8C). Reviewed13DB48,141490,138AB8 and the typed local queue
consumers do not invoke that slot or overwrite object+28/+2C. This is a bounded
negative finding, not proof that arbitrary indirect users never register another
handler. Object+2C is callback **context**; vtable+2C is the registration method.

For the initial error-free native fast path, read current callback/context from
guest bytes at admission, rather than trusting constructor-time cached values.
Delegate callback registration unchanged and invalidate/reimport any cached
native state afterward. A custom handler is not permission to silently remove
it: operations needing it must fall back before native writes, or implement its
original synchronous guard/reentry/state visibility precisely. Invalid selector
and exhaustion fallbacks are useful even when the currently installed handler
is the known default/return-only chain.

Get invalid-selector reporting precedes clearing its output; availability zeros
its output **before** reporting and does not clear it again afterward. Exhausted
Put/Unget report inside the guard and do not retry after callback return. These
details prohibit generic asynchronous error posting or a bool-error substitute.

## Retained handles and direct-field consumer closure

The following concrete escapes were followed through original instructions:

| Retaining owner / source PCs | Observed local-SJ access |
| --- | --- |
| Paired record `+8`; `13DD64` | Stores constructor result.13DDB4 calls Put through its vtable. Record+10/+14 writes are the initial payload descriptor, **not SJUNI node/head fields**. |
| SJX binding `+4`; `141510`, `141530..141540` | Saves local SJ and transmits local token plus EE binding token. No local callback/head/node mutation in141490. |
| DTR destination `+8`; `138B64..138B74` | Saves source/destination SJ pointers and DTR counters. Does not write fields inside either SJ object. |
| `13E910..13E920` | Passes paired local SJ as DTR destination; the original decoder input is a separate source SJ. Generic source calls cannot be assumed SJUNI. |
| DTR `138650`, stop `138BE0` | Loads object vtable at+0 and uses Get/Unget/Put. Direct stores clear/update DTR saved descriptors, not local SJUNI heads/nodes. |
| SJX collectors `14106C`, `14120C` | Get through local vtable+18 into stack descriptors; transport copies/reserves spans. They do not edit SJUNI metadata directly. |
| SJX receivers `140F80..140F90`, `141124..141134` | Resolve an EE binding then load local pointer+4 and call vtable+20. First receiver uses descriptor pool; second forces pool1. Neither writes SJUNI heads directly. |
| `13ED98`, `13EE08/24/48/9C` | Counts pool0 then Get/Put/Get/Put to consolidate storage. All SJUNI mutation remains through methods. This exposes exact queue ordering/adjacency and one-span4000 capacity, not merely byte totals. |
| Public handle escape `13F1C8`; diagnostic `131518..131548` | Returns raw local object. Known diagnostic only loads vtable and calls byte-count+24 twice. No direct node/head access in this consumer, but the public escape prevents global no-peeking claims. |
| `13DE94`, `13DEA8` | Local destructor is called before unregistering SJX binding. Original order does not prove no pending callback. Do not add native reclamation on pair reservation release alone. |

The bounded global-reference inventory finds object-pool references in140020,
140070 and1400C0; no additional literal node-work/base reference was established
by that graph. This does not discover arbitrary computed aliases, memcpy ranges,
overlay accesses, host writes or future callback code. The owned IOP boundary
stores the EE SJ/binding as tokens; inspected return descriptors resolve the EE
binding and invoke the local guest facade. It is not permission to replace those
wire tokens with native addresses. Current runtime compatibility/audio policies
remain separate dependencies documented in REMOTE_AND_DTX_BOUNDARY.md.

The safe transitional representation therefore retains **all48 object bytes and
all16 sixteen-byte nodes**, including node word+4 and stale payload words in
free nodes. Either import the entire current representation at each admitted
entry or compare it with a complete committed mirror. An unexpected external
change invalidates the sidecar; do not overwrite newer guest bytes with stale
native data. Fall back against the current guest representation, and re-enroll
only through a fresh validated import. A mirror mismatch is not grounds to
repair links, reset queues or clear callbacks.

Snapshot validation detects changes between calls, not racing mutation during a
call. Acyclic/in-range exclusive list ownership, stable node storage and a
serialized operation boundary remain explicit admission conditions. No static
evidence here proves universal concurrent quiescence.

## Scalar results and caller consumption

| Method / known source PCs | ABI result actually observed |
| --- | --- |
| Constructor13DD58 | `v0` is stored at13DD64 and NULL-tested at13DD6C. Preserve the guest object address/NULL, not a native index. |
| Byte sum+24 at12C504/12C544 | Caller logically shifts `v0` right one at12C510/12C550. Byte return width and halfword conversion matter; negative/wrapped bits are not a signed saturating sample count. |
| Byte sum at13ECC8/13ED08 | First participates in4000-minus-count and signed division-by-two adjustment; second adjusts/sign-shifts count/2. Preserve original32-bit arithmetic. |
| Byte sum at13ED98 | Compares `v0` with group capacity5C at13EDA8; exact equality gates DTR consolidation/start. |
| Diagnostic counts131530/131548 | Return values saved into s2/s3 and summed/printed. |
| Get at138770,14106C,14120C,13EE08/13EE48 | Reviewed consumers inspect the output descriptor/length, not a declared Get success code. |
| Put/Unget at13DDB4,1386D0/1387F8/138978,138C54,140F8C,141130,13EE24/13EE9C | Reviewed paths ignore the method's `v0` as a status; they next use descriptors/owner state or overwrite it. This is not proof for every generic SJ caller. |
| Availability1406D8 | Defined `v0`0/1 plus full head length output. No concrete paired-path availability caller was established in the reviewed set. |
| Node counts140768/1407A8 | Defined integer counts; no external direct caller in current indexed graph. Unchecked queue selector at140768 still needs adapter admission or original fallback. |

Get/Put/Unget/reset/destroy/error-registration do **not** normalize `v0` to an
operation status. Do not expose a new bool/error return through that register.
An adapter may leave caller-saved registers unspecified only under the original
void ABI and its admitted callers; it must not claim bit-exact context parity.
Preserve all required callee-saved registers, SP, return PC and generated dispatch
state. Defined integer results require proper guest32-bit/sign-extension
behavior, not host-size `size_t` or an arbitrary64-bit value. The original-word
oracle should distinguish contractual results from volatile clobbers.

## Entry dispatch, continuations and original fallback

The current registration file binds canonical entries separately, but many
continuations belong to larger generated bodies:

| Current registered PC(s) | Saved original binding |
| --- | --- |
| `1400C0`, `1400F8`, `140190`, `1401C8` | Constructor aggregate `sub_001400C0_0x1400c0`; its generated extent includes neighboring helpers. |
| `1401F8`, `140218`, `140260` | Reset aggregate `sub_001401F8_0x1401f8`. |
| `140478`, `1404A0`, `1404B8`, `140538`, `1405D0`, `1405F8`, `14066C`, `140780` | Also bound to the reset aggregate, although several PCs are inside Put/Unget or node count. |
| `140288`, `1402B0`, `1402D0` | Dedicated byte-sum body. |
| `140300`, `140348`, `140360`, `1403E4`, `140418` | Dedicated Get body. |
| `1406D8`, `140710` | Dedicated availability body. |
| `1407A8`, `1407B8` | Dedicated free-node count. |

The reset aggregate's own continuation switch includes even more neighboring
labels. **Function-pointer equality does not establish the semantic operation
of an arbitrary PC.** Capture the actual original binding per registered address
before installing adapters. A noncanonical PC must run that captured binding
with its existing context/frame. Do not run the reset entry logic for a Put
continuation, or restart a prologue on an already-created guest frame. Leave
continuation routes original unless their whole state machine is implemented.

Current generated call sites use lookup-based dispatch before their direct
fallback. Existing override `bind` registers both runtime and stub-override
routes; retain the appropriate installation pattern rather than relying on only
one dispatch mechanism. Saved fallback must not call the newly overwritten
lookup and recurse. This review establishes source routes, not matching compiled
library or executable identity.

For typed direct constructor interception, require **ctx.pc==1400C0**. For queue
operations likewise admit only the selected exact canonical entry. Keep generic
descriptor helper1407E0 original: many unrelated SJRB/file/MPEG/ADXB callers use
it, so replacing it is not local-SJUNI admission.

## Guard gating and why whole-method retry is unsafe

Get enters13F258 at140358 and resumes140360. Put enters at140498 and resumes
1404A0; Unget enters at1405F0 and resumes1405F8. Put/Unget inspect descriptor
length/pointer before entering, then read them again afterward. They can observe
hook/reentrant mutation. The generic entry callback pair is2649E0/+4; leave is
2649E8/+4. NULL callback functions make the generic paths skip their depth/tag
updates; both functions must be NULL for the proposed no-hook fast path.

Known runtime-installed scheduler hooks12A968/12A9F0 do not directly manipulate
SJUNI objects or descriptors. However they perform guest priority/worker
operations, which can allow other work or yield; that fact is not proof that an
object/input snapshot survives the call. Generic hooks are replaceable too.

If an adapter calls a live enter hook and subsequently discovers unsupported
state, it cannot safely restart the entire original method: the original would
enter again, changing nesting/callback traces. A future post-enter fallback must
preserve the original guest frame/registers and resume the exact continuation.
Registering a continuation alone does not intercept normal inline fallthrough
after the generated call returns; a deliberate dispatch handoff/state machine
is required. Original Get uses50hex-byte frame with saved s0..s3/RA; Put/Unget
use20hex-byte frame with saved s0..s2/RA. These cannot be synthesized by merely
changing ctx.pc in an unframed host wrapper.

For this core stage, the conservative policy is therefore:

- Read-only methods: validate full current object/node state and selector/output
  domain first; delegate every error case before even an output-initialization
  write. Availability output must not alias metadata, input state or unsupported
  memory, since the original zero-before-read order is observable.
- Mutating methods: require both hook function words NULL, known local instance,
  valid/acyclic/disjoint node ownership, canonical scalars, admitted descriptor
  addresses, safe span arithmetic/region identity, and an error-free operation.
  In particular, an exhausted pool can still admit an adjacency merge; otherwise
  delegate exhaustion before native mutation. Preserve ignored nonpositive/NULL
  spans and don't invent clamps.
- Any unsupported condition: execute original against the current synchronized
  guest representation. Never replay original against stale pre-native state,
  retry after callbacks, deliver errors asynchronously or add a host-only mutex
  as if it proved scheduler equivalence.
- Lifetime/reset/registration routes: retain original effects and invalidate or
  reimport sidecars. Pool first/last-reference clears and individual destruction
  must invalidate affected instances. Reservation-byte release alone is not
  destruction. Reclamation with pending SJX/DTR work remains outside this proof.

This can demonstrate an independently tested native implementation and a
conservative guest bridge. It does not establish full native operation under
ordinary installed CRI hooks, and must not be reported as having migrated all
player queue traffic or removed the PS2/runtime boundary.

## Evidence audit and source identity

Read-only original-byte checks covered53 complete main intervals: **2,111
instruction-comment words,46 omitted words verified zero, zero conflicts and
zero omitted nonzero words**. They comprise the16 local SJUNI entries through
1407E0, the paired/DTR/SJX/typed-query owners listed above, the callback boot and
registration chain, and the shared guard installation/dispatch bodies. Checks
used the owned ELF plus catalogue bounds, not current host execution.

Exact audited entries, for repeating the read-only original-word check:

```text
140000 140020 140070 1400C0 1401A8 1401E0 1401E8 1401F8
140288 140300 140438 140590 1406D8 140768 1407A8 1407E0
13DB48 13DE40 13DF20 13DF98 13E770 13EAC0 138AB8 138650 138BE0
141490 140F18 140FB8 1410C8 141158 13ED28 13F1C8 1314E0
12C4E0 12C520 13ECB0 13ECF0
1AC640 1AC650 12B620 163800 1280A8 133040 1418A8 141DB0 13F288
1415E0 141640 1416D0 1416E8 13F258 13F270 12B638
```

| New focused complete interval | Original byte SHA-256 |
| --- | --- |
| `1400C0..1401A4` | `5d9eb8b96a7d134aa2d656cf318cdbdbad33fcb3d16a720cdb2a5fd833752af5` |
| `1401E8..1401F4` | `56d0ad1facb4fbb6173de80e7c23a273dc4af693c8ac481c68cc3df109d10e61` |
| `1AC640..1AC648` | `6d64edf91449c1b17746c1ef18afa2eb25c70bdf1322ab3df5a2630993b7e2f1` |
| `1AC650..1AC6B8` | `5b850a0ea1c5912cc00e61a56326622d4589798a7aeb9ff46d85e3f6d3b12cba` |
| `141DB0..141DF0` | `c100da1979d5ec9998661a8727ca89c0b1b89f86f75b78fd8a345d8afbeb4848` |

Current generated-source snapshot used for dispatch findings:

| File | SHA-256 |
| --- | --- |
| `recomp/config/output/register_functions.cpp` | `00b594d33c6c3f7f34123b18821691c244095c9aa9319c94b893707fe4cbff7a` |
| `recomp/config/output/sub_0013DB48_0x13db48.cpp` | `f425c96b8c5534defae267367f8a08340da7a0f31d062619afe1eb099f2840e8` |
| `recomp/config/output/sub_001401F8_0x1401f8.cpp` | `7bc9f3ea3c5f91fdc14bd90afcec8faf03b2b493c1ffd04b562cb41ac5ee5947` |
| `recomp/overrides/reo_override.cpp` | `3c07a747bdab6f4979198475ae31cea9ba2b4f4a1790ceccef9f763dd21aff67` |

These are source-review identities. Adapter implementation may change the last
file after this snapshot; no built-binary correspondence is asserted. Existing
graph/pointer-word evidence remains bounded. The important newly narrowed fact
is boot's return-only lower callback1AC640, not universal absence of callbacks,
direct-field users, races or pending remote work.
