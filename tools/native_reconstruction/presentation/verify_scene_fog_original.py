"""Compare 6B1660 fog publication with the actual native presenter helper."""
import argparse,hashlib,json,os,re,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);out=p.parse_args().output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes()
    source=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_006B1660_*'));body=source.read_text()
    begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
    audit=compare_source('full scene light/fog publication',source.relative_to(ROOT).as_posix(),begin,end,lambda at,n:data[at-0x570000:at-0x570000+n])
    ref=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    (out/'reference.hpp').write_text(ref+'\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n')
    calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl='void '+source.stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
    decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for name in sorted(calls-{source.stem}))
    (out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body)
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    for name in ('ps2_recompiled_functions.h','o0_functions.h','o2_functions.h','ps2_overlay_functions.h'):(out/name).write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/scene_fog_original.cpp';native=ROOT/'game/native/gameplay_presentation/raster.cpp';header=native.with_suffix('.hpp');fog=ROOT/'game/native/gameplay_scenario/fog.hpp'
    inputs={str(x.relative_to(ROOT)):sha(x) for x in (fixture,native,header,fog,source)};exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(ROOT),'-I'+str(out)]
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture),str(native),'-o',str(exe)]),('run',[str(exe)])]
    receipt={'status':'failed','compiler_sha256':sha(CC),'overlay_sha256':sha(overlay),'inputs':inputs,'driver_sha256':sha(Path(__file__)),
             'original_word_audit':audit,'selector_callee':'capture only','checks':[],'game_run':False}
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-4000:])
        assert inputs=={str(x.relative_to(ROOT)):sha(x) for x in (fixture,native,header,fog,source)}
        receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
