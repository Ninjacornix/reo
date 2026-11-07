#!/usr/bin/env python3
"""Owned selected-clock/cache paths with explicitly declared external ports."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import movie_counter_clock_oracle as counter
from sjuni_oracle import OracleError, StepLimit, MASK64, sext32

ROOT=counter.ROOT;BASE=ROOT/'build-native-sjuni/movie-selected-clock'
BODIES={
    0x176350:(0x1763A0,'ae93d0ad2db06a8a2edf2b3199166da52f1e7e3e5e324bc7c07e3606fccc8c64'),
    0x176418:(0x1764B0,'6b05daafad4a64bb4c2ae147af8f2c16a871fcf18fab11d071b9fb9b84c3c1d6'),
    0x176578:(0x176670,'8164edb3e300b7098ecabe918852d5897a692ad425d996f375421a26aa97e8e2'),
    0x176930:(0x1769B0,'7d4b85519e5dcdb827752ecb1dd663bd74e58b1889a4a28fb1567e1a8857e228'),
    0x175E00:(0x175E50,'ef99d55af3c6944cb4928eec279e232e5b461161e4125e013289f4ede14dd313'),
    0x169EC8:(0x169EE0,'e7305c8f06da25d73aef8c55c358239179bb4f6876af960988024575cb8192a1'),
    0x169EE0:(0x169EF8,'01aa00baf918526c6ba57f488e005b9f9955a22634e541bb8dd31ce0914e8bf3'),
    0x12BD78:(0x12BD90,'a0b922d5b53855344c6f28b60e25d44372dd6a558687713159fdb6d65183b53a'),
    0x12BD90:(0x12BDA8,'040d357cd8d4aad7a9ca9f627531ecd5392e8c04db841e4bb3d288f352669766'),
    0x1416D0:(0x1416E8,'a268cf73feb0d3254f9f247e1e85b354770933495ab01becd145fd79d2a5978d'),
    0x1416E8:(0x141700,'d8a486eca0ebe2996a12fcb8f3e04c17a4025d589a79e4c5c08d88c8e9c857e0'),
    0x1415E0:(0x141640,'2151638dc19b6aa672e6ed9d095954bc70fa1bf679ef0c496d2b7f5c8abb8425'),
    0x141640:(0x1416D0,'119398a781be0ad759b7674f1645efbc8066a463bc44a0ba33a6ec326488324d')}
ENTRIES=dict(selected=0x176418,cached=0x176350,external=0x176578,refresh=0x176930,tick=0x175E00)
FIELDS=dict(counter.FIELDS,selector_f=0x9DC,pending=0x44,cached_numerator=0xF08,cached_denominator=0xF0C,
            previous_sample=0xF54,external_denominator=0xF5C,external_callback=0xF50)
FIELDS.update({'slot'+str(n):0xCC0+n*4 for n in range(7)})
PORTS={0xF00000:'query',0xF00010:'guard_enter',0xF00020:'guard_leave'}
HOOKS,GUARD=0x2649E0,0x22A5F0
sha=counter.sha


class Machine(counter.Machine):
    def __init__(self,case):
        super().__init__(case);self.case=case
        for start,(end,digest) in BODIES.items():
            data=self.elf.read(start,end-start)
            if data is None or hashlib.sha256(data).hexdigest()!=digest:raise OracleError('Original selected-clock body identity')
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        self.all_bodies=dict(counter.BODIES)|BODIES
        self.mem.span('guard_hooks',HOOKS,16,False,0);self.mem.span('guard_state',GUARD,8,True,0)
        for n,value in enumerate([0xF00010 if case['guard_hooks'] else 0,0x11223344,0xF00020 if case['guard_hooks'] else 0,0x55667788]):self.mem.store(HOOKS+n*4,4,value)
        self.mem.store(GUARD,4,case['guard_depth']);self.mem.store(GUARD+4,4,case['guard_tag'])
        slots=[0x1764B0,0x1764F8,0,0x176558,0,0x176578,0]
        if case['slot_kind']=='custom':slots[case['selector_f']]=0xF00000
        elif case['slot_kind']=='null':slots[case['selector_f']]=0
        for n,value in enumerate(slots):self.mem.store(counter.CLOCK+n*4,4,value)
        for name in ['pending','cached_numerator','cached_denominator','previous_sample','external_denominator']:self.mem.store(counter.MAIN+FIELDS[name],4,case[name])
        self.mem.store(counter.MAIN+FIELDS['external_callback'],4,0xF00000 if case['external_present'] else 0)
        if case['operation'] in ['refresh','tick']:
            self.mem.store(counter.TOP-0x30,4,case['refresh_scratch_numerator']);self.mem.store(counter.TOP-0x2C,4,case['refresh_scratch_denominator'])
        offset=0x40 if case['operation']=='external' else 0xB0 if case['operation'] in ['refresh','tick'] else 0x80
        self.mem.store(counter.TOP-offset,4,case['external_scratch_numerator']);self.mem.store(counter.TOP-offset+4,4,case['external_scratch_denominator'])
        self.ports=[];self.phases=[];self.scratch_observations=[]

    def snapshot(self):
        active,self.mem.active=self.mem.active,False
        state={name:self.mem.load(counter.MAIN+offset,4) for name,offset in FIELDS.items()}
        raw=bytearray(self.mem.load(counter.MAIN,0x2C00).to_bytes(0x2C00,'little'))
        for offset in FIELDS.values():raw[offset:offset+4]=b'\0'*4
        outputs=bytearray(self.mem.load(counter.NUM,0x40).to_bytes(0x40,'little'));outputs[:4]=outputs[16:20]=b'\0'*4
        result=dict(state=state,numerator=self.mem.load(counter.NUM,4),denominator=self.mem.load(counter.DEN,4),
                    guard_depth=self.mem.load(GUARD,4),guard_tag=self.mem.load(GUARD+4,4),
                    main_guard_sha256=hashlib.sha256(raw).hexdigest(),output_guard_sha256=hashlib.sha256(outputs).hexdigest())
        self.mem.active=active;return result

    def port(self,pc):
        name=PORTS[pc];event=dict(port=name,arguments=[v&0xFFFFFFFF for v in self.regs[4:7]],snapshot=self.snapshot())
        if name=='query':
            a,b=self.regs[5]&0xFFFFFFFF,self.regs[6]&0xFFFFFFFF
            event['before_pair']=[self.mem.load(a,4),self.mem.load(b,4)]
            if self.case['reply_mask']&1:self.mem.store(a,4,self.case['reply_numerator'])
            if self.case['reply_mask']&2:self.mem.store(b,4,self.case['reply_denominator'])
            for field,value in self.case['fact_updates'].items():
                if field not in ['actual','pause','buffering_pause','property_47']:raise OracleError('Undeclared callback fact update')
                self.mem.store(counter.MAIN+FIELDS[field],4,value)
            if self.case['remove_selected_slot']:self.mem.store(counter.CLOCK+self.case['selector_f']*4,4,0)
        self.ports.append(event)
        for r in [1,*range(2,16),24,25]:self.regs[r]=(0xABCDEF0000000000+r)&MASK64
        self.regs[2]=sext32(self.case['reply_status']) if name=='query' else 0
        return self.regs[31]&0xFFFFFFFF

    def run(self):
        before=self.snapshot();self.mem.active=True;pc=ENTRIES[self.operation];pending=None
        while pc!=counter.RETURN:
            if pc in PORTS:
                if pending is not None:raise OracleError('Port in delay slot')
                pc=self.port(pc);continue
            if self.steps>=3000:raise StepLimit('Selected-clock operation exhausted')
            if pc not in self.code or pc%4:raise OracleError('Unowned selected-clock transfer '+hex(pc))
            if pc in [0x176930,0x176578]:
                active,self.mem.active=self.mem.active,False
                base=(self.regs[29]&0xFFFFFFFF)-(0x30 if pc==0x176930 else 0x40)
                self.scratch_observations.append(dict(kind='refresh' if pc==0x176930 else 'external',words=[self.mem.load(base,4),self.mem.load(base+4,4)]))
                self.mem.active=active
            if pc in [0x169EC8,0x169EE0]:self.phases.append(dict(phase='enter' if pc==0x169EC8 else 'leave',snapshot=self.snapshot()))
            self.steps+=1;self.visited[pc]=self.visited.get(pc,0)+1
            if pc in self.all_bodies:self.calls[pc]=self.calls.get(pc,0)+1
            branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Branch in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False;after=self.snapshot()
        if self.regs[29]!=counter.TOP or any(self.regs[r]!=value for r,value in self.saved.items()):raise OracleError('ABI restoration')
        if any(before[n]!=after[n] for n in ['main_guard_sha256','output_guard_sha256']):raise OracleError('Escaped source state')
        return dict(before=before,after=after,return_defined=self.operation in ['selected','cached','external'],raw_v0_lower64=self.regs[2],
                    original_instructions=self.steps,calls={hex(k):v for k,v in self.calls.items()},visits={hex(k):v for k,v in self.visited.items()},
                    ports=self.ports,phases=self.phases,scratch_observations=self.scratch_observations,writes=self.mem.writes,reads=self.mem.reads)


def case(operation,**changes):
    value=counter.case(operation);value.update(guard_hooks=0,guard_depth=0,guard_tag=0,slot_kind='default',external_present=True,
        pending=0,cached_numerator=0xFFFFFFFB,cached_denominator=1,previous_sample=1000,external_denominator=48000,
        refresh_scratch_numerator=0x98765432,refresh_scratch_denominator=0x12345678,
        external_scratch_numerator=0x87654321,external_scratch_denominator=0x13572468,
        reply_mask=3,reply_numerator=1200,reply_denominator=48000,reply_status=0,fact_updates={},remove_selected_slot=False)
    for n,v in changes.items():value[n]=v&0xFFFFFFFF if isinstance(v,int) and not isinstance(v,bool) else v
    return value


def corpus():
    out=[]
    def add(row):out.append(dict(name=row['operation']+'-'+str(len(out)),**row))
    for operation in ['selected','cached','refresh','tick']:
        for selector in range(7):
            for actual in [4,-4,6,-6,3]:
                for guard in [0,1]:add(case(operation,selector_f=selector,actual=actual,guard_hooks=guard))
    for cached in [0,-1,-2,-3,-4,-5,-6,0x80000000]:
        for denominator in [0,1,0xFFFFFFFF]:add(case('cached',cached_numerator=cached,cached_denominator=denominator))
    for mask in range(4):
        for status in [0,7,0xFFFFFFFF]:
            for previous in [-5,0,0xFFFFFFFF,0x7FFFFFFF]:
                for changes in [{},{'pause':1},{'buffering_pause':1},{'actual':3}]:
                    add(case('external',reply_mask=mask,reply_status=status,previous_sample=previous,fact_updates=changes))
    for prop in [0,1,2,0xFFFFFFFF]:
        for same in [False,True]:
            for status in [0,0xFFFFFFFF]:add(case('refresh',selector_f=4,slot_kind='custom',property_47=prop,reply_status=status,
                cached_numerator=1200 if same else 1,cached_denominator=48000 if same else 2))
    for selector in range(7):
        for kind in ['custom','null']:add(case('selected',selector_f=selector,slot_kind=kind,remove_selected_slot=kind=='custom',reply_status=0x80000000,guard_hooks=1))
    for depth in [1,0xFFFFFFFF]:add(case('selected',guard_hooks=1,guard_depth=depth,guard_tag=9))
    for prop in [0,2,0xFFFFFFFF]:add(case('tick',property_47=prop,selector_f=4,slot_kind='custom'))
    for prop in [0,1,2,0xFFFFFFFF]:add(case('refresh',selector_f=4,slot_kind='custom',property_47=1,fact_updates={'property_47':prop}))
    for selector in range(7):add(case('selected',selector_f=selector,slot_kind='custom',actual=3,reply_status=7))
    add(case('cached',actual=0,cached_numerator=0xFFFFFFFE,cached_denominator=0))
    add(case('external',external_present=False));add(case('external',actual=0));add(case('external',external_present=False,actual=0));return out


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    out.mkdir(parents=True);rows=corpus();sources=[Path(__file__),Path(counter.__file__),ROOT/'tools/native_reconstruction/movie_position_oracle.py',ROOT/'tools/native_reconstruction/ee_mac_oracle.py',ROOT/'tools/native_reconstruction/sjuni_oracle.py']
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(v.relative_to(ROOT)):sha(v) for v in sources},
                  native_exists=(ROOT/'game/native/movie_selected_clock').exists(),external_ports='declared scripted query/hook inputs; not real provider or priority proof',game_run=False,device_opened=False)
    manifest['existing_native_sources']={str(v.relative_to(ROOT)):sha(v) for v in (ROOT/'game/native/movie_selected_clock').glob('*.cpp')}
    (out/'inputs.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8',newline='\n');(out/'input-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8',newline='\n')
    result=[dict(name=row['name'],**Machine(row).run()) for row in rows]
    (out/'original.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    receipt=dict(schema=1,status='original selected-clock/cache corpus returned',cases=len(rows),instructions=sum(r['original_instructions'] for r in result),native_exists=manifest['native_exists'],game_run=False,device_opened=False,outputs_sha256={n:sha(out/n) for n in ['inputs.json','input-manifest.json','original.json']})
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(dict(status=receipt['status'],cases=len(rows),instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
