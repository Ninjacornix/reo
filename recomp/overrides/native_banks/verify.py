#!/usr/bin/env python3
"""Compile real packet adapter + immutable bank v2; exercise bounded lifecycle."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
HERE=Path(__file__).resolve().parent
ROOT=HERE.parents[2]
V2=ROOT/'game/native/audio_banks/v2'
sys.path.insert(0,str(V2))
spec=importlib.util.spec_from_file_location('bank_budget_verifier',V2/'verify.py')
budget=importlib.util.module_from_spec(spec);spec.loader.exec_module(budget)
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def check_adapter():
    identity=json.loads((HERE/'identity.json').read_text(encoding='utf-8'))
    actual={p.name:sha(p) for p in HERE.iterdir() if p.is_file() and p.suffix in ('.cpp','.h','.py')}
    if actual!=identity['candidate_sha256']:raise ValueError('Packet adapter identified source cohort changed; review a new cohort')
    if sha(V2/'cohort_identity.json')!=identity['bank_v2_identity_sha256']:raise ValueError('Identified bank v2 prerequisite changed')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--runtime-lib',type=Path);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/native-bank-packet-adapter'):raise ValueError('Existing compiler/ignored adapter output required')
    check_adapter();budget.check_cohort();out.mkdir(parents=True,exist_ok=True);exe=out/'packet_tests.exe'
    cmd=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',str(V2/'algorithms.cpp'),str(V2/'session.cpp'),str(HERE/'packet_adapter.cpp'),str(HERE/'packet_adapter_tests.cpp'),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','');authored={p.name:sha(p) for p in HERE.iterdir() if p.is_file()};baseline=json.loads((V2/'cohort_identity.json').read_text(encoding='utf-8'))
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),command=cmd,authored=authored,bank_v2_identity_sha256=sha(V2/'cohort_identity.json'),bank_v2=baseline['candidate_sha256'],original_expected_observations_previously_seen=True,game_run=False,device_opened=False)
    try:
        c=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=120);receipt['compile']=dict(exit_code=c.returncode,stderr=c.stderr)
        if c.returncode:raise RuntimeError(c.stderr)
        r=subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=60);receipt['unit']=dict(exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr)
        if r.returncode:raise RuntimeError(r.stderr)
        # A deliberately broken PRIVATE variant must fail the same gated
        # whole-adapter check. Authored source remains unchanged; no expected
        # DSP/state values or runtime library are altered for this control.
        original=(HERE/'packet_adapter.cpp').read_text(encoding='utf-8')
        destructor='~PacketLoadUnlock(){if(lock&&!lock->owns_lock())lock->lock();}'
        if original.count(destructor)!=1:raise ValueError('Negative-control location changed')
        broken=out/'negative_no_relock.cpp';broken.write_text(original.replace(destructor,'~PacketLoadUnlock(){}'),encoding='utf-8',newline='\n')
        negative_exe=out/'negative_no_relock.exe';negative_cmd=list(cmd)
        negative_cmd[negative_cmd.index(str(HERE/'packet_adapter.cpp'))]=str(broken)
        negative_cmd[-1]=str(negative_exe);negative_cmd[1:1]=['-I',str(HERE)]
        nc=subprocess.run(negative_cmd,capture_output=True,text=True,env=env,timeout=120)
        receipt['negative_compile']=dict(command=negative_cmd,variant_sha256=sha(broken),exit_code=nc.returncode,stderr=nc.stderr)
        if nc.returncode:raise RuntimeError(nc.stderr)
        nr=subprocess.run([str(negative_exe)],capture_output=True,text=True,env=env,timeout=60)
        receipt['negative_relock']=dict(exit_code=nr.returncode,stdout=nr.stdout,stderr=nr.stderr,expected_failure=True)
        if nr.returncode==0 or 'packet adapter assertion' not in nr.stderr:raise RuntimeError('Missing relock was not detected by whole-adapter gated test')
        if a.runtime_lib:
            runtime=a.runtime_lib.resolve();header=runtime/'Kernel/Syscalls/Helpers/CriAudioBackend.h'
            if not header.is_file():raise ValueError('Actual complete V2 reconstructed runtime lib headers required')
            proof=ROOT/'build-native-sjuni/dependency-bank-reapply-v3-receipt.json'
            if sha(proof)!='3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a':raise ValueError('Final fresh125 proof identity changed')
            proved=json.loads(proof.read_text(encoding='utf-8'));checkout=Path(proved['checkout']).resolve()
            if proved['status']!='passed' or proved['base_revision']!='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f' or proved['applied_count']!=125 or runtime!=checkout/'ps2xRuntime/src/lib':raise ValueError('Fresh125 exact header cohort required')
            for name,digest in proved['source_sha256'].items():
                if sha(checkout/name)!=digest:raise ValueError('Fresh125 source drift '+name)
            for item in proved['patches']:
                if sha(ROOT/item['path'])!=item['sha256']:raise ValueError('Fresh125 patch input drift '+item['path'])
            probe=out/'actual_header.cpp'
            probe.write_text('#include "backend_status.h"\nps2_cri_audio::BankQueryV2 check_status(){return reo::native::bank_packets::to_backend(reo::native::bank_packets::Result<std::uint32_t>{reo::native::bank_packets::Status::ok,7});}\n',encoding='utf-8',newline='\n')
            hcmd=[cc,'-std=c++20','-Wall','-Wextra','-Werror','-I',str(HERE),'-I',str(runtime),'-c',str(probe),'-o',str(out/'actual_header.o')]
            h=subprocess.run(hcmd,capture_output=True,text=True,env=env,timeout=60);receipt['actual_header']=dict(path=str(header),sha256=sha(header),proof_sha256=sha(proof),verified_source_files=len(proved['source_sha256']),verified_patches=len(proved['patches']),command=hcmd,exit_code=h.returncode,stderr=h.stderr)
            if h.returncode:raise RuntimeError(h.stderr)
        receipt['status']='passed';print(r.stdout.strip())
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['postcheck_changed']=[name for name,digest in authored.items() if sha(HERE/name)!=digest]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
