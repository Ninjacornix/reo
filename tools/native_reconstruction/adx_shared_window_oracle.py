#!/usr/bin/env python3
"""Staged owned-word shared ADXB windows, ready configuration and loop evidence."""
from __future__ import annotations
import argparse
import copy
import csv
import hashlib
import json
from pathlib import Path
import re
import struct

import adx_window_oracle as window
import adx_header_oracle as header
import adx_header_math_oracle as math
import adxt_refill_oracle as refill
from sjuni_oracle import Elf, OracleError, MASK32, sext32, signed

ROOT=window.ROOT
sha,serialized=window.sha,window.serialized
SOURCE=ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output'
MAIN,FILE_RECORD=0x660000,0x650000
RNA,FILE_HANDLE=0xFFFF90,0xFFFF80
REGIONS=((0x122E70,0x122E90),(0x123020,0x123088),(0x124E60,0x1250A0),(0x126670,0x1266F0),(0x12C6E8,0x12C918),
         (0x12C9A0,0x12CCDC),(0x12D6E0,0x12DA68),(0x132FE0,0x132FF0),
         (0x133870,0x1343B8),(0x125248,0x125278),(0x134ED8,0x135048))
# Explicit external RNA/device control edges. No getter, loop, header, codec,
# reservation or ring result is supplied here. Calls/arguments are evidence only.
RNA_EDGES={0x13EBD8,0x13EF78,0x13EF80,0x13F038,0x13F058,0x13F080,0x13F1A0}
TRACE={**window.TRACE,**header.TRACE,**refill.TRACE,
       0x133FE0:'ready_configuration',0x133870:'first_loop_snapshot',
       0x133928:'repeat_loop',0x133AB8:'file_target_loop',0x1305C0:'file_progress',
       0x133D10:'seamless',0x126670:'aligned_header_scan',0x12CC80:'start_header',
       0x12CCB0:'stop_decoder',0x124F70:'snapshot_history_key',0x124FB0:'restore_history_key'}
ENGINE_NAMES=('sjuni_oracle.py','ee_mac_oracle.py','adx_stereo_oracle.py','sjrb_oracle.py',
              'adx_window_oracle.py','adx_header_oracle.py','adx_header_math_oracle.py',
              'adxt_refill_oracle.py')
FP_PARENT_SHA256={'7ffa76de4fe5aa56e4825c1a4a25ed591d5dfefe0331807848498974707a7158',
                  '0e2b3fd61fdcad1fe4f6f7fb479165dc6fe706bf12427e5533787371ed8d0d8f'}


def compact_serialized(value):return (json.dumps(value,sort_keys=True,separators=(',',':'))+'\n').encode()


def owned_bodies():
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    bodies={**window.BODIES,**header.BODIES,**math.MATH_BODIES,**refill.BODIES}
    for row in csv.DictReader((ROOT/'recomp/config/outbreak_ghidra_functions.csv').read_text().splitlines()):
        a,b=int(row['start'],0),int(row['end'],0)
        if any(lo<=a and b<=hi for lo,hi in REGIONS):bodies[a]=(b,sha(elf.read(a,b-a)))
    return bodies


def source_audit(bodies,source=SOURCE):
    elf=Elf(ROOT/'game_data/SLUS_207.65');comments={};files=[];covered=set()
    for path in sorted(source.glob('*.cpp')):
        match=re.match(r'sub_([0-9A-Fa-f]+)_',path.name)
        if not match or not any(a<=int(match[1],16)<b for a,(b,_) in bodies.items()):continue
        raw=path.read_bytes();files.append(dict(path=str(path.relative_to(ROOT)),sha256=sha(raw)))
        for pc,word in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw):
            pc,word=int(pc,16),int(word,16)
            if any(a<=pc<b for a,(b,_) in bodies.items()):
                if pc in comments and comments[pc]!=word:raise OracleError('Conflicting source comments')
                comments[pc]=word
    for a,(b,digest) in bodies.items():
        data=elf.read(a,b-a)
        if sha(data)!=digest:raise OracleError('Owned body digest mismatch')
        for pc in range(a,b,4):
            word=int.from_bytes(elf.read(pc,4),'little');covered.add(pc)
            if pc in comments:
                if word!=comments[pc]:raise OracleError(f'Wrong source word {pc:#x}')
            elif word:raise OracleError(f'Missing nonzero comment {pc:#x}')
    return dict(files=files,matched_comments=len(comments),
                omitted_zero_pcs=sorted(covered-set(comments)))


