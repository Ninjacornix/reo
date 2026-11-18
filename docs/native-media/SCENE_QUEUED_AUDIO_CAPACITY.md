# Scene queued-audio capacity: producer bounds and remaining content proof

2026-11-09. Offline File #1 owned-artifact investigation. No game launch,
build, live attachment, window action, asset conversion or save write. This
report qualifies the scene caller's producer mechanics; it does not establish
the maximum playlist actually encountered during gameplay.

**Sixteen is sufficient for the reviewed scene-list producer when its request
ring's producer index stays fixed during collection. It is not an unconditional
concurrency bound.** The collector appends one initial request and permits up
to sixteen additional iterations. If another producer replenishes the ring
between iterations, its local arithmetic permits seventeen entries. Neither
an authored seventeen-entry scene nor such an interleaving was observed here.

The accompanying [qualification record](../../tools/native_reconstruction/scene_cue_capacity_qualification_v1.json)
contains artifact/source hashes, exact selected original instruction words,
the direct-writer census and explicit assumptions. No admission guard is relaxed.

## Owned identity and corrected list address

Owned `build-function-index/owned-overlays/o2.bin` is based at `0x570000`,
SHA-256 `45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226`.
The main ELF `game_data/SLUS_207.65` passes `tools/function_index/index.py::Elf`
identity validation: SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
Every instruction comment in the eight source bodies recorded in the manifest
was checked against this owned overlay. Unlisted words within the full collector,
selector, queue writer and script-handler ranges were checked separately and
are zero/NOP. The manifest retains full original range hashes.

The audio list and merged-DM list have **the same base**, `0x4BAE36`:

| Owned PC | Original word | Instruction / consequence |
| --- | --- | --- |
| `0x6D7484` | `0x3C02004C` | `lui v0,0x4C` |
| `0x6D7488` | `0x2442ADD0` | `addiu v0,v0,-0x5230`: base is `0x4BADD0` |
| `0x6D7498` | `0x90460066` | read first byte at base + `0x66 + 3*i` |
| `0x6D74A0` | `0x90470067` | second byte |
| `0x6D74A4` | `0x90480068` | third byte |

Thus `0x4BADD0 + 0x66 = 0x4BAE36`. The existing `0x4BAD30` claim is a
transcription error, not a distinct audio descriptor array. Correction targets
are `docs/SYMBOLS_SCENARIO_ADX_NAME_SELECTION.md:11` and the rationale for
`o2:0x006D7470` in `tools/function_index/annotations.json:146660`.
Those existing files were not changed by this investigation.

## Actual producer and format

`o2:0x68F010`, script opcode `0x62`, packs the first five payload words into
five halfwords, appends three zero halfwords, and calls `0x5F0150` at `0x68F108`.
Owned dispatch slots `0x7179B8` and `0x73CEF0` both point to `0x68F010`.
Actor-state admission can bypass this append or substitute the owned payload
at `0x7174D0`; the handler is not an unconditional queue operation.

`0x5F0150` copies those eight halfwords to request storage
`0x3B26D0 + 16*producer`, then increments and masks producer `0x3B27D0`
with `0xF` (`0x5F0218/0x5F0224`). It has no full-ring check.
`0x5ECA90` initializes both request indices to zero.

`0x5F0380` consumes this request ring using consumer `0x3B27D8`:

1. Read one 16-byte request and advance/mask the consumer. Publish request
   halfwords 0/2/4/6/8 as the mode, two scene IDs, selector and actor selection
   near `0x38ECCF..0x38ECE0`. Mode 3 is normalized to mode 1.
2. Clear count byte `0x4BAE0B` at `0x5F046C`. Mode zero leaves it zero.
3. For a nonzero mode, set count to one at `0x5F04C0` and write the first
   triple at `0x5F04C8/0x5F04D0/0x5F04DC`.
4. Before each additional entry, reread the producer at `0x5F04E0`, stop on
   equality at `0x5F04E4`, or stop if the next request's kind is zero at
   `0x5F0500`. Append its low-byte scene IDs and the selector's resolved
   low-byte result at `0x5F052C/0x5F0544/0x5F057C`; increment count at
   `0x5F058C`. Advance the local consumer modulo sixteen at `0x5F0568`.

