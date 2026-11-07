#!/usr/bin/env python3
"""Replay frozen original joint inputs through aggregate3's null-stream profile.

Retain all original differences. Require identical complete observations to the
parent's independently qualified result; never normalize the terminal policy.
"""
import argparse,hashlib,importlib.util,json,os,shutil,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[3];PARENT=HERE.parent/'v2'
ORIGINAL=ROOT/'build-native-sjuni/audio-aggregate-oracle-v4'
ORIGINAL_SHA='b142dd116ef7c81b03c9795462a324ab413a29baa8d4147c098225adfd20da57'
PARENT_ACTUAL='59b21562284768df2736c1273f8837e2cb04485ffb12becd295fbb2ef0899afe'
PARENT_DIFF='438d30ef3fc7cd3bb1758fafd6f3f52410243b69b30a4c5a9ec51d66e12ac94a'
PARENT_DRIVER='373bfb1169ac2f046e94d17786fa177e83c6c1ba80fefbc9c973501cb9b9ba6d'
SURROUNDINGS=ROOT/'build-native-sjuni/native-audio-aggregate-v2/gcc-v1'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/native-audio-aggregate-v3'):raise ValueError('Fresh owned comparison scope required')
    subprocess.run([str(Path(os.sys.executable)),str(HERE/'derive.py'),'--check'],check=True)
    if sha(PARENT/'compare_original.py')!=PARENT_DRIVER or sha(ORIGINAL/'receipt.json')!=ORIGINAL_SHA:raise ValueError('Frozen original/transport provenance changed')
    parent=json.loads((PARENT/'identity.json').read_bytes())
    if sha(SURROUNDINGS/'receipt.json')!=parent['unit_receipts']['gcc-v1']:raise ValueError('Qualified mock surroundings changed')
    original=json.loads((ORIGINAL/'receipt.json').read_bytes());manifest=ORIGINAL/'input-manifest.json'
    if sha(manifest)!=original['input_manifest_sha256']:raise ValueError('Original inputs changed')
    inputs=json.loads(manifest.read_bytes())
    for name,digest in inputs['input_sha256'].items():
        if sha(ORIGINAL/name)!=digest:raise ValueError('Frozen original input changed '+name)
    expected=ORIGINAL/'0/expected.json'
    if sha(expected)!=original['compilers'][0]['expected_sha256']:raise ValueError('Frozen original observation changed')
    native=json.loads(a.native_receipt.read_bytes());core_manifest=ROOT/'tools/native_reconstruction/adxt_attenuation_player_manifest_v1.json'
    if native['status']!='native media pipeline standalone build and tests passed' or native['compiler_sha256']!=sha(a.compiler) or native['manifest_sha256']!=sha(core_manifest):raise ValueError('Exact native build required')
    hashes=json.loads(core_manifest.read_bytes())['files']|{p.relative_to(ROOT).as_posix():sha(p)for p in HERE.iterdir()if p.is_file() and p.suffix in ['.cpp','.h','.hpp','.py']}
    def verify():
        for name,digest in hashes.items():
            if sha(ROOT/name)!=digest:raise ValueError('Source drift '+name)
    verify();libraries=[]
    for name,digest in native['libraries'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Native archive drift')
        libraries.append(ROOT/name)
    out.mkdir(parents=True);shutil.copytree(SURROUNDINGS/'snapshot',out/'snapshot')
    text=(ORIGINAL/'harness.cpp').read_text();head=text[:text.index('#include "ps2_host_backend.h"')];body=text[text.index('namespace a=ps2_cri_audio;'):]
    body=body.replace('namespace a=ps2_cri_audio;','namespace a=native_pcm;').replace('namespace s=ps2_reo_sound;','namespace s=native_bank;')
    body=body.replace('void snapshot() {','void snapshot() {\n    native_environment::observe(channelKeys,voiceKeys);')
    body=body.replace('require(argc==2,"input argument");','hooks.reserve(65536);native_environment::initialize();require(argc==2,"input argument");')
    body=body.replace('require(!in.f.read(&extra,1),"trailing input");return 0;','require(!in.f.read(&extra,1),"trailing input");native_environment::finish();return 0;')
    transport=out/'transport.cpp';transport.write_text(head+'#include "oracle_transport.hpp"\n'+body,encoding='utf-8',newline='\n')
    spec=importlib.util.spec_from_file_location('frozen_parent_comparison',PARENT/'compare_original.py');module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    for key in list(env):
        if key.startswith(('REO_AUDIO_','REO_CRI_','REO_RNA_STOP')):env.pop(key,None)
    record=dict(status='failed',original_receipt_sha256=ORIGINAL_SHA,original_expected_sha256=sha(expected),parent_driver_sha256=PARENT_DRIVER,native_build_sha256=sha(a.native_receipt),compiler_sha256=sha(a.compiler),sources=hashes,original_expectations_previously_known=True,game_run=False,device_opened=False)
    try:
        binary=out/'transport.exe';command=[str(a.compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-pthread','-Wall','-Wextra','-Werror','-Wno-misleading-indentation','-Wl,--no-insert-timestamp','-I'+str(out),'-I'+str(out/'snapshot'),'-I'+str(HERE),'-I'+str(ROOT),str(transport),'-Wl,--start-group',*[str(p)for p in libraries],'-Wl,--end-group','-o',str(binary)]
        if 'clang' not in a.compiler.name:command.insert(1,'-Wno-subobject-linkage')
        run=subprocess.run(command,capture_output=True,text=True,env=env,timeout=120);(out/'compile.txt').write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n')
        if run.returncode:raise ValueError('Transport compilation failed')
        observed=[]
        for name in sorted(n for n in inputs['input_sha256']if n.startswith('case-')):
            run=subprocess.run([str(binary),str(ORIGINAL/name)],capture_output=True,text=True,env=env,timeout=60)
            if run.returncode:raise ValueError('Original-input replay failed '+name+': '+run.stderr)
            observed.append(json.loads(run.stdout))
        diff=list(module.differences(json.loads(expected.read_bytes()),observed));actual=out/'actual.json';differences=out/'differences.json'
        actual.write_text(json.dumps(observed,separators=(',',':'))+'\n',encoding='utf-8',newline='\n');differences.write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8',newline='\n')
        if sha(actual)!=PARENT_ACTUAL or sha(differences)!=PARENT_DIFF:raise ValueError('Null-stream profile differs from qualified parent; retain raw observations')
        verify();record.update(status='null-stream aggregate3 observations match qualified parent',raw_original_differences=len(diff),cases=len(observed),actions=sum(len(c['actions'])for c in observed),float_words=sum(len(x['pcm_bits'])for c in observed for x in c['actions']),hooks=sum(len(x['hooks'])for c in observed for x in c['actions']),actual_sha256=sha(actual),differences_sha256=sha(differences))
    finally:
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:record[k]for k in ['status','raw_original_differences','cases','actions','float_words','hooks']}))
if __name__=='__main__':main()
