# Audio mappings: pinned Code Veronica second pass

Static review, 2026-11-05. Reference checkout: `recvx-decomp` commit
`657b0c0c9489943116c71f151804ad7304fca975`. Outbreak File #1 US original
`game_data/SLUS_207.65`, SHA-256
`06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46`.
No game, build, decoding/encoding vector, target execution, emulation, process
attachment, live memory, input, audio device or RPC activity occurred.

This pass supports the broad existing audio ownership and processing roles. It
refines one previously opaque control and corrects a history-field description
and a wrong loop-field source offset. It also records concrete library
differences that make direct source substitution unsafe without separate parity
work. **No new catalogue entry receives mapping credit.** Comparative names below
are source-supported aliases, not recovered original Outbreak symbols.

## Corrections and refinements

**13EC58 is a remote queue-draining mode request.** The earlier authoritative
description called byte53/type8 an unknown auxiliary state. CVX
`include/cri/mwlib/ee/lib/libadxe/ps2_rna.h` names command8
`IOPRNA_CMD_SETTHRU`, the IOP byte `thru_flag`, and EE fields
`iop_thru`/`ee_thru`. Those names alone would not establish behavior. The owned
Outbreak driver supplies the actual connected implementation:

1. Complete resident13EC58 stores low bytea1 at group53. Complete13E000 compares
   desired53 with last-sent52, emits command8, and immediately updates52.
2. Owned `ioprna_rcvcbf` D40 uses the actual94C0 command table: slot8 selectsDC4,
   reads command byte8 and writes IOP objectbyte1 atDCC.
3. Complete owned `IOPRNA_ExecHndl` F80 reads signed objectbyte1 and acts only for
   exact1. Under its RNA critical section it visits each signed current channel
   count at object8, obtains an available pool1 SJ span and returns a positive
   span to pool0. After each sweep it repeats unless every visited queue was
   empty. It does not copy the audio to a hardware output in this path.

The supported term is **thru queue drain/discard**, not audible passthrough. The
EE setter does not synchronously drain, normalize values, stop producers or
acknowledge IOP completion. Concurrent production can prolong the remote loop;
this is a static control-flow observation, not a measured stall. The resident
[control row](../SYMBOLS_PS2RNA_AUDIO_CONTROLS_AND_UNSUPPORTED_API.md) and
[command table](../SYMBOLS_PS2RNA_COMMAND_DELTA_TRANSPORT.md) now state this.
The latter also replaces its stale typeA unknown with the already established
[owned mixer operation](../SYMBOLS_PS2RNA_OWNED_IOP_DOLBY_AND_MIX_ROUTES.md).

The driver is member9 of owned `/IOP/MODULES/DRIVE.DAT`, container offset2F040,
size125201, SHA-256
`456f07cb55a5bed66643fd95ca6ef64874265b578630b905a9328346e01aefb7`.
The container has ISO LBA1212,356544 bytes, SHA-256
`6ac9f10940514fe0d54139498de87d432a4e84db499aa5f07e53ad5889d92c79`.
Complete callback D40/504 bytes hash
`dbd669825aab891e63af5d4cdd28bb56d1f1a081e4e57cb035f4d953b188229e`;
complete F80/244 bytes hash
`6faa55753b3db59699865af4bc01774bf552d199ab52454f9e3534340fa0a696`.
The receipt retains both identities; the [existing owned module inspector](../../build-function-index/owned-iop/inspect_iop.py)
can print either original body without executing it.

**125248 resets predictor histories, not pending-work words.** CVX
`ADXB_Stop` calls `ADXPD_Stop`, whose history-array clear matches Outbreak's
125258 ->135020. Original135030 clears phaseC, then135034..135040 clears eight
bytes at28..2F: two signed16 history samples per channel. The earlier
`workwords28/2C` wording in the
[authoritative decoder row](../SYMBOLS_ADXB_DECODER_LIFETIME_HEADER_AND_PHASE.md)
is corrected. Request pointers, coefficient/key fields and outer SJ reservations
are separate. Neither version joins a worker here.

