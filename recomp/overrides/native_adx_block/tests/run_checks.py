#!/usr/bin/env python3
"""Host-only ADX ABI/whole-RAM tests and optional actual-header compilation."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[4]
HERE=Path(__file__).resolve().parent
FIXTURE_SHA='11785ce1d02f0355e54c38df58216911ca33d1ca8fbeaa6a2528c539a27eb6bb'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',default='g++')
    p.add_argument('--runtime-headers',type=Path);p.add_argument('--output',required=True,type=Path)
    args=p.parse_args();cxx=shutil.which(args.cxx)
    if not cxx:p.error('Pass an installed C++20 compiler')
    out=args.output.resolve();allowed=ROOT/'build-native-sjuni'
    if out==allowed or not out.is_relative_to(allowed):p.error('Use ignored output below build-native-sjuni')
    out.mkdir(parents=True,exist_ok=True)
    sys.path.insert(0,str(ROOT/'tools/function_index'))
    from index import Elf
    elf=Elf(ROOT/'game_data/SLUS_207.65');identity=out/'identity.bin'
    identity.write_bytes(b''.join(struct.pack('<II',at,size)+elf.read(at,size) for at,size in ((0x1276D8,0x1DC),(0x239BE8,64))))
    fixture_path=ROOT/'build-native-sjuni/adx-decode-fixtures.json'
    if sha(fixture_path)!=FIXTURE_SHA:raise ValueError('Independent original-word fixture changed')
    fixture=json.loads(fixture_path.read_text());cases=[c for c in fixture['cases'] if 1<=c['input']['requested_i32']<=16]
    if len(cases)!=101:raise ValueError('Expected101 positive-count cases')
    wire=bytearray(struct.pack('<I',len(cases)))
    for case in cases:
        i,e=case['input'],case['expected'];s=e['state'];encoded=bytes.fromhex(i['encoded_hex'])
        wire.extend(struct.pack('<iiiiiIiiI',i['requested_i32'],*i['history_i16'],*i['coefficients_i16'],i['key_u16'],i['multiplier_i16'],i['addend_i16'],len(encoded)))
        wire.extend(encoded);wire.extend(struct.pack('<IiiiI',len(s['pcm_i16']),e['return_i32'],*s['history_i16'],s['key_u16']))
        wire.extend(struct.pack('<'+'h'*len(s['pcm_i16']),*s['pcm_i16']))
    case_path=out/'cases.bin';case_path.write_bytes(wire)
    sources=[*HERE.glob('*'),HERE.parent/'runtime_adapter.cpp',HERE.parent/'runtime_adapter.h',
        ROOT/'game/native/adx_block/adx_block.cpp',ROOT/'game/native/adx_block/adx_block.hpp',
        ROOT/'recomp/overrides/native_geometry/reo_vu_native_sha256.h']
    receipt=dict(schema=1,status='running',compiler=cxx,compiler_sha256=sha(Path(cxx)),
        fixture_sha256=FIXTURE_SHA,elf_sha256=elf.sha256,positive_oracle_cases=len(cases),
        game_run=False,runtime_linked=False,source_sha256={f.relative_to(ROOT).as_posix():sha(f) for f in sources if f.is_file()},checks=[])
    env=dict(os.environ);compiler=Path(cxx).resolve()
    bins=[compiler.parent,compiler.parent.parent/'x86_64-w64-mingw32/bin']
    env['PATH']=os.pathsep.join(str(b) for b in bins if b.is_dir())+os.pathsep+env.get('PATH','')
    def run(name,cmd):
        r=subprocess.run([str(x) for x in cmd],cwd=ROOT,env=env,capture_output=True,text=True,timeout=90)
        receipt['checks'].append(dict(name=name,command=[str(x) for x in cmd],exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr))
        if r.returncode:print(r.stdout,r.stderr);raise RuntimeError(name+' failed')
        lines=[line for line in r.stderr.splitlines() if 'native op=' in line]
        if name=='trace':
            if len(lines)!=6 or [int(line.split('calls=')[1].split()[0]) for line in lines]!=[1,2,3,4,8,16]:raise RuntimeError('Trace did not sample postcommit calls')
        elif lines:raise RuntimeError('Unexpected native count outside trace scenario')
        print(name+': passed',flush=True)
    try:
        common=[cxx,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE),'-I'+str(ROOT)]
        inputs=[HERE/'harness.cpp',HERE.parent/'runtime_adapter.cpp',ROOT/'game/native/adx_block/adx_block.cpp']
        enabled=['-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_ADX_BLOCK=1']
        exe=out/'checks.exe';run('mock_compile',common+enabled+inputs+['-o',exe])
        for scenario in ('off','text','table','missing','wrong-binding','late','partial-runtime','partial-stub',
                         'fixtures','trace','allocation','changed-identity','changed-table','stop','manual',
                         'binding-change','runtime-identity','memory-identity','refusals'):
            run(scenario,[exe,identity,case_path,scenario])
        for name,flags in (('numeric-zero',['-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_ADX_BLOCK=0']),
                           ('not-built',['-DREO_GAME_FILE1']),('file2',['-DREO_GAME_FILE2','-DREO_BUILD_NATIVE_ADX_BLOCK=1'])):
            disabled=out/(name+'.exe');run(name+'_compile',common+flags+inputs+['-o',disabled]);run(name,[disabled,identity,case_path,'disabled'])
        if args.runtime_headers:
            dep=args.runtime_headers.resolve();receipt['real_header_sha256']=sha(dep/'ps2xRuntime/include/ps2_runtime.h')
            run('real_header_object',[cxx,'-std=c++20','-O1','-Wall','-Wextra','-Werror','-mssse3','-msse4.1',
                '-Wno-unused-variable','-Wno-unused-parameter',*enabled,
                '-I'+str(dep/'ps2xRuntime/include'),'-I'+str(dep/'ps2xRuntime/src/lib'),
                '-I'+str(dep/'ps2xRuntime/src/lib/Kernel'),'-I'+str(ROOT),'-c',HERE.parent/'runtime_adapter.cpp','-o',out/'real_adapter.o'])
        receipt['status']='passed'
    except Exception as error:receipt['status']='failed';receipt['failure']=str(error);raise
    finally:
        receipt['limitations']=['Synthetic mocks/whole-RAM checks, not a game run or actual runtime link.',
            'No stereo/COP1/stream/refill/SJ/ADXT/RNA/clock replacement.',
            'Original ABI volatile GPR/MAC observations excluded; saved registers and unrelated context retained.',
            'Lifecycle token requires guest-held synchronous calls; no external/manual invocation lifetime claim.']
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(out/'receipt.json')

if __name__=='__main__':main()
