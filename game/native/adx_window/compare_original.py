#!/usr/bin/env python3
"""Input-only native Window transport, compared to frozen original word stores.

Original observations are projected as plain byte writes, not by implementing
an expected ring/codec/window. No expected field enters the native executable.
"""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
FIXTURE_SHA='62dfa91bf99698bc10c84356e8320912967cefadbd6a83feb95f453122fafeff'
INPUT_SHA='55a7b1bdda757fbeeb764e3766453b062bab9f692e5da7f2ea23eefe5d8dcbee'
INPUT,PCM,POOL,OUTER,INNER,PRED,ODD=0x400010,0x410010,0x224C60,0x600000,0x610000,0x620000,0x21B7B0
PCM_PHYSICAL=16576


def sha(data): return hashlib.sha256(data).hexdigest()
def require(value,message):
    if not value: raise RuntimeError(message)


def commands(case,profile):
    """Only frozen authored input/profile, never an expected-output object."""
    require('expected' not in json.dumps(case),'Expected state entered input transport')
    require([profile[k] for k in ('input_capacity_bytes','input_extension_bytes','pcm_capacity_bytes','pcm_extension_bytes',
        'encoding','bits_per_sample','block_bytes','samples_per_block','frequency')]==[2048,36,16384,192,3,4,18,32,44100],'Unsupported input profile')
    config=[case['channels'],case['downmix'],case['total_samples'],case['max_request_samples'],case['sample_limit'],
        int(case['callback']),case['input_position'],*case['pcm_positions'],*case['occupied_pcm_bytes'],
        *profile['history_i16'],*profile['coefficients_i16'],profile['key_u16'],profile['multiplier_i16'],profile['addend_i16']]
    lines=['NEW '+' '.join(map(str,config)),'FEED '+(case['encoded_hex'] or '-'),'INITIAL']
    lines += [f'ACTION {n} {action}' for n,action in enumerate(case['actions'])]
    return '\n'.join(lines)+'\n'


class OriginalBytes:
    """Replay captured STORE bytes only; no ring grants, predictor or budgets."""
    def __init__(self,state,physical,channels):
        self.channels=channels
        self.regions={OUTER:bytearray.fromhex(state['outer_hex']),INNER:bytearray.fromhex(state['inner_hex']),
            PRED:bytearray.fromhex(state['predictor_hex']),ODD:bytearray(struct.pack('<I',state['odd_u32'])),
            POOL:bytearray(b''.join(struct.pack('<16I',*row) for row in state['rings']))}
        self.regions.update({address:bytearray(data) for address,data in physical.items()})
    def apply(self,writes):
        for write in writes:
            address,size=write['address'],write['bytes'];value=bytes.fromhex(write['value_hex'])
            require(len(value)==size,'Corrupt original STORE size')
            for base,data in self.regions.items():
                if base<=address and address+size<=base+len(data):
                    data[address-base:address-base+size]=value;break
    def raw(self,address,size):
        for base,data in self.regions.items():
            if base<=address and address+size<=base+len(data): return bytes(data[address-base:address-base+size])
        raise RuntimeError('Missing observed original byte range')
    def u(self,address): return int.from_bytes(self.raw(address,4),'little')
    def s(self,address): return int.from_bytes(self.raw(address,4),'little',signed=True)
    def span(self,pointer,length,role,base): return [role if pointer else 0,pointer-base if pointer else 0,length]
    def position(self,pointer,token,base): return [token,pointer-base] if pointer else [0,0]
    def project(self):
        o,i,p=OUTER,INNER,PRED
        return dict(outer=dict(phase=self.raw(o+1,1)[0],endflag=self.raw(o+3,1)[0],
            input=self.span(self.u(o+0x14),self.s(o+0x18),1,INPUT),
            pcm=[self.span(self.u(o+0x1C+8*c),self.s(o+0x20+8*c),2+c,PCM+c*PCM_PHYSICAL) for c in range(self.channels)],
            counters=[self.s(o+x) for x in (0x2C,0x30,0x34,0x38,0x3C,0x40,0x44)]),
            inner=dict(phase=self.u(i+4),input=self.position(self.u(i+0x48),1,INPUT),
                values=[self.s(i+x) for x in (0x4C,0x68,0x6C,0x70,0x88,0x8C,0x90,0x94)]),
            predictor=dict(phase=self.u(p+0xC),completed=self.u(p+0x10),mode=self.u(p+0x14),
                input=self.position(self.u(p+0x18),1,INPUT),requested=self.u(p+0x1C),
                left=self.position(self.u(p+0x20),2,PCM),right=self.position(self.u(p+0x24),2,PCM),
                history=list(struct.unpack('<4h',self.raw(p+0x28,8))),
                coefficients=list(struct.unpack('<2h',self.raw(p+0x30,4))),key=list(struct.unpack('<3H',self.raw(p+0x34,6)))),
            odd=self.u(ODD),rings=[[self.s(POOL+64*c+x) for x in (0x20,0x24,0xC,0x10,0x14,0x18)]+
                [self.u(POOL+64*c+x) for x in (0x28,0x2C,0x30,0x34)] for c in range(self.channels+1)])
    def physical(self): return {base:bytes(data) for base,data in self.regions.items() if base in (INPUT-16,PCM-16)}
    def planes(self): return [self.raw(PCM+c*PCM_PHYSICAL,PCM_PHYSICAL).hex() for c in range(self.channels)]


