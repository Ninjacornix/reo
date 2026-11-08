#!/usr/bin/env python3
"""Recheck a test-only correction after the complete minimum cohort built.

Only owner_tests.cpp may differ. Require the prior successful compile/failed
test receipt, unchanged archives and exactly the one test compile/link in the
Ninja dry-run. Preserve prior failure logs and produce a fresh result.
"""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__)
    for n in ['prior','before','manifest','build','output','compiler','cmake','ninja']:p.add_argument('--'+n,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve();build=a.build.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/lsc-minimum') or not build.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Fresh owned result and existing scoped build required')
    old=json.loads(a.before.read_bytes());current=json.loads(a.manifest.read_bytes());prior=json.loads(a.prior.read_bytes())
    changes={n for n,d in current['files'].items()if old['files'].get(n)!=d}
    if set(old['files'])!=set(current['files']) or changes!={'game/native/adxt_lsc_input/owner_tests.cpp'}:raise ValueError('Only the test correction is admitted')
    if prior['status']!='failed' or prior['manifest_sha256']!=sha(a.before):raise ValueError('Exact prior failure required')
    for name,path in [('compiler',a.compiler),('cmake',a.cmake),('ninja',a.ninja)]:
        if prior[name+'_sha256']!=sha(path):raise ValueError('Tool drift')
    if [(r['label'],r['exit'])for r in prior['checks']]!=[('configure',0),('build',0),('tests',8)]:raise ValueError('Expected complete successful compilation and failing CTest')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');checks=[]
    def verify():
        for n,d in current['files'].items():
            if sha(ROOT/n)!=d:raise ValueError('Source drift '+n)
    archives={p.relative_to(ROOT).as_posix():sha(p)for p in build.rglob('*.a')}
    record=dict(status='failed',manifest_sha256=sha(a.manifest),before_manifest_sha256=sha(a.before),prior_receipt_sha256=sha(a.prior),compiler_sha256=sha(a.compiler),cmake_sha256=sha(a.cmake),ninja_sha256=sha(a.ninja),checks=checks,driver_sha256=sha(Path(__file__)),changed_inputs=sorted(changes),game_run=False,device_opened=False)
    def run(label,command):
        r=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=env,timeout=120)
        (out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');checks.append(dict(label=label,exit=r.returncode,command=list(map(str,command))))
        if r.returncode:raise ValueError(label+' failed; see retained result')
        return r.stdout
    try:
        verify();plan=run('dry-run',[a.ninja,'-C',build,'-n']);lines=[s for s in plan.splitlines()if s.startswith('[')]
        if len(lines)!=2 or not all('adxt_lsc_input_owner_tests' in s for s in lines) or 'Building CXX object' not in lines[0] or 'Linking CXX executable' not in lines[1]:raise ValueError('Unexpected rebuild scope')
        run('build',[a.cmake,'--build',build,'-j','1'])
        if {p.relative_to(ROOT).as_posix():sha(p)for p in build.rglob('*.a')}!=archives:raise ValueError('Production archive changed during test-only rebuild')
        tests=run('tests',[a.cmake.with_name('ctest.exe'),'--test-dir',build,'--output-on-failure'])
        result=re.search(r'100% tests passed, 0 tests failed out of (\d+)',tests)
        if not result or int(result[1])!=78:raise ValueError('Complete78 suite result required')
        verify();record.update(status='native media pipeline standalone build and tests passed',parent_suites=78,libraries=archives,production_archives_unchanged=True)
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix=='.txt'}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],parent_suites=78,receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
