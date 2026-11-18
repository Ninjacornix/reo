#!/usr/bin/env python3
"""Run identical frozen joint INPUTS through the already frozen V2 aggregate.

Transport/observer only. Does not alter any frozen implementation or expected
observations. Raw differences, including terminal facade policy, are retained.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[4];HERE=Path(__file__).resolve().parent
ORIGINAL=ROOT/'build-native-sjuni/audio-aggregate-oracle-v4'
FREEZE_SHA='f6e7c65162da526eeb65e8a6a71335ddad83f09f5937a517eee82eeb7cb11012'
RECEIPT_SHA='b142dd116ef7c81b03c9795462a324ab413a29baa8d4147c098225adfd20da57'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def differences(a,b,path='$'):
    if type(a)!=type(b):yield dict(path=path,expected=a,actual=b);return
    if isinstance(a,dict):
        if set(a)!=set(b):yield dict(path=path,expected_keys=sorted(a),actual_keys=sorted(b));return
        for key in a:yield from differences(a[key],b[key],path+'.'+key)
    elif isinstance(a,list):
        if len(a)!=len(b):yield dict(path=path,expected_length=len(a),actual_length=len(b));return
        for i,(x,y) in enumerate(zip(a,b)):yield from differences(x,y,path+f'[{i}]')
    elif a!=b:yield dict(path=path,expected=a,actual=b)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/native-audio-aggregate-v2'):raise ValueError('Existing compiler/private output required')
    if sha(HERE/'identity.json')!=FREEZE_SHA:raise ValueError('Pre-expectation aggregate identity changed')
    freeze=json.loads(read(HERE/'identity.json'))
    for name,digest in freeze['candidate_sha256'].items():
        if sha(HERE/name)!=digest:raise ValueError('Frozen aggregate changed '+name)
    if sha(ORIGINAL/'receipt.json')!=RECEIPT_SHA:raise ValueError('Independent original receipt changed')
    original=json.loads(read(ORIGINAL/'receipt.json'));manifest=ORIGINAL/'input-manifest.json'
    if sha(manifest)!=original['input_manifest_sha256']:raise ValueError('Original input manifest changed')
    inputs=json.loads(read(manifest))
    for name,digest in inputs['input_sha256'].items():
        if sha(ORIGINAL/name)!=digest:raise ValueError('Frozen original input changed '+name)
    out.mkdir(parents=True,exist_ok=True)
    snapshot=ROOT/'build-native-sjuni/native-audio-aggregate-v2/gcc-v1/snapshot'
    if sha(ROOT/'build-native-sjuni/native-audio-aggregate-v2/gcc-v1/receipt.json')!=freeze['unit_receipts']['gcc-v1']:raise ValueError('Qualified source surroundings changed')
    shutil.copytree(snapshot,out/'snapshot',dirs_exist_ok=True)
    text=read(ORIGINAL/'harness.cpp');begin=text.index('namespace a=ps2_cri_audio;');head=text[:text.index('#include "ps2_host_backend.h"')]
    body=text[begin:].replace('namespace a=ps2_cri_audio;','namespace a=native_pcm;').replace('namespace s=ps2_reo_sound;','namespace s=native_bank;')
    body=body.replace('void snapshot() {','void snapshot() {\n    native_environment::observe(channelKeys,voiceKeys);')
    body=body.replace('require(argc==2,"input argument");','hooks.reserve(65536);native_environment::initialize();require(argc==2,"input argument");')
    body=body.replace('require(!in.f.read(&extra,1),"trailing input");return 0;','require(!in.f.read(&extra,1),"trailing input");native_environment::finish();return 0;')
    write(out/'transport.cpp',head+'#include "oracle_transport.hpp"\n'+body)
    flags=[cc,'-std=c++20','-O2','-ffp-contract=off','-fno-fast-math','-pthread','-Wall','-Wextra','-Werror','-Wno-misleading-indentation','-Wl,--no-insert-timestamp',
        '-I'+str(out),'-I'+str(out/'snapshot'),'-I'+str(HERE),'-I'+str(ROOT)]
    if 'clang' not in Path(cc).name:flags.append('-Wno-subobject-linkage') # read-only State observer includes exact .cpp
    cpp=[out/'transport.cpp',ROOT/'game/native/pcm/pcm.cpp',ROOT/'game/native/pcm_bridge/session_bridge.cpp',ROOT/'game/native/audio_output/audio_output_owner.cpp',
        ROOT/'game/native/audio_banks/v2/algorithms.cpp',ROOT/'game/native/audio_banks/v2/session.cpp',ROOT/'recomp/overrides/native_banks/v3/packet_adapter.cpp']
    exe=out/'transport.exe';command=flags+[str(p) for p in cpp]+['-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    for name in list(env):
        if name.startswith(('REO_AUDIO_','REO_CRI_','REO_RNA_STOP')):env.pop(name,None)
    receipt=dict(schema=1,status='running',aggregate_freeze_sha256=FREEZE_SHA,original_receipt_sha256=RECEIPT_SHA,
        existing_joint_expected_previously_known=True,input_manifest_sha256=sha(manifest),compiler=cc,compiler_sha256=sha(Path(cc)),command=[str(x) for x in command],
        transport_sha256=sha(HERE/'oracle_transport.hpp'),observer_sha256=sha(out/'transport.cpp'),game_run=False,device_opened=False)
    try:
        c=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);receipt['compile']=dict(exit_code=c.returncode,stdout=c.stdout,stderr=c.stderr)
        if c.returncode:raise RuntimeError(c.stderr)
        observed=[]
        for name in sorted(n for n in inputs['input_sha256'] if n.startswith('case-')):
            r=subprocess.run([str(exe),str(ORIGINAL/name)],env=env,capture_output=True,text=True,timeout=60)
            if r.returncode:raise RuntimeError(name+': '+r.stderr)
            observed.append(json.loads(r.stdout))
        expected=json.loads(read(ORIGINAL/'0/expected.json'))
        if sha(ORIGINAL/'0/expected.json')!=original['compilers'][0]['expected_sha256']:raise ValueError('Original expected identity changed')
        diff=list(differences(expected,observed));write(out/'actual.json',json.dumps(observed,separators=(',',':'))+'\n');write(out/'differences.json',json.dumps(diff,indent=2)+'\n')
        receipt.update(status='different' if diff else 'passed',differences=len(diff),cases=len(observed),actions=sum(len(c['actions']) for c in observed),
            float_words=sum(len(a['pcm_bits']) for c in observed for a in c['actions']),hooks=sum(len(a['hooks']) for c in observed for a in c['actions']),actual_sha256=sha(out/'actual.json'))
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['core_postcheck_changed']=[n for n,h in freeze['candidate_sha256'].items() if sha(HERE/n)!=h]
        write(out/'receipt.json',json.dumps(receipt,indent=2)+'\n')
    print(json.dumps({k:receipt[k] for k in ('status','differences','cases','actions','float_words','hooks')}))
if __name__=='__main__':main()