def physical(state):
    return {INPUT-16:bytes.fromhex(state['encoded_backing_guard_hex']),PCM-16:bytes.fromhex(state['pcm_arena_guard_hex'])}


def expected_result(result,buffers,channels):
    require(result['status']=='returned','Partial original operation cannot enter native parity')
    model=OriginalBytes(result['before'],buffers,channels);events=[];at=0;active_ring=None
    ring_entries=[row for row in result['traces'] if row['name'] in ('ring_get','ring_put','ring_unget')]
    for event in result['events']:
        index=event['write_index_before'];require(at<=index<=len(result['writes']),'Invalid original callback write index')
        model.apply(result['writes'][at:index]);at=index
        kind={'enter':'E','leave':'L','pcm_callback':'P'}.get(event['kind'])
        if kind is None:
            require(event['kind'] in ('bounded_memcpy','bounded_memset'),'Unexpected original diagnostic/error')
            continue
        if kind=='E':
            entry=max((row for row in ring_entries if row['write_index']<=index),key=lambda row:row['write_index'])
            active_ring=(entry['arguments_u64'][0]-POOL)//64
        ring=event['arguments_u64'][1] if kind=='P' else active_ring
        require(ring is not None and 0<=ring<=channels,'Missing original ring identity')
        row=dict(kind=kind,ring=ring,before=event['depth_before'],after=event['depth_after'],state=model.project())
        if kind=='P':
            measured=OriginalBytes(event['observed_before'],model.physical(),channels).project()
            require(measured==row['state'],'STORE replay disagrees with directly captured callback state')
            planes=model.planes()
            require([sha(bytes.fromhex(data)) for data in planes]==event['pcm_planes_sha256'],'STORE replay disagrees with actual callback plane hashes')
            row.update(offset=event['arguments_u64'][2]-PCM-ring*PCM_PHYSICAL,bytes=event['arguments_u64'][3],
                payload=event['pcm_bytes_hex'],planes=planes)
        events.append(row)
        if kind=='L': active_ring=None
    model.apply(result['writes'][at:])
    after=OriginalBytes(result['after'],model.physical(),channels)
    require(model.project()==after.project(),'STORE replay disagrees with actual final original state')
    if 'pcm_arena_guard_hex' in result['after']:
        require(model.physical()==physical(result['after']),'STORE replay disagrees with actual final physical bytes')
    return model,events


