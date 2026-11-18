#!/usr/bin/env python3
"""Host-only guarded position pilot checks against the frozen original corpus."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
FIXTURE_SHA='232d07ee2991cb07f25bc65247db597aa2a85f6080ef8d1bff47c45b5fa94822'
RANGES=[(0x16F338,252),(0x171530,16),(0x171E58,12),(0x15BA80,108),(0x10FB18,1684),
        (0x16EC90,644),(0x16F438,168),(0x240AF0,36),(0x2381A0,256)]


def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()


def segments(rows):
    data=bytearray(struct.pack('<I',len(rows)))
    for address,content in rows:data.extend(struct.pack('<II',address,len(content))+content)
    return data


def snapshot_rows(snapshot,descriptor,inner):
    fields=snapshot['source_fields_u32']
    offsets={'state':0x48,'header_numerator':0xD74,'header_scale':0xD78,'origin':0xDC4,
             'side_base':0xDDC,'bias':0xDE0,'latest_numerator':0xF00,'latest_scale':0xF04,'inner':0x1B30}
    rows=[(0x400000+offsets[key],struct.pack('<I',inner if key=='inner' else value)) for key,value in fields.items()]
    rows += [(0x400CC0,struct.pack('<168I',*snapshot['cc0_words_u32'])),
             (0x400D54,struct.pack('<10I',*snapshot['d54_words_u32'])),
             (descriptor,struct.pack('<32I',*snapshot['descriptor_words_u32'])),
             (inner+0x9D8,struct.pack('<I',snapshot['inner_fields_u32']['clock_flag'])),
             (inner+0xA08,struct.pack('<I',snapshot['inner_fields_u32']['side_counter'])),
             (0x700F80,struct.pack('<36I',*snapshot['original_frame_guard_words_u32']))]
    return rows


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--cxx',required=True);parser.add_argument('--output',required=True,type=Path)
    parser.add_argument('--runtime-headers',type=Path)
    args=parser.parse_args();compiler=shutil.which(args.cxx)
    if not compiler:parser.error('Existing C++20 compiler required')
    output=args.output.resolve()
    if output==ROOT/'build-native-sjuni' or not output.is_relative_to(ROOT/'build-native-sjuni'):
        parser.error('Use ignored private output under build-native-sjuni')
    output.mkdir(parents=True,exist_ok=True)
    fixture=ROOT/'build-native-sjuni/movie-position-oracle-v1/original-fixture.json'
    if sha(fixture)!=FIXTURE_SHA:raise ValueError('Original frozen fixture changed')
    data=json.loads(fixture.read_text())
    for name,digest in data['engine_sha256'].items():
        if Path(name).name!=name or sha(ROOT/'tools/native_reconstruction'/name)!=digest:
            raise ValueError('Original engine source changed')
    sys.path.insert(0,str(ROOT/'tools/function_index'))
    from index import Elf
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    identity=output/'identity.bin';identity.write_bytes(segments([(at,elf.read(at,size)) for at,size in RANGES]))
    # One extra case mechanically relocates an existing original input/backend
    # into the real embedded main+1F00 layout; no arithmetic expected changes.
    cases=[(case,False) for case in data['cases']]+[(data['cases'][5],True)]
    wire=bytearray(struct.pack('<I',len(cases)))
    for case,embedded in cases:
        before,after=case['expected']['before'],case['expected']['after']
        registers=before['abi']['gpr_lower64'].copy()
        # Mechanical known-caller ABI qualification; numerical expected outputs
        # remain frozen original results. RA and savedS3 stack slots follow ABI.
        inner=0x401F00 if embedded else 0x600000
        descriptor=inner+0x13C
        registers[5]=descriptor;registers[19]=0x400000;registers[31]=0x16EDF8
        initial=snapshot_rows(before,descriptor,inner)+[(0x701030,struct.pack('<I',descriptor)),
                                      (inner+0x138,struct.pack('<I',16)),
                                      (0x22F18C,struct.pack('<8I',0x400000,0,0,0,0,0,0,0))]
        final=snapshot_rows(after,descriptor,inner)+[(0x700FE8,struct.pack('<Q',0x400000)),
                                    (0x700FF0,struct.pack('<Q',0x16EDF8))]
        wire.extend(struct.pack('<32Q',*registers)+segments(initial)+segments(final)+struct.pack('<Q',after['abi']['gpr_lower64'][2]))
    fixtures=output/'cases.bin';fixtures.write_bytes(wire)
    adapter=ROOT/'recomp/overrides/native_movie_position'
    mock=ROOT/'recomp/overrides/native_adx_block/tests'
    wrapper=HERE/'mock'
    core=ROOT/'game/native/movie_position'
    sources=[Path(__file__),HERE/'check.cpp',adapter/'runtime_adapter.h',adapter/'runtime_adapter.cpp',
             core/'movie_position.cpp',core/'movie_position.hpp',*wrapper.glob('*.h'),*mock.glob('*.h')]
    receipt=dict(schema=1,status='running',fixture_sha256=FIXTURE_SHA,compiler=compiler,
        compiler_sha256=sha(Path(compiler)),identity_wire_sha256=sha(identity),case_wire_sha256=sha(fixtures),
        source_sha256={str(path.relative_to(ROOT)):sha(path) for path in sources},checks=[],game_run=False,runtime_linked=False)
    env=dict(os.environ);env['PATH']=str(Path(compiler).parent)+os.pathsep+env.get('PATH','')
    def run(name,command):
        result=subprocess.run([str(value) for value in command],capture_output=True,text=True,env=env,timeout=90)
        receipt['checks'].append(dict(name=name,command=[str(value) for value in command],exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr))
        if result.returncode:raise RuntimeError(name+': '+result.stderr)
        return result
    flags=['-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror']
    enabled=['-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_MOVIE_POSITION=1']
    inputs=[HERE/'check.cpp',adapter/'runtime_adapter.cpp',core/'movie_position.cpp']
    try:
        exe=output/'checks.exe'
        run('compile',[compiler,*flags,*enabled,'-I'+str(wrapper),'-I'+str(mock),'-I'+str(ROOT),*inputs,'-o',exe])
        for scenario in ('off','text','table','helper','missing','late','partial-runtime','partial-stub','fixtures',
                         'trace','refusals','changed-image','changed-table','changed-binding','stop','manual','memory','runtime','repeat',
                         'backing-install','backing-dispatch'):
            result=run(scenario,[exe,identity,fixtures,scenario])
            proof=[line for line in result.stderr.splitlines() if 'native op=' in line]
            if scenario=='trace':
                if [int(line.split('calls=')[1]) for line in proof]!=[1,2,3,4,8,16]:raise ValueError('Incorrect postcommit trace sampling')
            elif proof:raise ValueError('Unexpected native proof outside trace scenario')
        for name,defines in [('numeric-zero',['-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_MOVIE_POSITION=0']),
                             ('not-built',['-DREO_GAME_FILE1']),('file2',['-DREO_GAME_FILE2','-DREO_BUILD_NATIVE_MOVIE_POSITION=1'])]:
            disabled=output/(name+'.exe')
            run(name+'-compile',[compiler,*flags,*defines,'-I'+str(wrapper),'-I'+str(mock),'-I'+str(ROOT),*inputs,'-o',disabled])
            run(name,[disabled,identity,fixtures,'disabled'])
        if args.runtime_headers:
            dep=args.runtime_headers.resolve()
            receipt['actual_header_sha256']={name:sha(dep/'ps2xRuntime/include'/name)
                for name in ('ps2_runtime.h','ps2_runtime_macros.h')}
            run('actual-header-object',[compiler,'-std=c++20','-O1','-Wall','-Wextra','-Werror','-mssse3','-msse4.1',
                '-Wno-unused-variable','-Wno-unused-parameter',*enabled,
                '-I'+str(dep/'ps2xRuntime/include'),'-I'+str(dep/'ps2xRuntime/src/lib'),
                '-I'+str(dep/'ps2xRuntime/src/lib/Kernel'),'-I'+str(ROOT),'-c',adapter/'runtime_adapter.cpp','-o',output/'actual-adapter.o'])
        receipt['status']='passed'
    except Exception as error:
        receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['limitations']=['25 frozen numerical/ABI cases relocated into qualified private slots/known callerRA/savedS3 plus one embedded backend; no new numerical oracle.',
            'Mock registry/lifecycle plus whole32MiB RAM comparisons; not a linked runtime/game.',
            'Only callee-preserved/selective ABI +rawv0 compared; incoming volatile GPR/MAC state intentionally not original scratch state.',
            'Original intermediate descriptor writes and instruction-level scheduling/diagnostic history are not reproduced.']
        (output/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],checks=len(receipt['checks']),receipt=str(output/'receipt.json'))))


if __name__=='__main__':main()
