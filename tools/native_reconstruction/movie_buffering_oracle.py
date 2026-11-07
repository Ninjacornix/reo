#!/usr/bin/env python3
"""Execute complete original movie buffering predicates and two-span peeks.

The SJ virtual methods are explicit queue ports. The predicate, peek closure,
shared guard, cached clock, pause controller and rational helpers execute owned
ELF instructions. No game, renderer, audio device or production path is opened.
"""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import struct
import movie_timing_context_oracle as joined

ROOT=joined.ROOT
BASE=ROOT/'build-native-sjuni/movie-buffering'
INTERVALS={0x176778:0x176790,0x172CF8:0x172E78,0x172E78:0x172F58,0x172F58:0x172FF8,
           0x172FF8:0x1730B0,0x1730B0:0x173130,0x177C78:0x177C90,
           0x177C90:0x177CB0,0x167D00:0x167D20,0x167D20:0x167D48,
           0x166FE8:0x167000,0x167000:0x1670C8,0x1672E0:0x1673D8}
PROPERTIES={'video':5,'audio':6,'eligible':15,'enabled':67,'pause_margin':68,'resume_margin':69,'absolute':70}
QUEUE,VTABLE=0x610000,0x611000
QPORTS={0xF00100:'available',0xF00110:'get',0xF00120:'unget'}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(joined.Machine):
    def __init__(self,case,worker,qualified):
        self.queues=copy.deepcopy(case['queues']);self.borrowed=[[] for _ in range(8)]
        super().__init__(case,worker,qualified)
        for start,end in INTERVALS.items():
            data=self.elf.read(start,end-start);self.body_ids[hex(start)+':'+hex(end)]=hashlib.sha256(data).hexdigest()
            for n in range(0,len(data),4):self.code[start+n]=struct.unpack_from('<I',data,n)[0]
        self.mem.span('queues',QUEUE,0x100,False,0);self.mem.span('queue_vtable',VTABLE,0x30,False,0)
        for offset,value in [(0x24,0xF00100),(0x18,0xF00110),(0x1C,0xF00120)]:self.mem.store(VTABLE+offset,4,value)
        for index in range(8):self.mem.store(QUEUE+index*16,4,VTABLE)
        self.configure(case['buffer_state']);self.initial=self.capture()

    def configure(self,state):
        main=joined.MAIN
        for name,index in PROPERTIES.items():self.mem.store(main+0x9A0+index*4,4,state[name])
        for offset,name in [(0x96C,'stalled'),(0x1B38,'video_slot'),(0x1B7C,'audio_slot')]:self.mem.store(main+offset,4,state[name])
        for index in range(8):
            for offset,value in [(0x1144,state['stream_enabled'][index]),(0x114C,state['ended'][index]),(0x1154,QUEUE+index*16 if state['present'][index] else 0),(0x115C,state['capacity'][index])]:self.mem.store(main+offset+index*0x74,4,value)
        for index,key,offset in [(6,'video_done',0x1AA4),(7,'audio_done',0x1AA4),(1,'component_one',0x1AAC)]:self.mem.store(main+offset+index*0x44,4,state[key])
        for n,value in enumerate(state['latest']):self.mem.store(joined.CLOCK+0x240+n*4,4,value)

    def capture(self):
        value=super().capture()
        # Additional observed fields are immutable during each admitted call;
        # the inherited main guard therefore still detects unexpected writes.
        value['queues']=copy.deepcopy(self.queues)
        return value

    def port(self,pc):
        if pc not in QPORTS:return super().port(pc)
        args=[value&0xFFFFFFFF for value in self.regs[4:8]]
        index=(args[0]-QUEUE)//16
        if not 0<=index<8 or args[0]!=QUEUE+index*16 or args[1]!=1:raise joined.OracleError('Queue identity/channel')
        kind=QPORTS[pc];queue=self.queues[index];returned=0
        self.events.append(dict(kind='queue_'+kind,slot=index,guard=[self.mem.load(joined.selected.GUARD,4),self.mem.load(joined.selected.GUARD+4,4)]))
        if kind=='available':returned=sum(queue)&0xFFFFFFFF
        elif kind=='get':
            if args[2]!=0x7FFFFFFF:raise joined.OracleError('Peek must request maximum span')
            length=queue.pop(0) if queue else 0
            token=0x620000+index*0x10000+len(self.borrowed[index])*0x1000 if length else 0
            self.mem.store(args[3],4,token);self.mem.store(args[3]+4,4,length);self.borrowed[index].append((token,length))
        else:
            token=self.mem.load(args[2],4);length=self.mem.load(args[2]+4,4)
            if not self.borrowed[index] or self.borrowed[index].pop()!=(token,length):raise joined.OracleError('Peek return order')
            if length:queue.insert(0,length)
        for register in [1,*range(2,16),24,25]:self.regs[register]=0xCDCD000000000000+register
        self.regs[2]=joined.sext32(returned);return self.regs[31]&0xFFFFFFFF