**The leading-padding purpose is corroborated.** CVX `adx_bsc.c`
`ADXB_GetLpInsNsmpl` returns `lp_ins_nsmpl`; `adx_sjd.c`
`ADXSJD_GetLpInsNsmpl` forwards it. Its `ADX_DecodeInfoExLoop` sign-extends the
first loop BE16 into this field. These match124F08/12D850 and independently
support the existing Outbreak encoder68 -> wire -> parser126AC8 -> inner20
chain. The [purpose note](../SYMBOLS_ADXB_AINF_TEXT_AND_LEADING_PADDING_PURPOSES.md)
now records these qualified aliases. They do not turn the getter into a measured
silence counter or remove the partial-header caveat.

## Material differences retained

| Outbreak owners | Reference source/API | Verified distinction |
| --- | --- | --- |
| 125370,125518 | `adx_bsc.c` / `ADXB_EvokeDecode`, `ADXB_EndDecode` | The four admission bounds match. For result accounting Outbreak12559C multiplies the ceiling budget-block bound by channel count before1255B8 compares completed blocks. CVX compares against the unmultiplied bound. Outbreak's existing formula is correct for its instructions; copying CVX would alter the stereo edge case. |
| 126AC8 | `adx_dcd.c` / `ADX_DecodeInfoExLoop` | Both read the final loop byte offset at base14 hex. The previous Outbreak note's base18/skip assertion was wrong. CVX fixes loop base14 hex; Outbreak selects base20 hex for version4,14 hex otherwise, with corresponding minimum lengths3C/30 hex. |
| 134D90..135170 | `adx_xpnd.c` / `ADXPD_*` | Pool16 versus CVX8. Shared phase/context semantics hold; Outbreak's active135078 dispatcher passes a mutable key triple into integer keyed kernels, while CVX calls unkeyed float decoders. |
| 126FE8,127158,1273F0,127690,126FD8 | `adx_dcd3.c` | The unkeyed float block, early-marker/history, odd stereo count and duplicated float downmix contracts correspond. This does not establish keyed integer-downmix equivalence, PS2 float conversion parity, native output parity or active call frequency. |
| 126510 | `adx_dcd.c` / `ADX_GetCoefficient` | The cosine/sqrt quadratic and scale4096 match. Outbreak has explicit EE float/conversion/fallback operations; C double temporaries and casts are not an exact rounding/exception specification. |
| 13EBD8,13EC50 | `ps2_rna.c` / `PS2RNA_SetTransSw`, `PS2RNA_SetPlaySw` | CVX activates DTR in SetTransSw and resets local/remote SJ in SetPlaySw(0). Outbreak's first routine stops DTR for a non1 request; the second only stores desired playbyte. Its restart/service path must remain separate. |
| 13EF80 | `PS2RNA_SetSfreq` | CVX simply stores. Outbreak enforces48000 divisibility and an even quotient unless rate48000, including explicit divide-zero BREAK and invalid-value report/permanent-loop paths. |
| 13ECB0,13ECF0 | `PS2RNA_GetNumData`, `PS2RNA_GetNumRoom` | Same first-channel16384-byte geometry, but CVX casts to unsigned before /2; Outbreak truncates signed division toward zero. Malformed/negative values differ. |
| 13EB88,13EC60/80,13EF58,13F080/B8/108/130/158/180/1A0 | Unsupported `PS2RNA_*` APIs | CVX reports then permanently loops; Outbreak reports and returns, with explicit0 for relevant queries. An API-name match cannot justify importing noreturn behavior. |
| 13E000,13DFA0 | `ps2rna_sndcbf`, `ps2rna_rcvcbf` | Common16-byte command format and last-sent publication. CVX scans8 groups and serializes types2/3/4/5; Outbreak scans16 and also8/A/9, with stop before parameter changes and play after. Both receive callbacks read count once; they do not parse acknowledgements. |

**126AC8's final loop byte-offset source was mapped incorrectly.** The old
[authoritative row](../SYMBOLS_ADX_HEADER_HISTORY_LOOP_AND_AINF.md) claimed
base18 hex and an intentional skip over base14. The actual address trace is:

```text
t5 after the padding/count setup = loop_base + 4
126C08: t5 += 2                    # base+6, type pointer at126C10
126C14: t5 += 2                    # base+8, start-sample pointer at126C18
126C1C: t5 += 4                    # base+C, start-byte pointer at126C24
126C28: t5 += 4                    # base+10, end-sample pointer at126C54
126C5C: t5 += input_pointer        # input+base+10, no field increment here
126CCC: load word [t5+4]           # input+base+14, final end-byte offset
```

