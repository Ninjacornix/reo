#!/usr/bin/env python3
"""Compare both guarded adapters against the frozen large original-word corpus."""
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
FIXTURE_SHA='b49e2df608718db12b325903c46b2c1c132fcdf67c4472d0b10d06a90a84d514'


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def wire_segments(rows):
    data=bytearray(struct.pack('<I',len(rows)))
    for address,content in rows:
        data.extend(struct.pack('<II',address,len(content)));data.extend(content)
    return data


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',required=True);parser.add_argument('--output',required=True,type=Path)
    args=parser.parse_args();compiler=shutil.which(args.cxx)
    if not compiler:parser.error('Existing C++20 compiler required')
    out=args.output.resolve();allowed=ROOT/'build-native-sjuni'
    if out==allowed or not out.is_relative_to(allowed):parser.error('Use ignored output')
    fixture_path=allowed/'adx-large-block-fixtures.json'
    if sha(fixture_path)!=FIXTURE_SHA:raise ValueError('Frozen large corpus changed')
    fixture=json.loads(fixture_path.read_text())
    if sha(ROOT/'tools/native_reconstruction/adx_large_block_oracle.py')!=fixture['identity']['generator_sha256']:
        raise ValueError('Large original wrapper changed')
    for name,digest in fixture['identity']['tool_sha256'].items():
        if Path(name).name!=name or sha(ROOT/'tools/native_reconstruction'/name)!=digest:raise ValueError('Original engine changed')
    sys.path.insert(0,str(ROOT/'tools/function_index'))
    from index import Elf
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    out.mkdir(parents=True,exist_ok=True)
    identity=out/'identity.bin';identity.write_bytes(wire_segments([(at,elf.read(at,size)) for at,size in
        ((0x1276D8,0x1DC),(0x127C80,840),(0x1278B8,964),(0x239BE8,64))]))
    env=dict(os.environ);cc=Path(compiler).resolve();env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','')
    sources=[Path(__file__),HERE/'large_harness.cpp']
    for kind in ('native_adx_block','native_adx_stereo'):
        path=ROOT/'recomp/overrides'/kind
        sources.extend([path/'runtime_adapter.cpp',path/'runtime_adapter.h',*path.joinpath('tests').glob('*.h')])
    for kind in ('adx_block','adx_stereo'):
        sources.extend([ROOT/f'game/native/{kind}/{kind}.cpp',ROOT/f'game/native/{kind}/{kind}.hpp'])
    receipt=dict(schema=1,status='running',fixture_sha256=FIXTURE_SHA,compiler=compiler,compiler_sha256=sha(cc),
        game_run=False,runtime_linked=False,source_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in sources},checks=[])
    try:
        for kind in ('mono','stereo'):
            cases=[c for c in fixture['cases'] if (c['mode']=='mono')==(kind=='mono')]
            data=bytearray(struct.pack('<I',len(cases)))
            for case in cases:
                i,e=case['input'],case['expected'];state=e['state'];abi=e['original_abi'];is_mono=case['mode']=='mono'
                count=i['requested_i32'];admitted=case['proposed_adapter_count_admitted']
                if admitted!=(1<=count<=512):raise ValueError('Count-admission annotation changed')
                registers=abi['initial_gpr_lower64'];encoded=bytes.fromhex(i['encoded_hex'])
                capacity=i['output_capacity_samples' if is_mono else 'output_capacity_samples_per_plane']
                outputs=[registers[6]] if is_mono else [registers[6],registers[8]]
                history=0x420000 if is_mono else 0x430000;key=0x430000 if is_mono else 0x440000
                initial=[(registers[4],encoded),
                    *[(at-8,b'\xA5'*(capacity*2+16)) for at in outputs],
                    (history,struct.pack('<'+'h'*len(i['history_i16']),*i['history_i16'])),(key,struct.pack('<H',i['key_u16'])),
                    (abi['frame_address'],bytes.fromhex(abi['initial_frame_hex'])),
                    (abi['frame_address']-16,bytes.fromhex(abi['initial_lower_stack_guard_hex'])),
                    (abi['caller_stack_address'],bytes.fromhex(abi['caller_argument_bytes_hex']))]
                planes=[state['pcm_i16']] if is_mono else [state['left_pcm_i16'],state['right_pcm_i16']]
                final=[*[(at,struct.pack('<'+'h'*len(pcm),*pcm)) for at,pcm in zip(outputs,planes)],
                    (history,struct.pack('<'+'h'*len(state['history_i16']),*state['history_i16'])),(key,struct.pack('<H',state['key_u16'])),
                    (abi['frame_address'],bytes.fromhex(abi['final_frame_hex'])),
                    (abi['caller_stack_address'],bytes.fromhex(abi['final_caller_argument_bytes_hex'])),
                    (abi['frame_address']-16,bytes.fromhex(abi['final_lower_stack_guard_hex']))]
                entry=0x1276D8 if is_mono else 0x127C80 if case['mode']=='normal' else 0x1278B8
                data.extend(struct.pack('<I32QI',admitted,*registers,entry));data.extend(wire_segments(initial));data.extend(wire_segments(final))
                data.extend(struct.pack('<iII',e['return_i32'],abi['final_pc_u32'],abi['return_branch_pc']))
            transport=out/(kind+'.bin');transport.write_bytes(data)
            adapter=ROOT/'recomp/overrides'/('native_adx_block' if kind=='mono' else 'native_adx_stereo')
            core=ROOT/'game/native'/('adx_block' if kind=='mono' else 'adx_stereo')
            enabled='REO_BUILD_NATIVE_ADX_BLOCK' if kind=='mono' else 'REO_BUILD_NATIVE_ADX_STEREO'
            exe=out/(kind+'.exe')
            command=[compiler,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror',
                '-DREO_GAME_FILE1','-D'+enabled+'=1',*(['-DLARGE_STEREO'] if kind=='stereo' else []),
                '-I'+str(adapter/'tests'),'-I'+str(ROOT),str(HERE/'large_harness.cpp'),
                str(adapter/'runtime_adapter.cpp'),str(core/(core.name+'.cpp')),'-o',str(exe)]
            build=subprocess.run(command,env=env,capture_output=True,text=True,timeout=90)
            row=dict(kind=kind,command=command,compile_exit_code=build.returncode,compile_stderr=build.stderr,
                transport_sha256=sha(transport),cases=len(cases));receipt['checks'].append(row)
            if build.returncode:raise RuntimeError(build.stderr)
            run=subprocess.run([str(exe),str(identity),str(transport)],env=env,capture_output=True,text=True,timeout=90)
            row.update(exit_code=run.returncode,stdout=run.stdout,stderr=run.stderr)
            if run.returncode:raise RuntimeError(run.stderr)
            print(kind+': '+run.stdout.strip(),flush=True)
        receipt['status']='passed'
    except Exception as error:
        receipt.update(status='failed',failure=str(error));raise
    finally:
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')


if __name__=='__main__':main()
