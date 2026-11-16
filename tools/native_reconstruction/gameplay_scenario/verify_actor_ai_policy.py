"""Small complete702C50 original/native/VM cohort over the real LLVM graph."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(HERE.parent))
from verify_native_session import dependency_sources

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main(args):
    compiler=args.compiler.resolve();build=args.native_build.resolve();out=args.output.resolve()
    assert compiler.name=='x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    original_sources=[ROOT/'recomp/config/output_ovl/o2'/name for name in ('o2_00702C50_0x702c50.cpp','o2_007029E0_0x7029e0.cpp')]
    body='\n'.join(source.read_text() for source in original_sources);raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    words=re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',body)
    for pc,opcode in words:assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(opcode,16)
    assert struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+8*0x1a8)==(0x702c50,0,0,0,0)
    assert struct.unpack_from('<I',raw,0x717830-0x570000+4*0x1a8)[0]==0x68cd80
    assert struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+8*0x1a4)==(0x7029e0,1,1,1,0)
    assert struct.unpack_from('<I',raw,0x717830-0x570000+4*0x1a4)[0]==0x68cd80
    reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'
    (out/'original_fixture.hpp').write_bytes(reference.read_bytes())
    (out/'original.cpp').write_text('#include "original_fixture.hpp"\n'+'\n'.join(line for line in body.splitlines() if not line.startswith('#include')))
    sources,libraries=dependency_sources(build)
    sources.extend([Path(__file__).resolve(),*original_sources,reference,HERE/'actor_ai_policy_tests.cpp',ROOT/'game/native/gameplay_scenario/actor_ai_policy.hpp'])
    before={p.relative_to(ROOT).as_posix():sha(p) for p in sources}
    library_hashes={name:sha(build/name) for name in libraries}
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    commands=[]
    def run(command,label):
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=240)
        (out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr)
        commands.append(dict(command=command,exit_code=result.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt'))))
        if result.returncode:raise RuntimeError(label+': '+result.stderr[-4000:])
    base=[str(compiler),'-std=c++20','-O2','-msse4.1','-pthread','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out)]
    run(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],'compile-original')
    run(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(HERE/'actor_ai_policy_tests.cpp'),'-o',str(out/'tests.o')],'compile-tests')
    run([str(compiler),str(out/'tests.o'),str(out/'original.o'),'-Wl,--start-group']+[str(build/name) for name in libraries]+['-Wl,--end-group','-lpthread','-o',str(out/'checks.exe')],'link')
    run([str(out/'checks.exe')],'test')
    assert all(sha(ROOT/name)==digest for name,digest in before.items())
    assert all(sha(build/name)==digest for name,digest in library_hashes.items())
    # Actual stock caller locations/payloads, including conditional bodies.
    members=json.loads((ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json').read_text())
    contexts=[]
    for member in members:
        if member['format']!='E':continue
        with Path(member['archive']).open('rb') as stream:stream.seek(member['archive_offset']);bank=stream.read(member['bytes'])
        assert hashlib.sha256(bank).hexdigest()==member['sha256']
        records=[]
        for obj in member['declared_objects']:
            if obj['role']!=0:continue
            at=0
            while at<obj['upper_bound_bytes']:
                header=struct.unpack_from('<I',bank,obj['offset']+at)[0];extent=4<<(header>>24)
                assert extent<=obj['upper_bound_bytes']-at
                opcode=header&0xffffff
                if opcode in (0x1a4,0x1a8):
                    record=dict(opcode=hex(opcode),block=obj['table_index'],offset=at,bytes=extent)
                    if opcode==0x1a4:record.update(selector=struct.unpack_from('<I',bank,obj['offset']+at+4)[0],value=struct.unpack_from('<I',bank,obj['offset']+at+8)[0])
                    else:record['value']=struct.unpack_from('<I',bank,obj['offset']+at+4)[0]
                    records.append(record)
                at+=extent
        contexts.append(dict(name=member['name'],sha256=member['sha256'],profile='offline_actor',records=records))
    receipt=dict(schema='reo.native.actor_ai_policy.v1',status='passed',compiler=str(compiler),compiler_sha256=sha(compiler),source_sha256=before,native_library_sha256=library_hashes,
        commands=commands,result=json.loads((out/'test.stdout.txt').read_text()),executable_sha256=sha(out/'checks.exe'),generated_original_sha256=sha(out/'original.cpp'),generated_fixture_sha256=sha(out/'original_fixture.hpp'),checked_owned_instruction_comments=len(words),stock_contexts=contexts,
        limitations=['Static authored locations do not establish dynamic reachability.','81C500 damage/action consumers remain unavailable; this cohort qualifies the complete policy command and actual Update/VM caller only.','No gameplay, installed candidate or Stage4 completion is claimed.'],stage4_complete=False,game_launched=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',result=receipt['result'],stock_records=sum(len(row['records']) for row in contexts))))

if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);main(p.parse_args())
