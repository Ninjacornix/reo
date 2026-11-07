#!/usr/bin/env python3
"""Owned Sofdec lifecycle orchestration with explicit component/provider ports."""
import argparse,copy,hashlib,json,os,struct
from pathlib import Path
import movie_timing_context_oracle as j
ROOT=j.ROOT;BASE=ROOT/'build-native-sjuni/movie-lifecycle'
CONFIG=0x610000;REUSE=0x22F184;REGISTRY=0x22F18C;DEFAULTS=0x22EF88;TABLES=0x640000
RANGES={0x1734B8:0x1737A0,0x173990:0x173B00,0x173B28:0x173F90,0x1722C0:0x1722D0,0x177B48:0x177C30}
PORTS={0x1562D0:'zero',0x155E60:'copy',0x168F60:'header_init',0x1737A0:'metadata_init',0x173808:'metrics_init',0x173860:'statistics_init',0x169BF8:'error_init',0x175A50:'clock_init',0x166720:'streams_init',0x1775E0:'components_init',0x174518:'shared_init',0x168F78:'header_clear',0x1669E0:'streams_clear',0x167CE0:'stream_flag'}
ENTRY=dict(create=0x1734B8,start=0x173A70,stop=0x173B28,destroy=0x1739A8,rebuild=0x173C70,reset=0x173C10)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

