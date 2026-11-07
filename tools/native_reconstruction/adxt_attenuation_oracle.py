#!/usr/bin/env python3
"""Owned ADXT attenuation setter/metadata getter and actual type-5 producer.

Freeze inputs before replay. No native attenuation implementation is imported;
only the null-handle diagnostic is an explicit observational host port. No
process, runtime, real audio device, DMA/RPC receiver or game is executed.
"""
import argparse,hashlib,json,re,struct
from pathlib import Path
import adx_window_oracle as window
from sjuni_oracle import Elf,OracleError,MASK32,signed
ROOT=Path(__file__).resolve().parents[2]
RANGES={0x1327b8:0x132850,0x12d8f8:0x12d950,0x124f48:0x124f50,0x124f50:0x124f58,
        0x12c7f8:0x12c810,0x13f038:0x13f054,0x13e000:0x13e2b8}
TABLE,TABLE_BYTES=0x220498,4000
MAIN,OUTER,INNER,COMMANDS,RNAS=0x500000,0x510000,0x520000,0x530000,0x223880
sha=lambda data:hashlib.sha256(data).hexdigest()
encoded=lambda value:(json.dumps(value,sort_keys=True,indent=2)+'\n').encode()
ENGINES=('adx_window_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py','sjuni_oracle.py')

def authority():
    elf=Elf(ROOT/'game_data/SLUS_207.65');rows=[]
    for start,end in RANGES.items():
        path=ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp';raw=path.read_bytes()
        comments={int(a,16):int(b,16)for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw)};zeros=[]
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if comments[pc]!=word:raise OracleError('Owned comment disagrees '+hex(pc))
            elif word:raise OracleError('Missing nonzero source word '+hex(pc))
            else:zeros.append(pc)
        rows.append(dict(start=start,end=end,sha256=sha(elf.read(start,end-start)),source=path.relative_to(ROOT).as_posix(),source_sha256=sha(raw),omitted_zeros=zeros))
    return dict(elf_sha256=elf.sha256,ranges=rows,table_sha256=sha(elf.read(TABLE,TABLE_BYTES)),engines={name:sha(Path(__file__).with_name(name).read_bytes())for name in ENGINES})

def inputs():
    cases=[]
    def add(name,request,**kw):
        c=dict(name=name,request=request&MASK32,presence=1,metadata=0,phase=2,slot=0,null=False);c.update(kw);cases.append(c)
    for index in range(1000):add('table-'+str(index),-index,slot=index%16)
    values=(0,1,-1,-998,-999,-1000,-32768,32767,32768,65535,65536,0x7fffffff,0x80000000,0xffffffff)
    for request in values:
        for phase in (0,1,2,3,4,5,127,128,255):
            for metadata in (0,1,-1,-999,-32768,32767):add(f'combined-{request}-{phase}-{metadata}',request,phase=phase,metadata=metadata&0xffff)
    for presence in (0,1,0x7fffffff,0x80000000,0xffffffff):
        for phase in (1,2,3,4):
            for metadata in (-32768,-1,0,1,32767):add(f'presence-{presence}-{phase}-{metadata}',-123,presence=presence,phase=phase,metadata=metadata&0xffff)
    for request in values:add('null-'+str(request),request,null=True)
    return dict(schema=1,scope='ADXT signed-halfword attenuation, ready AINF gating, RNA clamp and unchanged original type-5 table producer',
        provenance='Inputs authored and frozen before native attenuation implementation; supplied metadata/initial state are inputs, not answers.',cases=cases)

