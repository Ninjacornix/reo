"""Static transferred CVX platform scope: source status, ownership and owned comparisons."""
import collections
import hashlib
import json
import pathlib
import re
import sqlite3
import subprocess

from review_recvx_ninja_complete_scope import REF, PIN, definitions, implementation, mask
from index import Elf

NAMES=set('gcc_wrapper.c adxwrap.c dread.c pad.c padman.c vibman.c sync.c sbinit.c ps2_event.c ps2_sg_bup.c ps2_sg_maloc.c ps2_sg_pad.c ps2_sg_pdvib.c ps2_sg_sd.c ps2_sg_sycbl.c ps2_sg_sycfg.c ps2_sg_syhw.c ps2_sg_syrtc.c ps2_sg_sytmr.c ps2_snddrv.c ps2_sg_cache.c ps2_sg_uf.c ps2_sg_sybt.c'.split())
FAMILY={
 'gcc_wrapper.c':('compiler_adapter_missing_dependency','Compiler ABI wrapper; __floatdisf/__floatdidf/dpcmp implementation bodies are absent from this pinned source inventory. Wrapper arithmetic does not establish dependency rounding/NaN/ABI semantics.'),
 'adxwrap.c':('cvx_game_adx_integration','CVX AfsInfo[16]/AdxFInfo[8]/AdxTInfo[4], RDX_LNK partition17, fixed stream buffer, volume table, fade/pan and caller-managed slots wrap independently reviewed CRI APIs; no Outbreak game-stream layout alias.'),
 'dread.c':('cvx_game_asset_integration','CVX player/weapon buffers, ML_WORK/MN_WORK, Ninja relocation/skin/PVP textures, object arrays and allocation alignments; not an Outbreak actor/NBD layout.'),
 'pad.c':('cvx_game_input_policy','CVX sys demo playback, keytype remap, input transitions, analog emulation and title/fade/audio policy; distinct from a reusable controller-report decoder.'),
 'padman.c':('cvx_pad_policy_state','CVX four Pad/RepeatInfo records, six repeat keys and shared current-port/soft-reset flags; no admitted Outbreak game-input policy ABI.'),
 'vibman.c':('cvx_vibration_policy','CVX enable flag and port%6==2 policy wrap pdVibMx readiness/start/stop, including caller parameter mutation; no Outbreak vibration-policy alias.'),
 'sync.c':('cvx_game_frame_integration','CVX vblank/EOR counters, sound service, tray handling, event flags/timers, palette/fog/camera updates, pad-disconnect pause and soft reset; not a generic host timing or wait interface.'),
 'sbinit.c':('cvx_platform_lifecycle','CVX init/exit order combines interrupt mask, fixed heap, Ninja, peripheral, RTC and GD wrappers; no same Outbreak application startup/shutdown contract.'),
 'ps2_event.c':('cvx_authored_game_policy','Explicit CVX stage/room/camera/event-flag background-colour tables and Ninja back-colour publication; authored content policy has no eligible generic Outbreak function equivalent.'),
 'ps2_sg_bup.c':('cvx_memory_card_adapter','CVX backup API init retry/error mapping or registered callbacks; underlying sceMc device operations are separate, and empty/constant hooks do not provide missing backup semantics.'),
 'ps2_sg_maloc.c':('different_heap_layout','CVX static13,422,592-byte array with64-byte HM headers/singly-linked predecessor ownership and tracked free13,422,528 bytes, unlike Outbreak user-8 boundary tags, bins, coalescing and locks.'),
 'ps2_sg_pad.c':('different_controller_report_abi','CVX fixed scePadRead bytes, old libpad state/mode/pressure negotiation, one static PDS_PERIPHERAL and game button/repeat state; Outbreak libpad2 supplies variable reports plus40 field descriptors.'),
 'ps2_sg_pdvib.c':('cvx_vibration_backend','CVX old scePad actuator interface and PAD_ACT[20]/motor buffer at port0/slot0, local power/duration/fade semantics; no compatible Outbreak actuator protocol admitted.'),
 'ps2_sg_sd.c':('cvx_sound_bank_and_port_backend','CVX SND_WORK,20 memory blocks/40handle slots, MIDI/shot bank layouts and Sdr command protocol; distinct from CRI PS2RNA service90000200 and Outbreak game sound records.'),
 'ps2_snddrv.c':('different_sound_rpc_protocol','CVX binds SIF RPC clients0/1,128command queue,512byte serialized byte commands,16byte status RPC and own IOP SND_STATUS addresses. Shared SIF APIs do not establish CRI90000200 protocol identity.'),
 'ps2_sg_sycbl.c':('constant_platform_policy','Returns fixed NTSC cable enum, without cable detection; no Outbreak hardware-detection equivalent established.'),
 'ps2_sg_sycfg.c':('cvx_sound_configuration_state','CVX SoundMode scalar access/init/exit hooks; does not implement PS2 system settings persistence or an admitted Outbreak configuration layout.'),
 'ps2_sg_syhw.c':('empty_reference_body','Hardware init/finish source hook has no supplied operation.'),
 'ps2_sg_syrtc.c':('cvx_rtc_adapter','CVX RTC API hook or BCD calendar-output conversion; distinct read-failure/result/layout contracts must be retained.'),
 'ps2_sg_sytmr.c':('empty_reference_body','Timer count source body is empty; no returned tick value or Outbreak timer equivalent may be inferred.'),
 'ps2_sg_cache.c':('empty_reference_body','JPN cache-writeback API body is empty; cache instructions or equivalent Outbreak cache semantics are unavailable.'),
 'ps2_sg_uf.c':('empty_reference_body','JPN user-history/UF API source bodies are empty, including nonvoid definitions; no operational or return-value equivalence established.'),
 'ps2_sg_sybt.c':('constant_boot_identity_policy','Boot-ID adapter writes fixed nNo1/nAll2 and zero16-byte product, or returns0 forNULL; no retrieved boot/hardware identity or Outbreak record ABI established.'),
}
CASES={
 'gcc_wrapper.c:_f_ulltof':(['main:001113D0','main:0011F198'],'supported_shared_suboperation','CVX unsigned64 fallback converts (u>>1)|(u&1) then doubles. Outbreak11F198 uses the same high-bit unsigned-to-single adjustment around1113D0, then computes a reciprocal tick rate. CVX __floatdisf body is absent; neither whole output nor dependency ABI is proven equivalent.'),
 'gcc_wrapper.c:_d_ulltod':(['main:00111328'],'related_different_contract','CVX unsigned64 wrapper delegates to absent __floatdidf and uses a jammed-half/double fallback; Outbreak111328 converts signed64 by two software-double signed32 parts. Different domain/rounding path; no whole-function identity.'),
 'gcc_wrapper.c:_d_utod':(['main:00111328'],'related_different_contract','CVX unsigned32 forwards to its unsigned64 wrapper and unavailable __floatdidf; Outbreak111328 is signed64 conversion with its own split-parts arithmetic, not the same adapter.'),
 'ps2_sg_maloc.c:syFree':(['main:001058D8'],'related_different_contract','CVX searches predecessor whose next header+64 equals pointer and merges next Total_size into predecessor; Outbreak header=user-8, neighboring boundary tags/doubly linked bins, recursive lock and optional trim. NULL-return role alone does not equate allocators.'),
 'ps2_sg_maloc.c:syMalloc':(['main:00106D18'],'related_different_contract','CVX aligns size to64 and splits its fixed HM list; Outbreak accepts requested alignment, delegates allocation, splits and frees boundary-tag fragments. Different object lifetime/layout/accounting and locking; not interchangeable heaps.'),
 'ps2_sg_syrtc.c:syRtcGetDate':(['main:001C18E0','main:001C1900','o6:00724050','o6:007240F8'],'supported_shared_suboperation','Same unsigned-byte decimal(nibbleHi*10+nibbleLo) and clock bytes7/6/5/3/2/1. CVX ignores sceCdReadClock return, writes year+2000/calendar fields/dayofweek0/ageofmoon0 and returns clock.stat. Outbreako6 checks read return/status then emits epoch-relative seconds; main1C1900 only rewrites six bytes in place. Whole outputs/error paths differ.'),
 'ps2_sg_pad.c:pdGetPeripheral':(['main:001804D8','main:001807C0'],'related_different_contract','CVX reads old fixed scePadRead offsets into shared static PDS_PERIPHERAL and uses system-counter cache. Outbreak libpad2 reader copies variable payload and rebuilds enabled one/eight-bit descriptors; no shared report or host controller ABI.'),
 'ps2_sg_pad.c:Ps2_pad_read':(['main:001804D8','main:001807C0'],'related_different_contract','CVX explicit old-libpad mode/actuator/pressure negotiation, fixed-byte inversion and Pad_set repeat policy differ from Outbreak libpad2 variable report/descriptors. Neither replaces the launcher controller path.'),
}
DETAIL={
 'syMallocInit':'Ignores heap/size arguments and binds fixed static storage; initial tracked size13,422,528, not exactly13MiB.',
 'syMallocStat':'Scans HM list Total_size-Use_size and publishes total-tracked/max-gap words; no boundary-tag arena statistic identity.',
 'syBtGetBootSystemID':'NULL0; otherwise nNo=1,nAll=2,zero16productbytes,return1. No actual platform ID query.',
 'buInit':'Up to10 sceMcInit attempts; invokes callback on0; -120/-121 or exhausted retries return-256. No backup I/O performed by this body.',
 'pdVibMxStart':'Finds first free of20 PAD_ACT records, setsbe_flag3, maps power to170+power/255 and time to9/6/4 by flag; no explicit success return.',
 'Ps2_pad_actuater':'Services only first19 PAD_ACT records, aggregates motor max then scePadSetActDirect(0,0); this local19/20 distinction is retained, not generalized.',
 'Ps2_pad_act_all_stop':'Clears20 PAD_ACT be_flag fields usingdo-while from19.',
 'pdGetPeripheralInfo':'Ignores port and queries0/0; debounces state and requires mode7/pressure capability before reporting type1.',
 'Pad_set':'Reads fixed button/axis/pressure bytes; computes push/release and two call-count repeat schedules; axis-threshold button merge uses previous saved axis fields before refreshing current bytes.',
 'SdrInit':'Binds service0/1, creates send/get semaphores, polls state18/19, copies64-byte IOP address data, initializes eight header/sequence address regions; not CRI90000200.',
 'sdr_initDev':'Up to1024 bind attempts with alarm/sleep delay; negative bind/delay-1, loop exhaustion still returns0 even without demonstrated server pointer.',
 'SdrSendReq':'Consumes ring until formatter fills512-byte buffer; packs/aligned RPC toclient0, callback signals semaphore, asynchronous flag tracks queued send. Distinct from a proven game-frame progress boundary.',
 'SdrGetState':'Send then up to100000 nonblocking receive polls; timeout signals semaphore and returnslastret. Counts are iterations, not milliseconds.',
 'sdSysSetSlotMax':'Forces10 MIDI slots regardless midi_slot_max, allocates shot/PSTM partitions within40 total handle records; no standard API slot-count equivalence.',
 'sdLibInit':'Ignores suppliedwork/capacities, sets init flag, clears20x16 memoryblock words and six SE state masks.',
 'sdDrvInit':'CVX Sdr/sceSd initialization, fixed IOP heaps12288/2048/327696 and reverb defaults; negative first allocations return success enum, last failure spins. No Outbreak policy inference.',
 'sndr_trans_func':'CVX sequence/program/shot transfer state machine, DMA completion waits, header checksums and retry,49152-byte chunking with alternating IOP area+204800 and callback. No same Outbreak bank/transfer ABI.',
 'sdMultiUnitDownload':'Downloads shot bank0 then sequencebank1 in pollingloops, rewrites handle source fields; concrete CVX unit-image format, not universal sound loader.',
 'Volume_Control':'Falling branch assigns dvol; rising branch assigns fieldvol and later returns dvol without assignment in visible source. Preserve this source limitation; do not transplant as a proven fade implementation.',
 'SetPanAdx2':'Only stores AdxTInfo[slot].Pan; no ADXT_SetOutPan in this supplied body.',
 'OpenAfsIsoFile':'Special .rdx names uppercase/match authored rdx_files then partition17; other names get backslash prefix. Slot exhaustion/-1 and filename extent are not locally guarded.',
 'CreatePartitionEx':'CVX named-partition load/poll then hardcoded partition17 RDX_LNK.AFS; error path still marks entered named partitionflag1. No full CRI API equivalent.',
 'GetAdxPlayTime':'Gets samplecount/rate and returns(double count/rate)*100; no local zero-rateguard. Not milliseconds or an Outbreak wallclock identity.',
 'RequestAdxFadeFunction2':'Converts timer through integer100/30/6/10 arithmetic then divides2, clamps zerocountto1, chooses targetvolume and speed; CVX manager-call counts, not generictime.',
 'bhControlVSync':'Calls sound sync, handles tray/titleexit, updates60-call frame counts and selectedgameeventtimers. No Outbreak clock/logic-update equivalence.',
 'bhControlEOR':'CVX paletteupload,controller,backcolourandfog/camera state aftermanytaskflag gates; not an empty renderer callback.',
}

