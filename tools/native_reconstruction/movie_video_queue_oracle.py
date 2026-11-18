#!/usr/bin/env python3
"""Execute original picture-pool ordering/lifetime and clock-admission bodies."""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import struct
import movie_timing_context_oracle as j
ROOT=j.ROOT;BASE=ROOT/'build-native-sjuni/movie-video-frames';BACKEND=0x620000
RANGES={0x170630:0x1706D0,0x170710:0x170738,0x170738:0x170760,0x170760:0x170848,0x170848:0x170980,0x170980:0x1709A0}
ENTRIES=dict(reserve=0x170630,release=0x170710,demote=0x170738,front=0x170760,advance=0x170848)
PUBLIC_RANGES={0x16FF20:0x16FFC0,0x16FFC0:0x1700D0,0x170518:0x170590,0x170590:0x170630,
               0x178F58:0x178FD0,0x176F30:0x176F68,0x1700D0:0x170120,0x170120:0x1701F0,
               0x1701F0:0x1701F8,0x1704D0:0x170518}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

class Machine(j.Machine):
    def __init__(self,case,worker,words):
        self.pool_ready=False;super().__init__(case,worker,words)
        for start,end in (RANGES|(PUBLIC_RANGES if case.get('public_profile') else {})).items():
            raw=self.elf.read(start,end-start);self.body_ids[hex(start)+':'+hex(end)]=hashlib.sha256(raw).hexdigest()
            for n in range(0,len(raw),4):self.code[start+n]=struct.unpack_from('<I',raw,n)[0]
        self.mem.span('video_backend',BACKEND,0xA00,True,0);self.mem.store(j.MAIN+0x1B30,4,BACKEND)
        self.mem.store(BACKEND+0x138,4,len(case['pictures']));self.mem.store(BACKEND+0x7C,4,case['end'])
        for index,picture in enumerate(case['pictures']):
            for offset,key in [(0,'state'),(4,'references'),(12,'numerator'),(16,'denominator')]:self.mem.store(BACKEND+0x13C+index*128+offset,4,picture[key])
            if case.get('public_profile'):self.mem.store(j.MAIN+0x14E0+index*92,4,0)
        self.pool_ready=True;self.initial=self.capture()
    def capture(self):
        value=super().capture()
        if self.pool_ready:
            value['pictures']=[self.mem.words(BACKEND+0x13C+i*128,5) for i in range(len(self.case['pictures']))]
            if self.case.get('public_profile'):
                value['public_valid']=[self.mem.load(j.MAIN+0x14E0+i*92,4) for i in range(len(self.case['pictures']))]
                current=self.mem.load(BACKEND+0x70,4);value['current']=-1 if not current else (current-BACKEND-0x13C)//128
        return value
    def port(self,pc):
        if pc==0x167BD8:
            # Source-selection transport boundary only; actual public get and
            # its pool/map/copy/clock writes run from the owned instructions.
            self.regs[5]=self.regs[6];return 0x16FF20
        return super().port(pc)
    def execute_pool(self,op):
        self.operation=op
        for name,value in op['facts'].items():self.mem.store(j.MAIN+j.FACTS[name],4,value)
        self.mem.store(j.ADXT+1,1,op['adxt_status']);self.mem.store(j.HELPER_FREQUENCY,8,op['helper_frequency'])
        before=self.capture();events=len(self.events);start=self.steps;kind=op['kind']
        address=BACKEND+0x13C+op['slot']*128 if op['slot']>=0 else 0
        if kind=='get':
            self.run_body(0x178F58,[j.MAIN,j.OUT]);body=self.mem.load(j.OUT,4);returned=-1 if not body else (body-j.MAIN-0x14E4)//92
        elif kind=='public_release':returned=self.run_body(0x1700D0,[j.MAIN,j.MAIN+0x14E4+op['slot']*92])
        elif kind=='skip':
            returned=self.run_body(0x170848,[j.MAIN])
            if returned:
                self.run_body(0x16FF20,[j.MAIN,j.OUT]);self.run_body(0x1700D0,[j.MAIN,self.mem.load(j.OUT,4)])
                returned=1
        elif kind in ['pause','tick']:
            returned=self.run_body(j.ENTRIES[kind],[j.MAIN,op['value']] if kind=='pause' else [j.MAIN])
        else:returned=self.run_body(ENTRIES[kind],[address] if kind in ['release','demote'] else [j.MAIN,j.OUT] if kind=='front' else [j.MAIN])
        if kind in ['reserve','front']:returned=-1 if returned==0 else (returned-(BACKEND+0x13C))//128
        return dict(operation=op,before=before,after=self.capture(),returned=returned if kind in ['reserve','front','get'] else returned&0xFFFFFFFF,flag=self.mem.load(j.OUT,4) if kind=='front' else 0,events=self.events[events:],instructions=self.steps-start)

