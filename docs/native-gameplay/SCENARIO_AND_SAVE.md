# Scenario execution and native save snapshot boundary

Status: the first native **save snapshot/codec** domain is implemented and passes
original-body differential checks on LLVM and GCC. It is not installed into game
callers yet. Scenario VM execution, event tasks, card UI/backend ownership and
whole Stage 4 completion remain open. No game, card load/write, live process or
window access was performed for this work.

## Evidence and coverage

The owned File #1 ELF SHA-256 is
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Its owned o2 image SHA-256 is
`45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.
The [qualification](../../tools/native_reconstruction/gameplay_save_qualification_v1.json)
binds source files, owned instruction comparisons, the native API, compiler
receipts and the explicit false opcode mask. Research labels are observations
about original contracts, not recovered original symbols.

The [VM investigation](../SYMBOLS_SCRIPT_VM.md) establishes the game-content
interpreter's table at `0x717830`: **432** observed slots, **220** default slots,
**212** nondefault slots and **213** distinct targets. The next word is
`0x00040404`, supporting this data-table extent rather than a runtime bounds
guarantee. Existing mapping/body coverage is not native execution coverage:
**0/432 native opcode slots are implemented by this change**. Every native mask
bit remains false in the generated inventory. No subset replaces the original
dispatcher and no unknown opcode is silently treated as a native no-op.

## Scenario contracts and dependency slices

The content bytecode interpreter is a valid native-game architecture. It is
separate from executing PS2 CPU instructions. A replacement must own these
original contracts before it becomes authoritative:

| Boundary | Original evidence | Required ownership |
| --- | --- | --- |
| Script dispatch `0x68C660` | Low **24-bit** opcode; header high byte controls `4*(1<<exponent)` span using original variable-shift behavior | Bounded content records, per-channel instruction/saved/block pointers, countdown and condition ordinal |
| Dispatch results | Return 0 advances, 1 retains handler-selected pointer, 2 reloads/re-enters; opcodes `0x0A/0x0D` yield | Preserve each distinction and per-tick countdown; no wall-clock reinterpretation |
| Nested conditions | `0x68C990`, `0x68C9E0`, `0x68CBE0`; opener list includes opcodes above `0xFF` | Complete nested-record walking and failure/else differences; validate malformed data without inventing gameplay |
| Flag timers | Eight signed halfword timers; original flag mutators/notifications | Scenario/session/local bank identity, notification ordering and original callback cadence |
| Event tasks | Two 24-slot owner/kind dispatch tables at `0x709620/0x709680` | Task admission/recycling, child acknowledgements, room counters, actor references and all phase transitions |
| Content actions | Existing sequence, entity, effect, actor, room/loading and audio handlers | Native actor/effect/resource/audio services and stable content IDs; no addresses or fake success callbacks as final owners |

The event-task tables are not the script opcode table. Their puzzle timers,
signed-byte phases, owner/session policies and allocation assumptions cannot be
normalized from their proposed labels. The scenario documentation covers actor
factory/pools, model children, joint effects, room/loading/exit transitions,
messages, auxiliary resources and sound mapping. Those are separate dependency
slices, not proof of an already migrated scenario engine. Their exact existing
document hashes and bounded inventory are retained in the qualification.

## Implemented native save domain

[`snapshot.hpp`](../../game/native/gameplay_save/snapshot.hpp) and
[`snapshot.cpp`](../../game/native/gameplay_save/snapshot.cpp) use native-owned
arrays, fixed-extent byte spans and explicit service callbacks. They include no
runtime, register, instruction-decoder or guest-address headers. Calls are
externally serialized and their live state/container storage must not alias.

The complete resident snapshot family `0x1C52B0..0x1C5760` is represented:

| Original entries | Native contract |
| --- | --- |
| `52B0`, `5300`, `5340`, `53B0` | Header/settings/flags and all four snapshot sections; exact zeroed ranges and untouched padding |
| `5410` | Timestamp service → all captures → exactly one RNG service draw with argument 1 → encode |
| `5480`, `54E0`, `5500`, `5520` | Settings copy → settings notification → flags → first/second/tail restores; original conditional eight-byte copy |
| `55C0` | Decode; any format/checksum failure returns original −1 without live restore; successful ordered restore returns 0 |
| `5630` | Root mode 0/1 clears only second flag and second live section; all other modes preserve them |
| `56A0`, `5760` | Complete fixed-length little-endian XOR/checksum codec and exact failure mutation |

All addresses in this table share prefix `0x1C`; numbers below are hexadecimal
unless stated otherwise. The container is `0x3FCC0` bytes; eight outer bytes
precede a `0x100`-byte header and data begins at `+0x108`. Encoded payload length
is `0x3FCB8`, or `0x1FE5C` halfwords.

| Native raw section | Original live range | Snapshot data offset | Capture policy |
| --- | --- | --- | --- |
| Settings, 16 bytes | `0x3241A0` | Header `+8` | Copy; raw flags from `0x324476/0x324488/0x32448D` go to header `18/19/1B` |
| First, `0x4234` bytes | `0x31FB60` | `0` | Clear first `0x10000` bytes, then copy |
| Second, `0x7000` bytes | `0x318B60` | `0x10000` | Clear `0x1FBC0` bytes from this offset, then copy unconditionally |
| Third, `0x8000` bytes | `0x35F080` | `0x2FBC0` | Copy |
| Tail, `0x40` bytes | `0x36F080` | `0x37BC0` | Copy; no trailing-padding clear |
| Conditional, eight bytes | `0x3165A8` | Derived on restore | Copy first eight restored tail bytes **only when tail byte zero is nonzero** |

The last rule deliberately preserves the original loop testing the **same first
byte** repeatedly. It is not changed into “any of the first eight bytes nonzero.”
Header `+1A`, unknown header bytes and the unused encoded tail retain their
caller-supplied bytes. This component does not assign gameplay semantics to raw
sections or silently introduce a new on-disk schema.

The codec writes magic `0x5963`, low 16 seed bits, modulo-`0x10000` plaintext
halfword sum, and a zero reserved halfword. Each payload halfword is XORed with
the current seed. Only **after** that word uses a zero seed is it replaced with
1 for the next `(176 * seed) % 0xFF53` step. Decode returns −1 for bad magic
without mutation, −2 for checksum failure **after mutating the complete payload**,
or 0. It preserves the original weak checksum format and makes no cryptographic
integrity claim. The higher-level original restore collapses either failure to
−1. Native admission separately reports `dependency_unavailable` before mutation
when a required service is missing.

## Explicit external services and actual caller migration

Timestamp, shared RNG and settings notification remain named dependencies:

- Original `0x1BF660` obtains/converts the clock, writes eight timestamp bytes,
  and computes its weekday byte. Its clock fallback and calendar helpers remain
  outside this native snapshot module; no new host-time policy is invented.
- Original `0x1AEC80(1)` advances shared guest RNG state. Capture calls its service
  once, after all section copies. A caller must preserve the shared RNG owner and
  draw order; independently seeded save RNG would change the game.
- Original `0x1BADF0` mirrors settings fields and calls `0x1AF790/0x1B86C0/
  0x1B86F0/0x1B8780`. Notification occurs after settings copy but **before** the
  three raw flags are restored. This is observable ordering, not an empty hook.

Actual resident UI callers have these verified call sites:

| Original caller | Calls into the new boundary | Caller policy to retain |
| --- | --- | --- |
| `0x1C3150` explicit load | Restore at `0x1C344C` | Pending read, decode error UI, acknowledgement and profile-flag differences |
| `0x1C3590` temporary load/rewrite | Restore `0x1C3754`, capture `0x1C3790` | Clear the two resume flags then rewrite; do not call this deletion |
| `0x1C3950` resume selection | Restore `0x1C3AEC` | Resolver `0x37B950`/selector binding remains unresolved |
| `0x1C3C90` save/create/overwrite | Multiple capture/clear-second sites | Confirmation, backend numeric commands and mode-specific clear policy |
| `0x1C4390` save-policy toggle | Multiple capture/clear-second sites | Raw flag XOR and error/port-change policy differences |
| `0x1C4970` automatic save | Capture `0x1C4AB0` | Original admission flag and timed success/error acknowledgement |

The qualification retains every exact site in these six bodies, checked against
owned ELF words. They are integration targets, **not already migrated callers**.
The root integration must admit complete buffer extents, preserve unknown
padding, route real shared services, establish native state ownership and keep
the original UI/backend/co-op policies until those domains are independently
ported. No CMake, build preparer, adapter, generated body or game caller is edited
by this independent module change.

## Verification and remaining work

Both LLVM and GCC pass **1,018 assertions**: 72 full-container encode/decode
comparisons, 16 complete original capture/restore chains, eight failed whole
restores and seven root-mode policies. Checks cover zero/high-bit seeds,
checksum overflow/failure, full post-failure mutation, untouched padding,
non-Boolean raw flags, the first-byte-only conditional tail copy, dependency
order and notification observing new settings with old flags. Missing services
refuse before container mutation.

The oracle compiles the **actual generated original bodies**, with their 377
instruction comments checked against the owned ELF. Bounded register/memory
scaffolding and explicit memcpy/time/RNG/notification doubles exist only in the
offline test. This does not ship a MIPS interpreter or prove those external
services' independent semantics. The decoder source also contains a subsequent
icon-loading body; its dependencies throw if reached, and every qualified decode
returns before it. Strict GCC first rejected one misleading-indentation line in
the fixture; that failed cohort is retained, braces were corrected, and both
final cohorts pass unchanged production code.

Remaining work is explicit: install and qualify the real caller/state bridge;
qualify real card assets and load/save/resume policy; port clock/settings/shared
RNG dependencies to their authoritative native owners; migrate the complete
scenario interpreter and all its content actions and event-task phases; then
validate gameplay/co-op/save compatibility. No percentage of handler mapping is
used as a percentage of native execution or whole-game completion.
