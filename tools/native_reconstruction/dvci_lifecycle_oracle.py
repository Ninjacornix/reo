#!/usr/bin/env python3
"""Owned-word DVCI lifecycle execution; bounded scripted external services.

No I/O, game, runtime, native lifecycle algorithm or instruction arrays. Device
responses and cached-file metadata are explicit external inputs; only original
instructions change the DVCI slots, break flag, stop counters or open fields.
"""
from dataclasses import asdict, dataclass
import argparse
import hashlib
import json
from pathlib import Path
import struct

from dvci_oracle import Machine as ScalarMachine, HookPlan, SRD, BUFFER, TABLE, TABLE_BYTES
from sjuni_oracle import OracleError, StepLimit, MASK32, sext32, signed

ROOT=Path(__file__).resolve().parents[2]
POOL,STRIDE,SLOTS=0x21CC60,0x48,40
SUBJECT=POOL+39*STRIDE
NAME=0x500100
VERBOSITY=0x21D8E8
GATE=0x21CBF0
RETURN=0xFFFFF0
ENTRIES={
    'stop':(0x139EA8,0x139FA8,False),
    'close':(0x139BD8,0x139C30,False),
    'find_slot':(0x1399F8,0x139A2C,True),
    'clear':(0x139A30,0x139A4C,False),
    'open':(0x139A50,0x139BD4,True),
    'status':(0x139FA8,0x139FE0,True),
    'tell':(0x139CC8,0x139D00,True),
    'transferred':(0x139FE8,0x13A034,True),
}
SUPPORT=((0x139798,0x139810),(0x1396D0,0x139794),(0x137868,0x1378D0))
HOOKS={0x141700:'enter',0x141778:'leave',0x1395F8:'diagnostic',
       0x116848:'message',0x142190:'service_gate',0x137D80:'server_service',
       0x137608:'srd_status',0x1373C8:'srd_destroy',0x107C68:'memset',
       0x13AA00:'cached_metadata'}


@dataclass(frozen=True)
class Plan:
    service_gate:int=1
    srd_states:tuple=(3,)
    cached_bytes:int=4097
    cached_lba:int=0x123400
    cached_result:int=2
    verbosity:int=2

    def validate(self):
        if self.service_gate not in (0,1):raise OracleError('Unknown scripted gate response')
        if not self.srd_states or any(x not in range(10) for x in self.srd_states):
            raise OracleError('Unknown scripted SRD response')
        if not 1<=self.cached_bytes<=0x7FFFF000:raise OracleError('Only bounded positive cached files admitted')
        if not 0<=self.cached_lba<=MASK32 or self.cached_result not in (1,2):
            raise OracleError('Unknown cached-file metadata domain')
        if self.verbosity not in (0,2):raise OracleError('Unknown verbosity fixture domain')


