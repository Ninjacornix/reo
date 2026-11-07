#!/usr/bin/env python3
"""Compare complete native buffering workflows with frozen original execution."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import verify as timing

ROOT=timing.ROOT;HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-buffering'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
STATE=['enabled','video','audio','stalled','component_one','video_done','audio_done','video_slot','audio_slot','pause_margin','resume_margin','absolute']


def plan(cases,originals):
    lines=[];expected=[]
    for index,(case,original) in enumerate(zip(cases,originals,strict=True)):
        state=case['buffer_state'];values=[index]+[case['facts'][name] for name in timing.FIELDS]+[case[key] for key in ['frequency','hooks','guard_depth','guard_tag']]+[state[key] for key in STATE]+state['latest']
        for slot in range(8):values += [state[key][slot] for key in ['stream_enabled','ended','capacity','present']]+[len(case['queues'][slot])]+case['queues'][slot]
        lines.append('begin '+' '.join(map(str,values))+' '+str(len(case['operations'])))
        expected.append((index,-1,timing.projection(original['initial'])+[0,0,0,0]))
        for number,(operation,row) in enumerate(zip(case['operations'],original['operations'],strict=True)):
            lines.append(operation['kind']+' '+' '.join(map(str,[operation['value']]+operation['sample']+[operation[key] for key in ['counter','helper_frequency','adxt_status']])))
            events=[event for event in row['events'] if not event['kind'].startswith('queue_')]
            values=timing.projection(row['after'])+[0,int(row['return_defined']),row['returned'] if row['return_defined'] else 0,len(events)]
            for event in events:
                kind=event['kind'];args=event['arguments'][1:] if kind=='command' else [0,0,event['arguments'][0],0] if kind.startswith('guard_') else [0]*4
                if kind not in ['estimate','counter','command','guard_enter','guard_leave']:raise ValueError('Unexpected native boundary '+kind)
                values += [timing.EVENTS[kind]]+args+timing.projection(event['before'])
            expected.append((index,number,values))
    return '\n'.join(lines)+'\n',expected


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    cohorts=[];receipts={}
    for tag,digest in [('gcc','07c5682a8c07036d60e5a772b2bda9e4f6bae17409321975cc4df81fadad70ca'),('llvm','ae87088f92a25db7f95edfe52402681446759793cb50dbb0bb00a9509f9eff2b')]:
        scope=BASE/('original-'+tag+'-v5');receipt=json.loads((scope/'receipt.json').read_bytes());manifest=json.loads((scope/'input-manifest.json').read_bytes())
        if sha(scope/'receipt.json')!=digest:raise ValueError('Original receipt drift')
        for name,pinned in receipt['outputs_sha256'].items():
            if sha(scope/name)!=pinned:raise ValueError('Frozen original drift')
        for name,pinned in manifest['sources'].items():
            if sha(ROOT/name)!=pinned:raise ValueError('Original runner drift')
        if sha(ROOT/'game_data/SLUS_207.65')!=manifest['elf_sha256']:raise ValueError('ELF drift')
        prior=BASE/('original-'+tag+'-v4');pre=json.loads((prior/'input-manifest.json').read_bytes());pre_receipt=json.loads((prior/'receipt.json').read_bytes())
        pinned_pre={'gcc':'14705c5deb059b904bd85d7855eb110a4b21d248d08090defe40cdea3ea38dc9','llvm':'6df3a74cd3851be6077df194a9eddbdd9c85ef91108beceeef1b6e30ddf52d45'}[tag]
        if sha(prior/'receipt.json')!=pinned_pre or pre['native_buffering_exists']:raise ValueError('Pre-native authority drift')
        for name,pinned in pre_receipt['outputs_sha256'].items():
            if sha(prior/name)!=pinned:raise ValueError('Pre-native result drift')
        if sha(BASE/'original-v4-source.py')!=next(value for name,value in pre['sources'].items() if name.replace('\\','/')=='tools/native_reconstruction/movie_buffering_oracle.py'):raise ValueError('Pre-native runner snapshot drift')
        inputs=json.loads((scope/'inputs.json').read_bytes());result=json.loads((scope/'original.json').read_bytes())
        if inputs[:202]!=json.loads((prior/'inputs.json').read_bytes()) or result[:202]!=json.loads((prior/'original.json').read_bytes()):raise ValueError('Pre-native workflows changed')
        cohorts.append((inputs,result));receipts[tag]=digest
    if cohorts[0]!=cohorts[1]:raise ValueError('Original compiler cohorts differ')
    cases,originals=cohorts[0];text,expected=plan(cases,originals);manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native manifest drift '+str(drift()))
    out.mkdir(parents=True);(out/'plan.txt').write_text(text,encoding='utf-8');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(HERE/'../movie_selected_clock')]
    report=dict(status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipts=receipts,cases=len(cases),rows=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False)
    def run(name,command,stdin=None,negative=False):
        result=subprocess.run([str(value) for value in command],text=True,input=stdin,capture_output=True,env=env,timeout=90)
        (out/(name+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8');report['checks'].append(dict(name=name,exit=result.returncode))
        if (result.returncode!=0)!=negative:raise ValueError(name+': '+result.stdout+result.stderr)
        return result.stdout
    def object(name,path):
        target=out/(name+'.o');run(name+'-compile',flags+['-c',path,'-o',target]);return target
    def executable(name,objects):
        target=out/(name+'.exe');run(name+'-link',[cc,*objects,'-o',target]);return target
    def compare(name,objects):
        target=executable(name,[*objects,fixture]);rows=run(name,[target],text).splitlines();differences=[]
        if len(rows)!=len(expected):raise ValueError('Incomplete native buffering transcript')
        for (identity,index,values),row in zip(expected,rows,strict=True):
            tokens=row.split()
            if tokens[:3]!=['row',str(identity),str(index)]:raise ValueError('Transcript identity')
            actual=list(map(int,tokens[3:]));actual[303]=values[303] if not values[302] else actual[303]
            if actual!=values:differences.append(dict(case=cases[identity]['name'],operation=index,expected_length=len(values),actual_length=len(actual),fields=[dict(index=n,expected=a,actual=b) for n,(a,b) in enumerate(zip(values,actual)) if a!=b]))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8');return differences
    try:
        definitions=[('context',HERE/'context.cpp'),('buffering',HERE/'buffering.cpp'),('queues',HERE/'buffer_queues.cpp')]+[(key,HERE/'..'/directory/file) for key,directory,file in [('selected','movie_selected_clock','clock.cpp'),('counter','movie_counter_clock','clock.cpp'),('audio','movie_audio_clock','clock.cpp'),('filter','movie_audio_filter','filter.cpp'),('pause','movie_pause','controller.cpp'),('admission','movie_admission','admission.cpp'),('initialize','movie_clock_initialize','initialize.cpp'),('sjuni','sjuni','sjuni.cpp'),('sjrb','sjrb','sjrb.cpp')]]
        objects={key:object(key,path) for key,path in definitions};ordered=list(objects.values());fixture=object('fixture',HERE/'buffer_fixture.cpp');units=object('units',HERE/'buffering_tests.cpp')
        binary=executable('units',[*ordered,units]);report['units']=run('units',[binary]).strip();differences=compare('native',ordered);report['native_differences']=len(differences)
        if differences:raise ValueError('Native buffering mismatch '+str(differences[:2]))
        body=(HERE/'buffering.cpp').read_text(encoding='utf-8')
        for name,old,new in [
            ('wide-refill-product','signed_word(stream.capacity*80u)/100','(std::int64_t{signed_word(stream.capacity)}*80)/100'),
            ('nonzero-video-gate','value.video==1','value.video!=0'),
            ('wrong-audio-peek-slot','buffer_peek(2,length)','buffer_peek(value.audio_slot,length)'),
            ('skip-audio-peek','if(signed_word(length)>0)return done(false);','if(false && signed_word(length)>0)return done(false);'),
            ('omit-positive-pause-gates','if(!resume && (signed_word(current.words.numerator)<=0 || signed_word(horizon.numerator)<=0))','if(false && !resume && (signed_word(current.words.numerator)<=0 || signed_word(horizon.numerator)<=0))'),
            ('invert-resume-time','return done(resume?ahead:!ahead);','return done(resume?!ahead:!ahead);')]:
            if old not in body:raise ValueError('Mutation selector drift '+name)
            path=out/(name+'.cpp');path.write_text(body.replace(old,new),encoding='utf-8');mutant=object(name,path);items=[mutant if key=='buffering' else obj for key,obj in objects.items()];diff=compare(name,items)
            if not diff:raise ValueError('Undetected buffering fault '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(diff)))
        queues=(HERE/'buffer_queues.cpp').read_text(encoding='utf-8');old='if(second_taken)admitted=unget(second);';new='if(second_taken){admitted=unget(first);if(admitted)admitted=unget(second);}'
        if queues.count(old)!=1:raise ValueError('Return-order selector drift')
        path=out/'return-order.cpp';path.write_text(queues.replace(old,new).replace('const auto returned_first=unget(first);','const auto returned_first=second_taken?true:unget(first);'),encoding='utf-8')
        mutant=object('return-order',path);binary=executable('return-order-units',[*[mutant if key=='queues' else obj for key,obj in objects.items()],units]);run('return-order-units',[binary],negative=True);report['negative_controls'].append(dict(name='return-first-before-second',units_rejected=True))
        if drift():raise ValueError('Native inputs changed during qualification')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified complete buffering in owned timing context'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file() and p.suffix in ['.txt','.json','.cpp'] and p.name!='receipt.json'}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({key:report[key] for key in ['status','cases','rows','native_differences','units']}|{'receipt_sha256':sha(out/'receipt.json')}))


if __name__=='__main__':main()
