#!/usr/bin/env python3
"""Actual private serviced-clock factory and measured-input original comparison."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3];BASE=ROOT/'build-native-sjuni/adxt-service-binding'
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
import adxt_serviced_discard_oracle as original
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class MeasuredMachine(original.Machine):
    def __init__(self,row,fp,identity):
        b=row['before'];s=row['shared_before'];o=row['observation_before'];self.measurement=row;self.applied=False
        case=dict(name=row['name'],entry=0,state=o[0],decoded=o[1],total=o[2],frequency=o[3],base=o[4],offset=o[5],depth_mode=o[6],depth_code=o[7],output_present=bool(o[8]),output_bytes=o[9],rna_free_bytes=o[10],
                  estimate_base=b[0],tick_base=b[1],paused=b[2],play=b[3],mode=s[0],ratio=s[1],counter=s[2],rebase_mode=s[3],service_guard=s[4],drift_bits=s[5],tick=row['tick'],argument=0,updates=[],fcr31=0x100003,fpr_u32=original.clock.prior_fp.fpr_seed())
        super().__init__(case,fp,identity)
        # The concrete native owner has one active decoder/player/RNA/DTR at
        # slot0 and no DTX children. Both empty DTX group scans still execute.
        self.mem.store(original.groups.TABLES['dtx'][0],1,0)

    def hook(self,pc):
        if pc==0x133098 and not self.applied:
            # Exact post-group return cut, before original raw queries/FP. These
            # are independently captured queues, never a supplied clock result.
            before=self.measurement['observation_before'];after=self.measurement['observation_after']
            if any(before[i]!=after[i]for i in (2,3,4,5,6,7,8)):raise ValueError('Unsupported measured metadata transition')
            for field,i in [('state',0),('decoded',1),('output_bytes',9),('rna_free_bytes',10)]:self.queue_effect(field,after[i])
            self.applied=True
        return super().hook(pc)


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    authority=original.authority();identity=json.loads((original.FP/'frozen-v1/input-manifest.json').read_bytes())
    worker_name='gcc-v1'if sha(Path(cc))==authority['workers']['gcc-v1']['compiler_sha256']else'llvm-v1'
    if sha(Path(cc))!=authority['workers'][worker_name]['compiler_sha256']:raise ValueError('Unqualified exact FP compiler')
    worker=original.FP/worker_name/'fp_worker.exe';out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    helper=ROOT/'game/native/adxt_control_session/verify.py';spec=importlib.util.spec_from_file_location('control_deps',helper);deps_module=importlib.util.module_from_spec(spec);spec.loader.exec_module(deps_module)
    deps=[ROOT/'game/native'/n for n in deps_module.SOURCES];objects=[out/(p.stem+'.o')for p in deps]
    if len(set(objects))!=len(objects):raise ValueError('Dependency object collision')
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE.parent),'-I'+str(ROOT)]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),checks=[],captures={},original_cases=[],negative_controls=[],game_run=False,device_opened=False,original_whole_player_parity=False)
    def run(name,cmd,cwd=ROOT):
        r=subprocess.run([str(x)for x in cmd],cwd=cwd,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout
    def replay(row,fp):
        m=MeasuredMachine(row,fp,identity);result=m.operation(dict(op='discard_rebase'))
        if result['result']['failure']:raise ValueError('Original execution cut '+str(result['result']['failure']))
        p=result['projection'];i=original.clock.integer
        expected=[p['estimate_base_u32'],p['tick_base_u32'],p['paused_byte'],p['rna_play_byte']]
        shared=[p['mode_u32'],m.mem.load(i.GLOBAL+56,4),p['counter_u32'],m.mem.load(i.GLOBAL+16,4),m.mem.load(i.GLOBAL+4,4),p['drift_bits_u32']]
        differences=[]
        if row['after']!=expected:differences.append('canonical stream')
        if row['shared_after']!=shared:differences.append('canonical shared clock')
        if row['group_visits']!=int(m.applied):differences.append('actual group attempt')
        if row['diagnostics']!=sum(e.get('kind')=='external_diagnostic'for e in result['result']['events']):differences.append('diagnostic count')
        if not m.applied and row['observation_after']!=row['observation_before']:raise ValueError('Unpaused measurement had unexpected queue progress')
        return dict(original=result,dispatch=m.dispatch,applied_measured_post_group=m.applied),differences
    try:
        run('dependency-compile',flags+['-c',*deps],cwd=out);report['dependency_objects']={p.name:sha(p)for p in objects}
        source=(HERE.parent/'control_session.cpp').read_text();anchor='const auto fresh=target->snapshot();stream=fresh.clock;observation=fresh.clock_observation;'
        if source.count(anchor)!=1:raise ValueError('Actual post-group snapshot cut drift')
        scheduled=out/'scheduled.cpp';scheduled_text=source.replace('#include "control_session.hpp"','#include "control_session.hpp"\nextern void test_after_group_before_clock_snapshot() noexcept;',1).replace(anchor,'test_after_group_before_clock_snapshot();\n            '+anchor)
        scheduled.write_text(scheduled_text,encoding='utf-8',newline='\n');records={};binaries={}
        for name,core in [('plain',HERE.parent/'control_session.cpp'),('scheduled',scheduled)]:
            binary=out/(name+'.exe');run(name+'-compile',flags+objects+[core,HERE/'fixture_runner.cpp','-o',binary]);rows=[json.loads(line)for line in run(name,[binary]).splitlines()]
            if len(rows)!=30:raise ValueError('Incomplete actual service binding matrix')
            if name=='plain'and any(r['scheduled_callbacks']for r in rows):raise ValueError('Unexpected plain callback')
            if name=='scheduled'and sum(r['scheduled_callbacks']for r in rows)!=18:raise ValueError('Missing declared model callback')
            records[name]=rows;binaries[name]=binary;(out/(name+'-captured.json')).write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8',newline='\n')
        # Freeze actual inputs before replaying a single original operation.
        capture=dict(schema=1,provenance='actual private native factory measurements before original replay; explicit model callback in scheduled cohort',inputs={n:sha(out/(n+'-captured.json'))for n in records},executables={n:sha(p)for n,p in binaries.items()},scheduled_source_sha256=sha(scheduled))
        (out/'capture-manifest.json').write_text(json.dumps(capture,indent=2)+'\n',encoding='utf-8',newline='\n');report['capture_manifest_sha256']=sha(out/'capture-manifest.json');report['fp_authority']=authority
        os.environ['PATH']=env['PATH']
        with original.clock.prior_fp.FpuWorker(worker)as fp:
            for cohort,rows in records.items():
                for n,row in enumerate(rows):
                    result,differences=replay(row,fp);path=out/(cohort+'-'+str(n)+'-original.json');path.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
                    report['original_cases'].append(dict(cohort=cohort,name=row['name'],original_instructions=result['original']['result']['original_instructions'],fp_steps=result['original']['result']['fp_steps'],sha256=sha(path),differences=differences))
                    if differences:raise ValueError(cohort+' '+row['name']+': '+str(differences))
            stale=out/'stale-queue.cpp';old='// Original discard services the group, not file/source polling.'
            if scheduled_text.count(old)!=1:raise ValueError('Stale snapshot mutation drift')
            stale_text=scheduled_text.replace(old,'const auto stale=target->snapshot().clock_observation;\n            '+old).replace('observation=fresh.clock_observation;','observation=stale;')
            stale.write_text(stale_text,encoding='utf-8',newline='\n');binary=out/'stale-queue.exe';run('stale-queue-compile',flags+objects+[stale,HERE/'fixture_runner.cpp','-o',binary]);bad=[json.loads(s)for s in run('stale-queue',[binary]).splitlines()];failures=[]
            for row in bad:
                _,differences=replay(row,fp)
                if differences:failures.append(dict(name=row['name'],differences=differences,consumed_before=row['consumed_before'],consumed_after=row['consumed_after']))
            if not failures:raise ValueError('Stale canonical factory snapshot was not detected')
            report['negative_controls'].append(dict(name='stale queue in actual private service factory',source_sha256=sha(stale),differences=failures))
        report.update(status='passed actual private serviced-clock binding and measured-input original replay',operations=len(report['original_cases']),original_instructions=sum(r['original_instructions']for r in report['original_cases']),fp_steps=sum(r['fp_steps']for r in report['original_cases']))
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],operations=report['operations'],stale_differences=len(report['negative_controls'][0]['differences']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
