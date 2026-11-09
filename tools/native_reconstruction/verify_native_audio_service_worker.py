"""Compile exact production worker block and exercise real owned ADX offline."""
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
    ap=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','native-receipt','output'):ap.add_argument('--'+name,required=True,type=Path)
    a=ap.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
    if out.exists() or not out.is_relative_to(allowed) or out==allowed:raise ValueError('Fresh private output required')
    native=json.loads(a.native_receipt.read_bytes());compiler=a.compiler.resolve()
    if native['parent_suites']!=80 or native['compiler_sha256']!=sha(compiler):raise ValueError('Matching qualified eighty-suite compiler cohort required')
    for name,digest in native['libraries'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Changed qualified native library: '+name)
    work=ROOT/'build-native-sjuni/gallery-e3-digital-clock-v1';decode=json.loads((work/'decode.json').read_bytes())
    asset=work/'E3-Bio_Mix.adx';pcm=work/'expected.pcm'
    if sha(pcm)!=decode['pcm_sha256'] or sha(asset)!=decode['member']['sha256'] or asset.stat().st_size!=decode['member']['bytes']:raise ValueError('Changed independent owned audio inputs')
    source=ROOT/'recomp/overrides/native_sound_ram/composite_backend.cpp';text=source.read_text()
    begin=text.index('// REO_NATIVE_SOURCE_SERVICE_BEGIN');end=text.index('// REO_NATIVE_SOURCE_SERVICE_END',begin)
    out.mkdir();(out/'worker_block.inc').write_text(text[begin:end],encoding='utf8')
    fixture=Path(__file__).with_name('native_audio_service_worker_tests.cpp');shutil.copyfile(fixture,out/'fixture.cpp')
    flags=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-pthread','-I'+str(ROOT),'-I'+str(out),str(out/'fixture.cpp'),'-Wl,--start-group',*[str(ROOT/name) for name in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',str(out/'test.exe')]
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    shutil.copyfile(source,out/'production-source.cpp')
    record=dict(schema=1,status='failed',game_launched=False,device_opened=False,source_sha256=sha(source),block_sha256=sha(out/'worker_block.inc'),fixture_sha256=sha(fixture),verifier_sha256=sha(Path(__file__)),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(compiler),owned_adx_sha256=sha(asset),independent_pcm_sha256=sha(pcm),checks=[])
    try:
        for name,command,timeout in [('compile',flags,120),('test',[str(out/'test.exe'),str(asset),str(pcm)],40)]:
            r=subprocess.run(command,capture_output=True,env=env,timeout=timeout)
            (out/(name+'.stdout.txt')).write_bytes(r.stdout);(out/(name+'.stderr.txt')).write_bytes(r.stderr)
            record['checks'].append(dict(label=name,command=command,exit_code=r.returncode))
            if r.returncode:raise RuntimeError(name+' failed: '+r.stderr.decode(errors='replace')[-2500:])
            if name=='test':record['results']=json.loads(r.stdout)
        record['status']='actual production worker passes withheld-guest-service, independent PCM, pause, inhibit and joined retirement checks'
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps(record['results']))
if __name__=='__main__':main()
