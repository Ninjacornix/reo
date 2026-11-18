#!/usr/bin/env python3
"""Qualify existing prepared-graph composition with a game-handle audio capability.

Video and helper/component ports are declared models; real ADX, source reads,
private rendering, canonical controls and asynchronous graph input are used.
"""
import argparse
import hashlib
import json
import os
import shutil
import subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','handoff-receipt','output'):parser.add_argument('--'+name,type=Path,required=True)
    args=parser.parse_args();out=args.output.resolve();parent=json.loads(args.handoff_receipt.read_bytes())
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/movie-graph-handoff'):raise ValueError('Fresh owned output required')
    if parent['status']!='game handle canonical movie source handoff qualified' or parent['compiler_sha256']!=sha(args.compiler):raise ValueError('Matching qualified handoff required')
    if shutil.disk_usage(ROOT).free<128*1024**2:raise ValueError('At least128MiB free required')
    sources=dict(parent['sources'])
    for path in (HERE/'movie_graph_handoff_tests.cpp',Path(__file__)):sources[path.relative_to(ROOT).as_posix()]=sha(path)
    def verify():
        for name,digest in {**sources,**parent['reused_libraries']}.items():
            if sha(ROOT/name)!=digest:raise ValueError('Source/archive drift '+name)
    verify();out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(args.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    fixture=(HERE/'game_handles_tests.cpp').read_text(encoding='utf-8')
    if fixture.count('\nint main()')!=1:raise ValueError('Unique fixture main boundary required')
    (out/'game_handles_fixture.hpp').write_text(fixture.split('\nint main()')[0]+'\n',encoding='utf-8',newline='\n')
    record=dict(status='failed',sources=sources,reused_libraries=parent['reused_libraries'],compiler_sha256=sha(args.compiler),handoff_receipt_sha256=sha(args.handoff_receipt),actual_native_audio_workers=True,actual_native_movie_read_worker=True,actual_video_provider=False,device_opened=False,game_run=False,actual_runtime_acquisition=False,checks=[])
    def run(label,command):
        result=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=100);(out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=result.returncode))
        if result.returncode:raise ValueError(label+' failed; see retained log')
        print(label+': passed',flush=True)
    try:
        binary=out/'graph-handoff.exe'
        run('compile',[args.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE),'-I'+str(ROOT),'-I'+str(out),
            HERE/'movie_graph_handoff_tests.cpp',HERE/'game_handles.cpp',ROOT/'game/native/movie_instance_audio/source.cpp',*[ROOT/name for name in parent['rebuilt_production_translation_units']],'-Wl,--start-group',*[ROOT/name for name in parent['reused_libraries']],'-Wl,--end-group','-o',binary])
        run('graph-handoff',[binary]);verify();record.update(status='prepared movie graph canonical audio composition qualified',workflows=1)
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
