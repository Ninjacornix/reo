#!/usr/bin/env python3
"""Compare native audio dispatch envelopes against frozen original execution."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/adxt-service-group'
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
import adxt_service_group_oracle as oracle
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=shutil.which(a.cxx)
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    frozen=ROOT/manifest['original_freeze'];original=ROOT/manifest['original_run']
    if sha(frozen/'manifest.json')!=manifest['original_freeze_sha256']or sha(original/'receipt.json')!=manifest['original_receipt_sha256']:raise ValueError('Original authority drift')
    identity=json.loads((frozen/'manifest.json').read_bytes());receipt=json.loads((original/'receipt.json').read_bytes())
    if identity['authority']!=oracle.authority()or identity['native_exists']or sha(frozen/'inputs.json')!=identity['inputs_sha256']:raise ValueError('Original identity mismatch')
    cases=json.loads((frozen/'inputs.json').read_bytes())['cases'];expected={}
    for row in receipt['rows']:
        path=original/(row['name']+'.json')
        if sha(path)!=row['sha256']:raise ValueError('Original output drift')
        expected[row['name']]=json.loads(path.read_bytes())['projection']
    plan=[]
    for c in cases:
        plan.append(' '.join(map(str,[c['name'],c['busy'],*c['decoder'],*c['stream'],*c['rna'],*c['phase'],len(c['actions'])])))
        for x in c['actions']:plan.append(' '.join(map(str,[x['trigger'],x['slot'],int(x.get('reenter',False)),x.get('table','none'),x.get('target',0),x.get('field','none'),x.get('value',0)])))
    out.mkdir(parents=True);(out/'plan.txt').write_text('\n'.join(plan)+'\n',encoding='utf-8',newline='\n');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(original/'receipt.json'),checks=[],negative_controls=[],game_run=False,device_opened=False,whole_child_pipeline_qualified=False)
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    def run(name,cmd,negative=False):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if not negative and r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r
    def compare(name,path):
        rows=[json.loads(x)for x in path.read_text().splitlines()]
        if len(rows)!=len(cases)or [x['name']for x in rows]!=[x['name']for x in cases]:raise ValueError('Missing native cases')
        differences=[x['name']for x in rows if x['projection']!=expected[x['name']]]
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');return differences
    try:
        binary=out/'units.exe';run('units-compile',flags+[HERE/'service_group.cpp',HERE/'service_group_tests.cpp','-o',binary]);report['units']=run('units',[binary]).stdout.strip()
        binary=out/'fixture.exe';run('fixture-compile',flags+[HERE/'service_group.cpp',HERE/'fixture_runner.cpp','-o',binary]);run('fixture',[binary,out/'plan.txt',out/'results.jsonl'])
        if compare('native',out/'results.jsonl'):raise ValueError('Native/original differences')
        source=(HERE/'service_group.cpp').read_text();mutants=[('wrong-active-byte','decoder->active()==1','decoder->active()!=0'),('wrong-tail-order','stream->propagate_input_end();\n        stream->propagate_error();','stream->propagate_error();\n        stream->propagate_input_end();'),('early-phase-two','guards_->enter(Domain::cri);\n    for(std::uint32_t i=0;i<slots;++i){','guards_->enter(Domain::cri);\n    clock_->service_busy=2;\n    for(std::uint32_t i=0;i<slots;++i){')]
        for name,old,new in mutants:
            if source.count(old)!=1:raise ValueError('Mutation source drift '+name)
            path=out/(name+'.cpp');path.write_text(source.replace(old,new),encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+[path,HERE/'fixture_runner.cpp','-o',binary]);r=run(name,[binary,out/'plan.txt',out/(name+'.jsonl')],negative=True)
            if r.returncode:raise ValueError('Negative fixture failed before comparison '+name)
            differences=compare(name,out/(name+'.jsonl'))
            if not differences:raise ValueError('Negative matched original '+name)
            report['negative_controls'].append(dict(name=name,differences=len(differences),source_sha256=sha(path)))
        report.update(status='passed native/original audio group dispatch envelopes',cases=len(cases),original_instructions=receipt['original_instructions'],executable_sha256=sha(out/'fixture.exe'),plan_sha256=sha(out/'plan.txt'),results_sha256=sha(out/'results.jsonl'))
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],cases=report['cases'],negative_controls=report['negative_controls'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
