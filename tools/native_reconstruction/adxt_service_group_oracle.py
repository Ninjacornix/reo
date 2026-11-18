#!/usr/bin/env python3
"""Execute owned audio group/dispatch words with explicit opaque child calls.

This establishes ordering and live membership/phase reloads. Decoder, controller,
RNA-slot and DTR/DTX bodies are external boundaries, not proven by this harness.
"""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import re
import struct

import sjrb_oracle as ring
from sjuni_oracle import Elf,OracleError,MASK32

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/adxt-service-group'
RANGES={0x132C08:0x132CD8,0x12D678:0x12D6D8,0x134C58:0x134D20,
        0x12C798:0x12C7B0,0x13EEE8:0x13EF58,0x1347F8:0x134800}
TABLES={'decoder':(0x217D88,0x9C),'stream':(0x20F3C8,0xC4),'rna':(0x223880,0x60)}
BUSY=0x21B754
CHILDREN={0x12D638:('decoder','decode'),0x133FE0:('stream','ready'),
          0x1343B8:('stream','buffer'),0x134530:('stream','play'),0x1345F0:('stream','drain'),
          0x134BC0:('stream','input_end'),0x134B40:('stream','error'),0x13ED28:('rna','rna'),
          0x1389D8:(None,'dtr'),0x141268:(None,'dtx')}
GUARDS={0x1264E0:('cri_enter',1),0x1264F8:('cri_leave',-1),
        0x13F218:('rna_enter',1),0x13F230:('rna_leave',-1)}
sha=lambda b:hashlib.sha256(b).hexdigest()
encoded=lambda x:(json.dumps(x,sort_keys=True,indent=2)+'\n').encode()


def authority():
    elf=Elf(ROOT/'game_data/SLUS_207.65');rows=[]
    for start,end in RANGES.items():
        path=ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp'
        raw=path.read_bytes();comments={int(a,16):int(b,16)for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw)}
        zero=[]
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if word!=comments[pc]:raise OracleError('Owned source disagreement '+hex(pc))
            elif word:raise OracleError('Missing nonzero source word '+hex(pc))
            else:zero.append(pc)
        rows.append(dict(start=start,end=end,sha256=sha(elf.read(start,end-start)),source=path.relative_to(ROOT).as_posix(),source_sha256=sha(raw),omitted_zero_pcs=zero))
    return dict(elf_sha256=elf.sha256,ranges=rows,engines={n:sha(Path(__file__).with_name(n).read_bytes())for n in ('sjrb_oracle.py','sjuni_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py')})


def inputs():
    rows=[]
    def add(name,**kw):
        c=dict(name=name,busy=0,decoder=[0]*16,stream=[0]*16,rna=[0]*16,phase=[0]*16,actions=[])
        c.update(kw);rows.append(c);return c
    add('empty')
    for busy in (1,2,3,0xFFFFFFFF):add('busy-'+str(busy),busy=busy,decoder=[1]*16,stream=[1]*16,rna=[1]*16,phase=[3]*16)
    add('all',decoder=[1]*16,stream=[1]*16,rna=[1]*16,phase=[i%8 for i in range(16)])
    for table in TABLES:
        for slot in range(16):
            c=add(f'{table}-{slot}',phase=[i%6 for i in range(16)]);c[table][slot]=1
        add(table+'-signed-activity',**{table:[0,1,2,0xFF,0x80,0x7F,1,0,1,2,0xFE,1,0,1,0xFF,1]},phase=[i%8 for i in range(16)])
    for phase in (0,1,2,3,4,5,6,7,0x7F,0x80,0xFF):add('phase-'+str(phase),stream=[1]*16,phase=[phase]*16)
    # Literal external child side effects, authored before the native dispatcher.
    # Each action applies once after the named opaque child is observed.
    def action(trigger,slot,table,target,field,value):return dict(trigger=trigger,slot=slot,table=table,target=target,field=field,value=value)
    c=add('decoder-live-membership',decoder=[1]+[0]*15,stream=[0]*16,rna=[0]*16,phase=[0]*16)
    c['actions']=[action('decode',0,'decoder',15,'active',1),action('decode',0,'stream',9,'active',1),action('decode',0,'stream',9,'phase',4),action('decode',0,'rna',5,'active',1)]
    c=add('stream-live-membership',stream=[1]*16,phase=[3]*16)
    c['actions']=[action('play',0,'stream',1,'active',0),action('play',0,'stream',15,'phase',2),action('play',0,'stream',0,'phase',4),action('input_end',0,'stream',0,'active',0),action('error',0,'rna',15,'active',1)]
    c=add('rna-live-membership',rna=[1]+[0]*15)
    c['actions']=[action('rna',0,'rna',15,'active',1)]
    for event in ('decode','ready','buffer','play','drain','input_end','error','rna','dtr','dtx'):
        c=add('reenter-'+event,decoder=[1]+[0]*15,stream=[1]+[0]*15,rna=[1]+[0]*15,phase=[{'ready':1,'buffer':2,'play':3,'drain':4}.get(event,3)]+[0]*15)
        c['actions']=[dict(trigger=event,slot=-1 if event in ('dtr','dtx')else 0,reenter=True)]
    return rows


