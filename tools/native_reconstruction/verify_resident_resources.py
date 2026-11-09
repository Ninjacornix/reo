"""Isolated resident-resource and actual native clip-loader regressions."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
ROOT=Path(__file__).resolve().parents[2]
def sha(p):
    with p.open('rb') as f:return hashlib.file_digest(f,'sha256').hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__)
    for key in ('compiler','native-receipt','output'):p.add_argument('--'+key,required=True,type=Path)
    a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
    if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
    native=json.loads(a.native_receipt.read_bytes());compiler=a.compiler.resolve()
    if sha(compiler)!=native['compiler_sha256'] or native['parent_suites']!=80:raise ValueError('Matching qualified native library cohort required')
    for name,digest in native['libraries'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Changed library: '+name)
    sources=[ROOT/'game/native/resources/bounded_view.cpp',ROOT/'game/native/audio_clip_loader/loader.cpp']
    fixtures=[('resident',ROOT/'tools/native_reconstruction/resident_resource_tests.cpp'),('loader',ROOT/'game/native/audio_clip_loader/loader_tests.cpp'),('queue',ROOT/'game/native/audio_cue_queue/queue_tests.cpp')]
    inputs={p.relative_to(ROOT).as_posix():sha(p) for p in [*sources,*(f for _,f in fixtures),Path(__file__)]}
    out.mkdir()
    for source in [*sources,*(f for _,f in fixtures)]:shutil.copyfile(source,out/(source.parent.name+'-'+source.name))
    record=dict(schema=1,status='failed',game_launched=False,device_opened=False,compiler_sha256=sha(compiler),native_receipt_sha256=sha(a.native_receipt),sources_sha256=inputs,checks=[])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    flags=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-pthread','-I'+str(ROOT)]
    link=['-Wl,--start-group',*[str(ROOT/name) for name in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject']
    try:
        for name,fixture in fixtures:
            exe=out/(name+'.exe')
            for label,command,timeout in [(name+'-compile',flags+[str(s) for s in [*sources,fixture]]+link+['-o',str(exe)],120),(name+'-test',[str(exe)],40)]:
                result=subprocess.run(command,capture_output=True,env=env,timeout=timeout)
                (out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr)
                record['checks'].append(dict(label=label,command=command,exit_code=result.returncode))
                if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-2500:])
                if label=='resident-test':record['resident_results']=json.loads(result.stdout)
        for name,digest in inputs.items():
            if sha(ROOT/name)!=digest:raise ValueError('Source changed during verification: '+name)
        record['status']='resident cache and full-body native clip preparation checks passed'
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps(record['resident_results']))
if __name__=='__main__':main()