def changed_bytes(before,after):
    """Exact compact effects; unchanged gaps excluded, no full RAM dump."""
    if len(before)!=len(after):raise OracleError('Backing extent changed')
    result=[];start=None
    for n,(a,b) in enumerate(zip(before,after)):
        if a!=b and start is None:start=n
        if a==b and start is not None:
            result.append(dict(offset=start,before_hex=before[start:n].hex(),after_hex=after[start:n].hex()));start=None
    if start is not None:result.append(dict(offset=start,before_hex=before[start:].hex(),after_hex=after[start:].hex()))
    return result


class Machine(math.Machine):
    """Frozen EE/FP instruction engines; own bounded composition and inputs."""
    def __init__(self,inputs,worker,bodies):
        self.inputs=inputs;self.worker=worker;self.capacity=inputs['capacity'];self.extension=36
        if self.capacity not in (2048,4096,8192):raise OracleError('Finite sector ring geometry')
        if inputs['channels'] not in (1,2):raise OracleError('Finite tag0 channel geometry')
        self.elf=Elf(ROOT/'game_data/SLUS_207.65');self.code={}
        for a,(b,digest) in bodies.items():
            data=self.elf.read(a,b-a)
            if sha(data)!=digest:raise OracleError('Owned function identity changed')
            self.code.update({a+i:struct.unpack_from('<I',data,i)[0] for i in range(0,len(data),4)})
        self.mem=header.HeaderMemory()
        for a,n,fill in [(window.GLOBAL,0x4040,0),(window.INPUT-16,self.capacity+68,0xA5),
            (window.PCM-16,inputs['channels']*window.PCM_PHYSICAL+32,0xA5),
            (window.OUTER,0x9C,0),(window.INNER,0xE4,0),(window.PRED,0x3C,0),
            (window.SCRATCH-4,0x100,0x5A),(window.STACK,0x2000,0xCC),
            (header.TABLE_START,header.TABLE_BYTES,0),(header.TABLE_START+header.TABLE_BYTES,0x28,0),(header.KEY_GLOBAL,0x1C,0),
            (0x23DA58,16,0),(window.MODE,4,0),(window.ODD,4,0),
            (FILE_RECORD,0x5C,0),(MAIN,0xD0,0),(0x21A8B4,12,0)]:self.mem.map(a,n,fill)
        for a,n in [(window.GLOBAL+8,48),(header.TABLE_START,header.TABLE_BYTES),
                    (header.TABLE_START+header.TABLE_BYTES,0x28),(0x23DA58,16)]:
            self.mem.store(a,n,int.from_bytes(self.elf.read(a,n),'little'))
        self.mem.store(window.MODE,4,inputs['downmix']);self.mem.store(0x21A8B4,4,2)
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)
        self.regs=[0]*32;self.guard_depth=0;self.all_visited=set();self.total_steps=0;self.setup=[]
        self.rings=[window.POOL+i*64 for i in range(inputs['channels']+1)]
        self.buffers=[(window.INPUT,self.capacity+36)]+[(window.PCM+i*window.PCM_PHYSICAL,window.PCM_PHYSICAL) for i in range(inputs['channels'])]
        self.fpr=math.fpr_seed();self.fcr31=0;self.fp_steps=0;self.qualified_fp_words=set(math.fp_words().values())
        self.jobs=[];self.action={};self.status_index=0;self.position=0;self.file_closed=False
        self.file_bytes=bytes.fromhex(inputs['file_hex'])
        if len(self.file_bytes)>131072:raise OracleError('Bounded synthetic file')

    def small(self):
        return dict(outer_hex=self.raw(window.OUTER,0x9C).hex(),inner_hex=self.raw(window.INNER,0xE4).hex(),
            predictor_hex=self.raw(window.PRED,0x3C).hex(),main_hex=self.raw(MAIN,0xD0).hex(),
            source_hex=self.raw(FILE_RECORD,0x5C).hex(),rings=[self.mem.words(r,16) for r in self.rings],
            key_global_hex=self.raw(header.KEY_GLOBAL,0x1C).hex(),odd_u32=self.mem.load(window.ODD,4),
            file_position_sectors=self.position,job_count=len(self.jobs))

    def snapshot(self):
        return dict(**self.small(),backing_sha256=[sha(self.raw(a-16,n+32)) for a,n in self.buffers],
            stack_frame_hex=self.raw(window.SP-0x400,0x400).hex(),caller_guard_hex=self.raw(window.SP,32).hex(),
            lower_stack_guard_hex=self.raw(window.STACK,32).hex(),jobs=copy.deepcopy(self.jobs))

    def instruction(self,pc,word):
        if pc in TRACE:
            state=self.small()
            if pc not in (0x133FE0,0x133870,0x133928,0x133AB8,0x1305C0,0x133D10,0x12D338):
                state={k:state[k] for k in ('rings','source_hex','outer_hex','predictor_hex')}
            self.events.append(dict(kind='original_entry',name=TRACE[pc],pc=pc,from_pc=self.from_pc,
                arguments_u64=list(self.regs[4:12]),write_index=len(self.mem.writes),state=state))
        return math.Machine.instruction(self,pc,word)

    def run(self,entry,arguments=(),**options):
        before=[self.raw(a-16,n+32) for a,n in self.buffers];fpr=self.fpr.copy();fcr=self.fcr31;fpsteps=self.fp_steps
        result=window.Machine.run(self,entry,arguments,**options)
        result['writes_summary']=dict(count=len(result['writes']),sha256=sha(serialized(result['writes'])))
        del result['writes']
        result['backing_effects']=[dict(base=a-16,bytes=n+32,before_sha256=sha(old),after_sha256=sha(self.raw(a-16,n+32)),
            changes=changed_bytes(old,self.raw(a-16,n+32))) for (a,n),old in zip(self.buffers,before)]
        result.update(fp_before=dict(fpr_u32=fpr,fcr31=fcr),fp_after=dict(fpr_u32=self.fpr.copy(),fcr31=self.fcr31),fp_steps=self.fp_steps-fpsteps)
        result['return_is_defined']=entry in (0x13F8A8,0x1305C0,0x126670,0x126F20)
        return result

    def hook(self,pc):
        if pc==window.MEMSET and self.regs[4]&MASK32==window.PRED+0x28:
            if self.regs[5]&MASK32 or self.regs[6]&MASK32!=8:raise OracleError('Only actual predictor-history clear')
            self.events.append(dict(kind='bounded_history_memset',pc=pc,destination=window.PRED+0x28,bytes=8,value=0,write_index=len(self.mem.writes)))
            self.mem.fill(window.PRED+0x28,8,0);self.regs[2]=sext32(window.PRED+0x28)
            self.pc=self.regs[31]&MASK32;return True
        if pc in (*refill.ENTER,*refill.LEAVE):
            entering=pc in refill.ENTER;before=self.guard_depth;self.guard_depth+=1 if entering else -1
            if self.guard_depth<0:raise OracleError('Unbalanced external guard')
            self.events.append(dict(kind='external_guard',pc=pc,entering=entering,depth_before=before,depth_after=self.guard_depth,
                write_index=len(self.mem.writes)));self.pc=self.regs[31]&MASK32;return True
        if pc in RNA_EDGES:
            self.events.append(dict(kind='external_rna_control',pc=pc,from_pc=self.from_pc,arguments_u64=list(self.regs[4:12]),
                write_index=len(self.mem.writes),return_contract='void; no supplied result or device behavior'))
            self.pc=self.regs[31]&MASK32;return True
        if pc==window.PCM_CALLBACK:
            size=self.regs[7]&MASK32
            if size>window.PCM_CAP:raise OracleError('Bounded PCM observation')
            self.events.append(dict(kind='pcm_callback',pc=pc,arguments_u64=list(self.regs[4:8]),
                pcm_hex=self.raw(self.regs[6]&MASK32,size).hex(),state=self.small(),write_index=len(self.mem.writes)))
            self.pc=self.regs[31]&MASK32;return True
        if pc in (refill.STATUS,refill.SEEK,refill.REQUEST,refill.CLOSE):
            event=dict(pc=pc,arguments_u64=list(self.regs[4:9]),write_index=len(self.mem.writes))
            if pc==refill.STATUS:
                states=self.action.get('statuses',[])
                if self.status_index>=len(states):raise OracleError('Unspecified external file status')
                value=states[self.status_index];self.status_index+=1;self.regs[2]=sext32(value)
                event.update(kind='scripted_cvfs_status',return_i32=value)
            elif pc==refill.SEEK:
                if self.regs[6]&MASK32:raise OracleError('Only absolute sector seek')
                self.position=self.regs[5]&MASK32;self.regs[2]=sext32(self.position)
                event.update(kind='scripted_cvfs_seek',return_i32=self.position)
            elif pc==refill.REQUEST:
                requested=self.regs[5]&MASK32;accepted=self.action.get('accept')
                if accepted=='requested':accepted=requested
                if not isinstance(accepted,int) or not -3<=accepted<=requested<=4:raise OracleError('Unspecified bounded read acceptance')
                event.update(kind='scripted_cvfs_request',requested_sectors=requested,accepted_sectors=accepted,state=self.small())
                if accepted>0:
                    self.jobs.append(dict(observation_id=len(self.jobs),destination=self.regs[6]&MASK32,
                        sector=self.position,accepted_sectors=accepted,written=False))
                    if self.action.get('inline_write'):self.write_job(len(self.jobs)-1)
                self.regs[2]=sext32(accepted)
            else:self.file_closed=True;self.regs[2]=0;event['kind']='scripted_cvfs_close'
            self.events.append(event);self.pc=self.regs[31]&MASK32;return True
        if pc==0x1280D0:
            self.events.append(dict(kind='diagnostic',pc=pc,arguments_u64=list(self.regs[4:8]),state=self.small(),write_index=len(self.mem.writes)))
            self.pc=self.regs[31]&MASK32;return True
        return header.Machine.hook(self,pc)

    write_job=refill.Machine.write_job

    def prepare(self):
        self.setup_call(0x13F7F8,[])
        for index,(a,n) in enumerate(self.buffers):
            cap,ext=(self.capacity,36) if index==0 else (window.PCM_CAP,window.PCM_EXT)
            result=self.setup_call(0x13F8A8,[a,cap,ext])
            if result['raw_v0_lower64_observation_only']&MASK32!=self.rings[index]:raise OracleError('Original ring pool identity')
            self.setup_call(0x13F9E0,[self.rings[index],window.ERROR,self.rings[index]])
        for i,occupied in enumerate(self.inputs.get('initial_pcm_bytes',[0]*self.inputs['channels'])):
            self.produce(self.rings[i+1],count=occupied)
        self.advance_empty(self.rings[0],self.inputs['position'])
        # Explicit prepared queued prefix; refill progress setter is actual code.
        seeded=self.inputs['seed_bytes'];self.produce(self.rings[0],data=self.file_bytes[:seeded])
        for off,value in {4:window.INNER,8:self.rings[0],0x38:128,0x3C:-1,
                          0x50:window.PCM_CALLBACK,0x54:0x24681357}.items():self.mem.store(window.OUTER+off,4,value)
        self.mem.store(window.OUTER,1,1);self.mem.store(window.OUTER+1,1,1);self.mem.store(window.OUTER+2,1,self.inputs['channels'])
        for i in range(self.inputs['channels']):self.mem.store(window.OUTER+0xC+4*i,4,self.rings[i+1])
        for off,value in {8:window.PRED,0x38:self.inputs['channels'],0x3C:window.PCM,0x40:8192,0x44:8288,
            0x78:0x12CEB8,0x7C:window.OUTER,0x80:0x124840,0x84:window.INNER}.items():self.mem.store(window.INNER+off,4,value)
        self.mem.store(window.INNER,2,1);self.mem.store(window.PRED,4,1)
        for i,value in enumerate((23456,7,-9)):self.mem.store(window.INNER+0x9C+2*i,2,value)
        self.setup_call(0x130108,[FILE_RECORD,FILE_HANDLE,0,len(self.file_bytes),self.rings[0]])
        self.mem.store(FILE_RECORD+0x45,1,1)
        self.setup_call(0x130E18,[FILE_RECORD,self.capacity,self.capacity]);self.setup_call(0x130E28,[FILE_RECORD,self.capacity//2048])
        if self.inputs['source_start']:self.setup_call(0x130698,[FILE_RECORD,0xFFFFF])
        self.setup_call(0x1305C0,[FILE_RECORD,seeded//2048]);self.setup_call(0x1307A8,[FILE_RECORD,-1])
        for off,value in {4:window.OUTER,8:FILE_RECORD,0xC:RNA,0x10:self.rings[0],0x14:self.rings[0],
            0x38:60}.items():self.mem.store(MAIN+off,4,value)
        self.mem.store(MAIN,1,1);self.mem.store(MAIN+1,1,1);self.mem.store(MAIN+3,1,self.inputs.get('channel_capacity',self.inputs['channels']))
        if not self.inputs.get('file_present',True):self.mem.store(MAIN+8,4,0)
        self.mem.store(MAIN+0x6C,1,self.inputs['loop_enabled']);self.mem.store(MAIN+0x98,1,self.inputs['seamless'])


def corpus_inputs():
    cases=[]
    def add(name,rate=44100,channels=1,loop=False,total=40017,windows=0,
            loop_start=32,loop_end=128,loop_byte_start=114,loop_byte_end=168,**changes):
        data=header.header(version=4 if loop else 3,rate=rate,channels=channels,total=total)
        if loop:
            data[0x20:0x38]=struct.pack('>HHIIIII',1,1,0,loop_start,loop_byte_start,loop_end,loop_byte_end)
        payload=b''.join(window.block(i%64) for i in range(((total+31)//32)*channels))
        file=data+payload;file+=bytes((-len(file))%2048)
        actions=[dict(kind='header'),dict(kind='ready')]
        for _ in range(windows):actions.extend([dict(kind='decode'),dict(kind='consume_pcm',bytes=16384),
            dict(kind='source',statuses=[0,3],accept='requested',inline_write=True),dict(kind='source',statuses=[1,3],accept='requested',inline_write=True)])
        row=dict(name=name,capacity=8192,channels=channels,downmix=0,position=0,seed_bytes=min(8192,len(file)),source_start=True,
            file_hex=bytes(file).hex(),loop_enabled=int(loop),seamless=0,actions=actions)
        row.update(changes);cases.append(row)
    for rate in (24000,44100,48000):
        for loop in (False,True):add(f'ready-{rate}-'+('loop' if loop else 'finite'),rate=rate,loop=loop)
    add('long-mono-44100',windows=40)
    add('long-stereo-48000',rate=48000,channels=2,windows=40)
    add('long-downmix-24000',rate=24000,channels=2,downmix=1,windows=70)
    add('file-loop-first-and-repeat',loop=True,total=512,windows=5)
    for rate,channels,downmix in [(44100,1,0),(48000,1,0),(44100,2,1)]:
        add(f'full-loop-request-{rate}-{channels}-{downmix}',rate=rate,channels=channels,downmix=downmix,loop=True,
            loop_start=12000,loop_end=24000,loop_byte_start=96+375*18*channels,
            loop_byte_end=96+750*18*channels,windows=3)
    # Complete seamless callback owns real Get/Unget and actual header re-entry.
    first=header.header(total=64);second=header.header(total=96,rate=48000)
    payload=bytes(first)+window.block(0)+window.block(1)+b'\x80\x01\x00\x0c'+bytes(12)+bytes(second)+window.block(2)+window.block(3)+window.block(4)
    payload+=bytes((-len(payload))%2048)
    add('seamless-next-header-first-span',total=64,file_hex=payload.hex(),seed_bytes=len(payload),seamless=1,
        actions=[dict(kind='header'),dict(kind='ready'),dict(kind='decode'),dict(kind='consume_pcm',bytes=16384),dict(kind='decode'),dict(kind='decode')])
    first_case=copy.deepcopy(cases[-1])
    def seamless(name,second_header=second,padding=0,position=0,seed=None,record=b'\x80\x01\x00\x0c'+bytes(12),extra_actions=None,**changes):
        data=bytes(first)+window.block(0)+window.block(1)+record+bytes(padding)+bytes(second_header)+window.block(2)+window.block(3)+window.block(4)
        default_seed=len(data);data+=bytes((-len(data))%8192)
        row=copy.deepcopy(first_case);row.update(name=name,file_hex=data.hex(),seed_bytes=default_seed if seed is None else seed,position=position)
        if extra_actions is not None:row['actions']=extra_actions
        row.update(changes);cases.append(row)
    seamless('seamless-next-header-second-span',padding=256,position=7900,seed=2048)
    seamless('seamless-pending-producer-two-grants',padding=256,position=7900,seed=2048,
        extra_actions=[dict(kind='header'),dict(kind='ready'),dict(kind='decode'),
            dict(kind='source',statuses=[0,3],accept='requested',inline_write=False),dict(kind='decode'),
            dict(kind='write_job',id=0),dict(kind='source',statuses=[1,3],accept='requested',inline_write=False),dict(kind='decode')])
    seamless('seamless-no-next-magic',second_header=bytes(96))
    seamless('seamless-short-end-record',second_header=b'',record=b'\x80\x01\x00',seed=135,
        domain='negative bounded prepared input; truncated end record')
    seamless('seamless-invalid-end-magic',record=b'\x81\x01\x00\x0c'+bytes(12))
    seamless('seamless-negative-record-length',record=b'\x80\x01\x80\x00'+bytes(12),
        domain='unsafe original negative signed extent; never native admission')
    seamless('seamless-next-header-reject',second_header=header.header(encoding=5,total=96))
    seamless('seamless-next-header-math-cut',second_header=header.header(filter_value=8000,total=96),
        domain='unowned math range reduction; partial execution only')
    seamless('seamless-header-defer-after-prefix',position=8030,seed=2048,padding=0)
    # Actual file target callback runs within actual130800 after publication.
    target_actions=[dict(kind='header'),dict(kind='ready'),
        dict(kind='source',statuses=[0,3],accept=1,inline_write=False),dict(kind='decode'),
        dict(kind='write_job',id=0),dict(kind='source',statuses=[1,3],accept='requested',inline_write=False),dict(kind='decode')]
    add('file-target-progress-mutates-in-publication',loop=True,total=8192,seed_bytes=2048,
        loop_byte_end=4096,actions=target_actions)
    add('file-target-disabled-removes-limits',loop=True,total=8192,seed_bytes=2048,
        loop_byte_end=4096,loop_enabled=0,actions=target_actions)
    add('repeat-padding-short-diagnostic',loop=True,total=512,seed_bytes=512,
        actions=[dict(kind='header'),dict(kind='ready'),dict(kind='decode'),dict(kind='decode'),dict(kind='decode')])
    add('repeat-without-file-disabled',loop=True,total=512,file_present=False,loop_enabled=0,
        domain='unsafe original null-file ready configuration; excluded from native profile',
        actions=[dict(kind='header'),dict(kind='ready'),dict(kind='decode'),dict(kind='decode'),dict(kind='decode')])
    add('repeat-no-file-disabled-helper',loop=True,total=512,file_present=False,loop_enabled=0,
        domain='direct complete child body with prepared caller; not a full ready/window transaction',
        actions=[dict(kind='header'),dict(kind='call',entry='repeat')])
    add('ready-before-header-not-ready',actions=[dict(kind='ready')])
    add('ready-insufficient-channel-cut',channels=2,channel_capacity=1,
        domain='diagnostic/stop closure probe; retained partial if a dependency is unowned')
    for name,channels,downmix,block_index in [('mono-large-marker-prefix',1,0,17),
            ('stereo-large-right-marker',2,0,35),('downmix-large-right-marker',2,1,35)]:
        add(name,channels=channels,downmix=downmix,windows=2,total=8193)
        row=cases[-1];data=bytearray.fromhex(row['file_hex']);offset=96+block_index*18
        data[offset:offset+2]=b'\x80\x00';row['file_hex']=data.hex()
    add('stereo-backpressure-full-request-recovery',channels=2,windows=3,total=8193,initial_pcm_bytes=[16352,16352])
    pending=copy.deepcopy(next(row for row in cases if row['name']=='seamless-pending-producer-two-grants'))
    pending['name']='seamless-pending-partial-acceptance';pending['actions'][3]['accept']=1;cases.append(pending)
    pending=copy.deepcopy(next(row for row in cases if row['name']=='seamless-pending-producer-two-grants'))
    pending['name']='seamless-pending-error-return';pending['actions'][5]=dict(kind='source',statuses=[3,3],accept='requested',inline_write=False)
    pending['actions'].pop(6);cases.append(pending)
    add('producer-stop-accepted-publication',total=8193,seed_bytes=2048,
        actions=[dict(kind='header'),dict(kind='ready'),dict(kind='source',statuses=[0,3],accept=1,inline_write=False),
            dict(kind='call',entry='source_stop'),dict(kind='decode'),dict(kind='write_job',id=0),
            dict(kind='source',statuses=[1,3],accept='requested',inline_write=False)])
    for enabled in (0,1):
        add(f'file-target-at-physical-end-loop-{enabled}',loop=True,total=512,seed_bytes=2048,
            loop_byte_end=4096,loop_enabled=enabled,actions=target_actions)
        row=cases[-1];data=bytes.fromhex(row['file_hex']);row['file_hex']=(data+bytes(4096-len(data))).hex()
    return dict(schema=1,stage='initial authored ready/long/loop probes; incomplete coverage until reviewed',
        provenance='Bounded synthetic file, prepared owner records, actual SJRB words and scripted external file/RNA edges; no game recording.',cases=cases)


def execute_case(inputs,worker,bodies):
    m=Machine(inputs,worker,bodies);m.prepare();initial=m.snapshot();backings=[m.raw(a-16,n+32).hex() for a,n in m.buffers];operations=[]
    for action in inputs['actions']:
        m.action=action;m.status_index=0
        if action['kind'] in ('header','decode'):result=m.run(0x12D638,[window.OUTER],full=False,limit=2500000)
        elif action['kind']=='ready':result=m.run(0x133FE0,[MAIN],full=False)
        elif action['kind']=='source':result=m.run(0x130800,[FILE_RECORD],full=False)
        elif action['kind']=='call':
            entries={'repeat':(0x133928,MAIN),'source_stop':(0x1306E0,FILE_RECORD)}
            if action['entry'] not in entries:raise OracleError('Unknown original control entry')
            entry,argument=entries[action['entry']];result=m.run(entry,[argument],full=False)
        elif action['kind']=='write_job':
            before=[m.raw(a-16,n+32) for a,n in m.buffers];m.write_job(action['id'])
            result=dict(status='external_input',failure=None,original_instructions=0,events=[],
                provider_write=copy.deepcopy(m.jobs[action['id']]),after=m.small(),
                backing_effects=[dict(base=a-16,bytes=n+32,before_sha256=sha(old),after_sha256=sha(m.raw(a-16,n+32)),
                    changes=changed_bytes(old,m.raw(a-16,n+32))) for (a,n),old in zip(m.buffers,before)])
        elif action['kind']=='consume_pcm':
            result=[]
            for ring in m.rings[1:]:
                got=m.run(0x13FA88,[ring,1,action['bytes'],window.SCRATCH],full=False)
                result.extend((got,m.run(0x13FBF8,[ring,0,window.SCRATCH],full=False)))
        else:raise OracleError('Unknown frozen authored action')
        operations.append(dict(input=action,results=result))
        if any(r['failure'] for r in (result if isinstance(result,list) else [result])):break
    return dict(name=inputs['name'],setup=m.setup,initial=initial,initial_backings_hex=backings,
        operations=operations,final=m.snapshot(),original_instructions=m.total_steps,visited_pcs=sorted(m.all_visited))


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--case',action='append',dest='selected',help='Replay only named cases; complete authored input file is still frozen first.')
    parser.add_argument('--fp-worker',type=Path,default=ROOT/'build-native-sjuni/adx-header-math-oracle-v4/gcc/fp_worker.exe')
    args=parser.parse_args();output=args.output.resolve()
    if output.exists():raise OracleError('Preserve earlier evidence; use a new output directory')
    output.mkdir(parents=True);frozen=output/'inputs.json';frozen.write_bytes(serialized(corpus_inputs()))
    inputs=json.loads(frozen.read_bytes());bodies=owned_bodies();audit=source_audit(bodies)
    parent_fixture=args.fp_worker.parent/'original-fixture.json';parent=json.loads(parent_fixture.read_bytes())
    if sha(parent_fixture.read_bytes()) not in FP_PARENT_SHA256:raise OracleError('Unqualified FP parent fixture')
    if sha(args.fp_worker.read_bytes())!=parent['compatibility']['worker_binary_sha256']:raise OracleError('Qualified FP binary changed')
    if args.selected and set(args.selected)-{c['name'] for c in inputs['cases']}:raise OracleError('Unknown selected case')
    rows=[]
    with math.FpuWorker(args.fp_worker) as worker:
        for case in inputs['cases']:
            if args.selected and case['name'] not in args.selected:continue
            row=execute_case(case,worker,bodies);rows.append(row)
            (output/(case['name']+'.json')).write_bytes(compact_serialized(row))
            failures=[r['failure'] for op in row['operations'] for r in (op['results'] if isinstance(op['results'],list) else [op['results']]) if r['failure']]
            print(case['name'],row['original_instructions'],failures,flush=True)
    value=dict(schema=1,elf_sha256=Elf(ROOT/'game_data/SLUS_207.65').sha256,inputs_sha256=sha(frozen.read_bytes()),
        body_sha256={hex(a):dict(end=b,sha256=d) for a,(b,d) in bodies.items()},source_word_audit=audit,
        engine_sha256={name:sha(Path(__file__).with_name(name).read_bytes()) for name in ENGINE_NAMES},
        oracle_sha256=sha(Path(__file__).read_bytes()),selected_cases=args.selected,fp_parent_fixture_sha256=sha(parent_fixture.read_bytes()),
        tables=[dict(address=a,bytes=n,sha256=sha(Elf(ROOT/'game_data/SLUS_207.65').read(a,n)))
            for a,n in ((window.GLOBAL+8,48),(header.TABLE_START,header.TABLE_BYTES+0x28),(0x23DA58,16))],
        fp_worker_sha256=sha(args.fp_worker.read_bytes()),cases=[dict(name=r['name'],file=r['name']+'.json',
            sha256=sha((output/(r['name']+'.json')).read_bytes()),original_instructions=r['original_instructions']) for r in rows],
        summary=dict(cases=len(rows),original_instructions=sum(r['original_instructions'] for r in rows),
            unique_visited_words=len(set().union(*(set(r['visited_pcs']) for r in rows))),
            partial=[dict(name=r['name'],**result['failure']) for r in rows for op in r['operations']
                for result in (op['results'] if isinstance(op['results'],list) else [op['results']]) if result['failure']]),
        limitations=['Initial staged corpus; inspect each result/partial cut and family coverage. No native Source2/window or full player proof.',
                    'External file status/acceptance/write timing and RNA/device control edges are explicit synthetic inputs, not real I/O or audible completion.'])
    (output/'manifest.json').write_bytes(serialized(value));print(json.dumps(dict(inputs_sha256=value['inputs_sha256'],cases=len(rows),manifest_sha256=sha((output/'manifest.json').read_bytes()))))


if __name__=='__main__':main()
