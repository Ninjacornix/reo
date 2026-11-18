#!/usr/bin/env python3
"""Build/test independent native media from explicit tools and pinned sources."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni';sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--cmake',type=Path,required=True);p.add_argument('--ninja',type=Path,required=True);p.add_argument('--manifest',type=Path,required=True);p.add_argument('--build',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--jobs',type=int,default=4);a=p.parse_args();build=a.build.resolve();out=a.output.resolve()
 if build.exists() or out.exists() or not build.is_relative_to(BASE) or not out.is_relative_to(BASE) or build==out or not 1<=a.jobs<=16:raise ValueError('Fresh owned build/output and bounded jobs required')
 manifest=json.loads(a.manifest.read_bytes());sources=manifest['files'];digest=sha(a.manifest)
 def verify():
  for name,value in sources.items():
   if sha(ROOT/name)!=value:raise ValueError('Source drift '+name)
 verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');checks=[]
 def run(label,args):
  r=subprocess.run([str(x) for x in args],capture_output=True,text=True,env=env);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');checks.append(dict(label=label,exit=r.returncode,command=[str(x) for x in args]));
  if r.returncode:raise ValueError(label+' failed; see owned log')
  return r.stdout
 record=dict(status='failed',manifest_sha256=digest,compiler_sha256=sha(a.compiler),cmake_sha256=sha(a.cmake),ninja_sha256=sha(a.ninja),checks=checks)
 try:
  run('configure',[a.cmake,'-S',ROOT/'game/native','-B',build,'-G','Ninja','-DCMAKE_BUILD_TYPE=Release','-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_MAKE_PROGRAM='+str(a.ninja.resolve())])
  run('build',[a.cmake,'--build',build,'-j',a.jobs]);tests=run('tests',[a.cmake.with_name('ctest.exe' if os.name=='nt' else 'ctest'),'--test-dir',build,'--output-on-failure']);match=re.search(r'100% tests passed, 0 tests failed out of (\d+)',tests)
  if not match:raise ValueError('Complete native test result missing')
  verify();record.update(status='native media pipeline standalone build and tests passed',parent_suites=int(match[1]),libraries={p.relative_to(ROOT).as_posix():sha(p) for p in build.rglob('*.a')})
 finally:
  record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.txt'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps(dict(status=record['status'],parent_suites=record['parent_suites'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
