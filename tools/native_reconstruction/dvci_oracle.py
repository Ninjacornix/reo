#!/usr/bin/env python3
"""Offline original-word DVCI scalar oracle; scripted external services, no I/O.

Reads only the pinned owned File #1 ELF. Reuses the SJUNI integer instruction
engine, never a native DVCI implementation. Generated fixtures contain synthetic
state, trace PCs and hashes, not original instruction arrays or payload bytes.
"""
from __future__ import annotations

import argparse
from dataclasses import asdict, dataclass
import hashlib
import json
from pathlib import Path
import struct

from sjuni_oracle import (Elf, ELF_SHA, Machine as IntegerEngine, Memory,
                          OracleError, StepLimit, MASK32, sext32, signed)

ROOT = Path(__file__).resolve().parents[2]
HANDLE, BUFFER, SRD = 0x400000, 0x500000, 0x21BB88
STACK_BASE, STACK_SIZE, STACK_TOP = 0x700000, 0x20000, 0x71F000
READ_MODE, SYNC_MODE = 0x21D8E0, 0x21D8E4
TABLE, TABLE_BYTES, RETURN = 0x23CA60, 40, 0xFFFFF0
ENTRIES = {
    'seek': (0x139C30, 0x139CC4, True),
    'tell': (0x139CC8, 0x139D00, True),
    'request': (0x139D00, 0x139EA4, True),
    'update': (0x1396D0, 0x139794, False),
    'status': (0x139FA8, 0x139FE0, True),
    'transferred': (0x139FE8, 0x13A034, True),
}
EXTERNAL = {
    0x141700: 'guard_enter', 0x141778: 'guard_leave',
    0x1395F8: 'diagnostic', 0x137340: 'srd_create',
    0x115058: 'cache_range', 0x137468: 'srd_prepare_disc',
    0x100D78: 'cd_sync', 0x137E90: 'server_gate',
    0x137D80: 'server_service', 0x137738: 'srd_wait',
    0x1373C8: 'srd_destroy', 0x137608: 'srd_status',
}


@dataclass(frozen=True)
class HookPlan:
    """Declared external results, not a model of SRD/device implementation."""
    create: int = SRD
    prepare: int = 1
    srd_state: int = 3
    sync_mode: int = 0
    wait_return: int = 0

    def validate(self):
        if self.create not in (0, SRD) or self.prepare not in (0, 1):
            raise OracleError('Unknown scripted SRD admission result')
        if not 0 <= self.srd_state <= 9:
            raise OracleError('Unknown scripted SRD state; only owned table states0..9 admitted')
        if self.sync_mode not in (0, 1, 2):
            raise OracleError('Unknown scripted DVCI sync-mode domain')
        if not -(1 << 31) <= self.wait_return < 1 << 31:
            raise OracleError('Unrepresentable scripted wait result')


