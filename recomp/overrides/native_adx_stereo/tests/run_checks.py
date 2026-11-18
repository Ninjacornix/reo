#!/usr/bin/env python3
"""Isolated native stereo adapter ABI/whole-RAM/lifecycle checks; no game."""
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
PCM_SHA='a02fc85b996feb650751407a5a2e5fc9cd8104fd1c5d9fe4278864cf4027f6b0'
ABI_SHA='2973e5606dfa1eefcc24c5007c55294cec770bb7910983a08293b7408a22e275'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx',default='g++');p.add_argument('--output',required=True,type=Path)
    p.add_argument('--runtime-headers',type=Path);args=p.parse_args();cxx=shutil.which(args.cxx)
    if not cxx:p.error('Pass installed C++20 compiler')
    out=args.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
    if out==allowed or not out.is_relative_to(allowed):p.error('Use ignored output below build-native-sjuni')
    out.mkdir(parents=True,exist_ok=True)
    sys.path.insert(0,str(ROOT/'tools/function_index'))
    from index import Elf
    elf=Elf(ROOT/'game_data/SLUS_207.65');identity=out/'identity.bin'
    identity.write_bytes(b''.join(struct.pack('<II',at,size)+elf.read(at,size)for at,size in ((0x127C80,840),(0x1278B8,964),(0x239BE8,64))))
    pcm_path=ROOT/'build-native-sjuni/adx-stereo-fixtures.json'
    abi_path=ROOT/'build-native-sjuni/adx-stereo-abi-fixtures.json'
    if sha(pcm_path)!=PCM_SHA or sha(abi_path)!=ABI_SHA:raise ValueError('Independent original fixture changed')
    pcm=json.loads(pcm_path.read_text());abi=json.loads(abi_path.read_text())
    if abi['identity']['frozen_pcm_fixture_sha256']!=PCM_SHA:raise ValueError('ABI and PCM proof differ')
    if sha(ROOT/'tools/native_reconstruction/test_adx_stereo_oracle.py')!=abi['identity']['exporter_sha256']:
        raise ValueError('Original ABI exporter changed')
    for name,digest in pcm['identity']['tool_sha256'].items():
        if Path(name).name!=name or sha(ROOT/'tools/native_reconstruction'/name)!=digest:raise ValueError('Original engine changed')
    pcm_cases={c['name']:c for c in pcm['cases']}
    cases=[c for c in abi['cases']if c['input']['mode']in('normal','downmix')and 1<=c['input']['requested_i32']<=16]
    if len(cases)!=166:raise ValueError('Expected166 direct lower-kernel positive-count original cases')
    wire=bytearray(struct.pack('<I',len(cases)))
    for case in cases:
        i=case['input'];e=case['expected'];s=e['state'];a=case['abi_input'];original=pcm_cases[case['name']]
        if i!=original['input']or s!=original['expected']['state']:raise ValueError('ABI/PCM case mismatch')
        if a['caller_sp']!=0x701000 or bytes.fromhex(a['caller_argument_bytes_hex'])[:4]!=struct.pack('<I',0x440000):
            raise ValueError('ABI synthetic address layout changed')
        encoded=bytes.fromhex(i['encoded_hex'])
        wire.extend(struct.pack('<Ii',i['mode']=='downmix',i['requested_i32']))
        wire.extend(struct.pack('<iiiiiiIiiI',*i['history_i16'],*i['coefficients_i16'],i['key_u16'],
            i['multiplier_i16'],i['addend_i16'],len(encoded)));wire.extend(encoded)
        wire.extend(struct.pack('<II',a['caller_sp'],a['return_address']))
        frame=bytes.fromhex(a['frame_hex']);caller=bytes.fromhex(a['caller_argument_bytes_hex'])
        if len(frame)!=112 or len(caller)!=24:raise ValueError('ABI frame size changed')
        wire.extend(frame);wire.extend(caller)
        wire.extend(struct.pack('<9Q',*(a['incoming_saved_gprs_u64'][str(n)]for n in [16,17,18,19,20,21,22,23,30])))
        wire.extend(struct.pack('<iiiiiIII',e['return_i32'],*s['history_i16'],s['key_u16'],
            original['expected']['pcm_store_count']//64,len(s['left_pcm_i16'])))
        for plane in ['left_pcm_i16','right_pcm_i16']:
            wire.extend(struct.pack('<'+'h'*len(s[plane]),*s[plane]))
        finalframe=bytes.fromhex(e['frame_hex'])
        if len(finalframe)!=112:raise ValueError('Final original frame size changed')
        wire.extend(finalframe);wire.extend(struct.pack('<II',e['pc'],e['branch_pc']))
    case_path=out/'cases.bin';case_path.write_bytes(wire)
    sources=[*HERE.glob('*'),HERE.parent/'runtime_adapter.cpp',HERE.parent/'runtime_adapter.h',
        ROOT/'game/native/adx_stereo/adx_stereo.cpp',ROOT/'game/native/adx_stereo/adx_stereo.hpp',
        ROOT/'recomp/overrides/native_geometry/reo_vu_native_sha256.h']
    receipt=dict(schema=1,status='running',compiler=cxx,compiler_sha256=sha(Path(cxx)),
        fixture_sha256=PCM_SHA,abi_fixture_sha256=ABI_SHA,elf_sha256=elf.sha256,
        direct_positive_oracle_cases=len(cases),identity_transport_sha256=sha(identity),case_transport_sha256=sha(case_path),
        game_run=False,runtime_linked=False,source_sha256={f.relative_to(ROOT).as_posix():sha(f)for f in sources if f.is_file()},checks=[])
    env=dict(os.environ);compiler=Path(cxx).resolve();bins=[compiler.parent,compiler.parent.parent/'x86_64-w64-mingw32/bin']
    env['PATH']=os.pathsep.join(str(b)for b in bins if b.is_dir())+os.pathsep+env.get('PATH','')
    def run(name,cmd):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,capture_output=True,text=True,timeout=90)
        receipt['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr))
        if r.returncode:print(r.stdout,r.stderr);raise RuntimeError(name+' failed')
        lines=[line for line in r.stderr.splitlines()if 'native op='in line]
        if name=='trace':
            if len(lines)!=12 or [int(line.split('calls=')[1].split()[0])for line in lines]!=[1,2,3,4,8,16]*2:
                raise RuntimeError('Postcommit trace sampling differs')
        elif lines:raise RuntimeError('Unexpected native count in refusal/nontrace check')
        print(name+': passed',flush=True)
    try:
        common=[cxx,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE),'-I'+str(ROOT)]
        sources=[HERE/'harness.cpp',HERE.parent/'runtime_adapter.cpp',ROOT/'game/native/adx_stereo/adx_stereo.cpp']
        enabled=['-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_ADX_STEREO=1']
        exe=out/'checks.exe';run('mock_compile',common+enabled+sources+['-o',exe])
        for name in ['off','text','downmix-text','table','missing','missing-normal','wrong-binding','wrong-downmix','late',
            'partial-runtime1','partial-runtime2','partial-stub1','partial-stub2','fixtures','trace','allocation',
            'changed-identity','changed-normal','changed-table','stop','manual','binding-change','runtime-identity','memory-identity','refusals']:
            run(name,[exe,identity,case_path,name])
        for name,flags in [('numeric-zero',['-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_ADX_STEREO=0']),
            ('not-built',['-DREO_GAME_FILE1']),('file2',['-DREO_GAME_FILE2','-DREO_BUILD_NATIVE_ADX_STEREO=1'])]:
            disabled=out/(name+'.exe');run(name+'_compile',common+flags+sources+['-o',disabled]);run(name,[disabled,identity,case_path,'disabled'])
        if args.runtime_headers:
            dep=args.runtime_headers.resolve();receipt['real_header_sha256']=sha(dep/'ps2xRuntime/include/ps2_runtime.h')
            run('real_header_object',[cxx,'-std=c++20','-O1','-Wall','-Wextra','-Werror','-mssse3','-msse4.1',
                '-Wno-unused-variable','-Wno-unused-parameter',*enabled,'-I'+str(dep/'ps2xRuntime/include'),
                '-I'+str(dep/'ps2xRuntime/src/lib'),'-I'+str(dep/'ps2xRuntime/src/lib/Kernel'),'-I'+str(ROOT),
                '-c',HERE.parent/'runtime_adapter.cpp','-o',out/'real_adapter.o'])
        receipt['status']='passed'
    except Exception as error:receipt['status']='failed';receipt['failure']=str(error);raise
    finally:
        receipt['limitations']=[
            'Synthetic mock lifecycle/whole32MiBRAM/context checks, no actual runtime link/game.',
            '166 direct positive-count normal/downmix original ABI cases; selector wrappers excluded from adapter proof.',
            'Final112Bframe bytes and untouchedholes from independent original-word ABI export, without pointer relocation.',
            'Definedv0/SP/RA/savedGPRs/returnprotocol compared; volatileGPR/MAC observations not reconstructed.',
            'No stream/SJ/ADXT/RNA/clock/lifetime beyond synchronous authenticated guest calls.',
        ]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(out/'receipt.json')

if __name__=='__main__':main()
