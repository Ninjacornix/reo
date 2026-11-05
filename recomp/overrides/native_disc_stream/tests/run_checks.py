#!/usr/bin/env python3
"""Isolated scalar adapter/wire/ABI checks; no game or runtime library execution."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[4]
HERE=Path(__file__).resolve().parent
RANGES=((0x139C30,0x94),(0x139CC8,0x38),(0x139FA8,0x38),(0x139FE8,0x4C),
        (0x1399F8,0x34),(0x139A50,0x184),(0x139A30,0x1C),(0x139BD8,0x58),(0x21CBF8,0x68))


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',default='g++')
    parser.add_argument('--runtime-headers',type=Path)
    args=parser.parse_args()
    compiler=shutil.which(args.cxx)
    if not compiler:parser.error('Pass an existing C++20 GCC/Clang compiler')
    sys.path.insert(0,str(ROOT/'tools/function_index'))
    from index import Elf
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    out=ROOT/'build-native-sjuni/disc-stream-adapter-checks'
    out.mkdir(parents=True,exist_ok=True)
    fixture=out/'identity.bin'
    fixture.write_bytes(b''.join(struct.pack('<II',pc,size)+elf.read(pc,size) for pc,size in RANGES))
    sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
    sources=[*HERE.glob('*'),HERE.parent/'runtime_adapter.cpp',HERE.parent/'runtime_adapter.h',
             ROOT/'game/native/disc_stream/disc_stream.hpp',ROOT/'game/native/disc_stream/disc_stream.cpp',
             ROOT/'recomp/overrides/native_geometry/reo_vu_native_sha256.h']
    receipt=dict(schema=1,status='running',game_run=False,game_built=False,runtime_linked=False,
        elf_sha256=elf.sha256,compiler=compiler,compiler_sha256=sha(Path(compiler)),
        source_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in sources if p.is_file()},checks=[])
    def run(name,command):
        result=subprocess.run([str(x) for x in command],cwd=ROOT,text=True,capture_output=True,timeout=40)
        receipt['checks'].append(dict(name=name,command=[str(x) for x in command],exit_code=result.returncode,
            stdout=result.stdout,stderr=result.stderr))
        if result.returncode:
            print(result.stdout,result.stderr);raise RuntimeError(name+' failed')
        native_lines=[line for line in result.stderr.splitlines() if 'native op=' in line]
        if name=='trace':
            if len(native_lines)!=15 or not all('slot=39' in line for line in native_lines):
                raise RuntimeError('trace did not sample committed native bodies as expected')
        elif native_lines:
            raise RuntimeError('disabled/nontrace/fallback scenario emitted native body counts')
        print(name+': passed')
    try:
        exe=out/'adapter_checks.exe'
        common=[compiler,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror']
        run('mock_adapter_compile',common+['-I'+str(HERE),'-I'+str(ROOT),HERE/'harness.cpp',
            HERE.parent/'runtime_adapter.cpp',ROOT/'game/native/disc_stream/disc_stream.cpp','-o',exe])
        for scenario in ('off','identity','missing','partial','operations','trace','refusals','text-change',
                         'binding-change','runtime-identity','stop'):
            run(scenario,[exe,fixture,scenario])
        if args.runtime_headers:
            dep=args.runtime_headers.resolve()
            receipt['real_header_sha256']=sha(dep/'ps2xRuntime/include/ps2_runtime.h')
            run('real_runtime_header_object',[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Werror',
                '-mssse3','-msse4.1','-Wno-unused-variable','-Wno-unused-parameter',
                '-I'+str(dep/'ps2xRuntime/include'),'-I'+str(dep/'ps2xRuntime/src/lib'),
                '-I'+str(dep/'ps2xRuntime/src/lib/Kernel'),'-I'+str(ROOT),
                '-c',HERE.parent/'runtime_adapter.cpp','-o',out/'real_runtime_adapter.o'])
        receipt['status']='passed'
    except Exception as error:
        receipt['status']='failed';receipt['failure']=str(error);raise
    finally:
        receipt['limitations']=['Mocks exercise ABI/wire/fallback policy, not guest/runtime/game execution.',
            'Owned instructions supply identity only; no request/update/SRD/callback/I/O parity is claimed.',
            'Installation must be before guest execution for one runtime/RAM/process lifetime.']
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print('Receipt: '+str(out/'receipt.json'))


if __name__=='__main__':main()
