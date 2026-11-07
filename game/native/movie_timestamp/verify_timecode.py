#!/usr/bin/env python3
"""Compare complete native timecode policy to independent owned-word execution."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-timecode';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def flat(s):return [s['temporal']['baseline']]+s['temporal']['state']+[s['property34']]+s['first']+s['latest']+s['current']+s['metadata']
def main():
 p=argparse.ArgumentParser();p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=shutil.which(a.cxx)
 if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Compiler/fresh scope required')
 cohorts=[];receipts={}
 for tag in ['gcc','llvm']:
  folder=BASE/('original-'+tag+'-v6');r=json.loads((folder/'receipt.json').read_bytes());assert not r['native_flow_exists'] and r['status']=='original joined timecodes returned'
  for name,digest in r['outputs_sha256'].items():assert sha(folder/name)==digest
  for name,digest in r['sources'].items():assert sha(ROOT/name)==digest
  cohorts.append((json.loads((folder/'inputs.json').read_bytes()),json.loads((folder/'original.json').read_bytes())));receipts[tag]=sha(folder/'receipt.json')
 assert cohorts[0]==cohorts[1];cases,original=cohorts[0];lines=[];expected=[]
 for identity,(case,result) in enumerate(zip(cases,original,strict=True)):
  initial=result['initial']['temporal'];lines.append(' '.join(map(str,[identity,initial['baseline']]+initial['state']+[len(case['operations'])])));expected.append('row '+str(identity)+' -1 4294967295 '+' '.join(map(str,flat(result['initial']))))
  for index,(op,evidence) in enumerate(zip(case['operations'],result['operations'],strict=True)):
   words=[op[k] for k in ['rate','reference','kind','drop','hours','minutes','seconds','frames','gop','changed']]+[int(op['stamp'] is not None),op['stamp'] or 0,op['begin'],op['bytes']]
   lines.append(' '.join(map(str,words)));expected.append('row '+str(identity)+' '+str(index)+' '+str(evidence['stamp'])+' '+' '.join(map(str,flat(evidence['after']))))
 out.mkdir(parents=True);plan='\n'.join(lines)+'\n';(out/'plan.txt').write_text(plan,encoding='utf-8',newline='\n');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
 paths=[HERE/name for name in ['timecode.cpp','timecode.hpp','timestamp.cpp','timestamp.hpp','timecode_fixture.cpp','verify_timecode.py']]+[ROOT/'tools/native_reconstruction/movie_timecode_oracle.py'];sources={p.relative_to(ROOT).as_posix():sha(p) for p in paths};report=dict(status='running',sources=sources,compiler=cc,compiler_sha256=sha(Path(cc)),original_receipts=receipts,cases=len(cases),operations=sum(len(c['operations']) for c in cases),rows=len(expected),negative_controls=[])
 def compare(label,source):
  exe=out/(label+'.exe');r=subprocess.run([cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(HERE),str(source),str(HERE/'timestamp.cpp'),str(HERE/'timecode_fixture.cpp'),'-o',str(exe)],capture_output=True,text=True,env=env);(out/(label+'-compile.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');assert not r.returncode,r.stderr
  r=subprocess.run([str(exe)],input=plan,capture_output=True,text=True,env=env,timeout=30);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');assert not r.returncode,r.stderr
  rows=r.stdout.splitlines();assert len(rows)==len(expected);diff=[dict(row=i,expected=e,actual=v) for i,(e,v) in enumerate(zip(expected,rows)) if e!=v];(out/(label+'-differences.json')).write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8',newline='\n');return len(diff)
 try:
  report['native_differences']=compare('native',HERE/'timecode.cpp');assert not report['native_differences'],'Native timecode differences'
  body=(HERE/'timecode.cpp').read_text(encoding='utf-8')
  for label,old,new in [('truncate-instead-of-round','/22500000.0+0.5','/22500000.0'),('overwrite-latest-with-b-picture','if(s(state.current.value)>=s(state.latest.value))','if(true)'),('omit-gop-advance','else if(input.changed)advance(p,state.latest);','else if(input.changed){advance(p,state.latest);copy_components(p,state.latest);}'),('reset-baseline-every-picture','if(!state.first.valid)','if(true)'),('standardized-drop-hour','{107891,17981,1800','{107892,17981,1800'),('standardized-drop60-coefficients','107892u:215892u','107892u:215784u')]:
   assert old in body,label
   source=out/(label+'.cpp');source.write_text(body.replace(old,new),encoding='utf-8',newline='\n');different=compare(label,source);assert different,label;report['negative_controls'].append(dict(name=label,differing_rows=different))
  for name,digest in sources.items():assert sha(ROOT/name)==digest
  report['status']='qualified joined native timecodes'
 except Exception as error:report.update(status='failed',failure=str(error));raise
 finally:
  report['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ['.txt','.json','.cpp']};(out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps({k:report[k] for k in ['status','cases','operations','rows','native_differences']}))
if __name__=='__main__':main()
