"""Classify reference-only skeletons and audit the available SDK startup source.

No target execution, builds, downloads or process access. Missing source is
recorded as unavailable rather than translated into a guessed comparison.
"""
from __future__ import annotations
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import subprocess

from index import Elf, ROOT
from recvx_scope_inventory import PIN, function_records

SKELETONS = ('src/atick.c','src/putsts.c','src/sdd_com.c','src/tq.c','src/tsnddrv.c',
             'src/users/oshimi/adx/sjr.093/sjr_svr.c',
             'src/ps2/veronica/prog/ps2_cri_adxt.c')


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference',required=True,type=Path)
    args=parser.parse_args()
    reference=args.reference.resolve()
    assert subprocess.check_output(['git','-C',str(reference),'rev-parse','HEAD'],text=True).strip()==PIN
    assert not subprocess.check_output(['git','-C',str(reference),'status','--porcelain','--untracked-files=no'],text=True).strip()
    inventory=json.loads((ROOT/'build-function-index/recvx-complete-source-inventory.json').read_text(encoding='utf-8'))
    source_files={x['path']:x for x in inventory['files']}
    files=[]
    for path in SKELETONS:
        raw=(reference/path).read_bytes()
        text=raw.decode('utf-8-sig',errors='replace')
        f=source_files[path]
        assert hashlib.sha256(raw).hexdigest()==f['sha256']
        rows=[]
        for body in function_records(text):
            masked=body.pop('masked_body')
            # These IOP metadata bodies have only declarations or empty braces.
            assert not re.search(r'\b(return|if|for|while|switch|asm|goto)\b|=|\(',masked), (path,body['symbol'])
            disposition=('empty_alternate_ADXT_hook' if path.endswith('ps2_cri_adxt.c') else
                         'debug_metadata_skeleton_no_behavior')
            rows.append(dict(**body,file=path,disposition=disposition,
                             comparison='No implementing operations are supplied in this source body; names/local declarations do not validate an Outbreak implementation.',
                             alternate_source=('src/cri/mwlib/ee/lib/libadxe/adx_tlk.c' if path.endswith('ps2_cri_adxt.c') else None)))
        expected={(r['symbol'],r['start_line'],r['body_sha256']) for r in f['functions']}
        assert expected=={(r['symbol'],r['start_line'],r['body_sha256']) for r in rows}
        files.append(dict(path=path,sha256=f['sha256'],functions=rows))
    # The two GS helpers embedded in the otherwise game-specific inventory UI
    # were inspected separately instead of excluding a mixed file wholesale.
    support='src/ps2/veronica/prog/sub1.c'
    raw=(reference/support).read_bytes()
    rows=[]
    for body in function_records(raw.decode('utf-8-sig',errors='replace')):
        if body['symbol'] not in ('Ps2ZbuffOffI','Ps2DrawOTagI'): continue
        masked=body.pop('masked_body')
        if body['symbol']=='Ps2ZbuffOffI':
            assert 'D2_SyncTag' in masked and 'WORKBASE' in masked and 'loadImage' in masked
            reason='CVX WORKBASE GIF TEST_1 packet with fixed alpha/depth policy and direct scratch-path submission; no demonstrated equivalent Outbreak packet-owner body.'
        else:
            assert masked.count('4096')==2 and 'Ps2DrawOTagSub' in masked
            reason='Two CVX4096-bucket OT passes with CVX depth helpers, SyncPath and texture-break global; not an Outbreak frame/GS ownership contract.'
        rows.append(dict(**body,file=support,disposition='reference_ui_graphics_owner_boundary',comparison=reason))
    assert len(rows)==2
    files.append(dict(path=support,sha256=hashlib.sha256(raw).hexdigest(),functions=rows))
    # Preserve every unavailable alternate ASM entry, including those with a
    # same-named implementation in the older mwlib tree. They are not proven
    # interchangeable builds merely because the public identifier agrees.
    all_symbols={}
    for f in inventory['files']:
        for r in f['functions']: all_symbols.setdefault(r['symbol'],[]).append(f['path'])
    placeholders=[]
    for f in inventory['files']:
        if not f['assembly_placeholders']: continue
        raw=(reference/f['path']).read_bytes()
        text=raw.decode('utf-8-sig',errors='replace')
        assert hashlib.sha256(raw).hexdigest()==f['sha256']
        matches=list(re.finditer(r'\bINCLUDE_ASM\s*\(\s*"([^"]+)"\s*,\s*(\w+)\s*\)',text))
        assert len(matches)==len(f['assembly_placeholders'])
        for m in matches:
            guessed=reference/(m[1]+'/'+m[2]+'.s')
            placeholders.append(dict(file=f['path'],source_sha256=f['sha256'],symbol=m[2],
                                     line=text.count('\n',0,m.start())+1,
                                     declared_assembly_directory=m[1],
                                     expected_assembly_file_present=guessed.exists(),
                                     same_named_C_definitions=all_symbols.get(m[2],[]),
                                     disposition='alternate_assembly_implementation_unavailable'))
    assert len(placeholders)==223
    assembly_files=[p.relative_to(reference).as_posix() for p in (reference/'src').rglob('*') if p.is_file() and p.suffix.lower()=='.s']
    assert assembly_files==['src/sce/ee/lib/crt0.s']
    crt='src/sce/ee/lib/crt0.s'
    crt_raw=(reference/crt).read_bytes()
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    db=sqlite3.connect(ROOT/'build-function-index/index.sqlite')
    db.row_factory=sqlite3.Row
    owned=[]
    for address in (0x100008,0x100218,0x100220):
        f=db.execute('select * from functions where image=? and start=?',('main',address)).fetchone()
        raw=elf.read(address,f['end']-address)
        assert raw is not None
        comments={}
        for m in re.finditer(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s+',(ROOT/f['source']).read_text(encoding='utf-8'),re.I):
            pc,word=int(m[1],16),int(m[2],16)
            if address<=pc<f['end']:
                assert int.from_bytes(elf.read(pc,4),'little')==word
                comments[pc]=word
        omitted=[pc for pc in range(address,f['end'],4) if pc not in comments]
        assert all(elf.read(pc,4)==bytes(4) for pc in omitted)
        owned.append(dict(id=f['id'],end=f'0x{f["end"]:08X}',sha256=hashlib.sha256(raw).hexdigest(),
                          instruction_comments=len(comments),omitted_zero_words=len(omitted),source=f['source']))
    required={'initialize_main_thread':(0x1001C4,0x2403003C),
              'initialize_heap':(0x1001E0,0x2403003D),
              'root_thread_exit':(0x100220,0x24030023)}
    for name,(pc,word) in required.items(): assert int.from_bytes(elf.read(pc,4),'little')==word,name
    external_names=('memcpy','memmove','memset','memcmp','strlen','strcpy','strcmp','printf','sprintf',
                    'malloc','free','realloc','fopen','fread','fwrite','sqrt','sqrtf','sinf','cosf',
                    'dpcmp','__floatdisf','__floatdidf','sceMcOpen','sceMcRead','sceMcWrite','sceMcSync',
                    'scePadRead','sceMpegGetPicture','sceMpegCreate','sceSifCallRpc','sceCdReadClock',
                    'CreateThread','SetAlarm','SleepThread','SignalSema')
    available={name:all_symbols.get(name,[]) for name in external_names}
    assert not any(available.values()), 'An external body became available: review scope must expand'
    result=dict(schema=1,reference_commit=PIN,files=files,
                counts=dict(functions=sum(len(f['functions']) for f in files),
                            statuses=dict(Counter(r['disposition'] for f in files for r in f['functions'])),
                            assembly_placeholders=len(placeholders)),
                assembly_placeholders=placeholders,
                sdk_startup=dict(path=crt,sha256=hashlib.sha256(crt_raw).hexdigest(),
                                 disposition='compared_startup_family_with_version_differences',owned_bodies=owned,
                                 differences=['Outbreak explicitly clears integer/FPU registers and handles byte BSS edges.',
                                              'Both initialize main thread with selector0x3C and heap with0x3D; argument addresses/layouts remain game-specific.',
                                              'CVX _exit forces a0=0; Outbreak100218 preserves incoming a0 before its own exit path.',
                                              'Both root thread paths use selector0x23, but the Outbreak catalogue interval also contains an adjacent CDVD callback entry.']),
                queried_external_implementation_availability=available,
                no_target_activity=True,
                limits='Exact identifier availability is bounded to this pinned source corpus. Different spellings, binary-only libraries and external dependencies are not disproved. Empty alternate hooks and debug metadata are not assumed to implement Outbreak no-ops.')
    out=ROOT/'build-function-index/recvx-reference-availability.json'
    out.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(f'{result["counts"]["functions"]} dispositions (60 metadata/alternate hooks,2 UI graphics helpers);223 unavailable ASM entries;3 owned startup intervals;35 queried external implementations absent.')


if __name__=='__main__': main()
