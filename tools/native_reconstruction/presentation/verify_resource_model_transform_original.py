"""Exercise complete 3724F0 with actual math bodies and captured draw selectors.

The controlled rigid-matrix profile proves source-order publication and transform
math, not the root's material importer, dynamic lighting or physical PS2 parity.
"""
import argparse, hashlib, json, os, re, subprocess, sys, time
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader

CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--cohort-snapshot',type=Path);args=p.parse_args();out=args.output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir(parents=True)
    elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o0.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'
    main_read=elf_reader(elf.read_bytes());blob=overlay.read_bytes()
    def overlay_read(at,n):
        assert 0x370000<=at and at+n<=0x370000+len(blob)
        return blob[at-0x370000:at-0x370000+n]
    sources=[ROOT/'recomp/config/output_ovl/o0/o0_003724F0_0x3724f0.cpp']
    sources += [next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*')) for at in (0x18fdf0,0x1900e0,0x191380,0x1919d0,0x191280)]
    audits=[];bodies=[]
    for source in sources:
        body=source.read_text();begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
        audits.append(compare_source('resource draw and actual reached math body',source.relative_to(ROOT).as_posix(),begin,end,overlay_read if source==sources[0] else main_read));bodies.append(body)
    ref=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    (out/'reference.hpp').write_text(ref.read_text()+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n')
    names={p.stem for p in sources};calls=set(re.findall(r'\b((?:sub|o0)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram','\n'.join(bodies)))
    declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    declarations+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text('\n'.join(bodies))
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ('ps2_recompiled_functions.h','o0_functions.h'):(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/resource_model_transform_original.cpp';inputs=[fixture,ref,*sources];before={str(f.relative_to(ROOT)):sha(f) for f in inputs}
    exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    libraries=[];snapshot_receipt=None;snapshot=None
    if args.cohort_snapshot:
        snapshot=args.cohort_snapshot.resolve();assert snapshot.is_relative_to((ROOT/'build-native-sjuni').resolve())
        snapshot_receipt=json.loads((snapshot/'receipt.json').read_text());assert snapshot_receipt['status']=='passed'
        def verify_snapshot():
            for name,digest in snapshot_receipt['source_sha256'].items():assert sha(snapshot/'source'/name)==digest,name
            for name,digest in snapshot_receipt['archives_sha256'].items():assert sha(snapshot/'native-build'/name)==digest,name
        verify_snapshot();libraries=[snapshot/'native-build'/name for name in snapshot_receipt['archives_sha256']]
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out)]
    if snapshot:flags+=['-DREO_COMPARE_NATIVE=1','-I'+str(snapshot/'source')]
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture)]+(['-Wl,--start-group',*(str(p) for p in libraries),'-Wl,--end-group','-luser32','-lgdi32','-ldxgi','-luuid','-lxinput'] if snapshot else [])+['-o',str(exe)]),('run',[str(exe)])]
    receipt=dict(status='failed',compiler_sha256=sha(CC),original_word_audits=audits,source_sha256=before,driver_sha256=sha(Path(__file__)),checks=[],game_run=False)
    if snapshot:receipt.update(snapshot=str(snapshot),snapshot_receipt_sha256=sha(snapshot/'receipt.json'),native_archive_sha256=snapshot_receipt['archives_sha256'])
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append(dict(name=name,seconds=time.monotonic()-start,exit=result.returncode))
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-5000:])
        assert before=={str(f.relative_to(ROOT)):sha(f) for f in inputs}
        if snapshot:verify_snapshot();assert sha(snapshot/'receipt.json')==receipt['snapshot_receipt_sha256']
        receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
