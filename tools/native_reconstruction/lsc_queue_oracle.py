#!/usr/bin/env python3
"""Execute owned LSC queue/control words; lower file I/O is an explicit port."""
import argparse
import copy
import json
from pathlib import Path
import struct

import adxt_service_group_oracle as audit
import sjrb_oracle as ring
from sjuni_oracle import OracleError, MASK32, signed, sext32

ROOT=audit.ROOT;BASE=ROOT/'build-native-sjuni/lsc-queue'
OBJECT,NAMES,FILE=0x600000,0x610000,0x620000
RANGES={0x13CD10:0x13CD38,0x13CD38:0x13CED0,0x13CED0:0x13CF10,
        0x13CF10:0x13CF78,0x13CF78:0x13D040,0x13D100:0x13D190,
        0x13D190:0x13D224,0x13D228:0x13D2BC,0x13D2C0:0x13D354,
        0x13D358:0x13D3C0,0x13D468:0x13D498,0x13D6D8:0x13D800,
        0x13D800:0x13D8B0,0x13D8B0:0x13D9B8,0x13D9B8:0x13DB48}
ENTRIES={'enqueue':(0x13CD38,True),'clear':(0x13CED0,False),
         'start':(0x13CF10,False),'stop':(0x13CF78,False),
         'pause':(0x13D000,False),'ordinal':(0x13D100,True),
         'name':(0x13D190,True),'status':(0x13D228,True),
         'progress':(0x13D2C0,True),'minimum':(0x13D358,False),
         'repeat':(0x13D468,False),'service':(0x13D9B8,False)}
PORTS={0x1306E0:('stop_lower',1),0x130520:('close_lower',1),
       0x130478:('open_range',5),0x1307A8:('limit',2),
       0x130E18:('thresholds',3),0x1305C0:('position',2),
       0x130658:('start_lower',1),0x130748:('stop_async',1),
       0x1305B8:('query_state',1),0x130608:('query_progress',1)}
sha=audit.sha;encoded=audit.encoded


def authority():
    saved=audit.RANGES;audit.RANGES=RANGES
    try:return audit.authority()
    finally:audit.RANGES=saved


def inputs():
    cases=[]
    def add(name,ops,**kw):
        c=dict(name=name,state=0,repeat=0,pause=0,head=0,tail=0,previous_sequence=0,
               file=True,capacity=8192,callback='none',names=['first.adx','second.adx',''],operations=ops)
        c.update(kw);cases.append(c)
    def op(call,*args,**kw):return dict(call=call,args=list(args),**kw)
    enqueue=lambda n=0:op('enqueue',n,17,3,5)
    service=lambda status=0,progress=0:op('service',lower_status=status,lower_progress=progress)
    add('two-files',[enqueue(),enqueue(1),op('start'),service(),service(2,3),service(3),service(3),service()])
    add('capacity',[enqueue(i%3)for i in range(17)])
    add('stopped-queue-preserved',[enqueue(),op('stop'),op('start'),service()])
    add('restart-active-clears',[enqueue(),op('start'),service(),enqueue(1),op('start'),service()])
    add('clear-only-stopped',[enqueue(),op('clear'),enqueue(),op('start'),op('clear'),service(),op('stop'),op('clear')])
    for value in (0,1,2,127,128,255,256,257,-1):
        add('repeat-'+str(value),[enqueue(),op('repeat',value),op('start'),service(),service(3),service(3)])
        add('pause-'+str(value),[enqueue(),op('start'),op('pause',value),service(),op('pause',0),service()])
    for state in (0,1,2,3,4,5,255):
        add('poll-'+str(state),[enqueue(),op('start'),service(),service(state,11),service(state,13)])
    for callback in ('none','disable_repeat','enqueue','stop','start','pause','remove_file'):
        add('empty-'+callback,[enqueue(),op('repeat',1),op('start'),service(),service(3),service()],callback=callback)
    for head in (0,1,7,15):
        add('wrap-'+str(head),[enqueue(),enqueue(1),op('start'),service(),service(3),service(3),enqueue(2),service()],head=head,tail=head)
    for previous in (0,1,0x7ffffffe,0x7fffffff):
        add('sequence-'+str(previous),[enqueue(),enqueue(1),op('ordinal',0),op('ordinal',1),op('ordinal',-1),op('ordinal',2),op('name',0),op('status',0),op('progress',0),op('name',0x76543210),op('status',0x76543210),op('progress',0x76543210)],previous_sequence=previous)
    for value in (-1,0,1,8192,8193):add('minimum-'+str(value),[op('minimum',value),enqueue(),op('start'),service()])
    add('missing-file',[enqueue(),op('start'),service(),service(3)],file=False)
    add('empty-name',[enqueue(2),op('start'),service(),service(3)])
    add('unsigned-name-checksum',[enqueue(),op('start'),service()],names=['a\u0080\u00ff.adx','second.adx',''])
    return cases