def expected_case(case,original):
    channels=case['channels'];model=OriginalBytes(original['initial'],physical(original['initial']),channels)
    rows=[dict(index=-1,action='initial',state=model.project(),events=[],
        encoded_hex=model.raw(INPUT,2084).hex(),pcm_hex=model.planes())]
    for index,operation in enumerate(original['operations']):
        results=operation['expected'] if isinstance(operation['expected'],list) else [operation['expected']]
        events=[]
        for result in results:
            model,new_events=expected_result(result,model.physical(),channels);events.extend(new_events)
        row=dict(index=index,action=operation['action'],state=model.project(),events=events,
                 encoded_hex=model.raw(INPUT,2084).hex(),pcm_hex=model.planes())
        if operation['action']=='default_reserve':
            result=results[0];raw=bytes.fromhex(result['after']['scratch_hex'])
            values=[int.from_bytes(raw[4+i*4:8+i*4],'little',signed=True) for i in range(3)]
            pointer=result['raw_v0_lower64_observation_only']&0xFFFFFFFF
            row['reservation']=values+[2,pointer-PCM]
        rows.append(row)
    return rows


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--compiler',default='g++');parser.add_argument('--output',required=True,type=Path)
    parser.add_argument('--fixture',type=Path,default=ROOT/'build-native-sjuni/adx-window-oracle-v5/original-fixture.json')
    args=parser.parse_args();out=args.output.resolve();require(not out.exists(),'Select a new evidence directory')
    freeze=json.loads((HERE/'frozen_identity.json').read_bytes())
    for name,value in freeze['source_sha256'].items(): require(sha((HERE/name).read_bytes())==value,'Frozen window source changed: '+name)
    for name,value in freeze['dependencies_sha256'].items(): require(sha((ROOT/name).read_bytes())==value,'Frozen dependency changed: '+name)
    data=args.fixture.read_bytes();require(sha(data)==FIXTURE_SHA,'Original fixture changed');fixture=json.loads(data)
    data=(ROOT/fixture['inputs_file']).read_bytes();require(sha(data)==INPUT_SHA,'Original authored input changed');inputs=json.loads(data)
    originals={row['name']:row for row in fixture['cases']};compiler=shutil.which(args.compiler);require(compiler,'Compiler unavailable')
    out.mkdir(parents=True);compiled=[]
    sources=[HERE/'adx_window.cpp',ROOT/'game/native/sjrb/sjrb.cpp',ROOT/'game/native/adx_block/adx_block.cpp',
        ROOT/'game/native/adx_stereo/adx_stereo.cpp',ROOT/'game/native/adx_control/predictor_control.cpp',ROOT/'game/native/adx_control/predictor_service.cpp']
    for source,target in [('adx_window_tests.cpp','units.exe'),('fixture_runner.cpp','fixture_runner.exe')]:
        command=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror',*map(str,sources),str(HERE/source),'-o',str(out/target)]
        ran=subprocess.run(command,capture_output=True,text=True);(out/(target+'-compile.txt')).write_text(ran.stdout+ran.stderr)
        require(ran.returncode==0,'Compilation failed: '+ran.stderr);compiled.append(dict(command=command,binary_sha256=sha((out/target).read_bytes())))
    units=subprocess.run([str(out/'units.exe')],capture_output=True,text=True);(out/'unit-output.txt').write_text(units.stdout+units.stderr);require(units.returncode==0,'Native units failed')
    records=[]
    for case in inputs['cases']:
        name=case['name'];wire=commands(case,inputs['profile']);path=out/(name+'.commands');path.write_text(wire)
        ran=subprocess.run([str(out/'fixture_runner.exe'),str(path)],capture_output=True,text=True)
        (out/(name+'-native.jsonl')).write_text(ran.stdout);require(ran.returncode==0,f'{name}: '+ran.stderr)
        observed=[json.loads(line) for line in ran.stdout.splitlines()];expected=expected_case(case,originals[name])
        require(len(observed)==len(expected),name+': action count differs')
        for index,(actual,old) in enumerate(zip(observed,expected)):
            if actual!=old:
                fields=[key for key in old if actual.get(key)!=old[key]]
                (out/(name+'-expected-projection.json')).write_text(json.dumps(expected,indent=2))
                raise RuntimeError(f'{name}, action {index-1}: differs in {fields}; observations retained')
        records.append(dict(name=name,commands_sha256=sha(wire.encode()),observations_sha256=sha(ran.stdout.encode()),
            actions=len(observed)-1,events=sum(len(row['events']) for row in observed),
            state_observations=len(observed)+sum(len(row['events']) for row in observed),
            physical_bytes=sum(len(bytes.fromhex(row['encoded_hex']))+sum(len(bytes.fromhex(p)) for p in row['pcm_hex']) for row in observed),
            pcm_callbacks=sum(event['kind']=='P' for row in observed for event in row['events'])))
    receipt=dict(schema=1,result='passed',provenance='Typed window frozen after original exposure and before comparator; synthetic parity only.',
        fixture_sha256=FIXTURE_SHA,inputs_sha256=INPUT_SHA,freeze_sha256=sha((HERE/'frozen_identity.json').read_bytes()),
        compiler=compiler,compiler_sha256=sha(Path(compiler).read_bytes()),compiled=compiled,units=units.stdout.strip(),cases=records,
        source_sha256={name:sha((HERE/name).read_bytes()) for name in ('adx_window.hpp','adx_window.cpp','adx_window_tests.cpp','fixture_runner.cpp','compare_original.py')},
        totals={field:sum(row[field] for row in records) for field in ('actions','events','state_observations','physical_bytes','pcm_callbacks')},
        projections=['Metadata snapshots at every guard/PCM boundary reconstructed ONLY from captured original STORE bytes, checked against direct original callback snapshots and plane hashes.',
            'Initialization source module/pool and raw guest static/header/ABI/stack identity are not native layout claims; mutable typed fields, complete physical backing and observable ordering compare.',
            'One constructor-default-reservation helper uses an actual copied InnerState with authored7/12prewrites and the real scalar core helper; it is not outer ring reservation.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2,sort_keys=True)+'\n')
    print(json.dumps(dict(result='passed',cases=len(records),units=units.stdout.strip(),**receipt['totals'],receipt=str(out/'receipt.json')),indent=2))


if __name__=='__main__':main()
