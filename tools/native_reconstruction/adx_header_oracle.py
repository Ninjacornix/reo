#!/usr/bin/env python3
"""Owned ADX integer header proof and honest partial tag0 COP1 boundary."""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

from adx_window_oracle import Machine as BoundedRunner, WindowInstructions, ObservedMemory
from sjrb_oracle import BODIES as RING_BODIES
from sjuni_oracle import Elf, OracleError, MASK32, sext32
from ee_mac_oracle import implementation_identity

ROOT=Path(__file__).resolve().parents[2]
BODIES={**RING_BODIES,
    0x124518:(0x124534,'32d8fb3895c2b8e2caf3463db2f17bf98637d4bb3b125220a4abcd69be661371'),
    0x124558:(0x12470C,'cb368ce8bd0f1525258c3d693be6bf49d5470791f3d2820c09a93149aed20a85'),
    0x1249E8:(0x124CD4,'abd26f34e1ee76095d22edc9b9343598ad81058013d7d2761d6e1a897250b982'),
    0x124CD8:(0x124E3C,'2a4735a8f0b3f84fc4ab932eb34e63c8dcaadcda802c3c584faa19f8970aab51'),
    0x124E68:(0x124E70,'e03365e004f73f9f7bea8f19ff856fceb2fc4551bbd9b52c1390b943564d8f62'),
    0x1250A0:(0x1251A0,'93d6e6b4fdf4f448d3b2c89c7cfdcf39f731a34f603fd8fd9bef66761976dc3a'),
    0x126510:(0x12666C,'9071bc1f23b6d55e342c906cd9df971f1c8fb1faf4c3b776b61cb0acfe9cd832'),
    0x126798:(0x126898,'fb330e34e841e89d11a3c265bac214d17a83bc040969942583481fd86e1ffbf1'),
    0x126898:(0x126918,'bc43d5ce33136d54731f9460bb8c85d157db0d5d573b5b61af1b9bd6b0a58080'),
    0x126918:(0x126990,'3f6c654ede6ff11d9be1cbc543cb5bee25f2e68a965a530e8da966f9c6837082'),
    0x126990:(0x126AC4,'d20a167acaca26293487ca6e8b278541aaf4948eecb0247672be5b9bed98a09b'),
    0x126AC8:(0x126D28,'40eea16d440aab4800913fb52335ca614ae5ec4318bd1055245b2944b1139a77'),
    0x126D28:(0x126F1C,'e4ad9b0bf9e65afbf4f5e6a847717f656c6aef28e7be31b3c864b02eb9f13016'),
    0x12CCE0:(0x12CEB8,'3027230bd9bdc3f8478350ce97813f064a4c36da9006bcea571457c9f34cea7d'),
    0x12D638:(0x12D678,'166986473a6bc25e0204900fe64bdc7e99ef36eb86ad9c4e4c570bc2cc49aaa0'),
    0x134EB0:(0x134ED4,'8cbc9ebaa48c7a1c0b466706a145ed4dbde8a696e9aab8b9c344c1dd909b0a14'),
    0x134ED8:(0x134EFC,'b943178b702b24292d72724f90e1ccfc8937d2a99ccdd952892d202bfca74fff'),
    0x134F28:(0x134F38,'0004aa877f1f2e3639f7ad2345b2d61bb68793e51511301e9c7fa1d16ffdd37f'),
    0x125C08:(0x125C30,'f9a2e9f1580a41e478bd83286717efa456111d97ba0163e70522767390f382ce'),
    0x126410:(0x126474,'a4c95ac70819d953ac7257116f05c60692769e77b7a747dfd8e7e619176ccc26'),
    0x123470:(0x1234D4,'10129d01f9154d2692b90c69fa627bf06932a7a31bf077c0a80a7f1e20193789'),
    0x123D58:(0x123DB0,'fce9782d96ee79aee1884eb00ca841c3312548c0cfe222a772ecd3560f0f3e4d'),
    0x122FA0:(0x122FF0,'fb49a445af76993b81ec1f465b6155919bf9c372b226ca7e57b9a773636767f6')}
