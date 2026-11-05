# Optional local SJUNI runtime bridge

This is the temporary File #1 adapter for
`game/native/sjuni_adapter/queue_bridge`. The independent queue implementation
remains in `game/native/sjuni`; neither component depends on this runtime file.
Original construction, reset/destruction, callback registration, reference
counts, guest vtables, continuations, remote SJUNI, DTR/SJX and audio stay intact.
This pilot does not remove those dependencies or establish a performance gain.

Root build integration supplies the default-OFF
`REO_BUILD_NATIVE_SJUNI_ADAPTER` option and calls
`reo_native_sjuni::install(runtime)` for File #1 after ELF and original function
registration. Compiling this source with `REO_GAME_FILE2` is rejected. At runtime,
installation additionally requires exactly `REO_NATIVE_SJUNI=1`; an unset or
different value does nothing. The setting is read at installation, not polled
as a live toggle. No renderer, VU path, original game speed or other developer
option is enabled by this adapter.

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

Each original is captured individually. Only the seven canonical addresses are
installed in runtime and stub-override tables. Existing continuation aliases
remain unchanged, including Put/Unget labels mapped to the generated reset
aggregate. A wrapper presented a different PC delegates directly to its saved
original; it never treats function-pointer equality as semantic entry identity.
Fallback calls the captured original once, without recursively consulting the
overwritten lookup.

Installation is for one runtime/process lifetime. Ownership is atomically claimed
without a new global mutex. Repeated installation on that runtime rechecks RAM
identity, loaded text and all seven current wrapper bindings; it refuses a changed
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
an availability-output initialization or other effect. **Mutation additionally
requires both generic guard function words2649E0 and2649E8 NULL.** With live CRI
scheduler hooks, Get/Put/Unget remain original. Thus installation does not mean
ordinary player audio mutations have migrated.

Put/Unget preflight also excludes free-node exhaustion that could invoke an
original per-object error callback. A mode1 adjacent merge may proceed with an
empty free list; the bridge still independently verifies arithmetic and region
admission. Ignored NULL/nonpositive spans retain their original semantics.
External callbacks are never dispatched from the portable bridge here:
`execute(..., callbacks={})` is mandatory. Custom callback fields remain in the
guest image, but native-admitted paths cannot need error delivery.

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
success/error return value. SP, callee-saved registers and all unrelated registers
are preserved, and PC returns to guest RA. Undefined volatile clobbers are not
claimed bit-identical to generated instructions.

Portable `fallback_before_effects` delegates original once. An allocation failure
or unexpected bridge contract/image violation disables the pilot and emits a
diagnostic, without stopping or killing the game. Crucially, such failure has
changed **only private scratch bytes**, invoked no external callback, and committed
no guest effect, so original delegation is still safe. This is not permission
to restart a real operation after a guest hook/callback or partial guest commit.
The final commit is allocation-free, range-validated and contains no callbacks
or runtime dispatch; there is no post-commit fallback branch.

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
no owned executable text is embedded in the authored test sources. The five
fresh-process scenarios passed, including1,063 assertions in the operations
scenario. They cover:

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

The harness is host-only verification, not the original instruction oracle,
actual scheduler concurrency, installed-library ABI/link validation, audio or
gameplay retesting. The independent core/bridge comparisons remain separate.
No game launch, full game rebuild, live capture or performance test was performed
for this adapter. See `docs/native-sjuni/ADAPTER_ADMISSION_REVIEW.md` for exact
original PCs and the remaining live-hook/alias/lifetime boundaries.
