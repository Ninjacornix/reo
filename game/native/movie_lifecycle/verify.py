#!/usr/bin/env python3
"""Compare native lifecycle orchestration to frozen owned original transcripts."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-lifecycle'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def state(s):return [s[k] for k in ['actual','requested','pending','pause','depth','reuse']]+s['current']+s['saved']+s['registry']
def main():
 p=argparse.ArgumentParser();p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=shutil.which(a.cxx)
 if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Compiler/fresh scope required')
 cohorts=[];original_receipts={}
 for tag in ['gcc','llvm']:
  folder=BASE/('original-'+tag+'-v2');r=json.loads((folder/'receipt.json').read_bytes());assert not r['native_lifecycle_exists'] and r['status']=='original lifecycle orchestration returned'
  for name,digest in r['outputs_sha256'].items():assert sha(folder/name)==digest
  for name,digest in r['sources'].items():assert sha(ROOT/name)==digest
  cohorts.append((json.loads((folder/'inputs.json').read_bytes()),json.loads((folder/'original.json').read_bytes())));original_receipts[tag]=sha(folder/'receipt.json')
 assert cohorts[0]==cohorts[1]
 cases,original=cohorts[0];names=sorted({e['kind'] for r in original for op in r['operations'] for e in op['events']})
 import sys;sys.path.insert(0,str(ROOT/'tools/native_reconstruction'));from sjuni_oracle import Elf
 import struct
 defaults=struct.unpack('<100I',Elf(ROOT/'game_data/SLUS_207.65').read(0x22EF88,400))
 lines=[str(len(names)),*names,' '.join(map(str,defaults))];expected=[]
 def row(identity,index,s,returned,events):
  values=[returned,1]+state(s)+[len(events)]
  for e in events:values += [names.index(e['kind']),len(e['payload'])]+e['payload']+state(e['before'])
  expected.append('row '+str(identity)+' '+str(index)+' '+' '.join(map(str,values)))
 for identity,(case,result) in enumerate(zip(cases,original,strict=True)):
  lines.append(' '.join(map(str,[identity,int(case['source']),case['workspace'],case['mask'],int(case['timing']['hooks'])]+state(result['initial']))));row(identity,-1,result['initial'],0,[]);lines.append(str(len(case['operations'])))
  for i,(op,evidence) in enumerate(zip(case['operations'],result['operations'],strict=True)):
   lines.append(str(['create','start','stop','destroy','rebuild','reset'].index(op['kind']))+' '+str(len(op['ports'])))
   for name,rule in op['ports'].items():
    words=[name]
    for key in ['returns','snapshot']:
     values=rule.get(key,[]);words += [str(len(values)),*map(str,values)]
    for key in ['current','saved']:
     values=rule.get(key,{});words.append(str(len(values)))
     for k,v in values.items():words += [str(k),str(v)]
    lines.append(' '.join(words))
   row(identity,i,evidence['after'],evidence['returned'],evidence['events'])
 out.mkdir(parents=True);plan='\n'.join(lines)+'\n';(out/'plan.txt').write_text(plan,encoding='utf-8');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
 source_paths=[HERE/'policy.cpp',HERE/'policy.hpp',HERE/'fixture.cpp',Path(__file__),ROOT/'tools/native_reconstruction/movie_lifecycle_oracle.py'];sources={str(s.relative_to(ROOT)).replace('\\','/'):sha(s) for s in source_paths}
 report=dict(status='running',compiler=cc,compiler_sha256=sha(Path(cc)),sources=sources,original_receipts=original_receipts,cases=len(cases),operations=sum(len(c['operations']) for c in cases),rows=len(expected),negative_controls=[])
 def run(label,args,stdin=None):
  r=subprocess.run(args,input=stdin,text=True,capture_output=True,env=env,timeout=90);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8')
  if r.returncode:raise ValueError(label+' failed: '+r.stderr[:1500])
  return r.stdout
 def compare(label,source):
  binary=out/(label+'.exe');run(label+'-compile',[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE),str(source),str(HERE/'fixture.cpp'),'-o',str(binary)])
  actual=run(label,[str(binary)],plan).splitlines();assert len(actual)==len(expected)
  diff=[dict(row=i,expected=e,actual=v) for i,(e,v) in enumerate(zip(expected,actual)) if e!=v];(out/(label+'-differences.json')).write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8');return len(diff)
 try:
  report['native_differences']=compare('native',HERE/'policy.cpp');assert not report['native_differences'],'Native transcript differs'
  body=(HERE/'policy.cpp').read_text(encoding='utf-8')
  for name,old,new in [('start-nonzero-property','state_.current[47]==1?3:4','state_.current[47]!=0?3:4'),('stop-not-state-one','state_.actual==1)return 0','state_.actual!=0)return 0'),('restore-prior-reuse','state_.reuse=0;','state_.reuse=7;'),('stop-error-ignored','const auto result=reset();if(result)return result;','const auto result=reset();(void)result;'),('omit-property-restore','state_.current=saved;state_.saved=saved;','(void)saved;'),('preserve-state-on-destroy','state_.actual=0;state_.requested=0;return broadcast(4);','return broadcast(4);'),('remove-only-first-slot','for(auto& entry:state_.registry)if(entry==1)entry=0;','for(auto& entry:state_.registry)if(entry==1){entry=0;break;}'),('check-first-snapshot-error','if(!old.snapshot_written)','if(old.status || !old.snapshot_written)')]:
   assert old in body,name
   source=out/(name+'.cpp');source.write_text(body.replace(old,new),encoding='utf-8');count=compare(name,source);assert count,name;report['negative_controls'].append(dict(name=name,differing_rows=count))
  assert all(sha(ROOT/name)==digest for name,digest in sources.items())
  report['status']='qualified native movie lifecycle orchestration'
 except Exception as error:report.update(status='failed',failure=str(error));raise
 finally:
  report['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ['.txt','.json','.cpp']};(out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
 print(json.dumps({k:report[k] for k in ['status','cases','operations','rows','native_differences']}))
if __name__=='__main__':main()
