# Optional local SJUNI runtime bridge

This is the temporary File #1 adapter for
`game/native/sjuni_adapter/queue_bridge`. The independent queue implementation
remains in `game/native/sjuni`; neither component depends on this runtime file.
Original construction, reset/destruction, callback registration, reference
counts, guest vtables, remote SJUNI, DTR/SJX and audio stay intact. A second
opt-in can substitute the queue body after the original guard/prologue.
This pilot does not remove those dependencies or establish a performance gain.

Root build integration supplies the default-OFF
`REO_BUILD_NATIVE_SJUNI_ADAPTER` option and calls
`reo_native_sjuni::install(runtime)` for File #1 after ELF and original function
registration. Compiling this source with `REO_GAME_FILE2` is rejected. At runtime,
installation additionally requires exactly `REO_NATIVE_SJUNI=1`; an unset or
different value does nothing. The setting is read at installation, not polled
as a live toggle. No renderer, VU path, original game speed or other developer
option is enabled by this adapter.

The additional `REO_NATIVE_SJUNI_GUARDED=1` flag enables only the reviewed
known-hook post-enter phase below. Both flags are required. Guarded mode is also
captured at first installation; changing it on a repeated install is refused
and requires a fresh process. The default guarded-flag-off behavior is retained.

`REO_NATIVE_SJUNI_TRACE=1` separately enables bounded proof logging. It is also
cached at installation; it is off by default and changes no gameplay setting.

## Installation and original paths

The loaded bytes `[140000,140840)` must have SHA-256
`544376807278847bc0f4294c7a62238acff5a645accc2ec2dec9bf58073d5cc2`.
Identity is checked from runtime RAM using the existing bounded SHA implementation.
All seven original bindings must exist before any wrapper is registered:

| Entry | Operation |
| --- | --- |
| 140288 | Queued bytes |
| 140300 | Get |
| 140438 | Put |
| 140590 | Unget |
| 1406D8 | Availability |
| 140768 | Queued nodes |
| 1407A8 | Free nodes |

Each original is captured individually, requiring `hasFunction(address)` before
`lookupFunction`: the real runtime returns a **nonnull default function** for
missing addresses. A lookup pointer alone is insufficient, particularly before
committing a body whose epilogue must restore the original frame.

With guarded mode off, only the seven canonical addresses are installed in
runtime and stub-override tables. Guarded mode additionally intercepts13F258 and
post-enter PCs140360/1404A0/1405F8; their originals are captured separately.
Other aliases remain unchanged, including other Put/Unget labels mapped to the
generated reset aggregate. A wrapper presented a different PC delegates to its saved
original; it never treats function-pointer equality as semantic entry identity.
Fallback calls the captured original once, without recursively consulting the
overwritten lookup.

Installation is for one runtime/process lifetime. Ownership is atomically claimed
without a new global mutex. Repeated installation on that runtime rechecks RAM
identity, loaded text and current wrapper/completion bindings; it refuses a changed
instance. Calls also require the originally registered RAM pointer. There is no
adapter teardown/reclamation API or promise that arbitrary runtime destruction,
address reuse or in-place ELF reload can be adopted. A second runtime is refused;
start a fresh process for a new runtime lifetime. Partial installation failure
disables native admission; any already installed wrapper retains its captured
original fallback.

## Per-call admission

The adapter uses the existing public recursive
`PS2Runtime::GuestExecutionScope`, including around original fallback. It adds
no independent mutex and does not depend on private/test-only depth-inspection
exports. Existing release scopes can release/reacquire the complete recursion
depth. This provides the runtime's current ownership boundary; original scheduler
timing and every external memory writer are not thereby proven equivalent.

Every attempt imports the current guest representation. It admits only:

- Canonical signed32 used scalar arguments, a valid queue0..3, nonnegative
  Get/availability request, a normal entry outside a delay slot, and a bounded
  guest SP. Unused arguments are not invented as additional API requirements.
- A48-byte active object in the64-entry pool at228C98, vtable228C60,
  UUID pointer23DA78, mode1 and exactly16 nodes. Node work must be one of the
  256-byte slots in221780..223780, with the corresponding paired-record local
  pointer at221480+24*slot+8 equal to this object. This is a narrow current-layout
  admission, not complete constructor-provenance or alias closure.
