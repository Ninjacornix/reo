#!/usr/bin/env python3
"""Transport frozen original bank inputs through frozen typed native Session.

The original harness supplies only binary input decoding and JSON observation.
native_transport.hpp translates packets to typed commands outside the core. No
expected value influences a native operation, DSP result, traversal, or state.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
from verify import FROZEN

HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
ORACLE=ROOT/'build-native-sjuni/bank-session-oracle-v2'
PINNED={'input.json':'9a8f9ebe2b650a0233c26edcc2eff13cbce625fb7e37a05ed46ce4990ac7bd8c',
 'input.bin':'94a2da79aa768d8bdd68279466bf7552f601b1899e0a0b25d928ac494f533862',
 'harness.cpp':'f4951c6f8e3bff5686957ca38e3f5dd1ffc2cc107223029adcafa596f309d945',
 '0/expected.json':'2b0e4010c7197216625fce46838835d58da4af98353bc11d6a6b1d2db2df7d06',
 '1/expected.json':'2b0e4010c7197216625fce46838835d58da4af98353bc11d6a6b1d2db2df7d06',
 'source/ReoSoundBanks.cpp':'e164ba72cc002311d4811d803be2e2df9a6228d5abcaa0c4fa419a31ee09b818',
 'source/ReoSoundBanks.h':'28963da544d533ae8f04765558ff0665c4dc87c38cfba767a4828705c07616c8'}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def differences(a,b,path='$'):
    if type(a)!=type(b):yield dict(path=path,expected=a,actual=b);return
    if isinstance(a,dict):
        if a.keys()!=b.keys():yield dict(path=path,expected_keys=list(a),actual_keys=list(b))
        for k in a.keys()&b.keys():yield from differences(a[k],b[k],path+'.'+k)
    elif isinstance(a,list):
        if len(a)!=len(b):yield dict(path=path+'.length',expected=len(a),actual=len(b))
        for i,(x,y) in enumerate(zip(a,b)):yield from differences(x,y,f'{path}[{i}]')
    elif a!=b:yield dict(path=path,expected=a,actual=b)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/audio-bank-original-comparison'):raise ValueError('Existing compiler and private ignored comparison output required')
    # Check candidate identity before reading expected observations.
    for name,digest in FROZEN.items():
        if sha(HERE/name)!=digest:raise ValueError('Frozen candidate changed: '+name)
    for name,digest in PINNED.items():
        if sha(ORACLE/name)!=digest:raise ValueError('Frozen source oracle changed: '+name)
    out.mkdir(parents=True,exist_ok=True)
    observer=(ORACLE/'harness.cpp').read_text(encoding='utf-8')
    assert observer.count('#include "source/ReoSoundBanks.cpp"')==1
    assert observer.count('namespace s = ps2_reo_sound;')==1
    observer=observer.replace('#include "source/ReoSoundBanks.cpp"','#include "native_transport.hpp"').replace('namespace s = ps2_reo_sound;','namespace s = native_transport;')
    harness=out/'transport.cpp';harness.write_text(observer,encoding='utf-8')
    exe=out/'transport.exe';actual=out/'actual.json'
    # One translation unit avoids divergent access-control declarations across
    # translation units when the observation shim exposes Session::state_.
    command=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Wno-misleading-indentation','-pthread','-I',str(HERE),str(harness),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    authored={p.name:sha(p) for p in [HERE/'native_transport.hpp',Path(__file__).resolve()]}
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),candidate=FROZEN,source_oracle=PINNED,authored=authored,command=command,game_run=False,device_opened=False,
        observation_policy='Original formatting and binary input reader; read-only private native state access; all session mutation through public typed API; packet parser outside core; no expected-derived DSP or normalization',
        diagnostic_limit='Packet-opcode/load-id unsupported counts map to native global_control kind; diagnostic kind events are not present in original observation schema and are not compared')
    try:
        c=subprocess.run(command,capture_output=True,text=True,env=env,timeout=120);receipt['compile']=dict(exit_code=c.returncode,stderr=c.stderr)
        if c.returncode:raise RuntimeError(c.stderr)
        r=subprocess.run([str(exe),str(ORACLE/'input.bin'),str(actual)],capture_output=True,text=True,env=env,timeout=120);receipt['run']=dict(exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr)
        if r.returncode:raise RuntimeError(r.stderr)
        expected=json.loads((ORACLE/'0/expected.json').read_text(encoding='utf-8'));observed=json.loads(actual.read_text(encoding='utf-8'))
        diff=list(differences(expected,observed));(out/'differences.json').write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8')
        receipt.update(status='different' if diff else 'passed',differences=len(diff),actual_sha256=sha(actual),cases=len(expected['cases']),actions=sum(len(c['actions']) for c in expected['cases']),float_words=sum(len(a['pcm_bits']) for c in expected['cases'] for a in c['actions']),gain_calls=sum(len(a['gain_calls']) for c in expected['cases'] for a in c['actions']))
        print(json.dumps({k:receipt[k] for k in ['status','differences','cases','actions','float_words','gain_calls']}))
        for d in diff[:10]:print(json.dumps(d))
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['postcheck_changed']=[name for name,digest in FROZEN.items() if sha(HERE/name)!=digest]+[name for name,digest in PINNED.items() if sha(ORACLE/name)!=digest]+[name for name,digest in authored.items() if sha(HERE/name)!=digest]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    if diff or receipt['postcheck_changed']:raise SystemExit(1)
if __name__=='__main__':main()
