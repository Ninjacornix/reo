#!/usr/bin/env python3
"""Frozen native bank candidate/unit checks; never reads original expected fixtures."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
FROZEN={'session.cpp':'8c0dc8a47dfcb57771edf8d05b70e263c280a2a86a5c2a1471c8c45d1d19559e',
 'session.hpp':'69d14f54e7de6d80ccfb0a6b35868bff0dcf33c3aa36a65fbb2bfc6cd7d881e8',
 'algorithms.cpp':'f0c88569224e1c8c2c5ce117e3296118f96a4b891a09a000ca2707c24fd9b923',
 'algorithms.hpp':'3b324870afdc42282910fe52f58e1fb3dd137f0550d590d547fd58e8ebd401e9',
 'source_members.inc':'15a9255f036a2658b173ada284a12385e929b66731618f227fe4770eb63c7f71',
 'source_mix.inc':'d28e10cdcc91cd4ae2941dd018c17ee902953c92d24a0fdc109fac3ec291f328',
 'source_records.inc':'44ea539c47bfd2dc31271c0aa96b9876d73818c9923a9739edae50127287dc0a'}
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--cxx',required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/audio-bank-session-checks'):raise ValueError('Existing compiler/private ignored output required')
    for name,digest in FROZEN.items():
        if sha(HERE/name)!=digest:raise ValueError('Frozen pre-oracle candidate changed: '+name)
    out.mkdir(parents=True,exist_ok=True);exe=out/'session_tests.exe'
    command=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',
        str(HERE/'algorithms.cpp'),str(HERE/'session.cpp'),str(HERE/'session_tests.cpp'),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),frozen_before_original_expected=FROZEN,
        command=command,game_run=False,device_opened=False,original_expected_read=False)
    try:
        result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=120)
        receipt['compile']=dict(exit_code=result.returncode,stderr=result.stderr)
        if result.returncode:raise RuntimeError(result.stderr)
        result=subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=60)
        receipt['unit']=dict(exit_code=result.returncode,stdout=result.stdout,stderr=result.stderr)
        if result.returncode:raise RuntimeError(result.stderr)
        receipt['status']='passed'
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['authored_sha256']={p.name:sha(p) for p in HERE.iterdir() if p.is_file()}
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(status=receipt['status'],unit=receipt['unit']['stdout'].strip())))
if __name__=='__main__':main()
