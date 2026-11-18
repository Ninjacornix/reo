#!/usr/bin/env python3
"""Bounded complete owned-word keyed mono ADX kernel fixtures, no game I/O.

No native decoder implementation is imported. Code and read-only nibble table
come from the hash-checked owned ELF; all media bytes/state are authored synthetic
inputs. The unchanged integer engine is composed with the tested EE MAC subset.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

from ee_mac_oracle import EeMacInstructions,implementation_identity
from sjuni_oracle import Elf,Memory,OracleError,StepLimit,MASK32,sext32,signed

ROOT=Path(__file__).resolve().parents[2]
ENTRY,END=0x1276D8,0x1278B4
TABLE,TABLE_BYTES=0x239BE8,64
INPUT,OUTPUT,HISTORY,KEY=0x400000,0x410008,0x420000,0x430000
STACK,STACK_BYTES,STACK_TOP=0x700000,0x2000,0x701000
RETURN=0xFFFFF0
MAX_BLOCKS=16


class ObservedMemory(Memory):
    """Finite named spans with read-only source/table and bounded output writes."""
    def __init__(self):
        super().__init__();self.reads={};self.writes={};self.pcm_stores=[];self.active=False
        self.allowed=[]

    def allow(self,name,base,size,write=False):
        if size:self.allowed.append((name,base,size,write))

    def observe(self,address,size,write):
        if not self.active:return
        for name,base,length,writable in self.allowed:
            if base<=address and address+size<=base+length:
                if write and not writable:raise OracleError('Write to read-only '+name)
                counter=self.writes if write else self.reads
                row=counter.setdefault(name,dict(accesses=0,bytes=0,first_offset=address-base,last_end=address+size-base))
                row['accesses']+=1;row['bytes']+=size
                row['first_offset']=min(row['first_offset'],address-base)
                row['last_end']=max(row['last_end'],address+size-base)
                return name
        raise OracleError(f'Access outside admitted kernel spans: {address:#x}+{size}')

    def load(self,address,size):
        self.observe(address,size,False);return super().load(address,size)

    def store(self,address,size,value):
        name=self.observe(address,size,True)
        if self.active and name=='pcm':self.pcm_stores.append(dict(offset=address-OUTPUT,bytes=size,value=value&((1<<(size*8))-1)))
        super().store(address,size,value)


class Machine(EeMacInstructions):
    def __init__(self,encoded,requested,*,history,coefficients,key,multiplier,addend,
                 output_samples=None,elf_path=ROOT/'game_data/SLUS_207.65',mac_initial=(0,0,0,0)):
        # All constructor admission happens before original instructions execute.
        if not isinstance(encoded,bytes) or len(encoded)>MAX_BLOCKS*18:
            raise OracleError('Synthetic encoded span must be bounded bytes')
        if not isinstance(requested,int) or not -0x80000000<=requested<=MAX_BLOCKS:
            raise OracleError('Admitted requested count is signed32 and at most16')
        if len(history)!=2 or len(coefficients)!=2 or any(not -32768<=v<=32767 for v in (*history,*coefficients,multiplier,addend)):
            raise OracleError('History/coefficient/key step inputs must be signed16')
        if not 0<=key<=65535:raise OracleError('Initial key must be uint16')
        if output_samples is None:output_samples=max(requested,0)*32
        if not isinstance(output_samples,int) or not 0<=output_samples<=MAX_BLOCKS*32:
            raise OracleError('Output capacity outside finite domain')
        if len(mac_initial)!=4:raise OracleError('All MAC banks require explicit initialization')
        self.elf=Elf(elf_path);self.code=self.elf.read(ENTRY,END-ENTRY)
        self.table=self.elf.read(TABLE,TABLE_BYTES)
        if self.code is None or self.table is None:raise OracleError('Owned text/table unavailable')
        self.initialize_mac(hi=mac_initial[0],lo=mac_initial[1],hi1=mac_initial[2],lo1=mac_initial[3])
        self.mem=ObservedMemory();self.output_samples=output_samples
        if encoded:
            self.mem.map(INPUT,len(encoded));self.mem.store(INPUT,len(encoded),int.from_bytes(encoded,'little'))
        self.mem.map(OUTPUT-8,output_samples*2+16,0xA5)
        self.mem.map(HISTORY,4);self.mem.map(KEY,2);self.mem.map(TABLE,TABLE_BYTES)
        self.mem.map(STACK,STACK_BYTES,0xCC)
        self.mem.store(HISTORY,2,history[0]);self.mem.store(HISTORY+2,2,history[1]);self.mem.store(KEY,2,key)
        self.mem.store(TABLE,TABLE_BYTES,int.from_bytes(self.table,'little'));self.mem.store(STACK_TOP,2,addend)
        self.mem.allow('encoded',INPUT,len(encoded));self.mem.allow('pcm',OUTPUT,output_samples*2,True)
        self.mem.allow('history',HISTORY,4,True);self.mem.allow('key',KEY,2,True)
        self.mem.allow('owned_nibble_table',TABLE,TABLE_BYTES);self.mem.allow('stack',STACK,STACK_BYTES,True)
        self.regs=[0]*32
        # Explicit nonzero callee-saved sentinels; ordinary unused registers zero.
        for reg in (*range(16,24),30):self.regs[reg]=0x1234000000000000+reg
        self.saved={reg:self.regs[reg] for reg in (*range(16,24),30)}
        args=[INPUT,requested,OUTPUT,HISTORY,*coefficients,KEY,multiplier]
        for i,arg in enumerate(args):self.regs[4+i]=sext32(arg)
        self.regs[29]=STACK_TOP;self.regs[31]=RETURN
        self.case_input=dict(encoded_hex=encoded.hex(),requested_i32=requested,
            history_i16=list(history),coefficients_i16=list(coefficients),key_u16=key,
            multiplier_i16=multiplier,addend_i16=addend,output_capacity_samples=output_samples,
            mac_initial_u64=list(mac_initial))
        self.pc=ENTRY;self.visited=set();self.instruction_counts={}

    def snapshot(self):
        active=self.mem.active;self.mem.active=False
        try:
            pcm=bytes(self.mem.load(OUTPUT+i,1) for i in range(self.output_samples*2))
            return dict(pcm_i16=list(struct.unpack('<'+'h'*self.output_samples,pcm)),
                pcm_sha256=hashlib.sha256(pcm).hexdigest(),history_i16=[signed(self.mem.load(HISTORY+i*2,2),16) for i in range(2)],
                key_u16=self.mem.load(KEY,2),
                output_guard_hex=bytes(self.mem.load(OUTPUT-8+i,1) for i in range(8)).hex()+bytes(self.mem.load(OUTPUT+self.output_samples*2+i,1) for i in range(8)).hex(),
                encoded_sha256=hashlib.sha256(bytes(self.mem.load(INPUT+i,1) for i in range(len(bytes.fromhex(self.case_input['encoded_hex']))))).hexdigest())
        finally:self.mem.active=active

    def run(self,step_cap=30000):
        if not isinstance(step_cap,int) or step_cap<=0:raise OracleError('Invalid finite step limit')
        pending=None;steps=0;self.mem.active=True
        try:
            while self.pc!=RETURN:
                if steps>=step_cap:raise StepLimit('Owned mono kernel instruction cap')
                if not ENTRY<=self.pc<END or self.pc%4:raise OracleError('Kernel transfer outside complete owned body')
                steps+=1;pc=self.pc;word=struct.unpack_from('<I',self.code,pc-ENTRY)[0]
                self.visited.add(pc);self.instruction_counts[pc]=self.instruction_counts.get(pc,0)+1
                branch=self.instruction(pc,word)
                if pending is not None:
                    if branch is not None:raise OracleError('Control transfer in kernel delay slot')
                    self.pc=pending;pending=None
                elif branch is not None:
                    taken,target,likely=branch
                    if not taken and likely:self.pc=pc+8
                    else:pending=target if taken else pc+8;self.pc=pc+4
                else:self.pc=pc+4
        finally:self.mem.active=False
        defined_return=signed(self.regs[2],32)
        return dict(return_i32=defined_return,steps=steps,visited_pcs=sorted(self.visited),
            pcm_store_count=len(self.mem.pcm_stores),pcm_stores=self.mem.pcm_stores,
            reads=self.mem.reads,writes=self.mem.writes,mac_instruction_counts=self.mac_counts,
            state=self.snapshot(),abi=dict(stack_restored=self.regs[29]==STACK_TOP,
                saved_registers_restored=all(self.regs[r]==v for r,v in self.saved.items())),
            observations_not_abi=dict(input_cursor_u32=self.regs[13]&MASK32,output_cursor_u32=self.regs[6]&MASK32,
                processed_index_u32=self.regs[10]&MASK32,mac_final_u64=self.mac_state()),
            instruction_counts={f'{pc:08X}':n for pc,n in sorted(self.instruction_counts.items())})


def block(header,payload):
    """Construct synthetic ADX bytes; never load a copyrighted media asset."""
    if not 0<=header<=65535 or len(payload)!=16:raise ValueError('Synthetic block geometry')
    return header.to_bytes(2,'big')+bytes(payload)


def generate(elf_path=ROOT/'game_data/SLUS_207.65'):
    cases=[]
    def add(name,encoded,count,**kwargs):
        params=dict(history=(0,0),coefficients=(0,0),key=0,multiplier=1,addend=0)
        params.update(kwargs);m=Machine(encoded,count,elf_path=elf_path,**params)
        cases.append(dict(name=name,input=m.case_input,expected=m.run()))
    # Each signed nibble in both positions, then all256 high/low combinations.
    for nibble in range(16):add(f'nibble_{nibble:02X}',block(0,bytes([nibble<<4|nibble])*16),1)
    for high in range(16):add(f'nibble_pairs_{high:02X}',block(0,bytes(high<<4|low for low in range(16))),1)
    for header in (0,1,0x1FFE,0x1FFF,0x2000,0x3FFF,0x7FFF):
        for key in (0,1,0x1FFF,0x7FFF,0xFFFF):
            add(f'scale_{header:04X}_key_{key:04X}',block(header,bytes(range(0,256,16))),1,
                key=key,multiplier=-32768,addend=32767)
    for history in ((32767,32767),(-32768,-32768),(32767,-32768),(-32768,32767),(12345,-23456)):
        for coefficients in ((32767,32767),(-32768,-32768),(8192,-4096),(4096,0),(0,4096)):
            add(f'predictor_h{history}_c{coefficients}',block(0x1FFF,bytes(range(16))),1,
                history=history,coefficients=coefficients,key=32767,multiplier=-1,addend=-32768)
    for count in (0,-1,-2147483648):add(f'nonpositive_{count}',b'',count,history=(-32768,32767),key=65535)
    for count in (1,2,3,8,16):
        encoded=b''.join(block((i*127)&0x7FFF,bytes((j*37+i*19)&255 for j in range(16))) for i in range(count))
        add(f'multiple_{count}',encoded,count,history=(23456,-12345),coefficients=(7192,-3172),key=32766,multiplier=-32767,addend=12345)
    for completed in (0,1,2):
        encoded=b''.join(block(i,bytes([0x7F,0x80]*8)) for i in range(completed))+b'\x80\x00'
        add(f'marker_after_{completed}',encoded,completed+1,history=(1234,-5678),coefficients=(4096,0),key=23456,multiplier=7,addend=-9)
    # The kernel does not consume previous MAC state; all four banks explicit.
    add('nonzero_initial_mac',block(12,bytes(range(16))),1,history=(32767,-32768),coefficients=(-32768,32767),
        mac_initial=(0x123456789ABCDEF0,0xFEDCBA9876543210,0x9999999999999999,0x7777777777777777))
    ref=Machine(b'',0,history=(0,0),coefficients=(0,0),key=0,multiplier=1,addend=0,elf_path=elf_path)
    hashes={name:hashlib.sha256(Path(__file__).with_name(name).read_bytes()).hexdigest()
            for name in ('sjuni_oracle.py','ee_mac_oracle.py','adx_decode_oracle.py')}
    return dict(schema=1,kind='owned-word keyed mono ADX scalar decode fixtures',
        identity=dict(elf_sha256=ref.elf.sha256,entry_pc=ENTRY,end_pc_exclusive=END,
            body_sha256=hashlib.sha256(ref.code).hexdigest(),nibble_table_address=TABLE,
            nibble_table_bytes=TABLE_BYTES,nibble_table_sha256=hashlib.sha256(ref.table).hexdigest(),tool_sha256=hashes,
            local_isa_reference=implementation_identity()),
        limitations=['No external calls, IO, scheduler, COP1, VU, MMI packed lanes or device state.',
            'Disjoint ordinary aligned synthetic encoded/output/history/key/stack spans only.',
            'Requested count signed32 <=16; nonpositive count admits no encoded/output accesses.',
            'MAC banks explicitly initialized; no architectural cycle/interlock timing is modeled.',
            'Original instructions determine outputs; cursor/MAC observations are not public ABI.'],
        counts=dict(cases=len(cases),runner_steps=sum(c['expected']['steps'] for c in cases),
            pcm_samples_written=sum(c['expected']['pcm_store_count'] for c in cases),
            visited_pcs=len(set().union(*(set(c['expected']['visited_pcs']) for c in cases)))),cases=cases)


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--elf',type=Path,default=ROOT/'game_data/SLUS_207.65')
    p.add_argument('--output',type=Path,default=ROOT/'build-native-sjuni/adx-decode-fixtures.json')
    args=p.parse_args();result=generate(args.elf);args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8');print(json.dumps(result['counts']))


if __name__=='__main__':main()