- Complete, acyclic, nonoverlapping node-list ownership. Node word+4 and stale
  free-node payload fields remain observable and preserved.
- A nonzero, nonwrapping registered numeric IOP arena from base221448 and
  length22143C. Payload tokens are opaque: no IOP token is dereferenced as host
  RAM. The portable bridge rejects queued spans outside this region or
  unsupported arithmetic before any guest effect.
- Four-byte-aligned, bounded descriptors with no overlap with local object/node
  arenas, this original method's possible80-byte stack window below SP, or the
  protected identity/hook/config/text ranges. The object and nodes themselves
  must not overlap that stack window. Aliased or noncanonical cases use original
  code instead of changing its store ordering.

Queries require valid selectors; error paths always go to original code before
an availability-output initialization or other effect. The **canonical mutation
fast path requires both generic guard function words2649E0 and2649E8 NULL**.
With live hooks, canonical Get/Put/Unget execute the original prologue/enter;
without the second guarded opt-in they remain wholly original. Installation
alone does not establish how much actual player traffic has migrated.

Put/Unget preflight also excludes free-node exhaustion that could invoke an
original per-object error callback. A mode1 adjacent merge may proceed with an
empty free list; the bridge still independently verifies arithmetic and region
admission. Ignored NULL/nonpositive spans retain their original semantics.
External callbacks are never dispatched from the portable bridge here:
`execute(..., callbacks={})` is mandatory. Custom callback fields remain in the
guest image, but native-admitted paths cannot need error delivery.

## Optional known-hook post-enter phase

Guarded mode retains the actual shared13F258 enter implementation and invokes it
exactly once, including unrelated callers and yielding guards. Native body
admission occurs only at an exact post-enter PC/RA with an existing original
frame, hook functions12A968/12A9F0, both hook contexts0, positive shared depth and
outer tag1. Unknown hook pairs, contexts, state or frames continue original code.
The known scheduler hooks still run; the native bridge invokes no additional
enter/leave callbacks.

Additional loaded-code identities are required before any registration:

| Range | SHA-256 |
| --- | --- |
| 13F258 +2C bytes | `97218c39f837a28ce2f4560c583267b2bd6cf904fb18936452f6789d7b86400a` |
| 1415E0 +120 bytes | `d2c7826232ca09d9f56b4db337934471c3fdae215bd9b9867ec75c5b1f717e7f` |
| 12A968 +84 bytes | `173cf0829a949c1074b00a1cdd812b99a87e19ff14bb2dee77ba5f3437b6121a` |
| 12A9F0 +70 bytes | `dcca4986672ca8c131ca8fe8cb442312f39dfc5f7517f9615d7362736a520fb2` |

Addresses and sizes in that table are hexadecimal. The actual leave13F270,
Get epilogue140418 and all three post-enter bindings must be registered before
installation. Leave/epilogue existence and identity are rechecked **before** a
body can commit. Removing an epilogue cannot silently dispatch the runtime's
default function after a successful native mutation.

| Post-enter PC | Preserved operands | Existing original frame |
| --- | --- | --- |
| 140360 (Get) | s0=object,s2=queue,s1=output,s3=request |50 bytes; saved s0/s1/s2/s3/RA at20/28/30/38/40 |
| 1404A0 (Put) | s0=object,s2=queue,s1=input |20 bytes; saved s0/s1/s2/RA at0/8/10/18 |
| 1405F8 (Unget) | s0=object,s2=queue,s1=input |same20-byte frame |

The adapter copies the full real context into a probe, derives arguments from
these preserved registers, and uses `currentSP+frameSize` as a virtual caller SP
**only for admission**. Caller-saved a0..a3 may be poisoned by the real enter
hook. The original frame is not synthesized or rewritten. All restore words
are preloaded/range-checked before the private transaction can commit. The
virtual caller SP makes the existing80-byte exclusion cover the actual saved
frame. A parent return matching13F258 or this post-PC is excluded to avoid the
containing generated call's entry-PC normalization executing the body twice.