class Machine(window.Machine):
    def __init__(self,case,elf,code):
        self.case=case;self.elf=elf;self.code=code;self.mem=window.ObservedMemory()
        for address,size,fill in [(MAIN-16,0xc4+32,0x5a),(OUTER,0x9c,0),(INNER,0xe4,0),
            (COMMANDS-16,96,0xa5),(RNAS,16*0x60,0),(TABLE,TABLE_BYTES,0),(window.STACK,0x2000,0xcc)]:self.mem.map(address,size,fill)
        self.mem.store(TABLE,TABLE_BYTES,int.from_bytes(elf.read(TABLE,TABLE_BYTES),'little'))
        self.rna=RNAS+case['slot']*0x60
        for offset,value in {4:OUTER,12:self.rna}.items():self.mem.store(MAIN+offset,4,value)
        self.mem.store(MAIN+0x40,2,0x1357);self.mem.store(OUTER+4,4,INNER);self.mem.store(OUTER+1,1,case['phase'])
        self.mem.store(INNER+0xc8,4,case['presence']);self.mem.store(INNER+0xdc,2,case['metadata'])
        self.mem.store(self.rna,1,1);self.mem.store(self.rna+0x20,4,0x1e0000+case['slot']*0x20)
        self.mem.store(self.rna+0x26,1,2);self.mem.store(self.rna+0x27,1,2)
        self.mem.store(self.rna+0x28,4,48000);self.mem.store(self.rna+0x2c,4,48000)
        self.mem.store(self.rna+0x30,4,-123);self.mem.store(self.rna+0x34,4,1)
        self.regs=[0]*32;self.guard_depth=0;self.all_visited=set();self.total_steps=0
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)
    def small(self):
        return dict(stored_i16=signed(self.mem.load(MAIN+0x40,2),16),rna_i32=signed(self.mem.load(self.rna+0x30,4),32),last_i32=signed(self.mem.load(self.rna+0x34,4),32),command_guard_hex=self.raw(COMMANDS-16,96).hex())
    def snapshot(self):return self.small()
    def hook(self,pc):
        if pc!=0x1280d0:return False
        self.events.append(dict(kind='null-diagnostic',pc=pc,format=self.regs[4]&MASK32));self.pc=self.regs[31]&MASK32;return True

def execute(case,elf,code):
    m=Machine(case,elf,code);calls=[]
    for entry,args in [(0x1327b8,[0 if case['null']else MAIN,case['request']]),(0x132820,[0 if case['null']else MAIN])]:
        result=m.run(entry,args,full=False)
        if result['status']!='returned':raise OracleError(str(result['failure']))
        calls.append(dict(entry=entry,instructions=result['original_instructions'],v0_lower64=result['raw_v0_lower64_observation_only'],events=result['events'],writes=result['writes']))
    get_result=signed(m.regs[2],32)
    if not case['null']:
        result=m.run(0x13e000,[0,COMMANDS],full=False)
        if result['status']!='returned':raise OracleError(str(result['failure']))
        calls.append(dict(entry=0x13e000,instructions=result['original_instructions'],writes=result['writes']))
        if m.mem.load(COMMANDS,4)!=1 or m.mem.load(COMMANDS+16,2)!=5:raise OracleError('Prepared profile did not emit exactly one original type-5 command')
    return dict(name=case['name'],projection=m.small()|dict(get_i32=get_result,volume_u32=m.mem.load(COMMANDS+28,4)if not case['null']else None),calls=calls,instructions=m.total_steps,visited=sorted(m.all_visited))

def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--replay',action='store_true');a=p.parse_args();out=a.output.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni/adxt-attenuation'):raise OracleError('Owned output required')
    if not a.replay:
        if out.exists():raise OracleError('Fresh output required')
        out.mkdir(parents=True);(out/'inputs.json').write_bytes(encoded(inputs()))
        plan=dict(schema=1,inputs_sha256=sha((out/'inputs.json').read_bytes()),oracle_sha256=sha(Path(__file__).read_bytes()),authority=authority(),native_core_authored=False)
        (out/'input-manifest.json').write_bytes(encoded(plan));print('Attenuation inputs frozen; no original execution');return
    plan=json.loads((out/'input-manifest.json').read_bytes())
    if plan['authority']!=authority() or plan['oracle_sha256']!=sha(Path(__file__).read_bytes()) or plan['inputs_sha256']!=sha((out/'inputs.json').read_bytes()):raise OracleError('Frozen input/source drift')
    if (out/'expected.json').exists():raise OracleError('Preserve original observations')
    elf=Elf(ROOT/'game_data/SLUS_207.65');code={}
    for start,end in RANGES.items():code.update({pc:int.from_bytes(elf.read(pc,4),'little')for pc in range(start,end,4)})
    rows=[execute(c,elf,code)for c in json.loads((out/'inputs.json').read_bytes())['cases']]
    (out/'expected.json').write_bytes(encoded(rows))
    receipt=dict(schema=1,status='owned attenuation/setter/getter/type5 producer replay completed',cases=len(rows),instructions=sum(r['instructions']for r in rows),input_manifest_sha256=sha((out/'input-manifest.json').read_bytes()),expected_sha256=sha((out/'expected.json').read_bytes()),native_core_authored=False,device_opened=False,game_run=False)
    (out/'receipt.json').write_bytes(encoded(receipt));print(json.dumps(receipt))
if __name__=='__main__':main()
