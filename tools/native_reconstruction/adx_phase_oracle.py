#!/usr/bin/env python3
"""Bounded owned-word ADX predictor/window scalar fixtures, without codec I/O."""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from sjuni_oracle import (Elf,Memory,Machine as IntegerEngine,OracleError,StepLimit,
                          MASK32,sext32,signed)

ROOT=Path(__file__).resolve().parents[2]
CONTEXT,DECODER=0x400000,0x410000
INPUT,LEFT,RIGHT=0x500000,0x500100,0x500200
RETURN=0xFFFFF0
ENTRIES={
    'phase':(0x134F98,0x134FA0,True),
    'mono':(0x134FA0,0x134FD0,True),
    'stereo':(0x134FD0,0x135000,True),
    'request':(0x135000,0x13501C,True),
    'cancel':(0x135020,0x135044,False),
    'acknowledge':(0x135048,0x135060,False),
    'completed':(0x135060,0x135068,True),
    'mono_window':(0x1252D0,0x125318,True),
    'stereo_window':(0x125318,0x125370,True),
}


class Machine:
    instruction=IntegerEngine.instruction
    def __init__(self,elf_path=ROOT/'game_data/SLUS_207.65',phase=0):
        if phase not in range(4):raise OracleError('Unknown admitted predictor phase')
        self.elf=Elf(elf_path)
        self.code={(a,b):self.elf.read(a,b-a) for a,b,_ in ENTRIES.values()}
        if any(raw is None or len(raw)!=b-a for (a,b),raw in self.code.items()):
            raise OracleError('Owned predictor code unavailable')
        self.mem=Memory();self.mem.map(CONTEXT,0x3C,0xA5)
        self.mem.map(DECODER,0x80,0x5A);self.mem.map(INPUT,0x300,0xD7)
        self.mem.map(0x700000,0x20000,0xCC)
        self.mem.store(CONTEXT+12,4,phase);self.mem.store(CONTEXT+16,4,0x89ABCDEF)
        self.mem.store(CONTEXT+40,8,0x9ABC5678FEDC1234)
        for offset,value in {8:CONTEXT,0x48:INPUT,0x5C:LEFT,0x64:128,0x68:7}.items():
            self.mem.store(DECODER+offset,4,value)
        self.regs=[0]*32;self.pc=0;self.visited=set()

    def snapshot(self):
        return dict(context_words_u32=self.mem.words(CONTEXT,15),
                    decoder_words_u32=self.mem.words(DECODER,32),
                    payload_probe_u32=self.mem.words(INPUT,0x300//4))

    def fetch(self,pc):
        if pc%4:raise OracleError('Unaligned predictor fetch')
        for (a,b),raw in self.code.items():
            if a<=pc<b:return struct.unpack_from('<I',raw,pc-a)[0]
        raise OracleError('Fetch outside admitted predictor/window bodies')

    def run(self,operation,args,step_cap=500):
        if operation not in ENTRIES or len(args)>5 or step_cap<=0:
            raise OracleError('Unknown/invalid predictor operation')
        if self.mem.load(CONTEXT+12,4) not in range(4):
            raise OracleError('Unknown admitted predictor phase')
        self.regs=[0]*32;self.regs[2]=0xBAD0BAD0
        self.regs[29]=0x71F000;self.regs[31]=RETURN
        for i,arg in enumerate(args):self.regs[4+i]=sext32(arg)
        entry,_,defined=ENTRIES[operation]
        self.pc=entry;pending=None;steps=0;events=[];visited=set()
        while self.pc!=RETURN:
            if steps>=step_cap:raise StepLimit('Predictor scalar instruction limit')
            steps+=1
            if pending is None and self.pc==0x107C68:
                if (self.regs[4]&MASK32,self.regs[5],self.regs[6])!=(CONTEXT+40,0,8):
                    raise OracleError('Unexpected predictor clear hook')
                before=self.snapshot()
                self.mem.fill(CONTEXT+40,8,0)
                self.regs[2]=self.regs[4]
                events.append(dict(kind='bounded_memset',bytes=8,before=before,after=self.snapshot()))
                self.pc=self.regs[31]&MASK32;continue
            pc=self.pc;word=self.fetch(pc);visited.add(pc)
            branch=self.instruction(pc,word)
            if pending is not None:
                if branch is not None:raise OracleError('Control in predictor delay slot')
                self.pc=pending;pending=None
            elif branch is not None:
                taken,target,likely=branch
                if not taken and likely:self.pc=pc+8
                else:pending=target if taken else pc+8;self.pc=pc+4
            else:self.pc=pc+4
        self.visited.update(visited)
        return dict(entry_pc=entry,arguments_i32=[signed(a,32) for a in args],steps=steps,
                    visited_pcs=sorted(visited),return_is_defined=defined,
                    return_u32=self.regs[2]&MASK32 if defined else None,
                    return_raw_u64_observation_only=self.regs[2],events=events,state=self.snapshot())


def generate(elf_path=ROOT/'game_data/SLUS_207.65'):
    cases=[]
    def sequence(name,machine,calls):
        initial=machine.snapshot()
        operations=[dict(operation=op,expected=machine.run(op,args)) for op,args in calls]
        cases.append(dict(name=name,initial_state=initial,operations=operations))
    for phase in range(4):
        for mode in ('mono','stereo'):
            args=[CONTEXT,INPUT,3,LEFT]+([RIGHT] if mode=='stereo' else [])
            sequence(f'phase{phase}_{mode}',Machine(elf_path,phase),[
                (mode,args),('request',[CONTEXT]),('phase',[CONTEXT]),
                ('acknowledge',[CONTEXT]),('completed',[CONTEXT]),('cancel',[CONTEXT]),
                ('phase',[CONTEXT]),('completed',[CONTEXT])])
    for mode in ('mono_window','stereo_window'):
        for count,offset in ((0,7),(3,7),(-1,7),(0x7FFFFFFF,0x7FFFFFFF)):
            m=Machine(elf_path);m.mem.store(DECODER+0x68,4,offset)
            sequence(f'{mode}_count{count}_offset{offset}',m,[
                (mode,[DECODER,count]),('phase',[CONTEXT]),('completed',[CONTEXT]),
                ('cancel',[CONTEXT])])
    reference=Machine(elf_path)
    return dict(schema=1,kind='owned-word ADX scalar predictor/window fixtures',
        identity=dict(elf_sha256=reference.elf.sha256,
            integer_engine_sha256=hashlib.sha256(Path(__file__).with_name('sjuni_oracle.py').read_bytes()).hexdigest(),
            generator_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            bodies=[dict(start_pc=a,end_pc_exclusive=b,sha256=hashlib.sha256(raw).hexdigest())
                    for (a,b),raw in sorted(reference.code.items())]),
        assumptions=['Only external bounded memset(8) is modeled; no other external call is admitted.',
            'Payload pointers are synthetic borrowed IDs; no compressed data or PCM is decoded.',
            'Only predictor phase0..3 admitted; void raw return is not a contract.'],
        counts=dict(cases=len(cases),operations=sum(len(c['operations']) for c in cases),
                    runner_steps=sum(o['expected']['steps'] for c in cases for o in c['operations'])),
        cases=cases)


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    p.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/adx-phase-fixtures.json')
    args=p.parse_args();result=generate(args.elf);args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts']))


if __name__=='__main__':main()
