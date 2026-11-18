"""Run complete original 1CCD90 and 1CCB30 around explicit I/O ports."""
import argparse,hashlib,json,os,re,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);out=p.parse_args().output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir(parents=True)
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
    sources=[next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*')) for at in (0x1ccd90,0x1ccb30)];bodies=[];audits=[]
    for source in sources:
        body=source.read_text();begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
        audits.append(compare_source('texture load mode and existing-key reference behavior',source.relative_to(ROOT).as_posix(),begin,end,read));bodies.append(body)
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';(out/'reference.hpp').write_text(reference.read_text())
    names={p.stem for p in sources};calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram','\n'.join(bodies)))
    declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    declarations+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text('\n'.join(bodies))
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/startup_texture_mode_original.cpp';inputs=[fixture,reference,*sources];before={str(f.relative_to(ROOT)):sha(f) for f in inputs}
    exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out)]
    receipt=dict(status='failed',compiler_sha256=sha(CC),source_sha256=before,original_word_audits=audits,driver_sha256=sha(Path(__file__)),checks=[],game_run=False,
                 limits=['The complete 1CCD90 and 1CCB30 bodies run; actual file read, decompression and image creation are ordered observation ports.'])
    try:
        for name,cmd in [('compile',flags+[str(out/'original.cpp'),str(fixture),'-o',str(exe)]),('run',[str(exe)])]:
            start=time.monotonic();r=subprocess.run(cmd,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(r.stdout);(out/(name+'.err')).write_bytes(r.stderr)
            receipt['checks'].append(dict(name=name,seconds=time.monotonic()-start,exit=r.returncode))
            if r.returncode:raise RuntimeError(name+': '+r.stderr.decode(errors='replace')[-5000:])
        assert before=={str(f.relative_to(ROOT)):sha(f) for f in inputs};receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