The current object, nodes and input descriptor are imported after enter, so valid
nested mutations or a changed input descriptor are observed. A current NULL or
nonpositive Put/Unget input is rejected here: the original post-enter body does
not repeat canonical pre-entry span admission, while the core canonical API
would ignore such an input. Exhaustion and all other unsupported cases likewise
continue the captured **post-enter** body, not canonical entry. A rejected probe
preserves the entire real context. The enter wrapper can simply return the
expected post-PC for original inline execution; a resumed post wrapper calls its
captured original continuation. Neither route enters again.

After successful body commit, completion is outside every fallback catcher:

- Get invokes the actual original13F270 once with RA140418 and its50-byte frame
  still active. If leave completes, the captured original140418 epilogue restores
  the frame. If leave yields, existing original continuation/140418 registrations
  finish the operation later.
- Put/Unget restore the saved low64 s0/s1/s2/RA and caller SP before tail-invoking
  original13F270 once, matching their original epilogues. Upper GPR lanes retain
  the existing register macro behavior. A yielding leave resumes its own original
  context rather than replaying a queue operation.
- An original leave that returns without changing its entry PC is normalized
  once to140418 (Get) or the restored parent RA (Put/Unget), following generated
  dispatch conventions. A guard that returns with its entry PC unchanged is
  left to the containing generated caller's original normalization/fallback.

Original enter/leave effects and any yields are retained; this is not a native
mutex replacement or proof of original scheduler timing. No persistent native
queue cache, pending-frame registry or generation/lifetime guarantee is added.

## Private transaction and failure handling

The imported48-byte object and16 metadata nodes are rebased into a512-byte host
scratch image. Only node links, list heads and the metadata node-base field are
translated; original payload tokens, lengths, UUID/vtable values, callback/context
and untouched node words retain their numeric values. The descriptor occupies a
separate nonoverlapping scratch location. This avoids a full-RAM copy and any
audio payload copy.

The core/bridge executes against that scratch image. Every allocation, arithmetic
check, encoding and post-operation validation finishes before guest commit. The
result is then translated back to original node addresses. Mutation mirrors only
queue/node fields; Get and availability publish their descriptors. Defined query
results use guest sign-extended32-bit `v0`; void Get/Put/Unget do not invent a
success/error return value. Canonical completion preserves SP/callee registers
and returns to RA; guarded completion uses the original frame/leave procedure
above. Undefined intermediate volatile clobbers and unused stack scratch are not
claimed bit-identical to generated instructions.

Portable `fallback_before_effects` delegates original once. An allocation failure
or unexpected bridge contract/image violation disables the pilot and emits a
diagnostic, without stopping or killing the game. Crucially, such failure has
changed **only private scratch bytes**, invoked no external callback, and committed
no queue effect, so original delegation is still safe. After an already completed
enter, delegation means only its **post-enter continuation**, never canonical
restart or undoing an external guard's effects. This is not permission
to restart a body after partial guest queue commit.
The final commit is allocation-free, range-validated and contains no callbacks
or runtime dispatch; there is no post-commit fallback branch.

## Optional bounded migration proof

Installation messages prove registration, not that any real call migrated. With
the trace flag explicitly enabled, successful native bodies emit only:

```text
[native-sjuni] native op=get guarded=1 calls=1 queue=0 slot=0
```

Counters are separate per operation and canonical/guarded phase. A counter is
incremented **only when tracing was explicitly enabled**, after successful native
body commit. It logs its first four calls and then powers of two; it does not
log every update/sample. Fields contain operation/phase/count and bounded
queue/object-pool slot indices, with no payload bytes, pointers, filenames,
player identity or other user data. The logger is `noexcept`, uses no new C++
allocation and cannot trigger a post-commit fallback. A guarded-body line proves
the body migrated; it does not prove leave completion, audible playback, original
frame counts, bottleneck attribution or an improvement in speed.

Controlled game testing additionally needs a strongly identified **candidate
binary and matching runtime libraries/source/toolchain**, not only these source
hashes. Use the same identified candidate for environment-disabled and enabled
comparisons; retain launch/log identity and proof lines. A successful install
without native-body lines is not a positive migration result. This directory's
tests do not themselves launch or certify a game build. The adapter's default-OFF
build/runtime switches preserve the baseline until a separate controlled test.

