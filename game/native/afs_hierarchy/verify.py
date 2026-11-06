#!/usr/bin/env python3
"""Bounded AFS hierarchy ownership and discriminating cache/tail controls."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/afs-hierarchy'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen input drift '+str(drift()))
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),verifier_sha256=sha(Path(__file__)),game_run=False,device_opened=False,checks=[],negative_controls=[])
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    deps=[ROOT/'game/native/afs_source_range/afs_source_range.cpp',ROOT/'game/native/resources/bounded_view.cpp']
    def run(name,cmd,negative=False):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if negative:
            if not r.returncode:raise ValueError('Negative passed '+name)
        elif r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout.strip()
    try:
        binary=out/'units.exe';run('units-compile',flags+[HERE/'hierarchy.cpp',HERE/'hierarchy_tests.cpp',*deps,'-o',binary]);report['units']=run('units',[binary])
        text=(HERE/'hierarchy.cpp').read_text()
        mutants=[('wrong-path-cache','c.depth==depth && c.path==path','c.depth==depth'),
                 ('logical-only-leaf','result.view=std::move(view)','result.view=resources::bounded_view(view,0,result.logical_bytes).view')]
        for name,old,new in mutants:
            if text.count(old)!=1:raise ValueError('Mutation source drift')
            path=out/(name+'.cpp');path.write_text(text.replace(old,new),encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+[path,HERE/'hierarchy_tests.cpp',*deps,'-o',binary]);run(name,[binary],negative=True)
            report['negative_controls'].append(dict(name=name,source_sha256=sha(path)))
        report['status']='passed bounded actual-parent hierarchy and cache/tail negative controls'
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