class Machine(ring.Machine):
    def __init__(self,case):
        self.case=copy.deepcopy(case);self.rna_depth=0;self.extra_steps=0;super().__init__()
        for a,b in RANGES.items():
            raw=self.elf.read(a,b-a);self.code.update({a+i:struct.unpack_from('<I',raw,i)[0]for i in range(0,len(raw),4)})
        self.mem.map(BUSY,4);self.mem.store(BUSY,4,case['busy'])
        for name,(base,stride)in TABLES.items():
            self.mem.map(base,16*stride)
            for i,value in enumerate(case[name]):self.mem.store(base+i*stride,1,value)
        for i,value in enumerate(case['phase']):self.mem.store(TABLES['stream'][0]+i*TABLES['stream'][1]+1,1,value)
        self.actions=copy.deepcopy(case['actions'])

    def state(self):
        return dict(busy=self.mem.load(BUSY,4),**{name:[self.mem.load(base+i*stride,1)for i in range(16)]for name,(base,stride)in TABLES.items()},phase=[self.mem.load(TABLES['stream'][0]+i*TABLES['stream'][1]+1,1)for i in range(16)])

    def observe(self,event,slot=-1):
        self.events.append(dict(event=event,slot=slot,busy=self.mem.load(BUSY,4),cri_depth=self.guard_depth,rna_depth=self.rna_depth))

    def nested(self):
        # Execute the actual early-reentry path, retaining the caller's external
        # child continuation. No result from the native dispatcher is supplied.
        saved_regs=self.regs[:];saved_pc=self.pc;pending=None;self.regs[31]=0xFFFFE0;self.pc=0x132C08
        steps=0
        while self.pc!=0xFFFFE0:
            if steps>1000:raise OracleError('Nested group did not return')
            if pending is None and self.hook(self.pc):continue
            pc=self.pc
            if pc not in self.code:raise OracleError('Unowned nested instruction')
            branch=self.instruction(pc,self.code[pc]);steps+=1
            if pending is not None:
                if branch is not None:raise OracleError('Nested delay transfer')
                self.pc=pending;pending=None
            elif branch is None:self.pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:self.pc+=8
                else:pending=target if taken else pc+8;self.pc+=4
        if self.regs[29]!=saved_regs[29]:raise OracleError('Nested stack imbalance')
        self.extra_steps+=steps;self.regs=saved_regs;self.pc=saved_pc

    def hook(self,pc):
        if pc in GUARDS:
            event,change=GUARDS[pc]
            if event.startswith('cri'):self.guard_depth+=change
            else:self.rna_depth+=change
            if min(self.guard_depth,self.rna_depth)<0:raise OracleError('Guard underflow')
            self.observe(event);self.pc=self.regs[31]&MASK32;return True
        if pc not in CHILDREN:return False
        table,event=CHILDREN[pc];slot=-1
        if table:
            base,stride=TABLES[table];address=self.regs[4]&MASK32
            if not base<=address<base+16*stride or(address-base)%stride:raise OracleError('Unexpected child object')
            slot=(address-base)//stride
        self.observe(event,slot)
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
        (out/'manifest.json').write_bytes(encoded(dict(authority=auth,oracle_sha256=sha(Path(__file__).read_bytes()),inputs_sha256=sha((out/'inputs.json').read_bytes()),native_exists=(ROOT/'game/native/adxt_service_group/service_group.cpp').exists())))
        print('Frozen',len(inputs()),'independent group cases');return
    frozen=json.loads((a.frozen/'manifest.json').read_bytes())
    if frozen['authority']!=auth or frozen['oracle_sha256']!=sha(Path(__file__).read_bytes())or frozen['inputs_sha256']!=sha((a.frozen/'inputs.json').read_bytes()):raise OracleError('Frozen input drift')
    ring.ENTRIES['audio_group']=(0x132C08,False);rows=[];instructions=0
    for case in json.loads((a.frozen/'inputs.json').read_bytes())['cases']:
        m=Machine(case);result=m.run('audio_group',[],step_cap=100000)
        if result['failure']or m.rna_depth:raise OracleError(str(result['failure']))
        if not all(x.get('done')for x in m.actions):raise OracleError('Unreached authored action '+case['name'])
        projection=dict(events=result['events'],after=result['after'])
        path=out/(case['name']+'.json');path.write_bytes(encoded(dict(input=case,original=result,nested_instructions=m.extra_steps,projection=projection)))
        n=result['original_instructions']+m.extra_steps;instructions+=n;rows.append(dict(name=case['name'],sha256=sha(path.read_bytes()),instructions=n))
    receipt=dict(schema=1,status='passed original group/dispatch envelopes with explicit external children',cases=len(rows),original_instructions=instructions,
                 frozen_manifest_sha256=sha((a.frozen/'manifest.json').read_bytes()),authority=auth,rows=rows,game_run=False,device_opened=False,
                 limitations=['Opaque decoder/controller/input/error/RNA/DTR/DTX children remain external.', 'Synthetic serialized guards are not actual CRI locks or priority scheduling.', 'Nested external child calls exercise actual busy early return only.'])
    (out/'receipt.json').write_bytes(encoded(receipt));print(json.dumps(dict(cases=len(rows),instructions=instructions,receipt_sha256=sha((out/'receipt.json').read_bytes()))))


if __name__=='__main__':main()
