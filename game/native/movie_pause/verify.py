#!/usr/bin/env python3
"""Compare typed pause state, ordered ports and clock steps to original calls."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-pause'
FIELDS=['actual','requested','pause','depth','pending','buffering','episodes','rate','active_counter','elapsed_counter','external_accumulator','external_denominator']
KINDS=['command','pause_predicate','resume_predicate','error','guard_enter','guard_leave']
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def projection(value):
    if value['last'] not in [0,0x400000]:raise ValueError('Original validated identity')
    return [value['state'][name] for name in FIELDS]+[int(bool(value['last'])),value['guard_depth'],value['guard_tag']]


def event_fields(event):
    kind=event['kind'];args=event['arguments'];fields=[KINDS.index(kind)]
    if kind=='command':fields+=args[1:]
    elif kind=='error':fields += [args[0],args[1],args[2],0]
    elif kind.startswith('guard_'):fields += [0,0,args[0],0]
    else:fields += [0,0,0,0]
    return fields+projection(event['before'])


def commands(cases):
    lines=[]
    for identity,case in enumerate(cases):
        lines.append('begin '+' '.join(map(str,[identity]+[case['state'][name] for name in FIELDS]+[case[name] for name in ['frequency','guard_hooks','guard_depth','guard_tag']])))
        for op in case['operations']:
            values=[op['value']]
            for kind in KINDS[:4]:
                updates=op['updates'].get(kind,{})
                values += [op['replies'].get(kind,0),sum(1<<n for n,name in enumerate(FIELDS) if name in updates)]+[updates.get(name,0) for name in FIELDS]
            lines.append(op['kind']+' '+' '.join(map(str,values)))
    return '\n'.join(lines)+'\n'


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    frozen=BASE/'original-freeze-v1';receipt=json.loads((frozen/'receipt.json').read_bytes())
    if sha(frozen/'receipt.json')!='307a72f2834fa4eac93b2702b60859aa53dd1aa5ad99c17237fea8e0abda7f12' or receipt['native_exists']:raise ValueError('Pre-native original corpus required')
    for name,digest in receipt['outputs_sha256'].items():
        if sha(frozen/name)!=digest:raise ValueError('Original expectation drift')
    authority=json.loads((frozen/'input-manifest.json').read_bytes())
    if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
    for name,digest in authority['sources'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Original engine drift '+name)
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native input drift '+str(drift()))
    cases=json.loads((frozen/'inputs.json').read_bytes());originals=json.loads((frozen/'original.json').read_bytes());expected=[]
    for identity,(case,original) in enumerate(zip(cases,originals,strict=True)):
        if case['name']!=original['name']:raise ValueError('Case identity')
        for index,row in enumerate(original['operations']):
            values=projection(row['after'])+[0,row['raw_v0_lower64']&0xFFFFFFFF if row['return_defined'] else 0,int(row['return_defined']),len(row['events'])]
            for event in row['events']:values+=event_fields(event)
            expected.append((identity,index,values))
    out.mkdir(parents=True);text=commands(cases);(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(frozen/'receipt.json'),cases=len(cases),operations=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False)

    def run(name,command,input=None,negative=False):
        r=subprocess.run([str(v) for v in command],cwd=ROOT,env=env,input=input,text=True,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=r.returncode))
        if (not negative and r.returncode) or (negative and not r.returncode):raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout

    def unit(name,source,negative=False):
        binary=out/(name+'-units.exe');run(name+'-units-compile',flags+[source,HERE/'controller_tests.cpp','-o',binary]);return run(name+'-units',[binary],negative=negative)

    def compare(name,source):
        binary=out/(name+'.exe');run(name+'-compile',flags+[source,HERE/'fixture.cpp','-o',binary]);lines=run(name,[binary],text).splitlines()
        if len(lines)!=len(expected):raise ValueError('Incomplete transcript')
        differences=[]
        for (identity,index,values),line in zip(expected,lines,strict=True):
            tokens=line.split()
            if tokens[0]!='row' or list(map(int,tokens[1:3]))!=[identity,index]:raise ValueError('Native row identity')
            actual=list(map(int,tokens[3:]));actual[16]=actual[16] if values[17] else 0
            if len(actual)!=len(values):differences.append(dict(name=cases[identity]['name'],operation=index,schema=[len(values),len(actual)]));continue
            fields=[dict(index=n,expected=left,actual=right) for n,(left,right) in enumerate(zip(values,actual,strict=True)) if left!=right]
            if fields:differences.append(dict(name=cases[identity]['name'],operation=index,fields=fields))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        report['units']=unit('native',HERE/'controller.cpp').strip();differences=compare('native',HERE/'controller.cpp');report['native_differences']=len(differences)
        if differences:raise ValueError('Native mismatch '+str(differences[:4]))
        source=(HERE/'controller.cpp').read_text(encoding='utf-8')
        variants=[
            ('normalize-pause',[('state.pause=value;','state.pause=value?1u:0u;')]),
            ('clamp-depth-underflow',[('--state.depth;if(state.depth==0)','if(state.depth)--state.depth;if(state.depth==0)')]),
            ('mode-two-any-active',[('else if(mode==2 && state.actual==4)','else if(mode==2 && state.actual!=0)')]),
            ('skip-auxiliary-clock-step',[('state.active_counter+=running;state.elapsed_counter+=running;','state.active_counter+=running;')]),
            ('unsigned-frequency',[('std::int64_t{std::bit_cast<std::int32_t>(frequency)}','static_cast<std::int64_t>(frequency)')]),
            ('drop-provider-effects',[('apply(reply.updates);','(void)reply.updates;')]),
            ('pending-before-command',[('state.pause=value;const auto result=nested(mode);state.pending=1;return result;','state.pause=value;state.pending=1;return nested(mode);')]),
            ('skip-deep-leave-hook',[('config_.hooks->leave(config_.leave_parameter);','if(!config_.guard.depth)config_.hooks->leave(config_.leave_parameter);')])]
        for name,changes in variants:
            changed=source
            for old,new in changes:
                if changed.count(old)!=1:raise ValueError('Mutation selector drift '+name)
                changed=changed.replace(old,new)
            path=out/(name+'.cpp');path.write_text(changed,encoding='utf-8',newline='\n');found=compare(name,path)
            if not found:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(found)))
        for name,old,new in [
            ('omit-reentry-refusal','if(busy_)return{Status::busy,0,false};','if(false && busy_)return{Status::busy,0,false};'),
            ('lose-failed-provider-effects','apply(reply.updates);','if(reply.provider==ProviderStatus::completed){apply(reply.updates);}')]:
            if source.count(old)!=1:raise ValueError('Boundary mutation selector drift')
            path=out/(name+'.cpp');path.write_text(source.replace(old,new),encoding='utf-8',newline='\n');unit(name,path,negative=True)
            report['negative_controls'].append(dict(name=name,boundary_tests_rejected=True))
        if drift():raise ValueError('Native inputs changed during run')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified isolated movie pause and buffering controller'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={p.name:sha(p) for p in sorted(out.iterdir()) if p.is_file() and p.name!='receipt.json' and p.suffix in ['.txt','.json','.cpp']}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],operations=len(expected),negative_controls=len(report['negative_controls']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
