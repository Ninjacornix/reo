#!/usr/bin/env python3
"""Compare typed movie counter/query operations with frozen owned-word cases."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-counter-clock'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
FIELDS=['actual','requested','pause','buffering_pause','property_47','active_counter','increment','elapsed_counter','elapsed_origin','external_accumulator']
MAIN_WRITES={0xF24:0,0xF48:1,0xF4C:2};OUTPUT_WRITES={0:3,16:4}


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args();cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh output required')
    frozen=BASE/'original-freeze-v3';receipt=json.loads((frozen/'receipt.json').read_bytes())
    if sha(frozen/'receipt.json')!='cc38614ac4408ecf758052588262312f9bff8affc9efacc1a164f2d34844aabe' or not receipt['native_exists']:raise ValueError('Missing expanded original authority')
    for name,digest in receipt['outputs_sha256'].items():
        if sha(frozen/name)!=digest:raise ValueError('Frozen original output drift')
    original_manifest=json.loads((frozen/'input-manifest.json').read_bytes())
    if sha(ROOT/'game_data/SLUS_207.65')!=original_manifest['elf_sha256']:raise ValueError('Owned ELF drift')
    for name,digest in original_manifest['existing_native_sources'].items():
        if sha(BASE/'failed-v1-inputs'/name)!=digest:raise ValueError('Pre-correction candidate snapshot drift')
    for name,digest in original_manifest['sources'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Original engine drift')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items() if sha(ROOT/n)!=d]
    if drift():raise ValueError('Native input drift '+str(drift()))
    cases=json.loads((frozen/'inputs.json').read_bytes());expected=json.loads((frozen/'original.json').read_bytes())
    text='\n'.join(row['operation']+' '+' '.join(str(row[n]) for n in FIELDS+['frequency','numerator','denominator']) for row in cases)+'\n'
    out.mkdir(parents=True);(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),
                original_receipt_sha256=sha(frozen/'receipt.json'),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False)

    def run(name,cmd,input=None):
        r=subprocess.run([str(x) for x in cmd],cwd=ROOT,env=env,text=True,input=input,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x) for x in cmd],exit=r.returncode))
        if r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout

    def compare(name,source):
        binary=out/(name+'.exe');run(name+'-compile',flags+[source,HERE/'fixture.cpp','-o',binary]);native=run(name,[binary],text).splitlines()
        if len(native)!=len(cases):raise ValueError('Incomplete native transcript')
        differences=[]
        for case,old,line in zip(cases,expected,native,strict=True):
            values=[int(x) for x in line.split()];state=[old['after']['state'][n] for n in FIELDS]
            outputs=[old['after']['numerator'],old['after']['denominator']];writes=[]
            for event in old['writes']:
                if event['span']=='stack':continue
                mapping=MAIN_WRITES if event['span']=='main' else OUTPUT_WRITES if event['span']=='outputs' else {}
                if event['bytes']!=4 or event['offset'] not in mapping:raise ValueError('Unadmitted original write')
                writes.append(mapping[event['offset']])
            errors=[]
            if values[:10]!=state:errors.append('state')
            if values[10:12]!=outputs:errors.append('rational words')
            if bool(values[12])!=old['return_defined'] or old['return_defined'] and values[13]!=(old['raw_v0_lower64']&0xFFFFFFFF):errors.append('defined return')
            if values[14]!=len(writes) or values[15:]!=writes:errors.append('ordered writes')
            if errors:differences.append(dict(name=case['name'],differences=errors))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n')
        report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        binary=out/'units.exe';run('units-compile',flags+[HERE/'clock.cpp',HERE/'clock_tests.cpp','-o',binary]);report['units']=run('units',[binary]).strip()
        differences=compare('native',HERE/'clock.cpp')
        if differences:raise ValueError('Native/original mismatch '+str(differences[:3]))
        source=(HERE/'clock.cpp').read_text(encoding='utf-8')
        mutants=[('ignore-buffering-pause','state.buffering_pause==0','true'),
                 ('elapsed-uses-actual-state','state.requested==4','state.actual==4'),
                 ('nonzero-property-is-one','state.property_47==1','state.property_47!=0'),
                 ('contextual-initializes-eligible-words','operation==Operation::admit || operation==Operation::contextual','operation==Operation::admit'),
                 ('normalize-zero-frequency','state.active_counter,shared_frequency','state.active_counter,shared_frequency?shared_frequency:48000u')]
        for name,old,new in mutants:
            if source.count(old)!=1:raise ValueError('Mutation selector drift '+name)
            path=out/(name+'.cpp');path.write_text(source.replace(old,new),encoding='utf-8',newline='\n');differences=compare(name,path)
            if not differences:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differences=len(differences),source_sha256=sha(path)))
        report.update(status='passed complete bounded movie counter/query original bodies and five counterfactuals',cases=len(cases),original_instructions=receipt['instructions'],native_transcript_sha256=sha(out/'native.txt'))
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['input_drift']=drift()
        if report['input_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],cases=report['cases'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
