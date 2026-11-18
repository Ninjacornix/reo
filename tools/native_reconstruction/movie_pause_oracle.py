#!/usr/bin/env python3
"""Original pause/buffering/step controller, with declared command/predicate ports."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import movie_selected_clock_oracle as selected
from movie_position_oracle import BODIES as MATH_BODIES,NORM,NORM_BYTES
from sjuni_oracle import MASK64,OracleError,StepLimit,sext32

ROOT=selected.ROOT;BASE=ROOT/'build-native-sjuni/movie-pause'
MAIN,TOP,RETURN=selected.counter.MAIN,selected.counter.TOP,selected.counter.RETURN
LAST=0x22EF80;RATE=0x240AF0
FIELDS=dict(actual=0x48,requested=0x4C,pause=0x50,depth=0x54,pending=0x44,buffering=0x964,episodes=0x968,
            rate=0x920,active_counter=0xF24,elapsed_counter=0xF48,external_accumulator=0xF58,external_denominator=0xF5C)
INTERVALS={0x1720C8:0x172158,0x172158:0x1721E8,0x1721E8:0x172250,0x172250:0x172278,0x172C48:0x172CF8,
           0x176D08:0x176D68,0x176D68:0x176DB0,0x176DB0:0x176DE8,0x176DE8:0x176E28,0x169E30:0x169E50}
ENTRIES=dict(pause=0x1720C8,nested=0x172158,forward=0x1721E8,buffer=0x172C48,step=0x176D08)
PORTS={0x177BE0:'command',0x172CF8:'pause_predicate',0x172E78:'resume_predicate',0x169C10:'error',0xF00010:'guard_enter',0xF00020:'guard_leave'}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(selected.Machine):
    def __init__(self,case):
        preset=selected.case('selected',guard_hooks=case['guard_hooks'],guard_depth=case['guard_depth'],guard_tag=case['guard_tag'])
        super().__init__(preset);self.pause_case=case;self.steps=0
        if sha(ROOT/'game_data/SLUS_207.65')!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise OracleError('Owned full ELF identity')
        self.extra_bodies={start:(end,hashlib.sha256(self.elf.read(start,end-start)).hexdigest()) for start,end in INTERVALS.items()}
        self.extra_bodies.update({start:MATH_BODIES[start] for start in [0x15BA80,0x10FB18]})
        for start,(end,digest) in self.extra_bodies.items():
            data=self.elf.read(start,end-start)
            if hashlib.sha256(data).hexdigest()!=digest:raise OracleError('Owned pause body identity')
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        for name,address,length,write in [('last',LAST,4,True),('rates',RATE,36,False),('normalization',NORM,NORM_BYTES,False)]:
            self.mem.span(name,address,length,write,0)
            if not write:self.mem.store(address,length,int.from_bytes(self.elf.read(address,length),'little'))
        if hashlib.sha256(self.elf.read(RATE,36)).hexdigest()!='a667ab0a5ce47cd7b60cc99ae7013e555d1042649698fecaa52ad08eb3b25f6b':raise OracleError('Owned picture-rate identity')
        self.mem.store(selected.counter.FREQUENCY,4,case['frequency'])
        for name,offset in FIELDS.items():self.mem.store(MAIN+offset,4,case['state'][name])
        self.events=[]

    def capture(self):
        active,self.mem.active=self.mem.active,False
        raw=bytearray(self.mem.load(MAIN,0x2C00).to_bytes(0x2C00,'little'))
        for offset in FIELDS.values():raw[offset:offset+4]=bytes(4)
        value=dict(state={name:self.mem.load(MAIN+offset,4) for name,offset in FIELDS.items()},guard_depth=self.mem.load(selected.GUARD,4),guard_tag=self.mem.load(selected.GUARD+4,4),last=self.mem.load(LAST,4),main_guard_sha256=hashlib.sha256(raw).hexdigest())
        self.mem.active=active;return value

    def invoke(self,pc,operation):
        kind=PORTS[pc];event=dict(kind=kind,before=self.capture(),arguments=[value&0xFFFFFFFF for value in self.regs[4:9]])
        if kind=='command' and event['arguments']!=[MAIN,7,8,operation['expected_mode'],0]:raise OracleError('Fixed component pause route '+str(event['arguments']))
        if kind=='error' and event['arguments'][:3]!=[0,0xFF000142,1]:raise OracleError('Pause error arguments')
        if kind in ['pause_predicate','resume_predicate','command','error']:
            for name,value in operation.get('updates',{}).get(kind,{}).items():
                if name not in FIELDS:raise OracleError('Undeclared state patch')
                self.mem.store(MAIN+FIELDS[name],4,value)
        self.events.append(event)
        for register in [1,*range(2,16),24,25]:self.regs[register]=(0xCBEE000000000000+pc+register)&MASK64
        self.regs[2]=sext32(operation.get('replies',{}).get(kind,0))
        return self.regs[31]&0xFFFFFFFF

    def execute(self,operation):
        for n,value in enumerate([MAIN,sext32(operation['value'])]):self.regs[4+n]=value
        self.regs[29]=TOP;self.regs[31]=RETURN;start=self.steps;event_start=len(self.events);write_start=len(self.mem.writes);read_start=len(self.mem.reads)
        before=self.capture();pc=ENTRIES[operation['kind']];pending=None;self.mem.active=True
        while pc!=RETURN:
            if self.steps-start>=10000:raise StepLimit('Original pause operation exhausted')
            if pc in PORTS:
                if pending is not None:raise OracleError('Port in delay slot')
                pc=self.invoke(pc,operation);continue
            if pc not in self.code or pc%4:raise OracleError('Unowned pause transfer '+hex(pc))
            self.steps+=1;self.visited[pc]=self.visited.get(pc,0)+1
            if pc in self.extra_bodies or pc in selected.BODIES:self.calls[pc]=self.calls.get(pc,0)+1
            branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Branch in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False;after=self.capture()
        if self.regs[29]!=TOP or any(self.regs[r]!=v for r,v in self.saved.items()):raise OracleError('Pause ABI restoration')
        if before['main_guard_sha256']!=after['main_guard_sha256']:raise OracleError('Pause escaped admitted fields')
        return dict(operation=operation,before=before,after=after,return_defined=operation['kind']!='step',raw_v0_lower64=self.regs[2]&MASK64,instructions=self.steps-start,events=self.events[event_start:],writes=self.mem.writes[write_start:],reads=self.mem.reads[read_start:])


def operation(kind,value=0,mode=0,replies=None,updates=None):return dict(kind=kind,value=value&0xFFFFFFFF,expected_mode=mode&0xFFFFFFFF,replies=replies or {},updates=updates or {})


def corpus():
    cases=[]
    def add(name,operations,state=None,**changes):
        initial=dict(actual=4,requested=4,pause=0,depth=0,pending=0,buffering=0,episodes=0,rate=1,active_counter=100,elapsed_counter=0xFFFFFFFF,external_accumulator=500,external_denominator=48000)
        initial.update({name:value&0xFFFFFFFF for name,value in (state or {}).items()})
        case=dict(name=name,state=initial,operations=operations,frequency=48000,guard_hooks=0,guard_depth=0,guard_tag=0)
        case.update(changes);cases.append(case)
    for old in [0,1,2,0xFFFFFFFF]:
        for value in [0,1,2,0xFFFFFFFF]:
            for requested in [0,3,4,5]:
                mode=0 if value==0 else 2 if old else 1
                add('public-'+str(len(cases)),[operation('pause',value,mode,dict(command=0x81234567))],dict(pause=old,depth=int(bool(old)),requested=requested))
    for depth in [0,1,2,0x7FFFFFFF,0x80000000,0xFFFFFFFF]:
        for value in [0,1,2,3,0xFFFFFFFF]:
            for actual in [4,-4,6,1]:add('nested-'+str(len(cases)),[operation('nested',value,value,dict(command=0xFFFFFFFF))],dict(depth=depth,actual=actual))
    for requested in [0,1,2,3,4,5,0xFFFFFFFF]:
        for mode in [0,1,2,3,0xFFFFFFFF]:add('forward-'+str(len(cases)),[operation('forward',mode,mode,dict(command=0x80000001))],dict(requested=requested))
    for rate in range(9):
        for frequency in [0,48000,0x7FFFFFFF,0x80000000,0xFFFFFFFF]:
            add('step-'+str(len(cases)),[operation('step',2)],dict(rate=rate,active_counter=0x7FFFFFFF,elapsed_counter=0xFFFFFFFF,external_accumulator=0xFFFFFFFF,external_denominator=frequency),frequency=frequency)
    for active in [0,1,2,0xFFFFFFFF]:
        for reply in [0,1,2,0xFFFFFFFF]:
            for guard in [0,1]:
                kind='resume_predicate' if active else 'pause_predicate';mode=0 if active else 1
                add('buffer-'+str(len(cases)),[operation('buffer',mode=mode,replies={kind:reply,'command':0x80000001})],dict(buffering=active,depth=int(bool(active)),episodes=0xFFFFFFFF),guard_hooks=guard)
    for depth in [1,0xFFFFFFFF]:add('guard-depth-'+str(depth),[operation('buffer',mode=1,replies=dict(pause_predicate=1))],guard_hooks=1,guard_depth=depth,guard_tag=9)
    add('repeated-public-pause',[operation('pause',1,1),operation('pause',2,2),operation('pause',0,0),operation('pause',0,0),operation('pause',0xFFFFFFFF,1),operation('pause',0,0)])
    add('nested-sequence',[operation('nested',1,1),operation('nested',1,1),operation('nested',0,0),operation('nested',0,0),operation('nested',0,0)])
    add('buffer-sequence',[operation('buffer',mode=1,replies=dict(pause_predicate=1)),operation('buffer',mode=0,replies=dict(resume_predicate=0)),operation('buffer',mode=0,replies=dict(resume_predicate=1))],guard_hooks=1)
    add('command-state-updates',[operation('pause',1,1,replies=dict(command=19),updates=dict(command=dict(actual=6,requested=3,pause=2,depth=7,pending=99)))])
    add('predicate-state-updates',[operation('buffer',mode=1,replies=dict(pause_predicate=1),updates=dict(pause_predicate=dict(requested=2,depth=0xFFFFFFFF,episodes=0xFFFFFFFF)))],guard_hooks=1)
    add('invalid-actual',[operation('pause',1,1,replies=dict(error=0x81234567))],dict(actual=0))
    add('negative-actual-valid',[operation('pause',1,1)],dict(actual=0xFFFFFFFF))
    return cases


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    out.mkdir(parents=True);cases=corpus();first=Machine(cases[0]);results=[]
    sources=[Path(__file__)]+[ROOT/'tools/native_reconstruction'/name for name in ['movie_selected_clock_oracle.py','movie_counter_clock_oracle.py','movie_position_oracle.py','ee_mac_oracle.py','sjuni_oracle.py']]
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(p.relative_to(ROOT)):sha(p) for p in sources},owned_extra_bodies={hex(start):dict(end=hex(end),sha256=digest) for start,(end,digest) in first.extra_bodies.items()},native_exists=(ROOT/'game/native/movie_pause').exists(),external_ports='component command, complete buffer predicates, invalid-state error handler; isolated paired pure guard hooks',game_run=False,device_opened=False)
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
    try:
        for case in cases:
            machine=Machine(case);rows=[machine.execute(op) for op in case['operations']]
            results.append(dict(name=case['name'],operations=rows,instructions=machine.steps,calls={hex(k):v for k,v in machine.calls.items()},visits={hex(k):v for k,v in machine.visited.items()}))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt=dict(schema=1,status='original bounded movie pause controller returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),native_exists=manifest['native_exists'],outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json']},game_run=False,device_opened=False)
    except Exception as error:
        (out/'partial.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');receipt=dict(status='failed',completed_cases=len(results),failure=str(error));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=receipt['cases'],operations=receipt['operations'],instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