def audit_owned(keys):
    sha=lambda b:hashlib.sha256(b).hexdigest()
    identity=json.loads(pathlib.Path('tools/function_index/overlay_identities.json').read_text())
    ep=pathlib.Path('game_data/SLUS_207.65');assert sha(ep.read_bytes())==identity['elf_sha256'];elf=Elf(str(ep))
    images={}
    for im in identity['images']:
        if any(key.startswith(im['image']+':') for key in keys):
            raw=pathlib.Path('build-function-index/owned-overlays/'+im['image']+'.bin').read_bytes();assert sha(raw)==im['imageSha256']
            images[im['image']]=(im['base'],raw)
    db=sqlite3.connect('file:build-function-index/index.sqlite?mode=ro',uri=True);db.row_factory=sqlite3.Row;rows=[]
    for key in sorted(keys):
        image,addr=key.split(':');start=int(addr,16);f=db.execute('SELECT * FROM functions WHERE image=? AND start=?',(image,start)).fetchone();assert f
        p=pathlib.Path(f['source']);words={}
        for m in re.finditer(r'// 0x([\da-f]+): 0x([\da-f]+)\s+',p.read_text(),re.I):
            pc,word=int(m[1],16),int(m[2],16)
            if start<=pc<f['end']:assert pc not in words or words[pc]==word;words[pc]=word
        zero=0
        for pc in range(start,f['end'],4):
            raw=elf.read(pc,4) if image=='main' else images[image][1][pc-images[image][0]:pc-images[image][0]+4]
            assert raw is not None and len(raw)==4
            word=int.from_bytes(raw,'little')
            if pc in words:assert words[pc]==word,(key,hex(pc))
            else:assert word==0,(key,hex(pc));zero+=1
        rows.append({'id':key,'source':f['source'],'source_sha256':sha(p.read_bytes()),'start':start,'end':f['end'],'verified_comments':len(words),'omitted_zero_words':zero})
    return {'elf_sha256':identity['elf_sha256'],'complete_catalogue_bodies':rows,'verified_comments':sum(r['verified_comments'] for r in rows),
            'omitted_zero_words':sum(r['omitted_zero_words'] for r in rows),'conflicts':0,'omitted_nonzero_words':0}

