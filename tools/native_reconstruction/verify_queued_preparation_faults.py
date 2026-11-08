#!/usr/bin/env python3
"""Detect stale-result and premature-EOF faults in private native source copies."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','cmake','ninja','manifest','output'):
        parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE/'queued-audio-checks'):
        raise ValueError('Fresh private fault-check output required')
    manifest=json.loads(args.manifest.read_bytes())
    def verify():
        for name,digest in manifest['files'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Root source drift: '+name)
    verify();out.mkdir(parents=True);snapshot=out/'snapshot';build=out/'build'
    for name,digest in manifest['files'].items():
        target=snapshot/name
        if not target.resolve().is_relative_to(snapshot):raise ValueError('Escaped source copy')
        target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(ROOT/name,target)
        if sha(target)!=digest:raise ValueError('Source copy mismatch')
    environment=dict(os.environ);environment['PATH']=str(args.compiler.resolve().parent)+os.pathsep+environment.get('PATH','')
    record=dict(schema=1,status='failed',manifest_sha256=sha(args.manifest),verifier_sha256=sha(Path(__file__)),
        compiler_sha256=sha(args.compiler),cmake_sha256=sha(args.cmake),ninja_sha256=sha(args.ninja),
        root_sources_modified=False,game_run=False,checks=[],phases=[])
    def run(label,command,negative=False):
        result=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=environment,timeout=180)
        log=out/(label+'.txt');log.write_text(result.stdout+result.stderr,encoding='utf8')
        record['checks'].append(dict(name=label,command=list(map(str,command)),exit_code=result.returncode,negative=negative,log_sha256=sha(log)))
        if (result.returncode==0)==negative:raise ValueError(label+' unexpected result; see retained log')
    def phase(name,test,negative=False):
        run(name+'-build',[args.cmake,'--build',build,'--target','adxt_control_session_tests','audio_clip_loader_tests','-j','4'])
        # The baseline executes both suites; each mutation executes the suite
        # that asserts the violated lifetime/decoder-boundary contract.
        run(name+'-test',[args.cmake.with_name('ctest.exe'),'--test-dir',build,'-R',test,'--output-on-failure'],negative)
        record['phases'].append(dict(name=name,test_expression=test,binaries_sha256={
            p.relative_to(build).as_posix():sha(p) for p in (build/'adxt_control_session_tests.exe',build/'audio_clip_loader/audio_clip_loader_tests.exe')},
            loader_sha256=sha(snapshot/'game/native/audio_clip_loader/loader.cpp'),
            input_sha256=sha(snapshot/'game/native/adxt_lsc_input/input.cpp')))
    try:
        run('configure',[args.cmake,'-S',snapshot/'game/native/adxt_control_session','-B',build,'-G','Ninja',
            '-DCMAKE_BUILD_TYPE=Release','-DCMAKE_CXX_COMPILER='+str(args.compiler.resolve()),'-DCMAKE_MAKE_PROGRAM='+str(args.ninja.resolve())])
        phase('baseline','^(adxt_control_session|audio_clip_loader)$')
        original_input=(ROOT/'game/native/adxt_lsc_input/input.cpp').read_text()
        anchor='s.pending_asset || s.report.preparing_assets ||'
        if original_input.count(anchor)!=1:raise ValueError('Unique decoder guard required')
        input_path=snapshot/'game/native/adxt_lsc_input/input.cpp'
        input_path.write_text(original_input.replace(anchor,'s.pending_asset ||'),encoding='utf8')
        shutil.copyfile(input_path,out/'premature-eof-input.cpp')
        phase('premature-eof','^adxt_control_session$',True)
        shutil.copyfile(ROOT/'game/native/adxt_lsc_input/input.cpp',input_path)
        original_loader=(ROOT/'game/native/audio_clip_loader/loader.cpp').read_text()
        anchor='auto prepared = adx_sequence::Clip::prepare(view);'
        if original_loader.count(anchor)!=1:raise ValueError('Unique loader publication boundary required')
        before,after=original_loader.split(anchor)
        guard=' || record.generation != generation'
        if after.count(guard)!=1:raise ValueError('Unique stale-publication guard required')
        loader_path=snapshot/'game/native/audio_clip_loader/loader.cpp'
        loader_path.write_text(before+anchor+after.replace(guard,'',1),encoding='utf8')
        shutil.copyfile(loader_path,out/'stale-publication-loader.cpp')
        phase('stale-publication','^audio_clip_loader$',True)
        verify();record['status']='both native queued-preparation faults detected'
    finally:
        record['source_mutations_sha256']={p.name:sha(p) for p in out.glob('*.cpp')}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status=record['status'],phases=len(record['phases']),receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
