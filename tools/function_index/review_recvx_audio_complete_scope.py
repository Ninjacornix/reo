#!/usr/bin/env python3
"""Exhaustive pinned CRI audio/core reference-function disposition ledger.

Only source parsing, original byte reads and documentation checks; no guest
execution, codec vectors, builds, process access or shared-index writes.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from index import Elf
from recvx_scope_inventory import function_records, PIN
from review_recvx_audio_second_pass import groups, SHA

ROOT=Path(__file__).resolve().parents[2]
LIB='src/cri/mwlib/ee/lib/libadxe/'
STEMS='adx_amp adx_baif adx_bau adx_bsc adx_bsps adx_bwav adx_crs adx_dcd adx_dcd3 adx_errs adx_fini adx_inis adx_mps2 adx_rnap adx_sjd adx_stmc adx_tlk adx_tlk2 adx_tsvr adx_xpnd ps2_rna rna_crs'.split()


def dispositions():
    records={}
    # Prior manually compared contracts retain their exact source-file identity.
    for group in groups():
        stem=Path(group['cvx_file']).stem
        for address,symbol,status,comparison in group['rows']:
            records[stem,symbol]=dict(outbreak_ids=[address],status='already-compared' if status=='supported-role' else 'version-different',comparison=comparison,prior='AUDIO_SECOND_PASS.md')

    def add(stem, text, common='', different=False):
        for line in text.strip().splitlines():
            line=line.strip()
            if not line:continue
            pair,_,detail=line.partition('|')
            symbol,ids=pair.split('=',1)
            key=(stem,symbol.strip())
            assert key not in records,key
            records[key]=dict(outbreak_ids=ids.strip().split(),status='version-different' if different else 'newly-compared',comparison=detail.strip() or common)

    add('adx_amp','''
ADXAMP_Init=122720 | Reference8 slots vs Outbreak16; first-reference clear and unconditional increment agree.
ADXAMP_Finish=122770 | Exact-zero decrement/clear agrees; neither clamps underflow, pool capacity differs.
ADXAMP_Create=1227C0 | Borrowed SJ pairs,44100Hz,0.1 durations and peak counters agree; pool16 vs8, Outbreak stores signed byte/fullword channel counts separately.
ADXAMP_Destroy=1228F0 | Optional critical section and fixed-record clear retain borrowed stream ownership.
ADXAMP_GetStat=122940 | Signed state accessor0/2 with no worker invocation.
ADXAMP_Start=122948 | Both clear positions/emission counter and set state2; Outbreak additionally resets/zeroes borrowed input/output streams. CVX does not.
ADXAMP_Stop=122AE8 | State-only stop, no queue clear or acknowledgement.
adxamp_extract=122AF0 | Same absolute signed16 peak,16-byte result,time/rate/window fields, zero-output-span permanent loop. CVX availability/chunk division casts unsigned; Outbreak signed division and explicit zero-window BREAK differ.
ADXAMP_ExecHndl=122D80 | Only state2 invokes peak extraction.
ADXAMP_ExecServer=122DA8 | Active scan16 vs reference8; per-object worker is not bounded by scan count.
ADXAMP_GetExtractNumSmpl=122E08 | First-channel cumulative extraction sample count.
ADXAMP_SetSfreq=122E10 | Configured rate word, no admission or device query.
ADXAMP_GetSfreq=122E18 | Configured rate word, no admission or device query.
ADXAMP_SetFrmLen=122E20 | Writes window duration; extraction multiplies this field by rate.
ADXAMP_GetFrmLen=122E28 | Returns window duration used by extraction.
ADXAMP_SetFrmPrd=122E30 | Comparative frame-period configuration field matches offset/constructor/setter; neither inspected worker consumes it. No scheduling effect asserted.
ADXAMP_GetFrmPrd=122E38 | Comparative frame-period configuration getter; consumer/effect absent in both extraction bodies.
''',different=True)
    add('adx_baif','''
AIFF_GetInfo=1230E0 | FORM/AIFF/COMM/SSND scan, first-recognized handling and unusual SSND pointer agree. CVX reads full16 exponent; Outbreak low exponent byte/guest variable shift; no actual-buffer length parameter.
ADXB_CheckAiff=123470 | Exact FORM0/AIFF8 signature comparisons, no length admission.
ADX_DecodeInfoAiff=1234D8 | Both require4096 input, return narrowed data offset/geometry. CVX tests narrowed dlen*1024; Outbreak tests offset<<16; invalid/truncated offsets differ.
ADXB_DecodeHeaderAiff=1235E8 | Format3, subtype1 for8-bit, clear loop state/copy working geometry; no conversion yet.
ADXB_ExecOneAiff16=123700 | Same big-endian16 swap, mono/stereo planar output and callback phase1/2/3 flow.
ADXB_ExecOneAiff8=123898 | Same byte<<8 expansion, no midpoint subtraction, stereo deinterleave and consumed-byte/sample accounting.
ADXB_ExecOneAiff=123A18 | Subtype1->8-bit, every other subtype->16-bit conversion.
''',different=True)
    add('adx_bau','''
AU_GetInfo=123A40 | Both accept .snd/.sd, encodings1/2/3->mulaw/8/16, declared-offset bound and channel division; preserve signed/unsigned field arithmetic and divide traps.
ADXB_CheckAu=123D58 | Two four-byte magic alternatives; .sd includes terminating NUL.
ADX_DecodeInfoAu=123DB0 | Both admit length8 and narrow data offset, despite parser reading24 fixed bytes. CVX dlen*1024 vs Outbreak offset<<16 gate differs.
ADXB_DecodeHeaderAu=123EC0 | Same format4/subtype installation, cleared loop metadata and copied working PCM geometry.
ADXB_ExecOneAu16=123FC0 | Same big-endian16 mono/stereo planar conversion and phase callbacks.
ADXB_ExecOneAu8=124158 | Same byte<<8 expansion without midpoint subtraction.
ADXB_ExecOneAuUlaw=1242D8 | Same256-entry signed16 lookup/deinterleave. Complete table bytes separately compared; no predictive history.
ADXB_ExecOneAu=124480 | Exact subtype2/1/default routing to mulaw/8/16-bit.
''',different=True)
    add('adx_bsps','''
ADX_DecodeInfoSpsd=125878 | Both preserve subtype from header8 then unconditionally override geometry to16-bit,block2,samples1,total=wordC/2. Unsupported subtype leaves prior subtype; no validation.
ADXB_DecodeHeaderSpsd=125998 | Format2 plus cleared loop fields and working-buffer geometry.
ADXB_ExecOneSpsd=125A90 | Direct16-bit planar copy regardless reported subtype, not inferred4-bit decoding.
ADXB_CheckSpsd=125C08 | Exact four-byte SPSD comparison only.
''')
    add('adx_bwav','''
ADX_DecodeInfoWav=125C30 | Both raw-scan fmt/data and derive PCM geometry before final admission; scans read4 bytes at each offset. Preserve Outbreak signed-byte geometry, BREAKs and unsigned/signed wavsize half-divide difference.
ADXB_DecodeHeaderWav=125E60 | Format1, parsed subtype, cleared loop metadata/working geometry.
ADXB_ExecOneWav16=125F60 | Same direct16-bit planar deinterleave and callbacks.
ADXB_ExecOneWav8=1260D8 | Same unsigned byte midpoint128 removal then<<8.
ADXB_ExecOneWav4=126270 | Same actual byte-pair16 assembly (stereo byte0/2 and1/3), not nibble ADPCM despite API name4.
ADXB_CheckWav=126410 | RIFF0/WAVE8 comparisons, no length/RIFF chunk validation.
ADXB_ExecOneWav=126478 | Subtypes2/1/0 route4/8/16 named workers, other subtypes return without work.
''',different=True)
    add('adx_bsc','''
adxb_DefGetWr=124810 | PCM base with position/remaining-capacity/remaining-samples tuple; no clamp or wrap.
adxb_DefAddWr=124840 | Adds callback sample argument to current and cumulative positions, ignores encoded-byte argument.
ADXB_EntryAddWrFunc=124E50 | Stores completion callback/context consumed by phase2 publisher.
ADXB_GetAdxpd=1252C8 | Returns constructor-owned predictor pointer8; borrowed pointer view, no ref acquisition.
ADXB_ExecServer=125818 | Fixed active-decoder scan16 vs reference8; dispatcher includes Outbreak additional formats.
''',different=True)
    add('adx_crs','''
ADXCRS_Init=1264D0 | Both initialization paths clear a CRI bookkeeping word, but Outbreak word20C7A0 has no admitted lock/unlock reader; historical name is qualified.
ADXCRS_Lock=1264E0 | CVX nests a local counter and calls ADXPS2_Lock on first entry; Outbreak tails generic tag1 optional-hook machinery. Do not import priority/mutex implementation.
ADXCRS_Unlock=1264F8 | CVX decrements its local level then scheduler unlock at0; Outbreak tails generic tag1 leave machinery.
''',different=True)
    add('adx_dcd','''
ADX_ScanInfoCode=126670 | Halfword-step8000 marker scan and -1/zero offset on absence; original Outbreak range/sign behavior authoritative.
ADX_DecodeInfoExADPCM2=126898 | Minimum18 bytes,8000 magic,signed declared offset>=14,BE16 filter output; not coefficient pair.
''')
    add('adx_errs','''
ADXERR_Init=128038 | Same256-byte text clear plus NULL callback/context.
ADXERR_Finish=128070 | Same clear shape; source gives distinct teardown name without extra destruction.
ADXERR_EntryErrFunc=1280A8 | CVX only stores local callback/context; Outbreak additionally registers lower-layer pair141DB0.
ADXERR_CallErrFunc1=1280D0 | Both bounded255 copy/local callback; Outbreak additionally formats/publishes through lower141800.
ADXERR_CallErrFunc2=128128 | Both copy255 then append255 (not remaining capacity); Outbreak adds lower publication.
ADXERR_ItoA=128198 | Both peculiar raw remainder writes to destination, NUL overwriting final remainder, then strlen/reversal from a different static scratch; not ordinary itoa/ASCII conversion.
ADXERR_ItoA2=1282A0 | Two formatter calls and space append; second capacity is literal4-currentfullstrlen. Outbreak note correctly distinguishes full-string pointer from advanced saved destination.
''',different=True)
    add('adx_fini','''
ADXF_Init=128348 | First-reference clear of handles/partition/history/counters then increment; Outbreak sizes/defaults/cache behavior retained.
ADXF_Finish=128410 | Predecrement exact0 closes all handles and clears shared bookkeeping, no negative clamp.
''',different=True)
    add('adx_inis','''
ADXT_ConfigVsyncSvr=12A0F0 | CVX configures Vsync flag; Outbreak same first-reference callback-registration selector has group2/group4 associations, not automatic display tick1:1.
adxini_rnaerr_cbfn=12A100 12A118 | Both forward second callback argument as error text; Outbreak has two distinct complete adapter entries, no source-order identity choice.
ADXT_VsyncProc=12A130 | Increment service tick then audio server; Outbreak tick has additional interrupt/service producer, not solely Vblank.
ADXT_Init=12A1E8 | Both first-reference initialize dependency pools/audio/file/LSC and clear ADXT pool; Outbreak16 objects, group registrations and hook-based guard machinery differ.
ADXT_ResetLibrary=12A368 | Both force init reference0 then invoke Init; not safe destruction/worker join.
ADXT_Finish=12A388 | Exact-zero ref release, service unregistration and dependency teardown differ from older direct chain; preserve Outbreak order/waits.
''',different=True)
    add('adx_mps2','''
adxps2_adx_thrd_func=12ABF8 | CVX one worker directly services audio+FS then sleeps; Outbreak group1 worker only dispatches registered group1, independent stop/ack. Related, not identical service set.
adxps2_safe_thrd_func=12ABA0 12AB88 | Spin-counter guard-worker counterpart; Outbreak has stop/ack/ExitDeleteThread instead of unconditional forever loop.
ADXPS2_VsyncCallback=12BDB8 | Both callback-chaining and wakeups, but Outbreak multiworker/status-gated wakeups, reentry gate and service counter differ.
ADXPS2_SetupThrd=12B638 12C1D0 | CVX creates2 threads; Outbreak ordinary4/extended6 worker initializers with different config layout/refcount/registered service callbacks.
ADXPS2_ShutdownThrd=12B800 12C388 | Outbreak reference-final stop flags and cooperative stop acknowledgements differ from CVX immediate suspend/delete pair.
ADXPS2_Lock=12A968 | Related scheduler priority handoff implemented through newer CRI guards; preserve owned complete priority/status sequence rather than transplant CVX two-thread layout.
ADXPS2_Unlock=12A9F0 | Paired priority/handoff leave in newer multiworker setup; no host mutex equivalence.
ADXPS2_ExecServer=12C078 12C138 | CVX direct audio+FS calls; Outbreak has plain reentry guard or optional-hook admission variant. Both distinct entries retained; no preferred identical API identity.
''',different=True)
    add('adx_rnap','''
ADXRNA_Init=12C630
ADXRNA_Finish=12C648
ADXRNA_Create=12C668
ADXRNA_Destroy=12C680
ADXRNA_Start=12C6B8
ADXRNA_Stop=12C6D0
ADXRNA_SetTransSw=12C6E8
ADXRNA_SetPlaySw=12C700
ADXRNA_GetTime=12C718
ADXRNA_GetNumData=12C730
ADXRNA_GetNumRoom=12C748
ADXRNA_GetStat=12C760 | Both diagnostic then permanent NOP loop; preserve distinction from returning PS2RNA stubs.
ADXRNA_ExecServer=12C798
ADXRNA_SetStartSmpl=12C7B0
ADXRNA_SetNumChan=12C7C8
ADXRNA_SetSfreq=12C7E0
ADXRNA_SetOutVol=12C7F8
ADXRNA_SetOutPan=12C810
ADXRNA_SetBitPerSmpl=12C830
ADXRNA_GetSfreq=12C848
ADXRNA_GetOutVol=12C860
ADXRNA_GetOutPan=12C878
ADXRNA_GetBitPerSmpl=12C898
ADXRNA_DiscardData=12C8B0
ADXRNA_SetStmHdInfo=12C8F8
''','Same complete typed adapter to corresponding PS2RNA operation. Actual child/version differences, diagnostics, signed arithmetic and borrowed ownership remain Outbreak-specific.',different=True)
    add('adx_sjd','''
ADXSJD_Init=12C948
ADXSJD_Finish=12C978
adxsjd_clear=12C9A0
ADXSJD_Create=12C9D8 | Same outer decoder with borrowed SJ/PCM storage; pool16 vs8, signed capacity halves vs CVX unsigned. Outbreak checks inner allocation before registering callback, CVX registration occurs before NULL check.
ADXSJD_Destroy=12CB58
ADXSJD_GetStat=12CBB8
ADXSJD_SetInSj=12CBC0 | Same borrowed SJ assignment; Outbreak additionally invokes two optional-plugin lifecycle hooks.
ADXSJD_SetOutSj=12CC00
ADXSJD_SetMaxDecSmpl=12CC10 | Same request cap; Outbreak also forwards optional-format controls.
ADXSJD_Start=12CC80
ADXSJD_Stop=12CCB0
adxsjd_decode_prep=12CCE0 | Same header reservation/consume path; Outbreak handles negative unsupported-format result and codec-specific ownership/defer tags absent in CVX.
adxsjd_get_wr=12CEB8 | Same per-channel free spans/output geometry/budget; CVX unsigned half division vs Outbreak signed truncation and no shortest-channel guarantee.
adxsjd_decexec_start=12CFD8 | Similar end/total/output admission; Outbreak additionally consumes end marker, skips zero padding, calls trap before admission and returns plugin spans before dispatch.
adxsjd_decexec_end=12D338 | Same encoded-prefix and sample-clamped per-channel publication/filter callback/counters; Outbreak typed complete ownership remains authoritative.
adxsjd_decode_exec=12D590 | Same input-if-idle/worker/ready-publication progression; Outbreak adds format-owned accounting12D500.
ADXSJD_ExecHndl=12D638
ADXSJD_ExecServer=12D678
ADXSJD_GetDecDtLen=12D6D8
ADXSJD_GetDecNumSmpl=12D6E0
ADXSJD_SetDecPos=12D6E8
ADXSJD_GetDecPos=12D6F0
ADXSJD_EntryFltFunc=12D728
ADXSJD_EntryTrapFunc=12D738
ADXSJD_SetTrapNumSmpl=12D748
ADXSJD_GetTrapNumSmpl=12D750
ADXSJD_SetTrapCnt=12D758
ADXSJD_GetTrapCnt=12D760
ADXSJD_SetTrapDtLen=12D768
ADXSJD_GetTrapDtLen=12D770
ADXSJD_GetFormat=12D778
ADXSJD_GetSfreq=12D790
ADXSJD_GetNumChan=12D7A8
ADXSJD_GetOutBps=12D7C0
ADXSJD_GetBlkSmpl=12D7D8
ADXSJD_GetBlkLen=12D7F0
ADXSJD_GetTotalNumSmpl=12D808
ADXSJD_GetCof=12D820
ADXSJD_GetNumLoop=12D838
ADXSJD_GetLpStartPos=12D868
ADXSJD_GetLpStartOfst=12D880 | Same typed inner offset getter; Outbreak adds NULL outer and inner zero defaults.
ADXSJD_GetLpEndPos=12D8B0
ADXSJD_GetLpEndOfst=12D8C8
ADXSJD_GetHdrLen=12DA10
ADXSJD_GetFmtBps=12DA18
ADXSJD_GetSpsdInfo=12DA30
''','Complete field/callback/inner-query contract agrees with the named CVX method; exact widths, readiness, borrowed pointer lifetime and added Outbreak codec paths retain authoritative note details.',different=True)
    add('adx_stmc','''
ADXT_SetupRtimeNumStm=130098 | Primary pool scan count; no pool-size admission. Caller conventions remain original.
ADXT_SetupNrmlNumStm=1300A8 | Secondary scan count plus40-count tail base; no independent second physical pool.
ADXSTM_Init=1300C8 | Both40-object clear/return1; stride/new lifecycle fields differ.
ADXSTMF_SetupHandleMember=130108 | Same borrowed SJ/file/start/length/callback target/default512 sectors; Outbreak initializes additional pause/open/limit/capacity fields under guard.
ADXSTMF_CreateCvfsRt=130218 | Primary configured-partition scan/descriptor setup, not fixed physical second allocation.
ADXSTMF_CreateCvfs=1302F8 | Secondary/tail partition scan; negative config and bounds remain caller-admitted.
ADXSTMF_Destroy=130420 | CVX simply clears descriptor; Outbreak synchronously stop/pumps and close/pumps before clear, leaving SJ borrowed.
ADXSTM_OpenFileRangeEx=1303D8 130478 1304E8 | No one-to-one body: CVX opens and allocates together; Outbreak split create-empty/request-open/cooperative-pump phases. Range params remain sectors and borrowed filename lifetime matters.
ADXSTM_OpenFileRangeExRt=1303D8 130478 1304E8 | Same structural replacement; primary-vs-secondary pool choice is separate create argument in Outbreak, not this old full API body.
ADXSTM_OpenFnameEx=1303D8 130478 1304E8 | No full equivalent signature/body: Outbreak combines later request with sentinel length and open service; CVX rejects nonNULLdir before direct file-size/open.
ADXSTM_OpenFname=1303D8 130478 1304E8 | Related create/request/open phases only; original synchronous-open wrapper not independently identified.
ADXSTM_OpenFileRange=130478 1304E8 | CVX NULL-dir/rtime convenience wrapper not a distinct demonstrated Outbreak entry; new request and pump interfaces have different object-first ABI.
ADXSTM_Close=130520 130560 | CVX stops/closes/destroys object together. Outbreak request-close and pump-close retain object, with130420 separate destroy.
ADXSTM_GetStat=1305B8 | Same signed request-state byte, not backend cvFs status.
ADXSTM_Seek=1305C0 | CVX performs cvFsSeek/Tell immediately; Outbreak sets/clamps logical sector progress and later read service seeks.
ADXSTM_Tell=130608 | CVX backend Tell minus start; Outbreak cached logical sector progress with file-present gate.
ADXSTM_Start=130620 130658 | Same reset/read-state progression; Outbreak adds service-request flag/finite limit wrapper, no immediate read.
ADXSTM_Stop=1306E0 130748 | CVX immediate stop transfer/state1; Outbreak deferred inflight-stop handshake plus optional pump wait.
ADXSTM_EntryEosFunc=130798 | Callback/context when logical sector progress reaches target, not every sample.
ADXSTM_SetEos=1307A8 | Nonnegative target or derive ceil(byte length/2048); no seek/start.
adxstm_sj_internal_error=1307E8 | Missing SJ/vtable diagnostic counter, no error callback or automatic retry.
adxstmf_stat_exec=130800 130B78 | Read reserve/complete/retry core130800 and added open/close/deferred lifecycle130B78; preserve Outbreak partial-sector admission and inflight protocol.
ADXSTMF_ExecHndl=130B78 | CVX only state2->read core; Outbreak always services lifecycle requests then read only active owned-open. Same family, not same whole-body behavior.
ADXSTM_ExecServer=130D48 | Both40active descriptor scan; Outbreak operation includes deferred lifecycle flags.
ADXSTM_GetCurOfst=130DC8 | CVX Tell-startposition; Outbreak outputs cached progress directly. Same broad progress API, different source/accounting.
ADXSTM_GetBufSize=130DF8 | Outputs refill threshold/min and maximum request bytes; return1.
ADXSTM_GetSj=130E10 | Borrowed SJ pointer; no ownership/refcount transfer.
ADXSTM_SetBufSize=130E18 | Min/refill threshold and max request bytes stores,return1, no ordering admission.
ADXSTM_SetReqRdSize=130E28 | Request cap in2048-byte sectors, not bytes or callbacks.
ADXSTM_GetFileLen=130E40 | Configured byte length, may be clamped after asynchronous open in Outbreak.
ADXSTM_GetCvdfsStat=130E58 | cvFsGetStat through current file handle to output, no result normalization.
ADXSTM_GetFad=130E88 | Both write0 tooutput/return1; static unsupported identity candidate only, not valid file-sector lookup or new mapping credit.
ADXSTM_GetFsizeSct=130E98 | File-size query then ceil positive sector division, output and1. Preserve Outbreak signed division/diagnostic child behavior.
ADXSTM_GetFsizeByte=130EF0 | File-size query to output then1, no file payload read.
ADXSTM_SetSj=130F20 | Rebind borrowed SJ, set both thresholds to capacity from pool0+pool1. CVX only Count0, Outbreak sums both under guard.
ADXSTM_SetRdSct=130FA0 | Sector count*2048 into configured byte length; no extent admission.
ADXSTM_SetOfst=130FB0 | Store start sector and reset logical progress; CVX additionally immediate backend Seek through old implementation.
ADXT_SetNumRetry=130FD0 | Global retry limit, negative disables error promotion; Outbreak retry counter signedbyte versus CVX field width.
''',different=True)
    add('adx_tlk','''
adxt_disp_rna_stat=1314E0 | Same first-channel local/remote pool count diagnostics and totals; remote calls not cheap local measurements.
ADXT_Create=1315E0 | Same borrowed aligned workarea/decoder/RNA/LSC ownership; Outbreak16 slots, larger extension/per-channel reservation, separate file object and explicit input guards differ.
ADXT_Destroy=131918 | Same child destruction/borrowed-workarea retention, but new file ownership and critical-section paths differ.
ADXT_DestroyAll=131AE8 | Active16-object destruction scan, CVX pool macro differs.
ADXT_CloseAllHandles=131B48 | Tail DestroyAll, no additional cleanup.
adxt_start_sj=131B60 | Same output reset/input bind/accounting/state1; Outbreak starts optional peak meter and forwards optional-codec input hooks.
adxt_start_stm=131C50 | CVX configures already-open stream. Outbreak accepts filename/range args, stop/closes then requests deferred open/start before decoder reset; different ABI.
ADXT_StartSj=131D18 | Same stop/guard/reset borrowed SJ/state1 source mode; Outbreak explicit NULL checks and helper delegation differ.
ADXT_StopWithoutLsc=131D98 | Same broad audio/decoder stop but CVX drains DMA/resets transport synchronously/closes file; Outbreak desired play0/drain1 plus owned memory-SJ destruction, no ordinary-file close here.
ADXT_Stop=131E38 | Outbreak all-file/LSC stop choreography differs from CVX SLFILE-only gate, both finish local stop helper.
ADXT_SetTimeMode=131F28 | Mode1->5994,2->5000; other modes retain current scale.
ADXT_GetTimeSfreq=131F60 | RNA or declared-terminal sample ratio plus base offset; RNA original returns0/48000.
ADXT_GetTimeSfreq2=132028 | CVX decoded-RNAoccupied; Outbreak additionally subtracts local output queue and adds correctionA4 before common base.
ADXT_GetTime=132160 | Same tick*100/drift60ms/terminal formula family; Outbreak configurable resync modes/counter and queue-position correction differ.
ADXT_GetTimeReal=132458 | Ratio to centiseconds; CVX doubledivision/cast vs explicit Outbreak float/CVT.W.S, no parity assumption.
ADXT_GetHdrLen=132598
ADXT_GetFmtBps=1325E8
ADXT_SetOutPan=132638 | Both store then validate and forward; Outbreak sentinel/AINF pan composition differs. Preserve invalid-index write-before-error behavior.
ADXT_GetOutPan=1326F0
ADXT_SetOutVol=1327B8 | Both configured volume+RNA update; Outbreak clamps/stores narrow field and applies AINF/balance paths, not raw identical setter.
ADXT_GetOutVol=132820
ADXT_SetReloadTime=1328E8 | Same ADX18-byte/32-sample geometry to input refill sectors, capped by max; Outbreak guest float conversion and signed fields retained.
ADXT_SetReloadSct=132978
ADXT_GetNumSctIbuf=1329A8
ADXT_GetNumSmplObuf=132A08
ADXT_GetIbufRemainTime=132A70 | Same queued ADX bytes to sample-time estimate, integer blocks18*channels and32 samples; no DAC/game-clock measurement.
ADXT_IsIbufSafety=132B58
ADXT_SetAutoRcvr=132BC8
ADXT_IsCompleted=132BD0
ADXT_ExecServer=132C08 | Decoder/RNA/active ADXT service related; Outbreak changed ordering/counters and LSC belongs separate pass. Not one global update or fixed work budget.
ADXT_ClearErrCode=132D20
ADXT_GetLpCnt=132D60
ADXT_SetLpFlg=132D90
ADXT_GetInputSj=132DC0
ADXT_SetWaitPlayStart=132DF0
ADXT_IsReadyPlayStart=132E20
ADXT_EntryErrFunc=133040
ADXT_DiscardSmpl=133058 | Both require paused state then discard/service/time-rebase; Outbreak temporarily zeroes shared clock mode and uses different queue clock/correction.
ADXT_SetTimeOfst=133140
ADXT_SetLnkSw=133148
ADXT_GetLnkSw=133150
ADXT_EntryFltFunc=133158
ADXT_GetDecNumSmpl=133170
ADXT_IsHeader=1331A8
ADXT_IsEndcode=133240
ADXT_InsertSilence=133280
ADXT_SetOutputMono=133428
''','Matched complete typed control/getter role; Outbreak NULL diagnostics, signed/narrow field behavior, underlying child differences and exact invalid-input paths remain authoritative.',different=True)
    add('adx_tlk2','''
ADXT_StartAfs=133490 | Both partition/range resolver then source start; Outbreak persistent file object/deferred-open ABI and error paths differ.
ADXT_StartFname=133580 | Both stop then start named source; Outbreak requests/pumps via separate file object and retains its ownership.
ADXT_StartMem=133618 | Both large-declared-extent facade to StartMem2; borrowed data lifetime unchanged.
ADXT_StartMem2=133630 | Stop/guard/create borrowed SJMEM/reset decoder/mode2; Outbreak NULL/error admission and fixed workarea details authoritative.
ADXT_StartMemIdx=133708 | Same BE archive count/offset indexed borrowed memory; preserve Outbreak index/source extent and no payload bound guarantee.
''',different=True)
    add('adx_tsvr','''
adxt_trap_entry=133928 | Loop repeat reset position/counters and owned memory source skip; Outbreak restores predictor/key snapshot and uses separate first-trap133870, absent CVX.
adxt_eos_entry=133AB8 | Same file-loop target seek/remove trap when disabled; Outbreak updates logical progress/new file object API.
adxt_set_outpan=133B48 | Both auto mono/stereo pan; Outbreak additionally composes AINF offsets and user balance, sentinel handling differs.
adxt_nlp_trap_entry=133D10 | Same footer/header scan across up to2 borrowed spans and decoder restart/trap reset; preserve owned marker lengths/signed narrowing/failure span ownership.
adxt_stat_decinfo=133FE0 | Same ready-header channel admission/budget/loop setup/RNA config; Outbreak AINF,key snapshots and different output/lifecycle controls.
adxt_stat_prep=1343B8 | Same buffered threshold/inhibit/pause/ready logic and silence priming; exact Outbreak request/queue arithmetic authoritative.
adxt_stat_playing=134530 | CVX queue>=64 AND RNAoccupied<=0 guard differs from Outbreak queue-only shortness scan, which setsA8=0/state4. Do not import older predicate.
adxt_stat_decend=1345F0 | CVX waits RNAoccupied<=0 and requests play0; Outbreak actively equalizes zero spans/addsA8 then stops transfer/play and requests remote queue drain. Different algorithm.
adxt_RcvrReplay=134800 | Same stop/reset/restart broad choreography, Outbreak persistent file object's progress/open state semantics differ.
ADXT_ExecErrChk=1348F0 | Same sample stall/starvation5/20 service-frequency thresholds and recovery modes; Outbreak counters signed16 and source/LSC path differs. No wall-clock timing.
ADXT_ExecErrChkPS2=134B40 | CVX sets error only for stream4; Outbreak also LSC state3 and promotes ADXT state6.
ADXT_ExecHndl=134C58 | Both dispatch states1..5 then source/error helpers. Outbreak calls134BC0 optional-format source-end notifications before134B40, which can promote state6; this dispatcher has no state6 branch. Exact child/state admission remains version-specific.
''',different=True)
    add('adx_xpnd','''
ADXPD_SetMode=134F90 | Both store an otherwise unconsumed mode field distinct from channel count and phase; direct constructor/caller identity supports only configuration storage, no decode effect/new credit.
''')
    add('ps2_rna','''
ps2rna_init_psj=13DB48 | Same remote/local SJUNI+SJX/PCM span arena setup; Outbreak configurable up-to32 paired slots, stereo/mono layout and allocation/reset details differ from CVX fixed8.
ps2rna_finish_psj=13DE40 | Same remote/local/SJX teardown/arena ownership, Outbreak configured slot count/layout differs.
ps2rna_get_psj=13DF20 | Both reserve inactive paired slot; CVX additionally resets/refills SJ and remote reset. Outbreak only active-byte reservation, reset occurs elsewhere.
ps2rna_release_psj=13DF98 | Reservation-byte clear only, retains paired stream/arena storage.
PS2RNA_Init=13E2B8 | Shared first-reference transport setup but Outbreak adds remote init RPC/arena and preserves raw/aligned allocation aliases. CVX fixed2256/2176 capacities and pointer treatment are not substitute layout.
PS2RNA_Finish=13E6C0 | Outbreak last-reference explicit DTX destroy/free/paired/remote shutdown; CVX only DTX/SJX/SJRMT module finish. Teardown effects differ.
PS2RNA_Create=13E770 | Same group/reserved PSJ/remote voice/DTR pattern; Outbreak16groups vs8, remote response output, defaults/unwind and mixer fields differ.
PS2RNA_Destroy=13EAC0 | Same DTR/remote voice/reservation release; borrowed stream buffers not freed.
PS2RNA_ExecHndl=13ED28 | CVX worker pads/flushes while stopping. Outbreak worker admits deferred DTR start only after all paired buffers entirely free, consolidates spans and clears thru/drain request. Different complete algorithm.
PS2RNA_ExecServer=13EEE8 | Group service scan16 vs8; Outbreak group scan before DTR/DTX services, including extra DTX pass. CVX SJX/DTR before group scan. RNA counter is not an actual lock.
PS2RNA_GetSjtmp=13F1C8 | Borrowed first/selected paired local stream, unchecked index.
PS2RNA_GetSjiop=13F1E0 | Borrowed selected paired remote stream handle, unchecked index.
''',different=True)
    add('rna_crs','''
RNACRS_Init=13F1F8 13F208 | Both reference Init/Finish clear same scalar; Outbreak has2 byte-identical clear entries for service balance224758 but no admitted callers distinguish phase. Candidate pair only, no per-entry lifecycle identity or new mapping credit.
RNACRS_Finish=13F1F8 13F208 | Same unresolved pairing as Init. Source supplies possible historical names, not proof which original clear entry is shutdown.
RNACRS_Lock=13F218 | Pure scalar increment around RNA group scan, no mutex/syscall/critical hook; matches reference implementation despite Lock spelling.
RNACRS_Unlock=13F230 | Pure decrement after group scan, no underflow clamp or synchronization.
''',different=True)
    # Honest explicit negatives after full nearby-body/caller/typed-table search.
    negatives={
        ('adx_stmc','ADXSTM_Finish'):('130100 12A388','CVX directly invokes cvFsFinish. Nearby Outbreak130100 is return-only; full service shutdown12A388 calls that no-op and manages dependencies separately. No equivalent file-stream-specific cvFsFinish body is demonstrated.'),
        ('adx_mps2','ADXPS2_RestoreVsyncCallback'):('12BDB8 12BEE0 12B638','CVX calls sceGsSyncVCallback and saves previous callback. Outbreak complete interrupt-service/callback adapter and worker initialization bodies have no equivalent callback-installation operation; no separate restore/install entry is demonstrated.'),
        ('adx_tlk','ADXT_SetPauseBuf'):('132FE0 132FE8 133010 133018 133020 133028 133030 133038','CVX returns16384. Examined all remaining adjacent ADXT return-only/zero leaves and constructor pause/work fields; no corresponding16384-return body or connected API registration. Adjacency cannot select an identity.'),
        ('ps2_rna','PS2RNA_Flush'):('13F150','CVX reports PS2RNA_Flush then permanent loop; adjacent Outbreak13F150 is return-only with no diagnostic or caller registration proving API identity. No demonstrated equivalent.'),
        ('ps2_rna','PS2RNA_IsPlySwOff'):('13ED28 13ECB0','CVX combines occupied<=0 and dtrstop==1. Reviewed Outbreak service/accessor/lifecycle family; its deferred-start/drain implementation lacks this complete predicate body. Related fields are not an equivalent function.'),
    }
    for key,(ids,why) in negatives.items():
        assert key not in records,key
        records[key]=dict(outbreak_ids=[],searched_candidates=ids.split(),status='no-demonstrated-counterpart',comparison=why)
    # Exact role/body matches inside otherwise version-different files are
    # classified separately; pool capacity differences do not make every getter
    # a different algorithm. This curated list changes no mapping credit.
    same={
        'adx_amp':'ADXAMP_Destroy ADXAMP_GetStat ADXAMP_Stop ADXAMP_ExecHndl ADXAMP_GetExtractNumSmpl ADXAMP_SetSfreq ADXAMP_GetSfreq ADXAMP_SetFrmLen ADXAMP_GetFrmLen ADXAMP_SetFrmPrd ADXAMP_GetFrmPrd',
        'adx_baif':'ADXB_CheckAiff ADXB_DecodeHeaderAiff ADXB_ExecOneAiff16 ADXB_ExecOneAiff8 ADXB_ExecOneAiff',
        'adx_bau':'ADXB_CheckAu ADXB_DecodeHeaderAu ADXB_ExecOneAu16 ADXB_ExecOneAu8 ADXB_ExecOneAuUlaw ADXB_ExecOneAu',
        'adx_bwav':'ADXB_DecodeHeaderWav ADXB_ExecOneWav16 ADXB_ExecOneWav8 ADXB_ExecOneWav4 ADXB_CheckWav ADXB_ExecOneWav',
        'adx_bsc':'adxb_DefGetWr adxb_DefAddWr ADXB_EntryAddWrFunc ADXB_GetAdxpd',
        'adx_errs':'ADXERR_Init ADXERR_Finish ADXERR_ItoA ADXERR_ItoA2',
        'adx_rnap':'ADXRNA_Init ADXRNA_Finish ADXRNA_Create ADXRNA_Destroy ADXRNA_Start ADXRNA_Stop ADXRNA_SetTransSw ADXRNA_SetPlaySw ADXRNA_GetTime ADXRNA_GetNumData ADXRNA_GetNumRoom ADXRNA_GetStat ADXRNA_ExecServer ADXRNA_SetStartSmpl ADXRNA_SetNumChan ADXRNA_SetSfreq ADXRNA_SetOutVol ADXRNA_SetOutPan ADXRNA_SetBitPerSmpl ADXRNA_GetSfreq ADXRNA_GetOutVol ADXRNA_GetOutPan ADXRNA_GetBitPerSmpl ADXRNA_DiscardData ADXRNA_SetStmHdInfo',
        'adx_sjd':'adxsjd_clear ADXSJD_Destroy ADXSJD_GetStat ADXSJD_SetOutSj ADXSJD_Start ADXSJD_Stop ADXSJD_GetDecDtLen ADXSJD_GetDecNumSmpl ADXSJD_SetDecPos ADXSJD_GetDecPos ADXSJD_EntryFltFunc ADXSJD_EntryTrapFunc ADXSJD_SetTrapNumSmpl ADXSJD_GetTrapNumSmpl ADXSJD_SetTrapCnt ADXSJD_GetTrapCnt ADXSJD_SetTrapDtLen ADXSJD_GetTrapDtLen ADXSJD_GetFormat ADXSJD_GetSfreq ADXSJD_GetNumChan ADXSJD_GetOutBps ADXSJD_GetBlkSmpl ADXSJD_GetBlkLen ADXSJD_GetTotalNumSmpl ADXSJD_GetCof ADXSJD_GetNumLoop ADXSJD_GetLpStartPos ADXSJD_GetLpEndPos ADXSJD_GetLpEndOfst ADXSJD_GetHdrLen ADXSJD_GetFmtBps ADXSJD_GetSpsdInfo',
        'adx_stmc':'ADXT_SetupRtimeNumStm ADXT_SetupNrmlNumStm ADXSTM_GetStat ADXSTM_EntryEosFunc ADXSTM_SetEos adxstm_sj_internal_error ADXSTM_GetBufSize ADXSTM_GetSj ADXSTM_SetBufSize ADXSTM_SetReqRdSize ADXSTM_GetFileLen ADXSTM_GetCvdfsStat ADXSTM_GetFad ADXSTM_GetFsizeByte ADXSTM_SetRdSct ADXT_SetNumRetry',
        'adx_tlk':'ADXT_CloseAllHandles ADXT_SetTimeMode ADXT_SetAutoRcvr ADXT_SetTimeOfst ADXT_SetLnkSw ADXT_GetLnkSw ADXT_EntryFltFunc ADXT_IsHeader ADXT_IsEndcode ADXT_InsertSilence ADXT_SetOutputMono ADXT_EntryErrFunc',
        'ps2_rna':'ps2rna_release_psj PS2RNA_GetSjtmp PS2RNA_GetSjiop',
        'rna_crs':'RNACRS_Init RNACRS_Finish RNACRS_Lock RNACRS_Unlock',
    }
    for stem,names in same.items():
        for symbol in names.split():
            record=records[stem,symbol]
            if record['status']=='version-different':record['status']='newly-compared'
    return records


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--reference',type=Path,default=Path.home()/'AppData/Local/Temp/reo-recvx-crosscheck-20261104')
    ap.add_argument('--output',type=Path,default=ROOT/'build-function-index/recvx-audio-complete-scope.json')
    args=ap.parse_args()
    universe=json.loads((ROOT/'build-function-index/recvx-complete-source-inventory.json').read_text(encoding='utf-8'))
    assert universe['reference_commit']==PIN
    reference=args.reference.resolve()
    manual=dispositions()
    # Existing old crosswalk only supplements exact file/symbol pairs not present
    # in second pass; it is never rewritten here.
    prior=json.loads((ROOT/'docs/recvx-crosscheck/review.json').read_text(encoding='utf-8'))
    for group in prior['groups']:
        stem=Path(group['cvx_file']).stem
        if stem not in STEMS:continue
        for address,symbol,status,comparison in group['rows']:
            key=(stem,symbol)
            if key not in manual:
                manual[key]=dict(outbreak_ids=[address],status='already-compared' if status=='supported-role' else 'version-different',comparison=comparison,prior='review.json')
    elf=Elf(ROOT/'game_data/SLUS_207.65');assert elf.sha256==SHA
    db=sqlite3.connect(f'file:{ROOT/"build-function-index/index.sqlite"}?mode=ro',uri=True)
    # Capture exact authoritative note rows as evidence, not fuzzy-name matches.
    notes={}
    for p in sorted((ROOT/'docs').glob('SYMBOLS*.md')):
        for line_no,line in enumerate(p.read_text(encoding='utf-8').splitlines(),1):
            m=re.match(r'^\| \[(?:main )?0x([\da-f]+)\]\(',line,re.I)
            if m:notes.setdefault(m[1].upper().lstrip('0'),[]).append(dict(path=p.relative_to(ROOT).as_posix(),line=line_no,text=line))
    audited={}
    def owned(address):
        address=address.upper().removeprefix('0X');entry=int(address,16)
        if address not in audited:
            found=db.execute("select end,source,proposed_name from functions where image='main' and start=?",(entry,)).fetchone()
            assert found, address
            end,source,label=found
            raw=elf.read(entry,end-entry);assert raw is not None
            words={int(a,16):int(w,16) for a,w in re.findall(r'// 0x([\da-f]+): 0x([\da-f]+)\s+', (ROOT/source).read_text(encoding='utf-8'),re.I)if entry<=int(a,16)<end}
            for pc,w in words.items():assert elf.read(pc,4)==struct.pack('<I',w),(address,hex(pc))
            missing=[pc for pc in range(entry,end,4)if pc not in words]
            assert all(elf.read(pc,4)==b'\0'*4 for pc in missing),address
            audited[address]=dict(id='main:'+address,entry=address,end_exclusive=f'{end:X}',source=source,label=label,
                sha256=hashlib.sha256(raw).hexdigest(),verified_words=len(words),omitted_zero_words=len(missing),notes=notes.get(address,[]))
        return audited[address]
    files=[];seen=set();missing=[]
    for original in universe['files']:
        stem=Path(original['path']).stem
        if original['path']!=LIB+stem+'.c' or stem not in STEMS:continue
        raw=(reference/original['path']).read_bytes();assert hashlib.sha256(raw).hexdigest()==original['sha256']
        text=raw.decode('utf-8-sig');defs=function_records(text)
        assert [(r['symbol'],r['start_line'],r['body_sha256'])for r in defs]==[(r['symbol'],r['start_line'],r['body_sha256'])for r in original['functions']]
        entries=[]
        for definition in original['functions']:
            key=(stem,definition['symbol']);seen.add(key)
            record=dict(reference_file=original['path'],reference_file_sha256=original['sha256'],**definition)
            current=next(d for d in defs if d['symbol']==definition['symbol'] and d['start_line']==definition['start_line'])
            record['reference_calls']=sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',current['masked_body']))-{'if','for','while','switch','sizeof'})
            if definition['implementation_shape']=='empty':
                record.update(status='source-no-implementation',outbreak_ids=[],comparison='Complete reference body is empty; an adjacent Outbreak return-only leaf does not establish API identity. No semantic credit assigned.')
            elif key not in manual:
                missing.append(key);continue
            else:record.update(manual[key])
            record['outbreak_evidence']=[owned(a)for a in record['outbreak_ids']]
            record['searched_evidence']=[owned(a)for a in record.get('searched_candidates',[])]
            record['limitations']='Static role comparison only: not original symbol recovery, native translation, bit/output parity, runtime reachability or measured cost. See literal original note widths/invalid-input contracts.'
            entries.append(record)
        files.append(dict(path=original['path'],sha256=original['sha256'],functions=entries))
    assert not missing,missing
    assert len(files)==22,len(files)
    unused=set(manual)-seen
    # Prior crosswalk may include conceptual aliases not actual definitions; do
    # not manufacture extra source-function records for them.
    qpath=LIB+'adx_qtbl.c';qraw=(reference/qpath).read_bytes()
    qrec=next(f for f in universe['files']if f['path']==qpath);assert not qrec['functions']
    arrays=[]
    qtext=qraw.decode('utf-8-sig')
    for name,declared,body in re.findall(r'const Float32 (\w+)\[(\d+)\]\s*=\s*\{(.*?)\};',qtext,re.S):
        values=[float(v[:-1])for v in re.findall(r'-?\d+(?:\.\d+)?f',body)]
        assert len(values)==int(declared)
        packed=b''.join(struct.pack('<f',v)for v in values)
        address={'AdxQtblFloat':0x23A4E8,'AdxQtblFloat0':0x23A528,'AdxQtblFloat1':0x23A928}[name]
        assert elf.read(address,len(packed))==packed,(name,hex(address))
        arrays.append(dict(symbol=name,count=len(values),outbreak_address=f'{address:X}',bytes_sha256=hashlib.sha256(packed).hexdigest(),comparison='Every reference float word matches owned Outbreak bytes; data comparison only, no new function credit.'))
    assert len(arrays)==3
    data_file=dict(path=qpath,sha256=hashlib.sha256(qraw).hexdigest(),function_count=0,status='data-only-compared',arrays=arrays)
    auxiliary_tables=[]
    for stem,name,address,width in [('ps2_rna','ps2rna_dbtbl',0x220498,4),('adx_bau','ulaw_exp_table',0x20B738,2)]:
        text=(reference/(LIB+stem+'.c')).read_text(encoding='utf-8')
        m=re.search(r'\b'+name+r'\[(\d+)\]\s*=\s*\{(.*?)\};',text,re.S)
        assert m,name
        values=[int(v,0)for v in re.findall(r'0x[0-9a-fA-F]+|\b\d+\b',m[2])]
        assert len(values)==int(m[1]),name
        raw=b''.join(v.to_bytes(width,'little',signed=False)for v in values)
        original=elf.read(address,len(raw));assert original is not None
        mismatches=[i for i in range(len(values))if raw[i*width:(i+1)*width]!=original[i*width:(i+1)*width]]
        auxiliary_tables.append(dict(reference_file=LIB+stem+'.c',symbol=name,words=len(values),word_bytes=width,
            outbreak_address=f'{address:X}',reference_bytes_sha256=hashlib.sha256(raw).hexdigest(),
            owned_bytes_sha256=hashlib.sha256(original).hexdigest(),mismatched_indices=mismatches))
    counts=Counter(r['status']for f in files for r in f['functions'])
    result=dict(schema=1,reference_commit=PIN,outbreak_elf_sha256=SHA,files=files,data_files=[data_file],auxiliary_tables=auxiliary_tables,
        counts=dict(function_files=len(files),data_files=1,functions=sum(len(f['functions'])for f in files),statuses=dict(counts),
            owned_complete_intervals=len(audited),owned_verified_words=sum(r['verified_words']for r in audited.values())),
        unmatched_prior_aliases=[list(k)for k in sorted(unused)],all_reference_definitions_dispositioned=True,
        no_target_activity=True,notes='docs/recvx-crosscheck/AUDIO_COMPLETE_SCOPE.md')
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts'],indent=2))


if __name__=='__main__':main()