def main():
    assert subprocess.check_output(['git','-C',str(REF),'rev-parse','HEAD'],text=True).strip()==PIN
    assert not subprocess.check_output(['git','-C',str(REF),'status','--porcelain','--untracked-files=no'],text=True).strip()
    shared=json.loads(pathlib.Path('build-function-index/recvx-complete-source-inventory.json').read_text());files=[];rows=[]
    sha=lambda b:hashlib.sha256(b).hexdigest()
    for f in shared['files']:
        name=pathlib.Path(f['path']).name
        if name not in NAMES:continue
        raw=(REF/f['path']).read_bytes();source=raw.decode();assert source.isascii()
        local=[]
        for symbol,a,b,z in definitions(source):
            body=source[b:z];clean=mask(body);status=implementation(body);key=name+':'+symbol
            verdict,reason=FAMILY[name];ids=[];depth='complete_source_body_and_ownership_boundary'
            if status=='empty':verdict='empty_reference_body';reason='Empty reference body supplies no operation or defined nonvoid result; no equivalent original no-op inferred.'
            if key in CASES:ids,verdict,reason=CASES[key];depth='direct_full_body_contract'
            if symbol in DETAIL:reason+=' '+DETAIL[symbol]
            calls=sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',clean))-{'if','for','while','switch','sizeof','return','volatile','asm','void','float','int'})
            detail='empty_reference_body' if status=='empty' else ('inline_ee_vu_source' if re.search(r'\basm\b',clean) else 'c_operations')
            if re.fullmatch(r'\{\s*return\s+(?:0|1|SYE_CBL_NTSC)\s*;\s*\}',clean):detail='constant_return_only';verdict='constant_reference_policy'
            if symbol in ('sdMidiSetFxLev','sdShotSetFxLev','sdSndClearFxPrg','sdSndSetFxPrg','sdMemBlkSetTransferMode','sdSysFinish','pdVibMxSetStopTime'):
                detail='init_or_constant_status_without_requested_operation';reason+=' Supplied body does not perform the operation implied by its name; only init/status/constant response is available.'
            if name=='gcc_wrapper.c':detail='adapter_with_unavailable_dependency'
            row={'id':f['path']+':'+symbol,'file':f['path'],'symbol':symbol,'signature_start':a,'body_start':b,'end_exclusive':z,
              'line_start':source.count('\n',0,a)+1,'body_line_start':source.count('\n',0,b)+1,'line_end':source.count('\n',0,z)+1,
              'signature':re.sub(r'\s+',' ',source[a:b]).strip(),'source_sha256':sha(raw),'definition_sha256':sha(source[a:z].encode()),'body_sha256':sha(body.encode()),
              'implementation_status':status,'implementation_detail':detail,'disposition':verdict,'reason':reason,'comparison_depth':depth,'outbreak_comparisons':ids,
              'source_facts':{'call_or_macro_tokens':calls,'member_expressions':sorted(set(re.findall(r'\b[A-Za-z_]\w*(?:(?:->|\.)[A-Za-z_]\w*)+',clean)))},
              'evidence':[f'https://github.com/AshfordFamily/recvx-decomp/blob/{PIN}/{f["path"]}#L{source.count(chr(10),0,a)+1}']}
            local.append(row);rows.append(row)
        assert {(r['symbol'],r['line_start'],r['body_sha256']) for r in local}=={(r['symbol'],r['start_line'],r['body_sha256']) for r in f['functions']}
        assert not f['assembly_placeholders']
        files.append({'file':f['path'],'sha256':sha(raw),'bytes':len(raw),'definitions':len(local)})
    assert len(files)==23 and len(rows)==193
    assert not {'dpcmp','__floatdisf','__floatdidf'} & {r['symbol'] for f in shared['files'] for r in f['functions']}
    result={'schema':1,'kind':'static-source-contract-inventory','reference_commit':PIN,'files':files,'definitions':rows,
      'independent_inventory_reconciliation':{'definitions':len(rows),'missing':0,'extra':0,'different_body_hashes':0,'assembly_placeholders':0},
      'counts':{'files':len(files),'definitions':len(rows),'implementation':dict(collections.Counter(r['implementation_status'] for r in rows)),
                'disposition':dict(collections.Counter(r['disposition'] for r in rows))},
      'unavailable_dependency_bodies':['dpcmp','__floatdisf','__floatdidf'],
      'outbreak_evidence':audit_owned({key for r in rows for key in r['outbreak_comparisons']})}
    pathlib.Path('build-function-index/recvx-platform-complete-scope.json').write_text(json.dumps(result,indent=2)+'\n')
    write_note(result)
    print(json.dumps({'counts':result['counts'],'word_audit':result['outbreak_evidence']['verified_comments'],'omitted_zero':result['outbreak_evidence']['omitted_zero_words']}))

