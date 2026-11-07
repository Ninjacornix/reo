#!/usr/bin/env python3
"""Check aggregate3 plus real native workers in one model output callback.

Uses the retained 126 facade mock surroundings, current audited 129 production
headers and an exact independent native library cohort. No game/device launch.
"""
import argparse,hashlib,json,os,shutil,subprocess,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3]
PRIOR=ROOT/'build-native-sjuni/audio-ram-capture-dispatch/gcc-qualified-v2-final'
PRIOR_SHA='80126f5d7e4fbfa353ac6197ba71855c3aa9ec08c72726749e2fdc1d21301483'
SDK=ROOT/'build-native-sjuni/dependency-sound-rpc10-reapply-v1'
SDK_RECEIPT=SDK.with_name(SDK.name+'-receipt.json')
SDK_SHA='692d86d3e19c51039e58749cedf86597810fcff672e95b62a451d3b14605514b'
SCENARIOS=('complete','between_stop','pretable','producer_stop','failed_fence','headless','contract','self','weak','boundaries','synchronous','self_owner','native_streams','native_refusals')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/native-audio-aggregate-v3'):raise ValueError('Fresh owned scope required')
    subprocess.run([sys.executable,str(HERE/'derive.py'),'--check'],check=True)
    if sha(PRIOR/'receipt.json')!=PRIOR_SHA or sha(SDK_RECEIPT)!=SDK_SHA:raise ValueError('Explicit facade/production provenance required')
    sdk=json.loads(SDK_RECEIPT.read_bytes())
    for name,digest in sdk['source_sha256'].items():
        if sha(SDK/name)!=digest:raise ValueError('Current audited SDK drift '+name)
    native=json.loads(a.native_receipt.read_bytes());manifest=ROOT/'tools/native_reconstruction/native_audio_submix_manifest_v2.json'
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(manifest):raise ValueError('Exact native submix build required')
    sources=json.loads(manifest.read_bytes())['files']
    def verify():
        for name,digest in sources.items():
            if sha(ROOT/name)!=digest:raise ValueError('Native source drift '+name)
    verify();libraries=[]
    for name,digest in native['libraries'].items():
        path=ROOT/name
        if sha(path)!=digest:raise ValueError('Native archive drift '+name)
        libraries.append(path)
    out.mkdir(parents=True);shutil.copytree(PRIOR/'prior/snapshot',out/'snapshot')
    # The mock's public API headers are exactly those of the actual 129 SDK.
    for name in ['CriAudio.h','CriAudioBackend.h','CriAudioRamCapture.h']:
        path='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'+name
        if sha(out/'snapshot/Kernel/Syscalls/Helpers'/name)!=sdk['source_sha256'][path]:raise ValueError('Mock API differs from actual SDK '+name)
    for name in ['tests.cpp','submix_tests.cpp']:shutil.copyfile(HERE/name,out/name)
    authored={p.relative_to(ROOT).as_posix():sha(p)for p in HERE.iterdir()if p.is_file()}
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    for key in list(env):
        if key.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(key,None)
    record=dict(status='failed',authored=authored,native_manifest_sha256=sha(manifest),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),facade_mock_receipt_sha256=PRIOR_SHA,actual_sdk_receipt_sha256=SDK_SHA,game_run=False,device_opened=False,checks=[])
    def run(label,command):
        v=subprocess.run([str(x)for x in command],capture_output=True,text=True,env=env,timeout=120);(out/(label+'.txt')).write_text(v.stdout+v.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=v.returncode,command=[str(x)for x in command]))
        if v.returncode:raise ValueError(label+' failed; see owned log')
        print(label+': passed',flush=True)
    try:
        binary=out/'aggregate.exe';flags=[a.compiler,'-std=c++20','-O1','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-pthread','-I'+str(out/'snapshot'),'-I'+str(HERE),'-I'+str(out),'-I'+str(ROOT)]
        run('compile',flags+[HERE/'aggregate.cpp',out/'submix_tests.cpp','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',binary])
        for name in SCENARIOS:run(name,[binary,name])
        run('actual129-object',[a.compiler,'-std=c++20','-O1','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-pthread','-I'+str(SDK/'ps2xRuntime/src/lib'),'-I'+str(ROOT),'-c',HERE/'aggregate.cpp','-o',out/'aggregate.o'])
        verify()
        if any(sha(ROOT/n)!=v for n,v in authored.items()):raise ValueError('Authored source changed during qualification')
        record.update(status='native stream-only aggregate composition qualified',scenarios=len(SCENARIOS),binary_sha256=sha(binary),production_object_sha256=sha(out/'aggregate.o'))
    finally:
        record['outputs_sha256']={p.name:sha(p)for p in out.iterdir()if p.suffix=='.txt'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],scenarios=record['scenarios'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