class Machine(ScalarMachine):
    def __init__(self,elf_path=ROOT/'game_data/SLUS_207.65',plan=Plan()):
        plan.validate()
        super().__init__(elf_path,HookPlan())
        self.script=plan
        self.code={(a,b):self.elf.read(a,b-a) for a,b,_ in ENTRIES.values()}
        self.code.update({(a,b):self.elf.read(a,b-a) for a,b in SUPPORT})
        if any(raw is None or len(raw)!=b-a for (a,b),raw in self.code.items()):
            raise OracleError('Owned lifecycle body unavailable')
        self.mem.map(POOL,STRIDE*SLOTS)
        self.mem.map(GATE,4)
        self.mem.map(SRD,0x40,0xA5)
        self.mem.map(NAME,64)
        for i,ch in enumerate(b'SYNTHETIC.BIN\0'):self.mem.store(NAME+i,1,ch)
        for i in range(SLOTS):self.mem.store(POOL+i*STRIDE,1,1)
        self.mem.fill(SUBJECT,STRIDE,0xA5)
        self.mem.store(SUBJECT,1,1);self.mem.store(SUBJECT+2,1,2)
        for off,value in {4:8192,8:4,12:3,16:1,20:0x11223344,24:BUFFER,28:SRD,32:0x123400}.items():
            self.mem.store(SUBJECT+off,4,value)
        self.mem.store(SRD,1,1);self.mem.store(SRD+2,1,2);self.mem.store(SRD+4,4,0)
        self.mem.store(VERBOSITY,4,plan.verbosity)
        self.mem.store(GATE,4,1)
        self.status_queries=0
        self.visited=set()
        self.guard_depth=0

    def image(self,address,size):
        data,offset=self.mem.region(address,size)
        return bytes(data[offset:offset+size])

    def local_snapshot(self):
        return dict(subject_address=SUBJECT,subject_bytes_hex=self.image(SUBJECT,STRIDE).hex(),
                    srd_prefix_hex=self.image(SRD,8).hex())

    def snapshot(self):
        return dict(**self.local_snapshot(),pool_bytes_hex=self.image(POOL,STRIDE*SLOTS).hex(),
                    verbosity=self.mem.load(VERBOSITY,4),gate_word=self.mem.load(GATE,4),
                    destination_probe_hex=self.image(BUFFER,64).hex())

    def hook(self,pc):
        if pc not in HOOKS:return False
        kind=HOOKS[pc]
        response=0
        before=self.image(SUBJECT,STRIDE)
        srd_before=self.image(SRD,8)
        depth_before=self.guard_depth
        args=tuple(self.regs[4:9])
        if kind=='enter':self.guard_depth+=1
        elif kind=='leave':
            self.guard_depth-=1
            if self.guard_depth<0:raise OracleError('Unbalanced lifecycle guard')
        elif kind=='service_gate':
            if args[0]&MASK32!=GATE:raise OracleError('Unknown service gate address')
            response=self.script.service_gate
        elif kind=='srd_status':
            if args[0]&MASK32!=SRD:raise OracleError('Unknown scripted SRD identity')
            index=min(self.status_queries,len(self.script.srd_states)-1)
            response=self.script.srd_states[index];self.status_queries+=1
        elif kind=='srd_destroy':
            if args[0]&MASK32!=SRD:raise OracleError('Unknown scripted SRD identity')
        elif kind=='memset':
            address,count=args[0]&MASK32,args[2]&MASK32
            if address!=SUBJECT or count!=STRIDE or args[1]!=0:
                raise OracleError('Unexpected lifecycle clear range')
            self.mem.fill(address,count,0)
            response=address
        elif kind=='cached_metadata':
            address=args[1]&MASK32
            if args[0]&MASK32!=NAME or address!=SUBJECT+32:
                raise OracleError('Unexpected cached-file output identity')
            # Explicit external metadata input, NOT an original cache algorithm.
            self.mem.store(address,4,self.script.cached_lba)
            self.mem.store(address+4,4,self.script.cached_bytes)
            response=self.script.cached_result
        self.regs[2]=sext32(response)
        after=self.image(SUBJECT,STRIDE)
        srd_after=self.image(SRD,8)
        self.event_total+=1
        self.event_counts[kind]=self.event_counts.get(kind,0)+1
        self.event_trace.update(struct.pack('<IIii5Q',pc,self.last_transfer_pc or 0,
                                           depth_before,self.guard_depth,*args))
        self.event_trace.update(before+srd_before+after+srd_after+struct.pack('<Q',self.regs[2]))
        sample=dict(kind=kind,target_pc=pc,from_pc=self.last_transfer_pc,arguments_u64=list(args),
                    guard_depth_before=depth_before,guard_depth_after=self.guard_depth,
                    scripted_return_u64=self.regs[2],
                    observed_before=dict(subject_bytes_hex=before.hex(),srd_prefix_hex=srd_before.hex()),
                    observed_after=dict(subject_bytes_hex=after.hex(),srd_prefix_hex=srd_after.hex()))
        record=self.samples.setdefault(kind,dict(first=[],last=[]))
        if len(record['first'])<2:record['first'].append(sample)
        record['last'].append(sample)
        if len(record['last'])>2:record['last'].pop(0)
        self.pc=self.regs[31]&MASK32
        return True

    def run(self,operation,args,step_cap=40_000_000):
        if operation not in ENTRIES:raise OracleError('Unknown lifecycle entry')
        if len(args)>4 or step_cap<=0:raise OracleError('Invalid isolated lifecycle call')
        if bytes(self.mem.load(TABLE+i,1) for i in range(TABLE_BYTES))!=self.original_table:
            raise OracleError('Owned dispatch table modified')
        self.script.validate()
        if self.mem.load(SUBJECT+2,1) not in (0,1,2,3):raise OracleError('Unknown DVCI subject state')
        self.regs=[0]*32;self.regs[2]=0xBAD0BAD0
        self.regs[29]=0x71F000;self.regs[31]=RETURN
        for i,arg in enumerate(args):self.regs[4+i]=sext32(arg)
        entry,_,defined=ENTRIES[operation]
        self.pc=entry;self.last_transfer_pc=None
        self.event_total=0;self.event_counts={};self.samples={};self.event_trace=hashlib.sha256()
        pending=None;steps=0;call_pcs=set()
        self.pc_counts={}
        while self.pc!=RETURN:
            if steps>=step_cap:raise StepLimit('Owned lifecycle instruction budget exceeded')
            steps+=1
            if pending is None and self.hook(self.pc):continue
            pc=self.pc;word=self.fetch(pc);call_pcs.add(pc)
            self.pc_counts[pc]=self.pc_counts.get(pc,0)+1
            branch=self.instruction(pc,word)
            if pending is not None:
                if branch is not None:raise OracleError('Control transfer in lifecycle delay slot')
                self.pc,self.last_transfer_pc=pending;pending=None
            elif branch is not None:
                taken,target,likely=branch
                if not taken and likely:self.pc=pc+8
                else:pending=(target if taken else pc+8,pc);self.pc=pc+4
            else:self.pc=pc+4
        if self.guard_depth:raise OracleError('Unbalanced lifecycle guards')
        self.visited.update(call_pcs)
        return dict(entry_pc=entry,arguments_i32=[signed(x,32) for x in args],
            return_is_defined=defined,return_u32=self.regs[2]&MASK32 if defined else None,
            return_raw_u64_observation_only=self.regs[2],steps=steps,visited_pcs=sorted(call_pcs),
            pc_execution_counts={hex(pc):count for pc,count in sorted(self.pc_counts.items())},
            hook_count=self.event_total,hook_counts=self.event_counts,hook_trace_sha256=self.event_trace.hexdigest(),
            hook_samples=self.samples,state=self.snapshot())


