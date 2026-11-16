"""Check complete original 18B2C0 conversion on every byte in both modes."""
import argparse, hashlib, json, os, re, subprocess, sys, time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True)
    out=parser.parse_args().output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    source=next((ROOT/'recomp/config/output').glob('sub_0018B2C0_*'));body=source.read_text()
    begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
    audit=compare_source('complete vertex component conversion',source.relative_to(ROOT).as_posix(),begin,end,elf_reader(elf.read_bytes()))
    (out/'reference.hpp').write_text((ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text())
    (out/'functions.h').write_text('#pragma once\nvoid '+source.stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n')
    (out/'original.cpp').write_text(body)
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/vertex_color_original_probe.cpp';exe=out/'checks.exe'
    env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror',
           '-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out)]
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture),'-o',str(exe)]),('run',[str(exe)])]
    receipt={'status':'failed','compiler_sha256':sha(CC),'elf_sha256':sha(elf),'fixture_sha256':sha(fixture),
             'driver_sha256':sha(Path(__file__)),'original_word_audit':audit,'checks':[],'game_run':False}
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-3000:])
        receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
