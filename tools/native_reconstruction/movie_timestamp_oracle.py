#!/usr/bin/env python3
"""Execute owned temporal-reference timestamp reconstruction before replacement."""
import argparse,copy,hashlib,json,os,struct
from pathlib import Path
import movie_timing_context_oracle as j
ROOT=j.ROOT;BASE=ROOT/'build-native-sjuni/movie-timestamp'
TEMP,META,STAMP=0x620000,0x620100,0x620200
RANGES={0x16D960:0x16DB20,0x107A18:0x107AB0}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
class Machine(j.Machine):
 def __init__(self,case,worker,words):
  self.timestamp_ready=False;super().__init__(case['timing'],worker,words);self.case=case
  for start,end in RANGES.items():
   raw=self.elf.read(start,end-start);self.body_ids[f'{start:x}:{end:x}']=hashlib.sha256(raw).hexdigest()
   for i in range(0,len(raw),4):self.code[start+i]=struct.unpack_from('<I',raw,i)[0]
  for name,base,length in [('temporal',TEMP,24),('metadata',META,64),('accounting',STAMP,12)]:self.mem.span(name,base,length,True,0)
  self.mem.store(j.CLOCK+0x114,4,case['baseline'])
  for i,v in enumerate(case['state']):self.mem.store(TEMP+i*4,4,v)
  self.timestamp_ready=True;self.initial=self.capture()
 def capture(self):
  if not self.timestamp_ready:return{}
  return dict(baseline=self.mem.load(j.CLOCK+0x114,4),state=self.mem.words(TEMP,6))
 def execute_timestamp(self,op):
  for offset,key in [(0x10,'rate'),(0x14,'reference'),(0x18,'kind')]:self.mem.store(META+offset,4,op[key])
  for i,v in enumerate(op['stamp']):self.mem.store(STAMP+4*i,4,v)
  before=self.capture();start=self.steps
  result=self.run_body(0x16D988,[j.CLOCK,TEMP,META,STAMP,op['changed']])&0xFFFFFFFF
  return dict(before=before,after=self.capture(),returned=result,instructions=self.steps-start)
def corpus():
 cases=[];timing=copy.deepcopy(j.corpus()[0])
 def add(name,ops,baseline=0xFFFFFFFF,state=None):cases.append(dict(name=name,timing=copy.deepcopy(timing),baseline=baseline,state=state or [0,0,0,0xFFFFFFFF,0,0xFFFFFFFF],operations=ops))
 def op(ref=0,rate=4,kind=1,stamp=0,changed=0,other=0):return dict(reference=ref&0xFFFFFFFF,rate=rate,kind=kind,stamp=[stamp&0xFFFFFFFF,other,other+17],changed=changed)
 for rate in range(9):
  for pts in [0,1,4500,0x7FFFFFFF,0x80000000,0xFFFFFFFF]:
   add(f'rate-{rate}-stamp-{pts}',[op(0,rate,1,pts),op(3,rate,2,pts),op(1,rate,3,pts),op(2,rate,3,pts),op(0,rate,1,pts,1),op(1,rate,2,pts)])
 for reference in [0,1,511,1023,0x7FFFFFFF,0x80000000,0xFFFFFFFF]:
  for baseline in [0xFFFFFFFF,0,10000]:
   add(f'baseline-{baseline}-ref-{reference}',[op(reference,kind=3,stamp=4500),op(reference+1,stamp=4500,changed=1)],baseline)
 for initial in [[0,0,0,17,2,3],[1023,0xFFFFFFFF,0x7FFFFFFF,17,2,3],[0x80000000,0x80000000,0xFFFFFFFF,17,2,3]]:
  add('wrap-'+str(len(cases)),[op(0,stamp=17),op(1,stamp=17,changed=1),op(4,stamp=18)],0,initial)
 add('compare-first-word-only',[op(0,stamp=100,other=1),op(1,stamp=100,other=100),op(4,stamp=101,other=100),op(0,stamp=101,changed=1)])
 for changed in [0,1,2,0xFFFFFFFF]:add('changed-'+str(changed),[op(0,stamp=0),op(4,kind=2,stamp=0),op(1,kind=3,stamp=0),op(0,stamp=0,changed=changed),op(4,stamp=0)])
 return cases
def main():
 p=argparse.ArgumentParser();p.add_argument('--cohort',choices=['gcc','llvm'],required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scope required')
 prior=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+a.cohort+'-v3');identity=json.loads((prior/'input-manifest.json').read_bytes());binary=prior/'fp_worker.exe';assert sha(binary)==identity['fp_worker_sha256']
 os.environ['PATH']=str(Path(identity['compiler']).parent)+os.pathsep+os.environ.get('PATH','');j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
 out.mkdir(parents=True);cases=corpus();record=dict(status='failed',native_exists=(ROOT/'game/native/movie_timestamp').exists(),elf_sha256=identity['elf_sha256'],worker_sha256=sha(binary),sources={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__)),Path(j.__file__).relative_to(ROOT).as_posix():sha(Path(j.__file__))});results=[]
 (out/'inputs.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8',newline='\n')
 try:
  with j.fp.FpuWorker(binary) as worker:
   for case in cases:
    m=Machine(case,worker,set(j.fp.fp_words().values()));ops=[m.execute_timestamp(op) for op in case['operations']];results.append(dict(name=case['name'],initial=m.initial,operations=ops,body_ids=m.body_ids,instructions=m.steps))
  (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');record.update(status='original temporal timestamps returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),game_run=False,device_opened=False)
 except Exception as error:record.update(failure=str(error),completed_cases=len(results));raise
 finally:
  record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps({k:v for k,v in record.items() if k not in ['sources','outputs_sha256']}))
if __name__=='__main__':main()