class Scenario:
    def __init__(self,name,plan=Plan(),writes=(),elf_path=ROOT/'game_data/SLUS_207.65'):
        self.name=name;self.machine=Machine(elf_path,plan);self.operations=[]
        self.initial_writes=list(writes)
        for address,size,value in writes:self.machine.mem.store(address,size,value)
        self.initial_state=self.machine.snapshot()
    def call(self,operation,args):
        r=self.machine.run(operation,args)
        self.operations.append(dict(operation=operation,expected=r));return r
    def fixture(self):
        return dict(name=self.name,external_plan=asdict(self.machine.script),
                    initial_writes=self.initial_writes,initial_state=self.initial_state,operations=self.operations)


def generate(elf_path=ROOT/'game_data/SLUS_207.65',include_caps=False):
    cases=[]
    def case(name,**kwargs):
        s=Scenario(name,elf_path=elf_path,**kwargs);cases.append(s);return s
    for state in (0,1):
        s=case(f'stop_early_state{state}',writes=[(SUBJECT+2,1,state)])
        s.call('stop',[SUBJECT]);s.call('close',[SUBJECT]);s.call('find_slot',[])
        s.call('open',[NAME,0,0]);s.call('status',[SUBJECT]);s.call('tell',[SUBJECT])
    for state in (2,3):
        for terminal in (0,3,9):
            s=case(f'stop_state{state}_srd{terminal}',plan=Plan(srd_states=(terminal,)),
                   writes=[(SUBJECT+2,1,state)])
            s.call('stop',[SUBJECT]);s.call('close',[SUBJECT]);s.call('find_slot',[])
            s.call('open',[NAME,0,0])
    s=case('pending_sequence_then_complete',plan=Plan(srd_states=(1,2,4,3)))
    s.call('stop',[SUBJECT]);s.call('transferred',[SUBJECT])
    s=case('error_state_without_request',writes=[(SUBJECT+2,1,3),(SUBJECT+28,4,0)])
    s.call('stop',[SUBJECT])
    s=case('null_stop_close')
    s.call('stop',[0]);s.call('close',[0])
    s=case('no_free_slot')
    s.call('find_slot',[]);s.call('open',[NAME,0,0])
    for free in ((0,),(0,3),(0,3,39)):
        s=case('last_free_'+'_'.join(map(str,free)),
               writes=[(POOL+i*STRIDE,1,0) for i in free])
        s.call('find_slot',[])
    s=case('open_argument_rejections')
    s.call('open',[0,0,0]);s.call('open',[NAME,0,1])
    for result in (1,2):
        s=case(f'cached_reopen_result{result}',plan=Plan(cached_result=result),
               writes=[(SUBJECT+2,1,0)])
        s.call('close',[SUBJECT]);s.call('open',[NAME,0,0])
    if include_caps:
        for verbosity in (0,2):
            s=case(f'owned_cap_verbosity{verbosity}',plan=Plan(service_gate=0,verbosity=verbosity))
            s.call('stop',[SUBJECT])
            s.call('close',[SUBJECT]);s.call('find_slot',[]);s.call('open',[NAME,0,0])
    m=cases[0].machine
    return dict(schema=1,kind='offline owned-word DVCI lifecycle fixtures',
        identity=dict(elf_sha256=m.elf.sha256,
            integer_engine_sha256=hashlib.sha256((ROOT/'tools/native_reconstruction/sjuni_oracle.py').read_bytes()).hexdigest(),
            generator_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
            bodies=[dict(start_pc=a,end_pc_exclusive=b,sha256=hashlib.sha256(raw).hexdigest())
                    for (a,b),raw in sorted(m.code.items())]),
        assumptions=['External gate and SRD status values are scripted/preserving; not real device progress.',
            'Only cache metadata and generic bounded memset have declared external memory effects.',
            'All DVCI slot/break/stop counter/open field changes execute original owned instructions.',
            'Hook streams retain exact counts/hash and first/last two samples per kind to bound cap output.',
            'No payload IO, scheduling, callback reentry, cancellation acknowledgement or SJ lease exists.'],
        counts=dict(cases=len(cases),operations=sum(len(s.operations) for s in cases),
                    caps_included=include_caps,interpreted_steps=sum(o['expected']['steps'] for s in cases for o in s.operations)),
        cases=[s.fixture() for s in cases])


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    parser.add_argument('--include-caps',action='store_true',help='Execute both complete original 655360-iteration stop caps; slower')
    parser.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/dvci-lifecycle-fixtures.json')
    args=parser.parse_args()
    result=generate(args.elf,args.include_caps)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts']),flush=True)


if __name__=='__main__':main()
