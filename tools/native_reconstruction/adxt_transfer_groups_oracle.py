#!/usr/bin/env python3
"""Expand original audio dispatch through both transfer-service scans.

DTR32 and DTX8 envelopes execute; their individual transfer protocols remain
opaque external calls. No device-frame or completion value is synthesized.
"""
import argparse
import copy
import json
from pathlib import Path
import struct

import adxt_service_group_oracle as prior
from sjuni_oracle import OracleError,MASK32

ROOT=prior.ROOT;BASE=ROOT/'build-native-sjuni/adxt-transfer-groups'
RANGES={**prior.RANGES,0x1389D8:0x138A38,0x141268:0x141280,0x139568:0x1395C8}
TABLES={**prior.TABLES,'dtr':(0x21BC08,0x40),'dtx':(0x21C430,0x44)}
COUNTS={'decoder':16,'stream':16,'rna':16,'dtr':32,'dtx':8}
CHILDREN={pc:v for pc,v in prior.CHILDREN.items()if pc not in (0x1389D8,0x141268)}
CHILDREN.update({0x138650:('dtr','dtr'),0x139198:('dtx','dtx')})
GUARDS={**prior.GUARDS,0x13F258:('chunk_enter',1),0x13F270:('chunk_leave',-1)}
sha=prior.sha;encoded=prior.encoded


def authority():
    saved=prior.RANGES;prior.RANGES=RANGES
    try:return dict(**prior.authority(),prior_oracle_sha256=sha(Path(prior.__file__).read_bytes()))
    finally:prior.RANGES=saved


def inputs():
    rows=prior.inputs()
    for c in rows:
        c['dtr']=[0]*32;c['dtx']=[0]*8
        for action in c['actions']:
            if action['trigger']in ('dtr','dtx')and action['slot']==-1:action['slot']=0;c[action['trigger']][0]=1
    def add(name,**kw):
        c=dict(name=name,busy=0,**{n:[0]*count for n,count in COUNTS.items()},phase=[0]*16,actions=[]);c.update(kw);rows.append(c);return c
    for name in ('dtr','dtx'):
        for slot in range(COUNTS[name]):c=add(f'{name}-slot-{slot}');c[name][slot]=1
        c=add(name+'-signed-activity');c[name]=([0,1,2,255,128,127,1,0]*4)[:COUNTS[name]]
    add('all-transfer-slots',dtr=[1]*32,dtx=[1]*8)
    def action(trigger,slot,table,target,value):return dict(trigger=trigger,slot=slot,table=table,target=target,field='active',value=value)
    c=add('dtr-activates-late-and-dtx',dtr=[1]+[0]*31)
    c['actions']=[action('dtr',0,'dtr',31,1),action('dtr',31,'dtx',7,1)]
    c=add('dtx-second-scan-observes-earlier-slot',dtx=[0]*7+[1])
    c['actions']=[action('dtx',7,'dtx',0,1)]
    c=add('dtx-retire-between-scans',dtx=[1]+[0]*7)
    c['actions']=[action('dtx',0,'dtx',0,0),action('dtx',0,'dtx',7,1)]
    c=add('dtx-changes-dtr-after-its-pass',dtx=[1]+[0]*7)
    c['actions']=[action('dtx',0,'dtr',31,1)]
    return rows


