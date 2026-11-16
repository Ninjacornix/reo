"""Compare actual 1D29F0 selector arguments with owned native mesh profiles.

The real caller runs to return; its 1AF780 callee is intercepted to record
arguments. This proves neither the VU draw program nor full frontend execution.
"""
import argparse, hashlib, json, os, re, struct, subprocess, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(ROOT / 'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source, elf_reader

CC = Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--build-receipt', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    build = ROOT / 'build-native-sjuni/gameplay-native-llvm-v1'
    output = args.output.resolve()
    assert not output.exists() and output.is_relative_to((ROOT / 'build-native-sjuni').resolve())
    receipt_path = args.build_receipt.resolve()
    build_receipt = json.loads(receipt_path.read_text())
    assert build_receipt['status'] == 'passed' and not build_receipt['source_drift'] and not build_receipt['archive_drift']
    assert sha(CC) == build_receipt['compiler_sha256']
    sources = build_receipt['sources_sha256']
    def verify_sources():
        for name, expected in sources.items():
            if sha(ROOT / name) != expected:
                raise RuntimeError('source identity mismatch: ' + name)
    verify_sources()
    archive_rel = 'gameplay_application/libreo_native_gameplay_presentation.a'
    archive = build / archive_rel
    assert sha(archive) == build_receipt['archives_sha256'][archive_rel]
    output.mkdir()
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    data = elf.read_bytes();read = elf_reader(data)
    source = next((ROOT / 'recomp/config/output').glob('sub_001D29F0_*'))
    begin, end = (int(v,16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', source.read_text()).groups())
    audit = compare_source('full mesh render property caller', source.relative_to(ROOT).as_posix(), begin, end, read)
    image = bytearray(0x2000000);phoff = struct.unpack_from('<I',data,28)[0];size,count = struct.unpack_from('<HH',data,42)
    for i in range(count):
        kind,offset,address,_,filesz,memsz = struct.unpack_from('<6I',data,phoff+i*size)
        if kind==1:
            assert address+memsz<=len(image) and offset+filesz<=len(data)
            image[address:address+filesz]=data[offset:offset+filesz]
    (output/'elf_image.bin').write_bytes(image)
    reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()
    (output/'reference.hpp').write_text(reference+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n'
                                        '#define SRA32(a,b) (std::bit_cast<std::int32_t>(std::uint32_t(a)) >> unsigned(b))\n')
    body=source.read_text();calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
    declarations='void '+source.stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
    declarations+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n' for name in sorted(calls))
    (output/'functions.h').write_text('#pragma once\n'+declarations)
    (output/'original.cpp').write_text(body)
    for name in ('ps2_runtime.h','ps2_runtime_macros.h'):(output/name).write_text('#pragma once\n#include "reference.hpp"\n')
    (output/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
    for name in ('ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(output/name).write_text('#pragma once\n')
    fixture=ROOT/'tools/native_reconstruction/presentation/mesh_render_properties_original.cpp'
    assets=ROOT/'build-native-sjuni/stage4-orchestration/presentation-mesh-explore'
    models=[assets/'r0417300.nbd',assets/'r0010100.nbd',assets/'P00_00.nbd']
    identities={str(p.relative_to(ROOT)):sha(p) for p in [fixture,source,*models]}
    exe=output/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
    flags=[str(CC),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label',
           '-Wno-unused-parameter','-Wno-unused-variable','-I'+str(ROOT),'-I'+str(output),
           '-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
    commands=[('compile',flags+[str(output/'original.cpp'),str(fixture),str(archive),'-o',str(exe)]),
              ('run',[str(exe),str(output/'elf_image.bin'),*(str(p) for p in models)])]
    receipt={'status':'failed','compiler_sha256':sha(CC),'build_receipt':str(receipt_path),
             'build_receipt_sha256':sha(receipt_path),'archive_sha256':sha(archive),'inputs':identities,
             'original_word_audit':audit,'checks':[],'selector_callee':'capture only','game_run':False}
    try:
        for name,command in commands:
            start=time.monotonic();result=subprocess.run(command,capture_output=True,env=env,timeout=120)
            (output/(name+'.out')).write_bytes(result.stdout);(output/(name+'.err')).write_bytes(result.stderr)
            receipt['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':result.returncode})
            if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-3000:])
        verify_sources();assert sha(archive)==receipt['archive_sha256']
        assert identities=={str(p.relative_to(ROOT)):sha(p) for p in [fixture,source,*models]}
        observed=json.loads((output/'run.out').read_text());assert observed['original_calls']>0
        receipt.update(status='passed',observed=observed)
    finally:
        (output/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(receipt['observed']))

if __name__=='__main__':main()
