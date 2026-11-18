#!/usr/bin/env python3
"""Complete movie audio envelope/cache with explicit estimator/counter ports."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from movie_audio_filter_oracle import Machine as FilterMachine,FILTER,GLOBALS,WORDS,PAIRS,DOUBLES,TOP,RETURN,BODIES as FILTER_BODIES
from movie_counter_clock_oracle import BODIES as COUNTER_BODIES
from sjuni_oracle import MASK64,OracleError,StepLimit,sext32

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/movie-audio-clock'
MAIN=FILTER-0xF60
CHILD=0x600000
ADXT=0x600100
NUM,DEN=0x500000,0x500040
DIAGNOSTIC=0x22EF68
FREQUENCY=0x22F980
PORTS={0x132160:'estimate',0x17E870:'counter'}
BODIES={
    0x165B48:(0x165C04,'3ed713e5d0d4e775106fef29b52e2ed161ab655702411bb19e940f91c04cc34a'),
    0x165C08:(0x165CB0,'aa65067c5297fb43c6380fe3c082af4fc376244fd32b367357a3f095e3966571'),
    0x176670:COUNTER_BODIES[0x176670]}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(FilterMachine):
    def __init__(self,case):
        super().__init__()
        self.constructor=super().run(dict(operation='construct'))
        self.seed(case['filter_seed'])
        # Pin full extra bodies by owned bytes in the manifest, before execution.
        intervals=dict(BODIES)
        for start,end in [(0x131EF8,0x131F28),(0x17E998,0x17E9A8)]:
            intervals[start]=(end,hashlib.sha256(self.elf.read(start,end-start)).hexdigest())
        self.extra_bodies=intervals
        for start,(end,digest) in intervals.items():
            data=self.elf.read(start,end-start)
            if hashlib.sha256(data).hexdigest()!=digest:raise OracleError('Owned envelope body identity')
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        for name,address,length,write in [('actual',MAIN+0x48,4,True),('audio_child',MAIN+0x1B74,4,False),('child',CHILD,64,True),('adxt',ADXT,64,False),('diagnostic',DIAGNOSTIC,4,True),('helper_frequency',FREQUENCY,8,False)]:
            self.mem.span(name,address,length,write,0xA5)
        self.mem.store(MAIN+0x1B74,4,CHILD)
        self.mem.store(CHILD,4,ADXT)
        for n,value in enumerate(case['cache']):self.mem.store(CHILD+0x24+n*4,4,value)
        for address,value in [(NUM,case['prior'][0]),(DEN,case['prior'][1]),(DIAGNOSTIC,case['diagnostic'])]:self.mem.store(address,4,value)
        self.port_events=[]

    def capture(self):
        value=super().snapshot()
        value.update(actual=self.mem.load(MAIN+0x48,4),cache=[self.mem.load(CHILD+0x24+n*4,4) for n in range(2)],caller=[self.mem.load(NUM,4),self.mem.load(DEN,4)],diagnostic=self.mem.load(DIAGNOSTIC,4))
        child=bytearray(self.mem.load(CHILD,64).to_bytes(64,'little'))
        child[0x24:0x2C]=bytes(8)
        value['child_guard_sha256']=hashlib.sha256(child).hexdigest()
        return value

    def port(self,pc,operation):
        event=dict(port=PORTS[pc],before=self.capture())
        if pc==0x132160:
            if self.regs[4]!=ADXT or self.regs[5]!=TOP-0x70-(0x50 if operation['kind']=='slot' else 0)+0x30 or self.regs[6]!=self.regs[5]+4:raise OracleError('Estimator argument identity')
            for address,value in zip(self.regs[5:7],operation['sample'],strict=True):self.mem.store(address,4,value)
            returned=0xBAD01001
        else:returned=operation['counter']
        for reg in [1,*range(2,16),24,25]:self.regs[reg]=(0xC10BBE0000000000+pc+reg)&MASK64
        self.regs[2]=returned&MASK64
        self.port_events.append(event)
        return self.regs[31]

    def execute(self,operation):
        self.mem.store(MAIN+0x48,4,operation['actual'])
        self.mem.store(ADXT+1,1,operation['adxt_status'])
        self.mem.store(FREQUENCY,8,operation['frequency'])
        self.regs[29]=TOP;self.regs[31]=RETURN
        args=[MAIN,NUM,DEN] if operation['kind']=='slot' else [FILTER,ADXT,NUM,DEN]
        for n,value in enumerate(args):self.regs[4+n]=value
        before=self.capture();start=self.steps;write_start=len(self.mem.writes);read_start=len(self.mem.reads);port_start=len(self.port_events)
        pc=0x165B48 if operation['kind']=='slot' else 0x165C08;pending=None;self.mem.active=True
        while pc!=RETURN:
            if self.steps-start>=100000:raise StepLimit('Original envelope operation exceeded bound')
            if pc in PORTS:
                if pending is not None:raise OracleError('Port in delay slot')
                pc=self.port(pc,operation);continue
            if pc not in self.code or pc%4:raise OracleError('Unowned envelope transfer '+hex(pc))
            self.steps+=1;self.visited[pc]=self.visited.get(pc,0)+1
            if pc in self.extra_bodies or pc in FILTER_BODIES:self.calls[pc]=self.calls.get(pc,0)+1
            branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Control transfer in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False;after=self.capture()
        if self.regs[29]!=TOP or any(self.regs[r]!=v for r,v in self.saved.items()):raise OracleError('Envelope ABI restoration')
        if any(before[key]!=after[key] for key in ['prefix','suffix','child_guard_sha256']):raise OracleError('Envelope escaped owned fields')
        return dict(operation=operation,before=before,after=after,original_instructions=self.steps-start,return_defined=operation['kind']=='slot',raw_v0_lower64=self.regs[2]&MASK64,ports=self.port_events[port_start:],writes=self.mem.writes[write_start:],reads=self.mem.reads[read_start:])


def operation(kind='slot',**changes):
    value=dict(kind=kind,actual=4,adxt_status=3,sample=[1600,48000],counter=19200,frequency=576000)
    value.update(changes)
    value['actual'] &= 0xFFFFFFFF
    value['adxt_status'] &= 0xFF
    value['sample']=[n&0xFFFFFFFF for n in value['sample']]
    value['counter'] &= MASK64;value['frequency'] &= MASK64
    return value


def corpus():
    cases=[]
    def add(name,operations,cache=None,seed=None):cases.append(dict(name=name,cache=cache or [0,1],prior=[0x80000001,0x12345678],diagnostic=0x12344321,filter_seed=seed or {},operations=operations))
    for actual in [4,-4,6,-6,0,1,2,3,5,7,-2147483648,2147483647]:
        for cache in [[0,1],[2000,24000],[0x80000000,0xFFFFFFFF]]:
            add('admission-'+str(len(cases)),[operation(actual=actual)],cache)
    for kind in ['slot','envelope']:
        for status in [0,1,3,4,5,127,128,255]:
            add('signed-status-'+str(len(cases)),[operation(kind,adxt_status=status)])
        for sample in [[0,48000],[-1,48000],[1600,-1],[1600,1],[0x7FFFFFFF,0x7FFFFFFF],[0x80000000,48000]]:
            add('word-lanes-'+str(len(cases)),[operation(kind,sample=sample,frequency=1)])
        for counter in [0,0xFFFFFFFF,0x100000001,0xFFFFFFFFFFFFFFFF]:
            add('counter-lanes-'+str(len(cases)),[operation(kind,counter=counter,frequency=1)])
    add('progress-pause-resume',[operation(actual=actual,sample=[n*1600,48000],counter=n*19200) for n,actual in enumerate([4,4,4,-4,-4,4,6,-6,4,4])])
    add('raw-cache-equal-denominator',[operation(sample=[n,rate],counter=0,frequency=1) for n,rate in [(2000,48000),(2000,24000),(1999,1000),(2001,12000)]],[2000,90000])
    add('cache-signed-narrowing',[operation(sample=[n,48000],frequency=1) for n in [0x7FFFFFFF,0x80000000,0xFFFFFFFF,0,0x7FFFFFFF]])
    for speed in [800,1600,2400]:add('filtered-trajectory-'+str(speed),[operation(sample=[n*speed,48000],counter=n*19200) for n in range(64)])
    for pause in [0,1,2]:add('filter-pause-'+str(pause),[operation(sample=[n*1600,48000],counter=n*19200) for n in range(8)],seed=dict(pause=pause))
    for kind in ['slot','envelope']:
        for sample in [[-1,48000],[0x80000000,48000],[1600,-1],[1600,0x80000000]]:
            add('filtered-signed-word-lanes-'+str(len(cases)),[operation(kind,sample=sample)])
    return cases


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    out.mkdir(parents=True);cases=corpus();results=[]
    sources=[Path(__file__)]+[ROOT/'tools/native_reconstruction'/name for name in ['movie_audio_filter_oracle.py','movie_counter_clock_oracle.py','ee_copy_store_oracle.py','adx_stereo_oracle.py','movie_position_oracle.py','ee_mac_oracle.py','sjuni_oracle.py']]
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(p.relative_to(ROOT)):sha(p) for p in sources},bodies={hex(start):dict(end=hex(end),sha256=digest) for start,(end,digest) in Machine(cases[0]).extra_bodies.items()},native_exists=(ROOT/'game/native/movie_audio_clock').exists(),external_ports='132160 estimator word pair; 17E870 raw counter; actual status/frequency getters/filter/cache execute',game_run=False,device_opened=False)
    manifest['existing_native_sources']={p.name:sha(p) for p in (ROOT/'game/native/movie_audio_clock').iterdir() if p.is_file() and p.suffix in ['.cpp','.hpp','.py','.json','.txt']}
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
    try:
        for case in cases:
            machine=Machine(case);rows=[machine.execute(op) for op in case['operations']]
            results.append(dict(name=case['name'],operations=rows,instructions=machine.steps,calls={hex(k):v for k,v in machine.calls.items()},visits={hex(k):v for k,v in machine.visited.items()}))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt=dict(schema=1,status='original bounded movie audio envelope returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),native_exists=manifest['native_exists'],outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json']},game_run=False,device_opened=False)
    except Exception as error:
        (out/'partial.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');receipt=dict(status='failed',completed_cases=len(results),failure=str(error));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=receipt['cases'],operations=receipt['operations'],instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