## Verification and limits

The translation unit compiled as an object against current real runtime headers
with MinGW g++/C++20 and SSSE3/SSE4.1. `-Wall -Wextra -Werror` was used with the
existing runtime header's unused-variable/parameter warnings suppressed. This
checks declarations/includes/code generation; it is not a complete game link or
proof of correspondence with an existing user's executable/static libraries.

A reproducible [synthetic harness](tests/harness.cpp) with
[mock runtime headers](tests/ps2_runtime_macros.h) links the actual adapter source,
portable bridge and independent core. It uses mocked runtime/context/registration
services and original-method sentinels; loaded original text bytes are used only
for the SHA gate, never executed. Run the [host-only driver](tests/run_checks.py):

```text
python recomp/overrides/native_sjuni/tests/run_checks.py --check-runtime-headers
```

Pass `--cxx <g++-or-clang++-path>` if necessary. The driver derives text from the
hash-checked owned ELF into ignored `build-native-sjuni/runtime-adapter-checks`;
no owned executable text is embedded in the authored test sources. All thirteen
fresh-process scenarios passed: the original guarded-flag-off operation scenario
still has1,063 assertions; [guarded operations](tests/guarded_harness.cpp) add2,739
assertions plus separate binding/hash refusal scenarios. They cover:

- Runtime opt-in absent, bad/right text hash, missing original binding,
  successful/idempotent install, unchanged continuation mapping, changed
  binding/RAM/text reinstallation refusal and safe partial-registration failure.
- Native queries with live hooks and original-once mutation fallback with hooks.
- No-hook Put/Get/Unget, availability and both node counts, output tokens and
  full16-node link rebasing with untouched word+4 preservation.
- Selector/canonical-width/region/chain/descriptor/stack rejection before writes.
- Exhaustion fallback despite a custom error token, plus exhausted-list adjacent
  Put/Unget merges that need no callback.
- Preserved callee and argument registers, undefined void `v0`, restored PC,
  balanced mock execution scopes and allocation-failure disabling with no guest
  commit followed by original-once fallback.
- Original enter once, preserved-register arguments despite volatile poisoning,
  fresh descriptor/nested queue changes, original post-enter fallback without
  a second enter, all three frame completions, enter/leave yields, unchanged-PC
  guard conventions, actual saved-frame alias rejection and removed completion
  binding rejection before commit.
- A nonnull missing-function sentinel, matching real lookup semantics: missing
  primary/enter/leave/epilogue/post bindings and wrong guard dependency hashes
  refuse installation before any wrapper is published.
- Trace-disabled canonical/guarded calls leave every proof counter zero.
  Trace-enabled tests complete native guarded calls and17 real native query
  invocations; the runner checks exact query log cadence1,2,3,4,8,16 and a
  guarded-body proof line. The trace-on scenario passes2,853 assertions.

The harness is host-only verification, not the original instruction oracle,
actual scheduler concurrency, installed-library ABI/link validation, audio or
gameplay retesting. Original instruction continuation and independent hybrid
comparisons are separate in `tools/native_reconstruction/`:
`sjuni_continuation_contract.py` and `compare_sjuni_continuations.py`. The mocks
check adapter dispatch/frame/fallback integration; they are not a second claim
of an original queue oracle.
Subsequently, a separate complete SDK runtime/backend/game rebuild and four
controlled original/native smoke runs passed their stated observations. Native
bodies were reached during title/media and bar gameplay; all four runs exited
normally after window-close requests. See
[candidate validation](../../../docs/native-sjuni/CANDIDATE_VALIDATION.md) for exact
binary/source identities, evidence counts and coverage gaps. This does not
establish frame/waveform equivalence, general lifetime parity or a speedup.
See `docs/native-sjuni/ADAPTER_ADMISSION_REVIEW.md` for exact
original PCs and its earlier baseline live-hook deferral. The opt-in phase above
implements only the newly reviewed known-hook subset; alias, lifetime, installed
binary identity outside that candidate, wider playback/lifetime coverage and
performance remain open.
