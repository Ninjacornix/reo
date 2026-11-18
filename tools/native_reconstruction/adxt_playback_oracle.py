#!/usr/bin/env python3
"""Buffer/start/drain original ADXT instructions with actual SJRB queues.

No native playback code or expected transition is imported. The only new
external edges are a bounded generic memset, CRI critical sections and the
completed DTR stop call. DTR stop is an explicit completion assumption here,
not an implementation or device fence proof.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import sjrb_oracle as ring
from sjuni_oracle import Elf, OracleError, MASK32, sext32, signed

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/adxt-playback'
MAIN,DECODER,INNER,RNA,DTR=0x600000,0x610000,0x620000,0x630000,0x640000
PCM_BUFFERS=(ring.BUFFER,0x410010)
RNA_BUFFER=0x420010
TICK,SCRATCH=0x20F3C4,0x21B7A0
RANGES=((0x1343B8,0x1347F8),(0x12C6E8,0x12C760),(0x12CBB8,0x12CBC0),
        (0x12D7A8,0x12D7F0),(0x124E78,0x124E80),(0x124EE8,0x124EF0),
        (0x132548,0x132598),(0x13EBD8,0x13EC60),(0x13ECB0,0x13ED28))
sha=lambda b:hashlib.sha256(b).hexdigest()
encode=lambda v:(json.dumps(v,sort_keys=True,separators=(',',':'))+'\n').encode()
ENGINES=('sjrb_oracle.py','sjuni_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py')


def authority():
    elf=Elf(ROOT/'game_data/SLUS_207.65');comments={};sources=[]
    for path in sorted((ROOT/'recomp/config/output').glob('*.cpp')):
        match=re.match(r'sub_([0-9A-Fa-f]+)_',path.name)
        if not match or not any(a<=int(match[1],16)<b for a,b in RANGES):continue
        raw=path.read_bytes();sources.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(raw)))
        for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw):
            pc,word=int(a,16),int(b,16)
            if any(lo<=pc<hi for lo,hi in RANGES):
                if pc in comments and comments[pc]!=word:raise OracleError('Conflicting source comments')
                comments[pc]=word
    rows=[]
    for start,end in RANGES:
        zero=[]
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if comments[pc]!=word:raise OracleError('Original source word mismatch '+hex(pc))
            elif word:raise OracleError('Missing nonzero comment '+hex(pc))
            else:zero.append(pc)
        rows.append(dict(start=start,end=end,sha256=sha(elf.read(start,end-start)),omitted_zero_pcs=zero))
    return dict(elf_sha256=elf.sha256,ranges=rows,sources=sources,
                engines={n:sha(Path(__file__).with_name(n).read_bytes())for n in ENGINES})


def inputs():
    rows=[]
    def add(name,phase=2,channels=1,request=128,queued=0,occupied=None,**kw):
        row=dict(name=name,phase=phase,channels=channels,request=request,queued=queued,
                 occupied=occupied if occupied is not None else [0]*channels,
                 decoder=2,block=32,inhibit=0,paused=0,started=0,padding=0,
                 base=0x12345678,tick_base=0x89ABCDEF,tick=0xFFFFFFFE,
                 cursor=0,play=0,transfer=1,thru=0)
        row.update(kw);rows.append(row)
    for ch in (1,2):
        for decoder in (2,3):
            for queued in (0,127,128,255,256,257,8160,8192):
                for inhibit,paused in ((0,0),(0,1),(1,0),(1,1)):
                    add(f'start-{ch}-{decoder}-{queued}-{inhibit}-{paused}',channels=ch,
                        decoder=decoder,queued=queued,inhibit=inhibit,paused=paused)
    for ch in (1,2):
        for n in (0,2,62,64,66,128,16384):
            for ended in (False,True):
                add(f'playing-{ch}-{n}-{ended}',phase=3,channels=ch,occupied=[n]*ch,
                    decoder=3 if ended else 2,padding=987,play=1)
    for ch in (1,2):
        for request in (1,32,128,4096):
            for occupied in (0,2,62,64,16256,16384):
                for queued in (0,1,128):
                    add(f'drain-{ch}-{request}-{occupied}-{queued}',phase=4,channels=ch,
                        request=request,occupied=[occupied]*ch,queued=queued,decoder=3,play=1)
    for ch in (1,2):
        for cursor in (16256,16320,16382):
            for phase in (2,4):
                add(f'wrap-{ch}-{cursor}-{phase}',phase=phase,channels=ch,cursor=cursor,
                    decoder=3,occupied=[62]*ch,queued=0)
    for padding in (1,32,8192,0x7FFFFFFF,0xFFFFFFF0,0xFFFFFFFF):
        add(f'padding-word-{padding}',phase=4,decoder=3,padding=padding,play=1)
    # Explicit uneven-channel observations, outside the composed matching-grant
    # owner profile; never silently discard them from the original evidence.
    for occupied in ([0,64],[64,0],[62,66],[16382,0]):
        for phase in (2,3,4):
            add(f'asymmetric-{occupied[0]}-{occupied[1]}-{phase}',phase=phase,
                channels=2,occupied=occupied,decoder=3)
    return rows


class Machine(ring.Machine):
    def __init__(self,case):
        self.case=case;super().__init__(capacity=16384,extension=192)
        for a,b in RANGES:
            data=self.elf.read(a,b-a)
            self.code.update({a+i:struct.unpack_from('<I',data,i)[0]for i in range(0,len(data),4)})
        for a,n,fill in ((MAIN,0xD0,0),(DECODER,0x9C,0),(INNER,0xE4,0),
                         (RNA,0x80,0),(DTR,0x40,0),(TICK,4,0),(SCRATCH,12,0),
                         (PCM_BUFFERS[1]-16,16608,0xA5),(RNA_BUFFER-16,16416,0xA5)):
            self.mem.map(a,n,fill)
        self.objects=[]

    def projection(self):
        return dict(phase=self.mem.load(MAIN+1,1),started=self.mem.load(MAIN+0x71,1),
            base=self.mem.load(MAIN+0x9C,4),tick_base=self.mem.load(MAIN+0xA0,4),
            padding=self.mem.load(MAIN+0xA8,4),play=self.mem.load(RNA+0x24,1),
            transfer=self.mem.load(RNA+0x50,1),stop_seen=self.mem.load(RNA+0x51,1),
            thru=self.mem.load(RNA+0x53,1),
            rings=[self.mem.words(obj,16)for obj in self.objects],
            backings=[self.bytes(b,16576 if i<self.case['channels'] else 16384).hex()
                      for i,b in enumerate((*PCM_BUFFERS[:self.case['channels']],RNA_BUFFER))])

    def state(self):
        # ABI/stack and every object/backing remain in the raw record. Native
        # comparison selects typed fields explicitly, never a broad byte mask.
        return dict(projection=self.projection(),stack_hex=self.bytes(ring.STACK_TOP-0x100,0x100).hex())

    def hook(self,pc):
        if pc==ring.MEMCPY:
            dest,source,n=[r&MASK32 for r in self.regs[4:7]]
            backings=(*PCM_BUFFERS[:self.case['channels']],RNA_BUFFER)
            if n>192 or not any(b<=dest<=dest+n<=b+16576 and b<=source<=source+n<=b+16576
                                for b in backings)or(n and dest<source+n and source<dest+n):
                raise OracleError('Unadmitted queue mirror memcpy')
            self.events.append(dict(kind='queue_mirror_memcpy',destination=dest,source=source,bytes=n,
                                    write_index=len(self.mem.writes)))
            data=self.bytes(source,n)
            for i,v in enumerate(data):self.mem.store(dest+i,1,v)
            self.regs[2]=sext32(dest);self.pc=self.regs[31]&MASK32;return True
        if pc==ring.MEMSET:
            dest,value,n=[r&MASK32 for r in self.regs[4:7]]
            if ring.POOL<=dest and dest+n<=ring.POOL+ring.POOL_BYTES:return super().hook(pc)
            if value or not any(b<=dest<=dest+n<=b+16576 for b in PCM_BUFFERS[:self.case['channels']]):
                raise OracleError('Unadmitted silence memset')
            self.events.append(dict(kind='silence_memset',destination=dest,bytes=n,write_index=len(self.mem.writes)))
            for i in range(n):self.mem.store(dest+i,1,0)
            self.regs[2]=sext32(dest);self.pc=self.regs[31]&MASK32;return True
        if pc in (0x1264E0,0x1264F8):
            entering=pc==0x1264E0;self.guard_depth+=1 if entering else -1
            self.events.append(dict(kind='cri_guard',entering=entering,depth=self.guard_depth,
                                    write_index=len(self.mem.writes)))
            if self.guard_depth<0:raise OracleError('Unbalanced CRI guard')
            self.pc=self.regs[31]&MASK32;return True
        if pc==0x138BE0:
            self.events.append(dict(kind='external_completed_dtr_stop',handle=self.regs[4]&MASK32,
                                    write_index=len(self.mem.writes)))
            self.pc=self.regs[31]&MASK32;return True
        return super().hook(pc)

    def call(self,name,*args):
        result=self.run(name,list(args),step_cap=200000)
        if result['failure']:raise OracleError(str(result['failure']))
        return result

    def produce(self,obj,count):
        if not count:return
        self.call('get',obj,0,count,ring.SLOTS);self.call('put',obj,1,ring.SLOTS)

    def prepare(self):
        c=self.case;self.call('initialize')
        for b in (*PCM_BUFFERS[:c['channels']],RNA_BUFFER):
            created=self.call('create',b,16384,192 if b!=RNA_BUFFER else 0)
            obj=created['return_u32'];self.objects.append(obj)
            self.call('set_error',obj,ring.ERROR,obj)
        for i,obj in enumerate(self.objects[:-1]):
            self.produce(obj,c['cursor'])
            if c['cursor']:
                self.call('get',obj,1,c['cursor'],ring.SLOTS);self.call('put',obj,0,ring.SLOTS)
            self.produce(obj,c['occupied'][i])
        self.produce(self.objects[-1],c['queued']*2)
        for offset,value in {4:DECODER,12:RNA,0x48:c['request'],0x9C:c['base'],
                             0xA0:c['tick_base'],0xA8:c['padding']}.items():self.mem.store(MAIN+offset,4,value)
        for off,key in ((1,'phase'),(0x70,'inhibit'),(0x71,'started'),(0x72,'paused')):
            self.mem.store(MAIN+off,1,c[key])
        for i,obj in enumerate(self.objects[:-1]):self.mem.store(MAIN+0x18+4*i,4,obj)
        self.mem.store(DECODER+1,1,c['decoder']);self.mem.store(DECODER+4,4,INNER)
        self.mem.store(INNER+0xE,1,c['channels']);self.mem.store(INNER+0x10,4,c['block'])
        for off,value in ((8,DTR),(0x24,c['play']),(0x26,c['channels']),
                          (0x50,c['transfer']),(0x53,c['thru'])):self.mem.store(RNA+off,4 if off==8 else 1,value)
        for i in range(c['channels']):self.mem.store(RNA+0x10+4*i,4,0x650000+64*i)
        self.mem.store(DTR+8,4,self.objects[-1]);self.mem.store(TICK,4,c['tick'])


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--freeze',action='store_true')
    p.add_argument('--frozen',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise OracleError('Fresh scoped output required')
    auth=authority();out.mkdir(parents=True)
    if a.freeze:
        (out/'inputs.json').write_bytes(encode(dict(cases=inputs())))
        (out/'manifest.json').write_bytes(encode(dict(authority=auth,oracle_sha256=sha(Path(__file__).read_bytes()),
            inputs_sha256=sha((out/'inputs.json').read_bytes()),native_exists=(ROOT/'game/native/adxt_playback/playback.cpp').exists())))
        print('Frozen',len(inputs()),'independent playback inputs');return
    identity=json.loads((a.frozen/'manifest.json').read_bytes())
    if identity['authority']!=auth or identity['oracle_sha256']!=sha(Path(__file__).read_bytes())or identity['inputs_sha256']!=sha((a.frozen/'inputs.json').read_bytes()):raise OracleError('Frozen source/input drift')
    ring.ENTRIES.update(buffering=(0x1343B8,False),playing=(0x134530,False),draining=(0x1345F0,False))
    rows=[];total=0
    for c in json.loads((a.frozen/'inputs.json').read_bytes())['cases']:
        m=Machine(c);m.prepare();result=m.call({2:'buffering',3:'playing',4:'draining'}[c['phase']],MAIN)
        path=out/(c['name']+'.json');path.write_bytes(encode(dict(input=c,original=result)))
        rows.append(dict(name=c['name'],sha256=sha(path.read_bytes()),instructions=result['original_instructions']))
        total+=result['original_instructions']
    receipt=dict(schema=1,status='returned original playback instructions',cases=rows,instructions=total,
                 frozen_manifest_sha256=sha((a.frozen/'manifest.json').read_bytes()),game_run=False,device_opened=False,
                 boundary='completed external DTR stop assumed; no DMA or device completion proof')
    (out/'receipt.json').write_bytes(encode(receipt));print(json.dumps(dict(cases=len(rows),instructions=total)))


if __name__=='__main__':main()
