#!/usr/bin/env python3
"""Execute owned movie counter/query bodies before native reconstruction."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from movie_position_oracle import ClockIntegerInstructions, AccessMemory
from sjuni_oracle import Elf, OracleError, StepLimit, MASK64

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/movie-counter-clock'
BODIES={
    0x175628:(0x175638,'6e3275b547a01af456200ef39e39d4ac7930b2821b974851f75bfd604488e2f7'),
    0x175E50:(0x175EC0,'c4b9a919596e3302b1867f6fb88433f70e198628e8b2269de4125bce115d0e5b'),
    0x175EC0:(0x175EF8,'13d5a7d320fc6ed9003de77b0bf657ff510ea947b7405460ec9c3480f80755a0'),
    0x175EF8:(0x175F20,'d7012c2775acd8813f7fa85ccf501af8a51563cd9d5bb75b5fcc975ef292019b'),
    0x175F20:(0x175F68,'8c40ce80904c5491ee839dafc52aba96f85e8b80b1e8f421a1550e4a6cdb9d74'),
    0x1764B0:(0x1764F8,'7bd780705b1e8d4bf1df42d5f647dffd795609044ef5a7ebbf0991fe9f84c319'),
    0x1764F8:(0x176558,'d35c968c5807972d2b5762767c1c53cfef9c6e0b594077e3551b67d033b69a6b'),
    0x176558:(0x176578,'f890f335faa757863623e0cbe7715c799a01cf24dabd6429cfd1ea339d0440a4'),
    0x176670:(0x1766C0,'7480112c8df842a45aaba962b75720f4045974576315b76954c3ef523124dde9')}
MAIN,CLOCK,NUM,DEN=0x400000,0x400CC0,0x500000,0x500010
FREQUENCY,STACK,TOP,RETURN=0x22F140,0x700000,0x701000,0xFFFFF0
FIELDS=dict(actual=0x48,requested=0x4C,pause=0x50,buffering_pause=0x964,
            property_47=0xABC,active_counter=0xF24,increment=0xF28,
            elapsed_counter=0xF48,elapsed_origin=0xF4C,external_accumulator=0xF58)
ENTRIES=dict(tick=0x175E50,active_gate=0x175EC0,elapsed_gate=0x175EF8,
             rebase=0x175F20,unavailable=0x1764B0,counter=0x1764F8,
             contextual=0x176558,admit=0x176670)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(ClockIntegerInstructions):
    def __init__(self,case):
        self.elf=Elf(ROOT/'game_data/SLUS_207.65');self.code={}
        for start,(end,digest) in BODIES.items():
            data=self.elf.read(start,end-start)
            if data is None or hashlib.sha256(data).hexdigest()!=digest:raise OracleError('Original body identity')
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        self.mem=AccessMemory()
        for name,base,length,write,fill in [('main',MAIN,0x2C00,True,0xA5),('outputs',NUM,0x40,True,0x5A),
                                         ('stack',STACK,0x2000,True,0xCC),('frequency',FREQUENCY,4,False,0)]:
            self.mem.span(name,base,length,write,fill)
        for name,offset in FIELDS.items():self.mem.store(MAIN+offset,4,case[name])
        self.mem.store(MAIN+0x9DC,4,case['selector_f'])
        self.mem.store(FREQUENCY,4,case['frequency']);self.mem.store(NUM,4,case['numerator']);self.mem.store(DEN,4,case['denominator'])
        self.regs=[0]*32
        for r in (*range(16,24),30):self.regs[r]=0x1234567800000000+r
        self.saved={r:self.regs[r] for r in (*range(16,24),30)}
        self.regs[2]=0xBAD0BAD0;self.regs[29]=TOP;self.regs[31]=RETURN
        args=[MAIN,CLOCK] if case['operation'] in ['elapsed_gate','rebase'] else [MAIN,NUM,DEN]
        for n,value in enumerate(args):self.regs[4+n]=value
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)
        self.extension_counts={};self.steps=0;self.visited={};self.calls={};self.operation=case['operation']

    def snapshot(self):
        active,self.mem.active=self.mem.active,False
        owned={name:self.mem.load(MAIN+offset,4) for name,offset in FIELDS.items()}
        guard=bytearray(self.mem.load(MAIN,0x2C00).to_bytes(0x2C00,'little'))
        for offset in FIELDS.values():guard[offset:offset+4]=b'\0'*4
        out_guard=bytearray(self.mem.load(NUM,0x40).to_bytes(0x40,'little'));out_guard[0:4]=out_guard[16:20]=b'\0'*4
        result=dict(state=owned,numerator=self.mem.load(NUM,4),denominator=self.mem.load(DEN,4),
                    main_guard_sha256=hashlib.sha256(guard).hexdigest(),output_guard_sha256=hashlib.sha256(out_guard).hexdigest())
        self.mem.active=active;return result

    def run(self):
        before=self.snapshot();self.mem.active=True;pc=ENTRIES[self.operation];pending=None
        while pc!=RETURN:
            if self.steps>=1000:raise StepLimit('Movie counter operation exhausted')
            if pc not in self.code or pc%4:raise OracleError('Unowned control transfer '+hex(pc))
            self.steps+=1;self.visited[pc]=self.visited.get(pc,0)+1
            if pc in BODIES:self.calls[pc]=self.calls.get(pc,0)+1
            branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Control transfer in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False;after=self.snapshot()
        if self.regs[29]!=TOP or any(self.regs[r]!=value for r,value in self.saved.items()):raise OracleError('ABI restoration')
        if any(before[n]!=after[n] for n in ['main_guard_sha256','output_guard_sha256']):raise OracleError('Original escaped admitted fields')
        return dict(before=before,after=after,return_defined=self.operation not in ['tick','rebase'],raw_v0_lower64=self.regs[2]&MASK64,
                    original_instructions=self.steps,calls={hex(k):v for k,v in self.calls.items()},
                    visits={hex(k):v for k,v in self.visited.items()},writes=self.mem.writes,reads=self.mem.reads)


def case(operation,**changes):
    value=dict(operation=operation,actual=4,requested=4,pause=0,buffering_pause=0,property_47=1,selector_f=1,
               active_counter=1234,increment=7,elapsed_counter=5678,elapsed_origin=99,external_accumulator=4321,
               frequency=48000,numerator=0x80000001,denominator=0x12345678)
    value.update({n:v&0xFFFFFFFF for n,v in changes.items()});return value


def corpus():
    states=[4,-4,6,-6,0,1,2,3,5,7,-2147483648,2147483647];out=[]
    def add(value):out.append(dict(name=value['operation']+'-'+str(len(out)),**value))
    for changes in [dict(elapsed_counter=0),dict(active_counter=0xFFFFFFFF,elapsed_counter=0x7FFFFFFF,increment=1),
                    dict(elapsed_counter=0,increment=0),dict(elapsed_counter=0,increment=0x80000000),
                    dict(elapsed_counter=0,pause=1),dict(elapsed_counter=0,buffering_pause=1)]:
        add(case('tick',**changes))
    for state in states:
        for requested in [4,3]:
            for pause,buffer in [(0,0),(1,0),(0,1),(2,0),(0,2)]:
                n=len(out);add(case('tick',actual=state,requested=requested,pause=pause,buffering_pause=buffer,
                                   active_counter=[0,0x7FFFFFFF,0xFFFFFFFF][n%3],elapsed_counter=[0xFFFFFFFF,0,0x7FFFFFFF][n%3],increment=[0,1,7,0x7FFFFFFF,0x80000000,0xFFFFFFFF][n%6]))
        for pause in [0,1,0xFFFFFFFF]:
            for buffer in [0,1,0x80000000]:add(case('active_gate',actual=state,pause=pause,buffering_pause=buffer))
        for operation in ['admit','unavailable','counter','contextual']:
            for frequency in [0,48000,0xFFFFFFFF]:add(case(operation,actual=state,frequency=frequency))
    for requested in [4,3,0,0xFFFFFFFF,0x80000000,0x7FFFFFFF]:
        for value in [0,0xFFFFFFFF,0x80000000]:add(case('elapsed_gate',requested=requested,elapsed_counter=value))
    for prop in [0,1,2,0xFFFFFFFF,0x80000000,0x7FFFFFFF]:
        for value in [0,0xFFFFFFFF,0x80000000]:
            for selector in [0,1,2,0xFFFFFFFF,0x80000000,0x7FFFFFFF]:add(case('rebase',property_47=prop,selector_f=selector,active_counter=value,external_accumulator=value^0x87654321))
    return out


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    rows=corpus();out.mkdir(parents=True)
    sources=[Path(__file__),ROOT/'tools/native_reconstruction/movie_position_oracle.py',ROOT/'tools/native_reconstruction/ee_mac_oracle.py',ROOT/'tools/native_reconstruction/sjuni_oracle.py']
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(p.relative_to(ROOT)):sha(p) for p in sources},
                  bodies={hex(a):dict(end=hex(b),sha256=d) for a,(b,d) in BODIES.items()},native_exists=(ROOT/'game/native/movie_counter_clock').exists(),game_run=False,device_opened=False)
    manifest['existing_native_sources']={str(p.relative_to(ROOT)):sha(p) for p in (ROOT/'game/native/movie_counter_clock').glob('*.cpp')}
    (out/'inputs.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8',newline='\n')
    (out/'input-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8',newline='\n')
    results=[]
    for row in rows:results.append(dict(name=row['name'],**Machine(row).run()))
    (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n')
    receipt=dict(schema=1,status='original movie counter/query corpus returned',cases=len(rows),instructions=sum(r['original_instructions'] for r in results),
                 native_exists=manifest['native_exists'],game_run=False,device_opened=False,outputs_sha256={n:sha(out/n) for n in ['inputs.json','input-manifest.json','original.json']})
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=len(rows),instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
