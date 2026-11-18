#!/usr/bin/env python3
"""Execute owned Sofdec pending-service dispatch and state transition bodies."""
import argparse,copy,hashlib,json,os,struct
from pathlib import Path
import movie_timecode_oracle as base
j=base.j;ROOT=j.ROOT;BASE=ROOT/'build-native-sjuni/movie-service'
TABLE=0x240AD0;SHARED=0x650000
RANGES={0x1725E0:0x172C48,0x173210:0x1732D8,0x174848:0x174878,0x175460:0x175588,0x175628:0x175638,0x177C48:0x177C90}
PORTS={0x17E870:'counter',0x172720:'broadcast',0x174878:'shared',0x167548:'extent',0x167528:'requested_count',0x173B00:'start',0x173130:'end_transition',0x172C48:'buffer_pause',0x177470:'statistics'}
OFFSETS={'actual':0x48,'requested':0x4C,'pending':0x44,'buffered':0xF2C,'threshold':0xF48}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

class Machine(base.Machine):
    def __init__(self,case,worker,words):
        self.service_ready=False
        super().__init__(copy.deepcopy(base.corpus()[0]),worker,words)
        self.case=case;self.events=[];self.invocations={}
        for start,end in RANGES.items():
            raw=self.elf.read(start,end-start);self.body_ids[f'{start:x}:{end:x}']=hashlib.sha256(raw).hexdigest()
            for n in range(0,len(raw),4):self.code[start+n]=struct.unpack_from('<I',raw,n)[0]
        self.mem.span('service_dispatch',TABLE,28,False,0)
        self.mem.store(TABLE,28,int.from_bytes(self.elf.read(TABLE,28),'little'))
        self.mem.span('shared_source_flags',SHARED,0xDB0,True,0)
        self.mem.store(j.MAIN+0x2AB0,4,SHARED)
        self.write(case['state']);self.service_ready=True;self.initial=self.capture()
    def write(self,state):
        for key,offset in OFFSETS.items():
            if key in state:self.mem.store(j.MAIN+offset,4,state[key])
        for index,value in state.get('properties',{}).items():self.mem.store(j.MAIN+0x9A0+4*int(index),4,value)
        for index,value in enumerate(state.get('cached',[])):
            component=6+index//2;offset=[0,4][index%2]
            self.mem.store(j.MAIN+0x1AA0+68*component+offset,4,value)
        for index,value in enumerate(state.get('shared',[])):self.mem.store(SHARED+0xDA4+4*index,4,value)
    def capture(self):
        if not self.service_ready:return {}
        return {**{k:self.mem.load(j.MAIN+v,4) for k,v in OFFSETS.items()},'properties':self.mem.words(j.MAIN+0x9A0,100),'cached':[self.mem.load(j.MAIN+0x1AA0+68*c+o,4) for c in [6,7] for o in [0,4]],'shared':self.mem.words(SHARED+0xDA4,2)}
    def port(self,pc):
        if not self.service_ready:return super().port(pc)
        kind=PORTS.get(pc)
        if kind is None:return super().port(pc)
        index=self.invocations.get(kind,0);self.invocations[kind]=index+1
        rule=self.operation.get('ports',{}).get(kind,{})
        choices=rule.get('returns',[100+index] if kind=='counter' else [0])
        returned=choices[min(index,len(choices)-1)]
        args=[]
        if kind in ['extent','requested_count']:args=[self.regs[5]&0xFFFFFFFF]
        if kind=='statistics':args=[self.regs[5]&0xFFFFFFFFFFFFFFFF]
        self.events.append(dict(kind=kind,args=args,before=self.capture(),returned=returned))
        self.write(rule.get('write',{}))
        for r in [1,*range(2,16),24,25]:self.regs[r]=0xCDCD000000000000+r
        self.regs[2]=returned if kind=='counter' else j.sext32(returned)
        return self.regs[31]&0xFFFFFFFF
    def execute(self,op):
        self.operation=op;self.invocations={};self.write(op.get('write',{}));at=len(self.events);before=self.capture();steps=self.steps
        self.run_body(0x1725E0,[j.MAIN])
        return dict(before=before,after=self.capture(),events=self.events[at:],instructions=self.steps-steps)

