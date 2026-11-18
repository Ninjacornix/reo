#!/usr/bin/env python3
"""Reproduce the complete, static 24-file CRI filesystem/stream comparison ledger.

No guest code, game, build, network, attachment or shared index/report mutation.
The ledger counts source bodies, not new Outbreak mappings or proven equivalence.
"""
from collections import Counter, defaultdict
import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import subprocess

from index import Elf, ELF_SHA
from recvx_scope_inventory import function_records, PIN

ROOT = Path(__file__).resolve().parents[2]
REL = 'cri/mwlib/ee/lib/libadxe/'
STEMS = 'adx_fcch adx_fs adx_fsvr adx_sudv adx_suht cri_cvfs dtr dtx dvci dvci_sub htci htci_sub lsc lsc_crs lsc_err lsc_ini lsc_svr sjr_clt sjx sj_crs sj_mem sj_rbf sj_uni sj_utl'.split()

# Independently reviewed descriptive-contract correspondences. Existing curated
# comparisons are merged below, including multiple Outbreak routes for one CVX
# symbol. A related-different entry is not an identity/equivalence claim.
PAIRS = {
'adx_fcch': 'ADXF_Ocbi=128328',
'adx_fs': '''adxf_SetCmdHstry=1284F8 adxf_wait_1ms=1285A8 adxf_ChkPrmPt=1285D8
adxf_CloseLdptnwHn=128A60 ADXF_StopPtLd=128AB0 ADXF_GetPtStat=128B18
adxf_AllocAdxFs=128F28 adxf_CreateAdxFs=128F80 adxf_SetFileInfoEx=129010 ADXF_Open=1290C8
adxf_CloseSjStm=1292E0 ADXF_Close=129350 ADXF_CloseAll=129408 adxf_read_sj32=129468
ADXF_ReadSj32=129568 ADXF_ReadNw32=129610 ADXF_ReadNw=1297A0 ADXF_Stop=1297E0
adxf_ExecOne=129998 ADXF_ExecServer=129A60 ADXF_Seek=129AC0 ADXF_Tell=129BD8
ADXF_GetNumReqSct=129CC8 ADXF_GetNumReadSct=129D18 ADXF_GetStat=129D48
adxf_ChkPrmGfr=129D78 ADXF_GetFnameRange=129DF0 ADXF_SetOcbiSw=129F88 ADXF_SetReqRdSct=129F98''',
'adx_sudv': 'adxt_err_dvd=131070 ADXT_SetupDvdFs=131088 ADXT_LoadFpCacheDvd=131190 ADXT_SetRdMode=131258',
'adx_suht': 'adxt_err_host=131320 ADXT_SetupHostFs=131338 ADXT_LoadFpCacheHost=131428 ADXT_SetOpMode=131490',
'cri_cvfs': '''cvFsCallUsrErrFn=1351D0 cvFsError=135200 cvFsInit=135228 cvFsFinish=1352F0
cvFsAddDev=1353F8 addDevice=135488 getDevice=135560 toUpperStr=1355F8 cvFsDelDev=135658
cvFsSetDefDev=135730 isExistDev=1357F8 cvFsGetDefDev=135878 allocCvFsHn=135A58
releaseCvFsHn=135AC0 getDevName=135AD0 getDefDev=135C18 cvFsGetFreeSize=1361A8
cvFsChangeDir=136410 cvFsIsExistFile=1364D0 cvFsGetMaxByteRate=136760
cvFsMakeDir=1367B8 cvFsRemoveDir=136878 cvFsDeleteFile=136938 cvFsGetDevName=1369F8 cvFsEntryErrFunc=136A80''',
'dtr': 'DTR_ExecHndl=138650 DTR_ExecServer=1389D8 DTR_Init=138A38 DTR_Finish=138AA0 DTR_Create=138AB8 DTR_Destroy=138BA8 DTR_Start=138BD0 DTR_Stop=138BE0',
'dtx': 'dtx_rpc_func=138C90 dtx_svr_proc=138D60 DTX_Init=1392F8 DTX_Finish=1393E8 DTX_CallUrpc=139460',
'dvci': '''dvCiGetInterface=1395C8 dvci_call_errfn=1395F8 dvCiExecHndl=1396D0
dvCiExecServer=139798 dvCiEntryErrFunc=139810 dvci_to_large_to_yen=139828 dvci_conv_fname=13A248
dvCiGetFileSize=139928 dvci_alloc=1399F8 dvci_free=139A30 dvCiOpen=139A50 dvCiClose=139BD8
dvCiSeek=139C30 dvCiTell=139CC8 dvCiReqRd=139D00 dvCiStopTr=139EA8 dvCiGetStat=139FA8 dvCiGetSctLen=139FE0''',
'dvci_sub': '''conv_to_tpath=13A248 analysis_flist=13A418 load_flist=13A5B0 search_fstate=13A738
get_fp_from_fname=13A910 dvci_init_flist=13A9D8 dvci_get_fstate=13AA00 dvCiLoadFpCache=13AAB0 dvCiSetRdMode=13ADF0''',
'htci': '''htCiGetInterface=13AF60 htci_wait=13AF98 htci_call_errfn=13AFC8 htCiExecHndl=13B110
htCiExecServer=13B1D8 htCiEntryErrFunc=13B250 htci_conv_fname=13BE80
htci_get_fsize_opened=13B528 htci_alloc=13B5B0 htci_free=13B5E8 htCiOpen=13B608
htCiClose=13B790 htCiSeek=13B840 htCiTell=13B8D8 htCiReqRd=13B910 htCiStopTr=13BAA0
htCiGetStat=13BBA8 htCiGetSctLen=13BBE0''',
'htci_sub': '''conv_to_tpath=13BE80 analysis_flist=13C0A0 load_flist=13C240 open_file_all=13C3A0
close_file_all=13C590 get_fstate=13C6F8 htci_init_flist=13C7C0 htci_get_finf=13C7E8
htCiLoadFpCache=13C838 htCiSetOpenMode=13C9E8''',
'lsc': '''lsc_Alloc=13CB50 LSC_Create=13CBB0 LSC_Destroy=13CCB8 LSC_EntryFname=13CD10
LSC_EntryFileRange=13CD38 LSC_Start=13CF10 LSC_Stop=13CF78 LSC_Pause=13D000
LSC_ExecServer=13D040 LSC_GetStat=13D0A0 LSC_GetNumStm=13D0D0 LSC_GetStmId=13D100
LSC_GetStmFname=13D190 LSC_GetStmStat=13D228 LSC_GetStmRdSct=13D2C0
LSC_SetFlowLimit=13D358 LSC_GetFlowLimit=13D3C0 LSC_EntryChgStatFunc=13D3F0
LSC_CallStatFunc=13D430 LSC_SetLpFlg=13D468''',
'lsc_crs': 'LSC_LockCrs=13D498 LSC_UnlockCrs=13D4B8',
'lsc_err': 'LSC_EntryErrFunc=13D4D0 LSC_CallErrFunc=13D4F8',
'lsc_ini': 'LSC_Init=13D598 LSC_Finish=13D618',
'lsc_svr': 'lsc_StatWait=13D6D8 lsc_StatRead=13D800 lsc_StatEnd=13D8B0 lsc_ExecHndl=13D9B8',
'sjr_clt': '''SJRBF_CreateRmt=140AF0 SJMEM_CreateRmt=140B48 SJUNI_CreateRmt=140B98
SJRMT_Destroy=140BF0 SJRMT_GetUuid=140C20 SJRMT_Reset=140C90 SJRMT_GetChunk=140CC0
SJRMT_UngetChunk=140D30 SJRMT_PutChunk=140D80 SJRMT_GetNumData=140DD0
SJRMT_IsGetChunk=140E20 SJRMT_Init=140E88 SJRMT_Finish=140ED8''',
'sjx': 'sjx_rcvcbf=140F18 sjx_sndcbf=140FB8 SJX_ExecServer=141268 SJX_Init=141280 SJX_Finish=141418 SJX_Create=141490 SJX_Destroy=141588 SJX_Reset=1415D0',
'sj_mem': '''SJMEM_Error=13F2A0 SJMEM_Init=13F2C0 SJMEM_Finish=13F310 SJMEM_Create=13F360
SJMEM_Destroy=13F428 SJMEM_GetUuid=13F460 SJMEM_EntryErrFunc=13F468 SJMEM_Reset=13F478
SJMEM_GetNumData=13F488 SJMEM_GetChunk=13F4D0 SJMEM_PutChunk=13F590 SJMEM_UngetChunk=13F628
SJMEM_IsGetChunk=13F720 SJMEM_GetBufPtr=13F7C8 SJMEM_GetBufSize=13F7D0''',
}

