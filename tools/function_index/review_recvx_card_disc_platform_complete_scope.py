#!/usr/bin/env python3
"""Static applicability/contract ledger for all120 transferred card/GD bodies.

Reads original words and pinned source as data; no game, guest execution,
build, card/file operation, process attachment, network or shared-index write.
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

ROOT=Path(__file__).resolve().parents[2]
REL='ps2/veronica/prog/'
FILES=['ps2_MemoryCard..c','ps2_McSaveFile.c','ps2_sg_gd.c','gdlib.c']
EXPECTED=[55,44,13,8]

# These compare bounded source/algorithm/platform concepts, not recovered
# original API identities or one-to-one function mappings.
COMPARE={
'ps2_MemoryCard..c':{
'MemoryCardGetSum':([0x1C56A0,0x1C5760,0x13CD38,0x13D6D8], 'CVX sums variable-length unsigned bytes into unsigned32 without mutation. Owned save codec sums fixed1FE5C plaintext halfwords modulo65536 and XOR-transforms them; not equivalent. The LSC filename checksum shares only byte-sum algebra over strlen bytes, not save-format identity.'),
'CheckMcSelectPortInfoType':([0x1BF840,0x181060,0x181D28], 'Related card-information query only. CVX retries sceMcGetInfo/synchronous Sync up to5 times; owned uses libmc2 device handles, queued info and3-retry availability classification. No sceMc implementation or identical result enum is present in the reference.'),
'CheckMemoryCardInfoFree':([0x1BF840,0x181060,0x181D28], 'Both distinguish asynchronous device-info completion from a stored free count. CVX subtracts2/clamps0 and uses5 retries; owned availability/error/free-capacity policy differs. Do not import the reserve2 policy.'),
'CheckMcSelectPortInfoState':([0x1BF840,0x181060], 'CVX returns whether raw card type equals2 after5 synchronous attempts. Owned availability uses info.word0==2 plus other validity fields/error classes; common raw test does not identify the wrappers or whole enums.'),
'CheckMemoryCardInfoUnformat':([0x1BF840,0x181060], 'CVX explicitly queries SDK format status accepting completion0/-1/-2; owned queued info/availability uses a different packet/error classifier. No format-state enum equivalence or command3/4 identity follows.'),
'GetMemoryCardDir':([0x1C02A0,0x181560,0x181D28], 'Related directory listing. CVX5 retries then blocking sceMcSync, returns count or-1/-2. Owned queues caller output/count pointers and polls incrementally with different admission/error mapping.'),
'MakeMemoryCardDir':([0x1BFC00,0x181650], 'Both separate mkdir submission/completion. CVX SDK path helper returns1/0, whereas owned handles existing-directory code11 and optional attribute update. Not the same backend or status convention.'),
'MemoryCardFormat':([0x1BFF70,0x180F60], 'CVX calls sceMcFormat and uses its own0/1/-1 substate protocol. Owned selected command3 is only numerically established; this source does not bind libmc2 command3 to sceMcFormat. No alias or missing operation purpose is admitted.'),
'MemoryCardFileOpen':([0x1BFB40,0x181230,0x181D28], 'Architectural contrast: CVX exposes async SDK descriptor-open state; owned read producer uses a path/device-handle request. CVX accepts nonnegative completion but does not assign that result to lOpenFileNumber in this body. No direct open counterpart is proved.'),
'MemoryCardFileClose':([0x1BFB40,0x181D28], 'CVX closes a stored SDK descriptor and normalizes completion to1; owned card read backend has no corresponding public client-descriptor close phase. Common queue/complete distinction only.'),
'MemoryCardFileRead':([0x1BFB40,0x181230,0x181D28], 'Both layered wrappers can accept nonnegative completion without requiring returned byte count==requested count. CVX uses descriptor/sceMcRead and0/1/-1 states; owned path request and outer metadata preflight differ. No full-read guarantee from sign alone.'),
'MemoryCardFileWrite':([0x1BFE00,0x181310,0x181D28], 'Common acceptance/completion and retained-buffer lifetime boundary; both helpers use sign rather than exact completed length. SDK descriptor state and owned libmc2 path operation are distinct APIs; no transaction guarantee.'),
},
'ps2_McSaveFile.c':{
'mcCreateIconInit':([0x1C13C0], 'Shared PS2 icon.sys schema:6 line-break offset,C transparency,10 background colors,50 light directions,80 light colors,B0 ambient,C0 title,104/144/184 view/copy/delete names. CVX clears full3C4 bytes and writes PS2D/static title/defaults; owned mutates borrowed asset/manifest fields, does not clear/write signature, and uses different constants.'),
'mcReadIconData':([0x1C58C0,0x1290C8,0x129C08,0x1297A0,0x129D48,0x129350], 'Both acquire an asset, read sector-rounded data and close, but CVX GD is a synchronous custom disc shim returning byte size; owned retries ADXF open, uses sector size and polls exact status3 without pumping in getter. Different errors/return values and capacity preconditions.'),
'mcGetFreeCapacitySize':([0x1C12C0], 'Narrow shared arithmetic: nonnegative byte sizes round up by1024 before adding directory overhead. CVX hardcodes15 saves+config+icon metadata+icon data+11; owned sums5 enabled manifest sizes and(count+1)/2+2 with guest signed rounding. Totals and file schema are not interchangeable.'),
},
'ps2_sg_gd.c':{
'gdFsGetDirInfo':([0x139828,0x13A910], 'Common ASCII uppercase/name lookup concept only. CVX looks up its custom indexed directory and copies{fad,size,flag}; owned DVCI adds slash folding/prefix/cache registration and copies its own metadata pair. No GDFS layout/API identity.'),
'gdFsOpen':([0x135930,0x139A50,0x1399F8], 'Common pooled-handle acquisition only. CVX first-free custom GD record is filled from CVX indexed directory; owned CVFS wrapper/device resolver and DVCI last-free backend pool are different layers/record sizes. Never alias these as one Open implementation.'),
'gdFsRead':([0x18D820,0x139D00], 'CVX repeatedly calls sceCdRead absolute sectors, blocking sync and retrying until error0. Owned resident reader opens a named fd and attempts byte read, while DVCI139D00 admits a request. Sector/byte units, completion, retry and return conventions differ.'),
},
'gdlib.c':{
'GetFileSize':([0x18DAB0,0x135FB8], 'Same size-query concept with missing/zero ambiguity, but CVX queries a custom directory table; owned reads device metadata or opens/seeks/closes and can retain negative seek errors. No shared implementation or GD alias.'),
'ReadFileEx':([0x18D820,0x1C58C0], 'Related whole-file loading only. CVX obtains custom GD byte length then requests ceil(size/2048) sectors and returns0; owned resident18D820 accepts explicit bytes and returns1 after attempted read, while card asset1C58C0 uses ADXF sector polling. Do not equate success codes/completion.'),
}}

STUBS={
'ps2_MemoryCard..c':{'MemoryCardUnFormat':'return0 without SDK operation','DeleteMemoryCard':'return0 without SDK operation'},
'ps2_sg_gd.c':{'gdFsGetDrvStat':'return2 without drive query','gdFsReqDrvStat':'return0 without drive-status request','gdFsSetDir':'return0 without directory mutation','gdFsLoadDir':'return0 without directory loading','gdFsEntryErrFuncAll':'empty error-registration body'},
}
UNMATCHED={
'ps2_MemoryCard..c':{'ChangeMemoryCardDir': 'Full CVX five-retry sceMcChdir wrapper inspected. Owned libmc2 path/device-request notes and profile path builders supply no demonstrated client working-directory counterpart; platform implementation absent.'},
'ps2_sg_gd.c':{
'gdFsClose':'CVX clears used/fad/fsize/fsctsize in a custom GD handle. Owned CVFS Close calls backend then clears wrapper; simple record clearing is not a file-close identity.',
'gdFsCreateDirhn':'Returns current global directory and ignores arguments; no matched owned GD directory-handle factory established.',
'gdFsFinish':'Only calls sceCdInit(EXIT); no matching owned GD shutdown facade established in resident disc/CRI notes. SDK implementation is not supplied here.',
'gdFsGetFileSize':'Custom handle field/output-bool getter; no same-layout owned GDFS object. Generic field read is insufficient to establish identity.',
},
'gdlib.c':{
'InitGdSystem':'CVX-specific allocator/workspace/table/GD setup with14 handles and max128 outer attempts; underlying init contains unbounded waits. No matching owned facade after resident/CRI loader review.',
'InitGdSystemEx':'Sets CVX MaxDirectoryEntry then invokes its own setup; no matching owned directory-capacity facade established.',
'ExitGdSystem':'Frees CVX directory/work buffers then GD shutdown; owned CRI/reference and resident file lifetimes differ, no one-to-one facade.',
}}

def sha(data):return hashlib.sha256(data).hexdigest()


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference',type=Path,default=Path('C:/Users/Ninjacornix/AppData/Local/Temp/reo-recvx-crosscheck-20261104'))
    parser.add_argument('--out',type=Path,default=ROOT/'build-function-index/recvx-card-disc-platform-complete-scope.json')
    args=parser.parse_args();ref=args.reference.resolve()
    git=lambda *a:subprocess.check_output(['git','-C',str(ref),*a],text=True,encoding='utf-8').strip()
    assert git('rev-parse','HEAD')==PIN and not git('status','--porcelain','--untracked-files=no')
    corpus=json.loads((ROOT/'build-function-index/recvx-complete-source-inventory.json').read_text())
    assert corpus['reference_commit']==PIN
    inventory={f['path']:f for f in corpus['files']}
    defined={r['symbol']for f in corpus['files']for r in f['functions']}
    notes=defaultdict(list)
    for p in sorted((ROOT/'docs').glob('SYMBOLS*.md')):
        for line_no,line in enumerate(p.read_text(encoding='utf-8').splitlines(),1):
            m=re.match(r'^\| \[0x([0-9a-f]+)\]\(([^)]+)\)\s*\|\s*`([^`]+)`\s*\|\s*([^|]+)\|\s*(.*?)\s*\|$',line,re.I)
            if m:notes[int(m[1],16)].append(dict(notebook=p.name,line=line_no,label=m[3],contract=m[5],sha256=sha(p.read_bytes())))
    elf=Elf(ROOT/'game_data/SLUS_207.65');db=sqlite3.connect('file:'+(ROOT/'build-function-index/index.sqlite').as_posix()+'?mode=ro',uri=True);db.row_factory=sqlite3.Row
    evidence={}
    def audit(address):
        if address in evidence:return 'main:'+hex(address)
        r=db.execute('select * from functions where image=? and start=?',('main',address)).fetchone();assert r and r['source']
        raw=elf.read(address,r['end']-address);comments={int(m[1],16):int(m[2],16)for m in re.finditer(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s',(ROOT/r['source']).read_text(),re.I)if address<=int(m[1],16)<r['end']}
        for pc in range(address,r['end'],4):
            w=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:assert comments[pc]==w,hex(pc)
            else:assert w==0,('omitted nonzero',hex(pc))
        assert notes[address]
        evidence[address]=dict(id='main:'+hex(address),source=r['source'],end_exclusive=hex(r['end']),sha256=sha(raw),instruction_comments=len(comments),omitted_zero_words=len(raw)//4-len(comments),notes=notes[address])
        return evidence[address]['id']
    files=[];all_keys=[];api_calls=set()
    for filename,total in zip(FILES,EXPECTED):
        path='src/'+REL+filename;raw=(ref/path).read_bytes();text=raw.decode('utf-8-sig',errors='replace');records=function_records(text)
        assert len(records)==total and sha(raw)==inventory[path]['sha256'] and not inventory[path]['assembly_placeholders']
        assert [(r['symbol'],r['start_line'],r['body_sha256'])for r in records]==[(r['symbol'],r['start_line'],r['body_sha256'])for r in inventory[path]['functions']]
        funcs=[];raw_lines=raw.splitlines(keepends=True)
        for r in records:
            name=r['symbol'];ids=[]
            calls=sorted(set(re.findall(r'\b([A-Za-z_]\w*)\s*\(',r['masked_body']))-{'if','for','while','switch','sizeof','asm'})
            apis=[c for c in calls if c.startswith(('sceMc','sceCd'))];api_calls.update(apis)
            if name in STUBS.get(filename,{}):
                disposition='source-unimplemented-stub';comparison=STUBS[filename][name];boundary='Full source body; no operation implementation follows from constant return/empty hook.'
                assert r['implementation_shape']=='empty' or re.fullmatch(r'\s*return\s+[02]\s*;\s*',r['masked_body'])
            elif name in COMPARE.get(filename,{}):
                disposition='compared-bounded-concept-or-algorithm';addresses,comparison=COMPARE[filename][name];ids=[audit(a)for a in addresses];boundary='Complete reference body versus the listed original words/authoritative typed contracts; no one-to-one API identity admitted.'
            elif name in UNMATCHED.get(filename,{}):
                disposition='no-demonstrated-counterpart';comparison=UNMATCHED[filename][name];boundary='Owned card profile/libmc2/resident-disc/CRI notebooks and their catalogue original intervals; no same-state/layout/ABI counterpart demonstrated.'
            elif filename=='gdlib.c' and name=='CheckOpenTray':
                disposition='source-stub-dependent';comparison='Full wrapper checks drive states6/9, but provided gdFsGetDrvStat always returns2 and gdFsReqDrvStat returns0 without work. This source does not implement a real tray query.';boundary='Both complete wrapper and directly called GD shim bodies checked.'
            else:
                disposition='game-specific-excluded';boundary='Full source/applicability inspection; no Outbreak identity asserted from setters, UI, save schema or named game data.'
                if filename=='ps2_MemoryCard..c':comparison='CVX MEMORYCARDSTATE0xA0, port/file/path fields and bespoke0/1/2/4/5/7/17.. completion states; BASLUS-20184 and five-retry policy. Owned profile/libmc2 context and result/state conventions differ. Simple field helpers are not unique shared identities.'
                elif filename=='ps2_McSaveFile.c':comparison='CVX save/config schema,15-slot selection UI, game flags/items/room messages, icon resource or texture placement. Full body inspected; owned manifest/snapshot/card UI is separately typed and is not aliased to this code.'
                elif filename=='ps2_sg_gd.c' and name=='gdFsInit':comparison='CVX dvd_image_data/link_file indexed-disc table builder and custom workspace/handle/directory layout; does not implement owned independent CRI registry/archive layer. Unbounded search/read retries and local-sector indexing remain source boundaries.'
                else:
                    assert filename=='gdlib.c' and name in ('LfInitLib','CallbackGdErrorFunc')
                    comparison='CVX fourteen-handle bookkeeping or its GD-specific -23/-33 error-flag policy; no matched owned library/error-state identity.'
            record={k:v for k,v in r.items()if k!='masked_body'}
            identity=path+':'+name+':'+str(r['start_line']);all_keys.append(identity)
            record.update(identity=identity,disposition=disposition,comparison=comparison,search_boundary=boundary,outbreak_ids=ids,
                source_calls=calls,source_platform_calls=apis,source_member_names=sorted(set(re.findall(r'->\s*([A-Za-z_]\w*)',r['masked_body']))),
                complete_reference_body=text[r['body_start']:r['body_end_offset']],
                raw_source_line_span_sha256=sha(b''.join(raw_lines[r['start_line']-1:r['end_line']])))
            funcs.append(record)
        header='include/'+REL+filename[:-2]+'.h';header_raw=(ref/header).read_bytes();header_text=header_raw.decode('utf-8-sig',errors='replace');assert not function_records(header_text)
        files.append(dict(path=path,sha256=sha(raw),raw_utf8_decode_has_replacements='\ufffd'in text,
            functions=funcs,header=dict(path=header,sha256=sha(header_raw),complete_text=header_text,definitions=[])))
    assert len(all_keys)==120 and len(set(all_keys))==120
    for address in (0x1C0370,0x1C03A0,0x1C04E0,0x1C0580,0x1C09D0,0x1C0A80,0x1BF660):audit(address)
    # Bounded data checks only, not execution or emulation of either algorithm.
    assert sum(bytes([0,1]))==1 and int.from_bytes(bytes([0,1]),'little')==256
    icon_constants=[]
    for address,count,kind in [(0x2351A0,12,'f32'),(0x2351D0,12,'f32'),(0x235200,4,'f32'),(0x235210,16,'i32'),(0x235250,12,'f32'),(0x235280,12,'f32'),(0x2352B0,4,'f32')]:
        data=elf.read(address,count*4);icon_constants.append(dict(address=hex(address),sha256=sha(data),kind=kind,values=struct.unpack('<'+('f'if kind=='f32'else'i')*count,data)))
    types_path='include/'+REL+'types.h';types_raw=(ref/types_path).read_bytes();types_text=types_raw.decode('utf-8-sig',errors='replace');type_lines=types_text.splitlines(keepends=True)
    type_span=''.join(type_lines[837:968])
    platform_status=[dict(symbol=n,available_definition=n in defined,evidence='Full pinned source manifest symbol inventory; external SDK bodies not invented.')for n in sorted(api_calls)]
    assert all(not x['available_definition']for x in platform_status if x['symbol'].startswith('sceMc'))
    assignments=[]
    for f in corpus['files']:
        if f['source_kind']!='C':continue
        t=(ref/f['path']).read_bytes().decode('utf-8-sig',errors='replace')
        for m in re.finditer(r'\blOpenFileNumber\s*=(?!=)',t):assignments.append(dict(path=f['path'],line=t.count('\n',0,m.start())+1,statement=t[m.start():t.find(';',m.start())+1]))
    counts=Counter(r['disposition']for f in files for r in f['functions'])
    out=dict(schema=1,reference_commit=PIN,original_elf_sha256=ELF_SHA,scope=dict(source_files=4,headers=4,definitions=120,header_definitions=0,dispositions=dict(counts)),
        files=files,supporting_types=dict(path=types_path,sha256=sha(types_raw),start_line=838,end_line=968,decoded_excerpt=type_span),
        reference_platform_api_definition_status=platform_status,reference_named_open_descriptor_assignments=assignments,
        outbreak_evidence=list(evidence.values()),owned_icon_constant_spans=icon_constants,
        checksum_arithmetic_witness=dict(bytes_hex='0001',cvx_unsigned_byte_sum=1,owned_little_endian_plaintext_halfword_sum=256,not_a_game_payload_execution=True),
        audit=dict(outbreak_intervals=len(evidence),instruction_comments=sum(e['instruction_comments']for e in evidence.values()),omitted_zero_words=sum(e['omitted_zero_words']for e in evidence.values()),conflicts=0,omitted_nonzero=0),
        new_mapping_credit=0,proposed_curated_groups=[],
        limits='Every120 available body and4 headers inspected. Comparisons are applicability/algorithm/platform concepts, not API identities. Legacy non-UTF8 bytes remain bound by raw-file/raw-line-span hashes; manifest body hashes use its decoded-UTF8 replacement convention. No absent SDK body, CVX save format or state machine is promoted as an Outbreak implementation.')
    args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(json.dumps(out,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(scope=out['scope'],audit=out['audit'],per_file=[dict(path=f['path'],definitions=len(f['functions']),dispositions=dict(Counter(r['disposition']for r in f['functions'])))for f in files],platform_api_definition_status=platform_status),indent=2))


if __name__=='__main__':main()
