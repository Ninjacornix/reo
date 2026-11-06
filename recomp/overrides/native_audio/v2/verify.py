#!/usr/bin/env python3
"""Isolated complete V2 aggregate tests; no game/device/full library build.

Does NOT read the independent joint original oracle or its expectations.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3]
TREE=ROOT/'build-native-sjuni/dependency-ram-reapply-v5'
PROOF=ROOT/'build-native-sjuni/dependency-ram-reapply-v5-receipt.json'
PROOF_SHA='2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0'
SNAPSHOT=ROOT/'build-native-sjuni/audio-ram-capture-dispatch/gcc-qualified-v2-final/prior/snapshot'
SCENARIOS=('complete','between_stop','pretable','producer_stop','failed_fence','headless','contract','self','weak','boundaries','synchronous','self_owner')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,text):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(text,encoding='utf-8',newline='\n')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/native-audio-aggregate-v2'):raise ValueError('Existing compiler/ignored aggregate output required')
    subprocess.run([sys.executable,str(HERE/'derive.py'),'--check'],check=True)
    if sha(PROOF)!=PROOF_SHA:raise ValueError('Final126 proof changed')
    proof=json.loads(read(PROOF))
    for name,digest in proof['source_sha256'].items():
        if sha(TREE/name)!=digest:raise ValueError('Final126 source changed '+name)
    for row in proof['patches']:
        if sha(ROOT/row['path'])!=row['sha256']:raise ValueError('Final126 patch changed')
    # Use the exact prior proven126 mock surroundings; their fake worker/device
    # boundaries are declared, not a real Runtime/capture factory qualification.
    prior=ROOT/'build-native-sjuni/audio-ram-capture-dispatch/gcc-qualified-v2-final/receipt.json'
    if sha(prior)!='80126f5d7e4fbfa353ac6197ba71855c3aa9ec08c72726749e2fdc1d21301483':raise ValueError('Prior mock surroundings changed')
    out.mkdir(parents=True,exist_ok=True);shutil.copytree(SNAPSHOT,out/'snapshot',dirs_exist_ok=True)
    helper=out/'snapshot/Kernel/Syscalls/Helpers'
    for name in ('CriAudio.cpp','CriAudio.h','CriAudioBackend.h','CriAudioRamCapture.h','CriAudioDispatch.h','ReoSoundBanks.cpp','ReoSoundBanks.h','ReoSoundBanksLegacy.h'):
        if sha(helper/name)!=proof['source_sha256']['ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'+name]:raise ValueError('Copied facade differs '+name)
    shutil.copyfile(HERE/'tests.cpp',out/'tests.cpp')
    inputs=[HERE/'aggregate.cpp',HERE/'aggregate.h',HERE/'tests.cpp',HERE/'derive.py',HERE/'oracle_transport.hpp',Path(__file__),
        ROOT/'game/native/pcm/pcm.cpp',ROOT/'game/native/pcm/pcm.hpp',
        ROOT/'game/native/pcm_bridge/session_bridge.cpp',ROOT/'game/native/pcm_bridge/session_bridge.hpp',
        ROOT/'game/native/audio_output/audio_output_owner.cpp',ROOT/'game/native/audio_output/audio_output_owner.h']
    for base in (ROOT/'game/native/audio_banks/v2',ROOT/'recomp/overrides/native_banks/v3'):
        identity=json.loads(read(base/('cohort_identity.json' if base==ROOT/'game/native/audio_banks/v2' else 'identity.json')))
        for name,digest in identity['candidate_sha256'].items():
            if sha(base/name)!=digest:raise ValueError('Frozen prerequisite changed '+name)
            inputs.append(base/name)
        inputs.append(base/('cohort_identity.json' if base==ROOT/'game/native/audio_banks/v2' else 'identity.json'))
    identities={p.relative_to(ROOT).as_posix():sha(p) for p in inputs}
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    for key in list(env):
        if key.startswith(('REO_CRI_','REO_AUDIO_PATH','REO_RNA_STOP')):env.pop(key,None)
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),authored=identities,actual126_proof=PROOF_SHA,
        game_run=False,device_opened=False,runtime_library_linked=False,joint_expected_read=False,original_joint_expected_previously_known=True,checks=[])
    def run(name,cmd):
        r=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=120)
        receipt['checks'].append(dict(name=name,command=[str(x) for x in cmd],exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr))
        if r.returncode:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
    flags=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-pthread','-I'+str(out/'snapshot'),'-I'+str(HERE),'-I'+str(ROOT)]
    cpp=[HERE/'aggregate.cpp',ROOT/'game/native/pcm/pcm.cpp',ROOT/'game/native/pcm_bridge/session_bridge.cpp',ROOT/'game/native/audio_output/audio_output_owner.cpp',
        ROOT/'game/native/audio_banks/v2/algorithms.cpp',ROOT/'game/native/audio_banks/v2/session.cpp',ROOT/'recomp/overrides/native_banks/v3/packet_adapter.cpp',out/'tests.cpp']
    try:
        exe=out/'aggregate.exe';run('compile_complete_aggregate',flags+[str(p) for p in cpp]+['-o',str(exe)])
        for name in SCENARIOS:run(name,[str(exe),name])
        # Separate production aggregate object consumes the ACTUAL126 V2 header,
        # with no fake runtime/header override in its include path.
        actual=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-pthread',
            '-I'+str(TREE/'ps2xRuntime/src/lib'),'-I'+str(ROOT),'-MMD','-MF',str(out/'aggregate.d'),'-c',str(HERE/'aggregate.cpp'),'-o',str(out/'aggregate.o')]
        run('actual126_production_object',actual)
        receipt['actual126_header_sha256']=sha(TREE/'ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudioBackend.h')
        receipt['actual126_companion_header_sha256']=sha(TREE/'ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudioRamCapture.h')
        receipt['actual_object_sha256']=sha(out/'aggregate.o');receipt['status']='passed'
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['postcheck_changed']=[n for n,h in identities.items() if sha(ROOT/n)!=h]
        if receipt['postcheck_changed']:receipt.update(status='failed',failure='Inputs changed during verification')
        write(out/'receipt.json',json.dumps(receipt,indent=2)+'\n')
    if receipt['postcheck_changed']:raise RuntimeError('Inputs changed during verification')
    print(json.dumps(dict(status=receipt['status'],scenarios=len(SCENARIOS))))
if __name__=='__main__':main()