class Machine:
    instruction = IntegerEngine.instruction

    def __init__(self, elf_path=ROOT/'game_data/SLUS_207.65', plan=HookPlan()):
        plan.validate()
        self.elf = Elf(elf_path)  # full ELF SHA checked before any instruction
        self.plan = plan
        self.code = {(start, end): self.elf.read(start, end-start)
                     for start, end, _ in ENTRIES.values()}
        if any(raw is None or len(raw) != end-start for (start,end),raw in self.code.items()):
            raise OracleError('Incomplete original DVCI text')
        table = self.elf.read(TABLE,TABLE_BYTES)
        if table is None or len(table) != TABLE_BYTES:
            raise OracleError('Incomplete owned DVCI dispatch table')
        # The table is data read from the same owned ELF, not a hand-written
        # terminal-state algorithm. Every destination must remain in update.
        if any(not ENTRIES['update'][0] <= pc < ENTRIES['update'][1] or pc % 4
               for pc in struct.unpack('<10I',table)):
            raise OracleError('Owned DVCI table escapes the admitted body')
        self.original_table=table
        self.mem = Memory()
        self.mem.map(HANDLE,0x48,0xA5)
        self.mem.map(BUFFER,64,0xD7)  # probes only; no payload I/O is provided
        self.mem.map(READ_MODE,12)
        self.mem.map(TABLE,TABLE_BYTES)
        for i,value in enumerate(table):self.mem.store(TABLE+i,1,value)
        self.mem.map(STACK_BASE,STACK_SIZE,0xCC)
        self.mem.store(HANDLE,1,1)
        self.mem.store(HANDLE+1,1,0)
        self.mem.store(HANDLE+2,1,0)
        for offset,value in {4:20*2048,8:20,12:3,16:6,20:0x11223344,
                             24:BUFFER,28:0,32:0x123400}.items():
            self.mem.store(HANDLE+offset,4,value)
        for i,value in enumerate((1,2,3)):self.mem.store(READ_MODE+i,1,value)
        self.mem.store(SYNC_MODE,4,plan.sync_mode)
        self.regs=[0]*32
        self.pc=0
        self.last_transfer_pc=None
        self.events=[]
        self.guard_depth=0
        self.visited=set()

    def snapshot(self):
        return {
            'handle_address':HANDLE,
            'handle_bytes_u8':[self.mem.load(HANDLE+i,1) for i in range(0x48)],
            'handle_words_u32':self.mem.words(HANDLE,18),
            'destination_probe_bytes_u8':[self.mem.load(BUFFER+i,1) for i in range(64)],
            'mode_bytes_u8':[self.mem.load(READ_MODE+i,1) for i in range(3)],
            'sync_mode_u32':self.mem.load(SYNC_MODE,4),
        }

    def hook(self,pc):
        if pc not in EXTERNAL:return False
        kind=EXTERNAL[pc]
        event=dict(kind=kind,target_pc=pc,from_pc=self.last_transfer_pc,
                   arguments_u64=self.regs[4:9].copy(),guard_depth_before=self.guard_depth,
                   observed_before=self.snapshot())
        response=0
        if kind=='guard_enter':
            self.guard_depth+=1
        elif kind=='guard_leave':
            self.guard_depth-=1
            if self.guard_depth<0:raise OracleError('Unmatched DVCI guard leave')
        elif kind=='srd_create':
            response=self.plan.create
        elif kind=='srd_prepare_disc':
            if self.regs[4]&MASK32 != SRD:raise OracleError('Unknown scripted request identity')
            response=self.plan.prepare
            mode=self.regs[8]&MASK32
            event['mode_bytes_u8']=[self.mem.load(mode+i,1) for i in range(4)]
        elif kind in ('srd_status','srd_wait','srd_destroy'):
            if self.regs[4]&MASK32 != SRD:raise OracleError('Unknown scripted request identity')
            if kind=='srd_status':response=self.plan.srd_state
            elif kind=='srd_wait':response=self.plan.wait_return
        # Every stub explicitly returns v0, preserves other GPRs/memory, and
        # invokes no reentrant callback. These are fixture assumptions, not
        # claims about real devices/guard functions or their full clobber ABI.
        self.regs[2]=sext32(response)
        event['scripted_return_u64']=self.regs[2]
        event['guard_depth_after']=self.guard_depth
        event['observed_after']=self.snapshot()
        self.events.append(event)
        self.pc=self.regs[31]&MASK32
        return True

    def fetch(self,pc):
        if pc % 4:raise OracleError('Unaligned instruction fetch')
        for (start,end),raw in self.code.items():
            if start<=pc<end:
                return struct.unpack_from('<I',raw,pc-start)[0]
        raise OracleError(f'Instruction fetch outside admitted DVCI bodies: {pc:#x}')

    def run(self,operation,args,step_cap=2000):
        if operation not in ENTRIES:raise OracleError('Unknown DVCI operation')
        if len(args)>4 or step_cap<=0:raise OracleError('Invalid isolated call')
        if args and args[0]&MASK32 not in (0,HANDLE):
            raise OracleError('Unknown DVCI handle identity/alias')
        if bytes(self.mem.load(TABLE+i,1) for i in range(TABLE_BYTES))!=self.original_table:
            raise OracleError('Owned DVCI dispatch table was modified')
        state=self.mem.load(HANDLE+2,1)
        if state not in (0,1,2,3):raise OracleError('Unknown DVCI handle state')
        if self.mem.load(SYNC_MODE,4) not in (0,1,2):
            raise OracleError('Unknown DVCI sync-mode fixture domain')
        self.plan.validate()
        request=self.mem.load(HANDLE+28,4)
        if request not in (0,SRD):raise OracleError('Unknown opaque SRD identity')
        self.regs=[0]*32
        self.regs[2]=0xBAD0BAD0
        self.regs[29]=STACK_TOP
        self.regs[31]=RETURN
        for i,arg in enumerate(args):self.regs[4+i]=sext32(arg)
        self.events=[]
        self.last_transfer_pc=None
        entry,_,defined=ENTRIES[operation]
        self.pc=entry
        pending=None
        call_pcs=set()
        steps=0
        while self.pc!=RETURN:
            if steps>=step_cap:raise StepLimit('DVCI isolated instruction limit exceeded')
            steps+=1
            if pending is None and self.hook(self.pc):continue
            pc=self.pc
            word=self.fetch(pc)
            call_pcs.add(pc)
            branch=self.instruction(pc,word)
            if pending is not None:
                if branch is not None:raise OracleError('Control transfer in delay slot')
                self.pc,self.last_transfer_pc=pending
                pending=None
            elif branch is not None:
                taken,target,likely=branch
                if not taken and likely:self.pc=pc+8
                else:
                    pending=(target if taken else pc+8,pc)
                    self.pc=pc+4
            else:self.pc=pc+4
        if self.guard_depth:raise OracleError('Unbalanced isolated DVCI guard')
        self.visited.update(call_pcs)
        return dict(entry_pc=entry,arguments_i32=[signed(x,32) for x in args],
                    return_is_defined=defined,return_u32=self.regs[2]&MASK32 if defined else None,
                    return_raw_u64_observation_only=self.regs[2],steps=steps,
                    visited_pcs=sorted(call_pcs),events=self.events,state=self.snapshot())