FAMILY = {
'adx_fcch': 'Both form an inclusive end address for cache-range maintenance; CVX declares Uint64 size, while owned128328 computes its endpoint with 32-bit ADDU/ADDIU. This is not host-cache coherence.',
'adx_fs': 'Shared ADXF handle/partition/sector-I/O family. Outbreak uses16 records of0x44 bytes, persistent stream setup and newer partition state/layout; preserve its recorded guards, ownership and signed arithmetic. This is role correspondence, not unchanged implementation.',
'adx_sudv': 'Shared DVD setup/error/file-list/mode facade. CVX ADXT_SPRM is28bytes with fname/fpc/size/mode fields; owned setup consumes a different20-byte prefix/mode/option descriptor, and cache loading is a separate16-byte descriptor. Do not copy argument offsets.',
'adx_suht': 'Shared host setup/error/file-list/mode facade. CVX28-byte ADXT_SPRM differs from owned16-byte prefix/reopen/64-bit-option/lock configuration; separate cache descriptor order/width differs.',
'cri_cvfs': 'Shared two-word CVFS wrapper,32-entry registry and26-slot interface family. Owned resolver/path extensions and returning-diagnostic paths are retained; a common API slot does not establish every provider implementation.',
'dtr': 'Shared chunk-reservation/SIF-DMA lifecycle. CVX pool16 versus owned32 contexts; stop ownership/completion differs. Both service bodies literally add the saved length after clearing it, yielding zero along that path; do not repair the finding from API expectations.',
'dtx': 'Shared8-context,64-byte-footer RPC/DMA protocol. Owned send gates and acknowledgement-aware teardown differ from CVX; preserve callbacks, ignored RPC status and unbounded-wait boundaries.',
'dvci': 'Shared disc interface and40-handle family. CVX issues sceCdRead/sync directly; owned bodies use SRD request objects, completed-count fields and guarded service. Cache/prefix options and field layout differ.',
'dvci_sub': 'Shared filename-list/cache family, but CVX embeds140-byte records; owned uses8-byte metadata pairs plus capacity*(width+1) names and a16-byte registration descriptor. Parser bounds, prefix options, normalization and returned size differ.',
'htci': 'Shared host interface and13-handle family. CVX ioctl/seek/read stages differ from owned SRD requests,64-bit stored size, completed-count fields and options. Do not assume equal field offsets or cursor/transfer-count semantics.',
'htci_sub': 'Shared host-list/cache family. CVX embeds268-byte records and fixed host prefix; owned has split metadata/name storage, configurable prefixes/width, slash-only case-sensitive matching, and a16-byte registration descriptor.',
'lsc': 'Shared16-slot filename queue lifecycle, but CVX has8 instances and copies40-byte names; owned has16 instances with32-byte queue records, borrows names plus checksum, and reuses a supplied stream. Layout/lifetime/guard contracts differ.',
'lsc_crs': 'Both wrappers delegate shared stream guards and ignore the token pointer. CVX SJCRS changes a plain global nesting counter; owned delegates callback-backed CRI tagged guards, not an independent token-restoration algorithm.',
'lsc_err': 'Same global error callback/context and shared unbounded variadic-format buffer design; exact owned formatter ABI is recorded separately, not inferred from the host C va_list.',
'lsc_ini': 'Same first/last-reference LSC lifecycle. CVX locks the whole finish; owned finish lacks an outer guard. Instance count/layout differ and underflow is not clamped.',
'lsc_svr': 'Related three-phase head service and retirement. CVX opens/closes a stream per queued file and owns copied names; owned checksum-validates borrowed names and reconfigures/reuses a supplied stream, with distinct progress/stop behavior.',
'sjr_clt': 'Same numeric20..2A operation family, word packing and reply shape; owned IOP server bindings independently confirm roles. Remote handles/payload pointers retain their IOP address domain; transport success is not validated.',
'sjx': 'Shared128-command,16-byte descriptor protocol and20-byte binding. CVX16 bindings versus owned32, generation validation/reset RPC and teardown policies differ; source fields cannot be transplanted unchanged.',
'sj_mem': 'Same32-object borrowed contiguous read-view layout and selector1 readable semantics; Put does not publish or restore consumed data, Unget mutates before pointer check. Default error action differs; shared guard implementation differs.',
'sj_rbf': 'Prior complete ring comparison retained: owned256*64-byte records versus CVX64*48; four transfer totals and shifted callback fields differ. UUID matches do not imply layout equivalence.',
'sj_uni': 'Prior complete four-queue/node-pool comparison retained:64 objects, external16-byte nodes. Signed owned work-size division differs from CVX Uint32 cast, and default error action differs.',
'sj_utl': 'Same borrowed pointer/length split and alias ordering; no payload copy or negative-size admission is established.',
}