GLOBAL,POOL,INPUT,DIRECT,SCRATCH=0x224C20,0x224C60,0x400010,0x420010,0x630004
OUTER,INNER,PRED,OUTPUT,STACK,SP=0x600000,0x610000,0x620000,0x640000,0x700000,0x701000
ENTER,LEAVE,MEMSET,MEMCPY,MEMCMP,REPORT,ERROR,DIAG,FORMAT=0x13F258,0x13F270,0x107C68,0x107AB0,0x107A18,0x13F288,0xFFFF00,0x128128,0x10A830
TABLE_START,TABLE_BYTES,KEY_GLOBAL=0x239300,0x900,0x20B93C
CAPACITY,EXTENSION=2048,36
TRACE={0x1249E8:'adx_header',0x124CD8:'format_selector',0x1250A0:'key_select',0x124558:'derive_key',
    0x126798:'base',0x126898:'filter',0x126918:'version',0x126990:'history',0x126AC8:'loop',0x126D28:'ainf',
    0x134EB0:'configure_coefficients',0x126510:'coefficient_math',0x134ED8:'install_history',0x134F28:'install_key',
    0x12CCE0:'outer_header'}

def sha(data):return hashlib.sha256(data).hexdigest()
def serialized(value):return (json.dumps(value,sort_keys=True,indent=2)+'\n').encode()

class HeaderMemory(ObservedMemory):
    def store(self,address,size,value):
        if self.active and address<TABLE_START+TABLE_BYTES and TABLE_START<address+size:
            raise OracleError('Write into owned read-only header constants')
        return super().store(address,size,value)

