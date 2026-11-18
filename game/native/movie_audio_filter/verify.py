#!/usr/bin/env python3
"""Compare a typed audio-time filter to frozen complete original-word calls."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/movie-audio-filter'
MASK64=(1<<64)-1
WORDS=['enabled','pause','active','mode','window','sample_counter','reanchors','positive_steps','negative_steps','resets','excess_resets','average_before','average_after','inactive_max','inactive_min','active_max','active_min']
PAIRS=['previous_input','previous_helper','previous_output','quantum','threshold','first_offset','later_offset']
DOUBLES=['helper_anchor','master_anchor','raw_maximum']
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def project(row):
    state=row['after']
    globals_=list(state['globals'])
    if globals_[2] not in [0,0x400000]:raise ValueError('Original last-filter identity')
    globals_[2]=int(bool(globals_[2]))
    values=[state['words'][key] for key in WORDS]
    values += [v for key in PAIRS for v in state['pairs'][key]]
    values += [state['doubles'][key] for key in DOUBLES]
    values += state['history']+[state['unused_word']]+globals_+state['input']+state['helper']+state['output']
    return values+[int(row['return_defined']),row['raw_v0_lower64'] if row['return_defined'] else 0,0]


def commands(cases):
    lines=[]
    for index,case in enumerate(cases):
        lines.append('begin '+str(index))
        for key,value in case['seed'].items():
            if key=='history':lines.append('seed_history '+' '.join(str(v&MASK64) for v in value))
            elif key in PAIRS:lines.append('seed_pair '+key+' '+' '.join(str(v&MASK64) for v in value))
            else:lines.append(('seed_word ' if key in WORDS else 'seed_lane ')+key+' '+str(value&MASK64))
        for operation in case['operations']:
            name=operation['operation']
            values=operation['input']+operation['helper'] if name=='filter' else operation.get('pair',[operation['value']] if 'value' in operation else [])
            lines.append(name+(' '+' '.join(str(v&MASK64) for v in values) if values else ''))
    return '\n'.join(lines)+'\n'


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx',required=True)
    p.add_argument('--output',type=Path,required=True)
    args=p.parse_args()
    compiler=shutil.which(args.cxx)
    out=args.output.resolve()
    if not compiler or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    frozen=BASE/'original-freeze-v6'
    receipt=json.loads((frozen/'receipt.json').read_bytes())
    if sha(frozen/'receipt.json')!='6564b5452b849ba68aa3bde7bf424c4bd4b9024d4372132ffdbf346200925e64' or receipt['native_exists']:raise ValueError('Pre-native authority required')
    for name,digest in receipt['outputs_sha256'].items():
        if sha(frozen/name)!=digest:raise ValueError('Original expectation drift '+name)
    authority=json.loads((frozen/'input-manifest.json').read_bytes())
    if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
    for name,digest in authority['sources'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Original engine drift '+name)
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    if any(sha(ROOT/name)!=digest for name,digest in manifest['files'].items()):raise ValueError('Committed cohort drift')
    cases=json.loads((frozen/'inputs.json').read_bytes())
    originals=json.loads((frozen/'original.json').read_bytes())
    expected=[]
    for index,(case,original) in enumerate(zip(cases,originals,strict=True)):
        if case['name']!=original['name']:raise ValueError('Case identity')
        for op,row in enumerate([original['constructor']]+original['operations']):expected.append((index,op-1,project(row)))
    out.mkdir(parents=True)
    text=commands(cases)
    (out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    sources={str(path.relative_to(ROOT)):sha(path) for path in sorted(HERE.glob('*')) if path.is_file() and path.suffix in ['.cpp','.hpp','.py','.txt']}
    env=dict(os.environ)
    env['PATH']=str(Path(compiler).parent)+os.pathsep+env.get('PATH','')
    flags=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    report=dict(schema=1,status='running',compiler=compiler,compiler_sha256=sha(Path(compiler)),sources=sources,original_receipt_sha256=sha(frozen/'receipt.json'),checks=[],negative_controls=[],cases=len(cases),operations=sum(len(c['operations']) for c in cases),rows=len(expected),game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False)

    def run(name,command,input=None,negative=False):
        r=subprocess.run([str(v) for v in command],cwd=ROOT,env=env,text=True,input=input,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n')
        report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=r.returncode))
        if (not negative and r.returncode) or (negative and not r.returncode):raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout

    def units(name,source,negative=False):
        binary=out/(name+'-units.exe')
        run(name+'-units-compile',flags+[source,HERE/'filter_tests.cpp','-o',binary])
        return run(name+'-units',[binary],negative=negative)

    def compare(name,source):
        binary=out/(name+'.exe')
        run(name+'-compile',flags+[source,HERE/'fixture.cpp','-o',binary])
        rows=run(name,[binary],text).splitlines()
        if len(rows)!=len(expected):raise ValueError('Incomplete transcript')
        differences=[]
        for (identity,index,values),line in zip(expected,rows,strict=True):
            tokens=line.split()
            if tokens[0]!='row' or list(map(int,tokens[1:3]))!=[identity,index]:raise ValueError('Row identity')
            actual=list(map(int,tokens[3:]))
            if len(actual)!=len(values):raise ValueError('Projection schema')
            # The original v0 scratch lane is undefined for all but average/push.
            if not values[-3]:actual[-2]=0
            fields=[dict(index=n,expected=x,actual=y) for n,(x,y) in enumerate(zip(values,actual,strict=True)) if x!=y]
            if fields:differences.append(dict(name=cases[identity]['name'],operation=index,fields=fields))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n')
        report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        report['units']=units('native',HERE/'filter.cpp').strip()
        differences=compare('native',HERE/'filter.cpp')
        report['native_differences']=len(differences)
        if differences:raise ValueError('Native mismatch '+str(differences[:4]))
        source=(HERE/'filter.cpp').read_text(encoding='utf-8')
        variants=[
            ('pause-any-nonzero',[('if(state.pause==1)','if(state.pause!=0)')]),
            ('quantum-inclusive',[('if(less(quantum,magnitude(mean)))','if(!less(magnitude(mean),quantum))')]),
            ('omit-history-shift',[('(void)shift(state,signed_word(static_cast<std::uint32_t>(correction)));','(void)correction;')]),
            ('cold-average-count',[('signed_word(sum)/static_cast<std::int32_t>(state.window)','signed_word(sum)/static_cast<std::int32_t>(std::max(1u,std::min(state.window,state.sample_counter)))')]),
            ('omit-output-pair-clamp',[('if(less(output.numerator,state.previous_output.numerator))output=state.previous_output;','if(false)output=state.previous_output;')]),
            ('omit-input-clamp',[('if(less(source.numerator,state.raw_maximum))source.numerator=state.raw_maximum;','if(false)source.numerator=state.raw_maximum;')])]
        for name,changes in variants:
            changed=source
            for old,new in changes:
                if changed.count(old)!=1:raise ValueError('Mutation selector drift '+name)
                changed=changed.replace(old,new)
            path=out/(name+'.cpp')
            path.write_text(changed,encoding='utf-8',newline='\n')
            found=compare(name,path)
            if not found:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(found)))
        for name,old,new in [
            ('partial-numeric-commit','if(arithmetic.status!=Status::completed)return{arithmetic.status,{},false};\n    destination=state;','if(arithmetic.status!=Status::completed){destination=state;return{arithmetic.status,{},false};}\n    destination=state;'),
            ('omit-alias-refusal','if(&input==pair)return{Status::invalid_alias,{},false};','if(false && &input==pair)return{Status::invalid_alias,{},false};')]:
            if source.count(old)!=1:raise ValueError('Admission mutation selector drift')
            path=out/(name+'.cpp')
            path.write_text(source.replace(old,new),encoding='utf-8',newline='\n')
            units(name,path,negative=True)
            report['negative_controls'].append(dict(name=name,admission_tests_rejected=True))
        if any(sha(ROOT/name)!=digest for name,digest in manifest['files'].items()):raise ValueError('Cohort changed during run')
        if any(sha(ROOT/name)!=digest for name,digest in sources.items()):raise ValueError('Native inputs changed during run')
        report['status']='qualified bounded integer audio-time filter'
    except Exception as error:
        report['status']='failed'
        report['failure']=str(error)
        raise
    finally:
        report['outputs_sha256']={path.name:sha(path) for path in sorted(out.iterdir()) if path.is_file() and path.suffix in ['.txt','.json','.cpp'] and path.name!='receipt.json'}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],rows=len(expected),negative_controls=len(report['negative_controls']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