def corpus():
    base=joined.corpus()[0]
    cases=[]
    def add(name,kind='buffer',facts=None,state=None,queues=None,operations=None,**extra):
        case=copy.deepcopy(base);case['name']=name;case['facts'].update(facts or {});case.update(extra)
        initial=dict(video=0,audio=0,eligible=1,enabled=1,pause_margin=0,resume_margin=0,absolute=999,
                     stalled=1,video_slot=1,audio_slot=3,video_done=0,audio_done=0,component_one=0,
                     stream_enabled=[1]*8,ended=[0]*8,present=[1]*8,capacity=[100]*8,latest=[1000,48000])
        initial.update(state or {});case['facts']['selector']=initial['eligible'];case['buffer_state']=initial;case['queues']=copy.deepcopy(queues or [[] for _ in range(8)])
        case['operations']=operations or [joined.operation('refresh',1),joined.operation(kind,2)]
        cases.append(case)
    add('pause-then-resume',operations=[joined.operation('refresh',1),joined.operation('buffer',2),joined.operation('buffer',3)])
    for key in ['enabled','eligible']:
        for value in ([0,1,2,5] if key=='eligible' else [0,1,2,0xFFFFFFFF]):add(key+'-'+str(value),state={key:value})
    for value in [0,1,2,0xFFFFFFFF]:add('user-pause-'+str(value),facts={'pause':value})
    for actual in [0,3,4,6,0xFFFFFFFC]:add('actual-'+str(actual),facts={'actual':actual})
    for field in ['video','audio']:
        for prop in [0,1,2,0xFFFFFFFF]:
            for buffering in [0,1]:
                add(field+'-done-'+str(prop)+'-'+str(buffering),facts={'buffering':buffering,'depth':buffering},state={field:prop,field+'_done':9})
    for slot in range(8):
        for buffering in [0,1]:
            ended=[0]*8;ended[slot]=0xFFFFFFFF;add('end-'+str(slot)+'-'+str(buffering),facts={'buffering':buffering,'depth':buffering},state={'ended':ended})
    for video in [0,1,2]:
        for stalled in [0,1,2]:add('stall-'+str(video)+'-'+str(stalled),state={'video':video,'stalled':stalled})
    for slot,field in [(2,'audio'),(0,'component_one')]:
        for spans in [[],[1],[3,5],[3,5,7]]:
            queues=[[] for _ in range(8)];queues[slot]=spans
            add('peek-'+str(slot)+'-'+str(spans),state={field:1},queues=queues)
            disabled=[1]*8;disabled[slot]=0;add('disabled-peek-'+str(slot)+'-'+str(spans),state={field:1,'stream_enabled':disabled},queues=queues)
    for field,slot in [('video',1),('audio',3)]:
        for capacity in [100,0,0x7FFFFFFF,0x80000000,0xFFFFFFFF,53687092]:
            for available in [0,79,80,81,999]:
                queues=[[] for _ in range(8)];queues[slot]=[available] if available else [];caps=[100]*8;caps[slot]=capacity
                add('refill-'+field+'-'+str(capacity)+'-'+str(available),facts={'buffering':1,'depth':1},state={field:1,'capacity':caps},queues=queues)
    for buffering in [0,1]:
        for numerator,denominator in [(0,1),(1,48000),(1000,48000),(1600,48000),(1601,48000),(0xFFFFFFFF,1),(1,0xFFFFFFFF),(0x80000000,0x7FFFFFFF)]:
            for margin in [0,1,1000000,0xFFFFFFFF]:
                add('horizon-'+str(buffering)+'-'+str(numerator)+'-'+str(denominator)+'-'+str(margin),facts={'buffering':buffering,'depth':buffering},state={'latest':[numerator,denominator],'pause_margin':margin,'resume_margin':margin})
    for depth in [0,1,0xFFFFFFFF]:
        queues=[[] for _ in range(8)];queues[2]=[3,5,7]
        add('nested-guard-'+str(depth),state={'audio':1},queues=queues,guard_depth=depth,guard_tag=9)
    # Retain every first-pass input. Add explicit audio-clock workflows because
    # selector 1 is a counter clock whose fresh value is zero.
    extra=[]
    for case in cases:
        if case['buffer_state']['eligible']==1:
            item=copy.deepcopy(case);item['name']+='-audio-clock';item['facts']['selector']=2;item['buffer_state']['eligible']=2;extra.append(item)
    return cases+extra


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--worker-cohort',choices=['gcc','llvm'],required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned output required')
    frozen=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+args.worker_cohort+'-v3')
    authority=json.loads((frozen/'input-manifest.json').read_bytes());worker=frozen/'fp_worker.exe'
    if sha(worker)!=authority['fp_worker_sha256'] or sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Original worker/ELF drift')
    for path in [Path(authority['compiler']).parent]:joined.os.environ['PATH']=str(path)+joined.os.pathsep+joined.os.environ.get('PATH','')
    # Only this separate process uses the expanded profile. Earlier oracle and
    # its recorded cohorts remain unchanged.
    joined.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
    joined.PORTS.pop(0x172CF8);joined.PORTS.pop(0x172E78);joined.PORTS.update(QPORTS)
    out.mkdir(parents=True);cases=corpus();sources={str(p.relative_to(ROOT)):sha(p) for p in [Path(__file__),ROOT/'tools/native_reconstruction/movie_timing_context_oracle.py']}
    manifest=dict(schema=1,elf_sha256=authority['elf_sha256'],sources=sources,worker_receipt_sha256=sha(frozen/'receipt.json'),worker_sha256=sha(worker),cohort=args.worker_cohort,native_buffering_exists=(ROOT/'game/native/movie_timing_context/buffering.cpp').exists(),profile='Complete owned buffering bodies and peek closure; immutable movie facts, explicit bounded SJ queue methods, original clock/controller/guard.',game_run=False,device_opened=False)
    (out/'inputs.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8');(out/'input-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
    results=[];receipt={'status':'failed'}
    try:
        with joined.fp.FpuWorker(worker) as fpu:
            for case in cases:
                machine=Machine(case,fpu,set(joined.fp.fp_words().values()));rows=[machine.execute(op) for op in case['operations']]
                if machine.queues!=case['queues'] or any(machine.borrowed):raise joined.OracleError('Peek failed to restore queue')
                results.append(dict(name=case['name'],initial=machine.initial,operations=rows,instructions=machine.steps,body_identities=machine.body_ids))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8')
        receipt=dict(status='complete original buffering workflows returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json']},game_run=False,device_opened=False)
    except Exception as error:
        receipt['failure']=str(error);receipt['completed_cases']=len(results);raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({**{k:receipt[k] for k in ['status','cases','operations','instructions']},'receipt_sha256':sha(out/'receipt.json')}))


if __name__=='__main__':main()