`0x5F0230` resolves the third component using request selector/actor state.
Its entire original body contains loads, arithmetic, branches and return;
there are no stores or calls. Consequently an EVB payload's third field is
not always a literal final audio-key component.

`0x6D7470` walks unsigned count `0x4BAE0B`, formats `%02d_%02d_%d`, resolves
through `0x6D7520`, and enqueues only successful lookups before starting the
stream. The earlier [caller asset audit](NATIVE_AUDIO_CUE_CALLER_ASSETS.md)
establishes 323 table rows / 236 distinct scene names and their finite stereo
48-kHz admission; those totals are not playlist lengths.

## Bounds and concurrency limit

With normalized indices in `[0,15]` and a fixed producer, the local consumer
reaches producer equality within at most fifteen additional advances after
the first request. Therefore count is at most sixteen. If the initial ring
is nonempty, the same fixed-index arithmetic gives at most fifteen entries;
sixteen conservatively also covers an initial equal-index stale read.
These are arithmetic bounds, not claims that either maximum occurs in content.

The explicit additional-iteration counter starts at zero (`0x5F048C`),
increments at `0x5F0564`, and continues while less than sixteen:
`0x5F0590 = 0x28C20010`, `0x5F0594 = 0x1440FFD2`. That cap applies to
**additional** entries; the initial entry was already counted. Without a
fixed producer, the local limit is therefore seventeen, assuming another
writer does not independently overwrite the count itself.

The generated collector calls `runtime->shouldPreemptGuestExecution()` on
the backward branch at source line 505. A pure selector helper does not make
collection atomic. This review has not established which other guest threads
can execute the opcode-62 producer during that interval, or whether the guest
scheduler excludes that interleaving. It does not claim that seventeen is
reachable in normal gameplay. The audio consumer also has backward-branch
preemption and rereads count, so global count stability must not be presumed.

The static index and a bounded search across generated main/extra/overlay
instruction listings identify five direct absolute stores to `0x4BAE0B`:
`0x5F046C`, `0x5F04C0`, `0x5F058C`, `0x5FFD10`, `0x600320`.
The last two store one in death-movie setup. The index identifies queue-index
writes in `0x5F0150`, `0x5F0380` and reset `0x5ECA90`.
This is a census of resolved direct references, not proof excluding indirect,
bulk-memory, aliasing, externally rewritten or corrupted state.

## Content extraction and capacity policy

The named inventory supplies five EVBs, whose exact original bytes were read
from the owned ISO and checked against inventory hashes: `r001.evb`
(`NETBIO00.DAT/1/1680`), `r002.evb` (`/3/1163`), `r028.evb` (`/5/937`),
`r035.evb` (`/7/1042`), and `r041.evb` (`/9/1908`). The manifest records each
ISO offset, extent and digest. These are verified extraction inputs, not a
complete decoded scene-list census. Unnamed assets are not classified as unused.

To measure the authored maximum, parse the EVB pointer/stream structure using
owned `0x68C260` relocation rules, then decode records according to dispatcher
`0x68C660`: opcode low 24 bits, span `4*(1 << header_high_byte)` with the
guest shift semantics. Trace opcode-62 payloads through the actor admission,
ring overwrite/wrap, selector resolution and collection boundaries above.
Preserve branch/condition and scheduling alternatives; a raw word search or
consecutive opcode count cannot establish a feasible playlist. Include room
script banks routed through `0x7006D0`, whose opcode-62 slot is also verified.
Inventory headers alone do not establish complete script/asset reachability.

The present native bound of sixteen can remain an explicit admission policy:
preserve every admitted sixteen-entry burst and report a capacity failure for
a larger burst. Do not silently drop or truncate entries, equate a refused
seventeenth entry with successful playback, or describe the policy as a proven
universal File #1 content bound. Raising it to seventeen would cover the local
collector cap under the stated count-ownership assumption, but would still
require a coherent native implementation and validation of other queue callers.
