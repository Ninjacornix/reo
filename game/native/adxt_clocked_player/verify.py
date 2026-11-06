#!/usr/bin/env python3
"""Live clock/player observations against original words and callback ordering."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/adxt-clocked-player'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True)
    p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen graph drift '+str(drift()))
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),game_run=False,device_opened=False,checks=[],negative_controls=[])
    def run(name,cmd,negative=False):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if negative:
            if not r.returncode:raise ValueError('Negative passed '+name)
        elif r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout.strip()
    flags=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT),'-I'+str(HERE)]
    deps=[ROOT/n for n in ['game/native/sjrb/sjrb.cpp','game/native/adxt_shared_source/shared_source.cpp','game/native/adxt_refill/adxt_refill.cpp',
        'game/native/resource_io/async_read_owner.cpp','game/native/tasks/serial_worker.cpp','game/native/resources/resource_session.cpp',
        'game/native/resources/virtual_file_view.cpp','game/native/resources/bounded_view.cpp','game/native/adx_header/adx_header.cpp',
        'game/native/adx_workspace/adx_workspace.cpp','game/native/adx_pcm_store/v2/pcm_store.cpp','game/native/adx_window/v2/playback_r2/stream_window.cpp',
        'game/native/adxt_playback/playback.cpp','game/native/adxt_output_session/session.cpp','game/native/pcm/pcm.cpp','game/native/audio_output/audio_output_owner.cpp']]
    deps += [ROOT/'game/native/adxt_estimated_clock/estimated_clock.cpp',ROOT/'game/native/adxt_integer_clock/integer_clock.cpp']
    try:
        unit=out/'units.exe';run('units-compile',flags+[HERE/'player.cpp',HERE/'player_tests.cpp',*deps,'-o',unit]);report['units']=run('units',[unit])
        inherited=out/'inherited.exe';run('inherited-compile',flags+[HERE/'player.cpp',HERE/'inherited_tests.cpp',*deps,'-o',inherited]);report['inherited']=run('inherited',[inherited])
        sys.path.insert(0,str(ROOT/'tools/native_reconstruction/adxt_estimated_clock_oracle'))
        sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
        import importlib.util
        oracle_path=ROOT/'tools/native_reconstruction/adxt_estimated_clock_oracle/oracle.py'
        spec=importlib.util.spec_from_file_location('clock_original',oracle_path);original=importlib.util.module_from_spec(spec);spec.loader.exec_module(original)
        parent=ROOT/'build-native-sjuni/adxt-estimated-clock'
        authority=json.loads((parent/'frozen-v1/input-manifest.json').read_bytes())
        if authority['authority']!=original.authority()or authority['emission']!=original.statements():raise ValueError('Original clock authority drift')
        worker_name='gcc-v1'if sha(Path(cc))=='51911fb398529fa19769da935279c1a8a56f1c3508b2df295624aaa3dae34aa5'else'llvm-v1'
        worker_dir=parent/worker_name;worker_receipt=json.loads((worker_dir/'receipt.json').read_bytes())
        worker=worker_dir/'fp_worker.exe'
        if sha(Path(cc))!=worker_receipt['compiler_sha256']or sha(worker)!=worker_receipt['worker_binary_sha256']:raise ValueError('Exact qualified compiler/FP worker required')
        report.update(original_authority_manifest_sha256=sha(parent/'frozen-v1/input-manifest.json'),fp_worker_receipt_sha256=sha(worker_dir/'receipt.json'),fp_worker_sha256=sha(worker))
        source=(HERE/'player.cpp').read_text();anchor='    clock::Clock owner(*s.shared_clock,before);'
        if source.count(anchor)!=1:raise ValueError('Pause scheduling edge drift')
        scheduled=out/'scheduled.cpp';scheduled.write_text(source.replace('#include "player.hpp"','#include "player.hpp"\nextern void test_after_play_before_clock() noexcept;',1).replace(anchor,'    if(active && changed)test_after_play_before_clock();\n'+anchor),encoding='utf-8',newline='\n')
        records={};binaries={}
        for name,core in [('plain',HERE/'player.cpp'),('scheduled',scheduled)]:
            binary=out/(name+'.exe');run(name+'-compile',flags+[core,HERE/'fixture_runner.cpp',*deps,'-o',binary]);binaries[name]=binary
            captured=run(name,[binary]);records[name]=[json.loads(line)for line in captured.splitlines()]
            (out/(name+'-captured.json')).write_text(json.dumps(records[name],indent=2)+'\n',encoding='utf-8',newline='\n')
        # Captures/hashes are sealed BEFORE any original execution below.
        (out/'capture-manifest.json').write_text(json.dumps(dict(schema=1,provenance='native live measurements before original replay',inputs={n:sha(out/(n+'-captured.json'))for n in records},executables={n:sha(p)for n,p in binaries.items()},scheduled_source_sha256=sha(scheduled)),indent=2)+'\n',encoding='utf-8',newline='\n')
        report['capture_manifest_sha256']=sha(out/'capture-manifest.json');report['original_cases']=[]
        def replay(row,fp):
            before=row['before'];shared=row['shared_before'];o=row['observation']
            case=dict(name=row['name'],entry=0,state=o[0],decoded=o[1],total=o[2],frequency=o[3],base=o[4],offset=o[5],depth_mode=o[6],depth_code=o[7],output_present=bool(o[8]),output_bytes=o[9],rna_free_bytes=o[10],
                      estimate_base=before[0],tick_base=before[1],paused=before[2],mode=shared[0],ratio=shared[1],counter=shared[2],rebase_mode=shared[3],service_guard=shared[4],drift_bits=shared[5],tick=row['tick'],argument=row['argument'],fcr31=0x100003,fpr_u32=original.prior_fp.fpr_seed())
            machine=original.Machine(case,fp,authority)
            machine.mem.store(original.integer.RNA+0x24,1,before[3]) # measured prepared input, not an execution hook
            result=machine.operation(dict(op=row['op'],tick=row['tick'],value=row['argument']))
            if result['result']['failure']:raise ValueError('Partial live original '+str(result['result']['failure']))
            projection=result['projection'];expected_stream=[projection[n]for n in ['estimate_base_u32','tick_base_u32','paused_byte','rna_play_byte']]
            expected_shared=[projection['mode_u32'],shared[1],projection['counter_u32'],shared[3],shared[4],projection['drift_bits_u32']]
            errors=[]
            if row['after']!=expected_stream:errors.append('stream')
            if row['shared_after']!=expected_shared:errors.append('shared')
            if row['status']!=0:errors.append('native refusal')
            if row['op']=='estimate'and(row['numerator'],row['denominator'])!=(projection['output_u32'],projection['denominator_u32']):errors.append('ratio')
            if row['op']=='centiseconds'and row['value']!=(result['result']['raw_v0_lower64_observation_only']&0xffffffff):errors.append('centiseconds')
            if row['actual_play']!=bool(expected_stream[3]):errors.append('actual play')
            return result,errors
        os.environ['PATH']=env['PATH']
        with original.prior_fp.FpuWorker(worker)as fp:
            for cohort,rows in records.items():
                for index,row in enumerate(rows):
                    result,errors=replay(row,fp);path=out/(cohort+'-'+str(index)+'-original.json');path.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
                    report['original_cases'].append(dict(cohort=cohort,name=row['name'],original_instructions=result['result']['original_instructions'],fp_steps=result['result']['fp_steps'],sha256=sha(path),differences=errors))
                    if errors:raise ValueError(cohort+': '+row['name']+': '+str(errors))
            stale=out/'stale-pause-input.cpp';text=scheduled.read_text();old='active && changed?s.observation():initial'
            if text.count(old)!=1:raise ValueError('Stale-input negative drift')
            stale.write_text(text.replace(old,'initial'),encoding='utf-8',newline='\n');binary=out/'stale-pause-input.exe'
            run('stale-input-compile',flags+[stale,HERE/'fixture_runner.cpp',*deps,'-o',binary]);bad=[json.loads(line)for line in run('stale-input',[binary]).splitlines()]
            mismatches=[]
            for row in bad:
                result,errors=replay(row,fp)
                if errors:mismatches.append(dict(name=row['name'],op=row['op'],differences=errors,consumed_before=row['consumed_before'],consumed_after=row['consumed_after']))
            if not mismatches:raise ValueError('Stale pre-resume observation was not detected')
            report['negative_controls'].append(dict(name='stale pre-resume queue',source_sha256=sha(stale),differences=mismatches))
        report['status']='passed live player clock projection/original replay and scheduled pause ordering'
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
