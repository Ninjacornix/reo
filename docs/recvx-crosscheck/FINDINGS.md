# Findings from the Code: Veronica comparison

The 2026-11-05 [second-pass findings](SECOND_PASS_FINDINGS.md) extend this first
review, correct actual field/argument claims and adopt the two candidate aliases
below. Their detailed current evidence is in the filesystem, audio, stream and
engine follow-ups. Earlier statements here about unnamed aliases and unverified
UUID identity describe the preceding pass and are superseded as noted below.

The comparison supports shared CRI interfaces, not a shared complete engine or
drop-in source replacements. Definitions and confidence counts are in the
[review scope](README.md); individual pinned references and original Outbreak
labels are in the [crosswalk](CROSSWALK.md).

## Two concrete naming leads

### Main 0x136688: candidate `cvFsLoadDirInfo`

The [current Outbreak label](../SYMBOLS_CRI.md) is
`cvfs_optional_path_query_vtable48_candidate`. Its instructions preserve the
three original arguments, split/default/optionally rewrite the path, resolve a
device interface and call method **+0x48**. Its copied diagnostic names
`cvFsIsExistFile`, even though Outbreak already has a separate +0x40 existence
wrapper at 0x1364D0.

The pinned CVX [cvFsLoadDirInfo implementation][cvfs] and [interface
header][cvfs-header] explain this ambiguity: the +0x48 slot is `LoadDirInfo`, its wrapper
takes `(name, inf, num)`, and it repeats the misleading `cvFsIsExistFile`
diagnostic. The slot, three-argument forwarding and duplicated diagnostic
together are stronger evidence than the diagnostic alone.

Suggested comparative alias: **`cvFsLoadDirInfo_candidate`**. This does not prove
the complete directory-information structure or its count/output units.
Outbreak's extra path-rewrite call is a real version difference. The
[second filesystem review](FILESYSTEM_SECOND_PASS.md) adopts this candidate
spelling on the existing annotation while retaining the output-schema gap.

### Main 0x135EF0: candidate `cvFsExecServer`

The [older notebook](../SYMBOLS.md) describes this as
`cri_poll_backend_callbacks`: 32 registry entries at 0x262068, stride 0x10,
each nonnull interface optionally dispatching its first function pointer.

CVX's [cvFsExecServer][cvfs] has exactly this registry-service shape. Its header
places `ExecServer` at interface +0. Suggested comparative alias:
**`cvFsExecServer_candidate`**. This identifies the service layer more precisely;
it does not establish callback duration, backend implementation or a slowdown
cause. Outbreak's original call at 0x135F24 remains indirect.

## Stream interfaces: strong role evidence, different storage contracts

