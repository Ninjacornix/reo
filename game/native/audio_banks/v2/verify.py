#!/usr/bin/env python3
"""Compile allocator-policy v2 and run bounded accounting/lifetime checks."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
from derive import derive
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[3]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def check_cohort():
    identity=json.loads((HERE/'cohort_identity.json').read_text(encoding='utf-8'))
    # The standalone cohort compiles these sources explicitly. Root-owned CMake
    # wiring is a separate build cohort and must not silently extend this one.
    actual={p.name:sha(p) for p in HERE.iterdir() if p.is_file() and p.suffix in ('.cpp','.hpp','.py')}
    if identity['candidate_sha256']!=actual:raise ValueError('Explicit post-expectations budget v2 cohort changed; review and identify a new cohort')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/audio-bank-budget-v2'):raise ValueError('Existing compiler/ignored v2 output required')
    check_cohort()
    for name,text in derive().items():
        if (HERE/name).read_text(encoding='utf-8')!=text:raise ValueError('Explicit allocator derivation drift: '+name)
    out.mkdir(parents=True,exist_ok=True);exe=out/'budget_tests.exe'
    cmd=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',str(HERE/'algorithms.cpp'),str(HERE/'session.cpp'),str(HERE/'budget_tests.cpp'),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','');identities={p.name:sha(p) for p in HERE.iterdir() if p.is_file() and (p.suffix in ('.cpp','.hpp','.py') or p.name=='cohort_identity.json')}
    receipt=dict(schema=2,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),command=cmd,authored=identities,historical_blind_baseline='384a0cb036a34ca3578376b036d143902332412a',original_expectations_previously_seen=True,game_run=False,device_opened=False)
    try:
        c=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=120);receipt['compile']=dict(exit_code=c.returncode,stderr=c.stderr)
        if c.returncode:raise RuntimeError(c.stderr)
        r=subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=60);receipt['unit']=dict(exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr)
        if r.returncode:raise RuntimeError(r.stderr)
        receipt['status']='passed';print(r.stdout.strip())
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['postcheck_changed']=[name for name,digest in identities.items() if sha(HERE/name)!=digest]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