class Machine(j.Machine):
    def __init__(self,case,worker,qualified):
        self.life_ready=False
        super().__init__(case['timing'],worker,qualified)
        self.case=case;self.invocations={}
        for start,end in RANGES.items():
            raw=self.elf.read(start,end-start);self.body_ids[f'{start:x}:{end:x}']=hashlib.sha256(raw).hexdigest()
            for n in range(0,len(raw),4):self.code[start+n]=struct.unpack_from('<I',raw,n)[0]
        for address,length,name in [(CONFIG,80,'config'),(REUSE,4,'reuse'),(REGISTRY,32,'registry'),(DEFAULTS,400,'defaults'),(TABLES,9*64,'component_methods')]:self.mem.span(name,address,length,True,0)
        self.defaults=list(struct.unpack('<100I',self.elf.read(DEFAULTS,400)))
        self.config=[0]*17;self.config[1]=0x680003 if case['source'] else 0;self.config[15]=j.MAIN;self.config[16]=case['workspace']
        for i,v in enumerate(self.config):self.mem.store(CONFIG+4*i,4,v);self.mem.store(j.MAIN+4*i,4,v)
        for i,v in enumerate(self.defaults):self.mem.store(DEFAULTS+4*i,4,v)
        for base,values in [(0x9A0,case['current']),(0xB30,case['saved'])]:
            for i,v in enumerate(values):self.mem.store(j.MAIN+base+4*i,4,v)
        for offset,key in [(0x48,'actual'),(0x4C,'requested'),(0x44,'pending'),(0x50,'pause'),(0x54,'depth')]:self.mem.store(j.MAIN+offset,4,case[key])
        self.mem.store(REUSE,4,case['reuse'])
        for i,v in enumerate(case['registry']):self.mem.store(REGISTRY+i*4,4,j.MAIN if v==1 else v*0x10000)
        self.install();self.life_ready=True;self.events=[];self.initial=self.capture()
    def install(self):
        for i in range(9):
            self.mem.store(j.MAIN+0x1AAC+68*i,4,TABLES+64*i if self.case['mask']&(1<<i) else 0)
            for cmd in range(16):self.mem.store(TABLES+64*i+cmd*4,4,0xF10000+i*256+cmd*4)
    def capture(self):
        if not self.life_ready:return {}
        return dict(actual=self.mem.load(j.MAIN+0x48,4),requested=self.mem.load(j.MAIN+0x4C,4),pending=self.mem.load(j.MAIN+0x44,4),pause=self.mem.load(j.MAIN+0x50,4),depth=self.mem.load(j.MAIN+0x54,4),reuse=self.mem.load(REUSE,4),current=self.mem.words(j.MAIN+0x9A0,100),saved=self.mem.words(j.MAIN+0xB30,100),registry=[1 if v==j.MAIN else v//0x10000 for v in self.mem.words(REGISTRY,8)])
    def port(self,pc):
        if not self.life_ready:return super().port(pc)
        args=[v&0xFFFFFFFF for v in self.regs[4:9]]
        if pc in [0x1562D0,0x155E60]:
            dst,source,count=args[:3]
            if pc==0x1562D0:self.mem.store(dst,count*4,0)
            else:self.mem.store(dst,count,self.mem.load(source,count))
            returned=dst
        else:
            component=-1;command=0;payload=[];target=0
            if 0xF10000<=pc<0xF10900:
                component=(pc-0xF10000)//256;command=((pc-0xF10000)%256)//4;kind=f'command-{component}-{command}'
                if command==9:target=args[1]
                if command==10:payload=args[1:3]
            else:kind=PORTS.get(pc,j.PORTS.get(pc))
            if kind is None:raise ValueError('Undeclared lifecycle port '+hex(pc))
            if kind=='error':payload=[args[1]]
            if kind=='stream_flag':payload=args[2:3]
            if kind in ['guard_enter','guard_leave']:payload=[]
            occurrence=self.invocations.get(kind,0);self.invocations[kind]=occurrence+1
            rule=self.operation.get('ports',{}).get(kind,{})
            returned=rule.get('returns',[0])[min(occurrence,len(rule.get('returns',[0]))-1)]
            self.events.append(dict(kind=kind,payload=payload,before=self.capture()))
            if kind=='streams_init':pass
            if kind=='components_init':self.install()
            if kind=='stream_flag':pass
            if target:
                value=rule.get('snapshot',[123,456])[min(occurrence,len(rule.get('snapshot',[123,456]))-1)]
                self.mem.store(target+20,4,value)
            for index,value in rule.get('current',{}).items():self.mem.store(j.MAIN+0x9A0+4*int(index),4,value)
            for index,value in rule.get('saved',{}).items():self.mem.store(j.MAIN+0xB30+4*int(index),4,value)
        for r in [1,*range(2,16),24,25]:self.regs[r]=0xCDCD000000000000+r
        self.regs[2]=j.sext32(returned);return self.regs[31]&0xFFFFFFFF
    def execute_life(self,op):
        self.operation=op;self.invocations={};before=self.capture();at=len(self.events);steps=self.steps
        result=self.run_body(ENTRY[op['kind']],[CONFIG,0] if op['kind']=='create' else [j.MAIN])&0xFFFFFFFF
        if op['kind']=='create':result=int(result!=0)
        return dict(before=before,after=self.capture(),returned=result,events=self.events[at:],instructions=self.steps-steps)

def corpus():
    timing=copy.deepcopy(j.corpus()[0]);cases=[]
    def add(name,ops,**changes):
        c=dict(name=name,timing=copy.deepcopy(timing),source=True,workspace=0x2BA0,actual=4,requested=4,pending=0,pause=1,depth=2,reuse=7,registry=[1,2,1,0,3,0,1,0],mask=511,current=[1000+i for i in range(100)],saved=[2000+i for i in range(100)],operations=ops)
        c['current'][8]=0;c.update(changes);cases.append(c);return c
    def op(kind,ports=None):return dict(kind=kind,ports=ports or {})
    for actual in [0,1,2,3,4,5,6,0xFFFFFFFF]:
        for kind in ['start','stop','reset','destroy','rebuild']:add(f'{kind}-state-{actual}',[op(kind)],actual=actual)
    for size in [0,0x2B9F,0x2BA0,0x2BA1,0x2BA3]:
        for source in [False,True]:add(f'create-{size}-{source}',[op('create')],workspace=size,source=source)
    for registry in [[2]*8,[0]*8,[2,2,0,2,0,2,2,2]]:add(f'create-slots-{len(cases)}',[op('create')],registry=registry)
    for kind in ['create','rebuild','stop','destroy']:
        for command in [3,4,7,9,10]:
            for node in [0,3,7,8]:
                c=add(f'{kind}-fail-{node}-{command}',[op(kind,{f'command-{node}-{command}':dict(returns=[17])})]);c['current'][8]=1
    for kind in ['create','stop','rebuild','destroy']:
        for mask in [0,1,128,256,129]:add(f'{kind}-mask-{mask}',[op(kind)],mask=mask)
    for prop in [0,1,2,0xFFFFFFFF]:
        c=add('start-prop-'+str(prop),[op('start')]);c['current'][47]=prop
    for reuse in [0,1,7]:
        for snap in [0,1,2]:
            c=add(f'stop-reuse-{reuse}-snapshot-{snap}',[op('stop')],reuse=reuse);c['current'][8]=snap
    for kind in ['create','stop','rebuild']:
        for helper in ['streams_init','components_init']:
            add(kind+'-'+helper+'-fail',[op(kind,{helper:dict(returns=[23])})])
    c=add('restore-after-callbacks',[op('stop',{'command-0-4':dict(saved={'9':0xBEEF}),'command-0-3':dict(current={'9':0xDEAD},saved={'9':0xFEED})})]);c['current'][8]=1
    c=add('snapshot-first-error-ignored',[op('stop',{'command-0-9':dict(returns=[19,0],snapshot=[123,456])})]);c['current'][8]=1
    c=add('snapshot-second-error-propagates',[op('stop',{'command-0-9':dict(returns=[0,19],snapshot=[123,456])})]);c['current'][8]=1
    add('create-start-stop-destroy',[op('create'),op('start'),op('stop'),op('destroy')],registry=[0]*8)
    return cases

def main():
    p=argparse.ArgumentParser();p.add_argument('--cohort',choices=['gcc','llvm'],required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh output required')
    frozen=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+a.cohort+'-v3');identity=json.loads((frozen/'input-manifest.json').read_bytes());worker=frozen/'fp_worker.exe'
    if sha(worker)!=identity['fp_worker_sha256']:raise ValueError('Qualified worker drift')
    os.environ['PATH']=str(Path(identity['compiler']).parent)+os.pathsep+os.environ.get('PATH','');j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
    j.PORTS.update(PORTS)
    # Execute the real indexed component dispatcher, replacing only its actual
    # installed virtual-method targets. The earlier clock oracle ports this
    # dispatcher for its narrower query profile.
    del j.PORTS[0x177BE0]
    for i in range(9):
        for cmd in range(16):j.PORTS[0xF10000+i*256+cmd*4]='component'
    out.mkdir(parents=True);cases=corpus();record=dict(status='failed',native_lifecycle_exists=(ROOT/'game/native/movie_lifecycle').exists())
    (out/'inputs.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8')
    record.update(elf_sha256=identity['elf_sha256'],worker_sha256=sha(worker),sources={str(Path(__file__).relative_to(ROOT)).replace('\\','/'):sha(Path(__file__))})
    results=[]
    try:
        with j.fp.FpuWorker(worker) as fp:
            for case in cases:
                machine=Machine(case,fp,set(j.fp.fp_words().values()));rows=[machine.execute_life(op) for op in case['operations']];results.append(dict(name=case['name'],initial=machine.initial,operations=rows,body_ids=machine.body_ids,instructions=machine.steps))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8');record.update(status='original lifecycle orchestration returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),game_run=False,device_opened=False)
    except Exception as error:record.update(failure=str(error),completed_cases=len(results));raise
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in record.items() if k not in ['sources','outputs_sha256']}))
if __name__=='__main__':main()
