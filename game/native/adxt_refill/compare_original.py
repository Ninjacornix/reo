#!/usr/bin/env python3
"""Input-only native refill transport; independently projected original evidence."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
import sjrb_oracle as original_ring

FIXTURE_SHA='366dcf38ac63e9d2c88c4be1392e9914d82925c87e0e5e1fbcc506aad7706b52'
INPUT_SHA='1f6253974eb701d83a6912dadcdcb09c321cae533009c8ca9dc2030c16e10572'
BUFFER,POOL,SCRATCH=0x400010,0x224C60,0x630004
UNSAFE={'reset-loses-outstanding-reservation','ring-reset-reuse-late-external-write','reset-close-late-external-write'}


def sha(data): return hashlib.sha256(data).hexdigest()
def canonical(value): return (json.dumps(value,sort_keys=True,indent=2)+'\n').encode()
def require(condition,message):
    if not condition: raise RuntimeError(message)


def commands(case):
    require('expected' not in json.dumps(case),'Expected output entered native transport')
    values=[case[k] for k in ('capacity','start_sector','byte_length','threshold','max_request_bytes','max_sectors',
        'target','finite_limit','retry_limit','position','occupied','callback')]
    values[-1]=int(values[-1]);lines=[' '.join(map(str,values))+' '+case['file_hex']]
    for index,action in enumerate(case['actions']):
        statuses=action.get('statuses',[0]);acceptance=action.get('accept',0)
        if acceptance=='requested': acceptance=-999
        error=int(len(statuses)>1 and statuses[1]==3)
        value=action.get('value',action.get('bytes',0))
        lines.append(f"{index} {action['kind']} {statuses[0]} {acceptance} {error} {value}")
        if action['kind']=='reset': break # Unsafe original behavior is a native before-effects refusal.
    return '\n'.join(lines)+'\n'


def project(state):
    raw=bytes.fromhex(state['record_hex']);q=state['ring_u32']
    def u(offset,size=4): return int.from_bytes(raw[offset:offset+size],'little')
    def s(offset,size=4): return int.from_bytes(raw[offset:offset+size],'little',signed=True)
    return dict(ring=[q[i] for i in (8,9,3,4,5,6,10,11,12,13)],
        source=[s(1,1),s(0x1C),s(0x54),s(0x30),s(3,1),u(0x40,1),u(2,1),u(0x43,1),u(0x44,1),
                u(0x42,1),int(u(8)!=0 and u(0x45,1)==1),u(0x20)-BUFFER if u(0x20) else 0,s(0x24)])


def original_view(state,proofs):
    """Execute actual Get/Unget on a clone; never host-calculate a ring grant."""
    q=state['ring_u32'];machine=original_ring.Machine(q[8],q[9])
    for i,value in enumerate(q): machine.mem.store(POOL+i*4,4,value)
    physical=bytes.fromhex(state['backing_guard_hex'])
    for i,value in enumerate(physical): machine.mem.store(BUFFER-16+i,1,value)
    got=machine.run('get',[POOL,1,q[8],original_ring.SLOTS])
    require(got['status']=='returned','Derived original published-view Get failed')
    pointer,length=machine.mem.words(original_ring.SLOTS,2)
    result=dict(offset=pointer-BUFFER,bytes=length,hex=machine.bytes(pointer,length).hex())
    returned=machine.run('unget',[POOL,1,original_ring.SLOTS])
    require(returned['status']=='returned' and machine.mem.words(POOL,16)==q,'Derived original view did not restore credit')
    proofs.append(dict(get_instructions=got['original_instructions'],unget_instructions=returned['original_instructions'],
        visited_pcs=sorted(set(got['visited_pcs']+returned['visited_pcs'])),view=result))
    return result


def captured_get_view(call):
    outputs={}
    for write in call['writes']:
        if write['address'] in (SCRATCH,SCRATCH+4): outputs[write['address']]=int.from_bytes(bytes.fromhex(write['value_hex']),'little')
    require(set(outputs)=={SCRATCH,SCRATCH+4},'Missing captured original Get descriptor')
    pointer,size=outputs[SCRATCH],outputs[SCRATCH+4]
    backing=bytes.fromhex(call['after']['backing_guard_hex']);offset=pointer-BUFFER
    require(0<=offset<=offset+size<=len(backing)-32,'Original read extent out of backing')
    return dict(offset=offset,bytes=size,hex=backing[16+offset:16+offset+size].hex())


def projection(case,observed,proofs):
    if case['name']=='partial-sector-file-length': return [dict(constructor_refused=True)]
    rows=[dict(index=-1,sub=0,state=project(observed['initial']),callbacks=[],view=original_view(observed['initial'],proofs))]
    for index,operation in enumerate(observed['operations']):
        kind=operation['input']['kind']
        if kind=='reset':
            before=operation['expected']['before']
            rows.append(dict(index=index,sub=0,state=project(before),callbacks=[],view=original_view(before,proofs),refusal_status=1))
            break
        if kind=='write_job':
            after=operation['external_effect']['after']
            rows.append(dict(index=index,sub=0,state=project(after),callbacks=[],view=original_view(after,proofs)));continue
        results=operation['expected'];results=[results] if isinstance(results,dict) else results
        for sub,result in enumerate(results):
            require(result['status']=='returned','Original partial result entered admission')
            callbacks=[project(event['observed_before']) for event in result['events'] if event['kind']=='target_callback']
            rows.append(dict(index=index,sub=sub,state=project(result['after']),callbacks=callbacks,
                view=captured_get_view(result) if kind=='consume' and sub==0 else original_view(result['after'],proofs)))
    return rows


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler',required=True);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();output=args.output.resolve()
    require(not output.exists(),'Choose a new output directory; preserve earlier receipts')
    output.mkdir(parents=True)
    fixture_path=ROOT/'build-native-sjuni/adxt-refill-oracle-v2/original-fixture.json'
    require(sha(fixture_path.read_bytes())==FIXTURE_SHA,'Original cohort changed')
    fixture=json.loads(fixture_path.read_bytes());input_path=ROOT/fixture['inputs_file']
    require(sha(input_path.read_bytes())==INPUT_SHA,'Original authored inputs changed')
    inputs=json.loads(input_path.read_bytes());frozen_path=HERE/'frozen_identity.json';frozen=json.loads(frozen_path.read_bytes())
    for name,digest in frozen['files'].items(): require(sha((ROOT/name).read_bytes())==digest,'Frozen native source/dependency changed: '+name)
    for name,digest in fixture['engine_sha256'].items(): require(sha((ROOT/'tools/native_reconstruction'/name).read_bytes())==digest,'Original engine changed: '+name)
    proofs=[];expected={case['name']:projection(case,observed,proofs) for case,observed in zip(inputs['cases'],fixture['cases'],strict=True)}
    projected_path=output/'projected-original.json'
    projected_path.write_bytes(canonical(dict(provenance='Frozen original snapshots plus actual cloned SJRB Get/Unget words; authored before native execution.',
        fixture_sha256=FIXTURE_SHA,inputs_sha256=INPUT_SHA,core_freeze_sha256=sha(frozen_path.read_bytes()),
        read_view_proofs=proofs,cases=expected)))
    compiler=shutil.which(args.compiler) or args.compiler;binary=output/'fixture_runner.exe'
    sources=[HERE/'adxt_refill.cpp',HERE/'fixture_runner.cpp',ROOT/'game/native/sjrb/sjrb.cpp',
        ROOT/'game/native/resource_io/async_read_owner.cpp',ROOT/'game/native/resources/resource_session.cpp',ROOT/'game/native/tasks/serial_worker.cpp']
    build=subprocess.run([compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',*map(str,sources),'-o',str(binary)],capture_output=True,text=True)
    (output/'compiler.stdout.txt').write_text(build.stdout);(output/'compiler.stderr.txt').write_text(build.stderr)
    require(build.returncode==0,'Native input runner failed compile; retained compiler stderr')
    observations=[];compared_records=0;payload_bytes=0
    for case in inputs['cases']:
        name=case['name'];wire=output/(name+'.input.txt');wire.write_text(commands(case))
        ran=subprocess.run([str(binary),str(wire)],capture_output=True,text=True)
        (output/(name+'.stdout.jsonl')).write_text(ran.stdout);(output/(name+'.stderr.txt')).write_text(ran.stderr)
        require(ran.returncode==0,'Native runner failure: '+name+' '+ran.stderr)
        rows=[json.loads(line) for line in ran.stdout.splitlines()]
        require(len(rows)==len(expected[name]),'Observation count mismatch: '+name)
        for index,(actual,want) in enumerate(zip(rows,expected[name],strict=True)):
            if 'constructor_refused' in want: require(actual==want,'Missing before-effects constructor refusal');continue
            status=actual.pop('status')
            allowed=(want['refusal_status'],) if 'refusal_status' in want else (0,8)
            require(status in allowed,'Unexpected native status '+name)
            projected={k:v for k,v in want.items() if k!='refusal_status'}
            require(actual==projected,f'Native observable mismatch: {name} record{index}; expected retained in projected-original.json')
            compared_records+=1;payload_bytes+=actual['view']['bytes']
        observations.append(dict(name=name,records=len(rows),classification='constructor_refusal' if name=='partial-sector-file-length' else
            'pending_reset_refusal' if name in UNSAFE else 'admitted_observable_projection',input_sha256=sha(wire.read_bytes())))
    receipt=dict(schema=1,provenance='No game/device; input-only typed native owner versus independent original observable projection.',
        compiler=compiler,compiler_sha256=sha(Path(compiler).read_bytes()),binary_sha256=sha(binary.read_bytes()),
        core_freeze_sha256=sha(frozen_path.read_bytes()),fixture_sha256=FIXTURE_SHA,inputs_sha256=INPUT_SHA,
        transport_sha256=sha((HERE/'fixture_runner.cpp').read_bytes()),comparator_sha256=sha(Path(__file__).read_bytes()),
        projected_original_sha256=sha(projected_path.read_bytes()),records=compared_records,published_read_bytes=payload_bytes,
        derived_original_view_calls=len(proofs)*2,derived_original_view_instructions=sum(p['get_instructions']+p['unget_instructions'] for p in proofs),
        cases=observations,exclusions=['Raw unpublished backing/pixel/stack/volatileGPR artifacts and host scheduling.',
            '2049-byte partial-sector source refuses before constructor effects; three pending reset/reuse/latewrite rows refuse at reset.',
            'Extra production DataLease read+unget0 observations preserve original ring state; no raw backing escape or expected input to runner.'])
    (output/'receipt.json').write_bytes(canonical(receipt));print(json.dumps({k:receipt[k] for k in ('records','published_read_bytes','derived_original_view_calls','derived_original_view_instructions')},indent=2))


if __name__=='__main__': main()