DIFFERENCES = {
'adx_fs:ADXF_Seek': 'Both clamp sector seek and stop an active read; CVX additionally calls ADXSTM_SetOfst(ofst+skpos), but complete owned129AC0 only updates cursor/logs and does not call a stream-offset setter.',
'adx_fs:adxf_CreateAdxFs': 'CVX initializes stream=NULL; owned128F80 constructs an actual stream immediately. Their later setup/destruction must retain that ownership difference.',
'adx_fs:ADXF_GetFnameRange': 'CVX directly walks linked additive/Uint16 partitions. Owned129DF0 adapts to129E18 and discards its parent output, supporting newer Uint16/32-bit/base fields rather than linked overlays.',
'adx_fs:ADXF_ReadNw32': 'Both reserve a ring over caller destination and return admission, not completion. CVX also records hardware timer checkpoints; no timer-equivalence claim is made for owned129610.',
'dvci:dvci_alloc': 'Both scan all40 records and return the last free record; neither reserves it here. Do not replace with first-free semantics.',
'htci:htci_alloc': 'Both scan all13 records and return the last free record; neither reserves it here.',
'htci_sub:htCiSetOpenMode': 'CVX maps mode0 to0,1 to1,others8001. Owned13C9E8 maps only1 to1 and every other argument, including0, to8001.',
'htci_sub:get_fstate': 'CVX strcasecmp is case-insensitive. Owned13C6F8 uses13C008, which normalizes slash direction only and preserves letter case.',
'htci_sub:load_flist': 'Both read at most4096 bytes without forcing NUL. Seek failure can leave the opened descriptor unclosed; short positive reads are not rejected.',
'htci_sub:open_file_all': 'Both cap initial opens at13 and store the initial descriptor/size before close/reopen; neither source evidence proves the reopened descriptor overwrites that stored initial descriptor.',
'lsc:LSC_EntryFname': 'CVX opens a file immediately to determine sectors and closes it before enqueue. Owned13CD10 only enqueues borrowed name with zero parent/start and FFFFF limit; actual open is deferred.',
'lsc:LSC_EntryFileRange': 'CVX strncpy copies40 bytes into each slot. Owned13CD38 stores a borrowed pointer, length/byte-sum checksum and richer range fields; queue consumers rely on later content/lifetime checks.',
'lsc:LSC_Stop': 'CVX closes stream and clears fp; owned13CF78 keeps supplied handle28, may stop transfer, resets queue only when state was nonzero and does not free the stream.',
'lsc:LSC_ExecServer': 'CVX guards whole8-instance scan. Owned13D040 scans16 active instances without any outer critical-section call.',
'lsc:LSC_GetStmFname': 'Both scan all16 IDs rather than current head/count. CVX returns an inline slot buffer; owned13D190 loads and returns the borrowed name pointer.',
'lsc:LSC_GetStmRdSct': 'Both report sector progress by sequence ID, not bytes/FPS. Owned13D800 stores130608 sector-progress word54 while reading or configured sector limit2C at completion; missing-ID zero remains ambiguous.',
'lsc:LSC_Destroy': 'Both clear the instance without destroying borrowed SJ. CVX wraps stop/clear in LSC guard; owned13CCB8 has no equivalent outer guard.',
'lsc_svr:lsc_StatEnd': 'CVX closes per-file fp and copies repeat name into static scratch. Owned13D8B0 keeps lower handle and retains the borrowed name pointer for possible repeat after callback.',
'sjr_clt:SJRMT_IsGetChunk': 'Both ask transport for ONE reply word then read reply[1] as available length. Owned server writes two, but EE copy refreshes only first; the shared stale-second-word hazard is preserved.',
'sjx:sjx_rcvcbf': 'CVX tests command.xid against binding.xid before PutChunk. Owned140F18 filters command0 but does not compare generation halfword; it uses the entry pool byte.',
'sjx:SJX_Finish': 'CVX only decrements reference count. Owned141418 on exact zero destroys DTX and releases owned IOP heap/reference.',
'sjx:SJX_Reset': 'CVX increments xid and sends reset op2 with remote ID/new generation. Owned1415D0 only increments the local16-bit generation and issues no RPC.',
'sj_mem:SJMEM_Error': 'CVX spins forever. Owned13F2A0 forwards owned SJMEM Error text; returning error handling is possible.',
'sj_mem:SJMEM_GetBufSize': 'Both return fixed capacity at+18, distinct from current available count+C. Earlier owned note mistakenly called+1C availability; +1C is error callback, now corrected.',
}

