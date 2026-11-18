#!/usr/bin/env python3
"""Original timestamp-reconstruction comparison and deliberate fault checks."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-timestamp';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def flat(state):return [state['baseline']]+state['state']
def main():
 p=argparse.ArgumentParser();p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=shutil.which(a.cxx)
 if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Compiler/fresh scope required')
 cohorts=[];receipts={}
 for tag in ['gcc','llvm']:
  folder=BASE/('original-'+tag+'-v1');r=json.loads((folder/'receipt.json').read_bytes());assert not r['native_exists'] and r['status']=='original temporal timestamps returned'
  for name,digest in r['outputs_sha256'].items():assert sha(folder/name)==digest
  for name,digest in r['sources'].items():assert sha(ROOT/name)==digest
  cohorts.append((json.loads((folder/'inputs.json').read_bytes()),json.loads((folder/'original.json').read_bytes())));receipts[tag]=sha(folder/'receipt.json')
 assert cohorts[0]==cohorts[1];cases,original=cohorts[0];lines=[];expected=[]
 for identity,(case,result) in enumerate(zip(cases,original,strict=True)):
  lines.append(' '.join(map(str,[identity]+flat(result['initial'])+[len(case['operations'])])));expected.append('row '+str(identity)+' -1 0 '+' '.join(map(str,flat(result['initial']))))
  for index,(op,evidence) in enumerate(zip(case['operations'],result['operations'],strict=True)):
   lines.append(' '.join(map(str,[op[k] for k in ['rate','reference','kind','changed']]+op['stamp'])));expected.append('row '+str(identity)+' '+str(index)+' '+str(evidence['returned'])+' '+' '.join(map(str,flat(evidence['after']))))
 out.mkdir(parents=True);plan='\n'.join(lines)+'\n';(out/'plan.txt').write_text(plan,encoding='utf-8',newline='\n');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
 paths=[HERE/'timestamp.cpp',HERE/'timestamp.hpp',HERE/'fixture.cpp',Path(__file__),ROOT/'tools/native_reconstruction/movie_timestamp_oracle.py'];sources={p.relative_to(ROOT).as_posix():sha(p) for p in paths};report=dict(status='running',sources=sources,compiler=cc,compiler_sha256=sha(Path(cc)),original_receipts=receipts,cases=len(cases),operations=sum(len(c['operations']) for c in cases),rows=len(expected),negative_controls=[])
 def compare(label,source):
  exe=out/(label+'.exe');compile=subprocess.run([cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE),str(source),str(HERE/'fixture.cpp'),'-o',str(exe)],capture_output=True,text=True,env=env);(out/(label+'-compile.txt')).write_text(compile.stdout+compile.stderr,encoding='utf-8',newline='\n');assert not compile.returncode,compile.stderr
  value=subprocess.run([str(exe)],input=plan,capture_output=True,text=True,env=env,timeout=30);(out/(label+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8',newline='\n');assert not value.returncode,value.stderr
  rows=value.stdout.splitlines();assert len(rows)==len(expected);diff=[dict(row=i,expected=e,actual=v) for i,(e,v) in enumerate(zip(expected,rows)) if e!=v];(out/(label+'-differences.json')).write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8',newline='\n');return len(diff)
 try:
  report['native_differences']=compare('native',HERE/'timestamp.cpp');assert not report['native_differences']
  body=(HERE/'timestamp.cpp').read_text(encoding='utf-8')
  for label,old,new in [('round-instead-of-truncate','*22500000)/rate','*22500000+rate/2)/rate'),('rebase-on-every-picture','state.cached.value!=input.stamp.value','true'),('drop-baseline-clamp','state.baseline=positive(input.stamp.value-convert(input.reference,rate))','state.baseline=input.stamp.value-convert(input.reference,rate)'),('changed-exactly-one','if(input.changed)','if(input.changed==1)'),('omit-maximum-plus-one','state.base+=state.maximum+1','state.base+=state.maximum'),('lose-b-picture-offset','state.maximum=input.kind==3?1:0','state.maximum=0')]:
   assert old in body,label
   source=out/(label+'.cpp');source.write_text(body.replace(old,new),encoding='utf-8',newline='\n');different=compare(label,source);assert different,label;report['negative_controls'].append(dict(name=label,differing_rows=different))
  for name,digest in sources.items():assert sha(ROOT/name)==digest
  report['status']='qualified native temporal timestamps'
 except Exception as error:report.update(status='failed',failure=str(error));raise
 finally:
  report['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ['.txt','.json','.cpp']};(out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps({k:report[k] for k in ['status','cases','operations','rows','native_differences']}))
if __name__=='__main__':main()
