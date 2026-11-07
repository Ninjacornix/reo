#!/usr/bin/env python3
"""Qualify joined movie audio controls against frozen original movie policies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import verify as timing
ROOT=timing.ROOT;HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-audio-commands'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
EVENTS=dict(timing.EVENTS,device_pause=8,device_discard=9,device_frequency=10)


def project(value):return timing.projection(value)+value['audio_control']


def return_defined(case,operation,row):
    # Requested/temporary pause are void, including their suppressed-unpause
    # branches. A dispatched mode 0/1 inherits that incidental register result.
    if operation['kind'] in ['audio_requested','audio_temporary']:return False
    if operation['kind']=='audio_command' and operation['value'] in [0,1] and case['channel'] and case['decoder'] and case['buffer_state']['audio']:return False
    return row['return_defined']


def plan(cases,originals):
    lines=[];expected=[]
    for identity,(case,original) in enumerate(zip(cases,originals,strict=True)):
        buffer=case['buffer_state'];values=[identity]+[case['facts'][name] for name in timing.FIELDS]+[case[key] for key in ['frequency','hooks','guard_depth','guard_tag']]+[buffer['audio'],buffer['enabled']]+buffer['latest']+[int(case[key]) for key in ['channel','decoder','requested_pause','residual','filter_mode']]
        lines.append('begin '+' '.join(map(str,values))+' '+str(len(case['operations'])))
        expected.append((identity,-1,project(original['initial'])+[0,0,0,0]))
        for index,(op,row) in enumerate(zip(case['operations'],original['operations'],strict=True)):
            lines.append(op['kind']+' '+' '.join(map(str,[op['value']]+op['sample']+[op[key] for key in ['counter','helper_frequency','adxt_status','sample_frequency']])))
            events=[event for event in row['events'] if not event['kind'].startswith('queue_')];defined=return_defined(case,op,row)
            values=project(row['after'])+[0,int(defined),row['returned'] if defined else 0,len(events)]
            for event in events:
                kind=event['kind'];args=[event.get('value',0),0,0,0] if kind.startswith('device_') else [0,0,event['arguments'][0],0] if kind.startswith('guard_') else [0]*4
                if kind not in EVENTS or kind in ['command','pause_predicate','resume_predicate','error']:raise ValueError('Unexpected control boundary '+kind)
                values += [EVENTS[kind]]+args+project(event['before'])
            expected.append((identity,index,values))
    return '\n'.join(lines)+'\n',expected


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh output required')
    cohorts=[];receipts={}
    for tag,pinned in [('gcc','1c1cde93426becfd67321ec4dd2a7b335494f646dad4b21b929729d1535044f6'),('llvm','56d83ead6500b9064df42881366b5a5769d824774e83e00f3bc69ce3fd12fbf5')]:
        scope=BASE/('original-'+tag+'-v3');receipt=json.loads((scope/'receipt.json').read_bytes());authority=json.loads((scope/'input-manifest.json').read_bytes())
        if sha(scope/'receipt.json')!=pinned or authority['native_commands_exist']:raise ValueError('Original must precede native command implementation')
        for name,digest in receipt['outputs_sha256'].items():
            if sha(scope/name)!=digest:raise ValueError('Original results changed')
        for name,digest in authority['sources'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Original runner changed '+name)
        if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Original ELF changed')
        cohorts.append((json.loads((scope/'inputs.json').read_bytes()),json.loads((scope/'original.json').read_bytes())));receipts[tag]=pinned
    if cohorts[0]!=cohorts[1]:raise ValueError('Original compiler results differ')
    cases,originals=cohorts[0];text,expected=plan(cases,originals);manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Source cohort changed '+str(drift()))
    out.mkdir(parents=True);(out/'plan.txt').write_text(text,encoding='utf-8');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(HERE/'../movie_selected_clock')]
    report=dict(status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipts=receipts,cases=len(cases),operations=810,rows=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,sdk_controls='Declared ports; actual native Session binding tested separately',void_pause_return_abi_excluded=True)
    def run(name,command,stdin=None):
        value=subprocess.run([str(v) for v in command],input=stdin,text=True,capture_output=True,env=env,timeout=90);(out/(name+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8');report['checks'].append(dict(name=name,exit=value.returncode))
        if value.returncode:raise ValueError(name+': '+value.stdout+value.stderr)
        return value.stdout
    def object(name,path):
        target=out/(name+'.o');run(name+'-compile',flags+['-c',path,'-o',target]);return target
    def compare(name,items):
        binary=out/(name+'.exe');run(name+'-link',[cc,*items,fixture,'-o',binary]);rows=run(name,[binary],text).splitlines();differences=[]
        if len(rows)!=len(expected):raise ValueError('Incomplete control transcript')
        for (identity,index,values),row in zip(expected,rows,strict=True):
            tokens=row.split()
            if tokens[:3]!=['row',str(identity),str(index)]:raise ValueError('Control row identity')
            actual=list(map(int,tokens[3:]))
            if actual!=values:differences.append(dict(case=cases[identity]['name'],operation=index,expected_length=len(values),actual_length=len(actual),fields=[dict(index=n,expected=a,actual=b) for n,(a,b) in enumerate(zip(values,actual)) if a!=b]))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8');return differences
    try:
        definitions=[('context',HERE/'context.cpp'),('commands',HERE/'audio_commands.cpp'),('buffering',HERE/'buffering.cpp'),('queues',HERE/'buffer_queues.cpp')]+[(name,HERE/'..'/directory/file) for name,directory,file in [('selected','movie_selected_clock','clock.cpp'),('counter','movie_counter_clock','clock.cpp'),('audio','movie_audio_clock','clock.cpp'),('filter','movie_audio_filter','filter.cpp'),('pause','movie_pause','controller.cpp'),('admission','movie_admission','admission.cpp'),('initialize','movie_clock_initialize','initialize.cpp'),('sjuni','sjuni','sjuni.cpp'),('sjrb','sjrb','sjrb.cpp')]]
        objects={name:object(name,path) for name,path in definitions};ordered=list(objects.values());fixture=object('fixture',HERE/'audio_fixture.cpp');diff=compare('native',ordered);report['native_differences']=len(diff)
        if diff:raise ValueError('Joined command mismatch '+str(diff[:2]))
        body=(HERE/'audio_commands.cpp').read_text(encoding='utf-8')
        for name,old,new in [
            ('nonzero-user-pause-gate','snapshot().facts.pause==1','snapshot().facts.pause!=0'),
            ('nonzero-requested-pause-gate','state.requested_pause==1','state.requested_pause!=0'),
            ('exact-one-audio-enable','!buffering_->audio','buffering_->audio!=1'),
            ('drop-residual-clear','state.residual=0;','(void)state.residual;'),
            ('wrong-zero-rate-frame','*(rate?1000:0)','*1000'),
            ('drop-residual-carry','const auto quantity=desired+state.residual;','const auto quantity=desired;'),
            ('drop-filter-pause','if(audio_->set_pause(value)!=audio::Status::completed)','if(false)'),
            ('filter-before-device','state.provider=controlled_audio_->pause(value);','(void)audio_->set_pause(value);state.provider=controlled_audio_->pause(value);')]:
            if old not in body:raise ValueError('Mutation selector changed '+name)
            path=out/(name+'.cpp');path.write_text(body.replace(old,new),encoding='utf-8');mutant=object(name,path);diff=compare(name,[mutant if key=='commands' else value for key,value in objects.items()])
            if not diff:raise ValueError('Undetected control fault '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(diff)))
        if drift():raise ValueError('Source cohort changed during qualification')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified joined movie audio control policy and filter ownership'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file() and p.suffix in ['.txt','.json','.cpp'] and p.name!='receipt.json'}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({key:report[key] for key in ['status','cases','operations','rows','native_differences']}|{'receipt_sha256':sha(out/'receipt.json')}))


if __name__=='__main__':main()