class Machine(BoundedRunner):
    def __init__(self,inputs):
        self.inputs=inputs;self.elf=Elf(ROOT/'game_data/SLUS_207.65');self.code={}
        for start,(end,expected) in BODIES.items():
            data=self.elf.read(start,end-start)
            if data is None or sha(data)!=expected:raise OracleError('Owned body identity mismatch')
            self.code.update({start+i:struct.unpack_from('<I',data,i)[0] for i in range(0,len(data),4)})
        self.mem=HeaderMemory()
        for address,size,fill in [(GLOBAL,0x4040,0),(INPUT-16,CAPACITY+EXTENSION+32,0xA5),
            (DIRECT-16,544,0xA5),(OUTER,0x9C,0x7A),(INNER,0xE4,0x6D),(PRED,0x3C,0x4B),
            (OUTPUT,0x100,0x5A),(SCRATCH-4,0x100,0x5A),(STACK,0x2000,0xCC),
            (TABLE_START,TABLE_BYTES,0),(KEY_GLOBAL,0x1C,0)]:self.mem.map(address,size,fill)
        for address,size in [(GLOBAL+8,48),(TABLE_START,TABLE_BYTES)]:
            self.mem.store(address,size,int.from_bytes(self.elf.read(address,size),'little'))
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)
        self.regs=[0]*32;self.guard_depth=0;self.all_visited=set();self.total_steps=0;self.rings=[POOL];self.setup=[]
        self.buffers=[(INPUT,CAPACITY+EXTENSION)]

    def small(self):
        return dict(outer_hex=self.raw(OUTER,0x9C).hex(),inner_hex=self.raw(INNER,0xE4).hex(),
            predictor_hex=self.raw(PRED,0x3C).hex(),ring_u32=self.mem.words(POOL,16),
            helper_output_hex=self.raw(OUTPUT,0x100).hex(),key_global_hex=self.raw(KEY_GLOBAL,0x1C).hex())
    def snapshot(self):
        return dict(**self.small(),backing_guard_hex=self.raw(INPUT-16,CAPACITY+EXTENSION+32).hex(),
            direct_guard_hex=self.raw(DIRECT-16,544).hex(),stack_frame_hex=self.raw(SP-0x400,0x400).hex(),
            caller_guard_hex=self.raw(SP,32).hex(),lower_stack_guard_hex=self.raw(STACK,32).hex())
    def instruction(self,pc,word):
        if pc in TRACE:self.events.append(dict(kind='original_entry',name=TRACE[pc],pc=pc,from_pc=self.from_pc,
            arguments_u64=list(self.regs[4:12]),write_index=len(self.mem.writes)))
        return WindowInstructions.instruction(self,pc,word)
    def run(self,entry,arguments=(),**options):
        result=super().run(entry,arguments,**options)
        result['return_is_defined']=result['failure'] is None and entry in (0x13F8A8,0x1249E8,0x124CD8,
            0x126798,0x126898,0x126918,0x126990,0x126AC8,0x126D28,0x1250A0,0x124558)
        return result
    def hook(self,pc):
        if pc not in (ENTER,LEAVE,MEMSET,MEMCPY,MEMCMP,REPORT,ERROR,DIAG,FORMAT):return False
        event=dict(pc=pc,from_pc=self.from_pc,arguments_u64=list(self.regs[4:12]),depth_before=self.guard_depth,
            write_index_before=len(self.mem.writes))
        if pc==ENTER:event['kind']='enter';self.guard_depth+=1
        elif pc==LEAVE:
            event['kind']='leave';self.guard_depth-=1
            if self.guard_depth<0:raise OracleError('Unbalanced guard')
        elif pc==MEMSET:
            dest,value,size=(v&MASK32 for v in self.regs[4:7])
            if not POOL<=dest<=dest+size<=POOL+0x4000:raise OracleError('Unadmitted memset')
            event['kind']='bounded_memset';self.mem.fill(dest,size,value);self.regs[2]=self.regs[4]
        elif pc==MEMCPY:
            dest,source,size=(v&MASK32 for v in self.regs[4:7])
            if size>256 or (size and dest<source+size and source<dest+size):raise OracleError('Unadmitted/overlapping copy')
            data=self.raw(source,size);self.mem.region(dest,size)
            event['kind']='bounded_memcpy';event['source_hex']=data.hex()
            for i,value in enumerate(data):self.mem.store(dest+i,1,value)
            self.regs[2]=sext32(dest)
        elif pc==MEMCMP:
            left,right,size=(v&MASK32 for v in self.regs[4:7])
            if size>16:raise OracleError('Finite signature comparison bound')
            a,b=self.raw(left,size),self.raw(right,size);difference=next((x-y for x,y in zip(a,b) if x!=y),0)
            event.update(kind='bounded_memcmp',left_hex=a.hex(),right_hex=b.hex(),return_i32=difference);self.regs[2]=sext32(difference)
        elif pc==FORMAT:
            dest,fmt,value=(v&MASK32 for v in self.regs[4:7])
            if fmt!=0x239BB0 or self.raw(fmt,5)!=b'%08X\0' or not STACK<=dest<=dest+9<=SP:
                raise OracleError('Only bounded owned eight-digit uppercase formatter admitted')
            data=f'{value:08X}'.encode()+b'\0'
            event.update(kind='bounded_format_u32',output_hex=data.hex())
            for i,value in enumerate(data):self.mem.store(dest+i,1,value)
            self.regs[2]=8
        else:
            event['kind']='error_callback' if pc==ERROR else 'diagnostic'
            active=self.mem.active;self.mem.active=False;event['observed_before']=self.small();self.mem.active=active
        event.update(depth_after=self.guard_depth,write_index_after=len(self.mem.writes));self.events.append(event)
        self.pc=self.regs[31]&MASK32;return True
    def prepare(self):
        data=bytes.fromhex(self.inputs['header_hex'])
        if len(data)>512 or not 0<=self.inputs['position']<CAPACITY:raise OracleError('Bounded header input required')
        self.setup_call(0x13F7F8,[]);self.setup_call(0x13F8A8,[INPUT,CAPACITY,EXTENSION]);self.setup_call(0x13F9E0,[POOL,ERROR,0])
        self.advance_empty(POOL,self.inputs['position']);self.produce(POOL,data=data)
        for i,value in enumerate(data):self.mem.store(DIRECT+i,1,value)
        for offset,value in {4:INNER,8:POOL,0x98:0x5A5A5A5A}.items():self.mem.store(OUTER+offset,4,value)
        self.mem.store(OUTER,1,1);self.mem.store(OUTER+1,1,1);self.mem.store(OUTER+3,1,0)
        for offset,value in {8:PRED,0x38:2,0x3C:0x410010,0x40:8192,0x44:8288,0xB0:0}.items():self.mem.store(INNER+offset,4,value)
        self.mem.store(INNER,2,1);self.mem.store(INNER+4,4,0)
        for offset,values in [(0x9C,self.inputs['configured_key'])]:
            for i,value in enumerate(values):self.mem.store(INNER+offset+i*2,2,value)
        for i,value in enumerate(self.inputs['fallback_key']):self.mem.store(KEY_GLOBAL+0x10+i*2,2,value)

def header(*,version=3,control=0,encoding=3,channels=1,bits=4,block=18,rate=44100,total=1000,offset=0x5C,filter_value=500):
    data=bytearray(96);data[0:4]=b'\x80\x00'+offset.to_bytes(2,'big')
    data[4:8]=bytes([encoding,block,bits,channels]);data[8:12]=rate.to_bytes(4,'big');data[12:16]=total.to_bytes(4,'big')
    data[16:20]=filter_value.to_bytes(2,'big')+bytes([version,control])
    data[24:32]=bytes.fromhex('1234fedc5678ba98')
    return data

