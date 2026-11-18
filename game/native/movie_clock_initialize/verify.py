#!/usr/bin/env python3
"""Verify fresh typed clock construction against both original FP worker cohorts."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-clock-initialize'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
KINDS={0:0,0x1764B0:1,0x1764F8:2,0x176558:3,0x176578:4}


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    originals=[];original_receipts={}
    for tag,pinned in [('gcc','6bf5fb3e5cf08de9c19922b695ae1d6b30cb77523ba470c052271bb325baf964'),('llvm','b5bd645531e3728635181262cc13831f8bd841eb07d7d7f479e39f53f42a6124')]:
        frozen=BASE/('original-'+tag+'-v1');receipt=json.loads((frozen/'receipt.json').read_bytes())
        if sha(frozen/'receipt.json')!=pinned or receipt['native_exists']:raise ValueError('Pre-native original evidence required')
        for name,digest in receipt['outputs_sha256'].items():
            if sha(frozen/name)!=digest:raise ValueError('Original output drift')
        authority=json.loads((frozen/'input-manifest.json').read_bytes())
        if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
        for name,digest in authority['sources'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Original engine drift '+name)
        for row in authority['fp_emission']['files']:
            if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Audited emitted FP source drift')
        if sha(frozen/'fp_worker.cpp')!=authority['fp_worker_source_sha256'] or sha(frozen/'fp_worker.exe')!=authority['fp_worker_sha256']:raise ValueError('Qualified FP worker drift')
        originals.append(json.loads((frozen/'original.json').read_bytes()));original_receipts[str(frozen/'receipt.json')]=pinned
    if originals[0]!=originals[1]:raise ValueError('Original compiler cohorts differ')
    expected=[]
    for original in originals[0]:
        words=original['after']['clock'].copy();words[:7]=[KINDS[word] for word in words[:7]]
        if expected and words!=expected:raise ValueError('Fresh constructor depends on stale clock bits')
        expected=words
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [name for name,digest in manifest['files'].items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native input drift '+str(drift()))
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipts=original_receipts,original_cases_per_compiler=4,original_instructions_per_compiler=2944,normalized_words=168,checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False)

    def run(name,command):
        result=subprocess.run([str(v) for v in command],text=True,capture_output=True,env=env,cwd=ROOT,timeout=60)
        (out/(name+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=result.returncode))
        if result.returncode:raise ValueError(name+': '+result.stdout+result.stderr)
        return result.stdout

    def compare(name,source):
        binary=out/(name+'.exe');run(name+'-compile',flags+[source,HERE/'fixture.cpp','-o',binary]);tokens=run(name,[binary]).split()
        if len(tokens)!=169 or tokens[0]!='row':raise ValueError('Native constructor projection schema')
        words=list(map(int,tokens[1:]));differences=[dict(index=n,expected=left,actual=right) for n,(left,right) in enumerate(zip(expected,words,strict=True)) if left!=right]
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        source=HERE/'initialize.cpp';binary=out/'native-units.exe';run('native-units-compile',flags+[source,HERE/'initialize_tests.cpp','-o',binary]);report['units']=run('native-units',[binary]).strip()
        differences=compare('native',source);report['native_differences']=len(differences)
        if differences:raise ValueError('Native mismatch '+str(differences[:4]))
        text=source.read_text(encoding='utf-8')
        variants=[('wrong-audio-slot',('Kind::counter,Kind::empty,Kind::contextual','Kind::counter,Kind::counter,Kind::contextual')),
                  ('wrong-record-default',('0xFFFFFFFFu,0,0xFFFFFFFFu,0x7FFFFFFFu','0xFFFFFFFFu,1,0xFFFFFFFFu,0x7FFFFFFFu')),
                  ('zero-window-unit',('state.window_parameters={1,0,0,0};','state.window_parameters={0,0,0,0};')),
                  ('zero-cache-sentinel',('state.previous=state.latest=state.cached={0xFFFFFFFBu,1};','state.previous=state.latest=state.cached={0,1};')),
                  ('frame-rate-increment',('state.increment=1000;','state.increment=60;')),
                  ('integer-negative-query',('state.tracked_query_bits=state.previous_query_bits=0xBF800000u;','state.tracked_query_bits=state.previous_query_bits=0xFFFFFFFFu;')),
                  ('initialized-elapsed-counter',('state.elapsed_counter=0xFFFFFFFFu;','state.elapsed_counter=0;')),
                  ('zero-external-history',('state.previous_external=0xFFFFFFFBu;','state.previous_external=0;'))]
        for name,(old,new) in variants:
            if text.count(old)!=1:raise ValueError('Mutation selector drift '+name)
            path=out/(name+'.cpp');path.write_text(text.replace(old,new),encoding='utf-8',newline='\n');found=compare(name,path)
            if not found:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differing_words=len(found)))
        if drift():raise ValueError('Native inputs changed during run')
        report['native_transcript_sha256']=sha(out/'native.txt');report['status']='qualified fresh typed movie clock constructor'
    except Exception as error:report['status']='failed';report['failure']=str(error);raise
    finally:
        report['outputs_sha256']={path.name:sha(path) for path in sorted(out.iterdir()) if path.is_file() and path.name!='receipt.json' and path.suffix in ['.txt','.json','.cpp']}
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],words=168,negative_controls=len(report['negative_controls']),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