class Scenario:
    def __init__(self,name,plan=HookPlan(),writes=(),elf_path=ROOT/'game_data/SLUS_207.65'):
        self.name=name
        self.machine=Machine(elf_path,plan)
        self.operations=[]
        self.initial_writes=[]
        self.write(writes,self.initial_writes)
        self.initial_state=self.machine.snapshot()

    def write(self,writes,output):
        for address,size,value in writes:
            self.machine.mem.store(address,size,value)
            output.append(dict(address=address,bytes=size,value_u64=value&((1<<(size*8))-1)))

    def call(self,operation,args,writes=()):
        edits=[]
        self.write(writes,edits)
        result=self.machine.run(operation,args)
        self.operations.append(dict(operation=operation,pre_writes=edits,expected=result))
        return result

    def fixture(self):
        return dict(name=self.name,hook_plan=asdict(self.machine.plan),initial_writes=self.initial_writes,
                    initial_state=self.initial_state,operations=self.operations)


def generate(elf_path=ROOT/'game_data/SLUS_207.65'):
    cases=[]
    def case(name,**kwargs):
        s=Scenario(name,elf_path=elf_path,**kwargs)
        cases.append(s)
        return s
    for origin,offset,cursor in [(0,7,3),(0,-7,3),(0,99,3),(1,4,3),(1,-9,3),
                                  (2,-3,3),(2,5,3),(7,123,9),(7,123,-1),
                                  (1,1,0x7FFFFFFF),(2,0x7FFFFFFF,3)]:
        s=case(f'seek_origin{origin}_offset{offset}_cursor{cursor}',
               writes=[(HANDLE+12,4,cursor)])
        s.call('seek',[HANDLE,offset,origin])
        s.call('tell',[HANDLE])
        s.call('transferred',[HANDLE])
    for operation,args in [('seek',[0,5,0]),('tell',[0]),('status',[0]),('transferred',[0]),
                           ('request',[0,1,BUFFER]),('request',[HANDLE,-1,BUFFER]),
                           ('request',[HANDLE,0,0]),('request',[HANDLE,1,0])]:
        s=case('null_or_invalid_'+operation+'_'+'_'.join(str(x) for x in args))
        s.call(operation,args)
    s=case('busy_ignores_positive_and_zero',writes=[(HANDLE+2,1,2)])
    s.call('request',[HANDLE,5,BUFFER]);s.call('request',[HANDLE,0,BUFFER])
    s=case('zero_request_retains_completed',writes=[(HANDLE+2,1,3)])
    s.call('request',[HANDLE,0,BUFFER]);s.call('transferred',[HANDLE])
    for mode in (0,1,2):
        for requested,cursor in ((4,3),(8,18),(1,20),(0x100000,3)):
            s=case(f'request_mode{mode}_count{requested}_cursor{cursor}',
                   plan=HookPlan(sync_mode=mode),writes=[(HANDLE+12,4,cursor)])
            s.call('request',[HANDLE,requested,BUFFER])
            s.call('tell',[HANDLE]);s.call('status',[HANDLE]);s.call('transferred',[HANDLE])
            if mode!=1:
                s.call('update',[HANDLE])
                s.call('tell',[HANDLE]);s.call('status',[HANDLE]);s.call('transferred',[HANDLE])
    s=case('srd_creation_declined',plan=HookPlan(create=0),writes=[(HANDLE+28,4,SRD)])
    s.call('request',[HANDLE,4,BUFFER])
    s=case('srd_preparation_declined',plan=HookPlan(prepare=0))
    s.call('request',[HANDLE,4,BUFFER])
    s=case('sync_wait_return_not_consumed',plan=HookPlan(sync_mode=1,wait_return=-1))
    s.call('request',[HANDLE,8,BUFFER]);s.call('transferred',[HANDLE])
    for state in range(10):
        s=case(f'update_scripted_srd_state{state}',plan=HookPlan(srd_state=state),
               writes=[(HANDLE+2,1,2),(HANDLE+28,4,SRD)])
        s.call('update',[HANDLE])
        s.call('tell',[HANDLE]);s.call('status',[HANDLE]);s.call('transferred',[HANDLE])
    s=case('update_without_request')
    s.call('update',[HANDLE])
    for state in range(4):
        s=case(f'query_state{state}',writes=[(HANDLE+2,1,state),(HANDLE+20,4,0x100001)])
        s.call('status',[HANDLE]);s.call('transferred',[HANDLE])
    fixture_cases=[s.fixture() for s in cases]
    m=cases[0].machine
    return dict(schema=1,kind='offline original-word DVCI scalar fixtures',
                identity=dict(elf_sha256=ELF_SHA,
                    integer_engine_sha256=hashlib.sha256(Path(__file__).with_name('sjuni_oracle.py').read_bytes()).hexdigest(),
                    generator_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
                    bodies=[dict(operation=name,start_pc=start,end_pc_exclusive=end,
                                 sha256=hashlib.sha256(m.code[start,end]).hexdigest())
                            for name,(start,end,_) in ENTRIES.items()],
                    dispatch_table=dict(start_pc=TABLE,bytes=TABLE_BYTES,
                        sha256=hashlib.sha256(m.elf.read(TABLE,TABLE_BYTES)).hexdigest())),
                assumptions=['Scripted external return values preserve other registers and memory.',
                    'No real IO, cache/device work, scheduler, error callback or reentry is modeled.',
                    'Only DVCI states0..3 and SRD table states0..9 are admitted.',
                    'Void update raw v0 is observed but is not a result contract.'],
                counts=dict(cases=len(cases),operations=sum(len(s.operations) for s in cases),
                    unique_instruction_pcs=len(set.union(*(s.machine.visited for s in cases)))),
                cases=fixture_cases)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    parser.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/dvci-oracle-fixtures.json')
    args=parser.parse_args()
    result=generate(args.elf)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['counts']))
    print('Synthetic fixtures: '+str(args.output))


if __name__=='__main__':main()