def op(kind,slot=-1,**kw):
    value=j.operation(kind,1);value['slot']=slot;value.update(kw);return value
def corpus():
    base=j.corpus()[0];cases=[]
    def add(name,pictures,ops=None,**kw):
        c=copy.deepcopy(base);c.update(name=name,pictures=[dict(state=s,references=r,numerator=n&0xFFFFFFFF,denominator=d&0xFFFFFFFF) for s,r,n,d in pictures],end=0,operations=ops or [op('front'),op('advance'),op('reserve')]);c.update(kw);cases.append(c);return c
    for count in [0,1,2,3,16]:
        for state in [0,1,2,3,4,5]:
            for refs in [0,1,0xFFFFFFFF]:add(f'count{count}-state{state}-refs{refs}',[(state,refs,i*1600,48000) for i in range(count)])
    for stamps in [[3200,0,1600],[1600,1600,1600],[-1,0,-2],[0x80000000,0x7FFFFFFF,0],[1,2,3]]:
        for actual in [0,3,4,6]:
            for selector in [0,1,2,5]:
                c=add('ordering-'+str(len(cases)),[(2,0,n,[1,48000,90000][i]) for i,n in enumerate(stamps)]);c['facts'].update(actual=actual,selector=selector)
    for end in [0,1,2,0xFFFFFFFF]:
        for states in [[2],[4],[2,4],[3,1]]:add('end-'+str(len(cases)),[(s,0,1000,48000) for s in states],end=end)
    for state in range(6):add('release-demote-'+str(state),[(state,9,0,48000)],[op('release',0),op('demote',0),op('reserve')])
    for query in [0,800,1599,1600,1601,3200,-2]:
        c=add('counter-step-'+str(query),[(2,0,0,48000),(4,0,query,48000)],[op('advance'),op('front')]);c['facts'].update(selector=1)
    # Post-candidate joined public get/release cases. Earlier 199 inputs and
    # complete original outputs remain unchanged; the larger profile is explicit.
    for stamps in [[0,1600,3200],[3200,0,1600],[-2,1600,1600],[1,1,1],[-2,0,1600]]:
        for actual in [0,3,4]:
            c=add('public-'+str(len(cases)),[(2,0,n,48000) for n in stamps],[op('get'),op('skip'),op('get')],public_profile=True);c['facts'].update(actual=actual,selector=1)
    for state in [2,4]:
        c=add('public-release-'+str(state),[(state,0,0,48000)],[op('get'),op('public_release',0),op('front')],public_profile=True);c['facts']['selector']=1
    c=add('public-paused-frame-step',[(2,0,0,48000),(4,0,1600,48000),(2,0,3200,48000)],
          [op('get'),op('public_release',0),op('pause',value=1),op('get'),op('pause',value=2),op('get'),op('public_release',1),op('pause',value=2),op('get'),op('pause',value=0)],public_profile=True)
    c['facts']['selector']=1
    c=add('public-paused-cached-step',[(2,0,0,48000),(2,0,1600,48000)],
          [op('get'),op('public_release',0),op('pause',value=1),op('tick'),op('get'),op('pause',value=2),op('get'),op('tick'),op('get'),op('public_release',1),op('pause',value=0)],public_profile=True)
    c['facts']['selector']=1
    return cases
def main():
    p=argparse.ArgumentParser();p.add_argument('--worker-cohort',choices=['gcc','llvm'],required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh output required')
    frozen=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+args.worker_cohort+'-v3');authority=json.loads((frozen/'input-manifest.json').read_bytes());worker=frozen/'fp_worker.exe'
    if sha(worker)!=authority['fp_worker_sha256'] or sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('ELF/worker identity')
    j.os.environ['PATH']=str(Path(authority['compiler']).parent)+j.os.pathsep+j.os.environ.get('PATH','');j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
    j.PORTS[0x167BD8]='video_source'
    out.mkdir(parents=True);cases=corpus();manifest=dict(elf_sha256=authority['elf_sha256'],sources={str(p.relative_to(ROOT)):sha(p) for p in [Path(__file__),Path(j.__file__)]},native_video_exists=(ROOT/'game/native/movie_timing_context/video_frames.cpp').exists(),worker_sha256=sha(worker),game_run=False,device_opened=False)
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')
    results=[];receipt=dict(status='failed')
    try:
        with j.fp.FpuWorker(worker) as fp:
            for case in cases:
                machine=Machine(case,fp,set(j.fp.fp_words().values()));rows=[machine.execute_pool(o) for o in case['operations']];results.append(dict(name=case['name'],initial=machine.initial,operations=rows,body_identities=machine.body_ids,instructions=machine.steps))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8');receipt=dict(status='original video queue and clock workflows returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),outputs_sha256={n:sha(out/n) for n in ['inputs.json','input-manifest.json','original.json']},game_run=False,device_opened=False)
    except Exception as error:receipt.update(failure=str(error),completed_cases=len(results));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(receipt|{'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
