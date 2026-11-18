"""Compare glyph rectangle/UV math to the original 1B71D0 packet writer.

The upload-reference callee is intercepted at its output cursor; this proves
only packet geometry, not GS sampling, blending or display presentation.
"""
import argparse,hashlib,json,os,re,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);out=p.parse_args().output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir(parents=True)
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
    source=ROOT/'recomp/config/output/sub_001B71D0_0x1b71d0.cpp';body=source.read_text()
    begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
    audit=compare_source('original glyph packet geometry',source.relative_to(ROOT).as_posix(),begin,end,read)
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    (out/'reference.hpp').write_text(reference+'\n#include "ps2_fpu_convert.h"\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(v,n) ((v) >> (n))\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n')
    names={source.stem};calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body)
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/font_geometry_original.cpp'
    inputs=[fixture,source,ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp',ROOT/'tools/native_reconstruction/audit_retail_effect_descriptors.py',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'];before={str(f.relative_to(ROOT)):sha(f) for f in inputs}
    executable=out/'geometry_checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(ROOT),'-I'+str(out),'-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture),'-o',str(executable)]),('run',[str(executable)])]
    receipt={'status':'failed','compiler_sha256':sha(CC),'elf_sha256':sha(elf),'source_sha256':before,'driver_sha256':sha(Path(__file__)),'original_word_audit':audit,'checks':[],'game_run':False}
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-4000:])
        assert before=={str(f.relative_to(ROOT)):sha(f) for f in inputs};receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