It therefore agrees with CVX's contiguous loop fields and Outbreak12F090's
fourth loop-word writer. The authoritative row is corrected tobase14, and both
the skip and intent claims are removed. No runtime bug or parser/writer
mismatch follows from the earlier documentation error. Existing sample/byte
query units remain grounded in Outbreak's downstream consumers. The receipt
helper independently checks this pointer progression from the owned instruction
encodings, without executing guest code.

PS2RNA record layouts differ too. In CVX's32-bit header, pan arrays end at48 hex,
followed by flags48..4B, flush4C and buffer size50, total54 hex. Outbreak adds
desired/last mixer words48/4C, moving flags to50..53 and sizes54/58, stride60.
Its IOP record likewise adds fields absent from the older CVX declaration. Do
not transplant struct offsets based on the shared type names.

## Optional codecs, AINF and Sofdec boundaries

The pinned CRI implementation/header corpus contains no `AINF` or `AHX`
identifier. CVX's `ADX_BASIC` lacks Outbreak's pluginB0/BC and AINF C8..E0
extension. It therefore supplies no concrete callback implementation to refine
122E40/122E90/122FF0/1230B0/12CC50/132FF8 into reset/start/flush internals.
The six existing lifecycle roles remain supported by Outbreak's full12CBC0 and
134BC0 callers. Initial callback slots remain zero; handle guards are not
callback-registration checks. No AC3/API identity is inferred for formatF merely
from0B77 or1536-sample metadata.

Similarly,124F68/12D9B8/132890 remain fixed-sixteen-byte borrowed text views,
with application-specific text meaning unknown. The Outbreak bounded-string
producer and parser support that description. CVX provides no basis to rename
the field title, author, language, codec name or a guaranteed terminated string.

All23 complete audio-service/metadata owners in
[the Sofdec note](../SYMBOLS_SOFDEC_AUDIO_SERVICE_AND_METADATA.md) were included
in the owned-word verification. Their internal flag1148/114C roles, metadata
word4 units and unsigned1656E8 readiness test cannot be resolved by CVX's
`ps2_sfd_mw.c`. That file is a game-side MPEG wrapper: several Sofdec-named
entries are empty, its server calls `readMpeg`, time is a frame delta/29, and
volume calls `changeInputVolume`. It is not source for Outbreak's resident
Sofdec internal audio module. No internal Sofdec mapping is promoted from those
similar public names.

CVX `adx_tlk.c` independently supports the six actual ADXT child contracts used
here:131EF8 status,1324A8 declared sample total,1324F8 frequency,132548 channels,
1328B8 configured service frequency,132CF0 error. Outbreak adds explicit NULL
diagnostics/returns. Its signed-byte readiness checks in the three metadata
getters remain distinct from Sofdec1656E8's unsigned comparison, which admits a
negative error code. Numeric playback-state names are not imported from an enum
definition absent from the inspected implementation/header corpus.

## Reproduction and integration

Run `python tools/function_index/review_recvx_audio_second_pass.py`, optionally
with `--reference PATH` and `--output PATH`. The
[portable helper](../../tools/function_index/review_recvx_audio_second_pass.py)
pins the reference HEAD and ten file hashes, verifies127 complete owned
catalogue intervals /3,507 source-comment words with only zero padding omitted,
and checks both complete owned IOP bodies. It writes
[`build-function-index/recvx-audio-second-pass.json`](../../build-function-index/recvx-audio-second-pass.json).
The receipt has **84 address comparisons:50 supported-role and34
related-different**, in the requested `notebook`, `cvx_file`,
`rows[address,symbol,status,comparison]` group format. These are crosswalk
comparisons, not84 newly mapped functions. Six optional-codec, three AINF text,
the drain-mode setter and23 Sofdec internals receive additional Outbreak-only
support coverage without invented CVX counterparts.

Source-word audits and a private notebook import check validate documentation
identity/uniqueness only. No old `review.json`, shared index, annotations,
generated guest code or runtime implementation was modified by this pass.