class Machine(ring.Machine):
    def __init__(self,case):
        super().__init__();self.case=copy.deepcopy(case);self.lower_status=0;self.lower_progress=0;self.nested_instructions=0
        for a,b in RANGES.items():
            raw=self.elf.read(a,b-a);self.code.update({a+i:struct.unpack_from('<I',raw,i)[0]for i in range(0,len(raw),4)})
        self.mem.map(OBJECT,0x238);self.mem.map(NAMES,0x1000)
        self.name_addresses=[NAMES+256*i for i in range(len(case['names']))]
        for address,name in zip(self.name_addresses,case['names'],strict=True):
            raw=name.encode('latin1')+b'\0';self.mem.store(address,len(raw),int.from_bytes(raw,'little'))
        for offset,value,size in [(0,1,1),(1,case['state'],1),(3,case['repeat'],1),(4,case['pause'],1),
                                  (0x14,case['capacity']*8//10,4),(0x18,case['capacity'],4),(0x1c,case['tail'],4),
                                  (0x20,case['head'],4),(0x28,FILE if case['file']else 0,4),
                                  (0x38+((case['tail']+15)%16)*32,case['previous_sequence'],4)]:self.mem.store(OBJECT+offset,size,value)

    def instruction(self,pc,word):
        # Only the two REGIMM likely forms absent from the older shared engine.
        # Scheduling/annulment remains in the existing original-word runner.
        if word>>26==1 and (word>>16)&31 in (2,3):
            rt=(word>>16)&31;value=signed(self.regs[(word>>21)&31],64)
            immediate=signed(word&65535,16);self.regs[0]=0
            return (value<0 if rt==2 else value>=0,(pc+4+immediate*4)&MASK32,True)
        return super().instruction(pc,word)

    def pointer(self,value):
        if value==0:return -1
        if value not in self.name_addresses:raise OracleError('Unowned filename pointer')
        return self.name_addresses.index(value)

    def state(self):
        slots=[]
        for i in range(16):
            words=self.mem.words(OBJECT+0x38+i*32,8);words[1]=self.pointer(words[1]);slots.append(words)
        return dict(flags=[self.mem.load(OBJECT+i,1)for i in range(1,5)],
                    minimum=self.mem.load(OBJECT+0x14,4),capacity=self.mem.load(OBJECT+0x18,4),
                    tail=self.mem.load(OBJECT+0x1c,4),head=self.mem.load(OBJECT+0x20,4),count=self.mem.load(OBJECT+0x24,4),
                    file=bool(self.mem.load(OBJECT+0x28,4)),limit=self.mem.load(OBJECT+0x2c,4),extra=self.mem.load(OBJECT+0x34,4),slots=slots)

    def nested(self,operation,args):
        saved_regs=self.regs[:];saved_pc=self.pc;self.regs[29]-=0x100;self.regs[31]=0xffffe0;self.pc=ENTRIES[operation][0]
        for i,value in enumerate(args):self.regs[4+i]=sext32(value)
        pending=None;steps=0
        while self.pc!=0xffffe0:
            if steps>10000:raise OracleError('Nested queue callback did not return')
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
        result=self.regs[2]&MASK32;self.nested_instructions+=steps;self.regs=saved_regs;self.pc=saved_pc
        return result

    def hook(self,pc):
        if pc==0x10B158:
            address=self.regs[4]&MASK32;length=0
            if address not in self.name_addresses:raise OracleError('Unowned strlen')
            while self.mem.load(address+length,1):length+=1
            self.regs[2]=length
        elif pc==0x13D4F8:
            self.events.append(dict(event='diagnostic',format=self.regs[4]&MASK32))
        elif pc==0x13D430:
            self.events.append(dict(event='empty'));action=self.case['callback']
            if action=='disable_repeat':self.mem.store(OBJECT+3,1,0)
            elif action=='pause':self.mem.store(OBJECT+4,1,1)
            elif action=='remove_file':self.mem.store(OBJECT+0x28,4,0)
            elif action in ('stop','start'):self.nested(action,[OBJECT])
            elif action=='enqueue':
                result=self.nested('enqueue',[OBJECT,self.name_addresses[1],29,7,9]);self.events.append(dict(event='callback_enqueue',result=result))
        elif pc in PORTS:
            name,count=PORTS[pc];args=[self.regs[4+i]&MASK32 for i in range(count)]
            if args[0]not in (0,FILE):raise OracleError('Unexpected lower handle')
            args[0]=int(bool(args[0]))
            if name=='open_range':args[1]=self.pointer(args[1])
            event=dict(event=name,args=args)
            if name in ('query_state','query_progress'):
                value=self.lower_status if name=='query_state'else self.lower_progress;self.regs[2]=sext32(value);event['return']=value&MASK32
            self.events.append(event)
        else:return False
        self.pc=self.regs[31]&MASK32;return True

    def operation(self,row):
        self.lower_status=row.get('lower_status',0);self.lower_progress=row.get('lower_progress',0)
        args=row['args'][:]
        if row['call']=='enqueue':args[0]=self.name_addresses[args[0]]
        result=self.run('lsc_'+row['call'],[OBJECT,*args],step_cap=30000)
        if result['failure']:raise OracleError(str(result['failure']))
        value=result['return_u32']
        if row['call']=='name'and value is not None:value=self.pointer(value)
        return result,dict(result=value,events=result['events'],after=result['after'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--freeze',action='store_true');p.add_argument('--frozen',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    auth=authority();out.mkdir(parents=True)
    if a.freeze:
        (out/'inputs.json').write_bytes(encoded(dict(cases=inputs())))
        (out/'manifest.json').write_bytes(encoded(dict(authority=auth,oracle_sha256=sha(Path(__file__).read_bytes()),inputs_sha256=sha((out/'inputs.json').read_bytes()),native_exists=(ROOT/'game/native/lsc_queue/queue.cpp').exists())))
        print('Frozen',len(inputs()),'independent LSC queue cases');return
    manifest=json.loads((a.frozen/'manifest.json').read_bytes())
    if manifest['authority']!=auth or manifest['oracle_sha256']!=sha(Path(__file__).read_bytes())or manifest['inputs_sha256']!=sha((a.frozen/'inputs.json').read_bytes()):raise OracleError('Frozen input drift')
    ring.ENTRIES.update({'lsc_'+k:v for k,v in ENTRIES.items()});rows=[];instructions=0;operations=0
    for case in json.loads((a.frozen/'inputs.json').read_bytes())['cases']:
        machine=Machine(case);records=[]
        for op in case['operations']:
            raw,projection=machine.operation(op);instructions+=raw['original_instructions'];operations+=1;records.append(dict(input=op,original=raw,projection=projection))
        instructions+=machine.nested_instructions;path=out/(case['name']+'.json');path.write_bytes(encoded(dict(input=case,operations=records,nested_instructions=machine.nested_instructions)))
        rows.append(dict(name=case['name'],sha256=sha(path.read_bytes())))
    receipt=dict(schema=1,status='passed original LSC queue/control words with explicit lower-file and notification ports',cases=len(rows),operations=operations,original_instructions=instructions,rows=rows,authority=auth,frozen_manifest_sha256=sha((a.frozen/'manifest.json').read_bytes()),game_run=False,device_opened=False,lower_file_implementation_parity=False)
    (out/'receipt.json').write_bytes(encoded(receipt));print(json.dumps(dict(cases=len(rows),operations=operations,instructions=instructions,receipt_sha256=sha((out/'receipt.json').read_bytes()))))

if __name__=='__main__':main()
