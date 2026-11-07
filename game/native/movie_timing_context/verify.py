#!/usr/bin/env python3
"""Compare an owned prepared timing context to joined original workflows."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-timing-context'
FIELDS=['actual','requested','pause','depth','pending','buffering','episodes','rate','property_e','selector','property_47','tolerance','admit_slack','requested_slack']
KINDS={0:0,0x1764B0:1,0x1764F8:2,0x176558:3,0x176578:4,0x165B48:5}
EVENTS={'estimate':0,'counter':1,'command':2,'pause_predicate':3,'resume_predicate':4,'error':5,'guard_enter':6,'guard_leave':7}
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def projection(snapshot):
    clock=snapshot['clock'].copy();clock[:7]=[KINDS[value] for value in clock[:7]]
    if snapshot['validated'] not in [0,0x400000] or snapshot['last_filter'] not in [0,0x400F60]:raise ValueError('Prepared original identity')
    return [snapshot['facts'][name] for name in FIELDS]+clock+snapshot['filter']+snapshot['audio_cache']+snapshot['guard']+[snapshot['diagnostic'],int(bool(snapshot['validated'])),int(bool(snapshot['last_filter']))]


def patch(value):return [sum(1<<n for n,name in enumerate(FIELDS) if name in value)]+[value.get(name,0) for name in FIELDS]


def plan(cases,originals):
    lines=[];expected=[]
    for identity,(case,original) in enumerate(zip(cases,originals,strict=True)):
        if case['name']!=original['name']:raise ValueError('Workflow identity')
        lines.append('begin '+' '.join(map(str,[identity]+[case['facts'][name] for name in FIELDS]+[case[name] for name in ['frequency','hooks','guard_depth','guard_tag']])))
        expected.append((identity,-1,projection(original['initial'])+original['initial']['caller']+[0,0,0,0]))
        for index,(operation,row) in enumerate(zip(case['operations'],original['operations'],strict=True)):
            values=[operation['value']]+operation['query']+operation['sample']+[operation[name] for name in ['counter','helper_frequency','adxt_status','predicate','nested_query','command_status','error_status']]+patch(operation['facts'])+patch(operation['command_updates'])
            lines.append(operation['kind']+' '+' '.join(str(int(value)) for value in values))
            values=projection(row['after'])+row['after']['caller']+[int(row['return_defined']),row['returned'] if row['return_defined'] else 0,0,len(row['events'])]
            for event in row['events']:
                kind=event['kind'];args=[0]*4
                if kind=='command':args=event['arguments'][1:]
                elif kind=='error':
                    detail=event['arguments'][2];args=[event['arguments'][0],event['arguments'][1],{1:1,0x400CC0:2,0x4009A0:3}.get(detail,detail),0]
                elif kind.startswith('guard_'):args=[0,0,event['arguments'][0],0]
                values += [EVENTS[kind],event['nesting']]+args+projection(event['before'])+[int('nested_result' in event)]
                if 'nested_result' in event:values+=event['nested_result']['pair']+[event['nested_result']['returned']]
            expected.append((identity,index,values))
    return '\n'.join(lines)+'\n',expected


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    originals=[];inputs=[];receipts={}
    for tag,pinned,pre_pinned in [('gcc','e9981ac67aa3d902f3c564e9215259d7971ad4aaf0f7dd4db628787e95589042','be4dcc2be36ce9af01f639344fcd541848566e1f5926ad8d6174e358f294cc26'),('llvm','cc142ee7c12017ab0a4b76090b6df6ff5da3041a352303f9aebca589a2a16007','00ef4f423a3322601cd528713e33eb8bd11f2d42a3aa5b92cb497bfdee415ac8')]:
        frozen=BASE/('original-'+tag+'-v3');receipt=json.loads((frozen/'receipt.json').read_bytes());pre=BASE/('original-'+tag+'-v2');prior=json.loads((pre/'receipt.json').read_bytes())
        if sha(frozen/'receipt.json')!=pinned or not receipt['native_exists'] or sha(pre/'receipt.json')!=pre_pinned or prior['native_exists']:raise ValueError('Original workflow authority')
        for scope,record in [(pre,prior),(frozen,receipt)]:
            for name,digest in record['outputs_sha256'].items():
                if sha(scope/name)!=digest:raise ValueError('Frozen original drift')
        authority=json.loads((frozen/'input-manifest.json').read_bytes())
        if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
        for name,digest in authority['sources'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Original engine drift '+name)
        for key in ['existing_native_sources','control_extension_sources']:
            for name,digest in authority[key].items():
                if sha(BASE/'candidate-before-workflow-extension-v1'/name)!=digest:raise ValueError('Pre-extension candidate snapshot drift')
        for row in authority['fp_emission']['files']:
            if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Audited emitted FP source drift')
        if sha(frozen/'fp_worker.cpp')!=authority['fp_worker_source_sha256'] or sha(frozen/'fp_worker.exe')!=authority['fp_worker_sha256']:raise ValueError('Joined FP worker drift')
        cases=json.loads((frozen/'inputs.json').read_bytes());result=json.loads((frozen/'original.json').read_bytes())
        if cases[:37]!=json.loads((pre/'inputs.json').read_bytes()) or result[:37]!=json.loads((pre/'original.json').read_bytes()):raise ValueError('Earlier original workflows changed')
        inputs.append(cases);originals.append(result);receipts[str(frozen/'receipt.json')]=pinned
    if originals[0]!=originals[1] or inputs[0]!=inputs[1]:raise ValueError('Original compiler cohorts differ')
    cases=inputs[0];text,expected=plan(cases,originals[0]);manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native cohort drift '+str(drift()))
    out.mkdir(parents=True);(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(HERE/'../movie_selected_clock')]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipts=receipts,workflows=len(cases),operations=210,rows=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False)

    def run(name,command,input=None,negative=False):
        result=subprocess.run([str(v) for v in command],text=True,capture_output=True,input=input,env=env,cwd=ROOT,timeout=60)
        (out/(name+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=result.returncode))
        if (not negative and result.returncode) or (negative and not result.returncode):raise ValueError(name+': '+result.stdout+result.stderr)
        return result.stdout

    def object(name,source):
        path=out/(name+'.o');run(name+'-compile',flags+['-c',source,'-o',path]);return path

    def binary(name,objects):
        path=out/(name+'.exe');run(name+'-link',[cc,*objects,'-o',path]);return path

    def compare(name,objects):
        exe=binary(name,[*objects,fixture]);lines=run(name,[exe],text).splitlines()
        if len(lines)!=len(expected):raise ValueError('Incomplete joined transcript')
        differences=[]
        for (identity,index,values),line in zip(expected,lines,strict=True):
            tokens=line.split()
            if tokens[:3]!=['row',str(identity),str(index)]:raise ValueError('Native workflow row identity')
            actual=list(map(int,tokens[3:]))
            if not values[304]:actual[305]=0
            if len(actual)!=len(values):differences.append(dict(name=cases[identity]['name'],operation=index,schema=[len(values),len(actual)]));continue
            fields=[dict(index=n,expected=left,actual=right) for n,(left,right) in enumerate(zip(values,actual,strict=True)) if left!=right]
            if fields:differences.append(dict(name=cases[identity]['name'],operation=index,fields=fields))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report.setdefault('executables',{})[name]=sha(exe);return differences

    try:
        definitions=[('context',HERE/'context.cpp')]+[(name,HERE/'..'/directory/file) for name,directory,file in [('selected','movie_selected_clock','clock.cpp'),('counter','movie_counter_clock','clock.cpp'),('audio','movie_audio_clock','clock.cpp'),('filter','movie_audio_filter','filter.cpp'),('pause','movie_pause','controller.cpp'),('admission','movie_admission','admission.cpp'),('initialize','movie_clock_initialize','initialize.cpp')]]
        objects={name:object('normal-'+name,source) for name,source in definitions};ordered=list(objects.values());fixture=object('fixture',HERE/'fixture.cpp');units=object('units',HERE/'context_tests.cpp')
        exe=binary('native-units',[*ordered,units]);report['units']=run('native-units',[exe]).strip();differences=compare('native',ordered);report['native_differences']=len(differences)
        if differences:raise ValueError('Joined native mismatch '+str(differences[:3]))
        source=(HERE/'context.cpp').read_text(encoding='utf-8')
        variants=[
            ('split-selected-guard',[('selected.shared_guard=guard_;','selected.shared_guard={};')]),
            ('omit-pre-component-clock-sync',[('if(!from_pause(view.state))return{pause::ProviderStatus::failed,0,{}};','(void)view;')]),
            ('omit-auxiliary-publication',[('selected::ControlUpdate update;update.elapsed_counter=state.auxiliary;\n    if(selected_->update(update)!=selected::Status::completed)return{Status::busy};','')]),
            ('invert-admit-bypass',[('if(facts_.property_e){Result result;','if(!facts_.property_e){Result result;')]),
            ('drop-component-property-effects',[('if(validate(reply.updates)!=Status::completed)return{pause::ProviderStatus::failed,reply.status,{}};\n    properties(reply.updates);','if(validate(reply.updates)!=Status::completed)return{pause::ProviderStatus::failed,reply.status,{}};')])]
        for name,changes in variants:
            changed=source
            for old,new in changes:
                if changed.count(old)!=1:raise ValueError('Mutation selector drift '+name)
                changed=changed.replace(old,new)
            path=out/(name+'.cpp');path.write_text(changed,encoding='utf-8',newline='\n');mutant=object(name,path);items=[mutant if key=='context' else value for key,value in objects.items()];found=compare(name,items)
            if not found:raise ValueError('Undetected joined counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(found)))
        selected_source=(HERE/'../movie_selected_clock/clock.cpp').read_text(encoding='utf-8')
        boundary=[
            ('omit-context-retention','context',source,'const auto retained=weak_from_this().lock();\n    if(!retained)return{Status::invalid_input};','if(weak_from_this().expired())return{Status::invalid_input};'),
            ('allow-busy-control','context',source,'Status Context::observe(const Updates& updates)noexcept {\n    if(busy_)return Status::busy;','Status Context::observe(const Updates& updates)noexcept {\n    if(false && busy_)return Status::busy;'),
            ('publish-refused-refresh','selected',selected_source,'if(provider_failed_)return;','if(false && provider_failed_)return;'),
            ('drop-refused-provider-facts','selected',selected_source,'facts(reply.facts);','if(reply.admitted)facts(reply.facts);'),
            ('treat-raw-status-as-refusal','selected',selected_source,'provider_failed_|=!reply.admitted;','provider_failed_|=reply.status!=0;')]
        for name,key,body,old,new in boundary:
            if body.count(old)!=1:raise ValueError('Boundary mutation selector drift '+name)
            path=out/(name+'.cpp');path.write_text(body.replace(old,new),encoding='utf-8',newline='\n');mutant=object(name,path);items=[mutant if n==key else value for n,value in objects.items()];exe=binary(name+'-units',[*items,units]);run(name+'-units',[exe],negative=True)
            report['negative_controls'].append(dict(name=name,boundary_tests_rejected=True))
        if drift():raise ValueError('Native inputs changed during run')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified prepared owned movie timing context'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={path.name:sha(path) for path in sorted(out.iterdir()) if path.is_file() and path.name!='receipt.json' and path.suffix in ['.txt','.json','.cpp']}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],workflows=len(cases),rows=len(expected),negative_controls=len(report['negative_controls']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