UNMATCHED = {
'adx_fsvr:ADXT_ExecFsSvr': ('main:135EF0, main:129A60 and file-service group dispatcher', 'CVX directly calls cvFs,ADXF,ADXSTM services in sequence; owned service scheduler distributes these phases. No one-to-one public facade is demonstrated in the reviewed notes/call graph.'),
'adx_fs:adxf_LoadData': ('128620 synchronous nested service loop and128860/128B18 partition loader', 'Related blocking read/poll concept, but owned loop is integrated with new asynchronous partition state; no independent matching LoadData body established.'),
'adx_fs:ADXF_LoadPartition': ('128620..128F10 partition-loading/range notes', 'CVX direct Uint16 header reader with supplied member cap has no proven one-to-one body; owned synchronous adapter delegates to newer asynchronous core.'),
'adx_fs:ADXF_LoadPartitionEx': ('128620..128F10 partition-loading/range notes', 'CVX independent direct reader with directory argument is not proved identical to owned shared-scratch/mode adapters.'),
'adx_fs:ADXF_LoadPartitionNw': ('128860 asynchronous partition core and128B18 poller', 'Shared role is clear, but expanded Outbreak core has scratch/size/mode and optional nested-parent arguments; old signature has no one-to-one admission contract.'),
'adx_fs:ADXF_AddPartition': ('128620..129F70 partition operations,129E18 range resolution', 'CVX prepends linked additive partitions; reviewed owned resolver selects16/32-bit tables and base fields without linked additive traversal. No matching additive-partition API demonstrated.'),
'adx_fs:ADXF_GetPtinfoSize': ('128F10 accessor and partition descriptor consumers', 'Do not match by nearby accessor: owned128F10 returns member count at+8, while CVX returns descriptor size. No typed size getter counterpart demonstrated.'),
'cri_cvfs:cvFsGetNumFiles': ('1351D0..137138 CVFS family;136578 legacy/private helper', 'Public CVX NULL aggregation plus zero-result diagnostic is absent from136578; only private getNumFiles is compared. No public-wrapper body established.'),
'cri_cvfs:getNumFilesAll': ('32-device registry service/lookup scans and136578', 'No owned aggregate-all method44 summing body demonstrated; 136578 has strlen input, first-callable return and no NULL aggregate route.'),
'dvci:dvci_wait': ('1395C8..13A248 provider helpers and stop path', 'CVX32768-iteration disc backoff has no demonstrated independent same-role owned body; SRD stop/backoff implementation differs.'),
'htci:htci_is_one_excute': ('13AFF8/13B048 predicates and13B110 updater', 'CVX ioctl(end_fg) predicate is related to owned request completion polling, but argument/field/status contracts differ; no one-to-one identity claimed.'),
'htci:htci_is_all_excute': ('13AFF8 active/read scan and host SRD updater', 'CVX scans active handles calling ioctl completion; owned13AFF8 tests whether any handle is in read state2. These predicates are not equivalent.'),
'htci:htci_wait_io': ('13AFF8 state scan and13B048 one-request polling', 'CVX unbounded all-handle ioctl loop has no demonstrated independent counterpart with identical admission/progress.'),
'htci:htci_wait_by_fd': ('13B048 completion test and host SRD wrappers', 'CVX loops ioctl by descriptor then waits all; owned13B048 polls a stored request once and tests a field. Do not rename it as this wait helper.'),
'sj_crs:SJCRS_Init': ('13F258/270 shared SJ guard wrappers and1415E0 tagged guards', 'CVX clears plain nesting global. No matching independent SJCRS initializer is demonstrated; generic counter clears elsewhere do not prove identity.'),
'sj_crs:SJCRS_Lock': ('13F258->1416D0->1415E0', 'Functional guard boundary is related, but owned uses optional callback-backed CRI tagged lock; CVX only increments its global counter. No one-to-one helper semantics.'),
'sj_crs:SJCRS_Unlock': ('13F270->1416E8->141640', 'Owned callback-backed tagged release differs from plain CVX decrement; do not replace synchronization with reference counter arithmetic.'),
}


