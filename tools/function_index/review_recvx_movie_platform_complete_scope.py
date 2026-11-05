#!/usr/bin/env python3
"""Offline complete CVX movie-wrapper/platform-buffer comparison ledger."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from index import Elf
from recvx_scope_inventory import function_records,PIN
from review_recvx_audio_second_pass import SHA

ROOT=Path(__file__).resolve().parents[2]
BASE='src/ps2/veronica/prog/'
FILES=('ps2_MovieFunc.c','ps2_sfd_mw.c','mwwrap.c')


def dispositions():
    out={}
    def shared(symbol,ids,comparison,different=False):
        out['ps2_MovieFunc.c',symbol]=dict(status='version-different' if different else 'newly-compared',outbreak_ids=ids.split(),comparison=comparison)
    shared('getFIFOindex','1709A0','Same special terminal-tag pointer=>0 and2048-byte block index. CVX uses unsigned address difference/division; Outbreak signed truncation toward0, different for invalid/out-of-range addresses.',True)
    shared('setD3_CHCR','1709F0','Exact from-IPU CHCR writer bracket: DI,globalDMApause,writeB000,clearDMApause,unconditionalEI. Unlike Outbreak SDK113BA8, prior IRQ state is not restored conditionally.')
    shared('setD4_CHCR','170A58','Exact to-IPU CHCR writer bracket targetingB400; unconditionalEI matches Sofdec worker, not SDK113C20 conditional restore.')
    shared('scTag2','170AC0','Same lower64 tag bits=(u32address<<32)|(u32id<<28)|u32QWC, only8bytes of16-byte tag written; no field/overlap checks.')
    shared('viBufReset','170B60','Same ViBuf field layout/reset,24-byte timestamps to -1/-1/0/0,2048-byte REF chain plus NEXT link,physical address mask,channel4stop5/return1. Positive loop guards retained.')
    shared('viBufBeginPut','170CA0','Exact semaphore/two-span formula: queued+read offset,capacity modulo,free=(n-queued-REST2)*2048-partial; no negative-free clamp, no payload copy. CVX macros/types.h independently confirm REST2.')
    shared('viBufEndPut','170D90','Same semaphore bracket,32-bit partial bytes plus64-bit total increment; no DMA submission or size validation.')
    shared('copy2area','171BE0','Same signed total-fit rejection,three-way two-source/two-destination memcpy geometry,all-or-nothing source count return; component signs/overflow/overlap unvalidated.')
    shared('mpegStopDMA','171060 1719A0','Complete DMA snapshot worker matches stop/input-output registers/FIFO maskF0 sequence. CVX callback uses global videoDec.vibuf; Outbreak worker accepts ViBuf pointer and1719A0 adapts main cookie. Same low-level contract, different ownership/ABI.',True)
    shared('mpegRestartDMA','171160 1719C8','Shared FIFO/bit-pointer compensation,ring wrap/tag fixup and DMA restore. CVX computes correction before semaphore; Outbreak locks first. CVX busy/BCLR waits only if dmaN!=0; Outbreak1713A4..1713EC always performs them. Outbreak callback uses maincookie->record, not CVX global object.',True)
    shared('viBufDelete','171478','Same channel4stop5,zeroQWC/MADR/TADR,DeleteSema,return1 ignoring delete result; no buffer/tag free.')
    shared('mpegNodata','170E60 171920','Same whole-block DMA chain reconciliation core, but CVX callback SleepThread before locking and returns inactive error without SignalSema; Outbreak170E60 explicitly releases on inactive and171920 adds original-IPU underflow/endcode policy. Related complete components, not identical callback.',True)
    # Every negative is tied to a reviewed alternative implementation boundary,
    # not just absence of a matching symbol spelling.
    def negative(file,text):
        for line in text.strip().splitlines():
            name,ids,why=(s.strip()for s in line.split('|',2))
            assert (file,name)not in out,(file,name)
            out[file,name]=dict(status='no-demonstrated-counterpart',outbreak_ids=[],searched_candidates=ids.split(),comparison=why)
    negative('ps2_MovieFunc.c','''
initAll | 147AD8 1715F0 170AE8 15CC80 | CVX global sceMpeg/PCM/read ring initialization and decoder thread; Outbreak separate caller-workspace decoder owner,optional IPU ring and CRI player constructor. Whole initialization body/callback layout does not match.
readMpeg | 16A660 16AEA0 171920 132C08 | CVX CD streaming8sectors/SonyDemuxPssRing plus global PCM and thread wake; Outbreak program-stream/SJ/ADXT service has different framing,ownership and scheduling. No full equivalent body.
readBufEndGet | 1670E0 1670F8 | CVX min(count,size) then local count subtraction. Outbreak borrowed SJ consume/move accounting has callbacks,channel selection and two operations; no demonstrated same READ_BUF count-only owner.
setImageTag | 1CC740 | CVX macroblock texture upload strip with BITBLTBUF/TRXREG and direct submit; searched effect-movie DMA tag builder is compressed-IPU REF chain,not pixel upload. Overlay movie upload pipeline is separately documented in SYMBOLS_MOVIE_FLOW.md; no whole matching function.
vbrank_draw | 160B98 160BB8 | CVX fixed GS context2 textured sprite/global display rectangle and direct image submit; searched Outbreak frame-conversion/output and public-frame path use distinct ownership/geometry. No equivalent fixed-tag body.
videoDecMain | 1715F0 171D10 | CVX resets global output ring,calls decode loop,spins until picture count0 then stateEND; Outbreak request-driven owner/picture service. No matching worker lifecycle.
decBs0 | 148170 171D10 | CVX sceMpegGetPicture RGB32 loop with thread sleep/global dimensions. Outbreak native guest MPEG driver and optional original-IPU request service are different full pipelines; shared hardware does not identify this loop.
audioDecSendToIOP | 164A50 13EEE8 | CVX global SonyPCM ring/DMA/status-driven IOP fill; Outbreak selected-stream ADXT/RNA transport. No equivalent whole AudioDec state machine.
iopGetArea | 13ED28 164AF8 | CVX reserves UNIT_SIZE guard in circular SPU PCM IOP arena from hardware position. Outbreak deferred DTR-start/free-SJ and selected copy contracts use distinct fields/ownership, no equivalent pointer formula body demonstrated.
sendToIOP2area | 171BE0 | CVX truncates source length to total destination then2/3 DMA calls; closest two-span Outbreak171BE0 rejects insufficient total and uses memcpy. Shared packing shape is not same transfer/partial-copy contract.
sendToIOP | 138BE0 13EEE8 | CVX optional sound_flag duplicates512B channel halves in-place then blocking SIF DMA. Outbreak DTR/RNA service has different queue ownership and submission; no same in-place transform/body identified.
changeInputVolume | 13F038 13E000 | CVX writes two SPU block-volume params via sceSdRemote; Outbreak desired attenuation setter/table/command transport is a different control layer. No direct matching body.
DmaAddr | 1709A0 170B60 | Same0FFFFFFF physical mask occurs inline in inspected ring workers; no distinct complete Outbreak mask-only API owner proved. Inline arithmetic is not a new function mapping.
viBufModifyPts | 170B60 174448 | CVX24-byte timestamp ring overlap trim/count/head updates. Outbreak ring reset preserves24-byte timestamp metadata but nearest searched generic metadata-ring query uses a different layout/predicate. No complete same timestamp mutator found.
IsPtsInRegion | 174448 171160 | CVX circular signed remainder<len predicate; Outbreak generic ring interval search and resume in-region logic are related inline arithmetic,not a demonstrated same standalone function/ABI.
viBufPutTs | 170B60 174218 | CVX semaphore24-byte PTS/DTS/position/length ring admission. Outbreak reset fields and generic metadata append use distinct record layouts/ownership; no complete same24-byte timestamp publisher established.
voBufIncCount | 1706E0 170388 | CVX DI,tagFULL,count++,unconditionalEI; Outbreak private picture states and reference/publication counters use different records/guards. No same VoBuf/tag owner.
audioDecResume | 13EC50 13E000 | CVX mute,start looping SPU block DMA from saved pause position,unmute/statePLAY. Outbreak command desired-play setter+serializer does not perform equivalent synchronous volume/DMA sequence.
videoDecPutTs | 170B60 174218 | CVX local TimeStamp24 tuple from pointer-relative position then viBufPutTs. Outbreak generic metadata records differ; no connected same viBufPutTs producer/callee pair.
audioDecBeginPut | 164AF8 167680 | CVX returns SSHD-header+PCM writable spans in INIT,otherwise AudioDec ring free spans. Outbreak SJ selected-source copy/type2 ring has different header and format contracts; no exact body.
termAll | 15D1D0 1719F0 | CVX terminates decoder thread/stops CDstream/clears fixed469120B arena and SPU DMA. Outbreak CRI child/arena teardown and optional-IPU owner save/delete differ. No same global teardown body.
videoDecDelete | 1719F0 147CE8 | CVX viBufDelete then sceMpegDelete(globalowner). Outbreak IPU mode/reuse-dependent teardown differs; no one-to-one function identity.
audioDecDelete | 13F038 15D1D0 | CVX only changeInputVolume(0),return1. Outbreak attenuation desired-state setter/child teardown do not supply same direct SPU mute-only API.
GetAllWorkMemory | 15C210 15D048 | CVX fixed ADX_STREAM_BUFFER/Ps2_MOVIE partition addresses and graphics resets/prints. Outbreak tracked arena allocator/configurable decoder workspace. No shared complete layout function.
OutPutCdErrorCode | 169C10 148828 | CVX fixed optical-drive error-switch diagnostics; Outbreak structured movie error records/callback and MPEG prefix output differ. No same complete switch/label set found in searched movie error family.
videoCallback | 171880 171BE0 | Shared two-span copy component, but CVX packet wrap/timestamp publication/global callback+returnbool is not171880's contiguous-source/maincookie bridge. No complete same callback.
pcmCallback | 164AF8 165630 | CVX strips4bytes,assembles SSHD/audio ring bookkeeping; Outbreak ADXT copy/metadata pipeline differs. No same PCM packet parser/header count callback.
mpegError | 171818 148828 | CVX prints callback errMessage and returns1; Outbreak171818 copies8-byte error packet into globals/main and reports structuredFF000F40,148828 has owned MPEG-prefix output. Different packet/API/error ownership.
mpegTS | 170B60 174448 | CVX compensates hardware position and searches24-byte PTS/DTS ring,marks chosen timestamp absent and decrements count. Outbreak reset metadata/generic interval search do not establish this complete callback; no guessed timestamp units.
''')
    negative('ps2_sfd_mw.c','''
ps2mwPlyCreateSofdec | 15CC80 15C210 | CVX uppercases/mutates filename,opens CDstream directly,returns singleton-vtable handle. Outbreak creates CRI player from caller arena/configuration; filename start is later. No equivalent whole creation body.
mwPlyExecServer | 163880 171D10 | CVX synchronous readMpeg loop until output and direct GS draw; Outbreak bounded/reentry-gated multicomponent service with separate decode/presentation. No same complete server.
mwPlySetDispPos | 160B98 | CVX stores into singleton display rectangle. Outbreak frame-conversion context/public output controls use distinct object/geometry. No exact global storage owner established.
mwPlySetDispSize | 160BB8 | CVX stores singleton dimensions. Outbreak computed conversion descriptor/scaling does not supply equivalent global dimensions-only body.
ps2mwPlyStartFname | 15F0B8 15F270 | CVX initAll and filename-specific MV_016.PSS cancel button,not media read start itself. Outbreak validated player/source-start chain and object buffer preparation differ; filename policy is game-specific.
ps2mwPlyStop | 15D1D0 1719F0 | CVX termAll(globalSonyMPEG); Outbreak child/arena teardown and IPU reuse are different whole operations.
ps2mwPlyGetStat | 160060 | Both broad playback-state API, but CVX singletonrmi.iMovieState directload vs validated per-player delegated state. No equivalent complete state owner/enum.
ps2mwPlyGetTime | 1603B8 132160 | CVX numeratorPs2_vcount-startframe/denominator29; Outbreak delegated movie/ADXT sample-ratio clocks. No identical clock or counter units.
ps2mwPlyPause | 15F3F0 132E50 | CVX toggles bit2 in singleton controlword; Outbreak per-player/ADXT pause performs state/audio/clock choreography. No same complete bit-only pause owner.
ps2mwPlySetOutVol | 1604A0 13F038 | CVX calls direct SPU volume with32.8*(vol+999); Outbreak desired attenuation clamp/ADXT or movie controls. No same volume law/body.
ps2mwErrorStop | 148828 169C10 | CVX prints generic MWunsupported message and returns. Outbreak MPEG prefix/structured-error pathways differ; a shared printf is insufficient identity.
Setps2FuncTbl | 15CC80 | CVX installs one static singleton14-entry movie vtable. Outbreak CRI player constructor installs its own interfaces/dependencies. No identical table/body established.
''')
    negative('mwwrap.c','''
InitMwSystem | 1CC260 15E6A0 | CVX game mode0/2 then Sofdec-init wrapper plus playflag0. Outbreak shared movie initializer constructs different config/work state. Broad initialization role,not equivalent game globals.
ReinitMwSystem | 15E860 | CVX mode-gated empty-display-mode API; Outbreak global configuration mutation is different. No identical mode/field caller.
ExitMwSystem | 15EA00 | CVX game mode0/2 and MwMode=-1; Outbreak reference-counted CRI teardown,not same game-mode facade.
GetMwPlayTime | 1603B8 | CVX virtual GetTime on global MwPly; Outbreak validated per-handle API/delegation. No matching complete wrapper/caller ownership.
GetMwPlayTimeEx | 132458 | Both ratio-to-centiseconds concept; CVX uses its global movie vtable and doubledivision,OutbreakADXT float ratio with other clock source. No complete equivalent game facade.
CreateSfdHandle | 15CC80 15BF48 | CVX defaults320x240/3frames/3686400bps,syMalloc or borrowedwork,singleton create withfilename. Outbreak configurable tracked-arena creation/size query differ; shared API names do not imply same layout/workspace calculation.
PlayMwOpenMain | 15F0B8 15CC80 | CVX game flags/mode switch,optional Pause,virtualStartFname; Outbreak player creation/source-start ownership is split/different. No whole same game wrapper.
PlayMw2 | 15F0B8 | CVX argument-preserving facade to PlayMwOpenMain; no corresponding Outbreak facade was established independently of broad start role.
StopMw | 15D1D0 | CVX gameflag,virtualStop/Destroy,conditionalsyFree and flagclear; Outbreak player teardown owns tracked blocks/children and different lifetime gates.
GetMwStatus | 160060 | CVX globalvirtualGetStat; Outbreak per-handle validated state API. No full equivalent game-global facade.
PlayMwMain2 | 163880 | CVX completionstate3 optionalcallback/StopMw thenserver; Outbreak service controller has different callback/status/gate ownership. No whole shared game mainloop.
PlayMwMain | 163880 | CVX passesNULLcallback to PlayMwMain2; no equivalent wrapper pair established in Outbreak.
PauseMw | 132E50 | CVX globalvtablePause1; Outbreak ADXT per-handle pause is another subsystem. No original global movie-pause facade identity proved.
RestartMw | 132E50 | CVX globalvtablePause0; Outbreak audio pause0 is related operation,not same wrapper/ownership.
SetMwVolume | 1604A0 | CVX globalvirtualmovievolume; Outbreak per-player desired-volume API. Same broad control,not a complete counterpart.
GetSfdFadeRate | 15FFC0 | CVX forwards to empty mwPlyGetBright; Outbreak active-word accessor is not a fade-rate getter. No brightness implementation for comparison.
SetSfdDislpaySize | 160BB8 | CVX two globaldisplay setters; Outbreak conversion descriptors/public output geometry differ. No whole corresponding game wrapper.
''')
    return out


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--reference',type=Path,default=Path.home()/'AppData/Local/Temp/reo-recvx-crosscheck-20261104')
    ap.add_argument('--output',type=Path,default=ROOT/'build-function-index/recvx-movie-platform-complete-scope.json')
    args=ap.parse_args();ref=args.reference.resolve()
    universe=json.loads((ROOT/'build-function-index/recvx-complete-source-inventory.json').read_text(encoding='utf-8'));assert universe['reference_commit']==PIN
    manual=dispositions();elf=Elf(ROOT/'game_data/SLUS_207.65');assert elf.sha256==SHA
    db=sqlite3.connect(f'file:{ROOT/"build-function-index/index.sqlite"}?mode=ro',uri=True)
    notes={}
    for p in sorted((ROOT/'docs').glob('SYMBOLS*.md')):
        for i,line in enumerate(p.read_text(encoding='utf-8').splitlines(),1):
            m=re.match(r'^\| \[(?:main )?0x([\da-f]+)\]\(',line,re.I)
            if m:notes.setdefault(m[1].upper().lstrip('0'),[]).append(dict(path=p.relative_to(ROOT).as_posix(),line=i,text=line))
    overlay_id=next(x for x in json.loads((ROOT/'tools/function_index/overlay_identities.json').read_text(encoding='utf-8'))['images']if x['image']=='o0')
    overlay=(ROOT/'build-function-index/owned-overlays/o0.bin').read_bytes()
    assert hashlib.sha256(overlay).hexdigest()==overlay_id['imageSha256']
    audited={}
    def owned(address):
        if address not in audited:
            im,addr=address.split(':')if ':'in address else ('main',address)
            a=int(addr,16);row=db.execute("select end,source,proposed_name from functions where image=? and start=?",(im,a)).fetchone();assert row,address
            def read(pc,n):
                if im=='main':return elf.read(pc,n)
                assert im=='o0'
                off=pc-overlay_id['base'];assert off>=0
                return overlay[off:off+n]
            end,source,label=row;raw=read(a,end-a);assert raw is not None and len(raw)==end-a
            words={int(x,16):int(w,16)for x,w in re.findall(r'// 0x([\da-f]+): 0x([\da-f]+)\s+',(ROOT/source).read_text(encoding='utf-8'),re.I)if a<=int(x,16)<end}
            for pc,w in words.items():assert read(pc,4)==struct.pack('<I',w),(address,hex(pc))
            missing=[pc for pc in range(a,end,4)if pc not in words];assert all(read(pc,4)==b'\0'*4 for pc in missing),address
            audited[address]=dict(id=im+':'+addr,source=source,end_exclusive=f'{end:X}',label=label,sha256=hashlib.sha256(raw).hexdigest(),verified_words=len(words),omitted_zero_words=len(missing),notes=notes.get(address,[]))
        return audited[address]
    files=[];missing=[]
    for name in FILES:
        original=next(f for f in universe['files']if f['path']==BASE+name)
        raw=(ref/original['path']).read_bytes();assert hashlib.sha256(raw).hexdigest()==original['sha256']
        defs=function_records(raw.decode('utf-8-sig'));assert [(r['symbol'],r['start_line'],r['body_sha256'])for r in defs]==[(r['symbol'],r['start_line'],r['body_sha256'])for r in original['functions']]
        entries=[]
        for d in original['functions']:
            key=(name,d['symbol']);record=dict(reference_file=original['path'],reference_file_sha256=original['sha256'],**d)
            if d['implementation_shape']=='empty':record.update(status='source-no-implementation',outbreak_ids=[],comparison='Complete CVX body is empty; no equivalent Outbreak implementation inferred from public API spelling or adjacent stubs.')
            elif key in manual:record.update(manual[key])
            else:missing.append(key);continue
            record['outbreak_evidence']=[owned(a)for a in record['outbreak_ids']]
            record['searched_evidence']=[owned(a)for a in record.get('searched_candidates',[])]
            record['limitations']='Static source/body comparison only; negative findings scoped to listed owned subsystem/caller evidence. No target execution, parity, runtime reachability, new function credit or same-pipeline inference.'
            entries.append(record)
        files.append(dict(path=original['path'],sha256=original['sha256'],functions=entries))
    assert not missing,missing
    assert sum(len(f['functions'])for f in files)==85
    support=[]
    for name in ('include/ps2/veronica/prog/types.h','include/ps2/veronica/prog/ps2_MovieFunc.h'):
        raw=(ref/name).read_bytes();support.append(dict(path=name,sha256=hashlib.sha256(raw).hexdigest()))
    counts=Counter(r['status']for f in files for r in f['functions'])
    # Retain distinct SDK guard bodies as contrast evidence, never equivalent
    # unconditional-EI source matches.
    sdk_contrast=[owned(a)for a in ('113BA8','113C20')]
    overlay_contrast=[owned(a)for a in ('o0:379420','o0:379660','o0:379AF0','o0:379D80','o0:379ED0')]
    comparison_groups=[]
    for f in files:
        for r in f['functions']:
            if not r['outbreak_ids']:continue
            address=r['outbreak_ids'][0]
            note=owned(address)['notes'][0]['path'].removeprefix('docs/')
            comparison_groups.append(dict(notebook=note,cvx_file=f['path'],rows=[[address,r['symbol'],'related-different' if r['status']=='version-different' else 'supported-role',r['comparison']]]))
    result=dict(schema=1,reference_commit=PIN,outbreak_elf_sha256=SHA,files=files,support_headers=support,sdk_guard_contrast=sdk_contrast,overlay_pipeline_contrast=overlay_contrast,groups=comparison_groups,
        counts=dict(files=3,functions=85,statuses=dict(counts),owned_complete_intervals=len(audited),owned_verified_words=sum(r['verified_words']for r in audited.values())),
        all_reference_definitions_dispositioned=True,no_target_activity=True,notes='docs/recvx-crosscheck/MOVIE_PLATFORM_COMPLETE_SCOPE.md')
    args.output.parent.mkdir(parents=True,exist_ok=True);args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts'],indent=2))


if __name__=='__main__':main()
