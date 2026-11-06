#!/usr/bin/env python3
"""Input-only typed header owner against frozen original math/header evidence."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
FIXTURE_SHA='7ffa76de4fe5aa56e4825c1a4a25ed591d5dfefe0331807848498974707a7158'
LLVM_SHA='0e2b3fd61fdcad1fe4f6f7fb479165dc6fe706bf12427e5533787371ed8d0d8f'
INPUT_SHA='ab304db5087b8c476b3e818c60d35da2fbaa9915161b71f6d0615391de0fc843'

def sha(data):return hashlib.sha256(data).hexdigest()
def canonical(value):return (json.dumps(value,sort_keys=True,indent=2)+'\n').encode()
def require(ok,message):
    if not ok:raise RuntimeError(message)

def commands(case):
    require('"expected":' not in json.dumps(case),'Expected output entered native input')
    length=case['supplied_length']
    if length is None:length=len(bytes.fromhex(case['header_hex']))
    values=[case['kind'],case['position'],length,case.get('rate',0),case.get('filter_value',0),
            *case['configured_key'],*case['fallback_key'],case['header_hex'] or '-']
    return ' '.join(map(str,values))+'\n'

def project(state):
    i,p,o,k=(bytes.fromhex(state[name]) for name in ('inner_hex','predictor_hex','outer_hex','key_global_hex'))
    u=lambda data,offset,size=4:int.from_bytes(data[offset:offset+size],'little')
    s=lambda data,offset,size=4:int.from_bytes(data[offset:offset+size],'little',signed=True)
    role=lambda address:1 if address==0x410010 else 0
    require(u(i,0x3C)==0x410010,'Unknown original PCM role')
    require(u(i,0x5C) in (0x410010,0x6D6D6D6D),'Unknown original active PCM relation')
    q=state['ring_u32']
    return dict(decoder=dict(phase=u(i,2,2),base=[s(i,0xC,1),s(i,0xD,1),s(i,0xF,1),s(i,0xE,1),u(i,0x14),u(i,0x18),s(i,0x10)],
        filter=s(i,0x1C,2),tag=s(i,0x98,2),configured_key=list(struct.unpack_from('<3H',i,0x9C)),
        history=list(struct.unpack_from('<4h',p,0x28)),coefficients=list(struct.unpack_from('<2h',p,0x30)),key=list(struct.unpack_from('<3H',p,0x34)),
        loop=[s(i,0x20),u(i,0x24,2),u(i,0x26,2),*[u(i,offset) for offset in (0x28,0x2C,0x30,0x34)]],
        ainf=dict(value=u(i,0xC8),payload=i[0xCC:0xDC].hex(),halves=[u(i,offset,2) for offset in (0xDC,0xDE,0xE0)]),
        borrowed_pcm=[s(i,0x40),s(i,0x44),role(u(i,0x3C))],active_pcm=[s(i,0x60),s(i,0x64),role(u(i,0x5C))],
        output_channels=s(i,0x38),active=[s(i,offset) for offset in (0x50,0x54,0x58,0x8C)]),
        outer=[u(o,1,1),u(o,3,1),u(o,0x98)],ring=[q[n] for n in (8,9,3,4,5,6,10,11,12,13)],
        keys=[u(k,0),*[u(k,offset,2) for offset in (0x10,0x12,0x14)]])

def helper(state,kind):
    data=bytes.fromhex(state['helper_output_hex'])
    u=lambda offset,size=4:int.from_bytes(data[offset:offset+size],'little')
    s=lambda offset,size=4:int.from_bytes(data[offset:offset+size],'little',signed=True)
    if kind=='base':return [u(0,2),u(4,1),u(5,1),u(6,1),u(7,1),u(16),u(32),s(36)]
    if kind=='version':return [u(0,1),u(4,1)]
    if kind=='filter':return [u(0,2)]
    if kind=='history':return [u(offset,2) for offset in (0,2,4,6)]
    if kind=='loop':return [s(0),u(4,2),u(6,2),*[u(offset) for offset in (16,20,24,32)]]
    if kind=='ainf':return dict(value=u(0),payload=data[4:20].hex(),halves=[u(offset,2) for offset in (32,36,38)])
    if kind=='key':return [u(offset,2) for offset in (0,2,4)]
    if kind=='math':return [s(0,2),s(2,2)]
    if kind=='outer':return None
    raise RuntimeError('Unknown original helper output')

def expected(case,observed):
    result=observed['result'];kind=case['kind']
    if result['failure']:
        require(result['failure']['pc']==0x120AE8,'New partial domain needs explicit classification')
        # Explicit native safety/profile difference. Original partial observations
        # stay untouched; native decoder/context refuses BEFORE those mutations,
        # and whole source Get/Unget activity is acknowledged, not called fallback.
        state=result['before']
        return dict(status=1,state=project(state),helper=helper(state,kind),return_=None,diagnostics=[])
    diagnostics=[]
    for event in result['events']:
        if event['kind']!='diagnostic':continue
        address=event['arguments_u64'][0]
        require(address in (0x239B68,0x23AD50),'Unknown original diagnostic contract')
        diagnostics.append(dict(kind=0 if address==0x239B68 else 1,state=project(event['observed_before'])))
    returned=None
    if kind not in ('outer','math'):
        require(result['return_is_defined'],'Missing original defined helper return')
        returned=(result['raw_v0_lower64_observation_only']&0xFFFFFFFF)
        if returned>=0x80000000:returned-=0x100000000
    return dict(status=0,state=project(result['after']),helper=helper(result['after'],kind),return_=returned,diagnostics=diagnostics)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--compiler',required=True);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve();require(not out.exists(),'Choose unused output directory; preserve earlier evidence');out.mkdir(parents=True)
    base=ROOT/'build-native-sjuni/adx-header-math-oracle-v4';fixture_path=base/'gcc/original-fixture.json';llvm_path=base/'llvm/original-fixture.json';inputs_path=base/'gcc/inputs.json'
    require(sha(fixture_path.read_bytes())==FIXTURE_SHA and sha(llvm_path.read_bytes())==LLVM_SHA,'Original header/math fixtures changed')
    require(sha(inputs_path.read_bytes())==INPUT_SHA,'Original authored input changed')
    original=json.loads(fixture_path.read_bytes());llvm=json.loads(llvm_path.read_bytes());inputs=json.loads(inputs_path.read_bytes())
    require(original['cases']==llvm['cases'],'Cross-compiler original finite/partial observations differ')
    frozen_path=HERE/'frozen_identity.json';frozen=json.loads(frozen_path.read_bytes())
    for path,digest in frozen['files'].items():require(sha((ROOT/path).read_bytes())==digest,'Frozen core/dependency changed: '+path)
    for name,digest in original['engine_sha256'].items():require(sha((ROOT/'tools/native_reconstruction'/name).read_bytes())==digest,'Original oracle/engine changed: '+name)
    table=list(map(int,re.findall(r'-?\d+',(HERE/'key_table.inc').read_text().split('\n',2)[2])))
    require(len(table)==1024 and sha(struct.pack('<1024h',*table))==frozen['key_table_packed_sha256'],'Owned key table mismatch')
    projected={case['name']:expected(case,row) for case,row in zip(inputs['cases'],original['cases'],strict=True)}
    (out/'projected-original.json').write_bytes(canonical(dict(provenance='Plain projection of frozen actual original snapshots/outputs/diagnostics; prepared before native compilation and output.',
        fixture_sha256=FIXTURE_SHA,inputs_sha256=INPUT_SHA,cases=projected)))
    compiler=shutil.which(args.compiler) or args.compiler;binary=out/'fixture_runner.exe'
    sources=[HERE/'adx_header.cpp',HERE/'fixture_runner.cpp',ROOT/'game/native/adxt_refill/adxt_refill.cpp',ROOT/'game/native/sjrb/sjrb.cpp',
        ROOT/'game/native/resource_io/async_read_owner.cpp',ROOT/'game/native/resources/resource_session.cpp',ROOT/'game/native/tasks/serial_worker.cpp']
    command=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-pthread',*map(str,sources),'-o',str(binary)]
    build=subprocess.run(command,capture_output=True,text=True);(out/'compiler.stdout.txt').write_text(build.stdout);(out/'compiler.stderr.txt').write_text(build.stderr)
    require(build.returncode==0,'Native runner failed compile; retained compiler stderr')
    records=[];scalar_fields=0;diagnostic_count=0
    for case,row in zip(inputs['cases'],original['cases'],strict=True):
        name=case['name'];wire=out/(name+'.input.txt');wire.write_text(commands(case));ran=subprocess.run([str(binary),str(wire)],capture_output=True,text=True)
        (out/(name+'.stdout.json')).write_text(ran.stdout);(out/(name+'.stderr.txt')).write_text(ran.stderr)
        require(ran.returncode==0,'Native runner failure: '+name+' '+ran.stderr)
        actual=json.loads(ran.stdout);actual['return_']=actual.pop('return')
        require(actual==projected[name],'Native projected mismatch: '+name+' (observed and projected files retained)')
        scalar_fields+=len(actual['state']['ring'])+len(actual['state']['outer'])+len(actual['state']['decoder']['base'])+len(actual['state']['keys'])
        diagnostic_count+=len(actual['diagnostics'])
        records.append(dict(name=name,classification='unsupported_before_parser_effects' if row['result']['failure'] else 'admitted_original_projection',
            kind=case['kind'],input_sha256=sha(wire.read_bytes())))
    receipt=dict(schema=1,provenance='Ordinary typed native parser/math+shared source owner compared after honest freeze; no game/device.',
        compiler=compiler,compiler_sha256=sha(Path(compiler).read_bytes()),compile_command=command,binary_sha256=sha(binary.read_bytes()),
        core_freeze_sha256=sha(frozen_path.read_bytes()),original_fixture_sha256=FIXTURE_SHA,original_llvm_fixture_sha256=LLVM_SHA,
        inputs_sha256=INPUT_SHA,projected_original_sha256=sha((out/'projected-original.json').read_bytes()),
        transport_sha256=sha((HERE/'fixture_runner.cpp').read_bytes()),comparator_sha256=sha(Path(__file__).read_bytes()),
        compared_cases=len(records),admitted=45,unsupported_controls=3,diagnostic_observations=diagnostic_count,baseline_scalar_observations=scalar_fields,
        cases=records,exclusions=['Original host FP exception accumulation/sourceFCR and volatile register/stack artifacts; native math preserves caller environment.',
            'Three original partial math cases use declared native before-parser-state refusal; source Get+Unget activity remains observable, never original fallback.',
            'PCM pointer values normalize only known borrowed/active equality roles; geometry metadata is not PCM storage ownership.'])
    path=out/'receipt.json';path.write_bytes(canonical(receipt));print(json.dumps({key:receipt[key] for key in ('compared_cases','admitted','unsupported_controls','diagnostic_observations','baseline_scalar_observations')},indent=2))

if __name__=='__main__':main()
