#!/usr/bin/env python3
"""Compare native admission state/decisions to independent original FP cohorts."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-admission'
FIELDS=['selector','tolerance','rate','increment','count','tracked_bits','cached','previous_bits','auxiliary']
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def commands(cases):
    lines=[]
    for identity,case in enumerate(cases):
        lines.append('begin '+' '.join(map(str,[identity]+[case['state'][name] for name in FIELDS]+[case['frequency']])))
        for operation in case['operations']:
            # Only authored query replies/effects are supplied; no expected
            # output or derived clock arithmetic is injected into the core.
            sample=[operation['sample'][n] if operation['mask']&(1<<n) else operation['scratch'][n] for n in range(2)]
            updates=operation['updates'];mask=sum(1<<n for n,name in enumerate(FIELDS) if name in updates)
            values=operation['query']+sample+[operation['slack'],operation['query_bits'],operation['current_bits'],mask]+[updates.get(name,0) for name in FIELDS]
            lines.append(operation['kind']+' '+' '.join(map(str,values)))
    return '\n'.join(lines)+'\n'


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    originals=[];cohorts=[];receipts={}
    for tag,pinned,pre_pinned in [('gcc','9b8ed4bd62535163ac92ca7a4ddf5a265505d85bb35f1e7cdcae836e72e884c6','1b23c4eb931ff71d531d8ca6d2f52b3139bd344c18ef807836013b6988743658'),('llvm','909618d04ab11da115ec5d4b1e10af2f1cc652a3542686faa7e56152600c01a0','c1203e939a7cc69276aa941f1140b27c10036d29cc4bf95381b1e8191d2e02a1')]:
        frozen=BASE/('original-'+tag+'-v3');receipt=json.loads((frozen/'receipt.json').read_bytes())
        if sha(frozen/'receipt.json')!=pinned or not receipt['native_exists']:raise ValueError('Original wrapped-margin refinement required')
        pre=BASE/('original-'+tag+'-v2');pre_receipt=json.loads((pre/'receipt.json').read_bytes())
        if sha(pre/'receipt.json')!=pre_pinned or pre_receipt['native_exists']:raise ValueError('Pre-native original corpus required')
        for name,digest in pre_receipt['outputs_sha256'].items():
            if sha(pre/name)!=digest:raise ValueError('Pre-native expectation drift')
        for name,digest in receipt['outputs_sha256'].items():
            if sha(frozen/name)!=digest:raise ValueError('Original expectation drift')
        authority=json.loads((frozen/'input-manifest.json').read_bytes())
        for name,digest in authority['existing_native_sources'].items():
            if sha(BASE/'failed-v1-inputs'/name)!=digest:raise ValueError('Pre-refinement candidate snapshot drift')
        if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
        for name,digest in authority['sources'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Original engine drift '+name)
        for row in authority['fp_emission']['files']:
            if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Audited public FP source drift')
        if sha(frozen/'fp_worker.exe')!=authority['fp_worker_sha256'] or sha(frozen/'fp_worker.cpp')!=authority['fp_worker_source_sha256']:raise ValueError('Original worker drift')
        result=json.loads((frozen/'original.json').read_bytes());cases=json.loads((frozen/'inputs.json').read_bytes())
        if result[:324]!=json.loads((pre/'original.json').read_bytes()) or cases[:324]!=json.loads((pre/'inputs.json').read_bytes()):raise ValueError('Earlier original cases changed')
        originals.append(result);cohorts.append(cases);receipts[str(frozen/'receipt.json')]=pinned
    if originals[0]!=originals[1] or cohorts[0]!=cohorts[1]:raise ValueError('Original compiler cohorts differ')
    cases=cohorts[0];expected=[]
    for identity,(case,original) in enumerate(zip(cases,originals[0],strict=True)):
        if case['name']!=original['name']:raise ValueError('Original case identity')
        for index,row in enumerate(original['operations']):expected.append((identity,index,[row['after']['state'][name] for name in FIELDS]+[row['after']['decision'],0]))
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native input drift '+str(drift()))
    out.mkdir(parents=True);text=commands(cases);(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE)]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipts=receipts,cases=len(cases),operations=len(expected),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False,live_query_binding_qualified=False)

    def run(name,command,input=None,negative=False):
        result=subprocess.run([str(v) for v in command],text=True,capture_output=True,input=input,env=env,cwd=ROOT,timeout=60)
        (out/(name+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=result.returncode))
        if (not negative and result.returncode) or (negative and not result.returncode):raise ValueError(name+': '+result.stdout+result.stderr)
        return result.stdout

    def unit(name,source,negative=False):
        binary=out/(name+'-units.exe');run(name+'-units-compile',flags+[source,HERE/'admission_tests.cpp','-o',binary]);return run(name+'-units',[binary],negative=negative)

    def compare(name,source):
        binary=out/(name+'.exe');run(name+'-compile',flags+[source,HERE/'fixture.cpp','-o',binary]);lines=run(name,[binary],text).splitlines()
        if len(lines)!=len(expected):raise ValueError('Incomplete native transcript')
        differences=[]
        for (identity,index,values),line in zip(expected,lines,strict=True):
            tokens=line.split()
            if tokens[0]!='row' or list(map(int,tokens[1:3]))!=[identity,index]:raise ValueError('Native row identity')
            actual=list(map(int,tokens[3:]))
            if len(actual)!=len(values):raise ValueError('Native projection schema')
            fields=[dict(index=n,expected=left,actual=right) for n,(left,right) in enumerate(zip(values,actual,strict=True)) if left!=right]
            if fields:differences.append(dict(name=cases[identity]['name'],operation=index,fields=fields))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        report['units']=unit('native',HERE/'admission.cpp').strip();differences=compare('native',HERE/'admission.cpp');report['native_differences']=len(differences)
        if differences:raise ValueError('Native mismatch '+str(differences[:4]))
        source=(HERE/'admission.cpp').read_text(encoding='utf-8')
        variants=[
            ('unavailable-any-negative',[('if(input.sample.numerator==0xFFFFFFFEu)','if(signed_word(input.sample.numerator)<0)')]),
            ('unsigned-cross-products',[('std::int64_t{signed_word(input.query.numerator)}*signed_word(input.frequency)','std::uint64_t{input.query.numerator}*input.frequency'),('std::int64_t{signed_word(state.auxiliary)}*signed_word(input.query.denominator)','std::uint64_t{state.auxiliary}*input.query.denominator')]),
            ('full-product-slack',[('const auto product=input.sample.denominator*input.slack;','[[maybe_unused]] const auto product=input.sample.denominator*input.slack;'),('std::int64_t{signed_word(product)}/signed_word(input.frequency)','(std::int64_t{signed_word(input.sample.denominator)}*signed_word(input.slack))/signed_word(input.frequency)')]),
            ('multiply-after-division',[('const float query_scaled=signed_float(input.query.numerator)*10000.0f;\n        query=divide(query_scaled,signed_float(input.query.denominator));','query=divide(signed_float(input.query.numerator),signed_float(input.query.denominator))*10000.0f;')]),
            ('selector-any-nonzero',[('if(state.selector==1)','if(state.selector!=0)')]),
            ('threshold-inclusive-rate',[('signed_word(state.rate)<3','signed_word(state.rate)<=3')]),
            ('unsigned-hysteresis-count',[('threshold<signed_word(state.count)','static_cast<std::uint32_t>(threshold)<state.count')]),
            ('clear-far-ahead-state',[('if(upper<query)return 0;','if(upper<query){state.count=0;return 0;}')]),
            ('drop-duplicate-suppression',[('if(state.previous!=query && state.tracked!=query)','if(true)')]),
            ('normalize-cached-decision',[('std::uint32_t result=state.cached;','std::uint32_t result=state.cached?1u:0u;')])]
        for name,changes in variants:
            changed=source
            for old,new in changes:
                if changed.count(old)!=1:raise ValueError('Mutation selector drift '+name)
                changed=changed.replace(old,new)
            path=out/(name+'.cpp');path.write_text(changed,encoding='utf-8',newline='\n');found=compare(name,path)
            if not found:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differing_rows=len(found)))
        for name,old,new in [
            ('omit-host-environment-restore','~Environment(){if(valid){(void)std::fesetenv(&environment);_mm_setcsr(csr);}}','~Environment(){}'),
            ('partial-zero-frequency-effect','if(operation==Operation::core && input.frequency==0)return{Status::zero_frequency,0};','if(operation==Operation::core && input.frequency==0){destination.count=0;return{Status::zero_frequency,0};}')]:
            if source.count(old)!=1:raise ValueError('Boundary mutation selector drift')
            path=out/(name+'.cpp');path.write_text(source.replace(old,new),encoding='utf-8',newline='\n');unit(name,path,negative=True)
            report['negative_controls'].append(dict(name=name,boundary_tests_rejected=True))
        if drift():raise ValueError('Native inputs changed during run')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified admission arithmetic and hysteresis value boundary'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={p.name:sha(p) for p in sorted(out.iterdir()) if p.is_file() and p.name!='receipt.json' and p.suffix in ['.txt','.json','.cpp']}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],operations=len(expected),negative_controls=len(report['negative_controls']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