def corpus_inputs():
    rows=[]
    def add(name,kind='outer',data=None,**changes):
        row=dict(name=name,kind=kind,header_hex=bytes(header() if data is None else data).hex(),position=0,
            supplied_length=None,configured_key=[0,0,0],fallback_key=[23456,7,65527]);row.update(changes);rows.append(row)
    for length in (0,1,15,16,19):add(f'outer-short-{length}',data=header()[:length])
    add('outer-bad-magic',data=bytes(96))
    add('outer-reject-ahx-without-plugin',data=header(encoding=5))
    add('outer-declared-offset-too-small',data=header(offset=8))
    add('outer-declared-offset-signed-negative',data=header(offset=0x8000))
    add('outer-wrap-short-first-span',position=2030)
    add('outer-valid-mono-COP1-open');add('outer-valid-stereo-v4-COP1-open',data=header(channels=2,version=4))
    add('outer-fallback-key-COP1-open',data=header(version=4,control=8))
    add('outer-configured-key-COP1-open',data=header(version=4,control=8),configured_key=[0x8001,0xFFFF,0x1234])
    add('outer-derived-key-COP1-open',data=header(version=4,control=16,total=0xFEDCBA98))
    add('outer-zero-rate-COP1-open',data=header(rate=0))
    add('outer-zero-bits-COP1-open',data=header(bits=0))
    add('base-mono','base');add('base-stereo','base',data=header(channels=2))
    add('base-signed-bytes','base',data=header(channels=255,bits=255,block=255,rate=0xFFFFFFFF,total=0x80000001))
    add('base-zero-bits','base',data=header(bits=0));add('base-header-halfword-wrap','base',data=header(offset=0xFFFE))
    add('base-short','base',supplied_length=15);add('base-bad-magic','base',data=bytes(96))
    add('version-v4','version',data=header(version=4,control=8));add('version-short','version',supplied_length=19)
    add('filter-signed-halfword','filter',data=header(filter_value=0x8001));add('filter-short','filter',supplied_length=17)
    add('history-v3-clears','history');add('history-v4','history',data=header(version=4));add('history-v4-short','history',data=header(version=4),supplied_length=31)
    for version in (3,4):
        data=header(version=version);base=0x20 if version==4 else 0x14
        data[base:base+24]=bytes.fromhex('fffe00010000123400112233445566778899aabbccddeeff')
        add(f'loop-v{version}','loop',data=data)
        data=header(version=version);data[base+4:base+8]=b'AINF';data[base+8:base+12]=bytes.fromhex('12345678')
        data[base+12:base+28]=bytes(range(16));data[base+28:base+36]=bytes.fromhex('fedc112233445566')
        add(f'ainf-v{version}','ainf',data=data)
    add('loop-absent-partial-clear','loop');add('ainf-absent-partial-clear','ainf')
    add('key-fallback-selection','key',data=header(version=4,control=8));add('key-derived-format-table','key',data=header(version=4,control=16,total=0xFEDCBA98))
    return dict(schema=1,provenance='Authored bounded synthetic ADX header inputs frozen BEFORE original replay. Successful tag0 coefficient path explicitly remains open.',cases=rows)

def execute_case(inputs):
    m=Machine(inputs);m.prepare();kind=inputs['kind'];length=inputs['supplied_length']
    if length is None:length=len(bytes.fromhex(inputs['header_hex']))
    if kind=='outer':entry,args=0x12D638,[OUTER]
    elif kind=='base':
        m.mem.store(SP,4,OUTPUT+32);m.mem.store(SP+8,4,OUTPUT+36)
        entry,args=0x126798,[DIRECT,length,OUTPUT,OUTPUT+4,OUTPUT+5,OUTPUT+6,OUTPUT+7,OUTPUT+16]
    elif kind in ('version','history'):
        entry,args=(0x126918 if kind=='version' else 0x126990),[DIRECT,length,OUTPUT,OUTPUT+4]
    elif kind=='filter':entry,args=0x126898,[DIRECT,length,OUTPUT]
    elif kind=='loop':
        m.mem.store(SP,4,OUTPUT+32)
        entry,args=0x126AC8,[DIRECT,length,OUTPUT,OUTPUT+4,OUTPUT+6,OUTPUT+16,OUTPUT+20,OUTPUT+24]
    elif kind=='ainf':entry,args=0x126D28,[DIRECT,length,OUTPUT,OUTPUT+4,OUTPUT+32,OUTPUT+36]
    elif kind=='key':
        raw=bytes.fromhex(inputs['header_hex'])
        entry,args=0x1250A0,[INNER,raw[18],raw[19],int.from_bytes(raw[12:16],'big'),OUTPUT,OUTPUT+2,OUTPUT+4]
    else:raise OracleError('Unknown authored header cut')
    initial=m.snapshot();result=m.run(entry,args)
    return dict(name=inputs['name'],kind=kind,setup=m.setup,initial=initial,result=result,
        original_instructions=m.total_steps,visited_pcs=sorted(m.all_visited),
        completion_claim='partial_not_completed' if result['failure'] else 'completed_integer_or_outer_short_reject_cut')

