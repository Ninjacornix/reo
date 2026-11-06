#!/usr/bin/env python3
"""Compare owned native LSC control against frozen original-word transcripts."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/lsc-queue'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    frozen=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in frozen['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    original=BASE/'original-v2';inputs=BASE/'original-freeze-v2'
    if sha(original/'receipt.json')!='7c4dd9e2532a90a4b2948a29c610d23beb97d59f4171652dfbbd56578d31fb20':raise ValueError('Original queue corpus identity drift')
    authority=json.loads((original/'receipt.json').read_bytes());im=json.loads((inputs/'manifest.json').read_bytes())
    if im['native_exists'] or sha(inputs/'manifest.json')!=authority['frozen_manifest_sha256']or sha(inputs/'inputs.json')!=im['inputs_sha256']:raise ValueError('Original pre-native input drift')
    cases=json.loads((inputs/'inputs.json').read_bytes())['cases'];expected=[];plan=[]
    for case,row in zip(cases,authority['rows'],strict=True):
        source=original/(case['name']+'.json')
        if row['name']!=case['name']or sha(source)!=row['sha256']:raise ValueError('Original transcript drift')
        if any(case[n]for n in ['state','repeat','pause'])or case['head']!=case['tail']:raise ValueError('Unadmitted native bootstrap')
        names=[name.encode('latin1').hex()or'-'for name in case['names']]
        plan.append(' '.join(map(str,[case['name'],case['head'],case['previous_sequence'],case['capacity'],int(case['file']),case['callback'],len(names),len(case['operations']),*names])))
        records=json.loads(source.read_bytes())['operations']
        for i,(op,record)in enumerate(zip(case['operations'],records,strict=True)):
            if op!=record['input']:raise ValueError('Original operation drift')
            expected.append(dict(case=case['name'],operation=i,projection=record['projection']))
            plan.append(' '.join(map(str,[op['call'],len(op['args']),*op['args'],op.get('lower_status',0),op.get('lower_progress',0)])))
    if len(expected)!=339:raise ValueError('Incomplete original corpus')
    out.mkdir(parents=True);data='\n'.join(plan)+'\n';(out/'plan.txt').write_text(data,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(original/'receipt.json'),original_cases=len(cases),original_operations=len(expected),original_instructions=authority['original_instructions'],plan_sha256=sha(out/'plan.txt'),checks=[],negative_controls=[],game_run=False,device_opened=False,lower_file_implementation_parity=False)
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    def run(name,command,input=None):
        r=subprocess.run([str(x)for x in command],cwd=ROOT,env=env,input=input,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in command],exit=r.returncode))
        if r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout
    def compare(name,core):
        binary=out/(name+'.exe');run(name+'-compile',flags+[core,HERE/'fixture_runner.cpp','-o',binary])
        rows=[json.loads(line)for line in run(name,[binary],input=data).splitlines()]
        if len(rows)!=len(expected):raise ValueError('Incomplete native transcript')
        differences=[dict(case=x['case'],operation=x['operation'])for x,y in zip(expected,rows,strict=True)if x!=y]
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n')
        return differences,sha(binary)
    try:
        binary=out/'units.exe';run('units-compile',flags+[HERE/'queue.cpp',HERE/'queue_tests.cpp','-o',binary]);report['units']=run('units',[binary]);report['units_executable_sha256']=sha(binary)
        differences,digest=compare('native',HERE/'queue.cpp')
        report.update(native_executable_sha256=digest,native_transcript_sha256=sha(out/'native.txt'))
        if differences:raise ValueError('Original/native control difference '+str(differences[:5]))
        source=(HERE/'queue.cpp').read_text()
        old='if (records_[head_].status == 0) start_head();'
        stale=source.replace('if (records_[head_].status == 2) retire_head();','const auto stale_head = head_; if (records_[head_].status == 2) retire_head();').replace(old,'if (records_[stale_head].status == 0) start_head();')
        variants=[('stale-head',stale),('nonzero-repeat',source.replace('if (repeat_ == 1)','if (repeat_ != 0)')),
                  ('callback-state-order',source.replace('notification_->notify(); state_ = 1;','state_ = 1; notification_->notify();')),
                  ('clear-stale-slots',source.replace('if (!state_) count_ = tail_ = head_ = 0;','if (!state_) { count_ = tail_ = head_ = 0; records_ = {}; }'))]
        for name,text in variants:
            if text==source:raise ValueError('Negative selector drift '+name)
            core=out/(name+'.cpp');core.write_text(text,encoding='utf-8',newline='\n');differences,digest=compare(name,core)
            if not differences:raise ValueError('Undetected negative control '+name)
            report['negative_controls'].append(dict(name=name,differences=len(differences),source_sha256=sha(core),executable_sha256=digest))
        report['status']='passed owned LSC control, all original projections, lifetime checks and negative controls'
    except Exception as e:report.update(status='failed',failure=str(e));raise
    finally:
        report['input_drift']=drift()
        if report['input_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],operations=len(expected),receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
