#!/usr/bin/env python3
"""Verify audio clock/cache state and provider observations against original calls."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-audio-clock'
spec=importlib.util.spec_from_file_location('filter_verify',HERE/'../movie_audio_filter/verify.py')
fv=importlib.util.module_from_spec(spec);spec.loader.exec_module(fv)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def projection(state):
    values=[state['words'][name] for name in fv.WORDS]
    values += [word for name in fv.PAIRS for word in state['pairs'][name]]
    values += [state['doubles'][name] for name in fv.DOUBLES]+state['history']
    if state['globals'][2] not in [0,0x400000]:raise ValueError('Last-filter identity')
    return values+[int(bool(state['globals'][2]))]+state['cache']+[state['diagnostic']]


def commands(cases):
    lines=[]
    for identity,case in enumerate(cases):
        lines.append('begin '+' '.join(map(str,[identity]+case['cache']+[case['diagnostic']]+case['prior'])))
        for key,value in case['filter_seed'].items():
            if key=='history':lines.append('seed_history '+' '.join(str(v&fv.MASK64) for v in value))
            elif key in fv.PAIRS:lines.append('seed_pair '+key+' '+' '.join(str(v&fv.MASK64) for v in value))
            else:lines.append(('seed_word ' if key in fv.WORDS else 'seed_lane ')+key+' '+str(value&fv.MASK64))
        for op in case['operations']:lines.append(op['kind']+' '+' '.join(map(str,[op['actual'],op['adxt_status']]+op['sample']+[op['counter'],op['frequency']])))
    return '\n'.join(lines)+'\n'


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    frozen=BASE/'original-freeze-v2';receipt=json.loads((frozen/'receipt.json').read_bytes())
    if sha(frozen/'receipt.json')!='53a9d7b27be02d17f3260b018ead016dbb8136a7fc44cb1a43063e255b19efbc' or not receipt['native_exists']:raise ValueError('Original numeric refinement authority required')
    prior=BASE/'original-freeze-v1';pre=json.loads((prior/'receipt.json').read_bytes())
    if sha(prior/'receipt.json')!='59e6956a74cdccc9ca18ff95a97a1c17b69b061a0f80f49884b1576ea9cce531' or pre['native_exists']:raise ValueError('Pre-native original authority required')
    for name,digest in pre['outputs_sha256'].items():
        if sha(prior/name)!=digest:raise ValueError('Pre-native expectations changed')
    for name,digest in receipt['outputs_sha256'].items():
        if sha(frozen/name)!=digest:raise ValueError('Frozen original outputs changed')
    authority=json.loads((frozen/'input-manifest.json').read_bytes())
    for name,digest in authority['existing_native_sources'].items():
        if sha(BASE/'failed-v2-inputs'/name)!=digest:raise ValueError('Pre-refinement candidate snapshot drift')
    if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
    for name,digest in authority['sources'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Original engine drift '+name)
    cases=json.loads((frozen/'inputs.json').read_bytes());originals=json.loads((frozen/'original.json').read_bytes())
    if cases[:81]!=json.loads((prior/'inputs.json').read_bytes()) or originals[:81]!=json.loads((prior/'original.json').read_bytes()):raise ValueError('Earlier original cases changed')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native input drift '+str(drift()))
    out.mkdir(parents=True);text=commands(cases);(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    expected=[]
    for identity,(case,original) in enumerate(zip(cases,originals,strict=True)):
        if case['name']!=original['name']:raise ValueError('Original case identity')
        for index,row in enumerate(original['operations']):
            state=row['after'];values=projection(state)+state['caller']+[int(row['return_defined']),row['raw_v0_lower64'] if row['return_defined'] else 0,0,len(row['ports'])]
            for event in row['ports']:values += [1 if event['port']=='estimate' else 2]+projection(event['before'])
            expected.append((identity,index,values))
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    filter_source=HERE/'../movie_audio_filter/filter.cpp'
    selected_sources=[HERE/'../movie_selected_clock/clock.cpp',HERE/'../movie_counter_clock/clock.cpp']
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(frozen/'receipt.json'),cases=len(cases),operations=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False,real_counter_provider_qualified=False)

    def run(name,command,input=None,negative=False):
        r=subprocess.run([str(v) for v in command],cwd=ROOT,env=env,input=input,text=True,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=r.returncode))
        if (not negative and r.returncode) or (negative and not r.returncode):raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout

    def unit(name,source,negative=False):
        binary=out/(name+'-units.exe');run(name+'-units-compile',flags+[source,filter_source,*selected_sources,HERE/'clock_tests.cpp','-o',binary]);return run(name+'-units',[binary],negative=negative)

    def compare(name,source):
        binary=out/(name+'.exe');run(name+'-compile',flags+[source,filter_source,HERE/'fixture.cpp','-o',binary]);lines=run(name,[binary],text).splitlines()
        if len(lines)!=len(expected):raise ValueError('Incomplete native transcript')
        differences=[]
        for (identity,index,values),line in zip(expected,lines,strict=True):
            tokens=line.split()
            if tokens[0]!='row' or list(map(int,tokens[1:3]))!=[identity,index]:raise ValueError('Native row identity')
            actual=list(map(int,tokens[3:]))
            if len(actual)!=len(values):differences.append(dict(name=cases[identity]['name'],operation=index,schema=[len(values),len(actual)]));continue
            fields=[dict(index=i,expected=left,actual=right) for i,(left,right) in enumerate(zip(values,actual,strict=True)) if left!=right]
            if fields:differences.append(dict(name=cases[identity]['name'],operation=index,fields=fields))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        report['units']=unit('native',HERE/'clock.cpp').strip();differences=compare('native',HERE/'clock.cpp');report['native_differences']=len(differences)
        if differences:raise ValueError('Native mismatch '+str(differences[:3]))
        source=(HERE/'clock.cpp').read_text(encoding='utf-8')
        variants=[
            ('zero-extend-samples',[('filter::Pair input{extend(sample.numerator),extend(sample.denominator)};','filter::Pair input{sample.numerator,sample.denominator};'),('std::uint64_t extend(', '[[maybe_unused]] std::uint64_t extend(')]),
            ('refresh-cache-on-equality',[('less(state_.cache.numerator,words.numerator)','!less(words.numerator,state_.cache.numerator)')]),
            ('query-all-eligible-states',[('if(slot && actual!=4)','if(false && slot && actual!=4)')]),
            ('unsigned-cache-maximum',[('less(state_.cache.numerator,words.numerator)','state_.cache.numerator<words.numerator'),('bool less(', '[[maybe_unused]] bool less(')]),
            ('unsigned-status-byte',[('static_cast<std::int32_t>(std::bit_cast<std::int8_t>(raw_status))','static_cast<std::int32_t>(raw_status)')])]
        for name,changes in variants:
            changed=source
            for old,new in changes:
                if changed.count(old)!=1:raise ValueError('Mutation selector drift '+name)
                changed=changed.replace(old,new)
            path=out/(name+'.cpp');path.write_text(changed,encoding='utf-8',newline='\n');found=compare(name,path)
            if not found:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(found)))
        for name,old,new in [
            ('omit-reentry-refusal','if(busy_)return{Status::busy,prior,false,false,0};','if(false && busy_)return{Status::busy,prior,false,false,0};'),
            ('publish-provider-failure','result.status=Status::provider_failure;result.return_defined=false;return result;','result.status=Status::provider_failure;result.written=true;result.return_defined=false;return result;')]:
            if source.count(old)!=1:raise ValueError('Admission mutation selector drift')
            # A missing reentry check is tested with one nested attempt only.
            changed=source.replace(old,new);path=out/(name+'.cpp');path.write_text(changed,encoding='utf-8',newline='\n');unit(name,path,negative=True)
            report['negative_controls'].append(dict(name=name,admission_tests_rejected=True))
        if drift():raise ValueError('Sources changed during run '+str(drift()))
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified bounded movie audio clock/cache envelope'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={p.name:sha(p) for p in sorted(out.iterdir()) if p.is_file() and p.name!='receipt.json' and p.suffix in ['.txt','.json','.cpp']}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],operations=len(expected),negative_controls=len(report['negative_controls']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