The [SJUNI comparisons](CROSSWALK.md#sjuni) support the existing four-list,
borrowed-span interpretation. Both versions use 64 objects, 16-byte externally
provided nodes, four queue heads, and mode-1 split/adjacent-span merging.
`GetNumData` sums bytes, `GetNumChunk` counts nodes, and `GetNumChainPool`
counts free nodes. Those quantities must remain separate.

Its `IsGetChunk` returns the **full first-span length**, with mode-dependent
admission. The [ring's corresponding method](CROSSWALK.md#sjrb) instead reports
a bounded contiguous grant. A common vtable shape is not permission to exchange
the two stream implementations.

| Contract | CVX source | Reviewed Outbreak behavior | Consequence |
| --- | --- | --- | --- |
| Ring object pool | 64 objects, 0x30-byte PS2 records | 256 objects, 0x40-byte records | Do not import pool dimensions or struct size. |
| Ring bookkeeping | Positions and readable/free capacity | Also four acquisition/return totals at +0x28..+0x34 | CVX Reset/Get/Put/Unget would omit state used in Outbreak. |
| Ring error callback | Fields +0x28/+0x2C | Fields +0x38/+0x3C | Casting to CVX's struct would read counters as callback/context. |
| SJUNI work-size conversion | Unsigned work size divided by 16 | Signed truncation toward zero | Normal positive sizes can agree while invalid/negative sizes diverge. |
| Default SJUNI/ring error | Permanent loop | Forward to Outbreak diagnostic helper | Returning versus nonreturning error paths must be checked locally. |

Sources: pinned [ring source][ring] and [header][ring-header],
[SJUNI source][uni] and [header][uni-header],
[Outbreak ring notebook](../SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md),
[Outbreak SJUNI notebook](../SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md).
PS2 record sizes assume 32-bit pointers and the source field layout; they are
not native-host `sizeof` values. The initial pass had not established binary
UUID identity; the [second stream review](STREAM_SECOND_PASS.md) now verifies
all sixteen bytes of both interface UUIDs, preserving the layout differences.

## DTX: same transport family, stronger Outbreak lifecycle

The [DTX comparison](CROSSWALK.md#dtx) supports eight context slots, RPC function
2 creation with four input words, function 3 destruction, aligned EE/IOP
buffers, a 64-byte footer and callback/context pairs. Both versions use a
newer footer sequence to trigger receive completion before sending again.

The important difference is destruction: CVX's [DTX_Destroy][dtx] requests
remote destruction and clears the object. Outbreak **disables new submission
and pumps all active contexts until the in-flight flag clears**, then destroys
the remote context. Its service also checks an enabled flag and global gate.
Copying CVX's immediate teardown would remove Outbreak's ownership/progress
contract; copying its unconditional send gate could prevent shutdown progress.

CVX's source default RPC service ID is 0x7D000000; our Outbreak configuration
uses 0x90000200. The shared PS2Recomp DTX compatibility mechanism already
accounts for game-specific layouts; this does not show that Outbreak directly
imports recvx-decomp code. See [Outbreak transport evidence](../SYMBOLS_CRI_DTX_TRANSFER_CONTEXT_AND_ACKNOWLEDGEMENT.md),
[runtime history](../DIVERGENCES.md#d12-cri-dtxsjxps2rna-server-sid-0x90000200--runtime-emulation-enabled)
and [current configuration](../../recomp/overrides/reo_override.cpp).

## Decoder and voice controls: additional version differences

The [ADXB comparisons](CROSSWALK.md#adxb) support borrowed PCM backing,
predictor lifetime, header metadata getters and multi-format header dispatch.
CVX has eight basic decoder objects; Outbreak's inner decoder pool has sixteen
and its notebooks distinguish a separate outer streaming layer. Similar API
names do not collapse those layers or justify sharing object layouts.

A narrow original-instruction check also found a meaningful base-header
difference: CVX's [ADX_DecodeInfo][decoder] computes samples per block by dividing
by the parsed bits-per-sample byte. Outbreak main **0x126798 explicitly outputs
zero when that byte is zero**, and otherwise uses signed byte arithmetic.
The zero branch is visible at 0x12685C..0x12686C in the owned instructions.
It must survive any translation derived from the CVX source.

The [PS2RNA comparisons](CROSSWALK.md#ps2rna) show additional differences:

| Operation | CVX | Outbreak |
| --- | --- | --- |
| `SetSfreq` | Store configured frequency | Enforce 48000 divisibility and an even quotient for non-48000 input; zero traps and rejected values can loop forever. |
| `SetTransSw` | Exact-1 activation can start DTR immediately | Store request; disabling stops channels; activation is deferred to service. |
| `SetPlaySw` | Also reset/return stream spans on switch zero | Store the desired remote-play byte here. |
| `GetNumData` / `GetNumRoom` | Unsigned division by two | Signed truncation toward zero in the reviewed bodies. |
| Several unsupported APIs | Print then spin forever | Selected bodies print and return, sometimes zero. |

Source: [pinned PS2RNA implementation][rna] and
[Outbreak controls notebook](../SYMBOLS_PS2RNA_AUDIO_CONTROLS_AND_UNSUPPORTED_API.md).
In both versions, the `GetTime`-shaped helper writes **0/48000**; it is not a
hardware playback clock. Volume clamps of [-999,0] and pan clamps of [-15,15]
support their control roles without establishing physical units or host mixing.

## Scheduling and optional-call ABIs need local reconstruction

CVX's [ADXPS2 worker][worker] locks, calls `ADXT_ExecServer`, calls
`ADXT_ExecFsSvr`, unlocks and sleeps. Its filesystem pass invokes three named
services. Outbreak instead has callback groups, four/six-worker configurations,
stop/acknowledgement state and service-border coordination. Our six-phase
0x12A020 pass cannot be renamed or rebuilt from CVX's three-service wrapper.
The two [worker crosswalk rows](CROSSWALK.md#workers) are deliberately
`concept-only`.

Likewise, CVX's `cvFsOptFn1/2` C expressions only explicitly supply the backend
object through old-style function pointers, while Outbreak forwards the extra
register arguments. This is a source/prototype limitation, not proof that
CVX's matched MIPS destroys those registers. It cannot supply a portable ABI
for Outbreak's extended optional operations and volume requests.

## What this enables next

1. Review the two naming leads against their Outbreak callers and destination
   vtables before changing the central annotation source.
2. Use SJUNI and the small header helpers as bounded reconstruction candidates,
   preserving the documented invalid-input, arithmetic and callback behavior.
3. Retain Outbreak-specific ring counters, DTX shutdown gates and PS2RNA control
   flow when reconstructing those larger subsystems.
4. Use actual profiling to choose an optimization target. Shared library names,
   short loops and a completed map do not identify an expensive executed path.

No listed function is approved here as a semantically equivalent replacement.
Equivalence work still needs complete caller/ABI contracts, current override
ownership, comparison against the existing path and targeted runtime validation.

[cvfs]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/cri_cvfs.c
[cvfs-header]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/include/cri/mwlib/ee/lib/libadxe/cri_cvfs.h
[ring]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/sj_rbf.c
[ring-header]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/include/cri/mwlib/ee/lib/libadxe/sj_rbf.h
[uni]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/sj_uni.c
[uni-header]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/include/cri/mwlib/ee/lib/libadxe/sj_uni.h
[dtx]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/dtx.c
[decoder]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/adx_dcd.c
[rna]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/ps2_rna.c
[worker]: https://github.com/AshfordFamily/recvx-decomp/blob/657b0c0c9489943116c71f151804ad7304fca975/src/cri/mwlib/ee/lib/libadxe/adx_mps2.c
