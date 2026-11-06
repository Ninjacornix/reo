#!/usr/bin/env python3
"""Corrected enable predicate, original independent fields, old whole regression."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;OLD=HERE.parent;ROOT=HERE.parents[4]
BASE=ROOT/'build-native-sjuni/adx-ready-flag'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--compiler',choices=['gcc','llvm'],required=True);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    for n,d in manifest['files'].items():
        if sha(ROOT/n)!=d:raise ValueError('Frozen source drift '+n)
    corrected=(HERE/'stream_window.cpp').read_text();baseline=(OLD/'stream_window.cpp').read_text()
    restored=corrected.replace('#include "../stream_window.hpp"','#include "stream_window.hpp"').replace('std::bit_cast<std::int16_t>(header_.loop.enabled) > 0','header_.loop.count > 0')
    if restored!=baseline:raise ValueError('Correction changed more than the declared predicate/include')
    spec=importlib.util.spec_from_file_location('comparison',OLD/'compare_original.py');compare=importlib.util.module_from_spec(spec);spec.loader.exec_module(compare)
    new_dir=BASE/('original-'+a.compiler+'-v1');new_receipt=json.loads((new_dir/'receipt.json').read_bytes())
    if not new_receipt['original_transcripts_unchanged']:raise ValueError('Original observation changed transcript')
    frozen=BASE/'frozen-v1';identity=json.loads((frozen/'manifest.json').read_bytes())
    if sha(frozen/'manifest.json')!=new_receipt['manifest_sha256']or sha(frozen/'inputs.json')!=identity['inputs_sha256']:raise ValueError('New input drift')
    new_cases=json.loads((frozen/'inputs.json').read_bytes())['cases'];new_descriptors={x['name']:x for x in new_receipt['cases']}
    old_dir=ROOT/'build-native-sjuni/adx-window-v2-oracle';old_cases=json.loads((old_dir/'frozen-v3/inputs.json').read_bytes())['cases']
    captures=ROOT/'build-native-sjuni/window2'/('capture-'+a.compiler+'-v1');capture_receipt=json.loads((captures/'receipt.json').read_bytes())
    capture_descriptors={x['name']:x for x in capture_receipt['cases']}
    admitted=json.loads((ROOT/'build-native-sjuni/window2/parity-gcc-final-v1/receipt.json').read_bytes())
    names={c['name']for c in admitted['cases']if c['classification'].startswith('matched')}
    old_full=old_dir/('gcc-v2'if a.compiler=='gcc'else'llvm-v2')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),implementation_manifest_sha256=sha(HERE/'manifest.json'),
                verifier_sha256=sha(Path(__file__)),fixture_sha256=sha(OLD/'fixture_runner.cpp'),comparator_sha256=sha(OLD/'compare_original.py'),
                new_original_receipt_sha256=sha(new_dir/'receipt.json'),prior_capture_receipt_sha256=sha(captures/'receipt.json'),
                mechanical_delta_only=True,game_run=False,device_opened=False,checks=[],new_cases=[],regression=[],legacy_differences=[])
    shutil.copyfile(__file__,out/'verify.source.py')
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT)]
    deps=['game/native/sjrb/sjrb.cpp','game/native/adxt_shared_source/shared_source.cpp','game/native/adxt_refill/adxt_refill.cpp',
          'game/native/resource_io/async_read_owner.cpp','game/native/tasks/serial_worker.cpp','game/native/resources/resource_session.cpp',
          'game/native/resources/virtual_file_view.cpp','game/native/resources/bounded_view.cpp','game/native/adx_header/adx_header.cpp',
          'game/native/adx_workspace/adx_workspace.cpp','game/native/adx_pcm_store/v2/pcm_store.cpp']
    def run(name,cmd):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode,stdout=r.stdout))
        if r.returncode:raise RuntimeError(name+': '+r.stdout+r.stderr)
        return r.stdout
    def build(name,core,client):
        binary=out/(name+'.exe');run(name+'_compile',flags+deps+[core,client,'-o',binary]);return binary
    def execute(binary,case):
        path=out/(case['name']+'.input.txt')
        if not path.exists():path.write_text(compare.commands(case),encoding='utf-8',newline='\n')
        r=subprocess.run([str(binary),str(path)],cwd=ROOT,env=env,text=True,capture_output=True,timeout=30)
        (out/(binary.stem+'-'+case['name']+'.jsonl')).write_text(r.stdout,encoding='utf-8',newline='\n')
        if r.returncode:raise RuntimeError(r.stderr)
        rows=[json.loads(x)for x in r.stdout.splitlines()];refused=False
        for row in rows:refused= row.pop('status',0)not in(0,1,2)or refused
        return rows,refused
    try:
        unit=build('units',HERE/'stream_window.cpp',OLD/'stream_window_tests.cpp');run('units',[unit])
        binary=build('corrected',HERE/'stream_window.cpp',OLD/'fixture_runner.cpp')
        legacy=build('legacy',OLD/'stream_window.cpp',OLD/'fixture_runner.cpp')
        for case in new_cases:
            path=new_dir/(case['name']+'.json')
            if sha(path)!=new_descriptors[case['name']]['sha256']:raise ValueError('Original result drift')
            data=json.loads(path.read_bytes());wanted=compare.expected_rows(case,data['original'],dict(events=data['observations']))
            actual,refused=execute(binary,case);mismatch,_=compare.compare_records(actual,wanted)
            if refused or mismatch:raise ValueError(case['name']+': '+str(mismatch or 'unexpected native refusal'))
            report['new_cases'].append(dict(name=case['name'],observations=len(actual)))
            bad,refused=execute(legacy,case);mismatch,_=compare.compare_records(bad,wanted)
            if refused or mismatch:report['legacy_differences'].append(dict(name=case['name'],difference=mismatch,refused=refused))
        if len(report['legacy_differences'])!=24:raise ValueError('Independent flags failed to discriminate expected legacy predicate')
        for case in old_cases:
            if case['name']not in names:continue
            observed_path=captures/(case['name']+'.json')
            if sha(observed_path)!=capture_descriptors[case['name']]['sha256']:raise ValueError('Historical observation drift')
            observed=json.loads(observed_path.read_bytes());original_path=old_full/(case['name']+'.json')
            if sha(original_path)!=observed['original_transcript_sha256']:raise ValueError('Historical original drift')
            wanted=compare.expected_rows(case,json.loads(original_path.read_bytes()),observed)
            actual,refused=execute(binary,case);mismatch,relations=compare.compare_records(actual,wanted)
            if refused or mismatch:raise ValueError(case['name']+': regression '+str(mismatch))
            report['regression'].append(dict(name=case['name'],observations=len(actual),live_grant_relations=len(relations)))
        report['status']='passed independent enable correction and prior admitted whole regression'
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['input_drift']=[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
        if report['input_drift']:report.update(status='failed',failure='Source drift')
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],new_cases=len(report['new_cases']),regression=len(report['regression']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
