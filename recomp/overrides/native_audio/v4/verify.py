#!/usr/bin/env python3
"""Check the distinct quiescent-reset aggregate with real native source workers."""
import argparse,hashlib,json,os,shutil,subprocess,sys
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3];PARENT=HERE.parent/'v3'
PRIOR=ROOT/'build-native-sjuni/audio-ram-capture-dispatch/gcc-qualified-v2-final'
PRIOR_SHA='80126f5d7e4fbfa353ac6197ba71855c3aa9ec08c72726749e2fdc1d21301483'
SDK=ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1';PROOF=SDK.with_name(SDK.name+'-receipt.json')
PROOF_SHA='473ad00c8fcae9966455fc8f47047f2dccd619d747077fc1ffaec2c2e3444df6'
PINS={'tests.cpp':'df05284f383e33caa7476de2f706474fc1c4b802796207402329df407f04361a','submix_tests.cpp':'137cc32cd8f8c8d56ca17a14fa1d5850fba8619e112834fbc09181ee2faaf80e'}
SCENARIOS=('complete','between_stop','pretable','producer_stop','failed_fence','headless','contract','self','weak','boundaries','synchronous','self_owner','native_streams','native_refusals','native_owner','native_quiescent','reset_callback')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def write(path,body):path.write_text(body,encoding='utf-8',newline='\n')

def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','native-receipt','manifest','output'):p.add_argument('--'+name,type=Path,required=True)
    p.add_argument('--native-manifest',type=Path)
    a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/native-audio-aggregate-v4'):raise ValueError('Fresh owned output required')
    subprocess.run([sys.executable,str(HERE/'derive.py'),'--check'],check=True)
    if sha(PRIOR/'receipt.json')!=PRIOR_SHA or sha(PROOF)!=PROOF_SHA:raise ValueError('Qualified facade ports and actual SDK130 required')
    sdk=json.loads(PROOF.read_bytes());native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    native_path=a.native_manifest or a.manifest;native_manifest=json.loads(native_path.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(native_path):raise ValueError('Matching complete native archive cohort required')
    # These runtime factory/fixture inputs are separately compiled. Every native
    # archive body/header/contract remains identical to its complete build.
    changes={n for n,d in native_manifest['files'].items() if manifest['files'].get(n)!=d}
    fixture_only={'tools/native_reconstruction/audio_media_factory/tests.cpp','tools/native_reconstruction/audio_media_factory/verify.py','recomp/overrides/native_sound_ram/composite_backend.h','recomp/overrides/native_sound_ram/composite_backend.cpp','tools/native_reconstruction/prepare_native_candidate.py'}
    if not changes.issubset(fixture_only):raise ValueError('Native archive cohort changed '+str(changes))
    sources=dict(manifest['files'])
    for name,digest in PINS.items():
        if sha(PARENT/name)!=digest:raise ValueError('Frozen parent fixture drift '+name)
        sources[(PARENT/name).relative_to(ROOT).as_posix()]=digest
    for path in HERE.iterdir():
        if path.suffix in ('.cpp','.h','.py'):sources[path.relative_to(ROOT).as_posix()]=sha(path)
    def verify():
        for name,digest in {**sources,**native['libraries']}.items():
            if sha(ROOT/name)!=digest:raise ValueError('Source/archive drift '+name)
        for name,digest in sdk['source_sha256'].items():
            if sha(SDK/name)!=digest:raise ValueError('Actual SDK drift '+name)
    verify();out.mkdir(parents=True);shutil.copytree(PRIOR/'prior/snapshot',out/'snapshot')
    for name in ('CriAudio.h','CriAudioBackend.h','CriAudioRamCapture.h'):
        if sha(out/'snapshot/Kernel/Syscalls/Helpers'/name)!=sdk['source_sha256']['ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'+name]:raise ValueError('Facade API differs from actual SDK130')
    for name in PINS:
        body=(PARENT/name).read_text().replace('reo::native::audio_aggregate::v3','reo::native::audio_aggregate::v4')
        if name=='submix_tests.cpp':body=body.replace('int main(int argc,char** argv)','int aggregate3_scenarios(int argc,char** argv)');name='parent_submix_tests.cpp'
        write(out/name,body)
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    for name in list(env):
        if name.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(name,None)
    record=dict(schema=1,status='failed',sources=sources,manifest_sha256=sha(a.manifest),native_manifest_sha256=sha(native_path),compatible_fixture_only_changes=sorted(changes),native_receipt_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),facade_ports_receipt_sha256=PRIOR_SHA,actual_sdk_receipt_sha256=PROOF_SHA,game_run=False,device_opened=False,checks=[])
    def run(label,command,negative=False):
        result=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=120);write(out/(label+'.txt'),result.stdout+result.stderr);record['checks'].append(dict(label=label,exit=result.returncode,negative=negative))
        if (result.returncode==0)==negative:raise ValueError(label+' unexpected result; see retained log')
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
    flags=[a.compiler,'-std=c++20','-O1','-pthread','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-I'+str(out/'snapshot'),'-I'+str(HERE),'-I'+str(out),'-I'+str(ROOT)]
    libraries=['-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group']
    try:
        binary=out/'aggregate.exe';run('compile',flags+[HERE/'aggregate.cpp',HERE/'reset_tests.cpp',*libraries,'-o',binary])
        for case in SCENARIOS:run(case,[binary,case])
        # Wrong-owner proof must fail before clearing the actual raw voice map.
        body=(HERE/'aggregate.cpp').read_text();anchor='!proof || !proof->authorizes(s.inputs.native_streams)'
        if body.count(anchor)!=1:raise ValueError('Proof mutation anchor')
        changed=out/'foreign-proof.cpp';write(changed,body.replace(anchor,'!proof'));fault=out/'foreign-proof.exe'
        run('fault-compile',flags+[changed,HERE/'reset_tests.cpp',*libraries,'-o',fault]);run('foreign-proof',[fault,'native_quiescent'],True)
        run('actual130-object',[a.compiler,'-std=c++20','-O1','-pthread','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-I'+str(SDK/'ps2xRuntime/src/lib'),'-I'+str(ROOT),'-c',HERE/'aggregate.cpp','-o',out/'aggregate.o'])
        verify();record.update(status='canonical quiescent reset aggregate passed',scenarios=len(SCENARIOS),detected_faults=['foreign-proof'],binary_sha256=sha(binary),production_object_sha256=sha(out/'aggregate.o'),fault_source_sha256=sha(changed))
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.txt'};write(out/'receipt.json',json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
