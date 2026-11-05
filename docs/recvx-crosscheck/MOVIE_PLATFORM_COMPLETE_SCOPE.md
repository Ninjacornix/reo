# Complete movie wrapper and platform-buffer reference scope

Static review, 2026-11-05. Reference `recvx-decomp` commit
`657b0c0c9489943116c71f151804ad7304fca975`. Owned Outbreak main ELF SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`;
owned overlay identities are checked against the repository identity catalogue.
No game, target process, build, replay, attachment, emulation, hardware register,
audio, input or DMA operation was executed.

All **85 actual reference definitions** in the transferred scope were read and
given an explicit disposition:41 in `ps2_MovieFunc.c`,24 in `ps2_sfd_mw.c`,20 in
`mwwrap.c`, all under `src/ps2/veronica/prog/`. The
[machine ledger](../../build-function-index/recvx-movie-platform-complete-scope.json)
records every exact file/symbol/start line/end line, raw file SHA, body SHA,
implementation shape, comparison, original Outbreak IDs or searched candidates,
complete original-byte evidence, note references and limitations. It contains
**8 newly compared close contracts,4 version-different comparisons,58 scoped
no-demonstrated-counterpart results and15 genuinely empty reference bodies**.
These are comparison dispositions, not85 new mappings or58 absent game features.

## Shared low-level components previously missed

The negative conclusion that CVX's Sofdec-named game wrapper is not source for
Outbreak's complete CRI/Sofdec implementation remains correct. It is incomplete
without these shared platform subcomponents: its Sony-MPEG-style ViBuf/DMA
family closely corresponds to Outbreak's compressed-ring support.

| Reference function | Outbreak owner(s) | Full-body comparison |
| --- | --- | --- |
| `getFIFOindex` | 1709A0 | Same terminal-tag pointer special case and2048-byte index. CVX uses unsigned subtraction/division; Outbreak uses signed truncation toward zero. Out-of-range addresses are not equivalent. |
| `setD3_CHCR` | 1709F0 | Same DI,global DMA pause bit,from-IPU CHCR write,clear pause,unconditional EI. |
| `setD4_CHCR` | 170A58 | Same bracket for to-IPU CHCR. These are not equivalent to the SDK's conditional interrupt restore. |
| `scTag2` | 170AC0 | Same64-bit address/id/QWC tag composition; only lower8bytes of each16-byte tag are stored. |
| `viBufReset` | 170B60 | Same ring counters/active flag,24-byte timestamp reset,2048-byte REF chain,terminal NEXT link and channel-stop initialization. |
| `viBufBeginPut` | 170CA0 | Same semaphore,write offset,capacity modulo,two writable spans and two-block safety reserve. Free space can remain negative for invalid state. |
| `viBufEndPut` | 170D90 | Same guarded partial-byte and64-bit lifetime-byte accounting, no DMA submission. |
| `copy2area` | 171BE0 | Same signed total-fit rejection and two/three memcpy routing across two source and destination spans; returns whole source byte count, no partial copy. |
| `mpegStopDMA` | 171060,1719A0 | Same DMA/FIFO/IPU snapshot mechanics. CVX uses global `videoDec.vibuf`; Outbreak has an explicit record worker and main-cookie callback adapter. |
| `mpegRestartDMA` | 171160,1719C8 | Same FIFO compensation,ring-crossing/tag fixup,output DMA restore and active publication; important guard/order differences below. |
| `viBufDelete` | 171478 | Same channel stop5,clear QWC/MADR/TADR,delete semaphore,return1; borrowed buffers/tags are not freed. |
| `mpegNodata` | 170E60,171920 | Shared DMA reconciliation core, but callback/sleep/inactive and underflow policies differ substantially; this is a related component comparison. |

The first eleven rows identify close platform roles; the twelfth retains a
materially different callback envelope. Eight are newly compared role matches
and four are explicitly version different, as the ledger records. No additional
catalogue owners were created for source fragments, inlined masks or helper
pieces. The authoritative
[compressed-ring note](../SYMBOLS_SOFDEC_COMPRESSED_RING_AND_IPU_DMA_SUSPEND_RESUME.md)
now links this evidence and records the new comparative vocabulary.

The CVX header `types.h` independently defines `REST=2`,
`FS=(dmaStart+dmaN)*2048`, `FN=(n-REST-dmaN)*2048` and physical mask0FFFFFFF.
Its ViBuf layout matches Outbreak's ring fields0..5C, including a timestamp
array of24-byte entries containing two64-bit values and two32-bit fields.
Thus170B60's existing -1/-1/0/0 reset is supported as comparative
`PTS,DTS,position,length` metadata initialization. This does not prove a matching
Outbreak timestamp-ring producer,consumer or runtime use; no extra credit is
assigned for those fields.

## Differences that must survive translation

Outbreak171160 acquires its semaphore at171188 **before** reading saved FIFO
state at171190. CVX `mpegRestartDMA` computes FIFO/bit-pointer compensation and
the initial prospective DMA state before acquiring the semaphore. CVX further
gates `sceIpuIsBusy`/`sceIpuBCLR` on queued-block count!=0. Outbreak1713A4..1713EC
performs both busy polls and the bit-offset command write unconditionally;
only the final to-IPU DMA restart at171414..171424 depends on queued count.
The existing Outbreak mapping describes the original instructions correctly.
The older callback must not replace its lock or empty-ring behavior.

CVX `mpegNodata` sleeps before taking the semaphore, prints and returns on an
inactive ring without releasing it, then otherwise reconciles whole DMA blocks.
Outbreak170E60's inactive path releases the semaphore;171920's caller additionally
contains original-IPU picture-underflow/endcode injection. The similar middle
chain-update arithmetic is not complete callback equivalence. No reachable hang,
measurement or fix is claimed for either program.

CVX/Sofdec's CHCR writers always EI after the protected register write. Outbreak
SDK113BA8/113C20 saves the result of interrupt-disable and only enables when it
was previously enabled. A generic replacement that makes all four functions
share unconditional or conditional behavior would change an original contract.
Both families also clear the global DMA pause bit rather than restoring its
prior value verbatim.

## Why the remaining functions are not promoted

The58 negative records each retain specific inspected Outbreak candidate bodies
and the reason their complete ownership/algorithm does not correspond. These
are scoped results from the full reference bodies and existing complete owned
movie/audio notes, not searches for identical symbol spelling. Representative
boundaries include:

- CVX's `initAll/readMpeg/decBs0/videoDecMain/termAll` own singleton Sony MPEG,
  CD-stream/read rings,a decoded-output thread and fixed global arenas.
  Outbreak has a caller-workspace MPEG owner,optional original-IPU callbacks,
  CRI/SJ program-stream service and separate public/private picture lifetimes.
- CVX's `pcmCallback/audioDecBeginPut/audioDecSendToIOP/audioDecResume` implement
  SSHD-header accumulation and a direct SPU PCM ring. Outbreak's ADXT/RNA copy,
  timing,queued PCM and desired remote commands are different full contracts.
- `sendToIOP2area` truncates source to destination capacity and performs DMA;
  the close two-span Outbreak171BE0 rejects insufficient capacity and memcpy
  copies. A packing-shape match cannot erase these differences.
- CVX's `setImageTag/vbrank_draw` build and submit fixed GS texture/sprite tags.
  Outbreak's overlay379420/379660/379AF0 has related packet/render roles with
  different tiling,resource and submission ownership. The existing original
  [movie GS flow](../SYMBOLS_MOVIE_FLOW.md) remains authoritative; there is no
  complete same function proved from GIF register names alone.
- CVX's timestamp24-byte modify/put/query functions have no demonstrated full
  Outbreak counterpart. Outbreak170B60 initializes a matching metadata layout;
  its general174218/174448 metadata ring uses a different record and predicate.
  That supports a search lead, not naming those operations `viBufPutTs` or
  importing standard PTS units into all Sofdec records.
- CVX's `ps2_sfd_mw.c` singleton “Sofdec” facade creates a CD/PSS path and often
  has empty API bodies. Its GetTime is frame delta/29, its volume formula is
  `32.8*(vol+999)`, and Pause toggles one global bit. Outbreak's real CRI player
  APIs and sample-ratio clocks cannot be substituted based on these names.
- `mwwrap.c` adds game-mode globals,allocator ownership,320x240 creation defaults,
  completion callback and virtual player calls. Outbreak's engine/player wrappers
  serve related product jobs but have different fields and lifecycle. No generic
  callback or constant-return leaf is credited merely to complete a crosswalk.

Fifteen actual empty reference bodies are classified separately. They comprise
the three `mwwrap.c` hooks `SetMwSoundMode/CreateWaveHandle/CreateTmHandle` and
twelve `ps2_sfd_mw.c` APIs:work-size,finish,brightness,init,preinit,display-mode,
fast-halfpel,start-frame,Vsync-handle,server-handle,destroy and output-volume
getter. Their absence does not prove that Outbreak's same-named full APIs are
empty or that an adjacent return-only entry has that original identity.

## Reproduction and validation

Run `python tools/function_index/review_recvx_movie_platform_complete_scope.py`.
The [helper](../../tools/function_index/review_recvx_movie_platform_complete_scope.py)
uses the parent's exact source inventory, asserts all85 path/symbol/start/body
identities and checks all three raw file hashes. It also hashes the two supporting
headers, owned main ELF and overlay0. The resulting ledger contains **75 complete
owned intervals /4,584 verified instruction-comment words**, with no conflicts
or omitted nonzero original words. This includes the contrasted SDK guards and
five full overlay creation/GS pipeline bodies. Top-level `groups` supplies12
curated reference comparisons for optional parent integration into the shared
crosswalk; the old crosswalk itself is untouched here.

The changed authoritative compressed-ring notebook passes its13-row/676-word
audit. A private full notebook import passes without duplicate IDs. No runtime,
native,generated guest code,shared annotations,index or renderer setting changed;
this establishes source relationships and their limits,not a tested optimization
or cause of the player's slowdown.