class Machine(prior.Machine):
    def __init__(self,case):
        self.case=copy.deepcopy(case);self.rna_depth=0;self.chunk_depth=0;self.extra_steps=0;prior.ring.Machine.__init__(self)
        for a,b in RANGES.items():
            raw=self.elf.read(a,b-a);self.code.update({a+i:struct.unpack_from('<I',raw,i)[0]for i in range(0,len(raw),4)})
        self.mem.map(prior.BUSY,4);self.mem.store(prior.BUSY,4,case['busy'])
        for name,(base,stride)in TABLES.items():
            self.mem.map(base,COUNTS[name]*stride)
            for i,value in enumerate(case[name]):self.mem.store(base+i*stride,1,value)
        for i,value in enumerate(case['phase']):self.mem.store(TABLES['stream'][0]+i*TABLES['stream'][1]+1,1,value)
        self.actions=copy.deepcopy(case['actions'])

    def state(self):
        return dict(busy=self.mem.load(prior.BUSY,4),**{name:[self.mem.load(base+i*stride,1)for i in range(COUNTS[name])]for name,(base,stride)in TABLES.items()},phase=[self.mem.load(TABLES['stream'][0]+i*TABLES['stream'][1]+1,1)for i in range(16)])

    def observe(self,event,slot=-1):
        self.events.append(dict(event=event,slot=slot,busy=self.mem.load(prior.BUSY,4),cri_depth=self.guard_depth,rna_depth=self.rna_depth,chunk_depth=self.chunk_depth))

    def hook(self,pc):
        if pc in GUARDS:
            event,change=GUARDS[pc]
            if event.startswith('cri'):self.guard_depth+=change
            elif event.startswith('rna'):self.rna_depth+=change
            else:self.chunk_depth+=change
            if min(self.guard_depth,self.rna_depth,self.chunk_depth)<0:raise OracleError('Guard underflow')
            self.observe(event);self.pc=self.regs[31]&MASK32;return True
        if pc not in CHILDREN:return False
        table,event=CHILDREN[pc];base,stride=TABLES[table];address=self.regs[4]&MASK32
        if not base<=address<base+COUNTS[table]*stride or(address-base)%stride:raise OracleError('Unexpected child object')
        slot=(address-base)//stride;self.observe(event,slot)
        for action in self.actions:
            if action.get('done')or action['trigger']!=event or action['slot']!=slot:continue
            action['done']=True
            if action.get('reenter'):self.nested()
            else:
                base,stride=TABLES[action['table']];offset=1 if action['field']=='phase'else 0
                self.mem.store(base+action['target']*stride+offset,1,action['value'])
        self.pc=self.regs[31]&MASK32;return True


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--freeze',action='store_true');p.add_argument('--frozen',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise OracleError('Fresh scoped output required')
    auth=authority();out.mkdir(parents=True)
    if a.freeze:
        (out/'inputs.json').write_bytes(encoded(dict(cases=inputs())))
        (out/'manifest.json').write_bytes(encoded(dict(authority=auth,oracle_sha256=sha(Path(__file__).read_bytes()),inputs_sha256=sha((out/'inputs.json').read_bytes()),native_exists=(ROOT/'game/native/adxt_transfer_groups/transfer_groups.cpp').exists())))
        print('Frozen',len(inputs()),'independent expanded transfer-group cases');return
    frozen=json.loads((a.frozen/'manifest.json').read_bytes())
    if frozen['authority']!=auth or frozen['oracle_sha256']!=sha(Path(__file__).read_bytes())or frozen['inputs_sha256']!=sha((a.frozen/'inputs.json').read_bytes()):raise OracleError('Frozen input drift')
    prior.ring.ENTRIES['audio_group']=(0x132C08,False);rows=[];instructions=0
    for case in json.loads((a.frozen/'inputs.json').read_bytes())['cases']:
        m=Machine(case);result=m.run('audio_group',[],step_cap=100000)
        if result['failure']or m.rna_depth or m.chunk_depth:raise OracleError(str(result['failure']))
        if not all(x.get('done')for x in m.actions):raise OracleError('Unreached action '+case['name'])
        path=out/(case['name']+'.json');path.write_bytes(encoded(dict(input=case,original=result,nested_instructions=m.extra_steps,projection=dict(events=result['events'],after=result['after']))))
        n=result['original_instructions']+m.extra_steps;instructions+=n;rows.append(dict(name=case['name'],sha256=sha(path.read_bytes()),instructions=n))
    receipt=dict(schema=1,status='passed original complete audio/transfer dispatch envelopes with opaque per-slot children',cases=len(rows),original_instructions=instructions,frozen_manifest_sha256=sha((a.frozen/'manifest.json').read_bytes()),authority=auth,rows=rows,game_run=False,device_opened=False,
                 limitations=['Individual decoder/controller/file/RNA/DTR/DTX protocols remain external.','Synthetic guards do not establish original locks, preemption or priority scheduling.','Two DTX scans are control service, not two device frames.'])
    (out/'receipt.json').write_bytes(encoded(receipt));print(json.dumps(dict(cases=len(rows),instructions=instructions,receipt_sha256=sha((out/'receipt.json').read_bytes()))))


if __name__=='__main__':main()
