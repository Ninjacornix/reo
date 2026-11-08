#!/usr/bin/env python3
"""Validate original LSC lifecycle observations and record adapter constraints."""
import argparse
import json
from pathlib import Path

import lsc_lifecycle_oracle as original

ROOT = original.ROOT


def verify(folder):
    proof=json.loads((folder/'receipt.json').read_bytes())
    if proof['authority']!=original.authority() or proof['oracle_sha256']!=original.sha(Path(original.__file__).read_bytes()):
        raise ValueError('Owned source/oracle drift')
    rows={}
    for row in proof['rows']:
        path=folder/(row['name']+'.json')
        if original.sha(path.read_bytes())!=row['sha256']:raise ValueError('Observation drift')
        rows[row['name']]=json.loads(path.read_bytes())
    checks=0
    def check(value):
        nonlocal checks
        checks+=1
        if not value:raise ValueError('Original lifecycle constraint failed')
    def byte_state(observation):return bytes.fromhex(observation['after']['focused_hex'])
    def word(raw,at):return int.from_bytes(raw[at:at+4],'little')
    for row in rows.values():
        for op in row['observations']:
            r=op['original'];check(r['failure'] is None and r['status']=='returned')
            check(r['after']['guards']==['a5'*16]*2 and r['after']['critical_depth']==0)
    for slot in range(16):
        records=rows['first-free-'+str(slot)]['observations']
        create,attach,destroy,again=[r['original'] for r in records]
        raw=byte_state(create)
        check(create['return_u32']==original.POOL+slot*original.STRIDE)
        check([e['event'] for e in create['events']]==['critical_enter','input_count','input_count','critical_leave'])
        check([(e['list'],e['value']) for e in create['events'] if e['event']=='input_count']==[(0,4096),(1,4096)])
        check(raw[0]==1 and raw[1]==0 and word(raw,8)==original.INPUT and word(raw,0x18)==8192 and word(raw,0x14)==6553)
        check(all(word(raw,0x50+i*32)==0 for i in range(16)))
        attached=byte_state(attach);check(attached[:0x28]==raw[:0x28] and attached[0x2c:]==raw[0x2c:] and word(attached,0x28)==original.FILE)
        check(byte_state(destroy)==bytes(original.STRIDE) and destroy['events']==[dict(event='zero_child',bytes=original.STRIDE)])
        check(again['return_u32']==create['return_u32'] and word(byte_state(again),0x28)==0)
    full=rows['full']['observations'][0]['original']
    check(full['return_u32']==0 and full['before']['pool_sha256']==full['after']['pool_sha256'])
    check([e['event'] for e in full['events']]==['critical_enter','diagnostic','critical_leave'])
    null=rows['null-input']['observations'][0]['original']
    check(null['return_u32']==0 and [e['event'] for e in null['events']]==['diagnostic'] and null['before']==null['after'])
    null=rows['null-destroy']['observations'][0]['original'];check(null['before']==null['after'] and not null['events'])
    allocated,first,second=[r['original'] for r in rows['multiple-free']['observations']]
    check(allocated['return_u32']==original.POOL+3*original.STRIDE and allocated['before']==allocated['after'])
    check(first['return_u32']==allocated['return_u32'] and second['return_u32']==original.POOL+7*original.STRIDE)
    expected={(0,0):(0,0),(8192,0):(8192,6553),(1,2):(3,2),
              (0x7fffffff,1):(0x80000000,0),(0x10000000,0):(0x10000000,0xf3333334),
              (0xffffffff,0xffffffff):(0xfffffffe,0xffffffff)}
    for counts,(capacity,minimum) in expected.items():
        raw=byte_state(rows['counts-'+'-'.join(map(str,counts))]['observations'][0]['original'])
        check(word(raw,0x18)==capacity and word(raw,0x14)==minimum)
    for phase in (0,1,2,3,255):
        for transfer in (0,1,2):
            r=rows[f'destroy-{phase}-{transfer}']['observations'][0]['original']
            check(byte_state(r)==bytes(original.STRIDE))
            check(sum(e['event']=='lower_stop_async' for e in r['events'])==int(phase!=0 and transfer==1))
    poison=byte_state(rows['poisoned-free-storage']['observations'][0]['original'])
    check(poison[2:5]==bytes([0xa5]*3) and word(poison,0x3c)==0xa5a5a5a5)
    check(word(poison,0x38)==0xa5a5a5a5 and all(word(poison,0x50+i*32)==0 for i in range(16)))
    return dict(checks=checks,cases=len(rows),operations=proof['operations'],original_instructions=proof['original_instructions'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--observations',type=Path,required=True);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/lsc-lifecycle'):raise ValueError('Fresh owned output required')
    result=verify(a.observations.resolve());out.mkdir(parents=True)
    record=dict(schema=1,status='original LSC lifecycle constraints verified',**result,
                observations_receipt_sha256=original.sha((a.observations/'receipt.json').read_bytes()),
                verifier_sha256=original.sha(Path(__file__).read_bytes()),oracle_sha256=original.sha(Path(original.__file__).read_bytes()),
                game_run=False,device_opened=False,native_comparison=False)
    (out/'receipt.json').write_bytes(original.encoded(record));print(json.dumps(result))


if __name__=='__main__':main()