def sha(data): return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference', type=Path, default=Path('C:/Users/Ninjacornix/AppData/Local/Temp/reo-recvx-crosscheck-20261104'))
    parser.add_argument('--out', type=Path, default=ROOT/'build-function-index/recvx-streamfs-complete-scope.json')
    args = parser.parse_args()
    ref = args.reference.resolve()
    git = lambda *a: subprocess.check_output(['git','-C',str(ref),*a],text=True,encoding='utf-8').strip()
    assert git('rev-parse','HEAD') == PIN
    assert not git('status','--porcelain','--untracked-files=no')
    corpus = json.loads((ROOT/'build-function-index/recvx-complete-source-inventory.json').read_text())
    manifest = {f['path']:f for f in corpus['files']}
    assert corpus['reference_commit'] == PIN
    baseline_path=Path(__file__).with_name('recvx_streamfs_prior_comparisons.json')
    old = json.loads(baseline_path.read_text())
    assert old['reference_commit']==PIN
    prior = defaultdict(list)
    for group in old['groups']:
        for address,symbol,status,comparison in group['rows']:
            prior[group['cvx_file'],symbol].append(dict(address=address,notebook=group['notebook'],status=status,comparison=comparison))
    notes = defaultdict(list)
    for path in sorted((ROOT/'docs').glob('SYMBOLS*.md')):
        for number,line in enumerate(path.read_text(encoding='utf-8').splitlines(),1):
            match = re.match(r'^\| \[0x([0-9a-f]+)\]\(([^)]+)\)\s*\|\s*`([^`]+)`\s*\|\s*([^|]+)\|\s*(.*?)\s*\|$',line,re.I)
            if match:
                notes[int(match[1],16)].append(dict(notebook=path.name,line=number,label=match[3],confidence=match[4],contract=match[5],notebook_sha256=sha(path.read_bytes())))
    elf = Elf(ROOT/'game_data/SLUS_207.65')
    db = sqlite3.connect('file:'+(ROOT/'build-function-index/index.sqlite').as_posix()+'?mode=ro',uri=True)
    db.row_factory=sqlite3.Row
    audited={}
    def audit(address):
        if address in audited:return audited[address]
        row=db.execute('select * from functions where image=? and start=?',('main',address)).fetchone()
        assert row and row['source'],hex(address)
        raw=elf.read(address,row['end']-address)
        comments={int(m[1],16):int(m[2],16) for m in re.finditer(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s',(ROOT/row['source']).read_text(),re.I) if address<=int(m[1],16)<row['end']}
        for pc in range(address,row['end'],4):
            w=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:assert comments[pc]==w,hex(pc)
            else:assert w==0,('omitted nonzero',hex(pc))
        value=dict(id='main:'+hex(address),source=row['source'],start=hex(address),end_exclusive=hex(row['end']),sha256=sha(raw),instruction_comments=len(comments),omitted_zero_words=len(raw)//4-len(comments),notes=notes[address])
        assert value['notes'],('no authoritative note',hex(address))
        audited[address]=value
        return value
    files=[];used_pairs=set();all_ids=[]
    for stem in STEMS:
        path='src/'+REL+stem+'.c';raw=(ref/path).read_bytes();text=raw.decode('utf-8-sig')
        assert sha(raw)==manifest[path]['sha256']
        assert not manifest[path]['assembly_placeholders']
        records=function_records(text)
        assert [(r['symbol'],r['start_line'],r['body_sha256']) for r in records]==[(r['symbol'],r['start_line'],r['body_sha256']) for r in manifest[path]['functions']]
        mappings={name:int(addr,16) for name,addr in (item.split('=') for item in PAIRS.get(stem,'').split())}
        functions=[]
        for record in records:
            name=record['symbol'];key=stem+':'+name
            old_rows=prior[path,name];candidates=[]
            for p in old_rows:
                candidates.append(dict(outbreak_id='main:'+hex(int(p['address'],16)),status=p['status'],comparison=p['comparison'],basis='prior-reviewed-comparison',notebook=p['notebook']))
            if name in mappings:
                used_pairs.add(key);address=mappings[name]
                if not any(int(c['outbreak_id'].split(':')[1],16)==address for c in candidates):
                    candidates.append(dict(outbreak_id='main:'+hex(address),status='related-different',comparison=DIFFERENCES.get(key,FAMILY.get(stem,'')),basis='new-complete-source-and-existing-owned-contract-comparison'))
            for c in candidates:
                evidence=audit(int(c['outbreak_id'].split(':')[1],16))
                c['evidence_id']=evidence['id']
                if 'notebook' not in c:c['notebook']=evidence['notes'][0]['notebook']
            if record['implementation_shape']=='empty':
                disposition='source-unimplemented-empty';boundary='Return-only owned13D588/590 are mechanical, no semantic credit';explanation='Empty registration hooks in CVX source; no behavior or subsystem purpose inferred from emptiness.'
            elif candidates:
                disposition='already-compared' if old_rows else 'newly-compared';boundary='Complete reference body and authoritative original interval(s)/typed notes retained in this receipt';explanation=DIFFERENCES.get(key,FAMILY.get(stem,''))
            else:
                assert key in UNMATCHED,('unclassified body',key)
                disposition='no-demonstrated-counterpart';boundary,explanation=UNMATCHED[key]
            copy={k:v for k,v in record.items() if k not in ('masked_body',)}
            copy.update(identity=path+':'+name+':'+str(record['start_line']),disposition=disposition,
                comparison=explanation,search_boundary=boundary,outbreak_comparisons=candidates,
                source_calls=sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',record['masked_body']))-{'if','for','while','switch','sizeof'}),
                source_member_names=sorted(set(re.findall(r'->\s*([A-Za-z_]\w*)',record['masked_body']))),
                complete_reference_body=text[record['body_start']:record['body_end_offset']])
            functions.append(copy);all_ids.append(copy['identity'])
        header='include/'+REL+stem+'.h';header_raw=(ref/header).read_bytes();header_text=header_raw.decode('utf-8-sig')
        header_defs=function_records(header_text)
        assert not header_defs,('unexpected header function bodies',header)
        files.append(dict(path=path,sha256=sha(raw),file_bytes=len(raw),
            source_global_declarations=text[:records[0]['header_start']] if records else text,
            family_comparison=FAMILY.get(stem,'See per-body searched boundary.'),functions=functions,
            header=dict(path=header,sha256=sha(header_raw),file_bytes=len(header_raw),complete_text=header_text,
                definitions=header_defs,review='Complete available header read; prototypes/layout/constants are comparative source evidence, not proof of owned ABI.')))
    assert len(files)==24 and len(all_ids)==286 and len(set(all_ids))==286
    assert used_pairs=={stem+':'+item.split('=')[0] for stem,values in PAIRS.items() for item in values.split()}
    dependency_ids=[]
    for address in (0x128F10,0x130608,0x13F258,0x13F270,0x1415E0,0x141640,0x1416D0,0x1416E8):
        dependency_ids.append(audit(address)['id'])
    assert elf.read(0x13F7D0,8).hex() == '0800e0031800828c'
    assert elf.read(0x1415D0,16).hex() == '02008294010042240800e003020082a4'
    uuid_checks=[]
    for stem,address in [('sj_mem',0x23DA08),('sj_rbf',0x23DA58),('sj_uni',0x23DA78)]:
        source=(ref/('src/'+REL+stem+'.c')).read_text()
        match=re.search(r'\b'+stem.replace('_','')+r'_uuid\s*=\s*\{(.*?)\};',source,re.S)
        assert match,stem
        fields=[int(v,16) for v in re.findall(r'0x[0-9a-f]+',match[1],re.I)]
        assert len(fields)==11
        packed=struct.pack('<IHH8B',*fields)
        assert elf.read(address,16)==packed
        uuid_checks.append(dict(reference=stem+'_uuid',outbreak_address=hex(address),raw_bytes=packed.hex(),identical=True))
    proposal=defaultdict(list);proposed_addresses=set()
    for f in files:
        for r in f['functions']:
            for c in r['outbreak_comparisons']:
                if c['basis']!='new-complete-source-and-existing-owned-contract-comparison':continue
                if c['outbreak_id'] in proposed_addresses:continue
                proposed_addresses.add(c['outbreak_id'])
                proposal[c['notebook'],f['path']].append([c['outbreak_id'].split(':')[1][2:].upper(),r['symbol'],c['status'],c['comparison']])
    counts=Counter(r['disposition'] for f in files for r in f['functions'])
    out=dict(schema=1,reference_commit=PIN,original_elf_sha256=ELF_SHA,
        prior_comparison_baseline=dict(path=baseline_path.relative_to(ROOT).as_posix(),
            sha256=sha(baseline_path.read_bytes()),original_review_sha256=old['baseline_review_sha256']),
        scope=dict(source_files=24,headers=24,source_definitions=286,header_definitions=0,
            inventory_identity='path + symbol + start_line; body hashes preserve decoded original CRLF',
            dispositions=dict(counts)),files=files,outbreak_evidence=list(audited.values()),
        additional_owned_dependency_ids=dependency_ids,
        shared_uuid_checks=uuid_checks,
        proposed_curated_groups=[dict(notebook=n,cvx_file=p,rows=rows) for (n,p),rows in proposal.items()],
        new_outbreak_mapping_credit_from_ledger=0,
        audit=dict(outbreak_intervals=len(audited),instruction_comments=sum(v['instruction_comments'] for v in audited.values()),
            omitted_zero_words=sum(v['omitted_zero_words'] for v in audited.values()),conflicts=0,omitted_nonzero=0),
        limits='All available24 C files and24 matching headers semantically inspected against the declared owned-contract boundary. Not proof of identical machine code, runtime correctness, exhaustive counterpart discovery, or complete native translation. Unmatched/empty bodies are explicitly retained, not promoted. Shared annotations/index/review.json are not written.')
    args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(scope=out['scope'],audit=out['audit'],per_file=[dict(path=f['path'],definitions=len(f['functions']),dispositions=dict(Counter(r['disposition']for r in f['functions']))) for f in files]),indent=2))


if __name__=='__main__':main()