def corpus():
    cases=[]
    def add(name,**changes):
        state=dict(actual=2,requested=4,pending=1,buffered=0,threshold=0,properties={str(i):0 for i in range(100)},cached=[1,0,1,0],shared=[0xFFFFFFFF,0xFFFFFFFF])
        state['properties'].update({'5':1,'6':1,'14':0,'15':2,'25':0,'45':1})
        state.update(changes);case=dict(name=name,state=state,operations=[{}]);cases.append(case);return case
    for actual in [0,1,2,3,4,5,6,7,0xFFFFFFFF]:
        for pending in [0,1,2]:
            for requested in [0,1,2,3,4,5,6,7,0xFFFFFFFF]:add(f'states-{actual}-{pending}-{requested}',actual=actual,pending=pending,requested=requested)
    for video in [0,1,2,0xFFFFFFFF]:
        for audio in [0,1,2,0xFFFFFFFF]:
            for selector in [0,1,2,3]:
                case=add(f'prepare-{video}-{audio}-{selector}')
                case['state']['properties'].update({'5':video,'6':audio,'15':selector})
    for cached in [[0,0,0,0],[0,1,0,1],[0,0,1,1],[1,1,0,0],[2,0,0xFFFFFFFF,0]]:
        add('cached-'+str(cached),cached=cached)
    for flags in [(0,0),(1,0),(0,1),(1,1),(2,2)]:
        for policy in [0,1,2,3,4,0xFFFFFFFF]:
            for done in [(0,0),(1,0),(0,1),(1,1),(2,1)]:
                case=add(f'start-gate-{flags}-{policy}-{done}',threshold=0)
                case['state']['properties'].update({'5':flags[0],'6':flags[1],'14':1,'25':policy,'45':1})
                case['state']['cached']=[1,done[0],1,done[1]]
    for port in ['broadcast','shared','counter','start','end_transition','buffer_pause']:
        for actual in [1,2,3,4,5,6,7,0xFFFFFFFF]:
            case=add(f'callback-{port}-{actual}',actual=4 if port in ['end_transition','buffer_pause'] else 2)
            case['operations']=[dict(ports={port:dict(write=dict(actual=actual,requested=6,pending=7),returns=[1] if port in ['end_transition','buffer_pause'] else [0])})]
    for counts in [[0],[1],[0,1],[1,0]]:
        case=add('extents-'+str(counts));case['operations']=[dict(ports={'extent':dict(returns=counts),'requested_count':dict(returns=counts)})]
    case=add('pending-consumed-before-work');case['operations']=[dict(ports={'broadcast':dict(write=dict(pending=1))}),{},dict(write=dict(pending=1,requested=6)),{}]
    return cases

def main():
    p=argparse.ArgumentParser();p.add_argument('--cohort',choices=['gcc','llvm'],required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned scope required')
    prior=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+a.cohort+'-v3');identity=json.loads((prior/'input-manifest.json').read_bytes());binary=prior/'fp_worker.exe'
    if sha(binary)!=identity['fp_worker_sha256']:raise ValueError('Worker drift')
    os.environ['PATH']=str(Path(identity['compiler']).parent)+os.pathsep+os.environ.get('PATH','')
    j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
    j.PORTS.update(PORTS)
    out.mkdir(parents=True);cases=corpus();record=dict(status='failed',native_service_exists=(ROOT/'game/native/movie_service/service.cpp').exists(),elf_sha256=identity['elf_sha256'],worker_sha256=sha(binary),sources={p.relative_to(ROOT).as_posix():sha(p) for p in [Path(__file__),Path(base.__file__),Path(base.temporal.__file__),Path(j.__file__)]});results=[]
    (out/'inputs.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8',newline='\n')
    try:
        with j.fp.FpuWorker(binary) as worker:
            for case in cases:
                machine=Machine(case,worker,set(j.fp.fp_words().values()));operations=[machine.execute(op) for op in case['operations']]
                results.append(dict(name=case['name'],initial=machine.initial,operations=operations,body_ids=machine.body_ids,instructions=machine.steps))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');record.update(status='owned pending service and transitions executed',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),game_run=False,device_opened=False)
    except Exception as error:record.update(failure=str(error),completed_cases=len(results));raise
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:v for k,v in record.items() if k not in ['sources','outputs_sha256']}))

if __name__=='__main__':main()
