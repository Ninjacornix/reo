"""Compare controlled owned-model vertex colors against original conversion.

Execution enters 1A3F70 at the bounded color-packing slice and stops just after
its store, then runs the complete 18B2C0 component converter. This is not a
whole mesh conversion or a rendering comparison.
"""
import argparse, hashlib, json, os, re, subprocess, sys, time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--build-receipt',type=Path)
    args=parser.parse_args();out=args.output.resolve()
    assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
    elf=ROOT/'game_data/SLUS_207.65';data=elf.read_bytes();assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read=elf_reader(data);sources=[];audits=[]
    for address in (0x1a3f70,0x1a45a0,0x18b2c0):
        source=next((ROOT/'recomp/config/output').glob(f'sub_{address:08X}_*'));body=source.read_text()
        begin,end=(int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups())
        audits.append(compare_source('vertex color source body',source.relative_to(ROOT).as_posix(),begin,end,read));sources.append(source)
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    extra='\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\nstruct PackingStop{};\n'
    (out/'reference.hpp').write_text(reference+extra)
    packing=sources[0].read_text();start=packing.index('ctx->pc = 0x1a43e0u;')
    marker='WRITE32(ADD32(GPR_U32(ctx, 9), 24), GPR_U32(ctx, 2));';pos=packing.index(marker,start)+len(marker)
    packing=packing[:pos]+' throw PackingStop{};'+packing[pos:]
    skinned=sources[1].read_text();start=skinned.index('ctx->pc = 0x1a4a88u;')
    marker='WRITE32(ADD32(GPR_U32(ctx, 10), 24), GPR_U32(ctx, 2));';pos=skinned.index(marker,start)+len(marker)
    skinned=skinned[:pos]+' throw PackingStop{};'+skinned[pos:]
    body=packing+'\n'+skinned+'\n'+sources[2].read_text();names={source.stem for source in sources}
    calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    declarations=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(names))
    declarations+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for n in sorted(calls-names))
    (out/'functions.h').write_text('#pragma once\n'+declarations);(out/'original.cpp').write_text(body)
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/vertex_packing_original.cpp';native=ROOT/'game/native/gameplay_presentation/model_mesh.cpp'
    header=native.with_suffix('.hpp');model=ROOT/'build-native-sjuni/stage4-orchestration/presentation-mesh-explore/r0417300.nbd';exe=out/'checks.exe'
    identities={str(p.relative_to(ROOT)):sha(p) for p in [fixture,native,header,model,*sources]};env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    build_receipt=None;archive=None
    if args.build_receipt:
        build_receipt=json.loads(args.build_receipt.read_text())
        assert build_receipt['status']=='passed' and not build_receipt['source_drift'] and not build_receipt['archive_drift']
        assert sha(CC)==build_receipt['compiler_sha256']
        def verify_sources():
            for name,expected in build_receipt['sources_sha256'].items():
                if sha(ROOT/name)!=expected:raise RuntimeError('source identity mismatch: '+name)
        verify_sources()
        relative='gameplay_application/libreo_native_gameplay_presentation.a'
        archive=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'/relative
        assert sha(archive)==build_receipt['archives_sha256'][relative]
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-ffp-contract=off',
           '-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(ROOT),'-I'+str(out),
           '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
    commands=[('compile',flags+[str(out/'original.cpp'),str(fixture),str(archive or native),'-o',str(exe)]),('run',[str(exe),str(model)])]
    receipt={'status':'failed','compiler_sha256':sha(CC),'elf_sha256':sha(elf),'inputs':identities,
             'driver_sha256':sha(Path(__file__)),'original_word_audits':audits,'checks':[],
             'packing_scope':'1A42C0 through 1A43E0 and 1A4964 through 1A4A88 stores; instrumented stops','game_run':False}
    if archive:
        receipt.update(build_receipt=str(args.build_receipt.resolve()),build_receipt_sha256=sha(args.build_receipt),archive_sha256=sha(archive))
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (out/(name+'.out')).write_bytes(result.stdout);(out/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-4000:])
        assert identities=={str(p.relative_to(ROOT)):sha(p) for p in [fixture,native,header,model,*sources]}
        if archive:
            verify_sources();assert sha(archive)==receipt['archive_sha256']
        receipt.update(status='passed',observed=json.loads((out/'run.out').read_text()))
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))
if __name__=='__main__':main()
