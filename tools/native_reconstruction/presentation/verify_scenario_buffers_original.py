"""Compare native EPP/door owners with complete original caller/query bodies.

File reads and formatting are bounded observation ports over owned scenario
sectors. The original missing-EPP path is checked separately from native I/O.
"""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
def sha(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        while block:=f.read(1024*1024):h.update(block)
    return h.hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--cohort-snapshot',type=Path,required=True);p.add_argument('--netbio',type=Path,required=True);args=p.parse_args()
    out=args.output.resolve();snapshot=args.cohort_snapshot.resolve();asset=args.netbio.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir(parents=True)
    snap=json.loads((snapshot/'receipt.json').read_text());assert snap['status']=='passed'
    def verify_snapshot():
        for name,digest in snap['source_sha256'].items():assert sha(snapshot/'source'/name)==digest,name
        for name,digest in snap['archives_sha256'].items():assert sha(snapshot/'native-build'/name)==digest,name
    verify_snapshot();libraries=[snapshot/'native-build'/name for name in snap['archives_sha256']]
    elf=ROOT/'game_data/SLUS_207.65';overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read=elf_reader(elf.read_bytes());blob=overlay.read_bytes()
    def overlay_read(at,n):
        assert 0x570000<=at and at+n<=0x570000+len(blob)
        return blob[at-0x570000:at-0x570000+n]
    sources=[ROOT/'recomp/config/output/sub_001D49E0_0x1d49e0.cpp',ROOT/'recomp/config/output_ovl/o2/o2_006DD9A0_0x6dd9a0.cpp',ROOT/'recomp/config/output_ovl/o2/o2_006344C0_0x6344c0.cpp']
    bodies=[];audits=[]
    for i,source in enumerate(sources):
        body=source.read_text();begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
        audits.append(compare_source('scenario buffer caller/query',source.relative_to(ROOT).as_posix(),begin,end,main_read if i==0 else overlay_read));bodies.append(body)
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';(out/'reference.hpp').write_text(reference.read_text())
    names={p.stem for p in sources};calls=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram','\n'.join(bodies)))
    declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    declarations+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text('\n'.join(bodies))
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ('ps2_recompiled_functions.h','o2_functions.h'):(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    raw=elf.read_bytes();image=bytearray(0x2000000);phoff=struct.unpack_from('<I',raw,28)[0];size,count=struct.unpack_from('<HH',raw,42)
    for i in range(count):
        kind,offset,address,_,filesz,memsz=struct.unpack_from('<6I',raw,phoff+i*size)
        if kind==1:
            assert address+memsz<=len(image) and offset+filesz<=len(raw);image[address:address+filesz]=raw[offset:offset+filesz]
    image_path=out/'elf_image.bin';image_path.write_bytes(image)
    fixture=ROOT/'tools/native_reconstruction/presentation/scenario_buffers_original.cpp';inputs=[fixture,reference,*sources];before={str(f.relative_to(ROOT)):sha(f) for f in inputs}
    asset_hash=sha(asset);assert asset_hash=='93f04f81a2d9c46ea4bc6ff7dc7788ae9249fb2a90f1079325023334816fca55';asset_stat=asset.stat()
    executable=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out),'-I'+str(snapshot/'source'),'-I'+str(ROOT)]
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture),'-Wl,--start-group',*(str(x) for x in libraries),'-Wl,--end-group','-luser32','-lgdi32','-ldxgi','-luuid','-lxinput','-o',str(executable)]),
              ('run',[str(executable),str(image_path),str(overlay),str(asset)])]
    receipt=dict(status='failed',compiler_sha256=sha(CC),snapshot=str(snapshot),snapshot_receipt_sha256=sha(snapshot/'receipt.json'),asset_sha256=asset_hash,source_sha256=before,original_word_audits=audits,driver_sha256=sha(Path(__file__)),checks=[],game_run=False,
                 limits=['Complete 1D49E0, 6DD9A0 and 6344C0 bodies; formatted names, bounded zeroing and sector reads are explicit observation ports.',
                         'The missing-EPP path runs in the original body only; native missing-file behavior is not compared in this fixture.'])
    try:
        for name,cmd in commands:
            start=time.monotonic();r=subprocess.run(cmd,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(r.stdout);(out/(name+'.err')).write_bytes(r.stderr)
            receipt['checks'].append(dict(name=name,seconds=time.monotonic()-start,exit=r.returncode))
            if r.returncode:raise RuntimeError(name+': '+r.stderr.decode(errors='replace')[-5000:])
        verify_snapshot();assert sha(snapshot/'receipt.json')==receipt['snapshot_receipt_sha256']
        assert before=={str(f.relative_to(ROOT)):sha(f) for f in inputs};after=asset.stat();assert (after.st_size,after.st_mtime_ns)==(asset_stat.st_size,asset_stat.st_mtime_ns)
        receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