def source_audit(source):
    elf=Elf(ROOT/'game_data/SLUS_207.65');comments={};files=[]
    for path in sorted(source.glob('*.cpp')):
        match=re.match(r'sub_([0-9A-Fa-f]+)_',path.name)
        if not match or not any(a<=int(match[1],16)<b for a,(b,_) in BODIES.items()):continue
        data=path.read_bytes();files.append(dict(path=str(path.relative_to(ROOT)),sha256=sha(data)))
        for pc,word in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',data):
            pc,word=int(pc,16),int(word,16)
            if any(a<=pc<b for a,(b,_) in BODIES.items()):
                if pc in comments and comments[pc]!=word:raise OracleError('Conflicting source comments')
                comments[pc]=word
    zeros=[]
    for a,(b,_) in BODIES.items():
        for pc in range(a,b,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if comments[pc]!=word:raise OracleError(f'Original comment mismatch{pc:#x}')
            elif word:raise OracleError(f'Omitted nonzero word{pc:#x}')
            else:zeros.append(pc)
    return dict(files=files,matched_comments=len(comments),omitted_zero_pcs=zeros)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',required=True,type=Path)
    parser.add_argument('--reference-source',type=Path,default=ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
    args=parser.parse_args();output=args.output.resolve();frozen=output.with_name(output.stem+'-inputs.json')
    if output.exists() or frozen.exists():raise OracleError('Preserve earlier evidence; choose unused output')
    output.parent.mkdir(parents=True,exist_ok=True);frozen.write_bytes(serialized(corpus_inputs()))
    inputs=json.loads(frozen.read_bytes());audit=source_audit(args.reference_source.resolve());rows=[execute_case(row) for row in inputs['cases']]
    partial=[dict(name=r['name'],**r['result']['failure']) for r in rows if r['result']['failure']]
    value=dict(schema=1,provenance='Actual original integer header/SJRB words; full successful tag0 remains NOT completed at unsupported COP1. No fake math.',
        elf_sha256=Elf(ROOT/'game_data/SLUS_207.65').sha256,inputs_file=str(frozen.relative_to(ROOT)),inputs_sha256=sha(frozen.read_bytes()),
        body_sha256={hex(a):h for a,(_,h) in BODIES.items()},source_word_audit=audit,isa_reference=implementation_identity(),
        engine_sha256={n:sha(Path(__file__).with_name(n).read_bytes()) for n in ('sjuni_oracle.py','ee_mac_oracle.py','adx_stereo_oracle.py','sjrb_oracle.py','adx_window_oracle.py','adx_header_oracle.py')},
        cases=rows,summary=dict(cases=len(rows),returned=len(rows)-len(partial),partial=partial,
            original_instructions=sum(r['original_instructions'] for r in rows),unique_visited_words=len({pc for r in rows for pc in r['visited_pcs']})),
        limitations=['No COP1/FPU engine added. Successful tag0 coefficient initialization is open; partial state and held borrow are preserved.',
            'Only guards, bounded generic memory primitives/owned-format formatting and read-only diagnostics are hooked; no coefficient/trig/libm return substitution.',
            'Independent loop/AINF helpers are complete integer cuts, not proof that full header reached them after coefficient setup.',
            'Prepared inner/predictor/outer and synthetic backing only; no game, audio, real asset coverage, plugin, scheduling or native migration claim.'])
    output.write_bytes(serialized(value));print(json.dumps(dict(cases=len(rows),returned=len(rows)-len(partial),partial=partial,
        original_instructions=value['summary']['original_instructions'],bytes=output.stat().st_size,sha256=sha(output.read_bytes()),inputs_sha256=value['inputs_sha256']),indent=2))

if __name__=='__main__':main()