def write_note(result):
    counts=result['counts'];audit=result['outbreak_evidence']
    lines=['# Complete transferred platform reference scope','',
      f'Static review,2026-11-05. Pinned CVX reference `{PIN}`. **193 complete C definitions across23 files** have exact source/body bounds and hashes, implementation status and individual applicability dispositions, including the two newly admitted `ps2_sg_sybt.c` definitions. Independent source-inventory reconciliation is193/193 with zero extras, omissions or differing body hashes; no assembly placeholders occur inside this scope. No game, build, target execution, attachment or live-memory inspection occurred.','',
      'All available bodies were read, including complete sound queue/serialization/RPC and transfer/server branches. The local machine ledger is `build-function-index/recvx-platform-complete-scope.json`, generated by [the static review helper](../../tools/function_index/review_recvx_platform_complete_scope.py). It retains byte/line bounds, raw source/definition/body hashes, signatures, call/member evidence, implementation details, every reason and image-qualified Outbreak comparison targets. These are dispositions, not original-name aliases or replacement approvals.','',
      '## Results and useful boundaries','',
      '- **RTC:** CVX `syRtcGetDate` and Outbreak main`0x1C18E0`/`0x1C1900`,o6`0x724050`/`0x7240F8` share decimal high/low-nibble interpretation and six clock-byte positions7/6/5/3/2/1. CVX writes calendar fields/year+2000,zero weekday/moon and returns clock.stat, while ignoring `sceCdReadClock` return. Outbreak o6 rejects read failure/nonzero status then returns epoch-relative seconds. Shared BCD arithmetic does not make the APIs interchangeable.',
      '- **Compiler helpers:** CVX unsigned64-to-single fallback `(u>>1)|(u&1)` followed by conversion/doubling is also visible inside Outbreak`0x11F198`. But that Outbreak owner computes a reciprocal tick rate and calls its own signed64 converter. CVX `__floatdisf`, `__floatdidf` and `dpcmp` bodies are absent from the pinned C/assembly source inventory; six comparison wrappers cannot establish NaN or underlying double-comparison semantics.',
      '- **Heap:** CVX uses static13,422,592-byte storage,64-byte HM headers, singly-linked predecessor search and initial tracked free13,422,528. It ignores `syMallocInit` supplied heap/size. Outbreak`0x1058D8`/`0x106D18` use user-8 boundary tags, bins, neighbor coalescing, requested alignment, locks and optional trimming. No allocator version or heap interoperability was inferred.',
      '- **Controller/vibration:** CVX uses fixed old `scePadRead` byte offsets, port0/slot0 negotiation, static peripheral cache and game repeat/key policy. Outbreak libpad2`0x1804D8`/`0x1807C0` copy variable report payloads and interpret descriptor-selected one/eight-bit fields. CVX vibration owns20 PAD_ACT records, but the active service visits19 while all-stop clears20; this is preserved as local source behaviour, not transplanted into Outbreak.',
      '- **Sound protocol:** CVX Sdr binds services0/1, with128 command entries,512-byte formatter and own status/IOP addresses. Its sound-bank layer adds20 memoryblock handles,40 sound slots, forced10 MIDI slots, checksums,49152-byte transfer chunks and game port/volume/fade policy. Outbreak CRI PS2RNA/SJRMT service90000200 is a different admitted protocol. Shared SIF/ADXT calls do not equate these backends.',
      '- **Game integrations:** `adxwrap`, `dread`, `pad`, `ps2_event` and `sync` use concrete CVX stream arrays/RDX partition17, player/weapon model buffers, demo controls, authored stage/room/camera colour tables, task/event flags and vblank/EOR policy. These meaningful game wrappers were explicitly classified rather than treated as generic SDK implementations.',
      '- **Unavailable or narrow hooks:** empty JPN cache/UF and hardware/timer functions provide no operational semantics. Constant-only backup/cable/RTC-init responses and init-gated sound FX/finish/transfer-mode stubs are distinct from full implementations. A name implying work is not proof the body performs it. The visible `Volume_Control` rising branch also leaves its returned local unassigned; this source limitation is recorded without asserting that Outbreak has the same defect.','',
      f'The focused audit validates **{len(audit["complete_catalogue_bodies"])} complete owned Outbreak bodies/{audit["verified_comments"]} original instruction comments**, with{audit["omitted_zero_words"]} omitted zero words,zero conflicts and zero omitted nonzero words. No canonical Outbreak mapping correction was demonstrated. See [boundary-tag heap](../SYMBOLS_LIBC_BOUNDARY_TAG_HEAP.md), [libpad2 reports](../SYMBOLS_LIBPAD2_REPORT_BUFFERS_AND_FIELDS.md), [CRI owned IOP server](../SYMBOLS_CRI_SJRMT_OWNED_IOP_SERVER_CONTRACTS.md) and [prior engine comparison](ENGINE_SECOND_PASS.md).','',
      '## Implementation inventory','',
      '`implemented` means nonempty operations exist; narrower detail marks constant/status-only bodies and unavailable compiler dependencies. `empty` is not a recovered no-op symbol. Full comparison is claimed only for rows with concrete candidate contracts; other rows state source ownership or unavailable semantics. No inferred host ABI, runtime performance or game timing equivalence follows.','',
      '| File | Definitions/nonempty/empty/declarations-only | Raw source SHA-256 |','| --- | --- | --- |']
    for f in result['files']:
        rows=[r for r in result['definitions'] if r['file']==f['file']];c=collections.Counter(r['implementation_status'] for r in rows)
        lines.append(f'| `{f["file"]}` | {len(rows)}/{c["implemented"]}/{c["empty"]}/{c["declarations_only"]} | `{f["sha256"]}` |')
    lines+=['','## Every-symbol ledger','',
      'Each source link is pinned. Signature-to-closing-brace lines and complete body hashes are shown; exact UTF-8 byte bounds and definition hashes are in the JSON. A comparison target identifies an investigated original body, never a transferred symbol.','']
    for f in result['files']:
        lines+=['### '+f['file'],'','| Symbol/source lines | Implementation/detail | Disposition and individual reason | Complete body SHA-256 |','| --- | --- | --- | --- |']
        for r in result['definitions']:
            if r['file']!=f['file']:continue
            ids=' '.join('`'+i+'`' for i in r['outbreak_comparisons']);reason=r['reason'].replace('|','\\|')
            calls=', '.join(r['source_facts']['call_or_macro_tokens'])
            if calls:reason+=' Direct source calls/macros: `'+calls+'`.'
            lines.append(f'| [{r["symbol"]}]({r["evidence"][0]}) {r["line_start"]}–{r["line_end"]} | {r["implementation_status"]}; {r["implementation_detail"]} | `{r["disposition"]}` {ids}. {reason} | `{r["body_sha256"]}` |')
        lines.append('')
    text='\n'.join(lines)+'\n'
    for old,new in [('review,2026','review, 2026'),('across23','across 23'),('is193/193','is 193/193'),('main`','main `'),(',o6`',', o6 `'),('Outbreak`','Outbreak `'),('positions7/6/5/3/2/1','positions 7/6/5/3/2/1'),('year+2000,zero','year+2000, zero'),('static13,422,592','static 13,422,592'),('storage,64-byte','storage, 64-byte'),('free13,422,528','free 13,422,528'),('owns20','owns 20'),('visits19','visits 19'),('clears20','clears 20'),('services0/1','services 0/1'),('with128','with 128'),('entries,512','entries, 512'),('adds20','adds 20'),('handles,40','handles, 40'),('forced10','forced 10'),('checksums,49152','checksums, 49152'),('partition17','partition 17'),('with'+str(audit['omitted_zero_words']),'with '+str(audit['omitted_zero_words'])),('words,zero','words, zero')]:text=text.replace(old,new)
    pathlib.Path('docs/recvx-crosscheck/PLATFORM_COMPLETE_SCOPE.md').write_text(text,encoding='utf-8')

if __name__=='__main__':main()
